//-----------------------------------------------------------------------------
// Borland International.
// (c) Copyright 1995.
// Blakjack.h
//-----------------------------------------------------------------------------

#ifndef __BLACKJACK_H
#define __BLACKJACK_H

#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\dialog.h>
#include <owl\button.h>
#include <owl\static.h>
#include <owl\inputdia.h>
#include <owl\validate.h>
#include <owl\framewin.h>
#include <owl\vbxctl.h>
#include <stdio.h>
#include "card.rh"
#include "mhcd2001.h"

#define DEALER_VBX_CARD1_X 300
#define DEALER_VBX_CARD1_Y 1300
#define PLAYER_VBX_CARD1_X 300
#define PLAYER_VBX_CARD1_Y 3800

#define VBX_CARD_WIDTH     41
#define VBX_CARD_LENGTH    59

// These are the win status.
#define PLAYER  1
#define DEALER  2
#define BOTH    3
#define UNKNOWN 4

// VBX card control class.
class TVbxMhCardDeck;
class TBlackjack;

class Card
{
	private:
		int number;    // Ace->0, Two->1..., Jack->10, King->11, Queen->12
		int type;      // HEARTS, CLUBS, DIAMONDS, SPADE
		int face;      // 1 -> face up, 0 -> face down.
		int mark;      // This is used to keep track of ACE value(1(0) or 11(1))
		int pVBXCard;  // this contains the index+1 of the VBX card in the VBX array
							// in TBlackjack class, in OwlMain.
	public:
				Card(int val, int type, int faceUp);
				~Card()
				{
						pVBXCard = 0;
				}

		int	setNumber (int i);
		int 	getNumber () const
				{
					return number;
				}
		int 	setType(int i);
		int	getType() const
				{
						return type;
				}
		// Marks the card as faceup
		void 	up()
				{
					face = 1;
				}
		// Marks the card as face down.
		void 	down()
				{
					face = 0;
				}
		int	isUp      () const;
		void 	flip      ();
		void 	setMark	 (int i);

		int 	getMark() const
				{
					return mark;
				}

		int	isMarked() const;
		int 	getVBXCard() const
				{
					return pVBXCard;
				}
		void 	setVBXCard(int );

};
class Deck
{
	private:
		int   total;       // Total number of cards in the deck
								 // Dealt cards are not in the deck.
		Card	**ppCards;   // Array of cards(52) in the deck.
		//Card	*pTop;       // May point to the top most card on the deck
		int  	topIndex;    // array index of the top most card in the deck.

	public:
		int   GetTotal    () const;  // returns total number of cards in the deck.
		void  SetTotal    (int i)throw (const char* ); // sets new total after a
											 // a card is dealt.
		void  SetTopIndex (int );   // Sets new top index after a card is dealt.
		Card  *GetCard	   ();       // gets the top most card on the deck.
		int   Shuffle     ();       // Shuffles all the cards on the deck.

				Deck()throw(const char *);
			  ~Deck();

		friend ostream& operator<<(ostream &str, Deck& rhs);
};
// Prints out the Deck information. Only used to debug.
ostream& operator<<(ostream &str, Deck& rhs);

class Hand
{
	private:
		Card  **ppCards;  //Cards dealt to the hand resides in this array.
		int   totalCards; //total number of cards dealt to hand.
		int 	points;     //total points in a game, resulting from above cards.
		int 	result;		// WIN, LOOSE, NONE
		int 	betMoney;   //stores the current bet money.

		//adjusts the ACE value from 11 to 1 if the total goes over 21.
		void  AdjustAceValueIfTotalIs21Plus();

	public:
      // returns the pointer to the array of cards.
		Card  **getCards   () const {return ppCards;};

		int   AddCard      (Card *pCard); // Adds the dealt card to the array.
		void  setPoints    (int i);
		int   getPoints    () const;
		void  setResult    (int i);
		int   getResult    () const;
		int   setBetMoney  (int i);
		int   getBetMoney  () const;
		int   getTotalCards() const;
		int   incTotalCards();
		int   flushCards   (); // Flushes all the cards from the hand.

		// calculate the points for the hand when a new card is drawn.
		// Rule , make Ace = 11 if (total points =< 10) else 1
		int   calcPoints   (int number) throw(const char*);

				Hand()throw (const char *);
			  ~Hand();

		friend ostream& operator << (ostream& , Hand &h);
};
ostream& operator << (ostream& , Hand &h); // only used for debugging purposes

class Bankroll
{
	private:
		int	total;     // Stores the current bankroll amount.

	public:
				Bankroll   (int i);
				~Bankroll  ();

		void 	setTotal   (int i); //Sets "total" to input value
		int 	getTotal   () const;      //Gets the "total" value
		// retlurns 0 if input > total
		int 	decrementBy(int i); //decrements the total by specified amount.
		int 	incrementBy(int i)throw(const char *); //increments the total
																	//by specified amount.
		int 	isEmpty    () const;      // Checks for 0 bankroll

};
class Dealer;
class Player: public Hand
{
	private:
		Bankroll		pocket;

	public:
		Bankroll & getPocket() { return pocket;}
		int	Bet  (int i);
		int 	Lost () throw(const char *);  // Registers loss
		int	Won  ();                      // Registers win

				Player(int money);
				~Player();

		friend operator << (Player &p, Dealer &d)throw(const char *);
		friend Dealer& operator << (Dealer &p, Dealer &d)throw(const char *);

};

class Dealer:public Hand
{
	private:
		Deck	*deck;

	public:
		int	dealACard();
		Deck 	&getDeck () const;
		void 	setDeck  (Deck *p);
				Dealer   ();
				~Dealer  ();

		friend operator << (Player &p, Dealer &d)throw(const char *);
		friend Dealer& operator << (Dealer &p, Dealer &d)throw(const char *);
		friend ostream& operator << (ostream& , Dealer &d);

};

ostream& operator << (ostream& , Dealer &d);
operator << (Player &p, Dealer &d) throw(const char *);

class Blackjack
{
	private:
		Dealer	dealer;
		Player	**ppPlayer;

	public:
		Dealer	&getDealer ()
		{
				return dealer;
		}
		Player	*getPlayer (int p) const;
		int 		IsBlackjack();

		// PLAYER, DEALER, BOTH
		int 		whoLost ();

					Blackjack ();
					Blackjack (int numberOfPlayer);
					~Blackjack();
};

#endif
