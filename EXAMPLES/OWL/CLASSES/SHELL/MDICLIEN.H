//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         mdiclien.h
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TShellMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------
#if !defined(mdiclien_h)              // Sentry, use file only if it's not already included.
#define mdiclien_h

#include <owl/mdi.h>
#include <owl/shellitm.h>

#include "shellapp.rh"            // Definition of all resources.


//{{TMDIClient = TShellMDIClient}}
class TShellMDIClient : public TMDIClient {
  public:
    int      ChildCount;                 // Number of child window created.

    TShellMDIClient(TModule* module = 0);
    virtual ~TShellMDIClient();

    void MyFileNew(TShellItem* item = 0);

  private:
//{{ShellMDIClientVIRTUAL_BEGIN}}
  protected:
    virtual void SetupWindow();
//{{ShellMDIClientVIRTUAL_END}}

//{{ShellMDIClientRSP_TBL_BEGIN}}
  protected:
    void CmFileNew();
//{{ShellMDIClientRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TShellMDIClient);
};    //{{TShellMDIClient}}


#endif  // mdiclien_h sentry.
