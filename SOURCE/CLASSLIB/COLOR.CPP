//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.14  $
//
// Implementation of color classes
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/color.h>
#include <winsys/system.h>

// Few constants only defined when WINVER >= 0x0400
//
#if !defined(COLOR_3DDKSHADOW)
# define COLOR_3DDKSHADOW        21
#endif
#if !defined(COLOR_3DLIGHT)
# define COLOR_3DLIGHT           22
#endif
#if !defined(COLOR_INFOTEXT)
# define COLOR_INFOTEXT          23
#endif
#if !defined(COLOR_INFOBK)
# define COLOR_INFOBK            24
#endif

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
const TColor TColor::SysScrollbar          (Symbolic | COLOR_SCROLLBAR);
const TColor TColor::SysDesktop            (Symbolic | COLOR_BACKGROUND);
const TColor TColor::SysActiveCaption      (Symbolic | COLOR_ACTIVECAPTION);
const TColor TColor::SysInactiveCaption    (Symbolic | COLOR_INACTIVECAPTION);
const TColor TColor::SysMenu               (Symbolic | COLOR_MENU);
const TColor TColor::SysWindow             (Symbolic | COLOR_WINDOW);
const TColor TColor::SysWindowFrame        (Symbolic | COLOR_WINDOWFRAME);
const TColor TColor::SysMenuText           (Symbolic | COLOR_MENUTEXT);
const TColor TColor::SysWindowText         (Symbolic | COLOR_WINDOWTEXT);
const TColor TColor::SysCaptionText        (Symbolic | COLOR_CAPTIONTEXT);
const TColor TColor::SysActiveBorder       (Symbolic | COLOR_ACTIVEBORDER);
const TColor TColor::SysInactiveBorder     (Symbolic | COLOR_INACTIVEBORDER);
const TColor TColor::SysAppWorkspace       (Symbolic | COLOR_APPWORKSPACE);
const TColor TColor::SysHighlight          (Symbolic | COLOR_HIGHLIGHT);
const TColor TColor::SysHighlightText      (Symbolic | COLOR_HIGHLIGHTTEXT);
const TColor TColor::Sys3dFace             (Symbolic | COLOR_BTNFACE);
const TColor TColor::Sys3dShadow           (Symbolic | COLOR_BTNSHADOW);
const TColor TColor::SysGrayText           (Symbolic | COLOR_GRAYTEXT);
const TColor TColor::SysBtnText            (Symbolic | COLOR_BTNTEXT);

// NOTE: WINVER >= 0x030a
//
const TColor TColor::SysInactiveCaptionText(Symbolic | COLOR_INACTIVECAPTIONTEXT);
const TColor TColor::Sys3dHilight          (Symbolic | COLOR_BTNHIGHLIGHT);

// NOTE: WINVER >= 0x0400
//
const TColor TColor::Sys3dDkShadow(isWin31() ? (Symbolic | COLOR_WINDOWFRAME) :
                                               (Symbolic | COLOR_3DDKSHADOW));
const TColor TColor::Sys3dLight   (isWin31() ? (Symbolic | COLOR_BTNFACE) :
                                               (Symbolic | COLOR_3DLIGHT));
const TColor TColor::SysInfoText  (isWin31() ?  MkRGB(0,0,0) :
                                               (Symbolic | COLOR_INFOTEXT));
const TColor TColor::SysInfoBk    (isWin31() ?  MkRGB(255,255,128) :
                                               (Symbolic | COLOR_INFOBK));

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

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

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif

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
