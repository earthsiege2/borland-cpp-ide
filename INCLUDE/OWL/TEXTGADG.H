//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of text gadget class TGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_TEXTGADG_H)
#define OWL_TEXTGADG_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif

//
//  class TTextGadget
//  ----- -----------
//
//  when constructing the text gadget specify how many characters you want
//  room for and how the text should be aligned horizontally
//
//  the inner bounds are computed by multiplying the number of characters by
//  the maximum character width
//
class _OWLCLASS TTextGadget : public TGadget {
  public:
    enum TAlign {Left, Center, Right};

    TTextGadget(int id = 0, TBorderStyle = Recessed, TAlign = Left, uint numChars = 10, const char* text = 0);
   ~TTextGadget();

    const char*   GetText() const {return Text;}

    //
    // makes a copy of the text
    //
    void    SetText(const char *text);

  protected:
    //
    // override virtual methods defined in TGadget
    //
    void    Paint(TDC& dc);
    void    GetDesiredSize(TSize &size);
    void    Invalidate();

  private:
    uint    GetMaxCharWidth();

  protected:
    char*    Text;
    uint     TextLen;
    TAlign   Align;
    uint     NumChars;

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TTextGadget(const TTextGadget&);
    TTextGadget& operator =(const TTextGadget&);
};

#endif  // OWL_TEXTGADG_H
