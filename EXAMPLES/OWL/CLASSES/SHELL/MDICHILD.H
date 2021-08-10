//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         mdichild.h
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TShellMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------
#if !defined(mdichild_h)              // Sentry, use file only if it's not already included.
#define mdichild_h

#include "shellapp.rh"            // Definition of all resources.


//{{TMDIChild = TShellMDIChild}}
class TShellMDIChild : public TMDIChild {
  public:
    TShellMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd,
                  TShellItem* item = 0, bool shrinkToClient = false,
                  TModule* module = 0);
    virtual ~TShellMDIChild();
    bool SetIcon(HICON icon);
    bool SetIconSm(HICON icon);
};    //{{TShellMDIChild}}


#endif  // mdichild_h sentry.
