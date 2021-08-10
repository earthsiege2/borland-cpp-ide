//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1995 by Borland International, All Rights Reserved
//
// Illustrates usage of TUIFace
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/uihelper.h>
#include "uiface.rh"

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);

  protected:
    void  Paint(TDC& dc, bool erase, TRect& rect);

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
END_RESPONSE_TABLE;

//
//
//
TClientWindow::TClientWindow(TWindow* parent)
:
 TWindow(parent)
{
  Attr.Style |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
  //SetBkgndColor(TColor::Sys3dFace);
}

//
//
//
void
LineRect(TDC& dc, const TRect& rect)
{
  dc.MoveTo(rect.left,  rect.top);
  dc.LineTo(rect.left,  rect.bottom);
  dc.LineTo(rect.right, rect.bottom);
  dc.LineTo(rect.right, rect.top);
  dc.LineTo(rect.left,  rect.top);
}

//
//
//
void
TClientWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  TPen pen(TColor(255, 0, 0));
  dc.SelectObject(pen);

  TBitmap bmp(*GetModule(), IDB_SAMPLE);

  const int margin = 10;
  int width = bmp.Width();
  int height= bmp.Height();

  TRect faceRect(TPoint(20, 10), TSize(width, height));
  faceRect.Inflate(margin, margin);

  for (int i=TUIFace::Normal; i < TUIFace::Default; i++) {

    faceRect.Offset(0, faceRect.Height() + margin/2);
    LineRect(dc, faceRect);

    TUIFace uif1(faceRect, bmp);
    uif1.Paint(dc, TPoint(margin, margin), TUIFace::TState(i), false, true);

    faceRect.Offset((faceRect.Width() + margin/2), 0);
    LineRect(dc, faceRect);

    TUIFace uif2(faceRect, bmp);
    uif2.Paint(dc, TPoint(margin, margin), TUIFace::TState(i), true, false);

    faceRect.Offset(-(faceRect.Width() + margin/2), 0);
  }

  dc.RestorePen();
}

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void    InitMainWindow();
};

//
//
//
void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, 0, new TClientWindow()));
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
