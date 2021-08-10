//-----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1995 by Borland International
// Owlmain.h
//-----------------------------------------------------------------------------

#ifndef __OWLMAIN_H
#define __OWLMAIN_H

class TBlackjackFrame: public TFrameWindow
{
public:

	TWindow* BlackjackDialog;
	TBlackjackFrame(  TWindow * ParentWindow,
							 const char far * title,
							 TWindow *clientWnd,
							 BOOL ShrinkToClient)
		  :TFrameWindow(ParentWindow,
							 title,
							 clientWnd,
							 ShrinkToClient)
		  {/*Empty body */}

	~TBlackjackFrame(){/* Empty body */}

	// Center the frame windows initial position here
	void SetupWindow();
};

class TBlackjack : public TDialog
{
private:
	static const int TextLen;
	int BankRollEnteredFirstTime;
	char prevBet[20];
	char prevBankroll[20];

public:
	TBrush      Brush;
	TButton     *pBankrollBtn;
	TButton     *pBetBtn;
	TButton     *pHitBtn;
	TButton     *pStandBtn;

	TStatic     *pIdDispBankroll1;
	TStatic     *pIdDispBet;
	TStatic     *pIdDispPPoints;
	TStatic     *pIdDispDPoints;

	TEdit       *pEInputBankRoll;
	TEdit       *pEInputBet;

	TFilterValidator *pValidBankRoll;
	TFilterValidator *pValidBet;
	TVbxMhCardDeck   *ppVBXCard[52];

	// VBXCardCount, keeps the card count of the  VBX cards.
	// Count 12 means, 0 to 11 cards have been dealt.
	int VBXCardCount;

	TInputDialog *pInputDialog;

	// This is the black jack class.
	Blackjack bj;

	TBlackjack(TWindow *pWin);
	~TBlackjack();

	// Displays the cards in the dialog.
	void   InitBlackjack();



protected:
	void     SetupWindow();
	BOOL     EvInitDialog(HWND hWnd);
	void     DisplayCardOnTable();
	void     RemoveAllCardsOnTable();
	void     IdStandBtn();
	void     IdHitBtn();
	void 	   IdBankrollBtn();
	void 	   IdBetBtn();
	void 		ProcessBetButton();
	void 		ProcessPlayButton();
	void     IdDispPPoints();
	void     gameOverCleanupBusted(int )throw(const char *);
	void 		CheckBankRollInput();
	void		CheckBetInput();
	operator << (Dealer &rhs);
	operator << (Player &rhs);

  DECLARE_RESPONSE_TABLE(TBlackjack);
};

class TBlackjackApp : public TApplication {
public:
	TVbxMhCardDeck *pCard;
	TBlackjackApp(const char far* name) : TApplication(name) {}
	~TBlackjackApp();

	void   InitMainWindow();
	void   IdAbout();

	LRESULT       EvCommand(UINT, HWND, UINT);
	DECLARE_RESPONSE_TABLE(TBlackjackApp);
};

class MovableDialog: public TDialog
{
private:
	int topLeftX, topLeftY;
public:
	MovableDialog(int topLeft_x, int topLeft_y, TWindow *pWin, TResId id):
	TDialog(pWin, id),
	topLeftX(topLeft_x), topLeftY(topLeft_y){}

	~MovableDialog(){};

	// Move the dialog here
	void SetupWindow();
};

int ConvToVBXNum(int cardNum);
int ConvToVBXSuite(int cardSuite);

#endif
