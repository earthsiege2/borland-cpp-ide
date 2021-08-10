#if !defined(__apxprev_h)               // Sentry, use file only if it's not already included.
#define __apxprev_h

##@QUERY_PRJ_NAME [[Project]]
/*  Main [[Project]]
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

#include <owl\controlb.h>
#include <owl\printdia.h>
#include <owl\preview.h>

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

//{{PreviewWindowVIRTUAL_BEGIN}}
protected:
##DBVirtual("PreviewWindow", "SetupWindow")
    virtual void SetupWindow ();
//{{PreviewWindowVIRTUAL_END}}

//{{PreviewWindowRSP_TBL_BEGIN}}
protected:
    void PPR_Previous ();
    void PPR_Next ();
    void PPR_OneUp ();
    void PPR_TwoUp ();
    void EvNCLButtonDown (UINT wHitTestCode, TPoint & point);
    void EvClose ();
//{{PreviewWindowRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(PreviewWindow);
};    //{{PreviewWindow}}


#endif      // __apxprev_h sentry.
