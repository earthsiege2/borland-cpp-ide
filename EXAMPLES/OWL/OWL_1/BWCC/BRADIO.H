//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBRadioButton.  This defines the basic behavior
//   for all Borland custom radio buttons.
//----------------------------------------------------------------------------
#ifndef __BRADIO_H
#define __BRADIO_H

#ifndef __RADIOBUT_H
  #include <owl\radiobut.h>
#endif

//
//  class TBRadioButton
//  ----- -------------
//
class _EXPCLASS TBRadioButton : public TRadioButton {
  public:
    TBRadioButton(TWindow*        parent,
                  int             id,
                  const char far* title,
                  int x, int y, int w, int h,
                  TGroupBox*      group,
                  TModule*        module = 0);

    TBRadioButton(TWindow*   parent,
                  int        resourceId,
                  TGroupBox* group,
                  TModule*   module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(_EXPCLASS, TBRadioButton, TRadioButton);
};

#endif //__BRADIO_H
