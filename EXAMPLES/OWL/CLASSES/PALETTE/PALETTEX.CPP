//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/dc.h>
#include <alloc.h>
#include "palette.h"

const int BoxW = 20;
const int BoxH = 20;
const int NumColors = 48;
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

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow();
   ~TTestWindow();

    void EvSize(uint, TSize&);
    void Paint(TDC& dc, bool erase, TRect& rect);
    void EvLButtonDown(uint, TPoint&);
    void CmAbout();

    LOGPALETTE* MyLogPalette; // Logical palette struct filled with colors
    bool        PalDevice;    // does display have a physical palette?

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_LBUTTONDOWN,
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
:
  TWindow(0, 0, 0)
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

  TScreenDC screenDC;
  PalDevice = (screenDC.GetDeviceCaps(RASTERCAPS) & RC_PALETTE) ? true : false;
}

TTestWindow::~TTestWindow()
{
  delete[] MyLogPalette;
}

void
TTestWindow::EvSize(uint how, TSize& sz)
{
  TWindow::EvSize(how, sz);
  Invalidate(true);
}

void
TTestWindow::Paint(TDC& paintDC, bool /*erase*/, TRect& /*rect*/)
{
  TPalette palette(MyLogPalette);
  paintDC.SelectObject(palette);
  paintDC.RealizePalette();

  TRect rect;
  GetClientRect(rect);
  int hc = rect.Width() / BoxW;

  for (int i = 0; i < NumColors; i++) {
    TColor palColor(i);
    int x = (i % hc) * BoxW;
    int y = (i / hc) * BoxH;
    paintDC.TextRect(x, y, x+BoxW, y+BoxH, palColor);
    paintDC.RestoreBrush();
  }
}

void
TTestWindow::EvLButtonDown(uint, TPoint&)
{
  PALETTEENTRY PaletteEntry = MyLogPalette->palPalEntry[0];

  int i;
  for (i = 0; i < NumColors-1; i++)
    MyLogPalette->palPalEntry[i] = MyLogPalette->palPalEntry[i + 1];
  MyLogPalette->palPalEntry[i] = PaletteEntry;

  if (PalDevice) {
    TClientDC paintDC(*this);
    TPalette Palette(MyLogPalette);
    paintDC.SelectObject(Palette);
    paintDC.RealizePalette();
    paintDC.RestorePalette();
  }
  else
    Invalidate(true);
}

void
TTestWindow::CmAbout()
{
  TDialog(this, IDD_ABOUT).Execute();
}

//----------------------------------------------------------------------------

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp()
    :
      TApplication()
    {
    }

    virtual void InitMainWindow();
};

void
TTestApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Palette Tester", new TTestWindow);
  frame->AssignMenu(IDM_PALTEST);

  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
