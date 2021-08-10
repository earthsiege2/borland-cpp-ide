/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "UScroll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TScrollForm *ScrollForm;
//---------------------------------------------------------------------------
__fastcall TScrollForm::TScrollForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TScrollForm::AddPoint(const double x, const double y, TColor AColor)
{
  if (CBVertical->Checked)   // if VERTICAL SCROLL
    LineSeries1->AddXY(y,x,"",AColor);
  else
    LineSeries1->AddXY(x,y,"",AColor);
}

void TScrollForm::FillDemoPoints()
{
  // fill the LineSeries with some random data }
  LineSeries1->Clear();  // <-- this removes all points from LineSeries1

 // let"s add 60 minutes from 12:00 to 12:59
  for (Word t = 0;t<60;t++)
    AddPoint( EncodeTime( 12, t, 0,0),random(100),clRed );

 // let"s add 60 more minutes from 13:00 to 13:59
  for (Word t = 0;t<60;t++)
    AddPoint( EncodeTime( 13, t, 0,0),random(100),clRed);
}
// This is the event we need to arrange Axis scale as new points are added->
void __fastcall TScrollForm::LineSeries1AfterAdd(TChartSeries *Sender,
      int ValueIndex)
{
  // if (VERTICAL SCROLL
  if (CBVertical->Checked) {
    Sender->GetVertAxis->Automatic  =  false;       // <-- we dont want automatic scaling
    Sender->GetVertAxis->AutomaticMaximum  =  false;       // <-- we dont want automatic scaling
    Sender->GetVertAxis->AutomaticMinimum  =  false;       // <-- we dont want automatic scaling

    // In this example, we will set the Axis Minimum and Maximum values to
    // show One Hour of data}ing at last point Time plus 5 minutes
    Sender->GetVertAxis->Minimum  =  0;
    Sender->GetVertAxis->Maximum  =  Sender->YValues->MaxValue + DateTimeStep[ dtFiveMinutes ];
    Sender->GetVertAxis->Minimum  =  Sender->GetVertAxis->Maximum - DateTimeStep[ dtOneHour ];
  }
  else {
    Sender->GetHorizAxis->Automatic  =  false;       // <-- we dont want automatic scaling
    Sender->GetHorizAxis->AutomaticMaximum  =  false;       // <-- we dont want automatic scaling
    Sender->GetHorizAxis->AutomaticMinimum  =  false;       // <-- we dont want automatic scaling

    // In this example, we will set the Axis Minimum and Maximum values to
    // show One Hour of data}ing at last point Time plus 5 minutes
    Sender->GetHorizAxis->Minimum  =  0;
    Sender->GetHorizAxis->Maximum  =  Sender->XValues->MaxValue + DateTimeStep[ dtFiveMinutes ];
    Sender->GetHorizAxis->Minimum  =  Sender->GetHorizAxis->Maximum - DateTimeStep[ dtOneHour ];
  }
}
//---------------------------------------------------------------------------
void __fastcall TScrollForm::FormCreate(TObject *Sender)
{
  FillDemoPoints();
}
//---------------------------------------------------------------------------
void __fastcall TScrollForm::Button1Click(TObject *Sender)
{
  Word h,m,s,msec;
  if (CBVertical->Checked)// if VERTICAL SCROLL
    DecodeTime( LineSeries1->YValues->Last(), h, m, s, msec);
  else
    DecodeTime( LineSeries1->XValues->Last(), h, m, s, msec);
  // add a new random point to the Series (one more minute) }
  m++;
  if (m == 60) {
    m = 0;
    h++;
  }
  AddPoint( EncodeTime( h, m, s, msec), random(100), clYellow );
}
//---------------------------------------------------------------------------
void __fastcall TScrollForm::CBVerticalClick(TObject *Sender)
{
  if (CBVertical->Checked) { // if VERTICAL SCROLL
    LineSeries1->YValues->Order = loAscending;
    LineSeries1->XValues->Order = loNone;
    LineSeries1->XValues->DateTime = false;
    LineSeries1->YValues->DateTime = true;
  } else {
    LineSeries1->XValues->Order = loAscending;
    LineSeries1->YValues->Order = loNone;
    LineSeries1->YValues->DateTime = false;
    LineSeries1->XValues->DateTime = true;
  }
  Chart1->LeftAxis->Automatic = true;// <-- this makes axis scales AUTOMATIC AGAIN !
  Chart1->BottomAxis->Automatic = true;// <-- this makes axis scales AUTOMATIC AGAIN !
  FillDemoPoints();  // <-- fill sample values again !
}
//---------------------------------------------------------------------------
