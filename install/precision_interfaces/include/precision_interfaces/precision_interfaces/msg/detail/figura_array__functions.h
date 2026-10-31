// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice

#ifndef PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__FUNCTIONS_H_
#define PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "precision_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "precision_interfaces/msg/detail/figura_array__struct.h"

/// Initialize msg/FiguraArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * precision_interfaces__msg__FiguraArray
 * )) before or use
 * precision_interfaces__msg__FiguraArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__init(precision_interfaces__msg__FiguraArray * msg);

/// Finalize msg/FiguraArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
void
precision_interfaces__msg__FiguraArray__fini(precision_interfaces__msg__FiguraArray * msg);

/// Create msg/FiguraArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * precision_interfaces__msg__FiguraArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
precision_interfaces__msg__FiguraArray *
precision_interfaces__msg__FiguraArray__create();

/// Destroy msg/FiguraArray message.
/**
 * It calls
 * precision_interfaces__msg__FiguraArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
void
precision_interfaces__msg__FiguraArray__destroy(precision_interfaces__msg__FiguraArray * msg);

/// Check for msg/FiguraArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__are_equal(const precision_interfaces__msg__FiguraArray * lhs, const precision_interfaces__msg__FiguraArray * rhs);

/// Copy a msg/FiguraArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__copy(
  const precision_interfaces__msg__FiguraArray * input,
  precision_interfaces__msg__FiguraArray * output);

/// Initialize array of msg/FiguraArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * precision_interfaces__msg__FiguraArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__Sequence__init(precision_interfaces__msg__FiguraArray__Sequence * array, size_t size);

/// Finalize array of msg/FiguraArray messages.
/**
 * It calls
 * precision_interfaces__msg__FiguraArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
void
precision_interfaces__msg__FiguraArray__Sequence__fini(precision_interfaces__msg__FiguraArray__Sequence * array);

/// Create array of msg/FiguraArray messages.
/**
 * It allocates the memory for the array and calls
 * precision_interfaces__msg__FiguraArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
precision_interfaces__msg__FiguraArray__Sequence *
precision_interfaces__msg__FiguraArray__Sequence__create(size_t size);

/// Destroy array of msg/FiguraArray messages.
/**
 * It calls
 * precision_interfaces__msg__FiguraArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
void
precision_interfaces__msg__FiguraArray__Sequence__destroy(precision_interfaces__msg__FiguraArray__Sequence * array);

/// Check for msg/FiguraArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__Sequence__are_equal(const precision_interfaces__msg__FiguraArray__Sequence * lhs, const precision_interfaces__msg__FiguraArray__Sequence * rhs);

/// Copy an array of msg/FiguraArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_precision_interfaces
bool
precision_interfaces__msg__FiguraArray__Sequence__copy(
  const precision_interfaces__msg__FiguraArray__Sequence * input,
  precision_interfaces__msg__FiguraArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PRECISION_INTERFACES__MSG__DETAIL__FIGURA_ARRAY__FUNCTIONS_H_
