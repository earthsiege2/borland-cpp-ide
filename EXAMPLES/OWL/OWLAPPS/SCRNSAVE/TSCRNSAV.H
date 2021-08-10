//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Windows desktop screensaver classes.
//----------------------------------------------------------------------------
#ifndef  __TSCRNSAV_H
#define  __TSCRNSAV_H

#ifndef __OWL_APPLICAT_H
  #include <owl\applicat.h>
#endif
#ifndef __OWL_FRAMEWIN_H
  #include <owl\framewin.h>
#endif

class _EXPCLASS TDialog;

class TScrnSavWindow : public TFrameWindow {
  public:
    TScrnSavWindow(TWindow* parent, const char* title, TModule* = 0);
    ~TScrnSavWindow();

    // Our own screen saver virtual
    //
    virtual void AnimateScreen() {}
    
  protected:
    
    // Override TWindow virtuals
    //
    char far* GetClassName() {return "OWLScreenSaverClass";}
    void GetWindowClass(WNDCLASS& wndClass);
    void SetupWindow();

    // Event handlers
    //
    void EvMouseMove(UINT, TPoint&);
    void EvLButtonDown(UINT, TPoint&);
    void EvRButtonDown(UINT, TPoint&);
    void EvMButtonDown(UINT, TPoint&);
    void EvActivate(UINT, BOOL, HWND);
    #if defined(__WIN32__)
      void EvActivateApp(BOOL, HANDLE);
    #else
      void EvActivateApp(BOOL, HTASK);
    #endif
    void EvKeyDown(UINT, UINT, UINT);
    void EvSysKeyDown(UINT, UINT, UINT);
    void EvSysCommand(UINT, TPoint&);

  private:
    TPoint   PrevPt;
    
  DECLARE_RESPONSE_TABLE(TScrnSavWindow);
};

class TScrnSavApp : public TApplication {
  public:
    TScrnSavApp(char far* name) : TApplication(name), ScrnSavWnd(0), 
                                  ConfigureDialog(0) {}

    void SetSpeed(int speed) {Speed = speed;}

    int  Run();

  protected:
    BOOL            Configuring;
    TDialog*        ConfigureDialog;
    TScrnSavWindow* ScrnSavWnd;

    void InitMainWindow();
    BOOL IdleAction(long);

    //
    // Virtual functions for screen save apps
    //
    virtual void InitScrnSavWindow();
    virtual void InitConfigDialog() {}

  private:
    int      Speed;
    uint32   LastTime;
};
#endif
