//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         shellapp.h
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TShellApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(shellapp_h)
#define shellapp_h

#include <classlib/bags.h>
#include <owl/decmdifr.h>

#include "mdiclien.h"


#include "shellapp.rh"
//{{TApplication = TShellApp}}
class TShellApp : public TApplication {
  private:
    void SetupSpeedBar(TDecoratedMDIFrame* frame);

  public:
    TShellApp();
    virtual ~TShellApp();

    TShellMDIClient*  MdiClient;

//{{ShellAppVIRTUAL_BEGIN}}
  public:
    virtual void InitMainWindow();
    virtual bool CanClose();
    virtual bool ProcessAppMsg(MSG& msg);
//{{ShellAppVIRTUAL_END}}

//{{ShellAppRSP_TBL_BEGIN}}
  protected:
    void CmHelpAbout();
//{{ShellAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TShellApp);
};    //{{TShellApp}}


#endif  // shellapp_h sentry.

