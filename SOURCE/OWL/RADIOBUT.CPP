//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of class TRadioButton.  This defines the basic behavior for
// all radio buttons.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_RADIOBUT_H)
# include <owl/radiobut.h>
#endif
#if !defined(OWL_GROUPBOX_H)
# include <owl/groupbox.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>
#endif

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

//
//
//
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
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled())
    return RADIO_CLASS;
  else
#endif
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

#if !defined(BI_NO_OBJ_STREAMING)

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
#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
