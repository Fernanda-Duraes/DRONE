# generated from rosidl_generator_py/resource/_idl.py.em
# with input from precision_interfaces:msg/Figura.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Figura(type):
    """Metaclass of message 'Figura'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('precision_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'precision_interfaces.msg.Figura')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__figura
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__figura
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__figura
            cls._TYPE_SUPPORT = module.type_support_msg__msg__figura
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__figura

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Figura(metaclass=Metaclass_Figura):
    """Message class 'Figura'."""

    __slots__ = [
        '_forma',
        '_cor',
        '_rgb_hex',
        '_centro_x',
        '_centro_y',
    ]

    _fields_and_field_types = {
        'forma': 'string',
        'cor': 'string',
        'rgb_hex': 'string',
        'centro_x': 'float',
        'centro_y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.forma = kwargs.get('forma', str())
        self.cor = kwargs.get('cor', str())
        self.rgb_hex = kwargs.get('rgb_hex', str())
        self.centro_x = kwargs.get('centro_x', float())
        self.centro_y = kwargs.get('centro_y', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.forma != other.forma:
            return False
        if self.cor != other.cor:
            return False
        if self.rgb_hex != other.rgb_hex:
            return False
        if self.centro_x != other.centro_x:
            return False
        if self.centro_y != other.centro_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def forma(self):
        """Message field 'forma'."""
        return self._forma

    @forma.setter
    def forma(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'forma' field must be of type 'str'"
        self._forma = value

    @builtins.property
    def cor(self):
        """Message field 'cor'."""
        return self._cor

    @cor.setter
    def cor(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'cor' field must be of type 'str'"
        self._cor = value

    @builtins.property
    def rgb_hex(self):
        """Message field 'rgb_hex'."""
        return self._rgb_hex

    @rgb_hex.setter
    def rgb_hex(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'rgb_hex' field must be of type 'str'"
        self._rgb_hex = value

    @builtins.property
    def centro_x(self):
        """Message field 'centro_x'."""
        return self._centro_x

    @centro_x.setter
    def centro_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'centro_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'centro_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._centro_x = value

    @builtins.property
    def centro_y(self):
        """Message field 'centro_y'."""
        return self._centro_y

    @centro_y.setter
    def centro_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'centro_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'centro_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._centro_y = value
