// #ifndef SIMPLE_PARAMETER_H
// #define SIMPLE_PARAMETER_H

// #include <rclcpp/rclcpp.hpp>
// #include <rcl_logging_interface/rcl_logging_interface.h>
// #include <rclcpp/parameter.hpp>
// #include <vector>
// class SimpleParameter : public rclcpp::Node
// {
// public:
//     SimpleParameter();
// private:
//     rcl_interfaces::msg::SetParametersResult paramChangeCallback(const std::vector<rclcpp::Parameter> &parameters);
//     OnSetParametersCallbackHandle::SharedPtr paramCallback;
// };
// #endif

#ifndef SIMPLE_PARAMETER_H
#define SIMPLE_PARAMETER_H

#include <rclcpp/rclcpp.hpp>
#include <rcl_logging_interface/rcl_logging_interface.h>
#include <rclcpp/parameter.hpp>
#include <vector>
#include <string>

class SimpleParameter : public rclcpp::Node
{
public:
    SimpleParameter();

private:
    rcl_interfaces::msg::SetParametersResult paramChangeCallback(const std::vector<rclcpp::Parameter> &parameters);
    OnSetParametersCallbackHandle::SharedPtr paramCallback;
};

#endif