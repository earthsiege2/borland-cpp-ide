#if !defined(__apxprev_h)               // Sentry, use file only if it's not already included.
#define __apxprev_h

##@QUERY_PRJ_NAME [[Project]]
/*  Project [[Project]]
##@QUERY_PRJ_COMPANY [[CompanyName]] 2
##@QUERY_PRJ_COPYRIGHT [[Copyright]] 2
##\\Copyright Copyright 2
    [[CompanyName]]
    [[Copyright]]

##@QUERY_TARGET_NAME [[Target]]
    SUBSYSTEM:    [[Target]] Application
    FILE:         APXPrev.H
##@QUERY_PRJ_USER [[Author]]
    AUTHOR:       [[Author]]


    OVERVIEW
    ========
    Class definition for PreviewWindow (Print Preview).      
*/


#include <owl\owlpch.h>
#pragma hdrstop

#include "apxprint.h"
##<<TApplication QUERY_FILENAME_CPP [[FileName]]
#include "[[FileName]].rh"


//{{TDecoratedFrame = PreviewWindow}}
class PreviewWindow : public TDecoratedFrame {
public:
    PreviewWindow (TWindow *parentWindow, TPrinter *printer, TWindow* currWindow, const char far* title, TLayoutWindow* client);
    ~PreviewWindow ();

    int             PageNumber;

    TWindow         *CurrWindow;
    TControlBar     *PreviewSpeedBar;
    TPreviewPage    *Page1;
    TPreviewPage    *Page2;
    TPrinter        *Printer;

    TPrintDC        *PrnDC;
    TSize           *PrintExtent;
    APXPrintOut     *Printout;

private:
    TLayoutWindow   *Client;

    void SpeedBarState ();
    void PPR_PreviousEnable (TCommandEnabler &tce);
    void PPR_NextEnable (TCommandEnabler &tce);
    void PPR_Previous ();
    void PPR_Next ();
    void PPR_OneUp ();
    void PPR_TwoUpEnable (TCommandEnabler &tce);
    void PPR_TwoUp ();
    void PPR_Done ();
##@QUERY_APPL_MODEL == VALUE_MDI 2
    void CmPrintEnable (TCommandEnabler &tce);
    void CmPrint ();

//{{PreviewWindowVIRTUAL_BEGIN}}
protected:
##DBVirtual("PreviewWindow", "SetupWindow")
    virtual void SetupWindow ();
//{{PreviewWindowVIRTUAL_END}}

//{{PreviewWindowRSP_TBL_BEGIN}}
protected:
//{{PreviewWindowRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(PreviewWindow);
};    //{{PreviewWindow}}


#endif      // __apxprev_h sentry.
