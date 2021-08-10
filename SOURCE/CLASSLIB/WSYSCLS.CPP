//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Implementation of window system structure and type encapsulation
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/wsyscls.h>
#include <services/memory.h>

//
// Drag / Drop support
//
TFileDroplet::TFileDroplet(const _TCHAR* fileName, TPoint& p, bool inClient)
:
  FileName(strnewdup(fileName)),
  Point(p),
  InClientArea(inClient)
{
}

//
// Construct a TFileDroplet given a DropInfo and a file index
//
// The location is relative to the client coordinates, and will have negative
// values if dropped in the non client partsof the window.
//
// DragQueryPoint copies that point where the file was dropped and returns
// whether or not the point is in the client area.  Regardless of whether or
// not the file is dropped in the client or non-client area of the window,
// you will still receive the file name.
//
TFileDroplet::TFileDroplet(TDropInfo& drop, int i)
{
  // Tell DragQueryFile the file wanted (i) and the length of the buffer.
  //
  int  namelen = drop.DragQueryFileNameLen(i) + 1;
  FileName = new _TCHAR[namelen];

  drop.DragQueryFile(i, FileName, namelen);

  InClientArea = drop.DragQueryPoint(Point);
}

//
// Clean up the new'd filename
//
TFileDroplet::~TFileDroplet()
{
  delete[] FileName;
}
