//----------------------------------------------------------------------------
//Standard Template Library Examples
// 	Adapted from console demos.
//
//Borland C++Builder
//Copyright (c) 1987, 2000 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "std1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
int ct;
TForm1 *Form1;
extern int accum_ex();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void build_all()
{
     accum_ex();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    for (int j = 0; j < 200; j++)
    	if (Memo1->Lines->Strings[j] != "")
    		Memo1->Lines->Strings[j] = " "; // make space in Memo
    ct = 0;
	switch (ComboBox1->ItemIndex)
    {
       case 0:
        build_all();
        break;
       case 1:
        accum_ex();
       	break;
       default:
        ShowMessage ("Sorry, not implemented yet");
        break;
    }
}
//---------------------------------------------------------------------------