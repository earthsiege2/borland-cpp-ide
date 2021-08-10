//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\gadgetwi.cpp
//   Defines class TGadgetWindow.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gadget.h>
#include <owl\gadgetwi.h>

DEFINE_RESPONSE_TABLE1(TGadgetWindow, TWindow)
  EV_WM_CTLCOLOR,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
  EV_WM_SIZE,
  EV_WM_SYSCOLORCHANGE,
END_RESPONSE_TABLE;

static inline int
HeightInPixels(int pointSize)
{
  TScreenDC  dc;

  return MulDiv(-pointSize, dc.GetDeviceCaps(LOGPIXELSY), 72);
}

TGadgetWindowFont::TGadgetWindowFont(int pointSize, BOOL bold, BOOL italic)
  : TFont("MS Sans Serif", HeightInPixels(pointSize), 0, 0, 0,
          bold ? FW_BOLD : FW_NORMAL,
          BYTE(VARIABLE_PITCH | FF_SWISS), BYTE(italic))
{
}

TGadgetWindow::TGadgetWindow(TWindow*       parent,
                             TTileDirection direction,
                             TFont*         font,
                             TModule*       module)
  : TWindow(parent, 0, module)
{
  PRECONDITION(font);

  Attr.Style |= WS_BORDER;
  Capture = 0;
  AtMouse = 0;
  Font = font;
  Direction = direction;
  if (Direction == Horizontal) {
    ShrinkWrapWidth = FALSE;
    ShrinkWrapHeight = TRUE;

  } else {
    ShrinkWrapWidth = TRUE;
    ShrinkWrapHeight = FALSE;
  }
  HintMode = PressHints;

  WideAsPossible = 0;  // number of gadgets with "WideAsPossible" set
  DirtyLayout = TRUE;
  Gadgets = 0;
  NumGadgets = 0;

  //
  // compute the font height
  //
  TScreenDC   dc;
  TEXTMETRIC  metrics;

  dc.SelectObject(*Font);
  dc.GetTextMetrics(metrics);
  FontHeight = metrics.tmHeight + metrics.tmExternalLeading;

  //
  // choose a default height based on the height of the font plus room
  // for a top and bottom border
  //
  Attr.H = FontHeight;

  if (Attr.Style & WS_BORDER)
    Attr.H += 2 * GetSystemMetrics(SM_CYBORDER);

  SetBkgndColor(GetSysColor(COLOR_BTNFACE));
  BkgndBrush = new TBrush(GetSysColor(COLOR_BTNFACE));
}

TGadgetWindow::~TGadgetWindow()
{
  TGadget* gadget = Gadgets;

  while (gadget) {
    TGadget*  tmp = gadget;

    gadget = gadget->Next;
    delete tmp;
  }

  delete Font;
  delete BkgndBrush;
}

void
TGadgetWindow::EvSysColorChange()
{
  for (TGadget* g = Gadgets; g; g = g->NextGadget())
    g->SysColorChange();
  SetBkgndColor(GetSysColor(COLOR_BTNFACE));
  delete BkgndBrush;
  BkgndBrush = new TBrush(GetSysColor(COLOR_BTNFACE));
}

BOOL
TGadgetWindow::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    // See if we missed a mouse move & still need to send a MouseLeave to a 
    // gadget 
    //
    if (AtMouse) {
      TPoint crsPoint;
      GetCursorPos(crsPoint);
      if (WindowFromPoint(crsPoint) != HWindow)
        HandleMessage(WM_MOUSEMOVE, 0, MAKELPARAM(-1,-1));  // nowhere
    }

    // Let the gadgets do command enabling if they need to
    //
    for (TGadget* g = Gadgets; g; g = g->NextGadget())
      g->CommandEnable();
  }
  return TWindow::IdleAction(idleCount);
}

TGadget*
TGadgetWindow::GadgetWithId(int id) const
{
  for (TGadget* g = Gadgets; g; g = g->NextGadget())
    if (g->GetId() == id)
      return g;

  return 0;
}

void
TGadgetWindow::SetShrinkWrap(BOOL shrinkWrapWidth, BOOL shrinkWrapHeight)
{
  ShrinkWrapWidth = shrinkWrapWidth;
  ShrinkWrapHeight = shrinkWrapHeight;
}

BOOL
TGadgetWindow::GadgetSetCapture(TGadget& gadget)
{
  if (Capture)
    return FALSE;

  else {
    Capture = &gadget;
    SetCapture();
    return TRUE;
  }
}

void
TGadgetWindow::GadgetReleaseCapture(TGadget& gadget)
{
  if (&gadget == Capture) {
    Capture = 0;
    ReleaseCapture();
  }
}

//
// Simulate menu select & idle messages to our parent so that it can display
// hint text the same way it does for menu commands
//
void
TGadgetWindow::SetHintCommand(int id)
{
  if (Parent) {
    if (id >= 0)
      Parent->HandleMessage(WM_MENUSELECT, id, 0);

    else
      // Send a menuselect w/ flags==0xFFFF and hMenu==0 to indicate end
      //
    #if defined(__WIN32__)
      Parent->HandleMessage(WM_MENUSELECT, 0xFFFF0000, 0); // flags+item, hmenu
    #else
      Parent->HandleMessage(WM_MENUSELECT, 0, 0x0000FFFFL);// item, hmenu+flags
    #endif
    Parent->HandleMessage(WM_ENTERIDLE, MSGF_MENU);
  }
}

void
TGadgetWindow::SetMargins(TMargins& margins)
{
  Margins = margins;
  LayoutSession();
}

int
TGadgetWindow::LayoutUnitsToPixels(int units)
{
  const long  UnitsPerEM = 8;

  return int((long(units) * FontHeight + UnitsPerEM / 2) / UnitsPerEM);
}

void
TGadgetWindow::GetMargins(TMargins& margins,
                          int& left, int& right, int& top, int& bottom)
{
  switch (margins.Units) {
    case TMargins::Pixels:
      left = margins.Left;
      top = margins.Top;
      right = margins.Right;
      bottom = margins.Bottom;
      break;

    case TMargins::LayoutUnits:
      left = LayoutUnitsToPixels(margins.Left);
      top = LayoutUnitsToPixels(margins.Top);
      right = LayoutUnitsToPixels(margins.Right);
      bottom = LayoutUnitsToPixels(margins.Bottom);
      break;

    case TMargins::BorderUnits:
      int  cxBorder = GetSystemMetrics(SM_CXBORDER);
      int  cyBorder = GetSystemMetrics(SM_CYBORDER);

      left = margins.Left * cxBorder;
      top = margins.Top * cyBorder;
      right = margins.Right * cxBorder;
      bottom = margins.Bottom * cyBorder;
      break;
  }
}

void
TGadgetWindow::LayoutSession()
{
  if (HWindow)
    InvalidateRect(TileGadgets());
}

void
TGadgetWindow::GetDesiredSize(TSize& size)
{
  int       left, right, top, bottom;
  int       maxWidth = 0, maxHeight = 0;
  TGadget*  lastGadget = 0;

  GetMargins(Margins, left, right, top, bottom);

  if (ShrinkWrapWidth || ShrinkWrapHeight) {
    for (TGadget* gadget = Gadgets; gadget; gadget = gadget->Next) {
      TSize  size;

      gadget->GetDesiredSize(size);

      if (size.cx > maxWidth)
        maxWidth = size.cx;

      if (size.cy > maxHeight)
        maxHeight = size.cy;
    }

    //
    // in some cases we need to actually tile the gadgets in order to tell how
    // much room is needed
    //
    if (Direction == Horizontal && ShrinkWrapWidth ||
        Direction == Vertical && ShrinkWrapHeight) {
      TileGadgets();

      for (lastGadget = Gadgets; lastGadget && lastGadget->Next; lastGadget = lastGadget->Next)
        ;
    }
  }

  if (!ShrinkWrapWidth)
    size.cx = Attr.W;

  else if (Direction == Horizontal) {
    size.cx = right;

    if (lastGadget)
      size.cx += lastGadget->GetBounds().right;

  } else {
    size.cx = left + right + maxWidth;

    if (Attr.Style & WS_BORDER)
      size.cx += 2 * GetSystemMetrics(SM_CXBORDER);
  }

  if (!ShrinkWrapHeight)
    size.cy = Attr.H;

  else if (Direction == Vertical) {
    size.cx = bottom;

    if (lastGadget)
      size.cx += lastGadget->GetBounds().bottom;

  } else {
    size.cy = top + bottom + maxHeight;

    if (Attr.Style & WS_BORDER)
      size.cy += 2 * GetSystemMetrics(SM_CYBORDER);
  }
}

BOOL
TGadgetWindow::Create()
{
  TSize  size;

  GetDesiredSize(size);

  if (ShrinkWrapWidth)
    Attr.W = size.cx;

  if (ShrinkWrapHeight)
    Attr.H = size.cy;

  return TWindow::Create();
}

//
// Set direction, & default shrink wrap flags. If already created, then also
// adjust shrink wrap dimension & re-layout
//
void
TGadgetWindow::SetDirection(TTileDirection direction)
{
  if (Direction != direction) {
    Direction = direction;
    if (Direction == Horizontal) {
      ShrinkWrapWidth = FALSE;
      ShrinkWrapHeight = TRUE;

    } else {
      ShrinkWrapWidth = TRUE;
      ShrinkWrapHeight = FALSE;
    }
    //
    // Swap margin's X & Y axis
    //
    int t = Margins.Left; Margins.Left = Margins.Top; Margins.Top = t;
    t = Margins.Right; Margins.Right = Margins.Bottom; Margins.Bottom = t;

    if (HWindow) {
      TSize  size;
      GetDesiredSize(size);

      if (ShrinkWrapWidth)
        Attr.W = size.cx;

      if (ShrinkWrapHeight)
        Attr.H = size.cy;

      LayoutSession();
    }
  }
}

void
TGadgetWindow::GetInnerRect(TRect& rect)
{
  int left, right, top, bottom;
  GetMargins(Margins, left, right, top, bottom);

  rect.left = left;
  rect.right = Attr.W - right;
  rect.top = top;
  rect.bottom = Attr.H - bottom;

  if (Attr.Style & WS_BORDER) {
    rect.right -= 2 * GetSystemMetrics(SM_CYBORDER);
    rect.bottom -= 2 * GetSystemMetrics(SM_CXBORDER);
  }
}

void
TGadgetWindow::PositionGadget(TGadget*, TGadget*, TPoint&)
{
}

TRect
TGadgetWindow::TileHorizontally()
{
  TRect  innerRect;
  TRect  invalidRect;
  int    width = 0;
  int    x;

  GetInnerRect(innerRect);
  invalidRect.SetEmpty();

  //
  // first pass tally the width of all gadgets that don't have "WideAsPossible"
  // set
  //
  // NOTE: we must also take into account any adjustments to the gadget spacing
  //
  for (TGadget* gadget = Gadgets; gadget; gadget = gadget->Next) {
    if (!gadget->WideAsPossible) {
      TSize   desiredSize;

      gadget->GetDesiredSize(desiredSize);
      width += desiredSize.cx;
    }

    if (gadget->Next) {
      TPoint  spacing(0, 0);

      PositionGadget(gadget, gadget->Next, spacing);
      width += spacing.x;
    }
  }

  //
  // now tile all the gadgets
  //
  x = innerRect.left;
  for (gadget = Gadgets; gadget; gadget = gadget->Next) {
    TRect  bounds = gadget->Bounds;
    TRect  originalBounds(bounds);
    TSize  desiredSize;

    bounds.left = x;
    gadget->GetDesiredSize(desiredSize);
    bounds.top = innerRect.top + (innerRect.Height() - desiredSize.cy) / 2;
    bounds.bottom = bounds.top + desiredSize.cy;

    if (gadget->WideAsPossible)
      bounds.right = bounds.left + (innerRect.Width() - width) / WideAsPossible;

    else
      bounds.right = bounds.left + desiredSize.cx;

    if (bounds != originalBounds) {
      gadget->SetBounds(bounds);
      invalidRect |= bounds;

      if (originalBounds.TopLeft() != TPoint(0, 0))
        invalidRect |= originalBounds;
    }
    x += bounds.Width();

    if (gadget->Next) {
      TPoint  origin(x, 0);

      PositionGadget(gadget, gadget->Next, origin);
      x = origin.x;
    }
  }
  return invalidRect;
}

TRect
TGadgetWindow::TileVertically()
{
  TRect  innerRect;
  TRect  invalidRect;
  int    y;

  GetInnerRect(innerRect);
  invalidRect.SetEmpty();

  //
  // now tile all the gadgets
  //
  y = innerRect.top;
  for (TGadget* gadget = Gadgets; gadget; gadget = gadget->Next) {
    TRect  bounds = gadget->Bounds;
    TRect  originalBounds(bounds);
    TSize  desiredSize;

    gadget->GetDesiredSize(desiredSize);
    bounds.top = y;
    bounds.bottom = bounds.top + desiredSize.cy;
    bounds.left = innerRect.left + (innerRect.Width() - desiredSize.cx) / 2;
    bounds.right = bounds.left + desiredSize.cx;

    if (bounds != originalBounds) {
      gadget->SetBounds(bounds);
      invalidRect |= bounds;

      if (originalBounds.TopLeft () != TPoint (0, 0))
        invalidRect |= originalBounds;
    }

    y += bounds.Height();

    if (gadget->Next) {
      TPoint  origin(0, y);

      PositionGadget(gadget, gadget->Next, origin);
      y = origin.y;
    }
  }
  return invalidRect;
}

TRect
TGadgetWindow::TileGadgets()
{
  return (Direction == Horizontal) ? TileHorizontally() : TileVertically();
}

void
TGadgetWindow::GadgetChangedSize(TGadget&)
{
  LayoutSession();
}

void
TGadgetWindow::Insert(TGadget& gadget, TPlacement placement, TGadget* sibling)
{
  PRECONDITION(!gadget.Window);

  TGadget**  g = &Gadgets;

  if (sibling || placement == After) {
    while (*g && *g != sibling)
      g = &(*g)->Next;

    CHECK(*g == sibling);
  }

  if (placement == After && *g)
    g = &(*g)->Next;

  gadget.Next = *g;
  *g = &gadget;

  gadget.Window = this;
  NumGadgets++;
  gadget.Inserted();

  if (gadget.WideAsPossible)
    WideAsPossible++;
}

//
// remove a gadget from the gadget window's list
//
TGadget*
TGadgetWindow::Remove(TGadget& gadget)
{
  if (gadget.Window != this || !Gadgets)
    return 0;

  //
  // handle head-of-list case
  //
  if (&gadget == Gadgets) {
    Gadgets = Gadgets->Next;

  //
  // scan for gadget, looking one link ahead
  //
  } else {
    TGadget* g = Gadgets;

    while (g->Next && g->Next != &gadget)
      g = g->Next;

    if (!g->Next)   // not found
      return 0;

    g->Next = g->Next->Next;
  }

  NumGadgets--;

  //
  // re-adjust gadget now that it doesn't live in a window
  //
  if (gadget.WideAsPossible)
    WideAsPossible--;
  if (&gadget == AtMouse)
    AtMouse = 0;
  GadgetReleaseCapture(gadget);
  gadget.Removed();
  gadget.Window = 0;
  gadget.Next = 0;
  gadget.GetBounds() -= gadget.GetBounds().TopLeft();

  return &gadget;
}

void
TGadgetWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);

  if (DirtyLayout || WideAsPossible > 0) {
    DirtyLayout = FALSE;
    TileGadgets();
    Invalidate();
  }
}

//
// Iterate thru the gadget list and paint each one.
//
void
TGadgetWindow::PaintGadgets(TDC& dc, BOOL, TRect& rect)
{
  for (TGadget* gadget = Gadgets; gadget; gadget = gadget->Next) {
    if (gadget->Bounds.Touches(rect)) {
      dc.SetViewportOrg((TPoint&)gadget->Bounds);

      if (gadget->Clip) {
        dc.SaveDC();
        dc.IntersectClipRect(gadget->Bounds);
      }

      gadget->Paint(dc);

      if (gadget->Clip)
        dc.RestoreDC();
    }
  }
}

void
TGadgetWindow::Paint(TDC& dc, BOOL erase, TRect& rect)
{
  dc.SelectObject(*Font);
  PaintGadgets(dc, erase, rect);
}

//
// Return gadget that a given window-relative point is in, 0 if none
//
TGadget*
TGadgetWindow::GadgetFromPoint(TPoint& point) const
{
  for (TGadget* gadget = Gadgets; gadget; gadget = gadget->Next)
    if (gadget->PtIn(point - *(TSize*)&gadget->Bounds.TopLeft()))
      break;

  return gadget;
}

HBRUSH
TGadgetWindow::EvCtlColor(HDC hDC, HWND /*hWndChild*/, UINT /*ctlType*/)
{
  ::SetBkColor(hDC, BkgndColor);
  return HBRUSH(*BkgndBrush);
}

//
// Determine if the mouse down is in an enabled gadget, & if so pass it to
// the gadget.
//
void
TGadgetWindow::EvLButtonDown(UINT modKeys, TPoint& point)
{
  TGadget* gadget = Capture ? Capture : GadgetFromPoint(point);
  if (gadget && gadget->GetEnabled())
    gadget->LButtonDown(modKeys, point - *(TSize*)&gadget->Bounds.TopLeft());
  TWindow::EvLButtonDown(modKeys, point);
}

//
// Forward mouse ups to the gadget that has captures the mouse, if any, or
// to the gadget at the mouse pos
//
void
TGadgetWindow::EvLButtonUp(UINT modKeys, TPoint& point)
{
  TGadget* gadget = Capture ? Capture : GadgetFromPoint(point);

  if (gadget && gadget->GetEnabled())
    gadget->LButtonUp(modKeys, TPoint(point.x - gadget->Bounds.left,
                                      point.y - gadget->Bounds.top));
  TWindow::EvLButtonUp(modKeys, point);
}

//
// Forward mouse moves to the gadget that has captures the mouse, if any.
// Otherwise checks for mouse entering & leaving gadgets
//
// Could enhance this by delaying mouse enter messages until mouse has been
// in the same area for a while, or looking ahead in queue for mouse msgs.
//
void
TGadgetWindow::EvMouseMove(UINT modKeys, TPoint& point)
{
  if (Capture) {
    Capture->MouseMove(modKeys, TPoint(point.x - Capture->Bounds.left,
                                       point.y - Capture->Bounds.top));

  } else {
    TGadget* gadget = GadgetFromPoint(point);
    if (gadget != AtMouse) {
      if (AtMouse)
        AtMouse->MouseLeave(modKeys, TPoint(point.x - AtMouse->Bounds.left,
                                            point.y - AtMouse->Bounds.top));
      AtMouse = gadget;
      if (AtMouse)
        AtMouse->MouseEnter(modKeys, TPoint(point.x - AtMouse->Bounds.left,
                                            point.y - AtMouse->Bounds.top));
    }
  }
  TWindow::EvMouseMove(modKeys, point);
}
