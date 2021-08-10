//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxprev.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of Print Preview.
//
//----------------------------------------------------------------------------
#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/textgadg.h>
#include <stdio.h>

#include "apxprev.h"
#include "apxsddva.rh"


//{{TApxPreviewWin Implementation}}

DEFINE_RESPONSE_TABLE1(TApxPreviewWin, TDecoratedFrame)
  EV_COMMAND_ENABLE(APX_PPR_PREVIOUS, PPR_PreviousEnable),
  EV_COMMAND_ENABLE(APX_PPR_NEXT, PPR_NextEnable),
  EV_COMMAND(APX_PPR_PREVIOUS, PPR_Previous),
  EV_COMMAND(APX_PPR_NEXT, PPR_Next),
  EV_COMMAND(APX_PPR_ONEUP, PPR_OneUp),
  EV_COMMAND_ENABLE(APX_PPR_TWOUP, PPR_TwoUpEnable),
  EV_COMMAND(APX_PPR_TWOUP, PPR_TwoUp),
  EV_COMMAND(APX_PPR_DONE, PPR_Done),
//{{TApxPreviewWinRSP_TBL_BEGIN}}
  EV_WM_CLOSE,
//{{TApxPreviewWinRSP_TBL_END}}
END_RESPONSE_TABLE;


TApxPreviewWin::TApxPreviewWin(TWindow* parentWindow, TPrinter* printer,
                               TWindow* currWindow, const char far* title,
                               TLayoutWindow* client)
:
  TDecoratedFrame(parentWindow, title, client)
{
  CurrWindow = currWindow;
  Printer = printer;
  Client = client;
  Page1 = 0;
  Page2 = 0;
  FromPage = 1;
  ToPage = 1;

  TPrintDialog::TData& data = Printer->GetSetup();
  PrnDC = new TPrintDC(data.GetDriverName(),
                       data.GetDeviceName(),
                       data.GetOutputName(),
                       data.GetDevMode());

  PrintExtent = new TSize(PrnDC->GetDeviceCaps(HORZRES), PrnDC->GetDeviceCaps(VERTRES));
  Printout = new TApxPrintout(Printer, "Print Preview", currWindow, true);

  SetBkgndColor(::GetSysColor(COLOR_APPWORKSPACE));

  // Create default toolbar New and associate toolbar buttons with commands.
  //
  PreviewSpeedBar = new TControlBar(this);
  PreviewSpeedBar->Insert(*new TButtonGadget(APX_PPR_PREVIOUS, APX_PPR_PREVIOUS, TButtonGadget::Command, true));
  PreviewSpeedBar->Insert(*new TButtonGadget(APX_PPR_NEXT, APX_PPR_NEXT, TButtonGadget::Command, true));
  PreviewSpeedBar->Insert(*new TSeparatorGadget(6));
  PreviewSpeedBar->Insert(*new TButtonGadget(APX_PPR_ONEUP, APX_PPR_ONEUP, TButtonGadget::Exclusive, true, TButtonGadget::Down));
  PreviewSpeedBar->Insert(*new TButtonGadget(APX_PPR_TWOUP, APX_PPR_TWOUP, TButtonGadget::Exclusive, true));
  PreviewSpeedBar->Insert(*new TSeparatorGadget(12));
  PreviewSpeedBar->Insert(*new TTextGadget(APX_PPR_CURRPAGE, TGadget::Recessed, TTextGadget::Left, 10, "Page 1"));
  PreviewSpeedBar->Insert(*new TSeparatorGadget(20));
  PreviewSpeedBar->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT, TButtonGadget::Command, true));
  PreviewSpeedBar->Insert(*new TSeparatorGadget(20));
  PreviewSpeedBar->Insert(*new TButtonGadget(APX_PPR_DONE, APX_PPR_DONE, TButtonGadget::Command, true));
  Insert(*PreviewSpeedBar, TDecoratedFrame::Top);

  Attr.Style &= ~WS_VISIBLE;
}


TApxPreviewWin::~TApxPreviewWin()
{
  delete Page1;
  delete Page2;

  delete PrnDC;
  delete PrintExtent;
  delete Printout;
}


void TApxPreviewWin::SetupWindow()
{
  TDecoratedFrame::SetupWindow();

  TAPointer<char> captionText = new char[256];

  // Set the caption of the preview window to that of the Main Window.
  //
  GetApplication()->GetMainWindow()->GetWindowText(captionText, 256);
  SetCaption(captionText);

  // Set the icons of the preview window to those of the Main Window.
  //
  SetIcon(GetApplication(), IDI_SDIAPPLICATION);
  SetIconSm(GetApplication(), IDI_SDIAPPLICATION);

  TPrintDialog::TData& data = Printer->GetSetup();
  Page1 = new TPreviewPage(Client, *Printout, *PrnDC, *PrintExtent, 1);
  Page1->SetPageNumber(1);
  data.MaxPage = 1;

  Page2 = 0;

  TLayoutMetrics metrics1;

  metrics1.X.Set(lmLeft, lmRightOf, lmParent, lmLeft, 15);
  metrics1.Y.Set(lmTop, lmBelow, lmParent, lmTop, 15);

  // Determine major axis of preview page, have that follow parent size.
  // Make minor axis a percentage (aspect ratio) of the page's major axis
  //
  TRect r = Client->GetClientRect();
  long ratio;

  if (PrintExtent->cx > PrintExtent->cy)
    ratio = ((long)PrintExtent->cy * 100) / PrintExtent->cx;
  else
    ratio = ((long)PrintExtent->cx * 100) / PrintExtent->cy;

  bool xMajor = ((r.Width() * ratio) / 100) > r.Height();
  if (xMajor){
    metrics1.Height.Set(lmBottom, lmAbove, lmParent, lmBottom, 15);
    metrics1.Width.PercentOf(Page1, (int)((long)PrintExtent->cx * 95 / PrintExtent->cy), lmHeight);
  }
  else {
    metrics1.Height.PercentOf(Page1, (int)((long)PrintExtent->cy * 95 / PrintExtent->cx), lmWidth);
    metrics1.Width.Set(lmRight, lmLeftOf, lmParent, lmRight, 15);
  }

  Page1->Create();

  Client->SetChildLayoutMetrics(*Page1, metrics1);
  Client->Layout();
}


void TApxPreviewWin::SpeedBarState()
{
  // Update the page count.
  //
  TTextGadget* cpGadget = TYPESAFE_DOWNCAST(PreviewSpeedBar->GadgetWithId(APX_PPR_CURRPAGE), TTextGadget);
  if (cpGadget) {
    TAPointer<char> buffer = new char[32];

    if (Page2 && FromPage != ToPage)
      sprintf(buffer, "Page %d - %d", FromPage, ToPage);
    else
      sprintf(buffer, "Page %d", FromPage);
    cpGadget->SetText(buffer);
  }
}


void TApxPreviewWin::PPR_PreviousEnable(TCommandEnabler& tce)
{
  // Only have previous on if we're not at the first page.
  //
  tce.Enable(FromPage != 1);
}


void TApxPreviewWin::PPR_NextEnable(TCommandEnabler& tce)
{
  // Only have next on if we're not at the last page.
  //
  TPrintDialog::TData& printerData = Printer->GetSetup();
  tce.Enable(ToPage != printerData.MaxPage);
}


void TApxPreviewWin::PPR_Previous()
{
  TPrintDialog::TData& printerData = Printer->GetSetup();

  if (FromPage > printerData.MinPage) {
    FromPage--;
    ToPage--;

    Page1->SetPageNumber(FromPage);
    if (Page2)
      Page2->SetPageNumber(ToPage);
  }

  SpeedBarState();
}


void TApxPreviewWin::PPR_Next()
{
  TPrintDialog::TData& printerData = Printer->GetSetup();

  if (ToPage < printerData.MaxPage) {
    FromPage++;
    ToPage++;

    Page1->SetPageNumber(FromPage);
    if (Page2)
      Page2->SetPageNumber(ToPage);
  }

  SpeedBarState();
}


void TApxPreviewWin::PPR_OneUp()
{
  if (Page2) {
    Client->RemoveChildLayoutMetrics(*Page2);

    delete Page2;
    Page2 = 0;

    Client->Layout();

    ToPage = FromPage;

    SpeedBarState();
  }
}


void TApxPreviewWin::PPR_TwoUpEnable(TCommandEnabler& tce)
{
  // Two up is only available for portrait mode.
  //
  tce.Enable(PrintExtent->cx <= PrintExtent->cy);
}


void TApxPreviewWin::PPR_TwoUp()
{
  if (!Page2) {
    Page2 = new TPreviewPage(Client, *Printout, *PrnDC, *PrintExtent, PageNumber + 1);
    Page2->Create();

    TLayoutMetrics metrics2;

    metrics2.X.Set(lmLeft, lmRightOf, Page1, lmRight, 30);
    metrics2.Y.SameAs(Page1, lmTop);

    // Assume portrait
    //
    metrics2.Width.SameAs(Page1, lmWidth);
    metrics2.Height.SameAs(Page1, lmBottom);

    Client->SetChildLayoutMetrics(*Page2, metrics2);
    Client->Layout();

    TPrintDialog::TData& printerData = Printer->GetSetup();

    // Page 2 is the next page.  If the next page is outside of our range then
    // set the first page back one and the 2nd page is the current page. If the
    // document is only 1 page long then the 2nd page is empty.
    //
    if (FromPage == printerData.MaxPage) {
      if (FromPage > 1) {
        FromPage--;
        ToPage = FromPage + 1;
        Page1->SetPageNumber(FromPage);
        Page2->SetPageNumber(ToPage);
      }
      else
        Page2->SetPageNumber(0);
    }
    else {
      ToPage = FromPage + 1;
      Page2->SetPageNumber(ToPage);
    }

    SpeedBarState();
  }
}


void TApxPreviewWin::PPR_Done()
{
  // Don't call the base class EvClose; we do not want TApxPreviewWin to be destructed.
  //
  GetApplication()->GetMainWindow()->SetRedraw(false);
  GetApplication()->EndModal(IDCANCEL);
}


void TApxPreviewWin::EvClose()
{
  // Don't call the base class EvClose; we do not want TApxPreviewWin to be destructed.
  //
  GetApplication()->GetMainWindow()->SetRedraw(false);
  GetApplication()->EndModal(IDCANCEL);
}
