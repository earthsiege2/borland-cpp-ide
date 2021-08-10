//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of mode-tracking text gadget class TModeGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_MODEGAD_H)
#define OWL_MODEGAD_H

#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TModeGadget
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TModeGadget : public TTextGadget {
  public:
    TModeGadget(int vkKey, const char far* text, int id = 0,
                TBorderStyle = Recessed, TAlign = Center,
                TFont* font = 0 /*new TGadgetWindowFont*/);

    // Override from TGadget
    //
    bool IdleAction(long count);

  private:
    int VkKey;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif // OWL_MODEGAD_H
