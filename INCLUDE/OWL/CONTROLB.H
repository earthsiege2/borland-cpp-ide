//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\controlb.h
//   Class TControlBar.
//----------------------------------------------------------------------------
#if !defined(__OWL_CONTROLB_H)
#define __OWL_CONTROLB_H

#if !defined(__OWL_GADGETWI_H)
  #include "owl\gadgetwi.h"
#endif

//
//  class TControlBar
//  ----- -----------
//
//  implements a control bar which provides mnemonic access for its button
//  gadgets. by default positions itself at the top of the window
//
class _OWLCLASS TControlBar : public TGadgetWindow {
  public:
    TControlBar(TWindow*        parent = 0,
                TTileDirection  direction= Horizontal,
                TFont*          font = new TGadgetWindowFont,
                TModule*        module = 0);

    BOOL    PreProcessMsg(MSG& msg);

  protected:
    void    PositionGadget(TGadget* previous, TGadget* next, TPoint& p);

  DECLARE_CASTABLE;
};

#endif  // __OWL_CONTROLB_H
