//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "FontList.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
  ListBox1->Items = Screen->Fonts;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ListBox1Click(TObject *Sender)
{
	FontLabel->Caption =  ListBox1->Items->Strings[ListBox1->ItemIndex].c_str();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
	ListBox1->Canvas->FillRect(Rect);
    ListBox1->Canvas->Font->Name =ListBox1->Items->Strings[Index].c_str();
    ListBox1->Canvas->Font->Size = 0;
    ListBox1->Canvas->TextOut(Rect.Left+1, Rect.Top+1, ListBox1->Items->Strings[Index].c_str());
}
//---------------------------------------------------------------------
void __fastcall TFormMain::ListBox1MeasureItem(TWinControl *Control,
      int Index, int &Height)
{
   ListBox1->Canvas->Font->Name =ListBox1->Items->Strings[Index].c_str();
   ListBox1->Canvas->Font->Size = 0;
   Height = ListBox1->Canvas->TextHeight("Wg") +2;
}
//---------------------------------------------------------------------