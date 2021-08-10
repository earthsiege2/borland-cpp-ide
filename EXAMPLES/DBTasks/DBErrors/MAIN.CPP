//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "DM1.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFmMain *FmMain;
//---------------------------------------------------------------------------
__fastcall TFmMain::TFmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFmMain::GridOrdersEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->OrdersSource;
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridCustomersEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->CustomerSource;
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridItemsEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->ItemsSource;  
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridCustomersExit(TObject *Sender)
{
	if (DM->Customer->State == dsEdit || DM->Customer->State == dsInsert)
    {
     	// Required if user clicks onto details
        // after changing key so that cascade
        // update displays properly.
        //
    	DM->Customer->Post();
    }
}
//---------------------------------------------------------------------
void __fastcall TFmMain::About1Click(TObject *Sender)
{
        TFmAboutBox* fmAboutBox = new TFmAboutBox(0);
        
        try
        {
                fmAboutBox->ShowModal();
        }
        catch(...)
        {
                delete fmAboutBox;
                throw;
        }

        delete fmAboutBox;
}
//---------------------------------------------------------------------