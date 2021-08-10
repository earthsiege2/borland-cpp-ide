/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UBitmap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBitmapForm *BitmapForm;

/*
 This example shows how to draw a custom Bitmap on a Panel Chart component

 Bitmap images (TBitmap component) can be painted in several styles:

  pbmStretch : Bitmap is stretched to fit Chart Panel Rectangle
  pbmTile    : Bitmap is repeteadly painted without stretching.
  pbmCenter  : Bitmap is painted centered without stretching.

  You use the PanelBitmapMode property:

  Chart1->PanelBitmapMode = pbmTile ;
*/
//---------------------------------------------------------------------------
__fastcall TBitmapForm::TBitmapForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBitmapForm::FormCreate(TObject *Sender)
{
  // This is to show something random in this example
  Series1->FillSampleValues(10);
}
//---------------------------------------------------------------------------
void __fastcall TBitmapForm::RadioGroup1Click(TObject *Sender)
{
  Chart1->BackImageMode = TTeeBackImageMode(RadioGroup1->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TBitmapForm::BitBtn1Click(TObject *Sender)
{
  if (OpenDialog1->Execute())
  {
    RadioGroup1->Enabled = false;
    Chart1->BackImage->LoadFromFile(OpenDialog1->FileName);
    RadioGroup1->Enabled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TBitmapForm::CheckBox1Click(TObject *Sender)
{
  Chart1->BackImageInside = CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TBitmapForm::Button1Click(TObject *Sender)
{
  Chart1->BackImage = 0;
}
//---------------------------------------------------------------------------
