//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Class TControlGadget definition
//----------------------------------------------------------------------------
#if !defined(OWL_CONTROLG_H)
#define OWL_CONTROLG_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
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

    void           Invalidate(bool erase = true);
    void           InvalidateRect(const TRect& rect, // receiver's coord system
                                  bool  erase = true);
    void           Update();  // Paint now if possible

    void           SetBounds(TRect& rect);

    //
    // computes the area excluding the borders and margins
    //
    void           GetInnerRect(TRect& rect);

    void           GetDesiredSize(TSize& size);

  protected:
    TWindow*       Control;

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TControlGadget(const TControlGadget&);
    TControlGadget& operator =(const TControlGadget&);
};

#endif  // OWL_CONTROLG_H
