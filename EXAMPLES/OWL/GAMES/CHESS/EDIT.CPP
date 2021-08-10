//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/window.h>
#include <owl/dc.h>
#include "wcdefs.h"
#include "edit.h"
#include "externs.h"

DEFINE_RESPONSE_TABLE1(TEditBarWindow, TWindow)
  EV_WM_LBUTTONUP,
END_RESPONSE_TABLE;


TEditBarWindow::TEditBarWindow(TWindow* parent, const char* title)
  : TWindow(parent, title)
{
  Attr.Style = WS_CHILD;
  Attr.X = 3*BORDERSIZE + MAXBDSIZE*SQUARE_SIZE + 2*MYFRAMESIZE;
  Attr.Y = BORDERSIZE;
  EditBarRect.right = Attr.W = SQUARE_SIZE*2 + 6;
  EditBarRect.bottom = Attr.H = SQUARE_SIZE*6 + 6;
  EditBarRect.left = EditBarRect.top = 0;
  SelectedItem = 0;
}

void
TEditBarWindow::Paint(TDC& dc, bool , TRect&)
{
  DrawFrame(dc, EditBarRect, TRUE);

  TMemoryDC memDC(dc);
  BITMAP    bm;
  GetObject(PieceBmpArray[0][white], sizeof(BITMAP), &bm);

  int i;
  for (i = 0; i < 6; i++) {
    TBitmap bitmap = PieceBmpArray[i][white];
    TBitmap maskBmp = MaskArray[i];
    memDC.SelectObject(maskBmp);
    dc.BitBlt(3, 3+SQUARE_SIZE*i, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCAND);
    memDC.SelectObject(bitmap);
    dc.BitBlt(3, 3 + SQUARE_SIZE*i, bm.bmWidth, bm.bmHeight,
              memDC, 0, 0, (SelectedItem == i) ? NOTSRCERASE : SRCINVERT);
  }

  for (i = 0; i < 6; i++) {
    TBitmap bitmap = PieceBmpArray[i][black];
    TBitmap maskBmp = MaskArray[i];
    memDC.SelectObject(maskBmp);
    dc.BitBlt(3 + SQUARE_SIZE, 3 + SQUARE_SIZE*i, bm.bmWidth, bm.bmHeight,
              memDC, 0, 0, SRCAND);
    memDC.SelectObject(bitmap);
    dc.BitBlt(3+SQUARE_SIZE, 3 + SQUARE_SIZE*i, bm.bmWidth, bm.bmHeight,
              memDC, 0, 0, (SelectedItem == i+6) ? NOTSRCERASE : SRCINVERT);
  }
}

void
TEditBarWindow::EvLButtonUp(UINT, TPoint& point)
{
  int previousItem = SelectedItem;

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 2; j++) {
      TRect rect(TPoint(j*SQUARE_SIZE + 3, i*SQUARE_SIZE + 3), TSize(SQUARE_SIZE, SQUARE_SIZE));
      if (rect.Contains(point))
        SelectedItem = i + (j ? 6 : 0);
    }
  if (SelectedItem == previousItem)
    return;

  BITMAP bm;
  GetObject(PieceBmpArray[0][white], sizeof(BITMAP), &bm);

  int temp = previousItem % 6;

  TClientDC dc(*this);
  TMemoryDC memDC(dc);

  TBitmap bitmap = PieceBmpArray[temp][(previousItem < 6) ? white : black];
  TBitmap maskBmp = MaskArray[temp];
  memDC.SelectObject(maskBmp);
  dc.BitBlt((previousItem < 6) ? 3 : 3 + SQUARE_SIZE, 3 + SQUARE_SIZE*temp,
            bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCERASE);
  memDC.SelectObject(bitmap);
  dc.BitBlt((previousItem < 6) ? 3 : 3 + SQUARE_SIZE, 3 + SQUARE_SIZE*temp,
            bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCINVERT);

  temp = SelectedItem % 6;

  TBitmap bitmap2 = PieceBmpArray[temp][(SelectedItem < 6) ? white : black];
  TBitmap maskBmp2 = MaskArray[temp];
  memDC.SelectObject(maskBmp2);
  dc.BitBlt((SelectedItem < 6) ? 3 : 3 + SQUARE_SIZE, 3 + SQUARE_SIZE*temp,
         bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCAND);
  memDC.SelectObject(bitmap2);
  dc.BitBlt((SelectedItem < 6) ? 3 : 3 + SQUARE_SIZE, 3 + SQUARE_SIZE*temp,
            bm.bmWidth, bm.bmHeight, memDC, 0, 0, NOTSRCERASE);
}
