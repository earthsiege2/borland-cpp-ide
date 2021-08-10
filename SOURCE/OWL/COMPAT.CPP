//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Owl 1.0 compatibility structures & functions
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/compat.h>
#include <owl/window.h>

TMessage _OWLFUNC
__GetTMessageWin(TWindow* win)
{
  TMessage  msg;
  TCurrentEvent& currentEvent = win->GetCurrentEvent();

  msg.Receiver = currentEvent.Win->HWindow;
  msg.Message = (uint16)currentEvent.Message;
  msg.WParam = (uint16)currentEvent.WParam;
  msg.LParam = currentEvent.LParam;

  return msg;
}

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

TXCompatibility::TXCompatibility(const TXCompatibility& src)
:
  TXOwl(src),
  Status(src.Status)
{
}

TXCompatibility::~TXCompatibility()
{
}

TXCompatibility*
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
