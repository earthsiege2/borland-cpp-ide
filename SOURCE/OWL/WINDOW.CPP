//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TWindow.  This defines the basic behavior of all
//   Windows.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/window.h>
#include <owl/applicat.h>
#include <owl/appdict.h>
#include <owl/scroller.h>
#include <owl/gdiobjec.h>
#include <owl/menu.h>
#include <owl/framewin.h>
#include <stdlib.h>

DIAG_DECLARE_GROUP(OwlMsg);  // diagnostic group for message tracing
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlWin, 1, 0);  // diagnostic group for windows

//
// define to build registered Window's classname using the module name
//
//#define _OWL_BUILDUP_CLASSNAME

//
// define to use rtti to create unique window ids for the message cache
//
#if defined(__BORLANDC__) && !defined(BI_NO_RTTI)
# define OWL_RTTI_MSGCACHE
# define TYPE_UNIQUE_UINT32(t)    reinterpret_cast<uint32>(typeid(t).tpp)
#endif

//
// Externs defined in owl.cpp
//
extern LRESULT CALLBACK __export InitWndProc(HWND, uint, WPARAM, LPARAM);

extern WNDPROC       CreateInstanceThunk(TWindow*);
extern void          FreeInstanceThunk(WNDPROC);
extern void _OWLFUNC SetCreationWindow(TWindow*);
extern uint _OWLDATA GetWindowPtrMsgId;

//$---------------------------------------------------------------------------

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
  EV_COMMAND(CM_EXIT, CmExit),
  EV_WM_QUERYENDSESSION,
  EV_WM_SYSCOLORCHANGE,
  EV_WM_INITMENUPOPUP,
END_RESPONSE_TABLE;


//$---------------------------------------------------------------------------
//
//
TCommandEnabler::TCommandEnabler(uint id, HWND hWndReceiver)
  : Id(id), HWndReceiver(hWndReceiver)
{
  Handled = false;
}

void
TCommandEnabler::Enable(bool)
{
  Handled = true;
}

//$---------------------------------------------------------------------------

//
// constructor for a TWindow.  if a parent window is passed, adds the TWindow
// to its parent's list of children
//
TWindow::TWindow(TWindow*        parent,
                 const char far* title,
                 TModule*        module)
{
  Thunk = 0;  // remember that we still need to initialize
  Init(parent, title, module);
}

//$---------------------------------------------------------------------------
//
// constructor for a TWindow which is being used as an alias for a
// non-OWL window.  This ctor is generally not used by derived classes
//
TWindow::TWindow(HWND hWnd, TModule* module)
{
  // Perform preliminary initialization
  //
  HWindow = hWnd;
  Title = 0;
  Thunk = 0;  // remember that we still need to initialize

  // If the receiver's parent is an OWL window then pass the window to Init()
  // so the receiver can be added to the parent's list of children
  //
  HWND      hParent = GetParent();
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

//$---------------------------------------------------------------------------
//
// Protected constructor for use by immediate virtually derived classes.
// Immediate derivitives must call Init() before constructions are done.
//
TWindow::TWindow()
{
  Thunk = 0;  // remember that we still need to initialize
}

//
// Normal initialization of a default constructed TWindow. Is ignored
// if called more than once.
//
void
TWindow::Init(TWindow*        parent,
              const char far* title,
              TModule*        module)
{
  if (!Thunk) {
    Init(parent, module);
    Title = strnewdup(title);
    DefaultProc = 0;
    HWindow = 0;
    EnableAutoCreate();

    // initialize creation attributes
    //
    Attr.Style = WS_CHILD | WS_VISIBLE;
    Attr.X = Attr.Y = Attr.W = Attr.H = 0;
    Attr.ExStyle = 0;
    Attr.Id = 0;
  }
}

//
// Private initializer function that does the bulk of the work
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
  hAccel = 0;
  Thunk = ::CreateInstanceThunk(this);
  Scroller = 0;

  CursorModule = 0;
  CursorResId = 0;
  HCursor = 0;
  BkgndColor = NoColor;

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

  TRACEX(OwlWin, 1, "TWindow constructed @" << (void*)this);
}

//
// installs the thunk as the window function and saves the old window function
// in "DefaultProc"
//
void
TWindow::SubclassWindowFunction()
{
  PRECONDITION(HWindow != 0);
#if defined(BI_PLAT_WIN32)
  uint32 processId;
  ::GetWindowThreadProcessId(HWindow, &processId);
  if (processId == ::GetCurrentProcessId()) {
#else
  if (::GetWindowTask(HWindow) == ::GetCurrentTask()) {
#endif
    DefaultProc = (WNDPROC)SetWindowLong(GWL_WNDPROC, uint32(GetThunk()));
    CHECK(DefaultProc != GetThunk());  // can only be called once!
  }
}

//
// Destructor for a TWindow: disposes of each window in its ChildList
// and removes itself from a non-0 parent's list of children
//
// Destroys a still-associated MS-Windows interface element and frees
// the instance thunk used for association of an MS-Windows element
// to the TWindow
//
// Disposes of its Scroller if the TScroller object was constructed
//
static void shutDown(TWindow* win, void*) {
  win->Destroy();
  delete win;
}

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

  // If the HWindow is still around, then destroy it or unlink from it as
  // appropriate.
  //
  if (HWindow) {
    // for aliases:
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
    // for non-aliases:
    //  - destroy the windows element
    // this is not a normal condition and is a safety net only
    //
    else {
      WARNX(OwlWin, HWindow, 0, "Destroying from TWindow::~TWindow: " << *this);
      Destroy();
    }
  }

  if (Parent)
    Parent->RemoveChild(this);

  if (IsFlagSet(wfMainWindow))
    GetApplication()->MainWindow = 0;
  if (Application)
    Application->Uncondemn(this);

  // Delete menu id string, scroller, title, cursor & thunk
  //
  if (Attr.Menu.IsString())
    delete [] (char far*)Attr.Menu;  // assume strnewdup was used

  // delete scroller if there is one, by casting up to base and relying on
  // virtual dtor to avoid pulling in TScroller object code.
  //
  if (Scroller) {
    delete (TStreamableBase*)Scroller;
    Scroller = 0;
  }

  if (HIWORD(Title))
    delete [] Title;

  if (HCursor && CursorModule)
    SetCursor(0, 0);

  ::FreeInstanceThunk(Thunk);
  TRACEX(OwlWin, 1, "TWindow destructed @" << (void*)this);
}

#if defined(BI_MULTI_THREAD)
//
// overrides TEventHandler::Dispatch() to handle multi-thread synchronization
//
LRESULT TWindow::Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp)
{
  TApplication::TAppLock Lock(*GetApplication());
  return TEventHandler::Dispatch(info, wp, lp);
}

#endif

//
//
//
bool
TWindow::PreProcessMsg(MSG& msg)
{
  return hAccel ? ::TranslateAccelerator(HWindow, hAccel, &msg) : false;
}

//
//
//
bool
TWindow::IdleAction(long /*idleCount*/)
{
  return false;  // we don't need any more time for now
}

//
// Respond to this message by broadcasting it to all children
//
void
TWindow::EvSysColorChange()
{
  ChildBroadcastMessage(WM_SYSCOLORCHANGE);
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
// parent (owner)
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
  // tell Windows about the change too, if appropriate
  //
  if (HWindow && Parent && GetParent() != Parent->HWindow) {
    if (newParent) {
      if (newParent->HWindow)
        ::SetParent(HWindow, newParent->HWindow);
    }
    else
      ::SetParent(HWindow, 0);
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
// Wildcard check used for child id notifications
//
static bool wildcardCheck(TGenericTableEntry __RTFAR& entry,
                          TEventHandler::TEventInfo& info) {
  return entry.Id == info.Id && (entry.Msg == UINT_MAX || entry.Msg == info.Msg);
}

//
// handles default processing of events
//
// this includes continued processing of menu/accelerators and child Id
// notifications
//
LRESULT
TWindow::DefaultProcessing()
{
  TCurrentEvent& currentEvent = GetCurrentEvent();

  if (currentEvent.Message == WM_COMMAND_ENABLE) {
    if (currentEvent.Win != this) {
      TWindow*          receiver = Parent ? Parent : currentEvent.Win;
      TCommandEnabler&  commandEnabler = *(TCommandEnabler*)currentEvent.LParam;
      TEventInfo        eventInfo(WM_COMMAND_ENABLE, commandEnabler.Id);

      if (receiver->Find(eventInfo))
        return receiver->Dispatch(eventInfo, 0, currentEvent.LParam);
    }

    return 0;
  }

  if (currentEvent.Message != WM_COMMAND)
    return DefWindowProc(currentEvent.Message, currentEvent.WParam, currentEvent.LParam);

  //
  // currentEvent.Message == WM_COMMAND
  //
#if defined(BI_PLAT_WIN16)
  uint    notifyCode = HIWORD(currentEvent.LParam);
#else
  uint    notifyCode = HIWORD(currentEvent.WParam);
#endif
  uint    id = LOWORD(currentEvent.WParam);
  HWND    hWndCtl = (HWND)(uint)currentEvent.LParam;

  if (currentEvent.Win == this) {
    //
    // menu command originally destined for the receiver. defer to the app
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
    //
    // originally destined for the receiver and the receiver has called us so
    // default processing can occur
    //
    // unpack the original parameters and call DefWindowProc()
    //
    return DefWindowProc(currentEvent.Message, currentEvent.WParam, currentEvent.LParam);
  }
  else {
    TWindow*        receiver;
    uint            wParam;
    TEqualOperator  equal = 0;

    if (hWndCtl == 0) {
      //
      // menu/accelerator/push button
      //
      // either give the message to the receiver's parent or the original
      // receiver of the message
      //
      receiver = Parent ? Parent : currentEvent.Win;

      //
      // "notifyCode" is either 0 or 1 depending on whether this is from an
      // accelerator; however, we want to explicitly look for a 0...
      //
      notifyCode = 0;

      wParam = id;  // pass along "id" in case the receiver wants it
    }
    else {
      //
      // child id notification sent to the child and the child has called us
      //
      // offer the parent an opportunity to handle the notification
      //
      // NOTE: use equal function that will do a wildcard search
      //
      equal = wildcardCheck;
      receiver = currentEvent.Win;

      //
      // the child window identifier shouldn't be 0, but if it is then it will
      // look like we are searching for a WM_ message with value "notifyCode"
      //
      if (receiver->IsFlagSet(wfAlias) || id == 0)
        return receiver->DefWindowProc(currentEvent.Message, currentEvent.WParam, currentEvent.LParam);

      wParam = notifyCode;  // pass notification code in case receiver wants it
    }

    TEventInfo  eventInfo(notifyCode, id);

    if (receiver->Find(eventInfo, equal))
      return receiver->Dispatch(eventInfo, wParam);

    else
      return receiver->DefaultProcessing();
  }
}

//
// processing for WM_COMMAND
//
LRESULT
TWindow::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  TWindow*        receiver = this;
  uint            wParam;
  TEqualOperator  equal = 0;

  if (hWndCtl == 0) {
    //
    // menu/accelerator
    //
    // "notifyCode" is either 0 or 1 depending on whether this is from an
    // accelerator; however, we want to explicitly look for a 0...
    //
    notifyCode = 0;

    //
    // pass the "id" along in case the user wants it...
    //
    wParam = id;
  }
  else {
    //
    // child id notification
    //
    TWindow*  child = GetWindowPtr(hWndCtl);

    //
    // pass the "notifyCode" along in case the user wants it...
    //
    wParam = notifyCode;

    if (child) {
      //
      // give the child first crack at the event
      //
      receiver = child;
      id = UINT_MAX;  // special designator for child Id notifications that are
                      // handled at the child
    }
    else {
      //
      // offer the parent an opportunity to handle the notification
      //
      // NOTE: use equal function that will do a wildcard search
      //
      equal = wildcardCheck;

      //
      // the child window identifier shouldn't be 0, but if it is then it will
      // look like we are searching for a WM_ message with value "notifyCode"
      //
      if (id == 0)
        return DefaultProcessing();
    }
  }

  TEventInfo  eventInfo(notifyCode, id);

  if (receiver->Find(eventInfo, equal))
    return receiver->Dispatch(eventInfo, wParam);

  else
    return receiver->DefaultProcessing();
}

//
//
//
void
TWindow::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  TEventInfo  eventInfo(WM_COMMAND_ENABLE, commandEnabler.Id);

  if (Find(eventInfo))
    Dispatch(eventInfo, 0, (LPARAM)&commandEnabler);
}

//
// Don't process for windows out of our window tree (esp. other apps)
//
void
TWindow::RouteCommandEnable(HWND hInitCmdTarget, TCommandEnabler& commandEnabler)
{
  // Extra processing for commands & commandEnablers: send the command down the
  // command chain if we are the original receiver
  //
  if (commandEnabler.IsReceiver(*this)) {
    HWND  hCmdTarget = hInitCmdTarget;
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

    HWND  hCmdTarget = hInitCmdTarget;
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
      // check if the app wants to handle it
      //
      TEventInfo    enableInfo(WM_COMMAND_ENABLE, commandEnabler.Id);
      TApplication* app = GetApplication();
      if (app->Find(enableInfo)) {
        app->Dispatch(enableInfo, 0, (LPARAM)&commandEnabler);
        if (commandEnabler.GetHandled())
          return;
      }
      enable = app->Find(eventInfo);
    }

    commandEnabler.Enable(enable);
  }
}

//
// specifies default processing for an incoming message
//
// calls original window proc that we subclassed, using ::CallWindowProc to
// make sure that registers get setup correctly.
//
LRESULT
TWindow::DefWindowProc(uint message, WPARAM wParam, LPARAM lParam)
{
  CHECK(DefaultProc);
  LRESULT result = ::CallWindowProc(DefaultProc, HWindow, message, wParam, lParam);
  GetApplication()->ResumeThrow();
  return result;
}


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
// Without rtti, use a per-instance unique id. Less efficient, but safe without
// rtti.
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
// if the message is WM_COMMAND calls EvCommand(); otherwise looks for a handler
// in the message response table
//
LRESULT
TWindow::WindowProc(uint msg, WPARAM wParam, LPARAM lParam)
{
  // Handle WM_COMMAND_ENABLE command enable msgs by directly calling the
  // virtual EvCommandEnable
  //
  if (msg == WM_COMMAND_ENABLE) {
    EvCommandEnable(*(TCommandEnabler*)lParam);
    return 0;
  }
  // Handle WM_COMMAND command msgs by directly calling the
  // virtual EvCommand
  //
  else if (msg == WM_COMMAND) {
#if defined(BI_PLAT_WIN16)
    return EvCommand(LOWORD(wParam), (HWND)(uint)lParam, HIWORD(lParam));
#else
    return EvCommand(LOWORD(wParam), (HWND)(uint)lParam, HIWORD(wParam));
#endif
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
        return Dispatch(eventInfo, wParam, lParam);

      } // else fall out & do default below
    }
    // Perform the lookup on this window.
    //
    else if (Find(eventInfo)) {
      TRACEX(OwlMsg, 1, MsgName(msg) << " => " << *this);
      msgCache[key].Set(UniqueId, msg, eventInfo.Entry, int(eventInfo.Object) - int(this));
      return Dispatch(eventInfo, wParam, lParam);
    }
    else  // not found
      msgCache[key].Set(UniqueId, msg, 0);  // Cache no-handler entries too

    // Behavior for messages that have no handler. If this is the main window,
    // then give the app a chance to handle the message. If not the main
    // window, or if the app had no handler, just call DefWindowProc() to
    // pass the message back to whomever we subclassed
    //
    if (IsFlagSet(wfMainWindow)) {
      TEventInfo cmdEventInfo(msg, wParam);
      if (GetApplication()->Find(cmdEventInfo))
        return GetApplication()->Dispatch(cmdEventInfo, wParam, lParam);
      if (GetApplication()->Find(eventInfo))
        return GetApplication()->Dispatch(eventInfo, wParam, lParam);
    }
    return DefWindowProc(msg, wParam, lParam);
  }
}

//
// Save current event and call this window's WindowProc. Handles exceptions,
// error checking, & GetWindowPtr messages.
//
LRESULT
TWindow::HandleMessage(uint msg, WPARAM wParam, LPARAM lParam)
{
  // save event away in "CurrentEvent"
  //
  TCurrentEvent& currentEvent = GetCurrentEvent();
  TCurrentEvent  saveEvent = currentEvent;  // for nested calls
  currentEvent.Win = this;
  currentEvent.Message = msg;
  currentEvent.WParam = wParam;
  currentEvent.LParam = lParam;

  // call window object's WindowProc virtual function
  //
  LRESULT  result;
  result = WindowProc(msg, wParam, lParam);
  currentEvent = saveEvent;  // restore previous event to current event
  return result;
}

//
// Window function called for normal, initialized, OWL windows via a
// per-window thunk. 'this' ptr is setup in register(s) by the thunk before
// StdWndProc is called.
//
#if defined(BI_PLAT_WIN16)
LRESULT
FAR PASCAL __export
StdWndProc(HWND, uint msg, WPARAM wParam, LPARAM lParam)
{
  return ((TWindow*)MK_FP(_ES,_BX))->ReceiveMessage(msg, wParam, lParam);
}
#else
LRESULT
FAR PASCAL _stdcall
StdWndProc(HWND, uint msg, WPARAM wParam, LPARAM lParam)
{
  return ((TWindow*)_EAX)->ReceiveMessage(msg, wParam, lParam);
}
#endif

//
// First member function that receives messages from windows thru the
// thunk & then StdWndProc. Deals with exception suspension for non-NT
// environments.
//
LRESULT
TWindow::ReceiveMessage(uint msg, WPARAM wParam, LPARAM lParam)
{
  // if it's a "GetWindowPtr" message, then return pointer to this window
  //
  if (msg == ::GetWindowPtrMsgId && (!lParam || lParam == LPARAM(Application)))
    return LRESULT(this);

#if defined(BI_PLAT_WIN32)
  static bool exceptionOK =
                !(::GetVersion()&0x80000000) || (::GetVersion()&0xFF) >= 4;
  if (exceptionOK)
    return HandleMessage(msg, wParam, lParam);
#endif
  TRY {
    return HandleMessage(msg, wParam, lParam);
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
  CATCH( (Bad_cast& x) {
    GetApplication()->SuspendThrow(TApplication::xsBadCast);
  })
  CATCH( (Bad_typeid& x) {
    GetApplication()->SuspendThrow(TApplication::xsBadTypeid);
  })
  CATCH( (...) {
    GetApplication()->SuspendThrow(TApplication::xsUnknown);
  })
  ENDCATCH

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
TWindow* _OWLFUNC GetWindowPtr(HWND hWnd, const TApplication* app)
{
  if (!hWnd /* && ::IsWindow(hWnd) */)  // could also check handle validity
    return 0;

#if defined(BI_DATA_NEAR)
  LPARAM param2 = app ? LPARAM(app) : 0;
#else
  LPARAM param2 = LPARAM(app);
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
// response method for an incoming WM_CREATE message
//
// Call virtual SetupWindow to give derived classes a chance to set things up
// now that we are created & have an HWindow
//
int
TWindow::EvCreate(CREATESTRUCT far&)
{
  SetupWindow();
  SetFlag(wfFullyCreated);
  return (int)DefaultProcessing();
}

//
// regular windows never hold focus child handles--just say no.
//
bool
TWindow::HoldFocusHWnd(HWND /*hWndLose*/, HWND /*hWndGain*/)
{
  return false;
}

//
// handle WM_KILLFOCUS so that we can have a parent window hold onto our
// HWindow and possibly restore focus later.
//
void
TWindow::EvKillFocus(HWND getFocus)
{
  // Follow the parent chain back until a window volunteers to hold our handle
  //
  if (IsFlagSet(wfFullyCreated)) {
    TWindow* holdWin = Parent;
    while (holdWin && !holdWin->HoldFocusHWnd(HWindow, getFocus))
      holdWin = holdWin->Parent;
  }

  DefaultProcessing();
}

//
// response method for an incoming WM_SIZE message
//
// saves the normal size of the window in Attr
//
// also calls the SetPageSize() and SetBarRange() methods of the TWindow's
// scroller, if it has been constructed
//
void
TWindow::EvSize(uint sizeType, TSize&)
{
  if (Scroller && sizeType != SIZE_MINIMIZED) {
    Scroller->SetPageSize();
    Scroller->SetSBarRange();
  }

  if (sizeType == SIZE_RESTORED) {
    TRect  wndRect;

    GetWindowRect(wndRect);
    Attr.W = wndRect.Width();
    Attr.H = wndRect.Height();
  }

  // Added owl functionality: notify parent of a resize in case it wants to
  // adust accordingly
  //
  if (Parent && !(GetWindowLong(GWL_EXSTYLE)&WS_EX_NOPARENTNOTIFY))
    Parent->SendMessage(WM_PARENTNOTIFY, WM_SIZE, (uint)HWindow);

  DefaultProcessing();
}

//
// save the normal position of the window
//
// if IsIconic() or IsZoomed() ignore the position since it does not reflect the
// normal state
//
void
TWindow::EvMove(TPoint&)
{
  if (!IsIconic() && !IsZoomed()) {
    TRect wndRect;

    GetWindowRect(wndRect);

    if ((GetWindowLong(GWL_STYLE) & WS_CHILD) == WS_CHILD && Parent &&
         Parent->HWindow)
      Parent->ScreenToClient(wndRect.TopLeft());

    Attr.X = wndRect.left;
    Attr.Y = wndRect.top;
  }

  DefaultProcessing();
}

//
// handles WM_COMPAREITEM message (for owner draw controls) by forwarding
// message to control itself
//
LRESULT
TWindow::EvCompareItem(uint /*ctrlId*/, COMPAREITEMSTRUCT far& compareInfo)
{
  TWindow* win = GetWindowPtr(compareInfo.hwndItem);
  if (win)
    return win->ForwardMessage();
  return DefaultProcessing();
}

//
// handles WM_DELETEITEM message (for owner draw controls) by forwarding
// message to control itself
//
void
TWindow::EvDeleteItem(uint /*ctrlId*/, DELETEITEMSTRUCT far& deleteInfo)
{
  TWindow* win = GetWindowPtr(deleteInfo.hwndItem);
  if (deleteInfo.hwndItem != HWindow && win)
    win->ForwardMessage();
  else
    DefaultProcessing();
}

//
// handles WM_DRAWITEM message (for owner draw controls & menus) by forwarding
// message to control itself
//
void
TWindow::EvDrawItem(uint /*ctrlId*/, DRAWITEMSTRUCT far& drawInfo)
{
  if (drawInfo.CtlType == ODT_MENU) {
    // dispatch to menu...
    // TMenu* menu = ...
    // menu->DrawItem(drawInfo);
  }
  else {
    TWindow* win = GetWindowPtr(drawInfo.hwndItem);
    if (drawInfo.hwndItem != HWindow && win) {
      win->ForwardMessage();
      return;
    }
  }
  DefaultProcessing();
}

//
// handles WM_MEASUREITEM message (for owner draw controls & menus) by
// forwarding message to control itself
//
void
TWindow::EvMeasureItem(uint ctrlId, MEASUREITEMSTRUCT far& measureInfo)
{
  if (measureInfo.CtlType == ODT_MENU) {
    // dispatch to menu...
    // TMenu* menu = ...
    // menu->MeasureItem(measureInfo);
  }
  else {
    HWND hwndCtl = GetDlgItem(measureInfo.CtlID);  // hWnd not in struct, get
    TWindow* win = GetWindowPtr(hwndCtl);
    //
    // If the GetWindowPtr failed, & CreationWindow is non-zero, then this
    // WM_MEASUREITEM is probably for the ctrl which is not yet thunked.
    // route the message directly to creation window.
    //
    extern TWindow* _OWLDATA CreationWindow;
    if (!win) {             // sometimes this is send before Owl thunks ctl
      if (CreationWindow)
        win = CreationWindow;
      else
        win = ChildWithId(ctrlId);
    }
    if (win) {
      win->HandleMessage(WM_MEASUREITEM, ctrlId, LPARAM(&measureInfo));
      return;
    }
  }
  DefaultProcessing();
}

//
//
#if defined(BI_PLAT_WIN32)
LRESULT
TWindow::EvWin32CtlColor(WPARAM wParam, LPARAM lParam)
{
  int  ctlType = GetCurrentEvent().Message - WM_CTLCOLORMSGBOX;

  CHECK(ctlType >= CTLCOLOR_MSGBOX && ctlType <= CTLCOLOR_STATIC);

  TEventInfo  eventInfo(WM_CTLCOLOR);

  if (!Find(eventInfo))
    return DefWindowProc(GetCurrentEvent().Message, wParam, lParam);

  else {
    typedef HBRUSH(GENERIC::*CTL_COLOR_PMF)(HDC, HWND, uint);

    CTL_COLOR_PMF&  pmf = (CTL_COLOR_PMF&)(eventInfo.Entry->Pmf);

    return (LRESULT)(eventInfo.Object->*pmf)((HDC)wParam, (HWND)lParam, ctlType);
  }
}
#endif

//
// dispatches scroll messages as if they were Command messages.
//
void
TWindow::DispatchScroll(uint scrollCode, uint /*thumbPos*/, HWND hWndCtrl)
{
  if (hWndCtrl) {
    TWindow* win = GetWindowPtr(hWndCtrl);
    if (win)
      win->ForwardMessage();

    //
    // Adjust "CurrentEvent" to allow DefaultProcessing to work
    //
    uint16 id = (uint16)::GetDlgCtrlID(hWndCtrl);
    TCurrentEvent& currentEvent = GetCurrentEvent();
    currentEvent.Message = WM_COMMAND;
#if defined(BI_PLAT_WIN16)
      currentEvent.WParam = id;
      currentEvent.LParam = MAKELPARAM(hWndCtrl, scrollCode);
#else
      currentEvent.WParam = MAKEWPARAM(id, scrollCode);
      currentEvent.LParam = LPARAM(hWndCtrl);
#endif

    EvCommand(id, hWndCtrl, scrollCode);
    return;
  }
  DefaultProcessing();
}

//
// response method for an incoming WM_HSCROLL message
//
// if the message is from a scrollbar control, calls DispatchScroll()
// otherwise passes the message to the TWindow's scroller if it has been
// constructed, else calls DefaultProcessing()
//
// assumes, because of a Windows bug, that if the window has the scrollbar
// style, it will not have scrollbar controls
//
void
TWindow::EvHScroll(uint scrollCode, uint thumbPos, HWND hWndCtl)
{
  if (!(GetWindowLong(GWL_STYLE) & WS_HSCROLL))
    DispatchScroll(scrollCode, thumbPos, hWndCtl);  // from scrollbar control

  else if (Scroller)
    Scroller->HScroll(scrollCode, thumbPos);

  else
    DefaultProcessing();
}

//
// response method for an incoming WM_VSCROLL message
//
// if the message is from a scrollbar control, calls DispatchScroll()
// otherwise passes the message to the TWindow's scroller if it has been
// constructed, else calls DefaultProcessing()
//
// assumes, because of a Windows bug, that if the window has the scrollbar
// style, it will not have scrollbar controls
//
void
TWindow::EvVScroll(uint scrollCode, uint thumbPos, HWND hWndCtl)
{
  if (!(GetWindowLong(GWL_STYLE) & WS_VSCROLL))
    DispatchScroll(scrollCode, thumbPos, hWndCtl);

  else if (Scroller)
    Scroller->VScroll(scrollCode, thumbPos);

  else
    DefaultProcessing();
}

//
// response method for an incoming WM_ERASEBKGND message
//
bool
TWindow::EvEraseBkgnd(HDC hDC)
{
  // color set, we'll handle erasing (or doing nothing) here
  //
  if (BkgndColor != NoColor) {

    // if a color is set, blt out a rectangle of it, else don't erase & let
    // paint handle background
    //
    if (BkgndColor != NoErase) {
      SetBkColor(hDC, BkgndColor);
      ExtTextOut(hDC, 0, 0, ETO_OPAQUE, &GetClientRect(), 0, 0, 0);
    }
    return true;
  }

  //
  // no color set, use default class brush
  //
  return (bool)DefaultProcessing();
}

//
// response method for an incoming WM_PAINT message
//
// calls Paint(), performing Windows-required paint setup and cleanup before
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
// redraws the contents of the TWindow after a WM_PAINT message
// is received
//
// placeholder for descendant object types to redefine
//
void
TWindow::Paint(TDC&, bool /*erase*/, TRect&)
{
}

//
// response method for an incoming WM_SETCURSOR message
//
// if a cursor has been set for this window, & the mouse is over the
// client area, set the cursor
//
bool
TWindow::EvSetCursor(HWND hWndCursor, uint hitTest, uint /*mouseMsg*/)
{
  if (hWndCursor == HWindow && hitTest == HTCLIENT && HCursor) {
    ::SetCursor(HCursor);
    return true;
  }
  return (bool)DefaultProcessing();
}

//
// response method for an incoming WM_LBUTTONDOWN message
//
// if the TWindow's Scroller has been constructed and if auto-scrolling
// has been requested, captures mouse input, loops until a WM_LBUTTONUP
// message comes in calling the Scroller's AutoScroll method, and then
// releases capture on mouse input
// will also break if a WM_MOUSEMOVE comes in without the left button down
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
void
DoEnableAutoCreate(TWindow* win, void* /*retVal*/)
{
  if (win->HWindow)
    win->EnableAutoCreate();
}

//
// Destroys an MS-Windows element associated with the TWindow.
// First, sets the wfAutoCreate flag to ON for each of the windows in the
// TWindow's ChildList to allow later re-creation.
//
void
TWindow::Destroy(int)
{
  if (HWindow) {
    ForEach(DoEnableAutoCreate, 0);

    if (::DestroyWindow(HWindow))
      HWindow = 0;
    GetApplication()->ResumeThrow();
    WARNX(OwlWin, HWindow, 0, "::DestroyWindow(" << (uint)HWindow << ") failed");
  }
}

//
// specifies registration attributes for the MS-Windows window class
// of the TWindow, allowing instances of TWindow to be registered
//
// sets the fields of the passed WNDCLASS parameter to the default
// attributes appropriate for a TWindow
//
void
TWindow::GetWindowClass(WNDCLASS& wndClass)
{
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = *GetModule();
  wndClass.hIcon = 0;
  wndClass.hCursor = ::LoadCursor(0, IDC_ARROW);
  wndClass.hbrBackground = HBRUSH(COLOR_WINDOW + 1);
  wndClass.lpszMenuName = 0;
  wndClass.lpszClassName = GetClassName();
  wndClass.style = CS_DBLCLKS;
  wndClass.lpfnWndProc = ::InitWndProc;
}

//
// Returns a classname for a generic owl window. Builds the name based on the
// name part of the current module's filename with "Window" appended.
//
char far*
TWindow::GetClassName()
{
#if defined(_OWL_BUILDUP_CLASSNAME)
  static char classSuffix[] = "Window";
  static char className[_MAX_FNAME+sizeof(classSuffix)];

  if (!*className) {
    char filePath[_MAX_PATH];
#if (BI_PLAT_WIN16)
    int  len = GetModule()->GetModuleFileName(filePath, sizeof(filePath));
#else
    int  len = ::GetModuleFileName(0, filePath, sizeof(filePath));
#endif
    CHECK(len > 0);
    _splitpath(filePath, 0, 0, className, 0);
    strcat(className, classSuffix);
  }
  return className;
#else
  return "OwlWindow";  // assume application private class
#endif
}

//
void
TWindow::LoadAcceleratorTable()
{
  if (Attr.AccelTable) {
    hAccel = GetModule()->LoadAccelerators(Attr.AccelTable);
    WARNX(OwlWin, !hAccel, 0,
          "Unable to load accelerators " << Attr.AccelTable
          << " from " << *GetModule());
  }
}

//
// Perform MS Windows window creation
//
void
TWindow::PerformCreate(int menuOrId)
{
  HWindow = ::CreateWindowEx(Attr.ExStyle,
                           GetClassName(),
                           Title,
                           Attr.Style,
                           Attr.X, Attr.Y, Attr.W, Attr.H,
                           Parent ? Parent->HWindow : 0,
                           (HMENU)menuOrId,
                           *GetModule(),
                           Attr.Param);
}

//
// associates an MS-Windows interface element with the TWindow object,
// after creating the interface element if not already created
//
// when creating an element, uses the creation attributes previously set in
// the Attr data field(simply associates the TWindow with an already
// created interface element if the "FromResource" flag is set)
//
// Since this member function now throw an exception on error, it always
// returns true.
//
bool
TWindow::Create()
{
  if (HWindow)
    return true;

  int  menuOrId = 0;

  DisableAutoCreate();

  if (IsFlagSet(wfFromResource))
    HWindow = Parent ? Parent->GetDlgItem(Attr.Id) : 0;  // windows already created it

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
    THROW( TXWindow(this, IDS_CLASSREGISTERFAIL) );

  if (!HWindow) {
    if (Attr.Menu)  // && !IsFlagSet(wfFromResource) ?
      DestroyMenu(HMENU(menuOrId));

    THROW( TWindow::TXWindow(this, IDS_WINDOWCREATEFAIL) );
  }

  // predefined (non-owl) class--grab the state info that the class setup,
  // install the thunk & zero the creation window since InitWndProc never got
  // called, and set a flag
  //
  if (!GetWindowPtr(HWindow)) {
    GetWindowTextTitle();
    GetHWndState();

    SubclassWindowFunction();
    ::SetCreationWindow(0);
    SetFlag(wfPredefinedClass|wfFullyCreated);

    SetupWindow();
  }

  return true;
}

//
// performs setup following creation of an associated MS-Windows window.
// Iterates through the TWindow's ChildList, attempting to create
// an associated MS-Windows interface element for each child window
// object in the list (a child's Create method is not called if its
// wfAutoCreate flag is not set)
//
// calls TransferData to transfer data for its children for whom data transfer
// is enabled
//
// if the receiver has a TScroller object, calls the scroller's SetBarRange()
// method
//
// can be redefined in derived classes to perform additional special
// initialization that requires an HWND
//
void
TWindow::SetupWindow()
{
  if (Scroller)
    Scroller->SetSBarRange();

  if (!CreateChildren())
    THROW( TXWindow(0, IDS_CHILDCREATEFAIL) ); // not us, an unspecified child

  TransferData(tdSetData);
}

//
// always called just before HWindow goes away to give derived classes a
// chance to cleanup HWND related resources.
//
void
TWindow::CleanupWindow()
{
}

//
// transfer window 'data' to/from the passed data buffer.  Used to initialize
// windows and get data in or out of them.
//
// the direction passed specifies whether data is to be read from or
// written to the passed buffer, or whether the data element size is simply
// to be returned
//
// the return value is the size (in bytes) of the transfer data.  this method
// recursively calls transfer on all its children that have wfTransfer set.
//

struct TTransferIterInfo {
  void*               Data;
  TTransferDirection  Direction;
};

static void transferDatchild(TWindow* child, TTransferIterInfo* info) {
  if (child->IsFlagSet(wfTransfer))
    (char*)info->Data += child->Transfer(info->Data, info->Direction);
}

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

//$---------------------------------------------------------------------------
//
// transfers data between the TWindow's data buffer and the child
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
// registers the TWindow's MS-Windows, if not already registered
//
bool
TWindow::Register()
{
  // Only check for globally registered classes if not in an NT WoW box,
  // since WoW plays nasty games with class registration.
  //
#if defined(BI_PLAT_WIN32)
  static bool checkGlobal = ToBool(::GetVersion()&0x80000000);  // not NT
#else
  static bool checkGlobal = !ToBool(::GetWinFlags()&0x4000);  // not WoW box
#endif

  WNDCLASS  windowClass;
  bool gc;
  if (checkGlobal)
    gc = ToBool(::GetClassInfo(0, GetClassName(), &windowClass));
  else
    gc = false;

  if (!gc && !GetModule()->GetClassInfo(GetClassName(), &windowClass)) {
    GetWindowClass(windowClass);
    return ::RegisterClass(&windowClass);
  }

  return true;
}

//
// returns a bool indicating whether or not it is Ok to close the TWindow
//
// iterates through the TWindow's ChildList, calling the CanClose()
// method of each
//
// returns false if any of the child windows returns false
//

static bool cannotClose(TWindow* win, void*) {
  return win->HWindow && !win->CanClose();
}

bool
TWindow::CanClose()
{
  return !FirstThat(cannotClose);
}

//
// destroys the associated MS-Windows interface element
// after determining that it is Ok to do so
//
// if the TWindow is the main window of the application, calls the CanClose()
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
// the default response to a WM_CLOSE message is to call CloseWindow()
// and then have the window deleted if the HWindow was really destroyed.
//
void
TWindow::EvClose()
{
  if (IsFlagSet(wfAlias))
    DefaultProcessing();

  else {
    CloseWindow();
    if (!HWindow && IsFlagSet(wfDeleteOnClose))
      GetApplication()->Condemn(this);  // Assumes delete
  }
}

//
// responds to an incoming WM_DESTROY message
//
// Calls CleanupWindow() to let derived classes cleanup
// Clears the wfFullyCreated flag since this window is no longer fully created
//
// if the TWindow is the application's main window posts a 'quit' message to
// end the application, unless already in ~TApplication() (MainWindow == 0)
//
void
TWindow::EvDestroy()
{
  ClearFlag(wfFullyCreated);
  CleanupWindow();

  if (!IsFlagSet(wfAlias)) {
    if (IsFlagSet(wfMainWindow) && GetApplication()->IsRunning())
      ::PostQuitMessage(GetApplication()->Status);
  }

  DefaultProcessing();
}

//
// responds to an incoming WM_NCDESTROY message, the last message
// sent to an MS-Windows interface element
//
// sets the HWindow data member of the TWindow to zero to indicate that an
// interface element is no longer associated with the object
//
void
TWindow::EvNCDestroy()
{
  DefaultProcessing();
  HWindow = 0;
}

//
// respond to Windows attempt to close down
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
// if the window receives an Exit menu choice, it will attempt
// to close down the window
//
void
TWindow::CmExit()
{
  if (IsFlagSet(wfMainWindow))
    CloseWindow();

  else
    DefaultProcessing();
}

//
// Handle message posted to us by a control needing assistance in dealing with
// invalid inputs
//
void
TWindow::EvChildInvalid(HWND hWnd)
{
  ::SendMessage(hWnd, WM_CHILDINVALID, 0, 0);
}

//----------------------------------------------------------------------------
// Non-virtuals
//----------------------------------------------------------------------------

//$---------------------------------------------------------------------------
unsigned
TWindow::NumChildren()
{
  return IndexOf(ChildList) + 1;
}

//$---------------------------------------------------------------------------
//
//
void
TWindow::AssignZOrder()
{
  TWindow*  wnd;
  HWND      curWindow = HWindow;

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

//$---------------------------------------------------------------------------
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

//$---------------------------------------------------------------------------
//
// returns true if the child was supposed to be created but couldn't be
//
static bool
cantCreate(TWindow* win, void*)
{
  if (win->HWindow)
    return false;

  bool autoCreate = win->IsFlagSet(wfAutoCreate);

  WARNX(OwlWin, !autoCreate, 0,
        "Child window(Id=" << win->GetId() << ") not autocreated");
  if (!autoCreate)
    return false;

  //
  // this call will only fail if a user-defined Create() returns false. Owl's
  // Creates always throw exceptions.
  //
  if (!win->Create())
    return true;

  if (win->IsIconic()) {
    int    textLen = ::GetWindowTextLength(win->HWindow);
    char*  text = new char[textLen + 1];

    ::GetWindowText(win->HWindow, text, textLen + 1);
    ::SetWindowText(win->HWindow, text);
    delete [] text;
  }
  return false;
}

//
// create the children of the object.  returns true if all the windows
// were successfully created
//
bool
TWindow::CreateChildren()
{
  if (FirstThat(cantCreate)) // create children first to restore created order
    return false;
  //
  // restore Z-ordering for children that have Z-ordering recorded
  //
  HWND above = HWND_TOP;
  for (int top = NumChildren(); top; top--) {
    TWindow* wnd = FirstThat(&TWindow::OrderIsI, &top);
    if (wnd) {
      wnd->SetWindowPos(above, 0,0,0,0, SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
      above = wnd->HWindow;
    }
  }
  return true;
}

//$---------------------------------------------------------------------------
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

//$---------------------------------------------------------------------------
//
// returns a pointer to the TWindow's previous sibling (the
// window previous to the TWindow in its parent's child window
// list)
//
// returns the sibling which points to the TWindow
//
// if the TWindow was the first child added to the list, returns
// a pointer to the last child added
//
TWindow*
TWindow::Previous()
{
  if (!SiblingList)
    return 0;

  else {
    TWindow*  CurrentIndex = this;

    while (CurrentIndex->Next() != this)
      CurrentIndex = CurrentIndex->Next();

    return CurrentIndex;
  }
}

//$---------------------------------------------------------------------------
//
// returns a pointer to the first TWindow in the ChildList that meets some
// specified criteria
//
// if no child in the list meets the criteria, 0 is returned
//
// the Test parameter which defines the criteria, is a pointer to a
// function that takes a TWindow pointer & a pointer to void
//
// the TWindow* will be used as the pointer to the child window and
// the void* as a pointer to the Test function's additional parameters
//
// the Test function must return a Boolean value indicating whether the
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

//$---------------------------------------------------------------------------
//
// iterates over each child window in the TWindow's ChildList,
// calling the procedure whose pointer is passed as the Action to be
// performed for each child
//
// a pointer to a child is passed as the first parameter to the iteration
// procedure
//
void
TWindow::ForEach(TActionFunc action, void* paramList)
{
  if (ChildList) {
    TWindow*  curChild;
    TWindow*  nextChild = ChildList->Next();  // allows ForEach to delete children

    do {
      curChild = nextChild;
      nextChild = nextChild->Next();
      action(curChild, paramList);
    } while (curChild != ChildList && ChildList);
  }
}

//$---------------------------------------------------------------------------
//
// returns a pointer to the first TWindow in the ChildList that
// meets some specified criteria
//
// if no child in the list meets the criteria, 0 is returned
//
// the Test parameter which defines the criteria, is a pointer to a member
// function (this is how it's different from FirstThat above) that takes a
// pointer to a TWindow & a pointer to void
//
// the TWindow pointer will be used as the pointer to the child window and the
// void pointer as a pointer to the Test function's additional parameters
//
// the Test function must return a Boolean value indicating whether the child
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

//$---------------------------------------------------------------------------
//
// iterates over each child window in the TWindow's ChildList,
// calling the member function (unlike ForEach above which takes pointer
// to non-member function) whose pointer is passed as the Action to
// be performed for each child
//
// a pointer to a child is passed as the first parameter to the iteration
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

//$---------------------------------------------------------------------------
//
// returns the position at which the passed child window appears
// in the TWindow's ChildList
//
// if the child does not appear in the list, -1 is returned
//
// zero'th position is ChildList->Next
//
static int position;
static bool isItThisChild1(TWindow* win, void* child) {
  ++position;
  return win == (TWindow*)child;
}

int
TWindow::IndexOf(TWindow* child)
{
  position = -1;
  return FirstThat(isItThisChild1, child) ? position : -1;
}

//$---------------------------------------------------------------------------
//
// returns the child at the passed position in the TWindow's
// ChildList
//
// the ChildList is circularly-referent so that passing a position
// larger than the number of children will cause the traversal of the
// list to wrap
//
// zero'th position is ChildList->Next
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

//$---------------------------------------------------------------------------
//
// returns a pointer to the window in the ChildList with the passed Id
//
// if no child in the list has the passed Id, 0 is returned
//
static bool isItThisChild2(TWindow* win, void* id) {
  return win->GetId() == *(int*)id;
}

TWindow*
TWindow::ChildWithId(int id) const
{
  return ((TWindow*)this)->FirstThat(isItThisChild2, &id);
}

//$---------------------------------------------------------------------------
//
LRESULT
TWindow::SendMessage(uint msg, WPARAM wParam, LPARAM lParam) {
  LRESULT result = ::SendMessage(HWindow, msg, wParam, lParam);
  GetApplication()->ResumeThrow();
  return result;
}

//$---------------------------------------------------------------------------
//
LRESULT
TWindow::ForwardMessage(HWND hWnd, bool send)
{
  if (!hWnd)
    return 0;
  TCurrentEvent& currentEvent = GetCurrentEvent();
  if (send) {
    LRESULT result = ::SendMessage(hWnd, currentEvent.Message,
                                   currentEvent.WParam,
                                   currentEvent.LParam);
    GetApplication()->ResumeThrow();
    return result;
  }
  else
    return ::PostMessage(hWnd, currentEvent.Message,
                         currentEvent.WParam,
                         currentEvent.LParam);
}

//$---------------------------------------------------------------------------
//
// Forward a message to an Owl window. If send, then bypass windows directly
// and call the owl window's window proc.
//
LRESULT
TWindow::ForwardMessage(bool send)
{
  TCurrentEvent& currentEvent = GetCurrentEvent();
  if (send)
    return HandleMessage(currentEvent.Message, currentEvent.WParam,
                         currentEvent.LParam);
  return ForwardMessage(HWindow, send);
}

//$---------------------------------------------------------------------------
//
void
TWindow::ChildBroadcastMessage(uint msg, WPARAM wParam, LPARAM lParam)
{
  for (HWND hWndChild = GetWindow(GW_CHILD); hWndChild; ) {
    HWND hWndNext = ::GetWindow(hWndChild, GW_HWNDNEXT);
    ::SendMessage(hWndChild, msg, wParam, lParam);
    GetApplication()->ResumeThrow();
    hWndChild = hWndNext;
  }
}

//$---------------------------------------------------------------------------
//
// destroys the associated MS-Windows interface element and deletes the C++
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

//$---------------------------------------------------------------------------
//
// displays the TWindow, after checking that it has a valid handle
//
void
TWindow::Show(int cmdShow)
{
  //
  // if the window is being minimzed send a WM_SYSCOMMAND; this way the
  // frame window focus saving works properly
  //
  if (HWindow)
    if (cmdShow == SW_MINIMIZE)
      HandleMessage(WM_SYSCOMMAND, SC_MINIMIZE);

    else
      ::ShowWindow(HWindow, cmdShow);
}

//$---------------------------------------------------------------------------
//
// sets the Title and caption of the TWindow
//
void
TWindow::SetCaption(const char far* title)
{
  if (Title != title) {
    if (HIWORD(Title))
      delete [] Title;

    Title = strnewdup(title);
  }

  if (HWindow)
    ::SetWindowText(HWindow, Title);
}

//$---------------------------------------------------------------------------
//
// gets the Title member var from the current window caption or text
//
void
TWindow::GetWindowTextTitle()
{
  if (LOWORD(Title) == 0xFFFF)  // ignore "don't-change" titles
    return;

  if (HIWORD(Title))
    delete [] Title;

  int titleLength = GetWindowTextLength();
  if (titleLength < 0)
    Title = strnewdup((const char far*)"");

  else {
    Title = new far char[titleLength + 1];
    Title[0] = 0;
    Title[titleLength] = 0;
    GetWindowText(Title, titleLength + 1);
  }
}

//$---------------------------------------------------------------------------
//
// copy over the styles, the coordinates & the id from the existing HWnd into
// the owl TWindow members.
// Note: the title is not copied here
//
void
TWindow::GetHWndState()
{
  //
  // retrieve Attr.Style and Attr.ExStyle
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

  //
  // retrieve Attr.X, Attr.Y, Attr.W and Attr.H
  //
  TRect  wndRect;

  GetWindowRect(wndRect);
  Attr.H = wndRect.Height();
  Attr.W = wndRect.Width();

  HWND      hParent = GetParent();
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

//$---------------------------------------------------------------------------
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

  //
  // If the cursor is in our client window then set it now
  //
  if (HWindow) {
    TPoint p;
    GetCursorPos(p);
    ScreenToClient(p);
    if (GetClientRect().Contains(p))
      ::SetCursor(HCursor);
  }

  //
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
  if (!sysMenu && hPopupMenu) {
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

      // ignore separators
      //
      if (id == 0 || id == uint(-1))
        continue;

      // Skip the rest if it is the mdi child list, or system commands
      //
      if (id == IDW_FIRSTMDICHILD || id > 0xF000)
        break;

      EvCommandEnable(TMenuItemEnabler(hPopupMenu, id, HWindow, pos));
    }
  }
}

//$---------------------------------------------------------------------------
//
// not inline to avoid requiring gdiobjec.h by window.h
//
bool
TWindow::GetUpdateRgn(TRegion& region, bool erase) const
{
  return ::GetUpdateRgn(HWindow, region, erase);
}

//$---------------------------------------------------------------------------
//
//
int
TWindow::MessageBox(const char far* text,
                    const char far* caption,
                    uint            type)
{
  if (GetApplication()->BWCCEnabled()) {
    static bool FAR PASCAL(*bwccMessageBox)(HWND, LPCSTR, LPCSTR, uint);
    if (!bwccMessageBox)
      (FARPROC)bwccMessageBox =
        GetApplication()->GetBWCCModule()->GetProcAddress("BWCCMessageBox");
    if (bwccMessageBox)
      return (*bwccMessageBox)(HWindow, text, caption, type);
    return 0;
  }
  else {
    GetApplication()->EnableCtl3dAutosubclass(true);
    int retValue = ::MessageBox(HWindow, text, caption, type);
    GetApplication()->EnableCtl3dAutosubclass(false);
    return retValue;
  }
}

#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TWindow& w)
  {
    os << '(';
#if !defined(BI_NO_RTTI)
      os << typeid(w).name() << ',';
#endif
    os << "0x" << hex << (unsigned)w.HWindow << ',';
    if (!w.Parent)
      os << '\'' << TResId(w.Title) << '\'';
    else
      os << "id=" << w.GetId();
    os << ')';
    return os;
  }
#endif

//$---------------------------------------------------------------------------
//
// static member function to construct base TXOwl object
//
string
TWindow::TXWindow::Msg(TWindow* win, uint resId)
{
  bool   found;  // did we locate the string
  string rscMsg = ResourceIdToString(&found, resId);

  if (found) {
    char buf[255];

    //
    // supply title of window if we have a valid window
    //
    wsprintf(buf, rscMsg.c_str(), win && HIWORD(win->Title) ? win->Title : "");
    return string(buf);
  }
  else
    return rscMsg;
}

//$---------------------------------------------------------------------------
//
// InvalidWindow exception constructor
//
TWindow::TXWindow::TXWindow(TWindow* win, uint resId)
  : TXOwl(Msg(win, resId), resId)
{
  Window = win;
}

TWindow::TXWindow::TXWindow(const TXWindow& src) : TXOwl(src),Window(src.Window)
{
}

int
TWindow::TXWindow::Unhandled(TModule* app, unsigned promptResId)
{
  delete Window;
  Window = 0;
  return TXOwl::Unhandled(app, promptResId);
}

TXOwl*
TWindow::TXWindow::Clone()
{
  return new TXWindow(*this);
}
