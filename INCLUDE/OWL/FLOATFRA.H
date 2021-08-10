//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Class TFloatingFrame.
//----------------------------------------------------------------------------
#if !defined(OWL_FLOATFRA_H)
#define OWL_FLOATFRA_H

#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_TINYCAPT_H)
# include <owl/tinycapt.h>
#endif

//
//  class TFloatingFrame
//  ----- --------------
//
//  implements a floating frame (owned popup frame w/ tiny caption)
//
//  if there is a client window then the floating frame shrinks to fit
//  the client window leaving room for margins on the left, top, right, and
//  bottom
//
//  if there is a client window then the floating palette expects the window
//  to paint its own background (and hence does nothing in response to the
//  WM_ERASEBKGND). if there is no client window then the floating palette
//  erases the client area background using COLOR_BTNFACE
//
class _OWLCLASS TFloatingFrame : public TFrameWindow, public TTinyCaption {
  public:
    TFloatingFrame(TWindow*        parent,
                   char*           title = 0,
                   TWindow*        clientWnd = 0,
                   bool            shrinkToClient = false,
                   int             captionHeight = DefaultCaptionHeight,
                   bool            popupPalette = false,
                   TModule*        module = 0);
    
    void    SetMargins(const TSize& margin) {Margin = margin;}

    enum {DefaultCaptionHeight = 58};

  protected:
    TEventStatus  DoNCHitTest(TPoint& screenPt, uint& evRes);

    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void    EvSysCommand(uint cmdType, TPoint& p);
    uint    EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& calcSize);
    void    EvNCPaint();
    uint    EvNCHitTest(TPoint& screenPt);

  private:
    TSize   Margin;  // left and right, top and bottom
    bool    FloatingPaletteEnabled;

  DECLARE_RESPONSE_TABLE(TFloatingFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TFloatingFrame, 1);
};

#endif  // OWL_FLOATFRA_H
