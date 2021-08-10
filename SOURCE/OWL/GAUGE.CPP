//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of TGauge, a gauge user interface widget
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GAUGE_H)
# include <owl/gauge.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#include <stdio.h>

DEFINE_RESPONSE_TABLE1(TGauge, TControl)
  EV_WM_ERASEBKGND,
END_RESPONSE_TABLE;

//
// Don't know off the bat, native impl may not cut it. Decide later before
// creation of the window
//
TNativeUse TGauge::ClassNativeUse = nuAttempt;

//
// General constructor for a TGauge object
//
TGauge::TGauge(TWindow*        parent,
               const char far* title,
               int             id,
               int x, int y, int w, int h,
               bool            isHorizontal,
               int             margin,
               TModule*        module)
:
  TControl(parent, id, title, x, y, w, h ? h : int(TUIMetric::CyVScroll), module)
{
  Min = 0;
  Max = 100;
  Step = 10;
  Value = 0;
  Margin = margin * TUIMetric::CxBorder;
  IsHorizontal = isHorizontal;
  LedSpacing = 0;
  LedThick = 0;
  BarColor = TColor::SysHighlight;
  Attr.Style &= ~WS_TABSTOP;     // no input for us

  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;
}

//
// Simplified constructor for a TGauge object--creates horizontal LED style
// gauge using a system control when available
//
TGauge::TGauge(TWindow*        parent,
               int             id,
               int x, int y, int w, int h,
               TModule*        module)
:
  TControl(parent, id, "", x, y, w, h ? h : int(TUIMetric::CyVScroll), module)
{
  Min = 0;
  Max = 100;
  Step = 10;
  Value = 0;
  Margin = TUIMetric::CxBorder;
  IsHorizontal = true;
  LedSpacing = ((Attr.H - 2*Margin) * 2) / 3 + 2*Margin;  
  LedThick = 100 * LedSpacing / (LedSpacing - 2*Margin);
  BarColor = TColor::SysHighlight;
  Attr.Style &= ~WS_TABSTOP;     // no input for us

  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;
}

//
// Constructor for a resource gauge object.
//
TGauge::TGauge(TWindow*        parent,
               int             resId,
               TModule*        module)
:
  TControl(parent, resId, module)
{
  Min = 0;
  Max = 100;
  Step = 10;
  Value = 0;
  Margin = TUIMetric::CxBorder;
  IsHorizontal = true;
  LedSpacing = ((Attr.H - 2*Margin) * 2) / 3 + 2*Margin;  
  LedThick = 100 * LedSpacing / (LedSpacing - 2*Margin);
  BarColor = TColor::SysHighlight;

  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;
}

//
// Returns the class name of the native control or emulation
// depending on NativeUse.
//
char far*
TGauge::GetClassName()
{
  // Decide now, if we haven't already, whether to use Native control for this
  // based on settings & availability
  //
  if ((NativeUse & nuSuggestion) >= nuDontCare && IsHorizontal &&
      LedSpacing > 0 && LedThick > 0 && TCommCtrl::IsAvailable())
    NativeUse = TNativeUse(NativeUse | nuUsing);
  else
    NativeUse = TNativeUse(NativeUse & ~nuUsing);

  return (NativeUse & nuUsing) ? PROGRESS_CLASS : "OWL_Gauge";
}

//
// Check & set the gauge range
//
void
TGauge::SetRange(int min, int max)
{
  if (max <= min)
    max = min+1;

  if ((NativeUse & nuUsing) && GetHandle()) {
    if (!SendMessage(PBM_SETRANGE, 0, MkParam2(min, max)))
      return; 
  }

  Min = min;
  Max = max;
}

//
// Set the step amount of the gauge for StepIt operations
//
void
TGauge::SetStep(int step)
{
  if ((NativeUse & nuUsing) && GetHandle())
    SendMessage(PBM_SETSTEP, step);

  Step = step;
}

//
// Set the value of the gauge
//
void
TGauge::SetValue(int value)
{
  // Constrain value to be in the range "Min..Max"
  //
  if (value > Max)
    value = Max;

  else if (value < Min)
    value = Min;

  // Paint to new position, converting value to pixels
  //
  if (value != Value) {
    if (GetHandle()) {
      if (NativeUse & nuUsing)
        SendMessage(PBM_SETPOS, value);
      else
        Invalidate(false);
    }
    Value = value;
  }
}

//
// Change the value of the gauge given a delta
//
void
TGauge::DeltaValue(int delta)
{
  if (!delta)
    return;

  // Constrain delta such that Value stays in the range "Min..Max"
  //
  if (delta + Value > Max)
    delta = Max - Value;

  else if (delta + Value < Min)
    delta = Min - Value;

  if (GetHandle()) {
    if (NativeUse & nuUsing) {
      Value = (int)SendMessage(PBM_DELTAPOS, delta); // Take oportunity to sync
      return;  // Bypass Value update below
    }
    // Paint to new position, converting value to pixels
    //
    else
      Invalidate(false);
  }

  Value += delta;
}

//
// Adjust active gauge value by step increment. Wrap around to Min of range
// on overflow
//
void
TGauge::StepIt()
{
  if (GetHandle()) {
    if (NativeUse & nuUsing) {
      SendMessage(PBM_STEPIT);
    }
    else {
      if (Value + Step < Max)
        DeltaValue(Step);
      else
        SetValue(Min);
    }
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
// If using a system control, update it to match our member settings
//
void
TGauge::SetupWindow()
{
  TControl::SetupWindow();
  if (NativeUse & nuUsing) {
    SendMessage(PBM_SETRANGE, 0, MkParam2(Min, Max));
    SendMessage(PBM_SETSTEP, Step);
    SendMessage(PBM_SETPOS, Value);
  }
}

//
// Paint the border-- bevel & margin
//
void
TGauge::PaintBorder(TDC& dc)
{
  int   xBorder = TUIMetric::CxBorder;
  int   yBorder = TUIMetric::CyBorder;
  TRect cr(GetClientRect());
  int   w = cr.right;
  int   h = cr.bottom;

  TBrush shadowBrush(TColor::Sys3dShadow);
  dc.SelectObject(shadowBrush);
  dc.PatBlt(0, 0, w, yBorder);
  dc.PatBlt(0, yBorder, xBorder, h-yBorder);

  TBrush hiliteBrush(TColor::Sys3dHilight);
  dc.SelectObject(hiliteBrush);
  dc.PatBlt(xBorder, h-yBorder, w-xBorder, h-yBorder);
  dc.PatBlt(w-xBorder, yBorder, xBorder, h-yBorder-yBorder);

  TBrush  faceBrush(TColor::Sys3dFace);
  TRect   innerRect(xBorder, yBorder, w-xBorder, h-yBorder);

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

  // Prepare to paint the bar or LED sequence in the well
  //
  int    xBorder = TUIMetric::CxBorder;
  int    yBorder = TUIMetric::CyBorder;
  TRect cr(GetClientRect());
  int   w = cr.right;
  int   h = cr.bottom;

  TBrush  barBrush(BarColor);
  TBrush  faceBrush(TColor::Sys3dFace);
  TRect   innerRect(xBorder+Margin, yBorder+Margin,
                    w-xBorder-Margin, h-yBorder-Margin);

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
      wsprintf(buff, Title, Value);  // Need wsprintf for char far*

      int   len = strlen(buff);
      TSize extent = dc.GetTextExtent(buff, len);
      int   x = innerRect.left;
      int   y = innerRect.top;

      if (extent.cx < innerRect.Width())
        x += (innerRect.Width() - extent.cx) / 2;  // center text horizontally

      if (extent.cy < innerRect.Height())
        y += (innerRect.Height() - extent.cy) / 2; // center text vertically

      // use ExtTextOut() to paint the text in contrasting colors to the bar
      // and background
      //
      dc.SetBkMode(TRANSPARENT);
      dc.SetTextColor(TColor::Sys3dFace);
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
  if (NativeUse & nuUsing)
    return DefaultProcessing();
  else
    return true;
}
