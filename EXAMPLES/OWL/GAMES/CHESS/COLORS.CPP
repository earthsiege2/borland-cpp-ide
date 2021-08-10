//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/static.h>
#include <owl/inputdia.h>
#include <bwcc.h>
#include <string.h>
#include <stdio.h>
#include "wcdefs.h"
#include "info.h"
#include "wchess.h"
#include "edit.h"
#include "colors.h"
#include "externs.h"

#define min(x, y)   (((x) < (y)) ? (x) : (y))
#define max(x, y)   (((x) > (y)) ? (x) : (y))

DEFINE_RESPONSE_TABLE1(TColorsDialog, TDialog)
  EV_WM_CTLCOLOR,
  EV_WM_VSCROLL,
  EV_WM_DRAWITEM,
  EV_COMMAND(IDOK, CmOk),
  EV_MESSAGE(CL_KILLFOCUS, EvKillFocus),
END_RESPONSE_TABLE;

TColorsDialog::TColorsDialog(TWindow* parent, const char* name)
  : TWindow(parent),
    TDialog(parent, name)
{
}

TColorsDialog::~TColorsDialog()
{
  DeleteObject(hSBBrush[Red]);
  DeleteObject(hSBBrush[Green]);
  DeleteObject(hSBBrush[Blue]);
}

inline void
TColorsDialog::CLSetFocus(HWND hWnd)
{
  SendMessage(WM_NEXTDLGCTL, WPARAM(hWnd), 1);
  ::SendMessage(hWnd, EM_SETSEL, 0, MAKELONG(0, 32767));
}

BOOL
TColorsDialog::GetColorValue(WORD id)
{
  int  newVal;
  bool ok;
  BYTE *curVal;
  HWND hScroller, hButton;

  newVal = GetDlgItemInt(id, &ok, TRUE);

  switch (id) {
    case IDD_WEDITRED:
      curVal = &WSqColors[0];
      hScroller = GetDlgItem(IDD_WRED);
      hButton = WhiteSq;
      break;
    case IDD_WEDITGREEN:
      curVal = &WSqColors[1];
      hScroller = GetDlgItem(IDD_WGREEN);
      hButton = WhiteSq;
      break;
    case IDD_WEDITBLUE:
      curVal = &WSqColors[2];
      hScroller = GetDlgItem(IDD_WBLUE);
      hButton = WhiteSq;
      break;
    case IDD_BEDITRED:
      curVal = &BSqColors[0];
      hScroller = GetDlgItem(IDD_BRED);
      hButton = BlackSq;
      break;
    case IDD_BEDITGREEN:
      curVal = &BSqColors[1];
      hScroller = GetDlgItem(IDD_BGREEN);
      hButton = BlackSq;
      break;
    case IDD_BEDITBLUE:
      curVal = &BSqColors[2];
      hScroller = GetDlgItem(IDD_BBLUE);
      hButton = BlackSq;
      break;
    }

  if (ok)
    ok = (newVal > 255) ? FALSE : ((newVal < 0 ) ? FALSE : TRUE);
  else
    newVal = *curVal;

  if (!ok) {
    Error("Please enter a valid number between 0 and 255.");
    CLSetFocus(GetDlgItem(id));

  } else if (newVal != *curVal) {
    *curVal = (BYTE)newVal;
    ::SetScrollPos(hScroller, SB_CTL, *curVal, TRUE);
    ::InvalidateRect(hButton, 0, FALSE);
  }
  return ok;
}

void
TColorsDialog::CmOk()
{
  MSG msg;
  while (PeekMessage(&msg, HWindow, CL_KILLFOCUS, CL_KILLFOCUS, PM_NOREMOVE))
    continue;

  if (GetColorValue(IDD_WEDITRED) && GetColorValue(IDD_WEDITGREEN) &&
      GetColorValue(IDD_WEDITBLUE) && GetColorValue(IDD_BEDITRED) &&
      GetColorValue(IDD_BEDITGREEN) && GetColorValue(IDD_BEDITBLUE)) {

    WhiteSquareColor = TColor(WSqColors[0], WSqColors[1], WSqColors[2]);
    BlackSquareColor = TColor(BSqColors[0], BSqColors[1], BSqColors[2]);
    CloseWindow(IDOK);
  }
}

void
TColorsDialog::SetupWindow()
{
  TDialog::SetupWindow();

  WSqColors[0] = WhiteSquareColor.Red();
  WSqColors[1] = WhiteSquareColor.Green();
  WSqColors[2] = WhiteSquareColor.Blue();
  BSqColors[0] = BlackSquareColor.Red();
  BSqColors[1] = BlackSquareColor.Green();
  BSqColors[2] = BlackSquareColor.Blue();

  SetDlgItemInt(IDD_WEDITRED, WSqColors[0], FALSE);
  SetDlgItemInt(IDD_WEDITGREEN, WSqColors[1], FALSE);
  SetDlgItemInt(IDD_WEDITBLUE, WSqColors[2], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_WRED), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_WRED), SB_CTL, WSqColors[0], FALSE);
  ::SetScrollRange(GetDlgItem(IDD_WGREEN), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_WGREEN), SB_CTL, WSqColors[1], FALSE);
  ::SetScrollRange(GetDlgItem(IDD_WBLUE), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_WBLUE), SB_CTL, WSqColors[2], FALSE);

  SetDlgItemInt(IDD_BEDITRED, BSqColors[0], FALSE);
  SetDlgItemInt(IDD_BEDITGREEN, BSqColors[1], FALSE);
  SetDlgItemInt(IDD_BEDITBLUE, BSqColors[2], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_BRED), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_BRED), SB_CTL, BSqColors[0], FALSE);
  ::SetScrollRange(GetDlgItem(IDD_BGREEN), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_BGREEN), SB_CTL, BSqColors[1], FALSE);
  ::SetScrollRange(GetDlgItem(IDD_BBLUE), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_BBLUE), SB_CTL, BSqColors[2], FALSE);

  RWID = ::GetDlgCtrlID(GetDlgItem(IDD_WRED));
  GWID = ::GetDlgCtrlID(GetDlgItem(IDD_WGREEN));
  BWID = ::GetDlgCtrlID(GetDlgItem(IDD_WBLUE));

  RBID = ::GetDlgCtrlID(GetDlgItem(IDD_BRED));
  GBID = ::GetDlgCtrlID(GetDlgItem(IDD_BGREEN));
  BBID = ::GetDlgCtrlID(GetDlgItem(IDD_BBLUE));

  WStatic = ::GetDlgCtrlID(WhiteSq = GetDlgItem(IDD_WHITECOLOR));
  BStatic = ::GetDlgCtrlID(BlackSq = GetDlgItem(IDD_BLACKCOLOR));

  hSBBrush[Red] = CreateSolidBrush(RGB(255, 0, 0));
  hSBBrush[Green] = CreateSolidBrush(RGB(0, 255, 0));
  hSBBrush[Blue] = CreateSolidBrush(RGB(0, 0, 255));
}

HBRUSH
TColorsDialog::EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType)
{
  int id = ::GetDlgCtrlID(hWndChild);
  if (ctlType == CTLCOLOR_SCROLLBAR) {
    if (id == RWID || id == RBID)
      return hSBBrush[Red];
    if (id == GWID || id == GBID)
      return hSBBrush[Green];
    if (id == BWID || id == BBID)
      return hSBBrush[Blue];
    }
  return TDialog::EvCtlColor(hDC, hWndChild, ctlType);
}

void
TColorsDialog::EvVScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl)
{
  int   id = ::GetDlgCtrlID(hWndCtl);
  BYTE* color;
  HWND  hScroller, hButton;
  int   dlgitem;

  if (id == RWID) {
    color = &WSqColors[0];
    hScroller = GetDlgItem(IDD_WRED);
    dlgitem = IDD_WEDITRED;
    hButton = WhiteSq;

  } else if (id == RBID) {
    color = &BSqColors[0];
    hScroller = GetDlgItem(IDD_BRED);
    dlgitem = IDD_BEDITRED;
    hButton = BlackSq;

  } else if (id == BBID) {
    color = &BSqColors[2];
    hScroller = GetDlgItem(IDD_BBLUE);
    dlgitem = IDD_BEDITBLUE;
    hButton = BlackSq;

  } else if (id == BWID) {
    color = &WSqColors[2];
    hScroller = GetDlgItem(IDD_WBLUE);
    dlgitem = IDD_WEDITBLUE;
    hButton = WhiteSq;

  } else if (id == GBID) {
    color = &BSqColors[1];
    hScroller = GetDlgItem(IDD_BGREEN);
    dlgitem = IDD_BEDITGREEN;
    hButton = BlackSq;

  } else if (id == GWID) {
    color = &WSqColors[1];
    hScroller = GetDlgItem(IDD_WGREEN);
    dlgitem = IDD_WEDITGREEN;
    hButton = WhiteSq;

  } else
      return;

  switch (scrollCode) {
    case SB_PAGEDOWN:
      *color += (BYTE)15;
    case SB_LINEDOWN:
      *color = (BYTE)min(255, *color + 1);
      break;
    case SB_PAGEUP:
      *color -= (BYTE)15;
    case SB_LINEUP:
      *color = (BYTE)max(0, *color - 1);
      break;
    case SB_TOP:
      *color = 0;
      break;
    case SB_BOTTOM:
      *color = 255;
      break;
    case SB_THUMBPOSITION:
    case SB_THUMBTRACK:
      *color = (BYTE)thumbPos;
  }
  ::SetScrollPos(hScroller, SB_CTL, *color, TRUE);
  SetDlgItemInt(dlgitem, *color, FALSE);
  ::InvalidateRect(hButton, 0, FALSE);
}

void
TColorsDialog::EvDrawItem(UINT ctlID, DRAWITEMSTRUCT far& drawInfo)
{
  if (drawInfo.itemAction != ODA_DRAWENTIRE)
    return;

  BYTE   *colors;
  if (ctlID == WStatic)
    colors = WSqColors;
  else if (ctlID == BStatic)
    colors = BSqColors;
  else
    return;

  HANDLE hOldBrush = SelectObject(drawInfo.hDC,
    CreateSolidBrush(RGB(colors[0], colors[1], colors[2])));

  TRect* r = (TRect*)&drawInfo.rcItem;

  ::Rectangle(drawInfo.hDC, r->left, r->top, r->right, r->bottom);
  DeleteObject(SelectObject(drawInfo.hDC, hOldBrush));
}

LRESULT
TColorsDialog::EvKillFocus(WPARAM wParam, LPARAM)
{
  WORD id = (WORD)wParam;
  HWND focus = GetFocus();

  if (GetDlgItem(id) == focus || GetDlgItem(IDCANCEL) == focus ||
      GetActiveWindow() != HWindow)
    return 0;
  GetColorValue(id);
  return 1;
}

LRESULT
TColorsDialog::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  if (hWndCtl && notifyCode == EN_KILLFOCUS) {
    if (::SendMessage(hWndCtl, EM_GETMODIFY, 0, 0))
      PostMessage(CL_KILLFOCUS, id);
    return 1;
  }
  return TDialog::EvCommand(id, hWndCtl, notifyCode);
}
