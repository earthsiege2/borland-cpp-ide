//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of print preview classes
//----------------------------------------------------------------------------
#if !defined(OWL_PREVIEW_H)
#define OWL_PREVIEW_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TPrintout;
class _OWLCLASS TPrinter;

//
// class TPreviewPage
// ~~~~~ ~~~~~~~~~~~~
// TPreviewPage encapsulates a window which displays print-preview data.
// It provides access to the basic information necessary to paint 
// print-preview data: i.e. the printer's DC. 
//
class _OWLCLASS TPreviewPage : public TWindow {
  public:
    TPreviewPage(TWindow*   parent,
                 TPrintout& printout,
                 TPrintDC&  prndc,
                 TSize&     printExtent,
                 int        pagenum = 1);

    void         SetPageNumber(int newNum);
    int          GetPageNumber() const;

    // Overriden TWindow virtual
    //
    void         Paint(TDC& dc, bool, TRect& clip);

  protected:
    void         EvSize(uint sizeType, TSize& size);

  protected_data:
    int          PageNum;         // Page currently being previewed
    TSize        PrintExtent;     // Size of printer device (in pixels)
    TPrintout&   Printout;        // Printout which sends the output
    TPrintDC&    PrintDC;         // Device context of the printer

  DECLARE_RESPONSE_TABLE(TPreviewPage);
  DECLARE_CASTABLE;
};

//
// class TPreviewDCBase
// ~~~~~ ~~~~~~~~~~~~~~
// TPreviewDCBase is the base class encapsulating a 'dual' device 
// context - i.e. a DC which is tied to the screen but responds as if it
// were tied to a printer or some other device. A dual DC is schizophrenic
// and maintains two personalities: Dr. Screen and Mr. Printer.
//
// When querried about it's attributes, a 'dual' DC acts as a printer DC.
// When requested to modify some attributes, a 'dual' DC acts as both a
// printer DC and a screen DC.
// When sent output, a 'dual' DC acts as a screen DC.
//
// NOTE: The TPreviewDCBase provides the basics of a 'dual' device context
//       object. However, this base object does not attempt to map the
//       screen DC to correspond to the attributes of the printer's device
//       context.
//
class _OWLCLASS TPreviewDCBase : public TPrintDC {
  public:
    TPreviewDCBase(TDC&         screen,
                   TPrintDC&    printdc);

    // Overriden to return printer's HDC
    //
    HDC           GetAttributeHDC() const;

  protected:

    // DC of 'real' device (aka TargetDevice) whose output we're previewing
    //
    TPrintDC&     PrnDC;                
};


//
// class TPrintPreviewDC
// ~~~~~ ~~~~~~~~~~~~~~~~
// TPrintPreviewDC is an enhanced 'TPreviewDCBase' where the attributes
// of the screen DC are modified to corresponds [fairly] to those of the
// printer. 
// For example, the screen DC's extent are modified to match those of the
// printers. Similarly, the default font of the screen DC is computed to
// correspond closely to the default font of the printer.
//
class _OWLCLASS TPrintPreviewDC : public TPreviewDCBase {
  public:
    TPrintPreviewDC(TDC&         screen,
                    TPrintDC&    printdc,
                    const TRect& client,
                    const TRect& clip);
   ~TPrintPreviewDC();

    // Override virtual TDC select & restore functions
    //
    void  SelectObject(const TFont& newFont);
    void  SelectStockObject(int index);
    void  RestoreFont();
    int   GetDeviceCaps(int index) const;

    // Dual DC synchronizing functions
    //
    virtual void SyncFont();
    virtual void ReScale();
    virtual void ReOrg();

    // Override virtual TDC color matching functions
    //
    TColor  SetBkColor(const TColor& color);
    TColor  SetTextColor(const TColor& color);

    // Override virtual TDC viewport & window mapping functions
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

    // Screen device point to Logical point conversions
    //
    bool  SDPtoLP(TPoint* points, int count = 1) const;
    bool  SDPtoLP(TRect& rect) const;
    bool  LPtoSDP(TPoint* points, int count = 1) const;
    bool  LPtoSDP(TRect& rect) const;

  protected_data:
    HFONT     PrnFont;              // Handle of current font in the printer dc
    TFont*    CurrentPreviewFont;   // Font object in PrnDC used during preview
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementation
//

//
// Converts device coordinates (in the 'points' parameter) into logical
// coordinates using the screen device context.
//
inline bool
TPrintPreviewDC::SDPtoLP(TPoint* points, int count) const {
#if   defined(BI_PLAT_WIN32)
  PRECONDITION(::GetObjectType(HDC(Handle)) != 0);
#elif defined(BI_PLAT_WIN16)
  PRECONDITION(::IsGDIObject(HDC(Handle)) != 0);
#endif
  return ::DPtoLP(HDC(Handle), points, count);
}

//
// Converts the device coordinates of a rectangle into logical coordinates
// using the screen device context.
//
inline bool
TPrintPreviewDC::SDPtoLP(TRect& rect) const {
  return SDPtoLP(rect, 2);
}

//
// Converts logical coordinates (in the 'points' parameter) into device
// coordinates using the screen device context.
//
inline bool
TPrintPreviewDC::LPtoSDP(TPoint* points, int count) const {
#if   defined(BI_PLAT_WIN32)
  PRECONDITION(::GetObjectType(HDC(Handle)) != 0);
#elif defined(BI_PLAT_WIN16)
  PRECONDITION(::IsGDIObject(HDC(Handle)) != 0);
#endif
  return ::LPtoDP(HDC(Handle), points, count);
}

//
// Converts the logical coordinates of a rectangle into device coordinates
// using the screen device context.
inline bool
TPrintPreviewDC::LPtoSDP(TRect& rect) const {
  return LPtoSDP(rect, 2);
}

//
// Retrieves the index of the page currently being previewed [painted]
// on the preview page window.
//
inline int
TPreviewPage::GetPageNumber() const {
  return PageNum;
}

#endif  // OWL_PREVIEW_H
