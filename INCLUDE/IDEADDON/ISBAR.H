/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 isbar.h
 Created: 11/21/95
 Copyright (c) 1995, 1996 Borland International
 $Header:   Y:\admin\bride\addon\deliver\interfac\isbar.h_v   1.19   18 Nov 1996 11:29:54   JDOUGLAS  $
 $Revision:   1.19  $
   
 Interfaces declared in this file:

 implemented by IDE
    IStatusBar

 implemented by IDE client
    None

 Overview:
  Use IStatusBar to display text on IDE status line.
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __ISBAR_H
#define __ISBAR_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\isbar.uid>
#include <ideaddon\common.h>

struct IStatusBar : public IUnknown {
  //
  // return the window handle of statusbar
  //
  virtual HWND BCWADDON_CMETHOD GetHwnd() = 0;
  //
  // display text in the status bar
  //
  virtual void BCWADDON_CMETHOD Display(IPolyString* polyStr) = 0;
};


#endif  // __ISBAR_H
