/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDraw.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDrawForm *DrawForm;
//---------------------------------------------------------------------------
__fastcall TDrawForm::TDrawForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDrawForm::FormCreate(TObject *Sender)
{
  Percent = 50;  // <-- used for this demo only
  LineSeries1->FillSampleValues(20);
}
//---------------------------------------------------------------------------
void __fastcall TDrawForm::LineSeries1BeforeDrawValues(TObject *Sender)
{
  TColor MyColors[5] = {
      clNavy,
      clGreen,
      clYellow,
      clRed,
      (TColor)0x00000080 // very red
  };
  int partial, YPosition;
  double tmpYCenterValue;
  TRect tmpRect;

  // we will divide the total chart width by 5
  tmpRect = Chart1->ChartRect;
  tmpRect.Right = tmpRect.Left;
  partial = Chart1->ChartWidth / 5;

  // change the brush style
  Chart1->Canvas->Brush->Style = bsDiagCross;
  Chart1->Canvas->Pen->Style = psClear;

  // for each section, fill with a specific color
  for (int t = 1;t<6;t++) {
  // adjust the rectangle dimension
  tmpRect.Right  = tmpRect.Right+partial+1 ;

  // set the brush color
  Chart1->Canvas->Brush->Color = MyColors[t];

  // paint !!!
  Chart1->Canvas->Rectangle(
    tmpRect.Left+Chart1->Width3D,
    tmpRect.Top-Chart1->Height3D,
    tmpRect.Right+Chart1->Width3D,
    tmpRect.Bottom-Chart1->Height3D );

  // adjust rectangle
  tmpRect.Left = tmpRect.Right;
  }

  // first calculate the middle vertical value (based on LineSeries points)
  //With LineSeries1->YValues do
  tmpYCenterValue = LineSeries1->YValues->MinValue+Percent*(
  LineSeries1->YValues->MaxValue-LineSeries1->YValues->MinValue)/100.0;

  // if calculate the Screen Pixel coordinate of the above value
  YPosition = Chart1->LeftAxis->CalcYPosValue(tmpYCenterValue);

  // change pen and draw the line
  Chart1->Canvas->Pen->Width = 3;
  Chart1->Canvas->Pen->Style = psSolid;
  Chart1->Canvas->Pen->Color = clRed;
  Chart1->Canvas->MoveTo(Chart1->ChartRect.Left,YPosition);
  Chart1->Canvas->LineTo(Chart1->ChartRect.Left+Chart1->Width3D,
    YPosition-Chart1->Height3D);
  Chart1->Canvas->LineTo(Chart1->ChartRect.Right+Chart1->Width3D,
    YPosition-Chart1->Height3D);
}
//---------------------------------------------------------------------------
void __fastcall TDrawForm::LineSeries1AfterDrawValues(TObject *Sender)
{
  int YPosition;
  double tmpYCenterValue;
  // first calculate the middle vertical value (based on LineSeries points)
  tmpYCenterValue = LineSeries1->YValues->MinValue +
  Percent * (LineSeries1->YValues->MaxValue -
  LineSeries1->YValues->MinValue)/100.0;

  // then calculate the Screen Pixel coordinate of the above value
  YPosition = Chart1->LeftAxis->CalcYPosValue(tmpYCenterValue);

  // change pen and draw the line
  Chart1->Canvas->Pen->Width = 3;
  Chart1->Canvas->Pen->Style = psSolid;
  Chart1->Canvas->Pen->Color = clRed;
  Chart1->Canvas->MoveTo(Chart1->ChartRect.Left,YPosition);
  Chart1->Canvas->LineTo(Chart1->ChartRect.Right,YPosition);
  Chart1->Canvas->LineTo(
  Chart1->ChartRect.Right+Chart1->Width3D,YPosition-Chart1->Height3D);

  // change font and draw some text above the line

  Chart1->Canvas->Font->Name = "Arial";

  // VERY IMPORTANT !!!!!!
  // THIS IS NECESSARY if (YOU"RE GOING TO PRINT !!!!
  // IT MAKES FONT SIZES TO WORK FINE BOTH AT SCREEN AND PRINTER.

  Chart1->Canvas->Font->Height = -24;   // <-- express font size in "Height", NOT "Size"

  Chart1->Canvas->Font->Color = clYellow;
  Chart1->Canvas->Font->Style = TFontStyles() << fsBold;

  // Set transparent background
  Chart1->Canvas->Brush->Style = bsClear;

  // Output some text
  Chart1->Canvas->TextOut(Chart1->ChartRect.Left+20,
         YPosition-24 ,
         "This is "+ String(tmpYCenterValue));
}
//---------------------------------------------------------------------------
void __fastcall TDrawForm::Timer1Timer(TObject *Sender)
{
  if (Percent+DeltaPercent>100) {
    Percent = 100;
    DeltaPercent = -5;
  } else if (Percent+DeltaPercent<0) {
    Percent = 0;
    DeltaPercent = 5;
  } else
    Percent = Percent+DeltaPercent;
  Chart1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDrawForm::CheckBox1Click(TObject *Sender)
{
  Timer1->Enabled = CheckBox1->Checked;
  DeltaPercent = 5;
}
//---------------------------------------------------------------------------


void __fastcall TDrawForm::CheckBox2Click(TObject *Sender)
{
  Chart1->View3D = CheckBox2->Checked ;
}
//---------------------------------------------------------------------------

