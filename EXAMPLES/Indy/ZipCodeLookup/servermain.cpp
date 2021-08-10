//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormCreate(TObject *Sender)
{
     ZipCodeList = new TStringList();
     ZipCodeList->LoadFromFile(ExtractFilePath(Application->ExeName) + "ZipCodes.dat");
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormDestroy(TObject *Sender)
{
     delete ZipCodeList;        
     ZipCodeList = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TformMain::IdTCPServer1Connect(TIdPeerThread *AThread)
{
     AThread->Connection->WriteLn("Indy Zip Code Server Ready.");
}
//---------------------------------------------------------------------------

void __fastcall TformMain::IdTCPServer1Execute(TIdPeerThread *AThread)
{
     AnsiString sCommand;

     sCommand = AThread->Connection->ReadLn();

     if(SameText(sCommand, "QUIT"))
     {
          AThread->Connection->Disconnect();
     }
     else if(SameText(sCommand.SubString(1, 8), "ZipCode "))
     {
          AThread->Connection->WriteLn(ZipCodeList->Values[sCommand.SubString(9, MaxInt)]);
     }
}
//---------------------------------------------------------------------------

