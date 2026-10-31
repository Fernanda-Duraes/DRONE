// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_H_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'figuras'
#include "precision_interfaces/msg/detail/figura__struct.h"

/// Struct defined in msg/FiguraArray in the package precision_interfaces.
typedef struct precision_interfaces__msg__FiguraArray
{
  std_msgs__msg__Header header;
  precision_interfaces__msg__Figura__Sequence figuras;
} precision_interfaces__msg__FiguraArray;

// Struct for a sequence of precision_interfaces__msg__FiguraArray.
typedef struct precision_interfaces__msg__FiguraArray__Sequence
{
  precision_interfaces__msg__FiguraArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} precision_interfaces__msg__FiguraArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__STRUCT_H_
