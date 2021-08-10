//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Pooling.h"
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

void __fastcall TFormMain::TestBtnClick(TObject *Sender)
{
  unsigned short Hour, Min, Sec, MSec;
  // Start the timer
  dtStart = TDateTime::CurrentTime();
  StartTimeEdt->Text= TimeToStr(dtStart);

  // Run the test
  DoTest();

  // End the timer, and calculate the elapsed time
  dtEnd = TDateTime::CurrentTime();
  EndTimeEdt->Text = TimeToStr(dtEnd);

  dtElp = dtEnd - dtStart;

  dtElp.DecodeTime(&Hour, &Min, &Sec, &MSec);

  ElpTimeEdt->Text = IntToStr( Hour * 60 + Min )  + ':' + IntToStr( Sec ) + '.' + IntToStr( MSec );
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::DoTest(void)
{

  // Close bde to ensure MTS Pooling param will be used
  Session->Close();
  for (int i = 0; i < StrToInt(Count->Text); i++)
  {
    Database1->Connected = true;
    Query1->Active = true;
    Query1->Active = false;
    Database1->Connected = false;

  }
  Session->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MTSPoolingClick(TObject *Sender)
{
  // Set the registry value to whatever the flag is
  TRegistry *reg = new TRegistry();
  reg->Access = KEY_ALL_ACCESS;
  reg->RootKey = HKEY_LOCAL_MACHINE;
  if ( reg->OpenKey(MTSRegistryKey, false) )
  {
    if (MTSPooling->Checked)
      reg->WriteString("MTS POOLING", "TRUE");
    else
      reg->WriteString("MTS POOLING", "FALSE");
    reg->CloseKey();
  }
  delete reg;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormActivate(TObject *Sender)
{
  String keyValue;
  // Determine the current registry value
  TRegistry *reg = new TRegistry();
  reg->RootKey = HKEY_LOCAL_MACHINE;
  if (reg->OpenKey(MTSRegistryKey, false) )
  {
    if (keyValue == "TRUE")
      MTSPooling->Checked = true;
    else
      MTSPooling->Checked = false;
    reg->CloseKey();
  }
  delete reg;
}
//---------------------------------------------------------------------------

