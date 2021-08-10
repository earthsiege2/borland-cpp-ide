//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\dc.h
//   Definition of DC classes
//----------------------------------------------------------------------------
#if !defined(__OWL_DC_H)
#define __OWL_DC_H

#if !defined(__OWL_GDIBASE_H)
  #include <owl\gdibase.h>
#endif
#if !defined(__PRINT_H) && !defined(__WIN32__)
  #include <print.h>      // Win16 printing and some general DC APIs
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

#if defined(__WIN32__)
  #define OLDFONTENUMPROC FONTENUMPROC
#else
  // Win 32 object defines for 16 bit GetCurrentObject emulation
  #define OBJ_PEN             1
  #define OBJ_BRUSH           2
  #define OBJ_PAL             5
  #define OBJ_FONT            6
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
    BOOL         GetDCOrg(TPoint& point) const;
    virtual int  SaveDC() const;
    virtual BOOL RestoreDC(int savedDC = -1);
    virtual int  GetDeviceCaps(int index) const;
    virtual BOOL ResetDC(DEVMODE far& devMode);

    // Select GDI objects into this DC and restore them to original
    void         SelectObject(const TBrush& brush);
    void         SelectObject(const TPen& pen);
    virtual void SelectObject(const TFont& font);
    void         SelectObject(const TPalette& palette, BOOL forceBackground=FALSE);
    virtual void SelectStockObject(int index);
    void         RestoreBrush();
    void         RestorePen();
    virtual void RestoreFont();
    void         RestorePalette();
    #if defined(__WIN32__)
      void       RestoreTextBrush();
    #endif
    void         RestoreObjects();
    HANDLE       GetCurrentObject(UINT objectType) const;

    // Drawing tool functions
    BOOL         GetBrushOrg(TPoint& point) const;
    BOOL         SetBrushOrg(const TPoint& origin, TPoint far* oldOrg=0);
    int          EnumObjects(UINT objectType, GOBJENUMPROC proc, LPVOID data) const;

    // Color and palette functions
    TColor       GetNearestColor(TColor Color) const;
    int          RealizePalette();
    void         UpdateColors();
    UINT         GetSystemPaletteEntries(int start, int num, 
                                         PALETTEENTRY far* entries) const;
    UINT         GetSystemPaletteUse() const;
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
    #if defined(__WIN32__)
      BOOL       SetMiterLimit(float newLimit, float* oldLimit=0);
    #endif

    // Viewport & window mapping functions
    int          GetMapMode() const;
    virtual int  SetMapMode(int mode);
    #if defined(__WIN32__)
      BOOL       SetWorldTransform(XFORM far& xform);
      BOOL       ModifyWorldTransform(XFORM far& xform, DWORD mode);
    #endif

    BOOL         GetViewportOrg(TPoint& point) const;
    TPoint       GetViewportOrg() const;
    virtual BOOL SetViewportOrg(const TPoint& origin, TPoint far* oldOrg=0);
    virtual BOOL OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg=0);

    BOOL         GetViewportExt(TSize& extent) const;
    TSize        GetViewportExt() const;
    virtual BOOL SetViewportExt(const TSize& extent, TSize far* oldExtent=0);
    virtual BOOL ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                                  TSize far* oldExtent=0);

    BOOL         GetWindowOrg(TPoint& point) const;
    TPoint       GetWindowOrg() const;
    BOOL         SetWindowOrg(const TPoint& origin, TPoint far* oldOrg=0);
    BOOL         OffsetWindowOrg(const TPoint& delta, TPoint far* oldOrg=0);

    BOOL         GetWindowExt(TSize& extent) const;
    TSize        GetWindowExt() const;
    virtual BOOL SetWindowExt(const TSize& extent, TSize far* oldExtent=0);
    virtual BOOL ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom,
                                TSize far* oldExtent=0);

    // Coordinate functions
    BOOL        DPtoLP(TPoint* points, int count = 1) const;
    BOOL        LPtoDP(TPoint* points, int count = 1) const;

    // Clip & Update Rect & Rgn functions
    int         GetClipBox(TRect& rect) const;
    TRect       GetClipBox() const;
    int         ExcludeClipRect(const TRect& rect);
    int         ExcludeUpdateRgn(HWND wnd);
    int         IntersectClipRect(const TRect& rect);
    int         OffsetClipRgn(const TPoint& delta);
    int         SelectClipRgn(const TRegion& region);
    BOOL        PtVisible(const TPoint& point) const;
    BOOL        RectVisible(const TRect& rect) const;
    BOOL        GetBoundsRect(TRect& bounds, WORD flags) const;
    UINT        SetBoundsRect(TRect& bounds, UINT flags);
    BOOL        GetClipRgn(TRegion& region) const;

    // MetaFile functions
    int         EnumMetaFile(const TMetaFilePict& metaFile,
                             MFENUMPROC callback, LPVOID data) const;
    BOOL        PlayMetaFile(const TMetaFilePict& metaFile);
    void        PlayMetaFileRecord(HANDLETABLE far& Handletable,
                                   METARECORD far& metaRecord, int count);

    // Output functions- Current position
    BOOL        GetCurrentPosition(TPoint& point) const;
    BOOL        MoveTo(int x, int y);
    BOOL        MoveTo(const TPoint& point);
    BOOL        MoveTo(const TPoint& point, TPoint& oldPoint);

    // Output functions- Icons
    BOOL        DrawIcon(int x, int y, const TIcon& icon);
    BOOL        DrawIcon(const TPoint& point, const TIcon& icon);

    // Output functions- Rects
    BOOL        FrameRect(int x1, int y1, int x2, int y2, const TBrush& brush);
    BOOL        FrameRect(const TRect& rect, const TBrush& brush);
    BOOL        FillRect(int x1, int y1, int x2, int y2, const TBrush& brush);
    BOOL        FillRect(const TRect& rect, const TBrush& brush);
    BOOL        InvertRect(int x1, int y1, int x2, int y2);
    BOOL        InvertRect(const TRect& rect);
    BOOL        DrawFocusRect(int x1, int y1, int x2, int y2);
    BOOL        DrawFocusRect(const TRect& rect);

    // Filled rect using ExtTextOut, no dithered colors & uses or sets BkColor
    BOOL        TextRect(int x1, int y1, int x2, int y2);
    BOOL        TextRect(const TRect& rect);
    BOOL        TextRect(int x1, int y1, int x2, int y2, TColor color);
    BOOL        TextRect(const TRect& rect, TColor color);

    // 
    void        OWLFastWindowFrame(TBrush &brush, TRect &r, int xWidth, int yWidth);
    
    // Output functions- Regions
    BOOL        FrameRgn(const TRegion& region, const TBrush& brush, const TPoint& p);
    BOOL        FillRgn(const TRegion& region, const TBrush& brush);
    BOOL        InvertRgn(const TRegion& region);
    BOOL        PaintRgn(const TRegion& region);

    // Output functions- Shapes
    #if defined(__WIN32__)
      BOOL      AngleArc(int x, int y, DWORD radius, float startAngle,
                         float sweepAngle);
      BOOL      AngleArc(const TPoint& center, DWORD radius, float startAngle,
                         float sweepAngle);
    #endif
    BOOL        Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                    int y4);
    BOOL        Arc(const TRect& r, const TPoint& start, const TPoint& end);
    BOOL        Chord(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                      int y4);
    BOOL        Chord(const TRect& R, const TPoint& Start, const TPoint& End);
    BOOL        Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                    int y4);
    BOOL        Pie(const TRect& rect, const TPoint& start, const TPoint& end);
    BOOL        Ellipse(int x1, int y1, int x2, int y2);
    BOOL        Ellipse(const TPoint& p1, const TPoint& p2);
    BOOL        Ellipse(const TPoint& point, const TSize& size);
    BOOL        Ellipse(const TRect& rect);
    BOOL        LineTo(int x, int y);
    BOOL        LineTo(const TPoint& point);
    BOOL        Polyline(const TPoint* points, int count);
    BOOL        Polygon(const TPoint* points, int count);
    BOOL        PolyPolygon(const TPoint* points, const int* PolyCounts,
                            int count);
    #if defined(__WIN32__)
      BOOL      PolyPolyline(const TPoint* points, const int* PolyCounts,
                             int count);
      BOOL      PolyBezier(const TPoint* points, int count);
      BOOL      PolyBezierTo(const TPoint* points, int count);
      BOOL      PolyDraw(const TPoint* points, BYTE* types, int count);
      BOOL      PolylineTo(const TPoint* points, int count);
    #endif
    BOOL        Rectangle(int x1, int y1, int x2, int y2);
    BOOL        Rectangle(const TPoint& p1, const TPoint& p2);
    BOOL        Rectangle(const TPoint& point, const TSize& s);
    BOOL        Rectangle(const TRect& rect);
    BOOL        RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
    BOOL        RoundRect(const TPoint& p1, const TPoint& p2, const TPoint& rad);
    BOOL        RoundRect(const TPoint& p, const TSize& s, const TPoint& rad);
    BOOL        RoundRect(const TRect& rect, const TPoint& rad);

    // Output functions- bitmaps & blitting
    TColor      GetPixel(int x, int y) const;
    TColor      GetPixel(const TPoint& point) const;
    TColor      SetPixel(int x, int y, TColor color);
    TColor      SetPixel(const TPoint& p, TColor color);
    BOOL        BitBlt(int dstX, int dstY, int w, int h, const TDC& srcDC,
                       int srcX, int srcY, DWORD rop=SRCCOPY);
    BOOL        BitBlt(const TRect& dst, const TDC& srcDC,
                       const TPoint& src, DWORD rop=SRCCOPY);
    BOOL        PatBlt(int x, int y, int w, int h, DWORD rop=PATCOPY);
    BOOL        PatBlt(const TRect& dst, DWORD rop=PATCOPY);
    BOOL        ScrollDC(int x, int y, const TRect& scroll, const TRect& clip,
                         TRegion& updateRgn, TRect& updateRect);
    BOOL        ScrollDC(const TPoint& delta, const TRect& scroll,
                         const TRect& clip, TRegion& updateRgn,
                         TRect& updateRect);
    BOOL        StretchBlt(int dstX, int dstY, int dstW, int dstH,
                           const TDC& srcDC, int srcX, int srcY, int srcW,
                           int srcH, DWORD rop=SRCCOPY);
    BOOL        StretchBlt(const TRect& dst, const TDC& srcDC,
                           const TRect& src, DWORD rop=SRCCOPY);
    #if defined(__WIN32__)
      BOOL      MaskBlt(const TRect& dst, const TDC& srcDC,
                        const TPoint& src, const TBitmap& maskBm,
                        const TPoint& maskPos, DWORD rop=SRCCOPY);
      BOOL      PlgBlt(const TPoint& dst, const TDC& srcDC,
                       const TRect& src, const TBitmap& maskBm,
                       const TPoint& maskPos, DWORD rop=SRCCOPY);
    #endif
    BOOL        GetDIBits(const TBitmap& bitmap, WORD startScan, WORD numScans,
                          void HUGE* bits, const BITMAPINFO far& info,
                          WORD usage);
    BOOL        GetDIBits(const TBitmap& bitmap, TDib& dib);
    BOOL        SetDIBits(TBitmap& bitmap, WORD startScan, WORD numScans,
                          const void HUGE* bits, const BITMAPINFO far& Info,
                          WORD usage);
    BOOL        SetDIBits(TBitmap& bitmap, const TDib& dib);
    BOOL        SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                  WORD startScan, WORD numScans,
                                  const void HUGE* bits,
                                  const BITMAPINFO far& bitsInfo, WORD usage);
    BOOL        SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                  const TDib& dib);
    BOOL        StretchDIBits(const TRect& dst, const TRect& src,
                              const void HUGE* bits,
                              const BITMAPINFO far& bitsInfo,
                              WORD usage, DWORD rop=SRCCOPY);
    BOOL        StretchDIBits(const TRect& dst, const TRect& src,
                              const TDib& dib, DWORD rop=SRCCOPY);
    BOOL        FloodFill(const TPoint& point, TColor color);
    BOOL        ExtFloodFill(const TPoint& point, TColor color, WORD fillType);

    // Output functions- text
    virtual BOOL TextOut(int x, int y, const char far* str, int count=-1);
    BOOL         TextOut(const TPoint& p, const char far* str, int count=-1);
    virtual BOOL ExtTextOut(int x, int y, WORD options, const TRect* r,
                      const char far* str, int count, const int far* dx = 0);
    BOOL         ExtTextOut(const TPoint& p, WORD options, const TRect* r,
                      const char far* str, int count, const int far* dx = 0);
    virtual BOOL TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin, TSize& size);
    BOOL         TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin);
    virtual BOOL DrawText(const char far* str, int count, const TRect& r,
                          WORD format=0);
    virtual BOOL GrayString(const TBrush& brush, GRAYSTRINGPROC outputFunc,
                            const char far* str, int count, const TRect& r);

    // Text functions
    BOOL        GetTextExtent(const char far* str, int stringLen, TSize& size);
    TSize       GetTextExtent(const char far* str, int stringLen);
    BOOL        GetTabbedTextExtent(const char far* str, int stringLen,
                                    int numPositions, const int far* positions,
                                    TSize& size) const;
    TSize       GetTabbedTextExtent(const char far* str, int stringLen,
                              int numPositions, const int far* positions) const;
    UINT        GetTextAlign() const;
    UINT        SetTextAlign(UINT flags);
    int         GetTextCharacterExtra() const;
    int         SetTextCharacterExtra(int extra);
    BOOL        SetTextJustification(int breakExtra, int breakCount);
    int         GetTextFace(int count, char far* facename) const;
    //string&    GetTextFace(string& facename) const;
    BOOL        GetTextMetrics(TEXTMETRIC far& metrics) const;
    DWORD       GetGlyphOutline(UINT chr, UINT format, GLYPHMETRICS far& gm,
                                DWORD buffSize, void far* buffer,
                                const MAT2 far& mat2);
    int         GetKerningPairs(int pairs, KERNINGPAIR far* krnPair);
  #if defined(__WIN32__)
    DWORD       GetOutlineTextMetrics(UINT data, OUTLINETEXTMETRIC far& otm);
  #else
    WORD        GetOutlineTextMetrics(UINT data, OUTLINETEXTMETRIC far& otm);
  #endif

    // Font functions
    BOOL        GetCharWidth(UINT firstChar, UINT lastChar, int* buffer);
    DWORD       SetMapperFlags(DWORD flag);
    BOOL        GetAspectRatioFilter(TSize& size) const;
    int         EnumFonts(const char far* faceName, OLDFONTENUMPROC callback,
                          LPVOID data) const;
    int         EnumFontFamilies(const char far* family,
                                 FONTENUMPROC proc, LPVOID data) const;
    DWORD       GetFontData(DWORD table, DWORD offset, void* buffer, long data);
    BOOL        GetCharABCWidths(UINT firstChar, UINT lastChar, ABC* abc);

    // Path functions
    #if defined(__WIN32__)
      BOOL        BeginPath();
      BOOL        CloseFigure();
      BOOL        EndPath();
      BOOL        FlattenPath();
      BOOL        WidenPath();
      BOOL        FillPath();
      BOOL        StrokePath();
      BOOL        StrokeAndFillPath();
      BOOL        SelectClipPath(int mode);
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
    #if defined(__WIN32__)
      HBRUSH    OrgTextBrush;
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
    void        SelectObject(const TPalette& palette, BOOL forceBackground=FALSE)
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
  BOOL  HasGraphics;
  BOOL  HasText;
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

  #if !defined(__WIN32__)
    BOOL        QueryAbort(int rsvd=0);
  #endif

    UINT        QueryEscSupport(int escapeNum);
    int         SetCopyCount(int reqestCount, int& actualCount);

    static DWORD DeviceCapabilities(const char far* driver,
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
#if !defined(__OWL_GDIOBJEC_H)
  #include <owl\gdiobjec.h>
#endif
#if !defined(__OWL_METAFILE_H)
  #include <owl\metafile.h>
#endif


inline BOOL TDC::GetDCOrg(TPoint& point) const {
#if defined(__WIN32__)
  return ::GetDCOrgEx(GetAttributeHDC(), &point);
#else
  point = ::GetDCOrg(GetAttributeHDC());
  return TRUE;
#endif
}

inline BOOL TDC::GetBrushOrg(TPoint& point) const {
  return ::GetBrushOrgEx(GetHDC(), &point);
}

inline BOOL TDC::SetBrushOrg(const TPoint& org, TPoint far* oldOrg) {
  #if defined(__WIN32__)
    return ::SetBrushOrgEx(GetHDC(), org.x, org.y, oldOrg);
    // ::UnrealizeObject(CurrentBrush); // could automate this for user
  #else
    if (oldOrg)
      *oldOrg = ::SetBrushOrg(GetHDC(), org.x, org.y);
    else
      ::SetBrushOrg(GetHDC(), org.x, org.y);
    // ::UnrealizeObject(CurrentBrush); // could automate this for user
    return TRUE;
  #endif
}

inline int TDC::EnumObjects(UINT objectType, GOBJENUMPROC proc, LPVOID data) const {
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

inline UINT TDC::GetSystemPaletteEntries(int start, int num, PALETTEENTRY far* entries) const {
  return ::GetSystemPaletteEntries(GetHDC(), start, num, entries);
}

inline UINT TDC::GetSystemPaletteUse() const {
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

#if defined(__WIN32__)
inline BOOL TDC::SetMiterLimit(float newLimit, float* oldLimit) {
  if (GetHDC() != GetAttributeHDC())
    ::SetMiterLimit(GetHDC(), newLimit, oldLimit);
  return ::SetMiterLimit(GetAttributeHDC(), newLimit, oldLimit);
}
#endif

inline int TDC::GetMapMode() const {
  return ::GetMapMode(GetAttributeHDC());
}

#if defined(__WIN32__)
inline BOOL TDC::SetWorldTransform(XFORM far& xform) {
  if (GetHDC() != GetAttributeHDC())
    ::SetWorldTransform(GetHDC(), &xform);
  return ::SetWorldTransform(GetAttributeHDC(), &xform);
}

inline BOOL TDC::ModifyWorldTransform(XFORM far& xform, DWORD mode) {
  if (GetHDC() != GetAttributeHDC())
    ::ModifyWorldTransform(GetHDC(), &xform, mode);
  return ::ModifyWorldTransform(GetAttributeHDC(), &xform, mode);
}
#endif

inline BOOL TDC::GetViewportOrg(TPoint& point) const {
  return ::GetViewportOrgEx(GetAttributeHDC(), &point);
}

inline TPoint TDC::GetViewportOrg() const {
  #if defined(__WIN32__)
    TPoint point;
    ::GetViewportOrgEx(GetAttributeHDC(), &point);
    return point;
  #else
    return ::GetViewportOrg(GetAttributeHDC());
  #endif
}

inline BOOL TDC::GetViewportExt(TSize& extent) const {
  return ::GetViewportExtEx(GetAttributeHDC(), &extent);
}

inline TSize TDC::GetViewportExt() const {
  #if defined(__WIN32__)
    TSize extent;
    ::GetViewportExtEx(GetAttributeHDC(), &extent);
    return extent;
  #else
    return ::GetViewportExt(GetAttributeHDC());
  #endif
}

inline BOOL TDC::GetWindowOrg(TPoint& point) const {
  return ::GetWindowOrgEx(GetAttributeHDC(), &point);
}

inline TPoint TDC::GetWindowOrg() const {
  #if defined(__WIN32__)
    TPoint point;
    ::GetWindowOrgEx(GetAttributeHDC(), &point);
    return point;
  #else
    return ::GetWindowOrg(GetAttributeHDC());
  #endif
}

inline BOOL TDC::GetWindowExt(TSize& extent) const {
  return ::GetWindowExtEx(GetAttributeHDC(), &extent);
}

inline TSize TDC::GetWindowExt() const {
  #if defined(__WIN32__)
    TSize extent;
    ::GetWindowExtEx(GetAttributeHDC(), &extent);
    return extent;
  #else
    return ::GetWindowExt(GetAttributeHDC());
  #endif
}

inline BOOL TDC::DPtoLP(TPoint* points, int count) const {
  return ::DPtoLP(GetAttributeHDC(), points, count);
}

//inline BOOL TDC::DPtoLP(TRect& rect) const {
//  return DPtoLP(rect, 2);
//}

inline BOOL TDC::LPtoDP(TPoint* points, int count) const {
  return ::LPtoDP(GetHDC(), points, count);
}

//inline BOOL TDC::LPtoDP(TRect& rect) const {
//  return LPtoDP(rect, 2);
//}

inline int TDC::GetClipBox(TRect& rect) const {
  return ::GetClipBox(GetAttributeHDC(), &rect);
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

inline BOOL TDC::PtVisible(const TPoint& point) const {
  return ::PtVisible(GetHDC(), point.x, point.y);
}

inline BOOL TDC::RectVisible(const TRect& rect) const {
  return ::RectVisible(GetHDC(), &rect);
}

inline BOOL TDC::GetBoundsRect(TRect& bounds, WORD flags) const {
  return ::GetBoundsRect(GetHDC(), &bounds, flags);
}

inline UINT TDC::SetBoundsRect(TRect& bounds, UINT flags) {
  return ::SetBoundsRect(GetHDC(), &bounds, flags);
}

#if defined(__WIN32__)
inline BOOL TDC::GetClipRgn(TRegion& region) const {
  return ::GetClipRgn(GetHDC(), region);
}
#endif

inline int TDC::EnumMetaFile(const TMetaFilePict& metafile, MFENUMPROC callback,
                             LPVOID data) const {
  return ::EnumMetaFile(GetHDC(), metafile, callback, (long)data);
}

inline BOOL TDC::PlayMetaFile(const TMetaFilePict& metafile) {
  return ::PlayMetaFile(GetHDC(), metafile);
}

inline void TDC::PlayMetaFileRecord(HANDLETABLE far& handletable,
                                    METARECORD far& metaRecord, int count) {
  ::PlayMetaFileRecord(GetHDC(), &handletable, &metaRecord, count);
}

inline BOOL TDC::GetCurrentPosition(TPoint& point) const {
  return ::GetCurrentPositionEx(GetHDC(), &point);
}

inline BOOL TDC::MoveTo(int x, int y) {
  return ::MoveToEx(GetHDC(), x, y, 0);
}

inline BOOL TDC::MoveTo(const TPoint& point) {
  return ::MoveToEx(GetHDC(), point.x, point.y, 0);
}

inline BOOL TDC::MoveTo(const TPoint& point, TPoint& OldPoint) {
  return ::MoveToEx(GetHDC(), point.x, point.y, &OldPoint);
}

inline BOOL TDC::DrawIcon(int x, int y, const TIcon& icon) {
  return ::DrawIcon(GetHDC(), x, y, icon);
}

inline BOOL TDC::DrawIcon(const TPoint& point, const TIcon& icon) {
  return ::DrawIcon(GetHDC(), point.x, point.y, icon);
}

inline BOOL TDC::FrameRect(int x1, int y1, int x2, int y2, const TBrush& brush) {
  return ::FrameRect(GetHDC(), &TRect(x1, y1, x2, y2), brush);
}

inline BOOL TDC::FrameRect(const TRect& rect, const TBrush& brush) {
  return ::FrameRect(GetHDC(), &rect, brush);
}

inline BOOL TDC::FillRect(int x1, int y1, int x2, int y2, const TBrush& brush) {
  return ::FillRect(GetHDC(), &TRect(x1, y1, x2, y2), brush);
}

inline BOOL TDC::FillRect(const TRect& rect, const TBrush& brush) {
  return ::FillRect(GetHDC(), &rect, brush);
}

//
// rect must be normalized for inverRect
//
inline BOOL TDC::InvertRect(int x1, int y1, int x2, int y2) {
  ::InvertRect(GetHDC(), &TRect(x1, y1, x2, y2));
  return TRUE;
}

inline BOOL TDC::InvertRect(const TRect& rect) {
  ::InvertRect(GetHDC(), &rect);
  return TRUE;
}

inline BOOL TDC::DrawFocusRect(int x1, int y1, int x2, int y2) {
  ::DrawFocusRect(GetHDC(), &TRect(x1, y1, x2, y2));
  return TRUE;
}

inline BOOL TDC::DrawFocusRect(const TRect& rect) {
  ::DrawFocusRect(GetHDC(), &rect);
  return TRUE;
}

inline BOOL TDC::TextRect(int x1, int y1, int x2, int y2) {
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &TRect(x1, y1, x2, y2), 0, 0, 0);
}

inline BOOL TDC::TextRect(const TRect& rect) {
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &rect, 0, 0, 0);
}

inline BOOL TDC::TextRect(int x1, int y1, int x2, int y2, TColor color) {
  SetBkColor(color);
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &TRect(x1, y1, x2, y2), 0, 0, 0);
}

inline BOOL TDC::TextRect(const TRect& rect, TColor color) {
  SetBkColor(color);
  return ::ExtTextOut(GetHDC(), 0, 0, ETO_OPAQUE, &rect, 0, 0, 0);
}

inline BOOL TDC::FrameRgn(const TRegion& region, const TBrush& brush, const TPoint& p) {
  return ::FrameRgn(GetHDC(), region, brush, p.x, p.y);
}

inline BOOL TDC::FillRgn(const TRegion& region, const TBrush& brush) {
  return ::FillRgn(GetHDC(), region, brush);
}

inline BOOL TDC::InvertRgn(const TRegion& region) {
  return ::InvertRgn(GetHDC(), region);
}

inline BOOL TDC::PaintRgn(const TRegion& region) {
  return ::PaintRgn(GetHDC(), region);
}

#if defined(__WIN32__)
inline BOOL TDC::AngleArc(int x, int y, DWORD radius, float startAngle, float sweepAngle) {
  return ::AngleArc(GetHDC(), x, y, radius, startAngle, sweepAngle);
}

inline BOOL TDC::AngleArc(const TPoint& Center, DWORD radius, float StartAngle, float SweepAngle) {
  return ::AngleArc(GetHDC(), Center.x, Center.y, radius, StartAngle, SweepAngle);
}
#endif

inline BOOL TDC::Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Arc(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline BOOL TDC::Arc(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Arc(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline BOOL TDC::Chord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Chord(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline BOOL TDC::Chord(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Chord(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline BOOL TDC::Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return ::Pie(GetHDC(), x1, y1, x2, y2, x3, y3, x4, y4);
}

inline BOOL TDC::Pie(const TRect& rect, const TPoint& start, const TPoint& end) {
  return ::Pie(GetHDC(), rect.left, rect.top, rect.right, rect.bottom, start.x, start.y, end.x, end.y);
}

inline BOOL TDC::Ellipse(int x1, int y1, int x2, int y2) {
  return ::Ellipse(GetHDC(), x1, y1, x2, y2);
}

inline BOOL TDC::Ellipse(const TPoint& p1, const TPoint& p2) {
  return ::Ellipse(GetHDC(), p1.x, p1.y, p2.x, p2.y);
}

inline BOOL TDC::Ellipse(const TPoint& p, const TSize& s) {
  return ::Ellipse(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy);
}

inline BOOL TDC::Ellipse(const TRect& rect) {
  return ::Ellipse(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline BOOL TDC::LineTo(int x, int y) {
  return ::LineTo(GetHDC(), x, y);
}

inline BOOL TDC::LineTo(const TPoint& point) {
  return ::LineTo(GetHDC(), point.x, point.y);
}

inline BOOL TDC::Polyline(const TPoint* points, int count) {
  return ::Polyline(GetHDC(), points, count);
}

inline BOOL TDC::Polygon(const TPoint* points, int count) {
  return ::Polygon(GetHDC(), (TPoint*)points, count);
}

inline BOOL TDC::PolyPolygon(const TPoint* points, const int* polyCounts, int count) {
  return ::PolyPolygon(GetHDC(), (TPoint*)points, (int*)polyCounts, count); // API typecast
}

#if defined(__WIN32__)
inline BOOL TDC::PolyPolyline(const TPoint* points, const int* polyCounts, int count) {
  return ::PolyPolyline(GetHDC(), (TPoint*)points, (DWORD*)polyCounts, count); // API typecast
}

inline BOOL TDC::PolyBezier(const TPoint* points, int count) {
  return ::PolyBezier(GetHDC(), (TPoint*)points, count);
}

inline BOOL TDC::PolyBezierTo(const TPoint* points, int count) {
  return ::PolyBezierTo(GetHDC(), (TPoint*)points, count);
}

inline BOOL TDC::PolyDraw(const TPoint* points, BYTE* types, int count) {
  return ::PolyDraw(GetHDC(), (TPoint*)points, types, count);
}

inline BOOL TDC::PolylineTo(const TPoint* points, int count) {   //Q or TPointList
  return ::PolylineTo(GetHDC(), (TPoint*)points, count);
}
#endif

inline BOOL TDC::Rectangle(int x1, int y1, int x2, int y2) {
  return ::Rectangle(GetHDC(), x1, y1, x2, y2);
}

inline BOOL TDC::Rectangle(const TPoint& p1, const TPoint& p2) {
  return ::Rectangle(GetHDC(), p1.x, p1.y, p2.x, p2.y);
}

inline BOOL TDC::Rectangle(const TPoint& p, const TSize& s) {
  return ::Rectangle(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy);
}

inline BOOL TDC::Rectangle(const TRect& rect) {
  return ::Rectangle(GetHDC(), rect.left, rect.top, rect.right, rect.bottom);
}

inline BOOL TDC::RoundRect(int x1, int y1, int x2, int y2, int x3, int y3) {
  return ::RoundRect(GetHDC(), x1, y1, x2, y2, x3, y3);
}

inline BOOL TDC::RoundRect(const TPoint& p1, const TPoint& p2, const TPoint& rad) {
  return ::RoundRect(GetHDC(), p1.x, p1.y, p2.x, p2.y, rad.x, rad.y);
}

inline BOOL TDC::RoundRect(const TPoint& p, const TSize& s, const TPoint& rad) {
  return ::RoundRect(GetHDC(), p.x, p.y, p.x+s.cx, p.y+s.cy, rad.x, rad.y);
}

inline BOOL TDC::RoundRect(const TRect& rect, const TPoint& rad) {
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

inline BOOL TDC::BitBlt(int dstX, int dstY, int w, int h, const TDC& srcDC,
                       int srcX, int srcY, DWORD rop) {
  return ::BitBlt(GetHDC(), dstX, dstY, w, h, srcDC, srcX, srcY, rop);
}

inline BOOL TDC::BitBlt(const TRect& dst, const TDC& srcDC, const TPoint& src,
                        DWORD rop) {
  return ::BitBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
                  srcDC, src.x, src.y, rop);
}

inline BOOL TDC::PatBlt(int x, int y, int w, int h, DWORD rop) {
  return ::PatBlt(GetHDC(), x, y, w, h, rop);
}

inline BOOL TDC::PatBlt(const TRect& dst, DWORD rop) {
  return ::PatBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(), rop);
}

inline BOOL TDC::ScrollDC(int dx, int dy, const TRect& scroll, const TRect& clip,
                          TRegion& updateRgn, TRect& updateRect) {
  return ::ScrollDC(GetHDC(), dx, dy, &scroll, &clip, updateRgn, &updateRect);
}

inline BOOL TDC::ScrollDC(const TPoint& delta, const TRect& scroll, const TRect& clip,
                          TRegion& updateRgn, TRect& updateRect) {
  return ::ScrollDC(GetHDC(), delta.x, delta.y, &scroll, &clip, updateRgn, &updateRect);
}

inline BOOL TDC::StretchBlt(int dstX, int dstY, int dstW, int dstH,
                           const TDC& srcDC, int srcX, int srcY, int srcW,
                           int srcH, DWORD rop) {
  return ::StretchBlt(GetHDC(), dstX, dstY, dstW, dstH,
                      srcDC, srcX, srcY, srcW, srcH, rop);
}

inline BOOL TDC::StretchBlt(const TRect& dst, const TDC& srcDC,
                            const TRect& src, DWORD rop) {
  return ::StretchBlt(GetHDC(),
                      dst.left, dst.top, dst.Width(), dst.Height(),
                      srcDC, src.left, src.top,
                      src.Width(), src.Height(), rop);
}

#if defined(__WIN32__)
inline BOOL TDC::MaskBlt(const TRect& dst,
                         const TDC& srcDC, const TPoint& src,
                         const TBitmap& maskBm, const TPoint& maskPos,
                         DWORD rop) {
  return ::MaskBlt(GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
                   srcDC, src.x, src.y, maskBm, maskPos.x, maskPos.y,
                   rop);
  return FALSE;
}

inline BOOL TDC::PlgBlt(const TPoint& dst,
                        const TDC& srcDC, const TRect& src,
                        const TBitmap& maskBm, const TPoint& maskPos, DWORD rop) {
  return ::PlgBlt(GetHDC(), (TPoint*)&dst,
                  srcDC, src.left, src.top, src.Width(), src.Height(),
                  maskBm, maskPos.x, maskPos.y);
  return FALSE;
}
#endif

inline BOOL TDC::GetDIBits(const TBitmap& bitmap, WORD startScan, WORD numScans,
                           void HUGE* bits, const BITMAPINFO far& info,
                           WORD usage) {
  return ::GetDIBits(GetHDC(), bitmap, startScan, numScans, bits,
                    (BITMAPINFO far*)&info, usage);
}

inline BOOL TDC::GetDIBits(const TBitmap& bitmap, TDib& dib) {
  return ::GetDIBits(GetHDC(), bitmap, dib.StartScan(), dib.NumScans(),
                     dib.GetBits(), dib.GetInfo(), dib.Usage());
}

inline BOOL TDC::SetDIBits(TBitmap& bitmap, WORD startScan, WORD numScans,
                           const void HUGE* bits, const BITMAPINFO far& info,
                           WORD usage) {
  return ::SetDIBits(GetHDC(), bitmap, startScan, numScans,
                     bits, (BITMAPINFO far*)&info, usage);
                     // API typecast
}

inline BOOL TDC::SetDIBits(TBitmap& bitmap, const TDib& dib) {
  return ::SetDIBits(GetHDC(), bitmap, dib.StartScan(), dib.NumScans(),
                     dib.GetBits(), (BITMAPINFO far*)dib.GetInfo(), dib.Usage());
                                   // API typecast
}

inline BOOL TDC::SetDIBitsToDevice(const TRect& dst, const TPoint& src,
                                   WORD startScan, WORD numScans,
                                   const void HUGE* bits,
                                   const BITMAPINFO far& info, WORD usage) {
  return ::SetDIBitsToDevice(
             GetHDC(), dst.left, dst.top,
             dst.Width(), dst.Height(), src.x, src.y,
             startScan, numScans,
             (void HUGE*)bits, (BITMAPINFO far*)&info, usage
         );                  // API typecast
}

inline BOOL TDC::SetDIBitsToDevice(const TRect& dst, const TPoint& src,
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

inline BOOL TDC::StretchDIBits(const TRect& dst, const TRect& src,
                               const void HUGE* bits,
                               const BITMAPINFO far& info,
                               WORD usage, DWORD rop) {
  return ::StretchDIBits(
             GetHDC(), dst.left, dst.top, dst.Width(), dst.Height(),
             src.left, src.top, src.Width(), src.Height(),
             bits, (BITMAPINFO far*)&info, usage, rop
         );
         // API typecast
}

inline BOOL TDC::StretchDIBits(const TRect& dst, const TRect& src,
                               const TDib& dib, DWORD rop) {
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

inline BOOL TDC::FloodFill(const TPoint& point, TColor C) {
  return ::FloodFill(GetHDC(), point.x, point.y, C);
}

inline BOOL TDC::ExtFloodFill(const TPoint& point, TColor color, WORD fillType) {
  return ::ExtFloodFill(GetHDC(), point.x, point.y, color, fillType);
}

inline BOOL TDC::TextOut(const TPoint& p, const char far* str, int count) {
  return ::TextOut(GetHDC(), p.x, p.y, str, count>=0 ? count : strlen(str));
}

inline BOOL TDC::ExtTextOut(const TPoint& p, WORD options, const TRect* rect,
                         const char far* str, int count, const int far* dx) {
  return ::ExtTextOut(GetHDC(), p.x, p.y, options, rect, str, count, (int far*)dx);
  // API typecast
}

inline BOOL TDC::TabbedTextOut(const TPoint& p, const char far* str, int count,
                               int numPositions, const int far* positions,
                               int tabOrigin) {
  ::TabbedTextOut(GetHDC(), p.x, p.y, str, count, numPositions,
                  (int far*)positions, tabOrigin);  // API typecast
  return TRUE;
}

inline BOOL TDC::GetTextExtent(const char far* str, int stringLen, TSize& size) {
  return ::GetTextExtentPoint(GetAttributeHDC(), str, stringLen, &size);
}

inline TSize TDC::GetTextExtent(const char far* str, int stringLen) {
  #if defined(__WIN32__)
    TSize size;
    ::GetTextExtentPoint(GetAttributeHDC(), str, stringLen, &size);
    return size;
  #else
    return ::GetTextExtent(GetAttributeHDC(), str, stringLen);
  #endif
}

inline BOOL TDC::GetTabbedTextExtent(const char far* str, int strLen,
                                     int numPositions, const int far* positions,
                                     TSize& size) const {
  size = ::GetTabbedTextExtent(GetAttributeHDC(), str, strLen, numPositions,
                               (int far*)positions);   // API Typecast
  return TRUE;
}

inline TSize TDC::GetTabbedTextExtent(const char far* str, int strLen,
                                      int numPositions, 
                                      const int far* positions) const {
  return ::GetTabbedTextExtent(GetAttributeHDC(), str, strLen, numPositions,
                               (int far*)positions);   // API Typecast
}

inline UINT TDC::GetTextAlign() const {
  return ::GetTextAlign(GetAttributeHDC());
}

inline UINT TDC::SetTextAlign(UINT flags) {
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

inline BOOL TDC::SetTextJustification(int breakExtra, int breakCount) {
  return ::SetTextJustification(GetAttributeHDC(), breakExtra, breakCount);
}

inline int TDC::GetTextFace(int count, char far* facename) const {
  return ::GetTextFace(GetAttributeHDC(), count, facename);
}

inline BOOL TDC::GetTextMetrics(TEXTMETRIC far& metrics) const {
  return ::GetTextMetrics(GetAttributeHDC(), &metrics);
}

inline DWORD TDC::GetGlyphOutline(UINT chr, UINT format, GLYPHMETRICS far& gm,
                                  DWORD buffSize, void far* buffer,
                                  const MAT2 far& mat2) {
  return ::GetGlyphOutline(GetAttributeHDC(), chr, format, &gm, buffSize,
                           buffer, (MAT2*)&mat2);
}

inline int TDC::GetKerningPairs(int pairs, KERNINGPAIR far* krnPair) {
  return ::GetKerningPairs(GetAttributeHDC(), pairs, krnPair);
}

#if defined(__WIN32__)
  inline DWORD
#else
  inline WORD
#endif
TDC::GetOutlineTextMetrics(UINT data, OUTLINETEXTMETRIC far& otm)
{
  return ::GetOutlineTextMetrics(GetAttributeHDC(), data, &otm);
}

inline BOOL TDC::GetCharWidth(UINT firstChar, UINT lastChar, int* buffer) {
  return ::GetCharWidth(GetAttributeHDC(), firstChar, lastChar, buffer);
}

inline DWORD TDC::SetMapperFlags(DWORD flag) {
  if (GetHDC() != GetAttributeHDC())
    ::SetMapperFlags(GetHDC(), flag);
  return ::SetMapperFlags(GetAttributeHDC(), flag);
}

inline BOOL TDC::GetAspectRatioFilter(TSize& size) const {
  return ::GetAspectRatioFilterEx(GetAttributeHDC(), &size);
}

inline int TDC::EnumFonts(const char far* faceName, OLDFONTENUMPROC callback, LPVOID data) const {
  return ::EnumFonts(GetAttributeHDC(), faceName, callback, LPARAM(data));
}

inline BOOL TDC::GetCharABCWidths(UINT firstChar, UINT lastChar, ABC* abc) {
  return ::GetCharABCWidths(GetAttributeHDC(), firstChar, lastChar, abc);
}

inline int TDC::EnumFontFamilies(const char far* familyName, FONTENUMPROC callback, LPVOID data) const {
  return ::EnumFontFamilies(GetAttributeHDC(), familyName, callback, LPARAM(data));
}

inline DWORD TDC::GetFontData(DWORD table, DWORD offset, void* buffer, long data) {
  return ::GetFontData(GetAttributeHDC(), table, offset, buffer, data);
}

#if defined(__WIN32__)
inline BOOL TDC::BeginPath() {
  return ::BeginPath(GetHDC());
}

inline BOOL TDC::CloseFigure() {
  return ::CloseFigure(GetHDC());
}

inline BOOL TDC::EndPath() {
  return ::EndPath(GetHDC());
}

inline BOOL TDC::FlattenPath() {
  return ::FlattenPath(GetHDC());
}

inline BOOL TDC::WidenPath() {
  return ::WidenPath(GetHDC());
}

inline BOOL TDC::FillPath() {
  return ::FillPath(GetHDC());
}

inline BOOL TDC::StrokePath() {
  return ::StrokePath(GetHDC());
}

inline BOOL TDC::StrokeAndFillPath() {
  return ::StrokeAndFillPath(GetHDC());
}

inline BOOL TDC::SelectClipPath(int mode) {
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
  return ::EndPage(GetHDC());
}

inline int TPrintDC::AbortDoc() {
  return ::AbortDoc(GetHDC());
}

inline int TPrintDC::EndDoc() {
  return ::EndDoc(GetHDC());
}

#if !defined(__WIN32__)
inline BOOL TPrintDC::QueryAbort(int rsvd) {
  return ::QueryAbort(GetHDC(), rsvd);
}
#endif

inline UINT TPrintDC::QueryEscSupport(int escapeNum) {
  return Escape(QUERYESCSUPPORT, sizeof(int), &escapeNum);
}

inline int TPrintDC::SetCopyCount(int reqestCopies, int& actualCopies) {
  return Escape(SETCOPYCOUNT, sizeof(int), &reqestCopies, &actualCopies);
}

#endif  // __OWL_DC_H
