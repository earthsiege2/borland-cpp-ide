//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/window.h>
#include <stdlib.h>
#include "dllhello.h"

bool far _export
CreateDLLWindow(HWND parentHWnd)
{
  TWindow* parentAlias = ::GetWindowPtr(parentHWnd);  // check if an OWL window
  if (!parentAlias)
    parentAlias = new TWindow(parentHWnd, ::Module);
  TWindow* window = new TWindow(parentAlias, "Hello from a DLL!");
  window->Attr.Style |= WS_POPUPWINDOW | WS_CAPTION | WS_THICKFRAME
                      | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
  window->Attr.X = 100; window->Attr.Y = 100;
  window->Attr.W = 300; window->Attr.H = 300;
  return window->Create();
}
