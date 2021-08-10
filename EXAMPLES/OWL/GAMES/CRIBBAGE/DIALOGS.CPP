//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include "dialogs.h"

TQuickPointsDialog::TQuickPointsDialog(TWindow* parent, const char *message,
                                        BOOL aPegging, int aActualPoints):
  TDialog(parent, QUICK_POINTS_DIALOG), msgText(message),
  actualPoints(aActualPoints), pegging(aPegging) {
  msg = new TStatic(this, IDC_QUICK_POINTS_MESSAGE);
  points=0;
  for (int i=15;i<30;i++)
    button[i-15]=new TButton(this, IDC_PUSHBUTTON0 + i);
 }

void TQuickPointsDialog::SetupWindow() {
  TDialog::SetupWindow();
  TRect rect;

  GetWindowRect(rect);
  msg->SetText(msgText);

  if (pegging) {
    rect.left+=200;
    rect.top+=100;
    rect.right=rect.left+200;
    rect.bottom=rect.top+200;
    SetWindowPos(0, rect, SWP_NOZORDER);
    for (int i=15;i<30;i++)
      button[i-15]->ShowWindow(SW_HIDE);
  }
  else {
    rect.left+=5;
    rect.top+=5;
    rect.right=rect.left+200;
    rect.bottom=rect.top+270;
    SetWindowPos(0, rect, SWP_NOZORDER);
  }
}

DEFINE_RESPONSE_TABLE1(TCutDeckDialog, TDialog)
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_COMMAND(IDOK, Ignore),
  EV_COMMAND(IDCANCEL, Ignore),
END_RESPONSE_TABLE;

DEFINE_RESPONSE_TABLE1(TShowPointsDialog, TDialog)
  EV_COMMAND(CM_DETAIL, ShowDetail),
END_RESPONSE_TABLE;

void TShowPointsDialog::SetupWindow() {
  char temp[50];
  TDialog::SetupWindow();
  switch (mode) {
    case mtMissed:
      wsprintf(temp,"You missed %d %s. Computer takes them.",
               missedPoints, (missedPoints==1)?"point":"points");
      break;
    case mtCrib:
      wsprintf(temp,"Computer counts %d %s in the crib.",
                points, (points==1)?"point":"points");
      break;
    case mtHand:
      wsprintf(temp,"Computer counts %d %s in its hand.",
                points, (points==1)?"point":"points");
      break;
    case mtPegging:
      wsprintf(temp,"Computer pegs %d %s",
                points, (points==1)?"point":"points");
      break;
  }
  msg->SetText(temp);
  if ((mode!=mtMissed) && (!points))
    detailBtn->EnableWindow(false);
}

void TShowPointsDialog::ShowDetail() {
  TRect rect;
  int tabs[3];

  tabs[0]=0;
  tabs[1]=50;
  tabs[2]=100;
  GetWindowRect(rect);
  rect.bottom+=150;
  SetWindowPos(0, rect, SWP_NOMOVE | SWP_NOZORDER);
  detailBtn->ShowWindow(SW_HIDE);
  ok->SetWindowPos(0, TRect(30, 200, 0, 0), SWP_NOSIZE | SWP_NOZORDER);
  listbox = new TListBox(this, 1, 10, 50, 210, 150);
  listbox->Attr.Style = (listbox->Attr.Style & ~LBS_SORT) | LBS_USETABSTOPS;
  listbox->Create();
  listbox->SetWindowFont(GetWindowFont(), false);
  listbox->SetTabStops(3, tabs);
  for (int i=0;i<detailCount;i++)
    listbox->AddString(detail[i]);
}

