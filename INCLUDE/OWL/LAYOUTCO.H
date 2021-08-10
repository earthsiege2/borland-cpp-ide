//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\layoutco.h
//   Declaration of class TLayoutConstraint.
//----------------------------------------------------------------------------
#if !defined(__OWL_LAYOUTCO_H)
#define __OWL_LAYOUTCO_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
class _OWLCLASS TWindow;

#define lmParent    0

enum TEdge {lmLeft, lmTop, lmRight, lmBottom, lmCenter};
enum TWidthHeight {lmWidth = lmCenter + 1, lmHeight};

enum TMeasurementUnits {lmPixels, lmLayoutUnits};

enum TRelationship {lmAsIs      = 0,
                    lmPercentOf = 1,
                    lmAbove     = 2, lmLeftOf = lmAbove,
                    lmBelow     = 3, lmRightOf = lmBelow,
                    lmSameAs    = 4,
                    lmAbsolute  = 5};

//
//  struct TLayoutConstraint
//  ------ -----------------
//
//  layout constraints are specified as a relationship between an edge/size
//  of one window and an edge/size of one of the window's siblings or parent
//
//  it is acceptable for a window to have one of its sizes depend on the
//  size of the opposite dimension (e.g. width is twice height)
//
//  distances can be specified in either pixels or layout units
//
//  a layout unit is defined by dividing the font "em" quad into 8 vertical
//  and 8 horizontal segments. we get the font by self-sending WM_GETFONT
//  (we use the system font if WM_GETFONT returns 0)
//
//  "lmAbove", "lmBelow", "lmLeftOf", and "lmRightOf" are only used with edge
//  constraints. they place the window 1 pixel to the indicated side(i.e.
//  adjacent to the other window) and then adjust it by "Margin"(e.g. above
//  window "A" by 6)
//
//  NOTE: "Margin" is either added to ("lmAbove" and "lmLeftOf") or subtracted
//        from("lmBelow" and "lmRightOf") depending on the relationship
//
//  "lmSameAs" can be used with either edges or sizes, and it doesn't offset
//  by 1 pixel like the above four relationships did. it also uses "Value"
//  (e.g. same width as window "A" plus 10)
//
//  NOTE: "Value" is always *added*. use a negative number if you want the
//        effect to be subtractive
//
struct TLayoutConstraint {
  TWindow*           RelWin;            // relative window, lmParent for parent

  UINT               MyEdge       : 4;  // edge or size (width/height)
  TRelationship      Relationship : 4;
  TMeasurementUnits  Units        : 4;
  UINT               OtherEdge    : 4;  // edge or size (width/height)

  //
  // this union is just for naming convenience
  //
  union {
    int  Margin;   // used for "lmAbove", "lmBelow", "lmLeftOf", "lmRightOf"
    int  Value;    // used for "lmSameAs" and "lmAbsolute"
    int  Percent;  // used for "lmPercentOf"
  };
};

//
//  struct TEdgeConstraint
//  ------ ---------------
//
//  adds member functions for setting edge constraints
//
struct TEdgeConstraint : public TLayoutConstraint {
  //
  // for setting arbitrary edge constraints. use it like this:
  //   metrics->X.Set(lmLeft, lmRightOf, lmParent, lmLeft, 10);
  //
  void    Set(TEdge edge,      TRelationship rel, TWindow* otherWin,
              TEdge otherEdge, int value = 0)
            {RelWin = otherWin; MyEdge = edge; Relationship = rel;
             OtherEdge = otherEdge; Value = value;}

  //
  // these four member functions can be used to position your window with
  // respective to a sibling window. you specify the sibling window and an
  // optional margin between the two windows
  //
  void    LeftOf(TWindow* sibling, int margin = 0)
            {Set(lmRight, lmLeftOf, sibling, lmLeft, margin);}
  void    RightOf(TWindow* sibling, int margin = 0)
            {Set(lmLeft, lmRightOf, sibling, lmRight, margin);}
  void    Above(TWindow* sibling, int margin = 0)
            {Set(lmBottom, lmAbove, sibling, lmTop, margin);}
  void    Below(TWindow* sibling, int margin = 0)
            {Set(lmTop, lmBelow, sibling, lmBottom, margin);}

  //
  // these two work on the same edge, e.g. "SameAs(win, lmLeft)" means
  // that your left edge should be the same as the left edge of "otherWin"
  //
  void    SameAs(TWindow* otherWin, TEdge edge)
            {Set(edge, lmSameAs, otherWin, edge, 0);}
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent)
            {Set(edge, lmPercentOf, otherWin, edge, percent);}

  //
  // setting an edge to a fixed value
  //
  void    Absolute(TEdge edge, int value)
            {MyEdge = edge; Value = value; Relationship = lmAbsolute;}
};

//
//  struct TEdgeOrSizeConstraint
//  ------ ---------------------
//
template<int widthOrHeight>
struct TEdgeOrSizeConstraint : public TEdgeConstraint {
  //
  // percent of another window's width/height (defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width 50%
  // of my parent's height)
  //
  void    PercentOf(TWindow*     otherWin,
                    int          percent,
                    TWidthHeight otherWidthHeight = widthOrHeight)
            {RelWin = otherWin; MyEdge = widthOrHeight;
             Relationship = lmPercentOf; OtherEdge = otherWidthHeight;
             Percent = percent;}

  //
  // same as another window's width/height(defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width
  // the same as my height)
  //
  void    SameAs(TWindow*     otherWin,
                 TWidthHeight otherWidthHeight = widthOrHeight,
                 int          value = 0)
            {RelWin = otherWin; MyEdge = widthOrHeight;
             Relationship = lmSameAs; OtherEdge = otherWidthHeight;
             Value = value;}

  //
  // setting a width/height to a fixed value
  //
  void    Absolute(int value)
            {MyEdge = widthOrHeight; Value = value; Relationship = lmAbsolute;}

  //
  // redefine member functions defined by TEdgeConstraint that are hidden by
  // TEdgeOrSizeConstraint
  //
  void    Absolute(TEdge edge, int value)
            {TEdgeConstraint::Absolute(edge, value);}
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent)
            {TEdgeConstraint::PercentOf(otherWin, edge, percent);}
  void    SameAs(TWindow* otherWin, TEdge edge)
            {TEdgeConstraint::SameAs(otherWin, edge);}
};

typedef TEdgeOrSizeConstraint<lmWidth>   TEdgeOrWidthConstraint;
typedef TEdgeOrSizeConstraint<lmHeight>  TEdgeOrHeightConstraint;

#endif  // __OWL_LAYOUTCO_H
