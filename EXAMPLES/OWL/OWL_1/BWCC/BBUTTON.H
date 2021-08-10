//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBButton.  This defines custom control push button
//----------------------------------------------------------------------------
#ifndef __BBUTTON_H
#define __BBUTTON_H

#ifndef __BUTTON_H
  #include <owl\button.h>
#endif

//
//  class TBButton
//  ----- --------
//
class _EXPCLASS TBButton : public TButton {
  public:
    TBButton(TWindow*        parent,
             int             id,
             const char far* text,
             int x, int y, int w, int h,
             BOOL            isDefault,
             TModule*        module = 0);

    TBButton(TWindow* parent, int resourceId, TModule* module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(_EXPCLASS, TBButton, TButton);
};

#endif //__BBUTTON_H
