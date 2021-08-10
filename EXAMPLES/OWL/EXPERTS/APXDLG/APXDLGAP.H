//----------------------------------------------------------------------------
//  Project ApxDlg
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlg Application
//  FILE:         apxdlgap.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxDlgApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxdlgap_h)              // Sentry, use file only if it's not already included.
#define apxdlgap_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/opensave.h>


#include "apxdlgap.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = TSDIDecFrame}}
class TSDIDecFrame : public TDecoratedFrame {
  public:
    TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
    ~TSDIDecFrame();

//{{TApxDlgAppVIRTUAL_BEGIN}}
  public:
    virtual void SetupWindow();
//{{TApxDlgAppVIRTUAL_END}}
};    //{{TSDIDecFrame}}


//{{TApplication = TApxDlgApp}}
class TApxDlgApp : public TApplication {
  private:

    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxDlgApp();
    virtual ~TApxDlgApp();

    THarbor*        ApxHarbor;

//{{TApxDlgAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxDlgAppVIRTUAL_END}}

//{{TApxDlgAppRSP_TBL_BEGIN}}
  protected:
    void CmHelpAbout();
//{{TApxDlgAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxDlgApp);
};    //{{TApxDlgApp}}


#endif  // apxdlgap_h sentry.
