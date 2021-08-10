//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\applicat.h
//   Defines class TApplication. This defines the basic behavior
//   for OWL applications.
//----------------------------------------------------------------------------
#if !defined(__OWL_APPLICAT_H)
#define __OWL_APPLICAT_H

#if !defined(__OWL_MODULE_H)
  #include <owl\module.h>
#endif
#if defined(__WIN32__) && !defined(__CLASSLIB_THREAD_H)
  #include <classlib\thread.h>
#endif

class _OWLCLASS TFrameWindow;
class _OWLCLASS TDocManager;

//
//  class TApplication
//  ----- ------------
//
class _OWLCLASS TApplication : public TModule {
  public:
    class _OWLCLASS_RTL TXInvalidMainWindow : public TXOwl {
      public:
        TXInvalidMainWindow();
        TXOwl* Clone();
        void Throw();
    };

    HINSTANCE     hPrevInstance;
    int           nCmdShow;

    TDocManager*  DocManager;  // will become private, use Get/SetDocManager()
    TFrameWindow* MainWindow;  // will become private, use Get/SetMainWindow()
    HACCEL        HAccTable;

    TApplication(const char far* name = 0, TModule*& gModule = ::Module);
    TApplication(const char far* name,
                 HINSTANCE       hInstance,
                 HINSTANCE       hPrevInstance,
                 const char far* cmdLine,
                 int             cmdShow,
                 TModule*&       gModule = ::Module);

   ~TApplication();

    TFrameWindow*    GetMainWindow() {return MainWindow;}
    TDocManager*     GetDocManager() {return DocManager;}

    static void      SetWinMainParams(HINSTANCE       hInstance,
                                      HINSTANCE       hPrevInstance,
                                      const char far* cmdLine,
                                      int             cmdShow);

    void             GetWinMainParams();

    virtual BOOL     CanClose();
    virtual int      Run();

#if defined(__WIN32__)
    TMutex *GetMutex();

    class _OWLCLASS TAppMutex {
      public:
        TAppMutex();
        ~TAppMutex();
        TMutex *GetMutex();
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

    //
    // override TEventHandler::Dispatch() to handle multi-thread
    // synchronization
    //
    virtual LRESULT  Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp = 0);
#endif

    BOOL             PumpWaitingMessages();  // pumps all waiting msgs
    virtual int      MessageLoop();          // Loops until break or WM_QUIT
    virtual BOOL     ProcessAppMsg(MSG& msg);
    void             SuspendThrow(xalloc& x); // saves xalloc exception info
    void             SuspendThrow(xmsg& x);   // saves xmsg exception info
    void             SuspendThrow(TXOwl& x);  // saves copy of TXOwl exception
    void             SuspendThrow(int);       // set bit flag to log exception
    void             ResumeThrow(); // checks and rethrows suspended exceptions
    int              QueryThrow() {return XState;}  // return suspend flags
    enum {
      xsUnknown   = 1,
      xsBadCast   = 2,
      xsBadTypeid = 4,
      xsMsg       = 8,
      xsAlloc     = 16,
      xsOwl       = 32,
    };

    //
    // begin and end of a modal window's modal message loop
    //
    int              BeginModal(TWindow* window, int flags=MB_APPLMODAL);
    void             EndModal(int result);
    virtual void     PreProcessMenu(HMENU);  // called from MainWindow

    //
    // Dead TWindow garbage collection
    //
    void             Condemn(TWindow* win);

    //
    // Call this function after each msg dispatch if TApplication's message
    // loop is not used.
    //
    void             PostDispatchAction();
  
    //
    // TApplication has no event table itself, defers event handling to 
    // DocManager if it has been installed.
    //
    BOOL  Find(TEventInfo&, TEqualOperator = 0);

    void             EnableBWCC(BOOL enable = TRUE, UINT language = 0);
    BOOL             BWCCEnabled() const {return BWCCOn;}
    TModule*         GetBWCCModule() const {return BWCCModule;}

    void             EnableCtl3d(BOOL enable = TRUE);
    void             EnableCtl3dAutosubclass(BOOL enable);
    BOOL             Ctl3dEnabled() const {return Ctl3dOn;}
    TModule*         GetCtl3dModule() const {return Ctl3dModule;}

  protected:
    BOOL        BreakMessageLoop;
    int         MessageLoopResult;

    virtual void     InitApplication();  // "first"-instance initialization
    virtual void     InitInstance();     // each-instance initialization
    virtual void     InitMainWindow();   // init application main window
    virtual int      TermInstance(int status); // each-instance termination

    //
    // (re)set a new main window either at construction or sometime later
    //
    TFrameWindow*    SetMainWindow(TFrameWindow* window);

    TDocManager*     SetDocManager(TDocManager* docManager);

    //
    // called each time there are no messages in the queue. idle count is
    // incremented each time, & zeroed when messages are pumped. Return
    // whether or not more processing needs to be done.
    //
    // default behavior is to give the main window an opportunity to do idle
    // processing by invoking its IdleAction() member function when
    // "idleCount" is 0
    //
    virtual BOOL     IdleAction(long idleCount);

  private:
    BOOL          BWCCOn;
    TModule*      BWCCModule;

    BOOL          Ctl3dOn;
    TModule*      Ctl3dModule;
    
#if defined(__WIN32__)
    TAppMutex     Mutex;
#endif
    
    static HINSTANCE       InitHInstance;
    static HINSTANCE       InitHPrevInstance;
    static const char far* InitCmdLine;
    static int             InitCmdShow;

    //
    // exception handling state
    //
    int    XState;
    string XString;
    size_t XSize;
    TXOwl* XOwl;

    //
    // Condemned TWindow garbage collection
    //
    void             DeleteCondemned();
    TWindow*         CondemnedWindows;

    //
    // hidden to prevent accidental copying or assignment
    //
    TApplication(const TApplication&);
    TApplication& operator =(const TApplication&);

  DECLARE_STREAMABLE(_OWLCLASS, TApplication, 1);
};


#if defined(__WIN32__)

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
    return REINTERPRET_CAST(TMutex *,(char *)Mutex);
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
  InitModule(InitHInstance, InitCmdLine);
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;
}

#endif  // __OWL_APPLICAT_H

