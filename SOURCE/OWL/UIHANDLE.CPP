//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;

//
// Construct a UIHandle object given a frame, a style and a handle size
//
TUIHandle::TUIHandle(const TRect& frame, uint style, int thickness)
:
  Frame(frame),
  Style(style),
  HandleBox(thickness, thickness)
{
}

//
//
//
void
TUIHandle::Move(int dx, int dy)
{
  Frame.Offset(dx, dy);
}

//
//
//
void
TUIHandle::MoveTo(int x, int y)
{
  Frame.Offset(x-Frame.left, y-Frame.top);
}

//
//
//
void
TUIHandle::Size(int w, int h)
{
  Frame.right = Frame.left + w;
  Frame.bottom = Frame.top + h;
}

//
// Calculate the outside frame rectangle
//
TRect
TUIHandle::GetBoundingRect() const
{
  return (Style&HandlesOut) ? Frame.InflatedBy(HandleBox) : Frame;
}

//
// Compare a given point to various parts of the UIHandle and return where the
// point hit.
//
TUIHandle::TWhere
TUIHandle::HitTest(const TPoint& point) const
{
  // Check first to see if point is a total miss
  //
  TRect outsideFrame = GetBoundingRect();
  if (!outsideFrame.Contains(point))
    return Outside;

  // Next check to see if it is completely inside
  //
  TRect insideFrame = outsideFrame.InflatedBy(-HandleBox);
  if (insideFrame.Contains(point))
    return (Style & InsideSpecial) ? Inside : MidCenter;

  // If no grapple are used, hit must be in move area
  //
  if (!(Style & Grapples))
    return MidCenter;

  // Determine which of the handles was hit. Calulate X and then Y parts
  //
  int where;
  TPoint halfHandle(HandleBox.x/2, HandleBox.y/2);
  if (point.x < insideFrame.left)
    where = 0; //Left;
  else if (point.x >= insideFrame.right)
    where = 2; //Right;
  else {
    int center = insideFrame.left + insideFrame.Width()/2;
    if (point.x >= center-halfHandle.x && point.x <= center+halfHandle.x)
      where = 1; //Center;
    else
      return MidCenter;
  }
  if (point.y < insideFrame.top)
    where += 0; //Top;
  else if (point.y >= insideFrame.bottom)
    where += 6; //Bottom;
  else {
    int middle = insideFrame.top + insideFrame.Height()/2;
    if (point.y >= middle-halfHandle.y && point.y <= middle+halfHandle.y)
      where += 3; //Middle;
    else
      return MidCenter;
  }
  return (TWhere)where;
}

//
// Helper function to convert a where code into a cursor shape Id
//
uint16
TUIHandle::GetCursorId(TWhere where)
{
  static uint16 cursorId[] = {
    32642, 32645, 32643,  // SIZENWSE, SIZENS, SIZENESW
    32644, 32512, 32644,  // SIZEWE,   ARROW,  SIZEWE,
    32643, 32645, 32642,  // SIZENESW, SIZENS, SIZENWSE
  };
  if (where == Outside)
    return 0;
  if (where == Inside)
    return 32513;         // IBEAM
  return cursorId[where];
}

//
// Paint this UIHandle object onto a given dc
//
void
TUIHandle::Paint(TDC& dc) const
{
  TRect outerRect = GetBoundingRect();

  // Draw a frame rect outside of Frame if indicated by the style
  //
  if (Style & (Framed | DashFramed)) {
    int oldRop2 = dc.GetROP2();
    dc.SetROP2(R2_XORPEN);
    TRect frame = Frame;
    if (Style & Framed) {
      TBrush frameBr(TColor::Black);
      dc.FrameRect(frame, frameBr);
    }
    else {
      TPen dashPen(TColor::White, 1, PS_DASH);
      dc.SelectObject(dashPen);
      dc.SelectStockObject(NULL_BRUSH);
      dc.SetBkColor(TColor::Black);
      dc.Rectangle(frame);
      dc.RestorePen();
    }
//    dc.DrawFocusRect(Frame); // a useful dotted rect frame...
    if (!(Style&HandlesOut))
      outerRect.Inflate(-1, -1);
    dc.SetROP2(oldRop2);
  }

  // Calculate the grapple box rectangle and the midpoint handle topleft offsets
  //
  TPoint grappleBox = (Style & Grapples) ? HandleBox : TPoint(0, 0);
  int center = outerRect.Width()/2 - grappleBox.x/2;
  int middle = outerRect.Height()/2 - grappleBox.y/2;

  // Draw the 8 grapples if indicated by the style
  //
  if (Style & Grapples) {
    const uint32 rop = DSTINVERT;
    dc.PatBlt(outerRect.left, outerRect.top,
              grappleBox.x, grappleBox.y, rop);
    dc.PatBlt(outerRect.left+center, outerRect.top,
              grappleBox.x, grappleBox.y, rop);
    dc.PatBlt(outerRect.right-HandleBox.x, outerRect.top,
              grappleBox.x, grappleBox.y, rop);

    dc.PatBlt(outerRect.left, outerRect.top+middle,
              grappleBox.x, grappleBox.y, rop);
    dc.PatBlt(outerRect.right-HandleBox.x, outerRect.top+middle,
              grappleBox.x, grappleBox.y, rop);

    dc.PatBlt(outerRect.left, outerRect.bottom-HandleBox.y,
              grappleBox.x, grappleBox.y, rop);
    dc.PatBlt(outerRect.left+center, outerRect.bottom-HandleBox.y,
              grappleBox.x, grappleBox.y, rop);
    dc.PatBlt(outerRect.right-HandleBox.x, outerRect.bottom-HandleBox.y,
              grappleBox.x, grappleBox.y, rop);
  }

  // Draw the hatched border or whole rect if indicated by the style
  //
  if (Style & (HatchBorder | HatchRect)) {
    const uint32 rop = PATINVERT;  // opposite color rop: 0x00A000C9L;
    static THatch8x8Brush hatchBrush(THatch8x8Brush::Hatch13F1);
    dc.SelectObject(hatchBrush);  //CQ set brush origin?
    if (Style & HatchBorder) {
      int center2 = outerRect.Width() - center - grappleBox.x;
      int middle2 = outerRect.Height() - middle - grappleBox.y;

      dc.PatBlt(outerRect.left+grappleBox.x, outerRect.top,
                center-grappleBox.x, HandleBox.y, rop);
      dc.PatBlt(outerRect.left+center+grappleBox.x, outerRect.top,
                center2-grappleBox.x, HandleBox.y, rop);

      dc.PatBlt(outerRect.left, outerRect.top+HandleBox.y,
                HandleBox.x, middle-HandleBox.y, rop);
      dc.PatBlt(outerRect.left, outerRect.top+middle+grappleBox.y,
                HandleBox.x, middle2-HandleBox.y, rop);

      dc.PatBlt(outerRect.right-HandleBox.x, outerRect.top+HandleBox.y,
                HandleBox.x, middle-HandleBox.y, rop);
      dc.PatBlt(outerRect.right-HandleBox.x, outerRect.top+middle+grappleBox.y,
                HandleBox.x, middle2-HandleBox.y, rop);

      dc.PatBlt(outerRect.left+grappleBox.x, outerRect.bottom-HandleBox.y,
                center-grappleBox.x, HandleBox.y, rop);
      dc.PatBlt(outerRect.left+center+grappleBox.x, outerRect.bottom-HandleBox.y,
                center2-grappleBox.x, HandleBox.y, rop);
    }
    else {
      dc.PatBlt(outerRect, rop);
    }
    dc.RestoreBrush();
  }
}
