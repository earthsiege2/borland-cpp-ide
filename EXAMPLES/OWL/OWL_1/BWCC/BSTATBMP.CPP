//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementaion of class TBStaticBmp.  This is a static control that draws
//   a bitmap
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bstatbmp.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBStaticBmp, TControl);

//
// constructor for a TBStaticBmp object
//
TBStaticBmp::TBStaticBmp(TWindow*        parent,
                         int             id,
                         const char far* text,
                         int x, int y, int w, int h,
                         TModule*        module)
  : TControl(parent, id, text, x, y, w, h, module)
{
  Attr.Style |= BBS_BITMAP;
  DisableTransfer();
}

//
// constructor for a TBStaticBmp to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition.
//
// disables transfer of state data for the TBStaticBmp
//
TBStaticBmp::TBStaticBmp(TWindow* parent,
                         int      resourceId,
                         TModule* module)
  : TControl(parent, resourceId, module)
{
  DisableTransfer();
}

char far* 
TBStaticBmp::GetClassName()
{
  return BUTTON_CLASS;
}
