//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// OWL 1.0 compatibility structures & functions
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_COMPAT_H)
# include <owl/compat.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

TMessage _OWLFUNC
__GetTMessageWin(TWindow* win)
{
  TMessage  msg;
  TCurrentEvent& currentEvent = win->GetCurrentEvent();

  msg.Receiver = currentEvent.Win->GetHandle();
  msg.Message = (uint16)currentEvent.Message;
  msg.WParam = (uint16)currentEvent.WParam;
  msg.LParam = currentEvent.LParam;

  return msg;
}

//
//
//
string
TXCompatibility::MapStatusCodeToString(int statusCode)
{
  uint resId;

  switch (statusCode) {
    case EM_INVALIDCHILD:
      resId = IDS_INVALIDCHILDWINDOW;
      break;

    case EM_INVALIDCLIENT:
      resId = IDS_INVALIDCLIENTWINDOW;
      break;

    case EM_INVALIDMAINWINDOW:
      resId = IDS_INVALIDMAINWINDOW;
      break;

    case EM_INVALIDMODULE:
      resId = IDS_INVALIDMODULE;
      break;

    case EM_INVALIDWINDOW:
      resId = IDS_INVALIDWINDOW;
      break;

    default:
      resId = IDS_UNKNOWNERROR;
  }
  return ResourceIdToString(0, resId);
}

//
// Constructor for exception signalled by setting TModule.Status or
//   TWindow.Status to one of the EM_XXX values.
//
TXCompatibility::TXCompatibility(int statusCode)
:
  TXOwl(MapStatusCodeToString(statusCode)),
  Status(statusCode)
{
}

//
//
//
TXCompatibility::TXCompatibility(const TXCompatibility& src)
:
  TXOwl(src),
  Status(src.Status)
{
}

#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXCompatibility*
#endif
TXCompatibility::Clone()
{
  return new TXCompatibility(*this);
}

//
//
//
int
TXCompatibility::Unhandled(TModule*, unsigned)
{
  return Status;
}

//
//
//
void
TXCompatibility::Throw()
{
  THROW( *this );
}

//
// Internal function used to update the state of a TStatus.  Throw
//   an exception if the updated status code is non-zero.
//
void
TStatus::Set(int statusCode)
{
  if (StatusCode == 0)       // don't overwrite previous error code
    StatusCode = statusCode;

  if (statusCode != 0)       // if non-zero, throw exception
    THROW( TXCompatibility(statusCode) );
}
