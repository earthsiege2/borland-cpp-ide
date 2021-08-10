//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBGroupBox.  This defines the basic behavior
//   for all custom control group boxes.
//----------------------------------------------------------------------------
#ifndef __BGRPBOX_H
#define __BGRPBOX_H

#ifndef __GROUPBOX_H
  #include <owl\groupbox.h>
#endif

//
//  class TBGroupBox
//  ----- ----------
//
class _EXPCLASS TBGroupBox : public TGroupBox {
  public:
    TBGroupBox(TWindow*        parent,
               int             id,
               const char far* text,
               int x, int y, int w, int h,
               TModule*        module = 0);

    TBGroupBox(TWindow* parent, int resourceId, TModule* module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(_EXPCLASS, TBGroupBox, TGroupBox);
};

#endif //__BGRPBOX_H
