//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\gadget.h
//   Base class TGadget and helper class TSeparatorGadget.
//----------------------------------------------------------------------------
#if !defined(__OWL_GADGET_H)
#define __OWL_GADGET_H

#if !defined(__OWL_WINDOW_H)
  #include "owl\window.h"
#endif
#if !defined(__OWL_DC_H)
  #include "owl\dc.h"
#endif

class _OWLCLASS TGadgetWindow;

//
//  struct TMargins
//  ------ --------
//
//  Used by class TGadgetWindow and class TGadget.
//
struct TMargins {
  enum TUnits {Pixels, LayoutUnits, BorderUnits};

  TUnits  Units;

  int  Left   : 8;
  int  Right  : 8;
  int  Top    : 8;
  int  Bottom : 8;

  TMargins() {Units = LayoutUnits; Left = Right = Top = Bottom = 0;}
};

//
//  class TGadget
//  ----- -------
//
//  gadgets have borders and margins, belong to a gadget window, and have
//  their own coordinate system
//
//  margins are the same as for TGadgetWindow and borders are always in
//  border units
//
//  default behavior for gadgets is to shrink wrap to "fit" around their contents
//  you can control this by setting "ShrinkWrapWidth" and "ShrinkWrapHeight"
//
class _OWLCLASS TGadget {
  public:
    enum TBorderStyle {None, Plain, Raised, Recessed, Embossed};

    TGadget(int id = 0, TBorderStyle = None);
    virtual ~TGadget();

    struct TBorders {
      unsigned  Left   : 4;
      unsigned  Right  : 4;
      unsigned  Top    : 4;
      unsigned  Bottom : 4;

      TBorders() {Left = Right = Top = Bottom = 0;}
    };

    int            GetId () {return Id;}

    //
    // typically you would either choose a border style (which automatically
    // sets the individual border edges) or set the borders and then override
    // member function PaintBorder() to create a custom look
    //
    // NOTE: changing the borders, margins, or border style all end up invoking
    //       the gadget window's GadgetChangedSize() member function
    //
    void           SetBorders(TBorders& borders);
    TBorders      &GetBorders() {return Borders;}

    void           SetMargins(TMargins& margins);
    TMargins      &GetMargins() {return Margins;}

    void           SetBorderStyle(TBorderStyle);
    TBorderStyle   GetBorderStyle() {return BorderStyle;}

    TRect         &GetBounds() {return Bounds;}

    virtual void   SetEnabled(BOOL);
    BOOL           GetEnabled() {return Enabled;}

    //
    // simply sets the corresponding member data. call the gadget window's
    // GadgetChangedSize() member function if you want to affect a change in size
    //
    void           SetShrinkWrap(BOOL shrinkWrapWidth, BOOL shrinkWrapHeight);

    //
    // directly alters the size of the gadget. calls the gadget window's
    // GadgetChangedSize() member function for the size change to take affect
    //
    // you would only use this member function if you turned off shrink wrapping
    // in one or both dimension; otherwise the GetDesiredSize() member function
    // will return the fitted size which will be different
    //
    void           SetSize(TSize& size);

    //
    // message send by the gadget window to query the gadget's size.
    // if shrink wrapping was requested just returns the size needed to
    // accomodate the borders and margins; otherwise the current width/height
    // are returned
    //
    // if you requested "WideAsPossible" then "size.cx" is ignored
    //
    virtual void   GetDesiredSize(TSize& size);

    //
    // returns the amount of space in pixels taken up by the borders and margins
    //
    void           GetOuterSizes(int& left, int& right, int& top, int& bottom);

    //
    // sent by the gadget window to inform the gadget of a change in its
    // bounding rectangle. default behavior just updates instance variable
    // "Bounds" but derived classes might override this method to update
    // internal state
    //
    virtual void   SetBounds(TRect& rect);

    virtual void   CommandEnable();
    virtual void   SysColorChange();

    TGadget       *NextGadget() {return Next;}

  protected:
    //
    // Virtuals called after inserting into window & before removing to allow
    // gadget a change to initialize or clean up.
    //
    virtual void   Inserted();
    virtual void   Removed();
    
    void           Invalidate(BOOL erase = TRUE);
    void           InvalidateRect(const TRect& rect,  // receiver's coord system
                                  BOOL  erase = TRUE);
    void           Update();  // Paint now if possible

    //
    // default behavior returns TRUE if the point is within the receiver's
    // bounding rect. "point" is in the receiver's coordinate system
    //
    virtual BOOL   PtIn(TPoint& point);

    virtual void   Paint(TDC& dc);

    //
    // self sent by method Paint(). override this is if you want to
    // implement a border style that isn't supported
    //
    virtual void   PaintBorder(TDC& dc);

    //
    // computes the area excluding the borders and margins
    //
    void           GetInnerRect(TRect& rect);

    //
    // "point" is in the receiver's coordinate system. MouseMove is only 
    // called if the mouse is captured.
    //
    virtual void   MouseMove(UINT modKeys, TPoint& point);
    virtual void   MouseEnter(UINT modKeys, TPoint& point);
    virtual void   MouseLeave(UINT modKeys, TPoint& point);

    //
    // captures the mouse if "TrackMouse" is set. "point" is in the receiver's
    // coordinate system
    //
    virtual void   LButtonDown(UINT modKeys, TPoint& point);

    //
    // releases the mouse capture if "TrackMouse" is set. "point" is in the
    // receiver's coordinate system
    //
    virtual void   LButtonUp(UINT modKeys, TPoint& point);

  public:
    BOOL             Clip;            // FALSE
    BOOL             WideAsPossible;  // FALSE

  protected:
    TGadgetWindow*   Window;
    TRect            Bounds;
    TBorderStyle     BorderStyle;
    TBorders         Borders;
    TMargins         Margins;
    BOOL             ShrinkWrapWidth;
    BOOL             ShrinkWrapHeight;
    BOOL             TrackMouse;      // FALSE
    int              Id;

  private:
    TGadget*         Next;
    BOOL             Enabled;

    friend class _OWLCLASS TGadgetWindow;

    //
    // hidden to prevent accidental copying or assignment
    //
    TGadget(const TGadget&);
    TGadget& operator =(const TGadget&);
};

//
//  class TSeparatorGadget
//  ----- ----------------
//
//  simple helper class that you can use when you want a separator between
//  gadgets. you specify the size of the separator (in units of SM_CXBORDER
//  and SM_CYBORDER) and the separator disables itself and turns off shrink
//  wrapping
//
//  "size" is used for both the width and the height
//
class _OWLCLASS TSeparatorGadget : public TGadget {
  public:
    TSeparatorGadget(int size = 6);
};

#endif  // __OWL_GADGET_H
