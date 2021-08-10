//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxsddev.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiDvEditView (TEditView).
//
//----------------------------------------------------------------------------
#if !defined(apxsddev_h)              // Sentry, use file only if it's not already included.
#define apxsddev_h

#include <owl/editview.h>

#include "apxsddva.rh"          // Definition of all resources.


//{{TEditView = TApxSdiDvEditView}}
class TApxSdiDvEditView : public TEditView {
  public:
    TApxSdiDvEditView(TDocument& doc, TWindow* parent = 0);
    virtual ~TApxSdiDvEditView();

//{{TApxSdiDvEditViewVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
//{{TApxSdiDvEditViewVIRTUAL_END}}
//{{TApxSdiDvEditViewRSP_TBL_BEGIN}}
  protected:
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
//{{TApxSdiDvEditViewRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxSdiDvEditView);
};    //{{TApxSdiDvEditView}}


#endif  // apxsddev_h sentry.
