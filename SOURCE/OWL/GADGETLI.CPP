//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of class TGadgetList, the base for classes that own gadgets
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

//
// Return the gadget that a given window-relative point is in, 0 if none found
//
TGadget*
TGadgetList::GadgetFromPoint(TPoint& point) const
{
  TGadget* gadget = Gadgets;
  for (; gadget; gadget = gadget->Next)
    if (gadget->PtIn(point - *(TSize*)&gadget->Bounds.TopLeft()))
      break;

  return gadget;
}

//
// Return the gadget with a given Id, 0 if none found.
//
TGadget*
TGadgetList::GadgetWithId(int id) const
{
  for (TGadget* g = Gadgets; g; g = g->NextGadget())
    if (g->GetId() == id)
      return g;
  return 0;
}

//
// Return gadget at a given index.
//
TGadget*
TGadgetList::operator [](uint index)
{
  PRECONDITION(index < NumGadgets);

  TGadget* g;
  for (g = FirstGadget(); index > 0; index--)
    g = NextGadget(*g);
  return g;
}

//
// Insert a Gadget. You can specify a sibling Gadget that the new Gadget
// is to be inserted before or after
//
// If "sibling" is 0 then the new Gadget is inserted at the beginning or
// the end. The default is to insert the new Gadget at the end
//
void
TGadgetList::Insert(TGadget& gadget, TPlacement placement, TGadget* sibling)
{
  PRECONDITION(!gadget.Window);  // Would cause problems if still in a window

  TGadget**  g = &Gadgets;

  // Locate spot to insert gadget
  //
  if (sibling || placement == After) {
    while (*g && *g != sibling)
      g = &(*g)->Next;

    CHECK(*g == sibling);
  }
  if (placement == After && *g)
    g = &(*g)->Next;

  // Link supplied gadget into this list
  //
  gadget.Next = *g;
  *g = &gadget;

  // Update count
  //
  NumGadgets++;

  Inserted(gadget);
}

//
// Insert a list of Gadget. Gadgets are removed from the source list
//
void
TGadgetList::InsertFrom(TGadgetList& list, TPlacement placement, TGadget* sibling)
{
  if (!list.Gadgets)
    return;

  TGadget**  g = &Gadgets;

  // Locate spot to insert gadgets
  //
  if (sibling || placement == After) {
    while (*g && *g != sibling)
      g = &(*g)->Next;

    CHECK(*g == sibling);
  }
  if (placement == After && *g)
    g = &(*g)->Next;

  // Find tail of list. Let the source list & this list know about the transfer
  // as we go.
  //
  TGadget* last;
  for (last = list.Gadgets; last->Next; last++) {
    list.Removed(*last);
    Inserted(*last);
  }

  // Link supplied list into this list
  //
  last->Next = *g;
  *g = list.Gadgets;

  // Update counts & source list pointer
  //
  NumGadgets += list.NumGadgets;
  list.Gadgets = 0;
  list.NumGadgets = 0;
}

//
// Removes (unlinks) a gadget from this gadget window. The gadget is
// returned but not destroyed. Returns 0 if gadget is not in this window
//
TGadget*
TGadgetList::Remove(TGadget& gadget)
{
  if (!Gadgets)
    return 0;

  // Handle head-of-list case
  //
  if (&gadget == Gadgets) {
    Gadgets = Gadgets->Next;
  }
  // Scan for gadget, looking one link ahead
  //
  else {
    TGadget* g = Gadgets;

    while (g->Next && g->Next != &gadget)
      g = g->Next;

    if (!g->Next)   // not found
      return 0;

    g->Next = g->Next->Next;
  }

  NumGadgets--;

  Removed(gadget);

  return &gadget;
}

//
// A gadget has been inserted. Derived class can override this to update
// internals
//
void
TGadgetList::Inserted(TGadget& /*gadget*/)
{
}

//
// A gadget has been removed. Derived class can override this to update
// internals
//
void
TGadgetList::Removed(TGadget& /*gadget*/)
{
}
