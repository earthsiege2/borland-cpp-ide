//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <EncdDecd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

const char* sPOST_FileExt = ".sop";
const char* sPOST_Filter  = "SOAP POST Files (*.sop)|*.SOP";
const char* sPOST_Request = "Request";
const char* sPOST_URL     = "URL";
const char* sPOST_Action  = "SOAPAction";
const char* sPOST_Untitled= "Untitled.sop";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileNewClick(TObject *Sender)
{
  Request->Text = "";
  Response->Text = "";
  URL->Text = "";
  SOAPAction->Text = "";
  Caption = sPOST_Untitled;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileSaveClick(TObject *Sender)
{
  SaveDialog1->DefaultExt = sPOST_FileExt;
  SaveDialog1->Filter = sPOST_Filter;
  if (SaveDialog1->Execute())
  {
    sPointer<TStringList> sl(new TStringList());
    sl->Add(AnsiString(sPOST_Request) + AnsiString("=") + EncodeString(Request->Text));
    sl->Add(AnsiString(sPOST_URL) + AnsiString("=") + EncodeString(URL->Text));
    sl->Add(AnsiString(sPOST_Action) + AnsiString("=") + EncodeString(SOAPAction->Text));
    sl->SaveToFile(SaveDialog1->FileName);
    Caption = SaveDialog1->FileName;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileOpenClick(TObject *Sender)
{
  OpenDialog1->DefaultExt = sPOST_FileExt;
  OpenDialog1->Filter = sPOST_Filter;
  if (OpenDialog1->Execute())
  {
    sPointer<TStringList> sl(new TStringList());
    sl->LoadFromFile(OpenDialog1->FileName);
    Request->Text = DecodeString(sl->Values[sPOST_Request]);
    URL->Text = DecodeString(sl->Values[sPOST_URL]);
    SOAPAction->Text = DecodeString(sl->Values[sPOST_Action]);
    Response->Text = "";
    Caption = SaveDialog1->FileName;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PostBtnClick(TObject *Sender)
{
  sPointer<TMemoryStream> stream(new TMemoryStream());
  HTTPReqResp1->URL = URL->Text;
  HTTPReqResp1->SoapAction = SOAPAction->Text;
  HTTPReqResp1->Execute(Request->Text, &stream);
  sPointer<TStringStream> strStream(new TStringStream(""));
  strStream->CopyFrom(&stream, 0);
  Response->Text = strStream->DataString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Caption = "PostTool";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

