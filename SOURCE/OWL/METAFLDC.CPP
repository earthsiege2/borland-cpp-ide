//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dc.cpp
//   Implementation of DC encapsulation classes
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

TMetaFileDC::TMetaFileDC(const char far* filename) : TDC()
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
