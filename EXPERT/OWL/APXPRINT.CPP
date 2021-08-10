##@QUERY_PRJ_NAME [[Project]]
/*  Project [[Project]]
##@QUERY_PRJ_COMPANY [[CompanyName]] 2
##@QUERY_PRJ_COPYRIGHT [[Copyright]] 2
##\\Copyright Copyright 2
    [[CompanyName]]
    [[Copyright]]

##@QUERY_TARGET_NAME [[Target]]
    SUBSYSTEM:    [[Target]] Application
    FILE:         APXPrint.CPP
##@QUERY_PRJ_USER [[Author]]
    AUTHOR:       [[Author]]


    OVERVIEW
    ========
    Source file for implementation of Printing.
*/


#include <owl\owlpch.h>
#pragma hdrstop

#include "apxprint.h"


##--BEGIN-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
// Do not enable page range in the print dialog since only one page is
// available to be printed
//
##--END-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
void APXPrintOut::GetDialogInfo (int& minPage, int& maxPage, int& selFromPage, int& selToPage)
{
    minPage = maxPage = 0;
    selFromPage = selToPage = 0;
}


void APXPrintOut::BeginPrinting ()
{
    TRect clientR;

    BeginPage(clientR);

    HFONT   hFont = (HFONT)Window->GetWindowFont();
    TFont   font("Arial", -12);
    if (hFont == 0)
      DC->SelectObject(font);
    else
      DC->SelectObject(TFont(hFont));
    
    TEXTMETRIC  tm;
    int fHeight = (DC->GetTextMetrics(tm) == true) ? tm.tmHeight + tm.tmExternalLeading : 10;

    DC->RestoreFont();
    
##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // How many lines of this font can we fit on a page.
    int linesPerPage = MulDiv(clientR.Height(), 1, fHeight);
    
    TPrintDialog::TData &printerData = Printer->GetSetup();

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // GetMinMaxInfo event is overrided to return the number of lines when printing.
    MINMAXINFO minmaxinfo;
    Window->SendMessage(WM_GETMINMAXINFO, 0, (long)&minmaxinfo);
    int maxPg = ((minmaxinfo.ptMaxSize.y / linesPerPage) + 1.0);


##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Compute the number of pages to print.
    printerData.MinPage = 1;
    printerData.MaxPage = maxPg;

    EndPage();

    TPrintout::BeginPrinting();
}


void APXPrintOut::BeginPage (TRect &clientR)
{
    TScreenDC screenDC;
    TSize screenRes(screenDC.GetDeviceCaps(LOGPIXELSX),
                    screenDC.GetDeviceCaps(LOGPIXELSY));
    TSize printRes(DC->GetDeviceCaps(LOGPIXELSX),
                   DC->GetDeviceCaps(LOGPIXELSY));

##--BEGIN-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Temporarily change the window size (so any WM_PAINT queries on the total window size (GetClientRect) is
    // the window size for the WM_PAINT of the window and the printer page size when Paint is called from
    // PrintPage. Notice, we don't use AdjustWindowRect because its harder and not accurate.  Instead we
    // compute the difference (in pixels) between the client window and the frame window.  This difference
    // is then added to the clientRect to compute the new frame window size for SetWindowPos.
##--END-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
    clientR = Window->GetClientRect();
    Window->MapWindowPoints(HWND_DESKTOP, (TPoint*)&clientR, 2);

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Compute extra X and Y pixels to bring a client window dimensions to equal the frame window.
    OrgR = Window->GetWindowRect();
    int adjX = OrgR.Width() - clientR.Width();
    int adjY = OrgR.Height() - clientR.Height();
    
##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Conditionally scale the DC to the window so the printout will resemble the window.
    if (Scale) {
        clientR = Window->GetClientRect();
        PrevMode = DC->SetMapMode(MapMode);
        DC->SetViewportExt(PageSize, &OldVExt);

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
        // Scale window to logical page size (assumes left & top are 0)
        clientR.right = MulDiv(PageSize.cx, screenRes.cx, printRes.cx);
        clientR.bottom = MulDiv(PageSize.cy, screenRes.cy, printRes.cy);

        DC->SetWindowExt(clientR.Size(), &OldWExt);
    }

##--BEGIN-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Compute the new size of the window based on the printer DC dimensions.    
    // Resize the window, notice position, order, and redraw are not done the window size changes but the user
    // doesn't see any visible change to the window.
##--END-- @QUERY_APPL_COMMENT == VALUE_VERBOSE
    Window->SetRedraw(false);
    Window->SetWindowPos(0, 0, 0, clientR.Width() + adjX, clientR.Height() + adjY,
                         SWP_NOMOVE | SWP_NOREDRAW | SWP_NOZORDER| SWP_NOACTIVATE);
}


void APXPrintOut::PrintPage (int page, TRect& bandRect, unsigned)
{
    TRect clientR;

    BeginPage(clientR);

    if (Scale)
        DC->DPtoLP(bandRect, 2);

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Change the printer range to this current page.
    TPrintDialog::TData& printerData = Printer->GetSetup();
    int fromPg = printerData.FromPage;
    int toPg = printerData.ToPage;

    printerData.FromPage = page;
    printerData.ToPage = page;

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Call the window to paint itself to the printer DC.
    Window->Paint(*DC, false, bandRect);

    printerData.FromPage = fromPg;
    printerData.ToPage = toPg;

    if (Scale)
        DC->LPtoDP(bandRect, 2);

    EndPage();
}


void APXPrintOut::EndPage ()
{
##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Resize to original window size, no one's the wiser.
    Window->SetWindowPos(0, 0, 0, OrgR.Width(), OrgR.Height(),
                         SWP_NOMOVE | SWP_NOREDRAW | SWP_NOZORDER| SWP_NOACTIVATE);
    Window->SetRedraw(true);

##:@QUERY_APPL_COMMENT == VALUE_VERBOSE
    // Restore changes made to the DC
    if (Scale) {
        DC->SetWindowExt(OldWExt);
        DC->SetViewportExt(OldVExt);
        DC->SetMapMode(PrevMode);
    }
}


bool APXPrintOut::HasPage (int pageNumber)
{
    TPrintDialog::TData &printerData = Printer->GetSetup();

    return (pageNumber >= printerData.MinPage) && (pageNumber <= printerData.MaxPage);
}
