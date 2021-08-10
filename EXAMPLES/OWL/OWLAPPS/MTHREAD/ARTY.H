//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Multi-thread arty demo window object header
//----------------------------------------------------------------------------
#ifndef __ARTY_H
#define __ARTY_H

#include "demobase.h"

class _EXPCLASS TList;
class _EXPCLASS TStatic;

class TArtyWindow : public TBaseDemoWindow {
  public:
    TArtyWindow();
    ~TArtyWindow();

  protected:
    void    EvLButtonDown(UINT modKeys, TPoint& point);
    void    EvRButtonDown(UINT modKeys, TPoint& point);
    void    EvSize(UINT, TSize& size);
    void    Paint(TDC& dc, BOOL erase, TRect& rect);

  private:
    TList*      List;
    TList*      BigLineList;
    TList*      IconicLineList;
    int         TextHeight;
    BOOL        Iconized;
    BOOL        Paused;
    TStatic*    StaticControl;

    void        DoRun();

  DECLARE_RESPONSE_TABLE(TArtyWindow);
};

#endif
