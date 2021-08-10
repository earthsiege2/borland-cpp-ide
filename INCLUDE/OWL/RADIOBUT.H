//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\radiobut.h
//   Defines class TRadioButton.  This defines the basic behavior
//   for all radio buttons.
//----------------------------------------------------------------------------
#if !defined(__OWL_RADIOBUT_H)
#define __OWL_RADIOBUT_H

#if !defined(__OWL_CHECKBOX_H)
  #include <owl\checkbox.h>
#endif

//
//  class TRadioButton
//  ----- ------------
//
class _OWLCLASS TRadioButton : public TCheckBox {
  public:
    TRadioButton(TWindow*        parent,
                 int             id,
                 const char far* title,
                 int x, int y, int w, int h,
                 TGroupBox*      group = 0,
                 TModule*        module = 0);

    TRadioButton(TWindow*   parent,
                 int        resourceId,
                 TGroupBox* group = 0,
                 TModule*   module = 0);

  protected:
    //
    // child id notification handled at the child
    //
    void       BNClicked();  // BN_CLICKED

    char far*  GetClassName();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TRadioButton(const TRadioButton&);
    TRadioButton& operator=(const TRadioButton&);
      
  DECLARE_RESPONSE_TABLE(TRadioButton);
  DECLARE_STREAMABLE(_OWLCLASS, TRadioButton, 1);
};

#endif  // __OWL_RADIOBUT_H
