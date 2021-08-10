//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustMod.h"
#include "DataMod.h"
//---------------------------------------------------------------------------
#pragma link "BASEMOD"
#pragma link "BASEMOD"
#pragma resource "*.dfm"
TCust *Cust;
//---------------------------------------------------------------------------
__fastcall TCust::TCust(TComponent* Owner)
  : TBase(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCust::FilterTextChange(TObject *Sender)
{
  FilterToggle->Checked = true;
  Data->Customers->Filtered = true;  
}
//---------------------------------------------------------------------
void __fastcall TCust::FilterToggleClick(TObject *Sender)
{
  Data->Customers->Filtered = FilterToggle->Checked;  
}
//---------------------------------------------------------------------