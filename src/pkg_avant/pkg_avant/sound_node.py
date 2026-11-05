
from rclpy.node import Node
import rclpy
from std_msgs.msg import String, Bool
from precision_interfaces.msg import FiguraArray
import os
import subprocess


class SoundNode(Node):

    def __init__(self):
        super().__init__('sound_node')

        self.nav_status = "offline"
        self.sound_state = "online"
        self.figuras = None
        self.visao_completa = False
        self.sequencia_executada = False

        self.figura_subscriber = self.create_subscription(FiguraArray,'/vision/objects',self.receber_figuras,10)
        self.nav_status_subscriber = self.create_subscription(String, '/pkg_avant/integra/nav_status', self.read_nav_status, 10)
        self.sound_node_state_publisher = self.create_publisher(String, '/pkg_avant/integra/sound_status', 10)

        self.caminho_sons = "./src/pkg_avant/pkg_avant/" #onde os sons estao localizados
        self.timer_status = self.create_timer(0.5, self.publish_sound_state)
        self.timer = self.create_timer(0.1, self.verificar_inicio)
        self.get_logger().info("Nó de som ativo. Aguardando pouso completo.")

    def publish_sound_state(self):
        msg = String()
        msg.data = self.sound_state
        self.sound_node_state_publisher.publish(msg)

    def receber_figuras(self, msg: FiguraArray):
        self.figuras = msg.figuras


    def read_nav_status(self, msg: String):
        self.nav_status = msg.data

    def verificar_inicio(self):

        if self.nav_status == "mission_complete" and self.figuras and not self.sequencia_executada:
            self.sequencia_executada = True
            self.get_logger().info("Pouso completo! Iniciando áudios.")
            self.processar_e_tocar(self.figuras)
            self.get_logger().info("Todos os áudios foram reproduzidos!")
            self.timer.cancel()

            self.sound_state = "mission_complete"
            msg = String()
            msg.data = self.sound_state
            self.sound_node_state_publisher.publish(msg)

    def processar_e_tocar(self, figuras):

        figuras_ordenadas = sorted(
            figuras,
            key=lambda fig: int(fig.rgb_hex.replace("#", ""), 16)
        )
        for fig in figuras_ordenadas:
            self.get_logger().info(f"Cor: {fig.cor} | Forma: {fig.forma}")
            self.tocar_audio_forma(fig.forma)

    def tocar_audio_forma(self, forma):
        if "circulo" in forma:
            arquivo = "circulo.mp3"

        elif "hexagono" in forma:
            arquivo = "hexagono.mp3"

        elif "triangulo" in forma:
            arquivo = "triangulo.mp3"

        else:
            self.get_logger().warn(f"Forma desconhecida: {forma}")
            return

        caminho = os.path.join(self.caminho_sons, arquivo)
        if os.path.exists(caminho):
            self.get_logger().info(f"Tocando: {forma}")
            try:
                subprocess.run(
                    ['mpg123', '-q', caminho],
                    check=True
                )
            except Exception as e:
                self.get_logger().error(f"Erro no áudio: {e}")

        else:
            self.get_logger().error(f"Arquivo não encontrado: {caminho}")


def main(args=None):

    rclpy.init(args=args)
    node = SoundNode()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
