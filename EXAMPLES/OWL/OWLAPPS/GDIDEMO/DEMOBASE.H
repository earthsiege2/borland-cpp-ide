//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
// Base window classes for the GDI demo windows
//----------------------------------------------------------------------------
#ifndef __DEMOBASE_H
#define __DEMOBASE_H

#include <owl\mdichild.h>

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

class TBaseDemoWindow : public TWindow  {
  public:
    TBaseDemoWindow() : TWindow(0, 0, 0) {}

    virtual void TimerTick() {}
    
  DECLARE_CASTABLE;
};

// TBaseDemoWindow.TimerTick is a trivial method that gets called
//  whenever application receives a EvTimer.  Descendants will override
//  this procedure if they need timer messages.
#endif
