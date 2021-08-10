//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition TMenuGadget class
//----------------------------------------------------------------------------
#if !defined(OWL_MENUGADGET_H)
#define OWL_MENUGADGET_H

#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TMenuGadget
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TMenuGadget : public TTextGadget {
  public:
    TMenuGadget(TMenu& menu, TWindow* window, int id = 0,
                TBorderStyle borderStyle = TGadget::ButtonUp,
                char far* text = 0, TFont* font = new TGadgetWindowFont);
   ~TMenuGadget();

    // Override from TGadget
    //
    void LButtonDown(uint modKeys, TPoint& p);

  private:
    TPopupMenu* PopupMenu;
    TWindow*    CmdTarget;
};


// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_MENUGADGET_H
