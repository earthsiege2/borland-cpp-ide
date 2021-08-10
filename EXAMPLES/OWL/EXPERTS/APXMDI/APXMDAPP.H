//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmdapp.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(apxmdapp_h)              // Sentry, use file only if it's not already included.
#define apxmdapp_h

#include <owl/controlb.h>
#include <owl/docking.h>
#include <owl/mailer.h>
#include <owl/opensave.h>
#include <owl/printer.h>
#include <owl/rcntfile.h>

#include <classlib/bags.h>

#include "apxmmdic.h"

#include "apxmdapp.rh"            // Definition of all resources.


//{{TApplication = TApxMdiApp}}
class TApxMdiApp : public TApplication, public TRecentFiles {
  private:

    void SetupSpeedBar(TDecoratedMDIFrame* frame);
    void AddFiles(TFileDropletList& files);
    void ProcessCmdLine(char * CmdLine);
    void RegisterInfo();
    void UnRegisterInfo();

  public:
    TApxMdiApp();
    virtual ~TApxMdiApp();

    TOpenSaveDialog::TData  FileData;                   // Data to control open/saveas standard dialog.

    TApxMdiMDIClient*  MdiClient;

    THarbor*        ApxHarbor;

    // Public data members used by the print menu commands and Paint routine in MDIChild.
    //
    TPrinter*       Printer;                            // Printer support.
    int             Printing;                           // Printing in progress.

//{{TApxMdiAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual void InitInstance();
//{{TApxMdiAppVIRTUAL_END}}

//{{TApxMdiAppRSP_TBL_BEGIN}}
  protected:
    void CmHelpAbout();
    void EvDropFiles(TDropInfo drop);
    void EvWinIniChange(char far* section);
    int32 CmFileSelected(uint wp, int32 lp);
//{{TApxMdiAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiApp);
};    //{{TApxMdiApp}}


#endif  // apxmdapp_h sentry.
