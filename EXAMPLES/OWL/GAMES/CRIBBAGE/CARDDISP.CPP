//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include "carddisp.h"
#include <owl/gdiobjec.h>

DEFINE_RESPONSE_TABLE1(TCardDisplay, TWindow)
  EV_MESSAGE(WM_VBXFIREEVENT, VBXEventHandler),
END_RESPONSE_TABLE;

TCardDisplay::TCardDisplay(TWindow* parent, int aId, int x, int y, int w, int h,
                          int aBorderSize, int aMaxCards, TPoint *cardPositions,
                          BOOL aRectangle, const char *aLabel,
                          TPoint aLabelPos)
:
  TWindow(parent, "", 0), TCardGroup(aMaxCards)
{

  Attr.Style = WS_CHILD | WS_VISIBLE;
  Attr.X = x;
  Attr.Y = y;
  Attr.W = w;
  Attr.H = h;
  rectangle=aRectangle;
  labelPos = aLabelPos;
  id = aId;

  if (aLabel) {
    strncpy(label,aLabel,20);
    label[19]=0;
  }
  else
    label[0]=0;

  borderSize=aBorderSize;
  cardPos = new TPoint[GetMaxCards()];
  for (int i = 0; i < GetMaxCards(); i++)
    cardPos[i] = cardPositions[i];
  cardvbx= new TVbxMhCardDeck*[GetMaxCards()];

  for (int i=GetMaxCards()-1;i>=0;i--)
    cardvbx[i] = new TVbxMhCardDeck(this, i, "",
                                     cardPos[i].x, cardPos[i].y,
                                     71, 95);
}

void TCardDisplay::SetupWindow()
{
  TWindow::SetupWindow();

  SetBkgndColor(TColor(0, 128, 0));

  for (int i = 0; i < GetMaxCards(); i++) {
    cardvbx[i]->ShowWindow(SW_HIDE);
    cardvbx[i]->SetPropBackColor(TColor(0, 128, 0));
  }
}

void TCardDisplay::Paint(TDC& dc, bool, TRect&)
{
  if (rectangle) {
    TRect temp = GetClientRect();
    temp.left += borderSize;
    temp.top += borderSize;
    temp.right -= borderSize;
    temp.bottom -= borderSize;
    dc.SelectObject(TPen(TColor(0, 255, 0)));
    dc.SelectObject(TBrush(TColor(0, 128, 0)));
    dc.RoundRect(temp, TPoint(10,10));
  }
  dc.SetTextColor(TColor(0, 255, 0));
  dc.SetBkColor(TColor(0, 128, 0));
  dc.TextOut(labelPos, label);
}

TCard* TCardDisplay::Remove(int pos)
{
  TCard* temp = TCardGroup::Remove(pos);
  cardvbx[pos]->ShowWindow(SW_HIDE);

  for (int i = 0; i < GetMaxCards(); i++) {
    if (i < GetCount() )
      Show(i, cards[i]);
    else
      cardvbx[i]->ShowWindow(SW_HIDE);
  }
  return temp;
}
