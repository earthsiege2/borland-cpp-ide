//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#ifndef CARDS_H
#define CARDS_H

#include <owl/window.h>
#include <assert.h>

//
// TCard -- a class which defines a single playing card.  The card
// has the following properties:
//
//   rank      -- 1-13, 1=ace, 13=king
//   suit      -- 0-3, hearts, diamons, spades, clubs
//   backStyle -- 0-13, one of 13 back styles
//   faceUp    -- bool, is the card face up or down
//
class TCard {
  public:
    int  rank, suit, backStyle;
    BOOL faceUp;
    TCard(int aRank = 0, int aSuit = 0, int aBackStyle = 0, BOOL aFaceUp = FALSE) {
      rank = aRank;
      suit = aSuit;
      backStyle = aBackStyle;
      faceUp = aFaceUp;
    }
    TCard(TCard& card) {
      *this = card;
    }
    static const char *Stringify(int r, int s) {
      strcpy(buffer, rankStr[r]);
      strcat(buffer, suitStr[s]);
      return buffer;
    }
    const char *Stringify() {
      return Stringify(rank, suit);
    }
  private:
    static char *rankStr[14];
    static char *suitStr[4];
    static char buffer[10];
};

//
// TCardGroup -- defines a group of cards.  At construction time, you
// must specifiy the maximum # of cards allowed in the group.  Then
// you can insert and remove cards.  TDeck is derived from this class.
//
#ifdef _OWLDLL
class _huge TCardGroup {
#else
class TCardGroup {
#endif
  public:
    TCardGroup(int aMaxCards);
    ~TCardGroup();
    int GetCount() { return count; }          // get current # of cards in group
    int GetMaxCards() { return maxCards; }
    int Insert(TCard* card);               // insert card (returns index)
    void Insert(TCardGroup* cardGroup);     // insert group of cards
    virtual TCard* Remove(int position=0);          // remove card
    const TCard& operator[](int position);  // access card without removing it

  protected:
    TCard **cards;

  private:
    int   maxCards,   // max # of cards that this group can contain
          count;      // current # of cards that this group contains

    TCardGroup& operator =(TCardGroup&) { return *this; }
    TCardGroup(TCardGroup&) {}
};

//
// TDeck -- derived from TCardGroup, automatically creates a group of
// 52 cards.  Added functions for shuffling, cutting, and dealing the
// cards
//
class TDeck : public TCardGroup {
  public:
    TDeck(int backStyle = 0);

    TCard* DealCard();                 // removes the top card from the deck
    void Shuffle(int shuffleCount);  // shuffle cards
    void Cut(int cutPosition);       // cut cards at given position
    void ResetBackStyle(int newBackStyle);
    const char * EncodeDeck();
    BOOL DecodeDeck(const char* encodedDeck);
    void Initialize(int backStyle);
};

#endif // CARDS_H
