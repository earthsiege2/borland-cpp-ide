//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBDivider.  This is a static control that draws
//   a beveled dividing line
//----------------------------------------------------------------------------
#ifndef __BDIVIDER_H
#define __BDIVIDER_H

#ifndef __CONTROL_H
  #include <owl\control.h>
#endif

//
//  class TBDivider
//  ----- ---------
//
class _EXPCLASS TBDivider : public TControl {
  public:
    TBDivider(TWindow*        parent,
              int             id,
              const char far* text,
              int x, int y, int w, int h,
              BOOL            isVertical,
              BOOL            isBump,
              TModule*        module = 0);

    TBDivider(TWindow* parent, int resourceId, TModule* module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(_EXPCLASS, TBDivider, TControl);
};

#endif //__BDIVIDER_H
