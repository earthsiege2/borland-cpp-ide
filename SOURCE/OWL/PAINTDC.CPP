//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TPaintDC
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

TPaintDC::TPaintDC(HWND wnd)
:
  TDC()
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
