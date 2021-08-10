//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBStatic.  This defines the basic behavior of
//   BWCC static controls
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bstatic.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBStatic, TStatic);

//
// constructor for a TBStatic object
//
TBStatic::TBStatic(TWindow*        parent,
                   int             id,
                   const char far* title,
                   int x, int y, int w, int h,
                   UINT            textLen,
                   TModule*        module)
  : TStatic(parent, id, title, x, y, w, h, textLen, module)
{
}

//
// constructor for a TBStatic to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition.
//
TBStatic::TBStatic(TWindow* parent,
                   int      resourceId,
                   UINT     textLen,
                   TModule* module)
  : TStatic(parent, resourceId, textLen, module)
{
}

char far* 
TBStatic::GetClassName()
{
  return STATIC_CLASS;
}
