// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__TRAITS_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "precision_interfaces/msg/detail/figura_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'figuras'
#include "precision_interfaces/msg/detail/figura__traits.hpp"

namespace precision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FiguraArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: figuras
  {
    if (msg.figuras.size() == 0) {
      out << "figuras: []";
    } else {
      out << "figuras: [";
      size_t pending_items = msg.figuras.size();
      for (auto item : msg.figuras) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FiguraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: figuras
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.figuras.size() == 0) {
      out << "figuras: []\n";
    } else {
      out << "figuras:\n";
      for (auto item : msg.figuras) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FiguraArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace precision_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use precision_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const precision_interfaces::msg::FiguraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  precision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use precision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const precision_interfaces::msg::FiguraArray & msg)
{
  return precision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<precision_interfaces::msg::FiguraArray>()
{
  return "precision_interfaces::msg::FiguraArray";
}

template<>
inline const char * name<precision_interfaces::msg::FiguraArray>()
{
  return "precision_interfaces/msg/FiguraArray";
}

template<>
struct has_fixed_size<precision_interfaces::msg::FiguraArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<precision_interfaces::msg::FiguraArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<precision_interfaces::msg::FiguraArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__TRAITS_HPP_
