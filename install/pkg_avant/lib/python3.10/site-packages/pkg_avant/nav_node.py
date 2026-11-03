#!/usr/bin/env python3
import signal
import time

import rclpy
from geometry_msgs.msg import PoseStamped
from mavros_msgs.srv import CommandBool, CommandTOL, ParamSetV2, SetMode
from numpy import sqrt
from rcl_interfaces.msg import Parameter, ParameterType, ParameterValue
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from std_msgs.msg import String

def handle_emergencyStop(signum,frame):
    raise KeyboardInterrupt

class NavNode(Node):
    def __init__(self):
        self.h = 6.0 #altura de voo escolhida
        self.waypointList = [ (6.3, -3, self.h), (-6.3, -3, self.h), (-6.3, -1.5, self.h), (6.3, -1.5, self.h), (6.3, 0, self.h), (-6.3, 0, self.h), (-6.3, 1.5, self.h), (6.3, 1.5, self.h), (6.3, 3, self.h), (-6.3, 3, self.h) ]
        #lista de waypoints a serem visitados no vasculhamento
        self.tolerance = 0.1 #tolerancia em metros
        self.maxSpeed = 100 #velocidade maxima cm/s
        self.maxMissionTime = 300 # tempo maximo para a missao

        self.currentPose = PoseStamped()
        super().__init__('nav_node')
        self.startTime = time.monotonic() # tempo de inicio em segundos
        self.get_logger().info('Esperando conexão com MAVROS...')



        # Clientes para os serviços MAVROS
        self.set_mode_client = self.create_client(SetMode, '/mavros/set_mode')
        self.arming_client = self.create_client(CommandBool, '/mavros/cmd/arming')
        self.takeoff_client = self.create_client(CommandTOL, '/mavros/cmd/takeoff')
        self.land_client = self.create_client(CommandTOL, '/mavros/cmd/land')

        #todas quinquilharias relacionadas aos processos do no de integracao
        # o no de integracao basicamente espera todos os nos estarem inicializados para
        # entao permitir que eles facam suas funcoes
        self.nav_state = "offline"
        self.system_state = "offline"
        self.system_state_subscriber = self.create_subscription(String,'/pkg_avant/integra/global_system_status',callback=self.readSystemStatus,qos_profile=10)
        self.nav_node_state_publisher = self.create_publisher(String,'/pkg_avant/integra/nav_status',10)
        self.timer = self.create_timer(timer_period_sec=0.5,callback=self.publish_nav_state)


        self.pose_subscriber = self.create_subscription(PoseStamped,'/mavros/local_position/pose',callback=self.readPose,qos_profile=qos_profile_sensor_data)
        self.waypoint_publisher = self.create_publisher(PoseStamped,'/mavros/setpoint_position/local',10)
        self.parameter_client = self.create_client(ParamSetV2,'/mavros/param/set')


        # Aguarda convexão MAVROS
        # Qualquer service pode ser usado para testar a conexão, não necessariamente o arming
        while rclpy.ok() and not self.arming_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Aguardando serviços do MAVROS...')



        # Roda o movimento
        self.get_logger().info('Conexão estabelecida. Iniciando sequência de voo.')
        self.setParameters('WPNAV_SPD',self.maxSpeed)
        self.setParameters('WPNAV_ACCEL',self.maxSpeed/2)
        self.setParameters('RTL_ALT',self.h*100)
        self.setParameters('RTL_CLIMB_MIN',self.h*100/3)

        self.nav_state = "online"

    """*
    Le o estado atual do sistema,
    se offline, fica esperando
    se online, libera o programa pra iniciar o resto dos trem
    se abort_mission, cancela a missao e pousa na base
    """
    def readSystemStatus(self,message:String):

        self.system_state=message.data
        if(self.system_state=="abort_mission"):
            self.system_state="abort_mission"
            raise KeyboardInterrupt


    """*
    Publica o estado atual do sistema a cada 0.5 segundos
    O no de integracao usa isso pra ver se o no de navegacao esta inicializado
    """
    def publish_nav_state(self):
        message = String()
        message.data = self.nav_state
        self.nav_node_state_publisher.publish(message)

    def setParameters(self,name,value):
        """
        Define os parametros do controlador de voo
        """
        req1 = ParamSetV2.Request()
        req1.force_set=False
        req1.param_id=name
        req1.value = ParameterValue(
            type=ParameterType.PARAMETER_DOUBLE,
            double_value=float(value)
        )
        future=self.parameter_client.call_async(req1)
        rclpy.spin_until_future_complete(self,future)
        if future.result() is not None:
            self.get_logger().info(f"Parametro {name} configurado para {value}")


    def readPose(self,msg):
        """
        Le a posiçao do drone em relacao ao Home
        """
        self.currentPose = msg

    def set_mode(self, mode_name):
            req = SetMode.Request()
            req.custom_mode = mode_name

            future = self.set_mode_client.call_async(req)

            rclpy.spin_until_future_complete(self, future)
            if future.result() is not None and future.result().mode_sent:
                self.get_logger().info(f'Modo {mode_name} definido.')

    def arm(self):
        req = CommandBool.Request()
        req.value = True
        self.arming_client.call_async(req)

        future = self.arming_client.call_async(req)

        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info('Drone armado.')

    def takeoff(self, altitude=2.0):
        req = CommandTOL.Request()
        req.altitude = altitude
        self.takeoff_client.call_async(req)

        future = self.takeoff_client.call_async(req)

        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info(f'Decolando para {altitude} metros.')

    def setWaypoint(self,i,x,y,z):
        """
        Configura um novo waypoint alvo para o drone
        por consistencia o indice -1 corresponde ao Home
        """
        msg = PoseStamped()
        msg.pose.position.x = float(x)
        msg.pose.position.y = float(y)
        msg.pose.position.z = float(z)

        msg.pose.orientation.x= float(0)
        msg.pose.orientation.y= float(0)
        msg.pose.orientation.z= float(1)
        msg.pose.orientation.w= float(0)

        self.waypoint_publisher.publish(msg=msg)
        self.get_logger().info(f"enviando waypoint {i} de coordenadas x={x} y={y} z={z}")

    def travelWaypointsInOrder(self):
            """
            Viaja entre todos os waypoints definidos na lista presente em __init__
            """
            self.get_logger().info('Começando a movimentacao para os waypoints')
            for i,(x,y,z) in enumerate(self.waypointList,start=0):
                self.setWaypoint(i,x,y,z)
                while rclpy.ok():
                    rclpy.spin_once(self,timeout_sec=1)

                    pose = self.currentPose.pose.position
                    #self.get_logger().info(f"Coordenadas atuais {pose.x} {pose.y} {pose.z} ")
                    distanceToWaypoint = sqrt(
                        (pose.x-x)**2 +
                        (pose.y-y)**2 +
                        (pose.z-z)**2)
                    if distanceToWaypoint<self.tolerance:
                        self.get_logger().info('Waypoint Alcançado!')
                        time.sleep(0.2) #da tempo para o drone estabilizar apos um waypoint
                        break
                    if time.monotonic()-self.startTime>self.maxMissionTime:
                        self.get_logger().info('Tempo limte alcançado! Indo para a base e pousando o drone')
                        return




    def emergencyLand(self):
        """
        Essa e a funcao chamada no caso de apertar control+c durante a execucao
        """
        if rclpy.ok():
            # manda um request RTK
            req = SetMode.Request()
            req.custom_mode = 'RTL'

            future = self.set_mode_client.call_async(req)
            rclpy.spin_until_future_complete(self, future)

            result = future.result()
            if result is not None and result.mode_sent:
                self.get_logger().info(
                    'RTL iniciado, voltando para casa.'
                )

    def land(self):
        """O pouso normal feito quando o drone segue todos os waypoints"""
        self.get_logger().info('Indo para a Base...')
        self.setWaypoint(-1,0,0,2)
        while rclpy.ok():
            rclpy.spin_once(self,timeout_sec=0.1)
            pose = self.currentPose.pose.position
            distanceToWaypoint = sqrt(
                (pose.x)**2 +
                (pose.y)**2 +
                (pose.z-2)**2)
            if distanceToWaypoint<self.tolerance:
                self.get_logger().info('Base Alcançada!')
                time.sleep(0.5) # da um tempo para o drone estabilizar apos voltar ao home
                break

        req = CommandTOL.Request()
        self.land_client.call_async(req)

        future = self.land_client.call_async(req)

        rclpy.spin_until_future_complete(self, future)
        if future.result().success:
            self.get_logger().info('Pousando...')


    def run_mission(self):
        while(self.system_state != "online"):
            rclpy.spin_once(self)
        self.startTime = time.monotonic()
        self.set_mode("GUIDED")  # modo que permite controle por comandos
        time.sleep(1)
        self.arm()
        time.sleep(1)
        self.takeoff(altitude=self.h)
        time.sleep(7)
        self.travelWaypointsInOrder()
        self.land()
        time.sleep(3)
        self.get_logger().info('Missão finalizada.')
        self.get_logger().info(f'Tempo total da missao: {time.monotonic()-self.startTime} segundos')


def main(args=None):


    rclpy.init(args=args)
    node = NavNode()


    signal.signal(signal.SIGINT,handle_emergencyStop)
    #tive que fazer essa logica adicional pra funcionar o control +c porque senao o
    # rclpy se destroi quando o comando de contro c eh dado

    try:
        node.run_mission()
        #rclpy.spin(node)
    except KeyboardInterrupt:
        node.emergencyLand()
    node.destroy_node()
    rclpy.shutdown()




if __name__ == '__main__':
    main()