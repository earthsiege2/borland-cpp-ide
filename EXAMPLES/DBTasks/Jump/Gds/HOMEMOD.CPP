//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HomeMod.h"
#include "CustMod.h"
#include "TermMod.h"
//---------------------------------------------------------------------------
#pragma link "BASEMOD"
#pragma resource "*.dfm"
THome *Home;
//---------------------------------------------------------------------------
__fastcall THome::THome(TComponent* Owner)
  : TBase(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THome::Button2Click(TObject *Sender)
{
  Cust->Show();  
}
//---------------------------------------------------------------------
void __fastcall THome::Button3Click(TObject *Sender)
{
  Term->Show();  
}
//---------------------------------------------------------------------