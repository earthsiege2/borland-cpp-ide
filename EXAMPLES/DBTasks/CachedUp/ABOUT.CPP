//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "about.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutDialog *AboutDialog;
//---------------------------------------------------------------------------
__fastcall TAboutDialog::TAboutDialog(TComponent* Owner)
  : TForm(Owner)
{
}

void __fastcall ShowAboutDialog()
{
  TAboutDialog      *AboutDlg;

  AboutDlg = new TAboutDialog(NULL);

  AboutDlg->AboutMemo->Lines->LoadFromFile(ExtractFilePath(ParamStr(0))+"ABOUT.TXT");
  AboutDlg->ShowModal();
  delete AboutDlg;
}

//---------------------------------------------------------------------------