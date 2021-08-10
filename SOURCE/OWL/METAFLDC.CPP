//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of DC encapsulation classes
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

TMetaFileDC::TMetaFileDC(const char far* filename)
:
  TDC()
{
  Handle = ::CreateMetaFile(filename);
  CheckValid();
}

TMetaFileDC::~TMetaFileDC()
{
  if (Handle) {
    if (ShouldDelete)
      // Do not restore objects, Metafiles cleanup after themselves
      ::DeleteMetaFile(Close());
    Handle = 0;
  }
}
