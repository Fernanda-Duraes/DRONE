// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA__TRAITS_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "precision_interfaces/msg/detail/figura__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace precision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Figura & msg,
  std::ostream & out)
{
  out << "{";
  // member: forma
  {
    out << "forma: ";
    rosidl_generator_traits::value_to_yaml(msg.forma, out);
    out << ", ";
  }

  // member: cor
  {
    out << "cor: ";
    rosidl_generator_traits::value_to_yaml(msg.cor, out);
    out << ", ";
  }

  // member: rgb_hex
  {
    out << "rgb_hex: ";
    rosidl_generator_traits::value_to_yaml(msg.rgb_hex, out);
    out << ", ";
  }

  // member: centro_x
  {
    out << "centro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.centro_x, out);
    out << ", ";
  }

  // member: centro_y
  {
    out << "centro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.centro_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Figura & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: forma
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "forma: ";
    rosidl_generator_traits::value_to_yaml(msg.forma, out);
    out << "\n";
  }

  // member: cor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cor: ";
    rosidl_generator_traits::value_to_yaml(msg.cor, out);
    out << "\n";
  }

  // member: rgb_hex
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rgb_hex: ";
    rosidl_generator_traits::value_to_yaml(msg.rgb_hex, out);
    out << "\n";
  }

  // member: centro_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "centro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.centro_x, out);
    out << "\n";
  }

  // member: centro_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "centro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.centro_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Figura & msg, bool use_flow_style = false)
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
  const precision_interfaces::msg::Figura & msg,
  std::ostream & out, size_t indentation = 0)
{
  precision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use precision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const precision_interfaces::msg::Figura & msg)
{
  return precision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<precision_interfaces::msg::Figura>()
{
  return "precision_interfaces::msg::Figura";
}

template<>
inline const char * name<precision_interfaces::msg::Figura>()
{
  return "precision_interfaces/msg/Figura";
}

template<>
struct has_fixed_size<precision_interfaces::msg::Figura>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<precision_interfaces::msg::Figura>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<precision_interfaces::msg::Figura>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA__TRAITS_HPP_
