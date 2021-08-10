//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\compat.cpp
//----------------------------------------------------------------------------
#include <owl\owldefs.h>
#include <owl\compat.h>
#include <owl\window.h>

struct TCurrentEvent {
  TWindow*  Win;
  UINT      Msg;
  WPARAM    WParam;
  LPARAM    LParam;
};

extern TCurrentEvent  CurrentEvent;

TMessage _OWLFUNC
__GetTMessage()
{
  TMessage  msg;

  msg.Receiver = CurrentEvent.Win->HWindow;
  msg.Message = (WORD)CurrentEvent.Msg;
  msg.WParam = (WORD)CurrentEvent.WParam;
  msg.LParam = CurrentEvent.LParam;

  return msg;
}

string
TXCompatibility::MapStatusCodeToString(int statusCode)
{
  UINT resId;

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
  : TXOwl(MapStatusCodeToString(statusCode)), Status(statusCode)
{
}

TXCompatibility::TXCompatibility(const TXCompatibility& src)
  : TXOwl(src), Status(src.Status)
{
}

TXOwl*
TXCompatibility::Clone()
{
  return new TXCompatibility(*this);
}

int
TXCompatibility::Unhandled(TModule*, unsigned)
{
  return Status;
}

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
