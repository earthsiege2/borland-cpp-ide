//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DecClientCount(void)
{
  ClientCount->Caption = IntToStr(--FClientCount);
};
//---------------------------------------------------------------------------
void __fastcall TMainForm::IncClientCount(void)
{
  ClientCount->Caption = IntToStr(++FClientCount);
};
//---------------------------------------------------------------------------
void __fastcall TMainForm::DecQueryCount(void)
{
  QueryCount->Caption = IntToStr(--FQueryCount);
};
//---------------------------------------------------------------------------
void __fastcall TMainForm::IncQueryCount(void)
{
  QueryCount->Caption = IntToStr(++FQueryCount);
};
//---------------------------------------------------------------------------

