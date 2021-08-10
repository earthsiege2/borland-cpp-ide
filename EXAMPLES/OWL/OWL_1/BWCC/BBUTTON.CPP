//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBButton.  This defines custom control push
//   button
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bbutton.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBButton, TButton);

//
// constructor for a TBButton object.  initializes its data fields using
// supplied parameters and default values
//
TBButton::TBButton(TWindow*        parent,
                   int             id,
                   const char far* text,
                   int x, int y, int w, int h,
                   BOOL            isDefault,
                   TModule*        module)
  : TButton(parent, id, text, x, y, w, h, isDefault, module)
{
}

//
// constructor for a TBButton to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
TBButton::TBButton(TWindow* parent,
                   int      resourceId,
                   TModule* module)
  : TButton(parent, resourceId, module)
{
}

char far*
TBButton::GetClassName()
{
  return BUTTON_CLASS;
}
