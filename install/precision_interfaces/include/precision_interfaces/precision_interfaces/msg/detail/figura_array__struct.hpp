// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_HPP_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'figuras'
#include "precision_interfaces/msg/detail/figura__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__precision_interfaces__msg__FiguraArray __attribute__((deprecated))
#else
# define DEPRECATED__precision_interfaces__msg__FiguraArray __declspec(deprecated)
#endif

namespace precision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FiguraArray_
{
  using Type = FiguraArray_<ContainerAllocator>;

  explicit FiguraArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit FiguraArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _figuras_type =
    std::vector<precision_interfaces::msg::Figura_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<precision_interfaces::msg::Figura_<ContainerAllocator>>>;
  _figuras_type figuras;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__figuras(
    const std::vector<precision_interfaces::msg::Figura_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<precision_interfaces::msg::Figura_<ContainerAllocator>>> & _arg)
  {
    this->figuras = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    precision_interfaces::msg::FiguraArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const precision_interfaces::msg::FiguraArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      precision_interfaces::msg::FiguraArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      precision_interfaces::msg::FiguraArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__precision_interfaces__msg__FiguraArray
    std::shared_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__precision_interfaces__msg__FiguraArray
    std::shared_ptr<precision_interfaces::msg::FiguraArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FiguraArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->figuras != other.figuras) {
      return false;
    }
    return true;
  }
  bool operator!=(const FiguraArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FiguraArray_

// alias to use template instance with default allocator
using FiguraArray =
  precision_interfaces::msg::FiguraArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace precision_interfaces

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_HPP_
