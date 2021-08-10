//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apmdmdi1.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiDvMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------
#if !defined(apmdmdi1_h)              // Sentry, use file only if it's not already included.
#define apmdmdi1_h

#include "apxmddva.rh"            // Definition of all resources.


//{{TMDIChild = TApxMdiDvMDIChild}}
class TApxMdiDvMDIChild : public TMDIChild {
  public:
    TApxMdiDvMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient = false, TModule* module = 0);
    virtual ~TApxMdiDvMDIChild();
};    //{{TApxMdiDvMDIChild}}


#endif  // apmdmdi1_h sentry.
