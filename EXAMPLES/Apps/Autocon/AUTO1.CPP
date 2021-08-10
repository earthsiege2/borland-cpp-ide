//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <sysdefs.h>
#include "..\autosrv\autosrv_tlb.h"
#include "auto1.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent *Owner)
  : TForm(Owner)
{
  try
  {
       AutoServer.BindDefault();
       EditServer = CoEditServer::Create();
  }
  catch (...)
  {
       ShowMessage("Please build and run the \\AutoSrv\\autosrv example before this one.");
       Application->Terminate();
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::setvalDClick(TObject *Sender)
{
     AutoServer.EditStr = WideString(Edit1->Text);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::getvalDClick(TObject *Sender)
{
     Edit1->Text = AutoServer.EditStr;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::clearDClick(TObject *Sender)
{
     // Call a server function
     AutoServer.Clear();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::functionDClick(TObject *Sender)
{
     WideString retval;

     AutoServer.SetThreeStr(WideString("one"),WideString("two"),
         WideString("three"), &retval);
     Edit1->Text = retval;     
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::setvalVClick(TObject *Sender)
{
     //call the server's setter function
     EditServer->set_EditStr(WideString(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::functionVClick(TObject *Sender)
{
     WideString p1("This ");
     WideString p2("is a ");
     WideString p3("test.");
     WideString retval;

     // The [out, retval] parameter most come last.
     EditServer->SetThreeStr(p1, p2, p3, &retval);
     Edit1->Text = retval;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::clearVClick(TObject *Sender)
{
     // Call a server function
     EditServer->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::getvalVClick(TObject *Sender)
{
     WideString str;
     EditServer->get_EditStr(&str);
     Edit1->Text = AnsiString(str);
}
//---------------------------------------------------------------------------
