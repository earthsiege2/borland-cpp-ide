//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Printing program example using Application Framework Libraries (OWL)
//   This application displays and prints a Ruler using OWL printer classes.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\printer.h>
#include <owl\editfile.rh>
#include <stdlib.h>
#include <string.h>


//----------------------------------------------------------------------------
// TWindowPrintout

class TWindowPrintout : public TPrintout {
  public:
    TWindowPrintout(const char* title, TWindow* window);

    void GetDialogInfo(int& minPage, int& maxPage,
                       int& selFromPage, int& selToPage);
    void PrintPage(int page, TRect& rect, unsigned flags);
    void SetBanding(BOOL b) {Banding = b;}
    BOOL HasPage(int pageNumber) {return pageNumber == 1;}
    
  protected:
    TWindow* Window;
    BOOL     Scale;
};

TWindowPrintout::TWindowPrintout(const char* title, TWindow* window)
  : TPrintout(title)
{
  Window = window;
  Scale = TRUE;
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
  Window->Paint(*DC, FALSE, rect);

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

class TRulerWin : public TFrameWindow {
  TPrinter* Printer;
  public:
    TRulerWin(TWindow* parent, const char* title, TModule* = 0);
    ~TRulerWin();

    void Paint(TDC&, BOOL, TRect&);

    void CmFilePrint();
    void CmFilePrinterSetup();

  DECLARE_RESPONSE_TABLE(TRulerWin);
};

DEFINE_RESPONSE_TABLE1(TRulerWin, TFrameWindow)
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrinterSetup),
END_RESPONSE_TABLE;

TRulerWin::TRulerWin(TWindow* parent, const char* title, TModule* module)
  : TFrameWindow(parent, title, 0, FALSE, module)
{
  AssignMenu("RulerMenu");
  Attr.X = GetSystemMetrics(SM_CXSCREEN) / 8;
  Attr.Y = GetSystemMetrics(SM_CYSCREEN) / 8;
  Attr.H = Attr.Y * 6;
  Attr.W = Attr.X * 6;
  Printer = new TPrinter;
}

TRulerWin::~TRulerWin()
{
  delete Printer;
}

void
TRulerWin::CmFilePrint()          // Execute File:Print command
{
  if (Printer) {
    TWindowPrintout printout("Ruler Test", this);
    printout.SetBanding(TRUE);
    Printer->Print(this, printout, TRUE);
  }
}

void
TRulerWin::CmFilePrinterSetup()    // Execute File:Printer-setup command
{
  if (Printer)
    Printer->Setup(this);
}

// Paint window's contents on any dc, screen or printer or whatever...
//
void
TRulerWin::Paint(TDC& dc, BOOL, TRect&)
{
  const UnitsPerInch = 100;                // Display scale units per inch
  const NumInches = 8;                     // Size of ruler in inches
  const MarkFraction = 4;                  // Power of 2 to use for marks
  const MarksPerInch = (1<<MarkFraction);  // Number of markers for each inch
  const LargeMarkerSize = UnitsPerInch/3;  // Size of large, labeled markers
  const SmallMarkerSize = UnitsPerInch/8;  // Size of smallest markers
  const MarkStep = (LargeMarkerSize-SmallMarkerSize) / MarkFraction;

  dc.SaveDC();
  dc.SetMapMode(MM_LOENGLISH);
  int x1 = 0; //0.50 * UnitsPerInch;
  int y1 = x1;
  int x2 = x1 + NumInches * UnitsPerInch;
  int y2 = y1 + 1*UnitsPerInch;
  dc.Rectangle(x1, -y1, x2, -y2);

  //
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

  //
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


//----------------------------------------------------------------------------
// TRulerApp

class TRulerApp : public TApplication {
  public:
    TRulerApp() : TApplication() {}
    void InitMainWindow() {
      EnableCtl3d();
      MainWindow = new TRulerWin(0, "Ruler Printing Demonstration");
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TRulerApp().Run();
}
