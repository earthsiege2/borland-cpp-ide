//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.29  $
//
// Implementation of class TFrameWindow, a TWindow with additional features
// for frames, such as client window, menus, icons, etc.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#include <stdio.h>

#if !defined(WM_SETICON)
# define WM_SETICON 0x0080
#endif

DIAG_DECLARE_GROUP(OwlCmd);

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TFrameWindow, TWindow)
  EV_WM_PAINT,
  EV_WM_ERASEBKGND,
  EV_WM_QUERYDRAGICON,
  EV_WM_INITMENUPOPUP,
  EV_WM_SETFOCUS,
  EV_WM_SIZE,
  EV_WM_PARENTNOTIFY,
  EV_WM_ENTERIDLE,
  EV_WM_QUERYNEWPALETTE,
  EV_WM_PALETTECHANGED,
END_RESPONSE_TABLE;

//
// Enable/disable the command sender, in this case the menu item.
//
void
TMenuItemEnabler::Enable(bool enable)
{
  TCommandEnabler::Enable(enable);
  ::EnableMenuItem(HMenu, Position,
                   MF_BYPOSITION | (enable ? MF_ENABLED : MF_GRAYED));
}

//
// Set the text for the command sender, in this case the menu item.
//
void
TMenuItemEnabler::SetText(const char far* str)
{
  ::ModifyMenu(HMenu, Position, MF_BYPOSITION | MF_STRING, Id, str);
}

//
// Set the check state of the command sender, in this case the menu item.
//
void
TMenuItemEnabler::SetCheck(int state)
{
  ::CheckMenuItem(HMenu, Position,
                  MF_BYPOSITION | (state == Checked ? MF_CHECKED : MF_UNCHECKED));
}

//----------------------------------------------------------------------------

//
// Constructor for a TFrameWindow
//
TFrameWindow::TFrameWindow(TWindow*        parent,
                           const char far* title,
                           TWindow*        clientWnd,
                           bool            shrinkToClient,
                           TModule*        module)
{
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(parent, title, module);


  IconResId = 0;  // remember that we still need to init
  Init(clientWnd, shrinkToClient);
}

//
// Constructor for a TFrameWindow. This ctor is generally not used by derived
// classes, only as generic alias to a framewindow-like THandle
//
TFrameWindow::TFrameWindow(THandle THandle, TModule* module)
:
  TWindow(THandle, module)
{
  Init(0);
}

//
// Protected constructor for use by immediate virtually derived classes.
// Immediate derivitives must call Init() before constructions are done.
//
TFrameWindow::TFrameWindow()
{
  IconResId = 0;  // Zero this member to remember that we still need to init
}

//
// Normal initialization of a default constructed TFrameWindow. Is ignored
// if called more than once.
//
void
TFrameWindow::Init(TWindow* clientWnd, bool shrinkToClient)
{
  if (!IconResId) {
    Attr.Style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
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
  KeyboardHandling = false;
  ClientWnd        = clientWnd;

  MenuDescr   = 0;
  MergeModule = 0;

  CurIcon      = 0;
  CurIconSm    = 0;
  IconModule   = 0;
  IconSmModule = 0;
  SetIcon(::Module, IDI_OWLAPP);
  SetIconSm(::Module, IDI_OWLAPPSM);

  MinimizedPos = TPoint(-1,-1);  // Windows convention for never minimized

  if (ClientWnd) {
    ClientWnd->SetParent(this);
    ClientWnd->EnableAutoCreate();  // in case client is a dialog
    SetBkgndColor(NoErase);         // no need to erase client area
  }
}

//
// Destructor for a TFrameWindow
//
TFrameWindow::~TFrameWindow()
{
  if (IsFlagSet(wfMainWindow))
    if (GetApplication()->GetMainWindow() == this)
      GetApplication()->MainWindow = 0;

  delete MenuDescr;
}

//
// Return a state mask representing the enabled menu items (up to 32)
//
static uint32
GetMenuStateBits(HMENU hmenu, int count)
{
  uint32 bit = 1;
  uint32 result = 0;

  for (int i = 0; i < count; i++) {
    uint state = GetMenuState(hmenu, i, MF_BYPOSITION);
    if (state != (uint)-1) {
      if (!(state  & (MF_DISABLED | MF_GRAYED))) {
        result |= bit;
      }
    }
    bit <<= 1;
  }

  return result;
}

//
// Responds to WM_INITMENUPOPUP by performing a command enable run on each
// of the menu items in the popup menu
//
void
TFrameWindow::EvInitMenuPopup(HMENU hPopupMenu, uint index, bool sysMenu)
{
  if (!sysMenu && hPopupMenu) {
    const int count = ::GetMenuItemCount(hPopupMenu);

    // Save current state of visible top level menus
    //
    uint32 preState = 0;
    if (hPopupMenu == GetMenu())
      preState = GetMenuStateBits(hPopupMenu, count);

    TWindow::EvInitMenuPopup(hPopupMenu, index, sysMenu);

    // If the top level menu state changes, redraw the menu bar
    //
    if (hPopupMenu == GetMenu())
      if (GetMenuStateBits(hPopupMenu, count) != preState)
        DrawMenuBar();
  }
}

//
// TFrameWindow processes idle action occurs once per block of messages
//
bool
TFrameWindow::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    // do command enabling for the menu bar if this is the active task
    //
#if defined(BI_PLAT_WIN32)
    if (GetFocus()) {
#else
    THandle focus = GetFocus();
    if (focus && ::GetWindowTask(focus) == GetCurrentTask()) {
#endif
      long style = ::GetWindowLong(*this, GWL_STYLE);
      if (!(style & WS_CHILD)) {
        if (IsWindow()) {
          HMENU hMenu = ::GetMenu(*this);
          if (IsMenu(hMenu))
            HandleMessage(WM_INITMENUPOPUP, TParam1(hMenu));
        }
      }
    }
  }
  // give child windows an opportunity to do any idle processing
  //
  return TWindow::IdleAction(idleCount);
}

//
// Locate and return the child window that is the target of command and command
// enable messages.
//
TWindow::THandle
TFrameWindow::GetCommandTarget()
{
  // Start with the focus window
  //
  THandle  hFocus = ::GetFocus();

  // If its a child of ours, then return it.
  //
  TWindow* client = GetClientWindow();
  if (client) {
    if (client->IsChild(hFocus)) {
      TRACEX(OwlCmd, 1, "TFrameWindow::GetCommandTarget - returns focus "\
                        "window, child of client: " << hex << uint(hFocus));
      return hFocus;
    }
  }
  else
    if (IsChild(hFocus)) {
      TRACEX(OwlCmd, 1, "TFrameWindow::GetCommandTarget - returns focus "\
                        "window, child of frame: " << hex << uint(hFocus));
      return hFocus;
    }

  // The focus is not our descendent, use our most recently active child
  //
  if (HWndRestoreFocus) {
    TRACEX(OwlCmd, 1, "TFrameWindow::GetCommandTarget - " \
                      " returns HWndRestoreFocus " \
                      << hex << uint(HWndRestoreFocus));
    return HWndRestoreFocus;
  }

  // If we have a client, fall back on that
  //
  if (GetClientWindow()) {
    TRACEX(OwlCmd, 1, "TFrameWindow::GetCommandTarget - " \
                      " returns ClientWindow " \
                      << hex << uint(THandle(*GetClientWindow())));
    return *GetClientWindow();
  }

  // Don't know who else to send it to, return ourselves
  //
  TRACEX(OwlCmd, 1, "TFrameWindow::GetCommandTarget - " \
                    " returns this frame " \
                    << hex << uint(THandle(*this)));
  return *this;
}

//
// Handle WM_COMMAND to provide extra processing for commands:
// Extra processing for commands: starts with the command target window
// (usually the focus window) and gives it and its parent windows an
// opportunity to handle the command.
//
TResult
TFrameWindow::EvCommand(uint id, THandle hCtl, uint notifyCode)
{
  TRACEX(OwlCmd, 1, "TFrameWindow::EvCommand - id(" << id << "), ctl(" <<\
                     hex << uint(hCtl) << "), code(" << notifyCode  << ")");

  // Walk the command chain from the command target back up to us or until
  // we hit a child that is an owl window. Delegate to owl-child or forward to
  // our base if no child is found.
  //
  if (hCtl == 0) {
    THandle  hCmdTarget = GetCommandTarget();

    // Check owl parentage too in case the THandles were reparented
    //
    while (hCmdTarget && hCmdTarget != GetHandle()) {
      TWindow*  cmdTarget = GetWindowPtr(hCmdTarget);

      if (cmdTarget)
        return cmdTarget->EvCommand(id, hCtl, notifyCode);

      hCmdTarget = ::GetParent(hCmdTarget);
    }
  }

  return TWindow::EvCommand(id, hCtl, notifyCode);
}

//
// Handle WM_COMMAND_ENABLE to provide command enable distribution and default
// support for windows without command enable handlers.
//
void
TFrameWindow::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  // Don't process for windows out of our window tree (esp. other apps)
  //
  RouteCommandEnable(GetCommandTarget(), commandEnabler);
}

//
// Preprocess queued messages to handle translation of accelerators on a per
// window basis, and dialog-like keyboard navigation if enabled.
//
bool
TFrameWindow::PreProcessMsg(MSG& msg)
{
  if (TWindow::PreProcessMsg(msg))
    return true;  // Processed accelerators

  if (KeyboardHandling && msg.message >= WM_KEYFIRST &&
                          msg.message <= WM_KEYLAST)
  {
    THandle parent = ::GetParent(msg.hwnd);

    // Retrieve the COMBO handle if we're in the EDIT ctrl parented to the
    // combobox
    //
    char szClassName[0x10];
    ::GetClassName(parent, szClassName, sizeof(szClassName));
    if (!strcmpi(szClassName, "COMBOBOX"))
      parent = ::GetParent(parent);

    if (parent && ::IsDialogMessage(parent, &msg));
      return true;
  }

  return false;
}

//
// Overrides TWindow's non-virtual SetMenu to make it virtual. This allows
// derived frame classes to implement this differently
// It also calls the application's PreProcessMenu() if it is the main window
// to let it make any changes just before setting.
//
bool
TFrameWindow::SetMenu(HMENU newMenu)
{
  if (IsFlagSet(wfMainWindow))
    GetApplication()->PreProcessMenu(newMenu);

  return TWindow::SetMenu(newMenu);
}

//
// Perform a high-level menu assignment either before or after the THandle for the
// window has been created.
//
// Returns true if successful; false otherwise
//
bool
TFrameWindow::AssignMenu(TResId menuResId)
{
  if (menuResId != Attr.Menu) {
    if (Attr.Menu.IsString())
      delete (char far*)Attr.Menu;

    Attr.Menu = menuResId.IsString() ? strnewdup(menuResId) : (char far*)menuResId;
  }

  // If the window has been created then load and set the new menu and destroy
  // the old menu
  //
  if (!GetHandle())
    return true;

  HMENU curMenu = GetMenu();
  HMENU newMenu = GetModule()->LoadMenu(Attr.Menu);

  if (!SetMenu(newMenu))
    return false;

  if (curMenu)
    ::DestroyMenu(curMenu);

  return true;
}

//
// Set the Icon for use when this frame is minimized
//
bool
TFrameWindow::SetIcon(TModule* module, TResId resId)
{
  // Delete old icon if not system icon
  //
  if (CurIcon && IconModule)
    ::DestroyIcon(CurIcon);

  IconModule = module;
  IconResId = resId;

  HINSTANCE hInstance = IconModule ? HINSTANCE(*IconModule) : HINSTANCE(0);

  if (IconResId != 0)
    CurIcon = TUser::LoadIcon(hInstance, IconResId);

  if (CurIcon && IsWindow())
    SendMessage(WM_SETICON, true, (LPARAM)(HICON)CurIcon);

  return true;
}

//
// Set the Small Icon (16 x 16)
//
bool
TFrameWindow::SetIconSm(TModule* module, TResId resId)
{
  // Delete old icon if not system icon
  //
  if (CurIconSm && IconSmModule)
    ::DestroyIcon(CurIconSm);

  IconSmModule = module;
  IconSmResId  = resId;

  HINSTANCE hInstance = IconSmModule ? HINSTANCE(*IconSmModule) : HINSTANCE(0);
  if (IconSmResId != 0) {
#if defined(BI_PLAT_WIN32)
    CurIconSm = (HICON)::LoadImage(hInstance, IconSmResId, IMAGE_ICON,
                                   TUIMetric::CxSmIcon, TUIMetric::CySmIcon,
                                   LR_DEFAULTCOLOR);
    if (!CurIconSm)
      CurIconSm = TUser::LoadIcon(hInstance, IconSmResId);
#else
    CurIconSm = TUser::LoadIcon(hInstance, IconSmResId);
#endif
  }

  if (CurIconSm && IsWindow())
    SendMessage(WM_SETICON, false, (LPARAM)(HICON)CurIconSm);

  return true;
}

//
// Return the current client window as a TWindow*
//
TWindow*
TFrameWindow::GetClientWindow()
{
  return ClientWnd;
}

//
// Remove the current client (if any) and set a new one.
// Assume clientWnd was parented to us.
//
TWindow*
TFrameWindow::SetClientWindow(TWindow* clientWnd)
{
  TWindow* oldClientWnd = ClientWnd;
  THandle oldWnd = oldClientWnd ? oldClientWnd->GetHandle() : (THandle)0;
  RemoveChild(ClientWnd);

  if (HWndRestoreFocus == oldWnd)
    HWndRestoreFocus = 0;

  ClientWnd = clientWnd;

  if (ClientWnd) {
    ClientWnd->SetParent(this);
    if (GetHandle()) {
      if (!ClientWnd->GetHandle())
        ClientWnd->Create();
      ClientWnd->ShowWindow(SW_SHOWNOACTIVATE);
    }
    SetBkgndColor(NoErase);         // no need to erase client area
    ResizeClientWindow(true); 
  }
  else
    SetBkgndColor(NoColor);         // will need to erase client area

  // Pass the focus to the new client, but only if we have it currently
  //
  if (ClientWnd && ClientWnd->GetHandle() && GetFocus() == GetHandle()) {
    ClientWnd->SetFocus();
    HWndRestoreFocus = ClientWnd->GetHandle();
  }

  return oldClientWnd;
}

//
// If someone removes our client with a RemoveChild() call, update our client
// and restore focus ptrs.
//
void
TFrameWindow::RemoveChild(TWindow* child)
{
  TWindow::RemoveChild(child);
  if (child) {
    if (child == ClientWnd)
      ClientWnd = 0;
    if (child->GetHandle() == HWndRestoreFocus) {
      HWndRestoreFocus = 0;
    }
  }
}

//
// Set the document style title for this frame window. Uses SetWindowText to
// modify the caption directly without modifying the Title data member.
// Generates a composite title based on Title if it exists, docname, and index
// if it is > 0.
//
//  [<Title> - ]<docname>[:<index>]
//
bool
TFrameWindow::SetDocTitle(const char far* docname, int index)
{
  if (index >= 0) {
    string title;

    if (Title && *Title) {
      title = Title;
      title += " - ";
    }

    if (docname)
      title += docname;

    if (index > 0) {
      title += ':';
      char num[10];
      itoa(index, num, 10);
      title += num;
    }

    SetWindowText(title.c_str());
  }  // else if index negative, simply acknowledge that title will display
  return true;
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
    static char className[] = "IconSnarfer";
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
// Response method for an incoming WM_PAINT message
//
// If iconic, and an icon has been defined then draw that.
// Or, if iconic & there is a client window, then call its paint function.
//
// If not iconic, forwards to TWindow for normal paint processing
//
void
TFrameWindow::EvPaint()
{
  if (IsIconic() && (IconResId || ClientWnd)) {
    TPaintDC  dc(GetHandle());

    if (IconResId) {
      SendMessage(WM_ICONERASEBKGND, TParam1(HDC(dc)));
      ::DrawIcon(dc, 0, 0, CurIcon ? CurIcon : getAppIcon());
    }
    else
      ClientWnd->Paint(dc, dc.Ps.fErase, *(TRect*)&dc.Ps.rcPaint);
  }
  else
    TWindow::EvPaint();
}

//
// Response method for an incoming WM_ERASEBKGND message
//
// If this frame window is iconic, and there is a client window, then give it
// a chance to erase the background since it may want to take over painting.
//
// If not iconic, forward to TWindow for normal erase background processing
//
bool
TFrameWindow::EvEraseBkgnd(HDC hDC)
{
  if (IsIconic()) {
    if (!IconResId && ClientWnd)
      return (bool)ClientWnd->HandleMessage(WM_ERASEBKGND, TParam1(hDC));

    HandleMessage(WM_ICONERASEBKGND, TParam1(hDC));
    return true;
  }
  else
    return TWindow::EvEraseBkgnd(hDC);
}

//
// Response method for an incoming WM_QUERYDRAGICON message
//
// If there is an icon set for this frame, then return it so that windows
// can make a nice cursor out of it when the user drags the icon
//
HANDLE
TFrameWindow::EvQueryDragIcon()
{
  if (IconResId) {
    HINSTANCE hInstance = IconModule ? HINSTANCE(*IconModule) : HINSTANCE(0);
    HICON hIcon = TUser::LoadIcon(hInstance, IconResId);
    return hIcon ? hIcon : getAppIcon();
  }
  else
    return TWindow::EvQueryDragIcon();
}

static inline bool
IsEnabledVisibleChild(long style)
{
  return (style & (WS_CHILD | WS_VISIBLE | WS_DISABLED)) == (WS_CHILD | WS_VISIBLE);
}

static TWindow*
SearchForChildWithTab(TWindow* win)
{
  TWindow*  firstChild = win->GetFirstChild();

  if (firstChild) {
    TWindow*  child = firstChild;

    do {
      if (child->GetHandle()) {
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

static bool
EnabledVisibleChild(TWindow* win, void*)
{
  return win->GetHandle() ? IsEnabledVisibleChild(win->GetWindowLong(GWL_STYLE)) :
                        false;
}

//
// If the receiver doesn't have any children then returns 0. Otherwise
// we search for the first child with WS_TABSTOP; If no child has WS_TABSTOP
// then we return the first enabled visible child
//
// Does a depth-first search of nested child windows
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
// losing focus, so that we can restore it again later (below).
//
// return true if caller can stop searching for a window to hold its handle.
//
bool
TFrameWindow::HoldFocusHWnd(THandle hWndLose, THandle hWndGain)
{
  if (IsChild(hWndLose)) {
    if (!hWndGain || !IsChild(hWndGain))
      HWndRestoreFocus = hWndLose;
    return true;
  }
  return hWndLose == GetHandle();
}

//
// Handle WM_SETFOCUS to return focus back to the child that had it most
// recently, or find the best one to give it to otherwise.
//
void
TFrameWindow::EvSetFocus(THandle hWndLostFocus)
{
  TWindow::EvSetFocus(hWndLostFocus);

  if (HWndRestoreFocus == 0)
    HWndRestoreFocus = GetCommandTarget();

//  if (HWndRestoreFocus == hWndLostFocus)
//    HWndRestoreFocus = GetHandle();

  if (HWndRestoreFocus) {
    // Set focus to the saved THandle as long as it is still a valid window handle
    //
    if (::IsWindow(HWndRestoreFocus))
      ::SetFocus(HWndRestoreFocus);
    else
      HWndRestoreFocus = 0;
  }
}

//
// Close this window if the client is destroyed
//
// Clear the wfFullyCreated flag on any child that is destroyed
// Resize this frame if the client changes size & wfShrinkToClient is set
//
void
TFrameWindow::EvParentNotify(uint event,
                             uint childHandleOrX, uint /*childIDOrY*/)
{
  if (event == WM_DESTROY) {
    if (ClientWnd && ClientWnd->GetHandle() == THandle(childHandleOrX))
      PostMessage(WM_CLOSE);  // using ShutDownWindow() has side effects

    TWindow* c = GetWindowPtr(THandle(childHandleOrX));
    if (c)
      c->ClearFlag(wfFullyCreated);
  }
  else if (event == WM_SIZE) {
    if (IsFlagSet(wfShrinkToClient)
        && ClientWnd
        && ClientWnd->GetHandle() == THandle(childHandleOrX)
        && !IsIconic())
      ResizeClientWindow(true); 
  }
  DefaultProcessing();
}

//
// Watch for WM_ENTERIDLE messages from idling modal dialog boxes so that
// background processing can continue when they are up.
//
void
TFrameWindow::EvEnterIdle(uint source, THandle THandleDlg)
{
  if (source == MSGF_DIALOGBOX && IsFlagSet(wfMainWindow))
    IdleAction(0);  // could call GetApplication()->IdleAction(0)...
  TWindow::EvEnterIdle(source, THandleDlg);
}

//
// Forwards the WM_QUERYNEWPALETTE message to the client window.
//
bool
TFrameWindow::EvQueryNewPalette()
{
  if (GetClientWindow())
    return GetClientWindow()->ForwardMessage();
  else
    return TWindow::EvQueryNewPalette();
}

//
// Forwards the WM_PALETTECHANGED message to the client window.
//
void
TFrameWindow::EvPaletteChanged(THandle hWndPalChg)
{
  if (GetClientWindow())
    GetClientWindow()->ForwardMessage();
  else
    TWindow::EvPaletteChanged(hWndPalChg);
}

//
// Resize & reposition the client window to fit in this frames client area
// or resize the frame to fit around the client's client area if
// wfShrinkToClient
// Return true if a client was actualy resized.
// Adjust clients styles & make sure they get set.
//
bool
TFrameWindow::ResizeClientWindow(bool repaint)
{
  bool hasThickFrame = Attr.Style & WS_THICKFRAME;
  Attr.Style |= WS_THICKFRAME;
  if (!ClientWnd)
    return false;

  // Prevent recursion during resize by ignore calls from EvParentNotify and
  // EvSize when we have already been called.
  // Do this by disabling notifications while resizing using the
  // wfShrinkToClient flag as a semaphore on the client
  //
  if (ClientWnd->IsFlagSet(wfShrinkToClient))
    return true;
  ClientWnd->SetFlag(wfShrinkToClient);

  bool  clientResized = false;
  TSize clientAreaSize = GetClientRect().Size();
  TSize childSize = ClientWnd->GetWindowRect().Size();

  // First time through, strip client window of thick borders.
  // If shrink-to-client, then must measure the client size first
  // If the client has scrolls bars, we must hide them to obtain the correct
  // size.
  // Border style is left on & dealt with by hand below
  //
  const uint32 badClientStyles = WS_DLGFRAME | WS_THICKFRAME | // bad borders
                                 WS_POPUP | WS_OVERLAPPED;     // bad parenting
  const uint32 badClientExStyles = WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE |
                                   WS_EX_STATICEDGE;        // more bad borders

  if ((ClientWnd->Attr.Style & badClientStyles) ||
      (ClientWnd->Attr.ExStyle & badClientExStyles)) {
    if (IsFlagSet(wfShrinkToClient)) {
      TSize tstSize = ClientWnd->GetClientRect().Size();
      ClientWnd->ShowScrollBar(SB_BOTH, false);
      childSize = ClientWnd->GetClientRect().Size();
      if (childSize != tstSize) {
        int restore = SB_BOTH;
        if (childSize.cx == tstSize.cx)
          restore = SB_HORZ;
        if (childSize.cy == tstSize.cy)
          restore = SB_VERT;
        ClientWnd->ShowScrollBar(restore, true);
      }
    }
    if (ClientWnd->Attr.Style & badClientStyles) {
      bool reparent = (ClientWnd->Attr.Style & (WS_POPUP|WS_OVERLAPPED)) != 0;
      ClientWnd->Attr.Style &= ~badClientStyles;
      ClientWnd->Attr.Style |= WS_CHILD | WS_BORDER | WS_VISIBLE;
      ClientWnd->SetWindowLong(GWL_STYLE, ClientWnd->Attr.Style);
      if (reparent)
        ::SetParent(*ClientWnd, *this);
    }
    if (ClientWnd->Attr.ExStyle & badClientExStyles) {
      ClientWnd->Attr.ExStyle &= ~badClientExStyles;
      ClientWnd->SetWindowLong(GWL_EXSTYLE, ClientWnd->Attr.ExStyle);
    }
  }
  if (ClientWnd->Attr.Style & WS_BORDER) {
    childSize = ClientWnd->GetClientRect().Size();
  }
  if (childSize != clientAreaSize) {
    if (IsFlagSet(wfShrinkToClient)) {
      TRect outside = GetWindowRect();
      TSize border = outside.Size() - clientAreaSize;
      SetWindowPos(0, 0, 0,
                   childSize.cx + border.cx, childSize.cy + border.cy,
                   SWP_NOACTIVATE|SWP_NOMOVE| (repaint ? 0 : SWP_NOREDRAW));
      clientAreaSize = childSize; // must move client, will not cause an EvSize
    }
    else {
      clientResized = true;      // client will get resized
    }
  }
  // If frame is sizeable, turn off flag so that user can then resize
  // after initial setup
  //
  if (Attr.Style & WS_THICKFRAME)
    ClearFlag(wfShrinkToClient);

  if (!hasThickFrame) {
    Attr.Style &= ~WS_THICKFRAME;
  }

  // Handle simple border style by shoving the client's borders under the frame
  // This code MUST not resize the client if shrinkToClient
  //
  if (ClientWnd->Attr.Style & WS_BORDER) {
    int bx = TUIMetric::CxBorder;
    int by = TUIMetric::CyBorder;
    ClientWnd->MoveWindow(-bx, -by, clientAreaSize.cx+bx+bx, clientAreaSize.cy+by+by, repaint);
  }
  else
    ClientWnd->MoveWindow(0, 0, clientAreaSize.cx, clientAreaSize.cy, repaint);

  // Turn off semaphore bit
  //
  ClientWnd->ClearFlag(wfShrinkToClient);

  return clientResized;
}

//
// Called following a successful association between an MS-Windows interface
// element and a TFrameWindow
//
void
TFrameWindow::SetupWindow()
{
  // Create windows in child list (this includes the client window)
  //
  TWindow::SetupWindow();

  ResizeClientWindow(true); 

  if (MinimizedPos != TPoint(-1,-1)) {
    WINDOWPLACEMENT windata;
    windata.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(&windata);
    windata.flags = WPF_SETMINPOSITION;
    windata.showCmd = SW_SHOWNA;
    windata.ptMinPosition = MinimizedPos;
    SetWindowPlacement(&windata);
  }

  // If SetMenuDescr() was called before window created, update the menu now
  //
  if (IsFlagSet(wfMainWindow) && MenuDescr) {
    HMENU curMenu = GetMenu();
    TMenu newMenu(*MenuDescr, NoAutoDelete);
    if (SetMenu(newMenu)) {
      if (curMenu)
        ::DestroyMenu(curMenu);
    }
    else
      ::DestroyMenu(newMenu);
  }

  // If we haven't set THandleRestoreFocus then pick the first child with tabstop
  //
  if (!HWndRestoreFocus) {
    HWndRestoreFocus = GetCommandTarget();
  }

  if (CurIcon)
    SendMessage(WM_SETICON, true, (LPARAM)(HICON)CurIcon);

  if (CurIconSm)
    SendMessage(WM_SETICON, false, (LPARAM)(HICON)CurIconSm);
}

//
// Cleans up any associated icons.
//
void
TFrameWindow::CleanupWindow()
{
  // icon cleanup
  //
  SetIcon(0, 0);
  SetIconSm(0, 0);

  TWindow::CleanupWindow();
}


//
// Response method for an incoming WM_SIZE message
//
// If not minimizing resizes the client window to be the same size as the
// client rectangle,
// If no WM_SIZE sent, forwards WM_SIZE message to client so it can recalc.
//
void
TFrameWindow::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);

  if (ClientWnd) {
    bool sizeSent = false;
    if (sizeType != SIZE_MINIMIZED) {
      sizeSent = ResizeClientWindow(true); 
      size = ClientWnd->GetClientRect().Size();
    }
    if (!sizeSent)
      ClientWnd->ForwardMessage();
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

//
// Set the menu descriptor for this frame window
//
void
TFrameWindow::SetMenuDescr(const TMenuDescr& menuDescr)
{
  delete MenuDescr;
  MenuDescr = new TMenuDescr(menuDescr);

  if (IsFlagSet(wfMainWindow) && GetHandle()) {
    HMENU curMenu = GetMenu();
    TMenu newMenu(*MenuDescr, NoAutoDelete);
    if (SetMenu(newMenu))
      ::DestroyMenu(curMenu);
    else
      ::DestroyMenu(newMenu);
  }
}

//
// Merge another menu, given its menu descriptor, into our own using our menu
// descriptor.
// optionally use an existing HMENU to merge into & set
//
bool
TFrameWindow::MergeMenu(const TMenuDescr& childMenuDescr)
{
  if (!MenuDescr || !GetHandle())
    return false;

  MergeModule = childMenuDescr.GetModule();
  TMenu  curMenu(*this, NoAutoDelete);
  TMenu  newMenu(NoAutoDelete);

  MenuDescr->Merge(childMenuDescr, newMenu);

  if (IsFlagSet(wfMainWindow))
    GetApplication()->PreProcessMenu(newMenu);

  if (SetMenu(newMenu)) {
    ::DestroyMenu(curMenu);
    return true;

  }
  else {
    ::DestroyMenu(newMenu);
    return false;
  }

}

//
// Restores this frame window's menu to the one described by our menu
// descriptor
//
bool
TFrameWindow::RestoreMenu()
{
  if (!MenuDescr)
    return false;

  HMENU curMenu = GetMenu();
  TMenu newMenu(*MenuDescr, NoAutoDelete);
  if (SetMenu(newMenu)) {
    MergeModule = 0;
    ::DestroyMenu(curMenu);
  }
  else
    ::DestroyMenu(newMenu);
  return true;
}


#endif
#if !defined(SECTION) || SECTION == 3

IMPLEMENT_STREAMABLE1(TFrameWindow, TWindow);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads data of the uninitialized TFrameWindow from the passed ipstream
//
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

  bool hasMenuDescr = is.readByte();
  if (hasMenuDescr) {
    o->MenuDescr = new TMenuDescr;
    is >> *o->MenuDescr;
  }
  else
    o->MenuDescr = 0;

  is >> o->IconModule;
  is >> o->IconResId;
  is >> o->MergeModule;
  is >> o->MinimizedPos;

  return o;
}

//
// Writes data of the TFrameWindow to the passed opstream
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

  os.writeByte(uint8(o->MenuDescr ? 1 : 0));
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

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif  // SECTION
