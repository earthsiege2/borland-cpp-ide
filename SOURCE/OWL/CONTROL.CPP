//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TControl.  This defines the basic behavior
//   of all controls.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/control.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TControl, TWindow)
  EV_WM_PAINT,
  EV_WM_COMPAREITEM,
  EV_WM_DELETEITEM,
  EV_WM_DRAWITEM,
  EV_WM_MEASUREITEM,
END_RESPONSE_TABLE;

//
// constructor for a TControl
//
TControl::TControl(TWindow*        parent,
                   int             id,
                   const char far* title,
                   int x, int y, int w, int h,
                   TModule*        module)
:
  TWindow(parent, title, module)
{
  Attr.Id = id;
  Attr.X = x;
  Attr.Y = y;
  Attr.W = w;
  Attr.H = h;
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP;
}

//
// constructor for a TControl to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
// data transfer is enabled for the TControl
//
TControl::TControl(TWindow*   parent,
                   int        resourceId,
                   TModule*   module)
:
  TWindow(parent, 0, module)
{
  if (HIWORD(Title))
    delete[] Title;     // Free memory allocated by TWindow's constructor
  Title = 0;

  SetFlag(wfFromResource);
  memset(&Attr, 0x0, sizeof(Attr));
  Attr.Id = resourceId;
  EnableTransfer();
}

void
TControl::EvPaint()
{
  if (IsFlagSet(wfPredefinedClass))
    DefaultProcessing();  // don't call TWindow::EvPaint()

  else
    TWindow::EvPaint();
}

//
// handles WM_COMPAREITEM message (for owner draw controls)
//
LRESULT
TControl::EvCompareItem(uint /*ctrlId*/, COMPAREITEMSTRUCT far& compareInfo)
{
  return CompareItem(compareInfo);
}

//
// Function called when a WM_COMPAREITEM is sent to parent on our behalf
//
int
TControl::CompareItem(COMPAREITEMSTRUCT far&)
{
  return 0;
}

//
// handles WM_DELETEITEM message(for owner draw controls)
//
void
TControl::EvDeleteItem(uint /*ctrlId*/, DELETEITEMSTRUCT far& deleteInfo)
{
  DeleteItem(deleteInfo);
}

//
// Function called when a WM_DELETEITEM is sent to parent on our behalf
//
void
TControl::DeleteItem(DELETEITEMSTRUCT far&)
{
}

void
TControl::EvDrawItem(uint /*ctrlId*/, DRAWITEMSTRUCT far& drawInfo)
{
  DrawItem(drawInfo);
}

//
// Function called when a WM_DRAWITEM is sent to parent on our behalf
//
void
TControl::DrawItem(DRAWITEMSTRUCT far& drawInfo)
{
  switch (drawInfo.itemAction) {
    case ODA_DRAWENTIRE:
         ODADrawEntire(drawInfo);
         break;

    case ODA_FOCUS:
         ODAFocus(drawInfo);
         break;

    case ODA_SELECT:
         ODASelect(drawInfo);
         break;
  }
}

void
TControl::EvMeasureItem(uint /*ctrlId*/, MEASUREITEMSTRUCT far& measureInfo)
{
  MeasureItem(measureInfo);
}

//
// Function called when a WM_MEASUREITEM is sent to parent on our behalf
//
void
TControl::MeasureItem(MEASUREITEMSTRUCT far&)
{
}

//
// function called when an "owner-draw" control needs to be redrawn
//
// will usually be redefined by descendants of TControl which use owner draw
// style
//
void
TControl::ODADrawEntire(DRAWITEMSTRUCT far&)
{
}

//
// function called when an "owner-draw" control gains or loses focus
//
// will usually be redefined by descendants of TControl which use owner draw
// style
//
void
TControl::ODAFocus(DRAWITEMSTRUCT far&)
{
}

//
// function called when an "owner-draw" control's selection status changes
//
// will usually be redefined by descendants of TControl which use owner draw
// style
//
void
TControl::ODASelect(DRAWITEMSTRUCT far&)
{
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TControl, TWindow);

void*
TControl::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);
  return GetObject();
}

void
TControl::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);
}
#endif
