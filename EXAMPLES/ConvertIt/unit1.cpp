//----------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987 - 2001 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
// ConverIt : Conversion Utilities Demo v.1 
//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <convutils.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConvFamiliesChange(TObject *Sender)
{
  TConvFamily LFamily;
  LFamily = TConvFamily(ConvFamilies->Tabs->Objects[ConvFamilies->TabIndex]);

  ConvTypes->Items->BeginUpdate();
  ConvTypes->Clear();

  TConvTypeArray LTypes;
  GetConvTypes(LFamily, LTypes);

  for (int i = 0; i <= LTypes.Length - 1; ++i)
    ConvTypes->Items->AddObject(ConvTypeToDescription(LTypes[i]),
                                reinterpret_cast<TObject*>(LTypes[i]));

  ConvTypes->ItemIndex = 0;
  ConvTypes->Items->EndUpdate();
  ConvTypesClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConvTypesClick(TObject *Sender)
{
  ConvValueChange(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
  ConvFamilies->Tabs->Clear();
  TStringList* LStrings = new TStringList();

  try
  {
    TConvFamilyArray LFamilies;
    GetConvFamilies(LFamilies);

    for (int i = 0; i <= LFamilies.Length - 1; ++i)
      LStrings->AddObject(ConvFamilyToDescription(LFamilies[i]),
                          reinterpret_cast<TObject*>(LFamilies[i]));

    LStrings->Sort();
    ConvFamilies->Tabs->Assign(LStrings);
    ConvFamiliesChange(Sender);
  }
  __finally
  {
    delete LStrings;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConvValueChange(TObject *Sender)
{
  TConvType LBaseType, LTestType;

  try
  {
    ConvResults->Items->BeginUpdate();
    ConvResults->Clear();

    try
    {
      double LValue = StrToFloatDef(ConvValue->Text, 0);
      if ( ConvTypes->ItemIndex != -1 )
      {
        LBaseType = TConvType(ConvTypes->Items->Objects[ConvTypes->ItemIndex]);

        for (int i = 0; i <= ConvTypes->Items->Count - 1; ++i)
        {
          LTestType = TConvType(ConvTypes->Items->Objects[i]);
          TVarRec v[] = {Convert(LValue, LBaseType, LTestType),
                         ConvTypeToDescription(LTestType)};
          ConvResults->Items->Add(Format("%n %s", v, ARRAYSIZE(v) - 1));
        }
      }
      else
        ConvResults->Items->Add("No base type");
    }
    catch (Exception& e)
    {
      ConvResults->Items->Add("Cannot parse value");
    }
  }
  __finally
  {
    ConvResults->Items->EndUpdate();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnCloseClick(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::About1Click(TObject *Sender)
{
  ShowMessage("Conversion Utilities Demo v1.\nC++Builder 6.0.\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

