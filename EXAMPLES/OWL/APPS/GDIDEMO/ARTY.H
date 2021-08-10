//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Arty demo window object header
//----------------------------------------------------------------------------
#if !defined(ARTY_H)
#define ARTY_H

#include "demobase.h"
class _EXPCLASS TList;
class _EXPCLASS TStatic;

class TArtyWindow : public TBaseDemoWindow {
  public:
    TArtyWindow();
    ~TArtyWindow();

    void    TimerTick();

  protected:
    void    EvLButtonDown(uint modKeys, TPoint& point);
    void    EvRButtonDown(uint modKeys, TPoint& point);
    void    EvSize(uint, TSize& size);
    void    Paint(TDC& dc, bool erase, TRect& rect);

  private:
    TList*      List;
    TList*      BigLineList;
    TList*      IconicLineList;
    int         TextHeight;
    bool        Iconized;
    bool        Paused;
    TStatic*    StaticControl;

  DECLARE_RESPONSE_TABLE(TArtyWindow);
  DECLARE_CASTABLE;
};

#endif
