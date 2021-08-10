//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBStaticBmp.  This is a static control that draws
//   a bitmap
//----------------------------------------------------------------------------
#ifndef __BSTATBMP_H
#define __BSTATBMP_H

#ifndef __CONTROL_H
  #include <owl\control.h>
#endif

//
//  class TBStaticBmp
//  ----- -----------
//
class  TBStaticBmp : public TControl {
  public:
    TBStaticBmp(TWindow*        parent,
                int             id,
                const char far* text,
                int x, int y, int w, int h,
                TModule*        module = 0);

    TBStaticBmp(TWindow* parent, int resourceId, TModule* module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(, TBStaticBmp, TControl);
};

#endif //__BSTATBMP_H
