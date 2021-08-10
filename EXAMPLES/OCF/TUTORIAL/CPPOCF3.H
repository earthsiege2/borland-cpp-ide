// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// Simple OLE Container using OCF
// ---------------------------------------------------------------------------
#if !defined(CPPOCF3_H)
#define CPPOCF3_H

#include <dir.h>
#include "ocfhlpr.h"
#include "cppocf3.rh"

//
// Prototypes
//
bool  InitInstance(HINSTANCE, int);
bool  InitFrame(HINSTANCE);
bool  InitChild(HINSTANCE);


//
// Retrieve OCF Helper associated with a window
//
TOleWin*    GetOleWinObj(HWND hwnd);


//
// MDI Frame and MDI Child Window Callbacks
//
LRESULT CALLBACK _export
MainWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK _export
ViewWndProc(HWND hwnd, uint message, WPARAM wParam, LPARAM lParam);


//
//
//
typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;


//
// Container class - holds array of points
//
class TLine : public TPoints {
  public:
    TLine(int penSize = 1, COLORREF color = RGB(0, 0, 0)) :
    TPoints(10, 0, 10), PenSize(penSize), Color(color)
    {}

    // The == operator must be defined for the container class, even if unused
    bool operator ==(const TLine& other) const
    {
      return &other == this;
    }

    COLORREF   Color;
    int        PenSize;
};


typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;


//
// Class which holds the data of the MDI Child window i.e. and array of Lines
//
class ViewWndData {
  public:
    ViewWndData() : Lines(new TLines(100, 0, 5)), IsDirty(false)
    {
      FileName[0] = 0;
    }
   ~ViewWndData()
    {
      delete Lines;
    }

    TLines*    Lines;
    bool       IsDirty;
    char       FileName[MAXPATH];
};


#endif   // CPPOCF3_H
