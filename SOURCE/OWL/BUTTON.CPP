//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TButton.  This defines the basic behavior
//   of all buttons.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/button.h>
#include <owl/applicat.h>
#include <bwcc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TButton, TControl)
  EV_WM_GETDLGCODE,
  EV_MESSAGE(BM_SETSTYLE, BMSetStyle),
END_RESPONSE_TABLE;

//
// constructor for a TButton object
//
TButton::TButton(TWindow*        parent,
                 int             id,
                 const char far* text,
                 int x, int y, int w, int h,
                 bool            isDefault,
                 TModule*        module)
:
  TControl(parent, id, text, x, y, w, h, module)
{
  IsCurrentDefPB = false;    // not used for buttons in windows
  IsDefPB = false;           // not used for buttons in windows

  if (isDefault)
    Attr.Style |= BS_DEFPUSHBUTTON;

  else
    Attr.Style |= BS_PUSHBUTTON;
}

//
// constructor for a TButton to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
// disables transfer of state data for the TButton
//
TButton::TButton(TWindow*   parent,
                 int        resourceId,
                 TModule*   module)
:
  TControl(parent, resourceId, module)
{
  DisableTransfer();
  IsDefPB = false;         // needed for drawable buttons
  IsCurrentDefPB = false;  // needed for drawable buttons
}

//
// Return name of predefined Windows button class
//
char far*
TButton::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return BUTTON_CLASS;
  else
    return "BUTTON";
}

//
// if this is a drawable button which is supposed to act like a DefPushButton,
// send DM_SETDEFID to Parent to make this into Parent's default pushbutton
//
// this only works (and IsDefPB should only be true) if Parent is a dialog
//
void
TButton::SetupWindow()
{
  if (IsDefPB && ((Attr.Style & BS_OWNERDRAW) == BS_OWNERDRAW))
    Parent->HandleMessage(DM_SETDEFID, Attr.Id);
}

//
// if this is a drawable button we tell Windows whether we want to
// be treated as the current default push button or not
//
uint
TButton::EvGetDlgCode(MSG far* msg)
{
  if ((Attr.Style & BS_OWNERDRAW) != BS_OWNERDRAW)
    return TControl::EvGetDlgCode(msg);

  else if (IsCurrentDefPB)
    return DLGC_BUTTON | DLGC_DEFPUSHBUTTON;

  else
    return DLGC_BUTTON | DLGC_UNDEFPUSHBUTTON;
}

//
// a Button can't have both BS_OWNERDRAW and BS_(DEF)PUSHBUTTON styles so
// when Windows tries to make us a DEF- or non-DEFPUSHBUTTON we keep track
// of the desired style in IsCurrentDefPB
//
LRESULT
TButton::BMSetStyle(WPARAM wParam, LPARAM)
{
  if ((Attr.Style & BS_OWNERDRAW) != BS_OWNERDRAW)
    DefaultProcessing();

  else if (wParam == BS_DEFPUSHBUTTON) {
    IsCurrentDefPB = true;
    Invalidate();
  }
  else if (wParam == BS_PUSHBUTTON) {
    IsCurrentDefPB = false;
    Invalidate();
  }
  else {
    DefaultProcessing();
  }

  return 0;
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TButton, TControl);

void*
TButton::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->IsDefPB;
  return GetObject();
}

void
TButton::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->IsDefPB;
}
#endif
