//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Class TControlBar.
//----------------------------------------------------------------------------
#if !defined(OWL_CONTROLB_H)
#define OWL_CONTROLB_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
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

    bool    PreProcessMsg(MSG& msg);

  protected:
    void    PositionGadget(TGadget* previous, TGadget* next, TPoint& p);

  DECLARE_CASTABLE;
};

#endif  // OWL_CONTROLB_H
