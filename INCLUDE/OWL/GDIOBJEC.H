//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\gdiobjct.h
//   Definition of abstract GDI object class and derived classes
//----------------------------------------------------------------------------
#if !defined(__OWL_GDIOBJEC_H)
#define __OWL_GDIOBJEC_H

#if !defined(__OWL_GDIBASE_H)
  #include <owl\gdibase.h>
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
  #define OBJ_REF_ADD(handle,type) TGdiObject::RefAdd((handle), (type))
  #define OBJ_REF_REMOVE(handle) TGdiObject::RefRemove(handle)
  #define OBJ_REF_INC(handle) TGdiObject::RefInc(handle)
  #if defined(__TRACE)
    #define OBJ_REF_DEC(handle, wantDelete) TGdiObject::RefDec((handle),\
                                                               (wantDelete))
  #else
    #define OBJ_REF_DEC(handle, wantDelete) TGdiObject::RefDec((handle))
  #endif
  #define OBJ_REF_COUNT(handle) TGdiObject::RefCount(handle)
  struct TObjInfo;
#else
  #define OBJ_REF_ADD(handle,type) handle
  #define OBJ_REF_REMOVE(handle) handle
  #define OBJ_REF_INC(handle) handle
  #define OBJ_REF_DEC(handle,wantDelete) handle
  #define OBJ_REF_COUNT(handle) -1
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

    #if !defined(NO_GDI_ORPHAN_CONTROL)
      enum TType {
        None, Pen, Brush, Font, Palette, Bitmap, TextBrush
      };
      static TObjInfo* RefFind(HANDLE object);
      static void      RefAdd(HANDLE handle, TType type);
      static void      RefRemove(HANDLE handle);
      static void      RefInc(HANDLE handle);
      #if defined(__TRACE)
        static void    RefDec(HANDLE handle, BOOL wantDelete);
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
  #if defined(__WIN32__)
    TPen(DWORD penStyle, DWORD width, const TBrush& brush, DWORD styleCount,
         LPDWORD style);
    TPen(DWORD penStyle, DWORD width, const LOGBRUSH& logBrush,
         DWORD styleCount, LPDWORD style);
  #endif

    operator HPEN() const {return HPEN(HGDIOBJ(*this));}

    // Get GDI Pen Object information
    BOOL        GetObject(LOGPEN far& logPen) const;

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
    BOOL        GetObject(LOGBRUSH far& logBrush) const;
    BOOL        UnrealizeObject();

  private:
    TBrush& operator =(const TBrush&);
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
          BYTE pitchAndFamily=DEFAULT_PITCH|FF_DONTCARE,
          BYTE italic=FALSE, BYTE underline=FALSE, BYTE strikeout=FALSE,
          BYTE charSet=1,  // DEFAULT_CHARSET or UNICODE_CHARSET
          BYTE outputPrecision=OUT_DEFAULT_PRECIS,
          BYTE clipPrecision=CLIP_DEFAULT_PRECIS,
          BYTE quality=DEFAULT_QUALITY);

    // CreateFont() matching font ctor
    TFont(int height, int width, int escapement=0, int orientation=0,
          int weight=FW_NORMAL,
          BYTE italic=FALSE, BYTE underline=FALSE, BYTE strikeout=FALSE,
          BYTE charSet=1,  // DEFAULT_CHARSET or UNICODE_CHARSET
          BYTE outputPrecision=OUT_DEFAULT_PRECIS,
          BYTE clipPrecision=CLIP_DEFAULT_PRECIS,
          BYTE quality=DEFAULT_QUALITY,
          BYTE pitchAndFamily=DEFAULT_PITCH|FF_DONTCARE,
          const char far* facename=0);
    TFont(const LOGFONT far* logFont);
    TFont(const TFont&);

    operator HFONT() const {return HFONT(HGDIOBJ(*this));}

    // Get GDI Font Object information
    BOOL        GetObject(LOGFONT far& logFont) const;

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
    TPalette(const BITMAPINFO far* info, UINT flags=0);    //Win 3.0 DIB hdr
    TPalette(const BITMAPCOREINFO far* core, UINT flags=0);//PM 1.0 DIB header
    TPalette(const TDib& dib, UINT flags=0);               // DIB object

    operator HPALETTE() const {return HPALETTE(HGDIOBJ(*this));}

    // Palette functions
    BOOL        ResizePalette(UINT numEntries);
    void        AnimatePalette(UINT start, UINT count, const PALETTEENTRY far* entries);
    UINT        SetPaletteEntries(WORD start, WORD count, const PALETTEENTRY far* entries);
    UINT        SetPaletteEntry(WORD index, const PALETTEENTRY far& entry);
    UINT        GetPaletteEntries(WORD start, WORD count, PALETTEENTRY far* entries) const;
    UINT        GetPaletteEntry(WORD index, PALETTEENTRY far& entry) const;
    UINT        GetNearestPaletteIndex(TColor color) const;
    BOOL        GetObject(WORD far& numEntries) const;
    WORD        GetNumEntries() const;

    // Put this palette onto the clipboard
    void        ToClipboard(TClipboard& Clipboard);
    BOOL        UnrealizeObject() {return ::UnrealizeObject(Handle);}

  protected:
    void        Create(const BITMAPINFO far* info, UINT flags);
    void        Create(const BITMAPCOREINFO far* core, UINT flags);

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

    TBitmap(int width, int height, BYTE planes=1, BYTE bitCount=1, void far* bits=0);
    TBitmap(const BITMAP far* bitmap);
    TBitmap(const TDC& Dc, int width, int height, BOOL discardable = FALSE);
    TBitmap(const TDC& Dc, const TDib& dib, DWORD usage=CBM_INIT);

    TBitmap(const TMetaFilePict& metaFile, TPalette& palette, const TSize& size);
    TBitmap(const TDib& dib, const TPalette* palette = 0);

    TBitmap(HINSTANCE, TResId);

    operator HBITMAP() const {return HBITMAP(HGDIOBJ(*this));}

    // Get/set GDI Object information
    BOOL        GetObject(BITMAP far& bitmap) const;
    int         Width() const;
    int         Height() const;
    BYTE        Planes() const;
    BYTE        BitsPixel() const;
    DWORD       GetBitmapBits(DWORD count, void far* bits) const;
    DWORD       SetBitmapBits(DWORD count, const void far* bits);
    BOOL        GetBitmapDimension(TSize& size) const;
    BOOL        SetBitmapDimension(const TSize& size, TSize far* oldSize=0);

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
    BOOL        operator ==(const TRegion& other) const;
    BOOL        operator !=(const TRegion& other) const;
    BOOL        Contains(const TPoint& point) const;
    BOOL        Touches(const TRect& rect) const;
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
  #if defined(__WIN32__)
    TIcon(const void* resBits, DWORD resSize);
    TIcon(const ICONINFO* iconInfo);
  #endif
    ~TIcon();

    operator HICON() const {return HICON(Handle);}

  #if defined(__WIN32__)
    BOOL      GetIconInfo(ICONINFO* iconInfo) const;
  #endif

  private:
    TIcon(const TIcon&); // Protect against copying of icons
    TIcon& operator =(const TIcon&);
};

//
// class TCursor
// ----- -------
//
// Pseudo-GDI object Icon class.  Can construct an icon from a resource or
// explicit info.  Overloads the destructor since it is not a real GDI object.
//
class _OWLCLASS TCursor : public TGdiObject {
  public:
    // Constructors
    TCursor(HCURSOR handle, TAutoDelete autoDelete = NoAutoDelete);
    TCursor(HINSTANCE, const TCursor& cursor);
    TCursor(HINSTANCE, TResId);
    TCursor(HINSTANCE, const TPoint& hotSpot,
            const TSize& size, void far* andBits, void far* xorBits);
  #if defined(__WIN32__)
    TCursor(const void* resBits, DWORD resSize);
    TCursor(const ICONINFO* iconInfo);
  #endif
    ~TCursor();

    operator HCURSOR() const {return HCURSOR(Handle);}

  #if defined(__WIN32__)
    BOOL      GetIconInfo(ICONINFO* iconInfo) const;
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

    TDib(int width, int height, int nColors, WORD mode=DIB_RGB_COLORS);
    TDib(HINSTANCE, TResId);
    TDib(const char* name);
    TDib(const TBitmap& bitmap, const TPalette* pal = 0);
    ~TDib();

    // Access to the internal structures of the dib
    const BITMAPINFO far*      GetInfo() const {return Info;}
    BITMAPINFO far*            GetInfo() {return Info;}
    const BITMAPINFOHEADER far*GetInfoHeader() const {return &Info->bmiHeader;}
    BITMAPINFOHEADER far*      GetInfoHeader() {return &Info->bmiHeader;}
    const TRgbQuad far*        GetColors() const {return (const TRgbQuad far*)Info->bmiColors;}
    TRgbQuad far*              GetColors() {return (TRgbQuad far*)Info->bmiColors;}
    const WORD far*            GetIndices() const {return (WORD*)Info->bmiColors;}
    WORD far*                  GetIndices() {return (WORD*)Info->bmiColors;}
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
    BOOL      IsOK() const {return Info != 0;}
    BOOL      IsPM() const {return IsCore;}
    int       Width() const {return W;}
    int       Height() const {return H;}
    TSize     Size() const {return TSize(W,H);}
    long      NumColors() const {return NumClrs;}
    WORD      StartScan() const {return 0;}
    WORD      NumScans() const {return WORD(H);}
    WORD      Usage() const {return Mode;}

    BOOL      WriteFile(const char* filename);

    // Work with the dib in PAL or RGB mode
    BOOL      ChangeModeToPal(const TPalette& pal);
    BOOL      ChangeModeToRGB(const TPalette& pal);
    TColor    GetColor(int entry) const;
    void      SetColor(int entry, TColor color);
    int       FindColor(TColor color);
    int       MapColor(TColor fromColor, TColor toColor, BOOL doAll = FALSE);
    WORD      GetIndex(int entry) const;
    void      SetIndex(int entry, WORD index);
    int       FindIndex(WORD index);
    int       MapIndex(WORD fromIndex, WORD toIndex, BOOL doAll = FALSE);

    enum {
      MapFace      = 0x01,  // Or these together to control colors to map
      MapText      = 0x02,  // to current SysColor values 
      MapShadow    = 0x04,
      MapHighlight = 0x08,
      MapFrame     = 0x10
    };
    void      MapUIColors(UINT mapColors, TColor* bkColor = 0);
    
  protected:
    BITMAPINFO far* Info;       // Locked global alloc'd block
    void HUGE*      Bits;       // Pointer into above block at bits
    long            NumClrs;
    int             W;
    int             H;
    WORD            Mode;
    BOOL            IsCore : 4;       //Q 1;
    BOOL            IsResHandle : 4;  //Q 1;

    void      InfoFromHandle();
    BOOL      Read(TFile& file, long offBits = 0);
    BOOL      LoadResource(HINSTANCE, TResId);
    BOOL      LoadFile(const char* name);

  private:
    TDib& operator =(const TDib&);
};

inline TClipboard& operator <<(TClipboard& clipboard, TDib& dib)
      {dib.ToClipboard(clipboard); return clipboard;}



//----------------------------------------------------------------------------
//   Inlines for abstract GDI object class and derived classes.
//----------------------------------------------------------------------------
#if !defined(__OWL_DC_H)
  #include <owl\dc.h>
#endif
#if !defined(__OWL_CLIPBOAR_H)
  #include <owl\clipboar.h>
#endif

inline int TGdiObject::GetObject(int count, void far* object) const {
  #if defined(__WIN32__)
    #if defined(UNICODE)
      return ::GetObjectW(Handle, count, object);
    #else
      return ::GetObjectA(Handle, count, object);
    #endif
  #else
    return ::GetObject(Handle, count, object);
  #endif
}

inline BOOL TPen::GetObject(LOGPEN far& logPen) const {
  return TGdiObject::GetObject(sizeof(logPen), &logPen) != 0;
}

inline BOOL TBrush::GetObject(LOGBRUSH far& logBrush) const {
  return TGdiObject::GetObject(sizeof(logBrush), &logBrush) != 0;
}

#if !defined(__WIN32__)
  inline BOOL TBrush:: UnrealizeObject() {
    return ::UnrealizeObject(Handle);
 }
#endif

inline BOOL TFont::GetObject(LOGFONT far& logFont) const {
  return TGdiObject::GetObject(sizeof(logFont), &logFont) != 0;
}


inline BOOL TPalette::ResizePalette(UINT numEntries) {
  return ::ResizePalette((HPALETTE)Handle, numEntries);
}

inline void TPalette::AnimatePalette(UINT start, UINT count, const PALETTEENTRY far* entries) {
  ::AnimatePalette((HPALETTE)Handle, start, count, entries);
}

inline UINT TPalette::SetPaletteEntries(WORD start, WORD count, const PALETTEENTRY far* entries) {
  return ::SetPaletteEntries((HPALETTE)Handle, start, count, entries);
}

inline UINT TPalette::SetPaletteEntry(WORD index, const PALETTEENTRY far& entry) {
  return ::SetPaletteEntries((HPALETTE)Handle, index, 1, &entry);
}

inline UINT TPalette::GetPaletteEntries(WORD start, WORD count, PALETTEENTRY far* entries) const {
  return ::GetPaletteEntries((HPALETTE)Handle, start, count, entries);
}

inline UINT TPalette::GetPaletteEntry(WORD index, PALETTEENTRY far& entry) const {
  return ::GetPaletteEntries((HPALETTE)Handle, index, 1, &entry);
}

inline UINT TPalette::GetNearestPaletteIndex(TColor Color) const {
  return ::GetNearestPaletteIndex((HPALETTE)Handle, Color);
}

inline BOOL TPalette::GetObject(WORD far& numEntries) const {
  return TGdiObject::GetObject(sizeof(numEntries), &numEntries);
}

inline WORD TPalette::GetNumEntries() const {
  WORD numEntries;
  if (TGdiObject::GetObject(sizeof(numEntries), &numEntries))
    return numEntries;
  return 0;
}

inline DWORD TBitmap::GetBitmapBits(DWORD count, void far* bits) const {
  return ::GetBitmapBits((HBITMAP)Handle, count, bits);
}

inline DWORD TBitmap::SetBitmapBits(DWORD count, const void far* bits) {
  return ::SetBitmapBits((HBITMAP)Handle, count, bits);
}

inline BOOL TBitmap::GetBitmapDimension(TSize& size) const {
  return ::GetBitmapDimensionEx((HBITMAP)Handle, &size);
}

inline BOOL TBitmap::SetBitmapDimension(const TSize& size, TSize far* oldSize) {
  return ::SetBitmapDimensionEx((HBITMAP)Handle, size.cx, size.cy, oldSize);
}

inline BOOL TBitmap::GetObject(BITMAP far& Bitmap) const {
  return TGdiObject::GetObject(sizeof(Bitmap), &Bitmap) != 0;
}


inline void TRegion::SetRectRgn(const TRect& rect) {
  ::SetRectRgn((HRGN)Handle, rect.left, rect.top, rect.right, rect.bottom);
}

inline BOOL TRegion::operator ==(const TRegion& other) const {
  return ::EqualRgn((HRGN)Handle, other);
}

inline BOOL TRegion::operator !=(const TRegion& other) const {
  return !::EqualRgn((HRGN)Handle, other);
}

inline BOOL TRegion::Contains(const TPoint& point) const {
  return ::PtInRegion((HRGN)Handle, point.x, point.y);
}

inline BOOL TRegion::Touches(const TRect& rect) const {
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
#if defined(__WIN32__)
inline BOOL TIcon::GetIconInfo(ICONINFO far* IconInfo) const {
  return ::GetIconInfo((HICON)Handle, IconInfo);
}

inline BOOL TCursor::GetIconInfo(ICONINFO far* IconInfo) const {
  return ::GetIconInfo((HICON)(HCURSOR)Handle, IconInfo);
}
#endif


#endif  // __OWL_GDIOBJEC_H
