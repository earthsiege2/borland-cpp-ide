#if !defined(__apxprint_h)              // Sentry use file only if it's not already included.
#define __apxprint_h

##@QUERY_PRJ_NAME [[Project]]
/*  Project [[Project]]
##@QUERY_PRJ_COMPANY [[CompanyName]] 2
##@QUERY_PRJ_COPYRIGHT [[Copyright]] 2
##\\Copyright Copyright 2
    [[CompanyName]]
    [[Copyright]]

##@QUERY_TARGET_NAME [[Target]]
    SUBSYSTEM:    [[Target]] Application
    FILE:         APXPrint.H
##@QUERY_PRJ_USER [[Author]]
    AUTHOR:       [[Author]]


    OVERVIEW
    ========
    Class definition for APXPrintOut (TPrintOut).      
*/


#include <owl\owlpch.h>
#pragma hdrstop


class APXPrintOut : public TPrintout {
public:
    APXPrintOut (TPrinter *printer, const char far *title, TWindow* window, bool scale = true) : TPrintout(title)
      { Printer = printer; Window = window; Scale = scale; MapMode = MM_ANISOTROPIC; }

    void GetDialogInfo (int& minPage, int& maxPage, int& selFromPage, int& selToPage);
    void BeginPrinting ();
    void BeginPage (TRect &clientR);
    void PrintPage (int page, TRect& rect, unsigned flags);
    void EndPage ();
    void SetBanding (bool b)        { Banding = b; }
    bool HasPage (int pageNumber);

protected:
    TWindow     *Window;
    bool        Scale;
    TPrinter    *Printer;
    int         MapMode;

    int         PrevMode;
    TSize       OldVExt, OldWExt;
    TRect       OrgR;
};


#endif          // __apxprint_h sentry.
