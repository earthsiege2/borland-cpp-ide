//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Arty demo window object
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dc.h>
#include <owl/static.h>
#include <stdlib.h>
#include "arty.h"           // class definition for TArtyWindow
#include "artypriv.h"       // internal component classes of TArtyWindow


//---------- TList ----------------------------------------------

//
// The low-level line draw routine
//
static void
LineDraw(TDC& dc, int x1, int y1, int x2, int y2)
{
  dc.MoveTo(x1, y1);
  dc.LineTo(x2, y2);
}

//
// Initialize the list-of-lines object 
//
TList::TList(int _max)
{
  MaxLines = min(_max, MaxLineCount);
  CurrentLine = 1;
  Xmax = 0;
  Ymax = 0;
  ColorDuration = MaxColorDuration;
  IncrementCount = 0;
  MaxDelta = 10;
  PenColor = TColor(random(256), random(256), random(256));
}

//
// Keep X within range, and reverse Delta if necessary to do so
//
void
TList::AdjustX(int& x, int& deltaX)
{
  int testX = x + deltaX;
  if (testX < 1 || testX > Xmax) {
    testX = x;
    deltaX = -deltaX;
  }
  x = testX;
}

//
// Keep Y within range, and reverse Delta if necessary to do so
//
void
TList::AdjustY(int& y, int& deltaY)
{
  int testY = y + deltaY;
  if (testY < 1 || testY > Ymax) {
    testY = y;
    deltaY = -deltaY;
  }
  y = testY;
}

//
// Clear the array of lines
//
void
TList::ResetLines() 
{
  int startX = Xmax / 2;
  int startY = Ymax / 2;
  for (int i = 0; i < MaxLines; i++) {
    Line[i].LX1 = startX;
    Line[i].LX2 = startX;
    Line[i].LY1 = startY;
    Line[i].LY2 = startY;
    Line[i].Color = 0;
  }
  X1 = startX;
  X2 = startX;
  Y1 = startY;
  Y2 = startY;
}

//
// Scale the old line coordinates to the new Xmax and Ymax coordinates.
//  The new Xmax and new Ymax are passed in as parameters so we can
//  calculate the scaling ratios.
//
void
TList::ScaleTo(int newXmax, int newYmax)
{
  if (!Xmax || !Ymax) {    // at startup, Xmax and Ymax are zero
    Xmax = newXmax;
    Ymax = newYmax;
    ResetLines();

  }
  else {
    X1 = int(long(X1)*newXmax / Xmax);
    Y1 = int(long(Y1)*newYmax / Ymax);
    X2 = int(long(X2)*newXmax / Xmax);
    Y2 = int(long(Y2)*newYmax / Ymax);
    for (int i = 0; i < MaxLines; i++) {
      Line[i].LX1 = int(long(Line[i].LX1)*newXmax / Xmax);
      Line[i].LX2 = int(long(Line[i].LX2)*newXmax / Xmax);
      Line[i].LY1 = int(long(Line[i].LY1)*newYmax / Ymax);
      Line[i].LY2 = int(long(Line[i].LY2)*newYmax / Ymax);
    }
  }
  Xmax = newXmax;
  Ymax = newYmax;
}

// The high-level Draw method of the object.
//
void
TList::DrawLine(TDC& dc, int index)
{
  TPen pen(Line[index].Color);
  dc.SelectObject(pen);
  LineDraw(dc, Line[index].LX1, Line[index].LY1, 
               Line[index].LX2, Line[index].LY2);
  dc.RestorePen();
}

// The high-level draw which erases a line.
//
void TList::EraseLine(TDC& dc, int index)
{
  dc.SelectStockObject(BLACK_PEN);
  LineDraw(dc, Line[index].LX1, Line[index].LY1,
               Line[index].LX2, Line[index].LY2);
}

//
// Redraw all the lines in the array.
//
void
TList::Redraw(TDC& dc)
{
  for (int i = 0; i < MaxLines; i++)
    DrawLine(dc, i);
}

//
// Reset the color counter and pick a random color.
//
void
TList::SelectNewColor()
{
  ColorDuration = MaxColorDuration;
  PenColor = TColor(random(256), random(256), random(256));
}

//
// Pick random directional deltas and reset the delta counter.
//
void
TList::SelectNewDeltaValues()
{
  DeltaX1 = random(MaxDelta) - MaxDelta/2;
  DeltaX2 = random(MaxDelta) - MaxDelta/2;
  DeltaY1 = random(MaxDelta) - MaxDelta/2;
  DeltaY2 = random(MaxDelta) - MaxDelta/2;
  IncrementCount = 2 * (1 + random(10));
}

//
// Process the movement of one line.
//
void
TList::LineTick(TDC& dc)
{
  EraseLine(dc, CurrentLine);
  if (ColorDuration < 0)
    SelectNewColor();
  if (!IncrementCount)
    SelectNewDeltaValues();
  AdjustX(X1, DeltaX1);
  AdjustX(X2, DeltaX2);
  AdjustY(Y1, DeltaY1);
  AdjustY(Y2, DeltaY2);

  Line[CurrentLine].LX1 = X1;
  Line[CurrentLine].LX2 = X2;
  Line[CurrentLine].LY1 = Y1;
  Line[CurrentLine].LY2 = Y2;
  Line[CurrentLine].Color = PenColor;

  DrawLine(dc, CurrentLine);
  CurrentLine++;
  if (CurrentLine >= MaxLines)
    CurrentLine = 1;
  ColorDuration--;
  IncrementCount--;
}


//------------ TQuadList ----------------------------------------

//
// Draw the line and 3 reflections of it.
//
void
TQuadList::DrawLine(TDC& dc, int index)
{
  TPen pen(Line[index].Color);
  dc.SelectObject(pen);
  LineDraw(dc, Line[index].LX1, Line[index].LY1,
               Line[index].LX2, Line[index].LY2);
  LineDraw(dc, Xmax - Line[index].LX1, Line[index].LY1,
               Xmax - Line[index].LX2, Line[index].LY2);
  LineDraw(dc, Line[index].LX1, Ymax - Line[index].LY1,
               Line[index].LX2, Ymax - Line[index].LY2);
  LineDraw(dc, Xmax - Line[index].LX1, Ymax - Line[index].LY1,
               Xmax - Line[index].LX2, Ymax - Line[index].LY2);
  dc.RestorePen();
}

//
// Erase the line and 3 reflections of it.
//
void
TQuadList::EraseLine(TDC& dc, int index)
{
  dc.SelectStockObject(BLACK_PEN);
  LineDraw(dc, Line[index].LX1, Line[index].LY1,
               Line[index].LX2, Line[index].LY2);
  LineDraw(dc, Xmax - Line[index].LX1, Line[index].LY1,
               Xmax - Line[index].LX2, Line[index].LY2);
  LineDraw(dc, Line[index].LX1, Ymax - Line[index].LY1,
               Line[index].LX2, Ymax - Line[index].LY2);
  LineDraw(dc, Xmax - Line[index].LX1, Ymax - Line[index].LY1,
               Xmax - Line[index].LX2, Ymax - Line[index].LY2);
}

//----------- TArtyWindow ------------------------------------------

DEFINE_RESPONSE_TABLE1(TArtyWindow, TBaseDemoWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_SIZE,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE1(TArtyWindow, TBaseDemoWindow);

//
//
//
TArtyWindow::TArtyWindow() : TBaseDemoWindow()
{
  StaticControl = new TStatic(this, 100,
    "Press Left Button to pause, Right Button to Clear",10,10,10,10,0);
  Iconized = false;
  TextHeight = 20;
  Paused = false;

  // Initialize two line list objects:
  //    BigLineList is the 4-reflection artwork that is displayed in
  //    a full sized window.  Mouse clicks will pause or clear
  //    the display, and the line list will be scaled to the
  //    new window coordinates when the window is resized.
  //
  //    IconicLineList is a smaller list implementing a single-line
  //    quark to display in the iconized window region.  Since
  //    mouse clicks are not sent to iconized windows, the icon
  //    cannot be paused or cleared, and since there is only one
  //    icon window size, scaling the lines to new coordinates
  //    has no visual effect.
  //
  //  The List pointer will be toggled between the two line list
  //  objects: when the window is iconized, List will point to the
  //  IconicLineList object.  When the window is restored to full
  //  size, List will be made to point to the BigLineList object.
  //  This is so the window routines don't have to know which kind
  //  of list they're dealing with.  Keyword: polymorphism.

  BigLineList = new TQuadList(MaxLineCount);
  IconicLineList = new TList(MaxIconicLineCount);
  List = BigLineList;

  SetBkgndColor(TColor::Black);
}

//
// Dispose of the objects that this window object created.  There's
//  no need to dispose the List pointer, since it will only point to
//  one of these two objects which are being disposed by their
//  primary pointers
//
TArtyWindow::~TArtyWindow()
{
  delete BigLineList;
  delete IconicLineList;
}

//
// When the window is resized, scale the line list to fit the new
//  window extent, or switch between full size and iconized window
//  states.
//
void
TArtyWindow::EvSize(uint sizeType, TSize& size)
{
  TBaseDemoWindow::EvSize(sizeType, size);

  // Force Windows to repaint the entire window region
  //
  Invalidate(true);

  int newXmax = size.cx;
  int newYmax = size.cy;
  if (sizeType == SIZE_MINIMIZED) {
    if (!Iconized) {
      Iconized = true;
      List = IconicLineList;
    }

  }
  else {
    if (Iconized) {
      Iconized = false;
      List = BigLineList;
    }
    newYmax -= TextHeight;  // allow room for the text at the bottom
  }

  List->ScaleTo(newXmax, newYmax);  // scale the lines in the list
  if (StaticControl)
    StaticControl->MoveWindow(0, newYmax, newXmax, TextHeight, true);
}

//
// Toggle the window's Paused status.  Since the window will
//  not receive mouse clicks when iconized, this will not pause the
//  iconized lines display.
//
void
TArtyWindow::EvLButtonDown(uint, TPoint&)
{
  Paused = !Paused;
}

//
// Clear the line list when the user presses the right mouse
//  button.  Same comments as above on iconized windows.
//
void
TArtyWindow::EvRButtonDown(uint, TPoint&)
{
  Invalidate(true);
  List->ResetLines();
}

//
// When the window is resized, or some other window blots out part
// of our client area, redraw the entire line list.
//
void
TArtyWindow::Paint(TDC& dc, bool, TRect&)
{
  List->Redraw(dc);
}

//
// Fetch a device context, pass it to the line list object, then
// release the device context back to Windows.
//
void
TArtyWindow::TimerTick()
{
  if (!Paused)
    List->LineTick(TClientDC(Iconized ? Parent->GetHandle() : GetHandle()));
}
