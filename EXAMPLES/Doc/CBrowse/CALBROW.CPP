//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CalBrow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CCALENDR"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BitBtn1Click(TObject *Sender)
{
  Calendar1->PrevYear();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtn2Click(TObject *Sender)
{
  Calendar1->PrevMonth();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtn3Click(TObject *Sender)
{
  Calendar1->NextMonth();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtn4Click(TObject *Sender)
{
  Calendar1->NextYear();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Calendar1Change(TObject *Sender)
{
  Caption = "Calendar Browser   " + DateToStr(Calendar1->CalendarDate);        
}
//---------------------------------------------------------------------------

