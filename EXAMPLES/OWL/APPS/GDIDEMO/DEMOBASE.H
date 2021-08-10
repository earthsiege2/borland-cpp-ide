//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Base window classes for the GDI demo windows
//----------------------------------------------------------------------------
#if !defined(DEMOBASE_H)
#define DEMOBASE_H

#include <owl/mdichild.h>

class TBaseDemoWindow : public TWindow  {
  public:
    TBaseDemoWindow() : TWindow(0, 0, 0) {}

    virtual void TimerTick() {}
    
  DECLARE_CASTABLE;
};

// TBaseDemoWindow.TimerTick is a trivial method that gets called
//  whenever application receives a EvTimer.  Descendants will override
//  this procedure if they need timer messages.

#endif  //  DEMOBASE_H
