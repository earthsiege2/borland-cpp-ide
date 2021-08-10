//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TGroupBox.  This defines the basic behavior
//   for all group boxes.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/groupbox.h>
#include <owl/applicat.h>
#include <bwcc.h>

#if !defined(SECTION) || SECTION == 1

//
// constructor for a TGroupBox object
//
// by default, the parent window is notified when the state of the group box's
// selection boxes has changed
//
TGroupBox::TGroupBox(TWindow*        parent,
                     int             id,
                     const char far* text,
                     int x, int y, int w, int h,
                     TModule*        module)
:
  TControl(parent, id, text, x, y, w, h, module)
{
  NotifyParent = true;
  Attr.Style = (Attr.Style | BS_GROUPBOX) & ~WS_TABSTOP;
}

//
// Return name of predefined BWCC shade or Windows groupbox class
//
char far* 
TGroupBox::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return SHADE_CLASS;
  else
    return "BUTTON";
}

//
// constructor for a TGroupBox to be associated with a MS-Windows interface
// element created by MS-Windows from a resource definition
//
// by default, the parent window is notified when the state of the group box's
// selection boxes has changed
//
// disables transfer of state data for the TGroupBox
//
TGroupBox::TGroupBox(TWindow*   parent,
                     int        resourceId,
                     TModule*   module)
  : TControl(parent, resourceId, module)
{
  NotifyParent = true;
  DisableTransfer();
}

//
// notifies parent that the selection in the associated groupbox has
// changed
//
// this method is called by TCheckBoxes grouped in the groupbox when
// their state changes
//
void
TGroupBox::SelectionChanged(int controlId)
{
  if (NotifyParent)
    #if defined(BI_PLAT_WIN32)
      Parent->PostMessage(WM_COMMAND, MAKEWPARAM(Attr.Id, controlId),
                          (LPARAM) HWindow);
    #else
      Parent->PostMessage(WM_COMMAND, Attr.Id, MAKELPARAM(HWindow, controlId));
    #endif
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TGroupBox, TControl);

//
// reads an instance of TGroupBox from the passed ipstream
//
void*
TGroupBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->NotifyParent;
  return GetObject();
}

//
// writes the TGroupBox to the passed opstream
//
void
TGroupBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->NotifyParent;
}
#endif
