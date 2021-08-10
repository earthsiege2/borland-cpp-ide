//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Definition of class TApplication. This defines the basic behavior for OWL
// applications. Also definitions for TBwccDll, TCtl3dDll, TXInvalidMainWindow
//----------------------------------------------------------------------------
#if !defined(OWL_APPLICAT_H)
#define OWL_APPLICAT_H

#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif
#if !defined(WINSYS_MSGTHRED_H)
# include <winsys/msgthred.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TWindow;
class _OWLCLASS TFrameWindow;
class _OWLCLASS TDocManager;
class _OWLCLASS TAppDictionary;
class _OWLCLASS_RTL TXInvalidMainWindow;
class _OWLCLASS TBwccDll;
class _OWLCLASS TCtl3dDll;

//
// struct TCurrentEvent
// ~~~~~~ ~~~~~~~~~~~~~
// Current event structure for windows events
//
struct TCurrentEvent {
  TWindow*  Win;      // Window that message was sent/dispatched to
  uint      Message;  // Message ID
  union {
#if defined(OWL2_COMPAT)
    TParam1 WParam;   // Old name
#endif
    TParam1 Param1;   // New name of first parameter
  };
  union {
#if defined(OWL2_COMPAT)
    TParam2 LParam;   // Old name
#endif
    TParam2 Param2;   // New name of secont parameter
  };
};

//
// class TApplication
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TApplication : virtual public TEventHandler,
                                       public TModule,
                                       public TMsgThread
{
  public:
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

    TFrameWindow*    GetMainWindow();
    TDocManager*     GetDocManager();

    static void      SetWinMainParams(HINSTANCE       hInstance,
                                      HINSTANCE       hPrevInstance,
                                      const char far* cmdLine,
                                      int             cmdShow);

    void             GetWinMainParams();

    HINSTANCE        GetPrevInstance() const;
    void             SetPrevInstance(HINSTANCE pi);

    int              GetCmdShow() const;
    void             SetCmdShow(int cmdshow);

    static string&   GetCmdLine();
    TCurrentEvent&   GetCurrentEvent();

    virtual bool     CanClose();
    virtual int      Run();
    virtual int      Start();

    // Message queue thread synchronization mechanism
    //
#if defined(BI_MULTI_THREAD_RTL)
    typedef TMsgThread::TQueueLock TAppLock;

    // Override TEventHandler::Dispatch() to handle multi-thread
    // synchronization
    //
    virtual TResult  Dispatch(TEventInfo& info, TParam1 wp, TParam2 lp = 0);
#endif

    // Message queue loop & response functions
    //
    virtual int      MessageLoop();
    virtual bool     IdleAction(long idleCount);
    virtual bool     ProcessMsg(MSG& msg);
    virtual bool     ProcessAppMsg(MSG& msg);

#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
    // Win16 / Win32s Exception propagation mechanism
    //
    void             SuspendThrow(xalloc& x);
    void             SuspendThrow(xmsg& x);
    void             SuspendThrow(TXBase& x);
    void             SuspendThrow(int);
    void             ResumeThrow();
    int              QueryThrow() const;
    enum {
      xsUnknown   = 1,
      xsBadCast   = 2,
      xsBadTypeid = 4,
      xsMsg       = 8,
      xsAlloc     = 16,
      xsBase      = 32,
#if defined(OWL2_COMPAT)
      xsOwl       = 32,  // For compatibility with Owl 2.0
#endif
    };
#endif

    // Get the TWindow pointer belonging to this app given an hWnd
    //
    TWindow*         GetWindowPtr(HWND hWnd) const;

    // Begin and end of a modal window's modal message loop
    //
    int              BeginModal(TWindow* window, int flags=MB_APPLMODAL);
    void             EndModal(int result);
    virtual void     PreProcessMenu(HMENU hMenubar);

    // Dead TWindow garbage collection
    //
    void             Condemn(TWindow* win);
    void             Uncondemn(TWindow* win);

    // Call this function after each msg dispatch if TApplication's message
    // loop is not used.
    //
    void             PostDispatchAction();

    // TApplication defers event handling to DocManager if one has been
    // installed.
    //
    bool             Find(TEventInfo&, TEqualOperator = 0);

    // Control of UI enhancing libraries
    //
    void             EnableBWCC(bool enable = true, uint language = 0);
    bool             BWCCEnabled() const;
    TBwccDll*        GetBWCCModule() const;

    void             EnableCtl3d(bool enable = true);
    void             EnableCtl3dAutosubclass(bool enable);
    bool             Ctl3dEnabled() const;
    TCtl3dDll*       GetCtl3dModule() const;

    // Open a modal message box, with appropriate BWCC or Ctl3d handling
    //
    int              MessageBox(HWND hParentWnd,
                                const char far* text,
                                const char far* caption = 0,
                                uint            type = MB_OK);

#if defined(OWL2_COMPAT)
    typedef ::TXInvalidMainWindow TXInvalidMainWindow;  // Exceptions moved to global scope
#endif

  protected:
    virtual void     InitApplication();
    virtual void     InitInstance();
    virtual void     InitMainWindow();
    virtual int      TermInstance(int status);

    // (Re)set a new main-window and DocManager either at construction or
    // sometime later
    //
    TFrameWindow*    SetMainWindow(TFrameWindow* window);
    TDocManager*     SetDocManager(TDocManager* docManager);

    // Member data -- use accessors to get at these
    //
  public_data:
    HINSTANCE     hPrevInstance;
    int           nCmdShow;
    TDocManager*  DocManager;
    TFrameWindow* MainWindow;

#if defined(OWL2_COMPAT)
    HACCEL        HAccTable;    // Obsolete, use each TWindow's
#endif

  protected_data:
    string        CmdLine;                 // string object copy of cmd line

  private:
    bool          BWCCOn;
    TBwccDll*     BWCCModule;

    bool          Ctl3dOn;
    TCtl3dDll*    Ctl3dModule;

    TCurrentEvent CurrentEvent;

#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
    // Exception handling state
    //
    int           XState;
    string        XString;
    size_t        XSize;
    TXBase*       XBase;
#endif

    // Condemned TWindow garbage collection
    //
    void             DeleteCondemned();
    TWindow*         CondemnedWindows;

    // The dictionary that this app is in
    //
    TAppDictionary*  Dictionary;

    // Static application initialization parameters cached here before app
    // is actually constructed
    //
    static HINSTANCE  InitHInstance;
    static HINSTANCE  InitHPrevInstance;
    static string     InitCmdLine;
    static int        InitCmdShow;

    // Response tables
    //
    typedef TResponseTableEntry<TApplication>::PMF TMyPMF;
    typedef TApplication                           TMyClass;

    static TResponseTableEntry<TApplication> __RTFAR __entries[];
    void CmExit();  // Exit from file menu


    // Hidden to prevent accidental copying or assignment
    //
    TApplication(const TApplication&);
    TApplication& operator =(const TApplication&);

  DECLARE_STREAMABLE(_OWLCLASS, TApplication, 1);
};

//
// class TBwccDll
// ~~~~~ ~~~~~~~~
// Wrapper for the BWCC Dll
//
class _OWLCLASS TBwccDll : public TModule {
  public:
    TBwccDll();

    // Used by TApplication
    //
    TModuleProc1<bool,uint>      IntlInit;
    TModuleProc1<bool,HINSTANCE> Register;
    TModuleProc0<bool>           IntlTerm;

    // Not used by OWL
    //
    TModuleProc3<HGLOBAL,HINSTANCE,LPCSTR,DLGPROC>  SpecialLoadDialog;
    TModuleProc3<HGLOBAL,HGLOBAL,HINSTANCE,DLGPROC> MangleDialog;
    TModuleProc4<LRESULT,HWND,UINT,WPARAM,LPARAM>   DefDlgProc;
    TModuleProc4<LRESULT,HWND,UINT,WPARAM,LPARAM>   DefGrayDlgProc;
    TModuleProc4<LRESULT,HWND,UINT,WPARAM,LPARAM>   DefWindowProc;
    TModuleProc4<LRESULT,HWND,UINT,WPARAM,LPARAM>   DefMDIChildProc;
    TModuleProc4<int,HWND,LPCSTR,LPCSTR,UINT>       MessageBox;
    TModuleProc0<HBRUSH> GetPattern;
    TModuleProc0<DWORD>  GetVersion;
};

//
// class TCtl3dDll
// ~~~~~ ~~~~~~~~~
// Wrapper for the Control 3D Dll
//
class _OWLCLASS TCtl3dDll : public TModule {
  public:
    TCtl3dDll();

    // Used by TApplication
    //
    TModuleProc1<BOOL,HANDLE> Register;
    TModuleProc1<BOOL,HANDLE> Unregister;
    TModuleProc1<BOOL,HANDLE> AutoSubclass;

    // Used by TDialog
    //
    TModuleProc3<HBRUSH,uint,WPARAM,LPARAM> CtlColorEx;
    TModuleProc2<BOOL,HWND,uint16>          SubclassDlg;

    // Not used by OWL
    //
    TModuleProc2<BOOL,HWND,DWORD> SubclassDlgEx;
    TModuleProc0<WORD> GetVer;
    TModuleProc0<BOOL> Enabled;
    TModuleProc0<BOOL> ColorChange;
    TModuleProc1<BOOL,HWND> SubclassCtl;
    TModuleProc4<LONG,HWND,UINT,WPARAM,LPARAM> DlgFramePaint;

    TModuleProc0<int> WinIniChange;
};

//
// class TXInvalidMainWindow
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class _OWLCLASS_RTL TXInvalidMainWindow : public TXOwl {
  public:
    TXInvalidMainWindow();

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXInvalidMainWindow* Clone();
#endif
    void Throw();

    static void Raise();
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations

//
// Return the current main window.
//
inline TFrameWindow* TApplication::GetMainWindow()
{
  return MainWindow;
}

//
// Return the current document manager.
//
inline TDocManager* TApplication::GetDocManager()
{
  return DocManager;
}

//
// Return the HINSTANCE of the previous running instance.
//
inline HINSTANCE TApplication::GetPrevInstance() const
{
  return hPrevInstance;
}

//
// Set the previous instance.
// This should not be called by normal programs.
//
inline void TApplication::SetPrevInstance(HINSTANCE pi)
{
  hPrevInstance = pi;
}

//
// Retrieve the initial state of the main window.
//
inline int TApplication::GetCmdShow() const
{
  return nCmdShow;
}

//
// Sets the initial state of the main window.
// Typically passed by the operating system.
//
inline void TApplication::SetCmdShow(int cmdshow)
{
  nCmdShow = cmdshow;
}

//
// Return the command line of the application.
// Most programs do not need to call this because OwlMain has the
// parameters already parsed.
//
inline string& TApplication::GetCmdLine()
{
  return InitCmdLine;
}

//
// Return the current event from the message queue.
//
inline TCurrentEvent& TApplication::GetCurrentEvent()
{
  return CurrentEvent;
}

#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
//
// Return the exception handling state.
//
inline int TApplication::QueryThrow() const
{
  return XState;
}
#endif

extern TWindow* GetWindowPtr(HWND, const TApplication*);

//
// Return the window pointer given a window's handle.
//
inline TWindow* TApplication::GetWindowPtr(HWND hWnd) const
{
  return ::GetWindowPtr(hWnd, this);
}

//
// Set the data members with data from WinMain.
//
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

//
// Retrieve the WinMain parameters.
//
inline void TApplication::GetWinMainParams()
{
  InitModule(InitHInstance, InitCmdLine.c_str());
  hPrevInstance = InitHPrevInstance;
  nCmdShow = InitCmdShow;
}

//
// Returns true if the BWCC is enabled for the application.
//
inline bool TApplication::BWCCEnabled() const
{
  return BWCCOn;
}

//
// If BWCC is enabled, return the module associated with it.
//
inline TBwccDll* TApplication::GetBWCCModule() const
{
  return BWCCModule;
}

//
// Returns true if Ctl3d is enabled.
//
inline bool TApplication::Ctl3dEnabled() const
{
  return Ctl3dOn;
}

//
// If Ctl3D is enabled, return the module associated with it.
//
inline TCtl3dDll* TApplication::GetCtl3dModule() const
{
  return Ctl3dModule;
}

#endif  // OWL_APPLICAT_H
