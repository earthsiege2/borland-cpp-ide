//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of class TMessageBar.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_MESSAGEB_H)
# include <owl/messageb.h>
#endif
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

OWL_DIAGINFO;

IMPLEMENT_CASTABLE1(TMessageBar, TGadgetWindow);

//
// Construct a message bar with a given font.
//
TMessageBar::TMessageBar(TWindow*   parent,
                         TFont*     font,
                         TModule*   module)
:
  TGadgetWindow(parent, Horizontal, font, module)
{
  TTextGadget*  textGadget = new TTextGadget(IDG_MESSAGE, TTextGadget::Recessed,
                             TTextGadget::Left, 10, 0, 0);

  Attr.Id = IDW_STATUSBAR;

  // 3d UI will bevel the client's inner edge, so we dont need the hilight
  //
  HighlightLine = !(TSystem::Has3dUI());

  HintText = 0;
  textGadget->WideAsPossible = true;
  Insert(*textGadget);
}

//
// Destruct this message bar and cleanup text allocated
//
TMessageBar::~TMessageBar()
{
  delete[] HintText;
}

//
// Paint the gadgets in this messagebar. Paints highlight line if enabled, and
// handles painting hint text over the gadgets if text is currently set.
//
void
TMessageBar::PaintGadgets(TDC& dc, bool erase, TRect& rect)
{
  if (HighlightLine && rect.top == 0)
    dc.TextRect(0, 0, rect.right, TUIMetric::CyBorder, TColor::Sys3dHilight);

  if (HintText) {
    TRect  clientRect = GetClientRect();
    int    y = (clientRect.bottom - GetFontHeight()) / 2;

    if (HighlightLine)
      clientRect.top += TUIMetric::CyBorder;
    dc.SelectObject(GetFont());
    dc.SetBkColor(TColor::Sys3dFace);
    dc.ExtTextOut(5, y, ETO_OPAQUE, &clientRect, HintText, strlen(HintText));
  }
  else {
    TGadgetWindow::PaintGadgets(dc, erase, rect);
  }
}

//
// Get the inner rect for this message bar. Adjust for the top highlight line
// if one is set.
//
void
TMessageBar::GetInnerRect(TRect& innerRect)
{
  TGadgetWindow::GetInnerRect(innerRect);

  if (HighlightLine)
    innerRect.top += TUIMetric::CyBorder;
}

//
// Get the desired size for this message bar. Adjust for the top highlight line
// if one is set.
//
void
TMessageBar::GetDesiredSize(TSize& size)
{
  TGadgetWindow::GetDesiredSize(size);

  if (HighlightLine)
    size.cy++;
}

//
// Set the text for the message bar by puting it in the message text gadget
//
void
TMessageBar::SetText(const char* text)
{
  SetMessageText(IDG_MESSAGE, text);
}

//
// Set the text for the text gadget with a given ID
//
void
TMessageBar::SetMessageText(int id, const char* text)
{
  TTextGadget* tg = TYPESAFE_DOWNCAST(GadgetWithId(id), TTextGadget);
  if (tg)
    tg->SetText(text);
}

//
// Sets or clears menu/command hint text that is displayed over all the gadgets
// Pass 0 to clear the text. Causes a repaint.
//
void
TMessageBar::SetHintText(const char* text)
{
  if (text != HintText) {
    delete[] HintText;
    HintText = text ? strnewdup(text) : 0;
    Invalidate();
  }
}
