//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/uihelper.h>
#include <owl/listbox.h>
#include <owl/gdiobjec.h>
#include <stdio.h>
#include "drawstat.rh"

class TTestWindow : public TDialog {
  public:
    TTestWindow();

  protected:
    void    Paint(TDC& dc, bool erase, TRect& rect);
    void    SetupWindow();
    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);

    void    PaintSample(TDC& dc);
    void    Update();

    uint  Type;
    uint  State;
    TRect SampleRect;
    TBitmap SampleBmp;
    TIcon SampleIcn;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_WININICHANGE,
END_RESPONSE_TABLE;


TTestWindow::TTestWindow()
:
  TDialog(0, IDD_DRAWSTATE, 0),
  SampleBmp(*GetModule(), IDB_SAMPLE),
  SampleIcn(*GetModule(), TResId(IDI_SAMPLE))
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

  SendDlgItemMessage( IDC_BITMAP, BM_SETCHECK, 1, 0 );

  ::GetWindowRect(GetDlgItem(IDC_SAMPLE), &SampleRect);
  ScreenToClient(SampleRect.TopLeft());
  ScreenToClient(SampleRect.BottomRight());
  ::DestroyWindow(GetDlgItem(IDC_SAMPLE));
  Update();
}


void
TTestWindow::PaintSample(TDC& dc)
{
  dc.SelectObject(TBrush(TColor::Sys3dFace));
  dc.PatBlt(SampleRect.InflatedBy(10,10), PATCOPY);

  dc.SetBkColor(TColor::Sys3dHilight);
  dc.SetTextColor(TColor::Sys3dFace);

  LPARAM lp = 0;
  switch (Type) {
    case DST_BITMAP:
      lp = LPARAM((HBITMAP)SampleBmp);
      break;
    case DST_ICON:
      lp = LPARAM((HICON)SampleIcn);
      break;
    case DST_TEXT:
      lp = LPARAM("PushMe");
      break;
    case DST_PREFIXTEXT:
      lp = LPARAM("Click&Me");
      break;
  }

  TUIFace::Draw(dc, TBrush(TColor::Sys3dShadow), lp, 0,
            SampleRect.left, SampleRect.top,
            SampleRect.Width(), SampleRect.Height(), Type | State);
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
  Invalidate();
  UpdateWindow();

  return true;
}

void
TTestWindow::Update()
{
  static int typeBit[] = {
    DST_BITMAP,
    DST_ICON,
    DST_PREFIXTEXT,
    DST_TEXT,
  };
  Type = 0;
  int i;
  for (i = 0; i < COUNTOF(typeBit); i++)
    if (IsDlgButtonChecked(IDC_BITMAP + i))
      Type |= typeBit[i];

  static int stateBit[] = {
    DSS_NORMAL,
    DSS_UNION,
    DSS_DISABLED,
    DSS_MONO,
    DSS_RIGHT,
  };
  State = 0;
  for (i = 0; i < COUNTOF(stateBit); i++)
    if (IsDlgButtonChecked(IDC_NORMAL + i))
      State |= stateBit[i];
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "DrawState", new TTestWindow, true);
      MainWindow->Attr.Style &= ~WS_THICKFRAME;
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
