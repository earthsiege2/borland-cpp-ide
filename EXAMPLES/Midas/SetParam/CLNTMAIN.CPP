//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClntMain.h"
#include "ClntDM.h"
#include "ClntAbout.h"
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
void __fastcall TFormMain::ExitActionExecute(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::RetrieveActionExecute(TObject *Sender)
{
  DataModule1->FetchData(dtStartDate->DateTime, dtEndDate->DateTime);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::About1Click(TObject *Sender)
{
  ShowAboutBox();        
}
//---------------------------------------------------------------------------

