//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\tinycapt.cpp
//   Defines type TTinyCaption
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\tinycapt.h>
#include <owl\gdiobjec.h>

#if !defined(SECTION) || SECTION == 1

//
// We only want to search this mixin for events, so don't include any base
// classes in Find()
//
DEFINE_RESPONSE_TABLE(TTinyCaption)
  EV_WM_NCHITTEST,
  EV_WM_NCPAINT,
  EV_WM_NCCALCSIZE,
  EV_WM_NCLBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_WM_NCACTIVATE,
  EV_WM_SYSCOMMAND,
END_RESPONSE_TABLE;

//
// Rely on TWindow's default ctor since we will always be mixed-in and another
// window will perform Init()
//
TTinyCaption::TTinyCaption()
{
  TCEnabled = FALSE;
  CaptionFont = 0;
}

TTinyCaption::~TTinyCaption()
{
  delete CaptionFont;
}

void
TTinyCaption::EnableTinyCaption(int captionHeight, BOOL closeBox)
{
  Border.cx = GetSystemMetrics(SM_CXBORDER);
  Border.cy = GetSystemMetrics(SM_CYBORDER);

  //
  // Get width of window borders, these will vary with type of window
  //
  long style = Attr.Style;
  if (style & WS_THICKFRAME) {
    Frame.cx = GetSystemMetrics(SM_CXFRAME);
    Frame.cy = GetSystemMetrics(SM_CYFRAME);

  } else if (style & WS_DLGFRAME) {
    Frame.cx = GetSystemMetrics(SM_CXDLGFRAME);
    Frame.cy = GetSystemMetrics(SM_CYDLGFRAME);

  } else if (style & WS_BORDER) {
    Frame = Border;

  } else {
    Frame.cx = 0;
    Frame.cy = 0;
  }

  CaptionHeight = ((Border.cy+GetSystemMetrics(SM_CYCAPTION)) * captionHeight)
                    / 100;
  CloseBox = closeBox;

  delete CaptionFont;
  CaptionFont = new TFont(
    "Small Fonts",              // facename
    -(CaptionHeight-Border.cy), // pixel height,
    0, 0, 0, FW_NORMAL,         // width,esc,orientation,weight
    VARIABLE_PITCH | FF_SWISS,  // Pitch and Family
    FALSE, FALSE, FALSE,        // Italic, Underline, Strikeout
    ANSI_CHARSET,               // Charset
    OUT_CHARACTER_PRECIS,       // Output precision
    CLIP_DEFAULT_PRECIS,        // Clip precision
    PROOF_QUALITY               // Quality
  );

  TCEnabled = TRUE;
}

//
// Return where in the non client area we are.  We only handle caption
// bar area
//
UINT
TTinyCaption::EvNCHitTest(TPoint& screenPt)
{
  UINT er;
  if (DoNCHitTest(screenPt, er) == esComplete)
    return er;
  return TWindow::EvNCHitTest(screenPt);
}

TEventStatus
TTinyCaption::DoNCHitTest(TPoint& screenPt, UINT& evRes)
{
  if (!TCEnabled)
    return esPartial;

  //
  // Check style bits to see what to paint
  //
  long style = GetWindowLong(GWL_STYLE);
  BOOL hasCaption, hasSysMenu, hasMaximize, hasMinimize;
  hasCaption = hasSysMenu = hasMaximize = hasMinimize = FALSE;
  if (style & WS_CAPTION) {
    hasCaption = TRUE;
    if (style & WS_SYSMENU)
      hasSysMenu = TRUE;
    if (style & WS_MAXIMIZEBOX)
      hasMaximize = TRUE;
    if (style & WS_MINIMIZEBOX)
      hasMinimize = TRUE;
  }

  //
  // Convert to window coordinates
  //
  TPoint winPt = screenPt - GetWindowRect().TopLeft();

  if ((hasSysMenu || CloseBox) && GetSysBoxRect().Contains(winPt)) {
    evRes = HTSYSMENU;
    return esComplete;

  } else if (hasMinimize && GetMinBoxRect().Contains(winPt)) {
    evRes = HTMINBUTTON;
    return esComplete;

  } else if (hasMaximize && GetMaxBoxRect().Contains(winPt)) {
    evRes = HTMAXBUTTON;
    return esComplete;

  //
  // CaptionRect includes buttons so make sure it's last checked
  // Should modify this one to allow clicking in left, top, right thin 
  // borders of caption
  //
  } else if (hasCaption && GetCaptionRect().Contains(winPt)) {
    evRes = HTCAPTION;
    return esComplete;

  } else {
    evRes = 0;
    return esPartial;
  }
}

//
// We only need to paint the caption. Someone else will paint the borders
//
void
TTinyCaption::EvNCPaint()
{
  TWindow::EvNCPaint();  // Default border painting
  DoNCPaint();           // Then our special caption painting
}

TEventStatus
TTinyCaption::DoNCPaint()
{
  if (!TCEnabled || IsIconic())
    return esPartial;  // We don't do anything special for an Icon

  //
  // If we have focus or our children have focus, then we're active
  // Note: We can't use GetFocus here because when we're being restored
  // from an icon, we're active, but don't yet have focus!
  //
  HWND focus = GetFocus();
  PaintCaption(GetActiveWindow() == HWindow || focus == HWindow || IsChild(focus));
  return esPartial;       // Caller must call function to paint borders
}

//
// Returns the size of our client area
//
UINT
TTinyCaption::EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& calcSize)
{
  UINT er;
  if (DoNCCalcSize(calcValidRects, calcSize, er) == esComplete)
    return er;
  return TWindow::EvNCCalcSize(calcValidRects, calcSize);
}

//
// Return the size of our client area, leaving room for caption bar
//
TEventStatus
TTinyCaption::DoNCCalcSize(BOOL /*calcValidRects*/,
                           NCCALCSIZE_PARAMS far& calcSize, UINT& evRes)
{
  if (!TCEnabled || IsIconic())
    return esPartial;

  TRect captRect = GetCaptionRect();

  calcSize.rgrc[0].left +=   Frame.cx;
  calcSize.rgrc[0].top +=    Frame.cy + captRect.Height();
  calcSize.rgrc[0].right -=  Frame.cx;
  calcSize.rgrc[0].bottom -= Frame.cy;

  evRes = 0;
  return esComplete;
}

void
TTinyCaption::EvNCLButtonDown(UINT hitTest, TPoint& screenPt)
{
  //
  // Display system menu, invert min/max icons (not), etc
  //
  if (DoNCLButtonDown(hitTest,screenPt) == esPartial)
    TWindow::EvNCLButtonDown(hitTest, screenPt);
}

TEventStatus
TTinyCaption::DoNCLButtonDown(UINT hitTest, TPoint& /*screenPt*/)
{
  if (!TCEnabled)
    return esPartial;

  switch (hitTest) {
    case HTSYSMENU:
      DownHit = HTSYSMENU;
      if (CloseBox) {
        IsPressed = TRUE;
        SetCapture();
        PaintCloseBox(TWindowDC(*this), GetSysBoxRect(), IsPressed);

      } else {
        TWindowDC(*this).PatBlt(GetSysBoxRect(), PATINVERT);
        //
        // Display sys menu on button down
        // Need to lock sys menu until user clicks outside
        //

        //
        // Set flag to indicate we're expecting a sys command
        //
        WaitingForSysCmd = TRUE;
        DoSysMenu();

        //
        // If we didn't execute a command, user released btn outside of menu
        // If it was released in sys menu box, then redisplay menu as if it
        // were brought up with a keystroke
        //
        if (WaitingForSysCmd) {
          UINT hitTest;
          TPoint pt;
          GetCursorPos(pt);
          DoNCHitTest(pt, hitTest);
          if (hitTest == HTSYSMENU) {
            //
            // Make this look like menu was brought up with LButton UP or
            // Alt-Space so that it stays on screen after mouse is released
            //
            BYTE rgbKeyState[256];
            GetKeyboardState(rgbKeyState);
            rgbKeyState[VK_LBUTTON] = 0;      // 0==UP, 1==DOWN
            SetKeyboardState(rgbKeyState);
            DoSysMenu();  // TrackPopupMenu will now have alt-space behavior
          }
        }
        if (HWindow)
          TWindowDC(*this).PatBlt(GetSysBoxRect(), PATINVERT);
      }
      return esComplete;

    case HTMINBUTTON:
      DownHit = HTMINBUTTON;
      IsPressed = TRUE;
      SetCapture();
      PaintMinBox(TWindowDC(*this), GetMinBoxRect(), IsPressed);
      return esComplete;

    case HTMAXBUTTON:
      DownHit = HTMAXBUTTON;
      IsPressed = TRUE;
      SetCapture();
      PaintMaxBox(TWindowDC(*this), GetMaxBoxRect(), IsPressed);
      return esComplete;
  }
  DownHit = HTNOWHERE;
  return esPartial;
}

void
TTinyCaption::EvMouseMove(UINT modKeys, TPoint& pt)
{
  if (DoMouseMove(modKeys, pt) == esPartial)
    TWindow::EvMouseMove(modKeys, pt);
}

TEventStatus
TTinyCaption::DoMouseMove(UINT /*modKeys*/, TPoint& pt)
{
  if (TCEnabled && DownHit != HTNOWHERE) {
    UINT   hitTest;
    TPoint screenPt = pt;
    ClientToScreen(screenPt);    // Cvt to screen coord
    DoNCHitTest(screenPt, hitTest);
    BOOL isNowPressed = hitTest == DownHit;

    if (isNowPressed != IsPressed) {
      IsPressed = isNowPressed;
      switch (DownHit) {
        case HTSYSMENU:
          if (CloseBox)
            PaintCloseBox(TWindowDC(*this), GetSysBoxRect(), IsPressed);
          return esComplete;
        case HTMINBUTTON:
          PaintMinBox(TWindowDC(*this), GetMinBoxRect(), IsPressed);
          return esComplete;
        case HTMAXBUTTON:
          PaintMaxBox(TWindowDC(*this), GetMaxBoxRect(), IsPressed);
          return esComplete;
      }
    }
  }
  return esPartial;
}

void
TTinyCaption::EvLButtonUp(UINT modKeys, TPoint& pt)
{
  //
  // If we're still in area where buton went down, then do it
  //
  if (DoLButtonUp(modKeys, pt) == esPartial)
    TWindow::EvLButtonUp(modKeys, pt);
}

TEventStatus
TTinyCaption::DoLButtonUp(UINT modKeys, TPoint& pt)
{
  if (TCEnabled && DownHit != HTNOWHERE) {
    ReleaseCapture();
    DoMouseMove(modKeys, pt);

    UINT   hitTest;
    TPoint screenPt = pt;
    ClientToScreen(screenPt);    // Cvt to screen coord
    DoNCHitTest(screenPt, hitTest);

    if (hitTest == DownHit) {
      DownHit = HTNOWHERE;
      switch (hitTest) {
        case HTSYSMENU:
          if (CloseBox)
            PostMessage(WM_CLOSE);
          return esComplete;

        //
        // We have to handle these buttons also to prevent defproc from painting
        // the standard big min/max buttons when left mouse button is pressed
        //
        case HTMINBUTTON:
          HandleMessage(WM_SYSCOMMAND, SC_MINIMIZE);
          return esComplete;

        case HTMAXBUTTON:
          HandleMessage(WM_SYSCOMMAND, IsZoomed() ? SC_RESTORE : SC_MAXIMIZE);
          return esComplete;
      }
    }
    DownHit = HTNOWHERE;
  }
  return esPartial;
}

BOOL
TTinyCaption::EvNCActivate(BOOL active)
{
  BOOL er;
  if (DoNCActivate(active, er) == esComplete)
    return er;
  return TWindow::EvNCActivate(active);
}

TEventStatus
TTinyCaption::DoNCActivate(BOOL active, BOOL& evRes)
{
  if (!TCEnabled || IsIconic())
    return esPartial;  // Let default do it's thing

  PaintCaption(active);
  evRes = !active;
  return esComplete;
}


LRESULT
TTinyCaption::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  LRESULT er;
  if (DoCommand(id, hWndCtl, notifyCode, er) == esComplete)
    return er;
  return TWindow::EvCommand(id, hWndCtl, notifyCode);
}

TEventStatus
TTinyCaption::DoCommand(UINT id, HWND /*hWndCtl*/, UINT notifyCode, LRESULT& evRes)
{
  //
  // We're displaying system menu using TrackPopup...
  // This will send us WM_COMMAND messages instead of WM_SYSCOMMAND msgs
  // If we get a system menu command then transform it into a WM_SYSCOMMAND
  //
  if (!TCEnabled)
    return esPartial;

  if (id >= 0xF000) {
    WaitingForSysCmd = FALSE;  // For LButtonDown use
    evRes = HandleMessage(WM_SYSCOMMAND, id, notifyCode);
    return esComplete;

  } else {
    evRes = 0;
    return esPartial;
  }
}

void
TTinyCaption::EvSysCommand(UINT cmdType, TPoint& p)
{
  if (DoSysCommand(cmdType,p) == esPartial)
    TWindow::EvSysCommand(cmdType,p);
}

TEventStatus
TTinyCaption::DoSysCommand(UINT cmdType, TPoint&)
{
  if (!TCEnabled)
    return esPartial;

  //
  // Make sure that ALT-SPACE brings up our sys menu at the right coord
  //
  if (cmdType == SC_KEYMENU) {
    //
    // If we're iconized, windows sends us the SC_KEYMENU message when the
    // user clicks on the icon.  We want the menu to be displayed in the
    // default position
    //
    if (!IsIconic()) {
      DoSysMenu();
      return esComplete;
    }
  }
  return esPartial;
}

void
TTinyCaption::PaintButton(TDC& dc, TRect& r, BOOL pressed)
{
//  dc.OWLFastWindowFrame(TBrush(GetSysColor(COLOR_WINDOWFRAME)), r, 1, 1);
  dc.FrameRect(r, TBrush(TColor::Black));

  r.Inflate(-1,-1);
  dc.TextRect(r, TColor::LtGray);
  if (r.Width() > 4 && r.Height() > 4) {
    if (pressed) {
      dc.TextRect(r.left, r.top, r.right, r.top+1, TColor::Gray);
      dc.TextRect(r.left, r.top+1, r.left+1, r.bottom, TColor::Gray);
    } else {
      dc.TextRect(r.left, r.top, r.right-1, r.top+1, TColor::White);
      dc.TextRect(r.left, r.top+1, r.left+1, r.bottom-1, TColor::White);
      dc.TextRect(r.right-1, r.top+1, r.right, r.bottom, TColor::Gray);
      dc.TextRect(r.left+1, r.bottom-1, r.right-1, r.bottom, TColor::Gray);
    }
  }
}

void
TTinyCaption::PaintCloseBox(TDC& dc, TRect& boxRect, BOOL pressed)
{
  //
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  //
  // Do something different to differentiate from standard system menu--
  // draw a recessed black box
  //
  TRect glyphRect(0, 0, boxRect.Width()/2+1, boxRect.Height()/2+1);
  glyphRect += TPoint(boxRect.left + glyphRect.right/2,
                      boxRect.top + glyphRect.bottom/2);

  dc.TextRect(glyphRect, TColor::Gray);
  glyphRect.Offset(1,1);
  dc.TextRect(glyphRect, TColor::White);
  glyphRect.BottomRight().Offset(-1,-1);
  dc.TextRect(glyphRect, TColor::Black);
}

void
TTinyCaption::PaintSysBox(TDC& dc, TRect& boxRect, BOOL /*pressed*/)
{
  //
  // Dont paint over the left & top borders
  //
  boxRect.left++;
  boxRect.top++;

  //
  // Fill the box with light gray
  //
  dc.TextRect(boxRect, TColor::LtGray);

  //
  // Draw the ventilator (sysmenu) box, with shadow
  // 
  TPoint begPt = boxRect.TopLeft().OffsetBy(2, (boxRect.Height()-3)/2);
  TRect ventRect(begPt, TSize(boxRect.Width()-5, 3));

  // Draw shadow down and right 1
  dc.TextRect(ventRect.left+1, ventRect.top+1,
              ventRect.right+1, ventRect.bottom+1, TColor::Gray);

  // Draw ventilator rectangle
  dc.FrameRect(ventRect, TBrush(TColor::Black));

  // Draw white interior of ventilator
  dc.TextRect(ventRect.left+1, ventRect.top+1,
              ventRect.right-1, ventRect.top+2, TColor::White);

  dc.TextRect(boxRect.right, boxRect.top,
              boxRect.right+1, boxRect.bottom, TColor::Black);
}

void
TTinyCaption::PaintMinBox(TDC& dc, TRect& boxRect, BOOL pressed)
{
  //
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  int bh = boxRect.Height();
  int bw = boxRect.Width();

  TPoint begPt = boxRect.TopLeft().OffsetBy((bw+1)/4, (bh+2)/3);
  TPoint endPt = begPt.OffsetBy((bw+1)/2,0);
  for (int i = 0; begPt.x < endPt.x; i++) {
    dc.MoveTo(begPt);
    dc.LineTo(endPt);
    begPt.Offset(1,1);
    endPt.Offset(-1,1);
  }
}

void
TTinyCaption::PaintMaxBox(TDC& dc, TRect& boxRect, BOOL pressed)
{
  //
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  //
  // Down triangle
  //
  int bh = boxRect.Height();
  int bw = boxRect.Width();

  if (IsZoomed()) {
    TPoint begPt = boxRect.BottomLeft().OffsetBy((bw+1)/4, -bh*3/8);
    TPoint endPt = begPt.OffsetBy((bw+1)/2, 0);
    for (int i = 0; begPt.x < endPt.x; i++) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset(1,1);
      endPt.Offset(-1,1);
    }
  }

  //
  // Up triangle
  //
  {
    TPoint begPt = boxRect.TopLeft().OffsetBy((bw+1)/4, IsZoomed() ? bh*3/8 : bh*2/3);
    TPoint endPt = begPt.OffsetBy((bw+1)/2, 0);
    for (int i = 0; begPt.x < endPt.x; i++) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset(1, -1);
      endPt.Offset(-1, -1);
    }
  }
}

void
TTinyCaption::PaintCaption(BOOL active)
{
  int xOrg;

  long style = GetWindowLong(GWL_STYLE);
  if (!(style & WS_CAPTION))
    return;    // Leave now if there is no caption, it's all we care about

  //
  // Paint caption background and caption text if any.
  //
  TWindowDC dc(*this);
  TRect captRect = GetCaptionRect();

  HBRUSH captionBrush = CreateSolidBrush(GetSysColor(active ?
                                                     COLOR_ACTIVECAPTION :
                                                     COLOR_INACTIVECAPTION));
  dc.SetTextColor(GetSysColor(active ? COLOR_CAPTIONTEXT :
                                       COLOR_INACTIVECAPTIONTEXT));
  dc.FillRect(captRect, captionBrush);
  DeleteObject(captionBrush);

  dc.SelectObject(*CaptionFont);
  dc.SetBkMode(TRANSPARENT);
  TSize textSize = dc.GetTextExtent(Title, lstrlen(Title));

  //
  // Calc x coord for text, so that text is centered between caption buttons
  //
  xOrg = captRect.right - captRect.left;
  if (style & WS_MINIMIZEBOX)
    xOrg -= GetMinBoxRect().Width();

  if (style & WS_MAXIMIZEBOX)
    xOrg -= GetMaxBoxRect().Width();

  if ((style & WS_SYSMENU) || CloseBox)
    xOrg -= GetSysBoxRect().Width();

  xOrg -= textSize.cx;
  if (xOrg<0)
    xOrg = 0;
  else
    xOrg = xOrg/2;
  
  xOrg += captRect.left;

  if ((style & WS_SYSMENU) || CloseBox)
    xOrg += GetSysBoxRect().Width();

  dc.ExtTextOut(xOrg, captRect.top,
    ETO_CLIPPED,
    &captRect,
    Title,
    lstrlen(Title)
  );
  dc.RestoreFont();

  //
  // Paint widgets: sysmenu or close button, minimize button, maximize button
  //
  dc.SelectStockObject(BLACK_PEN);

  //
  // Paint system menu or close button
  //

  if (CloseBox)
    PaintCloseBox(dc, GetSysBoxRect(), FALSE);
  else if (style & WS_SYSMENU)
    PaintSysBox(dc, GetSysBoxRect(), FALSE);

  //
  // Paint minimize button
  //
  if (style & WS_MINIMIZEBOX)
    PaintMinBox(dc, GetMinBoxRect(), FALSE);

  //
  // Paint maximize button
  //
  if (style & WS_MAXIMIZEBOX)
    PaintMaxBox(dc, GetMaxBoxRect(), FALSE);

  //
  // Draw black line under caption
  //
  dc.MoveTo(captRect.left, captRect.bottom-1);
  dc.LineTo(captRect.right, captRect.bottom-1);
}

//
//  NOTE: GetCaptionRect and GetSysBoxRect must be kept in sync!
//
TRect
TTinyCaption::GetCaptionRect()
{
  //
  // Get caption rect converted to window relative coordinates
  //
  TRect captRect = GetWindowRect();
  captRect -= captRect.TopLeft();

  captRect.left +=  Frame.cx;
  captRect.top +=   Frame.cy;
  captRect.right -= Frame.cx;
  captRect.bottom = captRect.top + CaptionHeight;

  return captRect;
}

//
// Returns a rectangle for sysmenu, minimize, or maximize rectangle
//
TRect
TTinyCaption::GetSysBoxRect()
{
  TRect boxRect = GetCaptionRect();
  boxRect.right = boxRect.left + CaptionHeight;
  boxRect.left -= 1;
  boxRect.top -= 1;
  return boxRect;
}

TRect
TTinyCaption::GetMinBoxRect()
{
  //
  // Far right on caption if no max box, else next to max box
  //
  TRect boxRect = GetMaxBoxRect();
  if (GetWindowLong(GWL_STYLE) & WS_MAXIMIZEBOX)
    boxRect.Offset(-CaptionHeight, 0);
  return boxRect;
}

TRect
TTinyCaption::GetMaxBoxRect()
{
  TRect boxRect = GetCaptionRect();
  boxRect.left = boxRect.right - CaptionHeight; 
  boxRect.top -= 1;
  boxRect.right += 1;
  return boxRect;
}

void
TTinyCaption::DoSysMenu()
{
  HMENU h = GetSystemMenu();
  if (h) {
    TRect r = GetSysBoxRect();
    ClientToScreen(r.TopLeft());  // Cvt pt to screen coord
    TrackPopupMenu(h, TPM_LEFTALIGN | TPM_LEFTBUTTON,
                   r.left-Frame.cx, r.top-Frame.cy-1, 0, HWindow,0);
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TTinyCaption);

void*
TTinyCaption::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TTinyCaption* o = GetObject();

  o->CaptionFont = 0;
  is >> o->TCEnabled;
  if (o->TCEnabled) {
    int captionHeight;
    is >> captionHeight >> o->CloseBox;;
    o->EnableTinyCaption(captionHeight, o->CloseBox);
  }
  return o;
}

void
TTinyCaption::Streamer::Write(opstream& os) const
{
  TTinyCaption* o = GetObject();

  os << o->TCEnabled;
  if (o->TCEnabled) {
    int captionHeight = (100*o->CaptionHeight) /
                          (o->Border.cy+GetSystemMetrics(SM_CYCAPTION));
    os << captionHeight << o->CloseBox;
  }
}
#endif
