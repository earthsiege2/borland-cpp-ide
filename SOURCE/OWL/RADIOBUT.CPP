//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TRadioButton.  This defines the basic behavior
//   for all radio buttons.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/radiobut.h>
#include <owl/groupbox.h>
#include <owl/applicat.h>
#include <bwcc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TRadioButton, TCheckBox)
  EV_NOTIFY_AT_CHILD(BN_CLICKED, BNClicked),
END_RESPONSE_TABLE;

//
// constructor for a TRadioButton object
//
TRadioButton::TRadioButton(TWindow*        parent,
                           int             id,
                           const char far* title,
                           int x, int y, int w, int h,
                           TGroupBox*      group,
                           TModule*        module)
:
  TCheckBox(parent, id, title, x, y, w, h, group, module)
{
  Attr.Style = WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON;
}

TRadioButton::TRadioButton(TWindow*   parent,
                           int        resourceId,
                           TGroupBox* group,
                           TModule*   module)
:
  TCheckBox(parent, resourceId, group, module)
{
}

//
// Return name of predefined BWCC or Windows radio button class
//
char far*
TRadioButton::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return RADIO_CLASS;
  else
    return "BUTTON";
}

//
// responds to an incoming BN_CLICKED message.
//
// need to see if it's checked because Windows generates two BN_CLICKED
// messages on keyboard input such as up arrow(but only one on mouse input),
// and we should only handle the one after it's checked
//
void
TRadioButton::BNClicked()
{
  if (GetCheck())
    TCheckBox::BNClicked();

  else
    DefaultProcessing();
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TRadioButton, TCheckBox);

//
// reads an instance of TRadioButton from the passed ipstream
//
void*
TRadioButton::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TCheckBox*)GetObject(), is);
  return GetObject();
}

//
// writes the TRadioButton to the passed opstream
//
void
TRadioButton::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TCheckBox*)GetObject(), os);
}
#endif
