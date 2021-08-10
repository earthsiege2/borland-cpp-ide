//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Implementation of TTinyCaption
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_TINYCAPT_H)
# include <owl/tinycapt.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

#if !defined(WS_EX_TOOLWINDOW)
# define WS_EX_TOOLWINDOW         0x00000080L
#endif

OWL_DIAGINFO;

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
  TCEnabled = false;
  CaptionFont = 0;
}

//
//
//
TTinyCaption::~TTinyCaption()
{
  delete CaptionFont;
}

//
//
//
void
TTinyCaption::EnableTinyCaption(int captionHeight, bool closeBox)
{
  Border.cx = TUIMetric::CxBorder;
  Border.cy = TUIMetric::CyBorder;

  // Get width of window borders, these will vary with type of window
  // Really 3 styles are supported:
  //   Fixed frame - WS_DLGFRAME, no WS_BORDER, WS_THICKFRAME optional and
  //                 only affects sizability, not look
  //   Thick frame - WS_BORDER + WS_THICKFRAME, visible thick frame for sizing
  //   Thin frame  - WS_BORDER only. No sizing.
  //
  if ((Attr.Style & WS_CAPTION) == WS_DLGFRAME) {
    Frame.cx = TUIMetric::CxFixedFrame;
    Frame.cy = TUIMetric::CyFixedFrame;
  }
  else {
    Attr.Style |= WS_BORDER;     // must have at least a border
    Attr.Style &= ~WS_DLGFRAME;  // but never a caption (WS_BORDER+WS_DLGFRAME)
    if (Attr.Style & WS_THICKFRAME) {
      Frame.cx = TUIMetric::CxSizeFrame;
      Frame.cy = TUIMetric::CySizeFrame;
    }
    else {
      Frame = Border;
    }
  }

  CloseBox = closeBox;

  // If running under Win95 or NT NewShell, then use its extended style to
  // become a tiny caption
  //
  if (TSystem::Has3dUI()) {
    Attr.Style |= WS_CAPTION;
    Attr.ExStyle |= WS_EX_TOOLWINDOW;
    if (closeBox)
      Attr.Style |= WS_SYSMENU;
    CaptionHeight = TUIMetric::CySmCaption;
    return;
  }

  // Calculate the actual caption height including lower divider, but not top
  // border
  //
  CaptionHeight = (TUIMetric::CyCaption * captionHeight) / 100 - Border.cy;

  // Create the small font
  //
  delete CaptionFont;
  CaptionFont = new TFont(
    "Small Fonts",                // facename
    -(CaptionHeight-2*Border.cy), // height in pixels
    0, 0, 0, FW_NORMAL,           // width,esc,orientation,weight
    VARIABLE_PITCH | FF_SWISS,    // Pitch and Family
    false, false, false,          // Italic, Underline, Strikeout
    ANSI_CHARSET,                 // Charset
    OUT_CHARACTER_PRECIS,         // Output precision
    CLIP_DEFAULT_PRECIS,          // Clip precision
    PROOF_QUALITY                 // Quality
  );

  TCEnabled = true;
}

//
// Return where in the non client area we are.  We only handle caption
// bar area
//
uint
TTinyCaption::EvNCHitTest(TPoint& screenPt)
{
  uint er = 0;
  if (DoNCHitTest(screenPt, er) == esComplete)
    return er;
  return TWindow::EvNCHitTest(screenPt);
}

//
//
//
TEventStatus
TTinyCaption::DoNCHitTest(TPoint& screenPt, uint& evRes)
{
  if (!TCEnabled)
    return esPartial;

  // Check style bits to see what to paint
  //
  long style = GetStyle();
  bool hasSysMenu, hasMaximize, hasMinimize;
  hasSysMenu = hasMaximize = hasMinimize = false;
  if (style & WS_SYSMENU)
    hasSysMenu = true;
  if (style & WS_MAXIMIZEBOX)
    hasMaximize = true;
  if (style & WS_MINIMIZEBOX)
    hasMinimize = true;

  // Convert to window coordinates
  //
  TPoint winPt = screenPt - GetWindowRect().TopLeft();

  if ((hasSysMenu || CloseBox) && GetSysBoxRect().Contains(winPt)) {
    evRes = HTSYSMENU;
    return esComplete;
  }
  else if (hasMinimize && GetMinBoxRect().Contains(winPt)) {
    evRes = HTMINBUTTON;
    return esComplete;
  }
  else if (hasMaximize && GetMaxBoxRect().Contains(winPt)) {
    evRes = HTMAXBUTTON;
    return esComplete;
  }

  // CaptionRect includes buttons so make sure it's last checked
  // Should modify this one to allow clicking in left, top, right thin
  // borders of caption
  //
  else if (GetCaptionRect().Contains(winPt)) {
    evRes = HTCAPTION;
    return esComplete;
  }
  else {
    return esPartial;
  }
}

//
// We only need to paint the caption. Someone else will paint the borders
//
#if defined(BI_PLAT_WIN32)
void TTinyCaption::EvNCPaint(HRGN /*region*/)
#else
void TTinyCaption::EvNCPaint()
#endif
{
  DefaultProcessing();   // Default border painting
  DoNCPaint();           // Then our special caption painting
}

//
//
//
TEventStatus
TTinyCaption::DoNCPaint()
{
  if (!TCEnabled || IsIconic())
    return esPartial;  // We don't do anything special for an Icon

  // If we have focus or our children have focus, then we're active
  // Note: We can't rely only on GetFocus here because when we're being
  //       restored from an icon, we're active, but don't yet have focus!
  //
  THandle focus = GetFocus();
  PaintCaption(GetActiveWindow() == GetHandle() || focus == GetHandle() || IsChild(focus));
  return esPartial;       // Caller must call function to paint borders
}

//
// Return the size of our client area
//
uint
TTinyCaption::EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& calcSize)
{
  uint er = TWindow::EvNCCalcSize(calcValidRects, calcSize);
  DoNCCalcSize(calcValidRects, calcSize, er);
  return er;
}

//
// Return the size of our client area, leaving room for caption bar
//
TEventStatus
TTinyCaption::DoNCCalcSize(bool /*calcValidRects*/,
                           NCCALCSIZE_PARAMS far& calcSize, uint& /*evRes*/)
{
  if (!TCEnabled || IsIconic())
    return esPartial;

  calcSize.rgrc[0].top += GetCaptionRect().Height();

  return esComplete;
}

//
//
//
void
TTinyCaption::EvNCLButtonDown(uint hitTest, TPoint& screenPt)
{
  // Display system menu, invert min/max icons (not), etc
  //
  if (DoNCLButtonDown(hitTest, screenPt) == esPartial)
    TWindow::EvNCLButtonDown(hitTest, screenPt);
}

//
//
//
TEventStatus
TTinyCaption::DoNCLButtonDown(uint hitTest, TPoint& screenPt)
{
  if (!TCEnabled)
    return esPartial;

  switch (hitTest) {
    case HTSYSMENU:
      DownHit = HTSYSMENU;
      if (CloseBox) {
        IsPressed = true;
        SetCapture();
        PaintCloseBox(TWindowDC(*this), GetSysBoxRect(), IsPressed);
      }
      else {
        TRect sysBoxRect = GetSysBoxRect().InflatedBy(-1,-1);
        sysBoxRect.right += 1;

        TWindowDC(*this).PatBlt(sysBoxRect, PATINVERT);

        // Display sys menu on button down
        // Need to lock sys menu until user clicks outside

        // Set flag to indicate we're expecting a sys command, & then send
        // message to popup sys menu
        //
        WaitingForSysCmd = true;
        SendMessage(WM_SYSCOMMAND, SC_MOUSEMENU|HTSYSMENU,
                    MkParam2(screenPt.x,screenPt.y));

        // If we didn't execute a command, user released btn outside of menu
        // If it was released in sys menu box, then redisplay menu as if it
        // were brought up with a keystroke
        //
        if (WaitingForSysCmd) {
          uint hitTest;
          TPoint pt;
          GetCursorPos(pt);
          DoNCHitTest(pt, hitTest);
          if (hitTest == HTSYSMENU) {
            SendMessage(WM_SYSCOMMAND, SC_KEYMENU|HTSYSMENU);
          }
        }
        if (GetHandle())
          TWindowDC(*this).PatBlt(sysBoxRect, PATINVERT);
      }
      return esComplete;

    case HTMINBUTTON:
      DownHit = HTMINBUTTON;
      IsPressed = true;
      SetCapture();
      PaintMinBox(TWindowDC(*this), GetMinBoxRect(), IsPressed);
      return esComplete;

    case HTMAXBUTTON:
      DownHit = HTMAXBUTTON;
      IsPressed = true;
      SetCapture();
      PaintMaxBox(TWindowDC(*this), GetMaxBoxRect(), IsPressed);
      return esComplete;
  }
  DownHit = HTNOWHERE;
  return esPartial;
}

//
//
//
void
TTinyCaption::EvMouseMove(uint modKeys, TPoint& pt)
{
  if (DoMouseMove(modKeys, pt) == esPartial)
    TWindow::EvMouseMove(modKeys, pt);
}

//
//
//
TEventStatus
TTinyCaption::DoMouseMove(uint /*modKeys*/, TPoint& pt)
{
  if (TCEnabled && DownHit != HTNOWHERE) {
    uint   hitTest;
    TPoint screenPt = pt;
    ClientToScreen(screenPt);    // Cvt to screen coord
    DoNCHitTest(screenPt, hitTest);
    bool isNowPressed = hitTest == DownHit;

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

//
//
//
void
TTinyCaption::EvLButtonUp(uint modKeys, TPoint& pt)
{
  // If we're still in area where buton went down, then do it
  //
  if (DoLButtonUp(modKeys, pt) == esPartial)
    TWindow::EvLButtonUp(modKeys, pt);
}

//
//
//
TEventStatus
TTinyCaption::DoLButtonUp(uint modKeys, TPoint& pt)
{
  if (TCEnabled && DownHit != HTNOWHERE) {
    ReleaseCapture();
    DoMouseMove(modKeys, pt);

    uint   hitTest;
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

        // We have to handle these buttons also to prevent defproc from
        // painting the standard big min/max buttons when left mouse button is
        // pressed
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

//
//
//
bool
TTinyCaption::EvNCActivate(bool active)
{
  bool er;
  if (DoNCActivate(active, er) == esPartial)
    er = TWindow::EvNCActivate(active);
  return er;
}

//
//
//
TEventStatus
TTinyCaption::DoNCActivate(bool active, bool& evRes)
{
  if (!TCEnabled || IsIconic())
    return esPartial;  // Let default do it's thing

  PaintCaption(active);
  evRes = true;
  return esComplete;
}

//
//
//
TResult
TTinyCaption::EvCommand(uint id, THandle hCtl, uint notifyCode)
{
  TResult er;
  if (DoCommand(id, hCtl, notifyCode, er) == esComplete)
    return er;
  return TWindow::EvCommand(id, hCtl, notifyCode);
}

//
//
//
TEventStatus
TTinyCaption::DoCommand(uint id, THandle /*hCtl*/, uint notifyCode, TResult& evRes)
{
  // We're displaying system menu using TrackPopup...
  // This will send us WM_COMMAND messages instead of WM_SYSCOMMAND msgs
  // If we get a system menu command then transform it into a WM_SYSCOMMAND
  //
  if (!TCEnabled)
    return esPartial;

  if (id >= 0xF000) {
    WaitingForSysCmd = false;  // Let LButtonDown handler know that a command was sent
    evRes = HandleMessage(WM_SYSCOMMAND, id, notifyCode);
    return esComplete;
  }
  else {
    evRes = 0;
    return esPartial;
  }
}

//
//
//
void
TTinyCaption::EvSysCommand(uint cmdType, TPoint& p)
{
  if (DoSysCommand(cmdType,p) == esPartial)
    TWindow::EvSysCommand(cmdType, p);
}

//
// Handle WM_SYSCOMMAND to make sure that SC_KEYMENU and SC_MOUSEMENU bring up
// our sys menu at the right coord w/ respect to the tiny sys box.
//
// If iconic, then let default windows processing deal with the menu
//
TEventStatus
TTinyCaption::DoSysCommand(uint cmdType, TPoint&)
{
  if (!TCEnabled)
    return esPartial;

  cmdType &= 0xFFF0;
  if ((cmdType == SC_KEYMENU || cmdType == SC_MOUSEMENU) && !IsIconic()) {
    DoSysMenu();
    return esComplete;
  }
  return esPartial;
}

//
//
//
void
TTinyCaption::PaintButton(TDC& dc, TRect& r, bool pressed)
{
   TBrush winFrameBr(TColor::SysWindowFrame);
//  dc.OWLFastWindowFrame(winFrameBr, r, 1, 1);
  dc.FrameRect(r, winFrameBr);

  r.Inflate(-1,-1);
  dc.TextRect(r, TColor::Sys3dFace);
  if (r.Width() > 4 && r.Height() > 4) {
    if (pressed) {
      dc.TextRect(r.left, r.top, r.right, r.top+1, TColor::Sys3dShadow);
      dc.TextRect(r.left, r.top+1, r.left+1, r.bottom, TColor::Sys3dShadow);
    }
    else {
      dc.TextRect(r.left, r.top, r.right-1, r.top+1, TColor::Sys3dHilight);
      dc.TextRect(r.left, r.top+1, r.left+1, r.bottom-1, TColor::Sys3dHilight);
      dc.TextRect(r.right-1, r.top+1, r.right, r.bottom, TColor::Sys3dShadow);
      dc.TextRect(r.left+1, r.bottom-1, r.right-1, r.bottom, TColor::Sys3dShadow);
    }
  }
}

//
//
//
void
TTinyCaption::PaintCloseBox(TDC& dc, TRect& boxRect, bool pressed)
{
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  // Do something different to differentiate from standard system menu--
  // draw a recessed black box glyph about half the button size, centered
  //
  int glyphWidth  = boxRect.Width() > 7 ?
                      boxRect.Width()-boxRect.Width()/2-1 : boxRect.Width()-3;
  int glyphHeight = boxRect.Height() > 7 ?
                      boxRect.Height()-boxRect.Height()/2-1 : boxRect.Height()-3;
  if (glyphWidth > 1 && glyphHeight > 1) {
    TRect glyphRect(0, 0, glyphWidth, glyphHeight);
    glyphRect.Offset(boxRect.left + (boxRect.Width()-glyphWidth-1)/2,
                     boxRect.top + (boxRect.Height()-glyphHeight-1)/2);

    dc.TextRect(glyphRect, TColor::Sys3dShadow);
    glyphRect.Offset(1,1);
    dc.TextRect(glyphRect, TColor::Sys3dHilight);
    glyphRect.BottomRight().Offset(-1,-1);
    dc.TextRect(glyphRect, TColor::SysBtnText);
  }
}

//
//
//
void
TTinyCaption::PaintSysBox(TDC& dc, TRect& boxRect, bool /*pressed*/)
{
  // Dont paint over the left & top borders
  //
  boxRect.left++;
  boxRect.top++;

  // Fill the box with 3d face
  //
  dc.TextRect(boxRect, TColor::Sys3dFace);

  // Draw the ventilator (sysmenu) box, with shadow
  //
  TPoint begPt = boxRect.TopLeft().OffsetBy(2, (boxRect.Height()-3)/2);
  TRect ventRect(begPt, TSize(boxRect.Width()-5, 3));

  // Draw shadow down and right 1
  //
  dc.TextRect(ventRect.left+1, ventRect.top+1,
              ventRect.right+1, ventRect.bottom+1, TColor::Sys3dShadow);

  // Draw ventilator rectangle
  //
  TBrush btnTextBr(TColor::SysBtnText);
  dc.FrameRect(ventRect, btnTextBr);

  // Draw white interior of ventilator
  //
  dc.TextRect(ventRect.left+1, ventRect.top+1,
              ventRect.right-1, ventRect.top+2, TColor::Sys3dHilight);

  dc.TextRect(boxRect.right, boxRect.top,
              boxRect.right+1, boxRect.bottom, TColor::SysBtnText);
}

//
//
//
void
TTinyCaption::PaintMinBox(TDC& dc, TRect& boxRect, bool pressed)
{
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  int bh = boxRect.Height();
  int bw = boxRect.Width();

  TPoint begPt = boxRect.TopLeft().OffsetBy((bw+1)/4, (bh+2)/3);
  TPoint endPt = begPt.OffsetBy((bw+1)/2,0);
  while (begPt.x < endPt.x) {
    dc.MoveTo(begPt);
    dc.LineTo(endPt);
    begPt.Offset(1,1);
    endPt.Offset(-1,1);
  }
}

//
//
//
void
TTinyCaption::PaintMaxBox(TDC& dc, TRect& boxRect, bool pressed)
{
  // Fill the box with light gray & draw bevel if possible
  //
  PaintButton(dc, boxRect, pressed);

  if (pressed)
    boxRect.Offset(1,1);

  // Down triangle
  //
  int bh = boxRect.Height();
  int bw = boxRect.Width();

  if (IsZoomed()) {
    TPoint begPt = boxRect.BottomLeft().OffsetBy((bw+1)/4, -bh*3/8);
    TPoint endPt = begPt.OffsetBy((bw+1)/2, 0);
    while (begPt.x < endPt.x) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset(1,1);
      endPt.Offset(-1,1);
    }
  }

  // Up triangle
  //
  {
    TPoint begPt = boxRect.TopLeft().OffsetBy((bw+1)/4, IsZoomed() ? bh*3/8 : bh*2/3);
    TPoint endPt = begPt.OffsetBy((bw+1)/2, 0);
    while (begPt.x < endPt.x) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset(1, -1);
      endPt.Offset(-1, -1);
    }
  }
}

//
//
//
void
TTinyCaption::PaintCaption(bool active)
{
  // Paint caption background and caption text if any.
  //
  TWindowDC dc(*this);
  TRect captRect = GetCaptionRect();

  dc.SetTextColor(active ? TColor::SysCaptionText :
                           TColor::SysInactiveCaptionText);

  // Could use a TBrush and PatBlt instead, but text backgrounds are always
  // solid so this works well.
  //
  dc.TextRect(captRect, active ? TColor::SysActiveCaption :
                                 TColor::SysInactiveCaption);

  CHECK(CaptionFont);
  dc.SelectObject(*CaptionFont);
  dc.SetBkMode(TRANSPARENT);
  TSize textSize = dc.GetTextExtent(Title, strlen(Title));

  // Calc x coord for text, so that text is centered between caption buttons
  //
  int  xOrg = captRect.right - captRect.left;
  long style = GetWindowLong(GWL_STYLE);

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

  dc.ExtTextOut(xOrg, captRect.top-Border.cy,
    ETO_CLIPPED,
    &captRect,
    Title,
    strlen(Title)
  );
  dc.RestoreFont();

  // Paint widgets: sysmenu or close button, minimize button, maximize button
  // They currently all use a black pen
  //
  dc.SelectStockObject(BLACK_PEN);

  // Paint system menu or close button
  //
  if (CloseBox)
    PaintCloseBox(dc, GetSysBoxRect(), false);
  else if (style & WS_SYSMENU)
    PaintSysBox(dc, GetSysBoxRect(), false);

  // Paint minimize button
  //
  if (style & WS_MINIMIZEBOX)
    PaintMinBox(dc, GetMinBoxRect(), false);

  // Paint maximize button
  //
  if (style & WS_MAXIMIZEBOX)
    PaintMaxBox(dc, GetMaxBoxRect(), false);

  // Draw window-frame color line under caption
  //
  TBrush winFrameBr(TColor::SysWindowFrame);
  dc.FrameRect(captRect.left, captRect.bottom-1, captRect.right, captRect.bottom,
               winFrameBr);
}

//
//  NOTE: GetCaptionRect and GetSysBoxRect must be kept in sync!
//
TRect
TTinyCaption::GetCaptionRect()
{
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
// Return a rectangle for sysmenu, minimize, or maximize rectangle
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

//
//
//
TRect
TTinyCaption::GetMinBoxRect()
{
  // Far right on caption if no max box, else next to max box
  //
  TRect boxRect = GetMaxBoxRect();
  if (GetWindowLong(GWL_STYLE) & WS_MAXIMIZEBOX)
    boxRect.Offset(-CaptionHeight, 0);
  return boxRect;
}

//
//
//
TRect
TTinyCaption::GetMaxBoxRect()
{
  TRect boxRect = GetCaptionRect();
  boxRect.left = boxRect.right - CaptionHeight;
  boxRect.top -= 1;
  boxRect.right += 1;
  return boxRect;
}

//
// Get system menu, setup menu items, popup & track it
//
void
TTinyCaption::DoSysMenu()
{
  HMENU hSysMenu = GetSystemMenu();
  if (hSysMenu) {
    uint32 style = GetWindowLong(GWL_STYLE);
    EnableMenuItem(hSysMenu, SC_RESTORE, (IsIconic() || IsZoomed()) ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hSysMenu, SC_MOVE, (1/*style & WS_CAPTION*/) ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hSysMenu, SC_SIZE, (style & WS_THICKFRAME) ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hSysMenu, SC_MINIMIZE, ((style&WS_MINIMIZEBOX) && !IsIconic()) ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hSysMenu, SC_MAXIMIZE, ((style&WS_MAXIMIZEBOX) && !IsZoomed()) ? MF_ENABLED : MF_GRAYED);
    TRect r = GetSysBoxRect();
    ClientToScreen(r.TopLeft());     // Cvt pt to screen coord
    ClientToScreen(r.BottomRight());
    TrackPopupMenu(hSysMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON,
                   r.left-Frame.cx, r.top-Frame.cy, 0, GetHandle(), &r);
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

#if !defined(BI_NO_OBJ_STREAMING)

IMPLEMENT_STREAMABLE(TTinyCaption);

//
// Reads an instance of TTinyCaption from the given ipstream
//
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

//
// Writes the TTinyCaption to the given opstream
//
void
TTinyCaption::Streamer::Write(opstream& os) const
{
  TTinyCaption* o = GetObject();

  os << o->TCEnabled;
  if (o->TCEnabled) {
    int captionHeight = (100*o->CaptionHeight) /
                          (o->Border.cy+TUIMetric::CyCaption);
    os << captionHeight << o->CloseBox;
  }
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
