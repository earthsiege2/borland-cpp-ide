/*********************************************/
/* TeeChart Delphi Component Library 4.0     */
/* Demo                                      */
/* Copyright (c) 1995-1998 by David Berneda  */
/* All rights reserved                       */
/*********************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UMetafil.h"
#include <clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMetafileForm *MetafileForm;
//---------------------------------------------------------------------------
__fastcall TMetafileForm::TMetafileForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMetafileForm::FormCreate(TObject *Sender)
{
  BarSeries1->FillSampleValues(8);  // <-- some sample random bars
}
//---------------------------------------------------------------------------
// This code copies Chart contents onto Windows Clipboard in Metafile Format
void __fastcall TMetafileForm::BitBtn3Click(TObject *Sender)
{
  // TeeClipWhenMetafiling = true; //  <--- FORCE CLIPPING WITH METAFILES
  // CLIPPING WORKS FINE BUT DO NOT ALLOW MOVEABLE OR RESIZEABLE METAFILES

  Chart1->CopyToClipboardMetafile(true);  // <--- Enhanced Metafile = true

  ShowMessage("Chart1 is now at Windows Clipboard in Metafile format.\n"
              "and will now be pasted HERE !");
  // Now PASTE!
  Image1->Picture->Assign(Clipboard());
  Image1->Refresh();
}
//---------------------------------------------------------------------------
// This button asks a filename and saves the Chart
void __fastcall TMetafileForm::BitBtn2Click(TObject *Sender)
{
  if (SaveDialog1->Execute()) {  // <-- ask for a filename first
    // SAVE IT !!

    // CLIPPING WORKS FINE BUT DO NOT ALLOW MOVEABLE OR RESIZEABLE METAFILES
    // TO FORCE CLIPPING WITH METAFILES UNCOMMENT THIS LINE:
    // TeeClipWhenMetafiling = true;

    Chart1->SaveToMetafile(SaveDialog1->FileName);

    // THIS METHOD CAN BE USED TOO:
    /*
      Chart1->SaveToMetafileRect( SaveDialog1->FileName,
      Rect( 0,0, round(21//cm*37->8), round(10//cm*37->8)));
    */
    //   ( this equals to 96 * 21 / 2->54 , 96 * 10 /2->54 )

    // now it's loaded HERE !
    Image1->Picture->LoadFromFile(SaveDialog1->FileName);
    Image1->Refresh();
  }
}
//---------------------------------------------------------------------------
