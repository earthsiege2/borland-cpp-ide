//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\chooseco.h
//   Definition of Choose Color Common Dialog class
//----------------------------------------------------------------------------
#if !defined(__OWL_CHOOSECO_H)
#define __OWL_CHOOSECO_H

#if !defined(__COMMDIAL_H)
  #include <owl\commdial.h>
#endif
#if !defined(__COLOR_H)
  #include <owl\color.h>
#endif

class _OWLCLASS TChooseColorDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        DWORD       Flags;
        DWORD       Error;
        TColor      Color;
        TColor*     CustColors;
    };

    TChooseColorDialog(TWindow*        parent,
                       TData&          data,
                       TResId          templateId = 0,
                       const char far* title = 0,
                       TModule*        module = 0);

    //
    // Set the current RGB color in this dialog
    //
    void    SetRGBColor(TColor color) {SendMessage(SetRGBMsgId,0,color);}

  protected:
    CHOOSECOLOR  cc;
    TData&       Data;

    int     DoExecute();
    BOOL    DialogFunction(UINT message, WPARAM, LPARAM);

    //
    // Registered messages this class sends (to itself)
    //
    static UINT SetRGBMsgId;

    //
    // Default behavior inline for message response functions
    //
    LPARAM  EvSetRGBColor(WPARAM, LPARAM)      // EV_REGISTERED(SETRGBSTRING,
             {return DefaultProcessing();}
    
  private:
    TChooseColorDialog(const TChooseColorDialog&);
    TChooseColorDialog& operator=(const TChooseColorDialog&);

  DECLARE_RESPONSE_TABLE(TChooseColorDialog);
  DECLARE_CASTABLE;
};

#endif  // __OWL_CHOOSECO_H
