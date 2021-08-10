//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#include <osl/locale.h>
#include <string.h>

//
// Construct a reglink pointing to a reglist, and add to end of list
//
TRegLink::TRegLink(TRegList& regList, TRegLink*& head)
:
  RegList(&regList),
  Next(0)
{
  AddLink(head, *this);
}

//
// Add a new link to the end of the link list
//
void TRegLink::AddLink(TRegLink*& head, TRegLink& newLink)
{
  TRegLink** link = &head;
  while (*link)                 // put new link at end of list
    link = &(*link)->Next;
  *link = &newLink;
}

//
// Remove a link from the link list. Return true if link found & removed
//
bool TRegLink::RemoveLink(TRegLink*& head, TRegLink& remLink)
{
  for (TRegLink** link = &head; *link; link = &(*link)->Next) {
    if (*link == &remLink) {
      *link = (*link)->Next;     // remove from list
      return true;
    }
  }
  return false;
}
