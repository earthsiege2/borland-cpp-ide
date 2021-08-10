//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of classes TWindowDC, TScreenDC, TDesktopDC & TClientDC
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

OWL_DIAGINFO;

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
