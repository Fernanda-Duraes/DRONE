// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from precision_interfaces:msg/FiguraArray.idl
// generated code does not contain a copyright notice
#include "precision_interfaces/msg/detail/figura_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `figuras`
#include "precision_interfaces/msg/detail/figura__functions.h"

bool
precision_interfaces__msg__FiguraArray__init(precision_interfaces__msg__FiguraArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    precision_interfaces__msg__FiguraArray__fini(msg);
    return false;
  }
  // figuras
  if (!precision_interfaces__msg__Figura__Sequence__init(&msg->figuras, 0)) {
    precision_interfaces__msg__FiguraArray__fini(msg);
    return false;
  }
  return true;
}

void
precision_interfaces__msg__FiguraArray__fini(precision_interfaces__msg__FiguraArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // figuras
  precision_interfaces__msg__Figura__Sequence__fini(&msg->figuras);
}

bool
precision_interfaces__msg__FiguraArray__are_equal(const precision_interfaces__msg__FiguraArray * lhs, const precision_interfaces__msg__FiguraArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // figuras
  if (!precision_interfaces__msg__Figura__Sequence__are_equal(
      &(lhs->figuras), &(rhs->figuras)))
  {
    return false;
  }
  return true;
}

bool
precision_interfaces__msg__FiguraArray__copy(
  const precision_interfaces__msg__FiguraArray * input,
  precision_interfaces__msg__FiguraArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // figuras
  if (!precision_interfaces__msg__Figura__Sequence__copy(
      &(input->figuras), &(output->figuras)))
  {
    return false;
  }
  return true;
}

precision_interfaces__msg__FiguraArray *
precision_interfaces__msg__FiguraArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__FiguraArray * msg = (precision_interfaces__msg__FiguraArray *)allocator.allocate(sizeof(precision_interfaces__msg__FiguraArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(precision_interfaces__msg__FiguraArray));
  bool success = precision_interfaces__msg__FiguraArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
precision_interfaces__msg__FiguraArray__destroy(precision_interfaces__msg__FiguraArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    precision_interfaces__msg__FiguraArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
precision_interfaces__msg__FiguraArray__Sequence__init(precision_interfaces__msg__FiguraArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__FiguraArray * data = NULL;

  if (size) {
    data = (precision_interfaces__msg__FiguraArray *)allocator.zero_allocate(size, sizeof(precision_interfaces__msg__FiguraArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = precision_interfaces__msg__FiguraArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        precision_interfaces__msg__FiguraArray__fini(&data[i - 1]);
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
precision_interfaces__msg__FiguraArray__Sequence__fini(precision_interfaces__msg__FiguraArray__Sequence * array)
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
      precision_interfaces__msg__FiguraArray__fini(&array->data[i]);
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

precision_interfaces__msg__FiguraArray__Sequence *
precision_interfaces__msg__FiguraArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  precision_interfaces__msg__FiguraArray__Sequence * array = (precision_interfaces__msg__FiguraArray__Sequence *)allocator.allocate(sizeof(precision_interfaces__msg__FiguraArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = precision_interfaces__msg__FiguraArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
precision_interfaces__msg__FiguraArray__Sequence__destroy(precision_interfaces__msg__FiguraArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    precision_interfaces__msg__FiguraArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
precision_interfaces__msg__FiguraArray__Sequence__are_equal(const precision_interfaces__msg__FiguraArray__Sequence * lhs, const precision_interfaces__msg__FiguraArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!precision_interfaces__msg__FiguraArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
precision_interfaces__msg__FiguraArray__Sequence__copy(
  const precision_interfaces__msg__FiguraArray__Sequence * input,
  precision_interfaces__msg__FiguraArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(precision_interfaces__msg__FiguraArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    precision_interfaces__msg__FiguraArray * data =
      (precision_interfaces__msg__FiguraArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!precision_interfaces__msg__FiguraArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          precision_interfaces__msg__FiguraArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!precision_interfaces__msg__FiguraArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
