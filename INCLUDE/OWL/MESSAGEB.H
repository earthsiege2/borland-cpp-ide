//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Class TMessageBar.
//----------------------------------------------------------------------------
#if !defined(OWL_MESSAGEB_H)
#define OWL_MESSAGEB_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

const int IDW_STATUSBAR     = 32040;  // Window ID used to locate status bars

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
    bool   HighlightLine;  // does this bar have a upper highlight line?
    char*  HintText;       // current command hint being displayed, if any

    //
    // compensate for highlight line
    //
    void   GetInnerRect(TRect& rect);
    void   GetDesiredSize(TSize& rect);

    //
    // draw highlight line, then HintText if any, or gadgets
    //
    void  PaintGadgets(TDC& dc, bool erase, TRect& rect);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMessageBar(const TMessageBar&);
    TMessageBar& operator =(const TMessageBar&);

  DECLARE_CASTABLE;
};

#endif  // OWL_MESSAGEB_H
