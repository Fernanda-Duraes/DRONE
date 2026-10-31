#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2

class NodeApresentacao(Node):
    def __init__(self):
        super().__init__(node_name="node_de_teste")
        self.camera_info_received = False
        self.infosubscription = self.create_subscription(CameraInfo,'/camera/camera_info',self.info_callback,10)

        self.subscription = self.create_subscription(Image,'/camera/image_raw',self.image_callback,10)
        self.bridge = CvBridge()
        # Mensagem "Hello World"
        self.get_logger().info("HAAAAAAello world!")

    def info_callback(self,msg):
        if not self.camera_info_received:

                self.get_logger().info('Camera information received:')
                self.get_logger().info(
                    f'Resolution: {msg.width} x {msg.height}'
                )

                self.get_logger().info(
                    f'Focal length: fx={msg.k[0]}, fy={msg.k[4]}'
                )

                self.get_logger().info(
                    f'Principal point: cx={msg.k[2]}, cy={msg.k[5]}'
                )

                self.get_logger().info(
                    f'Distortion coefficients: {msg.d}'
                )

                self.camera_info_received = True

    def image_callback(self,msg):
        # Convert ROS Image message to OpenCV image
        frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding='bgr8'
        )

        # Display image
        cv2.imshow('gz Camera', frame)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = NodeApresentacao()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ ==  '__main__':
    main()
