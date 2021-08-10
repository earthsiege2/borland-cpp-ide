//----------------------------------------------------------------------------
//  Project ApxDlg
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlg Application
//  FILE:         apxdlgdc.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxDlgDlgClient (TDialog).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxdlgap.h"
#include "apxdlgdc.h"


//{{TApxDlgDlgClient Implementation}}


//--------------------------------------------------------
// TApxDlgDlgClient
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxDlgDlgClient::TApxDlgDlgClient(TWindow* parent, TResId resId, TModule* module)
:
  TDialog(parent, resId, module)
{
  // INSERT>> Your constructor code here.
}


TApxDlgDlgClient::~TApxDlgDlgClient()
{
  Destroy();

  // INSERT>> Your destructor code here.
}
