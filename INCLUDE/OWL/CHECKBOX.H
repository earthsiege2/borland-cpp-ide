//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\checkbox.h
//   Defines class TCheckBox.  This defines the basic behavior
//   for all check boxes.
//----------------------------------------------------------------------------
#if !defined(__OWL_CHECKBOX_H)
#define __OWL_CHECKBOX_H

#if !defined(__OWL_BUTTON_H)
  #include <owl\button.h>
#endif

class _OWLCLASS TGroupBox;

//
// Checkbox flags indicating check state
//
enum {BF_CHECKED   = 0x01,
      BF_GRAYED    = 0x02,
      BF_UNCHECKED = 0x0};

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

    UINT       GetCheck() const;
    void       SetCheck(UINT check);

    UINT       GetState() const;
    void       SetState(UINT state) {HandleMessage(BM_SETSTATE, state);}

    void       SetStyle(UINT style, BOOL redraw);

    //
    // Override TWindow virtual member functions
    //
    UINT       Transfer(void* buffer, TTransferDirection direction);

  protected:
    //
    //  override TButton's processing so drawable check boxes and radio
    //  buttons work properly
    //
    UINT       EvGetDlgCode(MSG far*) {return (UINT)DefaultProcessing();}

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

inline UINT TCheckBox::GetCheck() const {
  return (UINT)CONST_CAST(TCheckBox*, this)->HandleMessage(BM_GETCHECK);
}

inline UINT TCheckBox::GetState() const {
  return (UINT)CONST_CAST(TCheckBox*, this)->HandleMessage(BM_GETSTATE);
}

inline void TCheckBox::SetStyle(UINT style, BOOL redraw) {
  HandleMessage(BM_SETSTYLE, style, MAKELPARAM(redraw,0));
}

#endif  // __OWL_CHECKBOX_H
