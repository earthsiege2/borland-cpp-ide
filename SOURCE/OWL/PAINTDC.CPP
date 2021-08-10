//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of TPaintDC, an encapsulation of client DCs used when
// responding to paint messages
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

//
//
//
TPaintDC::TPaintDC(HWND hWnd)
:
  TDC()
{
  Wnd = hWnd;
  Handle = ::BeginPaint(hWnd, &Ps);
  CheckValid();
}

//
//
//
TPaintDC::~TPaintDC()
{
  RestoreObjects();
  if (ShouldDelete)
    ::EndPaint(Wnd, &Ps);
}
