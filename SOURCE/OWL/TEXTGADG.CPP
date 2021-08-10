//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TTextGadget.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/textgadg.h>
#include <owl/gadgetwi.h>

TTextGadget::TTextGadget(int          id,
                         TBorderStyle borderStyle,
                         TAlign       align,
                         uint         numChars,
                         const char*  text)
:
  TGadget(id, borderStyle)
{
  Margins.Left = Margins.Right = 2;
  Align = align;
  NumChars = numChars;
  Text = 0;
  TextLen = 0;
  if (text)
    SetText(text);
}

TTextGadget::~TTextGadget()
{
  delete [] Text;
}

//
// Invalidate the working portion of this gadget--the InnerRect
//
void
TTextGadget::Invalidate()
{
  TRect  innerRect;

  GetInnerRect(innerRect);
  InvalidateRect(innerRect, false);
}

//
// Set the text for this gadget
//
void
TTextGadget::SetText(const char* text)
{
  //
  // Skip processing if new text is similar to current
  //
  if (text && Text && !strcmp(text, Text))
    return;

  //
  // Skip processing if matching pointers [eg. g->SetText(g->GetText()),
  // or g->SetText(0) when current text is already null].
  // NOTE: This is safe as long as 'Text' is always a strnewduped string
  //       and not simply a pointer to a user supplied buffer. Derived 
  //       classes must follow the convention of always setting
  //       'Text' via SetText.
  //
  if (text == Text) 
    return;

  delete [] Text;
  Text = 0;
  TextLen = 0;

  if (text) {
    Text = strnewdup(text);
    TextLen = strlen(Text);
  }

  Invalidate();
}

uint
TTextGadget::GetMaxCharWidth()
{
  TScreenDC   dc;
  TEXTMETRIC  metrics;

  dc.SelectObject(Window->GetFont());
  dc.GetTextMetrics(metrics);
  return (metrics.tmMaxCharWidth + metrics.tmAveCharWidth) / 2;
}

void
TTextGadget::GetDesiredSize(TSize& size)
{
  TGadget::GetDesiredSize(size);

  if (ShrinkWrapWidth)
    size.cx += GetMaxCharWidth() * NumChars;

  if (ShrinkWrapHeight)
    size.cy += Window->GetFontHeight();
}

//
// Paint the text gadget by painting gadget borders, & then painting text in
// the InnerRect. Empty or 0 text blanks the gadget.
//
void
TTextGadget::Paint(TDC& dc)
{
  PaintBorder(dc);

  TRect  innerRect;
  GetInnerRect(innerRect);
  int x = innerRect.left;
  int y = innerRect.top;

  //
  // adjust the horizontal position for centered or right justified text
  //
  if (Text && TextLen && Align != Left) {
    TSize  extent = dc.GetTextExtent(Text, TextLen);

    if (extent.cx < innerRect.Width()) {
      int  diff = innerRect.Width() - extent.cx;

      if (Align == Center)
        diff /= 2;

      x += diff;
    }
  }

  //
  // use ExtTextOut() to paint the text & background rectangle
  //
  dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
  dc.SetTextColor(GetSysColor(COLOR_BTNTEXT));
  dc.ExtTextOut(x, y, ETO_CLIPPED | ETO_OPAQUE, &innerRect, Text, TextLen);
}
