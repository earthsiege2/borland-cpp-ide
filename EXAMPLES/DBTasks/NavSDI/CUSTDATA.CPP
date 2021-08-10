//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustData.h"
#include "DM.h"
#include "ToolBar.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmCustomer *fmCustomer;
//---------------------------------------------------------------------------
__fastcall TfmCustomer::TfmCustomer(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmCustomer::FormActivate(TObject *Sender)
{
  fmToolBar->SetNavigator(DM1->CustomerSource);
}
//---------------------------------------------------------------------
void __fastcall TfmCustomer::FormCreate(TObject *Sender)
{
  fmToolBar->SetNavigator(DM1->CustomerSource);
}
//---------------------------------------------------------------------
void __fastcall TfmCustomer::FormShow(TObject *Sender)
{
   fmToolBar->UpdateMenu();
}
//---------------------------------------------------------------------