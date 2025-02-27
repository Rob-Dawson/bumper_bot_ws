import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter
class SimpleParameter(Node):
    def __init__(self):
        super().__init__("simple_parameter")
        
        self.declare_parameter("simple_int_param", 28)
        self.declare_parameter("simple_string_param", "MEEE")

        self.add_on_set_parameters_callback(self.paramChangeCallback)

    def paramChangeCallback(self, params):
        result = SetParametersResult()
        for param in params:
            if param.name == "simple_int_param" and param.type_ == Parameter.Type.INTEGER:
                self.get_logger().info("Param simple_int_param changed to %d" %param.value)
                result.successful=True


            if param.name =="simple_string_param" and param.type_ == Parameter.Type.STRING:
                self.get_logger().info("Param simple_string_param changed to %s" %param.value)
                result.successful=True
        return result    


def main():
    rclpy.init()
    param = SimpleParameter()
    rclpy.spin(param)
    param.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()