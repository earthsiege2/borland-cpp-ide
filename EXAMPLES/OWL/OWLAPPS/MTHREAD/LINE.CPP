//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Multi-thread MoveToLineTo demo window
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>
#include "line.h"
#include <math.h>

DEFINE_RESPONSE_TABLE1(TMoveToLineToWindow, TBaseDemoWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

TMoveToLineToWindow::TMoveToLineToWindow() : TBaseDemoWindow()
{
  Rotation = 0;
  PointCount = MaxPoints;
  Iconized = FALSE;
  RotatePoints();
  Start();
}

void
TMoveToLineToWindow::EvSize(UINT sizeType, TSize& size)
{
  TBaseDemoWindow::EvSize(sizeType, size);
  Invalidate();

  if (sizeType == SIZE_MINIMIZED) {
    if (!Iconized) {
      Rotation = 0;
      Iconized = TRUE;
      PointCount = IconicPoints;
      RotatePoints();
    }

  } else {
    if (Iconized) {
      Rotation = 0;
      Iconized = FALSE;
      PointCount = MaxPoints;
      RotatePoints();
    }
  }
}

void
TMoveToLineToWindow::DoRun()
{
  RotatePoints();
  if (Iconized) {
    // Iconized windows don't process paint messages, so we'll manually
    // update the image here.  Doing this painting during the timer tick
    // will slow things down a bit, especially with several of these
    // windows iconized at the same time.
    //
    Paint(TClientDC(*Parent), FALSE, TRect());

  } else {
    // In terms of Windows resources and system wide performance, letting
    // paint do the work is 'faster' because it reduces the CPU time spent
    // handling each timer tick.  Paint messages are low priority, so other
    // messages like mouse clicks and other user input get processed first.
    // The downside is that the paint messages are handled last, when
    // there's nothing else to do, which can make animation look a bit jerky
    // on a busy machine.
    //
    Invalidate(FALSE);    // Let the Paint method draw the new figure...
  }
}

void
TMoveToLineToWindow::RotatePoints()
{
  // NOTE: all figures are in radians
  const float M_2PI = 2 * M_PI;           // 2 pi radians in a circle
  float StepAngle = M_2PI / PointCount;   // angular distance between points

  Rotation += M_PI / 32;   // Increment the angle of rotation of figure
  if (Rotation > StepAngle)
    Rotation -= StepAngle;   // Keep rotation less than distance between points

  // The loop below has i walking through the Points array, while j walks
  // simultaneously through the angles to each point on the circle.  
  // Incrementing j by StepAngle moves j to the next point on the circle with
  // no complicated arithmetic (everything has been set up in advance of the
  // loop).  Initializing j with Rotation causes the entire figure to shift
  // clockwise a small amount.

  int i;
  float j;
  for (i = 0, j = Rotation; i < PointCount; i++, j += StepAngle) {
    Points[i].X = cos(j);   // These values will be multiplied by the
    Points[i].Y = sin(j);   // current radius at display time.
  }
}

void
TMoveToLineToWindow::Paint(TDC& dc, BOOL, TRect&)
{
  TRect rect;
  if (Iconized)
    Parent->GetClientRect(rect);
  else
    GetClientRect(rect);

  int centerX = rect.right / 2;
  int centerY = rect.bottom / 2;
  int radius = min(centerY, centerX);

  // The follow memory DC operations are not required to draw lines, but
  // were added to reduce screen flicker and speed up screen updates.
  //
  TMemoryDC  memDC(dc);

  TBitmap bitmap(dc, radius*2, radius*2);
  memDC.SelectObject(bitmap);

  // Initiallize the new bitmap to all white.
  //
  memDC.PatBlt(0, 0, radius*2, radius*2, WHITENESS);

  // The Ellipse and the loop are all that's really needed to draw.  If you
  // substitute dc for memDC, the draws will go directly to the screen.
  // (Though the figure would no longer be centered, since the figure is drawn
  // on a memDC bitmap, and the bitmap is then centered on the dc...)
  // Since this line window is animated, it is frequently updated, which would
  // cause the window to spend most of its time flickering if the dc were
  // used.  Thus, the need for memory DC operations.  If the window were not
  // animated, drawing onto the dc would look just fine.
  //
  memDC.Ellipse(0, 0, radius*2, radius*2);
  int i,j;
  for (i = 0; i < PointCount; i++) {
    for (j = i + 1; j < PointCount; j++) {
      memDC.MoveTo(radius + floor(Points[i].X * radius),
                   radius + floor(Points[i].Y * radius));
      memDC.LineTo(radius + floor(Points[j].X * radius),
                   radius + floor(Points[j].Y * radius));
    }
  }

  // Now transfer what was drawn on the (invisible) memory DC onto the visible
  // dc.  This one BitBlt transfer is much faster than the many 
  // individual operations that were performed above.
  //
  dc.BitBlt(centerX-radius, centerY-radius, radius*2, radius*2, 
            memDC, 0, 0, SRCCOPY);

  // Restore original bitmap before leaving
  //
  memDC.RestoreBitmap();
               
  // Footnotes:  Drawing this figure doesn't require a memory DC.  Animating
  // the figure requires a memory DC only to reduce flicker to a tolerable 
  // level.
  // To make the animation faster still, (but use more memory, too),
  // you could keep that memory DC hanging around between screen paints -
  // constructing a DC takes some effort, and we're constructing one every 
  // time we get a timer message.   You'd get the biggest improvement in 
  // animation speed by calculating a sequence of bitmaps, then just 
  // displaying them in the proper sequence.  This demo reconstructs the
  // points list and redraws the figure for every timer message - a lot of
  // work for the CPU, but it's code is simpler and doesn't use as much
  // memory as more elaborate schemes might.

  // A challenge:  Turn the rotating figure into a ball that bounces off the
  // walls of the window.  Don't forget the english (spin) the ball should 
  // pick up when bouncing off the wall...
}
