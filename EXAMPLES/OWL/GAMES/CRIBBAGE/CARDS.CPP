//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#include <owl/pch.h>
#include "cards.h"

char *TCard::rankStr[14] = { "0","A","2","3","4","5","6",
                             "7","8","9","10","J","Q","K" };
char *TCard::suitStr[4] = { "C","D","H","S" };

char TCard::buffer[10];

TCardGroup::TCardGroup(int aMaxCards) {
  maxCards = aMaxCards;
  count = 0;
  cards = new TCard*[maxCards];
  for (int i=0;i<maxCards;i++)
    cards[i]=0;
}

TCardGroup::~TCardGroup() {
  for (int i=0;i<count;i++)
    delete cards[i];
  delete [] cards;
}

int TCardGroup::Insert(TCard* card) {
  assert(count<maxCards);
  assert(card!=0);
  cards[count++] = card;
  return (count-1);
}

void TCardGroup::Insert(TCardGroup* cardGroup) {
  TCard *temp;
  do {
    temp = cardGroup->Remove(0);
    if (temp)
      Insert(temp);
  } while (temp);
}

TCard* TCardGroup::Remove(int position) {
  int i;

  if (count==0)
    return 0;

  TCard *temp = cards[position];
  for (i=position+1;i<count;i++)
    cards[i-1]=cards[i];
  cards[count-1]=0;
  count--;
  return temp;
}

const TCard& TCardGroup::operator[](int position) {
  assert((position>=0) && (position<GetCount()));
  return *cards[position];
}

TCard* TDeck::DealCard() {
  return Remove();
}

TDeck::TDeck(int backStyle): TCardGroup(52) {
  Initialize(backStyle);
}

void TDeck::Initialize(int backStyle) {
  int suit,value;

  while (Remove()!=0);

  for (suit=0;suit<4;suit++)
    for (value=1;value<=13;value++)
      Insert(new TCard(value, suit, backStyle, false));
}

void TDeck::Shuffle(int shuffleCount) {
  TCard *temp[52];  // temporarily hold the cards here
  int i,j,k,splitPos;
  int count = GetCount();

  assert(count==GetMaxCards());        // shuffle only works on a full deck

  while (shuffleCount>0) {
    for (i=0;i<count;i++)
      temp[i] = cards[i];
    i=0;
    splitPos = count/2+random(10)-5;
    j = splitPos;
    k=0;
    while ((i<splitPos)&&(j<count)) {
      if (random(2))
        cards[k++]=temp[i++];
      else
        cards[k++]=temp[j++];
    }
    while (i<splitPos)
      cards[k++]=temp[i++];
    while (j<count)
      cards[k++]=temp[j++];
    shuffleCount--;
  }
}

void TDeck::Cut(int cutPosition) {
  TCard *temp[52];
  int i,count = GetCount();
  int check[52];
  char tempstr[30];

  assert(cutPosition < count);

  wsprintf(tempstr,"cutpos = %d, deck size = %d",cutPosition,count);
  ::MessageBox(0,tempstr,"info",MB_OK);

  for (i=0;i<52;i++) {
    temp[i]=0;
    check[i]=0;
  }

  for (i=0;i<count;i++) {
    temp[i]=cards[i];
    check[cards[i]->suit*13+cards[i]->rank-1]++;
  }

  for (i=cutPosition+1;i<count;i++)
    cards[i-(cutPosition+1)]=temp[i];
  for (i=0;i<=cutPosition;i++)
    cards[cutPosition+i+1]=temp[i];

  for (i=0;i<count;i++) {
    check[cards[i]->suit*13+cards[i]->rank-1]--;
  }

  for (i=0;i<52;i++)
    if (check[i]!=0)
      ::MessageBox(0, "Cut failed.","Error",MB_OK);
}

void TDeck::ResetBackStyle(int newBackStyle) {
  int i,count = GetMaxCards();
  for (i=0;i<count;i++)
    cards[i]->backStyle = newBackStyle;
}

const char *TDeck::EncodeDeck() {
  static char encodedDeck[53];

  int temp,i;

  for (i=0;i<52;i++) {
    temp = cards[i]->rank | (cards[i]->suit<<4);
    encodedDeck[i] = char(temp+'0');
  }
  encodedDeck[52]=0;
  return encodedDeck;
}

BOOL TDeck::DecodeDeck(const char *encodedDeck) {
  int rank,suit,i,j,temp;
  int check[4][13];              // used to validate deck

  for (i=0;i<4;i++)
    for (j=0;j<13;j++)
      check[i][j]=0;

  for (i=0;i<52;i++) {
    temp = encodedDeck[i]-'0';
    rank = temp & 0x0f;
    suit = temp >> 4;
    check[suit][rank-1]++;
    cards[i]->rank = rank;
    cards[i]->suit = suit;
  }

  for (i=0;i<4;i++)              // make sure we have 1 of each card
    for (j=0;j<13;j++)
      if (check[i][j]!=1)
        return false;            // if not, return
  return true;
}


