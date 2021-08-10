//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.12  $
//
// TRegItem and TRegList members that need to be linked into user app and not
// the WinSys DLL
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/registry.h>
#include <stdio.h>   // sprintf()
#include <tchar.h>

//
// Initialize the data members to 0.
//
TRegFormatHeap::TRegFormatHeap()
:
  Head(0)
{
}

//
// Walk the heap chain & delete the memory blocks
//
TRegFormatHeap::~TRegFormatHeap()
{
  while (Head) {
    TBlock* next = Head->Next;
    delete[] (_TCHAR*)Head;
    Head = next;
  }
}

//
// Allocate a block of memory of a given size & link it into the heap chain
//
_TCHAR* TRegFormatHeap::Alloc(int spaceNeeded)
{
  TBlock* newblock = (TBlock*) new _TCHAR[sizeof(TBlock) + spaceNeeded];
  newblock->Next = Head;
  Head = newblock;

  return newblock->Data;
}

//
// Lookup the key and return the associated value.
// Returns an empty string if there is no associated value.
// If the key does not exist, it returns a null pointer.
//
const _TCHAR* TRegList::Lookup(const _TCHAR* key, TLangId lang)
{
  if (key) {
    for (TRegItem* regItem = Items; regItem->Key != 0; regItem++) {
      if (_tcscmp(regItem->Key, key) == 0)
        if (regItem->Value.Private)  // current can't test Value directly
          return regItem->Value.Translate(lang);
        else
          return "";
    }
  }
  return 0;
}

//
//
// Return a reference to the locale string object associated with the key.
//
TLocaleString& TRegList::LookupRef(const _TCHAR* key)
{
  for (TRegItem* regItem = Items; regItem->Key != 0; regItem++) {
    if (_tcscmp(regItem->Key, key) == 0)
       return regItem->Value;
  }
  return TLocaleString::Null;
}

//
// Maximum string length for REGFORMAT w/ string arg. String is clipped if too
// long.
//
const int MaxFormatLen = 40;

//
// Register data formats for the object.
//
//
_TCHAR* TRegItem::RegFormat(int f, int a, int t, int d, TRegFormatHeap& heap)
{
  // sprintf into sized auto buffer
  // ints have a max of 11 digits: -2000000000. Add pad of 8 just in case
  //
  _TCHAR temp[11+1+11+1+11+1+11+1+8];
  int len = _stprintf(temp, "%d,%d,%d,%d", f, a, t, d);

  // Copy into real heap buffer & return it
  //
  return _tcscpy(heap.Alloc(len + 1), temp);
}

//
//
// Register data formats for the object.
//
_TCHAR* TRegItem::RegFormat(const _TCHAR* f, int a, int t, int d, TRegFormatHeap& heap)
{
  // sprintf into sized auto buffer
  //
  _TCHAR temp[MaxFormatLen+1+11+1+11+1+11+1+8];
  int len = _stprintf(temp, "%.*s,%d,%d,%d", MaxFormatLen, (_TCHAR far*)f, a, t, d);

  // Copy into real heap buffer & return it
  //
  return _tcscpy(heap.Alloc(len + 1), temp);
}

//
// Register the flag.
//
//
_TCHAR* TRegItem::RegFlags(long flags, TRegFormatHeap& heap)
{
  // sprintf into sized auto buffer
  //
  _TCHAR temp[11+1+8];
  int len = _stprintf(temp, "%ld", flags);

  // Copy into real heap buffer & return it
  //
  return _tcscpy(heap.Alloc(len + 1), temp);
}

//
// Register the verb option.
//
//
_TCHAR* TRegItem::RegVerbOpt(int mf, int sf, TRegFormatHeap& heap)
{
  // sprintf into sized auto buffer
  //
  _TCHAR temp[11+1+11+1+8];
  int len = _stprintf(temp, "%d,%d", mf, sf);

  // Copy into real heap buffer & return it
  //
  return _tcscpy(heap.Alloc(len + 1), temp);
}
