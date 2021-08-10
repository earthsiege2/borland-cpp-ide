//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Class TControlGadget definition. TControlGadget is a gadget that takes a
// TWindow and allows it to be inserted into a gadget window. In effect it is
// an adapter that allows arbitrary controls to be used like gadgets in a tool
// bar, status bar, etc.
//----------------------------------------------------------------------------
#if !defined(OWL_CONTROLG_H)
#define OWL_CONTROLG_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TControlGadget
// ~~~~~ ~~~~~~~~~~~~~~
class _OWLCLASS TControlGadget : public TGadget {
  public:
    TControlGadget(TWindow& control, TBorderStyle = None);
   ~TControlGadget();

  protected:
    void           Created();
    void           Inserted();
    void           Removed();

    void           InvalidateRect(const TRect& rect, bool erase = true);
    void           Update();  // Paint now if possible

    void           SetBounds(const TRect& rect);

    // Computes the area excluding the borders and margins
    //
    void           GetInnerRect(TRect& rect);

    void           GetDesiredSize(TSize& size);

    TWindow*       GetControl() const;
    void           SetControl(TWindow* control);

  protected_data:
    TWindow*       Control;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TControlGadget(const TControlGadget&);
    TControlGadget& operator =(const TControlGadget&);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline Implementations
//

//
// Return the control that is simulating a gadget.
//
inline TWindow* TControlGadget::GetControl() const {
  return Control;
}

//
// Set the control that is simulating a gadget.
//
inline void TControlGadget::SetControl(TWindow* control) {
  Control = control;
}

#endif  // OWL_CONTROLG_H
