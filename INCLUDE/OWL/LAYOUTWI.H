//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Declarations of classes TLayoutMetrics & TLayoutWindow
//----------------------------------------------------------------------------
#if !defined(OWL_LAYOUTWI_H)
#define OWL_LAYOUTWI_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_LAYOUTCO_H)
# include <owl/layoutco.h>
#endif

//
//  class TLayoutMetrics
//  ----- --------------
//
//  when specifying the layout metrics for a window you specify four layout
//  constraints
//
class _OWLCLASS TLayoutMetrics {
  public:
    TEdgeConstraint         X;      // Horz1 can be lmLeft, lmCenter, lmRight
    TEdgeConstraint         Y;      // Vert1 can be lmTop, lmCenter, lmBottom
    TEdgeOrWidthConstraint  Width;  // Horz2 can be lmWidth, lmCenter, lmRight
    TEdgeOrHeightConstraint Height; // Vert2 can be lmHeight, lmCenter, lmBottom

    //
    // defaults each co: RelWin=0, MyEdge=(1st from above), Relationship=AsIs
    //
    TLayoutMetrics();
  
    void SetMeasurementUnits(TMeasurementUnits units);
};

//
// private structs used by TLayoutWindow
//
struct TChildMetrics;
struct TConstraint;
struct TVariable;

//
//  class TLayoutWindow
//  ----- -------------
//
// when specifying the layout metrics for a window, there are several options:
//   e.g. in the horizontal direction,
//
//   Two Edge Constraints in X and Width
//    1. left edge and right edge
//    2. center edge and right edge
//    3. left edge and center edge
//
//   Edge Constraint and Size constraint in X and Width
//    4. left edge and size
//    5. right edge and size
//    6. center edge and size
//
// the same holds true in the vertical direction for Y and Height
//
// it is also possible to specify "lmAsIs" in which case we use the windows
// current value
//
// specifying "lmAbsolute" means that we will use whatever is in data member
// "Value"
//
// we just name the fields "X" and "Width" and "Y" and "Height",
// although its okay to place a right or center edge constraint in the
// "Width" field and its also okay to place a right edge constraint in
// the "X" field (i.e. option #3)
//
// however, it's NOT okay to place a width constraint in the "X" or
// "Height" fields or a height constraint in the "Y" or "Width" fields.
//
class _OWLCLASS TLayoutWindow : virtual public TWindow {
  public:
    TLayoutWindow(TWindow*        parent,
                  const char far* title = 0,
                  TModule*        module = 0);

   ~TLayoutWindow();

    //
    // causes the receiver to size/position its children according to the
    // specified layout metrics
    //
    // if you change the layout metrics for a child window call Layout()
    // to have the changes take effect
    //
    void            Layout();

    void            SetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics);
    bool            GetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics);
    bool            RemoveChildLayoutMetrics(TWindow& child);

  protected:
    TSize           ClientSize;

    //
    // responds to a change in size by calling Layout()
    //
    void            EvSize(uint sizeType, TSize& size);

    //
    // Override TWindow virtuals
    //
    void            RemoveChild(TWindow* child);

  private:
    enum TWhichConstraint {XConstraint,     YConstraint,
                           WidthConstraint, HeightConstraint};

    TChildMetrics*  ChildMetrics;
    TConstraint*    Constraints;
    TConstraint*    Plan;
    TVariable*      Variables;
    bool            PlanIsDirty;
    int             NumChildMetrics;
    int             FontHeight;

    TChildMetrics*  GetChildMetrics(TWindow& child);

    void            AddConstraint(TChildMetrics&     metrics,
                                  TLayoutConstraint* c,
                                  TWhichConstraint   whichContraint);
    void            BuildConstraints(TChildMetrics& childMetrics);
    void            RemoveConstraints(TChildMetrics& childMetrics);

    void            BuildPlan();
    void            ExecutePlan();
    void            ClearPlan();

    int             LayoutUnitsToPixels(int);
    void            GetFontHeight();

    //
    // hidden to prevent accidental copying or assignment
    //
    TLayoutWindow(const TLayoutWindow&);
    TLayoutWindow& operator =(const TLayoutWindow&);

  DECLARE_RESPONSE_TABLE(TLayoutWindow);
  DECLARE_CASTABLE;
};

#endif  // OWL_LAYOUTWIN_H
