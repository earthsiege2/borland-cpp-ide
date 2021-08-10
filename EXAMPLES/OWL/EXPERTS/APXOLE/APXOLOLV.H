//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxololv.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxOleOleView (TOleView).
//
//----------------------------------------------------------------------------
#if !defined(apxololv_h)              // Sentry, use file only if it's not already included.
#define apxololv_h

#include <owl/oleview.h>

#include "apxolapp.rh"            // Definition of all resources.


//{{TOleView = TApxOleOleView}}
class TApxOleOleView : public TOleView {
  public:
    TApxOleOleView(TDocument& doc, TWindow* parent = 0);
    virtual ~TApxOleOleView();

  private:
    TControlBar* ToolBar;

//{{TApxOleOleViewVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
//{{TApxOleOleViewVIRTUAL_END}}
//{{TApxOleOleViewRSP_TBL_BEGIN}}
  protected:
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
    bool EvOcViewShowTools(TOcToolBarInfo far& tbi);
//{{TApxOleOleViewRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxOleOleView);
};    //{{TApxOleOleView}}


#endif  // apxololv_h sentry.
