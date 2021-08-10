//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxsdapp.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxsdapp_h)              // Sentry, use file only if it's not already included.
#define apxsdapp_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/opensave.h>
#include <owl/printer.h>
#include <owl/rcntfile.h>

#include <classlib/bags.h>

#include "apxprint.h"
#include "apxprev.h"

#include "apxsdapp.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = TSDIDecFrame}}
class TSDIDecFrame : public TDecoratedFrame {
  public:
    TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
    ~TSDIDecFrame();
};    //{{TSDIDecFrame}}


//{{TApplication = TApxSdiApp}}
class TApxSdiApp : public TApplication, public TRecentFiles {
  private:

    void SetupSpeedBar(TDecoratedFrame* frame);
    void AddFile(const char* fileName);
    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxSdiApp();
    virtual ~TApxSdiApp();

    TOpenSaveDialog::TData FileData;                    // Data to control open/saveas standard dialog.
    void OpenFile(const char* fileName = 0);

    THarbor*        ApxHarbor;

    // Public data members used by the print menu commands and Paint routine in MDIChild.
    //
    TPrinter*       Printer;                            // Printer support.
    int             Printing;                           // Printing in progress.

//{{TApxSdiAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxSdiAppVIRTUAL_END}}

//{{TApxSdiAppRSP_TBL_BEGIN}}
  protected:
    void CmFileNew();
    void CmFileOpen();
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CmPrintEnable(TCommandEnabler& tce);
    void CmHelpAbout();
    void EvDropFiles(TDropInfo drop);
    void EvWinIniChange(char far* section);
    int32 CmFileSelected(uint wp, int32 lp);
//{{TApxSdiAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxSdiApp);
};    //{{TApxSdiApp}}


#endif  // apxsdapp_h sentry.
