// #include <publisher.h>

// SimplePublisher::SimplePublisher() : Node("simple_publisher"), counter(0)
// {
//     pub_ = create_publisher<std_msgs::msg::String>("talker", 10);
//     timer = create_wall_timer(1s, std::bind(&SimplePublisher::timerCallback, this));
// }

// void SimplePublisher::timerCallback()
// {
//     auto msg = std_msgs::msg::String();
//     msg.data = "Hello ros2 - counter " + std::to_string(counter++);
//     pub_->publish(msg);
// }

// int main(int argc, char *argv[])
// {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<SimplePublisher>();
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }

/*
For a publisher, you need to have 
Constructor
callBack function
main function


The constructor should contain a counter and initialise it to 0
    This will be an indicator of the number of messages there has been
The constructor should also create a publisher with a message type, name and the message buffer
Finally, the constructor should create a wall timer. This will be used to call the callBack function which belongs to the SimplePublisher

The callback function contains the message to be published. You first need to create the message
After creating the message, you need to populate it with content.
Finally, publish the message


In the main function, you need to initialise the ros2 node
then create a node and make a shared pointer to the constructor
After this, you must ensure the node will continue until it is closed
Finally, ros will need to be shutdown

*/

#include <publisher.h>

SimplePublisher::SimplePublisher() 
    : Node("simple_publisher"), m_counter(0)
{
    m_pub = create_publisher<std_msgs::msg::String>("talker", 10);
    m_timer = create_wall_timer(1s, std::bind(&SimplePublisher::callback, this));
}

void SimplePublisher::callback()
{
    std_msgs::msg::String message;
    message.data = "This is a message " + std::to_string(m_counter++);
    RCLCPP_INFO_STREAM(get_logger(), "Message: " << message.data.c_str());
    m_pub->publish(message);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimplePublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}