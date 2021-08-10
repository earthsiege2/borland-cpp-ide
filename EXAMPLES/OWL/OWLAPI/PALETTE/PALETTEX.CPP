//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dialog.h>
#include <owl\dc.h>
#include <alloc.h>
#include "palettex.h"

const int BoxW = 20;
const int BoxH = 20;
const NumColors = 48;
const TColor Colors[NumColors] = {
  0x00FFFFFFl,0x00E0E0E0l,0x00C0C0FFl,0x00C0E0FFl,0x00E0FFFFl,0x00C0FFC0l,
  0x00FFFFC0l,0x00FFC0C0l,0x00FFC0FFl,0x000000C0l,0x000040C0l,0x0000C0C0l,
  0x0000C000l,0x00C0C000l,0x00C00000l,0x00C000C0l,
  0x00C0C0C0l,0x00404040l,0x008080FFl,0x0080C0FFl,0x0080FFFFl,0x0080FF80l,
  0x00FFFF80l,0x00FF8080l,0x00FF80FFl,0x00000080l,0x00004080l,0x00008080l,
  0x00008000l,0x00808000l,0x00800000l,0x00800080l,
  0x00808080l,0x00000000l,0x000000FFl,0x000080FFl,0x0000FFFFl,0x0000FF00l,
  0x00FFFF00l,0x00FF0000l,0x00FF00FFl,0x00000040l,0x00404080l,0x00004040l,
  0x00004000l,0x00404000l,0x00400000l,0x00400040l
};

class TTestWindow : public TWindow {
  public:
    LOGPALETTE* MyLogPalette; // Logical palette struct filled with colors
    BOOL        PalDevice;    // does display have a physical palette?

    TTestWindow();
    ~TTestWindow();

    void EvSize(UINT, TSize &);
    void EvPaint();
    void EvLButtonDown(UINT, TPoint&);
    void CmAbout();
 
  DECLARE_RESPONSE_TABLE(TTestWindow);
};
DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
{
  MyLogPalette = (LOGPALETTE*)new char[sizeof(LOGPALETTE) + sizeof(PALETTEENTRY) * NumColors];
  MyLogPalette->palVersion = 0x300;
  MyLogPalette->palNumEntries = NumColors;
  for (int i = 0; i < NumColors; ++i) {
    MyLogPalette->palPalEntry[i].peRed = Colors[i].Red();
    MyLogPalette->palPalEntry[i].peGreen = Colors[i].Green();
    MyLogPalette->palPalEntry[i].peBlue = Colors[i].Blue();
    MyLogPalette->palPalEntry[i].peFlags = PC_RESERVED;
  }
  
  TScreenDC  screenDC;
  PalDevice = (screenDC.GetDeviceCaps(RASTERCAPS) & RC_PALETTE) ? TRUE : FALSE;
}

TTestWindow::~TTestWindow()
{
  delete MyLogPalette;
}

void
TTestWindow::EvSize(UINT, TSize &)
{
  Invalidate(TRUE);
}

void
TTestWindow::EvPaint()
{
  TPaintDC paintDC(HWindow);
  TPalette Palette(MyLogPalette);
  paintDC.SelectObject(Palette);
  paintDC.RealizePalette();

  TRect rect;
  GetClientRect(rect);
  int hc = rect.Width() / BoxW;
  for (int i = 0; i < NumColors; i++) {
    TColor palColor(i);
    TBrush brush(palColor);
    paintDC.SelectObject(brush);
    int x = (i % hc) * BoxW;  
    int y = (i / hc) * BoxH;
    paintDC.Rectangle(x, y, x+BoxW, y+BoxH);
    paintDC.RestoreBrush();
  }
  paintDC.RestorePalette();
}

void
TTestWindow::EvLButtonDown(UINT, TPoint&)
{
  PALETTEENTRY PaletteEntry = MyLogPalette->palPalEntry[0];
  for (int i = 0; i < NumColors-1; i++)
    MyLogPalette->palPalEntry[i] = MyLogPalette->palPalEntry[i + 1];
  MyLogPalette->palPalEntry[i] = PaletteEntry;

  if (PalDevice) {
    TClientDC paintDC(HWindow);
    TPalette Palette(MyLogPalette);
    paintDC.SelectObject(Palette);
    paintDC.RealizePalette();
    paintDC.RestorePalette();
  } else
    Invalidate(FALSE);
}

void
TTestWindow::CmAbout()
{
  TDialog(this, "ABOUT").Execute();
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
  TTestApp() : TApplication() {}
  virtual void InitMainWindow();
};

void
TTestApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Palette Tester", new TTestWindow);
  frame->AssignMenu("PALTEST_MENU");
  frame->EnableKBHandler();
  MainWindow = frame;
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
