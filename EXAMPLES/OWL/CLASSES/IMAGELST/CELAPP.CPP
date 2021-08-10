// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/chooseco.h>
#include <owl/imagelst.h>
#include <stdio.h>
#include "celapp.rh"

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);
   ~TClientWindow();

  protected:
    void            SetupWindow();
    void            Paint(TDC& dc, bool erase, TRect& rect);

    void            SetBkColor();

    TImageList*     ImageList;
    TSize           ImgSize;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};


//
//
//
DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_COMMAND(CM_COLOR, SetBkColor),
END_RESPONSE_TABLE;


//
//
//
TClientWindow::TClientWindow(TWindow* parent) : TWindow(parent)
{
  Attr.Style |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
  ImageList = 0;
}


//
//
//
TClientWindow::~TClientWindow()
{
  delete ImageList;
}


//
//
//
void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  for (int i = IDB_WKING; i <= IDB_BPAWN; i++) {
    TBitmap img(*GetModule(), i);
    TBitmap msk(*GetModule(), i+MASK_DELTA);

    if (!ImageList) {
      ImgSize = TSize(img.Width(), img.Height());
      ImageList = new TImageList(ImgSize, true, 10, 10);
      ImageList->SetBkColor(RGB(0xff, 0, 0));
    }

    ImageList->Add(img, msk);
  }
}


//
//
//
void
TClientWindow::Paint(TDC& dc, bool, TRect&)
{
  int x = ImgSize.cx;
  int y = ImgSize.cy;

  for (int i = 0; i < ImageList->GetImageCount(); i++) {
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ILD_NORMAL);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ILD_TRANSPARENT);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ILD_MASK);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ILD_BLEND50);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ILD_BLEND25);

    x += ImgSize.cx;
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_NORMAL);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_TRANSPARENT);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_MASK);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_BLEND);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_BLEND50);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_BLEND25);

    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_MASK|ILD_BLEND);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_IMAGE|ILD_BLEND);
    ImageList->Draw(i, dc, (x += ImgSize.cx), y, ImgSize.cx, ImgSize.cy,
                   TColor::LtBlue, TColor::LtYellow, ILD_MASK|ILD_TRANSPARENT|ILD_BLEND);
    x =  ImgSize.cx;
    y += ImgSize.cy;
  }
}


//
//
//
void
TClientWindow::SetBkColor()
{
  TChooseColorDialog::TData colors;
  colors.Flags = CC_RGBINIT;
  colors.Color = ImageList->GetBkColor();
  colors.CustColors = 0;

#if 0
  if (TChooseColorDialog(this, colors).Execute() == IDOK)
    ImageList->SetBkColor(colors.Color);
#endif
}


//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp() : TApplication() {}
    void InitMainWindow();
};


//
//
//
void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "ImageList example", new TClientWindow()));
}


//
//
//
int
OwlMain(int /*argc*/, char */*argv*/[])
{
  return TSampleApp().Run();
}
