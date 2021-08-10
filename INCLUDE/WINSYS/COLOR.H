//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
// Definition of windowing system color classes
//----------------------------------------------------------------------------
#if !defined(WINSYS_COLOR_H)
#define WINSYS_COLOR_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>    // Need persist streaming classes & operators
#endif

#if defined(BI_PLAT_MSW)
# if !defined(WINSYS_WSYSINC_H)
#   include <winsys/wsysinc.h>
# endif
#else

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// Simulate Windows structures
//

  typedef uint32 COLORREF;

  struct tagPALETTEENTRY {
    uint8    peRed;
    uint8    peGreen;
    uint8    peBlue;
    uint8    peFlags;
  };
# include <pshpack1.h>
  struct tagRGBTRIPLE {
    uint8    rgbtBlue;
    uint8    rgbtGreen;
    uint8    rgbtRed;
  };
# include <poppack.h>
  struct tagRGBQUAD {
    uint8    rgbBlue;
    uint8    rgbGreen;
    uint8    rgbRed;
    uint8    rgbReserved;
};

#if defined(BI_NAMESPACE)
}       // namespace ClassLib
#endif

#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// Functions to convert number of bits to number of palette colors and back,
// and build an RGB COLORREF
//
long _WSYSFUNC NColors(uint16 bitCount);
uint16 _WSYSFUNC NBits(long colors);

//
// Convert the red, green, and blue components into a COLORREF.
//
inline COLORREF MkRGB(uint r, uint g, uint b)
{
  return COLORREF((r & 0xFF) |
                  ((g & 0xFF) << 8) |
                  ((uint32(b) & 0xFF) << 16)
                 );
}

//
// class TColor
// ~~~~~ ~~~~~~
// Class wrapper for management of color values.
// Internally, all colors are stored as a COLORREF.
//
class _WSYSCLASS TColor {
  public:
    // Constructors
    //
    TColor();
    TColor(const TColor& src);

    TColor(COLORREF value);
    TColor(long value);

    TColor(int r, int g, int b);
    TColor(int r, int g, int b, int f);
    TColor(int index);

    TColor(const PALETTEENTRY far& pe);
    TColor(const RGBQUAD far& q);
    TColor(const RGBTRIPLE far& t);

    // Conversion operator & value accessor
    //
    operator      COLORREF() const;
    COLORREF      GetValue() const;
    void          SetValue(const COLORREF& value);

    // Comparison operators
    //
    bool operator ==(const TColor& other) const;
    bool operator !=(const TColor& other) const;
    bool operator ==(COLORREF cr) const;
    bool operator !=(COLORREF cr) const;

    TColor& operator =(const TColor& src);

    // Accessors
    //
    int           Index() const;
    TColor        Rgb() const;
    TColor        PalIndex() const;
    TColor        PalRelative() const;

    uint8         Red() const;
    uint8         Green() const;
    uint8         Blue() const;
    uint8         Flags() const;
    bool          IsSysColor() const;
    bool          IsSpecialColor() const;

    // Common RGB color values
    //
    static const TColor  Black;
    static const TColor  LtGray;
    static const TColor  Gray;
    static const TColor  LtRed;
    static const TColor  LtGreen;
    static const TColor  LtYellow;
    static const TColor  LtBlue;
    static const TColor  LtMagenta;
    static const TColor  LtCyan;
    static const TColor  White;

    // Special color values
    //
    static const TColor  None;         // not-a-color
    static const TColor  Transparent;  // a non-painting color

    // Symbolic system color values. Perform GetSysColor() on conversion to
    // COLORREF
    //
    static const TColor  SysScrollbar;
    static const TColor  SysDesktop;
    static const TColor  SysActiveCaption;
    static const TColor  SysInactiveCaption;
    static const TColor  SysMenu;
    static const TColor  SysWindow;
    static const TColor  SysWindowFrame;
    static const TColor  SysMenuText;
    static const TColor  SysWindowText;
    static const TColor  SysCaptionText;
    static const TColor  SysActiveBorder;
    static const TColor  SysInactiveBorder;
    static const TColor  SysAppWorkspace;
    static const TColor  SysHighlight;
    static const TColor  SysHighlightText;
    static const TColor  Sys3dFace;
    static const TColor  Sys3dShadow;
    static const TColor  SysGrayText;
    static const TColor  SysBtnText;
    static const TColor  SysInactiveCaptionText;
    static const TColor  Sys3dHilight;
    static const TColor  Sys3dDkShadow;
    static const TColor  Sys3dLight;
    static const TColor  SysInfoText;
    static const TColor  SysInfoBk;

  private:
    COLORREF    Value;          // The 32bit color value type (not a struct)

  friend ipstream& operator >>(ipstream& is, TColor& c);
  friend opstream& operator <<(opstream& os, const TColor& c);
};


//
// class TPaletteEntry
// ~~~~~ ~~~~~~~~~~~~~
// Wrapper for Windows' PALETTEENTRY type
//
class TPaletteEntry : public tagPALETTEENTRY {
  public:
    TPaletteEntry(int r, int g, int b, int f = 0);
    TPaletteEntry(const TColor& c);

    bool operator ==(COLORREF cr) const;
};


//
// class TRgbQuad
// ~~~~~ ~~~~~~~~
// Wrapper for Windows' RBGQUAD type
//
class TRgbQuad : public tagRGBQUAD {
  public:
    TRgbQuad(int r, int g, int b);
    TRgbQuad(const TColor& c);
    TRgbQuad(const RGBQUAD far& q);

    bool operator ==(COLORREF cr) const;
};


//
// class TRgbTriple
// ~~~~~ ~~~~~~~~~~
// Wrapper for Windows' RBGTRIPLE type
//
class TRgbTriple : public tagRGBTRIPLE {
  public:
    TRgbTriple(int r, int g, int b);
    TRgbTriple(const TColor& c);
    TRgbTriple(const RGBTRIPLE far& t);

    bool operator ==(COLORREF cr) const;
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

//----------------------------------------------------------------------------
// Inline Implementations
//

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif
//
// Extract the color value from a persistent input stream.
//
inline ipstream& operator >>(ipstream& is, TColor& c)
{
  is >> c.Value;
  return is;
}

//
// Insert the color value into a persistent output stream.
//
inline opstream& operator <<(opstream& os, const TColor& c)
{
  os << c.Value;
  return os;
}

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

//
// Construct a null color.
//
inline
TColor::TColor()
:
  Value(0)
{
}

//
// Construct a color as a copy of another color.
//
inline
TColor::TColor(const TColor& src)
:
  Value(src.Value)
{
}

//
// Construct a color with an existing COLORREF value.
//
inline
TColor::TColor(COLORREF value)
:
  Value(value)
{
}

//
// Construct a color given a particular system value representation.
//
inline
TColor::TColor(long value)
:
  Value((COLORREF)value)
{
}

//
// Construct a color given the red, green, and blue components of color.
//
inline
TColor::TColor(int r, int g, int b)
:
  Value(MkRGB(r, g, b))
{
}

//
// Construct a color given red, green, blue, and flag components of color.
// The flag component is defined in the Windows SDK reference.
//
inline
TColor::TColor(int r, int g, int b, int f)
:
  Value(((uint32) f << 24) | MkRGB(r, g, b))
{
}

//
// Construct a color that is an index into a palette.
//
inline
TColor::TColor(int index)
:
  Value(PALETTEINDEX(index))
{
}

//
// Construct a color based on an existing PALETTEENTRY.
//
inline
TColor::TColor(const PALETTEENTRY far& pe)
:
  Value(MkRGB(pe.peRed, pe.peGreen, pe.peBlue))
{
}

//
// Construct a color based on an existing RGBQUAD.
//
inline
TColor::TColor(const RGBQUAD far& q)
:
  Value(MkRGB(q.rgbRed, q.rgbGreen, q.rgbBlue))
{
}

//
// Construct a color based on an existing RGBTRIPLE.
//
inline
TColor::TColor(const RGBTRIPLE far& t)
:
  Value(MkRGB(t.rgbtRed, t.rgbtGreen, t.rgbtBlue))
{
}

//
// Convert the stored color into a COLORREF.
//
inline
TColor::operator COLORREF() const
{
  return GetValue();
}

//
// Return true if two colors are equal.
// This function compares between two binary representation of colors, it
// does not compare colors logically.
//
// For example, if palette entry 4 is solid red (rgb components (255, 0, 0)),
// The following will return false:
//   if (TColor(4) == TColor(255, 0, 0))
//     /* colors match */
//   else
//     /* colors do not match */
//
//  To actually compare the RGB values of two TColor objects, use the
//  operator == (COLORREF). For example,
//  TColor colorA, colorB;
//  if (colorA == colorB.GetValue()) {
//      // ColorA & ColorB
//  }
//
inline bool
TColor::operator ==(const TColor& other) const
{
  return Value == other.Value;
}

//
// Return true if two colors are not equal.
// See additional comments in TColor::operator ==.
//
inline bool
TColor::operator !=(const TColor& other) const
{
  return Value != other.Value;
}

//
// Return true if this color matches a COLORREF.
// See additional comments in TColor::operator ==.
//
inline bool
TColor::operator ==(COLORREF cr) const
{
  return GetValue() == cr;
}

//
// Return true if this color does not match a COLORREF.
// See additional comments in TColor::operator ==.
//
inline bool
TColor::operator !=(COLORREF cr) const
{
  return GetValue() != cr;
}

//
// Change the color after it has been constructed.
//
inline void
TColor::SetValue(const COLORREF& value)
{
  Value = value;
}

//
// Set the value of color after it has been constructed.
//
inline TColor&
TColor::operator =(const TColor& src)
{
  Value = src.Value;
  return *this;
}

//
// Return the index of the palette entry.
//
inline int
TColor::Index() const
{
  return (int)Value & 0xFFFF;
}

//
// Return the RGB color value.
//
inline TColor
TColor::Rgb() const
{
  return GetValue();
}

//
// Return the palette index.
// Assumes that the color really is a palette index
//
inline TColor
TColor::PalIndex() const
{
  return (COLORREF)Index() | 0x01000000UL;
}

//
// Return the palette relative entry.
//
inline TColor
TColor::PalRelative() const
{
  return Rgb() | 0x02000000UL;
}

//
// Return the flags entry.
//
inline uint8
TColor::Flags() const
{
  return (uint8)(uint16)(Value >> 24);
}

//
// Return true if the color is a system color.
//
inline bool
TColor::IsSysColor() const
{
  return (Value & 0xFF000000UL) == 0x80000000UL;
}

//
// Return true if the color is a special color (currently None or Transparent)
//
inline bool
TColor::IsSpecialColor() const
{
  return (Value & 0xF0000000UL) == 0xF0000000UL;
}

//
// Construct a palette entry from the red, green, blue and flag components.
//
inline
TPaletteEntry::TPaletteEntry(int r, int g, int b, int f)
{
  peRed = (uint8)(uint16)r;
  peGreen = (uint8)(uint16)g;
  peBlue = (uint8)(uint16)b;
  peFlags = (uint8)(uint16)f;
}

//
// Construct a palette entry from a TColor.
//
inline
TPaletteEntry::TPaletteEntry(const TColor& c)
{
  peRed = c.Red();
  peGreen = c.Green();
  peBlue = c.Blue();
  peFlags = c.Flags();
}

//
// Returns true if the palette entries have the same color components.
//
inline bool
TPaletteEntry::operator ==(COLORREF cr) const
{
  return peRed == GetRValue(cr) &&
         peGreen == GetGValue(cr) &&
         peBlue == GetBValue(cr);
}

//
// Construct an RGB quad from the red, green and blue components
//
inline
TRgbQuad::TRgbQuad(int r, int g, int b)
{
  rgbRed = (uint8)(uint16)r;
  rgbGreen = (uint8)(uint16)g;
  rgbBlue = (uint8)(uint16)b;
  rgbReserved = 0;
}

//
// Construct an RGB quad from a TColor.
//
inline
TRgbQuad::TRgbQuad(const TColor& c)
{
  rgbRed = c.Red();
  rgbGreen = c.Green();
  rgbBlue = c.Blue();
  rgbReserved = 0;
}

//
// Wrap an object around an existing RGBQUAD.
//
inline
TRgbQuad::TRgbQuad(const RGBQUAD far& q)
{
  *(RGBQUAD*)this = q;
}

//
// Return true if the RGBQUAD has the same color components.
//
inline bool
TRgbQuad::operator ==(COLORREF cr) const
{
  return rgbRed == GetRValue(cr) &&
         rgbGreen == GetGValue(cr) &&
         rgbBlue == GetBValue(cr);
}

//
// Construct an RGB triple from its red, green, and blue components.
//
inline
TRgbTriple::TRgbTriple(int r, int g, int b)
{
  rgbtRed = (uint8)(uint16)r;
  rgbtGreen = (uint8)(uint16)g;
  rgbtBlue = (uint8)(uint16)b;
}

//
// Construct an RGB triple from a TColor.
//
inline
TRgbTriple::TRgbTriple(const TColor& c)
{
  rgbtRed = c.Red();
  rgbtGreen = c.Green();
  rgbtBlue = c.Blue();
}

//
// Wrap an object around an existing RGBTRIPLE.
//
inline
TRgbTriple::TRgbTriple(const RGBTRIPLE far& t)
{
  *(RGBTRIPLE*)this = t;
}

//
// Return true if the triple match color components.
//
inline bool
TRgbTriple::operator ==(COLORREF cr) const
{
  return rgbtRed == GetRValue(cr) &&
         rgbtGreen == GetGValue(cr) &&
         rgbtBlue == GetBValue(cr);
}

#endif  // WINSYS_COLOR_H
