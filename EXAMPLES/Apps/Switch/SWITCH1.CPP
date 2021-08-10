//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Switch1.h"
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
    MessageBox(NULL, "Event Hander # 1", "Hey", MB_OK);
    Button1->OnClick = Button1Click2;
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click2(TObject* /*Sender*/)
{
    MessageBox(NULL, "Event Hander # 2", "There", MB_OK);
    Button1->OnClick = Button1Click;
}
//----------------------------------------------------------------------------

