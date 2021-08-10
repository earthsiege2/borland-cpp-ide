//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.16  $
//
// Definition of abstract GDI object class and derived classes
//----------------------------------------------------------------------------
#if !defined(OWL_GDIOBJEC_H)
#define OWL_GDIOBJEC_H

#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif
  
class _BIDSCLASS TFile;

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif


#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TDC;
class _OWLCLASS TBrush;
class _OWLCLASS TBitmap;
class _OWLCLASS TDib;
class _OWLCLASS TPalette;
class _OWLCLASS TClipboard;
class _OWLCLASS TMetaFilePict;

//
// Define to not share handles in copy ctors, otherwise these classes may act
// as envelopes and treat the handles as ref counted letters
//
//#define NO_GDI_SHARE_HANDLES

//
// GDI Orphan control element
//
struct TObjInfo;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TGdiObject
// ~~~~~ ~~~~~~~~~~
// Abstract base class for Windows GDI objects. Provides base, destruction &
// orphan control for true GDI objects
//
class _OWLCLASS TGdiObject : private TGdiBase {
  public:
    // Class scoped types
    //
    typedef HGDIOBJ THandle;  // TGdiObject encapsulates an HGDIOBJ

    // Destructor
    //
   ~TGdiObject();  // GDI classes are not polymorphic, & dtor is not virtual

    HGDIOBJ     GetGdiHandle() const;
    operator    HGDIOBJ() const;

    int         GetObject(int count, void far* object) const;
    bool        operator ==(const TGdiObject& other) const;

    bool        IsGDIObject() const;
#if defined(BI_PLAT_WIN32)
    uint32      GetObjectType() const;
#endif

    // GDI handle management & orphan control
    //
    enum TType {
      None, Pen, Brush, Font, Palette, Bitmap, TextBrush
    };

    static TObjInfo* RefFind(HANDLE object);
    static void      RefAdd(HANDLE handle, TType type);
    static void      RefRemove(HANDLE handle);
    static void      RefInc(HANDLE handle);
    static void      RefDec(HANDLE handle, bool wantDelete);
    static int       RefCount(HANDLE handle);

  protected:
    TGdiBase::CheckValid;  // make this function available to derivatives
    TGdiBase::Handle;      // and these members too
    TGdiBase::ShouldDelete;

    // Constructors for use by derived classes only
    //
    TGdiObject();
    TGdiObject(HANDLE handle, TAutoDelete autoDelete = NoAutoDelete);

  private:
    TGdiObject(const TGdiObject&); // Protect against copying of GDI objects
    TGdiObject& operator =(const TGdiObject&);

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
#endif
};

//
// class TPen
// ~~~~~ ~~~~
// GDI Pen class. Can construct a pen from explicit info, or indirectly
//
class _OWLCLASS TPen : public TGdiObject {
  public:
    // Class scoped types
    //
    typedef HPEN THandle;  // TPen encapsulates an HPEN

    // Constructors
    //
    TPen(HPEN handle, TAutoDelete autoDelete = NoAutoDelete);

    TPen(const TColor& color, int width=1, int style=PS_SOLID);
    TPen(const LOGPEN far* logPen);
    TPen(const TPen& src);
#if defined(BI_PLAT_WIN32)
    TPen(uint32 penStyle, uint32 width, const TBrush& brush, uint32 styleCount,
         uint32* style);
    TPen(uint32 penStyle, uint32 width, const LOGBRUSH& logBrush,
         uint32 styleCount, uint32* style);
#endif

    // Type Accessor & Conversion Operator
    //
    HPEN     GetHandle() const;
    operator HPEN() const;

    // Get GDI Pen Object information
    //
    bool        GetObject(LOGPEN far& logPen) const;

  private:
    TPen& operator =(const TPen&);
};

//
// class TBrush
// ~~~~~ ~~~~~~
// GDI Brush class. Can construct a brush from explicit info, creating a
// solid, styled, or patterned brush.  Can also create a brush indirectly.
//
class _OWLCLASS TBrush : public TGdiObject {
  public:
    // Class scoped types
    //
    typedef HBRUSH THandle;  // TBrush encapsulates an HBRUSH

    // Constructors
    //
    TBrush(HBRUSH handle, TAutoDelete autoDelete = NoAutoDelete);

    TBrush(const TColor& color);
    TBrush(const TColor& color, int style);
    TBrush(const TBitmap& pattern);
    TBrush(const TDib& pattern);
    TBrush(const LOGBRUSH far* logBrush);
    TBrush(const TBrush& src);
   ~TBrush();

    // Type Accessor & Conversion Operator
    //
    HBRUSH   GetHandle() const;
    operator HBRUSH() const;

    // Get GDI Brush Object information
    //
    bool        GetObject(LOGBRUSH far& logBrush) const;
#if defined(BI_PLAT_WIN16)
    bool        UnrealizeObject();  // Use TDC::SetBrushOrg() for Win32
#endif

  private:
    TBrush& operator =(const TBrush&);
};

//
// class THatch8x8Brush
// ~~~~~ ~~~~~~~~~~~~~~
// Mini 8x8 monochrome configurable hatch brush class, with predefined patterns
//
class _OWLCLASS THatch8x8Brush : public TBrush {
  public:
    THatch8x8Brush(const uint8 hatch[], const TColor& fgColor=TColor::White,
                   const TColor& bgColor=TColor::Black);
    void     Reconstruct(const uint8 hatch[], const TColor& fgColor, const TColor& bgColor);

    const static uint8 Hatch22F1[8];  // 2-on, 2-off, offset 1 per row forward
    const static uint8 Hatch13F1[8];  // 1-on, 3-off, offset 1 per row forward
    const static uint8 Hatch11F1[8];  // 1-on, 1-off, offset 1 per row
    const static uint8 Hatch22B1[8];  // 2-on, 2-off, offset 1 per row backward
    const static uint8 Hatch13B1[8];  // 1-on, 3-off, offset 1 per row backward

  private:
    static HBRUSH Create(const uint8 hatch[], const TColor& fgColor, const TColor& bgColor);
};

//
// class TFont
// ~~~~~ ~~~~~
// GDI Font class.  Can construct a font from explicit info, or indirectly.
//
class _OWLCLASS TFont : public TGdiObject {
  public:
    // Class scoped types
    //
    typedef HFONT THandle;  // TFont encapsulates an HFONT

    // Constructors
    //
    TFont(HFONT handle, TAutoDelete autoDelete = NoAutoDelete);

    // Convenient font ctor
    //
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
    //
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
    TFont(const TFont& src);

    // Type Accessor & Conversion Operator
    //
    HFONT       GetHandle() const;
    operator    HFONT() const;

    // Retrieve info about this font when selected in the specified dc
    //
    TEXTMETRIC  GetTextMetrics(TDC& dc) const;
    void        GetTextMetrics(TEXTMETRIC& tm, TDC& dc) const;

    // Retrieve info about this font when selected in a screen DC
    //
    TEXTMETRIC  GetTextMetrics() const;
    void        GetTextMetrics(TEXTMETRIC& tm) const;

    // Retrieve specific attribute of font
    //
    int         GetHeight() const;
    int         GetHeight(TDC& dc) const;
    int         GetAveWidth() const;
    int         GetAveWidth(TDC& dc) const;
    int         GetMaxWidth() const;
    int         GetMaxWidth(TDC& dc) const;
    TSize       GetTextExtent(const char far* text) const;
    TSize       GetTextExtent(TDC& dc, const char far* text) const;

    // Retrieve attributes of logical font
    //
    bool            GetObject(LOGFONT far& logFont) const;
    const string&   GetFaceName() const;
    uint8           GetPitchAndFamily() const;

  private:
    TFont& operator =(const TFont&);
};

//
// class TDefaultGUIFont
// ~~~~~ ~~~~~~~~~~~~~~~
// Default GUI font classe encapsulating font used for user interface objects
// such as menus and dialog boxes.
//
class _OWLCLASS TDefaultGUIFont : public TFont {
  public:
    TDefaultGUIFont();
};

//
// class TPalette
// ~~~~~ ~~~~~~~~
// GDI Palette class.  Can construct a palette from explicit info, or
// indirectly from various color table types that are used by DIBs.
//
class _OWLCLASS TPalette : public TGdiObject {
  public:
    // Class scoped types
    //
    typedef HPALETTE THandle;  // TPalette encapsulates an HPALETTE

    // Constructors
    //
    TPalette(HPALETTE handle, TAutoDelete autoDelete = NoAutoDelete);

    TPalette(const TClipboard&);
    TPalette(const TPalette& src);          // Deep copy whole palette

    TPalette(const LOGPALETTE far* logPalette);
    TPalette(const PALETTEENTRY far* entries, int count);
    TPalette(const BITMAPINFO far* info, uint flags=0);    //Win 3.0 DIB hdr
    TPalette(const TDib& dib, uint flags=0);               // DIB object

    // Type Accessor & Conversion Operator
    //
    HPALETTE GetHandle() const;
    operator HPALETTE() const;

    // Palette functions
    //
    bool        ResizePalette(uint numEntries);
    void        AnimatePalette(uint start, uint count, const PALETTEENTRY far* entries);
    uint        SetPaletteEntries(uint16 start, uint16 count, const PALETTEENTRY far* entries);
    uint        SetPaletteEntry(uint16 index, const PALETTEENTRY far& entry);
    uint        GetPaletteEntries(uint16 start, uint16 count, PALETTEENTRY far* entries) const;
    uint        GetPaletteEntry(uint16 index, PALETTEENTRY far& entry) const;
    uint        GetNearestPaletteIndex(const TColor& color) const;
    bool        GetObject(uint16 far& numEntries) const;
    uint16      GetNumEntries() const;

    // Put this palette onto the clipboard
    //
    void        ToClipboard(TClipboard& Clipboard);
    bool        UnrealizeObject();

  protected:
    void        Create(const BITMAPINFO far* info, uint flags);

  private:
    TPalette& operator =(const TPalette&);

#if defined(OWL2_COMPAT)
  public:
    TPalette(const BITMAPCOREINFO far* core, uint flags=0);//PM 1.0 DIB header
  protected:
    void        Create(const BITMAPCOREINFO far* core, uint flags);
#endif
};

//
// class TBitmap
// ~~~~~ ~~~~~~~
// GDI Bitmap class.  Can construct a bitmap from many sources.  This bitmap
// is the lowest level object that is actually selected into a DC.
//
class _OWLCLASS TBitmap : public TGdiObject {
  public:
    // Class scoped types
    //
    typedef HBITMAP THandle;  // TBitmap encapsulates an HBITMAP

    // Constructors
    //
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
   ~TBitmap();

    // Type Accessor & Conversion Operator
    //
    HBITMAP  GetHandle() const;
    operator HBITMAP() const;

    // Get/set GDI Object information
    //
    bool        GetObject(BITMAP far& bitmap) const;
    int         Width() const;
    int         Height() const;
    TSize       Size() const;
    int         Planes() const;
    int         BitsPixel() const;
    uint32      GetBitmapBits(uint32 count, void far* bits) const;
    uint32      SetBitmapBits(uint32 count, const void far* bits);
    bool        GetBitmapDimension(TSize& size) const;
    bool        SetBitmapDimension(const TSize& size, TSize far* oldSize=0);

    // Put this bitmap onto the clipboard
    //
    void  ToClipboard(TClipboard& clipboard);

  protected:
    TBitmap();

    // Create a bitmap & fill in it's Handle
    //
    void Create(const TDib& dib, const TPalette& palette);
    void Create(const TBitmap& src);

  private:
    TBitmap& operator =(const TBitmap&);
};

//
// class TRegion
// ~~~~~ ~~~~~~~
// GDI Region class. Can construct a region from various shapes
//
class _OWLCLASS TRegion : private TGdiBase {
  public:
    // Class scoped types
    //
    typedef HRGN THandle;  // TRegion encapsulates an HRGN

    // Constructors
    //
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
    //
    void        SetRectRgn(const TRect& rect);

    // Type Accessor & Conversion Operator
    //
    HRGN     GetHandle() const;
    operator HRGN() const;

    // Test and information functions/operators
    //
    bool        operator ==(const TRegion& other) const;
    bool        operator !=(const TRegion& other) const;
    bool        Contains(const TPoint& point) const;
    bool        Touches(const TRect& rect) const;
    int         GetRgnBox(TRect& box) const;
    TRect       GetRgnBox() const;

    // Assignment operators
    //
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

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
#endif
};

//
// class TIcon
// ~~~~~ ~~~~~
// GDI object Icon class.  Can construct an icon from a resource or
// explicit info.  Overloads the destructor since it is not a regular GDI
// object.
//
class _OWLCLASS TIcon : private TGdiBase {
  public:
    // Class scoped types
    //
    typedef HICON THandle;  // TIcon encapsulates an HICON

    // Constructors
    //
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

    // Type Accessor & Conversion Operator
    //
    HICON    GetHandle() const;
    operator HICON() const;

    bool     operator ==(const TIcon& other) const;

#if defined(BI_PLAT_WIN32)
    bool     GetIconInfo(ICONINFO* iconInfo) const;
#endif

  private:
    TIcon(const TIcon&); // Protect against copying of icons
    TIcon& operator =(const TIcon&);

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
#endif
};

//
// class TCursor
// ~~~~~ ~~~~~~~
// GDI object Cursor class.  Can construct a cursor from a resource or
// explicit info.  Overloads the destructor since it is not a regular GDI
// object.
//
class _OWLCLASS TCursor : public TGdiBase {
  public:
    // Class scoped types
    //
    typedef HCURSOR THandle;  // TCursor encapsulates an HCURSOR

    // Constructors
    //
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

    // Type Accessor & Conversion Operator
    //
    HCURSOR  GetHandle() const;
    operator HCURSOR() const;

    bool     operator ==(const TCursor& other) const;

#if defined(BI_PLAT_WIN32)
    bool     GetIconInfo(ICONINFO* iconInfo) const;
#endif

  private:
    TCursor(const TCursor&); // Protect against copying of cursors
    TCursor& operator =(const TCursor&);

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
#endif
};

//
// class TDib
// ~~~~~ ~~~~
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
    // Class scoped types
    //
    typedef HANDLE THandle;  // TDib encapsulates an memory HANDLE w/ a DIB

    // Constructors and destructor
    //
    TDib(HGLOBAL handle, TAutoDelete autoDelete = NoAutoDelete);
    TDib(const TClipboard& clipboard);
    TDib(const TDib& src);

    TDib(int width, int height, uint32 nColors, uint16 mode=DIB_RGB_COLORS);
    TDib(HINSTANCE module, TResId resid);
    TDib(const char* name);
    TDib(TFile& file, bool readFileHeader = true);
#if !defined(BI_DATA_NEAR)
    TDib(istream& is, bool readFileHeader = false);
#endif
    TDib(const TBitmap& bitmap, const TPalette* pal = 0);
   ~TDib();

    // Comparison operator
    //
    bool     operator ==(const TDib& other) const;

    // Access to the internal structures of the dib
    //
    const BITMAPINFO far*      GetInfo() const;
    BITMAPINFO far*            GetInfo();
    const BITMAPINFOHEADER far*GetInfoHeader() const;
    BITMAPINFOHEADER far*      GetInfoHeader();
    const TRgbQuad far*        GetColors() const;
    TRgbQuad far*              GetColors();
    const uint16 far*          GetIndices() const;
    uint16 far*                GetIndices();
    const void HUGE*           GetBits() const;
    void HUGE*                 GetBits();

    // Type convert this dib by returning pointers to internal structures
    //
    HANDLE   GetHandle() const;
    operator HANDLE() const;

    operator const BITMAPINFO far*() const;
    operator BITMAPINFO far*();
    operator const BITMAPINFOHEADER far*() const;
    operator BITMAPINFOHEADER far*();
    operator const TRgbQuad far*() const;
    operator TRgbQuad far*();

    // Put this Dib onto the clipboard
    //
    void      ToClipboard(TClipboard& clipboard);

    // Get info about this Dib
    //
    bool      IsOK() const;         // Is DIB OK & info available
    bool      IsPM() const;         // Is DIB stored in PM core format
    int       Width() const;        // Width in pixels
    int       Height() const;       // Height in pixels
    int       FlippedY(int y) const;// Y flipped the other direction
    TSize     Size() const;         // Width & Height in pixels
    int       BitsPixel() const;    // Bits per pixel: 2, 4, 8, 16, 24, 32
    int       Pitch() const;        // Width in bytes, or bytes per scan
    uint32    Compression() const;  // Compression & encoding flags
    uint32    SizeImage() const;    // Size of the DIB image bits in bytes

    long      NumColors() const;    // Number of colors in color table
    uint      StartScan() const;    // Starting scan line
    uint      NumScans() const;     // Number of scans
    int32     SizeColors() const;   // Size of the color table in bytes.
    uint32    SizeDib() const;      // Memory size of DIB in bytes
    uint16    Usage() const;        // The mode or usage of the color table

    int       XOffset(uint16 x) const;
    int       YOffset(uint16 y) const;

    void HUGE* PixelPtr(uint16 x, uint16 y);

    // Write this dib to a file by name, to file object or to an ostream
    //
    bool      WriteFile(const char* filename);
    bool      Write(TFile& file, bool writeFileHeader = false);
#if !defined(BI_DATA_NEAR)
    bool      Write(ostream& os, bool writeFileHeader = false);
#endif

    // Work with the color table in RGB mode
    //
    TColor    GetColor(int entry) const;
    void      SetColor(int entry, const TColor& color);
    int       FindColor(const TColor& color);
    int       MapColor(const TColor& fromColor, const TColor& toColor, bool doAll = false);

    // Work with the color table in Palette relative mode
    //
    uint16    GetIndex(int entry) const;
    void      SetIndex(int entry, uint16 index);
    int       FindIndex(uint16 index);
    int       MapIndex(uint16 fromIndex, uint16 toIndex, bool doAll = false);

    // Change from RGB to Palette, or from Palette to RGB color table mode
    //
    bool      ChangeModeToPal(const TPalette& pal);
    bool      ChangeModeToRGB(const TPalette& pal);

    // Map colors in color table matching stock UI colors to current UI colors
    //
    enum {
      MapFace      = 0x01,  // Or these together to control colors to map
      MapText      = 0x02,  // to current SysColor values
      MapShadow    = 0x04,
      MapHighlight = 0x08,
      MapFrame     = 0x10
    };
    void      MapUIColors(uint mapColors, const TColor* bkColor = 0);

    // Dib->Dib Blitting
    //
    void CopyBlt(int dstX, int dstY, TDib& srcDib, int width=0, int height=0);
    void SpriteBlt(int dstX, int dstY, TDib& srcDib,
                   int width=0, int height=0, uint8 transparentColor=0);
    void MapToPalette(const TPalette& pal);

    // Internal DIB file Reda/Write functions talk to these interfaces
    //
    class _OWLCLASS IFileIn {
      public:
        virtual bool Read(void HUGE* buffer, long size) = 0;
        virtual void Skip(long size) = 0;
    };
    class _OWLCLASS IFileOut {
      public:
        virtual bool Write(void HUGE* buffer, long size) = 0;
    };

  protected:
    TGdiBase::CheckValid;  // make this function available to derivatives
    TGdiBase::Handle;      // and these members too
    TGdiBase::ShouldDelete;

    // Protected ctor- derived classes need to fill in handle & get info
    //
    TDib();

    void      InfoFromHeader(const BITMAPINFOHEADER& infoHeader);
    void      InfoFromHandle();  // Get info & members from handle
    void      CopyOnWrite();     // Make sure we can write on info
#if defined(BI_PLAT_WIN32)
    void      ResToMemHandle();  // Perform RO res handle to mem handle copy
#endif

    bool      ReadFile(const char* name);
    bool      Read(TFile& file, bool readFileHeader = false);
#if !defined(BI_DATA_NEAR)
    bool      Read(istream& is, bool readFileHeader = false);
#endif

    bool      LoadResource(HINSTANCE, TResId);

    bool      Read(IFileIn& in, bool readFileHeader = false);
    bool      Write(IFileOut& out, bool writeFileHeader = false);

    static int ScanBytes(long w, int bpp); // Width+bpp to dword aligned bytes

    void MultiBlt(int type, int dstX, int dstY, TDib& srcDib,
                  int width, int height, uint8 transparentColor=0);

  protected_data:
    BITMAPINFO far* Info;       // Locked global alloc'd block, has sub ptrs:
    uint32 far*     Mask;       //   Color mask[3] for 16 & 32 bpp bmps
    TRgbQuad far*   Colors;     //   Color table[NumClrs] for any bmp
    void HUGE*      Bits;       //   Pointer to bits (pixels)
    long            NumClrs;    // Number of colors in color table
    uint16          Mode;       // Palette or RGB based pixels
    bool            IsResHandle;// Is Handle a resource handle (vs. Memory)

  private:
    // Prevent accidental copying of object
    //
    TDib& operator =(const TDib&);

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
    bool      LoadFile(const char* name);  // Old OWL 2.0 name
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations for abstract GDI object class and derived classes.
//

#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif

//
// Get the palette object from the clipboard.
//
inline TClipboard& operator <<(TClipboard& clipboard, TPalette& palette)
{
  palette.ToClipboard(clipboard);
  return clipboard;
}

//
// Get the bitmap object from the clipboard.
//
inline TClipboard& operator <<(TClipboard& clipboard, TBitmap& bitmap)
{
  bitmap.ToClipboard(clipboard);
  return clipboard;
}

//
// Get the DIB from the clipboard.
//
inline TClipboard& operator <<(TClipboard& clipboard, TDib& dib)
{
  dib.ToClipboard(clipboard);
  return clipboard;
}

//
// Return the handle of the GDI object.
//
inline HGDIOBJ TGdiObject::GetGdiHandle() const
{
  return HGDIOBJ(Handle);
}

//
// Return the handle of the GDI object.
//
inline TGdiObject::operator HGDIOBJ() const
{
  return GetGdiHandle();
}

//
// Returns true if the handles are equal.
// This is a binary compare.
//
inline bool TGdiObject::operator ==(const TGdiObject& other) const
{
  return Handle == other.Handle;
}

//
// Retrieve the object's attributes into a buffer.
//
inline int TGdiObject::GetObject(int count, void far* object) const
{
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

#if defined(BI_PLAT_WIN32)
//
// Return the type of the GDI object.
//
inline uint32 TGdiObject::GetObjectType() const
{
  return ::GetObjectType(GetGdiHandle());
}
#endif

//
// Returns true if this represents a real GDI object.
//
inline bool TGdiObject::IsGDIObject() const
{
#if defined(BI_PLAT_WIN16)
  return ::IsGDIObject(GetGdiHandle()) != 0;
#else
  return GetObjectType() != 0;
#endif
}

//
// Return the handle of the pen with type HPEN.
//
inline HPEN TPen::GetHandle() const
{
  return HPEN(GetGdiHandle());
}

//
// Return the handle of the pen with type HPEN.
//
inline TPen::operator HPEN() const
{
  return GetHandle();
}

//
// Retrieve the attributes for the pen.
//
inline bool TPen::GetObject(LOGPEN far& logPen) const
{
  return TGdiObject::GetObject(sizeof(logPen), &logPen) != 0;
}

//
// Return the handle of the brush with type HBRUSH.
//
inline HBRUSH TBrush::GetHandle() const
{
  return HBRUSH(GetGdiHandle());
}

//
// Return the handle of the brush with type HBRUSH.
//
inline TBrush::operator HBRUSH() const
{
  return GetHandle();
}

//
// Retrieve the attributes of the brush.
//
inline bool TBrush::GetObject(LOGBRUSH far& logBrush) const
{
  return TGdiObject::GetObject(sizeof(logBrush), &logBrush) != 0;
}

#if defined(BI_PLAT_WIN16)
//
// Unrealize the object.
//
inline bool TBrush:: UnrealizeObject()
{
  return ::UnrealizeObject(GetHandle());
}
#endif

//
// Return the handle of the font with type HFONT.
//
inline HFONT TFont::GetHandle() const
{
  return HFONT(GetGdiHandle());
}

//
// Return the handle of the font with type HFONT.
//
inline TFont::operator HFONT() const
{
  return GetHandle();
}

//
// Retrieve the attributes of the font.
//
inline bool TFont::GetObject(LOGFONT far& logFont) const
{
  return TGdiObject::GetObject(sizeof(logFont), &logFont) != 0;
}

//
// Return the height of the font.
//
inline int TFont::GetHeight() const
{
  return int(GetTextMetrics().tmHeight);
}

//
// Return the height of the font if selected into the DC.
//
inline int TFont::GetHeight(TDC& dc) const
{
  return int(GetTextMetrics(dc).tmHeight);
}

//
// Return the average width of the characters in the font.
//
inline int TFont::GetAveWidth() const
{
  return int(GetTextMetrics().tmAveCharWidth);
}

//
// Return the average width of the characters in the font if selected into
// the DC.
//
inline int TFont::GetAveWidth(TDC& dc) const
{
  return int(GetTextMetrics(dc).tmAveCharWidth);
}

//
// Return the maximum width of the characters in the font.
//
inline int TFont::GetMaxWidth() const
{
  return int(GetTextMetrics().tmMaxCharWidth);
}

//
// Return the maximum width of the characters in the font if selected into
// the DC.
//
inline int TFont::GetMaxWidth(TDC& dc) const
{
  return int(GetTextMetrics(dc).tmMaxCharWidth);
}

//
// Return the handle of the palette.
//
inline HPALETTE TPalette::GetHandle() const
{
  return HPALETTE(GetGdiHandle());
}

//
// Return the handle of the palette.
//
inline TPalette::operator HPALETTE() const
{
  return GetHandle();
}

//
// Unrealize the palette.
//
inline bool TPalette::UnrealizeObject()
{
  return ::UnrealizeObject(Handle);
}

//
// Resize the palette to numEntries.
//
inline bool TPalette::ResizePalette(uint numEntries)
{
  return ::ResizePalette(GetHandle(), numEntries);
}

//
// Animate palette from entry 'start' for 'count' entries.
//
inline void TPalette::AnimatePalette(uint start, uint count, const PALETTEENTRY far* entries)
{
  ::AnimatePalette(GetHandle(), start, count, entries);
}

//
// Change the palette entries.
//
inline uint TPalette::SetPaletteEntries(uint16 start, uint16 count, const PALETTEENTRY far* entries)
{
  return ::SetPaletteEntries(GetHandle(), start, count, entries);
}

//
// Change one palette entry.
//
inline uint TPalette::SetPaletteEntry(uint16 index, const PALETTEENTRY far& entry)
{
  return ::SetPaletteEntries(GetHandle(), index, 1, &entry);
}

//
// Retrieve the palette entries.
//
inline uint TPalette::GetPaletteEntries(uint16 start, uint16 count, PALETTEENTRY far* entries) const
{
  return ::GetPaletteEntries(GetHandle(), start, count, entries);
}

//
// Retrieve one palette entry.
//
inline uint TPalette::GetPaletteEntry(uint16 index, PALETTEENTRY far& entry) const
{
  return ::GetPaletteEntries(GetHandle(), index, 1, &entry);
}

//
// Retrieve the index of the palette entry that matches closest to the
// specified color.
//
inline uint TPalette::GetNearestPaletteIndex(const TColor& Color) const
{
  return ::GetNearestPaletteIndex(GetHandle(), Color);
}

//
// Retrieve the attributes of the palette object.
//
inline bool TPalette::GetObject(uint16 far& numEntries) const
{
  return TGdiObject::GetObject(sizeof(numEntries), &numEntries);
}

//
// Return the number of entries in the palette.
//
inline uint16 TPalette::GetNumEntries() const
{
  uint16 numEntries;
  if (TGdiObject::GetObject(sizeof(numEntries), &numEntries))
    return numEntries;
  return 0;
}

//
// Return the handle of the bitmap of type BITMAP.
//
inline HBITMAP TBitmap::GetHandle() const
{
  return HBITMAP(GetGdiHandle());
}

//
// Return the handle of the bitmap of type BITMAP.
//
inline TBitmap::operator HBITMAP() const
{
  return GetHandle();
}

//
// Retrieve the bits of the bitmap into the buffer.
//
inline uint32 TBitmap::GetBitmapBits(uint32 count, void far* bits) const
{
  return ::GetBitmapBits(GetHandle(), count, bits);
}

//
// Set the bits of the bitmap.
//
inline uint32 TBitmap::SetBitmapBits(uint32 count, const void far* bits)
{
  return ::SetBitmapBits(GetHandle(), count, bits);
}

//
// Retrieve the dimensions of the bitmap.
//
inline bool TBitmap::GetBitmapDimension(TSize& size) const
{
  return ::GetBitmapDimensionEx(GetHandle(), &size);
}

//
// Resize the bitmap.
//
inline bool TBitmap::SetBitmapDimension(const TSize& size, TSize far* oldSize)
{
  return ::SetBitmapDimensionEx(GetHandle(), size.cx, size.cy, oldSize);
}

//
// Retrieve the attributes of the bitmap.
//
inline bool TBitmap::GetObject(BITMAP far& Bitmap) const
{
  return TGdiObject::GetObject(sizeof(Bitmap), &Bitmap) != 0;
}

//
// Return the handle of the region with type HREGION.
//
inline HRGN TRegion::GetHandle() const
{
  return HRGN(Handle);
}

//
// Return the handle of the region with type HREGION.
//
inline TRegion::operator HRGN() const
{
  return GetHandle();
}

//
// Changes region into a rectangular region.
//
inline void TRegion::SetRectRgn(const TRect& rect)
{
  ::SetRectRgn(GetHandle(), rect.left, rect.top, rect.right, rect.bottom);
}

//
// Return true if the regions are identical (equal in size and shape).
//
inline bool TRegion::operator ==(const TRegion& other) const
{
  return ::EqualRgn(GetHandle(), other);
}

//
// Return the opposite of operator ==.
//
inline bool TRegion::operator !=(const TRegion& other) const
{
  return !::EqualRgn(GetHandle(), other);
}

//
// Return true if the point is within the region.
//
inline bool TRegion::Contains(const TPoint& point) const
{
  return ::PtInRegion(GetHandle(), point.x, point.y);
}

//
// Return true if any part of the rectangle is within the region.
//
inline bool TRegion::Touches(const TRect& rect) const
{
  return ::RectInRegion(GetHandle(), (TRect*)&rect); // API <const> typecast
}

//
// Return the bounding rectangle of the region.
//
inline int TRegion::GetRgnBox(TRect& box) const
{
  return ::GetRgnBox(GetHandle(), &box);
}

//
// Return the bounding rectangle of the region.
//
inline TRect TRegion::GetRgnBox() const
{
  TRect box;
  ::GetRgnBox(GetHandle(), &box);
  return box;
}

//
// Makes this region the same as the passed-in region.
//
inline TRegion& TRegion::operator =(const TRegion& source)
{
  ::CombineRgn(GetHandle(), source, 0, RGN_COPY);
  return *this;
}

//
// Moves the region by delta.
//
inline TRegion& TRegion::operator +=(const TSize& delta)
{
  ::OffsetRgn(GetHandle(), delta.cx, delta.cy);
  return *this;
}

//
// Moves the region negatively by delta.
//
inline TRegion& TRegion::operator -=(const TSize& delta)
{
  ::OffsetRgn(GetHandle(), -delta.cx, -delta.cy);
  return *this;
}

//
// Return the subtraction of one region from another.
//
inline TRegion& TRegion::operator -=(const TRegion& source)
{
  ::CombineRgn(GetHandle(), GetHandle(), source, RGN_DIFF);
  return *this;
}

//
// Return the intersection of two regions.
//
inline TRegion& TRegion::operator &=(const TRegion& source)
{
  ::CombineRgn(GetHandle(), GetHandle(), source, RGN_AND);
  return *this;
}

//
// Return the union of two regions.
//
inline TRegion& TRegion::operator |=(const TRegion& source)
{
  ::CombineRgn(GetHandle(), GetHandle(), source, RGN_OR);
  return *this;
}

//
// Return the exclusive-or of two regions.
//
inline TRegion& TRegion::operator ^=(const TRegion& source)
{
  ::CombineRgn(GetHandle(), GetHandle(), source, RGN_XOR);
  return *this;
}

//
// Return the handle of the icon with type HICON.
//
inline HICON TIcon::GetHandle() const
{
  return HICON(Handle);
}

//
// Return the handle of the icon with type HICON.
//
inline TIcon::operator HICON() const
{
  return GetHandle();
}

//
// Return true if the handles of two icons are identical.
//
inline bool TIcon::operator ==(const TIcon& other) const
{
  return Handle == other.Handle;
}

#if defined(BI_PLAT_WIN32)
//
// Retrieve attributes about the icon.
//
inline bool TIcon::GetIconInfo(ICONINFO* IconInfo) const
{
  return ::GetIconInfo(GetHandle(), IconInfo);
}

//
// Retrieve attributes about the cursor.
//
inline bool TCursor::GetIconInfo(ICONINFO* IconInfo) const
{
  return ::GetIconInfo((HICON)GetHandle(), IconInfo);
}
#endif

//
// Return the handle of the cursor with type HCURSOR.
//
inline HCURSOR TCursor::GetHandle() const
{
  return HCURSOR(Handle);
}

//
// Return the handle of the cursor with type HCURSOR.
//
inline TCursor::operator HCURSOR() const
{
  return GetHandle();
}

//
// Return true if the two handles for the cursors are identical.
//
inline bool TCursor::operator ==(const TCursor& other) const
{
  return Handle == other.Handle;
}

//
// Return true if the two handles for the DIBs are identical.
//
inline bool TDib::operator ==(const TDib& other) const
{
  return Handle == other.Handle;
}

//
// Return the BITMAPINFO of the DIB.
//
inline const BITMAPINFO far* TDib::GetInfo() const
{
  return Info;
}

//
// Return the BITMAPINFO of the DIB.
//
inline BITMAPINFO far* TDib::GetInfo()
{
  return Info;
}

//
// Return the BITMAPINFOHEADER of the DIB.
//
inline const BITMAPINFOHEADER far* TDib::GetInfoHeader() const
{
  return &Info->bmiHeader;
}

//
// Return the BITMAPINFOHEADER of the DIB.
//
inline BITMAPINFOHEADER far* TDib::GetInfoHeader()
{
  return &Info->bmiHeader;
}

//
// Return the colors used by the DIB.
//
inline const TRgbQuad far* TDib::GetColors() const
{
  return Colors;
}

//
// Return the colors used by the DIB.
//
inline TRgbQuad far* TDib::GetColors()
{
  return Colors;
}

//
// Return the number of colors used by the DIB.
//
inline const uint16 far* TDib::GetIndices() const
{
  return (const uint16*)Colors;
}

//
// Return the number of colors used by the DIB.
//
inline uint16 far* TDib::GetIndices()
{
  return (uint16*)Colors;
}

//
// Retrieve the bits of the DIB.
//
inline const void HUGE* TDib::GetBits() const
{
  return Bits;
}

//
// Retrieve the bits of the DIB.
//
inline void HUGE* TDib::GetBits()
{
  return Bits;
}

//
// Return the handle of the DIB with type HANDLE.
//
inline HANDLE TDib::GetHandle() const
{
  return Handle;
}

//
// Return the handle of the DIB with type HANDLE.
//
inline TDib::operator HANDLE() const
{
  return GetHandle();
}

//
// Return the BITMAPINFO of the DIB.
//
inline TDib::operator const BITMAPINFO far*() const
{
  return GetInfo();
}

//
// Return the BITMAPINFO of the DIB.
//
inline TDib::operator BITMAPINFO far*()
{
  return GetInfo();
}

//
// Return the BITMAPINFOHEADER of the DIB.
//
inline TDib::operator const BITMAPINFOHEADER far*() const
{
  return GetInfoHeader();
}

//
// Return the BITMAPINFOHEADER of the DIB.
//
inline TDib::operator BITMAPINFOHEADER far*()
{
  return GetInfoHeader();
}

//
// Return the colors used by the DIB.
//
inline TDib::operator const TRgbQuad far*() const
{
  return GetColors();
}

//
// Return the colors used by the DIB.
//
inline TDib::operator TRgbQuad far*()
{
  return GetColors();
}

//
// Return true if the DIB is valid.
//
inline bool TDib::IsOK() const
{
  return Info != 0;
}

//
// Return false always since PM bitmaps are not supported.
//
inline bool TDib::IsPM() const
{
  return false;
}

//
// Return the width of the DIB.
//
inline int TDib::Width() const
{
  return (int)Info->bmiHeader.biWidth;
}

//
// Return the height of the DIB.
//
inline int TDib::Height() const
{
  return (int)Info->bmiHeader.biHeight;
}

//
// Return the coordinate of y if the direction of the y-axis were reversed.
//
inline int TDib::FlippedY(int y) const
{
  return int(Info->bmiHeader.biHeight - 1 - y);
}

//
// Return the dimension of the DIB.
//
inline TSize TDib::Size() const
{
  return TSize(Width(), Height());
}

//
// Return the number of bytes used to store a scanline for the DIB.
// Rounded up to the nearest 32-bit boundary.
//
inline int TDib::ScanBytes(long w, int bpp)
{
  return (int)(((w*bpp+31)&(~31))/8);
}

//
// Return the number of bits used to store a pixel for the DIB.
//
inline int TDib::BitsPixel() const
{
  return Info->bmiHeader.biBitCount;
}

//
// Size of scan in bytes =
//   Pixel Width * bits per pixel rounded up to a uint32 boundary
//
inline int TDib::Pitch() const
{
  return ScanBytes(Width(), BitsPixel());
}

//
// Return type of compression for bottom-up DIBs.
//
inline uint32 TDib::Compression() const
{
  return Info->bmiHeader.biCompression;
}

//
// Return number of bytes used to store the image.
//
inline uint32 TDib::SizeImage() const
{
  return Info->bmiHeader.biSizeImage;
}

//
// Return number of colors used by the DIB.
//
inline long TDib::NumColors() const
{
  return NumClrs;
}

//
// Return the starting scan line.
// Always 0 because all DIBs are normalized.
//
inline uint TDib::StartScan() const
{
  return 0;
}

//
// Return number of scan lines.
// Always same as height of the DIB.
//
inline uint TDib::NumScans() const
{
  return Height();
}

//
// Return number of colors times the size of each entry in the table,
// whether it is an RGB color table or palette index table.
//
inline int32 TDib::SizeColors() const
{
  return Mode == DIB_RGB_COLORS ?
           (long)NumColors() * sizeof(RGBQUAD) :  // RGB color table
           (long)NumColors() * sizeof(uint16);    // Palette index color table
}

//
// Size of dib is measured as the end of the bits minus the start of the block
//
inline uint32 TDib::SizeDib() const
{
  return ((char HUGE*)Bits + SizeImage()) - (char HUGE*)Info;
}

//
// Return whether the DIB has palette color entries or RGB color entries.
//
inline uint16 TDib::Usage() const
{
  return Mode;
}

//
// Return the byte offset from the start of the scan line to the xth pixel.
//
inline int TDib::XOffset(uint16 x) const
{
  return int((uint32)x * BitsPixel() / 8);
}

//
// Return the starting position of the scan line.
//
inline int TDib::YOffset(uint16 y) const
{
  return int((uint32)Pitch() * y);
}

//
// Return the byte of where the pixel is located.
//
inline void HUGE* TDib::PixelPtr(uint16 x, uint16 y)
{
  return (uint8 HUGE*)Bits + XOffset(x) + YOffset(y);
}

//
// Copy the DIB.
//
inline void TDib::CopyOnWrite()
{
#if defined(BI_PLAT_WIN32)
  if (IsResHandle)
    ResToMemHandle();
#endif
}

//
// Copy the DIB by copying the bits.
//
inline void TDib::CopyBlt(int dstX, int dstY, TDib& srcDib, int width, int height)
{
  MultiBlt(0, dstX, dstY, srcDib, width, height);
}

//
// Transparent bit the DIB.
//
inline void TDib::SpriteBlt(int dstX, int dstY, TDib& srcDib,
                      int width, int height, uint8 transparentColor)
{
  MultiBlt(1, dstX, dstY, srcDib, width, height, transparentColor);
}

#if defined(OWL2_COMPAT)
//
// Load the DIB from the external file
//
inline bool TDib::LoadFile(const char* name)
{
  return ReadFile(name);
}
#endif

//
// Old GDI Orphan control macros
//
#define OBJ_REF_ADD(handle,type) TGdiObject::RefAdd((handle), (type))
#define OBJ_REF_REMOVE(handle) TGdiObject::RefRemove(handle)
#define OBJ_REF_INC(handle) TGdiObject::RefInc(handle)
#define OBJ_REF_DEC(handle, wantDelete) TGdiObject::RefDec((handle),(wantDelete))
#define OBJ_REF_COUNT(handle) TGdiObject::RefCount(handle)

#endif  // OWL_GDIOBJEC_H
