//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\applicat.cpp
//   Implementation of class TApplication. This defines the basic behavior
//   for ObjectWindows applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\docmanag.h>

#if defined(SECTION) && SECTION != 1
DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group
#endif

#if !defined(SECTION) || SECTION == 1

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlApp, 1, 0);

//
// Static members for initialization
//
HINSTANCE       TApplication::InitHInstance;
HINSTANCE       TApplication::InitHPrevInstance;
const char far* TApplication::InitCmdLine;
int             TApplication::InitCmdShow;

//
// Constructor for use in OwlMain(). Gets members from statics set earlier by
// a call to InitWinMainParams() in Owl's WinMain.
//
TApplication::TApplication(const char far* name, TModule*& gModule)
  : TModule(name, InitHInstance, InitCmdLine), XOwl(0),XState(0),DocManager(0)

{
  //
  // Copy over values that were stashed in static members before this instance
  // was constructed.
  //
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;

  MainWindow = 0;
  HAccTable = 0;
  BreakMessageLoop = FALSE;
  BWCCOn = Ctl3dOn = FALSE;
  BWCCModule = Ctl3dModule = 0;
  CondemnedWindows = 0;

  AddApplicationObject(this);
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
                           TModule*&       gModule)
  : TModule(name, instance, cmdLine), XOwl(0), XState(0), DocManager(0)

{
  hPrevInstance = prevInstance;
  nCmdShow = cmdShow;
  MainWindow = 0;
  HAccTable = 0;
  BreakMessageLoop = FALSE;
  BWCCOn = Ctl3dOn = FALSE;
  BWCCModule = Ctl3dModule = 0;
  CondemnedWindows = 0;
  
  AddApplicationObject(this);
  gModule = this;
}

TApplication::~TApplication()
{
  DeleteCondemned();
  
  //
  // Unregister ourselves from the Ctl3d DLL and/or the BWCC DLL if they are
  // loaded.
  //
  if (Ctl3dModule) {
    BOOL FAR PASCAL(*Ctl3dUnregister)(HANDLE);
    (FARPROC)Ctl3dUnregister = Ctl3dModule->GetProcAddress("Ctl3dUnregister");
    if (Ctl3dUnregister)
      Ctl3dUnregister(*this);
    delete Ctl3dModule;
  }
  if (BWCCModule) {
    BOOL FAR PASCAL(*bwccIntlTerm)(void);
    (FARPROC)bwccIntlTerm = BWCCModule->GetProcAddress("BWCCIntlTerm");
    if (bwccIntlTerm)
      bwccIntlTerm();
    delete BWCCModule;
  }

  //
  // Deletes main window if still present, may be destroyed but not deleted
  // Sets MainWindow to 0 to prevent calling ::PostQuitMessage
  //
  TWindow* mainWindow = SetMainWindow(0);
  if (mainWindow) {
    mainWindow->Destroy();
    delete mainWindow;
  }

  delete (TStreamableBase*)DocManager;// cast to avoid ref to docmgr if not used

  //
  // Remove ourselves from the application object list
  //
  DeleteApplicationObject();
  delete XOwl;   // remove any exception copy
}

//
// handles initialization for the first executing instance of the OWL
// application
//
void
TApplication::InitApplication()
{
}

//
// handles initialization for each executing instance of the OWL
// application
//
// creates and displays the main window
//
void
TApplication::InitInstance()
{
  InitMainWindow();

  if (MainWindow) {
    MainWindow->SetFlag(wfMainWindow);
    MainWindow->Create();
    MainWindow->Show(nCmdShow);

  } else
    THROW( TXInvalidMainWindow() );
}

//
// initialize the application's main window
//
// default main window title is the same as the applications
//
void
TApplication::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, GetName()));
}

//
// handles termination for each executing instance of the OWL
// application
//
int
TApplication::TermInstance(int status)
{
  return status;
}

//
// Sets (or resets) the main window. Returns, but does not destroy the
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

#if defined(__WIN32__)
//
// overrides TEventHandler::Dispatch() to handle multi-thread synchonization
//
LRESULT TApplication::Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp)
{
  TApplication::TAppLock Lock(*this);
  return TModule::Dispatch(info, wp, lp);
}

int TApplication::TAppMutex::NotWIN32s =
    (HIWORD(::GetVersion()) & 0x8000) == 0;
#endif

//
// default idle action is to forward the action to the main window.
//
BOOL
TApplication::IdleAction(long idleCount)
{
  if (MainWindow)
    return MainWindow->IdleAction(idleCount);
  return 0;
}

//
// initializes instances, creating and displaying their main window (calls
// InitApplication for the first executing instance and calls InitInstance for
// all instances). Runs the application's message loop. Each of the virtual
// functions called are expected to throw an exception if there is an error.
//
int
TApplication::Run()
{
  int status;
  TRY {
    if (!hPrevInstance)
      InitApplication();
    InitInstance();
    status = MessageLoop();
  }
  CATCH( (TXOwl& x) {status = x.Unhandled(this, 0);})
  CATCH( (xmsg& x) {status = Error(x, 0);})
  CATCH( (Bad_cast& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )
  CATCH( (Bad_typeid& x) {status = Error(xmsg(string(typeid(x).name())), 0);} )

  MSG msg;
  while (::PeekMessage(&msg,0,0,0,PM_NOYIELD|PM_REMOVE)
         && msg.message != WM_PAINT) ; // flush queue
  return TermInstance(status);
}

BOOL
TApplication::ProcessAppMsg(MSG& msg)
{
  // start with the window that the event was destined for and allow it
  // and its parent (and its parent...) an opportunity to preprocess the
  // event
  //
  for (HWND hWnd = msg.hwnd; hWnd; hWnd = ::GetParent(hWnd)) {
    TWindow*  win = GetWindowPtr(hWnd);

    if (win && win->PreProcessMsg(msg))
      return TRUE;
  }

  // for compatability with OWL 1.0, check the application's accelerator
  // table if it is being used
  //
  // NOTE: we should only support this for one rev...
  //
  if (HAccTable && MainWindow)
    return ::TranslateAccelerator(MainWindow->HWindow, HAccTable, &msg);

  return FALSE;
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
  if (!::PeekMessage(0, 0, 0, 0, PM_NOREMOVE))
    IdleAction(0);
}

//
// lowlevel message loop: retrieves and processes messages from the OWL
// application's message queue until it is empty
//
// calls ProcessAppMsg() to allow special handling of the message
//
BOOL
TApplication::PumpWaitingMessages()
{
  MSG  msg;
  BOOL foundOne = FALSE;

  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
    foundOne = TRUE;
    if (msg.message == WM_QUIT) {
      BreakMessageLoop = TRUE;
      MessageLoopResult = msg.wParam;
      ::PostQuitMessage(msg.wParam);  // make sure all loops exit
      break;
    }

    if (!ProcessAppMsg(msg)) {
      ::TranslateMessage(&msg);
      ::DispatchMessage(&msg);
      DeleteCondemned();
      ResumeThrow();
    }
  }
  return foundOne;
}

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
TApplication::SuspendThrow(TXOwl& x)
{
  delete XOwl;       // remove any previous exception
  XOwl = x.Clone();
  XState |= xsOwl;
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
    if (XState & xsAlloc){
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
    if (XState & xsOwl) {
      XState &= ~xsOwl;
      XOwl->Throw();  // must be deleted later
    }
  }
}

//
// general message loop: retrieves and processes messages from the OWL
// application's message queue until BreakMessageLoop becomes true
//
// calls IdleAction() when there are no messages
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
  BreakMessageLoop = FALSE;
  return MessageLoopResult;
}

//
// event handling simply defers to the DocManager if it has been installed
//
BOOL
TApplication::Find(TEventInfo &eventInfo, TEqualOperator equal)
{
  return DocManager ? DocManager->Find(eventInfo, equal) : FALSE;
}

//
// determines whether the application can be closed
// makes sure app can close & doc manager can close.
//
BOOL
TApplication::CanClose()
{
  TEventInfo eventInfo(WM_OWLCANCLOSE);
  return (!MainWindow || MainWindow->CanClose())
      && (!DocManager ||!DocManager->Find(eventInfo)
                      || DocManager->Dispatch(eventInfo, 0, 0));
}

void
TApplication::PreProcessMenu(HMENU fmenu)
{
  TEventInfo eventInfo(WM_OWLPREPROCMENU);
  if (DocManager && DocManager->Find(eventInfo)) {
    DocManager->Dispatch(eventInfo, (WPARAM)fmenu, 0);
    MainWindow->DrawMenuBar();
  }
}

void
TApplication::Condemn(TWindow* win)
{
  TRACEX(OwlApp, 1, "Condemning window: " << *win);
  win->SetParent(0);
  win->SetNext(CondemnedWindows);
  CondemnedWindows = win;
}

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
            : TXOwl(IDS_INVALIDMAINWINDOW)
{
}

TXOwl*
TApplication::TXInvalidMainWindow::Clone()
{
  return new TXInvalidMainWindow(*this);
}

void
TApplication::TXInvalidMainWindow::Throw()
{
  THROW( *this );
}

//----------------------------------------------------------------------------
#endif
#if !defined(SECTION) || SECTION == 2

struct TEnumInfo {
  short     Count;
  HWND far* Wnds;
};

BOOL far _export _pascal
DisableWnds(HWND wnd, TEnumInfo* info)
{
  if (!::GetWindowLong(wnd, GWL_STYLE) & WS_CHILD) {
    if (!info->Wnds) {
      if (::IsWindowEnabled(wnd))
        info->Count++;  // no buffer yet, we are just counting

    } else if (::IsWindowEnabled(wnd)) {
      *(info->Wnds++) = wnd;
      ::EnableWindow(wnd, FALSE);
    }
  }
  return TRUE;
}

static void termModal(HWND* wnds, TWindow* w, int flags)
{
  //
  // Re-enable window(s) that are disabled in BeginModal()
  //
  if (wnds) {
    for (HWND* wnd = wnds; *wnd; wnd++)
      ::EnableWindow(*wnd, TRUE);
    delete wnds;

  } else if (!(flags & MB_SYSTEMMODAL))
    if (w)
      w->EnableWindow(TRUE);
}

//
// Go modal and enter a message loop until a quit message goes by.
// the flag values determine how window is used:
//   MB_APPLMODAL -   window is the owner to disable (if 0, none are disabled)
//   MB_TASKMODAL -   window is ignored, all top level windows are disabled
//   MB_SYSTEMMODAL - window is the window to make system modal
// returns -1 on errors
//
int
TApplication::BeginModal(TWindow* window, int flags)
{
  TEnumInfo ei = { 0, 0 };
  HWND*     wnds = 0;

  // Set modal state
  //
  if (flags & MB_TASKMODAL) {

    // count windows to disable
    //
    #if defined(__WIN32__)
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
    ei.Wnds = wnds = new HWND[ei.Count + 1];
    memset(wnds, 0, sizeof(HWND)*(ei.Count + 1));

    #if defined(__WIN32__)
      EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)DisableWnds,
                        (LPARAM)(TEnumInfo far*)&ei);
    #else
      EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)DisableWnds,
                      (LPARAM)(TEnumInfo far*)&ei);
    #endif
  }
  #if !defined(__WIN32__)
    else if (flags & MB_SYSTEMMODAL)
      window->SetSysModalWindow();
  #endif
  else if (window)
      window->EnableWindow(FALSE);

  // Enter message loop, saving & restoring the current status & getting the
  // returned result.
  //
  int result;
  TRY {
    result = MessageLoop();
  }
  CATCH( (...) {
    termModal(wnds, window, flags);
    RETHROW;
  })
  termModal(wnds, window, flags);

  // return the result from the model window EndModal call
  //
  return result;
}

//
// Cause the current modal message loop to break and have it return a result
//
void
TApplication::EndModal(int result)
{
  MessageLoopResult = result;
  BreakMessageLoop = TRUE;
}

//----------------------------------------------------------------------------
#endif
#if !defined(SECTION) || SECTION == 3

//
// Predefined DLLs that TApplication knows how to find.
//
#if defined(__WIN32__)
  const char BwccDllName[]  = "BWCC32.DLL";
  const char Ctl3dDllName[] = "CTL3D32.DLL";
#else
  const char BwccDllName[]  = "BWCC.DLL";
  const char Ctl3dDllName[] = "CTL3DV2.DLL";
#endif

//
// Load the BWCC DLL if needed & set the BWCC on flag according to 'enable'
// Library is not free'd on disable to reduce re-loads if enabling on the fly
//
void
TApplication::EnableBWCC(BOOL enable, UINT language)
{
  if (enable) {
    if (!BWCCModule) {
      BWCCModule = new TModule(BwccDllName, TRUE);

      BOOL FAR PASCAL(*bwccIntlInit)(UINT);
      (FARPROC)bwccIntlInit = BWCCModule->GetProcAddress("BWCCIntlInit");
      if (bwccIntlInit)
        bwccIntlInit(language);

      BOOL FAR PASCAL(*bwccRegister)(HINSTANCE);
      (FARPROC)bwccRegister = BWCCModule->GetProcAddress("BWCCRegister");
      if (bwccRegister)
        bwccRegister(GetInstance());
    }
    BWCCOn = TRUE;

  } else
    BWCCOn = FALSE;
}

//
// enable or disable the use of the CTL3D DLL. Loads it if needed.
//
void
TApplication::EnableCtl3d(BOOL enable)
{
  //
  // If we are running Win4.0 or greater, then ctl3d is unnecessary
  //
  if (LOBYTE(LOWORD(GetVersion())) >= 0x04)
    return;

  //
  // Load the Ctl3d DLL if needed & register our instance
  //
  if (enable) {
    if (!Ctl3dModule) {
      Ctl3dModule = new TModule(Ctl3dDllName, TRUE);
      BOOL FAR PASCAL(*ctl3dRegister)(HANDLE);
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
TApplication::EnableCtl3dAutosubclass(BOOL enable)
{
  if (Ctl3dEnabled()) {
    if (enable) {
      BOOL FAR PASCAL(*ctl3dRegister)(HANDLE);
      (FARPROC)ctl3dRegister = Ctl3dModule->GetProcAddress("Ctl3dRegister");
      if (ctl3dRegister) {
        ctl3dRegister(*this);

        BOOL FAR PASCAL(*ctl3dAutoSubclass)(HANDLE);
        (FARPROC)ctl3dAutoSubclass = Ctl3dModule->GetProcAddress("Ctl3dAutoSubclass");
        if (ctl3dAutoSubclass)
          ctl3dAutoSubclass(*this);
      }
      
    } else {
      BOOL FAR PASCAL(*Ctl3dUnregister)(HANDLE);
      (FARPROC)Ctl3dUnregister = Ctl3dModule->GetProcAddress("Ctl3dUnregister");
      if (Ctl3dUnregister)
        Ctl3dUnregister(*this);
    }
  }
}
#endif

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
