//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\controlg.h
//   Class TControlGadget definition
//----------------------------------------------------------------------------
#if !defined(__OWL_CONTROLG_H)
#define __OWL_CONTROLG_H

#if !defined(__OWL_GADGET_H)
  #include "owl\gadget.h"
#endif

//
//  class TControlGadget
//  ----- --------------
//
class _OWLCLASS TControlGadget : public TGadget {
  public:
    TControlGadget(TWindow& control, TBorderStyle = None);
   ~TControlGadget();

  protected:
    void           Inserted();
    void           Removed();

    void           Invalidate(BOOL erase = TRUE);
    void           InvalidateRect(const TRect& rect, // receiver's coord system
                                  BOOL  erase = TRUE);
    void           Update();  // Paint now if possible

    void           SetBounds(TRect& rect);

    //
    // computes the area excluding the borders and margins
    //
    void           GetInnerRect(TRect& rect);

    void           GetDesiredSize(TSize& size);

  protected:
    TWindow*         Control;

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TControlGadget(const TControlGadget&);
    TControlGadget& operator =(const TControlGadget&);
};

#endif  // __OWL_CONTROLG_H
