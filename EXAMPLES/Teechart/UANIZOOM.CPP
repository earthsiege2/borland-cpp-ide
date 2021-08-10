/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UAniZoom.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnimatedZoom *FormAnimatedZoom;
//---------------------------------------------------------------------------
__fastcall TFormAnimatedZoom::TFormAnimatedZoom(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TFormAnimatedZoom::RandomValues(TChartSeries* ASeries)
{
  int tmp=0;
  ASeries->Clear();
  for (int t=1;t<51;t++) {
    tmp=tmp+random(10000)-5000;
    ASeries->Add(tmp, "", clTeeColor);
  }
}

void __fastcall TFormAnimatedZoom::FormCreate(TObject *Sender)
{
  ScrollBar1->Position=Chart1->AnimatedZoomSteps;
  RandomValues(LineSeries1);
  RandomValues(LineSeries2);
  RandomValues(LineSeries3);
  RandomValues(LineSeries4);
  RandomValues(LineSeries5);
  RandomValues(PointSeries1);
  Chart1->AnimatedZoom=false;
  Chart1->ZoomPercent(5);
  Chart1->AnimatedZoom=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormAnimatedZoom::CheckBox1Click(TObject *Sender)
{
  Chart1->AnimatedZoom=CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimatedZoom::CheckBox2Click(TObject *Sender)
{
  Chart1->View3D=CheckBox2->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimatedZoom::BitBtn1Click(TObject *Sender)
{
  BitBtn1->Enabled=false;
  BitBtn2->Enabled=false;
  Chart1->ZoomPercent(115);
  BitBtn1->Enabled=true;
  BitBtn2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimatedZoom::BitBtn2Click(TObject *Sender)
{
  BitBtn1->Enabled=false;
  BitBtn2->Enabled=false;
  Chart1->ZoomPercent(85);
  BitBtn1->Enabled=true;
  BitBtn2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimatedZoom::ScrollBar1Change(TObject *Sender)
{
  Chart1->AnimatedZoomSteps=ScrollBar1->Position;
}
//---------------------------------------------------------------------------

