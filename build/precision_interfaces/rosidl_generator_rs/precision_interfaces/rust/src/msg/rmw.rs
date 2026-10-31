#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "precision_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__precision_interfaces__msg__Figura() -> *const std::ffi::c_void;
}

#[link(name = "precision_interfaces__rosidl_generator_c")]
extern "C" {
    fn precision_interfaces__msg__Figura__init(msg: *mut Figura) -> bool;
    fn precision_interfaces__msg__Figura__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Figura>, size: usize) -> bool;
    fn precision_interfaces__msg__Figura__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Figura>);
    fn precision_interfaces__msg__Figura__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Figura>, out_seq: *mut rosidl_runtime_rs::Sequence<Figura>) -> bool;
}

// Corresponds to precision_interfaces__msg__Figura
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Figura {

    // This member is not documented.
    #[allow(missing_docs)]
    pub forma: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cor: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rgb_hex: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centro_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centro_y: f32,

}



impl Default for Figura {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !precision_interfaces__msg__Figura__init(&mut msg as *mut _) {
        panic!("Call to precision_interfaces__msg__Figura__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Figura {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__Figura__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__Figura__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__Figura__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Figura {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Figura where Self: Sized {
  const TYPE_NAME: &'static str = "precision_interfaces/msg/Figura";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__precision_interfaces__msg__Figura() }
  }
}


#[link(name = "precision_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__precision_interfaces__msg__FiguraArray() -> *const std::ffi::c_void;
}

#[link(name = "precision_interfaces__rosidl_generator_c")]
extern "C" {
    fn precision_interfaces__msg__FiguraArray__init(msg: *mut FiguraArray) -> bool;
    fn precision_interfaces__msg__FiguraArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FiguraArray>, size: usize) -> bool;
    fn precision_interfaces__msg__FiguraArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FiguraArray>);
    fn precision_interfaces__msg__FiguraArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FiguraArray>, out_seq: *mut rosidl_runtime_rs::Sequence<FiguraArray>) -> bool;
}

// Corresponds to precision_interfaces__msg__FiguraArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FiguraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub figuras: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Figura>,

}



impl Default for FiguraArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !precision_interfaces__msg__FiguraArray__init(&mut msg as *mut _) {
        panic!("Call to precision_interfaces__msg__FiguraArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FiguraArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__FiguraArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__FiguraArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { precision_interfaces__msg__FiguraArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FiguraArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FiguraArray where Self: Sized {
  const TYPE_NAME: &'static str = "precision_interfaces/msg/FiguraArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__precision_interfaces__msg__FiguraArray() }
  }
}


