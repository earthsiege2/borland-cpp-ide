//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/static.h>
//#include <filedial.h>
//#include <inputdia.h>
//#include <bwcc.h>
#include <string.h>
#include <stdio.h>
#include "wcdefs.h"
#include "info.h"
#include "wchess.h"
#include "pvalue.h"
#include "externs.h"

const int DefaultValues[5] = {0x90, 0x4c, 0x30, 0x30, 0x10};

enum PIECES { pvqueen, pvrook, pvbishop, pvknight, pvpawn};

#define min(x, y)  (((x) < (y)) ? (x) : (y))
#define max(x, y)  (((x) > (y)) ? (x) : (y))


DEFINE_RESPONSE_TABLE1(TPieceValueDialog, TDialog)
  EV_MESSAGE(PV_KILLFOCUS, EvPvKillFocus),
  EV_COMMAND(IDOK, CmOk),
  EV_WM_HSCROLL,
  EV_COMMAND(IDD_DEFAULT, CmDefault),
END_RESPONSE_TABLE;

TPieceValueDialog::TPieceValueDialog(TWindow* parent, const char* name)
  : TWindow(parent),
    TDialog(parent, name)
{
}

inline void
TPieceValueDialog::PVSetFocus(HWND hWnd)
{
  SendMessage(WM_NEXTDLGCTL, WPARAM(hWnd), 1L);
  ::SendMessage(hWnd, EM_SETSEL, 0, MAKELONG(0, 32767));
}

BOOL
TPieceValueDialog::GetColorValue(WORD id)
{
  bool ok;
  int newVal = GetDlgItemInt(id, &ok, TRUE);

  int* curVal;
  HWND hScroller;
  switch (id) {
    case IDD_EQUEEN:
      curVal = &Values[pvqueen];
      hScroller = GetDlgItem(IDD_QUEEN);
      break;
    case IDD_EROOK:
      curVal = &Values[pvrook];
      hScroller = GetDlgItem(IDD_ROOK);
      break;
    case IDD_EBISHOP:
      curVal = &Values[pvbishop];
      hScroller = GetDlgItem(IDD_BISHOP);
      break;
    case IDD_EKNIGHT:
      curVal = &Values[pvknight];
      hScroller = GetDlgItem(IDD_KNIGHT);
      break;
    case IDD_EPAWN:
      curVal = &Values[pvpawn];
      hScroller = GetDlgItem(IDD_PAWN);
      break;
    }

  if (ok)
    ok = (newVal > 255) ? FALSE : ((newVal < 0) ? FALSE : TRUE);
  else
    newVal = *curVal;

  if (!ok) {
    Error("Please enter a valid number between 0 and 255.");
    PVSetFocus(GetDlgItem(id));

  } else if (newVal != *curVal) {
    *curVal = newVal;
    ::SetScrollPos(hScroller, SB_CTL, *curVal, TRUE);
  }
  return ok;
}

void
TPieceValueDialog::CmOk()
{
  MSG msg;
  while (PeekMessage(&msg, HWindow, PV_KILLFOCUS, PV_KILLFOCUS, PM_NOREMOVE))
    continue;

  if (GetColorValue(IDD_EQUEEN) && GetColorValue(IDD_EROOK) &&
      GetColorValue(IDD_EBISHOP) && GetColorValue(IDD_EKNIGHT) &&
      GetColorValue(IDD_EPAWN)) {
    PieceValue[queen] = Values[pvqueen] * 16;
    PieceValue[rook]  = Values[pvrook] * 16;
    PieceValue[bishop] = Values[pvbishop] * 16;
    PieceValue[knight] = Values[pvknight] * 16;
    PieceValue[pawn] = Values[pvpawn] * 16;
    CloseWindow(IDOK);
  }
}

void
TPieceValueDialog::SetupWindow()
{
  TDialog::SetupWindow();

  Values[pvqueen] = PieceValue[queen] / 16;
  Values[pvrook] = PieceValue[rook] / 16;
  Values[pvbishop] = PieceValue[bishop] / 16;
  Values[pvknight] = PieceValue[knight] / 16;
  Values[pvpawn] = PieceValue[pawn] / 16;

  SetDlgItemInt(IDD_EQUEEN, Values[pvqueen], FALSE);
  SetDlgItemInt(IDD_EROOK, Values[pvrook], FALSE);
  SetDlgItemInt(IDD_EBISHOP, Values[pvbishop], FALSE);
  SetDlgItemInt(IDD_EKNIGHT, Values[pvknight], FALSE);
  SetDlgItemInt(IDD_EPAWN, Values[pvpawn], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_QUEEN), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_QUEEN), SB_CTL, Values[pvqueen], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_ROOK), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_ROOK), SB_CTL, Values[pvrook], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_BISHOP), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_BISHOP), SB_CTL, Values[pvbishop], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_KNIGHT), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_KNIGHT), SB_CTL, Values[pvknight], FALSE);

  ::SetScrollRange(GetDlgItem(IDD_PAWN), SB_CTL, 0, 255, FALSE);
  ::SetScrollPos(GetDlgItem(IDD_PAWN), SB_CTL, Values[pvpawn], FALSE);
}


void
TPieceValueDialog::CmDefault()
{
  memcpy(Values, DefaultValues, 5 * sizeof(int));

  SetDlgItemInt(IDD_EQUEEN, Values[pvqueen], FALSE);
  SetDlgItemInt(IDD_EROOK, Values[pvrook], FALSE);
  SetDlgItemInt(IDD_EBISHOP, Values[pvbishop], FALSE);
  SetDlgItemInt(IDD_EKNIGHT, Values[pvknight], FALSE);
  SetDlgItemInt(IDD_EPAWN, Values[pvpawn], FALSE);

  ::SetScrollPos(GetDlgItem(IDD_QUEEN), SB_CTL, Values[pvqueen], TRUE);
  ::SetScrollPos(GetDlgItem(IDD_ROOK), SB_CTL, Values[pvrook], TRUE);
  ::SetScrollPos(GetDlgItem(IDD_BISHOP), SB_CTL, Values[pvbishop], TRUE);
  ::SetScrollPos(GetDlgItem(IDD_KNIGHT), SB_CTL, Values[pvknight], TRUE);
  ::SetScrollPos(GetDlgItem(IDD_PAWN), SB_CTL, Values[pvpawn], TRUE);
}

void
TPieceValueDialog::EvHScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl)
{
  int id = ::GetDlgCtrlID(hWndCtl);
  HWND hScroller;
  int* curvalue;
  int  dlgitem;

  if (id == ::GetDlgCtrlID(hScroller = GetDlgItem(IDD_QUEEN))) {
    curvalue = &Values[pvqueen];
    dlgitem = IDD_EQUEEN;

  } else if (id == ::GetDlgCtrlID(hScroller = GetDlgItem(IDD_ROOK))) {
    curvalue = &Values[pvrook];
    dlgitem = IDD_EROOK;

  } else if (id == ::GetDlgCtrlID(hScroller = GetDlgItem(IDD_BISHOP))) {
    curvalue = &Values[pvbishop];
    dlgitem = IDD_EBISHOP;

  } else if (id == ::GetDlgCtrlID(hScroller = GetDlgItem(IDD_KNIGHT))) {
    curvalue = &Values[pvknight];
    dlgitem = IDD_EKNIGHT;

  } else if (id == ::GetDlgCtrlID(hScroller = GetDlgItem(IDD_PAWN))) {
    curvalue = &Values[pvpawn];
    dlgitem = IDD_EPAWN;

  } else
    return;

  switch (scrollCode) {
    case SB_PAGEDOWN:
      *curvalue += 15;
    case SB_LINEDOWN:
      *curvalue = min(255, *curvalue + 1);
      break;
    case SB_PAGEUP:
      *curvalue -= 15;
    case SB_LINEUP:
      *curvalue = max(0, *curvalue - 1);
      break;
    case SB_TOP:
      *curvalue = 0;
      break;
    case SB_BOTTOM:
      *curvalue = 255;
      break;
    case SB_THUMBPOSITION:
    case SB_THUMBTRACK:
      *curvalue = thumbPos;
    }
  ::SetScrollPos(hScroller, SB_CTL, *curvalue, TRUE);
  SetDlgItemInt(dlgitem, *curvalue, FALSE);
}

LRESULT
TPieceValueDialog::EvPvKillFocus(WPARAM wParam, LPARAM)
{
  WORD id = WORD(wParam);
  HWND focus = GetFocus();
  if (GetDlgItem(id) != focus && GetDlgItem(IDCANCEL) != focus &&
      GetDlgItem(IDD_DEFAULT) != focus && GetActiveWindow() == HWindow)
    GetColorValue(id);
  return 0;
}

LPARAM
TPieceValueDialog::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  if (hWndCtl && notifyCode == EN_KILLFOCUS) {
    if (::SendMessage(hWndCtl, EM_GETMODIFY, 0, 0))
      PostMessage(PV_KILLFOCUS, id);
    return 1;
  }
  return TDialog::EvCommand(id, hWndCtl, notifyCode);
}
