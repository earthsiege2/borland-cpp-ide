//----------------------------------------------------------------------------
//  Project ApxDlg
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlg Application
//  FILE:         apxdlgdc.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxDlgDlgClient (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxdlgdc_h)              // Sentry, use file only if it's not already included.
#define apxdlgdc_h

#include "apxdlgap.rh"                  // Definition of all resources.


//{{TDialog = TApxDlgDlgClient}}
class TApxDlgDlgClient : public TDialog {
  public:
    TApxDlgDlgClient(TWindow* parent, TResId resId = IDD_CLIENT, TModule* module = 0);
    virtual ~TApxDlgDlgClient();

};    //{{TApxDlgDlgClient}}


#endif  // apxdlgdc_h sentry.
