//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Defines class TCheckBox.  This defines the basic behavior
//   for all check boxes.
//----------------------------------------------------------------------------
#if !defined(OWL_CHECKBOX_H)
#define OWL_CHECKBOX_H

#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif

class _OWLCLASS TGroupBox;

//
// Checkbox flags indicating check state
//
enum {
  BF_CHECKED   = 0x01,
  BF_GRAYED    = 0x02,
  BF_UNCHECKED = 0x0
};

//
//  class TCheckBox
//  ----- ---------
//
class _OWLCLASS TCheckBox : public TButton {
  public:
    TGroupBox*  Group;

    TCheckBox(TWindow*        parent,
              int             id,
              const char far* title,
              int x, int y, int w, int h,
              TGroupBox*      group = 0,
              TModule*        module = 0);

    TCheckBox(TWindow*   parent,
              int        resourceId,
              TGroupBox* group = 0,
              TModule*   module = 0);

    void       Check() {SetCheck(BF_CHECKED);}
    void       Uncheck() {SetCheck(BF_UNCHECKED);}
    void       Toggle();

    uint       GetCheck() const;
    void       SetCheck(uint check);

    uint       GetState() const;
    void       SetState(uint state) {SendMessage(BM_SETSTATE, state);}

    void       SetStyle(uint style, bool redraw);

    //
    // Override TWindow virtual member functions
    //
    uint       Transfer(void* buffer, TTransferDirection direction);

  protected:
    //
    //  override TButton's processing so drawable check boxes and radio
    //  buttons work properly
    //
    uint       EvGetDlgCode(MSG far*) {return (uint)DefaultProcessing();}

    //
    // child id notification
    //
    void       BNClicked();  // BN_CLICKED

    char far*  GetClassName();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TCheckBox(const TCheckBox&);
    TCheckBox& operator =(const TCheckBox&);

  DECLARE_RESPONSE_TABLE(TCheckBox);
  DECLARE_STREAMABLE(_OWLCLASS, TCheckBox, 1);
};

inline uint TCheckBox::GetCheck() const {
  return (uint)CONST_CAST(TCheckBox*, this)->SendMessage(BM_GETCHECK);
}

inline uint TCheckBox::GetState() const {
  return (uint)CONST_CAST(TCheckBox*, this)->SendMessage(BM_GETSTATE);
}

inline void TCheckBox::SetStyle(uint style, bool redraw) {
  SendMessage(BM_SETSTYLE, style, MAKELPARAM(redraw,0));
}

#endif  // OWL_CHECKBOX_H
