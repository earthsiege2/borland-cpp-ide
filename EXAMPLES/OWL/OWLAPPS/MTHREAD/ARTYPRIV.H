//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   classes used internally by the multi-thread TArtyWindow
//----------------------------------------------------------------------------
#ifndef __ARTYINTERNAL_H
#define __ARTYINTERNAL_H

#ifndef __OWL_COLOR_H
  #include <owl\color.h>
#endif
class _EXPCLASS TDC;
class _EXPCLASS TPen;

// Arty demo constants 
const int   MaxLineCount      =  100;
const int   MaxIconicLineCount=  5;
const int   MaxColorDuration  =  10;


struct TLineRec {
  int    LX1,LY1, LX2,LY2;
  TColor Color;
};

class TList {
  public:
    TList(int _max);
    void Redraw(TDC&);
    void ResetLines();
    void ScaleTo(int, int);
    void LineTick(TDC&);

  protected:
    TLineRec  Line[MaxLineCount];
    int       Xmax, Ymax;

    void AdjustX(int&, int&);
    void AdjustY(int&, int&);

    virtual void DrawLine(TDC&, int);
    virtual void EraseLine(TDC&, int);

    void SelectNewColor();
    void SelectNewDeltaValues();

  private:
    int  MaxLines;
    int  X1, Y1, X2, Y2;
    int  MaxDelta;
    int  ColorDuration;
    int  IncrementCount;
    int  DeltaX1, DeltaY1, DeltaX2, DeltaY2;
    int  CurrentLine;
    long PenColor;
};

// Quads draw 4 reflections of each line
//
class TQuadList : public TList {
  public:
    TQuadList(int _max) : TList(_max) {}

    void DrawLine(TDC&, int);
    void EraseLine(TDC&, int);
};

#endif
