//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of Choose Font Common Dialog class
//----------------------------------------------------------------------------
#if !defined(OWL_CHOOSEFO_H)
#define OWL_CHOOSEFO_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

class _WSYSCLASS TColor;

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif
  

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TChooseFontDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~
// Encapsulates the Choose-Font common dialog.
//
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
   ~TChooseFontDialog();

  protected:
    TData&  GetData();
    void    SetData(TData& data);

    CHOOSEFONT&   GetCF();
    void    SetCF(const CHOOSEFONT& cf);

    int     DoExecute();
    bool    DialogFunction(uint message, TParam1, TParam2);

    // Default behavior inline for message response functions
    //
    void    CmFontApply();   // EV_COMMAND(psh3...

  protected_data:
    union {
      CHOOSEFONT Cf;  // New name
      CHOOSEFONT cf;  // old name
    };
    TData&       Data;

  private:
    TChooseFontDialog(const TChooseFontDialog&);
    TChooseFontDialog& operator=(const TChooseFontDialog&);

  DECLARE_RESPONSE_TABLE(TChooseFontDialog);
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
// Return the data associated with this dialog.
//
inline TChooseFontDialog::TData& TChooseFontDialog::GetData() {
  return Data;
}

//
// Set the data associated with this dialog.
// Use this function with caution!
//
inline void TChooseFontDialog::SetData(TData& data) {
  Data = data;
}

//
// Return the CHOOSEFONT data structure for this dialog.
//
inline CHOOSEFONT& TChooseFontDialog::GetCF() {
  return Cf;
}

//
// Set the CHOOSEFONT data structure for this dialog.
//
inline void TChooseFontDialog::SetCF(const CHOOSEFONT& cf) {
  Cf = cf;
}

//
// User clicked on Apply for the font.
//
inline void TChooseFontDialog::CmFontApply() {
  DefaultProcessing();
}

#endif  // OWL_CHOOSEFO_H
