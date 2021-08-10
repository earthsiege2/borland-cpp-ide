//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBDivider.  This is a static control that draws
//   a beveled dividing line
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bdivider.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBDivider, TControl);

//
// constructor for a TBDivider object
//
TBDivider::TBDivider(TWindow*        parent,
                     int             id,
                     const char far* text,
                     int x, int y, int w, int h,
                     BOOL            isVertical,
                     BOOL            isBump,
                     TModule*        module)
  : TControl(parent, id, text, x, y, w, h, module)
{
  if (isVertical)
    Attr.Style |= isBump ? BSS_VBUMP : BSS_VDIP;

  else
    Attr.Style |= isBump ? BSS_HBUMP : BSS_HDIP;
}

//
// constructor for a TBDivider to be associated with a MS-Windows
// interface element created by MS-Windows from a resource definition
//
// disables transfer of state data for the TBDivider
//
TBDivider::TBDivider(TWindow* parent,
                     int      resourceId,
                     TModule* module)
  : TControl(parent, resourceId, module)
{
  DisableTransfer();
}

char far*
TBDivider::GetClassName()
{
  return SHADE_CLASS;
}
