/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TeeMain.h"
#include <stdlib.h>
#include <shellapi.hpp>
#include "TeeBasic.h"
#include "TeeAbout.hpp"
#include "Basic.h"
#include "specs.h"
#include "Features.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTeeMainForm *TeeMainForm;
//---------------------------------------------------------------------------
__fastcall TTeeMainForm::TTeeMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::FormCreate(TObject *Sender)
{
  int const n=5;
  TeeEraseBack = false;
  dynamic_cast<TCircledSeries*>(PieSeries6)->FillSampleValues(n);
  dynamic_cast<TCircledSeries*>(PieSeries9)->FillSampleValues(n);
  dynamic_cast<TCircledSeries*>(PieSeries7)->FillSampleValues(n);
  dynamic_cast<TCircledSeries*>(Series1)->FillSampleValues(n);
  PieSeries8->CheckDataSource();
  FastLineSeries1->FillSampleValues(20);
  FastLineSeries2->FillSampleValues(20);
  DeltaZoom = 5;
  Label3->Cursor=crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Timer1Timer(TObject *Sender)
{
  PieSeries6->Rotate(5);
  PieSeries7->Rotate(5);
  PieSeries9->Rotate(5);
  Series1->Rotate(355);
  PieSeries8->Rotate(355);
  Chart9->View3DOptions->Zoom = Chart9->View3DOptions->Zoom-DeltaZoom;
  if (Chart9->View3DOptions->Zoom<60 || Chart9->View3DOptions->Zoom>110)
    DeltaZoom = -DeltaZoom;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Timer2Timer(TObject *Sender)
{
  double tmpX = FastLineSeries1->XValues->Value[1]
    - FastLineSeries1->XValues->Value[0];
  FastLineSeries1->Delete(0);
  FastLineSeries1->AddXY(
    FastLineSeries1->XValues->Last() + tmpX,random(100),"",clTeeColor);
  tmpX = FastLineSeries2->XValues->Value[1] -
    FastLineSeries2->XValues->Value[0];
  FastLineSeries2->Delete(0);
  FastLineSeries2->AddXY(
    FastLineSeries2->XValues->Last()+tmpX,random(100),"",clTeeColor);
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Button2Click(TObject *Sender)
{
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  TDemoForm* form = new TDemoForm(this);
  form->ShowModal();
  delete form;
  Timer2->Enabled = true;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Chart2MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  Label10Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Chart2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  Chart2->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Label10Click(TObject *Sender)
{
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  TTeeAboutForm* form = new TTeeAboutForm(this);
  form->ShowModal();
  delete form;
  Timer2->Enabled = true;
  Timer1->Enabled = true;
  Chart2->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Button3Click(TObject *Sender)
{
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  TFeaturesForm* form = new TFeaturesForm(this);
  form->ShowModal();
  delete form;
  Timer2->Enabled = true;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Button4Click(TObject *Sender)
{
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  TChartSpecs* form = new TChartSpecs(this);
  form->ShowModal();
  delete form;
  Timer2->Enabled = true;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Button6Click(TObject *Sender)
{
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  TBasicForm* form = new TBasicForm(this);
  form->ShowModal();
  delete form;
  Timer2->Enabled = true;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTeeMainForm::Label3Click(TObject *Sender)
{
  String St = "http://"+Label3->Caption;
  ShellExecute(Handle,"open",St.c_str(),0,0,SW_SHOW);
}
//---------------------------------------------------------------------------
 