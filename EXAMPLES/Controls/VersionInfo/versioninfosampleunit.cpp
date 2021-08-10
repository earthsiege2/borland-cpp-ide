//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "VersionInfoSampleUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VersionInfoComponent"
#pragma link "VersionInfoUI"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btOKClick(TObject *Sender)
{
  Close();    
}
//---------------------------------------------------------------------------



