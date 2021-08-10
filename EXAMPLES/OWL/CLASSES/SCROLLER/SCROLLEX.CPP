//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/scroller.h>
#include <owl/dc.h>


//
// Each "unit" is the number of device units (pixels) to scroll if the
// SB_LINEUP or SB_LINEDOWN message is received.
//
const int XUnits = 7;
const int YUnits = 16;

//
// A range is number of units available to scroll.
//
const int XRange = 80;
const int YRange = 60;

//
// Therefore, the size of the imaginary canvas is calculated as
// follows:
// The width is XUnits * XRange  =  7 * 80 = 560 pixels.
// The height is YUnits * YRange = 16 * 60 = 960 pixels.
//
const int NumberOfRectangles = 49;


//
// class TScrollWindow
// ~~~~~ ~~~~~~~~~~~~~
class TScrollWindow : public TWindow {
  public:
    TScrollWindow(TWindow* parent = 0, const char* title = 0);
    void Paint(TDC& dc, bool, TRect&);
};

//
// Constructor for a TScrollWindow, sets scroll styles and
// constructs the Scroller object.
//
TScrollWindow::TScrollWindow(TWindow* parent, const char* title)
:
  TWindow(parent, title)
{
  Attr.Style |= WS_VSCROLL | WS_HSCROLL;
  Scroller = new TScroller(this, XUnits, YUnits, XRange, YRange);
}

//
// Responds to an incoming "paint" message by redrawing boxes. Note
// that the Scroller's BeginView method, which sets the viewport origin
// relative to the present scroll position, has already been called.
//
void
TScrollWindow::Paint(TDC& dc, bool, TRect&)
{
  const int offsetX = 10;
  const int offsetY = 30;

  // Golden ratio is 8/5. Derived from geometry.
  //
  const int goldenRatioX = 8;
  const int goldenRatioY = 5;

  // Draw the rectangles
  //
  for (int i = 0; i < NumberOfRectangles; i++) {
    int x = offsetX + i * goldenRatioX;
    int y = offsetY + i * goldenRatioY;
    dc.Rectangle(x, y, 2 * x, 3 * y);
  }
}


//
// class TScrollApp
//
class TScrollApp : public TApplication {
  public:
    TScrollApp()
    :
      TApplication("ScrollApp")
    {
    }
    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Boxes", new TScrollWindow));
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TScrollApp().Run();
}
