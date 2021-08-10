//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBCheckBox.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "owl\groupbox.h"
#include "bchkbox.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBCheckBox, TCheckBox);

//
// constructor for a TBCheckBox object
//
TBCheckBox::TBCheckBox(TWindow*        parent,
                       int             id,
                       const char far* title,
                       int x, int y, int w, int h,
                       TGroupBox*      group,
                       TModule*        module)
  : TCheckBox(parent, id, title, x, y, w, h, group, module)
{
}

//
// constructor for a TBCheckBox to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
TBCheckBox::TBCheckBox(TWindow*   parent,
                       int        resourceId,
                       TGroupBox* group,
                       TModule*   module)
  : TCheckBox(parent, resourceId, group, module)
{
}

char far*
TBCheckBox::GetClassName()
{
  return CHECK_CLASS;
}
