//----------------------------------------------------------------------------
//  Project ApxDlgDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlgDv Application
//  FILE:         apxdlddc.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxDlgDvDlgClient (TDialog).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "apxdlgda.h"
#include "apxdlddc.h"


//{{TApxDlgDvDlgClient Implementation}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(TApxDlgDvDlgClient, TDialog)
//{{TApxDlgDvDlgClientRSP_TBL_BEGIN}}
//{{TApxDlgDvDlgClientRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxDlgDvDlgClient
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxDlgDvDlgClient::TApxDlgDvDlgClient(TDocument& doc, TWindow* parent)
:
  TView(doc), TDialog(parent, IDD_CLIENT)
{
  // INSERT>> Your constructor code here.

}


TApxDlgDvDlgClient::~TApxDlgDvDlgClient()
{
  // INSERT>> Your destructor code here.

}


bool TApxDlgDvDlgClient::CanClose()
{
  return TWindow::CanClose() && Doc->CanClose();
}
