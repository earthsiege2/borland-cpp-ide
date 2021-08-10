//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Multi-thread MoveToLineTo demo window header
//----------------------------------------------------------------------------
#ifndef __LINE_H
#define __LINE_H

#include "demobase.h"

// MoveToLineTo demo constants
const int  MaxPoints    = 15;  // Number of points to be drawn 
const int  IconicPoints = 6;   // Number of points to draw when iconized

struct TRPoint {
  float X, Y;
};

class TMoveToLineToWindow : public TBaseDemoWindow {
  public:
    TMoveToLineToWindow();

    void Paint(TDC& dc, BOOL, TRect&);

  protected:
    void EvSize(UINT, TSize& Size);
  
  private:
    TRPoint     Points[MaxPoints];
    float       Rotation;     // in radians
    int         PointCount;
    BOOL        Iconized;
    void        RotatePoints();

    void        DoRun();

  DECLARE_RESPONSE_TABLE(TMoveToLineToWindow);
};

#endif
