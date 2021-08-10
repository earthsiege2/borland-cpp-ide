//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxomdi1.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxOleMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxolapp.h"
#include "apxomdi1.h"


//{{TApxOleMDIChild Implementation}}


//--------------------------------------------------------
// TApxOleMDIChild
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxOleMDIChild::TApxOleMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd, bool shrinkToClient, TModule* module)
:
  TMDIChild(parent, title, clientWnd, shrinkToClient, module)
{
  // INSERT>> Your constructor code here.

}


TApxOleMDIChild::~TApxOleMDIChild()
{
  Destroy();

  // INSERT>> Your destructor code here.

}
