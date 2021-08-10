//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dc.cpp
//   Implementation of TPaintDC
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

TPaintDC::TPaintDC(HWND wnd) : TDC()
{
  Wnd = wnd;
  Handle = ::BeginPaint(Wnd, &Ps);
  CheckValid();
}

TPaintDC::~TPaintDC()
{
  RestoreObjects();
  if (ShouldDelete)
    ::EndPaint(Wnd, &Ps);
}
