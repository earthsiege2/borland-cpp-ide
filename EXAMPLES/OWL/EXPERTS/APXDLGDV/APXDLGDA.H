//----------------------------------------------------------------------------
//  Project ApxDlgDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlgDv Application
//  FILE:         apxdlgda.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxDlgDvApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxdlgda_h)              // Sentry, use file only if it's not already included.
#define apxdlgda_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/rcntfile.h>


#include "apxdlgda.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = TSDIDecFrame}}
class TSDIDecFrame : public TDecoratedFrame {
  public:
    TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
    ~TSDIDecFrame();
};    //{{TSDIDecFrame}}


//{{TApplication = TApxDlgDvApp}}
class TApxDlgDvApp : public TApplication, public TRecentFiles {
  private:

    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxDlgDvApp();
    virtual ~TApxDlgDvApp();

    void CreateGadgets(TDockableControlBar* cb, bool server = false);
    THarbor*        ApxHarbor;

    TMailer*        ApxMail;

//{{TApxDlgDvAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxDlgDvAppVIRTUAL_END}}

//{{TApxDlgDvAppRSP_TBL_BEGIN}}
  protected:
    void EvNewView(TView& view);
    void EvCloseView(TView& view);
    void CeFileSend(TCommandEnabler& ce);
    void CmFileSend();
    void CmHelpAbout();
    void EvOwlDocument(TDocument& doc);
    int32 CmFileSelected(uint wp, int32 lp);
//{{TApxDlgDvAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxDlgDvApp);
};    //{{TApxDlgDvApp}}


#endif  // apxdlgda_h sentry.
