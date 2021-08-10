//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxololv.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxOleOleView (TOleView).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxolapp.h"
#include "apxololv.h"

#include <stdio.h>


//{{TApxOleOleView Implementation}}

//
// Build a response table for all messages/commands handled
// by TApxOleOleView derived from TOleView.
//
DEFINE_RESPONSE_TABLE1(TApxOleOleView, TOleView)
//{{TApxOleOleViewRSP_TBL_BEGIN}}
  EV_WM_GETMINMAXINFO,
  EV_OC_VIEWSHOWTOOLS,
//{{TApxOleOleViewRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxOleOleView
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxOleOleView::TApxOleOleView(TDocument& doc, TWindow* parent)
:
  TOleView(doc, parent)
{
  ToolBar = 0;

  // INSERT>> Your constructor code here.

}


TApxOleOleView::~TApxOleOleView()
{
  // INSERT>> Your destructor code here.

}


//
// Paint routine for Window, Printer, and PrintPreview for a TOleView client.
//
void TApxOleOleView::Paint(TDC& dc, bool erase, TRect& rect)
{
  TApxOleApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxOleApp);
  if (theApp) {
    // Only paint if we're printing and we have something to paint, otherwise do nothing.
    //
    if (theApp->Printing && theApp->Printer && !rect.IsEmpty()) {
      // Use pageSize to get the size of the window to render into.  For a Window it's the client area,
      // for a printer it's the printer DC dimensions and for print preview it's the layout window.
      //
      TSize   pageSize(rect.right - rect.left, rect.bottom - rect.top);

      TPrintDialog::TData& printerData = theApp->Printer->GetSetup();

      // Compute the number of pages to print.
      //
      printerData.MinPage = 1;
      printerData.MaxPage = 1;

      TOcView*  ocView = GetOcView();

      // Default TOcPart painting
      //
      TRect clientRect = GetClientRect();
      TRect logicalRect = clientRect +(TSize&)ocView->GetOrigin();
        for (TOcPartCollectionIter i(GetOcDoc()->GetParts()); i; i++) {
        TOcPart& p = *i.Current();
        if (p.IsVisible(logicalRect)) {
          TRect r = p.GetRect();
          r -= ocView->GetOrigin();
          p.Draw(dc, r, clientRect);        // Draw the embedded object.
        }
      }

      // INSERT>> Special printing code goes here.

    }
    else {
      TOleView::Paint(dc, erase, rect);

      // INSERT>> Normal painting code goes here.

    }
  }
}


void TApxOleOleView::EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo)
{
  TApxOleApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxOleApp);
  if (theApp) {
    if (theApp->Printing) {
      minmaxinfo.ptMaxSize = TPoint(32000, 32000);
      minmaxinfo.ptMaxTrackSize = TPoint(32000, 32000);
      return;
    }
  }
  TOleView::EvGetMinMaxInfo(minmaxinfo);
}


bool TApxOleOleView::EvOcViewShowTools(TOcToolBarInfo far& tbi)
{
  // Construct & create a control bar for show, destroy our bar for hide
  //
  if (tbi.Show) {
    if (!ToolBar) {
      ToolBar = new TControlBar(this);

      TApxOleApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxOleApp);
      CHECK(theApp);

      theApp->CreateGadgets(ToolBar, true);
    }

    ToolBar->Create();
    tbi.HTopTB = (HWND)*ToolBar;
  }
  else {
    if (ToolBar) {
      ToolBar->Destroy();
      delete ToolBar;
      ToolBar = 0;
    }
  }

  return true;
}
