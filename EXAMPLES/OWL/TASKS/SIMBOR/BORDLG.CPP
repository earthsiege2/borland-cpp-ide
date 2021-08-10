// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "SimBor.h"
#include <stdio.h>
#include <windowsx.h>

//
// constructor
//
TSimulatedBorlandDialog::TSimulatedBorlandDialog(TWindow* parent,
  TResId resId, TModule* module)
:
  TDialog(parent, resId, module)
{
  TBitmap bmDialog(*GetApplication(), IDB_DLGBRSH);
  BrDialog = new TBrush(bmDialog);
}


//
// destructor
//
TSimulatedBorlandDialog::~TSimulatedBorlandDialog()
{
  delete BrDialog;
}

//
// Response Table
//
DEFINE_RESPONSE_TABLE1(TSimulatedBorlandDialog, TDialog)
  EV_WM_PAINT,
  EV_WM_CTLCOLOR,
END_RESPONSE_TABLE;


//
// Draw3DRect
//
void
Draw3DRect(TDC& dc, TRect& rect, TPen hilite, TPen shadow)
{
  dc.SelectObject(hilite);
  dc.MoveTo(rect.left, rect.bottom);
  dc.LineTo(rect.left, rect.top);
  dc.LineTo(rect.right, rect.top);
  dc.MoveTo(rect.right-1, rect.top);
  dc.LineTo(rect.right-1, rect.bottom-1);
  dc.LineTo(rect.left+1, rect.bottom-1);
  dc.RestorePen();

  dc.SelectObject(shadow);
  dc.MoveTo(rect.left+1, rect.bottom-1);
  dc.LineTo(rect.left+1, rect.top+1);
  dc.LineTo(rect.right-1, rect.top+1);
  dc.MoveTo(rect.right, rect.top);
  dc.LineTo(rect.right, rect.bottom);
  dc.LineTo(rect.left, rect.bottom);
  dc.RestorePen();
}

//
// EvPaint
//
void
TSimulatedBorlandDialog::EvPaint()
{
  // let the dialog paint itself
  //
  TDialog::EvPaint();

  // draw 3D look
  //
  TClientDC dc(HWindow);
  TRect rect;
  GetClientRect(rect);
  rect.right--;
  rect.bottom--;
  Draw3DRect(dc, rect, GetStockPen(WHITE_PEN), GetStockPen(BLACK_PEN));
}


//
// Handle CtlColor
//
HBRUSH TSimulatedBorlandDialog::EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType)
{
  switch (ctlType) {
    case CTLCOLOR_DLG:
      // change background of the dialog
      //
      return *BrDialog;
  }
  return TDialog::EvCtlColor(hDC, hWndChild, ctlType);
}

//
// constructor
//
TSimBorDialog::TSimBorDialog(TWindow* parent, TResId resId) :
  TSimulatedBorlandDialog(parent, resId)
{
  ListBox   = new TListBox(this, ID_LISTBOX);
  ScrollBar = new TScrollBar(this, ID_SCROLLBAR);
  Static    = new TStatic(this, ID_MESSAGE);
}

//
// destructor
//
TSimBorDialog::~TSimBorDialog()
{
  delete BrScrollBar;
  delete BrListBox;
  delete BrStatic;
}

//
// SetupWindow
//
void
TSimBorDialog::SetupWindow()
{
  TSimulatedBorlandDialog::SetupWindow();

  LOGBRUSH lbTemp;

  // create hatched brush
  //
  lbTemp.lbStyle = BS_HATCHED;
  lbTemp.lbColor = RGB(255, 0, 255);
  lbTemp.lbHatch = HS_DIAGCROSS;
  BrStatic = new TBrush(&lbTemp);

  lbTemp.lbStyle = BS_SOLID;
  lbTemp.lbColor = RGB(255, 255, 255);
  lbTemp.lbHatch = 0;
  BrListBox = new TBrush(&lbTemp);

  // create pattern brushes
  //
  TBitmap bmScrollBar(*GetApplication(), IDB_SCRLBRSH);
  BrScrollBar = new TBrush(bmScrollBar);

  // add strings to the listbox
  //
  char cBuf[20];
  for (int i = 0; i < 20; i++) {
    sprintf(cBuf, "Line number #%d", i);
    ListBox->AddString(cBuf);
  }

  // set the scrollbar's thumb in the middle
  //
  ScrollBar->SetRange(0, 2);
  ScrollBar->SetPosition(1);
}

//
// Response table
//
DEFINE_RESPONSE_TABLE1(TSimBorDialog, TSimulatedBorlandDialog)
  EV_WM_CTLCOLOR,
END_RESPONSE_TABLE;


//
// Handle CtlColor
//
HBRUSH
TSimBorDialog::EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType)
{
  TDC dc(hDC);

  switch (ctlType) {
    case CTLCOLOR_STATIC:
      dc.SetBkMode(TRANSPARENT);      // transparent bkgrnd
      dc.SetTextColor(RGB(0, 0, 0));  // black text
      return *BrStatic;

    case CTLCOLOR_LISTBOX:
      dc.SetBkMode(TRANSPARENT);      // transparent bkgrnd
      dc.SetTextColor(RGB(0, 0, 255));
      return *BrListBox;

    case CTLCOLOR_SCROLLBAR:
      dc.SetBkMode(TRANSPARENT);
      dc.SetTextColor(RGB(0, 0, 0));
      return *BrScrollBar;
  }

  return TSimulatedBorlandDialog::EvCtlColor(hDC, hWndChild, ctlType);
}

