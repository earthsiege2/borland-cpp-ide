//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of class TButton.  This defines the basic behavior of all
// buttons.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlControl);

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
  TRACEX(OwlControl, OWL_CDLEVEL, "TButton constructed @" << (void*)this);
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
  TRACEX(OwlControl, OWL_CDLEVEL, "TButton constructed from resource @" << (void*)this);
}

//
// Output a debug message if using the diagnostic libraries.
//
TButton::~TButton()
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TButton destructed @" << (void*)this);
}

//
// Return name of predefined Windows button class
//
char far*
TButton::GetClassName()
{
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled()) {
    TRACEX(OwlControl, 1, "BWCC button used for classname @" << (void*)this);
    return BUTTON_CLASS;
  }
#endif
  TRACEX(OwlControl, 1, "Regular button used for classname @" << (void*)this);
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
  TRACEX(OwlControl, 1, "TButton::SetupWindow() @" << (void*)this);
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
TResult
TButton::BMSetStyle(TParam1 param1, TParam2)
{
  if ((Attr.Style & BS_OWNERDRAW) != BS_OWNERDRAW)
    DefaultProcessing();
  else if (param1 == BS_DEFPUSHBUTTON) {
    IsCurrentDefPB = true;
    Invalidate();
  }
  else if (param1 == BS_PUSHBUTTON) {
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

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TButton::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->IsDefPB;
  return GetObject();
}

//
//
//
void
TButton::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->IsDefPB;
}
#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
