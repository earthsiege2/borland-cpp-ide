//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Frmviews.h"
#include "DmCSDemo.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmViewDemo *FrmViewDemo;

//---------------------------------------------------------------------------
__fastcall TFrmViewDemo::TFrmViewDemo(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
// Check to see if there is a format for a try..finally block.
void TFrmViewDemo::ShowTable(char *ATable)
{
   // This is a perfect examples of where a try..finally block is needed
   //  try should be done after the Screen->Cursor = crSQLWait and
   //  then in the finally section, call Screen->Cursor = crDefault.
   //  This would eliminate the two crDefault calls.
   Screen->Cursor = crSQLWait;           // show user something is happening
   try
   {
      VaryingTable->DisableControls();   // hide data changes from user
      VaryingTable->Close();             // close the table
      VaryingTable->TableName = ATable;  // update the table name
      VaryingTable->Open();              // open the table
      VaryingTable->EnableControls();    // show the data changes
      Screen->Cursor = crDefault;        // reset the pointer
   }
   catch(char *E)
   {
      Screen->Cursor = crDefault;
      ShowMessage(E);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFrmViewDemo::FormShow(TObject *Sender)
{
   VaryingTable->Open();
}
//---------------------------------------------------------------------
void __fastcall TFrmViewDemo::BtnShowEmployeeClick(TObject *Sender)
{
   ShowTable("EMPLOYEE");
}
//---------------------------------------------------------------------
void __fastcall TFrmViewDemo::BtnShowPhoneListClick(TObject *Sender)
{
   ShowTable("PHONE_LIST");
}
//---------------------------------------------------------------------
