/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UScrollB.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TScrollBarForm *ScrollBarForm;
//---------------------------------------------------------------------------
__fastcall TScrollBarForm::TScrollBarForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TScrollBarForm::CalcScrollBarPos()
{
  double Difer;
  ChangingBars = true;
  if (Chart1->BottomAxis->Automatic)
    ScrollBar1->Enabled = false;
  else {
    ScrollBar1->Enabled = true;
    Difer = Chart1->MaxXValue(Chart1->BottomAxis) -
      Chart1->MinXValue(Chart1->BottomAxis);
    if (Difer>0)
       ScrollBar1->Position = floor(100.0*(
         Chart1->BottomAxis->Minimum-Chart1->MinXValue(Chart1->BottomAxis))/Difer);
  }
  if (Chart1->LeftAxis->Automatic)
    ScrollBar2->Enabled = false;
  else {
    ScrollBar2->Enabled = true;
    Difer = Chart1->MaxYValue(Chart1->LeftAxis) -
      Chart1->MinYValue(Chart1->LeftAxis);
    if (Difer>0)
    ScrollBar2->Position = floor(100.0*(
      Chart1->LeftAxis->Minimum-Chart1->MinYValue(Chart1->LeftAxis))/Difer);
  }
  ChangingBars = false;
}

void __fastcall TScrollBarForm::ScrollBar1Change(TObject *Sender)
{
  double Difer;
  if (!ChangingBars) {
    Difer = Chart1->BottomAxis->Maximum-Chart1->BottomAxis->Minimum;
    Chart1->BottomAxis->Maximum = Chart1->MaxXValue(Chart1->BottomAxis)-ScrollBar1->Position*Difer/100.0;
    Chart1->BottomAxis->Minimum = Chart1->BottomAxis->Maximum-Difer;
  }
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(1000);
  Chart1->ZoomPercent(115);
  CalcScrollBarPos();
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::ScrollBar2Change(TObject *Sender)
{
  double Difer;
  if (!ChangingBars) {
    Difer = Chart1->LeftAxis->Maximum-Chart1->LeftAxis->Minimum;
    Chart1->LeftAxis->Minimum = Chart1->MinYValue(Chart1->LeftAxis)+ScrollBar2->Position*Difer/100.0;
    Chart1->LeftAxis->Maximum = Chart1->LeftAxis->Minimum+Difer;
  }
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::Chart1Scroll(TObject *Sender)
{
  CalcScrollBarPos();
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::Chart1UndoZoom(TObject *Sender)
{
  CalcScrollBarPos();
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::Chart1Zoom(TObject *Sender)
{
  CalcScrollBarPos();
}
//---------------------------------------------------------------------------
void __fastcall TScrollBarForm::Chart1Resize(TObject *Sender)
{
  ScrollBar1->Left = 0;
  ScrollBar1->Top = Chart1->Height-ScrollBar1->Height;
  ScrollBar1->Width = Chart1->Width;

  ScrollBar2->Left = Chart1->Width-ScrollBar2->Width;
  ScrollBar2->Top = 0;
  ScrollBar2->Height = Chart1->Height;
}
//---------------------------------------------------------------------------
