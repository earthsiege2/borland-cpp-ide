//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.15  $
//
// Implementation of class TApplication. This defines the basic behavior
// for ObjectWindows applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_WINDOW_RH)
# include <owl/window.rh>
#endif

#if defined(SECTION) && SECTION != 1
DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group
#endif

#if !defined(SECTION) || SECTION == 1

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlApp, 1, 0);

//
// Static members for initialization of app prior to initial construction
//
HINSTANCE  TApplication::InitHInstance;
HINSTANCE  TApplication::InitHPrevInstance;
string     TApplication::InitCmdLine;
int        TApplication::InitCmdShow;

//
// Global GetWindowPtr() message ID used for registered message
//
uint _OWLDATA GetWindowPtrMsgId = 0;

//
// Constructor for use in OwlMain(). Gets members from statics set earlier by
// a call to InitWinMainParams() in Owl's WinMain.
//
TApplication::TApplication(const char far* name, TModule*& gModule,
                           TAppDictionary* appDict)
:
  TModule(name, InitHInstance, InitCmdLine.c_str()),
  TMsgThread(TMsgThread::Current),
  XBase(0), XState(0), DocManager(0),
  Dictionary(appDict ? appDict : &::OwlAppDictionary)
{
  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication constructing @" << (void*)this);

  // Copy over values that were stashed in static members before this instance
  // was constructed.
  //
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;

  MainWindow = 0;
  BWCCOn = Ctl3dOn = false;
  BWCCModule = 0;
  Ctl3dModule = 0;
  CondemnedWindows = 0;
  CmdLine = InitCmdLine;

  Dictionary->Add(this);
  gModule = this;

#if defined(OWL2_COMPAT)
  HAccTable = 0;
#endif

  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication constructed @" << (void*)this);
}

//
// Constructor for use in user defined WinMain() when all the args are
// available
//
TApplication::TApplication(const char far* name,
                           HINSTANCE       instance,
                           HINSTANCE       prevInstance,
                           const char far* cmdLine,
                           int             cmdShow,
                           TModule*&       gModule,
                           TAppDictionary* appDict)
:
  TModule(name, instance, cmdLine),
  TMsgThread(TMsgThread::Current),
  XBase(0), XState(0), DocManager(0),
  Dictionary(appDict ? appDict : &::OwlAppDictionary)
{
  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication constructing @" << (void*)this);
  hPrevInstance = prevInstance;
  nCmdShow = cmdShow;
  MainWindow = 0;
  BWCCOn = Ctl3dOn = false;
  BWCCModule = 0;
  Ctl3dModule = 0;
  CondemnedWindows = 0;
  CmdLine = cmdLine;

  Dictionary->Add(this);
  gModule = this;

#if defined(OWL2_COMPAT)
  HAccTable = 0;
#endif

  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication constructed @" << (void*)this);
}

//
//
//
TApplication::~TApplication()
{
  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication destructing @" << (void*)this);

  DeleteCondemned();

  // Unregister ourselves from the Ctl3d DLL and/or the BWCC DLL if they are
  // loaded.
  //
  if (Ctl3dModule) {
    Ctl3dModule->Unregister(*this);
    delete Ctl3dModule;
  }
  if (BWCCModule) {
    BWCCModule->IntlTerm();
    delete BWCCModule;
  }

  // Delete the main window if still present, may be destroyed but not deleted
  // Set MainWindow to 0 first to prevent it from calling ::PostQuitMessage
  //
  TWindow* mainWindow = SetMainWindow(0);
  if (mainWindow) {
    mainWindow->Destroy();
    delete mainWindow;
  }

  delete (TStreamableBase*)DocManager;// cast to avoid ref to docmgr if not used

  // Remove this app from the application dictionary that it is in
  //
  Dictionary->Remove(this);
  delete XBase;   // remove any exception copy

  TRACEX(OwlApp, OWL_CDLEVEL, "TApplication destructed @" << (void*)this);
}

//
// Popup a mesasge box. Automatically deals with BWCC and Ctl3d if enabled for
// this app.
//
int
TApplication::MessageBox(HWND hParentWnd,
                         const char far* text,
                         const char far* caption,
                         uint            type)
{
  // Default caption to this application's name
  //
  if (!caption)
    caption = GetName();

  // If no parent is supplied need to use task modal to disable all toplevel
  // windows in this task.
  //
  if (!hParentWnd && !(type & MB_SYSTEMMODAL))
    type |= MB_TASKMODAL;

  // Use the BWCC message box if BWCC is enabled
  //
#if defined(BI_COMP_BORLANDC)
  if (BWCCEnabled() && GetBWCCModule()) {
    return GetBWCCModule()->MessageBox(hParentWnd, text, caption, type);
  }
  else
#endif
  // Otherwise, 3d-ize the message box if ctl3d is enabled
  //
#if !defined(BI_COMP_MSC)
  {
    EnableCtl3dAutosubclass(true);
    int retValue = ::MessageBox(hParentWnd, text, caption, type);
    EnableCtl3dAutosubclass(false);
    return retValue;
  }
#else
  return ::MessageBox(hParentWnd, text, caption, type);
#endif
}

//
// Handle initialization for the first executing instance of the OWL
// application. Under Win32, every app instance is treated as the first.
//
// Derived classes can override this to perform app initialization, or they
// can use the derived class constructor.
//
void
TApplication::InitApplication()
{
  TRACEX(OwlApp, 1, "TApplication::InitApplication() called @" << (void*)this);
}

//
// Handle initialization for each executing instance of the OWL application.
// Derived classes can override this to perform initialization for each
// instance.
//
// This default implementation calls InitMainWindow() to initialize the
// main window, and then if successful, creates and shows it. A
// TXInvalidMainWIndow exception is thrown if no main window is set during
// InitMainWindow()
//
void
TApplication::InitInstance()
{
  TMsgThread::InitInstance();

  TRACEX(OwlApp, 1, "TApplication::InitInstance() called @" << (void*)this);

  if (!hPrevInstance)
    InitApplication();

  InitMainWindow();

  if (MainWindow) {
    MainWindow->SetFlag(wfMainWindow);
    MainWindow->Create();
    MainWindow->ShowWindow(nCmdShow);
  }
  else
    TXInvalidMainWindow::Raise();
}

//
// Initialize the application's main window. Derived classes should override
// this to construct, initialize and set the main window using SetMainWindow().
//
// Default main window is a plain TFrameWindow with a title that is the same
// as this application's name
//
void
TApplication::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, GetName()));
}

//
// Handle termination for each executing instance of the application. Called
// at the end of a Run() with the final return status.
//
int
TApplication::TermInstance(int status)
{
  TRACEX(OwlApp, 1, "TApplication::TermInstance() called @" << (void*)this);

  return TMsgThread::TermInstance(status);
}

//
// Set (or reset) the main window. Return, but do not destroy the previous
// main window.
//
TFrameWindow*
TApplication::SetMainWindow(TFrameWindow* window)
{
  if (MainWindow) {
    MainWindow->ClearFlag(wfMainWindow);
    uint32 style = MainWindow->GetExStyle();
    if (style & WS_EX_APPWINDOW)
      MainWindow->SetExStyle(style & ~WS_EX_APPWINDOW);
  }

  TFrameWindow* oldMainWindow = MainWindow;
  MainWindow = window;

  if (MainWindow) {
    MainWindow->SetFlag(wfMainWindow);
    uint32 style = MainWindow->GetExStyle();
    if (!(style & WS_EX_APPWINDOW))
      MainWindow->SetExStyle(style | WS_EX_APPWINDOW);
  }
  return oldMainWindow;
}

//
// Set (or resets) the document manager, return the previous one if present
//
TDocManager*
TApplication::SetDocManager(TDocManager* docManager)
{
  TDocManager* oldDocManager = DocManager;
  DocManager = docManager;
  return oldDocManager;
}

#if defined(BI_MULTI_THREAD_RTL)
//
// Override TEventHandler::Dispatch() to handle multi-thread synchonization
//
TResult TApplication::Dispatch(TEventInfo& info, TParam1 p1, TParam2 p2)
{
  TApplication::TQueueLock lock(*this);
  return TEventHandler::Dispatch(info, p1, p2);
}
#endif

//
// Run this application, return when application terminates
//
// Initialize instances, create and display their main window (calls
// InitApplication for the first executing instance and calls InitInstance for
// all instances). Run the application's message loop. Each of the virtual
// functions called are expected to throw an exception if there is an error.
//
// Exceptions that are not handled, i.e. status remains non-zero, are
// propagated out of this function. Msg queue is still flushed & TermInstance
// called.
//
int
TApplication::Run()
{
  int status;
  try {
    try {
      if (!MainWindow) {
        if (!hPrevInstance)
          InitApplication();
        InitInstance();
      }
      LoopRunning = true;
      status = MessageLoop();
    }
    catch (TXOwl& x) {
      status = x.Unhandled(this, 0);
      if (status)
        throw;
    }
    catch (xmsg& x) {
      status = Error(x, 0);
      if (status)
        throw;
    }
#if !defined(BI_NO_NEW_CASTS)
    catch (Bad_cast& x) {
      status = Error(xmsg(string(typeid(x).name())), 0);
      if (status)
        throw;
    }
    catch (Bad_typeid& x) {
      status = Error(xmsg(string(typeid(x).name())), 0);
      if (status)
        throw;
    }
#endif
  }
  catch (...) {
    FlushQueue();
    LoopRunning = false;
    TermInstance(status);
    throw;
  }

  FlushQueue();

  LoopRunning = false;
  return TermInstance(status);
}

//
// Start this application and return immediately. Used for component DLLs
//
// Initializes instances, creating and displaying their main window (calls
// InitApplication for the first executing instance and calls InitInstance for
// all instances). Each of the virtual functions called are expected to throw
// an exception if there is an error. Does not run message loop.
//
int
TApplication::Start()
{
  int status = 0;
  TRY {
    if (!hPrevInstance)
      InitApplication();
    InitInstance();
  }
  CATCH( (TXOwl& x) {status = x.Unhandled(this, 0);})
  CATCH( (xmsg& x) {status = Error(x, 0);})
#if !defined(BI_NO_NEW_CASTS)
  CATCH( (Bad_cast& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )
  CATCH( (Bad_typeid& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )
#endif

  return status;
}

//
// General message loop: retrieves and processes messages from the OWL
// application's message queue using PumpWaitingMessages() until
// BreakMessageLoop becomes true. Catches and defers to handlers a number of
// exceptions.
//
// Call IdleAction() when there are no messages
//
int
TApplication::MessageLoop()
{
  long idleCount = 0;

  MessageLoopResult = 0;
  while (!BreakMessageLoop) {      
    try {
      if (!IdleAction(idleCount++))
        ::WaitMessage();             // allow system to go idle
      if (PumpWaitingMessages())     // pumps any waiting messages
        idleCount = 0;
    }
    catch (TXOwl& x) {
      MessageLoopResult = x.Unhandled(this, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    }
    catch (xmsg& x) {
      MessageLoopResult = Error(x, 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    }
#if !defined(BI_NO_NEW_CASTS)
    catch (Bad_cast& x) {
      MessageLoopResult = Error(xmsg(string(typeid(x).name())), 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    }
    catch (Bad_typeid& x) {
      MessageLoopResult = Error(xmsg(string(typeid(x).name())), 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    }
  }
#endif
  BreakMessageLoop = false;
  return MessageLoopResult;
}

//
// Called each time there are no messages in the queue. Idle count is
// incremented each time, & zeroed when messages are pumped. Return
// whether or not more processing needs to be done.
//
// Default behavior is to give the main window an opportunity to do idle
// processing by invoking its IdleAction() member function when
// "idleCount" is 0
//
bool
TApplication::IdleAction(long idleCount)
{
  TRACEX(OwlApp, 1, "TApplication::IdleAction() called @" << (void*)this <<
                    " idleCount " << idleCount);
  if (MainWindow)
    return MainWindow->IdleAction(idleCount);
  return false;
}

//
// Called for each message that is pulled from the queue, to perform all
// translation & dispatching.
// dispatched.
// Return true to drop out of pump
//
bool
TApplication::ProcessMsg(MSG& msg)
{
  // Let the app preprocess the message. If it is not eaten, then translate
  // it, & dispatch it. If no HWND, then first find/dispatch it directly
  // to the app (for PostAppMessage() functionality)
  //
  if (!ProcessAppMsg(msg)) {
    ::TranslateMessage(&msg);
    if (!msg.hwnd) {
      TEventInfo cmdEventInfo(msg.message, msg.wParam);
      if (Find(cmdEventInfo)) {
        Dispatch(cmdEventInfo, msg.wParam, msg.lParam);
        return true;
      }
      else {
        TEventInfo eventInfo(msg.message);
        if (Find(eventInfo)) {
          Dispatch(eventInfo, msg.wParam, msg.lParam);
          return true;
        }
      }
    }
    ::DispatchMessage(&msg);
    DeleteCondemned();
    ResumeThrow();
  }
  return false;
}

//
// Called after each message is pulled from the queue, and before it is
// dispatched. Return true if the message was handled completely here.
//
bool
TApplication::ProcessAppMsg(MSG& msg)
{
  // Start with the window that the event was destined for and allow it
  // and its parent (and its parent...) an opportunity to preprocess the
  // event
  //
  for (HWND hWnd = msg.hwnd; hWnd; hWnd = ::GetParent(hWnd)) {
#if defined(BI_PLAT_WIN32)
    // NT seems very picky about calls to ::GetWindowThreadProcessId
    // with the HWND of the desktop. Hence we'll abort this loop
    // when encountering the desktop.
    // Dealing with the ComboLBox
    //
    static HWND deskTopHwnd = ::GetDesktopWindow();
    if (hWnd == deskTopHwnd)
      break;
#endif

    TWindow*  win = GetWindowPtr(hWnd);

    if (win && win->PreProcessMsg(msg))
      return true;
  }

#if defined(OWL2_COMPAT)
  // For compatability with OWL 1.0, check the application's accelerator
  // table if it is being used.
  //
  if (HAccTable && MainWindow)
    return ::TranslateAccelerator(MainWindow->GetHandle(), HAccTable, &msg);
#endif

  return false;
}

//
// Should call this after each message dispatch when TApplication's message
// loop is not being used.
//
void
TApplication::PostDispatchAction()
{
  DeleteCondemned();
  ResumeThrow();

  MSG msg;
  if (!::PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE))
    IdleAction(0);
}

#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
//
// Suspend throw functions store away a caught exception to allow foreign code
// to be re-entered. Call ResumeThrow() to rethrow the exception, if any, upon
// return from the foreign code.
//

//
// Save off xalloc information to be rethrown later
//
void
TApplication::SuspendThrow(xalloc& x)
{
  XString = x.why();
  XSize   = x.requested();
  XState |= xsAlloc;
}

//
// Save off xmsg information to be rethrown later
//
void
TApplication::SuspendThrow(xmsg& x)
{
  XString = x.why();
  XState |= xsMsg;
}

//
// Save off a copy of a TXBase object to be rethrown later
//
void
TApplication::SuspendThrow(TXBase& x)
{
  delete XBase;       // Remove any previous exception
  XBase = x.Clone();
  XState |= xsBase;
}

//
// Sets bit flag to log exception
//
void
TApplication::SuspendThrow(int flag)
{
  XState |= (flag & (xsBadCast | xsBadTypeid | xsUnknown));
}

//
// Check and rethrows suspended exceptions if one exists, otherwise does
// nothing
//
void
TApplication::ResumeThrow()
{
  if (XState) {
    if (XState & xsBase) {
      XState &= ~xsBase;
      XBase->Throw();  // must be deleted later
    }
    if (XState & xsAlloc) {
      XState &= ~xsAlloc;
      THROW( xalloc(XString,XSize) );
    }
    if (XState & xsMsg) {
      XState &= ~xsMsg;
      THROW( xmsg(XString) );
    }
    if (XState & xsUnknown) {
      XState &= ~xsUnknown;
      THROW( xmsg(string()) );
    }
#if !defined(BI_NO_NEW_CASTS)
    if (XState & xsBadCast) {
      XState &= ~xsBadCast;
      THROW( Bad_cast() );
    }
    if (XState & xsBadTypeid) {
      XState &= ~xsBadTypeid;
      THROW( Bad_typeid() );
    }
#endif
  }
}
#endif  // #if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)

DEFINE_RESPONSE_TABLE_ENTRIES(TApplication)
  EV_COMMAND(CM_EXIT, CmExit),
END_RESPONSE_TABLE;

//
// Close down main window if application receives a CM_EXIT command.
//
void
TApplication::CmExit()
{
  TFrameWindow* frame = GetMainWindow();
  if (frame) {
    frame->CloseWindow();
    DeleteCondemned();
  }
}

//
// TApplication defers event handling to DocManager first if one has been
// installed.
//
bool
TApplication::Find(TEventInfo &eventInfo, TEqualOperator equal)
{
  // Doc manager gets a chance to handle the event first
  //
  bool retVal = DocManager ? DocManager->Find(eventInfo, equal) : false;
  if (retVal == false) {
    eventInfo.Object = (GENERIC*)this;
    retVal = SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||
             TEventHandler::Find(eventInfo, equal);
  }
  return retVal;
}

//
// Determine whether the application can be closed.
// Makes sure the MainWindow can close & doc manager can close.
//
bool
TApplication::CanClose()
{
  TEventInfo eventInfo(WM_OWLCANCLOSE);
  return (!MainWindow || MainWindow->CanClose())
      && (!DocManager ||!DocManager->Find(eventInfo)
                      || DocManager->Dispatch(eventInfo, 0, 0));
}

//
// Called by the main window to provide an oportunity to preprocess the main
// window's menubar before it is installed.
// Normally delegated to the doc manager to install a file menu as needed
//
void
TApplication::PreProcessMenu(HMENU hMenubar)
{
  TEventInfo eventInfo(WM_OWLPREPROCMENU);
  if (DocManager && DocManager->Find(eventInfo)) {
    DocManager->Dispatch(eventInfo, TParam1(hMenubar), 0);
    MainWindow->DrawMenuBar();
  }
}

//
// Condemn a window to be deleted the at the next available safe time.
// Adds the window to a normal single linked list
//
// Condemned windows should be removed if they are destructed in the mean time
// thru some other mechanism (i.e. stack, aggregate, etc)
//
void
TApplication::Condemn(TWindow* win)
{
  TRACEX(OwlApp, 1, "Condemning window @" << (void*)win << *win);
  win->SetParent(0);
  win->SetNext(CondemnedWindows);
  CondemnedWindows = win;
}

//
// Remove a condemned window from the list.
//
void
TApplication::Uncondemn(TWindow* win)
{
  if (win && CondemnedWindows) {
    TWindow* w = 0;
    if (CondemnedWindows != win)
      for (w = CondemnedWindows; w->Next() != win; w = w->Next())
        if (!w->Next())
          return;

    TRACEX(OwlApp, 1, "Uncondemning window @" << (void*)win << *win);
    if (w)
      w->SetNext(win->Next());
    else
      CondemnedWindows = win->Next();
  }
}

//
// Walk the condemned window list & delete each window. Assumes that the
// windows were constructed using 'new'
//
void
TApplication::DeleteCondemned()
{
  while (CondemnedWindows) {
    TRACEX(OwlApp, 1, "Deleting condemned window @" << CondemnedWindows << *CondemnedWindows);
    TWindow* next = CondemnedWindows->Next();
    delete CondemnedWindows;
    CondemnedWindows = next;
  }
}

//----------------------------------------------------------------------------

//
//
//
TXInvalidMainWindow::TXInvalidMainWindow()
:
  TXOwl(IDS_INVALIDMAINWINDOW)
{
}

#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXInvalidMainWindow*
#endif
TXInvalidMainWindow::Clone()
{
  return new TXInvalidMainWindow(*this);
}

//
//
//
void
TXInvalidMainWindow::Throw()
{
  THROW( *this );
}

//
// Throws a TXInvalidMainWindow exception.
//
void
TXInvalidMainWindow::Raise()
{
  TXInvalidMainWindow().Throw();
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 2

struct TEnumInfo {
  HWND      ModalWnd; // The window being made modal if needed
  short     Count;    // Count of windows in Wnds below
  HWND*     Wnds;     // list of windows that were disabled
};
static TEnumInfo* stackTop = 0; // points to topmost enuminfo in BeginModal calls

//
// Enum[Thread/Task]Windows callback. Counts or disables given window based on
// whether or not window list has been allocated yet.
//
static bool CALLBACK OWL_EXPORT16
disableWnds(HWND hWnd, TEnumInfo far* ei)
{
  if (!(::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD)) {
    if (hWnd != ei->ModalWnd && ::IsWindowEnabled(hWnd)) {
      if (!ei->Wnds) {
        ei->Count++;  // no buffer yet, we are just counting
      }
      else {
        *(ei->Wnds++) = hWnd;
        ::EnableWindow(hWnd, false);
      }
    }
  }
  return true;
}

//
// Terminate the modal state initiated by BeginModal. Needs topmost ei block,
// and cleans the block up as needed inorder to be safe to be called twice.
//
static void termModal(TEnumInfo& ei)
{
  // Re-enable window(s) that are disabled in BeginModal()
  //
  if (ei.Wnds) {
    for (HWND* hWnd = ei.Wnds; *hWnd; hWnd++)
      ::EnableWindow(*hWnd, true);
    delete[] ei.Wnds;
    ei.Wnds = 0;
  }
  else {
    if (ei.ModalWnd && IsWindow(ei.ModalWnd)) {
      ::EnableWindow(ei.ModalWnd, true);
      ei.ModalWnd = 0;
    }
  }
}

//
// Go modal and enter a message loop until a quit message goes by.
// the flag values determine how window is used:
//
//   MB_APPLMODAL -   window is the owner to disable (if 0, none are disabled)
//   MB_TASKMODAL -   window is the window to make modal,
//                    all other top level windows are disabled
//   MB_SYSTEMMODAL - window is the window to make system modal
//
// return -1 on errors
//
int
TApplication::BeginModal(TWindow* window, int flags)
{
  TEnumInfo  ei = { 0, 0, 0 };
  TEnumInfo* lastStackTop = stackTop; // keep last stackTop to restore later
  stackTop = &ei;                     // point stackTop to topmost ei

  // Set modal state
  //
  if (flags & MB_TASKMODAL) {

    if (window)
      ei.ModalWnd = window->GetHandle();  // don't disable the modal window if exists

    // Count windows to disable
    //
#if defined(BI_PLAT_WIN32)
    if (!EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)disableWnds,
                           TParam2((TEnumInfo far*)&ei)))
      return -1;
#else
    if (!EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)disableWnds,
                         TParam2((TEnumInfo far*)&ei)))
      return -1;
#endif

    // Allocate list of windows to disable, disable windows that are
    // enabled and then stuff them into the list.
    //
    HWND* hWnds = ei.Wnds = new HWND[ei.Count + 1];
    memset(ei.Wnds, 0, sizeof(TModule::THandle)*(ei.Count + 1));

#if defined(BI_PLAT_WIN32)
    EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)disableWnds,
                      TParam2((TEnumInfo far*)&ei));
#else
    EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)disableWnds,
                    TParam2((TEnumInfo far*)&ei));
#endif

    ei.Wnds = hWnds;  // restore alloc'd pointer since enumerator bumps it
  }
#if defined(BI_PLAT_WIN16)
  else if (flags & MB_SYSTEMMODAL)
    window->SetSysModalWindow();
#endif

  //
  //    MB_APPMODAL. However, the semantics of 'window' differs between
  //    16-bit and 32-bit: In 16-bit 'window' refers to the window itself.
  //    In 32-bit, 'window' would have to be the parent since we fall
  //    thru' to MB_APPMODAL. Maybe we should consider updating the logic
  //    to have MB_SYTEMMODAL default to MB_TASKMODAL in 32-bit mode...
  //    This inconsistency is illustrated by the MODALWIN example: selecting
  //    'SystemModal' two or three times behaves differently in 16 and 32
  //    bit...
  //
  else if (window) {
    ei.ModalWnd = window->GetHandle();  // remember who to re-enable later
    CHECK(ei.ModalWnd);
    window->EnableWindow(false);
  }

  // Enter message loop, saving & restoring the current status & getting the
  // returned result.
  //
  int result;
  TRY {
    result = MessageLoop();
  }
  CATCH( (...) {
    termModal(ei);
    stackTop = lastStackTop;
    RETHROW;
  })
  stackTop = lastStackTop;
  termModal(ei);            // just in case termModal was missed in EndModal

  // Return the result from the modal window's EndModal call
  //
  return result;
}

//
// Cause the current modal message loop to break and have it return a result
// Re-enable the disabled windows here, if the EnumInfo is available.
//
void
TApplication::EndModal(int result)
{
  MessageLoopResult = result;
  BreakMessageLoop = true;
  if (stackTop)
    termModal(*stackTop);
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 3

//
// Predefined DLLs that TApplication knows how to find.
//
#if defined(BI_PLAT_WIN32)
  const char BwccDllName[]  = "BWCC32.DLL";
  const char Ctl3dDllName[] = "CTL3D32.DLL";
#elif defined(BI_PLAT_WIN16)
  const char BwccDllName[]  = "BWCC.DLL";
  const char Ctl3dDllName[] = "CTL3DV2.DLL";
#endif

//
// Load the BWCC DLL if needed & set the BWCC on flag according to 'enable'
// Library is not free'd on disable to reduce re-loads if enabling on the fly
//
void
TApplication::EnableBWCC(bool enable, uint language)
{
  if (enable) {
    if (!BWCCModule) {
      try {
        BWCCModule = new TBwccDll();
        BWCCModule->IntlInit(language);
        BWCCModule->Register(GetHandle());
        BWCCOn = true;
      }
      catch (...) {
      }
    }
  }
  else
    BWCCOn = false;
}

//
// Enable or disable the use of the CTL3D DLL. Loads it on demand if needed.
//
void
TApplication::EnableCtl3d(bool enable)
{
  // If we are running Win95 or NT 3.51, or newer, then ctl3d is builtin &
  // unnecessary
  //
  if (TSystem::Has3dUI())
    return;

  // Load the Ctl3d DLL if needed & register our instance
  //
  if (enable) {
    if (!Ctl3dModule) {
      try {
        Ctl3dModule = new TCtl3dDll();
        Ctl3dModule->Register(*this);
      }
      catch (...) {
        return;
      }
    }
  }
  Ctl3dOn = enable;
}

//
// Enable or disable Ctl3d's use of auto-subclassing.
//
// Caller should turn on autosubclassing before creating a non-owl dialog to
// make it 3d, & turn it off immediatly after.
//
void
TApplication::EnableCtl3dAutosubclass(bool enable)
{
  if (Ctl3dEnabled()) {
    if (enable) {
      Ctl3dModule->Register(*this);
      Ctl3dModule->AutoSubclass(*this);
    }
    else {
      Ctl3dModule->Unregister(*this);
    }
  }
}

//
// Load the BWCC DLL dynamically.
// Bind the member functions to the exported functions.
//
TBwccDll::TBwccDll()
:
  TModule(BwccDllName, true, true),

  IntlInit(*this, "BWCCIntlInit"),
  Register(*this, "BWCCRegister"),
  IntlTerm(*this, "BWCCIntlTerm"),

  SpecialLoadDialog(*this, "SpecialLoadDialog"),
  MangleDialog(*this, "MangleDialog"),
  DefDlgProc(*this, "BWCCDefDlgProc"),
  DefGrayDlgProc(*this, "BWCCDefGrayDlgProc"),
  DefWindowProc(*this, "BWCCDefWindowProc"),
  DefMDIChildProc(*this, "BWCCDefMDIChildProc"),
  MessageBox(*this, "BWCCMessageBox"),
  GetPattern(*this, "BWCCGetPattern"),
  GetVersion(*this, "BWCCGetVersion")
{
}

//
// Load the Ctl3d DLL dynamically.
// Bind the member functions to the exported functions.
//
TCtl3dDll::TCtl3dDll()
:
  TModule(Ctl3dDllName, true, true),

  Register(*this, "Ctl3dRegister"),
  Unregister(*this, "Ctl3dUnregister"),
  AutoSubclass(*this, "Ctl3dAutoSubclass"),
  CtlColorEx(*this, "Ctl3dCtlColorEx"),
  SubclassDlg(*this, "Ctl3dSubclassDlg"),
  SubclassDlgEx(*this, "Ctl3dSubclassDlgEx"),
  GetVer(*this, "Ctl3dGetVer"),
  Enabled(*this, "Ctl3dEnabled"),
  ColorChange(*this, "Ctl3dColorChange"),
  SubclassCtl(*this, "Ctl3dSubclassCtl"),
  DlgFramePaint(*this, "Ctl3dDlgFramePaint"),
  WinIniChange(*this, "Ctl3dWinIniChange")
{
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 4

#if !defined(BI_NO_OBJ_STREAMING)

// Broken apart: IMPLEMENT_STREAMABLE1(TApplication, TModule);
// to replace the ctor
//
IMPLEMENT_STREAMABLE_CLASS(TApplication);
IMPLEMENT_CASTABLE1(TApplication, TModule);
IMPLEMENT_STREAMER(TApplication);
IMPLEMENT_STREAMABLE_POINTER(TApplication)

// IMPLEMENT_STREAMABLE_CTOR1(TApplication, TModule), plus TMsgThread init
//
TApplication::TApplication(StreamableInit)
:
  TModule(streamableInit),
  TMsgThread(TMsgThread::Current)
{
}

//
//
//
void*
TApplication::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TApplication* o = GetObject();
  if (o != ::Module)
    is >> *::Module;   // set reference to OWL module
  return o;
}

//
//
//
void
TApplication::Streamer::Write(opstream& os) const
{
  TApplication* o = GetObject();
  if (o != ::Module)
    os << *::Module;    // write out reference to OWL module, no data written
}

#else

IMPLEMENT_STREAMABLE1(TApplication, TModule);

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif  // SECTION
