// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__precision_interfaces__msg__Figura __attribute__((deprecated))
#else
# define DEPRECATED__precision_interfaces__msg__Figura __declspec(deprecated)
#endif

namespace precision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Figura_
{
  using Type = Figura_<ContainerAllocator>;

  explicit Figura_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forma = "";
      this->cor = "";
      this->rgb_hex = "";
      this->centro_x = 0.0f;
      this->centro_y = 0.0f;
    }
  }

  explicit Figura_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : forma(_alloc),
    cor(_alloc),
    rgb_hex(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forma = "";
      this->cor = "";
      this->rgb_hex = "";
      this->centro_x = 0.0f;
      this->centro_y = 0.0f;
    }
  }

  // field types and members
  using _forma_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _forma_type forma;
  using _cor_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cor_type cor;
  using _rgb_hex_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _rgb_hex_type rgb_hex;
  using _centro_x_type =
    float;
  _centro_x_type centro_x;
  using _centro_y_type =
    float;
  _centro_y_type centro_y;

  // setters for named parameter idiom
  Type & set__forma(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->forma = _arg;
    return *this;
  }
  Type & set__cor(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cor = _arg;
    return *this;
  }
  Type & set__rgb_hex(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->rgb_hex = _arg;
    return *this;
  }
  Type & set__centro_x(
    const float & _arg)
  {
    this->centro_x = _arg;
    return *this;
  }
  Type & set__centro_y(
    const float & _arg)
  {
    this->centro_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    precision_interfaces::msg::Figura_<ContainerAllocator> *;
  using ConstRawPtr =
    const precision_interfaces::msg::Figura_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<precision_interfaces::msg::Figura_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<precision_interfaces::msg::Figura_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      precision_interfaces::msg::Figura_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<precision_interfaces::msg::Figura_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      precision_interfaces::msg::Figura_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<precision_interfaces::msg::Figura_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<precision_interfaces::msg::Figura_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<precision_interfaces::msg::Figura_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__precision_interfaces__msg__Figura
    std::shared_ptr<precision_interfaces::msg::Figura_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__precision_interfaces__msg__Figura
    std::shared_ptr<precision_interfaces::msg::Figura_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Figura_ & other) const
  {
    if (this->forma != other.forma) {
      return false;
    }
    if (this->cor != other.cor) {
      return false;
    }
    if (this->rgb_hex != other.rgb_hex) {
      return false;
    }
    if (this->centro_x != other.centro_x) {
      return false;
    }
    if (this->centro_y != other.centro_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Figura_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Figura_

// alias to use template instance with default allocator
using Figura =
  precision_interfaces::msg::Figura_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace precision_interfaces

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_HPP_
