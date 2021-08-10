//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmmdi1.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------
#if !defined(apxmmdi1_h)              // Sentry, use file only if it's not already included.
#define apxmmdi1_h

#include "apxmdapp.rh"            // Definition of all resources.


//{{TMDIChild = TApxMdiMDIChild}}
class TApxMdiMDIChild : public TMDIChild {
  public:
    TApxMdiMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient = false, TModule* module = 0);
    virtual ~TApxMdiMDIChild();
};    //{{TApxMdiMDIChild}}


#endif  // apxmmdi1_h sentry.
