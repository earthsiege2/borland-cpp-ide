//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Cust.h"
#include "FindCust.h"
#include "About.h"
#include "DM.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmCustomers *fmCustomers;
//---------------------------------------------------------------------------
__fastcall TfmCustomers::TfmCustomers(TComponent* Owner)
  : TForm(Owner)
{
}
//--------------------------------------------------------------------------- 
void __fastcall TfmCustomers::AboutItemClick(TObject *Sender)
{

  TfmAboutBox* fmAbout = new TfmAboutBox(this);
  fmAbout->ShowModal();
  delete fmAbout;
}
//---------------------------------------------------------------------
void __fastcall TfmCustomers::BitBtn1Click(TObject *Sender)
{
  fmFindCust->ShowModal();
  if (fmFindCust->ModalResult == mrOk)
    DM2->Customer->GotoCurrent(DM2->CustLookup);  
}
//---------------------------------------------------------------------
