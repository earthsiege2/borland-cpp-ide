//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LastValu.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDigitalForm *DigitalForm;

  /*
  This forms show 4 line series in "Stairs" mode.

  ( LineSeries1.Stairs  =  true ; )

  Legend Style is "lsLastValues" meaning the Legend will draw the
  Last value for each Series.
  */

//---------------------------------------------------------------------------
__fastcall TDigitalForm::TDigitalForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDigitalForm::FormCreate(TObject *Sender)
{
  Chart1->ApplyZOrder = CheckBox4->Checked;     // ZOrder or not ZOrder
  Chart1->Legend->Inverted = true;
  // Fill Series with random values
  for (int t = 0;t<Chart1->SeriesCount();t++) {
    Chart1->Series[t]->Clear();
    for (int tt = 1;tt<101;tt++)
      Chart1->Series[t]->Add( 2*t+random(2), "", clTeeColor);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::CheckBox1Click(TObject *Sender)
{
  Timer1->Enabled = CheckBox1->Checked;  // start / stop animation
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::Timer1Timer(TObject *Sender)
{
  Timer1->Enabled = false;  // <-- stop the timer

  // Now, add a new point to each Series
  for (int t = 0;t<Chart1->SeriesCount();t++)
    Chart1->Series[t]->Add( 2*t+random(2),"",clTeeColor);

  // Scroll the Horizontal Axis
  Chart1->BottomAxis->Automatic  =  false;        // <-- we dont want automatic scaling
  Chart1->BottomAxis->Maximum  =  LineSeries1->XValues->Last();
  Chart1->BottomAxis->Minimum  =  Chart1->BottomAxis->Maximum - 100;   // we want to see the last 100 points only

  // re-start timer
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::CheckBox2Click(TObject *Sender)
{
  Chart1->View3D = CheckBox2->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::CheckBox3Click(TObject *Sender)
{
  if (CheckBox3->Checked)
    Chart1->Legend->LegendStyle = lsLastValues;
  else
    Chart1->Legend->LegendStyle = lsAuto;
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::Chart1GetLegendText(TCustomAxisPanel *Sender,
      TLegendStyle LegendStyle, int Index, AnsiString &LegendText)
{
  // we want to show the Series Title as well as the Last Values
  if (LegendStyle == lsLastValues)
     LegendText = LegendText+" --> "+Chart1->Series[Index]->Title;
}
//---------------------------------------------------------------------------
void __fastcall TDigitalForm::CheckBox4Click(TObject *Sender)
{
  Chart1->ApplyZOrder = CheckBox4->Checked;
  Chart1->Repaint();
}
//---------------------------------------------------------------------------

