//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\menudesc.cpp
//   Implementation of class TMenuDescr
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\framewin.h>

#if !defined(SECTION) || SECTION == 1

TMenuDescr::TMenuDescr()
{
  Id = 0;
  Module = ::Module;
  for (int i = 0; i < NumGroups; i++)
    GroupCount[i] = 0;
}

TMenuDescr::TMenuDescr(TResId id,
                       int fg, int eg, int cg, int og, int wg, int hg,
                       TModule* module) {
  Id = id;
  Module = module;
  GroupCount[FileGroup] = fg;
  GroupCount[EditGroup] = eg;
  GroupCount[ContainerGroup] = cg;
  GroupCount[ObjectGroup] = og;
  GroupCount[WindowGroup] = wg;
  GroupCount[HelpGroup] = hg;
}

#endif
#if !defined(SECTION) || SECTION == 2

ipstream&
operator >>(ipstream& is, TMenuDescr& m)
{
  is >> m.Id;
  is >> m.Module;
  for (int i = 0; i < TMenuDescr::NumGroups; i++)
    is >> m.GroupCount[i];
  return is;
}

opstream&
operator <<(opstream& os, const TMenuDescr& m)
{
  os << m.Id;
  os << m.Module;
  for (int i = 0; i < TMenuDescr::NumGroups; i++)
    os << m.GroupCount[i];
  return os;
}


#endif
