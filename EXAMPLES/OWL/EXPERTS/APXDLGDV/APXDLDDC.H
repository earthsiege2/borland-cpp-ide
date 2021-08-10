//----------------------------------------------------------------------------
//  Project ApxDlgDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlgDv Application
//  FILE:         apxdlddc.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxDlgDvDlgClient (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(apxdlddc_h)              // Sentry, use file only if it's not already included.
#define apxdlddc_h

#include <owl/docview.h>

#include "apxdlgda.rh"                  // Definition of all resources.


//{{TDialog = TApxDlgDvDlgClient}}
class TApxDlgDvDlgClient : public TDialog, public TView {
  public:
//  TApxDlgDvDlgClient(TWindow* parent, TResId resId = IDD_CLIENT, TModule* module = 0);  //{{DIALOG_ASSOCIATION}}

    TApxDlgDvDlgClient(TDocument& doc, TWindow* parent = 0);
    virtual ~TApxDlgDvDlgClient();

    static const char far* StaticName() {return "Dialog View";}  // put in resource

    // Inherited virtuals from TView
    //
    const char far* GetViewName() {return StaticName();}
    TWindow* GetWindow() {return(TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
             { return TWindow::SetDocTitle(docname, index); }
  private:
    // Event handlers
    //
    bool     VnIsWindow(HWND hWnd)
             { return ((HWindow == hWnd) || IsChild(hWnd)); }

//{{TApxDlgDvDlgClientVIRTUAL_BEGIN}}
  public:
    virtual bool CanClose();
//{{TApxDlgDvDlgClientVIRTUAL_END}}

//{{TApxDlgDvDlgClientRSP_TBL_BEGIN}}
  protected:
//{{TApxDlgDvDlgClientRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxDlgDvDlgClient);
};    //{{TApxDlgDvDlgClient}}


#endif  // apxdlddc_h sentry.
