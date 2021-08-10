//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TMessageBar.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/messageb.h>
#include <owl/textgadg.h>

TMessageBar::TMessageBar(TWindow*   parent,
                         TFont*     font,
                         TModule*   module)
:
  TGadgetWindow(parent, Horizontal, font, module)
{
  TTextGadget*  textGadget = new TTextGadget(TGadget::None);

  Attr.Id = IDW_STATUSBAR;
  HighlightLine = true;
  HintText = 0;
  textGadget->WideAsPossible = true;
  Insert(*textGadget);
}

TMessageBar::~TMessageBar()
{
  delete [] HintText;
}

void
TMessageBar::PaintGadgets(TDC& dc, bool erase, TRect& rect)
{
  if (HighlightLine && rect.top == 0)
    dc.TextRect(0, 0, rect.right, GetSystemMetrics(SM_CYBORDER),
                GetSysColor(COLOR_BTNHIGHLIGHT));

  if (HintText) {
    TRect  clientRect = GetClientRect();
    int    y = (clientRect.bottom - GetFontHeight()) / 2;

    if (HighlightLine)
      clientRect.top += GetSystemMetrics(SM_CYBORDER);
    dc.SelectObject(GetFont());
    dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
    dc.ExtTextOut(5, y, ETO_OPAQUE, &clientRect, HintText, strlen(HintText));
  }
  else {
    TGadgetWindow::PaintGadgets(dc, erase, rect);
  }
}

void
TMessageBar::GetInnerRect(TRect& innerRect)
{
  TGadgetWindow::GetInnerRect(innerRect);

  if (HighlightLine)
    innerRect.top += GetSystemMetrics(SM_CYBORDER);
}

void
TMessageBar::GetDesiredSize(TSize& size)
{
  TGadgetWindow::GetDesiredSize(size);

  if (HighlightLine)
    size.cy++;
}

void
TMessageBar::SetText(const char* text)
{
  //
  // forward the message to the text gadget
  //
  ((TTextGadget*)Gadgets)->SetText(text);
}

//
// sets or clears menu/command hint text over all the gadgets
//
void
TMessageBar::SetHintText(const char* text)
{
  if (text != HintText) {
    delete [] HintText;
    HintText = text ? strnewdup(text) : 0;
    Invalidate();
  }
}
