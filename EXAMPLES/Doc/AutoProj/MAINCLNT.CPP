//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>

#include "mainclnt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ServerExecuteActionExecute(TObject *Sender)
{
  try{
    // Start the Server Object
    if (!MyAutoServer)
      MyAutoServer = CoMyAuto::Create();
    if (!MyAutoServer)
      return;
    //Pass strings as BSTRs
    MyAutoServer->MyProp = WideString(Edit1->Text).c_bstr();
    MyAutoServer->ShowDialog();
  }
  catch(EOleSysError& e)
  {
    char buf[256];
    sprintf(buf, "%s.\n\n%s", e.Message.c_str(),
            "Make sure you compile Srvr first and run it either from\n"
            "the commmand line or from C++Builder.\n");
    ShowMessage(buf);
  }
}
//---------------------------------------------------------------------------

