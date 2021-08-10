//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\floatfra.h
//   Class TFloatingFrame.
//----------------------------------------------------------------------------
#if !defined(__OWL_FLOATFRA_H)
#define __OWL_FLOATFRA_H

#if !defined(__OWL_FRAMEWIN_H)
  #include <owl\framewin.h>
#endif
#if !defined(__OWL_TINYCAPT_H)
  #include <owl\tinycapt.h>
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
                   BOOL            shrinkToClient = FALSE,
                   int             captionHeight = DefaultCaptionHeight,
                   BOOL            popupPalette = FALSE,
                   TModule*        module = 0);
    
    void    SetMargins(const TSize& margin) {Margin = margin;}

    enum {DefaultCaptionHeight = 48};

  private:
    LRESULT EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);
    void    EvSysCommand(UINT cmdType, TPoint& p);
    UINT    EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& calcSize);
    void    EvNCPaint();

    TSize   Margin;  // left and right, top and bottom
    BOOL    FloatingPaletteEnabled;

  DECLARE_RESPONSE_TABLE(TFloatingFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TFloatingFrame, 1);
};

#endif  // __OWL_FLOATFRA_H
