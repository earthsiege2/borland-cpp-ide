//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BaseMod.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TBase *Base;
//---------------------------------------------------------------------------
__fastcall TBase::TBase(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBase::Button1Click(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------
