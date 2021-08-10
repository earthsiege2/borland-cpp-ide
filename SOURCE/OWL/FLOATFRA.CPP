//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TFloatingFrame.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/floatfra.h>
#include <owl/dc.h>

#if !defined(SECTION) || SECTION == 1

//
// Order is very important.  Must make sure that TTinyCaption gets 1st crack
// after us
//
DEFINE_RESPONSE_TABLE2(TFloatingFrame, TTinyCaption, TFrameWindow)
  EV_WM_SYSCOMMAND,
  EV_WM_NCCALCSIZE,
  EV_WM_NCPAINT,
  EV_WM_NCHITTEST,
END_RESPONSE_TABLE;

TFloatingFrame::TFloatingFrame(TWindow* owner, char* title, TWindow* client, 
                               bool shrinkToClient, int captionHeight,
                               bool popupPalette, TModule* module)
:
  TFrameWindow(owner, title, client, shrinkToClient, module),
  TTinyCaption(),
  Margin(2, 2)
{
  FloatingPaletteEnabled = popupPalette;
  if (FloatingPaletteEnabled) {
    Attr.Style = WS_POPUP | WS_BORDER | WS_VISIBLE;

    //
    // Use close box (true) for palettes, & calc dimensions w/ new styles
    //
    EnableTinyCaption(captionHeight, true);

    //
    // Windows with a popup style ignore CW_USEDEFAULT style
    // So we will specify a default size
    // Normal use will be to specify a client and allow frame to sizeToClient
    // so this will rarely be used.
    //
    Attr.X = Attr.Y = 0;
    Attr.W = 100;
    Attr.H = 50;
  }
  else
    EnableTinyCaption(captionHeight, false);
}

//
// Resolving ambiguous mixin reference
//
LRESULT
TFloatingFrame::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  LRESULT er;
  if (TTinyCaption::DoCommand(id, hWndCtl, notifyCode, er) == esComplete)
    return er;
  if (Parent)
    return Parent->EvCommand(id, hWndCtl, notifyCode);
  return TFrameWindow::EvCommand(id, hWndCtl, notifyCode);
}

//
// This is an example of a mix-in that does partial event handling
// We need to call the 'do' function for the mixin instead of the 'Ev'
// function to avoid duplicate default processing
//
void
TFloatingFrame::EvSysCommand(uint cmdType, TPoint& p)
{
  if (TTinyCaption::DoSysCommand(cmdType, p) == esComplete)
    return;
  TFrameWindow::EvSysCommand(cmdType,p);
}

uint
TFloatingFrame::EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& calcSize)
{
  // Adjust margins for extra edge around palette
  //
  if (FloatingPaletteEnabled && !IsIconic()) {
    calcSize.rgrc[0].left +=   Margin.cx * GetSystemMetrics(SM_CXBORDER);
    calcSize.rgrc[0].top +=    Margin.cy * GetSystemMetrics(SM_CYBORDER);
    calcSize.rgrc[0].right -=  Margin.cx * GetSystemMetrics(SM_CXBORDER);
    calcSize.rgrc[0].bottom -= Margin.cy * GetSystemMetrics(SM_CYBORDER);
  }

  uint er;
  if (DoNCCalcSize(calcValidRects, calcSize, er) == esComplete)
    return er;
  return TFrameWindow::EvNCCalcSize(calcValidRects, calcSize);
}

//
// We only need to paint the margins. TWindow (via DefWindowProc) will paint
// the borders, & TTinyCaption will paint the caption
//
void
TFloatingFrame::EvNCPaint()
{
  TWindow::EvNCPaint();       // Default border painting
  TTinyCaption::DoNCPaint();  // Tiny caption painting

  if (FloatingPaletteEnabled) {
    //
    // Paint margins in button face color
    //
    TWindowDC dc(*this);
    TRect     wr = GetWindowRect().InflatedBy(-Frame);
    wr -= wr.TopLeft();
    wr += Border;
    wr.top = GetCaptionRect().bottom;
    int mx = Margin.cx * Border.cx;
    int my = Margin.cy * Border.cy;
    dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
    dc.TextRect(wr.left, wr.top, wr.left+mx, wr.bottom);           // left
    dc.TextRect(wr.left+mx, wr.top, wr.right-mx, wr.top+my);       // top
    dc.TextRect(wr.right-mx, wr.top, wr.right, wr.bottom);         // right
    dc.TextRect(wr.left+mx, wr.bottom-my, wr.right-mx, wr.bottom); // bottom
  }
}

//
// Return where in the non client area we are.  We only handle caption
// bar area
//
uint
TFloatingFrame::EvNCHitTest(TPoint& screenPt)
{
  uint er;
  if (TTinyCaption::DoNCHitTest(screenPt, er) == esComplete ||
      DoNCHitTest(screenPt, er) == esComplete)
    return er;
  return TWindow::EvNCHitTest(screenPt);
}

TEventStatus
TFloatingFrame::DoNCHitTest(TPoint& screenPt, uint& evRes)
{
  if (FloatingPaletteEnabled) {
    TPoint clientOffs(0,0);
    ClientToScreen(clientOffs);
    if (!GetClientRect().Contains(screenPt-clientOffs)) {
      evRes = HTCAPTION;
      return esComplete;
    }
  }
  return esPartial;
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TFloatingFrame, TTinyCaption, TFrameWindow);

void*
TFloatingFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TFloatingFrame* o = GetObject();
  ReadBaseObject((TFrameWindow*)o, is);
  ReadBaseObject((TTinyCaption*)o, is);
  is >> o->Margin;
  return o;
}

void
TFloatingFrame::Streamer::Write(opstream& os) const
{
  TFloatingFrame* o = GetObject();
  WriteBaseObject((TFrameWindow*)o, os);
  WriteBaseObject((TTinyCaption*)o, os);
  os << o->Margin;
}

#endif
