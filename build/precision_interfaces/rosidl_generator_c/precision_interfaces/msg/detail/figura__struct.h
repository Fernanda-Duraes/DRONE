// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_H_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'forma'
// Member 'cor'
// Member 'rgb_hex'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Figura in the package precision_interfaces.
typedef struct precision_interfaces__msg__Figura
{
  rosidl_runtime_c__String forma;
  rosidl_runtime_c__String cor;
  rosidl_runtime_c__String rgb_hex;
  float centro_x;
  float centro_y;
} precision_interfaces__msg__Figura;

// Struct for a sequence of precision_interfaces__msg__Figura.
typedef struct precision_interfaces__msg__Figura__Sequence
{
  precision_interfaces__msg__Figura * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} precision_interfaces__msg__Figura__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA__STRUCT_H_
