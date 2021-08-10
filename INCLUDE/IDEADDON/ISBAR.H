/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  isbar.h
  Created: 11/21/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
   
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __ISBAR_H
#define __ISBAR_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\isbar.uid>

struct IStatusBar : public IUnknown {
  //
  // return the window handle of statusbar
  //
  virtual HWND GetHwnd() = 0;
  //
  // display text in the status bar
  //
  virtual void Display(IPolyString* polyStr) = 0;
};


#endif  // __ISBAR_H
