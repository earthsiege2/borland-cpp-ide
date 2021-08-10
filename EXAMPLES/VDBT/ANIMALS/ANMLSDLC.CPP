//----------------------------------------------------------------------------
//  Project Animals
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    Animals Application
//  FILE:         AnmlsDlC.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TAnimalsDlgClient (TDialog).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "BeastWin.h"
#include "AnmlsDlC.h"


//{{TAnimalsDlgClient Implementation}}


//--------------------------------------------------------
// TAnimalsDlgClient
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TAnimalsDlgClient::TAnimalsDlgClient(TWindow* parent, TResId resId,
													TModule* module)
:
  TDialog(parent, resId, module)
{
  // INSERT>> Your constructor code here.
}


TAnimalsDlgClient::~TAnimalsDlgClient()
{
  Destroy();

  // INSERT>> Your destructor code here.
}

DEFINE_RESPONSE_TABLE2(TAnimalsDlgClient, TDialog, TVbxEventHandler)
END_RESPONSE_TABLE;
