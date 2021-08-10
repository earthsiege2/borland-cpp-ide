//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987,1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "First.h"
#include "second.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent *Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject* /*Sender*/)
{
    Form2 = new TForm2(Application);
    Form2->ShowModal();
    delete Form2;
}
//----------------------------------------------------------------------------
 
