//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\color.h
//   Definition of color classes
//----------------------------------------------------------------------------
#if !defined(__OWL_COLOR_H)
#define __OWL_COLOR_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif

long _OWLFUNC NColors(WORD bitCount);
WORD _OWLFUNC NBits(long colors);

#define OWLRGB(r,g,b)\
 ((COLORREF)(((BYTE)(WORD)(r)|((WORD)(g)<<8))|(((DWORD)(BYTE)(WORD)(b))<<16)))

class _OWLCLASS TColor {
  public:
    TColor() : Value(0) {}
    TColor(COLORREF value) : Value(value) {}
    TColor(long value) : Value((COLORREF)value) {}
    TColor(int r, int g, int b) : Value(OWLRGB(r,g,b)) {}
    TColor(int r, int g, int b, int f) : Value(((DWORD)f<<24) | OWLRGB(r,g,b)) {}
    TColor(int index) : Value(PALETTEINDEX(index)) {}
    TColor(const PALETTEENTRY far& pe) : Value(OWLRGB(pe.peRed,pe.peGreen,pe.peBlue)) {}
    TColor(const RGBQUAD far& q) : Value(OWLRGB(q.rgbRed,q.rgbGreen,q.rgbBlue)) {}
    TColor(const RGBTRIPLE far& t) : Value(OWLRGB(t.rgbtRed,t.rgbtGreen,t.rgbtBlue)) {}

    // Type Conversion Operators
    operator      COLORREF() const {return Value;}

    BOOL operator ==(const TColor& clrVal) const {return Value==clrVal;}

    int           Index() const {return (int)Value & 0xFFFF;}
    TColor        Rgb() const {return Value & 0x00FFFFFFUL;}
    TColor        PalIndex() const {return (COLORREF)Index() | 0x01000000UL;}
    TColor        PalRelative() const {return Rgb() | 0x02000000UL;}

    BYTE          Red() const {return (BYTE)(WORD)Value;}
    BYTE          Green() const {return ((BYTE)(WORD)(((WORD)Value) >> 8));}
    BYTE          Blue() const {return ((BYTE)(WORD)(Value>>16));}
    BYTE          Flags() const {return (BYTE)(WORD)(Value>>24);}

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

  protected:
    COLORREF    Value;          // the color value type (not a struct)
};

class TPaletteEntry : public tagPALETTEENTRY {
  public:
    TPaletteEntry(int r, int g, int b, int f = 0);
    TPaletteEntry(TColor c);
};

class TRgbQuad : public tagRGBQUAD {
  public:
    TRgbQuad(int r, int g, int b);
    TRgbQuad(TColor c);
    TRgbQuad(const RGBQUAD far& q) {*(RGBQUAD*)this = q;}
};

class TRgbTriple : public tagRGBTRIPLE {
  public:
    TRgbTriple(int r, int g, int b);
    TRgbTriple(TColor c);
    TRgbTriple(const RGBTRIPLE far& t) {*(RGBTRIPLE*)this = t;}
};


//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline TPaletteEntry::TPaletteEntry(int r, int g, int b, int f) {
  peRed = (BYTE)(WORD)r;
  peGreen = (BYTE)(WORD)g;
  peBlue = (BYTE)(WORD)b;
  peFlags = (BYTE)(WORD)f;
}

inline TPaletteEntry::TPaletteEntry(TColor c) {
  peRed = c.Red();
  peGreen = c.Green();
  peBlue = c.Blue();
  peFlags = c.Flags();
}

inline TRgbQuad::TRgbQuad(int r, int g, int b) {
  rgbRed = (BYTE)(WORD)r;
  rgbGreen = (BYTE)(WORD)g;
  rgbBlue = (BYTE)(WORD)b;
  rgbReserved = 0;
}

inline TRgbQuad::TRgbQuad(TColor c) {
  rgbRed = c.Red();
  rgbGreen = c.Green();
  rgbBlue = c.Blue();
  rgbReserved = 0;
}

inline TRgbTriple::TRgbTriple(int r, int g, int b) {
  rgbtRed = (BYTE)(WORD)r;
  rgbtGreen = (BYTE)(WORD)g;
  rgbtBlue = (BYTE)(WORD)b;
}

inline TRgbTriple::TRgbTriple(TColor c) {
  rgbtRed = c.Red();
  rgbtGreen = c.Green();
  rgbtBlue = c.Blue();
}

#endif  // __OWL_COLOR_H
