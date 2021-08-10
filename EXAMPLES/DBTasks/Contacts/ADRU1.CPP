//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
// CUSTOMER CONTACT BROWSER DEMO v.01
//
// Key Points:
//
// 1. Simple 1-Many join on a single field.
// 2. Parameterized Query.
// 3. Binding of parameters in code at runtime.
// 4. Dataset navigation in code.
// 5. Usefull implimentation of DataSet OnStateChange and State property.
//
// Pending Issues:
//
// 1. Tab order
// 2. Control Names
// 3. Hot Keys of labels related to "Orders" controls
//
//
//    Modifications:
//
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "adru1.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent *Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TFormMain::BitBtn1Click(TObject* /*Sender*/)
{    Close();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::TabControl1Change(TObject* /*Sender*/)
{    char cParam[3] = {'A','%',0};
     AnsiString  sParam = (AnsiString)"paramVar1";
     cParam[0] = (char)(65+TabControl1->TabIndex);
     Query1->Cancel();    Table1->Cancel();
     Table1->Close();     Query1->Close();
     Query1->ParamByName(sParam)->AsString = (AnsiString)cParam;
     Query1->Open();      Table1->Open();
     EnableDisableCsNav();
     EnableDisableOrNav();
}

//----------------------------------------------------------------------------
void __fastcall TFormMain::FirstCustClick(TObject* /*Sender*/)
{    Query1->First(); EnableDisableCsNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::PriorCustClick(TObject* /*Sender*/)
{    Query1->Prior(); EnableDisableCsNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::NextCustClick(TObject* /*Sender*/)
{    Query1->Next(); EnableDisableCsNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::LastCustClick(TObject* /*Sender*/)
{    Query1->Last(); EnableDisableCsNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::EditCustClick(TObject* /*Sender*/)
{    Query1->Edit();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::PostCustClick(TObject* /*Sender*/)
{    Query1->Post();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::CancelCustClick(TObject* /*Sender*/)
{    Query1->Cancel();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject* /*Sender*/,
     TCloseAction & /*Action*/)
{    Table1->Cancel();  Table1->Close();
     Query1->Cancel();  Query1->Close();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject* /*Sender*/)
{    Table1->Open();
     Query1->Open();
     EnableDisableOrNav();
     EnableDisableCsNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::CancelOrdersClick(TObject* /*Sender*/)
{    Table1->Cancel();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::PostOrdersClick(TObject* /*Sender*/)
{    Table1->Post();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::EditOrdersClick(TObject* /*Sender*/)
{    Table1->Edit();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::LastOrdersClick(TObject* /*Sender*/)
{    Table1->Last(); EnableDisableOrNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::NextOrdersClick(TObject* /*Sender*/)
{    Table1->Next(); EnableDisableOrNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::PriorOrdersClick(TObject* /*Sender*/)
{    Table1->Prior(); EnableDisableOrNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::FirstOrdersClick(TObject* /*Sender*/)
{    Table1->First(); EnableDisableOrNav();
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::EnableDisableOrNav()
{
     FirstOrders->Enabled = (!Table1->Bof ? True : False );
     PriorOrders->Enabled = (!Table1->Bof ? True : False );
     NextOrders->Enabled  = (!Table1->Eof ? True : False );
     LastOrders->Enabled  = (!Table1->Eof ? True : False );

}
//----------------------------------------------------------------------------
void __fastcall TFormMain::EnableDisableCsNav()
{
	 FirstCust->Enabled = (!Query1->Bof ? True : False );
     PriorCust->Enabled = (!Query1->Bof ? True : False );
     NextCust->Enabled  = (!Query1->Eof ? True : False );
     LastCust->Enabled  = (!Query1->Eof ? True : False );
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::DataSource1StateChange(TObject* /*Sender*/)
{    switch(Query1->State) {
        case dsInactive   : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsBrowse     : {
             EditCust->Enabled = True;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsEdit       : {
             EditCust->Enabled = False;
             PostCust->Enabled = True;
             CancelCust->Enabled = True;
             break;
        }
        case dsInsert     : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsSetKey     : {
             EditCust->Enabled = False;
             PostCust->Enabled = True;
             CancelCust->Enabled = False;
             break;
        }
        case dsCalcFields : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsNewValue  : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsOldValue  : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
        case dsFilter     : {
             EditCust->Enabled = False;
             PostCust->Enabled = False;
             CancelCust->Enabled = False;
             break;
        }
     }
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::DataSource2StateChange(TObject* /*Sender*/)
{    switch(Table1->State) {
        case dsInactive   : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsBrowse     : {
             EditOrders->Enabled = True;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsEdit       : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = True;
             CancelOrders->Enabled = True;
             break;
        }
        case dsInsert     : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsSetKey     : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = True;
             CancelOrders->Enabled = False;
             break;
        }
        case dsCalcFields : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsNewValue  : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsOldValue  : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
        case dsFilter     : {
             EditOrders->Enabled = False;
             PostOrders->Enabled = False;
             CancelOrders->Enabled = False;
             break;
        }
     }
}
