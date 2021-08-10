// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_IMAGELST_H)
# include <owl/imagelst.h>
#endif
#include <math.h>
#include "drawcel.rh"

#if !defined(BI_PLAT_WIN32)
# error This example must be built as a WIN32 target - It requires the 
# error 'drag' support of IMAGELIST.
#endif

// Few constants
//
const int ImageWidth  = 80;
const int ImageHeight = 50;
const int NumImages   = 2;
const TColor MaskColor= RGB(255, 0, 0);

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
	  TClientWindow(TWindow* parent= 0);
	 ~TClientWindow();

  protected:
	  void          SetupWindow();
	  void          Paint(TDC& dc, bool erase, TRect& rect);
    void          EvSize(uint, TSize&);
    void          EvLButtonDown(uint, TPoint& );
    void          EvLButtonUp(uint, TPoint& );
    void          EvMouseMove(uint, TPoint& );
	  void				  CmFlyImage();
	  void				  CmBirdImage();
	  void				  CmTurtleImage();

	  TImageList*   ImageList;
	  TSize         ImgSize;
    bool          Dragging;
    int           Xpos;
    int           Ypos;
    int           Xoffset;
    int           Yoffset;
    int           CurImage;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};


//
//
//
DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
	EV_COMMAND(CM_FLY, CmFlyImage),
	EV_COMMAND(CM_BIRDIMAGE, CmBirdImage),
	EV_COMMAND(CM_TURTLEIMAGE, CmTurtleImage),
END_RESPONSE_TABLE;


//
//
//
TClientWindow::TClientWindow(TWindow* parent) 
              :TWindow(parent), ImageList(0), CurImage(0), Dragging(false)
{
  ModifyStyle(0, WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
  Xpos =  Ypos = 0;
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
  ImageList = new TImageList(*GetApplication(), IDB_BMPSTRIP, ImageWidth, 1,
											        MaskColor, IMAGE_BITMAP, ILC_COLOR);
}


//
//
//
void
TClientWindow::Paint(TDC& dc, bool, TRect&)
{
  TBitmap* skyBmp = new TBitmap(*GetApplication(), IDB_SKYBMP);
  TPointer<TBitmap> __clnBmp = skyBmp;

  TMemoryDC memDc(dc);
  memDc.SelectObject(*skyBmp);

  TRect rect;
  GetClientRect(rect);
  dc.StretchBlt(rect.left, rect.top, rect.right, rect.bottom, memDc, 0, 0,
					      skyBmp->Width(), skyBmp->Height());

  if (Xpos + ImageWidth > rect.right)
    Xpos= rect.right-ImageWidth;
  if (Ypos + ImageHeight > rect.bottom)
    Ypos= rect.bottom-ImageHeight;

  if (ImageList && !Dragging)
    ImageList->Draw(CurImage, dc, Xpos, Ypos, ILD_NORMAL);

  memDc.RestoreBitmap();
}

void
TClientWindow::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType,size);
  InvalidateRect(GetClientRect(),false);
}

void
TClientWindow::EvLButtonDown(uint modeKeys, TPoint& point)
{
  TRect imageRect(Xpos, Ypos, Xpos + ImageWidth, Ypos + ImageHeight);
  bool hitTest = PtInRect(&imageRect, point); 
  if (ImageList && hitTest) {

    // Offset of mouse down within image
    //
    Xoffset = point.x - Xpos;
    Yoffset = point.y - Ypos;

    Dragging= true;
    ShowCursor(FALSE); 
    SetCapture();
    InvalidateRect(imageRect, false);
    UpdateWindow();
    ImageList->SetDragCursorImage(CurImage, 0, 0);
    ImageList->BeginDrag(CurImage, 0, 0);
    ImageList->DragEnter(*this, Xpos, Ypos);
  }
  else
    TWindow::EvLButtonDown(modeKeys, point);
}

void
TClientWindow::EvLButtonUp(uint modeKeys, TPoint& point)
{
  if (Dragging) {
    Xpos= point.x - Xoffset;
    Ypos= point.y - Yoffset;
    ImageList->DragLeave(*this);
    ImageList->EndDrag();
    ReleaseCapture();
    ShowCursor(TRUE); 
    InvalidateRect(GetClientRect(), false);
    Dragging= false;
  }
  else  
    TWindow::EvLButtonUp(modeKeys, point);
}

void
TClientWindow::EvMouseMove(uint modeKeys, TPoint& point)
{
  if (Dragging)
    ImageList->DragMove(point.x - Xoffset, point.y - Yoffset);
  else
    TWindow::EvMouseMove(modeKeys, point);
}


void
TClientWindow::CmFlyImage()
{
  TRect rect;
  GetClientRect(rect);
  int mid = rect.bottom/2 - ImageHeight/2;

  Xpos = 0;
  Ypos = mid;

  Dragging= true;
  Invalidate(false);
  UpdateWindow();
  ShowCursor(FALSE); 
  SetCapture();

  ImageList->SetDragCursorImage(CurImage, 0, 0);
  ImageList->BeginDrag(CurImage, 0, 0);
  ImageList->DragEnter(*this, Xpos, Ypos);
  while (Xpos < (rect.right - ImageWidth)) {
   Xpos++;
   Ypos = mid + int(sin((Xpos*M_PI)/180) * mid);
   ImageList->DragMove(Xpos, Ypos);
  }

  ImageList->DragLeave(*this);
  ImageList->EndDrag();
  Dragging= false;

  ReleaseCapture();
  ShowCursor(TRUE); 
  Invalidate(false);
}

void
TClientWindow::CmBirdImage()
{
  CurImage=0;
  InvalidateRect(GetClientRect(), false);
}

void
TClientWindow::CmTurtleImage()
{
  CurImage=1;
  InvalidateRect(GetClientRect(), false);
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
  TFrameWindow *frame = new TFrameWindow(0, "ImageList Drag", new TClientWindow());
  frame->AssignMenu(IDM_IMAGEMENU);
  SetMainWindow(frame);
}


//
//
//
int
OwlMain(int /*argc*/, char */*argv*/[])
{
  return TSampleApp().Run();
}
