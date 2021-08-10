//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBRadioButton.  This defines the basic behavior
//   for all Borland custom radio buttons.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "owl\groupbox.h"
#include "bradio.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBRadioButton, TRadioButton);

//
// constructor for a TBRadioButton object
//
TBRadioButton::TBRadioButton(TWindow*        parent,
                             int             id,
                             const char far* title,
                             int x, int y, int w, int h,
                             TGroupBox*      group,
                             TModule*        module)
  : TRadioButton(parent, id, title, x, y, w, h, group, module)
{
}

TBRadioButton::TBRadioButton(TWindow*   parent,
                             int        resourceId,
                             TGroupBox* group,
                             TModule*   module)
  : TRadioButton(parent, resourceId, group, module)
{
}

char far*
TBRadioButton::GetClassName()
{
  return RADIO_CLASS;
}
