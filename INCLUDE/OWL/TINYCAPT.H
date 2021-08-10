//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\tinycapt.h
//----------------------------------------------------------------------------
#if !defined(__OWL_TINYCAPT_H)
#define __OWL_TINYCAPT_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif
class _OWLCLASS TFont;

//
//  class TTinyCaption
//  ----- ------------
//
class _OWLCLASS TTinyCaption : public virtual TWindow {
  protected:
    TTinyCaption();
   ~TTinyCaption();

    //
    // Pass closeBox=TRUE to replace SystemMenu box with a box that will 
    // close window when clicked
    // Used for floating palettes, etc.
    //
    void        EnableTinyCaption(int ch=45, BOOL closeBox=FALSE);

    //
    // Controller class must handle events that call these mixin handlers
    //
    TEventStatus DoNCHitTest(TPoint& screenPt, UINT& evRes);
    TEventStatus DoNCPaint();
    TEventStatus DoNCCalcSize(BOOL calcValidRects, 
                              NCCALCSIZE_PARAMS far& calcSize, UINT& evRes);
    TEventStatus DoNCLButtonDown(UINT hitTest, TPoint& screenPt);
    TEventStatus DoMouseMove(UINT hitTest, TPoint& screenPt);
    TEventStatus DoLButtonUp(UINT hitTest, TPoint& screenPt);
    TEventStatus DoNCActivate(BOOL active, BOOL& evRes);
    TEventStatus DoCommand(UINT id, HWND hWndCtl, UINT notifyCode, LRESULT& evRes);
    TEventStatus DoSysCommand(UINT cmdType, TPoint& p);

  protected:
    //
    // Cache system metrics 
    //
    TSize    Border; // Thin frame border size for dividers
    TSize    Frame;  // Actual Left and Right, Top and Bottom frame size

    BOOL     CloseBox;      // True for special close box
    BOOL     TCEnabled;
    int      CaptionHeight;
    TFont*   CaptionFont;   // Tiny font for caption bar
    UINT     DownHit;       // Mouse down hit test result
    BOOL     IsPressed;     // Is a button currently pressed
    BOOL     WaitingForSysCmd;

    void        PaintButton(TDC& dc, TRect& boxRect, BOOL pressed);
    void        PaintCloseBox(TDC& dc, TRect& boxRect, BOOL pressed);
    void        PaintSysBox(TDC& dc, TRect& boxRect, BOOL pressed);
    void        PaintMinBox(TDC& dc, TRect& boxRect, BOOL pressed);
    void        PaintMaxBox(TDC& dc, TRect& boxRect, BOOL pressed);
    void        PaintCaption(BOOL active);
    void        DoSysMenu();

    TRect       GetCaptionRect();  // Get caption area for hit test or paint
    TRect       GetSysBoxRect();   // Same for close box
    TRect       GetMinBoxRect();
    TRect       GetMaxBoxRect();

  protected:
    UINT        EvNCHitTest(TPoint& screenPt);
    void        EvNCPaint();
    UINT        EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& calcSize);
    void        EvNCLButtonDown(UINT hitTest, TPoint& screenPt);
    void        EvMouseMove(UINT hitTest, TPoint& screenPt);
    void        EvLButtonUp(UINT hitTest, TPoint& screenPt);
    BOOL        EvNCActivate(BOOL active);
    LRESULT     EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);
    void        EvSysCommand(UINT cmdType, TPoint& p);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TTinyCaption(const TTinyCaption&);
    TTinyCaption& operator =(const TTinyCaption&);

  DECLARE_RESPONSE_TABLE(TTinyCaption);
  DECLARE_STREAMABLE(_OWLCLASS, TTinyCaption, 1);
};

#endif  // __OWL_TINYCAPT_H
