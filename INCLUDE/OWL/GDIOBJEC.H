//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of abstract GDI object class and derived classes
//----------------------------------------------------------------------------
#if !defined(OWL_GDIOBJEC_H)
#define OWL_GDIOBJEC_H

#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif

class _OWLCLASS TDC;
class _BIDSCLASS TFile;
class _OWLCLASS TBrush;
class _OWLCLASS TBitmap;
class _OWLCLASS TDib;
class _OWLCLASS TPalette;
class _OWLCLASS TClipboard;
class _OWLCLASS TMetaFilePict;

//
// GDI Orphan control - Object reference counting & orphan recovery
// enabled by default unless NO_GDI_ORPHAN_CONTROL is defined.
//
#if !defined(NO_GDI_ORPHAN_CONTROL)
# define OBJ_REF_ADD(handle,type) TGdiObject::RefAdd((handle), (type))
# define OBJ_REF_REMOVE(handle) TGdiObject::RefRemove(handle)
# define OBJ_REF_INC(handle) TGdiObject::RefInc(handle)
# if defined(__TRACE)
#   define OBJ_REF_DEC(handle, wantDelete) TGdiObject::RefDec((handle),\
                                                               (wantDelete))
# else
#   define OBJ_REF_DEC(handle, wantDelete) TGdiObject::RefDec((handle))
# endif
# define OBJ_REF_COUNT(handle) TGdiObject::RefCount(handle)
  struct TObjInfo;
#else
# define OBJ_REF_ADD(handle,type) handle
# define OBJ_REF_REMOVE(handle) handle
# define OBJ_REF_INC(handle) handle
# define OBJ_REF_DEC(handle,wantDelete) handle
# define OBJ_REF_COUNT(handle) -1
#endif

//
// class TGdiObject
// ----- ----------
//
// Abstract class for Windows GDI objects. Provides base, destruction &
// orphan control for true GDI objects
//
class _OWLCLASS TGdiObject : private TGdiBase {
  public:
    // virtual destructor--all GDI objects inherit this.
    /*virtual*/    ~TGdiObject();

    operator    HGDIOBJ() const {return HGDIOBJ(Handle);}
    int         GetObject(int count, void far* object) const;
    bool        operator ==(const TGdiObject& other) const {return Handle == other.Handle;}

    #if !defined(NO_GDI_ORPHAN_CONTROL)
      enum TType {
        None, Pen, Brush, Font, Palette, Bitmap, TextBrush
      };
      static TObjInfo* RefFind(HANDLE object);
      static void      RefAdd(HANDLE handle, TType type);
      static void      RefRemove(HANDLE handle);
      static void      RefInc(HANDLE handle);
      #if defined(__TRACE)
        static void    RefDec(HANDLE handle, bool wantDelete);
      #else
        static void    RefDec(HANDLE handle);
      #endif
      static int       RefCount(HANDLE handle);
    #endif

  protected:
    TGdiBase::CheckValid;  // make this function available to derivatives
    TGdiBase::Handle;      // and these members too
    TGdiBase::ShouldDelete;

    // constructors for use by derived classes only
    TGdiObject();
    TGdiObject(HANDLE handle, TAutoDelete autoDelete = NoAutoDelete);

  private:
    TGdiObject(const TGdiObject&); // Protect against copying of GDI objects
    TGdiObject& operator =(const TGdiObject&);
};

//
// class TPen
// ----- ----
//
// GDI Pen class. Can construct a pen from explicit info, or indirectly
//
class _OWLCLASS TPen : public TGdiObject {
  public:
    // Constructors
    TPen(HPEN handle, TAutoDelete autoDelete = NoAutoDelete);

    TPen(TColor color, int width=1, int style=PS_SOLID);
    TPen(const LOGPEN far* logPen);
    TPen(const TPen&);
#if defined(BI_PLAT_WIN32)
    TPen(uint32 penStyle, uint32 width, const TBrush& brush, uint32 styleCount,
         uint32* style);
    TPen(uint32 penStyle, uint32 width, const LOGBRUSH& logBrush,
         uint32 styleCount, uint32* style);
#endif

    operator HPEN() const {return HPEN(HGDIOBJ(*this));}

    // Get GDI Pen Object information
    bool        GetObject(LOGPEN far& logPen) const;

  private:
    TPen& operator =(const TPen&);
};

//
// class TBrush
// ----- ------
//
// GDI Brush class. Can construct a brush from explicit info, creating a 
// solid, styled, or patterned brush.  Can also create a brush indirectly.
//
class _OWLCLASS TBrush : public TGdiObject {
  public:
    // Constructors
    TBrush(HBRUSH handle, TAutoDelete autoDelete = NoAutoDelete);

    TBrush(TColor color);
    TBrush(TColor color, int style);
    TBrush(const TBitmap& pattern);
    TBrush(const TDib& pattern);
    TBrush(const LOGBRUSH far* logBrush);
    TBrush(const TBrush& src);

    operator HBRUSH() const {return HBRUSH(HGDIOBJ(*this));}

    // Get GDI Brush Object information
    bool        GetObject(LOGBRUSH far& logBrush) const;
#if defined(BI_PLAT_WIN16)
    bool        UnrealizeObject();  // Use TDC::SetBrushOrg() for Win32
#endif

  private:
    TBrush& operator =(const TBrush&);
};

//
// class THatch8x8Brush
// ----- --------------
//
// Mini 8x8 monochrome configurable hatch brush class, with predefined patterns
//
class _OWLCLASS THatch8x8Brush : public TBrush {
  public:
    THatch8x8Brush(const uint8 hatch[], TColor fgColor=TColor::White,
                   TColor bgColor=TColor::Black);
    void     Reconstruct(const uint8 hatch[], TColor fgColor, TColor bgColor);

    const static uint8 Hatch22F1[8];  // 2-on, 2-off, offset 1 per row forward
    const static uint8 Hatch13F1[8];  // 1-on, 3-off, offset 1 per row forward
    const static uint8 Hatch11F1[8];  // 1-on, 1-off, offset 1 per row
    const static uint8 Hatch22B1[8];  // 2-on, 2-off, offset 1 per row backward
    const static uint8 Hatch13B1[8];  // 1-on, 3-off, offset 1 per row backward

  private:
    static HBRUSH Create(const uint8 hatch[], TColor fgColor, TColor bgColor);
};

//
// class TFont
// ----- -----
//
// GDI Font class.  Can construct a font from explicit info, or indirectly.
//
class _OWLCLASS TFont : public TGdiObject {
  public:
    // Constructors
    TFont(HFONT handle, TAutoDelete autoDelete = NoAutoDelete);
  
    // Convenient font ctor
    TFont(const char far* facename=0,
          int height=0, int width=0, int escapement=0, int orientation=0,
          int weight=FW_NORMAL,
          uint8 pitchAndFamily=DEFAULT_PITCH|FF_DONTCARE,
          uint8 italic=false, uint8 underline=false, uint8 strikeout=false,
          uint8 charSet=1,  // DEFAULT_CHARSET or UNICODE_CHARSET
          uint8 outputPrecision=OUT_DEFAULT_PRECIS,
          uint8 clipPrecision=CLIP_DEFAULT_PRECIS,
          uint8 quality=DEFAULT_QUALITY);

    // CreateFont() matching font ctor
    TFont(int height, int width, int escapement=0, int orientation=0,
          int weight=FW_NORMAL,
          uint8 italic=false, uint8 underline=false, uint8 strikeout=false,
          uint8 charSet=1,  // DEFAULT_CHARSET or UNICODE_CHARSET
          uint8 outputPrecision=OUT_DEFAULT_PRECIS,
          uint8 clipPrecision=CLIP_DEFAULT_PRECIS,
          uint8 quality=DEFAULT_QUALITY,
          uint8 pitchAndFamily=DEFAULT_PITCH|FF_DONTCARE,
          const char far* facename=0);
    TFont(const LOGFONT far* logFont);
    TFont(const TFont&);

    operator HFONT() const {return HFONT(HGDIOBJ(*this));}

    // Get GDI Font Object information
    bool        GetObject(LOGFONT far& logFont) const;

  private:
    TFont& operator =(const TFont&);
};

//
// class TPalette
// ----- --------
//
// GDI Palette class.  Can construct a palette from explicit info, or
// indirectly from various color table types that are used by DIBs.
//
class _OWLCLASS TPalette : public TGdiObject {
  public:
    // Constructors
    TPalette(HPALETTE handle, TAutoDelete autoDelete = NoAutoDelete);

    TPalette(const TClipboard&);
    TPalette(const TPalette& palette);          // Copy whole palette

    TPalette(const LOGPALETTE far* logPalette);
    TPalette(const PALETTEENTRY far* entries, int count);
    TPalette(const BITMAPINFO far* info, uint flags=0);    //Win 3.0 DIB hdr
    TPalette(const BITMAPCOREINFO far* core, uint flags=0);//PM 1.0 DIB header
    TPalette(const TDib& dib, uint flags=0);               // DIB object

    operator HPALETTE() const {return HPALETTE(HGDIOBJ(*this));}

    // Palette functions
    bool        ResizePalette(uint numEntries);
    void        AnimatePalette(uint start, uint count, const PALETTEENTRY far* entries);
    uint        SetPaletteEntries(uint16 start, uint16 count, const PALETTEENTRY far* entries);
    uint        SetPaletteEntry(uint16 index, const PALETTEENTRY far& entry);
    uint        GetPaletteEntries(uint16 start, uint16 count, PALETTEENTRY far* entries) const;
    uint        GetPaletteEntry(uint16 index, PALETTEENTRY far& entry) const;
    uint        GetNearestPaletteIndex(TColor color) const;
    bool        GetObject(uint16 far& numEntries) const;
    uint16      GetNumEntries() const;

    // Put this palette onto the clipboard
    void        ToClipboard(TClipboard& Clipboard);
    bool        UnrealizeObject() {return ::UnrealizeObject(Handle);}

  protected:
    void        Create(const BITMAPINFO far* info, uint flags);
    void        Create(const BITMAPCOREINFO far* core, uint flags);

  private:
    TPalette& operator =(const TPalette&);
};

inline TClipboard& operator <<(TClipboard& clipboard, TPalette& palette)
      {palette.ToClipboard(clipboard); return clipboard;}

//
// class TBitmap
// ----- -------
//
// GDI Bitmap class.  Can construct a bitmap from many sources.  This bitmap
// is the lowest level object that is actually selected into a DC.
//
class _OWLCLASS TBitmap : public TGdiObject {
  public:
    // Constructors
    TBitmap(HBITMAP handle, TAutoDelete autoDelete = NoAutoDelete);
    TBitmap(const TClipboard& clipboard);
    TBitmap(const TBitmap& bitmap);

    TBitmap(int width, int height, uint8 planes=1, uint8 bitCount=1, const void far* bits=0);
    TBitmap(const BITMAP far* bitmap);
    TBitmap(const TDC& Dc, int width, int height, bool discardable = false);
    TBitmap(const TDC& Dc, const TDib& dib, uint32 usage=CBM_INIT);

    TBitmap(const TMetaFilePict& metaFile, TPalette& palette, const TSize& size);
    TBitmap(const TDib& dib, const TPalette* palette = 0);

    TBitmap(HINSTANCE, TResId);

    operator HBITMAP() const {return HBITMAP(HGDIOBJ(*this));}

    // Get/set GDI Object information
    bool        GetObject(BITMAP far& bitmap) const;
    int         Width() const;
    int         Height() const;
    uint8       Planes() const;
    uint8       BitsPixel() const;
    uint32      GetBitmapBits(uint32 count, void far* bits) const;
    uint32      SetBitmapBits(uint32 count, const void far* bits);
    bool        GetBitmapDimension(TSize& size) const;
    bool        SetBitmapDimension(const TSize& size, TSize far* oldSize=0);

    // Put this bitmap onto the clipboard
    void  ToClipboard(TClipboard& clipboard);

  protected:
    TBitmap();

    // Create a bitmap & fill in it's Handle
    void Create(const TDib& dib, const TPalette& palette);
    void Create(const TBitmap& src);
 
  private:
    TBitmap& operator =(const TBitmap&);
};

inline TClipboard& operator <<(TClipboard& clipboard, TBitmap& bitmap)
      {bitmap.ToClipboard(clipboard); return clipboard;}

//
// class TRegion
// ----- -------
//
// GDI Region class. Can construct a region from various shapes
//
class _OWLCLASS TRegion : private TGdiBase {
  public:
    // Constructors
    TRegion();
    TRegion(HRGN handle, TAutoDelete autoDelete = NoAutoDelete);
    TRegion(const TRegion& region);
    TRegion(const TRect& rect);
    enum TEllipse {Ellipse};
    TRegion(const TRect& e, TEllipse);
    TRegion(const TRect& rect, const TSize& corner);
    TRegion(const TPoint* points, int count, int fillMode);
    TRegion(const TPoint* points, const int* polyCounts, int count,
            int fillMode);
   ~TRegion();

    // Other initialization
    void        SetRectRgn(const TRect& rect);

    // Type Conversion Operators
    operator HRGN() const {return HRGN(Handle);}

    // Test and information functions/operators
    bool        operator ==(const TRegion& other) const;
    bool        operator !=(const TRegion& other) const;
    bool        Contains(const TPoint& point) const;
    bool        Touches(const TRect& rect) const;
    int         GetRgnBox(TRect& box) const;
    TRect       GetRgnBox() const;

    // Assignment operators
    TRegion&    operator =(const TRegion& source);
    TRegion&    operator +=(const TSize& delta);
    TRegion&    operator -=(const TSize& delta);
    TRegion&    operator -=(const TRegion& source);
    TRegion&    operator &=(const TRegion& source);
    TRegion&    operator &=(const TRect& source);
    TRegion&    operator |=(const TRegion& source);
    TRegion&    operator |=(const TRect& source);
    TRegion&    operator ^=(const TRegion& source);
    TRegion&    operator ^=(const TRect& source);
};

//
// class TIcon
// ----- -----
//
// Pseudo-GDI object Icon class.  Can construct an icon from a resource or
// explicit info.  Overloads the destructor since it is not a real GDI object.
//
class _OWLCLASS TIcon : private TGdiBase {
  public:
    // Constructors
    TIcon(HICON handle, TAutoDelete autoDelete = NoAutoDelete);
    TIcon(HINSTANCE, const TIcon& icon);
    TIcon(HINSTANCE, TResId);
    TIcon(HINSTANCE, const char far* filename, int index);
    TIcon(HINSTANCE, const TSize& size, int planes, int bitsPixel, 
          const void far* andBits, const void far* xorBits);
#if defined(BI_PLAT_WIN32)
    TIcon(const void* resBits, uint32 resSize);
    TIcon(const ICONINFO* iconInfo);
#endif
   ~TIcon();

    operator HICON() const {return HICON(Handle);}
    bool     operator ==(const TIcon& other) const {return Handle == other.Handle;}
    
#if defined(BI_PLAT_WIN32)
    bool     GetIconInfo(ICONINFO* iconInfo) const;
#endif

  private:
    TIcon(const TIcon&); // Protect against copying of icons
    TIcon& operator =(const TIcon&);
};

//
// class TCursor
// ----- -------
//
// Pseudo-GDI object Cursor class.  Can construct an cursor from a resource or
// explicit info.  Overloads the destructor since it is not a real GDI object.
//
class _OWLCLASS TCursor : public TGdiBase {
  public:
    // Constructors
    TCursor(HCURSOR handle, TAutoDelete autoDelete = NoAutoDelete);
    TCursor(HINSTANCE, const TCursor& cursor);
    TCursor(HINSTANCE, TResId);
    TCursor(HINSTANCE, const TPoint& hotSpot,
            const TSize& size, void far* andBits, void far* xorBits);
#if defined(BI_PLAT_WIN32)
    TCursor(const void* resBits, uint32 resSize);
    TCursor(const ICONINFO* iconInfo);
#endif
   ~TCursor();

    operator HCURSOR() const {return HCURSOR(Handle);}
    bool     operator ==(const TCursor& other) const {return Handle == other.Handle;}

#if defined(BI_PLAT_WIN32)
    bool     GetIconInfo(ICONINFO* iconInfo) const;
#endif
    
  private:
    TCursor(const TCursor&); // Protect against copying of cursors
    TCursor& operator =(const TCursor&);
};

//
// class TDib
// ----- ----
//
// Pseudo-GDI object Device Independent Bitmap (DIB) class.  DIBs really have
// no Window's handle, they are just a structure containing format and palette
// information and a collection of bits (pixels).  This class provides a very
// convenient way to work with DIBs like any other GDI object.
// The memory for the DIB is in one GlobalAlloc'd chunk so it can be passed to
// the Clipboard, OLE, etc.
// Overloads the destructor since it is not a real GDI object.
//
// This is what is really inside a .BMP file, what is in bitmap resources, and
// what is put on the clipboard as a DIB.
//
class _OWLCLASS TDib : private TGdiBase {
  public:
    // Constructors and destructor
    TDib(HGLOBAL handle, TAutoDelete autoDelete = NoAutoDelete);
    TDib(const TClipboard& clipboard);
    TDib(const TDib& dib);

    TDib(int width, int height, int nColors, uint16 mode=DIB_RGB_COLORS);
    TDib(HINSTANCE, TResId);
    TDib(const char* name);
#if !defined(BI_DATA_NEAR)
    TDib(istream& is, bool readFileHeader = false);
#endif
    TDib(const TBitmap& bitmap, const TPalette* pal = 0);
   ~TDib();

    // Comparison operator
    bool     operator ==(const TDib& other) const {return Handle == other.Handle;}

    // Access to the internal structures of the dib
    const BITMAPINFO far*      GetInfo() const {return Info;}
    BITMAPINFO far*            GetInfo() {return Info;}
    const BITMAPINFOHEADER far*GetInfoHeader() const {return &Info->bmiHeader;}
    BITMAPINFOHEADER far*      GetInfoHeader() {return &Info->bmiHeader;}
    const TRgbQuad far*        GetColors() const {return (const TRgbQuad far*)Info->bmiColors;}
    TRgbQuad far*              GetColors() {return (TRgbQuad far*)Info->bmiColors;}
    const uint16 far*          GetIndices() const {return (uint16*)Info->bmiColors;}
    uint16 far*                GetIndices() {return (uint16*)Info->bmiColors;}
    const void HUGE*           GetBits() const {return Bits;}
    void HUGE*                 GetBits() {return Bits;}

    // Type convert this dib by returning pointers to internal structures
    operator HANDLE() const {return Handle;}
    operator const BITMAPINFO far*() const {return GetInfo();}
    operator BITMAPINFO far*() {return GetInfo();}
    operator const BITMAPINFOHEADER far*() const {return GetInfoHeader();}
    operator BITMAPINFOHEADER far*() {return GetInfoHeader();}
    operator const TRgbQuad far*() const {return GetColors();}
    operator TRgbQuad far*() {return GetColors();}

    // Put this Dib onto the clipboard
    void      ToClipboard(TClipboard& clipboard);

    // Get info about this Dib
    bool      IsOK() const {return Info != 0;}
    bool      IsPM() const {return IsCore;}
    int       Width() const {return W;}
    int       Height() const {return H;}
    TSize     Size() const {return TSize(W,H);}
    long      NumColors() const {return NumClrs;}
    uint16    StartScan() const {return 0;}
    uint16    NumScans() const {return uint16(H);}
    uint16    Usage() const {return Mode;}

    // Write this dib to a file by name, to file object or to an ostream
    bool      WriteFile(const char* filename);
    bool      Write(TFile& file, bool writeFileHeader = false);
#if !defined(BI_DATA_NEAR)
    bool      Write(ostream& os, bool writeFileHeader = false);
#endif

    // Work with the dib in PAL or RGB mode
    bool      ChangeModeToPal(const TPalette& pal);
    bool      ChangeModeToRGB(const TPalette& pal);
    TColor    GetColor(int entry) const;
    void      SetColor(int entry, TColor color);
    int       FindColor(TColor color);
    int       MapColor(TColor fromColor, TColor toColor, bool doAll = false);
    uint16    GetIndex(int entry) const;
    void      SetIndex(int entry, uint16 index);
    int       FindIndex(uint16 index);
    int       MapIndex(uint16 fromIndex, uint16 toIndex, bool doAll = false);

    enum {
      MapFace      = 0x01,  // Or these together to control colors to map
      MapText      = 0x02,  // to current SysColor values 
      MapShadow    = 0x04,
      MapHighlight = 0x08,
      MapFrame     = 0x10
    };
    void      MapUIColors(uint mapColors, TColor* bkColor = 0);
    
  protected:
    TGdiBase::CheckValid;  // make this function available to derivatives
    TGdiBase::Handle;      // and these members too
    TGdiBase::ShouldDelete;

    BITMAPINFO far* Info;       // Locked global alloc'd block
    void HUGE*      Bits;       // Pointer into above block at bits
    long            NumClrs;
    int             W;
    int             H;
    uint16          Mode;
    bool            IsCore : 1;
    bool            IsResHandle : 1;

    // Protected ctor- derived classes need to fillin handle & get info
    TDib();

    void      InfoFromHandle();
    bool      ReadFile(const char* name);
    bool      Read(TFile& file, bool readFileHeader = false);
#if !defined(BI_DATA_NEAR)
    bool      Read(istream& is, bool readFileHeader = false);
#endif

    bool      LoadResource(HINSTANCE, TResId);

    bool      LoadFile(const char* name) {return ReadFile(name);} // old name

  private:
    TDib& operator =(const TDib&);
};

inline TClipboard& operator <<(TClipboard& clipboard, TDib& dib)
      {dib.ToClipboard(clipboard); return clipboard;}


//----------------------------------------------------------------------------
//   Inlines for abstract GDI object class and derived classes.
//----------------------------------------------------------------------------
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif

inline int TGdiObject::GetObject(int count, void far* object) const {
#if defined(BI_PLAT_WIN32)
# if defined(UNICODE)
    return ::GetObjectW(Handle, count, object);
#  else
    return ::GetObjectA(Handle, count, object);
#  endif
#else
  return ::GetObject(Handle, count, object);
#endif
}

inline bool TPen::GetObject(LOGPEN far& logPen) const {
  return TGdiObject::GetObject(sizeof(logPen), &logPen) != 0;
}

inline bool TBrush::GetObject(LOGBRUSH far& logBrush) const {
  return TGdiObject::GetObject(sizeof(logBrush), &logBrush) != 0;
}

#if defined(BI_PLAT_WIN16)
inline bool TBrush:: UnrealizeObject() {
  return ::UnrealizeObject(Handle);
}
#endif

inline bool TFont::GetObject(LOGFONT far& logFont) const {
  return TGdiObject::GetObject(sizeof(logFont), &logFont) != 0;
}


inline bool TPalette::ResizePalette(uint numEntries) {
  return ::ResizePalette((HPALETTE)Handle, numEntries);
}

inline void TPalette::AnimatePalette(uint start, uint count, const PALETTEENTRY far* entries) {
  ::AnimatePalette((HPALETTE)Handle, start, count, entries);
}

inline uint TPalette::SetPaletteEntries(uint16 start, uint16 count, const PALETTEENTRY far* entries) {
  return ::SetPaletteEntries((HPALETTE)Handle, start, count, entries);
}

inline uint TPalette::SetPaletteEntry(uint16 index, const PALETTEENTRY far& entry) {
  return ::SetPaletteEntries((HPALETTE)Handle, index, 1, &entry);
}

inline uint TPalette::GetPaletteEntries(uint16 start, uint16 count, PALETTEENTRY far* entries) const {
  return ::GetPaletteEntries((HPALETTE)Handle, start, count, entries);
}

inline uint TPalette::GetPaletteEntry(uint16 index, PALETTEENTRY far& entry) const {
  return ::GetPaletteEntries((HPALETTE)Handle, index, 1, &entry);
}

inline uint TPalette::GetNearestPaletteIndex(TColor Color) const {
  return ::GetNearestPaletteIndex((HPALETTE)Handle, Color);
}

inline bool TPalette::GetObject(uint16 far& numEntries) const {
  return TGdiObject::GetObject(sizeof(numEntries), &numEntries);
}

inline uint16 TPalette::GetNumEntries() const {
  uint16 numEntries;
  if (TGdiObject::GetObject(sizeof(numEntries), &numEntries))
    return numEntries;
  return 0;
}

inline uint32 TBitmap::GetBitmapBits(uint32 count, void far* bits) const {
  return ::GetBitmapBits((HBITMAP)Handle, count, bits);
}

inline uint32 TBitmap::SetBitmapBits(uint32 count, const void far* bits) {
  return ::SetBitmapBits((HBITMAP)Handle, count, bits);
}

inline bool TBitmap::GetBitmapDimension(TSize& size) const {
  return ::GetBitmapDimensionEx((HBITMAP)Handle, &size);
}

inline bool TBitmap::SetBitmapDimension(const TSize& size, TSize far* oldSize) {
  return ::SetBitmapDimensionEx((HBITMAP)Handle, size.cx, size.cy, oldSize);
}

inline bool TBitmap::GetObject(BITMAP far& Bitmap) const {
  return TGdiObject::GetObject(sizeof(Bitmap), &Bitmap) != 0;
}


inline void TRegion::SetRectRgn(const TRect& rect) {
  ::SetRectRgn((HRGN)Handle, rect.left, rect.top, rect.right, rect.bottom);
}

inline bool TRegion::operator ==(const TRegion& other) const {
  return ::EqualRgn((HRGN)Handle, other);
}

inline bool TRegion::operator !=(const TRegion& other) const {
  return !::EqualRgn((HRGN)Handle, other);
}

inline bool TRegion::Contains(const TPoint& point) const {
  return ::PtInRegion((HRGN)Handle, point.x, point.y);
}

inline bool TRegion::Touches(const TRect& rect) const {
  return ::RectInRegion((HRGN)Handle, (TRect*)&rect); // API <const> typecast 
}

inline int TRegion::GetRgnBox(TRect& box) const {
  return ::GetRgnBox((HRGN)Handle, &box);
}

inline TRect TRegion::GetRgnBox() const {
  TRect box;
  ::GetRgnBox((HRGN)Handle, &box);
  return box;
}

inline TRegion& TRegion::operator =(const TRegion& source) {
  ::CombineRgn((HRGN)Handle, source, 0, RGN_COPY);
  return *this;
}

inline TRegion& TRegion::operator +=(const TSize& delta) {
  ::OffsetRgn((HRGN)Handle, delta.cx, delta.cy);
  return *this;
}

inline TRegion& TRegion::operator -=(const TSize& delta) {
  ::OffsetRgn((HRGN)Handle, -delta.cx, -delta.cy);
  return *this;
}

inline TRegion& TRegion::operator -=(const TRegion& source) {
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, source, RGN_DIFF);
  return *this;
}

inline TRegion& TRegion::operator &=(const TRegion& source) {
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, source, RGN_AND);
  return *this;
}

inline TRegion& TRegion::operator |=(const TRegion& source) {
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, source, RGN_OR);
  return *this;
}

inline TRegion& TRegion::operator ^=(const TRegion& source) {
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, source, RGN_XOR);
  return *this;
}

#if defined(BI_PLAT_WIN32)
inline bool TIcon::GetIconInfo(ICONINFO far* IconInfo) const {
  return ::GetIconInfo((HICON)Handle, IconInfo);
}

inline bool TCursor::GetIconInfo(ICONINFO far* IconInfo) const {
  return ::GetIconInfo((HICON)(HCURSOR)Handle, IconInfo);
}
#endif


#endif  // OWL_GDIOBJEC_H
