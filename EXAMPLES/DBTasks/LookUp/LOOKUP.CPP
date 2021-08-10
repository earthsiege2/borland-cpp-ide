//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "lookup.h"
#include "About.h"
#include "maindata.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfmLookup *fmLookup;
//---------------------------------------------------------------------------
__fastcall TfmLookup::TfmLookup(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmLookup::About1Click(TObject *Sender)
{
  TfmAbout *fmAbout;

  fmAbout = new TfmAbout(NULL);
  fmAbout->ShowModal();
  delete fmAbout;
}
//---------------------------------------------------------------------