//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Definition of class TRadioButton.  This defines the basic behavior for all
// radio buttons.
//----------------------------------------------------------------------------
#if !defined(OWL_RADIOBUT_H)
#define OWL_RADIOBUT_H

#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TRadioButton
// ~~~~~ ~~~~~~~~~~~~
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
    // Child id notification handled at the child
    //
    void       BNClicked();  // BN_CLICKED
    char far*  GetClassName();

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TRadioButton(const TRadioButton&);
    TRadioButton& operator=(const TRadioButton&);
      
  DECLARE_RESPONSE_TABLE(TRadioButton);
  DECLARE_STREAMABLE(_OWLCLASS, TRadioButton, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_RADIOBUT_H
