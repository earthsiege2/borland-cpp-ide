//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Defines class TBStatic.  This defines the basic behavior of BWCC static
//   controls
//----------------------------------------------------------------------------
#ifndef __BSTATIC_H
#define __BSTATIC_H

#ifndef __STATIC_H
  #include <owl\static.h>
#endif

//
//  class TBStatic
//  ----- --------
//
class  TBStatic : public TStatic {
  public:
    TBStatic(TWindow*        parent,
             int             id,
             const char far* title,
             int x, int y, int w, int h,
             UINT            TextLen,
             TModule*        module = 0);

    TBStatic(TWindow* parent,
             int      resourceId,
             UINT     textLen,
             TModule* module = 0);

  protected:
    char far* GetClassName();

  DECLARE_STREAMABLE_FROM_BASE(, TBStatic, TStatic);
};

#endif //__BSTATIC_H
