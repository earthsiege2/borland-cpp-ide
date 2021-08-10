//----------------------------------------------------------------------------
##@QUERY_PRJ_NAME [[Project]]
//  Project [[Project]]
##@QUERY_PRJ_COMPANY [[CompanyName]] 2
##@QUERY_PRJ_COPYRIGHT [[Copyright]] 2
##\\Copyright Copyright 2
//  [[CompanyName]]
//  [[Copyright]]
//
##@QUERY_TARGET_NAME [[Target]]
//  SUBSYSTEM:    [[Target]] Application
//  FILE:         apxprev.h
##@QUERY_PRJ_USER [[Author]]
//  AUTHOR:       [[Author]]
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxPreviewWin (Print Preview).
//
//----------------------------------------------------------------------------
#if !defined(apxprev_h)   // Sentry, use file only if it's not already included.
#define apxprev_h

#include <owl/controlb.h>
#include <owl/preview.h>

#include "apxprint.h"
##<<TApplication QUERY_FILENAME_CPP [[FileName]]
#include "[[FileName]].rh"


//{{TDecoratedFrame = TApxPreviewWin}}
class TApxPreviewWin : public TDecoratedFrame {
  public:
    TApxPreviewWin(TWindow* parentWindow, TPrinter* printer, TWindow* currWindow, const char far* title, TLayoutWindow* client);
   ~TApxPreviewWin();

    int             PageNumber, FromPage, ToPage;

    TWindow*        CurrWindow;
    TControlBar*    PreviewSpeedBar;
    TPreviewPage*   Page1;
    TPreviewPage*   Page2;
    TPrinter*       Printer;

    TPrintDC*       PrnDC;
    TSize*          PrintExtent;
    TApxPrintout*   Printout;

  private:
    TLayoutWindow*  Client;

    void SpeedBarState();
    void PPR_PreviousEnable(TCommandEnabler& tce);
    void PPR_NextEnable(TCommandEnabler& tce);
    void PPR_Previous();
    void PPR_Next();
    void PPR_OneUp();
    void PPR_TwoUpEnable(TCommandEnabler& tce);
    void PPR_TwoUp();
    void PPR_Done();
##@QUERY_APPL_MODEL == VALUE_MDI 2
    void CmPrintEnable(TCommandEnabler& tce);
    void CmPrint();

//{{TApxPreviewWinVIRTUAL_BEGIN}}
  protected:
##DBVirtual("TApxPreviewWin", "SetupWindow")
    virtual void SetupWindow();
//{{TApxPreviewWinVIRTUAL_END}}

//{{TApxPreviewWinRSP_TBL_BEGIN}}
  protected:
    void EvClose();
//{{TApxPreviewWinRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxPreviewWin);
};    //{{TApxPreviewWin}}

#endif  // apxprev_h
