//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBCheckBox.
//----------------------------------------------------------------------------
#ifndef __BCHKBOX_H
#define __BCHKBOX_H

#ifndef __CHECKBOX_H
  #include <owl\checkbox.h>
#endif

class  TGroupBox;

//
//  class TBCheckBox
//  ----- ----------
//
class  TBCheckBox : public TCheckBox {
  public:
    TBCheckBox(TWindow*        parent,
               int             id,
               const char far* title,
               int x, int y, int w, int h,
               TGroupBox*      group,
               TModule*        module = 0);

    TBCheckBox(TWindow*   parent,
               int        resourceId,
               TGroupBox* group,
               TModule*   module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(, TBCheckBox, TCheckBox);
};

#endif //__BCHKBOX_H
