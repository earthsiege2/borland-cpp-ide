//-----------------------------------------------------------------------------
// Borland International.
// (c) Copyright 1995.
// Blakjack.h
//-----------------------------------------------------------------------------
#ifndef BLACKJACK_H
#define BLACKJACK_H

#define DEALER_VBX_CARD1_X 300
#define DEALER_VBX_CARD1_Y 1300
#define PLAYER_VBX_CARD1_X 300
#define PLAYER_VBX_CARD1_Y 3800

#define VBX_CARD_WIDTH     41
#define VBX_CARD_LENGTH    59

//
// These are the win status.
//
#define PLAYER  1
#define DEALER  2
#define BOTH    3
#define UNKNOWN 4

//
// VBX card control class.
//
class TVbxMhCardDeck;
class TBlackjack;

class Card {
  public:
    Card(int val, int type, int faceUp);
// ~Card() {pVBXCard = 0;}

    int setNumber (int i);
    int   getNumber () const
        {
          return number;
        }
    int   setType(int i);
    int getType() const
        {
            return type;
        }
    // Marks the card as faceup
    void  up()
        {
          face = 1;
        }
    // Marks the card as face down.
    void  down()
        {
          face = 0;
        }
    int isUp      () const;
    void  flip      ();
    void  setMark  (int i);

    int   getMark() const
        {
          return mark;
        }

    int isMarked() const;
    int   getVBXCard() const
        {
          return pVBXCard;
        }
    void  setVBXCard(int );

  private:
    int number;    // Ace->0, Two->1..., Jack->10, King->11, Queen->12
    int type;      // HEARTS, CLUBS, DIAMONDS, SPADE
    int face;      // 1 -> face up, 0 -> face down.
    int mark;      // This is used to keep track of ACE value(1(0) or 11(1))
    int pVBXCard;  // this contains the index+1 of the VBX card in the VBX array
              // in TBlackjack class, in OwlMain.
};

class Deck {
  public:
    Deck() throw (const char *);
   ~Deck();

    int   GetTotal() const;  // returns total number of cards in the deck.
    void  SetTotal(int i)throw (const char* ); // sets new total after a
                       // a card is dealt.
    void  SetTopIndex(int);   // Sets new top index after a card is dealt.
    Card  *GetCard();       // gets the top most card on the deck.
    int   Shuffle();       // Shuffles all the cards on the deck.

  private:
    int   total;       // Total number of cards in the deck
                 // Dealt cards are not in the deck.
    Card  **ppCards;   // Array of cards(52) in the deck.
    //Card  *pTop;       // May point to the top most card on the deck
    int   topIndex;    // array index of the top most card in the deck.

  friend ostream& operator<<(ostream &str, Deck& rhs);
};

//
// Prints out the Deck information. Only used to debug.
//
ostream& operator<<(ostream &str, Deck& rhs);

class Hand {
  public:
    Hand()throw (const char *);
   ~Hand();

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

    // Calculate the points for the hand when a new card is drawn.
    // Rule , make Ace = 11 if (total points =< 10) else 1
    int   calcPoints(int number) throw (const char*);

  private:
    Card  **ppCards;  //Cards dealt to the hand resides in this array.
    int   totalCards; //total number of cards dealt to hand.
    int   points;     //total points in a game, resulting from above cards.
    int   result;   // WIN, LOOSE, NONE
    int   betMoney;   //stores the current bet money.

    //adjusts the ACE value from 11 to 1 if the total goes over 21.
    void  AdjustAceValueIfTotalIs21Plus();

  friend ostream& operator << (ostream& , Hand &h);
};

ostream& operator << (ostream& , Hand &h); // only used for debugging purposes

class Bankroll {
  public:
    Bankroll(int i);
   ~Bankroll();

    void  setTotal(int i); //Sets "total" to input value
    int   getTotal() const;      //Gets the "total" value
    // retlurns 0 if input > total
    int   decrementBy(int i); //decrements the total by specified amount.
    int   incrementBy(int i)throw(const char *); //increments the total
                                  //by specified amount.
    int   isEmpty() const;      // Checks for 0 bankroll

  private:
    int total;     // Stores the current bankroll amount.
};

class Dealer;

class Player : public Hand {
  public:
    Player(int money);
   ~Player();

    Bankroll & getPocket() { return pocket;}
    int Bet(int i);
    int Lost() throw (const char*);  // Registers loss
    int Won();                      // Registers win

  private:
    Bankroll    pocket;

  friend operator << (Player &p, Dealer &d)throw(const char *);
  friend Dealer& operator << (Dealer &p, Dealer &d)throw(const char *);
};

class Dealer : public Hand {
  public:
    Dealer();
   ~Dealer();

    int   dealACard();
    Deck& getDeck() const;
    void  setDeck(Deck* p);

  private:
    Deck*  deck;

  friend operator << (Player &p, Dealer &d)throw(const char *);
  friend Dealer& operator << (Dealer &p, Dealer &d)throw(const char *);
  friend ostream& operator << (ostream& , Dealer &d);
};

ostream& operator << (ostream& , Dealer &d);
operator << (Player &p, Dealer &d) throw(const char *);

class Blackjack {
  public:
    Blackjack();
    Blackjack(int numberOfPlayer);
   ~Blackjack();

    Dealer&  getDealer() { return dealer; }
    Player*  getPlayer(int p) const;
    int      IsBlackjack();

    // PLAYER, DEALER, BOTH
    int     whoLost();

  private:
    Dealer   dealer;
    Player** ppPlayer;
};

#endif
