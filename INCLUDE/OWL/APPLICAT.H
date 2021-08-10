//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Defines class TApplication. This defines the basic behavior
//   for OWL applications.
//----------------------------------------------------------------------------
#if !defined(OWL_APPLICAT_H)
#define OWL_APPLICAT_H

#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if defined(BI_MULTI_THREAD) && !defined(CLASSLIB_THREAD_H)
# include <classlib/thread.h>
#endif

class _OWLCLASS TWindow;
class _OWLCLASS TFrameWindow;
class _OWLCLASS TDocManager;
class _OWLCLASS TAppDictionary;

//
// Internal current event structure for windows events
//
struct TCurrentEvent {
  TWindow*  Win;
  uint      Message;
  WPARAM    WParam;
  LPARAM    LParam;
};

//
//  class TApplication
//  ----- ------------
//
class _OWLCLASS TApplication : public TModule {
  public:
    class _OWLCLASS_RTL TXInvalidMainWindow : public TXOwl {
      public:
        TXInvalidMainWindow();
       ~TXInvalidMainWindow();
        TXInvalidMainWindow* Clone();
        void Throw();
    };

    HINSTANCE     hPrevInstance;
    int           nCmdShow;

    TDocManager*  DocManager;  // will become private, use Get/SetDocManager()
    TFrameWindow* MainWindow;  // will become private, use Get/SetMainWindow()
    HACCEL        HAccTable;

    // Constructors for TApplication. Default args for the ctor allow
    // TApplication to access global pointers in the user exe/dll.
    // Default OwlAppDictionary can be overridden by passing non-0 appDict arg
    //
    TApplication(const char far* name = 0, TModule*& gModule = ::Module,
                 TAppDictionary* appDict = 0);
    TApplication(const char far* name,
                 HINSTANCE       hInstance,
                 HINSTANCE       hPrevInstance,
                 const char far* cmdLine,
                 int             cmdShow,
                 TModule*&       gModule = ::Module,
                 TAppDictionary* appDict = 0);

   ~TApplication();

    TFrameWindow*    GetMainWindow() {return MainWindow;}
    TDocManager*     GetDocManager() {return DocManager;}

    static void      SetWinMainParams(HINSTANCE       hInstance,
                                      HINSTANCE       hPrevInstance,
                                      const char far* cmdLine,
                                      int             cmdShow);

    void             GetWinMainParams();

    virtual bool     CanClose();
    virtual int      Run();
    virtual int      Start();

#if defined(BI_MULTI_THREAD)
    TMutex* GetMutex();

    class _OWLCLASS TAppMutex {
      public:
        TAppMutex();
       ~TAppMutex();
        TMutex* GetMutex();
        static int HasMutex();
      private:
        char Mutex[sizeof(TMutex)];
        static int NotWIN32s;
    };

    class _OWLCLASS TAppLock {
      public:
        TAppLock(TApplication &app);
       ~TAppLock();
        void Release();
      private:
        char AppLock[sizeof(TMutex::Lock)];
    };

    // override TEventHandler::Dispatch() to handle multi-thread
    // synchronization
    //
    virtual LRESULT  Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp = 0);
#endif

    bool             PumpWaitingMessages();  // pumps all waiting msgs
    virtual int      MessageLoop();          // Loops until break or WM_QUIT
    virtual bool     ProcessAppMsg(MSG& msg);
    void             SuspendThrow(xalloc& x); // saves xalloc exception info
    void             SuspendThrow(xmsg& x);   // saves xmsg exception info
    void             SuspendThrow(TXBase& x); // saves copy of TXBase exception
    void             SuspendThrow(int);       // set bit flag to log exception
    void             ResumeThrow(); // checks and rethrows suspended exceptions
    int              QueryThrow() {return XState;}  // return suspend flags
    enum {
      xsUnknown   = 1,
      xsBadCast   = 2,
      xsBadTypeid = 4,
      xsMsg       = 8,
      xsAlloc     = 16,
      xsBase      = 32,
      xsOwl       = 32,  // for compatibility
    };

    // Get the TWindow pointer belonging to this app given an hWnd
    //
    TWindow*         GetWindowPtr(HWND hWnd) const;

    // begin and end of a modal window's modal message loop
    //
    int              BeginModal(TWindow* window, int flags=MB_APPLMODAL);
    void             EndModal(int result);
    virtual void     PreProcessMenu(HMENU);  // called from MainWindow

    // Is this Application object running? i.e. does it own the main msg loop
    //
    bool             IsRunning() const {return Running;}

    // Dead TWindow garbage collection
    //
    void             Condemn(TWindow* win);
    void             Uncondemn(TWindow* win);

    // Call this function after each msg dispatch if TApplication's message
    // loop is not used.
    //
    void             PostDispatchAction();

    // TApplication has no event table itself, defers event handling to
    // DocManager if it has been installed.
    //
    bool             Find(TEventInfo&, TEqualOperator = 0);

    void             EnableBWCC(bool enable = true, uint language = 0);
    bool             BWCCEnabled() const {return BWCCOn;}
    TModule*         GetBWCCModule() const {return BWCCModule;}

    void             EnableCtl3d(bool enable = true);
    void             EnableCtl3dAutosubclass(bool enable);
    bool             Ctl3dEnabled() const {return Ctl3dOn;}
    TModule*         GetCtl3dModule() const {return Ctl3dModule;}

    static string&   GetCmdLine() {return InitCmdLine;}
    TCurrentEvent&   GetCurrentEvent() {return CurrentEvent;}

  protected:
    bool        BreakMessageLoop;
    int         MessageLoopResult;
    string      CmdLine;                 // string object copy of cmd line

    virtual void     InitApplication();  // "first"-instance initialization
    virtual void     InitInstance();     // each-instance initialization
    virtual void     InitMainWindow();   // init application main window
    virtual int      TermInstance(int status); // each-instance termination

    // (re)set a new main-window and DocManager either at construction or
    // sometime later
    //
    TFrameWindow*    SetMainWindow(TFrameWindow* window);
    TDocManager*     SetDocManager(TDocManager* docManager);

    // Called each time there are no messages in the queue. idle count is
    // incremented each time, & zeroed when messages are pumped. Return
    // whether or not more processing needs to be done.
    //
    // Default behavior is to give the main window an opportunity to do idle
    // processing by invoking its IdleAction() member function when
    // "idleCount" is 0
    //
    virtual bool     IdleAction(long idleCount);

  private:
    bool          BWCCOn;
    TModule*      BWCCModule;

    bool          Ctl3dOn;
    TModule*      Ctl3dModule;

    bool          Running;

#if defined(BI_MULTI_THREAD)
    TAppMutex     Mutex;
#endif
    TCurrentEvent CurrentEvent;

    static HINSTANCE  InitHInstance;
    static HINSTANCE  InitHPrevInstance;
    static string     InitCmdLine;
    static int        InitCmdShow;

    // Exception handling state
    //
    int     XState;
    string  XString;
    size_t  XSize;
    TXBase* XBase;

    // Condemned TWindow garbage collection
    //
    void             DeleteCondemned();
    TWindow*         CondemnedWindows;

    // The dictionary that this app is in
    //
    TAppDictionary*  Dictionary;

    // Hidden to prevent accidental copying or assignment
    //
    TApplication(const TApplication&);
    TApplication& operator =(const TApplication&);

  DECLARE_STREAMABLE(_OWLCLASS, TApplication, 1);
};


#if defined(BI_MULTI_THREAD)

inline TMutex *TApplication::GetMutex()
{
  return Mutex.GetMutex();
}

inline TApplication::TAppMutex::TAppMutex()
{
  if (HasMutex())
    new(Mutex)TMutex;
}

inline TApplication::TAppMutex::~TAppMutex()
{
  if (HasMutex())
    REINTERPRET_CAST(TMutex *,Mutex)->TMutex::~TMutex();
}

inline TMutex *TApplication::TAppMutex::GetMutex()
{
  if (!HasMutex())
    return 0;
  else
    return REINTERPRET_CAST(TMutex *,(char*)Mutex);
}

inline int TApplication::TAppMutex::HasMutex()
{
  return NotWIN32s;
}

inline TApplication::TAppLock::TAppLock(TApplication &app)
{
  if (TAppMutex::HasMutex())
    new(AppLock)TMutex::Lock(*app.GetMutex());
}

inline TApplication::TAppLock::~TAppLock()
{
  if (TAppMutex::HasMutex())
    REINTERPRET_CAST(TMutex::Lock*,AppLock)->TMutex::Lock::~Lock();
}

inline void TApplication::TAppLock::Release()
{
  if (TAppMutex::HasMutex())
    REINTERPRET_CAST(TMutex::Lock*,AppLock)->Release();
}

#endif

extern TWindow* GetWindowPtr(HWND, const TApplication*);
inline TWindow* TApplication::GetWindowPtr(HWND hWnd) const
{
  return ::GetWindowPtr(hWnd, this);
}

inline void TApplication::SetWinMainParams(HINSTANCE       hInstance,
                                           HINSTANCE       hPrevInstance,
                                           const char far* cmdLine,
                                           int             cmdShow)
{
  InitHInstance = hInstance;
  InitHPrevInstance = hPrevInstance;
  InitCmdLine = cmdLine;
  InitCmdShow = cmdShow;
}

inline void TApplication::GetWinMainParams()
{
  InitModule(InitHInstance, InitCmdLine.c_str());
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;
}

#endif  // OWL_APPLICAT_H
