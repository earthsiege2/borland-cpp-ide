//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "servname.h"
#include "atmunit.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TServerNameDlg *ServerNameDlg;
//---------------------------------------------------------------------
__fastcall TServerNameDlg::TServerNameDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TServerNameDlg::FormShow(TObject/* */ *Sender)
{
   ServerNameLabel->Caption = FormATM->ATM->serverName();
   ServerNameEdit->Text = ServerNameLabel->Caption;
   ResultLabel->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TServerNameDlg::ConnectButtonClick(TObject/* */ *Sender)
{
  CountLabel->Caption = String(FormATM->TestConnection());
  if (CountLabel->Caption == "0")
     ResultLabel->Caption = "Connection Failed";
     else
     ResultLabel->Caption = "Connected";
}
//---------------------------------------------------------------------------

void __fastcall TServerNameDlg::OKBtnClick(TObject/* */ *Sender)
{
  if (CountLabel->Caption != String("0"))
  {
    FormATM->ATM->serverName(ServerNameEdit->Text);
  }
}
//---------------------------------------------------------------------------

