//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CustOrds.h"
#include "DM.h"
#include "Toolbar.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmCustOrd *fmCustOrd;
//---------------------------------------------------------------------------
__fastcall TfmCustOrd::TfmCustOrd(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmCustOrd::FormActivate(TObject *Sender)
{
  if(ActiveControl == DBGrid1)
    DBGrid1Enter(NULL);
}
//---------------------------------------------------------------------
void __fastcall TfmCustOrd::DBGrid1Enter(TObject *Sender)
{
  fmToolbar->SetNavigator(DM1->OrdersSource);
}
//---------------------------------------------------------------------
