// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA__BUILDER_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "precision_interfaces/msg/detail/figura__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace precision_interfaces
{

namespace msg
{

namespace builder
{

class Init_Figura_centro_y
{
public:
  explicit Init_Figura_centro_y(::precision_interfaces::msg::Figura & msg)
  : msg_(msg)
  {}
  ::precision_interfaces::msg::Figura centro_y(::precision_interfaces::msg::Figura::_centro_y_type arg)
  {
    msg_.centro_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::precision_interfaces::msg::Figura msg_;
};

class Init_Figura_centro_x
{
public:
  explicit Init_Figura_centro_x(::precision_interfaces::msg::Figura & msg)
  : msg_(msg)
  {}
  Init_Figura_centro_y centro_x(::precision_interfaces::msg::Figura::_centro_x_type arg)
  {
    msg_.centro_x = std::move(arg);
    return Init_Figura_centro_y(msg_);
  }

private:
  ::precision_interfaces::msg::Figura msg_;
};

class Init_Figura_rgb_hex
{
public:
  explicit Init_Figura_rgb_hex(::precision_interfaces::msg::Figura & msg)
  : msg_(msg)
  {}
  Init_Figura_centro_x rgb_hex(::precision_interfaces::msg::Figura::_rgb_hex_type arg)
  {
    msg_.rgb_hex = std::move(arg);
    return Init_Figura_centro_x(msg_);
  }

private:
  ::precision_interfaces::msg::Figura msg_;
};

class Init_Figura_cor
{
public:
  explicit Init_Figura_cor(::precision_interfaces::msg::Figura & msg)
  : msg_(msg)
  {}
  Init_Figura_rgb_hex cor(::precision_interfaces::msg::Figura::_cor_type arg)
  {
    msg_.cor = std::move(arg);
    return Init_Figura_rgb_hex(msg_);
  }

private:
  ::precision_interfaces::msg::Figura msg_;
};

class Init_Figura_forma
{
public:
  Init_Figura_forma()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Figura_cor forma(::precision_interfaces::msg::Figura::_forma_type arg)
  {
    msg_.forma = std::move(arg);
    return Init_Figura_cor(msg_);
  }

private:
  ::precision_interfaces::msg::Figura msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::precision_interfaces::msg::Figura>()
{
  return precision_interfaces::msg::builder::Init_Figura_forma();
}

}  // namespace precision_interfaces

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA__BUILDER_HPP_
