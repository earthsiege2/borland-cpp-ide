//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apxmddev.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiDvEditView (TEditView).
//
//----------------------------------------------------------------------------
#if !defined(apxmddev_h)              // Sentry, use file only if it's not already included.
#define apxmddev_h

#include <owl/editview.h>

#include "apxmddva.rh"          // Definition of all resources.


//{{TEditView = TApxMdiDvEditView}}
class TApxMdiDvEditView : public TEditView {
  public:
    TApxMdiDvEditView(TDocument& doc, TWindow* parent = 0);
    virtual ~TApxMdiDvEditView();

//{{TApxMdiDvEditViewVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
//{{TApxMdiDvEditViewVIRTUAL_END}}
//{{TApxMdiDvEditViewRSP_TBL_BEGIN}}
  protected:
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
//{{TApxMdiDvEditViewRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiDvEditView);
};    //{{TApxMdiDvEditView}}


#endif  // apxmddev_h sentry.
