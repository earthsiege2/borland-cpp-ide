//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#ifndef BOARD_H
#define BOARD_H

#include <owl/window.h>
#include <winsys/color.h>
#include <assert.h>

//
// TCribbageBoard -- the cribbage board, used to keep score
//
class TCribbageBoard : public TWindow {
  public:
    TCribbageBoard(TWindow* parent, int x, int y);
    void SetupWindow() {
      TWindow::SetupWindow();
      SetBkgndColor(TColor(128,128,0));
    }
    int GetScore(int player) {
      assert(player==1 || player==0);
      return points[player];
    }
    void Reset();

    enum PegType {
      ptPlayer0 = 0,
      ptPlayer1 = 1,
      ptEmpty   = 2
    };
    void PegHole(TDC& dc, int player, int hole, PegType pegType);
    void PegHole(TDC& dc, int player, int hole, int pegType) {
      PegHole(dc, player, hole, (PegType)pegType);
    }
    BOOL AddToScore(int player, int amount);
    void SetPlayerName(int player, const char* name);
    const char *GetPlayerName(int player);
    void Paint(TDC& dc, bool erase, TRect& rect);

  private:
    char   playerName[2][11];
    int    points[2];
    int    oldpoints[2];
    TPoint holes[2][123];
};

#endif // BOARD_H
