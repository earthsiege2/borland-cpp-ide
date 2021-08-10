//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/window.h>
#include <owl/inputdia.h>

#include "cribbage.h"       // declaration of TGameWindow
#include "board.h"          // TCribbageBoard
#include "cards.h"          // TCard, TCardGroup, TDeck
#include "carddisp.h"       // TCardDisplay
#include "dialogs.h"        // TCutDeckDialog, TCutResultDialog,
                            // TShowPointsDialog, TQuickPointsDialog
                            // TGoDialog

#include "cribbage.rh"

const char IniFilename[] = "CRIBBAGE.INI";
const int NAME_LEN = 21;

char playerName[NAME_LEN];

// the following arrays hold the card positions for the various
// card displays used in the game

TPoint TGameWindow::handCardPos[6] =
           { TPoint(20,20), TPoint(35,20), TPoint(50,20),
             TPoint(65,20), TPoint(80,20), TPoint(95,20) };

TPoint TGameWindow::cribCardPos[4] =
           { TPoint(20,20), TPoint(35,20),
             TPoint(50,20), TPoint(65,20) };

TPoint TGameWindow::pegCardPos[8] =
           { TPoint(20,0), TPoint(35,0), TPoint(50,0), TPoint(65,0),
             TPoint(80,0), TPoint(95,0), TPoint(110,0), TPoint(125,0) };

TPoint TGameWindow::topCardPos[1] = { TPoint(0,0) };

DEFINE_RESPONSE_TABLE1(TGameWindow, TWindow)
  EV_COMMAND(CM_GAME_NEW, NewGame),
  EV_COMMAND(CM_GAME_EXIT, Exit),
  EV_COMMAND(CM_HELP_ABOUT, AboutBox),
  EV_MESSAGE(WM_CARD_SELECTED, CardSelected),
  EV_COMMAND(CM_GO_BUTTON, GoButton),
  EV_COMMAND(CM_DONE_BUTTON, DoneButton),
  EV_COMMAND(CM_DEAL_BUTTON, DealButton),
END_RESPONSE_TABLE;

// RunSize -- determines if the given cards form a run, and if they
// do, returns the size of the run.  This only detects single runs.
// this function is used to test subsets of cards from the hand.
//
int TGameWindow::RunSize(int *rank, int count) {
  int largestRun,i;
  int hittest[13];
  int currentValue,transitionCount;

  // must have at least 3 cards for a run

  if (count<3)
    return 0;

  // first, create a size 13 array (1 position for each card rank),
  // and fill it with zeros.  Then loop through all the cards, and
  // increment the position in the array for each card rank encountered.
  // then loop through the array and count how many transitions there
  // are.  If there are 2 or less transitions, then there is a run.
  // Also, if any value of the hittest array is >1, then there is no
  // run.
  //
  // here's a few examples:
  //
  //  cards                           hittest array
  // -----------------------------------------------------------
  //  3,4,5,5,9                      0 0 1 1 2 0 0 0 1 0 0 0 0
  //                                    ^   ^ ^     ^ ^
  //                                      5 transitions
  //
  //  4,5,6,7,8                      0 0 0 1 1 1 1 1 0 0 0 0 0
  //                                      ^         ^
  //                                      2 transitions
  //
  //  7,7,8,8                        0 0 0 0 0 0 2 2 0 0 0 0 0
  //                                            ^   ^
  //                                          2 transitions

  largestRun=0;

  for (i=0;i<13;i++)
    hittest[i]=0;

  // fill the hittest array

  for (i=0;i<count;i++)
    hittest[rank[i]-1]++;

  // count the # of transitions

  currentValue=0;
  transitionCount=0;
  for (i=0;i<13;i++) {
    if (hittest[i]!=currentValue) {
      transitionCount++;
      currentValue=hittest[i];

      // if the value in the hittest array is >1, then there cannot
      // be a run, so force the transitionCount value high enough
      // that we don't count a run.

      if (currentValue>1)
        transitionCount=5;
    }
  }
  if (transitionCount<=2)
    largestRun = count;

  assert((largestRun==0) || (largestRun>=3));

  return largestRun;
}

// ComputeHandPoints -- computes the points in a hand (either a normal
// hand or the crib).  It returns the points counted, and also computes
// a detailed list of the points counted
//
int TGameWindow::ComputeHandPoints(TCardGroup* cards, TCard* extraCard,
                                    BOOL crib) {


  int rank[5];         // rank of the cards (1-13)
  int faceValue[5];    // face value of cards (1-10) (10,J,Q,K all = 10)
  int suit[5];         // suit of each card
  int runrank[5],
      runcardcount,
      runs[6];         // used to count 3,4,5 card runs

  int i,j,fifteenCount,pairCount,runSize,size,
      runCount,sum,temp,flushSize,matchingJack,total,largestRun;

  char tempstr[20];

  // initialize the faceValue, rank, and suit arrays

  for (i=0;i<4;i++) {
    rank[i]=(*cards)[i].rank;
    faceValue[i]=FaceValue(rank[i]);
    suit[i] = (*cards)[i].suit;
  }

  rank[4] = extraCard->rank;
  faceValue[4]=FaceValue(rank[4]);
  suit[4] = extraCard->suit;

  flushSize=0;
  fifteenCount=0;
  pairCount=0;
  matchingJack=0;
  runSize=0;
  runCount=0;
  runs[3]=0;
  runs[4]=0;
  runs[5]=0;

  detailCount=0;

  // check for all combinations of cards that add to 15

  for (i=1;i<32;i++) {
    sum=0;
    temp=i;

    detail[detailCount][0]=0;

    // loop through all bits of i
    for (j=0;j<5;j++) {

      // if the bit is set, add that card into the sum.

      if (temp&1) {
        strcat(detail[detailCount],TCard::Stringify(rank[j],suit[j]));
        strcat(detail[detailCount]," ");
        sum=sum+faceValue[j];
      }

      // get next bit
      temp=temp/2;
    }

    if (sum==15) {
      fifteenCount++;
      strcat(detail[detailCount++],"\t(fifteen)\t2 pts");
    }
  }

  // first find out what the largest run size is

  largestRun=0;
  for (i=1;i<32;i++) {
    temp=i;
    runcardcount=0;
    for (j=0;j<5;j++) {
      if (temp&1)
        runrank[runcardcount++]=rank[j];
      temp=temp/2;
    }

    size = RunSize(runrank, runcardcount);
    if (size>largestRun)
      largestRun=size;
  }

  // now go back and re-check for runs, but ignore anything
  // smaller than the largest run found above

  if (largestRun>=3) {
    for (i=1;i<32;i++) {
      temp=i;
      runcardcount=0;

      detail[detailCount][0]=0;
      // loop through all bits of i
      for (j=0;j<5;j++) {
        if (temp&1) {
          runrank[runcardcount++]=rank[j];
          strcat(detail[detailCount],TCard::Stringify(rank[j],suit[j]));
          strcat(detail[detailCount]," ");
        }
        temp=temp/2;
      }

      size = RunSize(runrank, runcardcount);
      if (size==largestRun) {
        runCount++;
        wsprintf(tempstr,"\t(%d-card run)\t%d pts",size,size);
        strcat(detail[detailCount++],tempstr);
      }
    }
    // only count the largest run.  ie, a 4-card run doesn't
    // also count as 2 3-card runs.

    runSize=largestRun;
  }

  // count pairs.  Note that this loop skips the condition where
  // i=j, and only counts each pair once (ie, it doesn't look at
  // the combination i=2,j=3 and i=3,j=2, since that would count
  // the same combination twice)

  for (i=0;i<5;i++)
    for (j=i+1;j<5;j++)
      if (rank[i]==rank[j]) {
        pairCount++;
        strcpy(detail[detailCount],TCard::Stringify(rank[i],suit[i]));
        strcat(detail[detailCount]," ");
        strcat(detail[detailCount],TCard::Stringify(rank[j],suit[j]));
        strcat(detail[detailCount++],"\t(pair)\t2 pts");
      }

  // check for flushes

  if ((suit[0]==suit[1]) &&
      (suit[1]==suit[2]) &&
      (suit[2]==suit[3])) {
    flushSize=4;
    if ((!crib) && (suit[3]==suit[4]))
      flushSize++;
  }

  if (flushSize) {
    detail[detailCount][0]=0;
    for (i=0;i<flushSize;i++)
      if (suit[i]==suit[0]) {
        strcat(detail[detailCount],TCard::Stringify(rank[i],suit[i]));
        strcat(detail[detailCount]," ");
      }
    wsprintf(tempstr,"\t(%d-card flush)\t%d pts",flushSize,flushSize);
    strcat(detail[detailCount++],tempstr);
  }

  // check for nobs

  for (i=0;i<4;i++)
    if ((rank[i]==11) &&
        (suit[i]==suit[4])) {
      matchingJack=1;
      wsprintf(detail[detailCount++],"%s%s\t(nobs)\t1 pt",
                TCard::Stringify(rank[i], suit[i]));
    }


  total = fifteenCount*2 +     // 2 points for each 15
          pairCount*2 +        // 2 points for each pair
          runSize*runCount +   // N points for each N-card run
          flushSize +          // 4 or 5 points for a 4 or 5 card flush
          matchingJack;        // 1 point for a jack of the same suit as

  strcpy(detail[detailCount++],"----------------------------------------------------");
  wsprintf(detail[detailCount++],"\tTotal:\t%d",total);

  return total;
}

BOOL TGameWindow::GameOver() {
  if ((board->GetScore(0)==121) ||
      (board->GetScore(1)==121))
    return true;
  return false;
}

// ShowPoints -- after all cards have been played, this function
// is called to split the cards back into their respective hands,
// and count the points for each hand.  The hands are counted in
// the following order:  nondealer, dealer, crib.
//
void TGameWindow::ShowPoints() {
  int  points,actualPoints;

  // split the cards back into two hands

  ReclaimPegCards();
  instructions->SetText("");

  for (int i=0;i<crib->GetCount();i++)
    crib->FaceUp(i, true);

  // NOTE: the AddToScore function returns true if players score
  // exceeds 121.  Any time we call AddToScore, if the return value
  // is true, the game is over so we simply return from this function.

  if (dealer==1) {

    // player dealt, let computer show points first, then
    // let the player count their hand, and then the crib.

    points = ComputeHandPoints(player[0], &((*topCard)[0]), false);
    TShowPointsDialog(this, TShowPointsDialog::mtHand,
                       points, 0, detail, detailCount).Execute();
    if (board->AddToScore(0, points)) return;

    actualPoints = ComputeHandPoints(player[1], &((*topCard)[0]), false);
    points = TQuickPointsDialog(this,
                                "Enter the points you count in your hand",
                               false, actualPoints).Execute();
    if (board->AddToScore(1, points)) return;
    if (points<actualPoints) {
      TShowPointsDialog(this, TShowPointsDialog::mtMissed,
                         points, actualPoints-points, detail, detailCount).Execute();
      if (board->AddToScore(0, actualPoints-points)) return;
    }

    actualPoints = ComputeHandPoints(crib, &((*topCard)[0]), true);
    points = TQuickPointsDialog(this,
                                 "Enter the points you count in the crib",
                                 false, actualPoints).Execute();
    if (board->AddToScore(1, points)) return;
    if (points<actualPoints) {
      TShowPointsDialog(this, TShowPointsDialog::mtMissed,
                         points, actualPoints-points, detail, detailCount).Execute();
      if (board->AddToScore(0, actualPoints-points)) return;
    }

  } else {

    // computer dealt, let player count their hand first, then
    // count computers hand and crib.

    actualPoints = ComputeHandPoints(player[1], &((*topCard)[0]), false);
    points = TQuickPointsDialog(this,
                                 "Enter the points you count in your hand",
                                 false, actualPoints).Execute();
    if (board->AddToScore(1, points)) return;
    if (points<actualPoints) {
      TShowPointsDialog(this, TShowPointsDialog::mtMissed,
                         points, actualPoints-points, detail, detailCount).Execute();
      if (board->AddToScore(0, actualPoints-points)) return;
    }

    points = ComputeHandPoints(player[0], &((*topCard)[0]), false);
    TShowPointsDialog(this, TShowPointsDialog::mtHand,
                       points, 0, detail, detailCount).Execute();
    if (board->AddToScore(0, points)) return;

    points = ComputeHandPoints(crib, &((*topCard)[0]), true);
    TShowPointsDialog(this, TShowPointsDialog::mtCrib,
                       points, 0, detail, detailCount).Execute();
    if (board->AddToScore(0, points)) return;
  }
}

// ResetPegCardDisplay -- blanks out the peg card count, and resets
// the array which keeps track of the peg cards owner
//
void TGameWindow::ResetPegCardDisplay() {
  int i;

  pegCards->SetLabel("");
  for (i=0;i<8;i++)
    pegCardOwner[i]=-1;
}

// ReclaimPegCards -- move the cards from the pegdisplay back into
// the computer and player hands.  The pegCardOwner array keeps track
// of which hands the cards came from.
//
void TGameWindow::ReclaimPegCards() {
  int i;
  for (i=0;i<8;i++)
    player[pegCardOwner[i]]->Insert(pegCards->Remove(), true);
  ResetPegCardDisplay();
}


void TGameWindow::SetState(TGameState newState)
{
  state = newState;

  go->ShowWindow(SW_HIDE);
  done->ShowWindow(SW_HIDE);
  deal->ShowWindow(SW_HIDE);

  switch (newState) {
    case gsNewGame:
      instructions->SetText("Select 'Game | New' to start a new game.");
      break;
    case gsDeal:
      instructions->SetText("Press the 'deal' button to deal the cards.");
      deal->ShowWindow(SW_SHOW);
      break;
    case gsDiscard:
      instructions->SetText("Discard 2 cards into the crib.");
      done->ShowWindow(SW_SHOW);
      break;
    case gsPegging:
      instructions->SetText("Play a card.  The total of the face values "
                            "may not exceed 31.  If you cannot play a card, "
                            "click the 'go' button.");
      go->ShowWindow(SW_SHOW);
      break;
    case gsPeggingFinish:
      MessageBox("Error!","Error!",MB_OK);
//      instructions->SetText("Play a card.  The total of the face values "
//                            "may not exceed 31.  If you cannot play a card, "
//                            "take your points and continue until all your "
//                            "cards have been played.");
//      take1->ShowWindow(SW_SHOW);
//      take2->ShowWindow(SW_SHOW);
      break;
    case gsPeggingGo:
      instructions->SetText("Play a card.  The total of the face values "
                            "may not exceed 31.  If you cannot play a card, "
                            "click '1 point' or '2 points' to peg your "
                            "'go' points.");
//      take1->ShowWindow(SW_SHOW);
//      take2->ShowWindow(SW_SHOW);
      break;
    case gsGameOver:
      if (board->GetScore(0)==121)
        MessageBox("The computer wins!","Cribbage",MB_OK);
      if (board->GetScore(1)==121)
        MessageBox("You win!!!","Cribbage",MB_OK);
      SetState(gsNewGame);
      break;
  }
}

// Deal -- deals the cards.  If it's the computers turn to deal, the
// cards are dealt.  If it's the players turn, the game state is set
// to gsDeal, which waits for the player to click the 'deal' button
//
void TGameWindow::Deal(BOOL prompt) {
  int i,j;

  FixDeck();
  deck.Shuffle(5+random(5));
  topCard->Insert(deck.DealCard(), false);

  if (dealer==0) {              // computer deals

    if (prompt)
      MessageBox("Computers turn to deal.","Cribbage",MB_OK);

    crib->MoveWindow(200, 0, 185, 135, true);
    instructions->MoveWindow(200, 280, 185, 135, true);

    for (i=0;i<6;i++)
      for (j=1;j>=0;j--) {
        player[j]->Insert(topCard->Remove(), j?true:false);
        topCard->Insert(deck.DealCard(), false);
      }
    ComputerDiscard(dealer);
    SetState(gsDiscard);
  } else {                      // player deals
    crib->MoveWindow(200, 280, 185, 135, true);
    instructions->MoveWindow(200, 0, 185, 135, true);
    SetState(gsDeal);
  }
}

// CountPoints -- asks the player to peg points for the card they
// just played.
//
void TGameWindow::CountPoints(TCardGroup*) {
  int actualPoints,points;

  // if only one card has been played, no points are
  // possible, so don't pop up the dialog in that case.

  if (pegCards->GetCount()>1) {
    actualPoints = ComputePegPoints(1, state==gsPeggingGo);
    if (actualPoints) {
      points = TQuickPointsDialog(this, "Peg points for card played.",
                                   true, actualPoints).Execute();
      if (board->AddToScore(1, points)) {
        SetState(gsGameOver);
        return;
      }
      if (points<actualPoints) {
        TShowPointsDialog(this, TShowPointsDialog::mtMissed,
                           points, actualPoints-points,
                           detail, detailCount).Execute();
        if (board->AddToScore(0, actualPoints-points))
          SetState(gsGameOver);
      }
    }
  }
}

// PegCardsSum -- computes the current sum of the face values of
// all the played cards
//
int TGameWindow::PegCardsSum() {
  int i,temp,sum=0;

  for (i=0;i<pegCards->GetCount();i++) {
    if ((*pegCards)[i].faceUp)
      temp = FaceValue((*pegCards)[i].rank);
    else
      temp=0;
    sum+=temp;
  }
  return sum;
}

// CanClose -- called whenever the app is trying to quit.  If a
// game is in progress, it asks the player if they want to abandon it.
//
bool TGameWindow::CanClose() {

  // if a game is in progess, ask the user before closing

  if (state!=gsNewGame)
    if (MessageBox("Abandon current game?", "Warning", MB_YESNO)==IDYES)
      return true;
    else
      return false;

  // otherwise, it's ok to close

  return true;
}

// DoneButton -- handler for the 'done' button.  The 'done' button is
// displayed when the game is waiting for the user to discard 2 cards
// into the crib.
//
void TGameWindow::DoneButton() {

  // the 'done' button should not be visible unless we're in the
  // gsDiscard state, so if this assertion fails, there is a
  // problem somewhere else in the code which caused the button
  // to be visible at the wrong time.

  assert(state==gsDiscard);

  // user must have exactly 4 cards left in their hand

  if (player[1]->GetCount()!=4) {
    MessageBox("You must discard 2 cards into the crib.", "Error", MB_OK);
  } else {

    // turn all the cards in the crib face-down

    for (int i=0;i<4;i++)
      crib->FaceUp(i, false);

    // the person who didn't deal gets to cut the cards.  the
    // dealer then turns the card over.  If it is the jack,
    // the dealer may take 2 points.

    topCard->FaceUp(0, true);

    if ((*topCard)[0].rank==11)
      if (dealer==0) {
        MessageBox("Computer takes 2 points for heels.","Cribbage",MB_OK);
        board->AddToScore(0, 2);
      }
      else {
        MessageBox("Player gets 2 points for heels.","Cribbage",MB_OK);
        board->AddToScore(1, 2);
      }

    // switch to the game-play state

    SetState(gsPegging);

    // if we dealt, the computer gets to play the first card.

    if (dealer==1)
      ComputerPlayCard();
  }
}

// NewGame -- reset the game display and prepare for a new game to start
//
void TGameWindow::NewGame() {

  // first check if player wants to abandon current game

  if (state!=gsNewGame) {
    int result = MessageBox("Abandon Current Game?", "Warning", MB_YESNO);
    if (result==IDNO) return;
  }

  // reset the scoreboard

  board->Reset();

  // erase the pegcard total, and reset the pegCardOwner array

  ResetPegCardDisplay();

  // get all the cards back into the deck

  FixDeck();

  // get the players name, display it on the score board, and
  // on the players card display

  int result = TInputDialog(this, "Cribbage",
                             "Enter your name:", playerName, NAME_LEN).Execute();
  if ((result!=IDOK) ||
       (playerName[0]==0))
    strcpy(playerName,"Anonymous");
  board->SetPlayerName(1,playerName);
  player[1]->SetLabel(playerName);

  // ask the player to cut a card, to see who deals first

  int playerCard=0,
      computerCard=0;

  while (deck[playerCard].rank==deck[computerCard].rank) {

    // get players cut

    playerCard = TCutDeckDialog(this, deck).Execute();

    // get a random card for the computer, but don't let
    // the computer choose the same card the player did

    do {
      computerCard = random(52);
    } while (computerCard==playerCard);

    // show the results

    TCutResultDialog(this, deck[playerCard], deck[computerCard]).Execute();
  }

  if (deck[playerCard].rank<deck[computerCard].rank)
    dealer=1;
  else
    dealer=0;

  Deal(false);
}

// PegCard -- adds a card to the pegCards display
//
void TGameWindow::PegCard(TCard* card, int player) {
  int index;
  char temp[10];

  // insert the card, face up, and keep track of its index

  index = pegCards->Insert(card, true);

  // keep track of who owns it

  pegCardOwner[index] = player;

  // move the cards so they are staggered.  This is so the player can
  // tell the difference between its cards, and the computers cards

  pegCards->SetCardPosition(index, TPoint(pegCardPos[index].x, player?15:0));

  // figure the new sum, and update the display

  wsprintf(temp,"%d",PegCardsSum());
  pegCards->SetLabel(temp);
}

// ComputerDiscard -- figure out which 2 cards the computer will
// discard into the crib.  The logic for this should be different
// depending on whether the crib belongs to the computer, or
// the player
//
void TGameWindow::ComputerDiscard(int dealer)  {

  // currently, we just discard the first 2 cards in the hand.
  // not very intelligent, but easy to implement.  should be
  // changed later *BBK*

  switch (dealer) {
    case 0:  // computers crib
    case 1:  // players crib
      crib->Insert(player[0]->Remove(), false);
      crib->Insert(player[0]->Remove(), false);
      break;
  }
}

// DealButton -- handler for the 'deal' button.  When the game state is
// gsDeal, the 'deal' button is visible, and the game is waiting for
// the user to click it to deal.
//
void TGameWindow::DealButton() {

  // button should only be visible if we are in the gsDeal state,
  // and it's the players turn to deal

  assert((state==gsDeal) && (dealer==1));

  // deal the cards

  for (int i=0;i<6;i++)
    for (int j=0;j<2;j++) {
      player[j]->Insert(topCard->Remove(), j?true:false);
      topCard->Insert(deck.DealCard(), false);
    }

  // let computer discard 2 cards into the crib

  ComputerDiscard(dealer);

  // wait for user to discard 2 cards

  SetState(gsDiscard);
}

// CardSelected -- handler for the WM_CARD_SELECTED message, which is
// generated by the TCardDisplay class:
//
//   MSG    - WM_CARD_SELECTED
//   WPARAM - id of the card display control clicked on
//   LPARAM - index of the card selected
//
LRESULT TGameWindow::CardSelected(WPARAM wparam, LPARAM lparam) {
  int group = wparam;
  int index = (int)lparam;

  // depending on the game state, clicking on a card does different
  // things

  switch (state) {

    // in gsDiscard mode, the user can click on a card in their
    // hand to move it to the crib.  Clicking on a faceUp card
    // in the crib (one of their cards), will return it to the
    // players hand.  Clicking on any other cards produces a
    // 'no cheating' message

    case gsDiscard:
      if (group==1) { // 1 is the ID of the players cardDisplay control

        // clicked on players card

        if (player[1]->GetCount()>4)
          crib->Insert(player[1]->Remove(index), true);
        else
          MessageBox("You can only discard two cards.  Click on\n"
                      "a card in the crib to return it to your hand.",
                      "Cribbage", MB_OK);
      } else

        // clicked on crib card.  make sure it is one of the players
        // cards (player cards are face up, computer cards are face
        // down), and then move it back to the players hand

        if (group==2) {  // crib
          if ((*crib)[index].faceUp)
            player[1]->Insert(crib->Remove(index), true);
          else
            MessageBox("That's not your card!", "No Cheating!", MB_OK);
        }
      break;

    // during the game play

    case gsPegging:
      if (group==1) {

        // players card was selected

        int currentSum,faceValue;
        currentSum=PegCardsSum();

        // don't allow the card to be played if it would cause the
        // sum of the face values to exceed 31

        faceValue = FaceValue((*player[1])[index].rank);

        if (currentSum+faceValue>31) {
          MessageBox("Playing that card would exceed 31.", "Cribbage", MB_OK);
          return true;
        }

        // insert the card into the display

        PegCard(player[1]->Remove(index), 1);

        // allow the player to count points

        CountPoints(pegCards);

        // if all cards have been played

        if (pegCards->GetCount()==8) {
          ShowPoints();                // count hands
          if (GameOver()) {
            SetState(gsGameOver);
            return true;
          }
          dealer = (dealer+1)%2;       // next dealer
          Deal(true);                // start new hand

        } else {                       // otherwise
          if (PegCardsSum()==31)
            TurnOverPegCards();
          ComputerPlayCard();          // let the computer play a card
        }
      }
      break;
    case gsPeggingGo:  // computer has said 'go'
      if (group==1) {

        // don't allow the card to be played if it would cause the
        // sum of the face values to exceed 31

        int faceValue = FaceValue((*player[1])[index].rank);

        if ((PegCardsSum()+faceValue)>31) {
          MessageBox("Playing that card would exceed 31.", "Cribbage", MB_OK);
          return true;
        }

        // insert the card into the display

        PegCard(player[1]->Remove(index), 1);

        // allow the player to count points

        CountPoints(pegCards);

        // if the sum is 31, or the player has no other playable
        // cards, turn over the cards and continue by having the
        // computer play a card

        if ((PegCardsSum()==31) ||
             (PlayableCards(player[1])==-1)) {
          TurnOverPegCards();
          SetState(gsPegging);
          if (player[0]->GetCount()>0) {
            ComputerPlayCard();
            return true;
          }
        }

        if (pegCards->GetCount()==8) {
          ShowPoints();
          if (GameOver()) {
            SetState(gsGameOver);
            return true;
          }
          dealer=(dealer+1)%2;
          Deal(true);
        }
      }
      break;
  }
  return true;
}

// PlayableCards -- given a group of cards, determines which cards
// can be played without exceeding 31.  The 'playable' parameter is
// filled with values that state whether each card is playable or
// not.  The function also returns the index of the first playable
// card, or -1 if none are playable.
//
// note: the parameter 'playable' can be 0, in which case the
// function only computes the first playable card.
//
int TGameWindow::PlayableCards(TCardGroup* cards, BOOL *playable) {
  int i,first,pegSum = PegCardsSum();

  first=-1;

  for (i=0;i<cards->GetCount();i++) {
    if (playable)
      playable[i]=false;
    if ((*cards)[i].rank+pegSum<=31) {
      if (playable)
        playable[i]=true;
      if (first==-1)
        first=i;
    }
  }
  return first;
}

void TGameWindow::TurnOverPegCards() {
  int i;
  for (i=0;i<pegCards->GetCount();i++)
    pegCards->FaceUp(i, false);
}

// ComputePegPoints -- compute the points generated by the last
// card played
//
int TGameWindow::ComputePegPoints(int cardPlayer, BOOL goInEffect) {
  int count,totalcount,total,largestRun,i,j,k;
  int currentValue,transitionCount,pairCount,firstFaceUp;
  int rank[8],hittest[13];
  char temp[30];

  total=0;
  detailCount=0;

  totalcount = pegCards->GetCount();

  // find the first face-up card

  firstFaceUp=0;
  while ((firstFaceUp<totalcount) && ((*pegCards)[firstFaceUp].faceUp==false))
    firstFaceUp++;

  // if the sum = 15, 2 points

  if (PegCardsSum()==15) {
    total+=2;
    detail[detailCount][0]=0;
    for (i=firstFaceUp;i<pegCards->GetCount();i++)
      strcat(detail[detailCount],(*pegCards)[i].Stringify());
    strcat(detail[detailCount++],"\t(15)\t2 pts");
  }

  // if sum == 31, 2 points (if no go is in effect)

  if ((PegCardsSum()==31)&&(!goInEffect)) {
    total+=2;
    detail[detailCount][0]=0;
    for (i=firstFaceUp;i<pegCards->GetCount();i++)
      strcat(detail[detailCount],(*pegCards)[i].Stringify());
    strcat(detail[detailCount++],"\t(31)\t2 pts");
  }

  // get the ranks of all the face-up cards

  count=0;
  i=firstFaceUp;
  while (i<totalcount)
    rank[count++]=(*pegCards)[i++].rank;

  // if there are 3 or more cards, check for runs

  largestRun=0;
  if (count>=3) {
    for (i=0;i<(count-3+1);i++) {
      for (k=0;k<13;k++)
        hittest[k]=0;
      for (j=i;j<count;j++)
        hittest[rank[j]-1]++;

      currentValue=0;
      transitionCount=0;
      for (j=0;j<13;j++) {
        if (hittest[j]!=currentValue) {
          transitionCount++;
          currentValue=hittest[j];
          if (currentValue>1)
            transitionCount=10;
        }
      }
      if ((transitionCount<=2) && (largestRun==0))
        largestRun = (count-i);
    }
  }

  total+=largestRun;
  if (largestRun) {
    detail[detailCount][0]=0;
    for (i=totalcount-largestRun;i<totalcount;i++)
      strcat(detail[detailCount],(*pegCards)[i].Stringify());
    wsprintf(temp,"\t%d-card run\t%d pts",largestRun,largestRun);
    strcat(detail[detailCount++],temp);
  }

  // if there are more than 2 cards, check for pairs

  if (count>=2) {
    currentValue=rank[count-1];
    pairCount=0;
    i=count-2;
    while ((i>=0)&&(rank[i]==currentValue)) {
      pairCount++;
      i--;
    }

    switch (pairCount) {
      case 1:
        detail[detailCount][0]=0;
        for (i=totalcount-1;i>=totalcount-2;i--)
          strcat(detail[detailCount],(*pegCards)[i].Stringify());
        strcat(detail[detailCount++],"\t1 pair\t2 pts");
        total+=2;
        break;
      case 2:
        detail[detailCount][0]=0;
        for (i=totalcount-1;i>=totalcount-3;i--)
          strcat(detail[detailCount],(*pegCards)[i].Stringify());
        strcat(detail[detailCount++],"\t3 pair\t6 pts");
        total+=6;
        break;
      case 3:
        detail[detailCount][0]=0;
        for (i=totalcount-1;i>=totalcount-4;i--)
          strcat(detail[detailCount],(*pegCards)[i].Stringify());
        strcat(detail[detailCount++],"\t6 pair\t12 pts");
        total+=12;
        break;
    }
  }

  // if all cards have been played, add 1 point for last card.

  if ((!goInEffect)&&(pegCards->GetCount()==8)) {
    total++;
    wsprintf(detail[detailCount++],"\tlast card\t1 pt");
  }

  // if a go is in effect, check to see if the player that just played
  // can play another card.  If not, then they can take a point for the
  // go

  if ((goInEffect) &&
       (PlayableCards(player[cardPlayer])==-1)) {
    if (PegCardsSum()==31) {
      total+=2;
      wsprintf(detail[detailCount++],"\tgo (31)\t2 pts");
    } else {
      total++;
      wsprintf(detail[detailCount++],"\tgo\t1 pt");
    }
  }

  return total;
}

void TGameWindow::ScoreComputerPegPoints() {
  int points = ComputePegPoints(0, false);

  if (points) {
    TShowPointsDialog(this, TShowPointsDialog::mtPegging,
                       points, 0, detail, detailCount).Execute();
    if (board->AddToScore(0, points))
      SetState(gsGameOver);
  }
}

// ComputerPlayPegCard -- select a single card to play.  If the parameter
// 'goInEffect' is true, and the computer cannot play a card, the computer
// will take 1 or 2 points (2 if the sum is equal to 31).
//
// if 'goInEffect' is true, the return value indicates whether the
// computer took points for the go.
//
// if 'goInEffect' is false, the return value indicates whether the
// computer played a card or not.
//
BOOL TGameWindow::ComputerPlayPegCard(BOOL goInEffect) {
  int playableCard;
  BOOL done;

  done=false;
  playableCard = PlayableCards(player[0], 0);

  if (playableCard>=0) {
    PegCard(player[0]->Remove(playableCard), 0);
    ScoreComputerPegPoints();
    if (PegCardsSum()==31)
      TurnOverPegCards();
    return true;
  }

  if (goInEffect) {
    done=true;
    if (PegCardsSum()==31) {
      MessageBox("Computer takes 2 points for 31.", "Cribbage", MB_OK);
      TurnOverPegCards();
      board->AddToScore(0, 2);
    }
    else {
      MessageBox("Computer takes 1 point.", "Cribbage", MB_OK);
      TurnOverPegCards();
      board->AddToScore(0, 1);
    }
  } // else done=false, which means the computer didn't play a card
  return done;
}

// ComputerPlayCard -- plays one or more cards from the computers hand,
// depending on several things:
//
//   - whether the player said 'go' (goInEffect parameter == true)
//   - whether the player has any cards left
//
void TGameWindow::ComputerPlayCard(BOOL goInEffect) {
  BOOL done;

  // if player has not said 'go', so just play one card

  if (!goInEffect) {

    // if computer doesn't have any cards, then just return

    if (player[0]->GetCount()==0)
      return;

    // have the computer play a card.  If it couldn't, then
    // the computer says 'go'.

    if (!ComputerPlayPegCard(goInEffect)) {
      int playableCard = PlayableCards(player[1], 0);

      // show a dialog that says 'go', and depending on whether
      // the player can play a card, either put a button that
      // says 'ok', or 'take 1 point'.

      TGoDialog(this, (playableCard!=-1)).Execute();

      // if the player has a playable card, switch back to
      // gsPeggingGo state

      if (playableCard!=-1)
        SetState(gsPeggingGo);
      else {

      // otherwise, since the computer said go, it's the computers
      // turn to play.

        board->AddToScore(1, 1);
        TurnOverPegCards();

        ComputerPlayCard();
      }
    }
  }

  // otherwise the player has said 'go', so keep playing cards until
  // you hit 31, or you run out of cards.

  else {

    // if the player is out of cards, keep playing until the
    // computer is out

    if (player[1]->GetCount()==0) {
      while (player[0]->GetCount()>0)
        ComputerPlayPegCard(goInEffect);
      ShowPoints();
      if (GameOver()) {
        SetState(gsGameOver);
        return;
      }
      dealer=(dealer+1)%2;
      Deal(true);
    }

    // otherwise, play until the computer hits 31, then return
    // to normal pegging

    else {
      done=false;
      while (!done)
        done = ComputerPlayPegCard(goInEffect);
      SetState(gsPegging);
    }
    return;
  }
}

void TGameWindow::GoButton() {
  int i,pegSum,temp;
  pegSum=0;
  for (i=0;i<pegCards->GetCount();i++) {
    if ((*pegCards)[i].faceUp)
      temp = (*pegCards)[i].rank;
    else temp=0;
    if (temp>9) temp=10;
    pegSum+=temp;
  }
  for (i=0;i<player[1]->GetCount();i++)
    if (player[1]->operator[](i).rank+pegSum<=31) {
      MessageBox("You must play a card if it is playable.",
                 "Cribbage",MB_OK);
      return;
    }
  ComputerPlayCard(true);
}

//
// FixDeck -- removes all the cards from the game board, and returns
// them to the deck
//
void TGameWindow::FixDeck()
{
  deck.Insert(player[0]);
  deck.Insert(player[1]);
  deck.Insert(pegCards);
  deck.Insert(crib);
  deck.Insert(topCard);
}

// TGameWindow -- constructor.  Builds the main game window,
// inserts all the card display controls, the game board, the buttons,
// and the instruction window.  Also, initializes the deck of cards.
//

TGameWindow::TGameWindow(): TWindow(0,0,0) {
  char encodedDeck[53];

  // allocate memory for the detailed point lists

  for (int i=0;i<DETAIL_MAXCOUNT;i++)
    detail[i] = new char[DETAIL_MAXLEN];

  // get the saved deck, and back style from the .INI file

  cardBackStyle = GetPrivateProfileInt("deck","backstyle",0,IniFilename);
  GetPrivateProfileString("game","playername","Anonymous",playerName,NAME_LEN,IniFilename);
  GetPrivateProfileString("deck","thecards","",encodedDeck,53,IniFilename);
  if (encodedDeck[0]!=0)
    if (!deck.DecodeDeck(encodedDeck)) {
      MessageBox("Saved deck is corrupted, using new deck.", "Warning", MB_OK);
      deck.Initialize(cardBackStyle);
    }
    else deck.ResetBackStyle(cardBackStyle);

  // set window size

  Attr.W = 605;
  Attr.H = 410;

  // create all the controls

  player[0] = new TCardDisplay(this, 0, 0, 0, 185, 135, 10,
                                6, handCardPos, true, "Computer", TPoint(20,2));

  player[1] = new TCardDisplay(this, 1, 0, 280, 185, 135, 10,
                                6, handCardPos, true, "Human", TPoint(20,2));

  crib = new TCardDisplay(this, 2, 200, 0, 185, 135, 10,
                           4, cribCardPos, true, "Crib", TPoint(140,60));

  pegCards = new TCardDisplay(this, 3, 5, 150, 200, 125, 0,
                               8, pegCardPos, false, "", TPoint(0,50));

  topCard = new TCardDisplay(this, 4, 305, 155, 71, 95, 0,
                              1, topCardPos);

  instructions = new TStatic(this, 6, "", 200, 280, 185, 135);

  board = new TCribbageBoard(this, 400, 5);
  board->SetPlayerName(0,"Computer");
  board->SetPlayerName(1,"Human");
  deal = new TButton(this, CM_DEAL_BUTTON, "Deal", 210, 195, 70, 30);
  go =   new TButton(this, CM_GO_BUTTON,   "Go",   210, 195, 70, 30);
  done = new TButton(this, CM_DONE_BUTTON, "Done", 210, 195, 70, 30);

  // initialize the game state, to wait for a new game to be started
  //
  SetState(gsNewGame);

  // set the window background to be green
  //
  SetBkgndColor(TColor(0, 128, 0));
}

//
// ~TGameWindow -- destructor.  Delete the brush we created, get all
// the cards back into the deck, and save the deck into the .INI file
//
TGameWindow::~TGameWindow()
{
  WritePrivateProfileString("game","playername",playerName,IniFilename);
  for (int i = 0; i < DETAIL_MAXCOUNT; i++)
    delete[] detail[i];

  FixDeck();
  WritePrivateProfileString("deck","thecards",deck.EncodeDeck(),IniFilename);
}

//
// SetupWindow
//
void TGameWindow::SetupWindow()
{
  try {

    TWindow::SetupWindow();
  }
  catch (TXOwl msg) {
    MessageBox(msg.why().c_str(), "msg");
  }

  // set the intial state, to wait for a new game
  //
  SetState(gsNewGame);

  // demo code
  //  TCard *temp = deck.DealCard();
  //  topCard->Insert(temp, true);

  // Actual game code
  //
  topCard->Insert(deck.DealCard(), false);
}

// Paint -- paints the game board.  Most of the painting is done by
// the child windows, but we have a single bitmap (the deck of cards)
// which must be drawn.
//
void TGameWindow::Paint(TDC& dc, bool, TRect&) {
  TBitmap deck(_hInstance, DECK);
  TMemoryDC memDC(dc);
  memDC.SelectObject(deck);
  dc.BitBlt(290, 154, 88, 112, memDC, 0, 0, SRCCOPY);
}

// TCribbageApp -- the main application.  Just the basics here, setup
// a frame window (without a sizeable border).  Assign our menu and
// icon to it.
//
class TCribbageApp: public TApplication {
  public:
    TCribbageApp(): TApplication() {
      randomize();
      EnableCtl3d();
    }
    void InitMainWindow() {
      TFrameWindow *fw;
      int          width,height;

      // get the current video resolution
      //
      width = TScreenDC().GetDeviceCaps(HORZRES);
      height = TScreenDC().GetDeviceCaps(VERTRES);

      fw = new TFrameWindow(0, "Turbo Cribbage", new TGameWindow, TRUE);
      fw->Attr.Style = WS_OVERLAPPED | WS_CAPTION |
                       WS_SYSMENU | WS_MINIMIZEBOX;

      // center the window on the screen.  since these calculations
      // are based on the client window size, the window won't be
      // entirely centered, but it's close enough.
      //
      fw->Attr.X = (width-605)/2;
      fw->Attr.Y = (height-410)/2-20;

      // assign the menu and icon to our framewindow
      //
      fw->AssignMenu(MENU_1);
      fw->SetIcon(this, ICON_1);

      SetMainWindow(fw);
    }
};

int OwlMain(int, char *[]) {
  TBIVbxLibrary vbxLib;           // necessary for VBX controls to work
  return TCribbageApp().Run();    // play cribbage!
}
