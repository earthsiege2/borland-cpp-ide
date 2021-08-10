//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1995 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/uihelper.h>
#include <owl/listbox.h>
#include <owl/gdiobjec.h>
#include <stdio.h>
#include "drawedge.rh"

class TTestWindow : public TDialog {
  public:
    TTestWindow();

  protected:
    void    Paint(TDC& dc, bool erase, TRect& rect);
    void    SetupWindow();
    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);

    HBRUSH  EvCtlColor(HDC, HWND hWndChild, uint ctlType);

    void    PaintSample(TDC& dc);
    void    Update();

    uint  Edge;
    uint  Flags;
    TRect SampleRect;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_CTLCOLOR,
  EV_WM_WININICHANGE,
END_RESPONSE_TABLE;


TTestWindow::TTestWindow()
:
  TDialog(0, IDD_DRAWEDGE, 0)
{
  SetBkgndColor(TColor::Sys3dFace);
}

//
//
//
void
TTestWindow::SetupWindow()
{
  TDialog::SetupWindow();

  ::GetWindowRect(GetDlgItem(IDC_SAMPLE), &SampleRect);
  ScreenToClient(SampleRect.TopLeft());
  ScreenToClient(SampleRect.BottomRight());
  ::DestroyWindow(GetDlgItem(IDC_SAMPLE));
  Update();
}


void
TTestWindow::PaintSample(TDC& dc)
{
  if (Flags & TUIBorder::Soft)
    dc.SelectObject(TBrush(TColor::Sys3dFace));
  else
    dc.SelectObject(TBrush(TColor::SysDesktop));
  dc.PatBlt(SampleRect.InflatedBy(10,10), PATCOPY);

  TRect r(SampleRect);
  TUIBorder border(r, TUIBorder::TEdge(Edge), Flags);
  border.Paint(dc);
}

//
// Paint some UI style thingies
//
void
TTestWindow::Paint(TDC& dc, bool, TRect&)
{
  PaintSample(dc);
}

LRESULT
TTestWindow::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  if (!hWndCtl)
    return TDialog::EvCommand(id, hWndCtl, notifyCode);

  Update();
  PaintSample(TClientDC(*this));

  return true;
}

//
// Provide a background color & brush for child controls to use
//
HBRUSH
TTestWindow::EvCtlColor(HDC hDC, HWND /*hWndChild*/, uint /*ctlType*/)
{
  ::SetBkColor(hDC, TColor::Sys3dFace);
  return TBrush(TColor::Sys3dFace);
}

void
TTestWindow::Update()
{
  static int edgeBit[] = {
    TUIBorder::RaisedOuter,
    TUIBorder::SunkenOuter,
    TUIBorder::RaisedInner,
    TUIBorder::SunkenInner,
  };

  Edge = 0;
  int i;
  for (i = 0; i < 4; i++)
    if (IsDlgButtonChecked(IDC_EDGE_RO + i))
      Edge |= edgeBit[i];

  static int flagBit[] = {
    TUIBorder::Left,
    TUIBorder::Top,
    TUIBorder::Right,
    TUIBorder::Bottom,
    TUIBorder::Diagonal,
    TUIBorder::Fill,
    TUIBorder::Soft,
    TUIBorder::Adjust,
    TUIBorder::Flat,
    TUIBorder::Mono,
  };

  Flags = 0;
  for (i = 0; i < 10; i++)
    if (IsDlgButtonChecked(IDC_FL_LEFT + i))
      Flags |= flagBit[i];
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "DrawEdge", new TTestWindow, true);
      MainWindow->Attr.Style &= ~WS_THICKFRAME;
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
