//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CtrlForm.h"
#include "DM.h"
#include "About.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFmCtrlGrid *FmCtrlGrid;
//---------------------------------------------------------------------------
__fastcall TFmCtrlGrid::TFmCtrlGrid(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFmCtrlGrid::FormShow(TObject *Sender)
{
	DM1->CalculateTotals( Sender, 0 );
}
//---------------------------------------------------------------------
void __fastcall TFmCtrlGrid::DBCtrlGrid1Enter(TObject *Sender)
{
	DBNavigator1->DataSource = DM1->dsHoldings;
}
//---------------------------------------------------------------------
void __fastcall TFmCtrlGrid::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TFmCtrlGrid::DBGrid1Enter(TObject *Sender)
{
  DBNavigator1->DataSource = DM1->dsMaster;
}
//---------------------------------------------------------------------
void __fastcall TFmCtrlGrid::About1Click(TObject *Sender)
{
  TFMAboutBox * fmAboutBox;

  fmAboutBox = new TFMAboutBox(this);
  fmAboutBox->ShowModal();
  delete fmAboutBox;
}
//---------------------------------------------------------------------