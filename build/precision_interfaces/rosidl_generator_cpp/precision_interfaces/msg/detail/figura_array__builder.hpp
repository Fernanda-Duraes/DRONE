// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__BUILDER_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "precision_interfaces/msg/detail/figura_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace precision_interfaces
{

namespace msg
{

namespace builder
{

class Init_FiguraArray_figuras
{
public:
  explicit Init_FiguraArray_figuras(::precision_interfaces::msg::FiguraArray & msg)
  : msg_(msg)
  {}
  ::precision_interfaces::msg::FiguraArray figuras(::precision_interfaces::msg::FiguraArray::_figuras_type arg)
  {
    msg_.figuras = std::move(arg);
    return std::move(msg_);
  }

private:
  ::precision_interfaces::msg::FiguraArray msg_;
};

class Init_FiguraArray_header
{
public:
  Init_FiguraArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FiguraArray_figuras header(::precision_interfaces::msg::FiguraArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FiguraArray_figuras(msg_);
  }

private:
  ::precision_interfaces::msg::FiguraArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::precision_interfaces::msg::FiguraArray>()
{
  return precision_interfaces::msg::builder::Init_FiguraArray_header();
}

}  // namespace precision_interfaces

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__BUILDER_HPP_
