//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of text gadget class TGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_TEXTGADG_H)
#define OWL_TEXTGADG_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TTextGadget
// ~~~~~ ~~~~~~~~~~~
// When constructing the text gadget specify how many characters you want
// room for and how the text should be aligned horizontally.
//
// The inner bounds are computed by multiplying the number of characters by
// the maximum character width.
//
class _OWLCLASS TTextGadget : public TGadget {
  public:
    enum TAlign {Left, Center, Right};

    TTextGadget(int id = 0, TBorderStyle = Recessed, TAlign = Left,
                uint numChars = 10, const char far* text = 0,
                TFont* font = 0 /*new TGadgetWindowFont*/);
   ~TTextGadget();

    const char far*   GetText() const;

    // Makes a copy of the text
    //
    void    SetText(const char far* text);

  protected:
    // Override virtual methods defined in TGadget
    //
    void    Paint(TDC& dc);
    void    GetDesiredSize(TSize &size);
    void    Invalidate();

  // Data members -- will become private
  //
  protected_data:
    char far* Text;       // new'd copy of the text for this gadget
    uint      TextLen;    // strlen of the above text
    TAlign    Align;      // Alignment: left, center or right
    uint      NumChars;   // Number of chars to reserve space for
    TFont*    Font;       // display font

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TTextGadget(const TTextGadget&);
    TTextGadget& operator =(const TTextGadget&);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementation
//

//
inline const char far* TTextGadget::GetText() const {
  return Text;
}

#endif  // OWL_TEXTGADG_H
