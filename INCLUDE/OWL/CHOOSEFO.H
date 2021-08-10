//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of Choose Font Common Dialog class
//----------------------------------------------------------------------------
#if !defined(OWL_CHOOSEFO_H)
#define OWL_CHOOSEFO_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(OWL_COLOR_H)
# include <owl/color.h>
#endif

class _OWLCLASS TChooseFontDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32       Flags;
        uint32       Error;
        HDC          DC;
        LOGFONT      LogFont;
        int          PointSize;
        TColor       Color;
        char far*    Style;
        uint16       FontType;
        int          SizeMin;
        int          SizeMax;                      
    };

    TChooseFontDialog(TWindow*        parent,
                      TData&          data,
                      TResId          templateId = 0,
                      const char far* title = 0,
                      TModule*        module = 0);

  protected:
    CHOOSEFONT   cf;
    TData&       Data;

    int     DoExecute();
    bool    DialogFunction(uint message, WPARAM, LPARAM);

    // Default behavior inline for message response functions
    //
    void    CmFontApply() {DefaultProcessing();}   // EV_COMMAND(psh3...

  private:
    TChooseFontDialog(const TChooseFontDialog&);
    TChooseFontDialog& operator=(const TChooseFontDialog&);

  DECLARE_RESPONSE_TABLE(TChooseFontDialog);
  DECLARE_CASTABLE;
};

#endif  // OWL_CHOOSEFO_H
