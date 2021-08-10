//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TScrollBar.  This defines the basic
//   behavior of all scrollbar controls.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/scrollba.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TScrollBar, TControl)
  EV_WM_VSCROLL,
  EV_WM_HSCROLL,
END_RESPONSE_TABLE;

//
// constructor for a TScrollBar object
//
// if the size attribute(H for horizontal scrollbars, W for vertical) is
// zero, the attribute is set to the appropriate system metric
//
TScrollBar::TScrollBar(TWindow*        parent,
                       int             id,
                       int x, int y, int w, int h,
                       bool            isHScrollBar,
                       TModule*        module)
:
  TControl(parent, id, 0, x, y, w, h, module)
{
  LineMagnitude = 1;
  PageMagnitude = 10;

  if (isHScrollBar) {
    Attr.Style |= SBS_HORZ;

    if (Attr.H == 0)
      Attr.H = GetSystemMetrics(SM_CYHSCROLL);
  }
  else {
    Attr.Style |= SBS_VERT;

    if (Attr.W == 0)
      Attr.W = GetSystemMetrics(SM_CXVSCROLL);
  }
}

TScrollBar::TScrollBar(TWindow*   parent,
                       int        resourceId,
                       TModule*   module)
:
  TControl(parent, resourceId, module)
{
  LineMagnitude = 1;
  PageMagnitude = 10;
}

//
// transfers state information for a TScrollbar
//
// direction specifies whether data is to be read from or written to the
// buffer, or whether the data element size is simply to be returned
//
// the return value is the size (in bytes) of the transfer data
//
uint
TScrollBar::Transfer(void* buffer, TTransferDirection direction)
{
  TScrollBarData* scrollBuff = (TScrollBarData*)buffer;

  if (direction == tdGetData) {
    GetRange(scrollBuff->LowValue, scrollBuff->HighValue);
    scrollBuff->Position = GetPosition();
  }
  else if (direction == tdSetData) {
    SetRange(scrollBuff->LowValue, scrollBuff->HighValue);
    SetPosition(scrollBuff->Position);
  }

  return sizeof(TScrollBarData);
}

//
// Return name of predefined Windows scrollbar class
//
char far *
TScrollBar::GetClassName()
{
  return "SCROLLBAR";
}

//
// initialize the scrollbar to the default range of 0 .. 100
//
void
TScrollBar::SetupWindow()
{
  SetRange(0, 100);
  TControl::SetupWindow();
}

//
// sets the position of the thumb
//
void
TScrollBar::SetPosition(int thumbPos)
{
  int  min, max;
  GetRange(min, max);

  //
  // constrain "thumbPos" to be in the range "min .. max"
  //
  if (thumbPos > max)
    thumbPos = max;

  else if (thumbPos < min)
    thumbPos = min;

  if (thumbPos != GetPosition())
    ::SetScrollPos(HWindow, SB_CTL, thumbPos, true);
}

//
// changes the position of the thumb by "delta" and returns the new position
//
int
TScrollBar::DeltaPos(int delta)
{
  if (delta != 0)
    SetPosition(GetPosition() + delta);

  return GetPosition();
}

//
// changes the position of the thumb by "LineMagnitude"
//
void
TScrollBar::SBLineUp()
{
  DeltaPos(-LineMagnitude);
}

//
// changes the position of the thumb by "LineMagnitude"
//
void
TScrollBar::SBLineDown()
{
  DeltaPos(LineMagnitude);
}

//
// changes the position of the thumb by "PageMagnitude"
//
void
TScrollBar::SBPageUp()
{
  DeltaPos(-PageMagnitude);
}

//
// changes the position of the thumb by "PageMagnitude"
//
void
TScrollBar::SBPageDown()
{
  DeltaPos(PageMagnitude);
}

//
// moves the thumb to the new position
//
void
TScrollBar::SBThumbPosition(int thumbPos)
{
  SetPosition(thumbPos);
}

//
// moves the thumb to the new position
//
void
TScrollBar::SBThumbTrack(int thumbPos)
{
  SetPosition(thumbPos);
}

//
// moves the thumb to the top of the scrollbar
//
void
TScrollBar::SBTop()
{
  int  min, max;
  GetRange(min, max);
  SetPosition(min);
}

//
// moves the thumb to the bottom of the scrollbar
//
void
TScrollBar::SBBottom()
{
  int  min, max;
  GetRange(min, max);
  SetPosition(max);
}

void
TScrollBar::SBEndScroll()
{
}

void
TScrollBar::EvHScroll(uint scrollCode, uint thumbPos, HWND /*hWndCtl*/)
{
  switch (scrollCode) {
    case SB_LINEDOWN:      SBLineDown(); break;
    case SB_LINEUP:        SBLineUp(); break;
    case SB_PAGEDOWN:      SBPageDown(); break;
    case SB_PAGEUP:        SBPageUp(); break;
    case SB_TOP:           SBTop(); break;
    case SB_BOTTOM:        SBBottom(); break;
    case SB_THUMBPOSITION: SBThumbPosition(thumbPos); break;
    case SB_THUMBTRACK:    SBThumbTrack(thumbPos); break;
    case SB_ENDSCROLL:     SBEndScroll();
  }
}

void
TScrollBar::EvVScroll(uint scrollCode, uint thumbPos, HWND hWndCtl)
{
  EvHScroll(scrollCode, thumbPos, hWndCtl);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TScrollBar, TControl);

//
// Reads an instance of TScrollBar from the passed ipstream.
//
void*
TScrollBar::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->LineMagnitude
     >> GetObject()->PageMagnitude;
  return GetObject();
}

//
// Writes the TScrollBar to the passed opstream.
//
void
TScrollBar::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->LineMagnitude
     << GetObject()->PageMagnitude;
}

#endif
