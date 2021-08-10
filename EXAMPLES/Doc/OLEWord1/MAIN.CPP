//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

/*
NOTE: This program will only function correctly with
the US version of Microsoft Word
*/

#include "main.h"
#include <comobj.hpp>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::TalkToWordClick(TObject *Sender)
{
     Variant V;

     V = CreateOleObject("Word.Basic");
     V.Exec(Procedure("AppShow"));
     V.Exec(Procedure("FileNew") << "Normal");
     V.Exec(Procedure("Insert") << "Hello from Borland");
}
//---------------------------------------------------------------------