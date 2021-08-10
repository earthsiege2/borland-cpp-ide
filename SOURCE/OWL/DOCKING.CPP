//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.20  $
//
// Implementation of docking window classes
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_DOCKING_H)
# include <owl/docking.h>
#endif
#if !defined(OWL_CONTROLB_H)
# include <owl/controlb.h>
#endif
#if !defined(OWL_TOOLTIP_H)
# include <owl/tooltip.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>  // for TUIBorder edge painting
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#if !defined(CLASSLIB_ARRAYS_H)
# include <classlib/arrays.h>
#endif

//
// Fillin missing defines for some configurations
//
#if !defined(WM_SIZING)
# define WM_SIZING 0x0214
#endif
#if !defined(DS_SETFOREGROUND)
# define DS_SETFOREGROUND    0x200L  /* not in win3.1 */
#endif
#if !defined(TB_CUSTOMIZE)
# define TB_CUSTOMIZE        (WM_USER + 27)
#endif

#if !defined(SECTION) || SECTION == 1

//
// Diagnostic group for docking
//
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlDocking, 1, 0);
DIAG_DECLARE_GROUP(OwlCmd);

//----------------------------------------------------------------------------

//
// Constructor to create a dockable gadget window.
// Sets the appropriate styles for the window.
//
TDockableGadgetWindow::TDockableGadgetWindow(TWindow*        parent,
                                             TTileDirection  direction,
                                             TFont*          font,
                                             TModule*        module)
:
  TGadgetWindow(parent, direction, font, module),
  TDockable()
{
#if 0
  Attr.Style |= WS_BORDER;  // Add in border for boundries between dockables
#else
  Attr.Style &= ~WS_BORDER; // Normally no borders
#endif
  Attr.Style |= WS_CLIPSIBLINGS;

  // Always shrink wrapped when dockable since slip fills out docking area
  //
  SetShrinkWrap(true, true);
}

//
//
//
TDockableGadgetWindow::~TDockableGadgetWindow()
{
}

DEFINE_RESPONSE_TABLE1(TDockableGadgetWindow, TGadgetWindow)
  EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;

//
// Find out how big this dockable would be in a given location, and with a
// given optional size hint
//
TSize
TDockableGadgetWindow::ComputeSize(TAbsLocation loc, TSize* dim)
{
  TTileDirection dir = GetDirectionForLocation(loc);

  // Save current settings to restore when done, since this is a info-request
  // only function
  //
  TTileDirection oldDir = GetDirection();
  int oldWidth = RowWidth;

  // If rectangular, calcuate adjust size for surrounding parent frame window
  //
  TSize delta(0,0);
  if (dir == Rectangular) {
    // If we currently are in a floating slip, use that window to calc frame delta
    //
    TWindow* parent = GetParentO();
    if (oldDir == Rectangular && parent && parent->GetHandle()) {
      delta = parent->GetWindowRect().Size() - parent->GetClientRect().Size();
      if (TSystem::Has3dUI()) {
        // In Win95, the bottom margin and the bottom sizing border are the
        // same color and not separated by a hard border, so we 'kern' them
        // together to match the size of the top margin.
        //
        int yt = TUIMetric::CySizeFrame - TUIMetric::CyFixedFrame;
        int topM, leftM, bottomM, rightM;
        GetMargins(Margins, leftM, topM, rightM, bottomM);
        delta.cy -= min(yt, bottomM);
      }
    }
    // No floating parent yet. Calculate the delta based on assumed frame
    // styles. (This rect is only used to size the drag frame anyway.)
    //
    else {
      TRect winRect(0, 0, 0, 0);
      AdjustWindowRectEx(winRect,
                         WS_POPUPWINDOW|WS_VISIBLE|WS_CAPTION|WS_THICKFRAME|WS_DLGFRAME,
                         false, WS_EX_TOOLWINDOW|WS_EX_WINDOWEDGE);
      delta = winRect.Size();
    }
  }

  TSize sz(0, 0);
  Direction = dir;

  // Seek a vertical size if just a non-zero cy is given
  //
  if (dim && dim->cx == 0 && dim->cy != 0) {

    int seekCy = dim->cy - delta.cy;  // This is the height to shoot for

    TSize testSz;
    GetDesiredSize(testSz);

    // Seek the row whose height is less than seekCy
    //
    if (testSz.cy < seekCy) {
      // Seek a taller row by successivly shrinking the width
      //
      while (1) {
        int prevW = RowWidth;
        sz = testSz;
        RowWidth -= 5;
        if (RowWidth <= 0) {     // Limit reached.  Give up
          RowWidth = testSz.cx;
          sz = testSz;
          break;
        }
        GetDesiredSize(testSz);
        if (seekCy < testSz.cy) { // Shrunk too far: use previous size
          RowWidth = prevW;
          break;
        }
      }
    }
    else if (testSz.cy > seekCy) {
      // Seek a shorter row by successivly growing the width
      //
      while (1) {
        int prevW = RowWidth;
        sz = testSz;
        RowWidth += 5;
        if (RowWidth > 1000) {      // CHNOTE: Limit reached. Give up
          RowWidth = testSz.cx;
          sz = testSz;
          break;
        }
        GetDesiredSize(testSz);
        if (seekCy > testSz.cy) {
          RowWidth = prevW;
          break;
        }
      }
    }
    else // seekCy == testSz.cy
      sz = testSz;
  }
  // Change to a given horizontal size, or just the natural size for the
  // direction
  //
  else {
    if (dim)      // Change the row width here because we are changing size.
      RowWidth = dim->cx - delta.cx;
    GetDesiredSize(sz);
  }

  Direction = oldDir;
  RowWidth = oldWidth;
  sz += delta;

  return sz;
}

//
// Get this dockable's screen rect
//
void
TDockableGadgetWindow::GetRect(TRect& rect)
{
  GetWindowRect(rect);
}

//
// Return a gadget window tile direction code given a docking absolute location
// code.
//
TGadgetWindow::TTileDirection
TDockableGadgetWindow::GetDirectionForLocation(TAbsLocation loc)
{
  switch(loc) {
    case alTop:
    case alBottom:
      return Horizontal;
    case alLeft:
    case alRight:
      return Vertical;
    case alNone:
    default:
      return Rectangular;
  }
}

//
// Cause this dockable to lay itself out vertical, horizontal or rectangular
//
void
TDockableGadgetWindow::Layout(TAbsLocation loc, TSize* dim)
{
  TGadgetWindow::TTileDirection dir = GetDirectionForLocation(loc);
  if (GetDirection() != dir || dim) {
    if (dim)
      SetRectangularDimensions(dim->cx, dim->cy); // Sets RowWidth mostly

    // Set the layout direction, which ends up invoking LayoutSession &
    // SetWindowPos
    //
    SetDirection(dir);
  }
}

//
// Return true if the mouse click point is in a spot that should move this
// dockable around.
//
bool
TDockableGadgetWindow::ShouldBeginDrag(TPoint& pt)
{
  TGadget* g = GadgetFromPoint(pt);
  if (g)
#if 1
    return !g->IsVisible(); // Allow hidden gadgets to begin a drag; separators are hidden
#else
    return !g->GetEnabled(); // Allow disabled gadgets to begin a drag
#endif

  return true;
}

//
// Return the TWindow part of this dockable object. In this case it is just
// this window
//
TWindow*
TDockableGadgetWindow::GetWindow()
{
  return this;
}

//
// When laying out a dockable gadget window, if the gadget window changes size
// make sure we tell the dock about it so the dock can resize too.
//
void
TDockableGadgetWindow::LayoutSession()
{
  TSize sz;
  GetDesiredSize(sz);           // Find out how big we'd like to be

  Attr.W = sz.cx;               // This will allow LayoutSession to work as if
  Attr.H = sz.cy;               // we were the right size.

  TGadgetWindow::LayoutSession();

  // If we are in a slip that has been created properly, then tell it to adjust
  // to our new layout
  //
  if (Parent) {
    TFloatingSlip* slip = TYPESAFE_DOWNCAST(Parent,TFloatingSlip);
    if (slip) {
      // If this is a null-sized gadget window, hide our floating frame.
      //
      bool hideSlip = Attr.W == 0 || Attr.H == 0;
      Parent->ShowWindow(hideSlip ? SW_HIDE : SW_SHOWNA);

      // Make sure the slip will adjust to our new size
      //
      bool stc = Parent->IsFlagSet(wfShrinkToClient);
      if (!stc)
        Parent->SetFlag(wfShrinkToClient);
      SetWindowPos(0, 0, 0, Attr.W, Attr.H, SWP_NOACTIVATE | SWP_NOMOVE);
      if (!stc)
        Parent->ClearFlag(wfShrinkToClient);
    }
    // If we aren't in a slip (because we haven't been inserted yet) resize
    // anyway.
    //
    else {
      SetWindowPos(0, 0, 0, Attr.W, Attr.H, SWP_NOACTIVATE | SWP_NOMOVE);
    }
  }
}

//
// Return the harbor containing the dockable object.
//
THarbor*
TDockableGadgetWindow::GetHarbor()
{
  // If parent is a slip, return its harbor.
  // If parent is the harbor (because the dockable is hidden), return the harbor.
  //
  if (!Parent)
    return 0;
  TDockingSlip* slip = TYPESAFE_DOWNCAST(Parent,TDockingSlip);
  if (slip)
    return slip->GetHarbor();
  THarbor* harbor = TYPESAFE_DOWNCAST(Parent,THarbor);
  return harbor;
}

//
// Forward event to slip to allow use to move gadget within the slip
//
void
TDockableGadgetWindow::EvLButtonDown(uint modKeys, TPoint& point)
{
  TPoint pt = point;
  TGadgetWindow::EvLButtonDown(modKeys, point);

  // Forward the message to the parent, this is for the docking areas.  To
  // allow moving of the controlbars within the docking areas.
  //
  TWindow* w = GetParentO();

  // Check that we're parented to the right window. In OLE server situation,
  // the toolbar could have been reparented to another HWND [i.e. container's
  // window]
  //
  if (w && ::GetParent(*this) != w->GetHandle())
    return;

  // Forward to parent [which is a slip]
  //
  if (w && w->GetHandle()) {
    MapWindowPoints(*w, &point, 1);   // Make to parents coordinate system.
    w->HandleMessage(WM_LBUTTONDOWN, modKeys, MkParam2(int16(point.x), int16(point.y)));
  }

  // At this point, our window may be in drag mode [i.e. being docked or
  // undocked]. This means that the harbor has invoked 'SetCapture' which in
  // turn implies that we won't see subsequent WM_MOUSEMOVE/WM_LBUTTONDOWN
  // messages. This will leave the tooltip the impression [strong impression
  // if I may add] that the mouse button never came up. The net side-effect
  // will be that the tooltip will not activate until it sees an LBUTTONUP
  // message. So to avoid this side-effect we fake an LBUTTONUP message here.
  //
  if (GetCapture() == *GetHarbor()) {
    TTooltip* tooltip = GetTooltip();
    if (tooltip && tooltip->IsWindow()) {
      MSG msg;
      msg.hwnd = *this;
      msg.message = WM_LBUTTONUP;
      msg.wParam = modKeys;
      msg.lParam = MkUint32(int16(pt.x), int16(pt.y));
      tooltip->RelayEvent(msg);
    }
  }
}

//----------------------------------------------------------------------------

IMPLEMENT_CASTABLE(TDockableControlBar);

//
// Construct a dockable control bar.
//
TDockableControlBar::TDockableControlBar(TWindow*        parent,
                                         TTileDirection  direction,
                                         TFont*          font,
                                         TModule*        module)
:
  TDockableGadgetWindow(parent, direction, font, module)
{
  Margins.Units = TMargins::BorderUnits;

  if (Direction == Horizontal) {
    Margins.Left = Margins.Right = TUIMetric::CxSizeFrame + TUIMetric::CxFixedFrame;
    Margins.Top = Margins.Bottom = TUIMetric::CySizeFrame;
  }
  else {
    Margins.Left = Margins.Right = TUIMetric::CxSizeFrame;
    Margins.Top = Margins.Bottom = TUIMetric::CySizeFrame + TUIMetric::CyFixedFrame;
  }

  WantTooltip = true;
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TFloatingSlip, TFloatingFrame)
  EV_WM_NCLBUTTONDOWN,
  EV_WM_LBUTTONDOWN,
  EV_WM_CLOSE,
  EV_WM_SIZING,             // Win 4.0 message only.
  EV_WM_WINDOWPOSCHANGING,
  EV_WM_WINDOWPOSCHANGED,
  EV_WM_WININICHANGE,       // WM_SETTINGCHANGE is same ID, new args in 4.x
END_RESPONSE_TABLE;

//
// Construct a floating slip.
// Sets the appropriate style for the window.
//
TFloatingSlip::TFloatingSlip(TWindow*        parent,
                             int x, int y,
                             TWindow*        clientWnd,
                             bool            shrinkToClient,
                             int             captionHeight,
                             bool            popupPalette,
                             TModule*        module)
:
  TFloatingFrame(parent, clientWnd->Title, 0/*clientWnd*/, shrinkToClient,
                 captionHeight, popupPalette, module)
{
  SetDragFrame(false);

  Attr.Style &= ~(WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPSIBLINGS | WS_SYSMENU);
  Attr.Style &= ~(WS_VISIBLE);    // Create initially hidden, show later
  Attr.Style |= WS_CLIPCHILDREN;  // Dont womp on children
  Attr.Style |= WS_BORDER | WS_THICKFRAME; // Sizeable frame to allow reshaping

  // Let tiny caption recalc margin & border dimensions using new styles. Tiny
  // caption will adjust these some more as needed.
  //
  EnableTinyCaption(TFloatingFrame::DefaultCaptionHeight, true);

  // Calculate a real initial position, & an estimated size. May resize later
  // when client has reshaped.
  //
  TRect winRect(x, y, x+clientWnd->Attr.W, y+clientWnd->Attr.H);
  AdjustWindowRectEx(winRect, Attr.Style, false, Attr.ExStyle);

#if 1
  Attr.X = x;            // Places this frame at given screen x,y
  Attr.Y = y;
#else
  Attr.X = winRect.left; // Places client rect at given screen x,y
  Attr.Y = winRect.top;
#endif
  Attr.W = winRect.Width();
  Attr.H = winRect.Height();
}

//
// Handle lbutton down in the caption to begin a dockable drag operation
//
void
TFloatingSlip::EvNCLButtonDown(uint hitTest, TPoint& point)
{
  if (hitTest == HTCAPTION) {
    // Call the dockable dragging setup function in Harbor, passing this
    // window as the dragged dockable and as the docking slip too
    //
    if (Harbor && Harbor->DockDraggingBegin(*this, point, alNone, this))
      return;
  }
  TWindow::EvNCLButtonDown(hitTest, point);
}

//
// Handle lbutton down bubbled up from the client to begin a dockable drag
// operation
//
void
TFloatingSlip::EvLButtonDown(uint modKeys, TPoint& point)
{
  // Is the mouseDown in a area where we can move the docked window?
  //
  TWindow* cw = GetClientWindow();
  TDockable* d = TYPESAFE_DOWNCAST(cw, TDockable);

  TPoint childPt = point;
  MapWindowPoints(*cw, &childPt, 1);

  if (d && d->ShouldBeginDrag(childPt)) {
    MapWindowPoints(0, &point, 1);
    if (Harbor && Harbor->DockDraggingBegin(*this, point, alNone, this))
      return;   // Successfully started
  }
  TWindow::EvLButtonDown(modKeys, point);
}

//
// When closing the floating slip, remove any dockable first so it is not
// destroyed.  Dockables are owned by the harbor, not the slip, and must not be
// destroyed when the slip is destroyed.
//
void
TFloatingSlip::EvClose()
{
  TDockable* dd = TYPESAFE_DOWNCAST(GetClientWindow(), TDockable);
  if (dd)
    Harbor->Remove(*dd);  // Will cause a close in DockableRemoved()
  else
    TWindow::EvClose();
}

//
// Handle this Win 4.0 message for the best resize user feedback
//
#if !defined(BI_PLAT_WIN16)
bool
TFloatingSlip::EvSizing(uint side, TRect& rect)
#else
bool
TFloatingSlip::EvSizing(uint, TRect&)
#endif
{

#if !defined(BI_PLAT_WIN16)
  // Look for size changes & make them track the dockable
  //
  TWindow* w = GetClientWindow();
  if (w) {
    TDockable* dockable = TYPESAFE_DOWNCAST(w, TDockable);
    if (dockable) {
      TSize trackSize(rect.Size());
      switch (side) {
        case WMSZ_BOTTOM:
        case WMSZ_TOP:
           trackSize.cx = 0;
           break;
        case WMSZ_LEFT:
        case WMSZ_RIGHT:
           trackSize.cy = 0;
           break;
      }
      TSize dsz = dockable->ComputeSize(alNone, &trackSize);

      // Center the fixed axis
      //
      switch (side) {
        case WMSZ_BOTTOM:
        case WMSZ_TOP:
          rect.left = rect.left + (rect.Width() - dsz.cx)/2;
          break;
        case WMSZ_LEFT:
        case WMSZ_RIGHT:
          rect.top = rect.top + (rect.Height() - dsz.cy)/2;
          break;
      }

      // Change the window size, keeping it pinned on the opposite corner
      //
      switch (side) {
        case WMSZ_TOP:
        case WMSZ_TOPRIGHT:
          rect.top = rect.bottom - dsz.cy;
          rect.right = rect.left + dsz.cx;
          break;
        case WMSZ_TOPLEFT:
          rect.left = rect.right - dsz.cx;
          rect.top = rect.bottom - dsz.cy;
          break;
        case WMSZ_BOTTOMLEFT:
        case WMSZ_LEFT:
          rect.left = rect.right - dsz.cx;
          rect.bottom = rect.top + dsz.cy;
          break;
        case WMSZ_BOTTOM:
        case WMSZ_BOTTOMRIGHT:
        case WMSZ_RIGHT:
          rect.right = rect.left + dsz.cx;
          rect.bottom = rect.top + dsz.cy;
          break;
      }
    }
  }
#endif
  return true;
}

//
// Handle WM_WINDOWPOSCHANGING to make sure that this frame is properly
// constrained by the dimensions of the dockable client
//
void
TFloatingSlip::EvWindowPosChanging(WINDOWPOS far& windowPos)
{
  //
  //  if (!TSystem::Has3dUI()) {  

  TFloatingFrame::EvWindowPosChanging(windowPos);

  // Look for size changes & make them track the dockable
  //
  if (!(windowPos.flags&SWP_NOSIZE)) {
    TWindow* w = GetClientWindow();
    if (w) {
      TDockable* dockable = TYPESAFE_DOWNCAST(w, TDockable);
      if (dockable) {
//        TRect cr(0,0,0,0);
//        AdjustWindowRectEx(cr, Attr.Style, false, Attr.ExStyle);
        TSize dsz = dockable->ComputeSize(alNone,
                                          &TSize(windowPos.cx, 0));

        // Center the non-sizing axis
        //
        if (!(windowPos.flags&SWP_NOMOVE)) {
//        if (sizing horizontally)
            windowPos.y = windowPos.y + (windowPos.cy - dsz.cy)/2;
//        else
//          windowPos.x = windowPos.x + (windowpos.cx - dsz.cx)/2;
        }
        windowPos.cx = dsz.cx;
        windowPos.cy = dsz.cy;
      }
    }
  }
  windowPos.flags |= SWP_NOACTIVATE;  // Not very effective, but worth a try
}

//
// Handle WM_WINDOWPOSCHANGED to make sure that the dockable client gets a
// chance to do final layout
//
void
TFloatingSlip::EvWindowPosChanged(WINDOWPOS far& windowPos)
{
  TFloatingFrame::EvWindowPosChanging(windowPos);

  if (!(windowPos.flags&SWP_NOSIZE)) {
    TWindow* w = GetClientWindow();
    if (w) {
      TDockable* dockable = TYPESAFE_DOWNCAST(w, TDockable);
      if (dockable) {
//        TRect cr(0,0,0,0);
//        AdjustWindowRectEx(cr, Attr.Style, false, Attr.ExStyle);
        TSize dsz = dockable->ComputeSize(alNone,
                                          &TSize(windowPos.cx, 0));

        dockable->Layout(alNone, &dsz);
      }
    }
  }
}

//
// Event handler for the .INI file changed message.
// Possibly resize because the user has changed the caption size.
//
void
TFloatingSlip::EvWinIniChange(char far* /*section*/)
{
  TWindow* w = GetClientWindow();

  // Resize, since our sizing borders may have changed size
  //
  if (w) {
    TRect newWinRect = w->GetWindowRect();
    AdjustWindowRectEx(newWinRect, Attr.Style, false, Attr.ExStyle);

    TRect winRect = GetWindowRect();

    if (winRect.Height() != newWinRect.Height() ||
        winRect.Width() != newWinRect.Width()) {
      SetWindowPos(0, newWinRect, SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);
    }
  }
}

//
// Overriden TDockingSlip virtual. Called by mouseup handler after a dockable
// is dropped into this docking window.
//
void
TFloatingSlip::DockableInsert(TDockable& dockable,
                              const TPoint* /*topLeft*/,
                              TRelPosition /*position*/, TDockable* /*relDockable*/)
{
  dockable.Layout(alNone);                // No specific dimensions suggested
  SetClientWindow(dockable.GetWindow());  // Set dockable as client & resize
}

//
// Overriden TDockingSlip virtual. Called by lbutton up handler after a drag
// within this docking window. This floating slip just moves its whole self
//
void
TFloatingSlip::DockableMove(TDockable& /*dockable*/, const TPoint* topLeft,
                            TRelPosition /*position*/, TDockable* /*relDockable*/)
{
  if (topLeft)
    SetWindowPos(0, topLeft->x, topLeft->y, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE);
}

//
// Overriden TDockingSlip virtual. Called by lbutton up handler after a
// dockable has been removed from this docking slip
//
void
TFloatingSlip::DockableRemoved(const TRect& /*orgDragRect*/)
{
  CloseWindow();
}

//
// Forward these first four TDockable virtuals to our client dockable
//
TSize
TFloatingSlip::ComputeSize(TAbsLocation loc, TSize* dim)
{
  TWindow* w = GetClientWindow();
  if (w) {
    TDockable* dockable = TYPESAFE_DOWNCAST(w, TDockable);
    if (dockable)
      return dockable->ComputeSize(loc, dim);
  }
  CHECK(w);
  return TSize(0, 0);
}

//
// Get this dockable's screen rect
//
void
TFloatingSlip::GetRect(TRect& rect)
{
  GetWindowRect(rect);
}

//
// Forward the layout message over to the dockable object.
//
void
TFloatingSlip::Layout(TAbsLocation loc, TSize* dim)
{
  TWindow* w = GetClientWindow();
  if (w) {
    TDockable* dockable = TYPESAFE_DOWNCAST(w, TDockable);
    if (dockable)
      dockable->Layout(loc, dim);  
  }
  CHECK(w);
}

//
// Should a given mouse down begin a drag? Never for this dockable.
//
bool
TFloatingSlip::ShouldBeginDrag(TPoint& /*pt*/)
{
  return false;
}

//
// Return the TWindow part of this dockable object. In this case it is actually
// the client window
//
TWindow*
TFloatingSlip::GetWindow()
{
  CHECK(GetClientWindow());
  return GetClientWindow();
}

//
// Return the associated harbor.
//
THarbor*
TFloatingSlip::GetHarbor()
{
  return Harbor;
}

//
// Return the location of the object.
//
TAbsLocation
TFloatingSlip::GetLocation() const
{
  return alNone;
}

//----------------------------------------------------------------------------

//
// Create a linked list of layouts.
//
template <class T>
TFastList<T>::TFastList(int initSize, int deltaGrowth, bool sorted, bool unique)
:
  SpaceCount(initSize),
  Delta(deltaGrowth),
  EntryCount(0),
  SortEntries(sorted),
  UniqueEntries(unique)
{
  DataPtr = new TDatum[SpaceCount];
}

//
// Destructor.
// Cleans up the previously allocated memory.
//
template <class T>
TFastList<T>::~TFastList()
{
  for (int i = 0; i < EntryCount; i++)
    delete DataPtr[i].Object;
  delete[] DataPtr;
}

//
// Grow the list by Delta if it is not as big as a given minimum size
//
template <class T> void
TFastList<T>::Grow(int minNewSize)
{
  if (minNewSize > SpaceCount) {
    SpaceCount += Delta;
    TDatum* newPtr = new TDatum[SpaceCount];
    memcpy(newPtr, DataPtr, sizeof(TDatum) * SpaceCount);

    delete[] DataPtr;
    DataPtr = newPtr;
  }
}

//
// Open up space at a given index (may be past end) and increase the entry
// count
//
template <class T> void
TFastList<T>::OpenUpSpace(int index)
{
  Grow(EntryCount+1);

  for (int i = EntryCount-1; i >= index; i--)
    DataPtr[i + 1] = DataPtr[i];
  EntryCount++;
}

//
// Close up space at a a given index and reduce the entry count
//
template <class T> void
TFastList<T>::CloseUpSpace(int index)
{
  for (int i = index; i < EntryCount - 1; i++)
    DataPtr[i] = DataPtr[i + 1];
  EntryCount--;
}

//
// Add a layout object into the list.
// Makes a copy of the object.
//
template <class T> bool
TFastList<T>::Add(uint32 comparison, T object)
{
  T* newObject = new T(object);  
  return Add(comparison, newObject);
}

//
// Add a layout object into the list.
//
template <class T> bool
TFastList<T>::Add(uint32 comparison, T* object)
{
  int i;             // Index of slot to add at
  if (SortEntries) {
    i = 0;
    while (i < EntryCount) {   
      if (comparison >= DataPtr[i].CompareItem)
        i++;
      else
        break;
    }

    // Already in list & duplicates not wanted
    //
    if (UniqueEntries && i < EntryCount && DataPtr[i].CompareItem == comparison) {
      return true;  
    }
  }
  else
    i = EntryCount;  // Append to the end

  // Open up one space at this location
  //
  OpenUpSpace(i);

  DataPtr[i].CompareItem = comparison;
  DataPtr[i].Object = object;

  return true;
}

//
// Remove the item from the list.
//
template <class T> T*
TFastList<T>::Remove(uint32 comparison)
{
  int i = FindEntry(comparison);
  return (i >= 0) ? RemoveEntry(i) : 0;
}

//
// Remove an indexed entry from the list.
//
template <class T> T*
TFastList<T>::RemoveEntry(int index)
{
  if (index < EntryCount) {
    T* object = DataPtr[index].Object;
    CloseUpSpace(index);
    return object;  
  }
  return 0;
}

//
// Find a particular entry.
//
template <class T> int
TFastList<T>::FindEntry(uint32 comparison)
{
  for (int i = 0; i < EntryCount; i++)   
    if (DataPtr[i].CompareItem == comparison)
      return i;
  return -1;
}

//
// Retrieve the indexed entry.
//
template <class T> T&
TFastList<T>::GetEntry(int index)
{
//  if (index >= EntryCount)
  return *DataPtr[index].Object;
}

//
// Clear the entries in the list.
//
template <class T> void
TFastList<T>::Clear()
{
  EntryCount = 0;
}

//
// Fill the list with items of where they should be.
//
template <class T> void
TFastList<T>::Fill(TWindow* parent, TGridType gridType)
{
  TWindow* first = parent->GetFirstChild();
  if (first) {
    TWindow* w = first;
    do {
      T* deco = new T(w,gridType);
      Add(deco->GetSortKey(), deco);
      w = w->Next();
    }
    while (w != first);
  }
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TEdgeSlip, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,  
  EV_WM_NCCALCSIZE,
  EV_WM_NCPAINT,
  EV_WM_ERASEBKGND,
  EV_WM_PARENTNOTIFY,
  EV_WM_WINDOWPOSCHANGING,
END_RESPONSE_TABLE;

//
// Construct an edge slip.
// Set the approriate styles for the window.
//
TEdgeSlip::TEdgeSlip(TDecoratedFrame& parent, TAbsLocation location, TModule* module)
:
  TWindow(&parent, "EdgeSlip", module),
  Location(location),
  GridType(Location == alTop || Location == alBottom ? YCoord : XCoord)
{
#if DEBUG_SLIPS
  SetBkgndColor(TColor(0,0,128));  // dark blue for debugging
#else
  SetBkgndColor(TColor::Sys3dFace);
#endif
  Attr.Style |= WS_CLIPCHILDREN;

  if (!TSystem::Has3dUI())
    Attr.Style |= WS_BORDER;  
}

//
// Type of decoration
//
struct TEachDecoration {
  int       Top;      // or Left if XCoord
  int       Bottom;   // or Right if XCoord
  TWindow*  Window;

  TEachDecoration(TWindow*, TGridType);
  TEachDecoration(int Top, int Bottom, TWindow* w);
  uint32 GetSortKey() const;
};

//
// Create a decoration from the grid.
//
TEachDecoration::TEachDecoration(TWindow* w, TGridType gridType)
:
  Window(w)
{
  TRect rect = w->GetWindowRect();
  if (gridType == YCoord) {
    Top = rect.top;
    Bottom = rect.bottom;
  }
  else {
    Top = rect.left;
    Bottom = rect.right;
  }
}

//
// Create the decoration from a specific location.
//
TEachDecoration::TEachDecoration(int top, int bottom, TWindow* w)
:
  Window(w),
  Top(top),
  Bottom(bottom)
{
}

//
// Return the sort key for the object.
// It currently uses either the left or the top coordinate.
//
uint32
TEachDecoration::GetSortKey() const
{
  return Top;
}

//
// Insure that all decorations in the docking window are abutted against each
// other (both horizontally and vertically) there should be no gapping holes.
//
void
TEdgeSlip::SetupWindow()
{
  TWindow::SetupWindow();                         // Create all children.

  TFastList<TEachDecoration>  decoList(20, 10, true, true);
  decoList.Fill(this, GridType);

  // Look for any gaping holes between the dockable windows and collapse them.
  // Normally, this doesn't occur unless the to be created size is different
  // from the actual created size of a gadget. This, currently, only occurs
  // for TControlGadgets where the gadget is a combobox the created size
  // specifies the editclass area and the drop-down area, however, the window
  // rect (when the GetHandle() is valid) is just the editclass area.
  //
  int diff = 0;
  int startWindowChange = -1;
  int rowHeight = 0;
  for (int i = 1; i < decoList.Count(); i++) {
    // Are the two decorations we're going to look at on the same vertical?
    //
    if (decoList[i-1].Top != decoList[i].Top) {
      // No, so compute possible difference.
      //
      if (decoList[i-1].Bottom+diff != decoList[i].Top+diff)  {
        // Remember the first window which is adjusted, we'll want to delay the
        // SetWindowPos until all windows from this point to the end have been
        // completely adjusted.
        //
        if (startWindowChange == -1)
          startWindowChange = i;

        // Found a spot. Compute the offset.
        //
        diff += decoList[i-1].Top + rowHeight - decoList[i].Top;
      }
      rowHeight = decoList[i].Bottom - decoList[i].Top;
    }
    else {
      rowHeight = max(rowHeight, decoList[i].Bottom - decoList[i].Top);
    }
    if (diff) {
      TEachDecoration& decoItem = decoList[i];
      decoItem.Top += diff;
      decoItem.Bottom += diff;
    }
  }

  // Re-adjust all windows which have changed location.
  //
  if (startWindowChange != -1) {
    for (int i = startWindowChange; i < decoList.Count(); i++) {
      TEachDecoration& decoItem = decoList[i];
      TRect r;
      decoItem.Window->GetWindowRect(r);

      TPoint pt(r.left, r.top);
      if (GridType == YCoord)
        pt.y = decoItem.Top;
      else
        pt.x = decoItem.Top;

      // Map from global to local coord (the parent's coordinate space).
      //
      ::MapWindowPoints(0, *this, (TPoint*)&pt, 1);
      decoItem.Window->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                    SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);
      i++;
    }
  }

  // Make sure that our size is updated
  //
  ReLayout(true);
}

//
// Change the reciever to be the framewindow not the docking window. The
// reciever window is normally setup in Activate upon the create of
// TButtonGadgetEnabler.
//
void
TEdgeSlip::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  if (Parent) {
    // Already being processed?
    //
    if (!commandEnabler.IsReceiver(Parent->GetHandle())) {
      // No, so forward it up to our parent
      //
      commandEnabler.SetReceiver(Parent->GetHandle());
      Parent->EvCommandEnable(commandEnabler);
    }
  }
}

//
// Forward command messages to the parent.
//
TResult
TEdgeSlip::EvCommand(uint id, THandle hWndCtl, uint notifyCode)
{
  TRACEX(OwlCmd, 1, "TEdgeSlip::EvCommand - id(" << id << "), ctl(" <<\
                     hex << uint(hWndCtl) << "), code(" << notifyCode  << ")");

  if (notifyCode == 0 && Parent)
    return Parent->EvCommand(id, hWndCtl, notifyCode);

  return TWindow::EvCommand(id, hWndCtl, notifyCode);
}

//
// Forward the left button down message to the dockable object.
//
void
TEdgeSlip::EvLButtonDown(uint modKeys, TPoint& point)
{
  TWindow* cw = GetWindowPtr(ChildWindowFromPoint(point));

  // Only allow immediate children of the docking window to be clicked on.
  //
  if (cw && cw->Parent == this) {
    // Is the mouseDown in a area where we can move the docked window?
    //
    TPoint childPt = point;
    MapWindowPoints(*cw, &childPt, 1);
    TDockable* d = TYPESAFE_DOWNCAST(cw, TDockable);
    if (d && d->ShouldBeginDrag(childPt)) {
      MapWindowPoints(0, &point, 1);
      if (Harbor && Harbor->DockDraggingBegin(*d, point, Location, this)) {
        return;          // Successfully started
      }
    }
  }
  TWindow::EvLButtonDown(modKeys, point);
}

//
// Handle WM_LBUTONDBLCLICK to tell the frame to edit a toolbar
//
void
TEdgeSlip::EvLButtonDblClk(uint, TPoint&)
{
  Parent->HandleMessage(TB_CUSTOMIZE, 0, 0);
}

//
// Return the size of our client area, leaving room for the etched separators
//
uint
TEdgeSlip::EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& calcSize)
{
  uint ret = TWindow::EvNCCalcSize(calcValidRects, calcSize);
  if (IsIconic())
    return ret;

  // Only add in space if this slip is not shrunk to nothing
  //
  if (calcSize.rgrc[0].bottom - calcSize.rgrc[0].top > 0) {
    if (!(Attr.Style & WS_BORDER)) {
      if (Location != alBottom)
        calcSize.rgrc[0].top += 2;
      if (Location != alTop)
        calcSize.rgrc[0].bottom -= 2;
    }
  }
  return 0;
}

//
// Erase the background & draw in etched 'borders' within the client area.
//
void
TEdgeSlip::EvNCPaint()
{
  // Non-3d style
  //
  if (Attr.Style & WS_BORDER) {
    DefaultProcessing();
  }
  // Use 3-d style
  //
  else {
    TWindowDC dc(*this);

    // Paint etched line along the top for left, top & right slips, and along
    // the bottom for bottom, left & right slips to separate from the menubar,
    // statusbar & eachother.
    //
    int height(GetWindowRect().Height());
    if (Location != alBottom)
      TUIBorder(TRect(0,0,9999,2), TUIBorder::EdgeEtched, TUIBorder::Top).Paint(dc);
    if (Location != alTop)
      TUIBorder(TRect(0,height-2,9999,height), TUIBorder::EdgeEtched, TUIBorder::Bottom).Paint(dc);
  }
}

//
// Erase the background & draw in etched 'borders' within the client area.
//
bool
TEdgeSlip::EvEraseBkgnd(HDC hDC)
{
  TWindow::EvEraseBkgnd(hDC);  // Let TWindow erase everything


  return true;
}

//
// Make sure that our slip size is updated when a child changes size
//
void
TEdgeSlip::EvParentNotify(uint event,
                          uint /*childHandleOrX*/, uint /*childIDOrY*/)
{
  if (event == WM_SIZE)
    ReLayout(false);
  else
    DefaultProcessing();
}

//
//
//
class TDecorationSpan {
public:
  int      Left;
  int      Right;
  int      Top;
  int      Bottom;
  TWindow* Window;
  bool     Moved;

  TDecorationSpan(TWindow* w, TGridType);
  uint32 GetSortKey() const;
  void Move(TGridType gridType);
};

//
// Create the decoration span from the grid.
//
TDecorationSpan::TDecorationSpan(TWindow* w, TGridType gridType)
{
  TRect rect = w->GetWindowRect();
  ::MapWindowPoints(0, w->GetParent(), (TPoint*)&rect, 2); // map to slip coordinates

  Window = w;
  if (gridType == YCoord) {
    Top = rect.top;
    Left = rect.left;
    Right = rect.right;
    Bottom = rect.bottom;
  }
  else {
    Top = rect.left;
    Left = rect.top;
    Right = rect.bottom;
    Bottom = rect.right;
  }
}

//
// Return the sorting key of the object.
//
uint32
TDecorationSpan::GetSortKey() const
{
  return (Top<<16)+Left;
}

//
// When the slip shrinks, squeeze dockables where needed
//
void
TEdgeSlip::EvWindowPosChanging(WINDOWPOS far& windowPos)
{
  if (!(windowPos.flags & SWP_NOSIZE)) {
    CompressParallel(windowPos.cx);
  }
  TWindow::EvWindowPosChanging(windowPos);
}

//
// Squash or expand dockables perpendicular to the grid line
//
void
TEdgeSlip::CompressGridLines()
{
  TFastList<TDecorationSpan>  decoList(20, 10, true, true);
  decoList.Fill(this, GridType);

  // Tile dockables perpendicular to grid lines
  //
  int gridLine = 0;
  int t;
  int lastTop = -1;
  int delta, i;
  for (i=0; i < decoList.Count(); i++) {
    decoList[i].Moved = false;
    t = decoList[i].Top;
    if (t != lastTop) {
      delta = gridLine-t;
      gridLine = 0;
      lastTop = t;
    }
    if (delta != 0) {
      decoList[i].Top += delta;
      decoList[i].Bottom += delta;
      decoList[i].Moved = true;
    }
    gridLine = max(gridLine,decoList[i].Bottom);
  }

  // Move all dockables that have changed location.
  //
  for (i = 0; i < decoList.Count(); i++) {
    TPoint pt;
    TDecorationSpan& decoItem = decoList[i];
    if (decoItem.Moved) {
      if (GridType == YCoord) {
        pt.x = decoItem.Left;
        pt.y = decoItem.Top;
      }
      else {
        pt.x = decoItem.Top;
        pt.y = decoItem.Left;
      }
      decoItem.Window->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                    SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);
    }
  }

  ReLayout(false);
}

//
// Compress empty space along Grid line if there is empty space and if
// any dockables hang out past the end.
//
void
TEdgeSlip::CompressParallel(int width)
{
  // scan for dockables that stick off the right side, where there is space to close
  // up the row.
  TFastList<TDecorationSpan>  decoList(20, 10, true, true);
  decoList.Fill(this, GridType);

  // Scan each row looking for a decoration that hangs off the end.
  // If possible, pull that decoration in by collapsing empty space between
  // decorations on that row.
  //
  int firstOnRow = 0;
  int lastOnRow = 0;

  while (firstOnRow < decoList.Count()) {
    int spaceOnRow = decoList[firstOnRow].Left;
    int rowTop = decoList[firstOnRow].Top;
    while (lastOnRow+1 < decoList.Count() && decoList[lastOnRow+1].Top == rowTop) {
      spaceOnRow += decoList[lastOnRow+1].Left-(decoList[lastOnRow].Right+1);
      lastOnRow ++;
    }

    int delta = decoList[lastOnRow].Right - width;
    if (delta > 0 && spaceOnRow > 0) {
      if (spaceOnRow > delta) {
        // if there is extra empty space, collapse from the right
        //
        int r = width;
        int i=lastOnRow;
        while (i >= firstOnRow && (decoList[i].Right+1) > r) {
          int dx = (decoList[i].Right+1) - r;
          decoList[i].Left -= dx;
          decoList[i].Right -= dx;
          decoList[i].Moved = true;
          r = decoList[i].Left;
          i--;
        }
      }
      else {
        // if there is not extra empty space, just collapse the space
        //
        int r = 0;
        for (int i=firstOnRow; i<=lastOnRow; i++) {
          if (decoList[i].Left > r) {
            int dx = decoList[i].Left - r;
            decoList[i].Left -= dx;
            decoList[i].Right -= dx;
            decoList[i].Moved = true;
            r = decoList[i].Right+1;
          }
          else
            break;
        }
      }
    }
    firstOnRow = lastOnRow+1;
  }

  // Move all dockables that have changed location.
  //
  for (int i = 0; i < decoList.Count(); i++) {
    TPoint pt;
    TDecorationSpan& decoItem = decoList[i];
    if (decoItem.Moved) {
      if (GridType == YCoord) {
        pt.x = decoItem.Left;
        pt.y = decoItem.Top;
      }
      else {
        pt.x = decoItem.Top;
        pt.y = decoItem.Left;
      }
      decoItem.Window->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                    SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);
    }
  }
}

//
// Change the child metrics of this docking window within its decorated frame.
// Call when the rectangle area of the docking area is different from the
// computed area of the dockable windows within the docking area.
//
void
TEdgeSlip::ReLayout(bool forcedLayout)
{
  // Has the docking area changed in size?
  //
  TSize area = ComputeDockingArea();

  bool sizeChanged;
  if (Location == alTop || Location == alBottom) {
    sizeChanged = Attr.H != area.cy;
    Attr.H = area.cy;
  }
  else {
    sizeChanged = Attr.W != area.cx;
    Attr.W = area.cx;
  }

  // If the size has change or we need to force a layout, then do so
  //
  if (sizeChanged || forcedLayout) {
    TDecoratedFrame* df = TYPESAFE_DOWNCAST(Parent, TDecoratedFrame);

    // Set the same metrics just to dirty the layout plan & force a rebuild
    //
    TLayoutMetrics  metrics;
    df->GetChildLayoutMetrics(*this, metrics);
    df->SetChildLayoutMetrics(*this, metrics);

    df->Layout();
  }
}

//
// Overriden TDockingSlip virtual to insert a new dockable into this slip.
// Called by mouseup handler after a dockable
// is dropped into this docking window.
//
void
TEdgeSlip::DockableInsert(TDockable& dockable, const TPoint* topLeft,
                          TRelPosition position, TDockable* relDockable)
{
  // Get dockable's window & hide it in case we have to toss it around a bit
  //
  TWindow* dockableWindow = dockable.GetWindow();
  dockableWindow->ShowWindow(SW_HIDE);
  dockableWindow->SetParent(this);

  // Slam dockable over to 0,0 since Move assumes we own it already
  //
  dockableWindow->SetWindowPos(0, 0, 0, 0, 0,
                               SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);

  // Make sure that the dockable is oriented the right way--horizontal layout
  // for Y-gridded slips
  //
  dockable.Layout(GridType == YCoord ? alTop : alLeft);

//  dockableWindow->Create();  // just in case? but only if we are?
  DockableMove(dockable, topLeft, position, relDockable);
  dockableWindow->ShowWindow(SW_SHOWNA);
}

//
// Overriden TDockingSlip virtual. Called by mouseup handler after a drag
// within this docking window.
//
void
TEdgeSlip::DockableMove(TDockable& dockable, const TPoint* topLeft,
                        TRelPosition position, TDockable* relDockable)
{
  TWindow* dockableWindow = dockable.GetWindow();
  TRect dockableRect = dockableWindow->GetWindowRect();
  TSize dockableSize = dockableRect.Size();

  TPoint dockPos;

  // If no dockable topleft given, calculate based on relative dockable &
  // location
  //
  if (topLeft) {
    dockPos = *topLeft;
  }
  else {
    // Figure out the best relative position if none given
    //
    if (position == rpNone) switch (Location) {
      case alTop:
        position = rpBelow;
        break;
      case alBottom:
        position = rpAbove;
        break;
      case alLeft:
        position = rpRightOf;
        break;
      case alRight:
        position = rpLeftOf;
        break;
    }

    // Get the last child inserted into this docking window and use it as the
    // relative window if none was given
    //
    TWindow* relWindow = 0;
    if (relDockable)
      relWindow = relDockable->GetWindow();
    if (!relWindow)
      relWindow = GetLastChild();

    // Get its rect if it exists, or the screen coord of this slip's client area
    //
    TRect relWindowRect(0,0,0,0);
    if (relWindow)
      relWindowRect = relWindow->GetWindowRect();
    else
      ::MapWindowPoints(0, *this, (TPoint*)&relWindowRect, 2);

    TSize dockableSize = dockableWindow->GetWindowRect().Size();
    switch (position) {
      case rpAbove:
        dockPos = TPoint(relWindowRect.left, relWindowRect.top-dockableSize.cy);
        break;
      case rpBelow:
        dockPos = TPoint(relWindowRect.left, relWindowRect.bottom);
        break;
      case rpLeftOf:
        dockPos = TPoint(relWindowRect.left-dockableSize.cx, relWindowRect.top);
        break;
      case rpRightOf:
        dockPos = TPoint(relWindowRect.right, relWindowRect.top);
        break;
    }
  }

  // Make a list of the dockables, sorted by y-coord
  //
  TFastList<TEachDecoration>  GridList(20, 10, true, true);
  GridList.Fill(this, GridType);

  // Find a gridline on which to put the dockable
  //
  int dockableEdge;
  int bottomEdge = 0;
  if (Location == alTop || Location == alBottom)
    dockableEdge = dockPos.y;
  else
    dockableEdge = dockPos.x;

  for (int i = 0; i < GridList.Count(); i++) {
    if (dockableEdge <= (GridList[i].Top+GridList[i].Bottom)/2)
      break;
    if (GridList[i].Window != dockableWindow)
      bottomEdge = max(bottomEdge,GridList[i].Bottom);
  }

  // Adjust perpendicular coord to newly found spot
  //
  TPoint newPos(dockPos);
  if (Location == alTop || Location == alBottom) {
    newPos.y = bottomEdge;
  }
  else {
    newPos.x = bottomEdge;
  }

  // Adjust from screen coords, but make sure rect topleft is > 0
  //
  ::MapWindowPoints(0, *this, &newPos, 1);
  if (newPos.x < 0)
    newPos.x = 0;
  if (newPos.y < 0)
    newPos.y = 0;

  // Position & show the dockable window
  //
  dockableWindow->SetWindowPos(0, newPos.x, newPos.y, 0, 0,
                               SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
  dockableWindow->ShowWindow(SW_SHOWNA);

  // Adjust all windows on the grid line
  //
  MoveAllOthers(dockableWindow, MoveDraggedWindow(dockableWindow));

  // Squash down dockable's previous area if needed
  //
  CompressGridLines();
}

//
// Overriden TDockingSlip virtual. Called by mouseup handler after a dockable
// has been removed from this docking slip
//
void
TEdgeSlip::DockableRemoved(const TRect& /*orgRect*/)
{
  CompressGridLines();
}

//
// All terminology in this function is referenced to the following two windows
// Drag and LeftEdge.  The LeftEdge window is only valid if the Drag windows's
// left side is intersecting the LeftEdge window's right side.
//
//                 ======================
//    -------------------  Drag Window  |
//    | LeftEdge Window |================
//    -------------------
//
// The goal of this function is to anchor down the Drag window's left side.
// This is accomplished by one of three ways:
//
//   1. Leave the Drag window where it is; if the Drag window's left side does
//      not intersect with any other windows (no LeftEdge window).
//
//   2. Slide the Drag window to the right of the LeftEdge window being
//      intersected. This is only done if the intersection is not beyond the
//      midpoint (less than 50% of the LeftEdge window) of the LeftEdge window.
//
//   3. Slide the Drag window to the left side position of the LeftEdge window
//      (the Drag window's left side is equal to the LeftEdge window's left
//      side).  The LeftEdge window is then slid to the right side of the Drag
//      window; if the intersection is beyond the mid point of the left edge
//      window (more than 50% of the LeftEdge window).
//
TWindow*
TEdgeSlip::MoveDraggedWindow(TWindow* draggedWindow)
{
  // Do we want to move the draggedWindow, if so do that.
  //
  TRect draggedRect = draggedWindow->GetWindowRect();

  TWindow* first = GetFirstChild();
  if (first) {
    TWindow* w = first;
    do {
      if (w != draggedWindow) {
        TRect currRect = w->GetWindowRect();
        TPoint pt;

        if (Location == alTop || Location == alBottom) {
          if (draggedRect.left >= currRect.left && draggedRect.left <= currRect.right &&
              currRect.top == draggedRect.top) {

            int midPt = (currRect.right - currRect.left) / 2;

            // If the dragged window is obscuring the window underneath by more
            // than 50% then the dragged window will keep its position and the
            // underneath window must moved.  Otherwise, the dragged window
            // will move and the window underneath will move.
            //
            if (currRect.left + midPt > draggedRect.left) {
              // Move the draggedWindow to the same left as the window
              // underneath.
              //
              pt.x = currRect.left;
              pt.y = draggedRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              draggedWindow->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);

              // Move the current window to the right of the dragged window.
              //
              draggedRect = draggedWindow->GetWindowRect();
              pt.x = draggedRect.right;
              pt.y = currRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              w->SetWindowPos(0, pt.x, pt.y, 0, 0,
                              SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
              return w;
            }
            else {
              // Move the dragged window to the right of the current window (w).
              //
              pt.x = currRect.right;
              pt.y = draggedRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              draggedWindow->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
              return draggedWindow;
            }
          }
        }
        else {
          // Left and right docking area.
          //
          if (draggedRect.top >= currRect.top && draggedRect.top <= currRect.bottom &&
              currRect.left == draggedRect.left) {

            int midPt = (currRect.bottom - currRect.top) / 2;

            // If the dragged window is obscuring the window underneath by more
            // than 50% then the dragged window will keep its position and the
            // underneath window must moved. Otherwise, the dragged window will
            // move and the window underneath will move.
            //
            if (currRect.top+midPt > draggedRect.top) {
              // Move the draggedWindow to the same left as the window underneath.
              //
              pt.x = currRect.left;
              pt.y = draggedRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              draggedWindow->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);

              // Move the current window to the right of the dragged window.
              //
              draggedRect = draggedWindow->GetWindowRect();
              pt.x = draggedRect.right;
              pt.y = currRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              w->SetWindowPos(0, pt.x, pt.y, 0, 0,
                              SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
              return w;
            }
            else {
              // Move the dragged window to the right of the current window (w).
              //
              pt.x = currRect.right;
              pt.y = draggedRect.top;
              ::MapWindowPoints(0, *this, &pt, 1);
              draggedWindow->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
              return draggedWindow;
            }
          }
        }
      }

      w = w->Next();
    } while (w != first);
  }

  return draggedWindow;
}

//
// Structure to manage the list of windows to slide.
//
struct TWindowItem {
  TWindow* DockedWindow;
  int      LeftSide;

  TWindowItem(TWindow* dockedW = 0, int left = 0)
  :
    DockedWindow(dockedW),
    LeftSide(left)
  {
  }
};
typedef TArrayAsVector<TWindowItem*> TWindowItemArray;
typedef TArrayAsVectorIterator<TWindowItem*> TWindowItemArrayIter;

//
// Build a sorted list (sorted by left coordinate) of windows on the same horz.
// (top/bottom docking) or vert. (left/right docking) of windows to the right
// or below the dragged window.  Then slide all windows from the first one
// intersecting the dragged window to the last one in the list.
//
void
TEdgeSlip::MoveAllOthers(TWindow* draggedWindow, TWindow* movedWindow)
{
  TWindowItemArray windowList(5, 0, 5);

  // Include the (upto) two windows which were anchored in MoveDraggedWindow.
  //
  TRect draggedRect = draggedWindow->GetWindowRect() | movedWindow->GetWindowRect();

  TWindow* first = GetFirstChild();
  if (first) {
    TWindow* w = first;
    do {
      // If the current window is the moved window or the draggedWindow then
      // grab another window.
      //
      if (w != draggedWindow) {
        TRect currRect = w->GetWindowRect();

        // Build a list of windows on the same horizontal or vertical after
        // the dragged window.
        //
        if (currRect.top == draggedRect.top && currRect.left >= draggedRect.left) {
          int   i = 0;
          while (i < windowList.GetItemsInContainer()) {
            if (currRect.left <= windowList[i]->LeftSide)
              break;
            i++;
          }

          TWindowItem* wItem = new TWindowItem(w, currRect.left); 
          windowList.AddAt(wItem, i);
        }
      }

      w = w->Next();
    } while (w != first);
  }

  // Are there windows after the dragged window to adjust?
  //
  if (windowList.GetItemsInContainer()) {
    int i = 0;

    // Find the first one, all subsequent ones (plus this one) will be slid.
    //
    while (i < windowList.GetItemsInContainer()) {
      if (windowList[i]->LeftSide >= draggedRect.left &&
          windowList[i]->LeftSide < draggedRect.right)
        break;
      i++;
    }

    // Slide all windows after the dragged window.
    //
    if (i == 0 || i != windowList.GetItemsInContainer()) {
      TWindow* w1 = draggedWindow;
      int      offset;
      TRect    r1, r2;
      TPoint   pt;

      while (i < windowList.GetItemsInContainer()) {
        offset = w1->GetWindowRect().right - windowList[i]->LeftSide;

        pt.x = windowList[i]->LeftSide + offset;
        pt.y = windowList[i]->DockedWindow->GetWindowRect().top;
        ::MapWindowPoints(0, *this, &pt, 1);
        windowList[i]->DockedWindow->SetWindowPos(0, pt.x, pt.y, 0, 0,
                                                  SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
        w1 = windowList[i++]->DockedWindow;
      }
    }
  }

  TWindowItemArrayIter iter(windowList);

  while (iter) {
    TWindowItem* item = iter.Current();
    windowList.Detach(item);
    delete item;
    iter++;
  }

  windowList.Flush();
}

#if 0
//
// Pull every child beyond a given coord in by a given delta (positive),
//  or push out every child beyond the given coord by the given delta (negative)
//
void
TEdgeSlip::Collapse(int topCoord, int delta)
{
  TWindow* first = GetFirstChild();
  if (first) {
    TWindow* w = first;
    do {
      TRect rect = w->GetWindowRect();
      if (Location == alTop || Location == alBottom) {
        if (rect.top > topCoord) {
          rect.Offset(0, -delta);
          ::MapWindowPoints(0, *this, (LPPOINT)&rect, 1);
          w->SetWindowPos(0, rect.left, rect.top, 0, 0,
                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
        }
      }
      else {
        if (rect.left > topCoord) {
          rect.Offset(-delta, 0);
          ::MapWindowPoints(0, *this, (LPPOINT)&rect, 1);
          w->SetWindowPos(0, rect.left, rect.top, 0, 0,
                          SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
        }
      }
      w = w->Next();
    } while (w != first);
  }
}
#endif

//
// Compute the docking area size based on the dockables inside (total height
// if top/bottom docking area or total width if left/right docking area).
// Includes the non-client area etched borders or real window borders
//
TSize
TEdgeSlip::ComputeDockingArea()
{
  TRect rect(0, 0, 0, 0);

  TWindow* first = GetFirstChild();
  if (first) {
    TWindow* w = first;
    do {
      // Union of all visible areas.
      //
      if (w->Attr.Style & WS_VISIBLE)
        rect |= w->GetWindowRect();
      w = w->Next();
    } while (w != first);
  }

  // Only add in space if this slip is not shrunk to nothing
  //
  if (rect.bottom > rect.top && rect.right > rect.left) {
    if (!(Attr.Style & WS_BORDER)) { // if 3d style, add space for the etchings
      if (Location != alBottom)
        rect.bottom += 2;
      if (Location != alTop)
        rect.bottom += 2;
    }
    else {
      AdjustWindowRectEx(rect, Attr.Style, false, Attr.ExStyle);
    }
  }

  return rect.Size();  
}

//
// Return the perpendicular size of the grid line with the given baseCoord.
//    ... 0 if there are not dockables on the given grid line.
//
int
TEdgeSlip::GridSize(int baseCoord)
{
  TWindow* first = GetFirstChild();
  int h = 0;
  if (first) {
    TWindow* w = first;
    do {
      if (w->Attr.Style & WS_VISIBLE) {
        TRect r = w->GetWindowRect();

        if (GridType == YCoord) {
          if (baseCoord == r.top) {
            h = max(h, r.Height());
          }
        }
        else {
          if (baseCoord == r.left) {
            h = max(h, r.Width());
          }
        }
      }
      w = w->Next();
    } while (w != first);
  }
  return h;
}

//
// Retrieve the location of the slip.
//
TAbsLocation
TEdgeSlip::GetLocation() const
{
  return Location;
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(THarbor, TWindow)
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_LBUTTONUP,
END_RESPONSE_TABLE;

//
// Create the harbor.
// The harbor is where the slips can go dock.
//
THarbor::THarbor(TDecoratedFrame& df)
:
  TWindow(&df, "Harbor"),
  DecFrame(df)
{
  Attr.W = 0;
  Attr.H = 0;
  Attr.Style = WS_CHILD;  // not visible

  SlipTop    = 0;
  SlipLeft   = 0;
  SlipBottom = 0;
  SlipRight  = 0;

  DragDC        = 0;
  DragDockable  = 0;
}

//
// Destructor.
// Currently does nothing.
//
THarbor::~THarbor()
{
}

//
//
void
THarbor::SetupWindow()
{
  TWindow::SetupWindow();
}

//
// Create an edge slip at a location.
//
TEdgeSlip*
THarbor::ConstructEdgeSlip(TDecoratedFrame& df, TAbsLocation location)
{
  return new TEdgeSlip(df, location);
}

//
// Construct a floating slip with a particular window at a location.
//
TFloatingSlip*
THarbor::ConstructFloatingSlip(TDecoratedFrame& df, int x, int y, TWindow* dockableWindow)
{
  return new TFloatingSlip(&df, x, y, dockableWindow);
}

//
// Return the slip at the location.
//
TEdgeSlip*
THarbor::GetEdgeSlip(TAbsLocation location)
{
  switch (location) {
    case alTop:
      return SlipTop;
    case alBottom:
      return SlipBottom;
    case alLeft:
      return SlipLeft;
    case alRight:
      return SlipRight;
  }
  return 0;
}

//
// Set a new edge slip for a given location. Also lets the edge slip know
// who we are.
//
void
THarbor::SetEdgeSlip(TAbsLocation location, TEdgeSlip* slip)
{
  slip->SetHarbor(this);

  switch (location) {
    case alTop:
      SlipTop = slip;
      break;
    case alBottom:
      SlipBottom = slip;
      break;
    case alLeft:
      SlipLeft = slip;
      break;
    case alRight:
      SlipRight = slip;
      break;
  }
}

//
// Return the default docking relatve position for a given slip location
//
TRelPosition
THarbor::GetSlipPosition(TAbsLocation location)
{
  switch (location) {
    case alTop:
      return rpBelow;
    case alBottom:
      return rpAbove;
    case alLeft:
      return rpRightOf;
    case alRight:
      return rpLeftOf;
  }
  return rpNone;
}

//
// Draw a fast window-type frame rect
//
static int fastWindowFrame(TDC& dc, const TRect& r, bool thick, uint32 rop)
{
  int thickness = thick ? TUIMetric::CxSizeFrame // a thick
                        : TUIMetric::CxBorder;   // or a thin frame

  int x = r.left;
  int y = r.top;
  int cx = r.right - x - thickness;
  int cy = r.bottom - y - thickness;

  static THatch8x8Brush ditherBrush(THatch8x8Brush::Hatch11F1);
  if (thick)
    dc.SelectObject(ditherBrush);
  else
    dc.SelectStockObject(WHITE_BRUSH);

  dc.PatBlt(x, y, thickness, cy, rop);                  // Left
  dc.PatBlt(x + thickness, y, cx, thickness, rop);      // Top
  dc.PatBlt(x, y + cy, cx, thickness, rop);             // Bottom
  dc.PatBlt(x + cx, y + thickness, thickness, cy, rop); // Right

  return true;
}

//
// Begin a dockable window tracking session. Return true if started OK.
//
bool
THarbor::DockDraggingBegin(TDockable& dockable, TPoint& point,
                           TAbsLocation location, TDockingSlip* dragNotificatee)
{
  // Get dockable to drag, its frame rectangle & the mouse anchor point
  // Compute relative position of mouse from top/left corner of window.
  //
  DragDockable = &dockable;
  DragDockable->GetRect(DragFrame);
  DragAnchor = point - DragFrame.TopLeft();

  // Remember the docking area & original docking area too. Also remember which
  // docking slip to notify when drag is done.
  //
  DragOrgSlipLoc = DragSlipLoc = location;
  DragNotificatee = dragNotificatee;

  // Find out the sizes of the dockable in the three orientations:
  //   Vertical, Horizontal & Natural
  //
  DragHSize = DragDockable->ComputeSize(alTop, 0);
  DragVSize = DragDockable->ComputeSize(alLeft, 0);
  DragNSize = DragDockable->ComputeSize(alNone, 0);

  // Calculate the screen relative rectangles for the four docking areas based
  // on the dec frame's client area.
  //
  TRect frameR = DecFrame.GetClientWindow()->GetWindowRect();
//  DecFrame.MapWindowPoints(0, frameR, 2);

  if (SlipTop)
    SlipTR = SlipTop->GetWindowRect();
  else
    SlipTR.Set(frameR.left, frameR.top, frameR.right, frameR.top);

  if (SlipBottom)
    SlipBR = SlipBottom->GetWindowRect();
  else
    SlipBR.Set(frameR.left, frameR.bottom, frameR.right, frameR.bottom);

  if (SlipLeft)
    SlipLR = SlipLeft->GetWindowRect();
  else
    SlipLR.Set(frameR.left, frameR.top, frameR.left, frameR.bottom);

  if (SlipRight)
    SlipRR = SlipRight->GetWindowRect();
  else
    SlipRR.Set(frameR.right, frameR.top, frameR.right, frameR.bottom);

  // Capture the mouse & create a screen DC to use while dragging
  //
  SetCapture();
  DragDC = new TScreenDC;

  // Update dragged window here to avoid asynchronous repaint uglies when
  // exposed by click. Then paint frame.
  //
  DragDockable->GetWindow()->UpdateWindow();
  fastWindowFrame(*DragDC, DragFrame, DragSlipLoc == alNone, PATINVERT);

  return true;
}

//
// Handle MouseMove to perform dockable dragging if a drag is in progress
//
void
THarbor::EvMouseMove(uint modKeys, TPoint& point)
{
  if (DragDockable && DragDC) {
    MapWindowPoints(0, &point, 1);

    // Save un-painting the frame until the end to reduce flicker
    //
    TRect        oldDragFrame = DragFrame;
    TAbsLocation oldDragSlipLoc = DragSlipLoc;

    // Compute the new horz, vert & natural frames to test for touching of
    // edge slips & to eventualy update DragRect. Make sure that horz & vert
    // rects surround mouse, shift as needed.
    //
    DragFrame.MoveTo(point.x - DragAnchor.x, point.y - DragAnchor.y);

    TRect hFrame(DragFrame.TopLeft(), DragHSize);
    if (!hFrame.Contains(point))
      hFrame.MoveTo(hFrame.left, point.y - DragHSize.cy/2);

    TRect vFrame(DragFrame.TopLeft(), DragVSize);
    if (!vFrame.Contains(point))
      vFrame.MoveTo(point.x - DragVSize.cx/2, vFrame.top);

    TRect nFrame(DragFrame.TopLeft(), DragNSize);
    if (!nFrame.Contains(point))
      nFrame.Offset(point.x - DragNSize.cx/2 - nFrame.left,
                    point.y - DragNSize.cy/2 - nFrame.top);

    if (hFrame.Touches(SlipTR))
      DragSlipLoc = alTop;
    else if (hFrame.Touches(SlipBR))
      DragSlipLoc = alBottom;
    else if (vFrame.Touches(SlipLR))
      DragSlipLoc = alLeft;
    else if (vFrame.Touches(SlipRR))
      DragSlipLoc = alRight;
    else
      DragSlipLoc = alNone;

    // If over a docking area and it is not the same as the last one, then
    // re-compute the frame rectangle
    //
    if (DragSlipLoc == alNone)
      DragFrame = nFrame;
    else if (DragSlipLoc == alTop || DragSlipLoc == alBottom)
      DragFrame = hFrame;
    else
      DragFrame = vFrame;

    // horz & vert?
    //
//    if (!DragFrame.Contains(point))
//      DragFrame.Offset(point.x - DragFrame.left - 15, point.y - DragFrame.top - 15);

    // Unpaint old frame, & paint new frame
    //
    fastWindowFrame(*DragDC, oldDragFrame, oldDragSlipLoc == alNone, PATINVERT);
    fastWindowFrame(*DragDC, DragFrame, DragSlipLoc == alNone, PATINVERT);
  }
  else
    TWindow::EvMouseMove(modKeys, point);
}

//
// Handle mouse up to possibly drop a dockable window being dragged
//
void
THarbor::EvLButtonUp(uint modKeys, TPoint& point)
{
  if (DragDockable && DragDC) {

    // Unpaint frame.
    //
    fastWindowFrame(*DragDC, DragFrame, DragSlipLoc == alNone, PATINVERT);

    ReleaseCapture();

    TRect orgDragRect;
    DragDockable->GetRect(orgDragRect);

    TDockable* dragDockable = DragDockable;
    DragDockable = 0;

    delete DragDC;
    DragDC = 0;

    // We're docking into a new slip--call the Move function to do the
    // work.
    //
    if (DragOrgSlipLoc != DragSlipLoc) {
      // Get the real dockable interface for the actual dockable window--
      // working dockable may have been a helper.
      //
      TDockable* dd = TYPESAFE_DOWNCAST(dragDockable->GetWindow(), TDockable);
      Move(*dd, DragSlipLoc, &DragFrame.TopLeft());
    }
    // Notifiy docking slip that the dragging resulted in a dockable move.
    //
    else {
      if (DragNotificatee)
        DragNotificatee->DockableMove(*dragDockable, &DragFrame.TopLeft());
    }
  }
  else
    TWindow::EvLButtonUp(modKeys, point);
}

//
// Handle the left button double click and forward the message to the
// dockable window.
//
void
THarbor::EvLButtonDblClk(uint modKeys, TPoint& point)
{
  // We get this message when a slip is in drag mode, and mouse clicks are
  // captured by the harbor.
  //
  if (DragDockable) {
    // If dragging, stop dragging and pass the message to the dragged window.
    //
    TWindow* win = DragDockable->GetWindow();
    EvLButtonUp(modKeys, point);
    win->HandleMessage(WM_LBUTTONDBLCLK, modKeys, MkParam2(point.x, point.y));
  }
  else {
    EvLButtonUp(modKeys, point);
  }
}

//
// Insert a dockable into the appropriate docking area indicate by the given
// location and either a point or a relative dockable&position
//
void
THarbor::Insert(TDockable& dockable, TAbsLocation location,
                const TPoint* where,
                TRelPosition position, TDockable* relDockable)
{
  // Get the actual window associated with the dockable
  //
  TWindow* dw = dockable.GetWindow();

  // Making the dockable Floating.
  //
  if (location == alNone) {
    // The 'where' is relative to the decframe's client. Make absolute when
    // the floatFrame is a popup
    //
    TPoint floatWhere;
    if (where) {
      floatWhere = *where;
//      DecFrame.MapWindowPoints(0, &floatWhere, 1);  
    }
    else {
      // Don't know where to put the floating palette, so put it at top-left
      // of client area.
//      floatWhere = DecFrame.GetClientRect().TopLeft();
//      DecFrame.MapWindowPoints(0, &floatWhere, 1);
      floatWhere = TPoint(CW_USEDEFAULT, CW_USEDEFAULT);
    }

    // Call out to the virtual to contruct a hidden floating slip
    //
    TFloatingSlip* slip = ConstructFloatingSlip(DecFrame,
                                                floatWhere.x, floatWhere.y, dw);
    slip->SetHarbor(this);
    slip->Create();
    slip->DockableInsert(dockable, where, rpNone, 0);
    slip->ShowWindow(SW_SHOWNA);
  }
  else {
    TEdgeSlip* slip = GetEdgeSlip(location);
    if (!slip) {
      // Make an edge slip if not one already for the given edge
      //
      slip = ConstructEdgeSlip(DecFrame, location);
      SetEdgeSlip(location, slip);
      DecFrame.Insert(*slip, (TDecoratedFrame::TLocation)location);

      if (DecFrame.GetHandle())  // Make sure the slip is created if frame is
        slip->Create();
    }

    // Insert the dockable into the slip, based on args given
    //
    slip->DockableInsert(dockable, where, position, relDockable);
  }

}

//
// Move a dockable from one slip to another
//
void
THarbor::Move(TDockable& dockable, TAbsLocation location, const TPoint* where,
              TRelPosition position, TDockable* relDockable)
{
  // Get current slip, assuming it is the parent of the dockable's window
  //
  TDockingSlip* previousSlip = 0;
  TWindow* dockableWindow = dockable.GetWindow();
  if (dockableWindow) {
    previousSlip = TYPESAFE_DOWNCAST(dockableWindow->Parent, TDockingSlip);
  }

  // If the location hasn't changes, just tweak the position within the slip,
  // otherwise insert into new & remove from old.
  //
  if (previousSlip && previousSlip->GetLocation() == location) {
    if (where)
      previousSlip->DockableMove(dockable, where);
    else
      ;
  }
  else {
    TRect previousRect;
    dockable.GetRect(previousRect);

    // Remove from the previous slip
    //
    Remove(dockable);

    // Insert into the new slip
    //
    Insert(dockable, location, where, position, relDockable);
  }
}

//
// Remove a dockable from the harbor
//
void
THarbor::Remove(TDockable& dockable)
{
  // Find the slip containg the dockable
  // Get the actual window associated with the dockable
  //
  TWindow* dockableWindow = dockable.GetWindow();

  if (dockableWindow) {
    TRect previousRect;
    dockable.GetRect(previousRect);

    // Find the slip containg the dockable
    //
    TDockingSlip* previousSlip = TYPESAFE_DOWNCAST(dockableWindow->Parent, TDockingSlip);

    // Remove the dockable from the slip
    //
    dockableWindow->ShowWindow(SW_HIDE);
    dockableWindow->SetParent(this);

    // Notify original docking slip that its dockable was removed.
    //
    if (previousSlip)
      previousSlip->DockableRemoved(previousRect);
  }
}

#endif  // SECTION == 1
