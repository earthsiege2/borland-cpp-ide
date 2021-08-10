//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TGroupBox.  This defines the basic behavior for all
// group boxes.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_GROUPBOX_H)
# include <owl/groupbox.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>
#endif

OWL_DIAGINFO;

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
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled())
    return SHADE_CLASS;
  else
#endif
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
:
  TControl(parent, resourceId, module)
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
    Parent->PostMessage(WM_COMMAND, MkParam1(Attr.Id, controlId),
                        TParam2(GetHandle()));
#else
    Parent->PostMessage(WM_COMMAND, Attr.Id, MkParam2(uint16(GetHandle()), controlId));
#endif
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TGroupBox, TControl);

#if !defined(BI_NO_OBJ_STREAMING)

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
#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
