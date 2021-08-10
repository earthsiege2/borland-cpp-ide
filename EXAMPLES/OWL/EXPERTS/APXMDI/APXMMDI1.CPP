//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmmdi1.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxMdiMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxmdapp.h"
#include "apxmdedf.h"
#include "apxmmdi1.h"


//{{TApxMdiMDIChild Implementation}}


//--------------------------------------------------------
// TApxMdiMDIChild
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxMdiMDIChild::TApxMdiMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient, TModule* module)
:
  TMDIChild(parent, title, !clientWnd ? new TApxMdiEditFile(0, 0, 0) : clientWnd, shrinkToClient, module)
{
  // INSERT>> Your constructor code here.

}


TApxMdiMDIChild::~TApxMdiMDIChild()
{
  Destroy();

  // INSERT>> Your destructor code here.

}
