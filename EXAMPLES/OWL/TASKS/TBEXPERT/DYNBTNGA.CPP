//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    dynbtnga.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "TBExpert.h"

TDynamicButtonGadget::TDynamicButtonGadget(const char* pathToDib,
  int id, TType type, bool enabled, TState state, bool sharedGlyph)
:
  TButtonGadget(TResId(id), id, type, enabled, state, sharedGlyph)
{
  PathToDib = strnewdup(pathToDib);
}


TDynamicButtonGadget::~TDynamicButtonGadget()
{
  delete[] PathToDib;
}


TDib*
TDynamicButtonGadget::GetGlyphDib()
{
  TDib* dib = new TDib(PathToDib);
  dib->MapUIColors( TDib::MapFace | TDib::MapText | TDib::MapShadow |
    TDib::MapHighlight );
  return dib;
}

