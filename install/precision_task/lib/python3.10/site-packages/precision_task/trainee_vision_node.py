import math
import rclpy
from rclpy.node import Node
import cv2 as cv
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Bool

from precision_interfaces.msg import Figura, FiguraArray

S_MIN = 100
V_MIN = 50
AREA_MIN = 300
EPS_FATOR = 0.02
CIRC_MIN = 0.80
FRAMES_CONFIRMA = 5
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
        self.declare_parameter('pose_topic', '/local_position/pose')
        self.show_debug = self.get_parameter('show_debug').value

        self.create_subscription(Image, '/camera/image_raw', self.read_im, 10)
        self.create_subscription(CameraInfo, '/camera/camera_info', self.camera_info, 10)

        self.pub_objects = self.create_publisher(FiguraArray, '/vision/objects', 10)
        self.pub_complete = self.create_publisher(Bool, '/vision/complete', 10)

        self.bridge = CvBridge()
        self.K = self.D = None
        self.nova_K = None
        self.roi = None
        self.pose = None

        self.figuras = {}
        self.candidatas = {}
        self.completo = False

        self.create_timer(0.5, self.publish_state)

        self.get_logger().info('Nó de visão ativo, aguardando imagens da câmera')

    def camera_info(self, info: CameraInfo):
        if self.K is not None:
            return
        self.K = np.array(info.k).reshape(3, 3)
        self.D = np.array(info.d)
        size = (info.width, info.height)
        self.nova_K, self.roi = cv.getOptimalNewCameraMatrix(
            self.K, self.D, size, 1, size
        )

    def undistort(self, img):
        x, y, rw, rh = self.roi
        img_corrigida = cv.undistort(img, self.K, self.D, None, self.nova_K)
        if rw > 0 and rh > 0:
            img_corrigida = img_corrigida[y:y + rh, x:x + rw]
        else:
            x = y = 0
        cx = self.nova_K[0][2] - x
        cy = self.nova_K[1][2] - y
        return img_corrigida, cx, cy

    def read_im(self, msg: Image):
        if self.K is None:
            return

        img, _, _ = self.undistort(self.bridge.imgmsg_to_cv2(msg, 'bgr8'))
        debug = img.copy()

        hsv = cv.cvtColor(cv.GaussianBlur(img, (5, 5), 0), cv.COLOR_BGR2HSV)

        vistas = set()

        for cor, faixas in FAIXAS.items():
            mask = np.zeros(hsv.shape[:2], np.uint8)
            for lo, hi in faixas:
                mask |= cv.inRange(hsv, np.array(lo), np.array(hi))

            kernel = np.ones((5, 5), np.uint8)
            mask = cv.morphologyEx(mask, cv.MORPH_OPEN, kernel)
            mask = cv.morphologyEx(mask, cv.MORPH_CLOSE, kernel)

            contornos, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

            for c in contornos:
                area = cv.contourArea(c)
                if area < AREA_MIN:
                    continue

                forma = self.classificar(c, area)
                if forma is None:
                    continue

                M = cv.moments(c)
                if M['m00'] == 0:
                    continue
                cx = M['m10'] / M['m00']
                cy = M['m01'] / M['m00']

                rgb_hex = self.hex_medio(img, c)

                vistas.add(forma)
                self.registrar(forma, cor, rgb_hex, cx, cy)

                cv.drawContours(debug, [c], -1, BGR_DEBUG[cor], 2)
                cv.putText(debug, f'{forma} {cor} {rgb_hex}', (int(cx) - 40, int(cy)),
                           cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2)

        for forma in list(self.candidatas):
            if forma not in vistas:
                del self.candidatas[forma]

        self.verificar_conclusao()

        if self.show_debug:
            cv.putText(debug, f'Figuras: {len(self.figuras)}/{MAX_FIGURAS}', (10, 25),
                       cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 0), 2)
            cv.imshow('vision_debug', debug)
            cv.waitKey(1)

    @staticmethod

    def classificar(contorno, area):
        per = cv.arcLength(contorno, True)
        if per == 0:
            return None
        aprox = cv.approxPolyDP(contorno, EPS_FATOR * per, True)
        if not cv.isContourConvex(aprox):
            return None
        n = len(aprox)
        circularidade = 4 * math.pi * area / (per ** 2)

        if n == 3:
            return 'triangulo'
        if n == 6:
            return 'hexagono'
        if n > 6 and circularidade >= CIRC_MIN:
            return 'circulo'
        return None
    

    @staticmethod
    def hex_medio(img_bgr, contorno):
        mask = np.zeros(img_bgr.shape[:2], np.uint8)
        cv.drawContours(mask, [contorno], -1, 255, -1)
        mask = cv.erode(mask, np.ones((5, 5), np.uint8))
        b, g, r, _ = cv.mean(img_bgr, mask=mask)
        return '#{:02X}{:02X}{:02X}'.format(int(round(r)), int(round(g)), int(round(b)))

    def registrar(self, forma, cor, rgb_hex, cx, cy):
        if forma in self.figuras:
            return
        if any(f['cor'] == cor for f in self.figuras.values()):
            return

        cand = self.candidatas.get(forma)
        if cand is None or cand['cor'] != cor:
            cand = {'cor': cor, 'n': 0, 'samples': [], 'cx': cx, 'cy': cy}
            self.candidatas[forma] = cand

        cand['n'] += 1
        cand['samples'].append(rgb_hex)
        cand['cx'], cand['cy'] = cx, cy

        if cand['n'] >= FRAMES_CONFIRMA:
            hex_final = max(set(cand['samples']), key=cand['samples'].count)
            self.figuras[forma] = {'cor': cor, 'rgb_hex': hex_final, 'cx': cx, 'cy': cy}
            del self.candidatas[forma]
            self.get_logger().info(
                f'Figura confirmada: {forma} {cor} {hex_final} '
                f'({len(self.figuras)}/{MAX_FIGURAS})')

    def verificar_conclusao(self):
        if not self.completo and len(self.figuras) >= MAX_FIGURAS:
            self.completo = True

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