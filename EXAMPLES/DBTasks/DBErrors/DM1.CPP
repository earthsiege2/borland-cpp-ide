//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
/*
  This example represents a sampling of the way that you might
  approach trapping a number of database errors.

  A complete listing of the database errorcodes is found in the
  IDAPI.h file in the Borland Database Engine.

  Database errors are defined by category and code. Here's a sample:

  // ERRCAT_INTEGRITY
  // ================

  #define ERRCODE_KEYVIOL             1     // Key violation
  #define ERRCODE_MINVALERR           2     // Min val check failed
  #define ERRCODE_MAXVALERR           3     // Max val check failed
  #define ERRCODE_REQDERR             4     // Field value required
  #define ERRCODE_FORIEGNKEYERR       5     // Master record missing
  #define ERRCODE_DETAILRECORDSEXIST  6     // Cannot MODIFY or DELETE this Master record
  #define ERRCODE_MASTERTBLLEVEL      7     // Master Table Level is incorrect
  #define ERRCODE_LOOKUPTABLEERR      8     // Field value out of lookup tbl range
  #define ERRCODE_LOOKUPTBLOPENERR    9     // Lookup Table Open failed
  #define ERRCODE_DETAILTBLOPENERR   10     // 0x0a Detail Table Open failed
  #define ERRCODE_MASTERTBLOPENERR   11     // 0x0b Master Table Open failed
  #define ERRCODE_FIELDISBLANK       12     // 0x0c Field is blank

  The constant for the base category is added to these constants to represent
  a unique DBI errorcode;

  #define DBIERR_KEYVIOL             (ERRBASE_INTEGRITY + ERRCODE_KEYVIOL)
  #define DBIERR_MINVALERR           (ERRBASE_INTEGRITY + ERRCODE_MINVALERR)
  #define DBIERR_MAXVALERR           (ERRBASE_INTEGRITY + ERRCODE_MAXVALERR)
  #define DBIERR_REQDERR             (ERRBASE_INTEGRITY + ERRCODE_REQDERR)
  #define DBIERR_FORIEGNKEYERR       (ERRBASE_INTEGRITY + ERRCODE_FORIEGNKEYERR)

  The ERRBASE_INTEGRITY value is 0x2600 (Hex 2600) or 9728 decimal.
  Thus, for example, the errorcode for keyviol is 9729 for master
  with details is 9734.

*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DM1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::CustomerPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol)
     {
        MessageBox(0, "Unable to post: Duplicate Customer ID.", "Warning" ,MB_OK);
        return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eDetailsExist)
     {
        // The customer record has dependant details in the order tale.
        //
        MessageBox(0, "To delete this record, first delete related orders and items."
                , "Warning" ,MB_OK);
        return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerCustNoChange(TField *Sender)
{
   // Field level event; This code is a cosmetic'
   // neccessity when you change the key of the
   // CustNo in Customer to prevent unexpected changes
   // in the display of the related 'Orders' and
   // 'Items' grids. These controls are re-enabled in the
   // CustomerAfterPost methods.
   //
   Orders->DisableControls();
   Items->DisableControls();
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerAfterPost(TDataSet *DataSet)
{
   // See note in CustomerCustNoChange.
   //
   DM->Orders->Refresh();
   DM->Items->Refresh();
   DM->Orders->EnableControls();
   DM->Items->EnableControls();
}
//---------------------------------------------------------------------
void __fastcall TDM::OrdersPostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action)
{
  int iDBIError;

  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     iDBIError = dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode;

     switch (iDBIError)
     {
        // The EmpNo field  is defined as being required.
        //
        case eRequiredFieldMissing :
           MessageBox(0, "Please provide an Employee ID.", "Warning" ,MB_OK);
           return;

        // The primary key is OrdNo.
        //
        case eKeyViol :
           MessageBox(0, "Unable to post: Duplicate Order Number.",
           "Warning" ,MB_OK);
           return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::ItemsPostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action)
{
   // This error will occur when a part number is specified that
   // is not in the parts table.
   //
   if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eForeignKey)
   {
      MessageBox(0, "Part Number is invalid.", "Warning" ,MB_OK);
      return;
   }
}
//---------------------------------------------------------------------
void __fastcall TDM::OrdersDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
   if (dynamic_cast<EDBEngineError*>(E) != 0)
   {
      if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eDetailsExist)
      {
         if (MessageBox(0, "Delete this order and related items?", "Confirmation",
            MB_YESNO) == IDYES)
         {
            // Delete related records in linked 'items' table.
            //
            while (Items->RecordCount > 0)
            {
               Items->Delete();
            }
            // Finally,delete this record
            //
            Action = daRetry;
         }
         else
         {
            return;
         }
      }
   }
}
//---------------------------------------------------------------------
