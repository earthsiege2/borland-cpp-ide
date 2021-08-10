//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TMessageBar.
//----------------------------------------------------------------------------
#if !defined(OWL_MESSAGEB_H)
#define OWL_MESSAGEB_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

const int IDW_STATUSBAR     = 32040;  // Window ID used to locate status bars

//
// class TMessageBar
// ~~~~~ ~~~~~~~~~~~
// Implements a message bar with one text gadget as wide as the window and no
// border. positions itself at the bottom of the window and uses the default
// decoration bar font
//
// The message bar optionally draws a highlight line at the top
//
class _OWLCLASS TMessageBar : public TGadgetWindow {
  public:
    TMessageBar(TWindow*   parent = 0,
                TFont*     font = new TGadgetWindowFont,
                TModule*   module = 0);
   ~TMessageBar();

    // Set the text for the default text message gadget or a text gadget by id
    //
    void    SetText(const char* text);
    void    SetMessageText(int id, const char* text);

    // Set (or clear if 0) menu/command item hint text displayed in/on bar
    //
    virtual void    SetHintText(const char* text);

  protected:
    // Compensate for highlight line
    //
    void   GetInnerRect(TRect& rect);
    void   GetDesiredSize(TSize& rect);

    // Draw highlight line, then HintText if any, or gadgets
    //
    void   PaintGadgets(TDC& dc, bool erase, TRect& rect);

    bool   GetHighlightLine() const;
    void   SetHighlightLine(bool highlightline);

    const char*  GetHintText() const;

  protected_data:
    bool   HighlightLine;  // does this bar have a upper highlight line?
    char*  HintText;       // current command hint being displayed, if any

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TMessageBar(const TMessageBar&);
    TMessageBar& operator =(const TMessageBar&);

  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Returns true if the message bar has an upper highlight line.
//
inline bool TMessageBar::GetHighlightLine() const {
  return HighlightLine;
}

//
// Sets the flag for the message bar to have an upper highlight line.
//
inline void TMessageBar::SetHighlightLine(bool highlightline) {
  HighlightLine = highlightline;
}

//
// Return the cached hint text for the current message.
//
inline const char* TMessageBar::GetHintText() const {
  return HintText;
}


#endif  // OWL_MESSAGEB_H
