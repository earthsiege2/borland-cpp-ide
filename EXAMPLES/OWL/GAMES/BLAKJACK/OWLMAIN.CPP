//-----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1995 by Borland International
// Owlmain.cpp contains the GUI interface for the blackjack game.
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include "blakjack.h"
#include <owl\point.h>
#include <owl\module.h>

#include "mhcd2001.h"
#include "owlmain.h"

const char AppName[] = "Blackjack";
const int  TBlackjack::TextLen = 5; // text length.


DEFINE_RESPONSE_TABLE1(TBlackjack, TDialog)
  EV_COMMAND  (ID_STAND_BTN,    IdStandBtn)   ,
  EV_COMMAND  (ID_HIT_BTN,      IdHitBtn)     ,
  EV_COMMAND  (ID_BANKROLL_BTN, IdBankrollBtn),
  EV_COMMAND  (ID_BET_BTN,      IdBetBtn)     ,
  EV_EN_CHANGE(ID_DISP_BANKROLL_INPUT, CheckBankRollInput),
  EV_EN_CHANGE(ID_DISP_BET_INPUT, CheckBetInput),
END_RESPONSE_TABLE;

TBlackjack::TBlackjack(TWindow *pWin)
  :TWindow(pWin),
	TDialog(pWin, AppName),
	Brush(TColor(0, 0, 0))
{

	strcpy(prevBet, "100");
	strcpy(prevBankroll, "1000");

	// You must new these card objects here.

	 VBXCardCount = 0;

	 // The order of "new"-ing the VBX cards is important, other wise
	 // the clipping order will become wrong. You do not want the first
	 // card which was dealt, to be sitting on top of all other cards, which
	 // were dealt later.

	 for(int l=51; l >= 0; l--)
	 {
			// All the card goes on the deck.
			// This is placed on the Dealer side.
			ppVBXCard[l] = new TVbxMhCardDeck(this,
																	 500-l,
																	 "VbControl",
																	 DEALER_VBX_CARD1_X,
																	 DEALER_VBX_CARD1_Y,
																	 VBX_CARD_WIDTH,
																	 VBX_CARD_LENGTH);
			ppVBXCard[l]->SetPropVisible(FALSE);
	 }

	 // Following objects are for the buttons.
	 pHitBtn      = new TButton(this, ID_HIT_BTN)       ;
	 pBankrollBtn = new TButton(this, ID_BANKROLL_BTN)  ;
	 pStandBtn    = new TButton(this, ID_STAND_BTN)     ;
	 pBetBtn      = new TButton(this, ID_BET_BTN)       ;

	 // The following objects are used to display scores
	 pIdDispBankroll1 = new TStatic(this, ID_DISP_BANKROLL1); // Bankroll
	 pIdDispBet       = new TStatic(this, ID_DISP_BET)      ; // Bet
	 pIdDispPPoints   = new TStatic(this, ID_DISP_PPOINTS)  ; // Player points.
	 pIdDispDPoints   = new TStatic(this, ID_DISP_DPOINTS)  ; // Dealer points.

	 // pointer to Edit field used to Input Bankroll amount.
	 pEInputBankRoll  = new TEdit(this, ID_DISP_BANKROLL_INPUT, TBlackjack::TextLen);
	 pEInputBet       = new TEdit(this, ID_DISP_BET_INPUT,      TBlackjack::TextLen);

	 // pointer to validater which validates Input Bankroll field.
	 pValidBankRoll   = new TFilterValidator("0-9");
	 pValidBet        = new TFilterValidator("0-9");

	 pEInputBankRoll->SetValidator(pValidBankRoll);
	 pEInputBet->SetValidator(pValidBet);

	 pEInputBankRoll->ShowWindow(SW_HIDE);
	 pEInputBet->ShowWindow(SW_HIDE);
}
TBlackjack::~TBlackjack()
{
	for (int l=0; l < 52; l++)
		delete ppVBXCard[l];

	delete pEInputBankRoll;
	delete pEInputBet;

	delete pValidBankRoll;
	delete pValidBet;

	delete pHitBtn;
	delete pBankrollBtn;
	delete pStandBtn;
	delete pBetBtn;

	delete pIdDispBankroll1;
	delete pIdDispBet;
	delete pIdDispPPoints;
	delete pIdDispDPoints;
}
void
TBlackjack::SetupWindow()
{
	TDialog::SetupWindow();
	// Center the dialog.
	int x = ::GetSystemMetrics(SM_CXSCREEN);
	int y = ::GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(
		  (x/2 - GetWindowRect().Width()/2),
		  (y < GetWindowRect().Height() ? 0: (y-GetWindowRect().Height())/2),
		  GetWindowRect().Width(), GetWindowRect().Height()
	  );

	// Enables the buttons in the dialog.
	InitBlackjack();
	DisplayCardOnTable();
}

BOOL
TBlackjack::EvInitDialog( HWND hWnd )
{
  BOOL rv = TDialog::EvInitDialog( hWnd );
  return rv;
}
void
TBlackjack::InitBlackjack()
{
	 pBankrollBtn->EnableWindow(TRUE);
	 pHitBtn->EnableWindow(FALSE);
	 pStandBtn->EnableWindow(FALSE);
	 pBetBtn->EnableWindow(FALSE);
}

void
TBlackjack::DisplayCardOnTable()
{
	 int k = 5;
	 // Display card on dealer's part of the table
	 for(int i=0; i < 9; i++,k++)
	 {
			ppVBXCard[i]->SetPropLeft(DEALER_VBX_CARD1_X+ (i*VBX_CARD_WIDTH*10));
			ppVBXCard[i]->SetPropTop (DEALER_VBX_CARD1_Y);

			ppVBXCard[i]->SetPropSuit(i%4);
			ppVBXCard[i]->SetPropValue(k%52);

			ppVBXCard[i]->SetPropVisible(TRUE);
	 }

	 // Display cards on player's part of the table
	 int p = 0;
	 for(k =13, i=10; i < 19; i++, k--, p++)
	 {
			ppVBXCard[i]->SetPropLeft(PLAYER_VBX_CARD1_X + p*VBX_CARD_WIDTH*10);
			ppVBXCard[i]->SetPropTop(PLAYER_VBX_CARD1_Y);
			if((13-k)%2)
			{
				ppVBXCard[i]->SetPropSuit((13-k)%4);
				ppVBXCard[i]->SetPropValue(k%52);
			}
			else
			{
				ppVBXCard[i]->SetPropCardBack(TVbxMhCardDeck::CardBack_10_Castle);
			}
			ppVBXCard[i]->SetPropVisible(TRUE);
	 }
}
void
TBlackjack::RemoveAllCardsOnTable()
{
	 for(int i=0; i < 52; i++)
	 {
			ppVBXCard[i]->SetPropVisible(FALSE);
	 }
}

//
// This is the callback function for the "BANKROLL" button.
//
void
TBlackjack::IdBankrollBtn()
{

	 BankRollEnteredFirstTime = 1;

	// Enable the input field for bankroll
	pEInputBankRoll->ShowWindow(SW_SHOWNORMAL);
	pEInputBankRoll->Clear();
	pEInputBankRoll->Insert(prevBankroll);
	pEInputBankRoll->SetSelection(0,4);

	pBetBtn->SetFocus();
	// Enables "return" key to work on the "Bet" button.
	SetDefaultId(pBetBtn->GetId());
}
//
// This is the callback function for the "BET"/"PLAY" button.
//
void
TBlackjack::IdBetBtn()
{
	char btnText[10];
	pBetBtn->GetWindowText(btnText,8); // It migth be "&Bet" or "Pla&y"
	if(!strcmp("&Bet", btnText))
	{
		ProcessBetButton();
	}
	else
	{
		ProcessPlayButton();
	}

}
// When "Bet" button is hit, this function is called.
// The "Bet" button can be clicked under 2 different conditions.
// 1) When a new bankroll amount is entered and
// 2) When a game is finished.
// For case one, the input bankroll amount must be more than 0, then only
// the bet button is activated.
// When the player hits the bet button he is allowed to enter a bet
// amount in the bet input field.
// "Bet" button is toggled to "Play" button.
// By default, the previous bet amount is displayed in the "Bet" input field.
// If the previous bet amount is more than the current bankroll amount,
// it is made equal to bankroll amount and displayed.
void
TBlackjack::ProcessBetButton()
{
char str[TBlackjack::TextLen+6];
int currBankroll;
int bankrollMoreThanZero = 0;

		if(BankRollEnteredFirstTime)
		{
			// When new bankroll is entered, it is read from
			// the input field.
			pEInputBankRoll->GetLine(str, TBlackjack::TextLen, 0);
			currBankroll = atoi(str);

			if(!currBankroll)
			{
				bankrollMoreThanZero = 0;
				currBankroll = 0;
				strcpy(str, "You are Bankrupt!");
				pIdDispBet->SetText(str);
			}
			else
			{
				bankrollMoreThanZero = 1;
				strcpy(prevBankroll, str);
				BankRollEnteredFirstTime = 0;
				(bj.getPlayer(1))->getPocket().setTotal(currBankroll);
			}
		}
		else
		{
			bankrollMoreThanZero = 1;
			currBankroll = (bj.getPlayer(1))->getPocket().getTotal();
			itoa(currBankroll, str, 10);
		}
		if(bankrollMoreThanZero)
		{
			// When bankroll amount is more than 0.
			// Make bet button to play button
			pBetBtn->SetWindowText("Pla&y");

			// Clear and activate the Input bet field
			pEInputBet->ShowWindow(SW_SHOWNORMAL);
			pEInputBet->Clear();

			// Set focus on play(bet) button
			pBetBtn->SetFocus();

			// Enables "return" key to work on the "Bet" button.
			SetDefaultId(pBetBtn->GetId());

			// Disable the Bankroll Edit field and Button.
			pEInputBankRoll->ShowWindow(SW_HIDE);
			::EnableWindow(GetDlgItem(ID_BANKROLL_BTN), FALSE);

			// Display the new/changed bankroll
			pIdDispBankroll1->SetText(str);

			// If bet is more than bankroll amount, make the bet
			// equal to bankroll, else use the prev bet amount.
			if(atoi(prevBet) > currBankroll)
			{
				char currBankrollStr[10];
				itoa(currBankroll, currBankrollStr, 10);
				pEInputBet->Insert(currBankrollStr);
			}
			else
				pEInputBet->Insert(prevBet);
		}
}

// When the play button is hit this funtion is called.
// "Play" button is toggled to "Bet" button.
// If the deck has less than 26 cards, a new deck is introduced.
// The Old cards are removed from the table
// The input bet amount is captured form the input bet field.
// If the "Bet" amount is more than Bankroll
// amount or 0, a warning is issued, otherwise for a valid bet, the "Hit" and
// "Stand" buttons are enabled but all the other buttons are disabled.
// Since this is a new game, the dealer and the player gets
// 2 cards each. Both the players cards are displayed but
// for the dealer, only one card is displayed.
// If any of the players score 21(with 2 cards), he  wins(Blackjack).

void
TBlackjack::ProcessPlayButton()
{
		{
			char buf[TextLen+1] = "\0";
			int money = (bj.getPlayer(1))->getPocket().getTotal();


			// Check if the total card count on the deck is less than equal
			// to 26, if it is, start with a new deck of cards.

			if(bj.getDealer().getDeck().GetTotal() < 26)
			{
				strcpy(buf, "New Deck");
				pIdDispBet->SetText(buf);
				VBXCardCount = 0;
				delete (&bj.getDealer().getDeck());
				bj.getDealer().setDeck(new Deck);
			}

			RemoveAllCardsOnTable();

			// Get the input bet amount
			pEInputBet->GetLine(buf, TBlackjack::TextLen, 0);
			int betMoney = atoi(buf);
			strcpy(prevBet, buf);

			// Disable the Bet input
			pEInputBet->ShowWindow(SW_HIDE);

			// Toggle "Play" button to "Bet" button.
			pBetBtn->SetWindowText("&Bet");

			if(!(bj.getPlayer(1))->Bet(betMoney))
			{
				//if bet Money > bankroll amount, or 0.
				strcpy(buf, "Bet > bankroll or 0");
				pIdDispBet->SetText(buf);

				// Set the points from the previous game to 0
				pIdDispPPoints->SetText("0");
				pIdDispDPoints->SetText("0");
			}
			else
			{
				// Valid bet amount.
				// Display and set bet amount.
				pIdDispBet->SetText(buf);
				(bj.getPlayer(1))->getPocket().setTotal(money);

				// Enable "Stand" and "Hit" buttons
				pStandBtn->EnableWindow   (TRUE);
				pHitBtn->EnableWindow     (TRUE);
				pHitBtn->SetFocus();

				// Enable "return" key to activate the "Hit" button.
				SetDefaultId(pHitBtn->GetId());

				// Disable "Bet" and "Bankroll" button.
				pBankrollBtn->EnableWindow(FALSE);
				pBetBtn->EnableWindow     (FALSE);

				// For a new game get rid of the cards
				// in dealers hand and players hand.
				bj.getDealer().flushCards();
				(*bj.getPlayer(1)).flushCards();

				// Dealer deals 2 cards to the player and displays
				*(bj.getPlayer(1)) << bj.getDealer();
				*(bj.getPlayer(1)) << bj.getDealer();

				// Display the dealt cards on players side.
				*this << *(bj.getPlayer(1));

				// Dealer deals a card to himself and displays.
				bj.getDealer() << bj.getDealer();
				*this << bj.getDealer();

				// Dealer deals another card to himself which is not displayed.
				bj.getDealer() << bj.getDealer();

				// Check for Blackjack condition here.
				if(bj.IsBlackjack())
				{
						gameOverCleanupBusted(bj.whoLost());
				}
			}
		}
}
//
// This is the callback function for the "HIT" button.
//
void
TBlackjack::IdHitBtn()
{
		 *(bj.getPlayer(1)) << bj.getDealer();      //player gets a card.
		 int pPoint = (*bj.getPlayer(1)).getPoints();

		 // Display the players card.
		 *this << *(bj.getPlayer(1));

		 if(pPoint > 21)
		 {
			  gameOverCleanupBusted(PLAYER);
		 }
}
//
// This is the callback function for the "STAND" button.
//
void
TBlackjack::IdStandBtn()
{
int dPoint;
int pPoint;

		 pPoint = (*bj.getPlayer(1)).getPoints();
		 dPoint = (bj.getDealer()).getPoints();
		 if(dPoint > pPoint)
		 {
				gameOverCleanupBusted(PLAYER);
		 }
		 else
		 {
			 if((dPoint >= 17) && (pPoint >= dPoint))
			 {
				// In this case the Dealer cannot draw any new
				// cards, game is over, Dealer busted.
				if(pPoint == dPoint)
					gameOverCleanupBusted(BOTH);
				else
					gameOverCleanupBusted(DEALER);
			 }
			 else
			 {
				 // Dealers algorithm for hit or stand.
				 int done = 0;
				 while((dPoint < 17) && !done)
				 {
					 bj.getDealer() << bj.getDealer();
					 dPoint = (bj.getDealer()).getPoints();
					 if(dPoint > pPoint)
					 {
						if(dPoint > 21)
							gameOverCleanupBusted(DEALER);
						else
							gameOverCleanupBusted(PLAYER);
						done = 1;
					 }
					 if(!done && (dPoint == pPoint))
					 {
						gameOverCleanupBusted(BOTH);
						done = 1;
					 }
					 if(!done && (dPoint < pPoint) && (dPoint >=17))
					 {
						gameOverCleanupBusted(DEALER);
						done = 1;
					 }

				 }// end while

			 }
		 }
}

// Input parameter is the person who got busted. Valid values are.
// PLAYER 1
// DEALER 2
// BOTH   3
// UNKNOWN 4
void
TBlackjack::gameOverCleanupBusted(int who) throw(const char *)
{
char buf[20];
		if(who == UNKNOWN)
			throw("gameOverCleanup():Input value Unknow.");

		// Put up the winning sign.

		if(who == DEALER)
		{
			pIdDispBet->SetText("Player Won");
			(*bj.getPlayer(1)).Won();
			int t = (*bj.getPlayer(1)).getPocket().getTotal();
			itoa(t, buf, 10);
			pIdDispBankroll1->SetText(buf);
		}

		if(who == PLAYER)
		{
			pIdDispBet->SetText("Dealer Won");
			(*bj.getPlayer(1)).Lost();
			int t = (*bj.getPlayer(1)).getPocket().getTotal();
			itoa(t, buf, 10);
			pIdDispBankroll1->SetText(buf);
		}

		if(who == BOTH)
		{
			pIdDispBet->SetText("Draw");
		}

		// Display all the Dealers card.
		*this << bj.getDealer();

		// Check if the Bank roll is 0,
		// Move focus to the Bankroll button in that case.

		if(!(bj.getPlayer(1))->getPocket().getTotal())
		{
			// Bankroll is 0 because you lost,
			// time to put more money in the bankroll.

			pIdDispBet->SetText("Enter Bankroll");

			pHitBtn->EnableWindow     (FALSE);
			pStandBtn->EnableWindow   (FALSE);
			pBetBtn->EnableWindow     (FALSE);
			pBankrollBtn->EnableWindow(TRUE);
			pBankrollBtn->SetFocus();
			// Enables "return" key to work on the "bankroll" button. 
			SetDefaultId(pBankrollBtn->GetId());

		}
		else
		{

			// BankRoll is not 0 but it cannot be more
			// than $9999, ie the limit.
			// If it is above it then start a new game.
			if((bj.getPlayer(1))->getPocket().getTotal() < 9999)
			{
				pBankrollBtn->EnableWindow(FALSE);
				pHitBtn->EnableWindow     (FALSE);
				pStandBtn->EnableWindow   (FALSE);
				pBetBtn->EnableWindow     (TRUE );
				pBetBtn->SetFocus();
				// Enables "return" key to work on the "Bet" button.
				SetDefaultId(pBetBtn->GetId());

			}
			else
			{
				// If bankroll is 9999 or more.
				pIdDispBet->SetText("Max Bankroll !!!");

				pHitBtn->EnableWindow     (FALSE);
				pStandBtn->EnableWindow   (FALSE);
				pBetBtn->EnableWindow     (FALSE);
				pBankrollBtn->EnableWindow(TRUE);
				pBankrollBtn->SetFocus();
				// Enables "return" key to work on the "Bankroll" button.
				SetDefaultId(pBankrollBtn->GetId());

			}
		}
}
void
TBlackjack::CheckBankRollInput()
{
	// Enable bet button if valid input is present.
	if(pEInputBankRoll->GetLineLength(0))
		::EnableWindow(GetDlgItem(ID_BET_BTN), TRUE);
	else
		::EnableWindow(GetDlgItem(ID_BET_BTN), FALSE);
}
void
TBlackjack::CheckBetInput()
{
	// Enable bet button if valid input is present.
	if(pEInputBet->GetLineLength(1))
	{
		//It should display "Play" button
		pBetBtn->SetWindowText("Pla&y");
	}
	else
	{
		// Should display the "Bet" button.
		pBetBtn->SetWindowText("&Bet");
	}
}
//------------------------------- operator << () ---------------------------
// This is operator is used to display the cards on the table
// for the dealer.

TBlackjack::operator << (Dealer &rhs)
{
int total = rhs.getTotalCards();
  for(int i =0; i < total; i++)
  {

	  if(rhs.getCards()[i] != NULL)
	  {
			if(!(rhs.getCards()[i])->getVBXCard())
			{
				TVbxMhCardDeck * pCard = ppVBXCard[VBXCardCount];
				pCard->SetPropSuit(ConvToVBXSuite(rhs.getCards()[i]->getType()));

				// Make the card faceup.
				pCard->SetPropValue(ConvToVBXNum(rhs.getCards()[i]->getNumber()));

				// Shift by "half the card width" to right.
				pCard->SetPropLeft(DEALER_VBX_CARD1_X+ (i*VBX_CARD_WIDTH*10));
				pCard->SetPropTop (DEALER_VBX_CARD1_Y);
				pCard->SetPropVisible(TRUE);

				// "VBXCardCount", points to the next VBX card which is
				// available for display.
				(rhs.getCards()[i])->setVBXCard(VBXCardCount+1);
				VBXCardCount++;

			}

	  }
  }

  // Set the points field of the dealer in TBlackjack dialog.
  char points[10];
  itoa(rhs.getPoints(), points, 10);
  pIdDispDPoints->SetText(points);
  return 1;
}
//------------------------------- operator << () ---------------------------
// This is operator is used to display the cards on the table
// for the player.

TBlackjack::operator << (Player &rhs)
{
int total = rhs.getTotalCards();
  for(int i =0; i < total; i++)
  {
	  if(rhs.getCards()[i] != NULL)
	  {
			if(!(rhs.getCards()[i])->getVBXCard())
			{
				TVbxMhCardDeck * pCard = ppVBXCard[VBXCardCount];
				pCard->SetPropSuit(ConvToVBXSuite(rhs.getCards()[i]->getType()));

				// Make the card faceup.
				pCard->SetPropValue(ConvToVBXNum(rhs.getCards()[i]->getNumber()));

				pCard->SetPropLeft(PLAYER_VBX_CARD1_X + i*VBX_CARD_WIDTH*10);
				pCard->SetPropTop(PLAYER_VBX_CARD1_Y);

				pCard->SetPropVisible(TRUE);

				// VBXCardCount, keeps the card count on the actual VBX deck.
				// count 12 menas 0-11 cards are already dealt.
				// The cards always remain here only while displaying it
				// displayed from here.

				(rhs.getCards()[i])->setVBXCard(VBXCardCount+1);
				VBXCardCount++;

			}

	  }
  }

  // Set the points field of the dealer in TBlackjack dialog.
  char points[10];
  itoa(rhs.getPoints(), points, 10);
  pIdDispPPoints->SetText(points);
  return 1;
}

void
TBlackjackFrame::SetupWindow()
{
  TFrameWindow::SetupWindow();
  BlackjackDialog = new TBlackjack(this);
  SetClientWindow(BlackjackDialog);

  // Center the Frame window.
  int x = ::GetSystemMetrics(SM_CXSCREEN);
  int y = ::GetSystemMetrics(SM_CYSCREEN);
  MoveWindow(
				(x/2 - GetWindowRect().Width()/2),
				(y < GetWindowRect().Height() ? 0: (y-GetWindowRect().Height())/2),
				GetWindowRect().Width(), GetWindowRect().Height()
				);
}
void
MovableDialog::SetupWindow()
{
	TDialog::SetupWindow();

	MoveWindow(
			Parent->GetWindowRect().TopLeft().x+topLeftX,
			Parent->GetWindowRect().TopLeft().y+topLeftY,
		  GetWindowRect().Width(), GetWindowRect().Height()
	  );
}
DEFINE_RESPONSE_TABLE(TBlackjackApp)
  EV_COMMAND(ID_ABOUT, IdAbout),
END_RESPONSE_TABLE;

void
TBlackjackApp::IdAbout()
{
	TDialog *pTDlg = new MovableDialog(0,0,MainWindow , AboutBox);
	pTDlg->Execute();
}

//
// The card suite runs from 1-4
// The VBX suite are enum-ed they have different values.
//
int
ConvToVBXSuite(int cardSuite)
{
	return((cardSuite-1)+ TVbxMhCardDeck::Suit_0_Clubs);
}

//
// The card numbers runs from 0(Ace)-13(Queen), this is for internal
// representation nothing to do with Blackjack card points.
// The VBX card numbers are enum-ed and they have different values.
// it runs from (1-14), 0 is the back of the card.

int
ConvToVBXNum(int cardNum)
{
	return (cardNum + TVbxMhCardDeck::Value_1_Ace);
}

//----------------------------------------------------------------------------
//
// Create the BlackJack dialog as the application's main window.
//
void
TBlackjackApp::InitMainWindow()
{
  EnableBWCC();
  MainWindow = new TBlackjackFrame(0, "Turbo 21", 0, TRUE);
  MainWindow->SetIcon(this, "BJ_ICO");
  MainWindow->AssignMenu("BJ_MENU");
  MainWindow->Attr.Style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME|WS_POPUP);
}
TBlackjackApp::~TBlackjackApp()
{
	delete MainWindow;
}
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  int retVal;
  TBIVbxLibrary vbxLib;
  try{
		retVal = TBlackjackApp(AppName).Run();
  }
  catch(const char *str)
  {
		::MessageBox(0, str, "Exception", MB_OK);
  }
  catch(...)
  {
		::MessageBox(0, "Exception Occured", "Generic Exception", MB_OK);
  }
  return retVal;
}


