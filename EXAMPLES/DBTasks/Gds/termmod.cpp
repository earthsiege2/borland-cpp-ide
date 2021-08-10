//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TermMod.h"
#include "DataMod.h"
//---------------------------------------------------------------------------
#pragma link "CustMod"
#pragma resource "*.dfm"
TTerm *Term;
//---------------------------------------------------------------------------
__fastcall TTerm::TTerm(TComponent* Owner)
  : TCust(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTerm::FilterTextChange(TObject *Sender)
{
  FilterToggle->Checked = true;
  Data->Orders->Filtered = true;  
}
//---------------------------------------------------------------------
void __fastcall TTerm::FilterToggleClick(TObject *Sender)
{
  Data->Orders->Filtered = FilterToggle->Checked;  
}
//---------------------------------------------------------------------