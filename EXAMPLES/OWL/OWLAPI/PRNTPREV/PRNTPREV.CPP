//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   prntprev.cpp
//   Example print preview program
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\preview.h>
#include <owl\printer.h>
#include <owl\dc.h>
#include <owl\gdiobjec.h>
#include <owl\layoutwi.h>

#include "prntprev.rh"

//#define  USE_WINDOW_PRINTOUT

//----------------------------------------------------------------------------
//
// Simple text & graphic test printout class
//
class TTestPrintout : public TPrintout {
  public:
    TTestPrintout(const char* title) : TPrintout(title) {Banding=0;}
    void GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage);
    void PrintPage(int page, TRect& rect, unsigned flags);
};

void TTestPrintout::GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage)
{
  minPage = 0;
  maxPage = 0;
  selFromPage = selToPage = 0;
}

void TTestPrintout::PrintPage(int /*page*/, TRect& /*bandRect*/, unsigned /*flags*/)
{
  
  TPrintDC& dc = *DC;
  TSize     pageSize = PageSize;

  //
  // Do the text stuff if this band can handle it.
  //
  const char* lines[6] = {
    "*Line 1: This small text starts at DC origin*",
    "*Line 2: Text only. 1 page of 6 lines.  This large text should be centered.*",
    "*Line 3: This small text should be right-justified.*",
    "*Line 4: This bold text should be on the bottom of the page.*",
    "*Line 5: Line 4 might not be displayed if driver gives wrong size info.*",
    "*Line 6: This line runs vertically.*"
  };
  TEXTMETRIC tm;
  int h;

  //
  // Size the fonts to whatever DC we print to
  //
  h = -MulDiv(dc.GetDeviceCaps(LOGPIXELSY), abs(-12), 72);
  TFont fontSmall(h, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                  ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                  DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -MulDiv(dc.GetDeviceCaps(LOGPIXELSY), abs(-24), 72);
  TFont fontBig(h, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DRAFT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -MulDiv(dc.GetDeviceCaps(LOGPIXELSY), abs(-14), 72);
  TFont fontItalic(h, 0, 0, 0, FW_NORMAL, TRUE, 0, 0,
                   ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                   DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, NULL);

  h = -MulDiv(dc.GetDeviceCaps(LOGPIXELSY), abs(-18), 72);
  TFont fontBold(h, 0, 0, 0, FW_BOLD, 0, 0, 0,
                 ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -MulDiv(dc.GetDeviceCaps(LOGPIXELSY), abs(-14), 72);
  TFont fontVertical(h, 0, 2700, 2700, FW_NORMAL, 0, 0, 0,
                     ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                     DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  TSize     extent;
  dc.SetBkMode(TRANSPARENT);

  //
  // top of the page
  //
  dc.SelectObject(fontSmall);
  dc.GetTextMetrics(tm);
  dc.TextOut(0, 0, lines[0], strlen(lines[0]));

  //
  // centered
  //
  dc.SelectObject(fontBig);
  dc.GetTextMetrics(tm);
  extent = dc.GetTextExtent(lines[1], strlen(lines[1]));
  dc.TextOut((pageSize.cx / 2) - (extent.cx / 2),
             (pageSize.cy / 2) - (extent.cy / 2),
             lines[1], strlen(lines[1]));

  //
  // right justified, above vertical center
  //
  dc.SelectObject(fontSmall);
  dc.GetTextMetrics(tm);
  extent = dc.GetTextExtent(lines[2], strlen(lines[2]));
  dc.TextOut(pageSize.cx - extent.cx,
             (pageSize.cy / 2) - (5 * extent.cy),
             lines[2], strlen(lines[2]));

  //
  // bottom of page
  //
  dc.SelectObject(fontBold);
  dc.GetTextMetrics(tm);
  extent = dc.GetTextExtent(lines[3], strlen(lines[3]));
  dc.TextOut(0, pageSize.cy - extent.cy, lines[3], strlen(lines[3]));

  //
  // below vertical center, left side
  //
  dc.SelectObject(fontItalic);
  dc.GetTextMetrics(tm);
  extent = dc.GetTextExtent(lines[4], strlen(lines[4]));
  dc.TextOut(0, (pageSize.cy / 2) + (5 * extent.cy), lines[4], strlen(lines[4]));

  //
  // right of center line, top, text rotated 270 degrees (vertical)
  //
  dc.SelectObject(fontVertical);
  dc.GetTextMetrics(tm);
  extent = dc.GetTextExtent(lines[5], strlen(lines[5]));
  dc.TextOut((pageSize.cx / 2) + extent.cy, extent.cy * 2, lines[5], strlen(lines[5]));
  

  //
  // Do the graphics stuff if this band can handle it
  //
  TPoint p(pageSize.cx / 4, pageSize.cy / 4);
  dc.SelectStockObject(HOLLOW_BRUSH);

  dc.Rectangle(p.x, p.y, pageSize.cx-p.x, pageSize.cy-p.y);
  dc.Rectangle(0, 0, pageSize.cx, pageSize.cy);
  dc.MoveTo(0, 0);
  dc.LineTo(pageSize.cx, pageSize.cy);
  dc.MoveTo(pageSize.cx, 0);
  dc.LineTo(0, pageSize.cy);
  dc.MoveTo(pageSize.cx / 2, -50);
  dc.LineTo(pageSize.cx / 2, pageSize.cy + 50);

  dc.Ellipse(pageSize.cx / 2 - pageSize.cx / 4,
             pageSize.cy / 2 - pageSize.cy / 4,
             pageSize.cx / 2 + pageSize.cx / 4,
             pageSize.cy / 2 + pageSize.cy / 4);

  dc.RestoreObjects();
}


//----------------------------------------------------------------------------
//
// Printout class that prints the contents of a window
//
class TWindowPrintout : public TPrintout {
  public:
    TWindowPrintout(const char* title, TWindow* window, BOOL scale = TRUE)
      : TPrintout(title)
      { Window = window;
        Scale = scale;
        //MapMode = MM_ISOTROPIC;    // Respect aspect ratio of window
        MapMode = MM_ANISOTROPIC;  // Make printout fill the page
      }

    void GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage);
    void PrintPage(int page, TRect& rect, unsigned flags);
    
  protected:
    TWindow*  Window;
    BOOL      Scale;
    int       MapMode;
};


// Do not enable page range in the print dialog since only one page is
// available to be printed
//
void TWindowPrintout::GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage)
{
  minPage = 0;
  maxPage = 0;
  selFromPage = selToPage = 0;
}


void TWindowPrintout::PrintPage(int /*page*/, TRect& bandRect, unsigned /*flags*/)
{
  // Conditionally scale the DC to the window so the printout will
  // resemble the window
  //
  int    oldMode;
  TSize  oldVExt, oldWExt;
  if (Scale) {
    oldMode = DC->SetMapMode(MapMode);
    TRect clientR = Window->GetClientRect();
    DC->SetViewportExt(PageSize, &oldVExt);
    DC->SetWindowExt(clientR.Size(), &oldWExt);
    DC->IntersectClipRect(clientR);
    DC->DPtoLP(bandRect, 2);
  }

  // Call the window to paint itself to the printer DC.
  //
  Window->Paint(*DC, FALSE, bandRect);

  // Restore changes made to the DC
  //
  if (Scale) {
    DC->SetWindowExt(oldWExt);
    DC->SetViewportExt(oldVExt);
    DC->SetMapMode(oldMode);
  }
}

//----------------------------------------------------------------------------

class TModalFrame : public TFrameWindow {
  public:
    TModalFrame (TWindow* parent, const char far* title, TWindow* client) :
      TFrameWindow(parent, title, client),
      TWindow(parent, title)  {}

    virtual void Destroy(int ret);
};


void TModalFrame::Destroy(int ret)
{
  GetApplication()->EndModal(IDCANCEL);
  GetApplication()->MainWindow->EnableWindow(TRUE);

  TWindow::Destroy(ret);
}

//----------------------------------------------------------------------------

class TMyClientWindow : public TWindow {
  public:
    TPrinter* Printer;

    TMyClientWindow() : TWindow(0, "")   {Printer = 0;}

    void Paint(TDC& dc, BOOL erase, TRect& rect);
    void EvSize(UINT sizeType, TSize& size);

    void CmPrinterSetup();
    void CmPrint();
    void CmPrintPreview();

  DECLARE_RESPONSE_TABLE(TMyClientWindow);
};


DEFINE_RESPONSE_TABLE1(TMyClientWindow, TWindow)
  EV_WM_SIZE,
  EV_COMMAND(CM_PRINTERSETUP, CmPrinterSetup),
  EV_COMMAND(CM_PRINT, CmPrint),
  EV_COMMAND(CM_PRINTPREVIEW, CmPrintPreview),
END_RESPONSE_TABLE;


void TMyClientWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  Invalidate(TRUE);
}


void TMyClientWindow::CmPrinterSetup()
{
  if (!Printer)
    Printer = new TPrinter;

  Printer->Setup(this);
}


void TMyClientWindow::CmPrint()
{
  //
  // Create Printer object if not already created.
  // 
  if (!Printer)
    Printer = new TPrinter;

  #if defined(USE_WINDOW_PRINTOUT)
    TWindowPrintout printout("Print Preview Printer Output", this);
  #else
    TTestPrintout   printout("Print Preview Printer Output");
  #endif

  Printer->Print(this, printout, TRUE);
}


void TMyClientWindow::CmPrintPreview()
{
  if (!Printer)
    Printer = new TPrinter;

  //
  // Create the printer DC. If it fails, let the print dialog report the error
  // for us.
  //
  TPrintDC* prnDC;
  try {
    prnDC = new TPrintDC(Printer->GetSetup().GetDriverName(),
                         Printer->GetSetup().GetDeviceName(),
                         Printer->GetSetup().GetOutputName(),
                         Printer->GetSetup().GetDevMode());
  }
  catch (TGdiBase::TXGdi) {
    TPrintDialog(Parent, Printer->GetSetup()).Execute();
    return;
  }
  
  TSize printExtent(prnDC->GetDeviceCaps(HORZRES), prnDC->GetDeviceCaps(VERTRES));

  #if defined(USE_WINDOW_PRINTOUT)
    TWindowPrintout printout("Print Preview", this);
  #else
    TTestPrintout   printout("Print Preview");
  #endif

  TLayoutWindow* layout = new TLayoutWindow(0);
  layout->SetBkgndColor(GetSysColor(COLOR_APPWORKSPACE));

  for (int i = 0; i < 1; i++) {
    TPreviewPage* page = new TPreviewPage(layout, printout, *prnDC, printExtent);

    TLayoutMetrics metrics;
    metrics.X.Set(lmLeft, lmRightOf, lmParent, lmLeft, 15);
    metrics.Y.Set(lmTop, lmBelow, lmParent, lmTop, 15);

    //
    // Determine major axis of preview page, have that follow parent size.
    // Make minor axis a percentage (aspect ratio) of the page's major axis
    //
    if (printExtent.cx > printExtent.cy) {
      metrics.Width.Set(lmRight, lmLeftOf, lmParent, lmRight, 15);
      metrics.Height.PercentOf(page, int((long(printExtent.cy)*100)/printExtent.cx),
                               lmWidth);
    } else {
      metrics.Height.Set(lmBottom, lmAbove, lmParent, lmBottom, 15);
      metrics.Width.PercentOf(page, int((long(printExtent.cx)*100)/printExtent.cy),
                              lmHeight);
    }

    layout->SetChildLayoutMetrics(*page, metrics);
  }

  TFrameWindow* frame = new TModalFrame(this, "Preview", layout);
  frame->Create();
  frame->ShowWindow(SW_SHOWNORMAL);

  GetApplication()->BeginModal(Parent);
  delete prnDC;
}


void TMyClientWindow::Paint(TDC& dc, BOOL erase, TRect& rect)
{
  if (erase)
    dc.FillRect(rect, TBrush(TColor::White));

  TRect   clientR = GetClientRect();
  TSize   pageSize(clientR.right - clientR.left, clientR.bottom - clientR.top);


  //
  // Do the text stuff.
  //
  const char* lines[6] = {
    "*Line 1: This small text starts at DC origin*",
    "*Line 2: Text only. 1 page of 6 lines.  This large text should be centered.*",
    "*Line 3: This small text should be right-justified.*",
    "*Line 4: This bold text should be on the bottom of the page.*",
    "*Line 5: Line 4 might not be displayed if driver gives wrong size info.*",
    "*Line 6: This line runs vertically.*"
  };
  int     h;

  h = -12;
  TFont fontSmall(h, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                  ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                  DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -24;
  TFont fontBig(h, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DRAFT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -14;
  TFont fontItalic(h, 0, 0, 0, FW_NORMAL, TRUE, 0, 0,
                   ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                   DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, NULL);

  h = -18;
  TFont fontBold(h, 0, 0, 0, FW_BOLD, 0, 0, 0,
                 ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  h = -14;
  TFont fontVertical(h, 0, 2700, 2700, FW_NORMAL, 0, 0, 0,
                     ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                     DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS, NULL);

  TSize     extent;
  dc.SetBkMode(TRANSPARENT);

  //
  // top of the page
  //
  dc.SelectObject(fontSmall);
  dc.TextOut(0, 0, lines[0], strlen(lines[0]));

  //
  // centered
  //
  dc.SelectObject(fontBig);
  extent = dc.GetTextExtent(lines[1], strlen(lines[1]));
  dc.TextOut((pageSize.cx / 2) - (extent.cx / 2),
             (pageSize.cy / 2) - (extent.cy / 2),
             lines[1], strlen(lines[1]));

  //
  // right justified, above vertical center
  //
  dc.SelectObject(fontSmall);
  extent = dc.GetTextExtent(lines[2], strlen(lines[2]));
  dc.TextOut(pageSize.cx - extent.cx,
             (pageSize.cy / 2) - (5 * extent.cy),
             lines[2], strlen(lines[2]));

  //
  // bottom of page
  //
  dc.SelectObject(fontBold);
  extent = dc.GetTextExtent(lines[3], strlen(lines[3]));
  dc.TextOut(0, pageSize.cy - extent.cy, lines[3], strlen(lines[3]));

  //
  // below vertical center, left side
  //
  dc.SelectObject(fontItalic);
  extent = dc.GetTextExtent(lines[4], strlen(lines[4]));
  dc.TextOut(0, (pageSize.cy / 2) + (5 * extent.cy), lines[4], strlen(lines[4]));

  //
  // right of center line, top, text rotated 270 degrees (vertical)
  //
  dc.SelectObject(fontVertical);
  extent = dc.GetTextExtent(lines[5], strlen(lines[5]));
  dc.TextOut((pageSize.cx / 2) + extent.cy, extent.cy * 2, lines[5], strlen(lines[5]));

  //
  // Do the graphics stuff.
  //

  TPoint p(pageSize.cx / 4, pageSize.cy / 4);
  dc.SelectStockObject(HOLLOW_BRUSH);

  dc.Rectangle(p.x, p.y, pageSize.cx-p.x, pageSize.cy-p.y);
  dc.Rectangle(0, 0, pageSize.cx, pageSize.cy);
  dc.MoveTo(0, 0);
  dc.LineTo(pageSize.cx, pageSize.cy);
  dc.MoveTo(pageSize.cx, 0);
  dc.LineTo(0, pageSize.cy);
  dc.MoveTo(pageSize.cx / 2, -50);
  dc.LineTo(pageSize.cx / 2, pageSize.cy + 50);

  dc.Ellipse(pageSize.cx / 2 - pageSize.cx / 4,
             pageSize.cy / 2 - pageSize.cy / 4,
             pageSize.cx / 2 + pageSize.cx / 4,
             pageSize.cy / 2 + pageSize.cy / 4);

  dc.RestoreObjects();
}


class TPrintApp : public TApplication {
  public:
    void InitMainWindow()
    {
      MainWindow = new TFrameWindow(0, "Printer Test", new TMyClientWindow); 
      MainWindow->AssignMenu(100);
    }
};


int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TPrintApp().Run();
}
