//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.12  $
//
// Implementation of classes TGadget, TSeparatorGadget and TSizeGripGadget
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_TOOLTIP_H)
# include <owl/tooltip.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

#if defined(BI_NO_RTTI)
  IMPLEMENT_CASTABLE1(TGadget, TStreamableBase);
#endif

//
// Convert layout units to pixels using a given font height
//
// A layout unit is defined by dividing the font "em" into 8 vertical and 8
// horizontal segments
//
static int
layoutUnitsToPixels(int units, int fontHeight)
{
  const long  unitsPerEM = 8;

  return int((long(units) * fontHeight + unitsPerEM / 2) / unitsPerEM);
}

//
// Return true if the Id is a predefined gadget id.
//
static bool
predefinedGadgetId(int id)
{
  if (id == 0 || id == -1 || (IDG_FIRST <= id && id < IDG_LAST)) {
    return true;
  }
  return false;
}

//
// Retrieve the sizes of the 4 margins in pixels given a font height
//
void
TMargins::GetPixels(int& left, int& right, int& top, int& bottom, int fontHeight) const
{
  switch (Units) {
    case Pixels:
      left = Left;
      top = Top;
      right = Right;
      bottom = Bottom;
      break;

    case LayoutUnits:
      left = layoutUnitsToPixels(Left, fontHeight);
      top = layoutUnitsToPixels(Top, fontHeight);
      right = layoutUnitsToPixels(Right, fontHeight);
      bottom = layoutUnitsToPixels(Bottom, fontHeight);
      break;

    case BorderUnits:
      int  cxBorder = TUIMetric::CxBorder;
      int  cyBorder = TUIMetric::CyBorder;

      left = Left * cxBorder;
      top = Top * cyBorder;
      right = Right * cxBorder;
      bottom = Bottom * cyBorder;
      break;
  }
}

//
// Construct a gadget with a given id and border style. Used by derived
// classes.
//
TGadget::TGadget(int id, TBorderStyle borderStyle)
{
  Window = 0;
  Bounds = TRect(0, 0, 0, 0);
  Flags = Enabled | Visible;
  TrackMouse = false;
  Clip = false;
  WideAsPossible = false;
  ShrinkWrapWidth = ShrinkWrapHeight = true;
  Next = 0;
  Id = id;

  SetBorderStyle(borderStyle);
}

//
// Destruct a gadget and cleanup
//
TGadget::~TGadget()
{
  // If we're in a window, remove ourselves.
  //
  if (Window)
    Window->Remove(*this);
}

//
// Called during idle time to allow the gadget to perform any idle actions.
// TGadget performs command enabling on first call in each idle period
//
bool
TGadget::IdleAction(long idleCount)
{
  if (idleCount == 0)
    CommandEnable();
  return false;
}

//
// Placeholder for virtual called for command enabling
//
void
TGadget::CommandEnable()
{
}

//
// Placeholder for virtual called when system colors change
//
void
TGadget::SysColorChange()
{
}

//
// Simple set accessor to set whether shrinkwrapping is performed horizontally
// and/or vertically.
// Call the gadget window's GadgetChangedSize() member function to affect a
// change in size.
//
void
TGadget::SetShrinkWrap(bool shrinkWrapWidth, bool shrinkWrapHeight)
{
  ShrinkWrapWidth = shrinkWrapWidth;
  ShrinkWrapHeight = shrinkWrapHeight;
}

//
// Directly alter the size of the gadget. Call the gadget window's
// GadgetChangedSize() member function for the size change to take affect
//
// Only use this member function if you turned off shrink wrapping in one or
// both dimension; otherwise the GetDesiredSize() member function will return
// the fitted size which will be different.
//
void
TGadget::SetSize(TSize& size)
{
  Bounds.right = Bounds.left + size.cx;
  Bounds.bottom = Bounds.top + size.cy;

  if (Window)
    Window->GadgetChangedSize(*this);
}

//
// Enable or disable this gadget
//
void
TGadget::SetEnabled(bool enabled)
{
  if (ToBool(Flags & Enabled) != enabled) {
    if (enabled)
      Flags |= Enabled;
    else
      Flags &= ~Enabled;
    Invalidate(false);
  }
}

//
// Called by the gadget window to inform the gadget of a change in its bounding
// rectangle. Default behavior here just updates instance variable "Bounds" but
// derived classes might override this method to update other internal state.
//
void
TGadget::SetBounds(const TRect& rect)
{
  if (rect != Bounds) {
    Bounds = rect;
    Moved();
  }
}

//
// Set the widths of the four outer borders. Notifies the owning Window of a
// size change.
//
void
TGadget::SetBorders(const TBorders& borders)
{
  Borders = borders;

  if (Window)
    Window->GadgetChangedSize(*this);
}

//
// Set the widths of the four margins within the borders. Notifies the owning
// Window of a size change.
//
void
TGadget::SetMargins(const TMargins& margins)
{
  Margins = margins;

  if (Window)
    Window->GadgetChangedSize(*this);
}

//
// Set the border style used by this gadget. Internal Border members are
// updated and owning Window is notified of a size change.
//
void
TGadget::SetBorderStyle(TBorderStyle borderStyle)
{
  BorderStyle = borderStyle;

  int  edgeThickness;
  switch (BorderStyle) {
    default:
    case None:
      edgeThickness = 0;
      break;

    case Plain:
    case Raised:
    case Recessed:
      edgeThickness = 1;
      break;

    case Embossed:
//      edgeThickness = 3;
    case Grooved:
    case ButtonUp:
    case ButtonDn:
    case WndRaised:
    case WndRecessed:
      edgeThickness = 2;
      break;
  }

  Borders.Left = Borders.Top = Borders.Right = Borders.Bottom = edgeThickness;

  if (Window)
    Window->GadgetChangedSize(*this);
}

//
// Determine if a point is logically within this gadget. Return true if this
// gadget is visible & the point is within this gadget's bounds rect
//
bool
TGadget::PtIn(const TPoint& point)
{
  return IsVisible() &&
         point.x >= 0 && point.y >= 0 &&
         point.x < Bounds.Width() && point.y < Bounds.Height();
}

//
// Virtual called after the window holding a gadget has been created
//
void
TGadget::Created()
{
  PRECONDITION(Window);
  PRECONDITION(Window->GetHandle());

  // Register ourself with the tooltip window (if there's one)
  //
  TTooltip* tooltip = Window->GetTooltip();
  if (tooltip) {
    CHECK(tooltip->GetHandle());

    // Don't register gadget's with Id's of 0 or -1.
    // Typically, 0 is reserved by separators and -1 could
    // be used for dumb text gadgets...
    //
    if (!predefinedGadgetId(Id)) {
      TToolInfo toolInfo(Window->GetHandle(), Bounds, Id);
      tooltip->AddTool(toolInfo);
    }
  }
}

//
// Virtual called after gadget is inserted into window
//
void
TGadget::Inserted()
{
}

//
// Virtual called before gadget is removed from window
//
void
TGadget::Removed()
{
  // Unregister ourself with the tooltip window (if there's one)
  //
  if (Window && Window->GetHandle()) {
    TTooltip* tooltip = Window->GetTooltip();
    if (tooltip) {
      CHECK(tooltip->GetHandle());

      // Don't bother with gadgets with Id's of 0 or -1.
      // Typically, 0 is reserved by separators and -1 could
      // be used for dumb text gadgets...
      //
      if (!predefinedGadgetId(Id)) {
        TToolInfo toolInfo(Window->GetHandle(), Bounds, Id);
        tooltip->DeleteTool(toolInfo);
      }
    }
  }
}

//
// Virtual called when a gadget is relocated
//
void
TGadget::Moved()
{
  // Send tooltip window our updated location
  //
  if (Window && Window->GetHandle()) {
    TTooltip* tooltip = Window->GetTooltip();
    if (tooltip) {
      CHECK(tooltip->GetHandle());

      // Don't bother with gadgets with Id's of 0 or -1.
      // Typically, 0 is reserved by separators and -1 could
      // be used for dumb text gadgets...
      //
      if (!predefinedGadgetId(Id)) {

        // First retrieve information about the tool
        //
        TToolInfo ti(true);
        ti.SetToolInfo(*Window, Id);
        tooltip->GetToolInfo(ti);

        // Update the tooltip info if we've moved
        //
        if (TRect(ti.rect) != Bounds) {
          tooltip->NewToolRect(TToolInfo(Window->GetHandle(), Bounds, Id));
        }
      }
    }
  }
}

//
// Invalidate a rectangle in our containing window. Rectangle is specified
// in gadget coordinates.
//
void
TGadget::InvalidateRect(const TRect& rect, bool erase)
{
  if (Window && Window->GetHandle()) {
    TRect  updateRect(rect.left + Bounds.left, rect.top + Bounds.top,
                      rect.right + Bounds.left, rect.bottom + Bounds.top);

    Window->InvalidateRect(updateRect, erase);
  }
}

//
// Invalidate the rectangle used by this gadget to cause it to repaint
//
void
TGadget::Invalidate(bool erase)
{
  InvalidateRect(TRect(0, 0, Bounds.Width(), Bounds.Height()), erase);
}

//
// Cause owning window to paint now if possible
//
void
TGadget::Update()
{
  if (Window && Window->GetHandle())
    Window->UpdateWindow();
}

//
// Paint the border of the gadget based on the BorderStyle member
//
void
TGadget::PaintBorder(TDC& dc)
{
  if (BorderStyle != None) {
    int  xB = TUIMetric::CxBorder;
    int  yB = TUIMetric::CyBorder;

    if (BorderStyle == Plain) {
      dc.OWLFastWindowFrame(TBrush(TColor::SysWindowFrame),
                            TRect(0, 0, Bounds.Width(), Bounds.Height()),
                            xB, yB);
    }
    else {
      TBrush  highlight(TColor::Sys3dHilight);
      TBrush  shadow(TColor::Sys3dShadow);

      // Use the 1:1 mapping of BorderStyle to TUIBorder::TStyle
      //
      TRect boundsRect(0,0,Bounds.Width(),Bounds.Height());
      TUIBorder(boundsRect, TUIBorder::TStyle(BorderStyle)).Paint(dc);
    }
    dc.RestoreBrush();
  }
}

//
// Default painting is just the border
//
void
TGadget::Paint(TDC& dc)
{
  PaintBorder(dc);
}

//
// Request by the gadget window to query the gadget's desired size.
// If shrink wrapping was requested just returns the size needed to
// accomodate the borders and margins--derived classes add in the guts;
// otherwise the current width/height are returned
//
// If this gadget is "WideAsPossible" then "size.cx" is ignored
//
void
TGadget::GetDesiredSize(TSize& size)
{
  int  left, right, top, bottom;
  GetOuterSizes(left, right, top, bottom);

  size.cx = ShrinkWrapWidth ? left+right : Bounds.Width();
  size.cy = ShrinkWrapHeight ? top+bottom : Bounds.Height();
}

//
// Get the four total outer sizes in pixels which consists of the margins
// plus the borders.
//
void
TGadget::GetOuterSizes(int& left, int& right, int& top, int& bottom)
{
  if (Window) {
    int  xBorder = TUIMetric::CxBorder;
    int  yBorder = TUIMetric::CyBorder;

    Window->GetMargins(Margins, left, right, top, bottom);
    left += Borders.Left * xBorder;
    right += Borders.Right * xBorder;
    top += Borders.Top * yBorder;
    bottom += Borders.Bottom * yBorder;
  }
}

//
// Get the inner working rectangle. Which is, by default, the Bounds minus
// each of the outer sizes
//
void
TGadget::GetInnerRect(TRect& innerRect)
{
  int  left, right, top, bottom;
  GetOuterSizes(left, right, top, bottom);

  innerRect.left = left;
  innerRect.right = Bounds.Width() - right;
  innerRect.top = top;
  innerRect.bottom = Bounds.Height() - bottom;
}

//
// Mouse response functions
//

//
// Mouse is entering this gadget. Called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseEnter(uint /*modKeys*/, TPoint&)
{
}

//
// Mouse is moving over this gadget. Called by gadget window only if this
// gadget has captured the mouse
//
void
TGadget::MouseMove(uint /*modKeys*/, TPoint&)
{
}

//
// Mouse is leaving this gadget. Called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseLeave(uint /*modKeys*/, TPoint&)
{
  PRECONDITION(Window);
  PRECONDITION(Window->GetHandle());

  // Send a fake WM_MOUSEMOVE to the tooltip in case the user moved away
  // from the gadget *very* quick without the window detecting mouse move
  // messages.
  //
  TTooltip* tooltip = Window->GetTooltip();
  if (tooltip) {
    CHECK(tooltip->GetHandle());

    TPoint crsPoint;
    GetCursorPos(&crsPoint);
    HWND hwnd = WindowFromPoint(crsPoint);
    if (hwnd) 
      ::MapWindowPoints(HWND_DESKTOP, hwnd, LPPOINT(&crsPoint), 1);
    else 
      hwnd = GetDesktopWindow();

    MSG msg;
    msg.hwnd    = hwnd;
    msg.message = WM_MOUSEMOVE;
    msg.wParam  = 0;
    msg.lParam  = MAKELPARAM(crsPoint.x, crsPoint.y);
    tooltip->RelayEvent(msg);
  }
}

//
// Mouse button down on this gadget, routed from parent.
//
void
TGadget::LButtonDown(uint /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetSetCapture(*this);
}

//
// Mouse button up on this gadget, routed from parent.
//
void
TGadget::LButtonUp(uint /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetReleaseCapture(*this);
}

//----------------------------------------------------------------------------

//
// Construct a separator gadget of a given size
//
TSeparatorGadget::TSeparatorGadget(int size, int id)
:
  TGadget(id)
{
  ShrinkWrapWidth = ShrinkWrapHeight = false;
  SetEnabled(false);
  SetVisible(false);

  // Default size to a sysMetric based value
  //
  if (!size)
    size = TUIMetric::CxSizeFrame * 2;
  Bounds.right = size; // * TUIMetric::CxBorder;
  Bounds.bottom = size; // * TUIMetric::CyBorder;
}

//
// Overridden virtual called after gadget is inserted into window
//
void
TSeparatorGadget::Inserted()
{
  BorderStyle = None;  // Prohibit our style from being changed
}

//----------------------------------------------------------------------------

//
// Construct a gadget that can be grabbed to resize the frame.
//
TSizeGripGadget::TSizeGripGadget(int id)
:
  TSeparatorGadget(TUIMetric::CxHScroll > TUIMetric::CyVScroll ?
                   TUIMetric::CxHScroll :
                   TUIMetric::CyVScroll, id)
{
}

//
// Draw the resize gadget.
//
void
TSizeGripGadget::Paint(TDC& dc)
{
  int  left, right, top, bottom;
  GetOuterSizes(left, right, top, bottom);

  TRect innerRect;
  innerRect.left = left;
  innerRect.top = top;
  innerRect.right = Bounds.Width() + 1;
  innerRect.bottom = Bounds.Height() + 1;

  TUIPart part;
  part.Paint(dc, innerRect, TUIPart::uiScroll, TUIPart::ScrollSizeGrip);
}
