//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include "board.h"
#include <owl/gdiobjec.h>

#include "cribbage.rh"

TCribbageBoard::TCribbageBoard(TWindow* parent, int x, int y)
:
  TWindow(parent, "", 0)
{
  Attr.Style = WS_CHILD | WS_VISIBLE;
  Attr.X = x;
  Attr.Y = y;
  Attr.W = 200;
  Attr.H = 400;
  points[0] = points[1] = 0;
  oldpoints[0] = oldpoints[1] = -1;
  playerName[0][0] = 0;
  playerName[1][0] = 0;

  // initialize the array of hole positions

  int i,j;
  for (i=0;i<2;i++)
    for (j=0;j<123;j++)
      holes[i][j] = TPoint(0,0);

  // starting holes
  for (i=0;i<2;i++) {
    holes[0][i] = TPoint(25, 289-i*9);
    holes[1][i] = TPoint(36, 289-i*9);
  }
  // all straight columns
  for (i=0;i<5;i++)
    for (j=0;j<5;j++) {
      holes[0][j*5+i+2] = TPoint(25, 270-j*46-i*9);
      holes[1][j*5+i+2] = TPoint(36, 270-j*46-i*9);

      holes[1][1+55-j*5-i] = TPoint(69, 270-j*46-i*9);
      holes[0][1+55-j*5-i] = TPoint(80, 270-j*46-i*9);

      holes[0][j*5+i+2+60] = TPoint(113, 270-j*46-i*9);
      holes[1][j*5+i+2+60] = TPoint(124, 270-j*46-i*9);

      holes[1][1+115-j*5-i] = TPoint(157, 270-j*46-i*9);
      holes[0][1+115-j*5-i] = TPoint(168, 270-j*46-i*9);
    }
  // last 5 holes
  for (i=0;i<5;i++) {
    holes[1][1+116+i] = TPoint(157, 280+i*9);
    holes[0][1+116+i] = TPoint(168, 280+i*9);
  }
  // last hole
  holes[1][122] = TPoint(157, 280+5*9+1);
  holes[0][122] = TPoint(168, 280+5*9+1);
  // first curve
  holes[0][26+1] = TPoint(25,40);
  holes[1][26+1] = TPoint(36,40);
  holes[0][27+1] = TPoint(32,23);
  holes[1][27+1] = TPoint(41,29);
  holes[0][28+1] = TPoint(52,13);
  holes[1][28+1] = TPoint(52,24);
  holes[0][29+1] = TPoint(72,23);
  holes[1][29+1] = TPoint(63,29);
  holes[0][30+1] = TPoint(80,40);
  holes[1][30+1] = TPoint(69,40);
  // third curve
  for (i=0;i<5;i++) {
    holes[0][86+1+i] = holes[0][26+1+i]+TPoint(113-25,0);
    holes[1][86+1+i] = holes[1][26+1+i]+TPoint(113-25,0);
  }
  holes[1][56+1] = TPoint(69, 280);
  holes[0][56+1] = TPoint(80, 280);
  holes[1][57+1] = TPoint(76, 297);
  holes[0][57+1] = TPoint(85, 291);
  holes[1][58+1] = TPoint(96, 307);
  holes[0][58+1] = TPoint(96, 296);
  holes[1][59+1] = TPoint(116, 297);
  holes[0][59+1] = TPoint(107, 291);
  holes[1][60+1] = TPoint(124, 280);
  holes[0][60+1] = TPoint(113, 280);
}

void TCribbageBoard::Reset() {
  points[0] = points[1] = 0;
  oldpoints[0] = oldpoints[1] = -1;
  Invalidate();
}

void TCribbageBoard::PegHole(TDC& dc, int player, int hole, PegType pegType) {
  TRect r1,r2;
  TBrush redBrush(TColor(255,0,0));
  TBrush blueBrush(TColor(0,0,255));
  TBrush brownBrush(TColor(128,128,0));

  hole++;
  r1 = TRect(holes[player][hole]+TPoint(1,2), holes[player][hole]+TPoint(6,5));
  r2 = TRect(holes[player][hole]+TPoint(2,1), holes[player][hole]+TPoint(5,6));

  switch (pegType) {
    case ptPlayer0:
      dc.FillRect(r1, redBrush);
      dc.FillRect(r2, redBrush);
      break;
    case ptPlayer1:
      dc.FillRect(r1, blueBrush);
      dc.FillRect(r2, blueBrush);
      break;
    case ptEmpty: {
      TBitmap bitmap(_hInstance, EMPTY_HOLE);
      TMemoryDC memDC(dc);
      memDC.SelectObject(bitmap);
      dc.BitBlt(holes[player][hole].x, holes[player][hole].y,
                 7, 7, memDC, 0, 0, SRCCOPY);
      }
      break;
  }
}

BOOL TCribbageBoard::AddToScore(int player, int amount) {

  if (amount==0)
    return false;

  if (points[player]==121)
    return true;

  TClientDC dc(HWindow);
  char temp[10];

  PegHole(dc, player, oldpoints[player], ptEmpty);
  oldpoints[player]=points[player];
  points[player]+=amount;
  if (points[player]>121) points[player]=121;
  PegHole(dc, player, points[player], player);
  wsprintf(temp, "%d", points[player]);
  dc.SetBkColor(TColor(128, 128, 0));
  dc.TextOut(150, 350+20*player, temp);

  return (points[player]==121);
}

void TCribbageBoard::SetPlayerName(int player, const char *name) {
  assert((player==0) || (player==1));
  strncpy(playerName[player], name, 10);
  playerName[player][10]=0;

  // if the player name is changed after the board is displayed,
  // we have to repaint the name
  //
  if (HWindow) {
    TClientDC dc(HWindow);
    dc.SetTextColor(TColor(0, 0, 0));
    dc.SetBkColor(TColor(128, 128, 0));
    dc.TextOut(25, 350+player*20, playerName[player]);
  }
}

const char *TCribbageBoard::GetPlayerName(int player) {
  assert((player==0) || (player==1));
  return playerName[player];
}

void TCribbageBoard::Paint(TDC& dc, bool, TRect&) {
  char temp[10];
  TBitmap bitmap(_hInstance, PEGBOARD);
  TMemoryDC memDC(dc);
  memDC.SelectObject(bitmap);
  dc.BitBlt(0, 0, 200, 400, memDC, 0, 0, SRCCOPY);
  dc.SetTextColor(TColor(0, 0, 0));
  dc.SetBkColor(TColor(128, 128, 0));
  dc.TextOut(25, 350, playerName[0]);
  dc.TextOut(25, 370, playerName[1]);
  wsprintf(temp,"%d",points[0]);
  dc.TextOut(150, 350, temp);
  wsprintf(temp,"%d",points[1]);
  dc.TextOut(150, 370, temp);

  for (int i=0;i<2;i++) {
    PegHole(dc, i, 0, ptEmpty);
    PegHole(dc, i, -1, ptEmpty);
    PegHole(dc, i, points[i], i);
    PegHole(dc, i, oldpoints[i], i);
  }
}

