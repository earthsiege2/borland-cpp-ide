//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\color.cpp
//   Implementation of color classes
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\color.h>

const TColor TColor::Black(0, 0, 0);         // 0
const TColor TColor::LtGray(192, 192, 192);  // 7
const TColor TColor::Gray(128, 128, 128);    // 8
const TColor TColor::LtRed(255, 0, 0);       // 9
const TColor TColor::LtGreen(0, 255, 0);     // 10
const TColor TColor::LtYellow(255, 255, 0);  // 11
const TColor TColor::LtBlue(0, 0, 255);      // 12
const TColor TColor::LtMagenta(255, 0, 255); // 13
const TColor TColor::LtCyan(0, 255, 255);    // 14
const TColor TColor::White(255, 255, 255);   // 15

//
// These routines converts bit count into a color count and vice versa
// They also verify that the bit count is one that is supported by windows,
// ie 1, 4, 8, and 24.  If the bit count is not supported, it returns -1
//
long _OWLFUNC
NColors(WORD bitCount)
{
  if (bitCount == 1 || bitCount == 4 || bitCount == 8)
    return 1 << bitCount;
  else if (bitCount == 24)
    return 0;
  return -1;
}

WORD _OWLFUNC
NBits(long colors)
{
  if (colors <= 2)
    return 1;
  else if (colors <= 16)
    return 4;
  else if (colors <= 256)
    return 8;
  return 24;
}
