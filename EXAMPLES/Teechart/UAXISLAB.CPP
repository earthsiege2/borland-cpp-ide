/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UAxisLab.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAxisLabelsForm *AxisLabelsForm;

/*
  This Sample Project shows how to set the Axis Labels at specific Axis
  positions.
  The key is the Chart.OnGetNextAxisLabel event.
  This event is called continuosly for each Axis Label until user decides
  to stop.
  At each call, you can specify the exact Axis value where a Label must be
  drawn.

  In this example, this event is used to set the BottomAxis labels to the
  first (1) day in month:   1/1/96,  2/1/96, 3/1/96..... 12/1/96

  This don"t needs necessarily to be datetime values.
  You can also set the Axis Labels in non-datetime axis.

  WARNING:
    Remember to set the Stop boolean variable to true when no more labels are
    needed.
    Remember also that using this event will NOT calculate Label used space or
    any Font size adjustment.
    TeeChart Axis will draw all labels you specify.
*/

//---------------------------------------------------------------------------
__fastcall TAxisLabelsForm::TAxisLabelsForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAxisLabelsForm::FormCreate(TObject *Sender)
{
  DefaultLabels = false;  // <-- boolean variable to show or not the demo

  LineSeries1->Clear();
  PointSeries1->Clear();
  for (int t = 1;t<101;t++) {
    LineSeries1->AddXY( Date()+t, 200+random(700),"",clTeeColor);  // <-- some random points
    PointSeries1->AddXY( Date()+t, 200+random(700),"",clTeeColor);
  }
}
//---------------------------------------------------------------------------
void __fastcall TAxisLabelsForm::RadioGroup1Click(TObject *Sender)
{
  //  Choose between default and custom labeling
  DefaultLabels = RadioGroup1->ItemIndex == 0;
  Chart1->Repaint();  //  <-- repaint chart to see changes
}
//---------------------------------------------------------------------------
void __fastcall TAxisLabelsForm::Chart1GetNextAxisLabel(TChartAxis *Sender,
      int LabelIndex, double &LabelValue, bool &Stop)
{
  Word year,month,day;
  if (!DefaultLabels) {
    if (Sender == Chart1->BottomAxis) {
      //  *****************************
      //  WARNING:

      //  Setting this axis increment:

      //  Chart1->BottomAxis->Increment  =  DateTimeStep[ dtOneMonth ];

      //  and...

      //  Chart1->BottomAxis->ExactDateTime  =  true ;

      //  Eliminates the need for the following code
      //  *****************************

      //  LabelValue has the "candidate" value where the Axis label will be painted->
      DecodeDate(LabelValue,year,month,day);
      //  we force that value to be the first day in month
      day = 1;
      month++;
      if (month>12) {
        month = 1;
        year++;
      }
      // then we set the preferred Label value
      LabelValue = EncodeDate(year,month,day);

    }
    else if (Sender == Chart1->LeftAxis) {
      // In this example, we want the Vertical Left Axis to show
      // labels only for positive values, starting at zero and
      // with 250 label increment
      if (LabelValue>=250)
        LabelValue = LabelValue+250;
      else
        LabelValue = 250;
    }
    //  we want more labels !!
    Stop = false;
  }
}
//---------------------------------------------------------------------------
