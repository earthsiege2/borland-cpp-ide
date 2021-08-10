//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of class TLayoutConstraint.
//----------------------------------------------------------------------------
#if !defined(OWL_LAYOUTCO_H)
#define OWL_LAYOUTCO_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TWindow;

//
// Use to represent the parent in layout metrics
//
#define lmParent    0

enum TEdge {lmLeft, lmTop, lmRight, lmBottom, lmCenter};

enum TWidthHeight {lmWidth = lmCenter + 1, lmHeight};

enum TMeasurementUnits {lmPixels, lmLayoutUnits};

enum TRelationship {
  lmAsIs      = 0,
  lmPercentOf = 1,
  lmAbove     = 2, lmLeftOf = lmAbove,
  lmBelow     = 3, lmRightOf = lmBelow,
  lmSameAs    = 4,
  lmAbsolute  = 5
};

//
// struct TLayoutConstraint
// ~~~~~~ ~~~~~~~~~~~~~~~~~
// Layout constraints are specified as a relationship between an edge/size
// of one window and an edge/size of one of the window's siblings or parent
//
// It is acceptable for a window to have one of its sizes depend on the
// size of the opposite dimension (e.g. width is twice height)
//
// Distances can be specified in either pixels or layout units
//
// A layout unit is defined by dividing the font "em" quad into 8 vertical
// and 8 horizontal segments. we get the font by self-sending WM_GETFONT
// (we use the system font if WM_GETFONT returns 0)
//
// "lmAbove", "lmBelow", "lmLeftOf", and "lmRightOf" are only used with edge
// constraints. They place the window 1 pixel to the indicated side (i.e.
// adjacent to the other window) and then adjust it by "Margin" (e.g. above
// window "A" by 6)
//
// NOTE: "Margin" is either added to ("lmAbove" and "lmLeftOf") or subtracted
//       from("lmBelow" and "lmRightOf") depending on the relationship
//
// "lmSameAs" can be used with either edges or sizes, and it doesn't offset
// by 1 pixel like the above four relationships did. it also uses "Value"
// (e.g. same width as window "A" plus 10)
//
// NOTE: "Value" is always *added*. use a negative number if you want the
//       effect to be subtractive
//
struct TLayoutConstraint {
  TWindow*           RelWin;            // relative window, lmParent for parent

  uint               MyEdge       : 4;  // edge or size (width/height)
  TRelationship      Relationship : 4;
  TMeasurementUnits  Units        : 4;
  uint               OtherEdge    : 4;  // edge or size (width/height)

  // This union is just for naming convenience
  //
  union {
    int  Margin;   // used for "lmAbove", "lmBelow", "lmLeftOf", "lmRightOf"
    int  Value;    // used for "lmSameAs" and "lmAbsolute"
    int  Percent;  // used for "lmPercentOf"
  };
};

//
// struct TEdgeConstraint
// ~~~~~~ ~~~~~~~~~~~~~~~
// Adds member functions for setting edge constraints
//
struct TEdgeConstraint : public TLayoutConstraint {

  // For setting arbitrary edge constraints. use it like this:
  //   metrics->X.Set(lmLeft, lmRightOf, lmParent, lmLeft, 10);
  //
  void    Set(TEdge edge,      TRelationship rel, TWindow* otherWin,
              TEdge otherEdge, int value = 0);

  // These four member functions can be used to position your window with
  // respective to a sibling window. you specify the sibling window and an
  // optional margin between the two windows
  //
  void    LeftOf(TWindow* sibling, int margin = 0);
  void    RightOf(TWindow* sibling, int margin = 0);
  void    Above(TWindow* sibling, int margin = 0);
  void    Below(TWindow* sibling, int margin = 0);

  // These two work on the same edge, e.g. "SameAs(win, lmLeft)" means
  // that your left edge should be the same as the left edge of "otherWin"
  //
  void    SameAs(TWindow* otherWin, TEdge edge);
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent);

  // Setting an edge to a fixed value
  //
  void    Absolute(TEdge edge, int value);

  // Letting an edge remain as-is
  //
  void    AsIs(TEdge edge);
};

//
// struct TEdgeOrSizeConstraint
// ~~~~~~ ~~~~~~~~~~~~~~~~~~~~~
struct TEdgeOrSizeConstraint : public TEdgeConstraint {

  // Redefine member functions defined by TEdgeConstraint that are hidden by
  // TEdgeOrSizeConstraint because of extra/different params
  //
  void    Absolute(TEdge edge, int value);
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent);
  void    SameAs(TWindow* otherWin, TEdge edge);
  void    AsIs(TEdge edge);
  void    AsIs(TWidthHeight edge);
};

struct TEdgeOrWidthConstraint : public TEdgeOrSizeConstraint {

  // Redefine member functions defined by TEdgeOrSizeConstraint that are hidden by
  // TEdgeOrWidthConstraint because of extra/different params
  //
  void    Absolute(TEdge edge, int value);
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent);
  void    SameAs(TWindow* otherWin, TEdge edge);

  // Setting a width/height to a fixed value
  //
  void    Absolute(int value);

  // Percent of another window's width/height (defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width 50%
  // of my parent's height)
  //
  void    PercentOf(TWindow*     otherWin,
                    int          percent,
                    TWidthHeight otherWidthHeight = lmWidth);

  // Same as another window's width/height (defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width
  // the same as my height)
  //
  void    SameAs(TWindow*     otherWin,
                 TWidthHeight otherWidthHeight = lmWidth,
                 int          value = 0);

};

struct TEdgeOrHeightConstraint : public TEdgeOrSizeConstraint {

  // Redefine member functions defined by TEdgeOrSizeConstraint that are hidden by
  // TEdgeOrHeightConstraint because of extra/different params
  //
  void    Absolute(TEdge edge, int value);
  void    PercentOf(TWindow* otherWin, TEdge edge, int percent);
  void    SameAs(TWindow* otherWin, TEdge edge);

  // Setting a width/height to a fixed value
  //
  void    Absolute(int value);

  // Percent of another window's width/height (defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width 50%
  // of my parent's height)
  //
  void    PercentOf(TWindow*     otherWin,
                    int          percent,
                    TWidthHeight otherWidthHeight = lmHeight);

  // Same as another window's width/height (defaults to being the same
  // dimension but could be the opposite dimension, e.g. make my width
  // the same as my height)
  //
  void    SameAs(TWindow*     otherWin,
                 TWidthHeight otherWidthHeight = lmHeight,
                 int          value = 0);

};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations

//
inline void TEdgeConstraint::Set(TEdge edge, TRelationship rel, TWindow* otherWin,
                                 TEdge otherEdge, int value)
{
  RelWin = otherWin;
  MyEdge = edge;
  Relationship = rel;
  OtherEdge = otherEdge;
  Value = value;
}

//
inline void TEdgeConstraint::LeftOf(TWindow* sibling, int margin)
{
  Set(lmRight, lmLeftOf, sibling, lmLeft, margin);
}

//
inline void TEdgeConstraint::RightOf(TWindow* sibling, int margin)
{
  Set(lmLeft, lmRightOf, sibling, lmRight, margin);
}

//
inline void TEdgeConstraint::Above(TWindow* sibling, int margin)
{
  Set(lmBottom, lmAbove, sibling, lmTop, margin);
}

//
inline void TEdgeConstraint::Below(TWindow* sibling, int margin)
{
  Set(lmTop, lmBelow, sibling, lmBottom, margin);
}

//
inline void TEdgeConstraint::SameAs(TWindow* otherWin, TEdge edge)
{
  Set(edge, lmSameAs, otherWin, edge, 0);
}

//
inline void TEdgeConstraint::PercentOf(TWindow* otherWin, TEdge edge, int percent)
{
  Set(edge, lmPercentOf, otherWin, edge, percent);
}

//
inline void TEdgeConstraint::Absolute(TEdge edge, int value)
{
  MyEdge = edge;
  Value = value;
  Relationship = lmAbsolute;
}

//
inline void TEdgeConstraint::AsIs(TEdge edge)
{
  MyEdge = edge;
  Relationship = lmAsIs;
}

//---

//
inline void TEdgeOrSizeConstraint::AsIs(TEdge edge)
{
  TEdgeConstraint::AsIs(edge);
}

//
inline void TEdgeOrSizeConstraint::AsIs(TWidthHeight edge)
{
  TEdgeConstraint::AsIs(TEdge(edge));
}

//---

//
inline void TEdgeOrWidthConstraint::Absolute(TEdge edge, int value)
{
  TEdgeConstraint::Absolute(edge, value);
}

//
inline void TEdgeOrWidthConstraint::PercentOf(TWindow* otherWin, TEdge edge, int percent)
{
  TEdgeConstraint::PercentOf(otherWin, edge, percent);
}

//
inline void TEdgeOrWidthConstraint::SameAs(TWindow* otherWin, TEdge edge)
{
  TEdgeConstraint::SameAs(otherWin, edge);
}

//
inline void TEdgeOrWidthConstraint::Absolute(int value)
{
  MyEdge = lmWidth;
  Value = value;
  Relationship = lmAbsolute;
}

//
inline void TEdgeOrWidthConstraint::PercentOf(TWindow* otherWin,
  int percent, TWidthHeight otherWidthHeight)
{
  RelWin = otherWin;
  MyEdge = lmWidth;
  Relationship = lmPercentOf;
  OtherEdge = otherWidthHeight;
  Percent = percent;
}

//
inline void TEdgeOrWidthConstraint::SameAs(TWindow* otherWin,
  TWidthHeight otherWidthHeight, int value)
{
  RelWin = otherWin;
  MyEdge = lmWidth;
  Relationship = lmSameAs;
  OtherEdge = otherWidthHeight;
  Value = value;
}

//---

//
inline void TEdgeOrHeightConstraint::Absolute(TEdge edge, int value)
{
  TEdgeConstraint::Absolute(edge, value);
}

//
inline void TEdgeOrHeightConstraint::PercentOf(TWindow* otherWin, TEdge edge, int percent)
{
  TEdgeConstraint::PercentOf(otherWin, edge, percent);
}

//
inline void TEdgeOrHeightConstraint::SameAs(TWindow* otherWin, TEdge edge)
{
  TEdgeConstraint::SameAs(otherWin, edge);
}

//
inline void TEdgeOrHeightConstraint::Absolute(int value)
{
  MyEdge = lmHeight;
  Value = value;
  Relationship = lmAbsolute;
}

//
inline void TEdgeOrHeightConstraint::PercentOf(TWindow* otherWin,
  int percent, TWidthHeight otherWidthHeight)
{
  RelWin = otherWin;
  MyEdge = lmHeight;
  Relationship = lmPercentOf;
  OtherEdge = otherWidthHeight;
  Percent = percent;
}

//
inline void TEdgeOrHeightConstraint::SameAs(TWindow* otherWin,
  TWidthHeight otherWidthHeight, int value)
{
  RelWin = otherWin;
  MyEdge = lmHeight;
  Relationship = lmSameAs;
  OtherEdge = otherWidthHeight;
  Value = value;
}

#endif  // OWL_LAYOUTCO_H
