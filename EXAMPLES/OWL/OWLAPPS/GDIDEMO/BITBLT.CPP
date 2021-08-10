//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   TBitBltWindow demo window object for GDIDEMO program
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include "bitblt.h"
#include <stdlib.h>
#include <math.h>

// TBitBltWindow ----------------------------------------------------

DEFINE_RESPONSE_TABLE1(TBitBltWindow, TBaseDemoWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE1(TBitBltWindow, TBaseDemoWindow);

// Initialize the bitblt demo window and allocate bitmaps
//
TBitBltWindow::TBitBltWindow() : TBaseDemoWindow()
{
  Background = new TBitmap(*GetApplication(), BackgroundId);
  Ship = new TBitmap(*GetApplication(), ShipId);
  MonoShip = new TBitmap(*GetApplication(), MonoShipId);
  ScratchBitmap = 0;
  StretchedBkgnd = 0;
  OldX = 0;
  OldY = 0;
  X = 0;
  Y = 0;
  Delta = 5;
  CurClick = 1;
}

// Dispose of all used resources
//
TBitBltWindow::~TBitBltWindow()
{
  delete Background;
  delete Ship;
  delete MonoShip;
  delete ScratchBitmap;
  delete StretchedBkgnd;
}

// Allocate scratch bitmaps
//
void
TBitBltWindow::SetupWindow()
{
  TBaseDemoWindow::SetupWindow();
  TClientDC winDC(*this);
  ScratchBitmap = new TBitmap(winDC, 80, 80);
  StretchedBkgnd = new TBitmap(winDC, 1000, 1000);
}

// Record the new size and stretch the background to it
//
void
TBitBltWindow::EvSize(UINT sizeType, TSize& size)
{
  TBaseDemoWindow::EvSize(sizeType, size);
  WindowSize.x = size.cx;
  WindowSize.y = size.cy;

  TClientDC winDC(*this);

  // Create a stretched to fit background
  //
  TMemoryDC stretchedDC(winDC);
  TMemoryDC memDC(winDC);
  stretchedDC.SelectObject(*StretchedBkgnd);
  memDC.SelectObject(*Background);

  // set the cursor to an hourglass - this might take awhile
  //
  HCURSOR oldCur = ::SetCursor(::LoadCursor(0, IDC_WAIT));
  stretchedDC.StretchBlt(0, 0, WindowSize.x, WindowSize.y, 
                         memDC, 0, 0, 100, 100, SRCCOPY);
  ::SetCursor(oldCur);
  Invalidate();
}

// Need to ensure that the Old copy of the ship gets redrawn with
//  any paint messages.
//
void
TBitBltWindow::Paint(TDC& dc, BOOL, TRect&)
{
  TMemoryDC memDC(dc);
  memDC.SelectObject(*StretchedBkgnd);
  dc.BitBlt(0, 0, WindowSize.x, WindowSize.y, memDC, 0, 0, SRCCOPY);
}

// TimerTick deletes the old position of the saucer and blt's a new one
//
void
TBitBltWindow::TimerTick()
{
  const int ClicksToSkip = 4;

  // Make the saucer go slower then everyone else- only move on every 4th tick
  //
  if (CurClick < ClicksToSkip) {
    CurClick++;
    return;
  } else {
    CurClick = 1;
  }

  // Setup the DC's
  //
  TClientDC windowDC(*this);
  TMemoryDC bits(windowDC);
  TMemoryDC backingStore(windowDC);

  // Calculate the offsets into and dimensions of the backing store
  //
  CalculateNewXY();
  int bx = min(X, OldX);
  int by = min(Y, OldY);
  int ox = abs(X - bx);
  int oy = abs(Y - by);
  int bw = BitmapSize + abs(OldX - X);
  int bh = BitmapSize + abs(OldY - Y);

  // Create an image into the backing store the will that, when blt into
  //  the window will both erase the old image and draw the new one.
  //  (to minimize screen flicker)
  //
  backingStore.SelectObject(*ScratchBitmap);
  bits.SelectObject(*StretchedBkgnd);
  backingStore.BitBlt(0, 0, bw, bh, bits, bx, by, SRCCOPY);
  bits.SelectObject(*MonoShip);
  backingStore.BitBlt(ox, oy, BitmapSize, BitmapSize, bits, 0, 0, SRCAND);
  bits.SelectObject(*Ship);
  backingStore.BitBlt(ox, oy, BitmapSize, BitmapSize, bits, 0, 0, SRCPAINT);

  // Blt the backing store to the window
  //
  windowDC.BitBlt(bx, by, bw, bh, backingStore, 0, 0, SRCCOPY);

  OldX = X;
  OldY = Y;
}

void
TBitBltWindow::CalculateNewXY()
{
  if (WindowSize.x < BitmapSize)        // Don't move if too small
    return;
  if (X > WindowSize.x - BitmapSize || X < 0) {
    Delta = -Delta;
    if (X > WindowSize.x-BitmapSize)
      X = WindowSize.x - BitmapSize - 5;
  }
  X += Delta;
  Y += random(10) - 5;  // range from -5 to +5
  if (Y > (WindowSize.y - BitmapSize)) {
    Y = WindowSize.y - BitmapSize;
  } else {
    if (Y < 0)
      Y = 0;
  }
}
