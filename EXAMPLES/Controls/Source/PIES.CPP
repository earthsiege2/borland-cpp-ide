//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
// pies.cpp
// This file is #included in PIEREG.CPP which #includes PIEREG.H which
// in turn #includes PIES.H.  Hence #including PIES.H here is redundant with
// no ramifications (there are sentries in the header file) but has been done
// just to clarify that the function and class implementations in this file are
// prototyped in PIES.H
#include  "pies.h"
#include <Windows.hpp>

//---------------------------------------------------------------------------
__fastcall TAngles::TAngles(void) : TPersistent() { }
__fastcall TAngles::~TAngles(void) { }

void __fastcall TAngles::Assign(TPersistent* Value)
{
  StartAngle = dynamic_cast<TAngles*>(Value)->StartAngle;
  EndAngle = dynamic_cast<TAngles*>(Value)->EndAngle;
}

void __fastcall TAngles::SetStart(int Value)
{
  if (Value != FStartAngle){
    FStartAngle = Value;
    Changed();
  }
}

void __fastcall TAngles::SetEnd(int Value)
{
  if (Value != FEndAngle){
    FEndAngle = Value;
    Changed();
  }
}

void __fastcall TAngles::Changed()
{
  if (FOnChange != NULL)
    FOnChange(this);
}

__fastcall TPie::TPie(TComponent* AOwner): TGraphicControl(AOwner)
{
  Width = 100;
  Height = 100;
  FPen = new TPen();
  FPen->OnChange = StyleChanged;
  FBrush = new TBrush();
  FBrush->OnChange = StyleChanged;
  FAngles = new TAngles();
  FAngles->OnChange = StyleChanged;
  FAngles->StartAngle = 180;
  FAngles->EndAngle = 90;
}

__fastcall TPie::~TPie(void) 
{
  delete FPen;
  delete FBrush;
  delete FAngles;
}

void __fastcall TPie::StyleChanged(TObject* /*Sender*/)
{
  Invalidate();
}

void __fastcall TPie::SetBrush(TBrush* Value)
{
  FBrush->Assign(Value);
}

void __fastcall TPie::SetPen(TPen* Value)
{
  FPen->Assign(Value);
}

void __fastcall TPie::SetAngles(TAngles* Value)
{
  FAngles->Assign(Value);
  Invalidate();
}

void __fastcall TPie::Paint()
{
  int StartA, EndA;
  int midX, midY, stX, stY, endX, endY;
  float sX, sY, eX, eY;

  StartA = FAngles->StartAngle;
  EndA = FAngles->EndAngle;
  midX =  Width/2;
  midY = Height/2;

  sX = cos((StartA / 180.0) * PI);
  sY = sin((StartA / 180.0) * PI);
  eX = cos((EndA / 180.0) * PI);
  eY = sin((EndA / 180.0) * PI);

  stX = floor(sX * 100);
  stY = floor(sY * 100);
  endX = ceil(eX * 100);
  endY = ceil(eY * 100);

  Canvas->Pen = FPen;
  Canvas->Brush = FBrush;
  Canvas->Pie(0,0,
              Width,Height,
              midX + stX, midY - stY,
              midX + endX, midY - endY);
}

