//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\messageb.h
//   Class TMessageBar.
//----------------------------------------------------------------------------
#if !defined(__OWL_MESSAGEB_H)
#define __OWL_MESSAGEB_H

#if !defined(__OWL_GADGETWI_H)
  #include "owl\gadgetwi.h"
#endif

const int IDW_STATUSBAR = 32000;

//
//  class TMessageBar
//  ----- -----------
//
//  implements a message bar with one text gadget as wide as the window and no
//  border. positions itself at the bottom of the window and uses the default
//  decoration bar font
//
//  the message bar optionally draws a highlight line at the top
//
class _OWLCLASS TMessageBar : public TGadgetWindow {
  public:
    TMessageBar(TWindow*   parent = 0,
                TFont*     font = new TGadgetWindowFont,
                TModule*   module = 0);
   ~TMessageBar();

    //
    // set the text for the text message gadget (the first gadget)
    //
    void    SetText(const char* text);

    //
    // set (or clear if 0) menu/command item hint text displayed in/on bar
    //
    virtual void    SetHintText(const char* text);

  protected:
    BOOL   HighlightLine;  // does this bar have a upper highlight line?
    char*  HintText;       // current command hint being displayed, if any

    //
    // compensate for highlight line
    //
    void   GetInnerRect(TRect& rect);
    void   GetDesiredSize(TSize& rect);

    //
    // draw highlight line, then HintText if any, or gadgets
    //
    void  PaintGadgets(TDC& dc, BOOL erase, TRect& rect);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMessageBar(const TMessageBar&);
    TMessageBar& operator =(const TMessageBar&);

  DECLARE_CASTABLE;
};

#endif  // __OWL_MESSAGEB_H
