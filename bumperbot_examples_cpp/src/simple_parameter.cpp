// #include "simple_parameter.h"

// using std::placeholders::_1;

// SimpleParameter::SimpleParameter() : Node("simple_parameter")
// {
//     declare_parameter<int>("simple_int_param", 28);
//     declare_parameter<std::string>("simple_string_param", "Mee");

//     paramCallback = add_on_set_parameters_callback(std::bind(&SimpleParameter::paramChangeCallback, this, _1));
// }

// rcl_interfaces::msg::SetParametersResult SimpleParameter::paramChangeCallback(const std::vector<rclcpp::Parameter> &parameter)
// {
//     rcl_interfaces::msg::SetParametersResult result;
//     for (auto &param :parameter)
//     {
//         if (param.get_name() == "simple_int_param" && param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER)
//         {
//             RCLCPP_INFO_STREAM(get_logger(), "I Heard " );

//             RCLCPP_INFO_STREAM(get_logger(), "Param simple_int_param changed to " << param.as_int());
//             result.successful = true;
//         }

//         if (param.get_name() == "simple_string_param" && param.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
//         {
//             RCLCPP_INFO_STREAM(get_logger(), "This has changed to: " << param.as_string());
//             result.successful = true;
//         }
//     }
    
    
//     return result;
// }



/*
This is a ROS2 node which uses parameters to change the behaviour of the node depending on the parameters assigned. This can be changed at run time

For this node you will need
Constructor
paramChangeCallback
main

First the Constructor will inherit from Node and be called simple_parameter
    The will initialise two declare_parameters which are templates
    The templates will take a name and default value
    You will also need to create an add_on_set_parameter_callback paramCallback which will be a shared pointer and to bind to a parameterChangeCallbackFunction

Next is the paramChangeCallback which returns SetParameterResult message and takes a vector of rclcpp::Parameters
Then you need to loop through the vectors and find the names of the params and check their type.
*/

#include "simple_parameter.hpp"

using std::placeholders::_1;

SimpleParameter::SimpleParameter() : Node("simple_parameter")
{
    declare_parameter<int>("simple_int_param", 28);
    declare_parameter<std::string>("simple_string_param", "Me");

    paramCallback = add_on_set_parameters_callback(std::bind(&SimpleParameter::paramChangeCallback, this, _1));
}

rcl_interfaces::msg::SetParametersResult SimpleParameter::paramChangeCallback(const std::vector<rclcpp::Parameter> &parameters)
{
    rcl_interfaces::msg::SetParametersResult result;

    for (auto &param : parameters)
    {
        if (param.get_name() == "simple_int_param" && param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER)
        {
            RCLCPP_INFO_STREAM(get_logger(), "The change is " << param.as_int());
            result.successful = true;
        }
        if (param.get_name() == "simple_string_param" && param.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
        {
            RCLCPP_INFO_STREAM(get_logger(), "The change is: " << param.as_string());
            result.successful = true;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleParameter>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}