//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Tutorial application -- step06.cpp
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\inputdia.h>
#include <stdlib.h>
#include <classlib\arrays.h>
#include "step06.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TMyWindow : public TWindow {
  public:
    TMyWindow(TWindow *parent = 0);
   ~TMyWindow() {delete DragDC; delete Pen; delete Line;}

    void SetPenSize(int newSize);

  protected:
    TDC *DragDC;
    int PenSize;
    TPen *Pen;
    TPoints *Line; // To store points in line.

    // Override member function of TWindow
    BOOL CanClose();

    // Message response functions
    void EvLButtonDown(UINT, TPoint&);
    void EvRButtonDown(UINT, TPoint&);
    void EvMouseMove(UINT, TPoint&);
    void EvLButtonUp(UINT, TPoint&);
    void Paint(TDC&, BOOL, TRect&);
    void CmFileNew();
    void CmFileOpen();
    void CmFileSave();
    void CmFileSaveAs();
    void CmAbout();

    DECLARE_RESPONSE_TABLE(TMyWindow);
};

DEFINE_RESPONSE_TABLE1(TMyWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

TMyWindow::TMyWindow(TWindow *parent)
{
  Init(parent, 0, 0);
  DragDC = 0;
  PenSize = 1;
  Pen = new TPen(TColor::Black, PenSize);
  Line = new TPoints(10, 0, 10);
}

BOOL TMyWindow::CanClose()
{
  return MessageBox("Do you want to save?", "Drawing has changed",
                    MB_YESNO | MB_ICONQUESTION) == IDNO;
}

void TMyWindow::EvLButtonDown(UINT, TPoint& point)
{
  Line->Flush();
  Invalidate();

  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void TMyWindow::EvRButtonDown(UINT, TPoint&)
{
  char inputText[6];

  wsprintf(inputText, "%d", PenSize);
  if ((TInputDialog(this, "Line Thickness",
                        "Input a new thickness:",
                        inputText, 
                        sizeof(inputText))).Execute() == IDOK) {
    int newPenSize = atoi(inputText);

    if (newPenSize < 0)
      newPenSize = 1;

    SetPenSize(newPenSize);
  }
}

void TMyWindow::EvMouseMove(UINT, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
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

void TMyWindow::Paint(TDC& dc, BOOL, TRect&)
{
  BOOL first = TRUE;
  TPointsIterator i(*Line);

  dc.SelectObject(*Pen);

  while (i) {
    TPoint p = i++;

    if (!first)
      dc.LineTo(p);
    else {
      dc.MoveTo(p);
      first = FALSE;
    }
  }
}

void TMyWindow::CmFileNew()
{
  Line->Flush();
  Invalidate();
}

void TMyWindow::CmFileOpen()
{
  MessageBox("Feature not implemented", "File Open", MB_OK);
}

void TMyWindow::CmFileSave()
{
  MessageBox("Feature not implemented", "File Save", MB_OK);
}

void TMyWindow::CmFileSaveAs()
{
  MessageBox("Feature not implemented", "File Save As", MB_OK);
}

void TMyWindow::CmAbout()
{
  MessageBox("Feature not implemented", "About Drawing Pad", MB_OK);
}

class TMyApp : public TApplication {
  public:
    TMyApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Drawing Pad", new TMyWindow));
      GetMainWindow()->AssignMenu("COMMANDS");
    }
};

int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp().Run();
}
