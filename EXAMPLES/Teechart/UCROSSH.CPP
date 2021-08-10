/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UCrossH.h"
#include "pendlg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCrossHairForm *CrossHairForm;
//---------------------------------------------------------------------------
__fastcall TCrossHairForm::TCrossHairForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCrossHairForm::FormCreate(TObject *Sender)
{
  LineSeries1->FillSampleValues(30);  // <-- some random values
  OldX = -1;                          // initialize variables
  CrossHairColor = clYellow;
  CrossHairStyle = psSolid;
  Chart1->Cursor = crCross;
}
//---------------------------------------------------------------------------

// This procedure draws the crosshair lines }
void TCrossHairForm::DrawCross(int ax, int ay)
{
  TColor tmp;
  tmp = Chart1->BackColor;
  if (tmp == clTeeColor)
    tmp = clBtnFace;
  Chart1->Canvas->Pen->Color = (TColor)(CrossHairColor ^ ColorToRGB(tmp));

  Chart1->Canvas->Pen->Style = CrossHairStyle;
  Chart1->Canvas->Pen->Mode = pmXor;
  Chart1->Canvas->Pen->Width = 1;
  Chart1->Canvas->MoveTo(ax,Chart1->ChartRect.Top-Chart1->Height3D);
  Chart1->Canvas->LineTo(ax,Chart1->ChartRect.Bottom-Chart1->Height3D);
  Chart1->Canvas->MoveTo(Chart1->ChartRect.Left+Chart1->Width3D,ay);
  Chart1->Canvas->LineTo(Chart1->ChartRect.Right+Chart1->Width3D,ay);
}

void __fastcall TCrossHairForm::Chart1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  double tmpX,tmpY;
  if (OldX != 1) {
    DrawCross(OldX,OldY);  // draw old crosshair
    OldX = -1;
  }

  // check if (mouse is inside Chart rectangle
  if (PtInRect((RECT*)&Chart1->ChartRect, Point(X-Chart1->Width3D,Y+Chart1->Height3D))) {
    DrawCross(X,Y);  // draw crosshair at current position
    // store old position
    OldX = X;
    OldY = Y;
    // set label text
    LineSeries1->GetCursorValues(tmpX,tmpY);  // <-- get values under mouse cursor
    Label1->Caption = LineSeries1->GetVertAxis->LabelValue(tmpY)
      + " " + LineSeries1->GetHorizAxis->LabelValue(tmpX);
  }
}
//---------------------------------------------------------------------------
void __fastcall TCrossHairForm::LineSeries1AfterDrawValues(TObject *Sender)
{
  OldX = -1;  // Reset old mouse position
}
//---------------------------------------------------------------------------
void __fastcall TCrossHairForm::CheckBox1Click(TObject *Sender)
{
  if (CheckBox1->Checked)
    Chart1->Cursor = crCross;
  else
    Chart1->Cursor = crDefault;
  Chart1->OriginalCursor = Chart1->Cursor;
}
//---------------------------------------------------------------------------
void __fastcall TCrossHairForm::BitBtn2Click(TObject *Sender)
{
  CrossHairColor = EditColor(this,CrossHairColor);
}
//---------------------------------------------------------------------------

 