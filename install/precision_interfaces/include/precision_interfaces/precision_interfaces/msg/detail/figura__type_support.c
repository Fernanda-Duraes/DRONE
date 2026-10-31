// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "precision_interfaces/msg/detail/figura__rosidl_typesupport_introspection_c.h"
#include "precision_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "precision_interfaces/msg/detail/figura__functions.h"
#include "precision_interfaces/msg/detail/figura__struct.h"


// Include directives for member types
// Member `forma`
// Member `cor`
// Member `rgb_hex`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  precision_interfaces__msg__Figura__init(message_memory);
}

void precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_fini_function(void * message_memory)
{
  precision_interfaces__msg__Figura__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_member_array[5] = {
  {
    "forma",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__Figura, forma),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cor",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__Figura, cor),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rgb_hex",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__Figura, rgb_hex),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "centro_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__Figura, centro_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "centro_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__Figura, centro_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_members = {
  "precision_interfaces__msg",  // message namespace
  "Figura",  // message name
  5,  // number of fields
  sizeof(precision_interfaces__msg__Figura),
  precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_member_array,  // message members
  precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_init_function,  // function to initialize message memory (memory has to be allocated)
  precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_type_support_handle = {
  0,
  &precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_precision_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, precision_interfaces, msg, Figura)() {
  if (!precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_type_support_handle.typesupport_identifier) {
    precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &precision_interfaces__msg__Figura__rosidl_typesupport_introspection_c__Figura_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
