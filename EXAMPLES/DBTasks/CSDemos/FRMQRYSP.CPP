//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Frmqrysp.h"
#include "DmCSDemo.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmQueryProc *FrmQueryProc;
//---------------------------------------------------------------------------
__fastcall TFrmQueryProc::TFrmQueryProc(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmQueryProc::WriteMsg(char *szWrite)
{
   StatusBar1->SimpleText = szWrite;
}
//---------------------------------------------------------------------------
void __fastcall TFrmQueryProc::FormShow(TObject *Sender)
{
  DmEmployee->EmployeeTable->Open();
  // Allow data flow from the EmployeeTable to the local EmployeeSource.  This
  //   will allow DataChange events to execute the query procedure
  EmployeeSource->Enabled = True;
  // Explicit query preparation is not required, but gives the best possible
  //  performance
  if (EmployeeProjectsQuery->Active != True)
     EmployeeProjectsQuery->Prepare();
}
//---------------------------------------------------------------------
void __fastcall TFrmQueryProc::EmployeeSourceDataChange(TObject *Sender,
      TField *Field)
{

  // Execute the ProjectsQuery, which uses a query procedure
  EmployeeProjectsQuery->Close();
  EmployeeProjectsQuery->ParamByName("EMP_NO")->AsSmallInt =
    DmEmployee->EmployeeTableEMP_NO->Value;
  EmployeeProjectsQuery->Open();

  String buf = "Employee "
             + String((int)DmEmployee->EmployeeTableEMP_NO->Value)
             + " is assigned to " 
             + String((int)EmployeeProjectsQuery->RecordCount)
             + " project(s)";
  WriteMsg(buf.c_str());
} 
//---------------------------------------------------------------------
void __fastcall TFrmQueryProc::FormHide(TObject *Sender)
{
   // Turn off the DataChange event for the form, since DmEmployee.EmployeeTable
   // is used elsewhere
   EmployeeSource->Enabled = True;
}
//---------------------------------------------------------------------
