#!usr/bin/python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
class SimplePublisher(Node):
    def __init__(self):
        super().__init__("simple_publisher")
        self.publisher = self.create_publisher(String, "chatter", 10)
        self.counter = 0
        self.frequency = 0.1 #Time taken to send a message
        self.get_logger().info("Publishing at %d Hz" %self.frequency)
        self.timer = self.create_timer(self.frequency, self.timerCallback)

    def timerCallback(self):
        msg = String()
        msg.data = "Hello - counter: %d" % self.counter
        self.publisher.publish(msg)
        self.counter +=1


def main():
    rclpy.init()
    simplePub = SimplePublisher()
    rclpy.spin(simplePub)
    simplePub.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()