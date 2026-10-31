// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice
#include "precision_interfaces/msg/detail/figura__rosidl_typesupport_fastrtps_cpp.hpp"
#include "precision_interfaces/msg/detail/figura__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace precision_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_precision_interfaces
cdr_serialize(
  const precision_interfaces::msg::Figura & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: forma
  cdr << ros_message.forma;
  // Member: cor
  cdr << ros_message.cor;
  // Member: rgb_hex
  cdr << ros_message.rgb_hex;
  // Member: centro_x
  cdr << ros_message.centro_x;
  // Member: centro_y
  cdr << ros_message.centro_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_precision_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  precision_interfaces::msg::Figura & ros_message)
{
  // Member: forma
  cdr >> ros_message.forma;

  // Member: cor
  cdr >> ros_message.cor;

  // Member: rgb_hex
  cdr >> ros_message.rgb_hex;

  // Member: centro_x
  cdr >> ros_message.centro_x;

  // Member: centro_y
  cdr >> ros_message.centro_y;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_precision_interfaces
get_serialized_size(
  const precision_interfaces::msg::Figura & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: forma
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.forma.size() + 1);
  // Member: cor
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.cor.size() + 1);
  // Member: rgb_hex
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.rgb_hex.size() + 1);
  // Member: centro_x
  {
    size_t item_size = sizeof(ros_message.centro_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: centro_y
  {
    size_t item_size = sizeof(ros_message.centro_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_precision_interfaces
max_serialized_size_Figura(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: forma
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: cor
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: rgb_hex
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: centro_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: centro_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = precision_interfaces::msg::Figura;
    is_plain =
      (
      offsetof(DataType, centro_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Figura__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const precision_interfaces::msg::Figura *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Figura__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<precision_interfaces::msg::Figura *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Figura__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const precision_interfaces::msg::Figura *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Figura__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Figura(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Figura__callbacks = {
  "precision_interfaces::msg",
  "Figura",
  _Figura__cdr_serialize,
  _Figura__cdr_deserialize,
  _Figura__get_serialized_size,
  _Figura__max_serialized_size
};

static rosidl_message_type_support_t _Figura__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Figura__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace precision_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_precision_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<precision_interfaces::msg::Figura>()
{
  return &precision_interfaces::msg::typesupport_fastrtps_cpp::_Figura__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, precision_interfaces, msg, Figura)() {
  return &precision_interfaces::msg::typesupport_fastrtps_cpp::_Figura__handle;
}

#ifdef __cplusplus
}
#endif
