//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RecForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TRecViewForm *RecViewForm;
//---------------------------------------------------------------------------
__fastcall TRecViewForm::TRecViewForm(TComponent* Owner)
  : TStdDataForm(Owner)
{
  Cust->Open();
  Orders->Open();
}
//---------------------------------------------------------------------------

