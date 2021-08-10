//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
// Implementation of color classes
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/color.h>
#include <winsys/system.h>

static bool
isWin31() 
{
#if   defined(BI_PLAT_WIN16)
  return !TSystem::IsWin95() && !TSystem::IsWoW();
#elif defined(BI_PLAT_WIN32)
  return !TSystem::IsWin95() && !TSystem::IsNT();
#else
  return false;
#endif
}

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
// Special marker colors using flag bit pattern. Value never really used.
// Value must not change for streaming compatibility w/ OWL's TWindow
//
const TColor TColor::None(0xFF000000l);
const TColor TColor::Transparent(0xFE000000l);

//
// Symbolic system colors looked up on evaluation or conversion
//
#define Symbolic 0x80000000UL
const TColor TColor::SysScrollbar(Symbolic | 0);
const TColor TColor::SysDesktop(Symbolic | 1);
const TColor TColor::SysActiveCaption(Symbolic | 2);
const TColor TColor::SysInactiveCaption(Symbolic | 3);
const TColor TColor::SysMenu(Symbolic | 4);
const TColor TColor::SysWindow(Symbolic | 5);
const TColor TColor::SysWindowFrame(Symbolic | 6);
const TColor TColor::SysMenuText(Symbolic | 7);
const TColor TColor::SysWindowText(Symbolic | 8);
const TColor TColor::SysCaptionText(Symbolic | 9);
const TColor TColor::SysActiveBorder(Symbolic | 10);
const TColor TColor::SysInactiveBorder(Symbolic | 11);
const TColor TColor::SysAppWorkspace(Symbolic | 12);
const TColor TColor::SysHighlight(Symbolic | 13);
const TColor TColor::SysHighlightText(Symbolic | 14);
const TColor TColor::Sys3dFace(Symbolic | 15);
const TColor TColor::Sys3dShadow(Symbolic | 16);
const TColor TColor::SysGrayText(Symbolic | 17);
const TColor TColor::SysBtnText(Symbolic | 18);
const TColor TColor::SysInactiveCaptionText(Symbolic | 19);
const TColor TColor::Sys3dHilight(Symbolic | 20);
const TColor TColor::Sys3dDkShadow(isWin31() ? (Symbolic | 6) : (Symbolic | 21));
const TColor TColor::Sys3dLight(isWin31() ? (Symbolic | 15) : (Symbolic | 22));
const TColor TColor::SysInfoText(isWin31() ? MkRGB(0,0,0) : (Symbolic | 23));
const TColor TColor::SysInfoBk(isWin31() ? MkRGB(255,255,128) : (Symbolic | 24));

//
// Convert a bit count into a color count for color table use, verifying that
// the bit count is one that is supported by Windows, ie 1, 4, 8, 16, 24, 32.
//
// If the bit count is not supported, -1 is returned.
//
long _WSYSFUNC
NColors(uint16 bitCount)
{
  if (bitCount == 1 || bitCount == 4 || bitCount == 8)
    return 1 << bitCount;
  if (bitCount == 16 || bitCount == 24 || bitCount == 32)
    return 0;
  return -1;
}

//
// Return the number of bits required to represent a given number of colors
//
uint16 _WSYSFUNC
NBits(long colors)
{
  if (colors <= 2)
    return 1;
  if (colors <= 16)
    return 4;
  if (colors <= 256)
    return 8;
  if (colors <= 65536L)
    return 16;
  return 24;
}

//
// Get a 32bit COLORREF type from this color object. Performs a
// GetSysColor() lookup if the object represents a symbolic sys-color index.
//
COLORREF
TColor::GetValue() const
{
#if defined(BI_PLAT_MSW)
  return IsSysColor() ? ::GetSysColor(Index()) : Value;
#else
  return Value;
#endif
}

//
// Return the color's red component
//
uint8
TColor::Red() const
{
  return (uint8)(uint16)GetValue();
}

//
// Return the color's green component
//
uint8
TColor::Green() const
{
  return (uint8)(uint16)(((uint16)GetValue()) >> 8);
}

//
// Return the color's blue component
//
uint8
TColor::Blue() const
{
  return (uint8)(uint16)(GetValue()>>16);
}
