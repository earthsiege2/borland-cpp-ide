//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\decframe.cpp
//   Implementation of class TDecoratedFrame
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\decframe.h>
#include <owl\messageb.h>

DIAG_DECLARE_GROUP(OwlWin);  // diagnostic group for windows

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE2(TDecoratedFrame, TFrameWindow, TLayoutWindow)
  EV_WM_ENTERIDLE,
  EV_WM_MENUSELECT,
  EV_WM_SIZE,           // inline in decframe.h
END_RESPONSE_TABLE;

const UINT  BLANK_HELP = UINT_MAX;

TDecoratedFrame::TDecoratedFrame(TWindow*        parent,
                                 const char far* title,
                                 TWindow*        clientWnd,
                                 BOOL            trackMenuSelection,
                                 TModule*        module)
  : TLayoutWindow(parent, title, module)
{
  //
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(parent, title, module);
  TFrameWindow::Init(clientWnd, FALSE);

  TLayoutMetrics  metrics;

  TrackMenuSelection = trackMenuSelection;
  MenuItemId = 0;

  if (!ClientWnd)
    ClientWnd = new TWindow(this, "\007");  // create dummy placeholder

  if (ClientWnd->Attr.Style & WS_BORDER) {
    metrics.X.SameAs(lmParent, lmLeft);
    metrics.Y.SameAs(lmParent, lmTop);
    metrics.Width.SameAs(lmParent, lmRight);
    metrics.Height.SameAs(lmParent, lmBottom);

  } else {
    metrics.X.Set(lmLeft, lmRightOf, lmParent, lmLeft);
    metrics.Y.Set(lmTop, lmBelow, lmParent, lmTop);
    metrics.Width.Set(lmRight, lmLeftOf, lmParent, lmRight);
    metrics.Height.Set(lmBottom, lmAbove, lmParent, lmBottom);
  }

  SetChildLayoutMetrics(*ClientWnd, metrics);
}

void
TDecoratedFrame::SetupWindow()
{
  TRect  clientRect = GetClientRect();

  TFrameWindow::SetupWindow();

  //
  // size/position child windows. don't wait until we get the WM_SIZE event
  // because by then the windows will have been displayed on the screen
  //
  ClientSize.cx = clientRect.right;
  ClientSize.cy = clientRect.bottom;
  Layout();
}

TWindow*
TDecoratedFrame::SetClientWindow(TWindow* clientWnd)
{
  TLayoutMetrics metrics;
  GetChildLayoutMetrics(*ClientWnd, metrics);
  if (!clientWnd)
    clientWnd = new TWindow(this, "\007");  // create dummy placeholder

  TWindow* oldWnd = TFrameWindow::SetClientWindow(clientWnd);
  SetChildLayoutMetrics(*clientWnd, metrics);
  Layout();
  if (oldWnd->Title[0] == 007) {
    oldWnd->Destroy();
    delete oldWnd;
    oldWnd = 0;
  }
  return oldWnd;
}

BOOL
TDecoratedFrame::PreProcessMsg(MSG& msg)
{
  //
  // give the decorations an opportunity to do pre-processing. don't bother
  // checking the client window since it is typically in the focus chain and
  // will be given an opportunity to do pre-processing
  //
  TWindow*  firstChild = GetFirstChild();

  if (firstChild) {
    TWindow*  child = firstChild;

    do {
      if (child != ClientWnd && child->HWindow &&
         (child->GetWindowLong(GWL_STYLE) & WS_VISIBLE) &&
          child->PreProcessMsg(msg))
        return TRUE;

      child = child->Next();
    } while (child != firstChild);
  }

  return TFrameWindow::PreProcessMsg(msg);
}

void
TDecoratedFrame::EvMenuSelect(UINT menuItemId, UINT flags, HMENU hMenu)
{
  if (TrackMenuSelection)
    if (flags == 0xFFFF && hMenu == 0) {  // menu closing
      TMessageBar*  messageBar = (TMessageBar*)ChildWithId(IDW_STATUSBAR);
      CHECK(messageBar);

      messageBar->SetHintText(0);
      MenuItemId = 0;           // restore status bar to normal look

    } else if (flags & (MF_SEPARATOR | MF_POPUP | MF_MENUBREAK | MF_MENUBARBREAK)
      || (menuItemId >= IDW_FIRSTMDICHILD && menuItemId < IDW_FIRSTMDICHILD+9)) {
      MenuItemId = BLANK_HELP;  // display an empty help message
                                // could also restore bar at this point too

    } else {
      MenuItemId = menuItemId;  // display a help message with this string Id
    }
}

void
TDecoratedFrame::EvEnterIdle(UINT source, HWND /*hWndDlg*/)
{
  if (source == MSGF_MENU && MenuItemId) {
    char          buf[128];
    TMessageBar*  messageBar = (TMessageBar*)ChildWithId(IDW_STATUSBAR);
    CHECK(messageBar);

    if (MenuItemId != BLANK_HELP) {
      int numBytes = GetModule()->LoadString(MenuItemId, buf, sizeof(buf));
      if (numBytes == 0 && MergeModule != 0)
          numBytes = MergeModule->LoadString(MenuItemId, buf, sizeof(buf));

      WARNX(OwlWin, numBytes == 0, 0,
           "TDecoratedFrame::EvEnterIdle LoadString("
           << *GetModule() << "," << MenuItemId << ") Failed");
    } else
      *buf = 0;
    messageBar->SetHintText(buf);
    MenuItemId = 0;             // Don't repaint on subsequent EvEnterIdle's
  }
}

//
// Get or set location codes stashed in the style long for a decoration
//
inline TDecoratedFrame::TLocation
GetLocation(TWindow& w) {
  return TDecoratedFrame::TLocation(WORD(w.Attr.Style) & 0x0F00);
}

inline void
SetLocation(TWindow& w, TDecoratedFrame::TLocation loc) {
  w.Attr.Style = (w.Attr.Style&~0x0F00) | loc;
}

//
// Find first sibling of a decoration in the same location
//
struct TSiblingSearch {
  TWindow*                   Decoration;
  TDecoratedFrame::TLocation Location;
  TWindow*                   Sibling;

  TSiblingSearch(TWindow* decoration, TDecoratedFrame::TLocation location)
  {
    Decoration = decoration;
    Sibling = 0;
    Location = location;
  }
};

static BOOL
FindSibling(TWindow* win, void* param)
{
  TSiblingSearch*  search = (TSiblingSearch*)param;

  if (win == search->Decoration)
    return TRUE;

  else if (GetLocation(*win) == search->Location && win->IsWindowVisible())
    search->Sibling = win;

  return FALSE;
}

LRESULT
TDecoratedFrame::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  if (hWndCtl == 0) {
    TWindow*  decoration = ChildWithId(id);

    if (decoration) {
      BOOL            visible = decoration->IsWindowVisible();
      TLocation       location = GetLocation(*decoration);

      TSiblingSearch  search(decoration, location);
      FirstThat(FindSibling, &search);
      if (!search.Sibling)
        search.Sibling = ClientWnd;

      //
      // toggle the window's visibility
      //
      if (visible)
        RemoveChildLayoutMetrics(*decoration);

      else
        switch (location) {
          case Top:
            InsertAtTop(*decoration, search.Sibling);
            break;

          case Bottom:
            InsertAtBottom(*decoration, search.Sibling);
            break;

          case Left:
            InsertAtLeft(*decoration, search.Sibling);
            break;

          case Right:
            InsertAtRight(*decoration, search.Sibling);
            break;
        }

      Layout();
      decoration->ShowWindow(visible ? SW_HIDE : SW_SHOW);
      return 0;
    }
  }

  return TFrameWindow::EvCommand(id, hWndCtl, notifyCode);
}

void
TDecoratedFrame::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  TWindow*  decoration = ChildWithId(commandEnabler.Id);

  if (!decoration)
    TFrameWindow::EvCommandEnable(commandEnabler);

  else {
    commandEnabler.Enable();
    commandEnabler.SetCheck(decoration->IsWindowVisible() ?
                            TCommandEnabler::Checked :
                            TCommandEnabler::Unchecked);
  }
}

void
TDecoratedFrame::InsertAtTop(TWindow& decoration, TWindow* insertAbove)
{
  TLayoutMetrics   metrics;
  TWindow*         insertBelow;

  //
  // get the layout metrics for "insertAbove" (the window the decoration is
  // going to be inserted above)
  //
  GetChildLayoutMetrics(*insertAbove, metrics);

  insertBelow = metrics.Y.RelWin;

  //
  // if "insertAbove" has a border then set its top edge to be the same as
  // the decoration's bottom edge; otherwise place its top edge below the
  // decoration's bottom edge
  //
  metrics.Y.Set(lmTop,
                insertAbove->Attr.Style & WS_BORDER ? lmSameAs : lmBelow,
                &decoration, lmBottom);
  SetChildLayoutMetrics(*insertAbove, metrics);

  //
  // now set the layout metrics for the decoration so its top edge is the same
  // as the bottom edge of "insertBelow"(i.e. they overlap)
  //
  if (!insertBelow)
    metrics.Y.SameAs(lmParent, lmTop);

  else
    metrics.Y.Set(lmTop, lmSameAs, insertBelow, lmBottom);

  metrics.Height.MyEdge = lmHeight;
  metrics.Height.Relationship = lmAsIs;
  metrics.X.Set(lmLeft, lmSameAs, lmParent, lmLeft);
  metrics.Width.Set(lmRight, lmSameAs, lmParent, lmRight);

  SetChildLayoutMetrics(decoration, metrics);
}

void
TDecoratedFrame::InsertAtBottom(TWindow& decoration, TWindow* insertBelow)
{
  TLayoutMetrics  metrics;
  TWindow*        insertAbove;

  //
  // get the layout metrics for "insertBelow"(the window the decoration is
  // going to be inserted below)
  //
  GetChildLayoutMetrics(*insertBelow, metrics);

  if (insertBelow == ClientWnd) {
    insertAbove = metrics.Height.RelWin;
    //
    // if the client window has a border then set the client window's bottom
    // to be the same as the top edge of the decoration; otherwise set the
    // client window's bottom edge to be above the decoration's top edge
    //
    metrics.Height.Set(lmBottom,
                       ClientWnd->Attr.Style & WS_BORDER ? lmSameAs : lmAbove,
                       &decoration, lmTop);

  } else {
    insertAbove = metrics.Y.RelWin;
    //
    // set the bottom edge of "insertBelow" to be the same as the top edge of
    // the decoration
    //
    metrics.Y.Set(lmBottom, lmSameAs, &decoration, lmTop);
  }
  SetChildLayoutMetrics(*insertBelow, metrics);

  //
  // now set the layout metrics for the decoration so its bottom edge is the
  // same as the top edge of "insertAbove"
  //
  if (!insertAbove)
    metrics.Y.SameAs(lmParent, lmBottom);

  else
    metrics.Y.Set(lmBottom, lmSameAs, insertAbove, lmTop);

  metrics.Height.MyEdge = lmHeight;
  metrics.Height.Relationship = lmAsIs;
  metrics.X.Set(lmLeft, lmSameAs, lmParent, lmLeft);
  metrics.Width.Set(lmRight, lmSameAs, lmParent, lmRight);

  SetChildLayoutMetrics(decoration, metrics);
}

void
TDecoratedFrame::InsertAtLeft(TWindow& decoration, TWindow* insertLeftOf)
{
  TLayoutMetrics  metrics;
  TWindow*        insertRightOf;

  //
  // get the layout metrics for "insertLeftOf"(the window the decoration is
  // going to be inserted to the left of)
  //
  GetChildLayoutMetrics(*insertLeftOf, metrics);

  insertRightOf = metrics.X.RelWin;

  //
  // if "insertLeftOf" has a border then set its left edge to be the same as
  // the decoration's right edge; otherwise place its left edge one pixel to
  // the right of the decoration's right edge
  //
  metrics.X.Set(lmLeft,
                insertLeftOf->Attr.Style & WS_BORDER ? lmSameAs : lmRightOf,
                &decoration, lmRight);
  SetChildLayoutMetrics(*insertLeftOf, metrics);

  //
  // now set the layout metrics for the decoration so it's left edge is the
  // same as the right edge of "insertRightOf"
  //
  if (!insertRightOf)
    metrics.X.SameAs(lmParent, lmLeft);

  else
    metrics.X.Set(lmLeft, lmSameAs, insertRightOf, lmRight);

  metrics.Width.MyEdge = lmWidth;
  metrics.Width.Relationship = lmAsIs;
  //
  // if the client window has a border then place the decoration so its
  // "y" and "bottom" are the same as the client windows; otherwise place
  // its "y" above the client window's "y" and its "bottom" below the client
  // window's "bottom"
  //
  // this way if there are top or bottom decorations they will be tiled
  // over/under the left/right decorations
  //
  if (ClientWnd->Attr.Style & WS_BORDER) {
    metrics.Y.SameAs(ClientWnd, lmTop);
    metrics.Height.SameAs(ClientWnd, lmBottom);

  } else {
    metrics.Y.Set(lmTop, lmAbove, ClientWnd, lmTop);
    metrics.Height.Set(lmBottom, lmBelow, ClientWnd, lmBottom);
  }
  SetChildLayoutMetrics(decoration, metrics);
}

void
TDecoratedFrame::InsertAtRight(TWindow& decoration, TWindow* insertRightOf)
{
  TLayoutMetrics  metrics;
  TWindow*        insertLeftOf;

  //
  // get the layout metrics for "insertRightOf"(the window the decoration is
  // going to be inserted to the right of)
  //
  GetChildLayoutMetrics(*insertRightOf, metrics);

  if (insertRightOf == ClientWnd) {
    insertLeftOf = metrics.Width.RelWin;
    //
    // if the client window has a border then set the client window's right
    // edge to be the same as the left edge of the decoration; otherwise set
    // the client window's right edge to be one pixel to the left of the
    // decoration's left edge
    //
    metrics.Width.Set(lmRight,
                      ClientWnd->Attr.Style & WS_BORDER ? lmSameAs : lmLeftOf,
                      &decoration, lmLeft);

  } else {
    insertLeftOf = metrics.X.RelWin;
    //
    // set the right edge of "insertRightOf" to be the same as the left edge of
    // the decoration
    //
    metrics.X.Set(lmRight, lmSameAs, &decoration, lmLeft);
  }
  SetChildLayoutMetrics(*insertRightOf, metrics);

  //
  // now set the layout metrics for the decoration so its right edge is the
  // same as the left edge of "insertLeftOf"
  //
  if (!insertLeftOf)
    metrics.X.Set(lmRight, lmSameAs, lmParent, lmRight);

  else
    metrics.X.Set(lmRight, lmSameAs, insertLeftOf, lmLeft);

  metrics.Width.MyEdge = lmWidth;
  metrics.Width.Relationship = lmAsIs;
  //
  // if the client window has a border then place the decoration so its
  // "y" and "bottom" are the same as the client windows; otherwise place
  // its "y" above the client window's "y" and its "bottom" below the client
  // window's "bottom"
  //
  // this way if there are top or bottom decorations they will be tiled
  // over/under the left/right decorations
  //
  if (ClientWnd->Attr.Style & WS_BORDER) {
    metrics.Y.SameAs(ClientWnd, lmTop);
    metrics.Height.SameAs(ClientWnd, lmBottom);

  } else {
    metrics.Y.Set(lmTop, lmAbove, ClientWnd, lmTop);
    metrics.Height.Set(lmBottom, lmBelow, ClientWnd, lmBottom);
  }
  SetChildLayoutMetrics(decoration, metrics);
}

void
TDecoratedFrame::Insert(TWindow& decoration, TLocation location)
{
  SetLocation(decoration, location);  // keep loc for removal & sibling inserts

  decoration.SetParent(this);
  RemoveChildLayoutMetrics(decoration); // in case this is a re-insert

  if (decoration.Attr.Style & WS_VISIBLE)
    switch (location) {
      case Top:
        InsertAtTop(decoration, ClientWnd);
        break;

      case Bottom:
        InsertAtBottom(decoration, ClientWnd);
        break;

      case Left:
        InsertAtLeft(decoration, ClientWnd);
        break;

      case Right:
        InsertAtRight(decoration, ClientWnd);
        break;
    }
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE3(TDecoratedFrame, TFrameWindow, TLayoutWindow, TWindow);

void*
TDecoratedFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadVirtualBase((TFrameWindow*)GetObject(), is);
  ReadBaseObject((TLayoutWindow*)GetObject(), is);
  return GetObject();
}

void
TDecoratedFrame::Streamer::Write(opstream& os) const
{
  WriteVirtualBase((TFrameWindow*)GetObject(), os);
  WriteBaseObject((TLayoutWindow*)GetObject(), os);
}

#endif
