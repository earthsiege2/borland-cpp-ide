//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   MoveToLineTo demo window header
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
    
    void TimerTick();
    void Paint(TDC& dc, BOOL, TRect&);

  protected:
    void EvSize(UINT, TSize& Size);
  
  private:
    TRPoint     Points[MaxPoints];
    float       Rotation;     // in radians
    int         PointCount;
    BOOL        Iconized;
    void        RotatePoints();

  DECLARE_CASTABLE;
  DECLARE_RESPONSE_TABLE(TMoveToLineToWindow);
};

#endif
