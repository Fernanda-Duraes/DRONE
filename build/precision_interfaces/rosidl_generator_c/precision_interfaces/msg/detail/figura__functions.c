// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice
#include "precision_interfaces/msg/detail/figura__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `forma`
// Member `cor`
// Member `rgb_hex`
#include "rosidl_runtime_c/string_functions.h"

bool
precision_interfaces__msg__Figura__init(precision_interfaces__msg__Figura * msg)
{
  if (!msg) {
    return false;
  }
  // forma
  if (!rosidl_runtime_c__String__init(&msg->forma)) {
    precision_interfaces__msg__Figura__fini(msg);
    return false;
  }
  // cor
  if (!rosidl_runtime_c__String__init(&msg->cor)) {
    precision_interfaces__msg__Figura__fini(msg);
    return false;
  }
  // rgb_hex
  if (!rosidl_runtime_c__String__init(&msg->rgb_hex)) {
    precision_interfaces__msg__Figura__fini(msg);
    return false;
  }
  // centro_x
  // centro_y
  return true;
}

void
precision_interfaces__msg__Figura__fini(precision_interfaces__msg__Figura * msg)
{
  if (!msg) {
    return;
  }
  // forma
  rosidl_runtime_c__String__fini(&msg->forma);
  // cor
  rosidl_runtime_c__String__fini(&msg->cor);
  // rgb_hex
  rosidl_runtime_c__String__fini(&msg->rgb_hex);
  // centro_x
  // centro_y
}

bool
precision_interfaces__msg__Figura__are_equal(const precision_interfaces__msg__Figura * lhs, const precision_interfaces__msg__Figura * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // forma
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->forma), &(rhs->forma)))
  {
    return false;
  }
  // cor
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cor), &(rhs->cor)))
  {
    return false;
  }
  // rgb_hex
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->rgb_hex), &(rhs->rgb_hex)))
  {
    return false;
  }
  // centro_x
  if (lhs->centro_x != rhs->centro_x) {
    return false;
  }
  // centro_y
  if (lhs->centro_y != rhs->centro_y) {
    return false;
  }
  return true;
}

bool
precision_interfaces__msg__Figura__copy(
  const precision_interfaces__msg__Figura * input,
  precision_interfaces__msg__Figura * output)
{
  if (!input || !output) {
    return false;
  }
  // forma
  if (!rosidl_runtime_c__String__copy(
      &(input->forma), &(output->forma)))
  {
    return false;
  }
  // cor
  if (!rosidl_runtime_c__String__copy(
      &(input->cor), &(output->cor)))
  {
    return false;
  }
  // rgb_hex
  if (!rosidl_runtime_c__String__copy(
      &(input->rgb_hex), &(output->rgb_hex)))
  {
    return false;
  }
  // centro_x
  output->centro_x = input->centro_x;
  // centro_y
  output->centro_y = input->centro_y;
  return true;
}

precision_interfaces__msg__Figura *
precision_interfaces__msg__Figura__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__Figura * msg = (precision_interfaces__msg__Figura *)allocator.allocate(sizeof(precision_interfaces__msg__Figura), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(precision_interfaces__msg__Figura));
  bool success = precision_interfaces__msg__Figura__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
precision_interfaces__msg__Figura__destroy(precision_interfaces__msg__Figura * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    precision_interfaces__msg__Figura__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
precision_interfaces__msg__Figura__Sequence__init(precision_interfaces__msg__Figura__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__Figura * data = NULL;

  if (size) {
    data = (precision_interfaces__msg__Figura *)allocator.zero_allocate(size, sizeof(precision_interfaces__msg__Figura), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = precision_interfaces__msg__Figura__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        precision_interfaces__msg__Figura__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
precision_interfaces__msg__Figura__Sequence__fini(precision_interfaces__msg__Figura__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      precision_interfaces__msg__Figura__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

precision_interfaces__msg__Figura__Sequence *
precision_interfaces__msg__Figura__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__Figura__Sequence * array = (precision_interfaces__msg__Figura__Sequence *)allocator.allocate(sizeof(precision_interfaces__msg__Figura__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = precision_interfaces__msg__Figura__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
precision_interfaces__msg__Figura__Sequence__destroy(precision_interfaces__msg__Figura__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    precision_interfaces__msg__Figura__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
precision_interfaces__msg__Figura__Sequence__are_equal(const precision_interfaces__msg__Figura__Sequence * lhs, const precision_interfaces__msg__Figura__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!precision_interfaces__msg__Figura__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
precision_interfaces__msg__Figura__Sequence__copy(
  const precision_interfaces__msg__Figura__Sequence * input,
  precision_interfaces__msg__Figura__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(precision_interfaces__msg__Figura);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    precision_interfaces__msg__Figura * data =
      (precision_interfaces__msg__Figura *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!precision_interfaces__msg__Figura__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          precision_interfaces__msg__Figura__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!precision_interfaces__msg__Figura__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
