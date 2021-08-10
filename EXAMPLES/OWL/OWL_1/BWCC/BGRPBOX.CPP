//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBGroupBox.  This defines the basic behavior
//   for all custom control group boxes.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bgrpbox.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBGroupBox, TGroupBox);

//
// constructor for a TBGroupBox object
//
TBGroupBox::TBGroupBox(TWindow*        parent,
                       int             id,
                       const char far* text,
                       int x, int y, int w, int h,
                       TModule*        module)
  : TGroupBox(parent, id, text, x, y, w, h, module)
{
  Attr.Style = (Attr.Style & ~BS_GROUPBOX) | BSS_GROUP;
}

//
// constructor for a TBGroupBox to be associated with a MS-Windows interface
// element created by MS-Windows from a resource definition
//
TBGroupBox::TBGroupBox(TWindow* parent,
                       int      resourceId,
                       TModule* module)
  : TGroupBox(parent, resourceId, module)
{
}

char far*
TBGroupBox::GetClassName()
{
  return SHADE_CLASS;
}
