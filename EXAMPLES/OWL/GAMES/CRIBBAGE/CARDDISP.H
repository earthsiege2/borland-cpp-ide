//--------------------------------------------------------------------------
// Turbo Cribbage -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#ifndef CARDDISP_H
#define CARDDISP_H

#include <owl/window.h>
#include <owl/vbxctl.h>
#include "mhcd2001.h"
#include "cards.h"
#include "cribbage.rh"

//  WM_CARD_SELECTED is sent to the parent of a TCardDisplay, when
//  a card is selected.
//
//  wparam = the id of the card display clicked on
//  lparam = the index of the card clicked on
//
#define WM_CARD_SELECTED  WM_USER+1

// class TCardDisplay -- derived from TCardGroup, and TWindow.  It is a
// card group which can be displayed as a control in a window.
//
class TCardDisplay: public TWindow, public TCardGroup {
  public:
    TCardDisplay(TWindow* parent, int aId, int x, int y, int w, int h,
                 int aBorderSize,
                 int aMaxCards, TPoint *cardPositions, BOOL aRectangle = false,
                 const char *aLabel = 0, TPoint aLabelPos = TPoint(0,0));
    ~TCardDisplay() {
      delete[] cardPos;
      delete[] cardvbx;
    }
    void Paint(TDC&, bool, TRect&);
    void SetupWindow();
    void FaceUp(int index, BOOL faceUp) {
      cards[index]->faceUp = faceUp;
      Show(index, cards[index]);
    }
    void SetCardPosition(int index, TPoint& pos) {
      cardPos[index]=pos;
      cardvbx[index]->MoveWindow(pos.x, pos.y, 71, 95);
    }
    void Show(int index, TCard* card) {
      cardvbx[index]->SetPropCardBack(ENUM(card->backStyle));
      if (card->faceUp)
        cardvbx[index]->SetPropValue(ENUM(card->rank));
      else
        cardvbx[index]->SetPropValue(0);
      cardvbx[index]->SetPropSuit(ENUM(card->suit));
      cardvbx[index]->ShowWindow(SW_SHOW);
    }
    void SetLabel(const char *text) {
      strncpy(label, text, 20);
      label[19]=0;
      Invalidate();
    }
    int Insert(TCard* card, BOOL faceUp) {
      assert(card!=0);
      card->faceUp = faceUp;
      int index = TCardGroup::Insert(card);
      Show(index, card);
      return index;
    }
    TCard* Remove(int pos=0);
    TCard& operator[](int index) {
      return *cards[index];
    }
    LRESULT VBXEventHandler(WPARAM wparam, LPARAM lparam) {
      VBXEVENT FAR *vbxEvent = (VBXEVENT FAR *)lparam;
      if (vbxEvent->EventIndex == Event_MhCardDeck_Click)
        Parent->PostMessage(WM_CARD_SELECTED, id, vbxEvent->ID);
      return true;
    }

  private:
    TVbxMhCardDeck** cardvbx;
    BOOL   rectangle;
    char   label[20];
    TPoint labelPos;
    int    borderSize;
    TPoint*cardPos;
    int    id;

  DECLARE_RESPONSE_TABLE(TCardDisplay);
};

#endif // CARDDISP_H
