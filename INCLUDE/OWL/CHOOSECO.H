//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of Choose Color Common Dialog class
//----------------------------------------------------------------------------
#if !defined(OWL_CHOOSECO_H)
#define OWL_CHOOSECO_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(OWL_COLOR_H)
# include <owl/color.h>
#endif

class _OWLCLASS TChooseColorDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32      Flags;
        uint32      Error;
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
    bool    DialogFunction(uint message, WPARAM, LPARAM);

    //
    // Registered messages this class sends (to itself)
    //
    static uint SetRGBMsgId;

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

#endif  // OWL_CHOOSECO_H
