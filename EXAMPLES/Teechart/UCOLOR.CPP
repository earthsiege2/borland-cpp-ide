/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UColor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TColoredForm *ColoredForm;
//---------------------------------------------------------------------------
__fastcall TColoredForm::TColoredForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TColoredForm::AddColors(TChartSeries* Series)
{
  double step = (Series->GetVertAxis->Maximum - Series->GetVertAxis->Minimum)/10.0;
  for (int t=0;t<Series->Count();t++)
    Series->ValueColor[t] = GetDefaultColor(
      (Series->YValue[t] - (int)(Series->GetVertAxis->Minimum) / step));
}

void __fastcall TColoredForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(100);
  PointSeries1->FillSampleValues(100);
  Chart1->LeftAxis->AdjustMaxMin();
  AddColors(LineSeries1);
  AddColors(PointSeries1);
}
//---------------------------------------------------------------------------
void __fastcall TColoredForm::CheckBox1Click(TObject *Sender)
{
  Chart1->LeftAxis->Inverted = CheckBox1->Checked;
}
//---------------------------------------------------------------------------
