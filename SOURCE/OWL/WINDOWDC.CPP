//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of classes TWindowDC, TScreenDC, TDesktopDC & TClientDC
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

//
//
//
TWindowDC::TWindowDC()
:
  TDC()
{
}

//
//
//
TWindowDC::TWindowDC(HWND hWnd)
:
  TDC(),
  Wnd(hWnd)
{
  Handle = ::GetWindowDC(Wnd);
  CheckValid();
}

//
//
//
TWindowDC::~TWindowDC()
{
  RestoreObjects();
  if (ShouldDelete)
    ::ReleaseDC(Wnd, HDC(Handle));
  Handle = 0;
}

//
//
//
TScreenDC::TScreenDC()
:
  TWindowDC(0)
{
}

//
//
//
TDesktopDC::TDesktopDC()
:
  TWindowDC(::GetDesktopWindow())
{
}

//
//
//
TClientDC::TClientDC(HWND wnd)
:
  TWindowDC()
{
  Wnd = wnd;
  Handle = ::GetDC(Wnd);
  CheckValid();
}
