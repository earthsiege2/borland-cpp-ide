//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apmdmdi1.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxMdiDvMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxmddva.h"
#include "apmdmdi1.h"


//{{TApxMdiDvMDIChild Implementation}}


//--------------------------------------------------------
// TApxMdiDvMDIChild
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxMdiDvMDIChild::TApxMdiDvMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient, TModule* module)
:
  TMDIChild(parent, title, clientWnd, shrinkToClient, module)
{
  // INSERT>> Your constructor code here.

}


TApxMdiDvMDIChild::~TApxMdiDvMDIChild()
{
  Destroy();

  // INSERT>> Your destructor code here.

}
