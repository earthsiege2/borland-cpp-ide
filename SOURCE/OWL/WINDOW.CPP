//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.41  $
//
// Implementation of TWindow.  This defines the basic behavior of all Windows.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_SCROLLER_H)
# include <owl/scroller.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#include <stdlib.h>
#include <stdio.h>

DIAG_DECLARE_GROUP(OwlMsg);  // diagnostic group for message tracing
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlWin, 1, 0);  // diag. group for windows
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlCmd, 1, 0);  // diag. group for commands

//
// Define to use rtti to create unique window ids for the message cache
//
#if defined(__BORLANDC__) && !defined(BI_NO_RTTI)
# define OWL_RTTI_MSGCACHE
# define TYPE_UNIQUE_UINT32(t)    reinterpret_cast<uint32>(typeid(t).tpp)
#endif

//
// Externs defined in owl.cpp
//
extern WNDPROC           CreateInstanceThunk(TWindow*, TThunkProc);
extern void              FreeInstanceThunk(WNDPROC);
extern void     _OWLFUNC SetCreationWindow(TWindow*);
extern TWindow* _OWLFUNC GetCreationWindow();
extern uint     _OWLDATA GetWindowPtrMsgId;


DEFINE_RESPONSE_TABLE(TWindow)
  EV_WM_SETCURSOR,
  EV_WM_SIZE,
  EV_WM_MOVE,
  EV_WM_COMPAREITEM,
  EV_WM_DELETEITEM,
  EV_WM_DRAWITEM,
  EV_WM_MEASUREITEM,
  EV_WM_VSCROLL,
  EV_WM_HSCROLL,
  EV_WM_CHILDINVALID,
  EV_WM_ERASEBKGND,
  EV_WM_CTLCOLOR,
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_WM_KILLFOCUS,
#if defined(BI_PLAT_WIN32)
  EV_MESSAGE(WM_CTLCOLORMSGBOX, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLOREDIT, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLORLISTBOX, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLORBTN, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLORDLG, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLORSCROLLBAR, EvWin32CtlColor),
  EV_MESSAGE(WM_CTLCOLORSTATIC, EvWin32CtlColor),
#endif
  EV_WM_CREATE,
  EV_WM_CLOSE,
  EV_WM_DESTROY,
  EV_WM_NCDESTROY,
  EV_WM_QUERYENDSESSION,
  EV_WM_ENDSESSION,
  EV_WM_SYSCOLORCHANGE,
  EV_WM_INITMENUPOPUP,
  EV_WM_CONTEXTMENU,
END_RESPONSE_TABLE;


#if defined(BI_NO_RTTI)
  IMPLEMENT_CASTABLE1(TCommandEnabler, TStreamableBase);
#endif

//
//
//
TCommandEnabler::TCommandEnabler(uint id, TWindow::THandle hReceiver)
:
  Id(id),
  HWndReceiver(hReceiver)
{
  Flags = 0;
}

//
//
//
void
TCommandEnabler::Enable(bool)
{
  Flags |= WasHandled;
}

//
// Constructor for a TWindow.  if a parent window is passed, adds the TWindow
// to its parent's list of children
//
TWindow::TWindow(TWindow* parent, const char far* title, TModule* module)
{
  Thunk = 0;  // Zero out to remember that we still need to initialize
  Init(parent, title, module);
}

//
// Constructor for a TWindow which is being used as an alias for a
// non-OWL window.  This ctor is generally not used by derived classes
//
TWindow::TWindow(THandle handle, TModule* module)
{
  PRECONDITION(handle);

  Thunk = 0;  // Zero out to remember that we still need to initialize
  Init(handle, module);
}

//
// Protected constructor for use by immediate virtually derived classes.
// Immediate derivitives must call an Init() before constructions are done.
//
TWindow::TWindow()
{
  Thunk = 0;  // Zero out to remember that we still need to initialize
}

//
// Normal initialization of a default constructed TWindow. Is ignored if
// called more than once.
//
void
TWindow::Init(TWindow* parent, const char far* title, TModule* module)
{
  if (!Thunk) {
    Title = strnewdup(title);
    Init(parent, module);
    DefaultProc = 0;
    Handle = 0;
    EnableAutoCreate();

    // Initialize creation attributes
    //
    Attr.Style = WS_CHILD | WS_VISIBLE;
    Attr.X = Attr.Y = Attr.W = Attr.H = 0;
    Attr.ExStyle = 0;
    Attr.Id = 0;
  }
}

//
// Wrapper initialization of a default constructed TWindow. Is ignored if
// called more than once.
//
void
TWindow::Init(THandle handle, TModule* module)
{
  PRECONDITION(handle);

  if (!Thunk) {
    // Perform preliminary initialization
    //
    SetHandle(handle);
    Title = 0;

    // If we've been given a module, then setup that and the app now if
    // possible so that GetWindowPtr below has some context. Otherwise at least
    // set it to 0.
    //
    Application = TYPESAFE_DOWNCAST(module,TApplication);

    // If the receiver's parent is an OWL window then pass the window to the
    // private Init() so the receiver can be added to the parent's list of
    // children
    //
    THandle   hParent = GetParentH();
    TWindow*  parent = hParent ? GetWindowPtr(hParent) : 0;
    Init(parent, module);

    // Thunk the window
    //
    SubclassWindowFunction();

    // Copy over the title, styles, the coordinates & the id
    //
    GetWindowTextTitle();
    GetHWndState();

    // Keep track that this is an alias object & that it is already created
    //
    SetFlag(wfAlias | wfFullyCreated);

    // Unique id may have been set inadvertantly to TWindow by the above
    // GetWindowTextTitle, et. al. Reset it just in case
    //
    SetUniqueId();
  }
}

//
// Private initializer function that does the bulk of the work for the
// protected Init()s
//
void
TWindow::Init(TWindow* parent, TModule* module)
{
  ZOrder = 0;
  ChildList = 0;
  Flags = wfDeleteOnClose;
  TransferBuffer = 0;
  Parent = parent;
  Attr.Param = 0;
  Attr.Menu = 0;
  Attr.AccelTable = 0;
  HAccel = 0;
  Thunk = ::CreateInstanceThunk(this, StdWndProc);
  Scroller = 0;
  ContextPopupMenu = 0;

  CursorModule = 0;
  CursorResId = 0;
  HCursor = 0;
  BkgndColor = TColor::None;

  if (Parent)
    Parent->AddChild(this);
  else
    SiblingList = 0;

  // Use passed module if one, else get parent's. If no parent, use app
  //
  if (Parent) {
    Application = Parent->GetApplication();
    Module = module ? module : Parent->GetModule();
  }
  else {
    Module = module ? module : 0;
    Application = TYPESAFE_DOWNCAST(Module,TApplication);
    if (!Application) {
      Application = ::GetApplicationObject();
      if (!Module)
        Module = Application;
    }
    CHECK(Application);
  }
  SetUniqueId();

  TRACEX(OwlWin, 1, "TWindow constructed @" << (void*)this << *this);
}

//
// Installs the thunk as the window function and saves the old window function
// in the DefaultProc member
//
void
TWindow::SubclassWindowFunction()
{
  PRECONDITION(GetHandle());

#if defined(BI_PLAT_WIN32)
  uint32 processId;
  ::GetWindowThreadProcessId(GetHandle(), &processId);
  if (processId == ::GetCurrentProcessId())
#else
  if (::GetWindowTask(GetHandle()) == ::GetCurrentTask())
#endif
  {
    DefaultProc = (WNDPROC)SetWindowLong(GWL_WNDPROC, uint32(GetThunk()));
    CHECK(DefaultProc != GetThunk());  // can only be called once!
  }
}

//
// Destructor for a TWindow: disposes of each window in its ChildList
// and removes itself from a non-0 parent's list of children
//
// Destroys a still-associated Handle and frees the instance thunk used for
// linking the TWindow to the Handle
//
// Disposes of its Scroller if the TScroller object was constructed
//
static void shutDown(TWindow* win, void*) {
  win->Destroy();
  delete win;
}

//
//
//
TWindow::~TWindow()
{
  // Flush the cache so that messages dont get dispatched to a
  // already-destructed derived class
  //
  void CacheFlush(uint32 id);
  CacheFlush(UniqueId);

  // ShutDown children first, so the Owl objects get a chance to clean up
  //
  ForEach(shutDown);

  // If the Handle is still around, then destroy it or unlink from it as
  // appropriate.
  //
  if (GetHandle()) {
    // For aliases:
    //  - we are destructing the C++ object but not destroying the MS window
    //  - restore the original window function
    //
    if (IsFlagSet(wfAlias)) {
      // May want to check WNDPROC against Thunk to see if its still us
      // and not restore if it's not us...
      //
      WARNX(OwlWin, GetWindowLong(GWL_WNDPROC) != (uint32)GetThunk(), 0,
            "Restoring old WndProc after foreign subclass of:" << *this);
      SetWindowLong(GWL_WNDPROC, uint32(DefaultProc));
    }
    // For non-aliases:
    //  - destroy the windows element
    // this is not a normal condition and is a safety net only
    //
    else {
      WARNX(OwlWin, GetHandle(), 0, "Destroying from TWindow::~TWindow: " << *this);
      Destroy();
    }
  }

  // Remove from parent's ChildList
  //
  if (Parent)
    Parent->RemoveChild(this);

#if 0
  // Clear TApplication's member to avoid dangling pointer
  //
  //
  if (IsFlagSet(wfMainWindow))
    GetApplication()->MainWindow = 0;
#endif

  // Remove pointer from application's CondemnList
  //
  if (Application)
    Application->Uncondemn(this);

  // Delete menu id string, scroller, title, cursor & thunk
  //
  if (Attr.Menu.IsString())
    delete[] (char far*)Attr.Menu;  // Assumes strnewdup was used

  // Get rid of our scroller, if any.
  //
  SetScroller(0);

  // Clean up title member
  //
  if (HiUint16(uint32(Title)))
    delete[] Title;
  Title = 0;

  // Cleanup cursor
  //
  if (HCursor && CursorModule)
    SetCursor(0, 0);

  // Clean up context menu object
  //
  delete ContextPopupMenu;

  // Clean up thunk
  //
  ::FreeInstanceThunk(Thunk);
  TRACEX(OwlWin, 1, "TWindow destructed @" << (void*)this << *this);
}

#if defined(BI_MULTI_THREAD_RTL)
//
// Overrides TEventHandler::Dispatch() to handle multi-thread synchronization
//
TResult TWindow::Dispatch(TEventInfo& info, TParam1 p1, TParam2 p2)
{
  TApplication::TQueueLock lock(*GetApplication());
  return TEventHandler::Dispatch(info, p1, p2);
}

#endif

//
// Called from TApplication::ProcessAppMsg() to give the window an
// opportunity to perform preprocessing of the Windows message
//
// If you return true, further processing of the message is halted
//
// If you override this method in a derived class, make sure to call this
// routine because it handles translation of accelerators...
//
bool
TWindow::PreProcessMsg(MSG& msg)
{
  PRECONDITION(GetHandle());

  return HAccel ? ::TranslateAccelerator(GetHandle(), HAccel, &msg) : false;
}

//
// Propagate idle action to all children if count==0, and to any children that
// previously said they wanted more time.
//
bool
TWindow::IdleAction(long idleCount)
{
  bool wantMore = false;
  TWindow* win = GetFirstChild();
  if (win) {
    do {
      if (idleCount == 0 || win->IsFlagSet(wfPropagateIdle)) {
        if (win->IdleAction(idleCount)) {
          win->SetFlag(wfPropagateIdle);
          wantMore = true;
        }
        else {
          win->ClearFlag(wfPropagateIdle);
        }
      }
      win = win->Next();
    } while (win && win != GetFirstChild());
  }
  return wantMore;
}

//
// Respond to WM_SYSCOLORCHANGE by broadcasting it to all children
//
void
TWindow::EvSysColorChange()
{
  ChildBroadcastMessage(WM_SYSCOLORCHANGE);
  DefaultProcessing();
}

//
// Removes the passed pointer to a child window from the linked list of
// sibling windows which the TWindow's ChildList points to
//
void
TWindow::RemoveChild(TWindow* child)
{
  if (child && ChildList) {
    TWindow*  lastChild = ChildList;
    TWindow*  nextChild = lastChild;

    while (nextChild->SiblingList != lastChild &&
           nextChild->SiblingList != child) {
      nextChild = nextChild->SiblingList;
    }

    if (nextChild->SiblingList == child) {
      if (nextChild->SiblingList == nextChild)
        ChildList = 0;

      else {
        if (nextChild->SiblingList == ChildList)
          ChildList = nextChild;

        nextChild->SiblingList = nextChild->SiblingList->SiblingList;
      }
    }
  }
}

//
// Reparents this window to a new owl parent window. Also sets the windows
// parent (owner really)
//
void
TWindow::SetParent(TWindow* newParent)
{
  if (Parent != newParent) {
    if (Parent)
      Parent->RemoveChild(this);

    SiblingList = 0;

    Parent = newParent;

    if (Parent)
      Parent->AddChild(this);
  }
  // Tell Windows about the change too, if appropriate
  //
  if (GetHandle() && Parent && GetParentH() != Parent->GetHandle()) {
    if (newParent) {
      if (newParent->GetHandle())
        ::SetParent(GetHandle(), newParent->GetHandle());
    }
    else
      ::SetParent(GetHandle(), 0);
  }
}

//
// Default behavior for updating document title is to pass it to parent frame
//
bool
TWindow::SetDocTitle(const char far* docname, int index)
{
  return Parent ? Parent->SetDocTitle(docname, index) : false;
}

//
// Set the scroller object for this window. This window assumes ownership of
// the scroller object, & will delete it when done & on subsequent sets.
//
void
TWindow::SetScroller(TScroller* scroller)
{
  if (Scroller) {
    // Delete scroller if there is one, by casting up to base and relying on
    // virtual dtor to avoid forcing in TScroller object code.
    //
    delete (TStreamableBase*)Scroller;
  }
  Scroller = scroller;
}

//
// Wildcard check used for child id notifications
//
static bool wildcardCheck(TGenericTableEntry __RTFAR& entry,
                          TEventHandler::TEventInfo& info) {
  return entry.Id == info.Id && (entry.Msg == UINT_MAX || entry.Msg == info.Msg);
}

//
// Handles default processing of events, which includes continued processing
// of menu/accelerators commands and enablers, as well as notifications
//
TResult
TWindow::DefaultProcessing()
{
  TCurrentEvent& currentEvent = GetCurrentEvent();

  if (currentEvent.Message == WM_COMMAND_ENABLE) {
    if (currentEvent.Win != this) {
      TWindow*         receiver = Parent ? Parent : currentEvent.Win;
      TCommandEnabler& commandEnabler = *(TCommandEnabler*)currentEvent.Param2;
      TEventInfo       eventInfo(WM_COMMAND_ENABLE, commandEnabler.Id);

      if (receiver->Find(eventInfo))
        return receiver->Dispatch(eventInfo, 0, currentEvent.Param2);
    }

    return 0;
  }

  // Handle normal message default processing by routing directly to the
  // virtual DefWindowProc() for the window.
  //
  if (currentEvent.Message != WM_COMMAND && currentEvent.Message != WM_NOTIFY)
    return DefWindowProc(currentEvent.Message,
                         currentEvent.Param1,
                         currentEvent.Param2);

  // currentEvent.Message == WM_COMMAND or WM_NOTIFY
  //
  uint    notifyCode;
  uint    id;
  THandle hWndCtl;

  // Get notify code, control id and control handle from packed params.
  // Unpacking based on message & platform.
  //
  if (currentEvent.Message == WM_COMMAND) {
#if defined(BI_PLAT_WIN16)
    notifyCode = HiUint16(currentEvent.Param2);
#else
    notifyCode = HiUint16(currentEvent.Param1);
#endif
    id = LoUint16(currentEvent.Param1);
    hWndCtl = THandle((uint)currentEvent.Param2);
  }
  else {
    notifyCode = ((TNotify*)currentEvent.Param2)->code;
    id = currentEvent.Param1;
    hWndCtl = ((TNotify*)currentEvent.Param2)->hwndFrom;
  }

  // If all special routing is done, then process the command/notify for this
  // window
  //
  if (currentEvent.Win == this) {
    // Menu command originally destined for the receiver, defer to the app.
    //
    if (hWndCtl == 0) {
      TEventInfo     eventInfo(0, id);
      TApplication*  app = GetApplication();

      if (app->Find(eventInfo)) {
        app->Dispatch(eventInfo, eventInfo.Id);
        return 0;
      }
      WARNX(OwlMsg, notifyCode<=1, 0, "Unprocessed WM_COMMAND(id=" << id << ")");
    }
    // Originally destined for the receiver and the receiver has called us so
    // default processing can occur.
    // Unpack the original parameters and call DefWindowProc()
    //
    return DefWindowProc(currentEvent.Message, currentEvent.Param1, currentEvent.Param2);
  }

  // Perform special routing for commands and notifications
  //
  else {
    TWindow*        receiver;
    TEqualOperator  equal = 0;

    if (hWndCtl == 0) {
      // Menu/accelerator/push button
      // Either give the message to the receiver's parent or the original
      // receiver of the message
      //
      receiver = Parent ? Parent : currentEvent.Win;

      // "notifyCode" is either 0 or 1 depending on whether this is from an
      // accelerator; however, we want to explicitly look for a 0...
      //
      notifyCode = 0;
    }
    else {
      // Child id notification (either WM_COMMAND or WM_NOTIFY) sent to the
      // child and the child has called us.
      // Offer the parent an opportunity to handle the notification
      //   NOTE: use equal function that will do a wildcard search
      //
      equal = wildcardCheck;
      receiver = currentEvent.Win;

      // The child window identifier shouldn't be 0, but if it is then it will
      // look like we are searching for a WM_ message with value "notifyCode",
      // in that case just give up and call DefWindowProc() for the window.
      //
      if (receiver->IsFlagSet(wfAlias) || id == 0)
        return receiver->DefWindowProc(currentEvent.Message,
                                       currentEvent.Param1,
                                       currentEvent.Param2);
    }

    // Now dispatch the command or notification to the receiver window
    //
    TEventInfo  eventInfo(notifyCode, id);

    // NOTE: The ResponseTableEntry of handlers which expect an id (e.g.
    //       EV_COMMAND_AND_ID) have a zero in their first field. The
    //       ResponseTableEntry of handlers which expect a notification code
    //       (e.g. EV_CHILD_NOTIFY_AND_CODE and EV_NOTIFY_ALL_CODES) contain
    //       either the notifyCode or UINT_MAX in that field. Hence, we can
    //       dispatch the expected information based on the contents of that
    //       field.
    //
    //       However, this logic will fail to disambiguate cases where a
    //       notification code is 0. The only standard control with such a
    //       notification is BUTTON /w BN_CLICKED. So for button handlers
    //       expecting the id, you can use EV_COMMAND_AND_ID. For handlers
    //       expecting the notification code, you can use EV_NOTIFY_ALL_CODES,
    //       (*NOT* EV_CHILD_NOTIFY_AND_CODE(Id, BN_CLICKED, xxxx,...))
    //
    if (receiver->Find(eventInfo, equal)) {
      TParam1 param1 = eventInfo.Entry->NotifyCode ? notifyCode : id;
      return receiver->Dispatch(eventInfo, param1, currentEvent.Param2);
    }
    else
      return receiver->DefaultProcessing();
  }
}

//
// Called by WindowProc() to handle WM_COMMANDs
//
// id         - specifies the identifier of the menu item or control
//
// hWndCtl    - specifies the control sending the message if the message
//              is from a control; otherwise it is 0
//
// notifyCode - specifies the notification message if the message is from
//              a control. if the message is from an accelerator, it is 1.
//              if the message is from a menu, it is 0
//
TResult
TWindow::EvCommand(uint id, THandle hWndCtl, uint notifyCode)
{
  TRACEX(OwlCmd, 1, "TWindow::EvCommand - id(" << id << "), ctl(" <<\
                     hex << uint(hWndCtl) << "), code(" << notifyCode  << ")");

  TWindow*        receiver = this;
  TEqualOperator  equal = 0;

  // Menu/accelerator
  //
  if (hWndCtl == 0) {
    // "notifyCode" is either 0 or 1 depending on whether this is from an
    // accelerator; however, we want to explicitly look for a 0 in the tables
    //
    notifyCode = 0;
  }

  // Child id notification
  //
  else {
    TWindow*  child = GetWindowPtr(hWndCtl);

    if (child) {
      // Give the child first crack at the event
      //
      receiver = child;
      id = UINT_MAX;  // special designator for child Id notifications that are
                      // handled at the child
    }
    else {
      // Offer the parent an opportunity to handle the notification
      //
      // NOTE: use equal function that will do a wildcard search
      //
      equal = wildcardCheck;

      // The child window identifier shouldn't be 0, but if it is then it will
      // look like we are searching for a WM_ message with value "notifyCode"
      //
      if (id == 0)
        return DefaultProcessing();
    }
  }

  TEventInfo  eventInfo(notifyCode, id);

  // NOTE: The ResponseTableEntry of handlers which expect an id
  //       (e.g. EV_COMMAND_AND_ID) have a zero in their first field.
  //       The ResponseTableEntry of handlers which expect a notification
  //       code (e.g. EV_CHILD_NOTIFY_AND_CODE and EV_NOTIFY_ALL_CODES)
  //       contain either the notifyCode or UINT_MAX in that field.
  //       Hence, we can dispatch the expected information based on the
  //       contents of that field.
  //
  //       However, this logic will fail to disambiguate cases where
  //       a notification code is 0. The only standard control with
  //       such a notification is BUTTON /w BN_CLICKED. So for button
  //       handlers expecting the id, you can use EV_COMMAND_AND_ID.
  //       For handlers expecting the notification code, you can use
  //       EV_NOTIFY_ALL_CODES.
  //
  //       Do *NOT* use "EV_CHILD_NOTIFY_AND_CODE(Id, BN_CLICKED, xxxx,...)"
  //
  if (receiver->Find(eventInfo, equal))
    return receiver->Dispatch(eventInfo,
                              eventInfo.Entry->NotifyCode ? notifyCode : id);
  else
    return receiver->DefaultProcessing();
}

//
// Handle WM_NOTIFY & subdispatch messages from child controls
//
TResult
TWindow::EvNotify(uint ctlId, TNotify far& notifyInfo)
{
  TWindow*        receiver = this;
  TEqualOperator  equal = 0;
  TWindow*        child = GetWindowPtr(notifyInfo.hwndFrom);

  if (child) {
    // Give the Owl child first crack at the event
    //
    receiver = child;
    ctlId = UINT_MAX;// special designator for child Id notifications that are
                     // handled at the child 
  }
  else {
    // Offer the parent an opportunity to handle the notification
    //   NOTE: use equal function that will do a wildcard search
    //
    equal = wildcardCheck;

    // The child window identifier shouldn't be 0, but if it is then it will
    // look like we are searching for a WM_ message with value "notifyCode"
    //
    if (ctlId == 0)
      return DefaultProcessing();
  }

  TEventInfo  eventInfo(notifyInfo.code, ctlId);

  // Pass the "notifyCode" along in case the user wants it...
  //
  if (receiver->Find(eventInfo, equal))
    return receiver->Dispatch(eventInfo, notifyInfo.code, TParam2(&notifyInfo));
  else
    return receiver->DefaultProcessing();
}

//
// Handle an ObjectWindow's defined WM_COMMANDENABLE message by
// sub-dispatching it based on the command id
//
void
TWindow::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  DispatchMsg(WM_COMMAND_ENABLE, commandEnabler.Id, 0, TParam2(&commandEnabler));
}

//
// Don't process for windows out of our window tree (esp. other apps)
//
void
TWindow::RouteCommandEnable(THandle hInitCmdTarget, TCommandEnabler& commandEnabler)
{
  // Extra processing for commands & commandEnablers: send the command down the
  // command chain if we are the original receiver
  //
  if (commandEnabler.IsReceiver(*this)) {
    THandle  hCmdTarget = hInitCmdTarget;
    while (hCmdTarget && hCmdTarget != *this) {
      TWindow*  cmdTarget = GetWindowPtr(hCmdTarget);

      if (cmdTarget) {
        cmdTarget->EvCommandEnable(commandEnabler);

        if (commandEnabler.GetHandled())
          return;
      }
      hCmdTarget = ::GetParent(hCmdTarget);
    }
  }

  // Always call base handler
  //
  TWindow::EvCommandEnable(commandEnabler);

  // No one explicitly enabled/disabled the command via the enabler, so run up
  // the command chain checking for any one who is going to handle the command
  // itself; if not then disable it...
  // Don't do this for command senders that don't actually generate commands,
  // like popup menu items.
  //
  if (commandEnabler.IsReceiver(*this) && !commandEnabler.GetHandled()
      && commandEnabler.SendsCommand()) {
    bool        enable = false;
    TEventInfo  eventInfo(0, commandEnabler.Id);

    THandle  hCmdTarget = hInitCmdTarget;
    while (true) {
      TWindow*  cmdTarget = GetWindowPtr(hCmdTarget);

      if (cmdTarget && cmdTarget->Find(eventInfo)) {
        enable = true;  // command will be handled, leave sender alone
        break;
      }
      if (!hCmdTarget || hCmdTarget == *this)
        break;

      hCmdTarget = ::GetParent(hCmdTarget);
    }

    if (!enable) {
      // Check if the app wants to handle it
      //
      TEventInfo    enableInfo(WM_COMMAND_ENABLE, commandEnabler.Id);
      TApplication* app = GetApplication();
      if (app->Find(enableInfo)) {
        app->Dispatch(enableInfo, 0, TParam2(&commandEnabler));
        if (commandEnabler.GetHandled())
          return;
      }
      enable = app->Find(eventInfo);
    }

    commandEnabler.Enable(enable);
  }
}

//
// Virtual function provides final default processing for an incoming message
// Calls original window proc that was subclassed, using ::CallWindowProc to
// make sure that registers get setup correctly.
//
TResult
TWindow::DefWindowProc(uint message, TParam1 param1, TParam2 param2)
{
  PRECONDITION(DefaultProc);

  TResult result = ::CallWindowProc(DefaultProc, GetHandle(), message, param1, param2);
  GetApplication()->ResumeThrow();
  return result;
}

//
// Message cache
//
static const int     msgCacheSize = 31;
struct TCacheEntry {
  uint32                       UniqueId;
  TGenericTableEntry  __RTFAR* Entry;
  uint                         Msg;
  int                          Delta;  // adjustment to "this" pointer

  void Set(uint32 uniqueId, uint msg, TGenericTableEntry __RTFAR* entry, int delta = 0) {
    UniqueId = uniqueId;
    Entry = entry;
    Msg = msg;
    Delta = delta;
  }
  bool  Hit(uint msg, uint32 uniqueId) {return msg == Msg && uniqueId == UniqueId;}

  static uint  Key(uint32 id, uint msg) {return (uint(id) ^ msg) % msgCacheSize;}
};

uint32 TWindow::LastUniqueId = 0;

static TCacheEntry  msgCache[msgCacheSize];
static bool         cacheEnabled = true;

void CacheFlush(uint32 id) {
  for (int i = 0; i < msgCacheSize; i++)
    if (msgCache[i].UniqueId == id)
      msgCache[i].Msg = 0;
}

//
// If rtti is available, then use it get an id for this window that is unique
// on a per-class basis.
//
// Without rtti, use a per-instance unique id. Less efficient, but safe.
//
void
TWindow::SetUniqueId()
{
#if defined(OWL_RTTI_MSGCACHE)
  UniqueId = 0;
#else
  if (++LastUniqueId == 0) {
    //
    // numbers wrapped around. disable the cache to be safe...
    //
    LastUniqueId = 1;
    cacheEnabled = false;
  }
  UniqueId = LastUniqueId;
#endif
}

//
// First virtual function called to handling incoming messages to a TWindow
//
// Hand calls handler for WM_COMMAND, WM_COMMAND_ENABLE and WM_NOTIFY.
// otherwise looks for a handler in the message response table
//
TResult
TWindow::WindowProc(uint msg, TParam1 param1, TParam2 param2)
{
  PRECONDITION(GetHandle());  // Should never get here without a handle

  // Handle WM_COMMAND_ENABLE command enable msgs by directly calling the
  // virtual EvCommandEnable
  //
  if (msg == WM_COMMAND_ENABLE) {
    EvCommandEnable(*(TCommandEnabler*)param2);
    return 0;
  }
  // Handle WM_COMMAND command msgs by directly calling the
  // virtual EvCommand
  //
  else if (msg == WM_COMMAND) {
#if defined(BI_PLAT_WIN16)
    return EvCommand(LoUint16(param1), THandle(uint(param2)), HiUint16(param2));
#else
    return EvCommand(LoUint16(param1), THandle(uint(param2)), HiUint16(param1));
#endif
  }
  // Handle WM_NOTIFY msgs by directly calling the virtual EvNotify
  //
  else if (msg == WM_NOTIFY) {
    return EvNotify(param1, *(TNotify far*)param2);
  }

  // Handle all other messages by looking up and dispatching using the
  // response tables
  //
  else {
#if defined(OWL_RTTI_MSGCACHE)
    if (!UniqueId)
      UniqueId = TYPE_UNIQUE_UINT32(*this);
#endif
    uint        key = TCacheEntry::Key(UniqueId, msg);
    TEventInfo  eventInfo(msg);

    // Check the cache. A cache hit may be an RT handler, or an RT miss.
    //
    if (cacheEnabled && msgCache[key].Hit(msg, UniqueId)) {
      eventInfo.Entry = msgCache[key].Entry;
      if (eventInfo.Entry) {
        TRACEX(OwlMsg, 1, MsgName(msg) << "* => " << *this);
        eventInfo.Object = (GENERIC*)(((char*)this) + msgCache[key].Delta);
        return Dispatch(eventInfo, param1, param2);

      } // else fall out & do default below
    }
    // Perform the lookup on this window.
    //
    else if (Find(eventInfo)) {
      TRACEX(OwlMsg, 1, MsgName(msg) << " => " << *this);
      msgCache[key].Set(UniqueId, msg, eventInfo.Entry, int(eventInfo.Object) - int(this));
      return Dispatch(eventInfo, param1, param2);
    }
    else  // not found
      msgCache[key].Set(UniqueId, msg, 0);  // Cache no-handler entries too

    // Behavior for messages that have no handler. If this is the main window,
    // then give the app a chance to handle the message. If not the main
    // window, or if the app had no handler, just call DefWindowProc() to
    // pass the message back to whomever we subclassed
    //
    if (IsFlagSet(wfMainWindow)) {
      TEventInfo cmdEventInfo(msg, param1);
      if (GetApplication()->Find(cmdEventInfo))
        return GetApplication()->Dispatch(cmdEventInfo, param1, param2);
      if (GetApplication()->Find(eventInfo))
        return GetApplication()->Dispatch(eventInfo, param1, param2);
    }
    return DefWindowProc(msg, param1, param2);
  }
}

//
// Save current event and call this window's WindowProc. Handles exceptions,
// error checking, & GetWindowPtr messages.
//
TResult
TWindow::HandleMessage(uint msg, TParam1 param1, TParam2 param2)
{
  // Save event away in "CurrentEvent"
  //
  TCurrentEvent& currentEvent = GetCurrentEvent();
  TCurrentEvent  saveEvent = currentEvent;  // for nested calls
  currentEvent.Win = this;
  currentEvent.Message = msg;
  currentEvent.Param1 = param1;
  currentEvent.Param2 = param2;

  // Call window object's WindowProc virtual function
  //
  TResult  result;
  result = WindowProc(msg, param1, param2);
  currentEvent = saveEvent;  // restore previous event to current event
  return result;
}

//
// Window function called for normal, initialized, OWL windows via a
// per-window thunk. 'this' ptr is setup in register(s) by the thunk before
// StdWndProc is called.
//
#if defined(BI_PLAT_WIN16)
TResult CALLBACK OWL_EXPORT16
TWindow::StdWndProc(THandle, uint msg, TParam1 param1, TParam2 param2)
{
  return ((TWindow*)MK_FP(_ES,_BX))->ReceiveMessage(msg, param1, param2);
}
#else
/*OWL_EXPORT*/ TResult CALLBACK
TWindow::StdWndProc(THandle, uint msg, TParam1 param1, TParam2 param2)
{
#if defined(BI_COMP_BORLANDC)
  return ((TWindow*)_EAX)->ReceiveMessage(msg, param1, param2);
#else
  TWindow* w;
  _asm mov w, eax
  return w->ReceiveMessage(msg, param1, param2);
#endif
}
#endif

//
// First member function that receives messages from windows thru the
// thunk & then StdWndProc. Deals with exception suspension for non-NT
// environments.
//
TResult
TWindow::ReceiveMessage(uint msg, TParam1 param1, TParam2 param2)
{
  // If it's a "GetWindowPtr" message, then return pointer to this window
  //
  if (msg == ::GetWindowPtrMsgId && (!param2 || param2 == TParam2(Application)))
    return TResult(this);

#if defined(BI_PLAT_WIN32)
  if (TSystem::SupportsExceptions())
    return HandleMessage(msg, param1, param2);
#endif
#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
  TRY {
    return HandleMessage(msg, param1, param2);
  }
  CATCH( (TXOwl& x) {
    GetApplication()->SuspendThrow(x);
  })
  CATCH( (xalloc& x) {
    GetApplication()->SuspendThrow(x);
  })
  CATCH( (xmsg& x) {
    GetApplication()->SuspendThrow(x);
  })
#if !defined(BI_NO_NEW_CASTS)
  CATCH( (Bad_cast& x) {
    GetApplication()->SuspendThrow(TApplication::xsBadCast);
  })
  CATCH( (Bad_typeid& x) {
    GetApplication()->SuspendThrow(TApplication::xsBadTypeid);
  })
#endif
  CATCH( (...) {
    GetApplication()->SuspendThrow(TApplication::xsUnknown);
  })
  ENDCATCH
#endif

  // When exceptions are disabled CATCH is defined as empty, so the only code
  // is the TRY block, making this return unreachable
  //
# pragma warn -rch
  return msg == WM_CREATE ? -1 : 0;  // default value returned when exception caught
# pragma warn .rch
}

//
// Determine the object pointer by sending a GetWindowPtrMsgId message to the
// window.  When the first StdWndProc() in the subclass chain receives this
// message it returns a pointer to the object (via the thunking mechanism).
// If app is non-zero, then the process makes sure that the corresponding
// TWindow is returned.
//
TWindow* _OWLFUNC GetWindowPtr(TWindow::THandle hWnd, const TApplication* app)
{
  if (!hWnd /* && ::IsWindow(hWnd) */)  // Could also check handle validity
    return 0;

#if defined(BI_DATA_NEAR)
  TParam2 param2 = app ? TParam2(app) : 0;
#else
  TParam2 param2 = TParam2(app);
#endif

  // Avoid SendMessage to cutdown the overhead & message spy tool flooding
  //
  // Under Win16, need to fallback to SendMessage when the given hWnd is owned
  // by another task. Using CallWindowProc on it would result in a bad SS
  // setup when it received the message.
  //
  // Under Win32 don't even try if it is not our process. Some Win32's will
  // return a wndProc that crashes.
  //
#if defined(BI_PLAT_WIN16)
  if (::GetWindowTask(hWnd) != ::GetCurrentTask())
    return (TWindow*)::SendMessage(hWnd, GetWindowPtrMsgId, 0, param2);
#else
  uint32 processId;
  ::GetWindowThreadProcessId(hWnd, &processId);
  if (processId != ::GetCurrentProcessId())
    return 0;
#endif

  WNDPROC wndProc = (WNDPROC)::GetWindowLong(hWnd, GWL_WNDPROC);
  if (!wndProc)
    return 0;
  return (TWindow*)::CallWindowProc(wndProc, hWnd, GetWindowPtrMsgId, 0, param2);
}

//
// Response method for an incoming WM_CREATE message
//
// Call virtual SetupWindow to give derived classes a chance to set things up
// now that we are created & have a Handle
//
int
TWindow::EvCreate(CREATESTRUCT far&)
{
  SetupWindow();
  SetFlag(wfFullyCreated);
  return (int)DefaultProcessing();
}

//
// Regular windows never hold focus child handles--just say no.
//
bool
TWindow::HoldFocusHWnd(THandle /*hWndLose*/, THandle /*hWndGain*/)
{
  return false;
}

//
// Handle WM_KILLFOCUS so that we can have a parent window hold onto our
// Handle and possibly restore focus later.
//
void
TWindow::EvKillFocus(THandle getFocus)
{
  // Follow the parent chain back until a window volunteers to hold our handle
  //
  if (IsFlagSet(wfFullyCreated)) {
    TWindow* holdWin = Parent;
    while (holdWin && !holdWin->HoldFocusHWnd(GetHandle(), getFocus))
      holdWin = holdWin->Parent;
  }

  DefaultProcessing();
}

//
// Response method for an incoming WM_SIZE message
//
// Saves the normal size of the window in Attr.
// Also calls the SetPageSize() and SetBarRange() methods of the TWindow's
// scroller, if it has been constructed.
//
void
TWindow::EvSize(uint sizeType, TSize&)
{
  static bool inScroller = false;
  if (!inScroller && Scroller && sizeType != SIZE_MINIMIZED) {
    inScroller = true;
    Scroller->SetPageSize();
    Scroller->SetSBarRange();
    inScroller = false;
  }

  if (sizeType == SIZE_RESTORED) {
    TRect  wndRect;
    GetWindowRect(wndRect);

    Attr.W = wndRect.Width();
    Attr.H = wndRect.Height();
  }

  // Added Owl functionality: notify parent of a resize in case it wants to
  // adjust accordingly
  //
  if (Parent && !(GetExStyle() & WS_EX_NOPARENTNOTIFY))
    Parent->SendMessage(WM_PARENTNOTIFY, WM_SIZE, TParam2(GetHandle()));

  DefaultProcessing();
}

//
// Save the normal position of the window.
// If IsIconic() or IsZoomed() ignore the position since it does not reflect
// the normal state
//
void
TWindow::EvMove(TPoint&)
{
  if (!IsIconic() && !IsZoomed()) {
    TRect wndRect;

    GetWindowRect(wndRect);

    if ((GetWindowLong(GWL_STYLE) & WS_CHILD) == WS_CHILD && Parent &&
         Parent->GetHandle())
      Parent->ScreenToClient(wndRect.TopLeft());

    Attr.X = wndRect.left;
    Attr.Y = wndRect.top;
  }

  DefaultProcessing();
}

//
// Handles WM_COMPAREITEM message (for owner draw controls) by forwarding
// message to control itself
//
TResult
TWindow::EvCompareItem(uint /*ctrlId*/, COMPAREITEMSTRUCT far& compareInfo)
{
  TWindow* win = GetWindowPtr(compareInfo.hwndItem);
  if (win)
    return win->ForwardMessage();
  return DefaultProcessing();
}

//
// Handles WM_DELETEITEM message (for owner draw controls) by forwarding
// message to control itself
//
void
TWindow::EvDeleteItem(uint /*ctrlId*/, DELETEITEMSTRUCT far& deleteInfo)
{
  TWindow* win = GetWindowPtr(deleteInfo.hwndItem);
  if (deleteInfo.hwndItem != GetHandle() && win)
    win->ForwardMessage();
  else
    DefaultProcessing();
}

//
// Handles WM_DRAWITEM message (for owner draw controls & menus) by forwarding
// message to control itself
//
void
TWindow::EvDrawItem(uint /*ctrlId*/, DRAWITEMSTRUCT far& drawInfo)
{
  if (drawInfo.CtlType == ODT_MENU) {
    // Could dispatch to menu...
    // TMenu* menu = ...
    // menu->DrawItem(drawInfo);
  }
  else {
    TWindow* win = GetWindowPtr(drawInfo.hwndItem);
    if (drawInfo.hwndItem != GetHandle() && win) {
      win->ForwardMessage();
      return;
    }
  }
  DefaultProcessing();
}

//
// Handles WM_MEASUREITEM message (for owner draw controls & menus) by
// forwarding message to control itself
//
void
TWindow::EvMeasureItem(uint ctrlId, MEASUREITEMSTRUCT far& measureInfo)
{
  if (measureInfo.CtlType == ODT_MENU) {
    // Could dispatch to menu...
    // TMenu* menu = ...
    // menu->MeasureItem(measureInfo);
  }
  else {
    THandle  hCtl = GetDlgItem(measureInfo.CtlID);  // hWnd not in struct, get
    TWindow* win = GetWindowPtr(hCtl);

    // If the GetWindowPtr failed, & CreationWindow is non-zero, then this
    // WM_MEASUREITEM is probably for the ctrl which is not yet thunked.
    // route the message directly to creation window.
    // NOTE: Msg. may be sent before OWL has had a chance to thunk the ctrl.
    //
    if (!win) {
      TWindow* creationWindow = GetCreationWindow();
      if (creationWindow) {
        if (creationWindow != this)   // Don't cause a recursion loop
          win = creationWindow;
      }
      else
        win = ChildWithId(ctrlId);
    }
    if (win) {
      win->SendMessage(WM_MEASUREITEM, ctrlId, TParam2(&measureInfo));
      return;
    }
  }
  DefaultProcessing();
}

#if defined(BI_PLAT_WIN32)
//
// Process Win32 Control Color messages by redispatching to Win16-like member
// function.
//
TResult
TWindow::EvWin32CtlColor(TParam1 param1, TParam2 param2)
{
  int  ctlType = GetCurrentEvent().Message - WM_CTLCOLORMSGBOX;

  CHECK(ctlType >= CTLCOLOR_MSGBOX && ctlType <= CTLCOLOR_STATIC);

  TEventInfo  eventInfo(WM_CTLCOLOR);

  if (Find(eventInfo)) {
    typedef HBRUSH(GENERIC::*CTL_COLOR_PMF)(HDC, THandle, uint);

    CTL_COLOR_PMF&  pmf = (CTL_COLOR_PMF&)(eventInfo.Entry->Pmf);

    return (TResult)(eventInfo.Object->*pmf)((HDC)param1, (THandle)param2, ctlType);
  }
  return DefWindowProc(GetCurrentEvent().Message, param1, param2);
}
#endif

//
// Dispatches scroll messages as if they were Command messages.
//
void
TWindow::DispatchScroll(uint scrollCode, uint /*thumbPos*/, THandle hWndCtrl)
{
  if (hWndCtrl) {
    TWindow* win = GetWindowPtr(hWndCtrl);
    if (win)
      win->ForwardMessage();

    // Adjust "CurrentEvent" to allow DefaultProcessing to work
    //
    uint16 id = (uint16)::GetDlgCtrlID(hWndCtrl);
    TCurrentEvent& currentEvent = GetCurrentEvent();
    currentEvent.Message = WM_COMMAND;
#if defined(BI_PLAT_WIN16)
      currentEvent.Param1 = id;
      currentEvent.Param2 = MkParam2(uint16(hWndCtrl), scrollCode);
#else
      currentEvent.Param1 = MkParam1(id, scrollCode);
      currentEvent.Param2 = TParam2(hWndCtrl);
#endif

    EvCommand(id, hWndCtrl, scrollCode);
    return;
  }
  DefaultProcessing();
}

//
// Response method for an incoming WM_HSCROLL message
//
// If the message is from a scrollbar control, calls DispatchScroll()
// otherwise passes the message to the TWindow's scroller if it has been
// constructed, else calls DefaultProcessing()
//
// Assumes, because of a Windows bug, that if the window has the scrollbar
// style, it will not have scrollbar controls
//
void
TWindow::EvHScroll(uint scrollCode, uint thumbPos, THandle hWndCtl)
{
  if (!(GetWindowLong(GWL_STYLE) & WS_HSCROLL))
    DispatchScroll(scrollCode, thumbPos, hWndCtl);  // from scrollbar control

  else if (Scroller)
    Scroller->HScroll(scrollCode, thumbPos);

  else
    DefaultProcessing();
}

//
// Response method for an incoming WM_VSCROLL message
//
// If the message is from a scrollbar control, calls DispatchScroll()
// otherwise passes the message to the TWindow's scroller if it has been
// constructed, else calls DefaultProcessing()
//
// Assumes, because of a Windows bug, that if the window has the scrollbar
// style, it will not have scrollbar controls
//
void
TWindow::EvVScroll(uint scrollCode, uint thumbPos, THandle hWndCtl)
{
  if (!(GetWindowLong(GWL_STYLE) & WS_VSCROLL))
    DispatchScroll(scrollCode, thumbPos, hWndCtl);

  else if (Scroller)
    Scroller->VScroll(scrollCode, thumbPos);

  else
    DefaultProcessing();
}

//
// Response method for an incoming WM_ERASEBKGND message
//
bool
TWindow::EvEraseBkgnd(HDC hDC)
{
  // If color is set, we'll handle erasing (or doing nothing) here
  //
  if (BkgndColor != TColor::None) {

    // If a color is set, blt out a rectangle of it, else don't erase & let
    // paint handle background
    //
    if (BkgndColor != TColor::Transparent) {
      TDC dc(hDC);
      dc.SelectObject(TBrush(BkgndColor));  // Rely on caching for performance
      dc.SetBkColor(BkgndColor);
      dc.PatBlt(GetClientRect());
      dc.RestoreBrush();
    }
    return true;
  }

  // No color set, use default class brush
  //
  return (bool)DefaultProcessing();
}

//
// Respond to WM_CTLCOLOR if we have a bkgnd color set & pass that to the
// control
//
HBRUSH
TWindow::EvCtlColor(HDC hDC, THandle /*hWndChild*/, uint ctlType)
{
  // If a bkgnd color is set, then setup the hdc's bkcolor and return a
  // brush for the child to use
  //
  if (BkgndColor != TColor::None && BkgndColor != TColor::Transparent
      && ctlType != CTLCOLOR_EDIT && ctlType != CTLCOLOR_LISTBOX)
  {
    ::SetBkColor(hDC, BkgndColor);
    return TBrush(BkgndColor);  // HBRUSH will stay in cache
  }

  // No color set, use default windows behavior
  //
  return (HBRUSH)DefaultProcessing();
}

//
// Response method for an incoming WM_PAINT message
//
// Calls Paint(), performing Windows-required paint setup and cleanup before
// and after. if the TWindow has a TScroller, also calls its BeginView() and
// EndView() methods before and after call to Paint()
//
void
TWindow::EvPaint()
{
  if (IsFlagSet(wfAlias))
    DefaultProcessing();  // use application-defined wndproc

  else {
    TPaintDC dc(*this);
    TRect&   rect = *(TRect*)&dc.Ps.rcPaint;

    if (Scroller)
      Scroller->BeginView(dc, rect);

    Paint(dc, dc.Ps.fErase, rect);

    if (Scroller)
      Scroller->EndView();
  }
}

//
// Redraws the contents of the TWindow after a WM_PAINT message
// is received
//
// Placeholder for descendant object types to redefine
//
void
TWindow::Paint(TDC&, bool /*erase*/, TRect&)
{
}

//
// Response method for an incoming WM_SETCURSOR message
//
// If a cursor has been set for this window, & the mouse is over the
// client area, set the cursor
//
bool
TWindow::EvSetCursor(THandle hWndCursor, uint hitTest, uint /*mouseMsg*/)
{
  if (hWndCursor == GetHandle() && hitTest == HTCLIENT && HCursor) {
    ::SetCursor(HCursor);
    return true;
  }
  return (bool)DefaultProcessing();
}

//
// Response method for an incoming WM_LBUTTONDOWN message
//
// If the TWindow's Scroller has been constructed and if auto-scrolling
// has been requested, captures mouse input, loops until a WM_LBUTTONUP
// message comes in calling the Scroller's AutoScroll method, and then
// releases capture on mouse input.
// Will also break if a WM_MOUSEMOVE comes in without the left button down
// indicating a lost WM_LBUTTONUP
//
void
TWindow::EvLButtonDown(uint /*modKeys*/, TPoint& /*pt*/)
{
  if (Scroller && Scroller->IsAutoMode()) {
    MSG  loopMsg;

    loopMsg.message = 0;
    SetCapture();

    while (loopMsg.message != WM_LBUTTONUP &&
          (loopMsg.message != WM_MOUSEMOVE || (loopMsg.wParam&MK_LBUTTON))) {
      if (::PeekMessage(&loopMsg, 0, 0, 0, PM_REMOVE)) {
        ::TranslateMessage(&loopMsg);
        ::DispatchMessage(&loopMsg);
      }

      Scroller->AutoScroll();
    }

    ReleaseCapture();
    GetApplication()->ResumeThrow();
  }

  DefaultProcessing();
}

//
//
//
void
DoEnableAutoCreate(TWindow* win, void* /*retVal*/)
{
  if (win->GetHandle())
    win->EnableAutoCreate();
}

//
// Destroys an MS-Windows element associated with the TWindow.
// First, sets the wfAutoCreate flag to ON for each of the windows in the
// TWindow's ChildList to allow later re-creation.
//
void
TWindow::Destroy(int ret)
{
  if (GetHandle()) {
    ForEach(DoEnableAutoCreate, 0);

    if (IsFlagSet(wfModalWindow)) {
      GetApplication()->EndModal(ret);
      ClearFlag(wfModalWindow);
      if (Parent && Parent->GetHandle())
        Parent->SetFocus();
    }

    if (::DestroyWindow(GetHandle()))
      SetHandle(0);

    GetApplication()->ResumeThrow();
    WARNX(OwlWin, GetHandle(), 0, "::DestroyWindow(" << (uint)GetHandle() << ") failed");
  }
}

//
// Specifies registration attributes for the MS-Windows window class of the
// TWindow, allowing instances of TWindow to be registered
//
// Sets the fields of the passed WNDCLASS parameter to the default attributes
// appropriate for a TWindow
//
// Register unique classes for windows that want system background colors so
// that full-drag erasing uses the right color (NT fails to let window erase
// itself)
//
void
TWindow::GetWindowClass(WNDCLASS& wndClass)
{
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = *GetModule();
  wndClass.hIcon = 0;
  wndClass.hCursor = ::LoadCursor(0, IDC_ARROW);

  if (BkgndColor.IsSysColor() &&
      BkgndColor != TColor::None && BkgndColor != TColor::Transparent)
    wndClass.hbrBackground = HBRUSH(BkgndColor.Index()+1);
  else
    wndClass.hbrBackground = HBRUSH(COLOR_WINDOW+1);

  wndClass.lpszMenuName = 0;
  wndClass.lpszClassName = GetClassName();
  wndClass.style = CS_DBLCLKS;
  wndClass.lpfnWndProc = InitWndProc;
}

//
// Return the classname for a generic owl window. Assume instance private class
// registration so that no instance mangling is needed.
//
// Register unique classnames for windows that want system background colors
//
char far*
TWindow::GetClassName()
{
  static const char baseClassName[] = "OWL_Window";

  if (BkgndColor.IsSysColor() &&
      BkgndColor != TColor::None && BkgndColor != TColor::Transparent) {
    static char namebuff[sizeof baseClassName + 1 + 10 + 1 + 4];
    sprintf(namebuff, "%s:%X", baseClassName, BkgndColor.Index());
    return namebuff;
  }
  return CONST_CAST(char far*, baseClassName);  // cast for old non-const type
}

//
// Set this window's accelerator table, performing the load also if this window
// is already created
//
void
TWindow::SetAcceleratorTable(TResId resId)
{
  Attr.AccelTable = resId;
  if (GetHandle())
    LoadAcceleratorTable();
  else
    HAccel = 0;
}

//
// Load the accelerator table indicated in Attr from this window's module's
// resource.
//
void
TWindow::LoadAcceleratorTable()
{
  if (Attr.AccelTable) {
    HAccel = GetModule()->LoadAccelerators(Attr.AccelTable);
    WARNX(OwlWin, !HAccel, 0,
          "Unable to load accelerators " << Attr.AccelTable
          << " from " << *GetModule());
  }
}

//
// Perform MS Windows THandle creation and keep hwnd in Handle member
//
void
TWindow::PerformCreate(int menuOrId)
{
  PRECONDITION(GetModule());
  HWND hwnd = ::CreateWindowEx(Attr.ExStyle,
                               GetClassName(),
                               Title,
                               Attr.Style,
                               Attr.X, Attr.Y, Attr.W, Attr.H,
                               Parent ? Parent->GetHandle() : 0,
                               REINTERPRET_CAST(HMENU,menuOrId),
                               *GetModule(),
                               Attr.Param);
  SetHandle(hwnd);

#if defined(__WARN)
  char modName[_MAX_PATH];
  GetModule()->GetModuleFileName(modName, _MAX_PATH);
  uint parent = Parent ? uint(Parent->GetHandle()) : 0;
  WARNX(OwlWin, !hwnd, 0, "CreateWindowEx failed: " <<\
                "Class: \"" << string(GetClassName()) << "\", " <<\
                "Title: \"" << string(Title) << "\", " <<\
                "Style: " << Attr.Style << ", " <<\
                "Parent: " << parent << ", "        <<\
                "Module: \"" << modName);
#endif
}

//
// Associates an MS-Windows interface element with the TWindow object,
// after creating the interface element if not already created
//
// When creating an element, uses the creation attributes previously set in
// the Attr data field(simply associates the TWindow with an already
// created interface element if the "FromResource" flag is set)
//
// Since this member function now throw an exception on error, it always
// returns true.
//
bool
TWindow::Create()
{
  if (GetHandle())
    return true;

  int  menuOrId = 0;

  DisableAutoCreate();

  // If this is the main window, make sure it is treated like one by the shell
  //
  if (IsFlagSet(wfMainWindow))
    Attr.Style != WS_EX_APPWINDOW;

  if (IsFlagSet(wfFromResource))
    SetHandle(Parent ? Parent->GetDlgItem(Attr.Id) : 0);  // Windows already created it

  else if (Register()) {
    ::SetCreationWindow(this);

    LoadAcceleratorTable();

    if (Attr.Menu) {
      menuOrId = (int)GetModule()->LoadMenu(Attr.Menu);
      WARNX(OwlWin, !menuOrId, 0, "Unable to load menu: " << Attr.Menu <<
            " from " << *GetModule());
    }
    else
      menuOrId = Attr.Id;

    PerformCreate(menuOrId);
    GetApplication()->ResumeThrow();
  }
  else
    TXWindow::Raise(this, IDS_CLASSREGISTERFAIL);

  if (!GetHandle()) {
    if (Attr.Menu)  // && !IsFlagSet(wfFromResource) ?
      DestroyMenu(HMENU(menuOrId));

    TXWindow::Raise(this, IDS_WINDOWCREATEFAIL);
  }

  // Here we have a non-thunked handle. This may be caused by two scenarios:
  // 1. Predefined-class (non-owl) windows.
  // 2. OWL controls which were created from resource [Although these
  //    are registered with InitWndProc, they did not get thunked since
  //    'CreationWindow' was not set when they received their first messages].
  //
  if (!GetWindowPtr(GetHandle())) {

    // Grab the state info.
    //
    GetWindowTextTitle();
    GetHWndState();

    // If it's a 'predefinedClass' window, subclass it
    //
    if (GetWindowProc() != InitWndProc) {
      SubclassWindowFunction();

      // Reset the 'CreationWindow' pointer [if necessary]
      //
      if (::GetCreationWindow() == this)
        ::SetCreationWindow(0);

      // Set status flag [since we missed EvCreate]
      //
      SetFlag(wfPredefinedClass|wfFullyCreated);
    }
    else {
      // This window's WNDPROC is 'InitWndProc' - However, it has not
      // been thunked since 'CreationWindow' was not set when it received
      // its first messages [it was probably created from a resource but
      // registered by OWL]. We'll set 'CreationWindow' and send a dummy
      // message to allow thunking to take place
      //
      if (!::GetCreationWindow())
        ::SetCreationWindow(this);
      SendMessage(WM_USER+0x4000, 0, 0);

      // Update flags
      //
      SetFlag(wfFullyCreated);
    }

    // Invoke SetupWindow since 'EvCreate' was missed..
    //
    SetupWindow();
  }
  return true;
}

//
// Creates the underlying HWND and makes modal with the help
// of TApplication's BeginModal support.
//
int
TWindow::Execute()
{
  return DoExecute();
}

//
// Do actual modal execution using the Begin/End Modal
// support of TApplication.
// NOTE: Defaults to 'TASKMODAL'
//
int
TWindow::DoExecute()
{
  // Attempting to go modal when one's a child is indicative of
  // suicidal tendencies!!
  //
  PRECONDITION((GetStyle() & WS_CHILD) == 0);

  if (GetApplication()) {
    if (Create()) {
      SetFlag(wfModalWindow);
      return GetApplication()->BeginModal(this, MB_TASKMODAL);
    }
  }
  return -1;
}

//
// Performs setup following creation of an associated MS-Windows window.
// Iterates through the TWindow's ChildList, attempting to create
// an associated MS-Windows interface element for each child window
// object in the list (a child's Create method is not called if its
// wfAutoCreate flag is not set)
//
// Calls TransferData to transfer data for its children for whom data transfer
// is enabled.
//
// If the receiver has a TScroller object, calls the scroller's SetBarRange()
// method.
//
// Can be redefined in derived classes to perform additional special
// initialization that requires an THandle.
//
void
TWindow::SetupWindow()
{
  TRACEX(OwlWin, 1, "TWindow::SetupWindow() @" << (void*)this << *this);
  if (Scroller)
    Scroller->SetSBarRange();

  if (!CreateChildren())
    TXWindow::Raise(0, IDS_CHILDCREATEFAIL); // not us, an unspecified child

  TransferData(tdSetData);
}

//
// Always called just before Handle goes away to give derived classes a
// chance to cleanup native Handle related resources.
//
void
TWindow::CleanupWindow()
{
  TRACEX(OwlWin, 1, "TWindow::CleanupWindow() @" << (void*)this << *this);
}

//
// Transfer window 'data' to/from the passed data buffer.  Used to initialize
// windows and get data in or out of them.
//
// The direction passed specifies whether data is to be read from or written
// to the passed buffer, or whether the data element size is simply to be
// returned
//
// The return value is the size (in bytes) of the transfer data.  this method
// recursively calls transfer on all its children that have wfTransfer set.
//
#include <pshpack1.h>

struct TTransferIterInfo {
  void*               Data;
  TTransferDirection  Direction;
};

#include <poppack.h>

static void transferDatchild(TWindow* child, TTransferIterInfo* info) {
  if (child->IsFlagSet(wfTransfer))
    info->Data = (char*)info->Data + child->Transfer(info->Data, info->Direction);
}

//
//
//
uint
TWindow::Transfer(void* buffer, TTransferDirection direction)
{
  if (buffer) {
    TTransferIterInfo info = { buffer, direction };
    ForEach((TActionFunc)transferDatchild, &info);
    return (char near*)info.Data - (char near*)buffer;
  }
  return 0;
}

//
// Transfers data between the TWindow's data buffer and the child
// windows in its ChildList (data is not transfered between any child
// windows whose wfTransfer flag is not set)
//
void
TWindow::TransferData(TTransferDirection direction)
{
  if (TransferBuffer)
    Transfer(TransferBuffer, direction);
}

//
// Registers the TWindow's MS-Windows, if not already registered
//
bool
TWindow::Register()
{
  // Only check for globally registered classes if not under NT or WoW box,
  // since NT treats a 0 hInstance completely differently than Windows.
  //
#if defined(BI_PLAT_WIN32)
  static bool checkGlobal = !TSystem::IsNT();
#else
  static bool checkGlobal = !TSystem::IsWoW();
#endif

  WNDCLASS  windowClass;
  bool gc;
  if (checkGlobal)
    gc = TUser::GetClassInfo(0, GetClassName(), &windowClass) != 0;
  else
    gc = false;

  // If the wndclass is not yet registered, call GetWindowClass() to let our
  // derived class fill in the appropriate info. If the class is still then not
  // registered, then make it so.
  //
  if (!gc && !GetModule()->GetClassInfo(GetClassName(), &windowClass)) {
    GetWindowClass(windowClass);
    WNDCLASS dummy;
    if (!GetModule()->GetClassInfo(GetClassName(), &dummy))
      return ::RegisterClass(&windowClass);
  }

  return true;
}

//
// Returns a bool indicating whether or not it is Ok to close the TWindow
//
// Iterates through the TWindow's ChildList, calling the CanClose()
// method of each
//
// Returns false if any of the child windows returns false
//

static bool cannotClose(TWindow* win, void*) {
  return win->GetHandle() && !win->CanClose();
}

//
//
//
bool
TWindow::CanClose()
{
  return !FirstThat(cannotClose);
}

//
// Destroys the associated MS-Windows interface element after determining that
// it is Ok to do so
//
// If the TWindow is the main window of the application, calls the CanClose()
// method of the application, else calls this->CanClose(), before calling
// Destroy()
//
void
TWindow::CloseWindow(int retVal)
{
  bool  willClose;

  if (IsFlagSet(wfMainWindow))
    willClose = GetApplication()->CanClose();

  else
    willClose = CanClose();

  if (willClose)
    Destroy(retVal);
}

//
// The default response to a WM_CLOSE message is to call CloseWindow()
// and then have the window deleted if the Handle was really destroyed.
//
void
TWindow::EvClose()
{
  if (IsFlagSet(wfAlias))
    DefaultProcessing();

  else {
    CloseWindow();
    if (!GetHandle() && IsFlagSet(wfDeleteOnClose))
      GetApplication()->Condemn(this);  // Assumes delete
  }
}

//
// Responds to an incoming WM_DESTROY message
//
// Calls CleanupWindow() to let derived classes cleanup
// Clears the wfFullyCreated flag since this window is no longer fully created
//
// If the TWindow is the application's main window posts a 'quit' message to
// end the application, unless already in ~TApplication() (MainWindow == 0)
//
void
TWindow::EvDestroy()
{
  ClearFlag(wfFullyCreated);
  CleanupWindow();

  if (!IsFlagSet(wfAlias)) {
    if (IsFlagSet(wfMainWindow) && GetApplication()->IsRunning())
      ::PostQuitMessage(0);
  }

  DefaultProcessing();
}

//
// Responds to an incoming WM_NCDESTROY message, the last message
// sent to an MS-Windows interface element
//
// Sets the Handle data member of the TWindow to zero to indicate that an
// interface element is no longer associated with the object
//
void
TWindow::EvNCDestroy()
{
  DefaultProcessing();
  SetHandle(0);
}

//
// Respond to Windows attempt to close down. Determines if this app or window
// is ready to close.
//
bool
TWindow::EvQueryEndSession()
{
  if (IsFlagSet(wfAlias))
    return (bool)DefaultProcessing();

  else if (IsFlagSet(wfMainWindow))
    return GetApplication()->CanClose();

  else
    return CanClose();
}

//
// Windows is shutting down.
//
void
TWindow::EvEndSession(bool, bool)
{
  DefaultProcessing();    
}

//
// Handle message posted to us by a control needing assistance in dealing with
// invalid inputs
//
void
TWindow::EvChildInvalid(THandle handle)
{
  PRECONDITION(handle);

  ::SendMessage(handle, WM_CHILDINVALID, 0, 0);
}

//----------------------------------------------------------------------------
// Non-virtuals
//

//
//
//
unsigned
TWindow::NumChildren()
{
  return IndexOf(ChildList) + 1;
}

//
// Walks over children and assigns a z-order index to the ZOrder member
//
void
TWindow::AssignZOrder()
{
  TWindow*  wnd;
  THandle   curWindow = GetHandle();

  if (curWindow) {
    curWindow = ::GetWindow(curWindow, GW_CHILD);

    if (curWindow) {
      int  i = 1;

      for (curWindow = ::GetWindow(curWindow, GW_HWNDLAST);
           curWindow;
           curWindow = ::GetWindow(curWindow, GW_HWNDPREV))
      {
        wnd = GetWindowPtr(curWindow);

        if (wnd)
          wnd->ZOrder = (uint16)i++;
      }
    }
  }
}

//
// The private field ZOrder is used to ensure the Z-order is
// consistent through read and write of the object.
//
// When the object is written, parent->AssignZOrder will fill in this value
//
// ZOrder ranges from 1 to N where N is the number of objects and the top one.
// A ZOrder value of 0 means that the Z-ordering has not be recoreded.
//
bool
TWindow::OrderIsI(TWindow* win, void* position)
{
  return win->ZOrder == *(int*)position;
}

//
// Returns true if the child was supposed to be created but couldn't be
//
static bool
cantCreate(TWindow* win, void*)
{
  // If child is already created, then no need to re-create it.
  //
  if (win->GetHandle()) {
    return false;
  }

  bool autoCreate = win->IsFlagSet(wfAutoCreate);

  WARNX(OwlWin, !autoCreate, 0,
        "Child window(Id=" << win->GetId() << ") not autocreated");
  if (!autoCreate)
    return false;

  // This call will only fail if a user-defined Create() returns false. Owl's
  // Creates always throw exceptions.
  //
  if (!win->Create())
    return true;

  // Get & set the window text for the child if it is iconic.
  //
  if (win->IsIconic()) {
    int    textLen = win->GetWindowTextLength();
    char*  text = new char[textLen + 1];

    win->GetWindowText(text, textLen + 1);
    win->SetWindowText(text);
    delete[] text;
  }
  return false;
}

//
// Create the children of the object.  returns true if all the windows
// were successfully created
//
bool
TWindow::CreateChildren()
{
  if (FirstThat(cantCreate)) // create children first to restore created order
    return false;

  // Restore Z-ordering for children that have Z-ordering recorded
  //
  THandle above = HWND_TOP;
  for (int top = NumChildren(); top; top--) {
    TWindow* wnd = FirstThat(&TWindow::OrderIsI, &top);
    if (wnd) {
      wnd->SetWindowPos(above, 0,0,0,0, SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE);
      above = wnd->GetHandle();
    }
  }
  return true;
}

//
// adds the passed pointer to a child window to the linked list
// of sibling windows which ChildList points to
//
void
TWindow::AddChild(TWindow* child)
{
  if (child)
    if (ChildList) {
      child->SiblingList = ChildList->SiblingList;
      ChildList->SiblingList = child;
      ChildList = child;
    }
    else {
      ChildList = child;
      child->SiblingList = child;
    }
}

//
// Returns a pointer to the TWindow's previous sibling (the window previous to
// the TWindow in its parent's child window list)
//
// Returns the sibling which points to the TWindow
//
// If the TWindow was the first child added to the list, returns a pointer to
// the last child added
//
TWindow*
TWindow::Previous()
{
  if (!SiblingList) {
    return 0;
  }
  else {
    TWindow*  CurrentIndex = this;

    while (CurrentIndex->Next() != this)
      CurrentIndex = CurrentIndex->Next();

    return CurrentIndex;
  }
}

//
// Returns a pointer to the first TWindow in the ChildList that meets some
// specified criteria
//
// If no child in the list meets the criteria, 0 is returned
//
// The Test parameter which defines the criteria, is a pointer to a
// function that takes a TWindow pointer & a pointer to void
//
// The TWindow* will be used as the pointer to the child window and
// the void* as a pointer to the Test function's additional parameters
//
// The Test function must return a Boolean value indicating whether the
// child passed meets the criteria
//
TWindow*
TWindow::FirstThat(TCondFunc test, void* paramList)
{
  if (ChildList) {
    TWindow*  nextChild = ChildList->Next();
    TWindow*  curChild;

    do {
      curChild = nextChild;
      nextChild = nextChild->Next();

      //
      // Test curChild for okay
      //
      if (test(curChild, paramList))
        return curChild;
    } while (curChild != ChildList && ChildList);
  }
  return 0;
}

//
// Iterates over each child window in the TWindow's ChildList,
// calling the procedure whose pointer is passed as the Action to be
// performed for each child
//
// A pointer to a child is passed as the first parameter to the iteration
// procedure
//
void
TWindow::ForEach(TActionFunc action, void* paramList)
{
  if (ChildList) {
    TWindow*  curChild;
    TWindow*  nextChild = ChildList->Next();  // Allows ForEach to delete children

    do {
      curChild = nextChild;
      nextChild = nextChild->Next();
      action(curChild, paramList);
    } while (curChild != ChildList && ChildList);
  }
}

//
// Returns a pointer to the first TWindow in the ChildList that
// meets some specified criteria
//
// If no child in the list meets the criteria, 0 is returned
//
// The Test parameter which defines the criteria, is a pointer to a member
// function (this is how it's different from FirstThat above) that takes a
// pointer to a TWindow & a pointer to void
//
// The TWindow pointer will be used as the pointer to the child window and the
// void pointer as a pointer to the Test function's additional parameters
//
// The Test function must return a Boolean value indicating whether the child
// passed meets the criteria
//
TWindow*
TWindow::FirstThat(TCondMemFunc test, void* paramList)
{
  if (ChildList) {
    TWindow*  nextChild = ChildList->Next();
    TWindow*  curChild;

    do {
      curChild = nextChild;
      nextChild = nextChild->Next();

      if ((this->*test)(curChild, paramList))
        return curChild;
    } while (curChild != ChildList && ChildList);
  }
  return 0;
}

//
// Iterates over each child window in the TWindow's ChildList,
// calling the member function (unlike ForEach above which takes pointer
// to non-member function) whose pointer is passed as the Action to
// be performed for each child
//
// A pointer to a child is passed as the first parameter to the iteration
// procedure
//
void
TWindow::ForEach(TActionMemFunc action, void* paramList)
{
  if (ChildList) {
    TWindow*  nextChild = ChildList->Next();
    TWindow*  curChild;

    do {
      curChild = nextChild;
      nextChild = nextChild->Next();
      (this->*action)(curChild, paramList);
    } while (curChild != ChildList && ChildList);
  }
}

//
// Returns the position at which the passed child window appears
// in the TWindow's ChildList
//
// If the child does not appear in the list, -1 is returned
//
// Zero'th position is ChildList->Next
//
static int position;
static bool isItThisChild1(TWindow* win, void* child)
{
  ++position;
  return win == (TWindow*)child;
}

//
//
//
int
TWindow::IndexOf(TWindow* child)
{
  position = -1;
  return FirstThat(isItThisChild1, child) ? position : -1;
}

//
// Returns the child at the passed position in the TWindow's
// ChildList
//
// The ChildList is circularly-referent so that passing a position
// larger than the number of children will cause the traversal of the
// list to wrap
//
// Zero'th position is ChildList->Next
//
TWindow*
TWindow::At(int position)
{
  if (position == -1)
    return 0;

  else {
    TWindow*  currentChild = ChildList;

    if (currentChild) {
      currentChild = ChildList->Next();

      while (position > 0) {
        currentChild = currentChild->Next();
        position--;
      }
    }
    return currentChild;
  }
}

//
// Returns a pointer to the window in the ChildList with the passed Id
//
// If no child in the list has the passed Id, 0 is returned
//
static bool isItThisChild2(TWindow* win, void* id) {
  return win->GetId() == *(int*)id;
}

//
//
//
TWindow*
TWindow::ChildWithId(int id) const
{
  return ((TWindow*)this)->FirstThat(isItThisChild2, &id);
}

//
// Send a message directly to this window using system API. Handles exception
// resumption for systems that need it.
//
TResult
TWindow::SendMessage(uint msg, TParam1 param1, TParam2 param2)
{
  PRECONDITION(GetHandle());

  TResult result = ::SendMessage(GetHandle(), msg, param1, param2);
  GetApplication()->ResumeThrow();
  return result;
}

//
// Forward the current event to a given window. Can either send or post, based
// on the send argument.
//
TResult
TWindow::ForwardMessage(THandle handle, bool send)
{
  if (!handle)
    return 0;

  TCurrentEvent& currentEvent = GetCurrentEvent();
  if (send) {
    TResult result = ::SendMessage(handle, currentEvent.Message,
                                   currentEvent.Param1,
                                   currentEvent.Param2);
    GetApplication()->ResumeThrow();
    return result;
  }
  else
    return ::PostMessage(handle, currentEvent.Message,
                         currentEvent.Param1,
                         currentEvent.Param2);
}

//
// Forward a message to an Owl window. If send, then bypass windows directly
// and call the owl window's window proc.
//
TResult
TWindow::ForwardMessage(bool send)
{
  TCurrentEvent& currentEvent = GetCurrentEvent();
  if (send)
    return HandleMessage(currentEvent.Message, currentEvent.Param1,
                         currentEvent.Param2);
  return ForwardMessage(GetHandle(), send);
}

//
// Broadcast a given message to all the children of this window, including
// non-object windows
//
void
TWindow::ChildBroadcastMessage(uint msg, TParam1 param1, TParam2 param2)
{
  for (THandle hWndChild = GetWindow(GW_CHILD); hWndChild; ) {
    THandle hWndNext = ::GetWindow(hWndChild, GW_HWNDNEXT);
    ::SendMessage(hWndChild, msg, param1, param2);
    GetApplication()->ResumeThrow();
    hWndChild = hWndNext;
  }
}

//
// Destroys the associated MS-Windows interface element and deletes the C++
// object unconditionally (without calling CanClose())
//
// This function is static to avoid side effects of deleting 'this'.
//
void
TWindow::ShutDownWindow(TWindow* win, int retVal)
{
  win->Destroy(retVal);
  delete win;
}

//
// Sets the Title and caption of this TWindow
//
void
TWindow::SetCaption(const char far* title)
{
  if (Title != title) {
    if (HiUint16(uint32(Title)))
      delete[] Title;

    Title = strnewdup(title);
  }

  if (GetHandle())
    ::SetWindowText(GetHandle(), Title);
}

//
// Gets the Title member var from the current window caption or text
//
void
TWindow::GetWindowTextTitle()
{
  if (LoUint16(uint32(Title)) == 0xFFFF)  // ignore "don't-change" titles
    return;

  if (HiUint16(uint32(Title)))
    delete[] Title;

  int titleLength = GetWindowTextLength();
  if (titleLength < 0) {
    Title = strnewdup((const char far*)"");
  }
  else {
    Title = new far char[titleLength + 1];
    Title[0] = 0;
    Title[titleLength] = 0;
    GetWindowText(Title, titleLength + 1);
  }
}

//
// Copy over the styles, the coordinates & the id from the existing HWnd into
// the Owl TWindow members.
//   NOTE: the title is not copied here, but in GetWindowTextTitle()
//
void
TWindow::GetHWndState()
{
  // Retrieve Attr.Style and Attr.ExStyle
  //
  // NOTE: some windows controls (e.g. EDIT) change the style bits
  // (e.g. WS_BORDER) from their original values.  if we always reset
  // Attr.Style and Attr.ExStyle by extracting their values from
  // Windows, we will lose some of the style bits we supplied
  // in the CreateWindowEx call.  in the case of the ResourceId
  // constructors, of course, we must retrieve these values.
  //
  if (IsFlagSet(wfFromResource)) {
    Attr.Style = GetWindowLong(GWL_STYLE);
    Attr.ExStyle = GetWindowLong(GWL_EXSTYLE);
  }

  // Retrieve Attr.X, Attr.Y, Attr.W and Attr.H
  //
  TRect  wndRect;

  GetWindowRect(wndRect);
  Attr.H = wndRect.Height();
  Attr.W = wndRect.Width();

  THandle  hParent = GetParentH();
  if ((Attr.Style & WS_CHILD) && hParent)
    ::ScreenToClient(hParent, &wndRect.TopLeft());

  Attr.X = wndRect.left;
  Attr.Y = wndRect.top;

#if defined(BI_PLAT_WIN16)
  Attr.Id = GetWindowWord(GWW_ID);
#else
  Attr.Id = GetWindowLong(GWL_ID);
#endif
}

//
//
//
uint
TWindow::GetDlgItemInt(int childId, bool* translated, bool isSigned) const
{
  PRECONDITION(GetHandle());

#if (sizeof(bool) == sizeof(int))
  uint retVal = ::GetDlgItemInt(GetHandle(), childId, (int*)translated, isSigned);
#else
  int tempTranslated;
  uint retVal = ::GetDlgItemInt(GetHandle(), childId, &tempTranslated, isSigned);
  if (translated)
    *translated = tempTranslated;
#endif
  return retVal;
}

//
// Gets/Sets the style bits of the underlying window or the 'Style'
// member of the attribute structure associated with this TWindow object.
//
uint32
TWindow::GetStyle() const
{
  return GetHandle() ? GetWindowLong(GWL_STYLE) : Attr.Style;
}

//
// Gets/Sets the style bits of the underlying window or the 'Style'
// member of the attribute structure associated with this TWindow object.
//
uint32
TWindow::SetStyle(uint32 style)
{
  if (!GetHandle()) {
    uint32 oldstyle = Attr.Style;
    Attr.Style = style;
    return oldstyle;
  }
  return SetWindowLong(GWL_STYLE, style);
}

//
// Gets the extra style bits of the window.
//
uint32
TWindow::GetExStyle() const
{
  return GetHandle() ? GetWindowLong(GWL_EXSTYLE) : Attr.ExStyle;
}

//
// Sets the extra style bits of the window.
//
uint32
TWindow::SetExStyle(uint32 style)
{
  if (!GetHandle()) {
    uint32 oldstyle = Attr.ExStyle;
    Attr.ExStyle = style;
    return oldstyle;
  }
  return SetWindowLong(GWL_EXSTYLE, style);
}

//
// Modify the style bits of the window.
//
bool
TWindow::ModifyStyle(uint32 offBits, uint32 onBits, uint swpFlags)
{
  uint32 style = GetStyle();
  uint32 newStyle = (style & ~offBits) | onBits;
  if (style == newStyle)
    return false;

  SetStyle(newStyle);

  if (swpFlags && GetHandle())
    SetWindowPos(0, 0, 0, 0, 0,
                 SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE|SWP_NOZORDER|swpFlags);
  return true;
}

//
// Modify the style bits of the window.
//
bool
TWindow::ModifyExStyle(uint32 offBits, uint32 onBits, uint swpFlags)
{
  uint32 style = GetExStyle();
  uint32 newStyle = (style & ~offBits) | onBits;
  if (style == newStyle)
    return false;

  SetExStyle(newStyle);
  if (swpFlags)
    SetWindowPos(0, 0, 0, 0, 0,
                 SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE|SWP_NOZORDER|swpFlags);
  return true;
}

//
// Get the window rectangle whether it has been created or not
//
void
TWindow::GetWindowRect(TRect& rect) const {
  if (GetHandle()) {
    ::GetWindowRect(GetHandle(), &rect);
  }
  else {
    rect.SetWH(Attr.X, Attr.Y, Attr.W, Attr.H);
  }
}

//
// Get the window's client rectangle whether it has been created or not
//
void
TWindow::GetClientRect(TRect& rect) const {
  if (GetHandle()) {
    ::GetClientRect(GetHandle(), &rect);
  }
  else {
    rect.Set(0, 0, Attr.W, Attr.H);
  }
}

//
// Set the new window position.
//
bool
TWindow::SetWindowPos(THandle hWndInsertAfter,
                      int x, int y, int w, int h,
                      uint flags)
{
  if (GetHandle())
    return ::SetWindowPos(GetHandle(), hWndInsertAfter, x, y, w, h, flags);

  if (!(flags & SWP_NOMOVE)) {
    Attr.X = x;
    Attr.Y = y;
  }
  if (!(flags & SWP_NOSIZE)) {
    Attr.W = w;
    Attr.H = h;
  }


  if (flags & SWP_SHOWWINDOW)
    Attr.Style |= WS_VISIBLE;
  else if (flags & SWP_HIDEWINDOW)
    Attr.Style &= ~WS_VISIBLE;

  return true;
}

//
// Displays this TWindow in a given state. Can be called either before or after
// the Window is created. If before, the show state is placed into Attr for use
// at creation
//
bool
TWindow::ShowWindow(int cmdShow)
{
  // If the window is being minimzed send a WM_SYSCOMMAND; this way the
  // frame window focus saving works properly
  //
  if (GetHandle()) {
    if (cmdShow == SW_MINIMIZE)
      return HandleMessage(WM_SYSCOMMAND, SC_MINIMIZE);

    else
      return ::ShowWindow(GetHandle(), cmdShow);
  }

  switch (cmdShow) {
    case SW_HIDE:
      Attr.Style &= ~WS_VISIBLE;
      break;
    case SW_SHOWNORMAL:
    case SW_RESTORE:
      Attr.Style |= WS_VISIBLE;
      Attr.Style &= ~(WS_MINIMIZE | WS_MAXIMIZE);
      break;
    case SW_SHOWMINIMIZED:
    case SW_MINIMIZE:
    case SW_SHOWMINNOACTIVE:
      Attr.Style |= WS_VISIBLE;
      Attr.Style |= WS_MINIMIZE;
      break;
    case SW_SHOWMAXIMIZED:
      Attr.Style |= WS_VISIBLE;
      Attr.Style |= WS_MINIMIZE;
      break;
    case SW_SHOWNOACTIVATE:
    case SW_SHOW:
    case SW_SHOWNA:
      Attr.Style |= WS_VISIBLE;
      break;
  }
  return true;
}

//
// Set the cursor for this window given a TModule and a resId
// Updates the current cursor if it is over this window.
//
bool
TWindow::SetCursor(TModule* module, TResId resId)
{
  if (module == CursorModule && resId == CursorResId)
    return false;

  HCURSOR hOldCursor = (HCursor && CursorModule) ? HCursor : 0;

  CursorModule = module;
  CursorResId = resId;
  if (CursorResId)
    if (CursorModule)
      HCursor = CursorModule->LoadCursor(CursorResId);
    else
      HCursor = ::LoadCursor(0, CursorResId);
  else
    HCursor = 0;

  // If the cursor is in our client window then set it now
  //
  if (GetHandle()) {
    TPoint p;
    GetCursorPos(p);
    ScreenToClient(p);
    if (GetClientRect().Contains(p))
      ::SetCursor(HCursor);
  }

  // Destroy old cursor if there was one & it was not loaded from USER
  //
  if (hOldCursor)
    ::DestroyCursor(hOldCursor);
  return true;
}

//
// Handle WM_INITMENUPOPUP while embeded to generate command enable messages
// for our server menu items. Very similar to TFrameWindow::EvInitMenuPopup;
// could rearrange code to share better.
//
void
TWindow::EvInitMenuPopup(HMENU hPopupMenu, uint /*index*/, bool sysMenu)
{
  if (IsFlagSet(wfAlias))
    DefaultProcessing();

  else if (!sysMenu && hPopupMenu) {
    const int count = ::GetMenuItemCount(hPopupMenu);

    for (int pos = 0; pos < count; pos++) {
      uint  id;

      if (hPopupMenu == GetMenu()) // top level menu
        id = ::GetMenuItemID(hPopupMenu, pos);

      else {
        // For second level and below menus, return the implied id for popup
        // sub-menus. The implied id for a sub-menu is the id of the first item
        // in the popup sub-menu less 1. If there are more than one level of
        // popup menus, it will recursively look into those sub-menus as well.
        //
        TMenu popupMenu(hPopupMenu);
        id = popupMenu.GetMenuItemID(pos);
      }

      // Ignore separators
      //
      if (id == 0 || uint16(id) == uint16(-1))
        continue;

      // Skip the rest if it is the mdi child list, or system commands
      //
      if (id == IDW_FIRSTMDICHILD || id > 0xF000)
        break;

      EvCommandEnable(TMenuItemEnabler(hPopupMenu, id, GetHandle(), pos));
    }
  }
}

//
// Associate a popup menu with the window so that it can automatically
// handle a WM_CONTEXTMENU message.
//
void
TWindow::AssignContextMenu(TPopupMenu* popupMenu)
{
  delete ContextPopupMenu;
  ContextPopupMenu = popupMenu;
}

//
// Respond to a right button click in window.
//
void
TWindow::EvContextMenu(HWND /*child*/, int x, int y)
{
  if (GetContextMenu()) {
    GetContextMenu()->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
                                     x, y, 0, *this, 0);
  }
  else {
    // Allow 'wfPredefined' and 'wfAlias' classes to handle the ContextMenu
    // event.
    //
    DefaultProcessing();
  }
}

//
// Wrapper for Windows API.
//
int
TWindow::GetScrollPos(int bar) const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  return ::GetScrollPos(GetHandle(), bar);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
//  info.fMask = SIF_DISABLENOSCROLL | SIF_POS;
  info.fMask = SIF_POS;
  GetScrollInfo(bar, &info);
  return info.nPos;
#endif
}

//
// Wrapper for Windows API.
//
int
TWindow::SetScrollPos(int bar, int pos, bool redraw)
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  return ::SetScrollPos(GetHandle(), bar, pos, redraw);
#else
  int oldPos = GetScrollPos(bar);

  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_POS;
  info.nPos = pos;
  SetScrollInfo(bar, &info, redraw);
  return oldPos;
#endif
}

//
// Wrapper for Windows API.
//
void
TWindow::GetScrollRange(int bar, int& minPos, int& maxPos) const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  ::GetScrollRange(GetHandle(), bar, &minPos, &maxPos);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_RANGE;
  GetScrollInfo(bar, &info);
  minPos = info.nMin;
  maxPos = info.nMax;
#endif
}

//
// Wrapper for Windows API.
//
void
TWindow::SetScrollRange(int bar, int minPos, int maxPos, bool redraw)
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  ::SetScrollRange(GetHandle(), bar, minPos, maxPos, redraw);
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_RANGE;
  info.nMin = minPos;
  info.nMax = maxPos;
  SetScrollInfo(bar, &info, redraw);
#endif
}

//
//
//
void
TWindow::SetScrollPage(int bar, int page, bool redraw)
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_PAGE;
  info.nPage = page;
  SetScrollInfo(bar, &info, redraw);
#endif
}

//
//
//
int
TWindow::GetScrollPage(int bar) const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  SCROLLINFO info;
  ZeroMemory(&info, sizeof info);
  info.cbSize = sizeof info;
  info.fMask = SIF_PAGE;
  GetScrollInfo(bar, &info);
  return info.nPage;
#endif
}

#if defined(BI_PLAT_WIN32)
//
//
//
void
TWindow::SetScrollInfo(int bar, SCROLLINFO* scrollInfo, bool redraw)
{
  PRECONDITION(GetHandle());
  ::SetScrollInfo(GetHandle(), bar, scrollInfo, redraw);
}

//
//
//
void
TWindow::GetScrollInfo(int bar, SCROLLINFO* scrollInfo) const
{
  PRECONDITION(GetHandle());
  ::GetScrollInfo(GetHandle(), bar, scrollInfo);
}
#endif

//
// Not inline to avoid requiring gdiobjec.h by window.h just to get TRegion's
// conversion operator
//
bool
TWindow::GetUpdateRgn(TRegion& region, bool erase) const
{
  PRECONDITION(GetHandle());

  return ::GetUpdateRgn(GetHandle(), region, erase);
}

//
//
//
#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TWindow& w)
  {
    os << '(';
#if !defined(BI_NO_RTTI)
      os << typeid(w).name() << ',';
#else
      os << _TYPENAME(&w) << ',';
#endif
    os << "0x" << hex << uint(w.GetHandle()) << ',';
    if (w.Title)
      os << '\'' << TResId(w.Title) << '\'' << ',';
    if (w.Parent)
      os << "id=" << w.GetId();
    os << ')';
    return os;
  }
#endif


//
// Returns a string which kind-of identifies the window (used during autopsy
// and vivisection of dead/dying window)
//
static const char*
winInfo(TWindow* win)
{
  const char noTitle[] = "Untitled";
  static char winStr[80];
  if (win) {
    sprintf(winStr, "%s, %u, %s",
                    HiUint16(uint32(win->Title)) ? win->Title : noTitle,
                    win->Attr.Id, _TYPENAME(win));
    return winStr;
  }
  return "";
}

#if defined(OWL2_COMPAT)
//
// For backward compatibility
//
string
TXWindow::Msg(TWindow* win, uint resId)
{
  return MakeMessage(resId, winInfo(win));
}
#endif

//
// InvalidWindow exception constructor
//
TXWindow::TXWindow(TWindow* win, uint resId)
:
  TXOwl(MakeMessage(resId, winInfo(win)), resId),
  Window(win)
{
}

//
// Copy the exception object.
//
TXWindow::TXWindow(const TXWindow& src)
:
  TXOwl(src),
  Window(src.Window)
{
}

//
// Unhandled exception.
//
int
TXWindow::Unhandled(TModule* app, uint promptResId)
{
  Window = 0;
  return TXOwl::Unhandled(app, promptResId);
}

//
// Clone the exception object for safe-throwing in Win16.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXWindow*
#endif
TXWindow::Clone()
{
  return new TXWindow(*this);
}

//
// Throw the exception.
//
void
TXWindow::Throw()
{
  THROW( *this );
}

//
// Creates the TXWindow exception and throws it.
//
void
TXWindow::Raise(TWindow* win, uint resourceId)
{
  TXWindow(win, resourceId).Throw();
}
