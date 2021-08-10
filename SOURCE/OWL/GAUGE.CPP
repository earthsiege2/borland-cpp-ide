//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TGauge, gauge user interface widget
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gauge.h>
#include <owl/dc.h>

DEFINE_RESPONSE_TABLE1(TGauge, TControl)
  EV_WM_ERASEBKGND,
END_RESPONSE_TABLE;

//
// Constructor for a TGauge object
//
TGauge::TGauge(TWindow*        parent,
               const char far* title,
               int             id,
               int x, int y, int w, int h,
               bool            isHorizontal,
               int             margin,
               TModule*        module)
:
  TControl(parent, id, title, x, y, w, h, module)
{
  SetRange(0, 100);
  Value = 0;
  Margin = margin * GetSystemMetrics(SM_CXBORDER);
  IsHorizontal = isHorizontal;
  LedSpacing = 0;
  LedThick = 0;
  BarColor = TColor(0, 0, 255);  // default to solid blue
  Attr.Style &= ~WS_TABSTOP;     // no input for us
}

//
// Check & set the gauge range
//
void
TGauge::SetRange(int min, int max) 
{
  Min = min;
  Max = max;
  if (Max <= Min)
    Max = Min+1;
}

//
// Set the value of the gauge
//
void
TGauge::SetValue(int value)
{
  //
  // constrain value to be in the range "Min .. Max"
  //
  if (value > Max)
    value = Max;

  else if (value < Min)
    value = Min;
  
  //
  // Paint to new position, converting value to pixels
  //
  if (value != Value) {
    if (HWindow) {
      Invalidate(false);
    }
    Value = value;
  }
}

//
// Set led parameters
//
void
TGauge::SetLed(int spacing, int thickPercent)
{
  LedSpacing = spacing;
  LedThick = thickPercent;
}

//
// Paint the border-- bevel & margin
//
void
TGauge::PaintBorder(TDC& dc)
{
  int    xBorder = ::GetSystemMetrics(SM_CXBORDER);
  int    yBorder = ::GetSystemMetrics(SM_CYBORDER);

  TBrush shadowBrush(::GetSysColor(COLOR_BTNSHADOW));
  dc.SelectObject(shadowBrush);
  dc.PatBlt(0, 0, Attr.W, yBorder);
  dc.PatBlt(0, yBorder, xBorder, Attr.H-yBorder);

  TBrush hiliteBrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
  dc.SelectObject(hiliteBrush);
  dc.PatBlt(xBorder, Attr.H-yBorder, Attr.W-xBorder, Attr.H-yBorder);
  dc.PatBlt(Attr.W-xBorder, yBorder, xBorder, Attr.H-yBorder-yBorder);

  TBrush  faceBrush(::GetSysColor(COLOR_BTNFACE));
  TRect   innerRect(xBorder, yBorder, Attr.W-xBorder, Attr.H-yBorder);

  //
  // Walk in from the bevel painting frames as we go
  //
  for (int i = 0; i < Margin; i++) {
    dc.FrameRect(innerRect, faceBrush);
    innerRect.Inflate(-1, -1);
  }
}

//
// Paint the whole gauge: border & graphic
//
void
TGauge::Paint(TDC& dc, bool /*erase*/, TRect&)
{
  PaintBorder(dc);

  //
  // Prepare to paint the bar or LED sequence in the well
  //
  int    xBorder = ::GetSystemMetrics(SM_CXBORDER);
  int    yBorder = ::GetSystemMetrics(SM_CYBORDER);

  TBrush  barBrush(BarColor);
  TBrush  faceBrush(::GetSysColor(COLOR_BTNFACE));
  TRect   innerRect(xBorder+Margin, yBorder+Margin, 
                   Attr.W-xBorder-Margin, Attr.H-yBorder-Margin);
  //
  // Draw either LEDs or a solid bar as indicated by LedSpacing
  //
  if (LedSpacing) {
    if (IsHorizontal) {
      int ledStep = (innerRect.Width()*LedSpacing)/(Max-Min);
      int ledWidth = (ledStep*LedThick)/100;
      int gapWidth = ledStep - ledWidth;
      int x = innerRect.left;
      int right = innerRect.left +
                  int((long(Value-Min)*innerRect.Width())/(Max-Min));
      for (; x < right; x += ledStep) {
        dc.FillRect(x, innerRect.top, x+ledWidth, innerRect.bottom, barBrush);
        dc.FillRect(x+ledWidth, innerRect.top, x+ledWidth+gapWidth, innerRect.bottom, faceBrush);
      }
      dc.FillRect(x, innerRect.top, innerRect.right, innerRect.bottom, faceBrush);
    }
    else {
      int ledStep = int((long(innerRect.Height())*LedSpacing)/(Max-Min));
      int ledHeight = int((long(ledStep)*LedThick)/100);
      int gapHeight = ledStep - ledHeight;
      int y = innerRect.bottom;
      int top = innerRect.top + innerRect.Height() -
                int((long(Value-Min)*innerRect.Height())/(Max-Min));
      for (; y > top; y -= ledStep) {
        dc.FillRect(innerRect.left, y-ledHeight, innerRect.right, y, barBrush);
        dc.FillRect(innerRect.left, y-ledHeight-gapHeight, innerRect.right, y-ledHeight, faceBrush);
      }
      dc.FillRect(innerRect.left, innerRect.top, innerRect.right, y, faceBrush);
    }
  }
  else {
    TRect barRect(innerRect);
    TRect emptyRect(innerRect);
    if (IsHorizontal) {
      int w = int((long(Value-Min)*innerRect.Width())/(Max-Min));
      barRect.right = emptyRect.left = innerRect.left+w;
    }
    else {
      int h = innerRect.Height() -
              int((long(Value-Min)*innerRect.Height())/(Max-Min));
      barRect.top = emptyRect.bottom = innerRect.top+h;
    }
    dc.FillRect(emptyRect, faceBrush);
    dc.FillRect(barRect, barBrush);
    
    if (Title && *Title) {
      char buff[32];
      wsprintf(buff, Title, Value);

      int   len = strlen(buff);
      TSize extent = dc.GetTextExtent(buff, len);
      int   x = innerRect.left;
      int   y = innerRect.top;

      if (extent.cx < innerRect.Width())
        x += (innerRect.Width() - extent.cx) / 2;  // center text horizontally

      if (extent.cy < innerRect.Height())
        y += (innerRect.Height() - extent.cy) / 2; // center text vertically
      
      //
      // use ExtTextOut() to paint the text in contrasting colors to the bar
      // and background
      //
      dc.SetBkMode(TRANSPARENT);
      dc.SetTextColor(GetSysColor(COLOR_BTNFACE));
      dc.ExtTextOut(x, y, ETO_CLIPPED, &barRect, buff, strlen(buff));
      dc.SetTextColor(BarColor);
      dc.ExtTextOut(x, y, ETO_CLIPPED, &emptyRect, buff, strlen(buff));
    }
  }
}

//
// We'll always erase as we paint to avoid flicker
//
bool
TGauge::EvEraseBkgnd(HDC)
{
  return true;
}
