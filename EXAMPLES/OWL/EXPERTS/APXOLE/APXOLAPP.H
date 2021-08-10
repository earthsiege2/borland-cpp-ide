//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxolapp.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxOleApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxolapp_h)              // Sentry, use file only if it's not already included.
#define apxolapp_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/olemdifr.h>
#include <owl/printer.h>
#include <owl/rcntfile.h>

#include <classlib/bags.h>

#include "apxomdic.h"

#include "apxolapp.rh"            // Definition of all resources.


//{{TApplication = TApxOleApp}}
class TApxOleApp : public TApplication, public TOcModule, public TRecentFiles {
  private:
    void SetupSpeedBar(TOleMDIFrame* frame);
    void AddFiles(TFileDropletList& files);
    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxOleApp();
    virtual ~TApxOleApp();

    void CreateGadgets(TControlBar *cb, bool server = false);

    TApxOleMDIClient* MdiClient;

    // Public data members used by the print menu commands and Paint routine in MDIChild.
    //
    TPrinter*       Printer;                           // Printer support.
    int             Printing;                          // Printing in progress.

    TMailer*        ApxMail;

//{{TApxOleAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxOleAppVIRTUAL_END}}

//{{TApxOleAppRSP_TBL_BEGIN}}
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
//{{TApxOleAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxOleApp);
};    //{{TApxOleApp}}


#endif  // apxolapp_h sentry.
