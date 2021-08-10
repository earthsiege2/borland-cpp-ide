//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of print preview classes
//----------------------------------------------------------------------------
#if !defined(OWL_PREVIEW_H)
#define OWL_PREVIEW_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

#if !defined(OWL_DC_H)
# include <owl/dc.h>
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
    void  Paint(TDC& dc, bool, TRect& clip);

  protected:
    int        PageNum;
    TSize      PrintExtent;
    TPrintout& Printout;
    TPrintDC&  PrintDC;

    void  EvSize(uint sizeType, TSize& size);

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
    bool  SetViewportOrg(const TPoint& origin, TPoint far* oldOrg=0);
    bool  OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg=0);

    bool  SetViewportExt(const TSize& extent, TSize far* oldExtent=0);
    bool  ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                           TSize far* oldExtent=0);

    bool  SetWindowExt(const TSize& extent, TSize far* oldExtent=0);
    bool  ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom,
                         TSize far* oldExtent=0);

    //
    // Screen device point to Logical point conversions
    //
    bool  SDPtoLP(TPoint* points, int count = 1) const;
    bool  SDPtoLP(TRect& rect) const;
    bool  LPtoSDP(TPoint* points, int count = 1) const;
    bool  LPtoSDP(TRect& rect) const;

  protected:
    HFONT     PrnFont;              // Handle of current font in the printer dc
    TPrintDC& PrnDC;                // DC for the printer we are previewing
    TFont*    CurrentPreviewFont;   // font object in PrnDC used during preview

    HDC   GetAttributeHDC() const;
};

inline bool
TPrintPreviewDC::SDPtoLP(TPoint* points, int count) const {
  return ::DPtoLP(HDC(Handle), points, count);
}

inline bool
TPrintPreviewDC::SDPtoLP(TRect& rect) const {
  return SDPtoLP(rect, 2);
}

inline bool
TPrintPreviewDC::LPtoSDP(TPoint* points, int count) const {
  return ::LPtoDP(HDC(Handle), points, count);
}

inline bool
TPrintPreviewDC::LPtoSDP(TRect& rect) const {
  return LPtoSDP(rect, 2);
}

#endif  // OWL_PREVIEW_H
