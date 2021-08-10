//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Frmexesp.h"
#include "DmCSDemo.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmExecProc *FrmExecProc;
//---------------------------------------------------------------------------
__fastcall TFrmExecProc::TFrmExecProc(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmExecProc::FormShow(TObject *Sender)
{
   DmEmployee->SalesTable->Open();
   DmEmployee->CustomerTable->Open();
   // Enable DataEvents from the SalesTable for this form now
   SalesSource->Enabled = True;
}
//---------------------------------------------------------------------
void __fastcall TFrmExecProc::FormHide(TObject *Sender)
{
   // Disable DataEvents from the SalesTable for this form now
   SalesSource->Enabled = False;
}
//---------------------------------------------------------------------
void __fastcall TFrmExecProc::SalesSourceDataChange(TObject *Sender,
      TField *Field)
{
   if (CompareText(DmEmployee->SalesTable->FieldByName("ORDER_STATUS")->AsString,
               "SHIPPED") != 0)
      BtnShipOrder->Enabled = True;
   else
      BtnShipOrder->Enabled = False;
}
//---------------------------------------------------------------------
void __fastcall TFrmExecProc::BtnShipOrderClick(TObject *Sender)
{
   DmEmployee->ShipOrderProc->Params->Items[0]->AsString =
        DmEmployee->SalesTable->FieldByName("PO_NUMBER")->AsString;
   DmEmployee->ShipOrderProc->ExecProc();
   DmEmployee->SalesTable->Refresh();
}
//---------------------------------------------------------------------