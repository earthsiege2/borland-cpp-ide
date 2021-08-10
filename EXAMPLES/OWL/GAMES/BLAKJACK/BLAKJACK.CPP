//-----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1995 by Borland International
// blakjack.cpp
// This is the engine for the blackjack game, it does not contain any
// windows or OWL code.
//-----------------------------------------------------------------------------

#include "blakjack.h"
#include <stdlib.h>
#include <ctype.h>
#include <iostream.h>

//------------------------------Card--------------------------

Card::Card(int iVal, int iType, int iface=0)
:	number(iVal),
	type(iType),
	face(iface),
	mark(0),
	pVBXCard( NULL)
{
}
// Sets new number i to the card, returns the old number.
inline
Card::setNumber(int i)
{
	int t = number;
	number = i;
	return t;
}
// Sets the new Type (HEARTS, CLUBS, DIAMONDS, SPADE),
// returns the old type.
inline
Card::setType(int i)
{
	int t = type;
	type = i;
	return t;
}
inline
Card::isUp() const
{
	return (face?1:0);
}
// Flips the card.
inline void
Card::flip()
{
	face = face? 0: 1;
}
// If a card is marked as 1, it means it has been
// dealt by the dealer from the deck and can be no longer used
// to deal or shuffle.
inline void
Card::setMark(int i)
{
	mark = i;
}
inline
Card::isMarked() const
{
	return (mark?1:0);
}
void
Card::setVBXCard(int VBXCardArrayIndexPlus1)
{
	pVBXCard = VBXCardArrayIndexPlus1;
}
//------------------------------------ Deck---------------------
// returns total number of cards in the deck.
Deck::GetTotal() const
{
	return total;
}
void
Deck::SetTotal(int i) throw (const char* )
{
	if(i > 52)
		throw "SetTotal:Invalid range, try 0-52";
	else
	  total = i;
}
void
Deck::SetTopIndex(int i)
{
	topIndex = i;
}
Card *
Deck::GetCard()
{
	if(!total)
		return (Card *)NULL;
	else
	{
	  total--;
	  Card *retCard = ppCards[topIndex];
	  ppCards[topIndex++] = NULL;
	  return retCard;
	}
}
// It generates a random number between 0 and 51
// For 100 times it generates 2 random numbers in the above range
// and exchanges the cards in these 2 positions in the deck.
// Returns how many times the card gets shuffled for 100 tries.
Deck::Shuffle()
{
  int i;
  int j;
  int s =0;

  Card *tmp;

  randomize();
  for(int k = 0; k <100; k++)
  {
		i = rand() % 52; // generates 0 to 51.
		j = rand() % 52;

		// swap cards only if the cards are in the
		// deck.

		if(ppCards[i] && ppCards[j])
		{
			// Shuffle only if the cards are in deck.
			tmp          = ppCards[i  ];
			ppCards[i]   = ppCards [j];
			ppCards[j]   = tmp;
			s++;
		}
  }
  return s;
}

Deck::Deck() throw(const char *)
:	total(52),
	ppCards((Card **)new char [sizeof(Card *)*(52+1)]),
	topIndex(0)

{

	if(!ppCards)
		throw "Error:Deck::Deck() out of memory.";
	for(int i=0; i < 52; i++)

	{             // Number (0-13)  Type(1-4)
		ppCards[i] = new Card(i%13, ((i/13)+1), 1);
	}
	ppCards[i] = NULL; // the last cell

	Shuffle();
}
Deck::~Deck()
{
	for(int i=0; i < 52; i++)
	{
		delete ppCards[i];
	}
	delete ppCards;
}

// This funtion prints the all the crads in the deck.
// Do not use this funtion in the OWL program. Used for
// debugging purpose only.

ostream&
operator<<(ostream &str, Deck& rhs)
{
  for(int i =0; i < 52; i++)
  {
	// if the card is already dealt to the player it will not be present
	//  on the deck. In that case do not try to print it.
	if(rhs.ppCards[i])
	{
		 str << rhs.ppCards[i]->getNumber() << " " ;
		 switch(rhs.ppCards[i]->getType())
		 {
			 case 1:
			 str << "Hearts";
			 break;
			 case 2:
			 str << "Spades";
			 break;
			 case 3:
			 str << "Clubs";
			 break;
			 case 4:
			 str << "Diamonds";
			 break;
			 default:
			 str << "Uninitialized card";
			 break;
		 }
		 str << "  ";
	}
  }
  return str;
}

//-----------------------Hand----------------------------------
void
Hand::AdjustAceValueIfTotalIs21Plus()
{
			// Check if the player/Dealer has any ACE in his hand.
			// If it was 11 make it 1 and give the player
			// a 2nd chance. Adjust the players score also.

			Card *pCard = ppCards[0];
			int done = 0;
			for(int i =0; pCard && !done; i++)
			{
				pCard = ppCards[i];
				if(pCard)
				{
					if(pCard->getNumber() == 0)
					{
					  // card is ACE
					  if(pCard->getMark())
					  {
						  //ACE is marked as 11, mark it as 1.
						  pCard->setMark(0);

						  // recalculate points with ACE as 1 instead of 11.
						  setPoints(getPoints()-10);
						  done = 1;
					  }
					}
				}
				else
				  done = 1;
			}
}
//
// It calculates the total number of points including the added card.
// and stores it in "points" data member.
// Returns the index at which the new card was added.
//
Hand::AddCard(Card *pCard)
{
int retVal = getTotalCards();
	ppCards[retVal] = pCard;

	// Add the Card and then increase the total.
	incTotalCards();
	calcPoints(pCard->getNumber());
	return retVal;
}

// Set value for point data member. Which holds total points for the hand.
void
Hand::setPoints(int i)
{
	points = i;
}

// Get the total point for the particular hand.
Hand::getPoints() const
{
	return points;
}
inline void
Hand::setResult(int i)
{
	result = i;
}
Hand::getResult() const
{
	return result;
}
// if bet amount is more than total
// return 0.
// else 1.
inline
Hand::setBetMoney(int i)
{
	{
		betMoney = i;
		return 1;
	}
}
Hand::getBetMoney() const
{
	return betMoney;
}
Hand::getTotalCards() const
{
	return totalCards;
}
// Increments and returns the value of the
// new "totalCards".
Hand::incTotalCards()
{
  return ++totalCards;
}
//
// It is called after a game is over, to initialize
// the hand.
// Returns how many cards where actually flushed.
//
Hand::flushCards()
{
int howManyFlushed =0;
	for(int i=0; i < 52; i++)
	{
		 if(ppCards[i])
		 {
			 delete(ppCards[i]);
			 ppCards[i] = NULL;
			 howManyFlushed++;
		 }

	}

	totalCards = 0;
	points =0;
	return howManyFlushed;
}
//-------------------------calcPoints()-----------------------------------
// Numbers    Blackjack
// which      points
// represent
// a card.
// ----------------------
// 0 -       Ace (is 11 if total in hand is <= 10 else 1, cannot go over 21.)
// 1         2 of any suit
// 2         3 of any suit
// ...
// 9 -       10 of any suit
// 10 -       Jack   (10)
// 11 -       Queen  (10)
// 12 -       King   (10)
// After a new card is added this is called to calculate the total points.
// Input is the internal number representation of the card as shown in the
// first column above. The 2nd column shows the points for different cards.
// Returns the incremented value of total point.

Hand::calcPoints(int number) throw(const char*)
{
	switch(number)
	{
		case 0:
			if(points <= 10)
			{
				points += 11;

				// Mark the card as 1, that means, ACE which is 11.
				ppCards[getTotalCards() - 1]->setMark(1);
			}
			else
				points +=1;

		break;
		case 10:  // jack
		case 11:  // Queen
		case 12:  // King
			points += 10;
		break;
		default:
			if(number >=1 && number <=9)
				points += (++number);
			else
			 throw "Error:calcPoints():Card number outof range.\n";
	}
	// Adjust the point of the card here.
	if(points > 21)
		AdjustAceValueIfTotalIs21Plus();

	return points;
}

Hand::Hand() throw (const char *)
:  ppCards ((Card **)new char [sizeof(Card *)*(52+1)]),
	totalCards(0),
	points(0),
	result(UNKNOWN),
	betMoney(0)
{
	// Array of pointers to Card type.

	if(!ppCards)
		throw "Ran out of memory in Hand::Hand()";
	for(int i=0; i < 52; i++)
	{
		ppCards[i] = NULL;
	}
	ppCards[i] = NULL;
}
Hand::~Hand()
{
	for(int i=0; i < 52; i++)
	{
		delete ppCards[i];
	}
	delete ppCards;
}

//-----------------------------Bankroll---------------------------

Bankroll::Bankroll(int i = 100):total(i)
{
}

Bankroll::~Bankroll()
{
}
void
Bankroll::setTotal(int i)
{
	total = i;
}
Bankroll::getTotal() const
{
	return total;
}
// returns 0 if input > total
// else returns 1.
Bankroll::decrementBy(int i)
{
	if( (total -i) < 0)
		return 0;
	else
	{
		total -= i;
		return 1;
	}
}
// increaments the total by input
// and returns the new total.
Bankroll::incrementBy(int i)  throw(const char *)
{
	if(i>=0)
	{
		total += i;
	}
	else
	{
		throw "Error:Bankroll.incrementby: -ve input\n";
	}
	return total;
}
// returns
// 1 if empty.
// 0 if not empty.

Bankroll::isEmpty() const
{
	return(total?0:1);
}
//------------------------Player---------------------------
//
// returns
// 0 if bet > bankroll
// 1 if bet has been made.
// sets the "betMoney" data member to inut.
//
Player::Bet(int i)
{
	if(i > pocket.getTotal() || (i <=0))
	  return 0;
	else
	{
		// in Hand.
		setBetMoney(i);
		return 1;
	}
}
//-----------------Lost()-----------------------
// Decrements the bankroll by "betMoney".
// Returns the amount of bankroll money left.

Player::Lost() throw(const char *)
{
int total = pocket.getTotal();
	if(getBetMoney() <= total)
	{
		pocket.decrementBy(getBetMoney());
	}
	else
	{
		// Fatal error, it should not happen.
		// before betting this condition is checked.
		throw "Error:Player.Lost():You lost more money than you have\n";
	}
	return (total - getBetMoney());
}
// Increments the bankRoll by "betMoney".
// Returns the total after winning.
Player::Won()
{
	return (pocket.incrementBy(getBetMoney()));
}

Player::Player(int money)
{
	pocket.setTotal(money);
}
Player::~Player()
{
}
//-------------------------Dealer--------------------------------
Dealer::Dealer()
:	deck( new Deck)
{
}
Dealer::~Dealer()
{
	delete deck;
}
Deck &
Dealer::getDeck() const
{
	return *deck;
}
void
Dealer::setDeck(Deck *p)
{
	deck = p;
}
//-------------------------BlackJack----------------------------
// Returns the nth number player.
// If no such player exists then it returns NULL.
// Player number starts from 1.
// There is no 0th player.

Player *Blackjack::getPlayer(int p) const
{
	if (p ==0)
		return NULL;

	// finds the total number of players.
	for(int i=0; ppPlayer[i]; i++)
	  ;
	 if(p <= (i))
		return ppPlayer[p-1];
	 else
		return NULL;
}
// Returns
// PLAYER ->  1 or
// DEALER ->  2 or
// BOTH   ->  3 or
// UNKNOWN -> 4
// Depending on who lost.
// header file.

Blackjack::whoLost()
{
	int pPoint = (*getPlayer(1)).getPoints();
	int dPoint = getDealer().getPoints();

	// if any player has scored more than 21

	if(dPoint > 21 && pPoint <= 21)
		return DEALER;
	if(pPoint > 21 && dPoint <= 21)
		return PLAYER;

	// Following cases cannot be "greater than 21" cases
	if(dPoint > pPoint)
	  return PLAYER;
	else
	  if(dPoint < pPoint)
		return DEALER;
	  else
		if(dPoint == pPoint)
			return BOTH;

	 return(UNKNOWN);
}

// Returns
// 1
// when a player or both(player and dealer) hit blackjack
// ie, scored 21 points when the 1st 2 cards where dealt.
// 0 - if not.

Blackjack::IsBlackjack()
{
	int pPoint = (*getPlayer(1)).getPoints();
	int dPoint = (getDealer()).getPoints();
	if(pPoint == 21 || dPoint == 21)
		return 1;
	else
		return 0;
}
Blackjack::Blackjack()
{
	// This application uses only one player and one dealer
   // You can extend the game by adding more number of players.
	ppPlayer = (Player **)new char[sizeof(Player *)*2];
	ppPlayer[0] = new Player(100);
	ppPlayer[1] = NULL;

}
Blackjack::~Blackjack()
{
	for(int i=0; ppPlayer[i]; i++)
		delete ppPlayer[i];
	delete ppPlayer;
}
// This is the "Deal" operator for dealing a card to the dealer.
// eg: "Dealer << Dealer", means Dealer deals a card to himself.

Dealer& operator << (Dealer &p, Dealer &d) throw(const char *)
{
	Card *pCard = (d.deck)->GetCard();
	if(pCard)
	{
		if(p.getTotalCards()> 52)
			throw "Dealer cannot have more than 52 cards\n";
		else
		{
			  p.AddCard(pCard);
		}
	}
	else
		throw "All cards exhausted\n";
	return p;
}
// This is the "Deal" operator for dealing a card to the player.
// eg: "Player << Dealer", means Dealer deals a card to the player.
// Returns always 0.
// DO NOT chain it.
//
operator << (Player &p, Dealer &d) throw(const char *)
{
	Card *pCard = (d.deck)->GetCard();
	if(pCard)
	{
		if(p.getTotalCards()> 52)
			throw "Player cannot have more than 52 cards\n";
		else
		{
			  p.AddCard(pCard);
		}
	}
	else
		throw "All cards exhausted\n";
	return 0;
}
// This is a debugging function to print out the hand status.
// Useful while debugging the engine in text mode. Now it is not
// used any where.
ostream& 
operator << (ostream& str, Hand &rhs)
{
int total = rhs.getTotalCards();
  for(int i =0; i < total; i++)
  {
	str << rhs.ppCards[i]->getNumber() << " " ;
	switch(rhs.ppCards[i]->getType())
	{
		case 3:
		str << "Hearts";
		break;
		case 4:
		str << "Spades";
		break;
		case 1:
		str << "Clubs";
		break;
		case 2:
		str << "Diamonds";
		break;
		default:
		break;
	}
	str << "  ";
  }
  str << "total: " << rhs.getPoints();
  str << endl;
  return str;
}

