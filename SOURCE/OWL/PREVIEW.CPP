//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of print preview classes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_PREVIEW_H)
# include <owl/preview.h>
#endif
#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_PRINTDIA_H)
# include <owl/printdia.h>
#endif
#include <math.h>

OWL_DIAGINFO;

//
// Some inlines to provide platform independence since we drop directly to API
// calls to implement some of TPrintPreviewDC.
//
#if defined(BI_PLAT_WIN32)
  inline bool SetWindowExt(HDC hdc, int w, int h) {return ::SetWindowExtEx(hdc, w, h, 0);}
  inline bool SetWindowOrg(HDC hdc, int w, int h) {return ::SetWindowOrgEx(hdc, w, h, 0);}
  inline bool SetViewportExt(HDC hdc, int w, int h) {return ::SetViewportExtEx(hdc, w, h, 0);}
  inline bool SetViewportOrg(HDC hdc, int x, int y) {return ::SetViewportOrgEx(hdc, x, y, 0);}
#endif


//
// Construct a basic Preview DC
//
TPreviewDCBase::TPreviewDCBase(TDC&      screen,
                               TPrintDC& printdc)
:
  TPrintDC(screen),
  PrnDC(printdc)
{}

//
//
//
HDC
TPreviewDCBase::GetAttributeHDC() const
{
  return PrnDC;
}

//
// Construct a Print Preview Device context
//
TPrintPreviewDC::TPrintPreviewDC(TDC&         screen,
                                 TPrintDC&    printdc,
                                 const TRect& client,
                                 const TRect& clip)
:
  TPreviewDCBase(screen, printdc),
  PrnFont(0),
  CurrentPreviewFont(0)
{
  //
  // Set the initial mode & extents for the screen dc
  //
  ::SetMapMode(GetHDC(), MM_ANISOTROPIC);
  ::SetWindowExt(GetHDC(), client.Width(), client.Height());
  ::SetViewportExt(GetHDC(), client.Width(), client.Height());

  //
  // Static call to virtual method, but some mapping must be done now.
  //
  ReScale();

  //
  // Assume clip rect is in device points - DPs are same in new viewport
  //
  SelectClipRgn(clip);
  PrnFont = (HFONT)PrnDC.GetCurrentObject(OBJ_FONT);
  SyncFont();
}

//
//
//
TPrintPreviewDC::~TPrintPreviewDC()
{
  // cleanup screen dc
  //
  ::DeleteObject(::SelectObject(GetHDC(), ::GetStockObject(SYSTEM_FONT)));
  delete CurrentPreviewFont;
}

//
// Intercept setting of the printer font, making & keeping a copy of it and
// calling SyncFont if needed to recreate the preview font.
//
void
TPrintPreviewDC::SelectObject(const TFont& newFont)
{
  if ((HFONT)newFont) {
    LOGFONT   lf;
    newFont.GetObject(lf);

    TFont*  oldPreviewF = CurrentPreviewFont;
    CurrentPreviewFont = new TFont(&lf);

    PrnDC.SelectObject(*CurrentPreviewFont);
    delete oldPreviewF;

    if ((HFONT)(*CurrentPreviewFont) != PrnFont) {
      PrnFont = (HFONT)(*CurrentPreviewFont);
      SyncFont();
    }
  }
}

//
//
//
void
TPrintPreviewDC::SelectStockObject(int index)
{
  PrnDC.SelectStockObject(index);
  switch (index) {
    case ANSI_FIXED_FONT:
    case ANSI_VAR_FONT:
    case DEVICE_DEFAULT_FONT:
    case OEM_FIXED_FONT:
    case SYSTEM_FONT:
    case SYSTEM_FIXED_FONT: {
      HFONT stockFont = (HFONT)GetStockObject(index);
      if (stockFont != PrnFont) {
        PrnFont = stockFont;
        SyncFont();
      }
      break;
    }
    default:
      TPrintDC::SelectStockObject(index);
  }
}

//
//
//
void
TPrintPreviewDC::RestoreFont()
{
  PrnDC.RestoreFont();
  PrnFont = (HFONT)PrnDC.GetCurrentObject(OBJ_FONT);
  TPrintDC::RestoreFont();
  SyncFont();
}

//
//
//
int
TPrintPreviewDC::GetDeviceCaps(int index) const
{
  switch (index) {
    case CLIPCAPS:
    case RASTERCAPS:
    case CURVECAPS:
    case LINECAPS:
    case POLYGONALCAPS:
    case TEXTCAPS:      // report capabilities supported on both devices
      return PrnDC.GetDeviceCaps(index) & TPrintDC::GetDeviceCaps(index);

      // otherwise, report printer caps and let GDI sort out differences
    default:
      return PrnDC.GetDeviceCaps(index);
  }
}

//
//
//
inline int
GlyphHeight(TEXTMETRIC& tm)
{
  return tm.tmHeight < 0
            ? tm.tmHeight
            : -(tm.tmHeight - tm.tmInternalLeading);
}

//
// SyncFont performs a simple font match attempt, with a retry option if
// the GDI selected match is too different from the selected printer font.
// In print preview, matching the size of the characters is more important
// than matching their appearance.  In most cases, the print preview will
// barely be legible anyway.  Size is most important because you don't
// want character size differences to change the line breaks or page
// breaks of the on-screen document from what they would be on the
// printed page.  This effect is minimized in this TPrintPreviewDC object,
// since info reports such as GetTextMetrics and GetTextExtent are always
// reported from the printer dc using the real font.  Internal calculations
// should be the same for preview as for printing, but the output accuracy
// will depend upon the accuracy of font selection.
//
// It is also possible to take over control of the text output functions
// through this DC object - the TextOut and other text methods are virtual.
// You can place each character on the preview screen yourself, if you
// desire more precision in character placement than GDI's font matching
// can provide.  That's a lot of work, and a lot of code, and isn't
// necessary to meet the needs of most applications.
//
// SyncFont is virtual so that you may substitute your own font matching
// algorythm with more font matching heuristics.
//
void
TPrintPreviewDC::SyncFont()
{
  //
  // set screen font to match current printer font.
  //
  LOGFONT lf;
  ::GetObject(PrnFont, sizeof(lf), &lf);

  TEXTMETRIC tm;
  PrnDC.GetTextMetrics(tm);

  lf.lfHeight         = GlyphHeight(tm);
  lf.lfWidth          = tm.tmAveCharWidth;
  lf.lfWeight         = tm.tmWeight;
  lf.lfItalic         = tm.tmItalic;
  lf.lfUnderline      = tm.tmUnderlined;
  lf.lfStrikeOut      = tm.tmStruckOut;
  lf.lfCharSet        = tm.tmCharSet;
  lf.lfOutPrecision   = OUT_TT_PRECIS;
  lf.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
  lf.lfQuality        = DRAFT_QUALITY;

  // Keep just the pitch (low 2 bits). Ignore the family
  //
  lf.lfPitchAndFamily = uint8((tm.tmPitchAndFamily & 0x0003) | FF_DONTCARE);
  PrnDC.GetTextFace(sizeof(lf.lfFaceName), lf.lfFaceName);

  ::DeleteObject(::SelectObject(GetHDC(), ::CreateFontIndirect(&lf)));

  //
  // if height isn't right, relax the font pitch and facename requirements
  //
  GetTextMetrics(tm);
  if (abs(abs(lf.lfHeight) - abs(GlyphHeight(tm))) > 2) {
    if (lf.lfPitchAndFamily & FF_DECORATIVE)
      lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DECORATIVE;
    else
      lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
    lf.lfFaceName[0] = 0;
    ::DeleteObject(::SelectObject(GetHDC(), CreateFontIndirect(&lf)));
  }
}

//
// Rescale the preview DC by adjusting its window & viewport
//
// Assume the viewport extent (scrve) is set to the size of the window
// client area.  All we have to do to map the addressable points of the
// printer DC into the screen DC, then, is set the screen window extent
// equal to the maximum addressable logical point of the printer dc.
// PrnDC.DPtoLP will pull the device point through the printer's mapping
// mode conversions, giving us the maximum point we should allow on the
// screen dc.
//
void
TPrintPreviewDC::ReScale()
{
  TSize scrve;
  ::GetViewportExtEx(GetHDC(), &scrve);

  TPoint scrwe(PrnDC.GetDeviceCaps(HORZRES), PrnDC.GetDeviceCaps(VERTRES));
  PrnDC.DPtoLP(&scrwe);

  ::SetMapMode(GetHDC(), MM_ANISOTROPIC);
  ::SetWindowExt(GetHDC(), scrwe.x, scrwe.y);
  ::SetViewportExt(GetHDC(), scrve.cx, scrve.cy);
  ReOrg();
}

//
// Reset the DC's origin
//
void
TPrintPreviewDC::ReOrg()
{
  TPoint origin = PrnDC.GetViewportOrg();
  PrnDC.DPtoLP(&origin);
  LPtoSDP(&origin);
  ::SetViewportOrg(GetHDC(), origin.x, origin.y);

  PrnDC.GetWindowOrg(origin);
  ::SetWindowOrg(GetHDC(), origin.x, origin.y);
}

//
//
//
TColor
TPrintPreviewDC::SetBkColor(const TColor& color)
{
  TColor result = PrnDC.SetBkColor(color);
  ::SetBkColor(GetHDC(), PrnDC.GetBkColor());
  return result;
}

//
//
//
TColor
TPrintPreviewDC::SetTextColor(const TColor& color)
{
  TColor result = PrnDC.SetTextColor(color);
  ::SetTextColor(GetHDC(), PrnDC.GetTextColor());
  return result;
}

//
//
//
int
TPrintPreviewDC::SetMapMode(int mode)
{
  int result = PrnDC.SetMapMode(mode);
  ReScale();
  return result;
}

//
//
//
bool
TPrintPreviewDC::SetViewportOrg(const TPoint& origin, TPoint far* oldOrg)
{
  bool result = PrnDC.SetViewportOrg(origin, oldOrg);
  ReOrg();
  return result;
}

//
//
//
bool
TPrintPreviewDC::OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg)
{
  bool result = PrnDC.OffsetViewportOrg(delta, oldOrg);
  ReOrg();
  return result;
}

//
//
//
bool
TPrintPreviewDC::SetViewportExt(const TSize& extent, TSize far* oldExtent)
{
  bool result = PrnDC.SetViewportExt(extent, oldExtent);
  ReScale();
  return result;
}

bool
TPrintPreviewDC::ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                                  TSize far* oldExtent)
{
  bool result = PrnDC.ScaleViewportExt( xNum, xDenom, yNum, yDenom, oldExtent);
  ReScale();
  return result;
}

bool
TPrintPreviewDC::SetWindowExt(const TSize& extent, TSize far* oldExtent)
{
  bool result = PrnDC.SetWindowExt(extent, oldExtent);
  ReScale();
  return result;
}

//
//
//
bool
TPrintPreviewDC::ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom,
                                TSize far* oldExtent)
{
  bool result = PrnDC.ScaleWindowExt(xNum, xDenom, yNum, yDenom, oldExtent);
  ReScale();
  return result;
}


DEFINE_RESPONSE_TABLE1(TPreviewPage, TWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TPreviewPage);

//
//
//
TPreviewPage::TPreviewPage(TWindow* parent, TPrintout& printout,
                           TPrintDC& prndc, TSize& printExtent, int pagenum)
:
  TWindow(parent),
  Printout(printout),
  PrintDC(prndc),
  PrintExtent(printExtent),
  PageNum(pagenum)
{
  Attr.Style = WS_CHILD | WS_BORDER | WS_VISIBLE;
  SetBkgndColor(TColor::White);
}

//
//
//
void
TPreviewPage::SetPageNumber(int newNum)
{
  PageNum = newNum;
  if (GetHandle())
    Invalidate();
}

//
// Using a TPrintPreviewDC, 'print' the current page (PageNum) of Printout
// onto the window DC provided,
//
void
TPreviewPage::Paint(TDC& dc, bool, TRect& clip)
{
  TPrintPreviewDC pdc(dc, PrintDC, GetClientRect(), clip);
  Printout.SetPrintParams(&pdc, PrintExtent);

  if (Printout.HasPage(PageNum)) {
    Printout.BeginPrinting();
    Printout.BeginDocument(PageNum, PageNum, pfBoth);

    // Change clip rect into the shared logical coordinate space, & print
    //
    pdc.SDPtoLP(clip);
    Printout.PrintPage(PageNum, clip, pfBoth);

    Printout.EndDocument();
    Printout.EndPrinting();
  }
  else
    dc.PatBlt(0, 0, Attr.W, Attr.H, WHITENESS);
}

//
// Always repaint whole window if size is changed
//
void
TPreviewPage::EvSize(uint sizeType, TSize& size)
{
  Invalidate();
  TWindow::EvSize(sizeType, size);
}
