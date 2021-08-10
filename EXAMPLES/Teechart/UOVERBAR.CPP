/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UOverbar.h"
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOverBarForm *OverBarForm;

// This form shows 3 bar series in a overlayed layout.
// Each Bar Series has a different BarWidthPercent.
// The order Series are drawn is the most important thing. See below.

//---------------------------------------------------------------------------
__fastcall TOverBarForm::TOverBarForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TOverBarForm::ChangeOverBars()
{
  //  compress / expand the overlayed space between bars
  BarSeries3->BarWidthPercent = ScrollBar2->Position;
  BarSeries1->BarWidthPercent = ScrollBar2->Position-floor(ScrollBar2->Position*55.0/100.0);
  BarSeries2->BarWidthPercent = ScrollBar2->Position-floor(ScrollBar2->Position*35.0/100.0);
}

void __fastcall TOverBarForm::FormCreate(TObject *Sender)
{
  //  lets fill the 3 Bar Series with some random data
  //  Series3 has the biggest values, while Series1 has the smaller values
  BarSeries3->Clear();
  for (int t = 1;t<11;t++)
    BarSeries3->Add( 100+random(30),"", clTeeColor);
  BarSeries2->Clear();
  for (int t = 1;t<11;t++)
    BarSeries2->Add( 50+random(10), "", clTeeColor);
  BarSeries1->Clear();
  for (int t = 1;t<11;t++)
    BarSeries1->Add( 20+random(10), "", clTeeColor);
  ChangeOverBars();

  BarSeries1->Cursor = crUpArrow;
  BarSeries2->Cursor =(TCursor)crTeeHand;
  BarSeries3->Cursor = crHandPoint;

}
//---------------------------------------------------------------------------
void __fastcall TOverBarForm::BarSeries2Click(TChartSeries *Sender,
      int ValueIndex, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ShowMessage("You clicked the Red Bar at point #: "+ String(ValueIndex));
}
//---------------------------------------------------------------------------
void __fastcall TOverBarForm::BarSeries1Click(TChartSeries *Sender,
      int ValueIndex, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ShowMessage("You clicked the Green Bar at point #: "+ String(ValueIndex));
}
//---------------------------------------------------------------------------
void __fastcall TOverBarForm::CBPatternsClick(TObject *Sender)
{
  if (CBPatterns->Checked) {
    BarSeries1->BarBrush->Style = bsFDiagonal;
    BarSeries2->BarBrush->Style = bsBDiagonal;
    BarSeries3->BarBrush->Style = bsDiagCross;
    Chart1->BackColor = clWhite;
  }
  else {
    BarSeries1->BarBrush->Style = bsSolid;
    BarSeries2->BarBrush->Style = bsSolid;
    BarSeries3->BarBrush->Style = bsSolid;
    Chart1->BackColor = clTeeColor;
  }
}
//---------------------------------------------------------------------------
void __fastcall TOverBarForm::BarSeries3Click(TChartSeries *Sender,
      int ValueIndex, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ShowMessage("You clicked the Blue Bar at point #: "+ String(ValueIndex));
}
//---------------------------------------------------------------------------
void __fastcall TOverBarForm::ScrollBar1Change(TObject *Sender)
{
  //  increase / decrease the 3 Series OffsetPercent property }
  //  This will make partially overlay }
  BarSeries3->OffsetPercent = ScrollBar1->Position;
  BarSeries1->OffsetPercent = ScrollBar1->Position-floor(ScrollBar1->Position*55.0/100.0);
  BarSeries2->OffsetPercent = ScrollBar1->Position-floor(ScrollBar1->Position*35.0/100.0);

}
//---------------------------------------------------------------------------

void __fastcall TOverBarForm::ScrollBar2Change(TObject *Sender)
{
  ChangeOverBars();
}
//---------------------------------------------------------------------------

 