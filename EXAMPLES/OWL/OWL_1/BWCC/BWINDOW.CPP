//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TBWindow, a BWCC friendly derivation of TWindow
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "bwindow.h"
#include "bwcc.h"

IMPLEMENT_STREAMABLE_FROM_BASE(TBWindow, TWindow);

//
// constructor for a TBWindow object
//
TBWindow::TBWindow(TWindow*        parent,
                   const char far* title,
                   TModule*        module)
  : TWindow(parent, title, module)
{
}

char far*
TBWindow::GetClassName()
{
  return "TBWindow";
}

void
TBWindow::GetWindowClass(WNDCLASS& wndClass)
{
  TWindow::GetWindowClass(wndClass);
  wndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
}
