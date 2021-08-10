//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apxmddva.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiDvApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxmddva_h)              // Sentry, use file only if it's not already included.
#define apxmddva_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/printer.h>
#include <owl/rcntfile.h>

#include <classlib/bags.h>

#include "apmdmdic.h"

#include "apxmddva.rh"            // Definition of all resources.


//{{TApplication = TApxMdiDvApp}}
class TApxMdiDvApp : public TApplication, public TRecentFiles {
  private:
    void SetupSpeedBar(TDecoratedMDIFrame* frame);
    void AddFiles(TFileDropletList& files);
    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxMdiDvApp();
    virtual ~TApxMdiDvApp();

    void CreateGadgets(TDockableControlBar* cb, bool server = false);
    THarbor*        ApxHarbor;

    TApxMdiDvMDIClient* MdiClient;

    // Public data members used by the print menu commands and Paint routine in MDIChild.
    //
    TPrinter*       Printer;                           // Printer support.
    int             Printing;                          // Printing in progress.

    TMailer*        ApxMail;

//{{TApxMdiDvAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxMdiDvAppVIRTUAL_END}}

//{{TApxMdiDvAppRSP_TBL_BEGIN}}
  protected:
    void EvNewView(TView& view);
    void EvCloseView(TView& view);
    void CeFileSend(TCommandEnabler& ce);
    void CmFileSend();
    void CmHelpAbout();
    void EvDropFiles(TDropInfo drop);
    void EvWinIniChange(char far* section);
    void EvOwlDocument(TDocument& doc);
    int32 CmFileSelected(uint wp, int32 lp);
//{{TApxMdiDvAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiDvApp);
};    //{{TApxMdiDvApp}}


#endif  // apxmddva_h sentry.
