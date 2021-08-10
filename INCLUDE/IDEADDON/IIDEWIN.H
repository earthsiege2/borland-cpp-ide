/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iidewin.h
  Created: 06/24/96
  Copyright (c) 1996, Borland International
  $Revision:   1.0  $

  IIdeWindow
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IIDEWIN_H
#define __IIDEWIN_H

#include <windows.h>
#include <objbase.h>
#include <ideaddon\iidewin.uid>
#include <ideaddon\common.h>


class IIdeWindow : public IUnknown {
 public:
  virtual HWND BCWADDON_METHOD GetHwnd() = 0;
};


#endif    // __IIDEWIN_H
