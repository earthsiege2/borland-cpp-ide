//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\floatfra.cpp
//   Implementation of class TFloatingFrame.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\floatfra.h>
#include <owl\dc.h>

#if !defined(SECTION) || SECTION == 1

//
// Order is very important.  Must make sure that TTinyCaption gets 1st crack
// after us
//
DEFINE_RESPONSE_TABLE2(TFloatingFrame, TTinyCaption, TFrameWindow)
  EV_WM_SYSCOMMAND,
  EV_WM_NCCALCSIZE,
  EV_WM_NCPAINT,
END_RESPONSE_TABLE;

TFloatingFrame::TFloatingFrame(TWindow* owner, char* title, TWindow* client, 
                               BOOL shrinkToClient, int captionHeight,
                               BOOL popupPalette, TModule* module)
  : TFrameWindow(owner, title, client, shrinkToClient, module),
    TTinyCaption(),
    Margin(2, 2)
{
  FloatingPaletteEnabled = popupPalette;
  EnableTinyCaption(captionHeight, FloatingPaletteEnabled);
  if (FloatingPaletteEnabled) {
    Attr.Style = WS_POPUP | WS_BORDER | WS_VISIBLE;

    //
    // Use close box (TRUE) for palettes
    //
    EnableTinyCaption(TFloatingFrame::DefaultCaptionHeight, TRUE);

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
}

//
// Resolving ambiguous mixin reference
//
LRESULT
TFloatingFrame::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
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
TFloatingFrame::EvSysCommand(UINT cmdType, TPoint& p)
{
  if (TTinyCaption::DoSysCommand(cmdType, p) == esComplete)
    return;
  TFrameWindow::EvSysCommand(cmdType,p);
}

UINT
TFloatingFrame::EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& calcSize)
{
  // Adjust margins for extra edge around palette
  //
  if (FloatingPaletteEnabled && !IsIconic()) {
    calcSize.rgrc[0].left +=   Margin.cx * GetSystemMetrics(SM_CXBORDER);
    calcSize.rgrc[0].top +=    Margin.cy * GetSystemMetrics(SM_CYBORDER);
    calcSize.rgrc[0].right -=  Margin.cx * GetSystemMetrics(SM_CXBORDER);
    calcSize.rgrc[0].bottom -= Margin.cy * GetSystemMetrics(SM_CYBORDER);
  }

  UINT er;
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
