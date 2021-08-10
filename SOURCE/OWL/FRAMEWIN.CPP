//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\framewin.cpp
//   Implementation of class TFrameWindow
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\framewin.h>
#include <owl\applicat.h>
#include <owl\menu.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TFrameWindow, TWindow)
  EV_WM_PAINT,
  EV_WM_ERASEBKGND,
  EV_WM_QUERYDRAGICON,
  EV_WM_INITMENUPOPUP,
  EV_WM_SETFOCUS,
  EV_WM_SIZE,
  EV_WM_PARENTNOTIFY,
END_RESPONSE_TABLE;

//
// command enabler for menu items
//
class _OWLCLASS TMenuItemEnabler : public TCommandEnabler {
  public:
    TMenuItemEnabler(HMENU hMenu, UINT id, HWND hWndReceiver, int position)
      : TCommandEnabler(id, hWndReceiver) {HMenu = hMenu; Position = position;}

    //
    // override member functions of TCommandEnabler
    //
    void  Enable(BOOL);
    void  SetText(LPCSTR);
    void  SetCheck(int);

  protected:
    HMENU  HMenu;
    int    Position;
};

void
TMenuItemEnabler::Enable(BOOL enable)
{
  TCommandEnabler::Enable(enable);
  ::EnableMenuItem(HMenu, Position,
                   MF_BYPOSITION | (enable ? MF_ENABLED : MF_GRAYED));
}

void
TMenuItemEnabler::SetText(LPCSTR str)
{
  ::ModifyMenu(HMenu, Position, MF_BYPOSITION | MF_STRING, Id, str);
}

void
TMenuItemEnabler::SetCheck(int state)
{
  ::CheckMenuItem(HMenu, Position,
                  MF_BYPOSITION | (state == Checked ? MF_CHECKED : MF_UNCHECKED));
}

//----------------------------------------------------------------------------

//
// constructor for a TFrameWindow
//
TFrameWindow::TFrameWindow(TWindow*        parent,
                           const char far* title,
                           TWindow*        clientWnd,
                           BOOL            shrinkToClient,
                           TModule*        module)
{
  //
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(parent, title, module);


  IconResId = 0;  // remember that we still need to init
  Init(clientWnd, shrinkToClient);
}

//
// constructor for a TFrameWindow. This ctor is generally not used by derived
// classes
//
TFrameWindow::TFrameWindow(HWND hWnd, TModule* module)
  : TWindow(hWnd, module)
{
  Init(0);
}

//
// Protected constructor for use by immediate virtually derived classes.
// Immediate derivitives must call Init() before constructions are done.
//
TFrameWindow::TFrameWindow()
{
  IconResId = 0;  // remember that we still need to init
                  // (may want to use a specific member flag)
}

//
// Normal initialization of a default constructed TFrameWindow. Is ignored
// if called more than once.
//
void
TFrameWindow::Init(TWindow* clientWnd, BOOL shrinkToClient)
{
  if (!IconResId) {
    Attr.Style = WS_OVERLAPPEDWINDOW;
    Attr.X = Attr.W = CW_USEDEFAULT;

    if (clientWnd)
      Attr.Style |= WS_CLIPCHILDREN;

    if (shrinkToClient)
      SetFlag(wfShrinkToClient);

    Init(clientWnd);
  }
}

//
// Private initializer does a bulk of the common frame window initialization
//
void
TFrameWindow::Init(TWindow* clientWnd)
{
  HWndRestoreFocus = 0;
  KeyboardHandling = FALSE;
  ClientWnd = clientWnd;

  MenuDescr = 0;
  MergeModule = 0;

  IconModule = ::Module;
  IconResId = IDI_OWLAPP;

  MinimizedPos = TPoint(-1,-1);  // Windows convention for never minimized

  if (ClientWnd) {
    ClientWnd->SetParent(this);
    ClientWnd->EnableAutoCreate();  // in case client is a dialog
  }
}

TFrameWindow::~TFrameWindow()
{
  delete MenuDescr;
}

void
TFrameWindow::EvInitMenuPopup(HMENU hPopupMenu, UINT /*index*/, BOOL sysMenu)
{
  if (!sysMenu && hPopupMenu) {
    int  count = ::GetMenuItemCount(hPopupMenu);

    for (int pos = 0; pos < count; pos++) {
      UINT  id = ::GetMenuItemID(hPopupMenu, pos);

      //
      // ignore sub-menus and separators
      //
      if (id == 0 || id == (UINT)-1)
        continue;

      //
      // Skip the rest if it is the mdi child list, or system commands
      //
      if (id == IDW_FIRSTMDICHILD || id > 0xF000)
        break;

      EvCommandEnable(TMenuItemEnabler(hPopupMenu, id, HWindow, pos));
    }
  }
}

static void
DoIdleAction(TWindow* win, void* idleCount)
{
  win->IdleAction(*(long*)idleCount);
}

//
// TFrameWindow processes idle action occurs once per block of messages
//
BOOL
TFrameWindow::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    //
    // do command enabling for the menu bar if this is the active task
    //
  #if defined(__WIN32__)
    if (GetFocus())
  #else
    HWND focus = GetFocus();
    if (focus && ::GetWindowTask(focus) == GetCurrentTask())
  #endif
      HandleMessage(WM_INITMENUPOPUP, WPARAM(::GetMenu(HWindow)));

    //
    // give child windows an opportunity to do any idle processing
    //
    ForEach(DoIdleAction, &idleCount);
  }
  return FALSE;  // we don't need any more time for now
}

LRESULT
TFrameWindow::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  //
  // extra processing for commands: send the command down the command chain
  //
  if (hWndCtl == 0) {
    HWND  hFocus = ::GetFocus();

    if (IsChild(hFocus))
      while (hFocus != HWindow) {
        TWindow*  focusWindow = GetWindowPtr(hFocus);

        if (focusWindow)
          return focusWindow->EvCommand(id, hWndCtl, notifyCode);

        hFocus = ::GetParent(hFocus);
      }
  }

  return TWindow::EvCommand(id, hWndCtl, notifyCode);
}

void
TFrameWindow::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  //
  // Dont process for windows out of our window tree (esp. other apps)
  //
  HWND  hFocus = ::GetFocus();
  if (hFocus != HWindow && !IsChild(hFocus))
    return;

  //
  // extra processing for commands: send the command down the command chain
  // if we are the original receiver
  //
  if (commandEnabler.IsReceiver(*this)) {
    while (hFocus != HWindow) {
      TWindow*  focusWindow = GetWindowPtr(hFocus);

      if (focusWindow) {
        focusWindow->EvCommandEnable(commandEnabler);

        if (commandEnabler.GetHandled())
          return;
      }

      hFocus = ::GetParent(hFocus);
    }
  }

  TWindow::EvCommandEnable(commandEnabler);

  if (commandEnabler.IsReceiver(*this) && !commandEnabler.GetHandled()) {
    //
    // no one explicitly enabled/disabled the command
    //
    // now run up the command chain checking for if any one is going to
    // handle the command; if not then disable it...
    //
    BOOL        enable = FALSE;
    TEventInfo  eventInfo(0, commandEnabler.Id);

    hFocus = ::GetFocus();
    while (TRUE) {
      TWindow*  focusWindow = GetWindowPtr(hFocus);

      if (focusWindow && focusWindow->Find(eventInfo)) {
        enable = TRUE;  // will be handled
        break;
      }

      if (hFocus == HWindow)
        break;

      hFocus = ::GetParent(hFocus);
    }

    if (!enable) {
      //
      // check if the app wants to handle it
      //
      TEventInfo enableInfo(WM_COMMAND_ENABLE, commandEnabler.Id);
      TApplication* app = GetApplication();
      if (app->Find(enableInfo)) {
        app->Dispatch(enableInfo, 0, (LPARAM)&commandEnabler);
        if (commandEnabler.GetHandled())
          return;
      }
      enable = GetApplication()->Find(eventInfo);
    }

    commandEnabler.Enable(enable);
  }
}

BOOL
TFrameWindow::PreProcessMsg(MSG& msg)
{
  if (TWindow::PreProcessMsg(msg))
    return TRUE;  // process accelerators

  else if (KeyboardHandling) {
    HWND parent = ::GetParent(msg.hwnd);

    return parent && ::IsDialogMessage(parent, &msg);
  }

  return FALSE;
}

BOOL
TFrameWindow::SetMenu(HMENU hMenu)
{
  return TWindow::SetMenu(hMenu);
}

//
// returns TRUE if successful; FALSE otherwise
//
// NOTE: this function is declared virtual, but may be called from constructors
// of classes derived from TFrameWindow. in C++, virtual functions called from
// constructors are called as though they are non-virtual
//
BOOL
TFrameWindow::AssignMenu(TResId menuResId)
{
  if (menuResId != Attr.Menu) {
    if (Attr.Menu.IsString())
      delete (char far*)Attr.Menu;

    Attr.Menu = menuResId.IsString() ? strnewdup(menuResId) : (char far*)menuResId;
  }

  //
  // if the window has been created then load and set the new menu and destroy
  // the old menu
  //
  if (!HWindow)
    return TRUE;

  HMENU oldMenu = GetMenu();
  HMENU newMenu = GetModule()->LoadMenu(Attr.Menu);

  if (IsFlagSet(wfMainWindow))
    GetApplication()->PreProcessMenu(newMenu);

  if (!SetMenu(newMenu))
    return FALSE;

  if (oldMenu)
    ::DestroyMenu(oldMenu);

  return TRUE;
}

//
//
//
BOOL
TFrameWindow::SetIcon(TModule* module, TResId resId)
{
  IconModule = module;
  IconResId = resId;
  return TRUE;
}

TWindow*
TFrameWindow::GetClientWindow()
{
  return ClientWnd;
}

//
// Removes the current client (if any) and sets a new one.
// Assumes clientWnd was parented to us.
//
TWindow*
TFrameWindow::SetClientWindow(TWindow* clientWnd)
{
  TWindow* oldClientWnd = ClientWnd;
  HWND oldHWnd = oldClientWnd ? oldClientWnd->HWindow : (HWND)0;
  RemoveChild(ClientWnd);

  if (HWndRestoreFocus == oldHWnd)
    HWndRestoreFocus = 0;

  ClientWnd = clientWnd;

  if (ClientWnd) {
    ClientWnd->SetParent(this);
    if (!ClientWnd->HWindow)
      ClientWnd->Create();
    ClientWnd->Show(SW_NORMAL);
    ResizeClientWindow();
  }
  if (ClientWnd && ClientWnd->HWindow)
    ClientWnd->SetFocus();
  else
    SetFocus();

  return oldClientWnd;
}

BOOL
TFrameWindow::SetDocTitle(LPCSTR docname, int index)
{
  if (index == 0)
    SetCaption(docname);
  else if (index > 0) {
    char buf[280];
    wsprintf(buf, "%s:%d", docname, index);
    SetCaption(buf);
  } // else if index is negative, simply acknowledge that title will display
  return TRUE;
}

//
// Obtain the real windows application icon. The IDI_APPLICATION icon is an
// ugly black & white box, but when a class is registered with this icon it
// gets substituted with a better windows icon. Worse case we end up with the
// ugly box icon.
//
static HICON
getAppIcon()
{
  static HICON hRealAppIcon = 0;
  if (!hRealAppIcon) {
    WNDCLASS wndClass;
    static char className[] = "OwlIconSnarfer";
    memset(&wndClass, 0, sizeof wndClass);
    wndClass.hInstance = *::Module;
    wndClass.hIcon = ::LoadIcon(0, IDI_APPLICATION);
    wndClass.lpszClassName = className;
    wndClass.lpfnWndProc = ::DefWindowProc;
    ::RegisterClass(&wndClass);
    ::GetClassInfo(*::Module, className, &wndClass);
    hRealAppIcon = wndClass.hIcon;
    ::UnregisterClass(className, *::Module);
  }
  return hRealAppIcon ? hRealAppIcon : ::LoadIcon(0, IDI_APPLICATION);
}  

//
// response method for an incoming WM_PAINT message
//
// if iconic, and an icon has been defined then draws that,
// or if iconic & there is a client window, then calls its paint function.
//
// if not iconic, forwards to TWindow for normal paint processing
//
void
TFrameWindow::EvPaint()
{
  if (IsIconic() && (IconResId || ClientWnd)) {
    TPaintDC  dc(HWindow);

    if (IconResId) {
      HINSTANCE hInstance = IconModule ? HINSTANCE(*IconModule) : HINSTANCE(0);
      HICON hIcon = ::LoadIcon(hInstance, IconResId);
      ::DrawIcon(dc, 0, 0, hIcon ? hIcon : getAppIcon());

    } else
        ClientWnd->Paint(dc, dc.Ps.fErase, *(TRect*)&dc.Ps.rcPaint);

  } else
    TWindow::EvPaint();
}

//
//
//
BOOL
TFrameWindow::EvEraseBkgnd(HDC hDC)
{
  if (IsIconic()) {
    if (!IconResId && ClientWnd)
      return (BOOL)ClientWnd->HandleMessage(WM_ERASEBKGND, WPARAM(hDC));

    HandleMessage(WM_ICONERASEBKGND, WPARAM(hDC));
    return TRUE;

  } else
    return (BOOL)DefaultProcessing();
}

//
//
//
HANDLE
TFrameWindow::EvQueryDragIcon()
{
  if (IconResId) {
    HINSTANCE hInstance = IconModule ? HINSTANCE(*IconModule) : HINSTANCE(0);
    HICON hIcon = ::LoadIcon(hInstance, IconResId);
    return hIcon ? hIcon : getAppIcon();

  } else
    return (HANDLE)DefaultProcessing();
}

static inline BOOL
IsEnabledVisibleChild(long style)
{
  return (style & (WS_CHILD | WS_VISIBLE | WS_DISABLED)) == (WS_CHILD | WS_VISIBLE);
}

static
TWindow*
SearchForChildWithTab(TWindow* win)
{
  TWindow*  firstChild = win->GetFirstChild();

  if (firstChild) {
    TWindow*  child = firstChild;

    do {
      if (child->HWindow) {
        long  style = child->GetWindowLong(GWL_STYLE);

        if (IsEnabledVisibleChild(style)) {
          if (style & WS_TABSTOP)
            return child;

          else {
            TWindow*  result = SearchForChildWithTab(child);
            if (result)
              return result;
          }
        }
      }
      child = child->Next();
    } while (child != firstChild);
  }

  return 0;
}

static BOOL
EnabledVisibleChild(TWindow* win, void*)
{
  return win->HWindow ? IsEnabledVisibleChild(win->GetWindowLong(GWL_STYLE)) :
                        FALSE;
}

//
// if the receiver doesn't have any children then returns 0. otherwise
// we search for the first child with WS_TABSTOP; if no child has WS_TABSTOP
// then we return the first enabled visible child
//
// does a depth-first search of nested child windows
//
// NOTE: we stop at the first child with WS_TABSTOP and do not search its
//       children...
//
TWindow*
TFrameWindow::FirstChildWithTab()
{
  TWindow*  win = SearchForChildWithTab(this);

  return win ? win : FirstThat(EnabledVisibleChild);
}

//
// Respond to a request to hold on to the handle of a child window that is
// losing focus, so that we can restore it again later.
//
// return true if caller can stop searching for a window to hold its handle.
//
BOOL
TFrameWindow::HoldFocusHWnd(HWND hWndLose, HWND hWndGain)
{
  if (IsChild(hWndLose)) {
    if (!hWndGain || !IsChild(hWndGain))
      HWndRestoreFocus = hWndLose;
    return TRUE;
  }
  return hWndLose == HWindow;
}

//
//
//
void
TFrameWindow::EvSetFocus(HWND hWndLostFocus)
{
  TWindow::EvSetFocus(hWndLostFocus);

  if (HWndRestoreFocus) {
    //
    // The child could have been destroyed at this point; ensure focus
    // doesn't get set to a deleted window when backing out KILLFOCUSes
    // during a window takedown.
    //
    if (::IsWindow(HWndRestoreFocus))
      ::SetFocus(HWndRestoreFocus);

    HWndRestoreFocus = 0;

  } else {
    TWindow*  win = FirstChildWithTab();

    if (win && win->HWindow != hWndLostFocus)
      win->SetFocus();
  }
}

//
// Close this window if the client is destroyed, or resize frame if indicated
//
void
TFrameWindow::EvParentNotify(UINT event,
                             UINT childHandleOrX, UINT /*childIDOrY*/)
{
  if (event == WM_DESTROY) {
    if (ClientWnd && ClientWnd->HWindow == HWND(childHandleOrX))
      PostMessage(WM_CLOSE);  // using ShutdownWindow() has side effects

  } else if (event == WM_SIZE) {
    if (IsFlagSet(wfShrinkToClient)
    && ClientWnd
    && ClientWnd->HWindow == HWND(childHandleOrX)
    && !IsIconic())
      ResizeClientWindow();
  }
}

//
// Resize & reposition the client window to fit in this frames client area
// or resize the frame to fit on the client's client area if wfShrinkToClient
// Return TRUE if a client was actualy resized.
// Adjust clients styles & make sure they get set.
//
BOOL
TFrameWindow::ResizeClientWindow(BOOL redraw)
{
  if (!ClientWnd)
    return FALSE;
  if (ClientWnd->IsFlagSet(wfShrinkToClient))// prevent recursion during resize  
    return TRUE;               // ignore calls from EvParentNotify and EvSize

  BOOL clientResized = FALSE;
  ClientWnd->SetFlag(wfShrinkToClient);  // disable notifications while resizing

  TSize frameSize = GetClientRect().Size();
  TSize childSize = ClientWnd->GetWindowRect().Size();
  //
  // first time through, strip client window of borders and caption
  // and set style bits to be a compatible child window
  // if shrink-to-client, then must measure the client size first
  // if the client has scrolls bars, we must hide to obtain the correct size
  //
  if (ClientWnd->Attr.Style & (WS_BORDER | WS_DLGFRAME)) {
    if (IsFlagSet(wfShrinkToClient)) {
      TSize tstSize = ClientWnd->GetClientRect().Size();
      ClientWnd->ShowScrollBar(SB_BOTH, FALSE);
      childSize = ClientWnd->GetClientRect().Size();
      if (childSize != tstSize) {
        int restore = SB_BOTH;
        if (childSize.cx == tstSize.cx)
          restore = SB_HORZ;
        if (childSize.cy == tstSize.cy)
          restore = SB_VERT;
        ClientWnd->ShowScrollBar(restore, TRUE);
      }
    } 
    ClientWnd->Attr.Style &= ~(WS_CAPTION|WS_BORDER|WS_DLGFRAME|
                               WS_SYSMENU|WS_THICKFRAME|WS_POPUP|
                               WS_MINIMIZEBOX|WS_MAXIMIZEBOX);
    ClientWnd->Attr.Style |= WS_CHILD;
    ClientWnd->Attr.ExStyle &= ~(WS_EX_DLGMODALFRAME);
    ClientWnd->SetWindowLong(GWL_STYLE, ClientWnd->Attr.Style);
    ClientWnd->SetWindowLong(GWL_EXSTYLE, ClientWnd->Attr.ExStyle);
  }
  if (childSize != frameSize) {
    if (IsFlagSet(wfShrinkToClient)) {
      TRect outside = GetWindowRect();
      TPoint outsideOrg(0, 0);
      if (Parent) {
        Parent->ClientToScreen(outsideOrg); // adjust our rect by our parent's
      }
      TSize border = outside.Size() - frameSize;
      MoveWindow(outside.left - outsideOrg.x, outside.top - outsideOrg.y,
                 childSize.cx + border.cx, childSize.cy + border.cy, redraw);
      frameSize = childSize;     // must move client, will not cause an EvSize
    } else {
      clientResized = TRUE;
    }
  }
  // if frame is sizeable, turn off flag so that user can then resize
  // after initial setup
  if (Attr.Style & WS_THICKFRAME)
    ClearFlag(wfShrinkToClient);

  ClientWnd->MoveWindow(0, 0, frameSize.cx, frameSize.cy, redraw);
  ClientWnd->ClearFlag(wfShrinkToClient);
  return clientResized;
}

//
// called following a successful association between an MS-Windows interface
// element and a TWindow
//
void
TFrameWindow::SetupWindow()
{
  //
  // create windows in child list (this includes the client window)
  //
  TWindow::SetupWindow();

  ResizeClientWindow();

  if (MinimizedPos != TPoint(-1,-1)) {
    WINDOWPLACEMENT windata;
    windata.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(&windata);
    windata.flags = WPF_SETMINPOSITION;
    windata.showCmd = SW_SHOWNA;
    windata.ptMinPosition = MinimizedPos;
    SetWindowPlacement(&windata);
  }
  //
  // if SetMenuDescr() called before window created, update the menu
  //
  if (IsFlagSet(wfMainWindow) && MenuDescr && MenuDescr->Id != Attr.Menu)
    AssignMenu(MenuDescr->Id);

  //
  // if we haven't set HWndRestoreFocus then pick the first child with tabstop
  //
  if (!HWndRestoreFocus) {
    TWindow*  win = FirstChildWithTab();

    HWndRestoreFocus = win ? win->HWindow : HWindow;
  }
}

//
// response method for an incoming WM_SIZE message
//
// if not minimizing resizes the client window to be the same size as the
// client rectangle,
// if no WM_SIZE sent, forwards WM_SIZE message to client so it can recalc.
//
void
TFrameWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);

  if (ClientWnd) {
    BOOL sizeSent = FALSE;
    if (sizeType != SIZE_MINIMIZED) {
      sizeSent = ResizeClientWindow();
      size = ClientWnd->GetClientRect().Size();
    }
    if (!sizeSent)
      ClientWnd->ForwardMessage();
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

static void
DeleteSubMenus(TMenu& fromMenu, int count)
{
  for (int j = 0; j < count; j++)
    fromMenu.DeleteMenu(0, MF_BYPOSITION);
}

//
//
//
static void
MoveSubMenus(TMenu& fromMenu, TMenu& toMenu, int count)
{
  char   str[256];
  for (int j = 0; j < count; j++) {
    fromMenu.GetMenuString(0, str, sizeof(str), MF_BYPOSITION);
    HMENU subMenu = fromMenu.GetSubMenu(0);
    if (subMenu)
      toMenu.AppendMenu(MF_POPUP, UINT(subMenu), str);
    else
      toMenu.AppendMenu(0, fromMenu.GetMenuItemID(0), str);
    fromMenu.RemoveMenu(0, MF_BYPOSITION);
  }
}

//
//
//
void
TFrameWindow::SetMenuDescr(const TMenuDescr& menuDescr)
{
  delete MenuDescr;
  MenuDescr = new TMenuDescr(menuDescr);
  if (IsFlagSet(wfMainWindow))
    AssignMenu(MenuDescr->Id);
}

BOOL
TFrameWindow::MergeMenu(const TMenuDescr& childMenuDescr)
{
  if (!MenuDescr || !HWindow)
    return FALSE;

  MergeModule = childMenuDescr.Module;
  TMenu  oldMenu(*this, NoAutoDelete);
  TMenu  newMenu(NoAutoDelete);
  TMenu  resMenu(*MenuDescr->Module, MenuDescr->Id);
  TMenu  childMenu(*MergeModule, childMenuDescr.Id);

  for (int i = 0; i < TMenuDescr::NumGroups; i++) {
    if (childMenuDescr.GroupCount[i] != 0) {
      MoveSubMenus(childMenu, newMenu, childMenuDescr.GroupCount[i]);
      DeleteSubMenus(resMenu, MenuDescr->GroupCount[i]);
    } else {
      MoveSubMenus(resMenu, newMenu, MenuDescr->GroupCount[i]);
    }
  }
  if (IsFlagSet(wfMainWindow))
    GetApplication()->PreProcessMenu(newMenu);

  if (!SetMenu(newMenu)) {
    ::DestroyMenu(newMenu);
    return FALSE;
  }

  ::DestroyMenu(oldMenu);
  return TRUE;
}

BOOL
TFrameWindow::RestoreMenu()
{
  if (!MenuDescr)
    return FALSE;

  AssignMenu(Attr.Menu);
  MergeModule = 0;
  return TRUE;
}

#endif
#if !defined(SECTION) || SECTION == 3

IMPLEMENT_STREAMABLE1(TFrameWindow, TWindow);

void*
TFrameWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TFrameWindow* o = GetObject();
  ReadVirtualBase((TWindow*)o, is);
  if (o->IsFlagSet(wfMainWindow))
    return o;

  is >> o->ClientWnd;
  is >> o->KeyboardHandling;
  o->HWndRestoreFocus = 0;

  BOOL hasMenuDescr = is.readByte();
  if (hasMenuDescr) {
    o->MenuDescr = new TMenuDescr;
    is >> *o->MenuDescr;
  } else
    o->MenuDescr = 0;

  is >> o->IconModule;
  is >> o->IconResId;
  is >> o->MergeModule;
  is >> o->MinimizedPos;

  return o;
}

//
// writes data of the TFrameWindow to the passed opstream
//
void
TFrameWindow::Streamer::Write(opstream& os) const
{
  TFrameWindow* o = GetObject();
  WriteVirtualBase((TWindow*)o, os);
  if (o->IsFlagSet(wfMainWindow))
    return;

  os << o->ClientWnd;
  os << o->KeyboardHandling;

  os.writeByte(BYTE(o->MenuDescr ? 1 : 0));
  if (o->MenuDescr)
    os << *o->MenuDescr;

  os << o->IconModule;
  os << o->IconResId;
  os << o->MergeModule;
  WINDOWPLACEMENT windata;
  windata.length = sizeof(WINDOWPLACEMENT);
  o->GetWindowPlacement(&windata);
  os << TPoint(windata.ptMinPosition);
}

#endif  // SECTION
