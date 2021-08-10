//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxsddva.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiDvApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxsddva_h)              // Sentry, use file only if it's not already included.
#define apxsddva_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/printer.h>
#include <owl/rcntfile.h>

#include <classlib/bags.h>


#include "apxprint.h"
#include "apxprev.h"

#include "apxsddva.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = TSDIDecFrame}}
class TSDIDecFrame : public TDecoratedFrame {
  public:
    TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
    ~TSDIDecFrame();
};    //{{TSDIDecFrame}}


//{{TApplication = TApxSdiDvApp}}
class TApxSdiDvApp : public TApplication, public TRecentFiles {
  private:

  private:
    void SetupSpeedBar(TDecoratedFrame* frame);
    void AddFile(const char* fileName);
    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxSdiDvApp();
    virtual ~TApxSdiDvApp();

    void CreateGadgets(TDockableControlBar* cb, bool server = false);
    THarbor*        ApxHarbor;

    // Public data members used by the print menu commands and Paint routine in MDIChild.
    //
    TPrinter*       Printer;                            // Printer support.
    int             Printing;                           // Printing in progress.

    TMailer*        ApxMail;

//{{TApxSdiDvAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxSdiDvAppVIRTUAL_END}}

//{{TApxSdiDvAppRSP_TBL_BEGIN}}
  protected:
    void EvNewView(TView& view);
    void EvCloseView(TView& view);
    void CeFileSend(TCommandEnabler& ce);
    void CmFileSend();
    void CmHelpAbout();
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CmPrintEnable(TCommandEnabler& tce);
    void EvDropFiles(TDropInfo drop);
    void EvWinIniChange(char far* section);
    void EvOwlDocument(TDocument& doc);
    int32 CmFileSelected(uint wp, int32 lp);
//{{TApxSdiDvAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxSdiDvApp);
};    //{{TApxSdiDvApp}}


#endif  // apxsddva_h sentry.
