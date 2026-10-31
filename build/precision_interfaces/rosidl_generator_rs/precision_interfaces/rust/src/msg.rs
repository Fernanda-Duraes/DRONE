#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to precision_interfaces__msg__Figura

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Figura {

    // This member is not documented.
    #[allow(missing_docs)]
    pub forma: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cor: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rgb_hex: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centro_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub centro_y: f32,

}



impl Default for Figura {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Figura::default())
  }
}

impl rosidl_runtime_rs::Message for Figura {
  type RmwMsg = super::msg::rmw::Figura;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        forma: msg.forma.as_str().into(),
        cor: msg.cor.as_str().into(),
        rgb_hex: msg.rgb_hex.as_str().into(),
        centro_x: msg.centro_x,
        centro_y: msg.centro_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        forma: msg.forma.as_str().into(),
        cor: msg.cor.as_str().into(),
        rgb_hex: msg.rgb_hex.as_str().into(),
      centro_x: msg.centro_x,
      centro_y: msg.centro_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      forma: msg.forma.to_string(),
      cor: msg.cor.to_string(),
      rgb_hex: msg.rgb_hex.to_string(),
      centro_x: msg.centro_x,
      centro_y: msg.centro_y,
    }
  }
}


// Corresponds to precision_interfaces__msg__FiguraArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FiguraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub figuras: Vec<super::msg::Figura>,

}



impl Default for FiguraArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FiguraArray::default())
  }
}

impl rosidl_runtime_rs::Message for FiguraArray {
  type RmwMsg = super::msg::rmw::FiguraArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        figuras: msg.figuras
          .into_iter()
          .map(|elem| super::msg::Figura::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        figuras: msg.figuras
          .iter()
          .map(|elem| super::msg::Figura::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      figuras: msg.figuras
          .into_iter()
          .map(super::msg::Figura::from_rmw_message)
          .collect(),
    }
  }
}


