//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TMenuDescr
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/menu.h>
#include <owl/module.h>

#if !defined(SECTION) || SECTION == 1

//
// Construct a default, empty menu descriptor
//
TMenuDescr::TMenuDescr()
:
  TMenu()
{
  Id = 0;
  Module = ::Module;
  for (int i = 0; i < NumGroups; i++)
    GroupCount[i] = 0;
}

//
// Construct a menu descriptor from an existing one
//
TMenuDescr::TMenuDescr(const TMenuDescr& other)
:
  TMenu(other)
{
  Id = other.Id;
  Module = other.Module;
  for (int i = 0; i < NumGroups; i++)
    GroupCount[i] = other.GroupCount[i];
}

//
// Construct a menu descriptor from a normal menu resource, supplying group
// counts here. If the resource has seperators, use those instead of the counts
//
TMenuDescr::TMenuDescr(TResId id,
                       int fg, int eg, int cg, int og, int wg, int hg,
                       TModule* module)
:
  TMenu(*module, id),
  Module(module),
  Id(id)
{
  if (!ExtractGroups()) {
    GroupCount[FileGroup] = fg;
    GroupCount[EditGroup] = eg;
    GroupCount[ContainerGroup] = cg;
    GroupCount[ObjectGroup] = og;
    GroupCount[WindowGroup] = wg;
    GroupCount[HelpGroup] = hg;
  }
}

//
// Construct a menu descriptor from a menu resource with group separators
// built in (using MF_SEPARATOR)
//
TMenuDescr::TMenuDescr(TResId id, TModule* module)
:
  TMenu(*module, id),
  Module(module),
  Id(id)
{
  ExtractGroups();
}

//
// Construct a menu descriptor that is an alias for an existing menu with group
// information. If the menu has seperators, use those instead of the counts
//
TMenuDescr::TMenuDescr(HMENU hMenu,
                       int fg, int eg, int cg, int og, int wg, int hg,
                       TModule* module)
:
  TMenu(hMenu, NoAutoDelete),
  Module(module)
{
  if (!ExtractGroups()) {
    GroupCount[FileGroup] = fg;
    GroupCount[EditGroup] = eg;
    GroupCount[ContainerGroup] = cg;
    GroupCount[ObjectGroup] = og;
    GroupCount[WindowGroup] = wg;
    GroupCount[HelpGroup] = hg;
  }
}

//
// destructor
//
TMenuDescr::~TMenuDescr()
{
}

//
// Assign another menu descriptor on to this one
//
TMenuDescr&
TMenuDescr::operator =(const TMenuDescr& other)
{
  *static_cast<TMenu*>(this) = *static_cast<const TMenu*>(&other);
  Id = other.Id;
  Module = other.Module;
  for (int i = 0; i < NumGroups; i++)
    GroupCount[i] = other.GroupCount[i];
  return *this;
}

//
// Scan menu looking for separators that signify group divisions
// return whether we found any at all
//
bool
TMenuDescr::ExtractGroups()
{
  if (!Handle)
    return false;  // no menu to extract from...

  // walk menu & remove separators, setting up count as we go.
  //
  int itemCount = GetMenuItemCount();
  int g = 0;
  int count = 0;
  for (int i = 0; i < itemCount; ) {
    uint s = GetMenuState(i, MF_BYPOSITION);
    if ((s & MF_SEPARATOR) && !(s & MF_POPUP)) {
      if (g < NumGroups)
        GroupCount[g++] = count;
      count = 0;
      RemoveMenu(i, MF_BYPOSITION);
      itemCount--;
    }
    else {
      i++;
      count++;
    }
  }
  // Leave if no separators were found
  //
  if (!g)
    return false;

  // Get trailing group
  //
  if (g < NumGroups)
    GroupCount[g++] = count;

  // Finish zeroing groups
  //
  for (; g < NumGroups; g++)
    GroupCount[g] = 0;
  return true;
}

//
// Merge another menu descriptor into this menu descriptor
// Popups are DeepCopied and are then owned by this menu
// Group counts are merged too.
//
bool
TMenuDescr::Merge(const TMenuDescr& srcMenuDescr)
{
  int thisOffset = 0;
  int srcOffset = 0;

  for (int i = 0; i < NumGroups; i++) {
    if (srcMenuDescr.GroupCount[i] != 0) {
      // Delete same menu group in the dest. menudescr.
      for (int j = GroupCount[i] - 1; j >= 0; j--) {
        DeleteMenu(thisOffset+j, MF_BYPOSITION);
      }
      GroupCount[i] = 0;

      if (srcMenuDescr.GroupCount[i] > 0) {
        DeepCopy(*this, thisOffset, srcMenuDescr, srcOffset, srcMenuDescr.GroupCount[i]);
        srcOffset += srcMenuDescr.GroupCount[i];
        GroupCount[i] += srcMenuDescr.GroupCount[i];
      }
    }

    if (GroupCount[i] > 0)
      thisOffset += GroupCount[i];
  }
  return true;
}

//
// Merge another menu descriptor, with this menu descriptor into a third menu
// Popups are DeepCopied and are then owned by the destMenu.
//
bool
TMenuDescr::Merge(const TMenuDescr& srcMenuDescr, TMenu& dstMenu)
{
  int thisOffset = 0;
  int srcOffset = 0;

  for (int i = 0; i < NumGroups; i++) {
    if (srcMenuDescr.GroupCount[i] > 0) {
      DeepCopy(dstMenu, srcMenuDescr, srcOffset, srcMenuDescr.GroupCount[i]);
      srcOffset += srcMenuDescr.GroupCount[i];
    }
    else if (srcMenuDescr.GroupCount[i] == 0 && GroupCount[i] > 0) {
      DeepCopy(dstMenu, *this, thisOffset, GroupCount[i]);
    }
    // else don't copy either

    if (GroupCount[i] > 0)
      thisOffset += GroupCount[i];
  }
  return true;
}

#endif
#if !defined(SECTION) || SECTION == 2

ipstream& _OWLFUNC
operator >>(ipstream& is, TMenuDescr& m)
{
  is >> m.Id;
  is >> m.Module;
  for (int i = 0; i < TMenuDescr::NumGroups; i++)
    is >> m.GroupCount[i];
  return is;
}

opstream& _OWLFUNC
operator <<(opstream& os, const TMenuDescr& m)
{
  os << m.Id;
  os << m.Module;
  for (int i = 0; i < TMenuDescr::NumGroups; i++)
    os << m.GroupCount[i];
  return os;
}


#endif
