//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\scroller.h>
#include <owl\dc.h>

class TScrollWindow : public TFrameWindow {
  public:
    TScrollWindow(const char* title);
    void Paint(TDC& dc, BOOL, TRect&);
};

//
// Constructor for a TScrollWindow, sets scroll styles and
// constructs the Scroller object.
//
TScrollWindow::TScrollWindow(const char* title)
  : TWindow(0, title),
    TFrameWindow(0, title)
{
  Attr.Style |= WS_VSCROLL | WS_HSCROLL;
  Scroller = new TScroller(this, 7, 16, 80, 60);
}

//
// Responds to an incoming "paint" message by redrawing boxes. Note
// that the Scroller's BeginView method, which sets the viewport origin
// relative to the present scroll position, has already been called. 
//
void
TScrollWindow::Paint(TDC& dc, BOOL, TRect&)
{
  for (int i = 0; i <= 49; i++) {
    int x = 10 + i*8;
    int y = 30 + i*5;
    int w = x;
    int h = y * 2;
//    if (Scroller->IsVisibleRect((x-Scroller->XUnit/2)/Scroller->XUnit,
//                                (y-Scroller->YUnit/2)/Scroller->YUnit, 
//                                (w+Scroller->XUnit/2)/Scroller->XUnit,
//                                (h+Scroller->YUnit/2)/Scroller->YUnit))
      dc.Rectangle(x, y, x+w, y+h);
  }
}

//----------------------------------------------------------------------------

class TScrollApp : public TApplication {
  public:
    TScrollApp() : TApplication("ScrollApp") {}
    void InitMainWindow() {MainWindow = new TScrollWindow("Boxes");}
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TScrollApp().Run();
}
