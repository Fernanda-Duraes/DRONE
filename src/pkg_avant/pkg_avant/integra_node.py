#!/usr/bin/env python3
import signal
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class IntegraNode(Node):

    def __init__(self):
        super().__init__('integra_node')

        self.nav_node_status = "offline"
        self.vision_node_status = "offline"
        self.sound_node_status = "offline"
        self.keyboardInterupted = False

        self.system_state = "offline"
        self.last_published_state = None
        #a ideia é manter o último estado publicado para evitar publicar o mesmo estado várias vezes seguidas, o que poderia gerar logs desnecessários.
        #e deixar o prompt limpo
        self._last_nav_status = None
        self._last_vision_status = None
        self._last_sound_status = None

        # Leitores dos estados dos nós
        self.nav_status_subscriber = self.create_subscription(String, '/pkg_avant/integra/nav_status', self.read_nav_status, 10)
        self.vision_status_subscriber = self.create_subscription(String, '/pkg_avant/integra/vision_status', self.read_vision_status, 10)
        self.sound_status_subscriber = self.create_subscription(String, '/pkg_avant/integra/sound_status', self.read_sound_status, 10)
        
        # Publicador do estado global
        self.system_status_publisher = self.create_publisher(String, '/pkg_avant/integra/global_system_status', 10)
        
        self.timer = self.create_timer(0.5, self.publish_system_state)

    def sendKeyboardInteruptSignal(self):
        self.keyboardInterupted = True

    def read_nav_status(self, msg: String):
        self.nav_node_status = msg.data

    def read_vision_status(self, msg: String):
        self.vision_node_status = msg.data

    def read_sound_status(self, msg: String):
        self.sound_node_status = msg.data

    def atualizacao_status(self):
        """Registra logs apenas quando um dos nós muda de estado individualmente."""
        if self.nav_node_status != self._last_nav_status:
            if self.nav_node_status == "online":
                self.get_logger().info("Nó de navegação iniciado")
            elif self.nav_node_status == "mission_complete":
                self.get_logger().info("Nó de navegação finalizado")
            self._last_nav_status = self.nav_node_status

        if self.vision_node_status != self._last_vision_status:
            if self.vision_node_status == "online":
                self.get_logger().info("Nó de visão iniciado")
            elif self.vision_node_status == "mission_complete":
                self.get_logger().info("Nó de visão finalizado")
            self._last_vision_status = self.vision_node_status

        if self.sound_node_status != self._last_sound_status:
            if self.sound_node_status == "online":
                self.get_logger().info("Nó de som iniciado")
            elif self.sound_node_status == "mission_complete":
                self.get_logger().info("Nó de som finalizado")
            self._last_sound_status = self.sound_node_status

    def publish_system_state(self):
        self.atualizacao_status()

        # Determina o novo estado global
        if (not self.keyboardInterupted 
            and self.sound_node_status == "mission_complete" 
            and self.vision_node_status == "mission_complete" 
            and self.nav_node_status == "mission_complete"):
            self.system_state = "mission_complete"
            self.keyboardInterupted = True

        elif (not self.keyboardInterupted
              and self.nav_node_status == "online"
              and self.vision_node_status == "online"
              and self.sound_node_status == "online"):
            self.system_state = "online"

        elif self.keyboardInterupted:
            self.system_state = "abort_mission"
        
        else:
            self.system_state = "offline"

        if self.system_state != self.last_published_state:
            if self.system_state == "abort_mission":
                self.get_logger().info("Missão abortada")
            else:
                self.get_logger().info(f"Sistema em {self.system_state}")

            message = String()
            message.data = self.system_state
            self.system_status_publisher.publish(message)
            self.last_published_state = self.system_state



def main(args=None):
    rclpy.init(args=args)
    node = IntegraNode()    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()