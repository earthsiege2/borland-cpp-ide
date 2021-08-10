//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#ifndef CRIBBAGE_H
#define CRIBBAGE_H

#include <owl/window.h>
#include "carddisp.h"
#include "board.h"
#include "dialogs.h"

const int DETAIL_MAXCOUNT = 20;
const int DETAIL_MAXLEN = 128;

//
// TGameWindow -- This class defines all the logic which controls the
// game.
//
class TGameWindow : public TWindow {
  public:
    enum TGameState {
      gsNewGame,       // waiting for new game command

      gsDeal,          // waiting for user to press the deal button

      gsDiscard,       // waiting for user to discard 2 cards

      gsCutAfterDeal,  // waiting for user to cut the deck, to show the fifth
                       // card

      gsPegging,       // waiting for user to play a card, or
                       // click the 'go' button

      gsPeggingFinish, // same as gsPegging, but the computer
                       // is out of cards

      gsPeggingGo,     // computer has said 'go' to player,
                       // waiting for player to hit 31

      gsGameOver       // somebody reached 121 points and won
    };

    TGameWindow();
   ~TGameWindow();

    void SetupWindow();

    BOOL GameOver();
    int  FaceValue(int rank) {
      return (rank>10) ? 10 : rank;   // return the vace value of the card
    }
    int  RunSize(int *ranks, int count);
    int  ComputeHandPoints(TCardGroup* cards, TCard* extraCard, BOOL crib);
    int  ComputePegPoints(int cardPlayer, BOOL goInEffect);
    void ResetPegCardDisplay();
    void ReclaimPegCards();
    void PegCard(TCard* card, int player);
    void ScoreComputerPegPoints();
    BOOL ComputerPlayPegCard(BOOL goInEffect);
    void TurnOverPegCards();
    int  PlayableCards(TCardGroup* cards, BOOL *playable = 0);
    void SetState(TGameState newState);
    void Deal(BOOL prompt);
    void ShowPoints();
    void NewGame();
    void DealButton();
    void FixDeck();
    void SaveGame() {}
    void Exit() {
      CloseWindow();
    }
    void SaveGameEnabler(TCommandEnabler& tce) {
      tce.Enable(state!=gsNewGame);
    }
    void AboutBox() {
      TDialog(this, ABOUT_DIALOG).Execute();
    }
    void LoadGame() {}
    void Paint(TDC& dc, bool erase, TRect& rect);

    LRESULT CardSelected(WPARAM wparam, LPARAM lparam);

    int  PegCardsSum();
    bool CanClose();
    void GoButton();
    void DoneButton();
    void ComputerDiscard(int dealer);
    void ComputerPlayCard(BOOL go = false);
    void CountPoints(TCardGroup* cards);

    static TPoint handCardPos[6],cribCardPos[4],pegCardPos[8],topCardPos[1];

    TCardDisplay   *player[2],           // the two hands
                   *crib,                // the crib
                   *pegCards,            // where the cards are played
                   *topCard;             // top card on the deck

    TCribbageBoard *board;               // the score board

    TButton        *deal, *go, *done;    // buttons used during game play

    TStatic        *instructions;        // a window to display help in

    TGameState   state;                  // current state of the game
    uint         dealer;                 // who dealt the current hand

    TDeck    deck;                       // 52 cards
    int      currentCribPos;
    int      cardBackStyle;
    int      pegCardOwner[8];            // keeps track of who owns each card
                                         // that is played during pegging

    char *detail[DETAIL_MAXCOUNT];  // used for displaying individual point counts
    int  detailCount;

  DECLARE_RESPONSE_TABLE(TGameWindow);
};

#endif // CRIBBAGE_H
