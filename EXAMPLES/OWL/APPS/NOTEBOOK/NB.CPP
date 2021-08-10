//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/mdi.h>
#include <owl/decmdifr.h>
#include <owl/statusba.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"              // debugging support
#include "notebook.h"
#include "nb.h"
//----------------------------------------------------------------------------
DEFINE_RESPONSE_TABLE1(TNBClient, TMDIClient)
  EV_COMMAND_AND_ID(MID_TOP, NewWin),
  EV_COMMAND_AND_ID(MID_RIGHT, NewWin),
  EV_COMMAND_AND_ID(MID_BOTTOM, NewWin),
  EV_COMMAND_AND_ID(MID_LEFT, NewWin),
  EV_COMMAND(MID_EXIT, CmdExit),
  EV_COMMAND(MID_CASCADE, CmdCascade),
  EV_COMMAND(MID_TILEH, CmdTileH),
  EV_COMMAND(MID_TILEV, CmdTileV),
  EV_COMMAND(MID_ARRANGE, CmdArrange),
END_RESPONSE_TABLE;
//----------------------------------------------------------------------------
DEFINE_RESPONSE_TABLE2(TMyNotebook, TNotebook, TMDIChild)
  EV_WM_SIZE,
  EV_WM_HSCROLL,
  EV_WM_VSCROLL,
END_RESPONSE_TABLE;
//----------------------------------------------------------------------------
TTestApp::TTestApp()
    : TApplication("Notebook Test App")
{
}
//----------------------------------------------------------------------------
TMyNotebook::TMyNotebook(TMDIClient& parent, const char far* title, int tabloc)
    : TMDIChild(parent, title), TNotebook(tabloc)
{
  Attr.Style |= (WS_HSCROLL | WS_VSCROLL);              // for testing...
  sprintf(textbuff, "Window %d", 0);
  SetTabCnt(2000, 0, 0);

  maxhs = 100;          // match initial scroll bars
  maxvs = 100;          // match initial scroll bars
  curhs = 0;
  curvs = 0;
  myresizing = FALSE;
  maxxval = 350;
  maxyval = 250;
}
//----------------------------------------------------------------------------
void TMyNotebook::ActivateTab(int tabnum)
{
  TNotebook::ActivateTab(tabnum);

  sprintf(textbuff, "Window %d", tabnum);
  ::InvalidateRect(HWindow, NULL, TRUE);
}
//----------------------------------------------------------------------------
void TTestApp::InitMainWindow()
{
  EnableCtl3d(TRUE);

  TDecoratedMDIFrame *frame;

  Client = new TNBClient;
  frame = new TDecoratedMDIFrame("Notebook Test App", "mainmenu",
    *Client, TRUE);
  frame->SetIcon(this, "nb");
  MainWindow = frame;

  TStatusBar *statusbar = new TStatusBar(0, TGadget::Recessed,
    TStatusBar::CapsLock | TStatusBar::NumLock | TStatusBar::Overtype);

  frame->Insert(*statusbar, TDecoratedFrame::Bottom);
}
//----------------------------------------------------------------------------
void TTestApp::InitInstance()
{
  TApplication::InitInstance();

  Client->NewWin(MID_LEFT);
}
//----------------------------------------------------------------------------
int OwlMain(int /*argc*/, char* /*argv*/ [])
{
#if defined(__WIN32__)
  if (!TSystem::Has3dUI()) {
    ::MessageBox(0, "Must be run on Windows 4.0 or greater.", "OWL Examples", MB_OK);
    return 0;
  }
#endif
  return(TTestApp().Run());
}
//----------------------------------------------------------------------------
void TMyNotebook::Paint(TDC& dc, bool erase, TRect& /*rect*/)
{
  dc.SetWindowOrg(TPoint(curhs, curvs));

  if (erase) {
    RECT myrect = GetClientRect();
    FillRect(dc, &myrect, (HBRUSH) GetStockObject(WHITE_BRUSH));
  }

  TBrush bluebrush(TColor::LtBlue);
  TBrush greenbrush(TColor::LtGreen);
  TBrush redbrush(TColor::LtRed);

  dc.FrameRect(0, 0, 350, 250, redbrush);
  dc.FrameRect(50, 50, 300, 200, greenbrush);
  dc.FrameRect(100, 100, 250, 150, bluebrush);

  dc.DrawText(textbuff, -1, TRect(100, 100, 250, 150),
    DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
//----------------------------------------------------------------------------
void TMyNotebook::EvSize(UINT sizeType, TSize& newsize)
{
  defer_ncpaint = 1;            // don't paint nc until futher notice...
                        // otherwise base EvSize() will paint
  TNotebook::EvSize(sizeType, newsize);

  if (! myresizing) {
    int cwidth = newsize.cx;
    int cheight = newsize.cy;
    int hsize = GetSystemMetrics(SM_CYHSCROLL) - 1;
    int vsize = GetSystemMetrics(SM_CXVSCROLL) - 1;
    int prev_maxvs = maxvs;
    int prev_maxhs = maxhs;

    if ((maxhs) && (tabloc != LOC_BOTTOM))  // add size for horz sb
            cheight += hsize;
    if ((maxvs) && (tabloc != LOC_RIGHT))   // add size for vert sb
            cwidth += vsize;

    // set "maxhs" and "maxvs" to max amt to be scrolled in each dir
    if (cwidth < maxxval) {
            maxhs = maxxval - cwidth;
            if (tabloc != LOC_BOTTOM)
              cheight -= hsize;
    } else
            maxhs = 0;

    if (cheight < maxyval){
            maxvs = maxyval - cheight;
            if (tabloc != LOC_RIGHT)
              cwidth -= vsize;
    } else
            maxvs = 0;

    // if vscroll being used, recalc maxhs
    if ((maxvs) && (cwidth < maxxval))
            maxhs = maxxval - cwidth;

    myresizing = TRUE;          // avoid recursion
    if (maxhs != prev_maxhs){
      curhs = min(curhs, maxhs);
      SetScrollRange(SB_HORZ, 0, maxhs, FALSE);
      SetScrollPos(SB_HORZ, curhs, TRUE);
    }

    if (maxvs != prev_maxvs){
        curvs = min(curvs, maxvs);
        SetScrollRange(SB_VERT, 0, maxvs, FALSE);
        SetScrollPos(SB_VERT, curvs, TRUE);
    }
    ForceResize(TRUE);
    myresizing = FALSE;
    ::InvalidateRect(HWindow, NULL, TRUE);
  }
}
//----------------------------------------------------------------------------
void TMyNotebook::EvHScroll(UINT scrollCode, UINT thumbPos, HWND /*hWndCtl*/)
{
  int delta, newhs;
  TRect crect = GetClientRect();
  int cwidth = crect.Width();

  switch (scrollCode){
    case SB_LINELEFT:
            delta = -cwidth/10;
            break;

    case SB_LINERIGHT:
            delta = cwidth/10;
            break;

    case SB_PAGELEFT:
            delta = -cwidth;
            break;

    case SB_PAGERIGHT:
            delta = cwidth;
            break;

    case SB_THUMBPOSITION:
            delta = thumbPos-curhs;
            break;

    default:
            delta = 0;
            break;
  }

  newhs = min(max(0, curhs + delta), maxhs);
  if (newhs != curhs) {
    curhs = newhs;
    SetScrollPos(SB_HORZ, curhs, TRUE);
    ::InvalidateRect(HWindow, NULL, TRUE);
    UpdateWindow();
  }
}
//----------------------------------------------------------------------------
void TMyNotebook::EvVScroll(UINT scrollCode, UINT thumbPos, HWND /*hWndCtl*/)
{
  int newvs, delta;
  TRect crect = GetClientRect();
  int cheight = crect.Height();

  switch (scrollCode) {
    case SB_LINEUP:
            delta = -cheight/10;
            break;

    case SB_LINEDOWN:
            delta = cheight/10;
            break;

    case SB_PAGEUP:
            delta = -cheight;
            break;

    case SB_PAGEDOWN:
            delta = cheight;
            break;

    case SB_THUMBPOSITION:
            delta = thumbPos-curvs;
            break;

    default:
            delta = 0;
            break;
  }

  newvs = min(max(0, curvs + delta), maxvs);
  if (newvs != curvs) {
    curvs = newvs;
    SetScrollPos(SB_VERT, curvs, TRUE);
    ::InvalidateRect(HWindow, NULL, TRUE);
    UpdateWindow();
  }
}
//----------------------------------------------------------------------------
TNBClient::TNBClient(TModule *module)
    : TMDIClient(module)
{
}
//----------------------------------------------------------------------------
void TNBClient::NewWin(WPARAM cmd)
{
  int tabloc;
  TMyNotebook *nb;
  char name[30];

  tabloc = cmd-MID_TOP;
  switch (tabloc) {
    case LOC_BOTTOM:
            strcpy(name, "Tabs on Bottom");
            break;
    case LOC_TOP:
            strcpy(name, "Tabs on Top");
            break;
    case LOC_LEFT:
            strcpy(name, "Tabs on Left");
            break;
    case LOC_RIGHT:
            strcpy(name, "Tabs on Right");
            break;
  }

  nb = new TMyNotebook(*this, name, tabloc);
  nb->SetIcon(GetApplication(), "notebook");

  nb->Create();
}
//----------------------------------------------------------------------------
void TNBClient::CmdCascade()
{
  CascadeChildren();
}
//----------------------------------------------------------------------------
void TNBClient::CmdTileH()
{
  TileChildren(MDITILE_HORIZONTAL);
}
//----------------------------------------------------------------------------
void TNBClient::CmdTileV()
{
  TileChildren(MDITILE_VERTICAL);
}
//----------------------------------------------------------------------------
void TNBClient::CmdArrange()
{
  ArrangeIcons();
}
//----------------------------------------------------------------------------
void TNBClient::CmdExit()
{
  PostQuitMessage(0);
}
//----------------------------------------------------------------------------
