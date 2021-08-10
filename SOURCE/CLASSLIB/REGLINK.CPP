//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/registry.h>
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
