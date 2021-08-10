/////////////////////////////////////////////////////////////////////////////
// OCXPROXY.H - Helpers for hosting OCX in CBuilder's IDE
//
// $Revision:   1.3.1.0  $
// $Date:   04 Jan 2000 15:34:54  $
//
// Copyright (c) 1999,2000 Borland International
/////////////////////////////////////////////////////////////////////////////
#ifndef __OCXPROXY_H
#define __OCXPROXY_H

#include <olectrls.hpp>

// These macros provide overloaded versions of property setters/getters
// to OCX proxy classes. They simply invoke methods provide by TOleControl
// or TDBOleControl.
//
#define OVERLOADED_PROP_METHODS                                             \
  bool __fastcall GetWordBoolProp(int index)                                \
  {                                                                         \
    return TOleControl::GetWordBoolProp(index) != 0;                        \
  }                                                                         \
  void __fastcall SetWordBoolProp(int index, bool value)                    \
  {                                                                         \
    TOleControl::SetWordBoolProp(index, value ? Word(-1) : Word(0));        \
  }                                                                         \
  Shortint __fastcall GetShortintProp(int index)                            \
  {                                                                         \
    return TOleControl::GetSmallintProp(index);                             \
  }                                                                         \
  void __fastcall SetShortintProp(int index, Shortint value)                \
  {                                                                         \
    TOleControl::SetSmallintProp(index, value);                             \
  }                                                                         \
  void __fastcall _SetIUnknownProp(int index, _di_IUnknown const val)       \
  {                                                                         \
    TOleControl::SetIUnknownProp(index, val);                               \
  }                                                                         \
  void __fastcall _SetIDispatchProp(int index, _di_IDispatch const val)     \
  {                                                                         \
    TOleControl::SetIDispatchProp(index, val);                              \
  }                                                                         \
  void __fastcall _SetTFontProp(int index, Graphics::TFont* value)          \
  {                                                                         \
    TOleControl::SetTFontProp(index, value);                                \
  }                                                                         \
  void __fastcall _SetTPictureProp(int index, Graphics::TPicture* value)    \
  {                                                                         \
    TOleControl::SetTPictureProp(index, value);                             \
  }                                                                         \
  void __fastcall _SetOleVariantProp(int index, const OleVariant &value)    \
  {                                                                         \
    TOleControl::SetOleVariantProp(index, value);                           \
  }
   

#endif  //  __OCXPROXY_H
