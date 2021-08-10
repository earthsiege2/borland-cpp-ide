//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Frmtrans.h"
#include "DmCSDemo.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmTransDemo *FrmTransDemo;
//---------------------------------------------------------------------------
__fastcall TFrmTransDemo::TFrmTransDemo(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmTransDemo::FormShow(TObject *Sender)
{
  DmEmployee->EmployeeDatabase->StartTransaction();
  DmEmployee->EmployeeTable->Open();
}
//---------------------------------------------------------------------
void __fastcall TFrmTransDemo::FormHide(TObject *Sender)
{
  DmEmployee->EmployeeDatabase->Commit();
}
//---------------------------------------------------------------------
void __fastcall TFrmTransDemo::BtnCommitEditsClick(TObject *Sender)
{
   if (DmEmployee->EmployeeDatabase->InTransaction == True)
   {
      if (MessageDlg("Are you sure you want to commit your changes?",
            mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
      {
         DmEmployee->EmployeeDatabase->Commit();
         DmEmployee->EmployeeDatabase->StartTransaction();
         DmEmployee->EmployeeTable->Refresh();
      }
   }
   else
      MessageDlg("Can't Commit Changes: No Transaction Active", mtError,
               TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------
void __fastcall TFrmTransDemo::BtnUndoEditsClick(TObject *Sender)
{
   if (DmEmployee->EmployeeDatabase->InTransaction == True)
   {
      if (MessageDlg("Are you sure you want to undo all changes",
            mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
      {
         DmEmployee->EmployeeTable->Edit();
         DmEmployee->EmployeeTable->Post();
         DmEmployee->EmployeeDatabase->Rollback();
         DmEmployee->EmployeeDatabase->StartTransaction();
         DmEmployee->EmployeeTable->Refresh();
      }
   }
   else
      MessageDlg("Can't Undo Edits: No Transaction Active", mtError,
               TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------
