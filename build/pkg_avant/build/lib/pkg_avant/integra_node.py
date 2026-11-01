#!/usr/bin/env python3
import signal
import time
import sys
import rclpy
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Bool, String
from mavros_msgs.srv import CommandBool, CommandTOL, ParamSetV2, SetMode
from numpy import sqrt
from rcl_interfaces.msg import Parameter, ParameterType, ParameterValue
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data


class IntegraNode(Node):
    def __init__(self):

        self.nav_node_status = "offline"
        self.vision_node_status = "offline"
        self.sound_node_status = "offline"
        self.keyboardInterupted = False

        self.system_state = "offline"

        super().__init__('integra_node')

        self.nav_status_subscriber = self.create_subscription(String,'/pkg_avant/integra/nav_status',callback=self.read_nav_status,qos_profile=10)
        self.vision_status_subscriber = self.create_subscription(String,'/pkg_avant/integra/vision_status',callback=self.read_vision_status,qos_profile=10)
        self.sound_status_subscriber = self.create_subscription(String,'/pkg_avant/integra/sound_status',callback=self.read_sound_status,qos_profile=10)
        self.system_status_publisher = self.create_publisher(String,'/pkg_avant/integra/global_system_status',qos_profile=10)

        self.timer = self.create_timer(timer_period_sec=0.5,callback=self.publish_system_state)

    def publish_system_state(self):

        if (self.sound_node_status == "mission_complete"):
            self.get_logger().info("missao encerrada com sucesso")
            self.keyboardInterupted = True

        if( (not self.keyboardInterupted)
            and self.nav_node_status == "online"
            #and self.vision_node_status == "online"
            #and self.sound_node_status == "online"
        ):
            self.system_state = "online"
        elif (self.keyboardInterupted):
            self.system_state = "abort_mission"

        self.get_logger().info(f"system state is {self.system_state}")
        message = String()
        message.data = self.system_state
        self.system_status_publisher.publish(message)



    def sendKeyboardInteruptSignal(self):
        self.keyboardInterupted= True

    def read_nav_status(self,msg:String):
        self.nav_node_status=msg.data

    def read_vision_status(self,msg:String):
        self.vision_node_status = msg.data

    def read_sound_status(self,msg:String):
        self.sound_node_status=msg.data

def handle_emergencyStop(signum,frame):
    raise KeyboardInterrupt

def main():
    rclpy.init()
    node = IntegraNode()
    signal.signal(signal.SIGINT,handle_emergencyStop)
    #tive que fazer essa logica adicional pra funcionar o control +c porque senao o
    # rclpy se destroi quando o comando de contro c eh dado
    try:
        rclpy.spin(node)
        #rclpy.spin(node)
    except KeyboardInterrupt:
        node.sendKeyboardInteruptSignal()
        node.publish_system_state()
        rclpy.spin_once(node)
        node.destroy_node()
        rclpy.shutdown()


if(__name__=="__main__"):
    main()
