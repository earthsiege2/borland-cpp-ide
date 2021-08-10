//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of classes TLayoutMetrics & TLayoutWindow
//----------------------------------------------------------------------------
#if !defined(OWL_LAYOUTWI_H)
#define OWL_LAYOUTWI_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_LAYOUTCO_H)
# include <owl/layoutco.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TLayoutMetrics
// ~~~~~ ~~~~~~~~~~~~~~
// When specifying the layout metrics for a window, four layout constraints
// are needed.
//
class _OWLCLASS TLayoutMetrics {
  public:
    TEdgeConstraint         X;      // Horz1 can be lmLeft, lmCenter, lmRight
    TEdgeConstraint         Y;      // Vert1 can be lmTop, lmCenter, lmBottom
    TEdgeOrWidthConstraint  Width;  // Horz2 can be lmWidth, lmCenter, lmRight
    TEdgeOrHeightConstraint Height; // Vert2 can be lmHeight, lmCenter, lmBottom

    // Defaults each co: RelWin=0, MyEdge=(1st from above), Relationship=AsIs
    //
    TLayoutMetrics();
  
    void SetMeasurementUnits(TMeasurementUnits units);
};

//
// Private structs used by TLayoutWindow
//
struct TChildMetrics;
struct TConstraint;
struct TVariable;

//
// class TLayoutWindow
// ~~~~~ ~~~~~~~~~~~~~
// When specifying the layout metrics for a window, there are several options:
// e.g. in the horizontal direction,
//
//  Two Edge Constraints in X and Width
//   1. left edge and right edge
//   2. center edge and right edge
//   3. left edge and center edge
//
//  Edge Constraint and Size constraint in X and Width
//   4. left edge and size
//   5. right edge and size
//   6. center edge and size
//
// The same holds true in the vertical direction for Y and Height
//
// It is also possible to specify "lmAsIs" in which case we use the windows
// current value
//
// Specifying "lmAbsolute" means that we will use whatever is in data member
// "Value"
//
// We just name the fields "X" and "Width" and "Y" and "Height",
// although its okay to place a right or center edge constraint in the
// "Width" field and its also okay to place a right edge constraint in
// the "X" field (i.e. option #3)
//
// However, it's NOT okay to place a width constraint in the "X" or
// "Height" fields or a height constraint in the "Y" or "Width" fields.
//
class _OWLCLASS TLayoutWindow : virtual public TWindow {
  public:
    TLayoutWindow(TWindow*        parent,
                  const char far* title = 0,
                  TModule*        module = 0);

   ~TLayoutWindow();

    // Causes the receiver to size/position its children according to the
    // specified layout metrics
    //
    // If you change the layout metrics for a child window call Layout()
    // to have the changes take effect
    //
    virtual void    Layout();

    void            SetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics);
    bool            GetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics);
    bool            RemoveChildLayoutMetrics(TWindow& child);

  protected:
    // Responds to a change in size by calling Layout()
    //
    void            EvSize(uint sizeType, TSize& size);

    // Override TWindow virtual to allow cleanup of child metrics
    //
    void            RemoveChild(TWindow* child);

  protected_data:
    TSize           ClientSize;

  private:
    enum TWhichConstraint {
      XConstraint,
      YConstraint,
      WidthConstraint,
      HeightConstraint
    };

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

    // Hidden to prevent accidental copying or assignment
    //
    TLayoutWindow(const TLayoutWindow&);
    TLayoutWindow& operator =(const TLayoutWindow&);

  DECLARE_RESPONSE_TABLE(TLayoutWindow);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_LAYOUTWIN_H
