//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Implementation of class TMciWnd
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "mciwnd.h"

#if defined(BI_PLAT_WIN32)
  char MciWndDllName[] = "MSVFW32.DLL";
#else
  char MciWndDllName[] = "MSVIDEO.DLL";
#endif

//
//
//
TMciWndDll::TMciWndDll()
:
  TModule(MciWndDllName),

  Create(*this, "MCIWndCreate"),               // or use ord:42
  RegisterClass(*this, "MCIWndRegisterClass")  // or use ord:45
{
}

//
//
//
TMciWnd::TMciWnd(TWindow* parent, int id, char far* title, 
                 int x, int y, int w, int h, TModule* module)
:
  TControl(parent, id, title, x, y, w, h, module)
{
  Attr.Style |= MCIWNDF_NOTIFYALL;
}

//
//
//
TMciWnd::TMciWnd(TWindow* parent, int resourceId, TModule* module)
:
  TControl(parent, resourceId, module)
{
}

//
//
//
char far*   
TMciWnd::GetClassName() 
{
  return MCIWND_WINDOW_CLASS;
}

//
//
//
bool        
TMciWnd::Register()
{
  PRECONDITION(GetModule());

  WNDCLASS  windowClass;
  if (!GetModule()->GetClassInfo(GetClassName(), &windowClass)) {
    return MciWndDll.RegisterClass() != 0;
  }
  return true;
}
