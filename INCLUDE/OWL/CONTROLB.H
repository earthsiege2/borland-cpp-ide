//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of class TControlBar.
//----------------------------------------------------------------------------
#if !defined(OWL_CONTROLB_H)
#define OWL_CONTROLB_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TControlBar
// ~~~~~ ~~~~~~~~~~~
// Implements a control bar which provides mnemonic access for its button
// gadgets. By default positions itself at the top of the window
//
class _OWLCLASS TControlBar : public TGadgetWindow {
  public:
    TControlBar(TWindow*        parent = 0,
                TTileDirection  direction= Horizontal,
                TFont*          font = new TGadgetWindowFont,
                TModule*        module = 0);
   ~TControlBar();

    bool    PreProcessMsg(MSG& msg);

  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_CONTROLB_H
