//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Windows desktop screensaver classes.
//----------------------------------------------------------------------------
#ifndef  TSCRNSAV_H
#define  TSCRNSAV_H

#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif

class _OWLCLASS TDialog;

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
    void EvMouseMove(uint, TPoint&);
    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);
    void EvMButtonDown(uint, TPoint&);
    void EvActivate(uint, bool, HWND);
#if defined(BI_PLAT_WIN32)
    void EvActivateApp(bool, HANDLE);
#else
    void EvActivateApp(bool, HTASK);
#endif
    void EvKeyDown(uint, uint, uint);
    void EvSysKeyDown(uint, uint, uint);
    void EvSysCommand(uint, TPoint&);

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
    bool            Configuring;
    TDialog*        ConfigureDialog;
    TScrnSavWindow* ScrnSavWnd;

    void InitMainWindow();
    bool IdleAction(long);

    // Virtual functions for screen save apps
    //
    virtual void InitScrnSavWindow();
    virtual void InitConfigDialog() {}

  private:
    int      Speed;
    uint32   LastTime;
};

#endif
