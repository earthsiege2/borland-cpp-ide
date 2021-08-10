/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Basic.h"
#include <stdlib.h>
#include <math.h>
#include <Printers.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBasicForm *BasicForm;
//---------------------------------------------------------------------------
__fastcall TBasicForm::TBasicForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::FormCreate(TObject *Sender)
{
  Summer->FillSampleValues(20); // <-- Some random points
  Winter->FillSampleValues(20); // <-- Some random points

  // Will need a Bar Series with special random values,
  // so we dont call the standard FillSampleValues method
  for (int t=1;t<13;t++)
    BarSeries1->Add(random(1000),ShortMonthNames[t],GetDefaultColor(t));

  South->FillSampleValues(20); // <-- Some random points
  North->FillSampleValues(20); // <-- Some random points

  Speaking->FillSampleValues(20); // <-- Some random points
  Reading->FillSampleValues(20); // <-- Some random points
  Writing->FillSampleValues(20); // <-- Some random points

  //  Force to resize the four charts
  FormResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::CheckBox1Click(TObject *Sender)
{
  Timer1->Enabled=CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void TBasicForm::Animate(TChartSeries* Series)
{
  Series->Delete(0); // <-- remove the first point
  // Add a new random point
  Series->AddXY(Series->XValues->Last()+1,
    Series->YValues->Last()+(random(ChartSamplesMax)-(ChartSamplesMax/2)),
    "",clTeeColor);
}

void __fastcall TBasicForm::Timer1Timer(TObject *Sender)
{
  String tmpLabel;
  TColor tmpColor;
  Animate(Summer);
  Animate(Winter);
  // BarSeries1 has special treatment to animate
  tmpLabel=BarSeries1->XLabel[0];
  tmpColor=BarSeries1->ValueColor[0];
  BarSeries1->Delete(0);
  BarSeries1->AddXY(BarSeries1->XValues->Last()+1,random(1000),tmpLabel,tmpColor);

  // Change Bar Style randomly
  if (random(10)<1)
    BarSeries1->BarStyle=TBarStyle(random(8));

  Animate(South);
  Animate(North);
  Animate(Speaking);
  Animate(Reading);
  Animate(Writing);

  // Change Pointer Style randomly
  if (random(10)<1)
    Speaking->Pointer->Style=TSeriesPointerStyle(random(9));
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::FormResize(TObject *Sender)
{
  // Top and bottom Panel positioning
  int w=ClientWidth-4-Panel1->Width;
  Panel2->Width=w-4;
  Panel1->Height=ClientHeight-Panel2->Height-4;
  int h=Panel1->Height;
  // Top Left Chart
  dynamic_cast<TCustomPanel*>(Chart1)->SetBounds(Panel1->Width,Panel2->Height,w / 2,h / 2);
  // Bottom Left Chart
  dynamic_cast<TCustomPanel*>(Chart2)->SetBounds(Panel1->Width,Panel2->Height+Chart1->Height,w / 2,h / 2);
  // Top Right Chart
  dynamic_cast<TCustomPanel*>(Chart3)->SetBounds(Panel1->Width+Chart1->Width+1,Chart1->Top,w / 2,h / 2);
  // Bottom Right Chart
  dynamic_cast<TCustomPanel*>(Chart4)->SetBounds(Chart3->Left,Chart2->Top,w / 2,h / 2);
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::FormShow(TObject *Sender)
{
  FormResize(this); // <-- to align charts
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::BitBtn1Click(TObject *Sender)
{
  int tmpH,tmpW,tmpWMargin,tmpHMargin; // margins
  TPrinterOrientation OldOrientation;
  Screen->Cursor = crHourGlass;
  OldOrientation=Printer()->Orientation;  // <-- save paper orientation
  Printer()->Orientation=poLandscape; // <-- Force Horizontal paper
  try {
    Printer()->BeginDoc();       // <-- start printer job
    try {
      Printer()->Title="TeeChart Printing Demo";

      switch (RadioGroup1->ItemIndex) {
        case 0: {
          // screen proportional
          Chart1->PrintResolution= 0;
          Chart2->PrintResolution= 0;
          Chart3->PrintResolution= 0;
          Chart4->PrintResolution= 0;
          break;
        }
        case 1 : {
          // thin lines and small fonts
          Chart1->PrintResolution= -100;
          Chart2->PrintResolution= -100;
          Chart3->PrintResolution= -100;
          Chart4->PrintResolution= -100;
          break;
        }
      }

      // Print the four charts, each one at a different paper position

      // CALCULATE HORIZONTAL MARGIN
      tmpW=Printer()->PageWidth;
      tmpWMargin=floor(5.0*tmpW/100.0); // <-- 5% margins
      tmpW=tmpW-2*tmpWMargin;  // <-- left and right margins
      tmpW=tmpW / 2; // half height for left and right charts

      // CALCULATE VERTICAL MARGIN
      tmpH=Printer()->PageHeight;
      tmpHMargin=floor(5.0*tmpH/100.0);  // <-- 5% margins
      tmpH=tmpH-2*tmpHMargin;  // <-- bottom and top margins
      tmpH=tmpH / 2; // half height for top and bottom charts

      // left / top chart
      Chart1->PrintPartial( Rect( tmpWMargin,tmpHMargin,
                                 tmpWMargin+tmpW,tmpHMargin+tmpH ) );

      // right / top chart
      Chart3->PrintPartial( Rect( tmpWMargin+tmpW,tmpHMargin,
                                 tmpWMargin+2*tmpW,tmpHMargin+tmpH ) );

      // left / bottom chart
      Chart2->PrintPartial( Rect( tmpWMargin,tmpHMargin+tmpH,
                                 tmpWMargin+tmpW,tmpHMargin+2*tmpH ) );

      // right / bottom chart
      Chart4->PrintPartial( Rect( tmpWMargin+tmpW,tmpHMargin+tmpH,
                                 tmpWMargin+2*tmpW,tmpHMargin+2*tmpH ) );

      Printer()->EndDoc(); // <-- end job and print !!
    }
    catch (...) {
       Printer()->Abort();
       Printer()->EndDoc();
       throw;
    }
  }
  __finally {
    Printer()->Orientation=OldOrientation;  // <-- restore paper orientation
    Screen->Cursor=crDefault; // <-- restore cursor
  }
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::CheckBox2Click(TObject *Sender)
{
  Chart1->View3D=CheckBox2->Checked;
  Chart2->View3D=CheckBox2->Checked;
  Chart3->View3D=CheckBox2->Checked;
  Chart4->View3D=CheckBox2->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::BitBtn2Click(TObject *Sender)
{
  int tmpH,tmpW;
  // This code creates and stores a new BITMAP file
  // which contains the FOUR charts.
  // Asks previously the user the BMP filename.
  if (SaveDialog1->Execute()) {
    Graphics::TBitmap* bm = new Graphics::TBitmap;
    try {
      // calculate bitmap size (2x2)
      tmpW=Chart1->Width;
      tmpH=Chart1->Height;
      bm->Width = 2*tmpW;
      bm->Height= 2*tmpH;
      // draw chart 1
      Chart1->BufferedDisplay=false;
      Chart1->Draw(bm->Canvas,Rect(0,0,tmpW,tmpH));
      Chart1->BufferedDisplay=true;

      // draw chart 2
      Chart2->BufferedDisplay=false;
      Chart2->Draw(bm->Canvas,Rect(0,tmpH+1,tmpW,2*tmpH));
      Chart2->BufferedDisplay=true;

      // draw chart 3
      Chart3->BufferedDisplay=false;
      Chart3->Draw(bm->Canvas,Rect(tmpW+1,0,2*tmpW,tmpH));
      Chart3->BufferedDisplay=true;

      // draw chart 4
      Chart4->BufferedDisplay=false;
      Chart4->Draw(bm->Canvas,Rect(tmpW+1,tmpH+1,2*tmpW,2*tmpH));
      Chart4->BufferedDisplay=true;
      bm->SaveToFile(SaveDialog1->FileName);
    }
    __finally {
      delete bm;
    }
  }
}
//---------------------------------------------------------------------------
