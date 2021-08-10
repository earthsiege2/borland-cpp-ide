//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Multi-thread MoveToLineTo demo window header
//----------------------------------------------------------------------------
#if !defined(LINE_H)
#define LINE_H

#include "demobase.h"

//
// MoveToLineTo demo constants
//
const int  MaxPoints    = 15;  // Number of points to be drawn
const int  IconicPoints = 6;   // Number of points to draw when iconized

struct TRPoint {
  float X, Y;
};

class TMoveToLineToWindow : public TBaseDemoWindow {
  public:
    TMoveToLineToWindow();
   ~TMoveToLineToWindow();

    void Paint(TDC& dc, bool, TRect&);

  protected:
    void EvSize(uint, TSize& Size);

  private:
    TRPoint     Points[MaxPoints];
    float       Rotation;     // in radians
    int         PointCount;
    bool        Iconized;

    TMemoryDC*  MemDC;
    TBitmap*    Bitmap;

    void        RotatePoints();

    void        ClockTick();

  DECLARE_CASTABLE;
  DECLARE_RESPONSE_TABLE(TMoveToLineToWindow);
};

#endif  // LINE_H
