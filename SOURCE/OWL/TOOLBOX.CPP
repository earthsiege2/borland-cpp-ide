//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Implementation of class TToolBox, a 2-d arrangement of TButtonGadgets.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_TOOLBOX_H)
# include <owl/toolbox.h>
#endif
#if !defined(OWL_BUTTONGA_H)
# include <owl/buttonga.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

OWL_DIAGINFO;

IMPLEMENT_CASTABLE(TToolBox);

//
// Construct a 2-d toolbox with a given number of rows, columns, and direction.
//
TToolBox::TToolBox(TWindow*        parent,
                   int             numColumns,
                   int             numRows,
                   TTileDirection  direction,
                   TModule*        module)
:
  TGadgetWindow(parent, direction, new TGadgetWindowFont, module)
{
  NumRows = numRows;
  NumColumns = numColumns;

  // Make the gadget borders (if any) overlap the tool box's borders
  //
  Margins.Units = TMargins::BorderUnits;
  Margins.Left = Margins.Right = TSystem::Has3dUI() ? 0 : -TUIMetric::CxBorder;
  Margins.Top = Margins.Bottom = TSystem::Has3dUI() ? 0 : -TUIMetric::CyBorder;

  ShrinkWrapWidth = true;
}

//
// Always turn off notched corners when gadgets are in this toolbox.
// Only TButtonGadgets or derived gadgets are supported.
//
void
TToolBox::Insert(TGadget& g, TPlacement placement, TGadget* sibling)
{
  TGadgetWindow::Insert(g, placement, sibling);

  // Notch the corners if it's a buttonGadget
  //
  TButtonGadget* bg = TYPESAFE_DOWNCAST(&g,TButtonGadget);
  if (bg)
    bg->SetNotchCorners(false);
}

//
// Swap the rows & columns count, & let our base class do the rest
//
void
TToolBox::SetDirection(TTileDirection direction)
{
  if (Direction != direction) {
    int t = NumRows;
    NumRows = NumColumns;
    NumColumns = t;
  }

  TGadgetWindow::SetDirection(direction);
}

//
// Compute the numer of rows & columns, filling in rows OR columns if left
// unspecified using AS_MANY_AS_NEEDED (but not both).
//
void
TToolBox::ComputeNumRowsColumns(int& numRows, int& numColumns)
{
  CHECK(NumRows != AS_MANY_AS_NEEDED || NumColumns != AS_MANY_AS_NEEDED);
  numRows = NumRows == AS_MANY_AS_NEEDED ?
              (NumGadgets + NumColumns - 1) / NumColumns :
              NumRows;
  numColumns = NumColumns == AS_MANY_AS_NEEDED ?
                 (NumGadgets + NumRows - 1) / NumRows :
                 NumColumns;
}

//
// Compute the cell size which is determined by the widest and the highest
// gadget
//
void
TToolBox::ComputeCellSize(TSize& cellSize)
{
  cellSize.cx = cellSize.cy = 0;

  for (TGadget* g = Gadgets; g; g = g->NextGadget()) {
    TSize  desiredSize(0, 0);

    g->GetDesiredSize(desiredSize);

    if (desiredSize.cx > cellSize.cx)
      cellSize.cx = desiredSize.cx;

    if (desiredSize.cy > cellSize.cy)
      cellSize.cy = desiredSize.cy;
  }
}

//
// Calculate how big this toolbox should be.
//
void
TToolBox::GetDesiredSize(TSize& size)
{
  // Get border sizes
  //
  int    cxBorder = TSystem::Has3dUI() ? 0 : (int)TUIMetric::CxBorder;
  int    cyBorder = TSystem::Has3dUI() ? 0 : (int)TUIMetric::CyBorder;

  int    left, right, top, bottom;
  GetMargins(Margins, left, right, top, bottom);
  size.cx = left + right;
  size.cy = top + bottom;

  // Add in this window's border size if used
  //
  if (Attr.Style & WS_BORDER) {
    size.cx += 2 * TUIMetric::CxBorder;
    size.cy += 2 * TUIMetric::CyBorder;
  }

  TSize  cellSize;
  ComputeCellSize(cellSize);

  int    numRows, numColumns;
  ComputeNumRowsColumns(numRows, numColumns);

  size.cx += numColumns * cellSize.cx;
  size.cy += numRows * cellSize.cy;

  // Compensate for the gadgets overlapping if UI style does that
  //
  size.cx -= (numColumns - 1) * cxBorder;
  size.cy -= (numRows - 1) * cyBorder;
}

//
// Tile the gadgets in a tight 2-dimensional grid. Horizontal direction results
// in a row-major layout, and vertical direction results in column-major layout
//
TRect
TToolBox::TileGadgets()
{
  TSize     cellSize;
  ComputeCellSize(cellSize);

  int       numRows, numColumns;
  ComputeNumRowsColumns(numRows, numColumns);

  TRect     innerRect;
  GetInnerRect(innerRect);

  TRect     invalidRect;
  invalidRect.SetEmpty();

  if (Direction == Horizontal) {
    // Row Major
    //
    int y = innerRect.top;
    TGadget* g = Gadgets;

    for (int r = 0; r < numRows; r++) {
      int x = innerRect.left;

      for (int c = 0; c < numColumns && g; c++) {
        TRect bounds(TPoint(x, y), cellSize);
        TRect originalBounds(g->GetBounds());

        if (bounds != g->GetBounds()) {
          g->SetBounds(bounds);

          if (invalidRect.IsNull())
            invalidRect = bounds;
          else
            invalidRect |= bounds;

          if (originalBounds.TopLeft() != TPoint(0, 0))
            invalidRect |= originalBounds;
        }

        x += cellSize.cx;
        g = g->NextGadget();
      }

      y += cellSize.cy;
    }
  }
  else {
    // Column Major
    //
    int x = innerRect.left;
    TGadget* g = Gadgets;

    for (int c = 0; c < numColumns; c++) {
      int y = innerRect.top;

      for (int r = 0; r < numRows && g; r++) {
        TRect bounds(TPoint(x, y), cellSize);
        TRect originalBounds(g->GetBounds());

        if (bounds != originalBounds) {
          g->SetBounds(bounds);

          if (invalidRect.IsNull())
            invalidRect = bounds;
          else
            invalidRect |= bounds;

          if (originalBounds.TopLeft() != TPoint(0, 0))
            invalidRect |= originalBounds;
        }

        y += cellSize.cy;
        g = g->NextGadget();
      }

      x += cellSize.cx;
    }
  }
  return invalidRect;
}

//
// Perform a layout session. After calling the base LayoutSession, adjust this
// window's size & pos to match desired. Assumes it is used as a client in a
// frame.
//
void
TToolBox::LayoutSession()
{
  TGadgetWindow::LayoutSession();

  TSize sz;
  GetDesiredSize(sz);

  SetWindowPos(0, 0,0, sz.cx, sz.cy, SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOZORDER);
}
