//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClntMain.h"
#include "ClntAbout.h"
#include "MDClntDM.h"
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
void __fastcall TFormMain::About1Click(TObject *Sender)
{
  ShowAboutBox();        
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ApplyActionExecute(TObject *Sender)
{
  DataModule1->ApplyUpdates();        
}
//---------------------------------------------------------------------------

