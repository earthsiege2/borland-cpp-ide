//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TScrollBar.  This defines the basic behavior of all
// scrollbar controls.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_SCROLLBA_H)
# include <owl/scrollba.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TScrollBar, TControl)
  EV_WM_VSCROLL,
  EV_WM_HSCROLL,
END_RESPONSE_TABLE;

//
// Constructor for a TScrollBar object
//
// If the size attribute (H for horizontal scrollbars, W for vertical) is
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
      Attr.H = TUIMetric::CyHScroll;
  }
  else {
    Attr.Style |= SBS_VERT;

    if (Attr.W == 0)
      Attr.W = TUIMetric::CxVScroll;
  }
}

//
// Constructor for a scrollbar from resource (dialog child)
// The LineMagnitude is set to 1 by default.
// The PageMagnitude is set to 10 by default.
//
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
// Transfers state information for a TScrollbar
//
// Direction specifies whether data is to be read from or written to the
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
// Initialize the scrollbar to the default range of 0 .. 100
//
void
TScrollBar::SetupWindow()
{
  SetRange(0, 100);
  TControl::SetupWindow();
}

#if defined(BI_PLAT_WIN32)
//
// Set scrollbar info
//
void
TScrollBar::SetScrollInfo(SCROLLINFO* info, bool redraw)
{
  PRECONDITION(GetHandle());
  ::SetScrollInfo(GetHandle(), SB_CTL, info, redraw);
}

//
// Retrieve the scroll info.
//
void
TScrollBar::GetScrollInfo(SCROLLINFO* info) const
{
  PRECONDITION(GetHandle());
  ::GetScrollInfo(GetHandle(), SB_CTL, info);
}
#endif

//
// Return the current position of the thumb.
//
int
TScrollBar::GetPosition() const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  return ::GetScrollPos(GetHandle(), SB_CTL);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_POS;
  GetScrollInfo(&info);
  return info.nPos;
#endif
}

//
// Sets the position of the thumb.
//
void
TScrollBar::SetPosition(int thumbPos)
{
  PRECONDITION(GetHandle());
  int  min, max;
  GetRange(min, max);

  // Constrain "thumbPos" to be in the range "min .. max"
  //
  if (thumbPos > max)
    thumbPos = max;

  else if (thumbPos < min)
    thumbPos = min;

  if (thumbPos != GetPosition()) {
#if defined(BI_PLAT_WIN16)
    ::SetScrollPos(GetHandle(), SB_CTL, thumbPos, true);
#else
    SCROLLINFO info;
    ZeroMemory(&info, sizeof info);
    info.cbSize = sizeof info;
    info.fMask = SIF_POS;
    info.nPos = thumbPos;
    SetScrollInfo(&info);
#endif
  }
}

//
// Return the current delta to move the thumb when page up/page down is
// received.
//
int
TScrollBar::GetPageMagnitude() const
{
  return PageMagnitude;
}

//
// Set the delta to move the thumb when page up/page down is received.
//
void
TScrollBar::SetPageMagnitude(int pagemagnitude)
{
  PageMagnitude = pagemagnitude;
#if defined(BI_PLAT_WIN32)
  PRECONDITION(GetHandle());
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_PAGE;
  info.nPage = pagemagnitude;
  SetScrollInfo(&info);
#endif
}

//
// Return the range of the scrollbar.
//
void
TScrollBar::GetRange(int& min, int& max) const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  ::GetScrollRange(GetHandle(), SB_CTL, &min, &max);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_RANGE;
  GetScrollInfo(&info);
  min = info.nMin;
  max = info.nMax;
#endif
}

//
// Sets the range of the scrollbar.
//
void
TScrollBar::SetRange(int min, int max)
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  ::SetScrollRange(GetHandle(), SB_CTL, min, max, false);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_RANGE;
  info.nMin = min;
  info.nMax = max;
  SetScrollInfo(&info);
#endif
}


//
// Changes the position of the thumb by "delta" and returns the new position
//
int
TScrollBar::DeltaPos(int delta)
{
  if (delta != 0)
    SetPosition(GetPosition() + delta);

  return GetPosition();
}

//
// Changes the position of the thumb by "LineMagnitude"
//
void
TScrollBar::SBLineUp()
{
  DeltaPos(-LineMagnitude);
}

//
// Changes the position of the thumb by "LineMagnitude"
//
void
TScrollBar::SBLineDown()
{
  DeltaPos(LineMagnitude);
}

//
// Changes the position of the thumb by "PageMagnitude"
//
void
TScrollBar::SBPageUp()
{
  DeltaPos(-PageMagnitude);
}

//
// Changes the position of the thumb by "PageMagnitude"
//
void
TScrollBar::SBPageDown()
{
  DeltaPos(PageMagnitude);
}

//
// Moves the thumb to the new position
//
void
TScrollBar::SBThumbPosition(int thumbPos)
{
  SetPosition(thumbPos);
}

//
// Moves the thumb to the new position
//
void
TScrollBar::SBThumbTrack(int thumbPos)
{
  SetPosition(thumbPos);
}

//
// Moves the thumb to the top of the scrollbar
//
void
TScrollBar::SBTop()
{
  int  min, max;
  GetRange(min, max);
  SetPosition(min);
}

//
// Moves the thumb to the bottom of the scrollbar
//
void
TScrollBar::SBBottom()
{
  int  min, max;
  GetRange(min, max);
  SetPosition(max);
}

//
// User released the mouse after scrolling
//
void
TScrollBar::SBEndScroll()
{
}

//
// Horizontal message handler.
// Dispatch messages to virtual functions.
//
void
TScrollBar::EvHScroll(uint scrollCode, uint thumbPos, THandle /*hCtl*/)
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

//
// Forward vertical message to horizontal message handler.
//
void
TScrollBar::EvVScroll(uint scrollCode, uint thumbPos, THandle hCtl)
{
  EvHScroll(scrollCode, thumbPos, hCtl);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TScrollBar, TControl);

#if !defined(BI_NO_OBJ_STREAMING)

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

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
