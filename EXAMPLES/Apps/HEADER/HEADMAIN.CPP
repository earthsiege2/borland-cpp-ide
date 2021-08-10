//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "headmain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::HeaderControl1SectionTrack(
      THeaderControl *HeaderControl, THeaderSection *Section,
      int Width, TSectionTrackState State)
{
        Section->Width = Width;
        Shape1->Width = HeaderControl->Sections->Items[0]->Width;
        Shape2->Width = HeaderControl->Sections->Items[1]->Width;
        Shape2->Left = HeaderControl->Sections->Items[1]->Left;
        Shape3->Width = HeaderControl->Sections->Items[2]->Width;
        Shape3->Left = HeaderControl->Sections->Items[2]->Left;
}
//---------------------------------------------------------------------
