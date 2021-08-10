//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxsdedf.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxSdiEditFile (TEditFile).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxsdapp.h"
#include "apxsdedf.h"

#include <stdio.h>


//{{TApxSdiEditFile Implementation}}


//
// Build a response table for all messages/commands handled
// by TApxSdiEditFile derived from TEditFile.
//
DEFINE_RESPONSE_TABLE1(TApxSdiEditFile, TEditFile)
//{{TApxSdiEditFileRSP_TBL_BEGIN}}
  EV_WM_GETMINMAXINFO,
//{{TApxSdiEditFileRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxSdiEditFile
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxSdiEditFile::TApxSdiEditFile(TWindow* parent, int id, const char far* text, int x, int y, int w, int h, const char far* fileName, TModule* module)
:
  TEditFile(parent, id, text, x, y, w, h, fileName, module)
{
  // INSERT>> Your constructor code here.

}


TApxSdiEditFile::~TApxSdiEditFile()
{
  Destroy();

  // INSERT>> Your destructor code here.

}


void TApxSdiEditFile::SetupWindow()
{
  TEditFile::SetupWindow();

  TApxSdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxSdiApp);
  FileData = theApp->FileData;
}


//
// Paint routine for Window, Printer, and PrintPreview for an TEdit client.
//
void TApxSdiEditFile::Paint(TDC& dc, bool, TRect& rect)
{
  TApxSdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxSdiApp);
  if (theApp) {
    // Only paint if we're printing and we have something to paint, otherwise do nothing.
    //
    if (theApp->Printing && theApp->Printer && !rect.IsEmpty()) {
      // Use pageSize to get the size of the window to render into.  For a Window it's the client area,
      // for a printer it's the printer DC dimensions and for print preview it's the layout window.
      //
      TSize   pageSize(rect.right - rect.left, rect.bottom - rect.top);

      HFONT   hFont = (HFONT)GetWindowFont();
      TFont   font("Arial", -12);
      if (!hFont)
        dc.SelectObject(font);
      else
        dc.SelectObject(TFont(hFont));

      TEXTMETRIC  tm;
      int fHeight = dc.GetTextMetrics(tm) ? tm.tmHeight + tm.tmExternalLeading : 10;

      // How many lines of this font can we fit on a page.
      //
      int linesPerPage = MulDiv(pageSize.cy, 1, fHeight);
      if (linesPerPage) {        TPrintDialog::TData& printerData = theApp->Printer->GetSetup();

        int maxPg = ((GetNumLines() / linesPerPage) + 1.0);

        // Compute the number of pages to print.
        //
        printerData.MinPage = 1;
        printerData.MaxPage = maxPg;

        // Do the text stuff:
        //
        int   fromPage = printerData.FromPage == -1 ? 1 : printerData.FromPage;
        int   toPage = printerData.ToPage == -1 ? 1 : printerData.ToPage;
        int   currentPage = fromPage;
        TAPointer<char> buffer = new char[255];

        while (currentPage <= toPage) {
          int startLine = (currentPage - 1) * linesPerPage;
          int lineIdx = 0;
          while (lineIdx < linesPerPage) {
            // If the string is no longer valid then there's nothing more to display.
            //
            if (!GetLine(buffer, 255, startLine + lineIdx))
              break;
            dc.TabbedTextOut(TPoint(0, lineIdx * fHeight), buffer, strlen(buffer), 0, 0, 0);
            lineIdx++;
          }
          currentPage++;
        }
      }
    }
  }
}


void TApxSdiEditFile::EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo)
{
  TApxSdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxSdiApp);
  if (theApp) {
    if (theApp->Printing) {
      minmaxinfo.ptMaxSize = TPoint(32000, 32000);
      minmaxinfo.ptMaxTrackSize = TPoint(32000, 32000);
      return;
    }
  }
  TEditFile::EvGetMinMaxInfo(minmaxinfo);
}


// Override SaveAs to store the menu choice.
//
bool TApxSdiEditFile::SaveAs()
{
  if (TEditFile::SaveAs()) {
    TApxSdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxSdiApp);
    theApp->SaveMenuChoice(GetFileName());
    return true;
  }
  return false;
}
