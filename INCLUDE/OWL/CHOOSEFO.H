//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\choosefo.h
//   Definition of Choose Font Common Dialog class
//----------------------------------------------------------------------------
#if !defined(__OWL_CHOOSEFO_H)
#define __OWL_CHOOSEFO_H

#if !defined(__COMMDIAL_H)
  #include <owl\commdial.h>
#endif
#if !defined(__COLOR_H)
  #include <owl\color.h>
#endif

class _OWLCLASS TChooseFontDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        DWORD        Flags;
        DWORD        Error;
        HDC          DC;
        LOGFONT      LogFont;
        int          PointSize;
        TColor       Color;
        char far*    Style;
        WORD         FontType;
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
    BOOL    DialogFunction(UINT message, WPARAM, LPARAM);

    // Default behavior inline for message response functions
    //
    void    CmFontApply() {DefaultProcessing();}   // EV_COMMAND(psh3...

  private:
    TChooseFontDialog(const TChooseFontDialog&);
    TChooseFontDialog& operator=(const TChooseFontDialog&);

  DECLARE_RESPONSE_TABLE(TChooseFontDialog);
  DECLARE_CASTABLE;
};

#endif  // __OWL_CHOOSEFO_H
