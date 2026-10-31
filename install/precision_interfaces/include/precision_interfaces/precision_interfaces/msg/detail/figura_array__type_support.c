// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "precision_interfaces/msg/detail/figura_array__rosidl_typesupport_introspection_c.h"
#include "precision_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "precision_interfaces/msg/detail/figura_array__functions.h"
#include "precision_interfaces/msg/detail/figura_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `figuras`
#include "precision_interfaces/msg/figura.h"
// Member `figuras`
#include "precision_interfaces/msg/detail/figura__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  precision_interfaces__msg__FiguraArray__init(message_memory);
}

void precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_fini_function(void * message_memory)
{
  precision_interfaces__msg__FiguraArray__fini(message_memory);
}

size_t precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__size_function__FiguraArray__figuras(
  const void * untyped_member)
{
  const precision_interfaces__msg__Figura__Sequence * member =
    (const precision_interfaces__msg__Figura__Sequence *)(untyped_member);
  return member->size;
}

const void * precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_const_function__FiguraArray__figuras(
  const void * untyped_member, size_t index)
{
  const precision_interfaces__msg__Figura__Sequence * member =
    (const precision_interfaces__msg__Figura__Sequence *)(untyped_member);
  return &member->data[index];
}

void * precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_function__FiguraArray__figuras(
  void * untyped_member, size_t index)
{
  precision_interfaces__msg__Figura__Sequence * member =
    (precision_interfaces__msg__Figura__Sequence *)(untyped_member);
  return &member->data[index];
}

void precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__fetch_function__FiguraArray__figuras(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const precision_interfaces__msg__Figura * item =
    ((const precision_interfaces__msg__Figura *)
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_const_function__FiguraArray__figuras(untyped_member, index));
  precision_interfaces__msg__Figura * value =
    (precision_interfaces__msg__Figura *)(untyped_value);
  *value = *item;
}

void precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__assign_function__FiguraArray__figuras(
  void * untyped_member, size_t index, const void * untyped_value)
{
  precision_interfaces__msg__Figura * item =
    ((precision_interfaces__msg__Figura *)
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_function__FiguraArray__figuras(untyped_member, index));
  const precision_interfaces__msg__Figura * value =
    (const precision_interfaces__msg__Figura *)(untyped_value);
  *item = *value;
}

bool precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__resize_function__FiguraArray__figuras(
  void * untyped_member, size_t size)
{
  precision_interfaces__msg__Figura__Sequence * member =
    (precision_interfaces__msg__Figura__Sequence *)(untyped_member);
  precision_interfaces__msg__Figura__Sequence__fini(member);
  return precision_interfaces__msg__Figura__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__FiguraArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "figuras",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(precision_interfaces__msg__FiguraArray, figuras),  // bytes offset in struct
    NULL,  // default value
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__size_function__FiguraArray__figuras,  // size() function pointer
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_const_function__FiguraArray__figuras,  // get_const(index) function pointer
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__get_function__FiguraArray__figuras,  // get(index) function pointer
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__fetch_function__FiguraArray__figuras,  // fetch(index, &value) function pointer
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__assign_function__FiguraArray__figuras,  // assign(index, value) function pointer
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__resize_function__FiguraArray__figuras  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_members = {
  "precision_interfaces__msg",  // message namespace
  "FiguraArray",  // message name
  2,  // number of fields
  sizeof(precision_interfaces__msg__FiguraArray),
  precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_member_array,  // message members
  precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_init_function,  // function to initialize message memory (memory has to be allocated)
  precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_type_support_handle = {
  0,
  &precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_precision_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, precision_interfaces, msg, FiguraArray)() {
  precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, precision_interfaces, msg, Figura)();
  if (!precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_type_support_handle.typesupport_identifier) {
    precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &precision_interfaces__msg__FiguraArray__rosidl_typesupport_introspection_c__FiguraArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
