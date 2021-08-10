//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//  This application displays and prints a Ruler using OWL printer classes.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <owl/printer.h>
#include <owl/editfile.rh>
#include <stdlib.h>
#include <string.h>

#define IDM_RULERMENU 100

//
// class TWindowPrintout
// ~~~~~ ~~~~~~~~~~~~~~~
class TWindowPrintout : public TPrintout {
  public:
    TWindowPrintout(const char* title, TWindow* window);

    void GetDialogInfo(int& minPage, int& maxPage,
                       int& selFromPage, int& selToPage);
    void PrintPage(int page, TRect& rect, unsigned flags);
    void SetBanding(bool b)
    {
      Banding = b;
    }
    bool HasPage(int pageNumber)
    {
      return pageNumber == 1;
    }

  protected:
    TWindow* Window;
    bool     Scale;
};

TWindowPrintout::TWindowPrintout(const char* title, TWindow* window)
:
  TPrintout(title)
{
  Window = window;
  Scale = true;
}

void
TWindowPrintout::PrintPage(int, TRect& rect, unsigned)
{
  // Conditionally scale the DC to the window so the printout will
  // resemble the window
  //
  int    prevMode;
  TSize  oldVExt, oldWExt;
  if (Scale) {
    prevMode = DC->SetMapMode(MM_ISOTROPIC);
    TRect windowSize = Window->GetClientRect();
    DC->SetViewportExt(PageSize, &oldVExt);
    DC->SetWindowExt(windowSize.Size(), &oldWExt);
    DC->IntersectClipRect(windowSize);
    DC->DPtoLP(rect, 2);
  }

  // Call the window to paint itself
  Window->Paint(*DC, false, rect);

  // Restore changes made to the DC
  if (Scale) {
    DC->SetWindowExt(oldWExt);
    DC->SetViewportExt(oldVExt);
    DC->SetMapMode(prevMode);
  }
}

// Do not enable page range in the print dialog since only one page is
// available to be printed
//
void
TWindowPrintout::GetDialogInfo(int& minPage, int& maxPage,
                               int& selFromPage, int& selToPage)
{
  minPage = 0;
  maxPage = 0;
  selFromPage = selToPage = 0;
}

//----------------------------------------------------------------------------
// TRulerWin

class TRulerWin : public TWindow {
  public:
    TRulerWin(TWindow* parent = 0);
   ~TRulerWin();

    void Paint(TDC&, bool, TRect&);

    void CmFilePageSetup();
    void CmFilePrint();

  private:
    TPrinter* Printer;

  DECLARE_RESPONSE_TABLE(TRulerWin);
};

DEFINE_RESPONSE_TABLE1(TRulerWin, TWindow)
  EV_COMMAND(CM_FILEPAGESETUP, CmFilePageSetup),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
END_RESPONSE_TABLE;

TRulerWin::TRulerWin(TWindow* parent)
:
  TWindow(parent)
{
  Printer = new TPrinter;
}

TRulerWin::~TRulerWin()
{
  delete Printer;
}

void
TRulerWin::CmFilePageSetup()    // Execute File:Page-setup command
{
  if (Printer)
    Printer->Setup(this);
}

void
TRulerWin::CmFilePrint()          // Execute File:Print command
{
  if (Printer) {
    TWindowPrintout printout("Ruler Test", this);
    printout.SetBanding(true);
    Printer->Print(this, printout, true);
  }
}

// Paint window's contents on any dc, screen or printer or whatever...
//
void
TRulerWin::Paint(TDC& dc, bool , TRect&)
{
  const int UnitsPerInch = 100;                 // Display scale units per inch
  const int NumInches = 8;                      // Size of ruler in inches
  const int MarkFraction = 4;                   // Power of 2 to use for marks
  const int MarksPerInch = (1 << MarkFraction); // Number of markers for each inch
  const int LargeMarkerSize = UnitsPerInch/3;   // Size of large, labeled markers
  const int SmallMarkerSize = UnitsPerInch/8;   // Size of smallest markers
  const int MarkStep = (LargeMarkerSize-SmallMarkerSize) / MarkFraction;

  dc.SaveDC();
  dc.SetMapMode(MM_LOENGLISH);
  int x1 = 0; //0.50 * UnitsPerInch;
  int y1 = x1;
  int x2 = x1 + NumInches * UnitsPerInch;
  int y2 = y1 + 1*UnitsPerInch;
  dc.Rectangle(x1, -y1, x2, -y2);

  // Draw marks
  //
  y2 = y1 + SmallMarkerSize;
  for (int marksPerInch = MarksPerInch; marksPerInch > 0; marksPerInch /= 2) {
    for (int i = 0; i <= NumInches*marksPerInch - 1; i++) {
      int x = x1 + (i * UnitsPerInch) / marksPerInch;
      dc.MoveTo(x, -y1);
      dc.LineTo(x, -y2);
    }
    y2 += MarkStep;
  }

  // Label the inch marks
  //
  y2 = y1 + LargeMarkerSize; // - text height
  for (int i = 1;  i <= NumInches - 1; i++) {
    int x = x1 + i * UnitsPerInch;  // - ( text width + 20%)
    char s[3];
    itoa(i, s, 10);
    dc.TextOut(TPoint(x, -y2), s, strlen(s));
  }

  dc.RestoreDC();
}


//
// class TRulerApp
// ~~~~~ ~~~~~~~~~
class TRulerApp : public TApplication {
  public:
    TRulerApp()
    :
      TApplication()
    {
    }

    void InitMainWindow() {
      EnableCtl3d();
      TFrameWindow* frame = new TFrameWindow(0, "Ruler Printing Demonstration",
        new TRulerWin);
      frame->Attr.X = GetSystemMetrics(SM_CXSCREEN) / 8;
      frame->Attr.Y = GetSystemMetrics(SM_CYSCREEN) / 8;
      frame->Attr.H = frame->Attr.Y * 6;
      frame->Attr.W = frame->Attr.X * 6;
      frame->AssignMenu(IDM_RULERMENU);
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TRulerApp().Run();
}
