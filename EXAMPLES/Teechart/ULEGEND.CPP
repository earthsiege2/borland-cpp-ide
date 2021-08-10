/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ULegend.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLegendForm *LegendForm;
//---------------------------------------------------------------------------
__fastcall TLegendForm::TLegendForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLegendForm::LineSeries2AfterDrawValues(TObject *Sender)
{
  // we'll draw over PaintBox1
  for (int t = 0;t<Chart1->SeriesCount();t++) {  // for each Series in Chart
    PaintBox1->Canvas->Font->Color = Chart1->Series[t]->SeriesColor;  // set font color
    // draw the customized Series Title
    PaintBox1->Canvas->TextOut(40,20+16*t,
      "This is a long Series title: "+Chart1->SeriesTitleLegend(t));
  }
}
//---------------------------------------------------------------------------
void __fastcall TLegendForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(50); // random values
  LineSeries2->FillSampleValues(50);
}
//---------------------------------------------------------------------------
