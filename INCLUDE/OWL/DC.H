//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of DC classes
//----------------------------------------------------------------------------
#if !defined(OWL_DC_H)
#define OWL_DC_H

#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif
#if defined(BI_PLAT_WIN16) && !defined(__PRINT_H)
# include <print.h>      // Win16 printing and some general DC APIs
#endif

class _OWLCLASS TPen;
class _OWLCLASS TBrush;
class _OWLCLASS TFont;
class _OWLCLASS TBitmap;
class _OWLCLASS TPalette;
class _OWLCLASS TIcon;
class _OWLCLASS TDib;
class _OWLCLASS TRegion;
class _OWLCLASS TMetaFilePict;

#if defined(BI_PLAT_WIN32)
# define OLDFONTENUMPROC FONTENUMPROC
#else
  // Win 32 object defines for 16 bit GetCurrentObject emulation
# define OBJ_PEN         1
# define OBJ_BRUSH       2
# define OBJ_PAL         5
# define OBJ_FONT        6
#endif

//
// class TDC
// ----- ---
//
// Root class for GDI DC.  This class can be instantiated, or
// specialized subclasses can be used to get specific behavior.
// Tracks & restores handles of first GDI objects that are replaced by
// ::SelectObject()
// Can be used as an interface to a borrowed handle.
//
class _OWLCLASS TDC : private TGdiBase {
  public:
    // Constructors / destructor
    TDC(HDC handle);  // use an existing DC, doesn't auto delete it
    virtual    ~TDC();

    // Type Conversion Operators
    operator    HDC() const {return HDC(Handle);}  // Must assume const is OK

    // DC functions
    bool         GetDCOrg(TPoint& point) const;
    virtual int  SaveDC() const;
    virtual bool RestoreDC(int savedDC = -1);
    virtual int  GetDeviceCaps(int index) const;
    virtual bool ResetDC(DEVMODE far& devMode);

    // Select GDI objects into this DC and restore them to original
    void         SelectObject(const TBrush& brush);
    void         SelectObject(const TPen& pen);
    virtual void SelectObject(const TFont& font);
    void         SelectObject(const TPalette& palette, bool forceBackground=false);
    virtual void SelectStockObject(int index);
    void         RestoreBrush();
    void         RestorePen();
    virtual void RestoreFont();
    void         RestorePalette();
#if defined(BI_PLAT_WIN32)
    void         RestoreTextBrush();
#endif
    void         RestoreObjects();
    HANDLE       GetCurrentObject(uint objectType) const;

    // Drawing tool functions
    bool         GetBrushOrg(TPoint& point) const;
    bool         SetBrushOrg(const TPoint& origin, TPoint far* oldOrg=0);
    int          EnumObjects(uint objectType, GOBJENUMPROC proc, void far* data) const;

    // Color and palette functions
    TColor       GetNearestColor(TColor Color) const;
    int          RealizePalette();
    void         UpdateColors();
    uint         GetSystemPaletteEntries(int start, int num, 
                                         PALETTEENTRY far* entries) const;
    uint         GetSystemPaletteUse() const;
    int          SetSystemPaletteUse(int usage);

    // Drawing attribute functions
    TColor         GetBkColor() const;
    virtual TColor SetBkColor(TColor color);
    int          GetBkMode() const;
    int          SetBkMode(int mode);
    int          GetPolyFillMode() const;
    int          SetPolyFillMode(int mode);
    int          GetROP2() const;
    int          SetROP2(int mode);
    int          GetStretchBltMode() const;
    int          SetStretchBltMode(int mode);
    TColor         GetTextColor() const;
    virtual TColor SetTextColor(TColor color);

#if defined(BI_PLAT_WIN32)
    bool         SetMiterLimit(float newLimit, float* oldLimit=0);
#endif

    // Viewport & window mapping functions
    int          GetMapMode() const;
    virtual int  SetMapMode(int mode);

#if defined(BI_PLAT_WIN32)
    bool         SetWorldTransform(XFORM far& xform);
    bool         ModifyWorldTransform(XFORM far& xform, uint32 mode);
#endif

    bool         GetViewportOrg(TPoint& point) const;
    TPoint       GetViewportOrg() const;
    virtual bool SetViewportOrg(const TPoint& origin, TPoint far* oldOrg=0);
    virtual bool OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg=0);

    bool         GetViewportExt(TSize& extent) const;
    TSize        GetViewportExt() const;
    virtual bool SetViewportExt(const TSize& extent, TSize far* oldExtent=0);
    virtual bool ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                                  TSize far* oldExtent=0);

    bool         GetWindowOrg(TPoint& point) const;
    TPoint       GetWindowOrg() const;
    bool         SetWindowOrg(const TPoint& origin, TPoint far* oldOrg=0);
    bool         OffsetWindowOrg(const TPoint& delta, TPoint far* oldOrg=0);

    bool         GetWindowExt(TSize& extent) const;
    TSize        GetWindowExt() const;
    virtual bool SetWindowExt(const TSize& extent, TSize far* oldExtent=0);
    virtual bool ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom,
                                TSize far* oldExtent=0);

    // Coordinate functions
    bool        DPtoLP(TPoint* points, int count = 1) const;
    bool        LPtoDP(TPoint* points, int count = 1) const;

    // Clip & Update Rect & Rgn functions
    int         GetClipBox(TRect& rect) const;
    TRect       GetClipBox() const;
    int         ExcludeClipRect(const TRect& rect);
    int         ExcludeUpdateRgn(HWND wnd);
    int         IntersectClipRect(const TRect& rect);
    int         OffsetClipRgn(const TPoint& delta);
    int         SelectClipRgn(const TRegion& region);
    bool        PtVisible(const TPoint& point) const;
    bool        RectVisible(const TRect& rect) const;
    bool        GetBoundsRect(TRect& bounds, uint16 flags) const;
    uint        SetBoundsRect(TRect& bounds, uint flags);
    bool        GetClipRgn(TRegion& region) const;

    // MetaFile functions
    int         EnumMetaFile(const TMetaFilePict& metaFile,
                             MFENUMPROC callback, void far* data) const;
    bool        PlayMetaFile(const TMetaFilePict& metaFile);
    void        PlayMetaFileRecord(HANDLETABLE far& Handletable,
                                   METARECORD far& metaRecord, int count);

    // Output functions- Current position
    bool        GetCurrentPosition(TPoint& point) const;
    bool        MoveTo(int x, int y);
    bool        MoveTo(const TPoint& point);
    bool        MoveTo(const TPoint& point, TPoint& oldPoint);

    // Output functions- Icons
    bool        DrawIcon(int x, int y, const TIcon& icon);
    bool        DrawIcon(const TPoint& point, const TIcon& icon);

    // Output functions- Rects
    bool        FrameRect(int x1, int y1, int x2, int y2, const TBrush& brush);
    bool        FrameRect(const TRect& rect, const TBrush& brush);
    bool        FillRect(int x1, int y1, int x2, int y2, const TBrush& brush);
    bool        FillRect(const TRect& rect, const TBrush& brush);
    bool        InvertRect(int x1, int y1, int x2, int y2);
    bool        InvertRect(const TRect& rect);
    bool        DrawFocusRect(int x1, int y1, int x2, int y2);
    bool        DrawFocusRect(const TRect& rect);

    // Filled rect using ExtTextOut, no dithered colors & uses or sets BkColor
    bool        TextRect(int x1, int y1, int x2, int y2);
    bool        TextRect(const TRect& rect);
    bool        TextRect(int x1, int y1, int x2, int y2, TColor color);
    bool        TextRect(const TRect& rect, TColor color);

    // 
    void        OWLFastWindowFrame(TBrush &brush, TRect &r, int xWidth, int yWidth);
    
    // Output functions- Regions
    bool        FrameRgn(const TRegion& region, const TBrush& brush, const TPoint& p);
    bool        FillRgn(const TRegion& region, const TBrush& brush);
    bool        InvertRgn(const TRegion& region);
    bool        PaintRgn(const TRegion& region);

    // Output functions- Shapes
#if defined(BI_PLAT_WIN32)
    bool        AngleArc(int x, int y, uint32 radius, float startAngle,
                         float sweepAngle);
    bool        AngleArc(const TPoint& center, uint32 radius, float startAngle,
                         float sweepAngle);
#endif
    bool        Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                    int y4);
    bool        Arc(const TRect& r, const TPoint& start, const TPoint& end);
    bool        Chord(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                      int y4);
    bool        Chord(const TRect& R, const TPoint& Start, const TPoint& End);
    bool        Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                    int y4);
    bool        Pie(const TRect& rect, const TPoint& start, const TPoint& end);
    bool        Ellipse(int x1, int y1, int x2, int y2);
    bool        Ellipse(const TPoint& p1, const TPoint& p2);
    bool        Ellipse(const TPoint& point, const TSize& size);
    bool        Ellipse(const TRect& rect);
    bool        LineTo(int x, int y);
    bool        LineTo(const TPoint& point);
    bool        Polyline(const TPoint* points, int count);
    bool        Polygon(const TPoint* points, int count);
    bool        PolyPolygon(const TPoint* points, const int* PolyCounts,
                            int count);
#if defined(BI_PLAT_WIN32)
    bool        PolyPolyline(const TPoint* points, const int* PolyCounts,
                             int count);
    bool        PolyBezier(const TPoint* points, int count);
    bool        PolyBezierTo(const TPoint* points, int count);
    bool        PolyDraw(const TPoint* points, uint8* types, int count);
    bool        PolylineTo(const TPoint* points, int count);
#endif
    bool        Rectangle(int x1, int y1, int x2, int y2);
    bool        Rectangle(const TPoint& p1, const TPoint& p2);
    bool        Rectangle(const TPoint& point, const TSize& s);
    bool        Rectangle(const TRect& rect);
    bool        RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
    bool        RoundRect(const TPoint& p1, const TPoint& p2, const TPoint& rad);
    bool        RoundRect(const TPoint& p, const TSize& s, const TPoint& rad);
    bool        RoundRect(const TRect& rect, const TPoint& rad);

    // Output functions- bitmaps & blitting
    TColor      GetPixel(int x, int y) const;
    TColor      GetPixel(const TPoint& point) const;
    TColor      SetPixel(int x, int y, TColor color);
    TColor      SetPixel(const TPoint& p, TColor color);
    bool        BitBlt(int dstX, int dstY, int w, int h, const TDC& srcDC,
                       int srcX, int srcY, uint32 rop=SRCCOPY);
    bool        BitBlt(const TRect& dst, const TDC& srcDC,
                       const TPoint& src, uint32 rop=SRCCOPY);
    bool        PatBlt(int x, int y, int w, int h, uint32 rop=PATCOPY);
    bool        PatBlt(const TRect& dst, uint32 rop=PATCOPY);
    bool        ScrollDC(int x, int y, const TRect& scroll, const TRect& clip,
                         TRegion& updateRgn, TRect& updateRect);
    bool        ScrollDC(const TPoint& delta, const TRect& scroll,
                         const TRect& clip, TRegion& updateRgn,
                         TRect& updateRect);
    bool        StretchBlt(int dstX, int dstY, int dstW, int dstH,
                           const TDC& srcDC, int srcX, int srcY, int srcW,
                           int srcH, uint32 rop=SRCCOPY);
    bool        StretchBlt(const TRect& dst, const TDC& srcDC,
                           const TRect& src, uint32 rop=SRCCOPY);
#if defined(BI_PLAT_WIN32)
    bool        MaskBlt(const TRect& dst, const TDC& srcDC,
                        const TPoint& src, const TBitmap& maskBm,
                        const TPoint& maskPos, uint32 rop=SRCCOPY);
    bool        PlgBlt(const TPoint& dst, const TDC& srcDC,
                       const TRect& src, const TBitmap& maskBm,
                       const TPoint& maskPos, uint32 rop=SRCCOPY);
#endif
    bool        GetDIBits(const TBitmap& bitmap, uint16 startScan, uint16 numScans,
                          void HUGE* bits, const BITMAPINFO far& info,
                          uint16 usage);
    bool        GetDIBits(const TBitmap& bitmap, TDib& dib);
    bool        SetDIBits(TBitmap& bitmap, uint16 startScan, uint16 numScans,
                          const void HUGE* bits, const BITMAPINFO far& Info,
                          uint16 usage);
    bool        SetDIBits(TBitmap& bitmap, const TDib& dib);
    bool        SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                  uint16 startScan, uint16 numScans,
                                  const void HUGE* bits,
                                  const BITMAPINFO far& bitsInfo, uint16 usage);
    bool        SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                  const TDib& dib);
    bool        StretchDIBits(const TRect& dst, const TRect& src,
                              const void HUGE* bits,
                              const BITMAPINFO far& bitsInfo,
                              uint16 usage, uint32 rop=SRCCOPY);
    bool        StretchDIBits(const TRect& dst, const TRect& src,
                              const TDib& dib, uint32 rop=SRCCOPY);
    bool        FloodFill(const TPoint& point, TColor color);
    bool        ExtFloodFill(const TPoint& point, TColor color, uint16 fillType);

    // Output functions- text
    virtual bool TextOut(int x, int y, const char far* str, int count=-1);
    bool         TextOut(const TPoint& p, const char far* str, int count=-1);
    virtual bool ExtTextOut(int x, int y, uint16 options, const TRect* r,
                            const char far* str, int count=-1,
                            const int far* dx = 0);
    bool         ExtTextOut(const TPoint& p, uint16 options, const TRect* r,
                            const char far* str, int count=-1,
                            const int far* dx = 0);
    virtual bool TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin, TSize& size);
    bool         TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin);
    virtual int  DrawText(const char far* str, int count, const TRect& r,
                          uint16 format=0);
    virtual bool GrayString(const TBrush& brush, GRAYSTRINGPROC outputFunc,
                            const char far* str, int count, const TRect& r);

    // Text functions
    bool        GetTextExtent(const char far* str, int stringLen, TSize& size);
    TSize       GetTextExtent(const char far* str, int stringLen);
    bool        GetTabbedTextExtent(const char far* str, int stringLen,
                                    int numPositions, const int far* positions,
                                    TSize& size) const;
    TSize       GetTabbedTextExtent(const char far* str, int stringLen,
                              int numPositions, const int far* positions) const;
    uint        GetTextAlign() const;
    uint        SetTextAlign(uint flags);
    int         GetTextCharacterExtra() const;
    int         SetTextCharacterExtra(int extra);
    bool        SetTextJustification(int breakExtra, int breakCount);
    int         GetTextFace(int count, char far* facename) const;
    bool        GetTextMetrics(TEXTMETRIC far& metrics) const;
    uint32      GetGlyphOutline(uint chr, uint format, GLYPHMETRICS far& gm,
                                uint32 buffSize, void far* buffer,
                                const MAT2 far& mat2);
    int         GetKerningPairs(int pairs, KERNINGPAIR far* krnPair);
#if defined(BI_PLAT_WIN32)
    uint32      GetOutlineTextMetrics(uint data, OUTLINETEXTMETRIC far& otm);
#else
    uint16      GetOutlineTextMetrics(uint data, OUTLINETEXTMETRIC far& otm);
#endif

    // Font functions
    bool        GetCharWidth(uint firstChar, uint lastChar, int* buffer);
    uint32      SetMapperFlags(uint32 flag);
    bool        GetAspectRatioFilter(TSize& size) const;
    int         EnumFonts(const char far* faceName, OLDFONTENUMPROC callback,
                          void far* data) const;
    int         EnumFontFamilies(const char far* family,
                                 FONTENUMPROC proc, void far* data) const;
    uint32      GetFontData(uint32 table, uint32 offset, void* buffer, long data);
    bool        GetCharABCWidths(uint firstChar, uint lastChar, ABC* abc);

    // Path functions
#if defined(BI_PLAT_WIN32)
    bool        BeginPath();
    bool        CloseFigure();
    bool        EndPath();
    bool        FlattenPath();
    bool        WidenPath();
    bool        FillPath();
    bool        StrokePath();
    bool        StrokeAndFillPath();
    bool        SelectClipPath(int mode);
    HRGN        PathToRegion();
#endif

  protected:
    TGdiBase::CheckValid;       // make this function available to derivatives
    TGdiBase::Handle;           // The handle of this DC
    TGdiBase::ShouldDelete;     // Should object delete the Handle in dtor?

    HBRUSH      OrgBrush;       // Original objects when DC was created
    HPEN        OrgPen;
    HFONT       OrgFont;
    HPALETTE    OrgPalette;
#if defined(BI_PLAT_WIN32)
    HBRUSH      OrgTextBrush;
#endif

    TDC();          // For use by derived classes only
    TDC(HDC handle, TAutoDelete autoDelete); //use an existing DC
    void        Init();

               // Override to implement a twin DC object, like TPrintPreviewDC
    virtual HDC GetAttributeHDC() const;
            HDC GetHDC() const {return HDC(Handle);}

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TDC(const TDC&);
    TDC& operator =(const TDC&);
};

//
// class TWindowDC
// ----- ---------
//
// A DC class that provides access to the entire area owned by a window. Is
// the base for any DC class that Releases its handle when done.
//
class _OWLCLASS TWindowDC : public TDC {
  public:
    TWindowDC(HWND wnd);
   ~TWindowDC();

  protected:
    HWND        Wnd;
    TWindowDC();  // for derived classes

  private:
    TWindowDC(const TWindowDC&);
    TWindowDC& operator =(const TWindowDC&);
};

//
// class TScreenDC
// ----- ---------
//
// A DC class that provides direct access to the screen bitmap.  Gets a DC for
// Window handle 0, which is for the whole screen w/ no clipping, etc. will
// paint on top of everything.
//
class _OWLCLASS TScreenDC : public TWindowDC {
  public:
    TScreenDC();

  private:
    TScreenDC(const TScreenDC&);
    TScreenDC& operator =(const TScreenDC&);
};

//
// class TDesktopDC
// ----- ----------
//
// A DC class that provides access to the desktop window's client area which
// is the screen behind all other windows.
//
class _OWLCLASS TDesktopDC : public TWindowDC {
  public:
    TDesktopDC();

  private:
    TDesktopDC(const TDesktopDC&);
    TDesktopDC& operator =(const TDesktopDC&);
};

//
// class TClientDC
// ----- ---------
//
// A DC class that provides access to the client area owned by a window
//
class _OWLCLASS TClientDC : public TWindowDC {
  public:
    TClientDC(HWND wnd);

  private:
    TClientDC(const TClientDC&);
    TClientDC& operator =(const TClientDC&);
};

//
// class TPaintDC
// ----- --------
//
// A DC class that wraps begin and end paint calls for use in an WM_PAINT
// response function.
//
class _OWLCLASS TPaintDC : public TDC {
  public:
    TPaintDC(HWND wnd);
   ~TPaintDC();

    PAINTSTRUCT Ps;

  protected:
    HWND        Wnd;

  private:
    TPaintDC(const TPaintDC&);
    TPaintDC& operator =(const TPaintDC&);
};

//
// class TMetaFileDC
// ----- -----------
//
// A DC class that provides access to a DC with a metafile selected into it
// for drawing on (into).
//
class _OWLCLASS TMetaFileDC : public TDC {
  public:
    TMetaFileDC(const char far* filename = 0);
   ~TMetaFileDC();

    HMETAFILE Close();

  private:
    TMetaFileDC(const TMetaFileDC&);
    TMetaFileDC& operator =(const TMetaFileDC&);
};

//
// class TCreatedDC
// ----- ----------
//
class _OWLCLASS TCreatedDC : public TDC {
  public:
    TCreatedDC(const char far* driver, const char far* device,
               const char far* output, const DEVMODE far* initData=0);

    TCreatedDC(HDC handle, TAutoDelete autoDelete);  // use an existing DC
   ~TCreatedDC();

  protected:
    TCreatedDC();

  private:
    TCreatedDC(const TCreatedDC&);
    TCreatedDC& operator =(const TCreatedDC&);
};

//
// class TIC
// ----- ---
//
class _OWLCLASS TIC : public TCreatedDC {
  public:
    TIC(const char far* driver, const char far* device,
        const char far* output, const DEVMODE far* initData=0);

  private:
    TIC(const TIC&);
    TIC& operator =(const TIC&);
};

//
// class TMemoryDC
// ----- ---------
//
// A DC class that provides access to a memory DC
//
class _OWLCLASS TMemoryDC : public TCreatedDC {
  public:
    TMemoryDC();
    TMemoryDC(const TDC& DC); // Make it compatible with an existing DC
    TMemoryDC(HDC handle, TAutoDelete autoDelete);  // use an existing DC
   ~TMemoryDC();

    // Select GDI objects into this DC and restore them to original
    void        SelectObject(const TBrush& brush) {TDC::SelectObject(brush);}
    void        SelectObject(const TPen& pen) {TDC::SelectObject(pen);}
    void        SelectObject(const TFont& font) {TDC::SelectObject(font);}
    void        SelectObject(const TPalette& palette, bool forceBackground=false)
      {TDC::SelectObject(palette, forceBackground);}
    void        SelectObject(const TBitmap& bitmap);

    void        RestoreBitmap();
    void        RestoreObjects() {TDC::RestoreObjects(); RestoreBitmap();}

  protected:
    HBITMAP     OrgBitmap;

  private:
    TMemoryDC(const TMemoryDC&);
    TMemoryDC& operator =(const TMemoryDC&);
};

//
// class TDibDC
// ----- ------
//
// A DC class that provides access to DIBs using the DIB.DRV driver
//
class _OWLCLASS TDibDC : public TCreatedDC {
  public:
    TDibDC(const TDib& dib);

  private:
    TDibDC(const TDibDC&);
    TDibDC& operator =(const TDibDC&);
};

//----------------------------------------------------------------------------
// A DC class that provides access to a printer
//
struct TBandInfo {    // Equivalent to BANDINFOSTRUCT
  bool  HasGraphics;
  bool  HasText;
  TRect GraphicsRect;
};

class _OWLCLASS TPrintDC : public TCreatedDC {
  public:
    TPrintDC(HDC handle, TAutoDelete autoDelete = NoAutoDelete);
    TPrintDC(const char far* driver, const char far* device,
             const char far* output, const DEVMODE far* initData);

    int         Escape(int escape, int count=0, const void* inData=0,
                       void* outData=0);
    int         SetAbortProc(ABORTPROC proc);
    int         StartDoc(const char far* docName, const char far* output);
    int         StartPage();
    int         BandInfo(TBandInfo& bandInfo);
    int         NextBand(TRect& rect);
    int         EndPage();
    int         EndDoc();
    int         AbortDoc();

#if defined(BI_PLAT_WIN16)
    bool        QueryAbort(int rsvd=0);
#endif

    uint        QueryEscSupport(int escapeNum);
    int         SetCopyCount(int reqestCount, int& actualCount);

    static uint32 DeviceCapabilities(const char far* driver,
                                    const char far* device,
                                    const char far* port,
                                    int capability, char far* output=0,
                                    LPDEVMODE devmode=0);
  protected:
    DOCINFO     DocInfo;

  private:
    TPrintDC(const TPrintDC&);
    TPrintDC& operator =(const TPrintDC&);
};

//----------------------------------------------------------------------------
// Inlines for DC classes
//----------------------------------------------------------------------------

//
// Get the GDI object headers so that we have access to conversion operators,
// etc.
//
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_METAFILE_H)
# include <owl/metafile.h>
#endif


inline bool TDC::GetDCOrg(TPoint& point) const {
#if defined(BI_PLAT_WIN32)
  return ::GetDCOrgEx(GetAttributeHDC(), &point);
#else
  point = ::GetDCOrg(GetAttributeHDC());
  return true;
#endif
}

inline bool TDC::GetBrushOrg(TPoint& point) const {
  return ::GetBrushOrgEx(GetHDC(), &point);
}

inline bool TDC::SetBrushOrg(const TPoint& org, TPoint far* oldOrg) {
#if defined(BI_PLAT_WIN32)
  return ::SetBrushOrgEx(GetHDC(), org.x, org.y, oldOrg);
#else
  if (oldOrg)
    *oldOrg = ::SetBrushOrg(GetHDC(), org.x, org.y);
  else
    ::SetBrushOrg(GetHDC(), org.x, org.y);
  return true;
#endif
}

inline int TDC::EnumObjects(uint objectType, GOBJENUMPROC proc, void far* data) const {
  return ::EnumObjects(GetHDC(), objectType, proc, (LPARAM)data);
}

inline TColor TDC::GetNearestColor(TColor color) const {
  return ::GetNearestColor(GetAttributeHDC(), color);
}

inline int TDC::RealizePalette() {
  return ::RealizePalette(GetHDC());
}

inline void TDC::UpdateColors() {
  ::UpdateColors(GetHDC());
}

inline uint TDC::GetSystemPaletteEntries(int start, int num, PALETTEENTRY far* entries) const {
  return ::GetSystemPaletteEntries(GetHDC(), start, num, entries);
}

inline uint TDC::GetSystemPaletteUse() const {
  return ::GetSystemPaletteUse(GetHDC());
}

inline int TDC::SetSystemPaletteUse(int usage) {
  return ::SetSystemPaletteUse(GetHDC(), usage);
}

inline TColor TDC::GetBkColor() const {
  return ::GetBkColor(GetAttributeHDC());
}

inline int TDC::GetBkMode() const {
  return ::GetBkMode(GetAttributeHDC());
}

inline int TDC::SetBkMode(int mode) {
  if (GetHDC() != GetAttributeHDC())
    ::SetBkMode(GetHDC(), mode);
  return ::SetBkMode(GetAttributeHDC(), mode);
}

inline int TDC::GetPolyFillMode() const {
  return ::GetPolyFillMode(GetAttributeHDC());
}

inline int TDC::SetPolyFillMode(int mode) {
  if (GetHDC() != GetAttributeHDC())
    ::SetPolyFillMode(GetHDC(), mode);
  return ::SetPolyFillMode(GetAttributeHDC(), mode);
}

inline int TDC::GetROP2() const {
  return ::GetROP2(GetAttributeHDC());
}

inline int TDC::SetROP2(int mode) {
  if (GetHDC() != GetAttributeHDC())
    ::SetROP2(GetHDC(), mode);
  return ::SetROP2(GetAttributeHDC(), mode);
}

inline int TDC::GetStretchBltMode() const {
  return ::GetStretchBltMode(GetAttributeHDC());
}

inline int TDC::SetStretchBltMode(int mode) {
  if (GetHDC() != GetAttributeHDC())
    ::SetStretchBltMode(GetHDC(), mode);
  return ::SetStretchBltMode(GetAttributeHDC(), mode);
}

inline TColor TDC::GetTextColor() const {
  return ::GetTextColor(GetAttributeHDC());
}

inline int TDC::GetMapMode() const {
  return ::GetMapMode(GetAttributeHDC());
}

#if defined(BI_PLAT_WIN32)

inline bool TDC::SetMiterLimit(float newLimit, float* oldLimit) {
  if (GetHDC() != GetAttributeHDC())
    ::SetMiterLimit(GetHDC(), newLimit, oldLimit);
  return ::SetMiterLimit(GetAttributeHDC(), newLimit, oldLimit);
}

inline bool TDC::SetWorldTransform(XFORM far& xform) {
  if (GetHDC() != GetAttributeHDC())
    ::SetWorldTransform(GetHDC(), &xform);
  return ::SetWorldTransform(GetAttributeHDC(), &xform);
}

inline bool TDC::ModifyWorldTransform(XFORM far& xform, uint32 mode) {
  if (GetHDC() != GetAttributeHDC())
    ::ModifyWorldTransform(GetHDC(), &xform, mode);
  return ::ModifyWorldTransform(GetAttributeHDC(), &xform, mode);
}

#endif  // defined(BI_PLAT_WIN32)

inline bool TDC::GetViewportOrg(TPoint& point) const {
  return ::GetViewportOrgEx(GetAttributeHDC(), &point);
}

inline TPoint TDC::GetViewportOrg() const {
#if defined(BI_PLAT_WIN32)
  TPoint point;
  ::GetViewportOrgEx(GetAttributeHDC(), &point);
  return point;
#else
  return ::GetViewportOrg(GetAttributeHDC());
#endif
}

inline bool TDC::GetViewportExt(TSize& extent) const {
  return ::GetViewportExtEx(GetAttributeHDC(), &extent);
}

inline TSize TDC::GetViewportExt() const {
#if defined(BI_PLAT_WIN32)
  TSize extent;
  ::GetViewportExtEx(GetAttributeHDC(), &extent);
  return extent;
#else
  return ::GetViewportExt(GetAttributeHDC());
#endif
}

inline bool TDC::GetWindowOrg(TPoint& point) const {
  return ::GetWindowOrgEx(GetAttributeHDC(), &point);
}

inline TPoint TDC::GetWindowOrg() const {
#if defined(BI_PLAT_WIN32)
  TPoint point;
  ::GetWindowOrgEx(GetAttributeHDC(), &point);
  return point;
#else
  return ::GetWindowOrg(GetAttributeHDC());
#endif
}

inline bool TDC::GetWindowExt(TSize& extent) const {
  return ::GetWindowExtEx(GetAttributeHDC(), &extent);
}

inline TSize TDC::GetWindowExt() const {
#if defined(BI_PLAT_WIN32)
  TSize extent;
  ::GetWindowExtEx(GetAttributeHDC(), &extent);
  return extent;
#else
  return ::GetWindowExt(GetAttributeHDC());
#endif
}

inline bool TDC::DPtoLP(TPoint* points, int count) const {
  return ::DPtoLP(GetAttributeHDC(), points, count);
}

inline bool TDC::LPtoDP(TPoint* points, int count) const {
  return ::LPtoDP(GetHDC(), points, count);
}

inline int TDC::GetClipBox(TRect& rect) const {
  return ::GetClipBox(GetHDC(), &rect);
}

inline TRect TDC::GetClipBox() const {
  TRect rect;
  ::GetClipBox(GetHDC(), &rect);
  return rect;
}

inline int TDC::ExcludeClipRect(const TRect& rect) {
  return ::ExcludeClipRect(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline int TDC::ExcludeUpdateRgn(HWND Wnd) {
  return ::ExcludeUpdateRgn(GetHDC(), Wnd);
}

inline int TDC::IntersectClipRect(const TRect& rect) {
  return ::IntersectClipRect(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline int TDC::OffsetClipRgn(const TPoint& delta) {
  return ::OffsetClipRgn(GetHDC(), delta.x, delta.y);
}

inline int TDC::SelectClipRgn(const TRegion& region) {
  return ::SelectClipRgn(GetHDC(), region);
}

inline bool TDC::PtVisible(const TPoint& point) const {
  return ::PtVisible(GetHDC(), point.x, point.y);
}

inline bool TDC::RectVisible(const TRect& rect) const {
  return ::RectVisible(GetHDC(), &rect);
}

inline bool TDC::GetBoundsRect(TRect& bounds, uint16 flags) const {
  return ::GetBoundsRect(GetHDC(), &bounds, flags);
}

inline uint TDC::SetBoundsRect(TRect& bounds, uint flags) {
  return ::SetBoundsRect(GetHDC(), &bounds, flags);
}

#if defined(BI_PLAT_WIN32)
inline bool TDC::GetClipRgn(TRegion& region) const {
  return ::GetClipRgn(GetHDC(), region);
}
#endif

inline int TDC::EnumMetaFile(const TMetaFilePict& metafile, MFENUMPROC callback,
                             void far* data) const {
  return ::EnumMetaFile(GetHDC(), metafile, callback, (long)data);
}

inline bool TDC::PlayMetaFile(const TMetaFilePict& metafile) {
  return ::PlayMetaFile(GetHDC(), metafile);
}

inline void TDC::PlayMetaFileRecord(HANDLETABLE far& handletable,
                                    METARECORD far& metaRecord, int count) {
  ::PlayMetaFileRecord(GetHDC(), &handletable, &metaRecord, count);
}

inline bool TDC::GetCurrentPosition(TPoint& point) const {
  return ::GetCurrentPositionEx(GetHDC(), &point);
}

inline bool TDC::MoveTo(int x, int y) {
  return ::MoveToEx(GetHDC(), x, y, 0);
}

inline bool TDC::MoveTo(const TPoint& point) {
  return ::MoveToEx(GetHDC(), point.x, point.y, 0);
}

inline bool TDC::MoveTo(const TPoint& point, TPoint& OldPoint) {
  return ::MoveToEx(GetHDC(), point.x, point.y, &OldPoint);
}

inline bool TDC::DrawIcon(int x, int y, const TIcon& icon) {
  return ::DrawIcon(GetHDC(), x, y, icon);
}

inline bool TDC::DrawIcon(const TPoint& point, const TIcon& icon) {
  return ::DrawIcon(GetHDC(), point.x, point.y, icon);
}

inline bool TDC::FrameRect(int x1, int y1, int x2, int y2, const TBrush& brush) {
  return ::FrameRect(GetHDC(), &TRect(x1, y1, x2, y2), brush);
}

inline bool TDC::FrameRect(const TRect& rect, const TBrush& brush) {
  return ::FrameRect(GetHDC(), &rect, brush);
}

inline bool TDC::FillRect(int x1, int y1, int x2, int y2, const TBrush& brush) {
  return ::FillRect(GetHDC(), &TRect(x1, y1, x2, y2), brush);
}

inline bool TDC::FillRect(const TRect& rect, const TBrush& brush) {
  return ::FillRect(GetHDC(), &rect, brush);
}

//
// rect must be normalized for inverRect
//
inline bool TDC::InvertRect(int x1, int y1, int x2, int y2) {
  ::InvertRect(GetHDC(), &TRect(x1, y1, x2, y2));
  return true;
}

inline bool TDC::InvertRect(const TRect& rect) {
  ::InvertRect(GetHDC(), &rect);
  return true;
}

inline bool TDC::DrawFocusRect(int x1, int y1, int x2, int y2) {
  ::DrawFocusRect(GetHDC(), &TRect(x1, y1, x2, y2));
  return true;
}

inline bool TDC::DrawFocusRect(const TRect& rect) {
  ::DrawFocusRect(GetHDC(), &rect);
  return true;
}

inline bool TDC::TextRect(int x1, int y1, int x2, int y2) {
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &TRect(x1, y1, x2, y2), 0, 0, 0);
}

inline bool TDC::TextRect(const TRect& rect) {
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &rect, 0, 0, 0);
}

inline bool TDC::TextRect(int x1, int y1, int x2, int y2, TColor color) {
  SetBkColor(color);
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &TRect(x1, y1, x2, y2), 0, 0, 0);
}

inline bool TDC::TextRect(const TRect& rect, TColor color) {
  SetBkColor(color);
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &rect, 0, 0, 0);
}

inline bool TDC::FrameRgn(const TRegion& region, const TBrush& brush, const TPoint& p) {
  return ::FrameRgn(GetHDC(), region, brush, p.x, p.y);
}

inline bool TDC::FillRgn(const TRegion& region, const TBrush& brush) {
  return ::FillRgn(GetHDC(), region, brush);
}

inline bool TDC::InvertRgn(const TRegion& region) {
  return ::InvertRgn(GetHDC(), region);
}

inline bool TDC::PaintRgn(const TRegion& region) {
  return ::PaintRgn(GetHDC(), region);
}

#if defined(BI_PLAT_WIN32)
inline bool TDC::AngleArc(int x, int y, uint32 radius, float startAngle, float sweepAngle) {
  return ::AngleArc(GetHDC(), x, y, radius, startAngle, sweepAngle);
}

inline bool TDC::AngleArc(const TPoint& Center, uint32 radius, float StartAngle, float SweepAngle) {
  return ::AngleArc(GetHDC(), Center.x, Center.y, radius, StartAngle, SweepAngle);
}
#endif

inline bool TDC::Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Arc(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline bool TDC::Arc(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Arc(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline bool TDC::Chord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Chord(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline bool TDC::Chord(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Chord(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline bool TDC::Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Pie(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline bool TDC::Pie(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Pie(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline bool TDC::Ellipse(int x1, int y1, int x2, int y2) {
  return ::Ellipse(GetHDC(), x1, y1, x2, y2);
}

inline bool TDC::Ellipse(const TPoint& p1, const TPoint& p2) {
  return ::Ellipse(GetHDC(), p1.x, p1.y, p2.x, p2.y);
}

inline bool TDC::Ellipse(const TPoint& p, const TSize& s) {
  return ::Ellipse(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy);
}

inline bool TDC::Ellipse(const TRect& rect) {
  return ::Ellipse(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline bool TDC::LineTo(int x, int y) {
  return ::LineTo(GetHDC(), x, y);
}

inline bool TDC::LineTo(const TPoint& point) {
  return ::LineTo(GetHDC(), point.x, point.y);
}

inline bool TDC::Polyline(const TPoint* points, int count) {
  return ::Polyline(GetHDC(), points, count);
}

inline bool TDC::Polygon(const TPoint* points, int count) {
  return ::Polygon(GetHDC(), (TPoint*)points, count);
}

inline bool TDC::PolyPolygon(const TPoint* points, const int* polyCounts, int count) {
  return ::PolyPolygon(GetHDC(), (TPoint*)points, (int*)polyCounts, count); // API typecast
}

#if defined(BI_PLAT_WIN32)
inline bool TDC::PolyPolyline(const TPoint* points, const int* polyCounts, int count) {
  return ::PolyPolyline(GetHDC(), (TPoint*)points, (uint32*)polyCounts, count); // API typecast
}

inline bool TDC::PolyBezier(const TPoint* points, int count) {
  return ::PolyBezier(GetHDC(), (TPoint*)points, count);
}

inline bool TDC::PolyBezierTo(const TPoint* points, int count) {
  return ::PolyBezierTo(GetHDC(), (TPoint*)points, count);
}

inline bool TDC::PolyDraw(const TPoint* points, uint8* types, int count) {
  return ::PolyDraw(GetHDC(), (TPoint*)points, types, count);
}

inline bool TDC::PolylineTo(const TPoint* points, int count) {
  return ::PolylineTo(GetHDC(), (TPoint*)points, count);
}
#endif

inline bool TDC::Rectangle(int x1, int y1, int x2, int y2) {
  return ::Rectangle(GetHDC(), x1, y1, x2, y2);
}

inline bool TDC::Rectangle(const TPoint& p1, const TPoint& p2) {
  return ::Rectangle(GetHDC(), p1.x, p1.y, p2.x, p2.y);
}

inline bool TDC::Rectangle(const TPoint& p, const TSize& s) {
  return ::Rectangle(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy);
}

inline bool TDC::Rectangle(const TRect& rect) {
  return ::Rectangle(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline bool TDC::RoundRect(int x1, int y1, int x2, int y2, int x3, int y3) {
  return ::RoundRect(GetHDC(), x1, y1, x2, y2, x3, y3);
}

inline bool TDC::RoundRect(const TPoint& p1, const TPoint& p2, const TPoint& rad) {
  return ::RoundRect(GetHDC(), p1.x, p1.y, p2.x, p2.y, rad.x, rad.y);
}

inline bool TDC::RoundRect(const TPoint& p, const TSize& s, const TPoint& rad) {
  return ::RoundRect(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy, rad.x, rad.y);
}

inline bool TDC::RoundRect(const TRect& rect, const TPoint& rad) {
  return ::RoundRect(GetHDC(), rect.left, rect.top, rect.right, rect.bottom,
                     rad.x, rad.y);
}

inline TColor TDC::GetPixel(int x, int y) const {
  return ::GetPixel(GetHDC(), x, y);
}

inline TColor TDC::GetPixel(const TPoint& point) const {
  return ::GetPixel(GetHDC(), point.x, point.y);
}

inline TColor TDC::SetPixel(int x, int y, TColor color) {
  return ::SetPixel(GetHDC(), x, y, color);
}

inline TColor TDC::SetPixel(const TPoint& point, TColor color) {
  return ::SetPixel(GetHDC(), point.x, point.y, color);
}

inline bool TDC::BitBlt(int dstX, int dstY, int w, int h, const TDC& srcDC,
                       int srcX, int srcY, uint32 rop) {
  return ::BitBlt(GetHDC(), dstX, dstY, w, h, srcDC, srcX, srcY, rop);
}

inline bool TDC::BitBlt(const TRect& dst, const TDC& srcDC, const TPoint& src,
                        uint32 rop) {
  return ::BitBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
                  srcDC, src.x, src.y, rop);
}

inline bool TDC::PatBlt(int x, int y, int w, int h, uint32 rop) {
  return ::PatBlt(GetHDC(), x, y, w, h, rop);
}

inline bool TDC::PatBlt(const TRect& dst, uint32 rop) {
  return ::PatBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(), rop);
}

inline bool TDC::ScrollDC(int dx, int dy, const TRect& scroll, const TRect& clip,
                          TRegion& updateRgn, TRect& updateRect) {
  return ::ScrollDC(GetHDC(), dx, dy, &scroll, &clip, updateRgn, &updateRect);
}

inline bool TDC::ScrollDC(const TPoint& delta, const TRect& scroll, const TRect& clip,
                          TRegion& updateRgn, TRect& updateRect) {
  return ::ScrollDC(GetHDC(), delta.x, delta.y, &scroll, &clip, updateRgn, &updateRect);
}

inline bool TDC::StretchBlt(int dstX, int dstY, int dstW, int dstH,
                           const TDC& srcDC, int srcX, int srcY, int srcW,
                           int srcH, uint32 rop) {
  return ::StretchBlt(GetHDC(), dstX, dstY, dstW, dstH,
                      srcDC, srcX, srcY, srcW, srcH, rop);
}

inline bool TDC::StretchBlt(const TRect& dst, const TDC& srcDC,
                            const TRect& src, uint32 rop) {
  return ::StretchBlt(GetHDC(),
                      dst.left, dst.top, dst.Width(), dst.Height(),
                      srcDC, src.left, src.top,
                      src.Width(), src.Height(), rop);
}

#if defined(BI_PLAT_WIN32)
inline bool TDC::MaskBlt(const TRect& dst,
                         const TDC& srcDC, const TPoint& src,
                         const TBitmap& maskBm, const TPoint& maskPos,
                         uint32 rop) {
  return ::MaskBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
                   srcDC, src.x, src.y, maskBm, maskPos.x, maskPos.y,
                   rop);
}

inline bool TDC::PlgBlt(const TPoint& dst,
                        const TDC& srcDC, const TRect& src,
                        const TBitmap& maskBm, const TPoint& maskPos, uint32 rop) {
  return ::PlgBlt(GetHDC(), (TPoint*)&dst,
                  srcDC, src.left, src.top, src.Width(), src.Height(),
                  maskBm, maskPos.x, maskPos.y);
}
#endif

inline bool TDC::GetDIBits(const TBitmap& bitmap, uint16 startScan, uint16 numScans,
                           void HUGE* bits, const BITMAPINFO far& info,
                           uint16 usage) {
  return ::GetDIBits(GetHDC(), bitmap, startScan, numScans, bits,
                    (BITMAPINFO far*)&info, usage);
}

inline bool TDC::GetDIBits(const TBitmap& bitmap, TDib& dib) {
  return ::GetDIBits(GetHDC(), bitmap, dib.StartScan(), dib.NumScans(),
                     dib.GetBits(), dib.GetInfo(), dib.Usage());
}

inline bool TDC::SetDIBits(TBitmap& bitmap, uint16 startScan, uint16 numScans,
                           const void HUGE* bits, const BITMAPINFO far& info,
                           uint16 usage) {
  return ::SetDIBits(GetHDC(), bitmap, startScan, numScans,
                     bits, (BITMAPINFO far*)&info, usage);
                     // API typecast
}

inline bool TDC::SetDIBits(TBitmap& bitmap, const TDib& dib) {
  return ::SetDIBits(GetHDC(), bitmap, dib.StartScan(), dib.NumScans(),
                     dib.GetBits(), (BITMAPINFO far*)dib.GetInfo(), dib.Usage());
                                   // API typecast
}

inline bool TDC::SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                   uint16 startScan, uint16 numScans,
                                   const void HUGE* bits,
                                   const BITMAPINFO far& info, uint16 usage) {
  return ::SetDIBitsToDevice(
             GetHDC(), dst.left, dst.top,
             dst.Width(), dst.Height(), src.x, src.y,
             startScan, numScans,
             (void HUGE*)bits, (BITMAPINFO far*)&info, usage
         );                  // API typecast
}

inline bool TDC::SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                   const TDib& dib) {
  return ::SetDIBitsToDevice(
             GetHDC(),
             dst.left, dst.top, dst.Width(), dst.Height(),
             src.x, src.y,
             dib.StartScan(), dib.NumScans(),
             (void HUGE*)dib.GetBits(),
             (BITMAPINFO far*)dib.GetInfo(), dib.Usage()
         );                  // API typecast
}

inline bool TDC::StretchDIBits(const TRect& dst, const TRect& src,
                               const void HUGE* bits,
                               const BITMAPINFO far& info,
                               uint16 usage, uint32 rop) {
  return ::StretchDIBits(
             GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
             src.left, src.top, src.Width(), src.Height(),
             bits, (BITMAPINFO far*)&info, usage, rop
         );
         // API typecast
}

inline bool TDC::StretchDIBits(const TRect& dst, const TRect& src,
                               const TDib& dib, uint32 rop) {
  return ::StretchDIBits(
             GetHDC(),
             dst.left, dst.top, dst.Width(), dst.Height(),
             src.left, src.top, src.Width(), src.Height(),
             dib.GetBits(),
             (BITMAPINFO far*)dib.GetInfo(),
             dib.Usage(), rop
         );
             // API typecast
}

inline bool TDC::FloodFill(const TPoint& point, TColor C) {
  return ::FloodFill(GetHDC(), point.x, point.y, C);
}

inline bool TDC::ExtFloodFill(const TPoint& point, TColor color, uint16 fillType) {
  return ::ExtFloodFill(GetHDC(), point.x, point.y, color, fillType);
}

inline bool TDC::TextOut(const TPoint& p, const char far* str, int count) {
  return TextOut(p.x, p.y, str, count);
}

inline bool TDC::ExtTextOut(const TPoint& p, uint16 options, const TRect* rect,
                            const char far* str, int count, const int far* dx) {
  return ExtTextOut(p.x, p.y, options, rect, str, count, dx);
}

inline bool TDC::TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin) {
  TSize size;
  TabbedTextOut(p, str, count, numPositions, positions, tabOrigin, size);
  return true;
}

inline bool TDC::GetTextExtent(const char far* str, int stringLen, TSize& size) {
  return ::GetTextExtentPoint(GetAttributeHDC(), str, stringLen, &size);
}

inline TSize TDC::GetTextExtent(const char far* str, int stringLen) {
#if defined(BI_PLAT_WIN32)
  TSize size;
  ::GetTextExtentPoint(GetAttributeHDC(), str, stringLen, &size);
  return size;
#else
  return ::GetTextExtent(GetAttributeHDC(), str, stringLen);
#endif
}

inline bool TDC::GetTabbedTextExtent(const char far* str, int strLen,
                                     int numPositions, const int far* positions,
                                     TSize& size) const {
  size = ::GetTabbedTextExtent(GetAttributeHDC(), str, strLen, numPositions,
                               (int far*)positions);   // API Typecast
  return true;
}

inline TSize TDC::GetTabbedTextExtent(const char far* str, int strLen,
                                      int numPositions, 
                                      const int far* positions) const {
  return ::GetTabbedTextExtent(GetAttributeHDC(), str, strLen, numPositions,
                               (int far*)positions);   // API Typecast
}

inline uint TDC::GetTextAlign() const {
  return ::GetTextAlign(GetAttributeHDC());
}

inline uint TDC::SetTextAlign(uint flags) {
  if (GetHDC() != GetAttributeHDC())
    ::SetTextAlign(GetHDC(), flags);
  return ::SetTextAlign(GetAttributeHDC(), flags);
}

inline int TDC::GetTextCharacterExtra() const {
  return ::GetTextCharacterExtra(GetAttributeHDC());
}

inline int TDC::SetTextCharacterExtra(int extra) {
  if (GetHDC() != GetAttributeHDC())
    ::SetTextCharacterExtra(GetHDC(), extra);
  return ::SetTextCharacterExtra(GetAttributeHDC(), extra);
}

inline bool TDC::SetTextJustification(int breakExtra, int breakCount) {
  return ::SetTextJustification(GetAttributeHDC(), breakExtra, breakCount);
}

inline int TDC::GetTextFace(int count, char far* facename) const {
  return ::GetTextFace(GetAttributeHDC(), count, facename);
}

inline bool TDC::GetTextMetrics(TEXTMETRIC far& metrics) const {
  return ::GetTextMetrics(GetAttributeHDC(), &metrics);
}

inline uint32 TDC::GetGlyphOutline(uint chr, uint format, GLYPHMETRICS far& gm,
                                  uint32 buffSize, void far* buffer,
                                  const MAT2 far& mat2) {
  return ::GetGlyphOutline(GetAttributeHDC(), chr, format, &gm, buffSize,
                           buffer, (MAT2*)&mat2);
}

inline int TDC::GetKerningPairs(int pairs, KERNINGPAIR far* krnPair) {
  return ::GetKerningPairs(GetAttributeHDC(), pairs, krnPair);
}

#if defined(BI_PLAT_WIN32)
  inline uint32
#else
  inline uint16
#endif
TDC::GetOutlineTextMetrics(uint data, OUTLINETEXTMETRIC far& otm)
{
  return ::GetOutlineTextMetrics(GetAttributeHDC(), data, &otm);
}

inline bool TDC::GetCharWidth(uint firstChar, uint lastChar, int* buffer) {
  return ::GetCharWidth(GetAttributeHDC(), firstChar, lastChar, buffer);
}

inline uint32 TDC::SetMapperFlags(uint32 flag) {
  if (GetHDC() != GetAttributeHDC())
    ::SetMapperFlags(GetHDC(), flag);
  return ::SetMapperFlags(GetAttributeHDC(), flag);
}

inline bool TDC::GetAspectRatioFilter(TSize& size) const {
  return ::GetAspectRatioFilterEx(GetAttributeHDC(), &size);
}

inline int TDC::EnumFonts(const char far* faceName, OLDFONTENUMPROC callback, void far* data) const {
  return ::EnumFonts(GetAttributeHDC(), faceName, callback, LPARAM(data));
}

inline bool TDC::GetCharABCWidths(uint firstChar, uint lastChar, ABC* abc) {
  return ::GetCharABCWidths(GetAttributeHDC(), firstChar, lastChar, abc);
}

inline int TDC::EnumFontFamilies(const char far* familyName, FONTENUMPROC callback, void far* data) const {
  return ::EnumFontFamilies(GetAttributeHDC(), familyName, callback, LPARAM(data));
}

inline uint32 TDC::GetFontData(uint32 table, uint32 offset, void* buffer, long data) {
  return ::GetFontData(GetAttributeHDC(), table, offset, buffer, data);
}

#if defined(BI_PLAT_WIN32)
inline bool TDC::BeginPath() {
  return ::BeginPath(GetHDC());
}

inline bool TDC::CloseFigure() {
  return ::CloseFigure(GetHDC());
}

inline bool TDC::EndPath() {
  return ::EndPath(GetHDC());
}

inline bool TDC::FlattenPath() {
  return ::FlattenPath(GetHDC());
}

inline bool TDC::WidenPath() {
  return ::WidenPath(GetHDC());
}

inline bool TDC::FillPath() {
  return ::FillPath(GetHDC());
}

inline bool TDC::StrokePath() {
  return ::StrokePath(GetHDC());
}

inline bool TDC::StrokeAndFillPath() {
  return ::StrokeAndFillPath(GetHDC());
}

inline bool TDC::SelectClipPath(int mode) {
  return ::SelectClipPath(GetHDC(), mode);
}

inline HRGN TDC::PathToRegion() {
  return ::PathToRegion(GetHDC());
}
#endif


inline HMETAFILE TMetaFileDC::Close() {
  HMETAFILE mf = ::CloseMetaFile(GetHDC());
  Handle = 0;
  return mf;
}

inline int TPrintDC::Escape(int esc, int count, const void* inData, void* outData) {
  return ::Escape(GetHDC(), esc, count, (const char far*)inData, outData);
                                        // API type cast
}

inline int TPrintDC::SetAbortProc(ABORTPROC proc) {
  return ::SetAbortProc(GetHDC(), proc);
}

inline int TPrintDC::StartDoc(const char far* docName, const char far* output) {
  DocInfo.lpszDocName = (char far*)docName;
  DocInfo.lpszOutput = (char far*)output;
  return ::StartDoc(GetHDC(), &DocInfo);
}

inline int TPrintDC::StartPage() {  // Only call if not banding
  return ::StartPage(GetHDC());
}

inline int TPrintDC::BandInfo(TBandInfo& bandInfo) {
  return Escape(BANDINFO, sizeof(TBandInfo), 0, (LPSTR)&bandInfo);
}

inline int TPrintDC::NextBand(TRect& rect) {
  return Escape(NEXTBAND, 0, 0, (void*)&rect);
}

inline int TPrintDC::EndPage() {  // Only call if not banding
  RestoreObjects();  // Make sure this TDC stays in sync with HDC
  return ::EndPage(GetHDC());
}

inline int TPrintDC::AbortDoc() {
  return ::AbortDoc(GetHDC());
}

inline int TPrintDC::EndDoc() {
  return ::EndDoc(GetHDC());
}

#if defined(BI_PLAT_WIN16)
inline bool TPrintDC::QueryAbort(int rsvd) {
  return ::QueryAbort(GetHDC(), rsvd);
}
#endif

inline uint TPrintDC::QueryEscSupport(int escapeNum) {
  return Escape(QUERYESCSUPPORT, sizeof(int), &escapeNum);
}

inline int TPrintDC::SetCopyCount(int reqestCopies, int& actualCopies) {
  return Escape(SETCOPYCOUNT, sizeof(int), &reqestCopies, &actualCopies);
}

#endif  // OWL_DC_H
