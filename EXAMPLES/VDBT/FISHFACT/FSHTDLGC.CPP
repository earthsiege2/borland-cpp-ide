/*  Project fishfact
    Borland International
    Copyright © 1996. All Rights Reserved.

    SUBSYSTEM:    fishfact.exe Application
    FILE:         fshtdlgc.cpp
    AUTHOR:       


    OVERVIEW
    ========
    Source file for implementation of fishfactTDLGClient (TDialog).

*/


#include <owl\pch.h>
#pragma hdrstop

#include "ffactwin.h"
#include "fshtdlgc.h"


//{{fishfactTDLGClient Implementation}}


//////////////////////////////////////////////////////////
// fishfactTDLGClient
// ==========
// Construction/Destruction handling.
fishfactTDLGClient::fishfactTDLGClient (TWindow *parent, TResId resId, TModule *module)
    : TDialog(parent, resId, module)
{
    // INSERT>> Your constructor code here.
}


fishfactTDLGClient::~fishfactTDLGClient ()
{
    Destroy();

    // INSERT>> Your destructor code here.
}

DEFINE_RESPONSE_TABLE2(fishfactTDLGClient, TDialog, TVbxEventHandler)
END_RESPONSE_TABLE;

