//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxomdi1.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxOleMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------
#if !defined(apxomdi1_h)              // Sentry, use file only if it's not already included.
#define apxomdi1_h

#include "apxolapp.rh"            // Definition of all resources.


//{{TMDIChild = TApxOleMDIChild}}
class TApxOleMDIChild : public TMDIChild {
  public:
    TApxOleMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient = false, TModule* module = 0);
    virtual ~TApxOleMDIChild();
};    //{{TApxOleMDIChild}}


#endif  // apxomdi1_h sentry.
