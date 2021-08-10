//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TWindowDC, TScreenDC, TDesktopDC & TClientDC
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

TWindowDC::TWindowDC()
:
  TDC()
{
}

TWindowDC::TWindowDC(HWND wnd)
:
  TDC(),
  Wnd(wnd)
{
  Handle = ::GetWindowDC(Wnd);
  CheckValid();
}

TWindowDC::~TWindowDC()
{
  RestoreObjects();
  if (ShouldDelete)
    ::ReleaseDC(Wnd, HDC(Handle));
  Handle = 0;
}

TScreenDC::TScreenDC()
:
  TWindowDC(0)
{
}

TDesktopDC::TDesktopDC()
:
  TWindowDC(::GetDesktopWindow())
{
}

TClientDC::TClientDC(HWND wnd)
:
  TWindowDC()
{
  Wnd = wnd;
  Handle = ::GetDC(Wnd);
  CheckValid();
}
