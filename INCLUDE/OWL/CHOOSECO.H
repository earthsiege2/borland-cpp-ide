//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of Choose Color Common Dialog class
//----------------------------------------------------------------------------
#if !defined(OWL_CHOOSECO_H)
#define OWL_CHOOSECO_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TChooseColorDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// Wrapper for the Choose-Color common dialog.
//
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
   ~TChooseColorDialog();

    // Set the current RGB color in this dialog
    //
    void    SetRGBColor(const TColor& color);

  protected:
    TData&  GetData();
    void    SetData(TData& data);

    CHOOSECOLOR&  GetCC();
    void   SetCC(const CHOOSECOLOR& cc);

    int     DoExecute();
    bool    DialogFunction(uint message, TParam1, TParam2);

    // Default behavior inline for message response functions
    //
    TParam2  EvSetRGBColor(TParam1, TParam2);      // EV_REGISTERED(SETRGBSTRING,

    // Registered messages this class sends (to itself)
    //
    static uint SetRGBMsgId;

  protected_data:
    union {
      CHOOSECOLOR  Cc;  // New name
      CHOOSECOLOR  cc;  // Old name
    };
    TData&       Data;

  private:
    TChooseColorDialog(const TChooseColorDialog&);
    TChooseColorDialog& operator=(const TChooseColorDialog&);

  DECLARE_RESPONSE_TABLE(TChooseColorDialog);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Set the current selection to a specific RGB color.
//
inline void TChooseColorDialog::SetRGBColor(const TColor& color) {
  SendMessage(SetRGBMsgId, 0, color);
}

//
// Return the data object for this common dialog.
//
inline TChooseColorDialog::TData& TChooseColorDialog::GetData() {
  return Data;
}

//
// Set the data for this common dialog.
// Use this function with caution!
//
inline void TChooseColorDialog::SetData(TData& data) {
  Data = data;
}

//
// Return the CHOOSECOLOR data structure for this dialog.
//
inline CHOOSECOLOR& TChooseColorDialog::GetCC() {
  return Cc;
}

//
// Set the CHOOSECOLOR data structure for this dialog.
// Use this function with caution!
//
inline void TChooseColorDialog::SetCC(const CHOOSECOLOR& cc) {
  Cc = cc;
}

//
// The user has clicked on a color.
//
inline TParam2 TChooseColorDialog::EvSetRGBColor(TParam1, TParam2) {
  return DefaultProcessing();
}

#endif  // OWL_CHOOSECO_H
