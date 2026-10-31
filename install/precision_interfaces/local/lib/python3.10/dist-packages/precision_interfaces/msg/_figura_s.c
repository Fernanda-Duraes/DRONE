// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from precision_interfaces:msg/Figura.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "precision_interfaces/msg/detail/figura__struct.h"
#include "precision_interfaces/msg/detail/figura__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool precision_interfaces__msg__figura__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("precision_interfaces.msg._figura.Figura", full_classname_dest, 39) == 0);
  }
  precision_interfaces__msg__Figura * ros_message = _ros_message;
  {  // forma
    PyObject * field = PyObject_GetAttrString(_pymsg, "forma");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->forma, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // cor
    PyObject * field = PyObject_GetAttrString(_pymsg, "cor");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->cor, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rgb_hex
    PyObject * field = PyObject_GetAttrString(_pymsg, "rgb_hex");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->rgb_hex, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // centro_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "centro_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->centro_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // centro_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "centro_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->centro_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * precision_interfaces__msg__figura__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Figura */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("precision_interfaces.msg._figura");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Figura");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  precision_interfaces__msg__Figura * ros_message = (precision_interfaces__msg__Figura *)raw_ros_message;
  {  // forma
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->forma.data,
      strlen(ros_message->forma.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "forma", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cor
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->cor.data,
      strlen(ros_message->cor.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rgb_hex
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->rgb_hex.data,
      strlen(ros_message->rgb_hex.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "rgb_hex", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // centro_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->centro_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "centro_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // centro_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->centro_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "centro_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
