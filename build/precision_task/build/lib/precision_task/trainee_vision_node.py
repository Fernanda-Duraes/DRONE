import math
import cv2 as cv
import numpy as np
import rclpy
from cv_bridge import CvBridge
from precision_interfaces.msg import Figura, FiguraArray
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image
from std_msgs.msg import Bool, String

S_MIN = 100
V_MIN = 50

ALTURA_REF = 5.0
AREA_MIN_REF = 300
SOLIDEZ_MIN = 0.90
MARGEM_BORDA = 2

RAZAO_TRIANGULO_MAX = 0.60
RAZAO_HEXAGONO_MAX = 0.90

FRAMES_CONFIRMA = 3
FRAMES_PERDIDOS_MAX = 4
MAX_FIGURAS = 3

FAIXAS = {
    'vermelho': [((0, S_MIN, V_MIN), (10, 255, 255)),
                 ((170, S_MIN, V_MIN), (179, 255, 255))],
    'verde':    [((40, S_MIN, V_MIN), (85, 255, 255))],
    'azul':     [((95, S_MIN, V_MIN), (135, 255, 255))],
}

BGR_DEBUG = {'vermelho': (0, 0, 255), 'verde': (0, 255, 0), 'azul': (255, 0, 0)}


class TraineeVisionNode(Node):
    def __init__(self):
        super().__init__('trainee_vision_node')

        self.declare_parameter('show_debug', True)
        self.declare_parameter('altura_voo', 6.0)
        self.show_debug = self.get_parameter('show_debug').value
        altura = float(self.get_parameter('altura_voo').value)
        self.area_min = AREA_MIN_REF * (ALTURA_REF / altura) ** 2

        self.create_subscription(Image, '/camera/image_raw', self.read_im,
                                 qos_profile_sensor_data)

        self.pub_objects = self.create_publisher(FiguraArray, '/vision/objects', 10)
        self.pub_complete = self.create_publisher(Bool, '/vision/complete', 10)
        self.vision_node_state_publisher = self.create_publisher(String,'/pkg_avant/integra/vision_status',10)



        self.bridge = CvBridge()
        self.primeiro_frame = True

        self.figuras = {}
        self.candidatas = {}
        self.completo = False

        self.create_timer(0.5, self.publish_state)
        self.vision_state = "online"
        self.timer = self.create_timer(0.5, self.publish_vision_state)
        self.get_logger().info(
            f'Nó de visão ativo (altura {altura:.1f} m, AREA_MIN efetiva {self.area_min:.0f} px)')

    def publish_vision_state(self):
        msg = String()
        msg.data = self.vision_state
        self.vision_node_state_publisher.publish(msg)

    def read_im(self, msg: Image):
        if self.primeiro_frame:
            self.get_logger().info(f'Primeiro frame recebido ({msg.width}x{msg.height})')
            self.primeiro_frame = False
        img = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        h_img, w_img = img.shape[:2]
        debug = img.copy()

        hsv = cv.cvtColor(cv.GaussianBlur(img, (5, 5), 0), cv.COLOR_BGR2HSV)
        kernel = np.ones((3, 3), np.uint8)
        vistas = set()

        for cor, faixas in FAIXAS.items():
            mask = np.zeros(hsv.shape[:2], np.uint8)
            for lo, hi in faixas:
                mask |= cv.inRange(hsv, np.array(lo), np.array(hi))
            mask = cv.morphologyEx(mask, cv.MORPH_OPEN, kernel)
            mask = cv.morphologyEx(mask, cv.MORPH_CLOSE, kernel)

            contornos, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

            for c in contornos:
                area = cv.contourArea(c)
                if area < self.area_min:
                    continue

                bx, by, bw, bh = cv.boundingRect(c)
                if (bx <= MARGEM_BORDA or by <= MARGEM_BORDA
                        or bx + bw >= w_img - MARGEM_BORDA
                        or by + bh >= h_img - MARGEM_BORDA):
                    continue

                forma = self.classificar(c, area)
                if forma is None:
                    continue

                M = cv.moments(c)
                if M['m00'] == 0:
                    continue
                cx = M['m10'] / M['m00']
                cy = M['m01'] / M['m00']

                rgb = self.rgb_medio(img, c)

                vistas.add(forma)
                self.registrar(forma, cor, rgb, cx, cy)

                cv.drawContours(debug, [c], -1, BGR_DEBUG[cor], 2)
                cv.putText(debug, f'{forma} {cor}', (int(cx) - 40, int(cy)),
                           cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2)

        for forma in list(self.candidatas):
            if forma not in vistas:
                self.candidatas[forma]['perdidos'] += 1
                if self.candidatas[forma]['perdidos'] > FRAMES_PERDIDOS_MAX:
                    del self.candidatas[forma]

        self.verificar_conclusao()

        if self.show_debug:
            cv.putText(debug, f'Figuras: {len(self.figuras)}/{MAX_FIGURAS}', (10, 25),
                       cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 0), 2)
            try:
                cv.imshow('vision_debug', debug)
                cv.waitKey(1)
            except cv.error:
                self.get_logger().warn('Sem display para imshow, desativando debug visual')
                self.show_debug = False

    @staticmethod
    def classificar(contorno, area):
        hull = cv.convexHull(contorno)
        area_hull = cv.contourArea(hull)
        if area_hull == 0 or area / area_hull < SOLIDEZ_MIN:
            return None

        _, raio = cv.minEnclosingCircle(contorno)
        if raio <= 0:
            return None
        razao = area / (math.pi * raio ** 2)

        if razao < RAZAO_TRIANGULO_MAX:
            return 'triangulo'
        if razao < RAZAO_HEXAGONO_MAX:
            return 'hexagono'
        return 'circulo'

    @staticmethod
    def rgb_medio(img_bgr, contorno):
        mask = np.zeros(img_bgr.shape[:2], np.uint8)
        cv.drawContours(mask, [contorno], -1, 255, -1)
        mask = cv.erode(mask, np.ones((3, 3), np.uint8))
        b, g, r, _ = cv.mean(img_bgr, mask=mask)
        return (r, g, b)

    def registrar(self, forma, cor, rgb, cx, cy):
        if forma in self.figuras:
            return
        if any(f['cor'] == cor for f in self.figuras.values()):
            return

        cand = self.candidatas.get(forma)
        if cand is None or cand['cor'] != cor:
            cand = {'cor': cor, 'n': 0, 'perdidos': 0, 'samples': [], 'cx': cx, 'cy': cy}
            self.candidatas[forma] = cand

        cand['n'] += 1
        cand['perdidos'] = 0
        cand['samples'].append(rgb)
        cand['cx'], cand['cy'] = cx, cy

        if cand['n'] >= FRAMES_CONFIRMA:
            r, g, b = np.mean(cand['samples'], axis=0)
            hex_final = '#{:02X}{:02X}{:02X}'.format(
                int(round(r)), int(round(g)), int(round(b)))
            self.figuras[forma] = {'cor': cor, 'rgb_hex': hex_final, 'cx': cx, 'cy': cy}
            del self.candidatas[forma]
            self.get_logger().info(
                f'Figura confirmada: {forma} {cor} {hex_final} '
                f'({len(self.figuras)}/{MAX_FIGURAS})')

    def verificar_conclusao(self):
        if not self.completo and len(self.figuras) >= MAX_FIGURAS:
            self.completo = True
            self.get_logger().info('Visão completa: 3 figuras confirmadas')

    def publish_state(self):
        arr = FiguraArray()
        arr.header.stamp = self.get_clock().now().to_msg()
        arr.header.frame_id = 'camera'
        for forma, d in self.figuras.items():
            f = Figura()
            f.forma = forma
            f.cor = d['cor']
            f.rgb_hex = d['rgb_hex']
            f.centro_x = float(d['cx'])
            f.centro_y = float(d['cy'])
            arr.figuras.append(f)
        self.pub_objects.publish(arr)

        done = Bool()
        done.data = self.completo
        self.pub_complete.publish(done)
       


def main(args=None):
    rclpy.init(args=args)
    node = TraineeVisionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        cv.destroyAllWindows()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
