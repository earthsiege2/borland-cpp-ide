//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of TTextGadget.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

OWL_DIAGINFO;

//
// Construct a text gadget
//
TTextGadget::TTextGadget(int          id,
                         TBorderStyle borderStyle,
                         TAlign       align,
                         uint         numChars,
                         const char far* text,
                         TFont*       font)
:
  TGadget(id, borderStyle),
  Font(font)
{
  Margins.Left = Margins.Right = TUIMetric::CxFixedFrame;
  Align = align;
  NumChars = numChars;
  Text = 0;
  TextLen = 0;

  SetShrinkWrap(false, true);
  SetText(text);
}

//
// Destruct this text gadget and delete the text it is holding
//
TTextGadget::~TTextGadget()
{
  delete[] Text;
  delete Font;
}

//
// Invalidate the working portion of this gadget--in this case just the
// InnerRect
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
TTextGadget::SetText(const char far* text)
{
  // Skip processing if new text is the same as current
  //
  if (text && Text && strcmp(text, Text) == 0)
    return;

  delete[] Text;

  if (text) {
    Text = strnewdup(text);
    TextLen = strlen(Text);
  }
  else {
    Text = 0;
    TextLen = 0;
  }

  if (Window)
    Window->GadgetChangedSize(*this);

  Invalidate();
}

//
// Respond to the virtual call to let this gadget's Window know how big this
// text gadget wants to be based on the text size.
//
void
TTextGadget::GetDesiredSize(TSize& size)
{
  TGadget::GetDesiredSize(size);
  TFont* font = Font;
  if (font == 0)
    font = &(Window->GetFont());

  if (font == 0)
    return;

  if (ShrinkWrapWidth)
    size.cx += font->GetTextExtent(Text).cx;
  else {
    int  left, right, top, bottom;
    GetOuterSizes(left, right, top, bottom);

    int newW = font->GetMaxWidth() * NumChars;
    size.cx += newW + left + right - Bounds.Width();  // Old bounds already considered
  }

  if (ShrinkWrapHeight)
    size.cy += font->GetHeight() + 2;
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

  if (Font == 0)
    dc.SelectObject(Window->GetFont());
  else
    dc.SelectObject(*Font);

  // Adjust the horizontal position for centered or right justified text
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

  // Use ExtTextOut() to paint the text & background rectangle
  //
  dc.SetBkColor(TColor::Sys3dFace);
  dc.SetTextColor(GetEnabled() ? TColor::SysBtnText : TColor::SysGrayText);
  dc.ExtTextOut(x, y, ETO_CLIPPED | ETO_OPAQUE, &innerRect, Text, TextLen);
  dc.RestoreFont();
}
