//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Implementation of the Help | About menu choice.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/propsht.h>
#include <owl/dibitmap.h>
#include <owl/button.h>
#include <owl/mci.h>
#include <winsys/uimetric.h>
#include "blazer.h"
#include "propdlgs.h"

int RandomMax     = 4;
int AbsoluteDelta = 7;

DEFINE_RESPONSE_TABLE1(TSpeedBallWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_PALETTECHANGED,
  EV_WM_QUERYNEWPALETTE,
END_RESPONSE_TABLE;

//
// TSpeedBallWindow Contructor (WinG bouncing ball)
// Initializes variables.
//
TSpeedBallWindow::TSpeedBallWindow(TWindow* w)
:
  TWindow(w, 0),
  ClientDC(0),
  DisplayBitmap(0),
  BlitterBlocks(true),
  EnableSound(false),
  Delay(1)
{
  TDib ballDib(*::Application, TResId(IDB_BALL));
  Palette   = new TPalette(ballDib);

  DisplayDC = new TDibDC;
  BallDC    = new TDibDC;

  BallBitmap = new TDiBitmap(ballDib);
  BallDC->SelectObject(*BallBitmap);
  BallDC->StretchDIBits(TRect(0, 0, BallBitmap->Width(), BallBitmap->Height()),
                        TRect(0, 0, BallBitmap->Width(), BallBitmap->Height()),
                        ballDib);
  XPosition = 0;
  YPosition = 0;
  XDelta = random(RandomMax) + AbsoluteDelta;
  YDelta = random(RandomMax) + AbsoluteDelta;

  WaveAudio = new TMciWaveAudio("boing.wav");
}

//
// TSpeedBallWindow Cleanup with a valid HWindow.
//
void
TSpeedBallWindow::CleanupWindow()
{
  delete ClientDC;
  delete Palette;
  delete BallDC;
  delete DisplayDC;
  delete BallBitmap;
  delete DisplayBitmap;
  delete WaveAudio;
}


//
// TSpeedBallWindow Paint.
// Activates Palette, then blit's current double buffer.
//
void
TSpeedBallWindow::Paint(TDC& dc, bool, TRect&)
{
  dc.SelectObject(*Palette);
  dc.RealizePalette();
  DisplayDC->BitBltToScreen(dc, 0, 0,
                            DisplayBitmap->Width(), DisplayBitmap->Height());
}

//
// TSpeedBallWindow IdleAction.
// When nothing needs to be processed step the image then update the
// display.
//
bool
TSpeedBallWindow::IdleAction(long)
{
  // No need to call the base class because it does not do anything.
  //
  bool bounce = false;

  static uint32 timesCalled = 0;

  if (++timesCalled % Delay != 0)
    return true;

  if (DisplayBitmap) {
    if (BlitterBlocks)
      DisplayBitmap->CopyBlt(XPosition, YPosition, *BallBitmap, 0, 0);
    else
      DisplayBitmap->SpriteBlt(XPosition, YPosition, *BallBitmap, 0, 0);

    DisplayDC->BitBltToScreen(*ClientDC, XPosition, YPosition, 110, 110, XPosition, YPosition);

    XPosition += XDelta;
    YPosition += YDelta;

    if (XPosition > XLimit) {
      XPosition = XLimit;
      XDelta = -(random(RandomMax) + AbsoluteDelta);
      bounce = true;
    }

    if (XPosition < 0) {
      XPosition = 0;
      XDelta = random(RandomMax) + AbsoluteDelta;
      bounce = true;
    }

    if (YPosition > YLimit) {
      YPosition = YLimit;
      YDelta = -(random(RandomMax) + AbsoluteDelta);
      bounce = true;
    }

    if (YPosition < 0) {
      YPosition = 0;
      YDelta = random(RandomMax) + AbsoluteDelta;
      bounce = true;
    }

    if (bounce && EnableSound && WaveAudio) {
      WaveAudio->Play(MCI_NOTIFY);
    }
  }

  return true;
}


//
//
//
void
TSpeedBallWindow::EvPaletteChanged(HWND hWndPalChg)
{
  if (hWndPalChg != GetHandle()) {
    TClientDC clientDC(*this);
#if defined(BI_PLAT_WIN16)
    Palette->UnrealizeObject();
#endif
    clientDC.SelectObject(*Palette, true);
    bool needsUpdate = clientDC.RealizePalette() > 0;
    if (needsUpdate)
      Invalidate(false);
  }
}


//
//
//
bool
TSpeedBallWindow::EvQueryNewPalette()
{
  if (ClientDC && Palette) {
    ClientDC->SelectObject(*Palette);
    ClientDC->RealizePalette();
  }
  return true;
}


//
// When the size changes create a new double buffer.
//
void
TSpeedBallWindow::EvSize(uint, TSize& newSize)
{
  if (DisplayDC && newSize.cx && newSize.cy) {
    TDiBitmap* newBitmap = new TDiBitmap(newSize.cx, newSize.cy, 256);
    DisplayDC->SelectObject(*newBitmap);

    delete DisplayBitmap;
    DisplayBitmap = newBitmap;

    DisplayDC->PatBlt(0, 0, newSize.cx, newSize.cy, BLACKNESS);
    DisplayDC->BitBltToScreen(*ClientDC, 0, 0, newSize.cx, newSize.cy);

    XLimit = newSize.cx - BallBitmap->Width();
    YLimit = newSize.cy - BallBitmap->Height();
  }
}

//
// TSpeedBallWindow SetupWindow.
// Create WinG DC's, Bitmaps and double buffers.
// Select objects into appropriate DC's.
//
void
TSpeedBallWindow::SetupWindow()
{
  TWindow::SetupWindow();

  ClientDC = new TClientDC(*this);
}


//
// TAboutWindow constructor
//
TAboutWindow::TAboutWindow(TWindow* parent)
:
  TLayoutWindow(parent, 0)
{
  const int SpeedBallPercent = 90;

  // Create the child controls.
  // The WinG bouncing ball takes up 90 percent of the parent's height
  //
  SpeedBall = new TSpeedBallWindow(this);
  TLayoutMetrics lmSpeedBall;
  lmSpeedBall.X.SameAs(lmParent, lmLeft);
  lmSpeedBall.Y.SameAs(lmParent, lmTop);
  lmSpeedBall.Width.SameAs(lmParent, lmWidth);
  lmSpeedBall.Height.PercentOf(lmParent, SpeedBallPercent);
  SetChildLayoutMetrics(*SpeedBall, lmSpeedBall);

  // Ok button is 10 percent of parent's height and 1/3 its width.
  //
  Ok = new TButton(this, IDOK, "O&k", 10, 10, 10, 10, true);
  TLayoutMetrics lmOk;
  lmOk.X.SameAs(lmParent, lmLeft);
  lmOk.Y.Below(SpeedBall, 1);
  lmOk.Width.PercentOf(lmParent, 33);
  lmOk.Height.PercentOf(lmParent, 100 - SpeedBallPercent);
  SetChildLayoutMetrics(*Ok, lmOk);

  // Help button is same size as the Ok button but to the right of it
  //
  Help = new TButton(this, IDHELP, "&Help", 10, 10, 10, 10);
  TLayoutMetrics lmHelp;
  lmHelp.X.RightOf(Ok, 1);
  lmHelp.Y.Below(SpeedBall, 1);
  lmHelp.Width.SameAs(Ok);
  lmHelp.Height.SameAs(Ok);
  SetChildLayoutMetrics(*Help, lmHelp);

  // Option button is same size as the Ok button but to the right of
  // the help button.
  //
  Options = new TButton(this, OPTIONSID, "&Options", 10, 10, 10, 10);
  TLayoutMetrics lmOptions;
  lmOptions.X.RightOf(Help, 1);
  lmOptions.Y.Below(SpeedBall, 1);
  lmOptions.Width.SameAs(Ok);
  lmOptions.Height.SameAs(Ok);
  SetChildLayoutMetrics(*Options, lmOptions);

  SetAcceleratorTable(IDA_ABOUT);

  // Center the about window
  //
  Attr.Style = WS_POPUP | WS_THICKFRAME | WS_VISIBLE | WS_CAPTION;
  Attr.X = TUIMetric::CxFullScreen / 4;
  Attr.Y = TUIMetric::CyFullScreen / 4;
  Attr.W = TUIMetric::CxFullScreen / 2;
  Attr.H = TUIMetric::CyFullScreen / 2;
  SetCaption("About Blazer");

  // Give it a context menu
  //
  TMenu contextMenu(*::Application, IDM_AWCONTEXTMENU);
  AssignContextMenu(new TPopupMenu(contextMenu));
}


DEFINE_RESPONSE_TABLE1(TAboutWindow, TLayoutWindow)
  EV_WM_GETMINMAXINFO,
  EV_COMMAND(IDOK, CmOk),
  EV_COMMAND(IDHELP, CmHelp),
  EV_COMMAND(OPTIONSID, CmOptions),
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TAboutWindow)
  HCENTRY_MENU_AND_CONTROL(IDH_ABOUTOK,      IDOK,      IDOK),
  HCENTRY_MENU_AND_CONTROL(IDH_ABOUTHELP,    IDHELP,    IDHELP),
  HCENTRY_MENU_AND_CONTROL(IDH_ABOUTOPTIONS, OPTIONSID, OPTIONSID),
END_HELPCONTEXT;

//
// Make sure the smallest size the About window can be is twice the
// size of the ball bitmap.
//
void
TAboutWindow::EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo)
{
  if (SpeedBall && SpeedBall->BallBitmap) {
    TPoint p(SpeedBall->BallBitmap->Width() * 2, SpeedBall->BallBitmap->Height() * 2);
    minmaxinfo.ptMinTrackSize = p;
  }
  else
    TLayoutWindow::EvGetMinMaxInfo(minmaxinfo);
}

//
// Close the About window on Ok.
//
void
TAboutWindow::CmOk()
{
  CloseWindow(IDOK);
}


//
// Display the property sheet.
//
void
TAboutWindow::CmOptions()
{
  // Create the property sheets.
  //
  TPropertySheet* ps = new TPropertySheet(this, "Options");
  TBitBltPage* bitBltPage = new TBitBltPage(SpeedBall->BlitterBlocks,
    SpeedBall->EnableSound, ps, IDD_BITBLT);
  TSpeedPage* speedPage = new TSpeedPage(::RandomMax, ::AbsoluteDelta,
    SpeedBall->Delay, ps, IDD_SPEED);

  // If user pressed Ok, save the values to affect the bouncing ball
  //
  if (ps->Execute() == IDOK) {
    ::RandomMax      = speedPage->FactorValue;
    ::AbsoluteDelta  = speedPage->DeltaValue;
    SpeedBall->Delay = speedPage->DelayValue;
    SpeedBall->BlitterBlocks = bitBltPage->BlitterBlocks;
    SpeedBall->EnableSound = bitBltPage->EnableSound;
  }
}

//
// User wants help.
//
void
TAboutWindow::CmHelp()
{
  WinHelp(HELPFILENAME, HELP_CONTEXT, IDH_ABOUTWINDOW);
}

//
// SetupWindow()
// Setup the context sensitive help.
//
void
TAboutWindow::SetupWindow()
{
  TLayoutWindow::SetupWindow();
  SETUP_HELPCONTEXT(TBlazerApp, TAboutWindow);
}


//
// CleanupWindow()
// Removes the context sensitive help info.
//
void
TAboutWindow::CleanupWindow()
{
  CLEANUP_HELPCONTEXT(TBlazerApp, TAboutWindow);
  TLayoutWindow::CleanupWindow();
}
