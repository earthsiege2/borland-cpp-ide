/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UMain.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMiniForm *MiniForm;
// This project show some very small mini-charts and some animation
// That mini-charts could be useful as small data-monitors in your
// forms or reports
//---------------------------------------------------------------------------
__fastcall TMiniForm::TMiniForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMiniForm::FormCreate(TObject *Sender)
{
  PosChart1 = -1; // starting position of vertical divider
  PosChart4 = NumPoints / 2;

  // Generate some random points
  LineSeries1->FillSampleValues(NumPoints);
  dynamic_cast<TCircledSeries*>(PieSeries1)->FillSampleValues(8);
  AreaSeries1->FillSampleValues(NumPoints);
  LineSeries2->FillSampleValues(NumPoints);
  BarSeries1->FillSampleValues(6);
  LineSeries3->FillSampleValues(NumPoints);
}
//---------------------------------------------------------------------------
void __fastcall TMiniForm::FormResize(TObject *Sender)
{
  // Equally resize the panels to center charts
  Chart2->Height = ClientHeight / 2;
  Chart3->Height = ClientHeight / 2;
  Panel1->Width = ClientWidth / 2;
}

// This procedure changes the Series values every second
void TMiniForm::RefreshMonitorChart(TChart* Chart, int &PosChart)
{
  double LastValueWas;
  PosChart++;
  if (PosChart >= NumPoints)
    PosChart = 0;
  for (int t = 0;t<Chart->SeriesCount()-1;t++) {
    if (PosChart == 0)      {
      Chart->LeftAxis->Automatic = true;
      Chart->LeftAxis->SetMinMax(
        Chart->MinYValue(Chart->LeftAxis),Chart->MaxYValue(Chart->LeftAxis));
      LastValueWas = Chart->Series[t]->YValues->Last();
    }
    else
      LastValueWas = Chart->Series[t]->YValue[PosChart-1];

    // change the value for a new random one
    Chart->Series[t]->YValue[PosChart] =
      LastValueWas+random(ChartSamplesMax)- (ChartSamplesMax / 2);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMiniForm::Timer1Timer(TObject *Sender)
{
  RefreshMonitorChart(Chart1,PosChart1);       // refresh chart1
  RefreshMonitorChart(Chart4,PosChart4);       // refresh chart4
  PieSeries1->RotationAngle = (PieSeries1->RotationAngle+1) % 359;  // rotate pie

  // change Bar Series values }
  int tmpPos = random(BarSeries1->Count());
  BarSeries1->YValue[tmpPos] =
    BarSeries1->YValue[tmpPos]*(80.0+random(40))/100.0;
}
//---------------------------------------------------------------------------
void __fastcall TMiniForm::LineSeries2AfterDrawValues(TObject *Sender)
{
  // this event draws the red divider in Chart1
  if (PosChart1 >= 0) {
    Chart1->Canvas->Pen->Color = clRed;
    Chart1->Canvas->DoVertLine(Chart1->Series[0]->CalcXPos(PosChart1),  // x
    Chart1->ChartRect.Top+1,                // initial Y
    Chart1->ChartRect.Bottom-1);            // ending Y
  }
}
//---------------------------------------------------------------------------
void __fastcall TMiniForm::LineSeries3AfterDrawValues(TObject *Sender)
{
  // this event draws the blue divider in Chart4 }
   if (PosChart4 >= 0) {
     Chart1->Canvas->Pen->Color = clBlue;
     Chart1->Canvas->DoVertLine(
       Chart1->Series[0]->CalcXPos(PosChart4),  // x
       Chart1->ChartRect.Top+1,                // initial Y
       Chart1->ChartRect.Bottom-1);            // ending Y
   }
}
//---------------------------------------------------------------------------
