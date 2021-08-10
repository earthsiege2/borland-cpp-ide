//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Tutorial application -- step05.cpp
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\inputdia.h>
#include <stdlib.h>

class TMyWindow : public TWindow {
  public:
    TMyWindow(TWindow *parent = 0);
   ~TMyWindow() {delete DragDC; delete Pen;}

    void SetPenSize(int newSize);

  protected:
    TDC *DragDC;
    int PenSize;
    TPen *Pen;

    // Override member function of TWindow
    BOOL CanClose();

    // Message response functions
    void EvLButtonDown(UINT, TPoint&);
    void EvRButtonDown(UINT, TPoint&);
    void EvMouseMove(UINT, TPoint&);
    void EvLButtonUp(UINT, TPoint&);

    DECLARE_RESPONSE_TABLE(TMyWindow);
};

DEFINE_RESPONSE_TABLE1(TMyWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
END_RESPONSE_TABLE;

TMyWindow::TMyWindow(TWindow *parent)
{
  Init(parent, 0, 0);
  DragDC = 0;
  PenSize = 1;
  Pen = new TPen(TColor::Black, PenSize);
}

BOOL TMyWindow::CanClose()
{
  return MessageBox("Do you want to save?", "Drawing has changed",
                    MB_YESNO | MB_ICONQUESTION) == IDNO;
}

void TMyWindow::EvLButtonDown(UINT, TPoint& point)
{
  Invalidate();

  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
  }
}

void TMyWindow::EvRButtonDown(UINT, TPoint&)
{
  char           inputText[6];

  wsprintf(inputText, "%d", PenSize);
  if ((TInputDialog(this, "Line Thickness",
                        "Input a new thickness:",
                        inputText, 
                        sizeof(inputText))).Execute() == IDOK) {
    int  newPenSize = atoi(inputText);

    if (newPenSize < 0)
      newPenSize = 1;

    SetPenSize(newPenSize);
  }
}

void TMyWindow::EvMouseMove(UINT, TPoint& point)
{
  if (DragDC)
    DragDC->LineTo(point);
}

void TMyWindow::EvLButtonUp(UINT, TPoint&)
{
  if (DragDC) {
    ReleaseCapture();
    delete DragDC;
    DragDC = 0;
  }
}

void TMyWindow::SetPenSize(int newSize)
{
  delete Pen;
  PenSize = newSize;
  Pen = new TPen(TColor::Black, PenSize);
}

class TMyApp : public TApplication {
  public:
    TMyApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Drawing Pad", new TMyWindow));
    }
};

int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp().Run();
}
