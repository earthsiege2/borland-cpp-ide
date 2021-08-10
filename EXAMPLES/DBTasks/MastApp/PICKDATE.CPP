//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pickdate.h"
//---------------------------------------------------------------------------
#pragma link "CCALENDR"
#pragma resource "*.dfm"
TBrDateForm *BrDateForm;
//---------------------------------------------------------------------------
__fastcall TBrDateForm::TBrDateForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TBrDateForm::SetDate(TDateTime Date)
{
  Calendar1->CalendarDate = Date;
}
//---------------------------------------------------------------------------
TDateTime TBrDateForm::GetDate()
{
  TDateTime Date = Calendar1->CalendarDate;
  return Date;
}//---------------------------------------------------------------------------
void __fastcall TBrDateForm::PrevMonthBtnClick(TObject *Sender)
{
  Calendar1->PrevMonth();
}
//---------------------------------------------------------------------------
void __fastcall TBrDateForm::NextMonthBtnClick(TObject *Sender)
{
  Calendar1->NextMonth();
}
//---------------------------------------------------------------------------
void __fastcall TBrDateForm::Calendar1Change(TObject *Sender)
{
   TitleLabel->Caption = FormatDateTime("MMMM, YYYY", Calendar1->CalendarDate);
}
//---------------------------------------------------------------------------
