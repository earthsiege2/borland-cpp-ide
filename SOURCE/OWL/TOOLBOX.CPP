//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\toolbox.cpp
//   Implementation of class TToolBox, a 2-d arrangement of TButtonGadgets.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\toolbox.h>
#include <owl\buttonga.h>

IMPLEMENT_CASTABLE(TToolBox);

TToolBox::TToolBox(TWindow*        parent,
                   int             numColumns,
                   int             numRows,
                   TTileDirection  direction,
                   TModule*        module)
  : TGadgetWindow(parent, direction, new TGadgetWindowFont, module)
{
  NumRows = numRows;
  NumColumns = numColumns;

  //
  // make the gadget borders overlap the tool box's borders
  //
  Margins.Units = TMargins::BorderUnits;
  Margins.Left = Margins.Right = Margins.Top = Margins.Bottom = -1;
  
  ShrinkWrapWidth = TRUE;
}

void
TToolBox::Insert(TGadget& g, TPlacement placement, TGadget* sibling)
{
  TGadgetWindow::Insert(g, placement, sibling);
  ((TButtonGadget&)g).SetNotchCorners(FALSE);
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
// compute the numer of rows & columns, filling in rows OR columns if left
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
// compute the cell size which is determined by the widest and the highest
// gadget
//
void
TToolBox::ComputeCellSize(TSize& cellSize)
{
  cellSize.cx = cellSize.cy = 0;

  for (TGadget* g = Gadgets; g; g = g->NextGadget()) {
    TSize  desiredSize;

    g->GetDesiredSize(desiredSize);

    if (desiredSize.cx > cellSize.cx)
      cellSize.cx = desiredSize.cx;

    if (desiredSize.cy > cellSize.cy)
      cellSize.cy = desiredSize.cy;
  }
}

void
TToolBox::GetDesiredSize(TSize& size)
{
  TSize  cellSize;
  int    left, right, top, bottom;
  int    numRows, numColumns;
  int    cxBorder = GetSystemMetrics(SM_CXBORDER);
  int    cyBorder = GetSystemMetrics(SM_CYBORDER);

  GetMargins(Margins, left, right, top, bottom);
  size.cx = left + right;
  size.cy = top + bottom;

  if (Attr.Style & WS_BORDER) {
    size.cx += 2 * cxBorder;
    size.cy += 2 * cyBorder;
  }

  ComputeCellSize(cellSize);
  ComputeNumRowsColumns(numRows, numColumns);

  size.cx += numColumns * cellSize.cx;
  size.cy += numRows * cellSize.cy;

  //
  // compensate for the gadgets overlapping
  //
  size.cx -= (numColumns - 1) * cxBorder;
  size.cy -= (numRows - 1) * cyBorder;
}

TRect
TToolBox::TileGadgets()
{
  TSize     cellSize;
  int       numRows, numColumns;
  TRect     innerRect;
  TRect     invalidRect;
  TGadget*  g = Gadgets;
  int       x, y;
  int       cxBorder = GetSystemMetrics(SM_CXBORDER);
  int       cyBorder = GetSystemMetrics(SM_CYBORDER);

  ComputeCellSize(cellSize);
  ComputeNumRowsColumns(numRows, numColumns);
  GetInnerRect(innerRect);
  invalidRect.SetEmpty();

  if (Direction == Horizontal) {    // Row Major--
    y = innerRect.top;

    for (int r = 0; r < numRows; r++) {
      x = innerRect.left;

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

        x += cellSize.cx - cxBorder;
        g = g->NextGadget();
      }

      y += cellSize.cy - cyBorder;
    }

  } else {
    x = innerRect.left;

    for (int c = 0; c < numColumns; c++) {
      y = innerRect.top;

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

        y += cellSize.cy - cyBorder;
        g = g->NextGadget();
      }

      x += cellSize.cx - cxBorder;
    }
  }
  return invalidRect;
}

void
TToolBox::LayoutSession()
{
  TGadgetWindow::LayoutSession();
  TSize sz;
  GetDesiredSize(sz);
  MoveWindow(0, 0, sz.cx, sz.cy, TRUE);
}

