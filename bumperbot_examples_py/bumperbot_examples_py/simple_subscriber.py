#!usr/bin/python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SimpleSub(Node):
    def __init__(self):
        super().__init__("simpleSub")
        self.sub = self.create_subscription(topic="talker", msg_type=String, callback=self.msgCallback, qos_profile=10)

    def msgCallback(self, msg):
        self.get_logger().info(f"Heard {msg.data}")

def main():
    rclpy.init()
    simpleSub = SimpleSub()
    rclpy.spin(simpleSub)
    simpleSub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()