//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TApplication. This defines the basic behavior
//   for ObjectWindows applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/docmanag.h>
#include <owl/appdict.h>

#if defined(SECTION) && SECTION != 1
DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group
#endif

#if !defined(SECTION) || SECTION == 1

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlApp, 1, 0);

//
// Static members for initialization
//
HINSTANCE  TApplication::InitHInstance;
HINSTANCE  TApplication::InitHPrevInstance;
string     TApplication::InitCmdLine;
int        TApplication::InitCmdShow;

//
// Global GetWindowPtr() message id used for registered message
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
  XBase(0), XState(0), DocManager(0),
  Dictionary(appDict ? appDict : &::OwlAppDictionary)
{
  // Copy over values that were stashed in static members before this instance
  // was constructed.
  //
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;

  MainWindow = 0;
  HAccTable = 0;
  BreakMessageLoop = false;
  BWCCOn = Ctl3dOn = false;
  BWCCModule = Ctl3dModule = 0;
  Running = false;
  CondemnedWindows = 0;
  CmdLine = InitCmdLine;

  Dictionary->Add(this);
  gModule = this;
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
  XBase(0), XState(0), DocManager(0),
  Dictionary(appDict ? appDict : &::OwlAppDictionary)
{
  hPrevInstance = prevInstance;
  nCmdShow = cmdShow;
  MainWindow = 0;
  HAccTable = 0;
  BreakMessageLoop = false;
  BWCCOn = Ctl3dOn = false;
  BWCCModule = Ctl3dModule = 0;
  Running = false;
  CondemnedWindows = 0;
  CmdLine = cmdLine;
  
  Dictionary->Add(this);
  gModule = this;
}

//
//
//
TApplication::~TApplication()
{
  DeleteCondemned();
  
  // Unregister ourselves from the Ctl3d DLL and/or the BWCC DLL if they are
  // loaded.
  //
  if (Ctl3dModule) {
    bool FAR PASCAL(*Ctl3dUnregister)(HANDLE);
    (FARPROC)Ctl3dUnregister = Ctl3dModule->GetProcAddress("Ctl3dUnregister");
    if (Ctl3dUnregister)
      Ctl3dUnregister(*this);
    delete Ctl3dModule;
  }
  if (BWCCModule) {
    bool FAR PASCAL(*bwccIntlTerm)(void);
    (FARPROC)bwccIntlTerm = BWCCModule->GetProcAddress("BWCCIntlTerm");
    if (bwccIntlTerm)
      bwccIntlTerm();
    delete BWCCModule;
  }

  // Delete the main window if still present, may be destroyed but not deleted
  // Set MainWindow to 0 to prevent calling ::PostQuitMessage
  //
  TWindow* mainWindow = SetMainWindow(0);
  if (mainWindow) {
    mainWindow->Destroy();
    delete mainWindow;
  }

  delete (TStreamableBase*)DocManager;// cast to avoid ref to docmgr if not used

  // Remove ourselves from the application dictionary that we are in
  //
  Dictionary->Remove(this);
  delete XBase;   // remove any exception copy
}

//
// Handle initialization for the first executing instance of the OWL
// application
//
void
TApplication::InitApplication()
{
}

//
// Handle initialization for each executing instance of the OWL
// application
//
// This implementation creates and displays the main window
//
void
TApplication::InitInstance()
{
  InitMainWindow();

  if (MainWindow) {
    MainWindow->SetFlag(wfMainWindow);
    MainWindow->Create();
    MainWindow->Show(nCmdShow);
  }
  else
    THROW( TXInvalidMainWindow() );
}

//
// Initialize the application's main window
//
// Default main window title is the same as the applications
//
void
TApplication::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, GetName()));
}

//
// Handle termination for each executing instance of the application
//
int
TApplication::TermInstance(int status)
{
  return status;
}

//
// Set (or reset) the main window. Returns, but does not destroy the
// previous main window.
//
TFrameWindow*
TApplication::SetMainWindow(TFrameWindow* window)
{
  if (MainWindow)
    MainWindow->ClearFlag(wfMainWindow);
  TFrameWindow* oldMainWindow = MainWindow;
  MainWindow = window;
  if (MainWindow)
    MainWindow->SetFlag(wfMainWindow);
  return oldMainWindow;
}

//
// Sets (or resets) the document manager, returns the previous one if present
//
TDocManager*
TApplication::SetDocManager(TDocManager* docManager)
{
  TDocManager* oldDocManager = DocManager;
  DocManager = docManager;
  return oldDocManager;
}

#if defined(BI_PLAT_WIN32)
//
// overrides TEventHandler::Dispatch() to handle multi-thread synchonization
//
LRESULT TApplication::Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp)
{
  TApplication::TAppLock Lock(*this);
  return TModule::Dispatch(info, wp, lp);
}

int TApplication::TAppMutex::NotWIN32s =
    !( (::GetVersion()&0x80000000) && (::GetVersion()&0xFF) < 4);
#endif

//
// default idle action is to forward the action to the main window.
//
bool
TApplication::IdleAction(long idleCount)
{
  if (MainWindow)
    return MainWindow->IdleAction(idleCount);
  return 0;
}

//
// Run this application, return when finished
//
// Initializes instances, creating and displaying their main window (calls
// InitApplication for the first executing instance and calls InitInstance for
// all instances). Runs the application's message loop. Each of the virtual
// functions called are expected to throw an exception if there is an error.
//
int
TApplication::Run()
{
  int status;
  TRY {
    if (!MainWindow) {
      if (!hPrevInstance)
        InitApplication();
      InitInstance();
    }
    Running = true;
    status = MessageLoop();
  }
  CATCH( (TXOwl& x) {status = x.Unhandled(this, 0);})
  CATCH( (xmsg& x) {status = Error(x, 0);})
  CATCH( (Bad_cast& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )
  CATCH( (Bad_typeid& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )

  MSG msg;
  while (::PeekMessage(&msg,0,0,0,PM_NOYIELD|PM_REMOVE)
         && msg.message != WM_PAINT) ; // flush queue

  Running = false;
  return TermInstance(status);
}

//
// Start this application and return immediately
//
// Initializes instances, creating and displaying their main window (calls
// InitApplication for the first executing instance and calls InitInstance for
// all instances). Each of the virtual functions called are expected to throw an
// exception if there is an error. Does not run message loop.
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
  CATCH( (Bad_cast& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )
  CATCH( (Bad_typeid& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )

  return status;
}

//
// Called after each message is pulled from the queue, and before it is
// dispatched. Return true if the message was handled completely here.
//
bool
TApplication::ProcessAppMsg(MSG& msg)
{
  // start with the window that the event was destined for and allow it
  // and its parent (and its parent...) an opportunity to preprocess the
  // event
  //
  for (HWND hWnd = msg.hwnd; hWnd; hWnd = ::GetParent(hWnd)) {
    TWindow*  win = GetWindowPtr(hWnd);

    if (win && win->PreProcessMsg(msg))
      return true;
  }

  // for compatability with OWL 1.0, check the application's accelerator
  // table if it is being used
  //
  // NOTE: we should only support this for one rev...
  //
  if (HAccTable && MainWindow)
    return ::TranslateAccelerator(MainWindow->HWindow, HAccTable, &msg);

  return false;
}

//
// Called after each message dispatch when TApplication's message loop is not
// being used.
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

//
// Lowlevel message loop: retrieves and processes messages from the OWL
// application's message queue until it is empty
//
// calls ProcessAppMsg() to allow special pre-handling of the message
//
bool
TApplication::PumpWaitingMessages()
{
  MSG  msg;
  bool foundOne = false;

  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
    foundOne = true;
    if (msg.message == WM_QUIT) {
      BreakMessageLoop = true;
      MessageLoopResult = msg.wParam;
      ::PostQuitMessage(msg.wParam);  // make sure all loops exit
      break;
    }

    // Let the app preprocess the message. If it is not eaten, then translate
    // it, & dispatch it. If no hwnd, then first find/dispatch it directly to
    // the app (for PostAppMessage() functionality)
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
  }
  return foundOne;
}

//
// Suspend throw functions store away a caught exception to allow foreign code
// to be re-entered. Call ResumeThrow() to rethrow the exception, if any, upon
// return from the foreign code.
//
void
TApplication::SuspendThrow(xalloc& x)
{
  XString = x.why();
  XSize   = x.requested();
  XState |= xsAlloc;
}

void
TApplication::SuspendThrow(xmsg& x)
{
  XString = x.why();
  XState |= xsMsg;
}

void
TApplication::SuspendThrow(TXBase& x)
{
  delete XBase;       // remove any previous exception
  XBase = x.Clone();
  XState |= xsBase;
}

void
TApplication::SuspendThrow(int flag)
{
  XState |= (flag & (xsBadCast | xsBadTypeid | xsUnknown));
}

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
    if (XState & xsBadCast) {
      XState &= ~xsBadCast;
      THROW( Bad_cast() );
    }
    if (XState & xsBadTypeid) {
      XState &= ~xsBadTypeid;
      THROW( Bad_typeid() );
    }
  }
}

//
// General message loop: retrieves and processes messages from the OWL
// application's message queue until BreakMessageLoop becomes true
//
// Calls IdleAction() when there are no messages
//
int
TApplication::MessageLoop()
{
  long idleCount = 0;

  MessageLoopResult = 0;
  while (!BreakMessageLoop) {
    TRY {
      if (!IdleAction(idleCount++))
        ::WaitMessage();             // allow system to go idle
      if (PumpWaitingMessages())     // pumps any waiting messages
        idleCount = 0;
    }
    CATCH( (TXOwl& x) {
      MessageLoopResult = x.Unhandled(this, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    })
    CATCH( (xmsg& x) {
      MessageLoopResult = Error(x, 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    })
    CATCH( (Bad_cast& x) {
      MessageLoopResult = Error(xmsg(string(typeid(x).name())), 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    })
    CATCH( (Bad_typeid& x) {
      MessageLoopResult = Error(xmsg(string(typeid(x).name())), 0, IDS_OKTORESUME);
      if (MessageLoopResult != 0) {
        ::PostQuitMessage(MessageLoopResult);
        break;
      }
    })
  }
  BreakMessageLoop = false;
  return MessageLoopResult;
}

//
// Default event handling simply defers to the DocManager if it has been
// installed
//
bool
TApplication::Find(TEventInfo &eventInfo, TEqualOperator equal)
{
  return DocManager ? DocManager->Find(eventInfo, equal) : false;
}

//
// Determines whether the application can be closed.
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
// Oportunity to preprocess the main window's menubar before it is installed.
// Normally delegated to the doc manager to install a file menu as needed
//
void
TApplication::PreProcessMenu(HMENU fmenu)
{
  TEventInfo eventInfo(WM_OWLPREPROCMENU);
  if (DocManager && DocManager->Find(eventInfo)) {
    DocManager->Dispatch(eventInfo, (WPARAM)fmenu, 0);
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
  TRACEX(OwlApp, 1, "Condemning window: " << *win);
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
           
    TRACEX(OwlApp, 1, "Uncondemning window: " << *win);
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
    TRACEX(OwlApp, 1, "Deleting condemned window: " << *CondemnedWindows);
    TWindow* next = CondemnedWindows->Next();
    delete CondemnedWindows;
    CondemnedWindows = next;
  }
}

TApplication::TXInvalidMainWindow::TXInvalidMainWindow()
:
  TXOwl(IDS_INVALIDMAINWINDOW)
{
}

TApplication::TXInvalidMainWindow::~TXInvalidMainWindow()
{
}

TApplication::TXInvalidMainWindow*
TApplication::TXInvalidMainWindow::Clone()
{
  return new TXInvalidMainWindow(*this);
}

void
TApplication::TXInvalidMainWindow::Throw()
{
  THROW( *this );
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
bool CALLBACK __export
DisableWnds(HWND wnd, TEnumInfo far* ei)
{
  if (!(::GetWindowLong(wnd, GWL_STYLE) & WS_CHILD)) {
    if (wnd != ei->ModalWnd && ::IsWindowEnabled(wnd)) {
      if (!ei->Wnds) {
        ei->Count++;  // no buffer yet, we are just counting
      }
      else {
        *(ei->Wnds++) = wnd;
        ::EnableWindow(wnd, false);
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
  //
  // Re-enable window(s) that are disabled in BeginModal()
  //
  if (ei.Wnds) {
    for (HWND* wnd = ei.Wnds; *wnd; wnd++)
      ::EnableWindow(*wnd, true);
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
//   MB_APPLMODAL -   window is the owner to disable (if 0, none are disabled)
//   MB_TASKMODAL -   window is the window to make modal,
//                    all other top level windows are disabled
//   MB_SYSTEMMODAL - window is the window to make system modal
// returns -1 on errors
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
      ei.ModalWnd = window->HWindow;  // don't disable the modal window if exists

    // count windows to disable
    //
#if defined(BI_PLAT_WIN32)
    if (!EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)DisableWnds,
                           (LPARAM)(TEnumInfo far*)&ei))
      return -1;
#else
    if (!EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)DisableWnds,
                         (LPARAM)(TEnumInfo far*)&ei))
      return -1;
#endif

    // Allocate list of windows to disable, disable windows that are
    // enabled and then stuff them into the list.
    //
    HWND* wnds = ei.Wnds = new HWND[ei.Count + 1];
    memset(ei.Wnds, 0, sizeof(HWND)*(ei.Count + 1));

#if defined(BI_PLAT_WIN32)
    EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)DisableWnds,
                      (LPARAM)(TEnumInfo far*)&ei);
#else
    EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)DisableWnds,
                    (LPARAM)(TEnumInfo far*)&ei);
#endif

    ei.Wnds = wnds;  // restore alloc'd pointer since enumerator bumps it
  }
#if defined(BI_PLAT_WIN16)
  else if (flags & MB_SYSTEMMODAL)
    window->SetSysModalWindow();
#endif
  else if (window) {
    ei.ModalWnd = window->HWindow;  // remember who to re-enable later
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

  // return the result from the modal window's EndModal call
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
      BWCCModule = new TModule(BwccDllName, true);

      bool FAR PASCAL(*bwccIntlInit)(uint);
      (FARPROC)bwccIntlInit = BWCCModule->GetProcAddress("BWCCIntlInit");
      if (bwccIntlInit)
        bwccIntlInit(language);

      bool FAR PASCAL(*bwccRegister)(HINSTANCE);
      (FARPROC)bwccRegister = BWCCModule->GetProcAddress("BWCCRegister");
      if (bwccRegister)
        bwccRegister(GetInstance());
    }
    BWCCOn = true;
  }
  else
    BWCCOn = false;
}

//
// enable or disable the use of the CTL3D DLL. Loads it if needed.
//
void
TApplication::EnableCtl3d(bool enable)
{
  //
  // If we are running Win4.0 or greater, then ctl3d is unnecessary
  //
#if defined(BI_PLAT_WIN32)
  if ((::GetVersion()&0xFF) >= 4)
#else
  if ((::GetVersion()&0xFF) >= 3 && ((::GetVersion()>>8)&0xFF) >= 95)
#endif
    return;

  //
  // Load the Ctl3d DLL if needed & register our instance
  //
  if (enable) {
    if (!Ctl3dModule) {
      Ctl3dModule = new TModule(Ctl3dDllName, true);
      bool FAR PASCAL(*ctl3dRegister)(HANDLE);
      (FARPROC)ctl3dRegister = Ctl3dModule->GetProcAddress("Ctl3dRegister");
      if (ctl3dRegister)
        ctl3dRegister(*this);
      else {
        delete Ctl3dModule;
        Ctl3dModule = 0;
        return;   // could not register--don't change Ctl3dOn flag
      }
    }
  }
  Ctl3dOn = enable;
}

//
// enable or disable CTL3D's use of auto-subclassing. Turn on autosubclassing
// before creating a non-owl dialog to make it 3d, & turn it off immediatly
// after.
//
void
TApplication::EnableCtl3dAutosubclass(bool enable)
{
  if (Ctl3dEnabled()) {
    if (enable) {
      bool FAR PASCAL(*ctl3dRegister)(HANDLE);
      (FARPROC)ctl3dRegister = Ctl3dModule->GetProcAddress("Ctl3dRegister");
      if (ctl3dRegister) {
        ctl3dRegister(*this);

        bool FAR PASCAL(*ctl3dAutoSubclass)(HANDLE);
        (FARPROC)ctl3dAutoSubclass = Ctl3dModule->GetProcAddress("Ctl3dAutoSubclass");
        if (ctl3dAutoSubclass)
          ctl3dAutoSubclass(*this);
      }
    }
    else {
      bool FAR PASCAL(*Ctl3dUnregister)(HANDLE);
      (FARPROC)Ctl3dUnregister = Ctl3dModule->GetProcAddress("Ctl3dUnregister");
      if (Ctl3dUnregister)
        Ctl3dUnregister(*this);
    }
  }
}

#endif
//----------------------------------------------------------------------------
#if !defined(SECTION) || SECTION == 4

IMPLEMENT_STREAMABLE1(TApplication, TModule);

void*
TApplication::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TApplication* o = GetObject();
  if (o != ::Module)
    is >> *::Module;   // set reference to OWL module
  return o;
}

void
TApplication::Streamer::Write(opstream& os) const
{
  TApplication* o = GetObject();
  if (o != ::Module)
    os << *::Module;    // write out reference to OWL module, no data written
}

#endif  // SECTION
