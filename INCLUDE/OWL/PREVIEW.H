//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\preview.h
//   Definition of print preview classes
//----------------------------------------------------------------------------
#if !defined(__OWL_PREVIEW_H)
#define __OWL_PREVIEW_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif

#if !defined(__OWL_DC_H)
  #include <owl\dc.h>
#endif

class _OWLCLASS TPrintout;
class _OWLCLASS TPrinter;

//
// class TPreviewPage
// ----- ------------
//
class _OWLCLASS TPreviewPage : public TWindow {
  public:
    TPreviewPage(TWindow*   parent,
                 TPrintout& printout,
                 TPrintDC&  prndc,
                 TSize&     printExtent,
                 int        pagenum = 1);

    void  SetPageNumber(int newNum) {PageNum = newNum; if (HWindow) Invalidate();}
    void  Paint(TDC& dc, BOOL, TRect& clip);

  protected:
    int        PageNum;
    TSize      PrintExtent;
    TPrintout& Printout;
    TPrintDC&  PrintDC;

    void  EvSize(UINT sizeType, TSize& size);

  DECLARE_RESPONSE_TABLE(TPreviewPage);
  DECLARE_CASTABLE;
};

//
// class TPrintPreviewDC
// ----- ---------------
//
class _OWLCLASS TPrintPreviewDC : public TPrintDC {
  public:
    TPrintPreviewDC(TDC&         screen,
                    TPrintDC&    printdc,
                    const TRect& client,
                    const TRect& clip);
   ~TPrintPreviewDC();

    //
    // override virtual TDC select & restore functions
    //
    void  SelectObject(const TFont& newFont);
    void  SelectStockObject(int index);
    void  RestoreFont();
    int   GetDeviceCaps(int index) const;

    //
    // Dual DC synchronizing functions
    //
    virtual void SyncFont();
    virtual void ReScale();
    virtual void ReOrg();

    //
    // override virtual TDC color matching functions
    //
    TColor  SetBkColor(TColor color);
    TColor  SetTextColor(TColor color);

    //
    // override virtual TDC viewport & window mapping functions
    //
    int   SetMapMode(int mode);
    BOOL  SetViewportOrg(const TPoint& origin, TPoint far* oldOrg=0);
    BOOL  OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg=0);

    BOOL  SetViewportExt(const TSize& extent, TSize far* oldExtent=0);
    BOOL  ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                           TSize far* oldExtent=0);

    BOOL  SetWindowExt(const TSize& extent, TSize far* oldExtent=0);
    BOOL  ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom,
                         TSize far* oldExtent=0);

    //
    // Screen device point to Logical point conversions
    //
    BOOL  SDPtoLP(TPoint* points, int count = 1) const;
    BOOL  SDPtoLP(TRect& rect) const;
    BOOL  LPtoSDP(TPoint* points, int count = 1) const;
    BOOL  LPtoSDP(TRect& rect) const;

  protected:
    HFONT     PrnFont;              // Handle of current font in the printer dc
    TPrintDC& PrnDC;                // DC for the printer we are previewing
    TFont*    CurrentPreviewFont;   // font object in PrnDC used during preview

    HDC   GetAttributeHDC() const;
};

inline BOOL
TPrintPreviewDC::SDPtoLP(TPoint* points, int count) const {
  return ::DPtoLP(HDC(Handle), points, count);
}

inline BOOL
TPrintPreviewDC::SDPtoLP(TRect& rect) const {
  return SDPtoLP(rect, 2);
}

inline BOOL
TPrintPreviewDC::LPtoSDP(TPoint* points, int count) const {
  return ::LPtoDP(HDC(Handle), points, count);
}

inline BOOL
TPrintPreviewDC::LPtoSDP(TRect& rect) const {
  return LPtoSDP(rect, 2);
}
#endif  // __OWL_PREVIEW_H
