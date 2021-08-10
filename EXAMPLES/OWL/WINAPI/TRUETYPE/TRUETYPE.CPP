//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dialog.h>
#include <owl\dc.h>
#include <owl\choosefo.h>
#include <owl\printer.h>
#include <owl\editfile.rh>
#include <string.h>
#include <math.h>
#include "truetype.h"

inline double Round(double x) {return floor(x + .5);}
inline double Sqr(double x)   {return pow(x, 2);}


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
//
class TFontWindow: public TFrameWindow {
  public:
    TFontWindow(TWindow* parent, const char* title);

  protected:
    void Paint(TDC&, BOOL erase, TRect&);

    void EvGetMinMaxInfo(MINMAXINFO far&);
    void EvSize(UINT, TSize&);

    void CmAbout();
    void CmFilePrint();
    void CmAlignmentMarks();
    void CmFonts();
    void CmShadows();

  private:
    LOGFONT   MainFontRec;
    LOGFONT   CornerFontRec;
    LOGFONT   BorlandFontRec;
    TColor    FanColor[10];
    BOOL      ShadowAll;
    BOOL      ShowAlignmentMarks;
    BOOL      Rendering;
    TPrinter* Printer;

  DECLARE_RESPONSE_TABLE(TFontWindow);
};

DEFINE_RESPONSE_TABLE1(TFontWindow, TFrameWindow)
  EV_WM_GETMINMAXINFO,
  EV_WM_SIZE,
  EV_COMMAND(CM_ABOUT, CmAbout),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_ALIGNMENTMARKS, CmAlignmentMarks),
  EV_COMMAND(CM_FONTS, CmFonts),
  EV_COMMAND(CM_SHADOWS, CmShadows),
END_RESPONSE_TABLE;


TFontWindow::TFontWindow(TWindow* parent, const char* title)
  : TFrameWindow(parent, title),
    TWindow(parent, title)
{
  AssignMenu(MR_TRUETYPE);

  MainFontRec.lfHeight = 26;
  MainFontRec.lfWidth = 10;
  MainFontRec.lfEscapement = 0;
  MainFontRec.lfOrientation = 0;
  MainFontRec.lfWeight = FW_BOLD;
  MainFontRec.lfItalic = 0;
  MainFontRec.lfUnderline = 0;
  MainFontRec.lfStrikeOut = 0;
  MainFontRec.lfCharSet = ANSI_CHARSET;
  MainFontRec.lfOutPrecision = OUT_DEFAULT_PRECIS;
  MainFontRec.lfClipPrecision = CLIP_DEFAULT_PRECIS;
  MainFontRec.lfQuality = PROOF_QUALITY;
  MainFontRec.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
  strcpy(MainFontRec.lfFaceName, "Times New Roman");

  CornerFontRec = MainFontRec;

  BorlandFontRec = MainFontRec;
  BorlandFontRec.lfHeight = 60;
  BorlandFontRec.lfWidth = 0;   // choose best width for this height
  BorlandFontRec.lfWeight = 900;
  strcpy(BorlandFontRec.lfFaceName, "Arial");

  // Array of colors used to color the fan text
  FanColor[0] = TColor(255,0,0);
  FanColor[1] = TColor(128,0,0);
  FanColor[2] = TColor(255,128,0);
  FanColor[3] = TColor(80,80,0);
  FanColor[4] = TColor(80,255,0);
  FanColor[5] = TColor(0,128,0);
  FanColor[6] = TColor(0,128,255);
  FanColor[7] = TColor(0,0,255);
  FanColor[8] = TColor(128,128,128);
  FanColor[9] = TColor(255,0,0);

  ShadowAll = 0;
  ShowAlignmentMarks = 0;
  Rendering = 0;
  Printer = new TPrinter;
}

//
// Limit the minimum size of the window to 300x300, so the fonts don't get
// too small
//
void
TFontWindow::EvGetMinMaxInfo(MINMAXINFO far& mminfo)
{
  mminfo.ptMinTrackSize.x = 300;
  mminfo.ptMinTrackSize.y = 300;
}

//
// Set the Re-render flag if the window changes size & is visible
//
void
TFontWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  if (sizeType == SIZENORMAL || sizeType == SIZEFULLSCREEN) {
    Rendering = TRUE;
    Invalidate(TRUE);
  }
}

const char ArcText[] = "TrueType";
const char* WaitText = "Windows is rendering fonts...";
const char* FanText = "Borland C++ for Windows";
const char* BorlandText = "Borland";
const int   Radius = 100;
const float Deg2Rad = M_PI / 18;

void
TFontWindow::Paint(TDC& dc, BOOL, TRect&)
{
  const char* p = ArcText;
  int fanTextLen = strlen(FanText);

  dc.SaveDC();

  if (Rendering)
    // display a message that Windows is rendering fonts, please wait...
    SetWindowText(WaitText);

  LOGFONT fontRec = CornerFontRec;
  dc.SetBkMode(TRANSPARENT);
  dc.SetTextColor(TColor(128,128,128));
  fontRec.lfHeight = fontRec.lfHeight * 2;
  fontRec.lfWidth = floor(fontRec.lfWidth * 2.1);
  TFont* font = new TFont(&fontRec);
  dc.SelectObject(*font);
  dc.TextOut(18, 5, "T", 1);
  dc.SetTextColor(TColor(0,0,0));
  dc.TextOut(32, 13,"T", 1);
  dc.RestoreFont();
  delete font;

  TRect r = GetClientRect();

  fontRec = MainFontRec;
  font = new TFont(&fontRec);
  dc.SelectObject(*font);
  
  UINT fmSize = ::GetOutlineTextMetrics(HDC(dc), 0, 0);
  OUTLINETEXTMETRIC* fontMetric = (OUTLINETEXTMETRIC*)new char[fmSize];
  fontMetric->otmpFamilyName = 0;
  fontMetric->otmpFaceName = 0;
  fontMetric->otmpStyleName = 0;
  fontMetric->otmpFullName = 0;
  dc.GetOutlineTextMetrics(fmSize, *fontMetric);
  int fontHeight = fontMetric->otmTextMetrics.tmHeight;
  dc.SetViewportOrg(fontHeight+2, 0);
  r.right -= fontHeight+2;
  TSize size;
  dc.GetTextExtent(FanText, fanTextLen, size);
  int baseWidth = size.cx;
  dc.RestoreFont();
  delete font;

  dc.SelectStockObject(NULL_BRUSH);
  if (ShowAlignmentMarks)
    dc.Ellipse( -r.right, -r.bottom, r.right, r.bottom);
  dc.Ellipse(-(Radius-5), -(Radius-5), Radius-5, Radius-5);
  dc.Ellipse(-(Radius-10), -(Radius-10), Radius-10, Radius-10);

  dc.SetTextColor(FanColor[0]);
  for (int d = 27; d <= 36; d++) {
    int x = Round(Radius * cos(d * Deg2Rad));
    int y = Round(Radius * sin(-d * Deg2Rad)); //-d because y axis is inverted

    float theta = -d * Deg2Rad;
    if (x)
      theta = atan((r.right / (r.bottom * 1.0)) * (y / (x * 1.0)));
    int j = Round(r.right * cos(theta));
    int k = Round(r.bottom * sin(theta));

    if (ShowAlignmentMarks) {
      dc.MoveTo(x,y);
      dc.LineTo(j,k);
    }

    int desiredExtent = Round(sqrt(Sqr(x*1.0 - j) + Sqr(y*1.0 - k))) - 5;
    fontRec = MainFontRec;
    fontRec.lfEscapement = d * 100;
    fontRec.lfOrientation = d * 100;
    fontRec.lfWidth = floor(fontMetric->otmTextMetrics.tmAveCharWidth * (desiredExtent / (baseWidth * 1.0)));
    font = new TFont(&fontRec);
    dc.SelectObject(*font);

    // Shave off some character width until the string fits
    //
    dc.GetTextExtent(FanText, fanTextLen, size);
    for (; size.cx > desiredExtent && fontRec.lfWidth; fontRec.lfWidth--) {
      dc.RestoreFont();
      delete font;
      font = new TFont(&fontRec);
      dc.SelectObject(*font);
      dc.GetTextExtent(FanText, fanTextLen, size);
    }

    // Expand the string if necessary to make it fit the desired extent
    if (size.cx < desiredExtent)
      dc.SetTextJustification(desiredExtent - size.cx, 3);
    if (ShadowAll) {
      dc.SetTextColor(TColor(0,0,0));
      dc.TextOut(x+2, y+1, FanText, fanTextLen);
    }
    dc.SetTextColor(FanColor[d - 27]);
    dc.TextOut(x, y, FanText, fanTextLen);
    dc.SetTextJustification(0,0);  // clear justifier's internal error accumulator
    dc.RestoreFont();
    delete font;

    if (*p) {
      fontRec = CornerFontRec;
      fontRec.lfEscapement = (d+10) * 100;
      fontRec.lfOrientation = (d+10) * 100;
      fontRec.lfWidth = 0;
      font = new TFont(&fontRec);
      dc.SelectObject(*font);
      dc.SetTextColor(0);
      x = floor((Radius - fontHeight - 5) * cos(d * Deg2Rad));
      y = floor((Radius - fontHeight - 5) * sin(-d * Deg2Rad));
      dc.TextOut(x, y, p, 1);
      dc.RestoreFont();
      delete font;
      p++;
    }
  }

  font = new TFont(&BorlandFontRec);
  dc.SelectObject(*font);
  dc.GetTextExtent(BorlandText, strlen(BorlandText), size);
  dc.SetTextColor(TColor(0,0,0));
  dc.TextOut(r.right-size.cx, r.bottom-size.cy, BorlandText, strlen(BorlandText));
  dc.SetTextColor(TColor(255,0,0));
  dc.TextOut(r.right-size.cx-5, r.bottom-size.cy, BorlandText, strlen(BorlandText));
  dc.RestoreFont();
  delete font;

  if (Rendering) {
    // restore the window caption to the proper title string
    SetWindowText(Title);
    // clear the rendering flag.  It will be set again when the window is resized (WMSIZE)
    Rendering = FALSE;
  }

  dc.RestoreDC();
  delete fontMetric;
}

void
TFontWindow::CmShadows()
{
  ShadowAll = !ShadowAll;
  CheckMenuItem(GetMenu(), CM_SHADOWS,
                MF_BYCOMMAND | (ShadowAll ? MF_CHECKED : MF_UNCHECKED));
  Invalidate(!ShadowAll);  // Erase if going Shadow -> no Shadow
}

void
TFontWindow::CmAlignmentMarks()
{
  ShowAlignmentMarks = !ShowAlignmentMarks;
  CheckMenuItem(GetMenu(), CM_ALIGNMENTMARKS,
                MF_BYCOMMAND | (ShowAlignmentMarks ? MF_CHECKED : MF_UNCHECKED));
  Invalidate(!ShowAlignmentMarks);  // Erase if going Marks -> no Marks
}

void
TFontWindow::CmAbout()
{
  TDialog(this, "About").Execute();
}

void
TFontWindow::CmFilePrint()
{
  if (Printer) {
    TWindowPrintout printout("True Type Printout", this);
    printout.SetBanding(TRUE);
    Printer->Print(this, printout, TRUE);
  }
}

void
TFontWindow::CmFonts()
{
  TChooseFontDialog::TData fontData;
  fontData.LogFont = MainFontRec;
  fontData.Flags = CF_ANSIONLY | CF_TTONLY | CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT;
  fontData.FontType = SCREEN_FONTTYPE;
  fontData.SizeMin = 20;
  fontData.SizeMax = 20;

  if (TChooseFontDialog(this, fontData, "FontDlg").Execute()) {
    // Only get the font name, weight, and italics - we don't care about size
    strcpy(MainFontRec.lfFaceName, fontData.LogFont.lfFaceName);
    MainFontRec.lfWeight = fontData.LogFont.lfWeight;
    MainFontRec.lfItalic = fontData.LogFont.lfItalic;
    Rendering = TRUE;
    Invalidate(TRUE);
  }
}

//----------------------------------------------------------------------------

class TFontApp : public TApplication {
  public:
    TFontApp() : TApplication() {}
    void InitMainWindow()
    {
      MainWindow = new TFontWindow(0, "TrueType Font Lab");
      MainWindow->SetIcon(this, 1);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TFontApp().Run();
}
