//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <printers.hpp>

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormMain::PrintBtnClick(TObject *Sender)
{

     int trips;         // number of times to print from first to last
     int dups;          // number of copies of each page to print each time
     int firstpg;
     int lastpg;
     bool needsnewpg=false;


     // make sure the current page is saved before printing
     pages[TabSet1->TabIndex]->Text = Memo1->Text;

     if (!PrintDialog1->Execute())
          return; // user did not press OK

     // if we're not collating, we only go from the first page to last page once
     // but each time through we print duplicates of each page.
     if (!PrintDialog1->Collate)
     {
        trips = 1;
        dups = PrintDialog1->Copies;
     }
     // if we're collating, we go from the first page to the last page
     // multiple times but only print one duplicate each time through.
     else
     {
        trips = PrintDialog1->Copies;
        dups = 1;
     }

     // user has selected to print all pages...
     if (PrintDialog1->PrintRange == prAllPages)
     {
        firstpg = 1;
        lastpg = 5;
     }
     // ...or a range of pages
     else
     {
         firstpg = PrintDialog1->FromPage;
         lastpg = PrintDialog1->ToPage;
     }

     // Initialize print job
     Printer()->BeginDoc();

     // Title to appear in the print manager and network print banners
     Printer()->Title = "Borland C++Builder Printer Example";

     for (int x=0; x<trips; x++)                    // for each pass
          for (int y=firstpg-1; y<lastpg; y++)      // for each page
               for (int z=0; z<dups; z++)           // for each dup of the page
               {
                    if (needsnewpg)     // page 1 does not need a page break
                       Printer()->NewPage();
                    PrintPage(y);      // print the page
                    needsnewpg = true; // subsequent pages need page breaks
               }

     Printer()->EndDoc();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormShow(TObject *Sender)
{
     // initialize variables
     currentpage=0;
     for (int i=0; i<5; i++)
     {
         pages[i] = new TStringList;
         pages[i]->Text = "Page " + IntToStr(i+1);
     }

     // the first page is the initial page
     Memo1->Text = pages[0]->Text;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::TabSet1Click(TObject *Sender)
{
     // When a tab is selected, put the text for that page into the memo control
     Memo1->Text = pages[TabSet1->TabIndex]->Text;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PrintPage(int page)
{
     int pageline=0; // keeps track of the line number as we print for correct
                     // positioning of text on the page

     // print a banner
     Printer()->Canvas->TextOut(20,
          (10+Printer()->Canvas->TextHeight("Hi there!"))*pageline,
          "Borland C++Builder Printer Example -- Page " + IntToStr(page+1));
     pageline+=2;

     for (int line=0; line < pages[page]->Count; line++)
     {
          Printer()->Canvas->TextOut(20,
               (10+Printer()->Canvas->TextHeight("Hi there!"))*pageline,
               pages[page]->Strings[line].c_str());
          pageline++;
     }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::TabSet1Change(TObject *Sender, int NewTab,
      bool &AllowChange)
{
      // before we leave this tab, save the text for this page
      pages[TabSet1->TabIndex]->Text = Memo1->Text;
}
//---------------------------------------------------------------------
__fastcall TFormMain::~TFormMain(void)
{
     // release dynamic data
     for (int i=0; i<5; i++)
     {
         delete pages[i];
     }
}
//---------------------------------------------------------------------
