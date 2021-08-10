//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustData.h"
#include "DM.h"
#include "Toolbar.h"
#include "CustOrds.h"
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
  fmToolbar->SetNavigator(DM1->CustomersSource);
}
//---------------------------------------------------------------------
void __fastcall TfmCustomer::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  int I;
  bool bl = false;

  for(I=Application->ComponentCount; I==1;I--)
  {
    if(Application->Components[I] == fmCustOrd)
      bl = true;
    if(!bl)
      fmToolbar->DBNavigator1->DataSource = NULL;
  }
}
//---------------------------------------------------------------------