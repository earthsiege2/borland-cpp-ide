//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "Datamod.h"
#include <utilcls.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMastData *MastData;
//---------------------------------------------------------------------------
__fastcall TMastData::TMastData(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
// Utility functions

bool Confirm(const char *Msg)
{
  return ((MessageBox(NULL,Msg, "Confirmation", MB_YESNO) == IDYES)?1:0);
}

AnsiString TMastData::DataDirectory()
{
 //Assume data is in ..\..\data relative to where we are
  AnsiString temp = ExtractFilePath(ParamStr(0));
  return ExpandFileName(temp + "..\\..\\DATA\\");
}

//This function switches the database to a different alias.

void TMastData::SetDatabaseAlias(AnsiString AliasName)
{
  Screen->Cursor = crHourGlass;
  try
  {
    Database->Close();
    Database->AliasName = AliasName;
    Database->Open();
    Screen->Cursor = crDefault;
  }
  catch(...)  {    Screen->Cursor = crDefault;  }
}

// Steps through Items and gathers sum of ExtPrice. After OrdersItemsTotal
//  is calculated, OrdersCalcFields is automatically called (which
//  updates other calculated fields.
void TMastData::UpdateTotals()
{
  Extended TempTotal;
  TBookmark PrevRecord;

  if (!DeletingItems)		// don't calculate if deleting all items
  {
    PrevRecord = Items->GetBookmark();	// returns null if table is empty }
    try
    {
      Items->DisableControls();
      Items->First();
      TempTotal = 0;			// use temp for efficiency
      while (!Items->Eof)
      {
        TempTotal = TempTotal + ItemsExtPrice->Value;
        Items->Next();
      }
      OrdersItemsTotal->Value = TempTotal;
    }
    catch(...)
    {
       Items->EnableControls();
       if (PrevRecord)
       {
         Items->GotoBookmark(PrevRecord);
         Items->FreeBookmark(PrevRecord);
       }
       return;    //do not repeat execution of above code.
    }
    Items->EnableControls(); //if no catch clause do a little cleanup
    if (PrevRecord)
    {
      Items->GotoBookmark(PrevRecord);
      Items->FreeBookmark(PrevRecord);
    }
  }/*end !DeleteingItems*/
}


void TMastData::DeleteItems()
{
  DeletingItems = True;     // Suppress recalc of totals during delete
  Items->DisableControls(); // for faster table traversal.
  try
  {
    Items->First();
    while(!Items->Eof)
     Items->Delete();
  }
  catch(...)
  {
    DeletingItems = False;
    Items->EnableControls();   //always re-enable controls after disabling
    return;
  }
  DeletingItems = False;
  Items->EnableControls();     //always re-enable controls after disabling
}

// Create an alias for the local data if needed, then swith the Database
//  to use it.
void TMastData::UseLocalData()
{
  AnsiString DataDir;
  // See if the target alias exists, if not then add it.
  if (!Session->IsAlias("DBDEMOS"))
  {
    DataDir = DataDirectory();
    if (!FileExists(DataDir+"ORDERS.DB"))
//      raise Exception.Create("Cannot locate Paradox data files");
      MessageBox(NULL,"Cannot locate Paradox data files","Warning",MB_OK);
    Session->AddStandardAlias("DBDEMOS", DataDir, "PARADOX");
  }
  SetDatabaseAlias("DBDEMOS");
}

// Create an alias to point to the MastSQL.GDB file if needed

void TMastData::UseRemoteData()
{
  TStringList * Params = new TStringList;
  AnsiString DataFile;
  TPtr<TOpenDialog> opendlg = new TOpenDialog(NULL);

  // See if the alias exists.  if not then add it.
  if (!Session->IsAlias("MASTSQL"))
  {
    DataFile = DataDirectory() + "MASTSQL.GDB";
    if (!FileExists(DataFile))
    {
      opendlg->Filter = "Interbase files (*.gdb)|*.GDB";
      if (opendlg->Execute())
        DataFile = opendlg->FileName;
    }
    else
      MessageBox(NULL,"Cannot locate Interbase data file: MASTSQL.GDB","Warning!",MB_OK);
    try
    {
      Params->Values["SERVER NAME"] = DataFile;
      Params->Values["USER NAME"] = "SYSDBA";
      Session->AddAlias("MASTSQL", "INTRBASE", Params);
    }
    catch(...)
    {
       Params->Free();
       return;
    }
    Params->Free();
  }
  SetDatabaseAlias("MASTSQL");
}

bool TMastData::DataSetApplyUpdates(TDBDataSet *DataSet, bool Apply)
{
  bool retval = true;
    if ((DataSet->State==dsEdit || DataSet->State==dsInsert ||DataSet->State==dsSetKey)
        || DataSet->UpdatesPending)
    {
      if (Apply)
      {
        Database->ApplyUpdates((const TDBDataSet **)DataSet, 0);
        DataSet->CancelUpdates();
      }
      else
      {
        if (Confirm("Unsaved changes, exit anyway?"))
          DataSet->CancelUpdates();
        else
          retval = false;
      }
    }
  return retval;
}


//---------------------------------------------------------------------------
void __fastcall TMastData::PartsBeforeOpen(TDataSet *DataSet)
{
  Vendors->Open();
}
//---------------------------------------------------------------------------
void __fastcall TMastData::PartsCalcFields(TDataSet *DataSet)
{
  PartsBackOrd->Value = (PartsOnOrder->Value > PartsOnHand->Value);
}
//---------------------------------------------------------------------------
void __fastcall TMastData::PartsQueryCalcFields(TDataSet *DataSet)
{
  PartsQueryBackOrd->Value = (PartsOnOrder->Value > PartsOnHand->Value);
}
//---------------------------------------------------------------------------
//If user cancels the updates to the orders table, cancel the updates to
//the line items as well
void __fastcall TMastData::OrdersAfterCancel(TDataSet *DataSet)
{
  Cust->CancelUpdates();
  Parts->CancelUpdates();
  Items->CancelUpdates();
  Orders->CancelUpdates();
}
//---------------------------------------------------------------------------
// Order Entry

//Post new LastInvoiceDate to CUST table.
void __fastcall TMastData::OrdersAfterPost(TDataSet *DataSet)
{
  Set<TLocateOption,0,1> flags;
  if (Cust->Locate("CustNo", OrdersCustNo->Value, flags) &&
    (CustLastInvoiceDate->Value < OrdersShipDate->Value))
  {
    Cust->Edit();
    CustLastInvoiceDate->Value = OrdersShipDate->Value;
    Cust->Post();
  }

  TDBDataSet *dsArray[] = { Orders, Items, Parts, Cust };
  Database->ApplyUpdates((const TDBDataSet **)dsArray, 3);
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeCancel(TDataSet *DataSet)
{
  if( (Orders->State == dsInsert) &&  !(Items->Bof && Items->Eof) )
    if (!Confirm("Cancel order being inserted and delete all line items?"))
      Abort();
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeClose(TDataSet *DataSet)
{
  Items->Close();
  Emps->Close();
  CustByOrd->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeDelete(TDataSet *DataSet)
{
  if (!Confirm("Delete order and line items?"))
    Abort();
  else
    DeleteItems();
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeInsert(TDataSet *DataSet)
{
  if (Orders->State==dsEdit||Orders->State==dsInsert||Orders->State==dsSetKey)
    if (Confirm("An order is being processed.  Save changes and start a new one?"))
      Orders->Post();
    else
      Abort();
  FItemNo = 1;
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeOpen(TDataSet *DataSet)
{
  CustByComp->Open();
  CustByOrd->Open();
  Cust->Open();
  Emps->Open();
  Items->Open();
}
//---------------------------------------------------------------------------
// Calculate the order's tax totals and amount due
void __fastcall TMastData::OrdersCalcFields(TDataSet *DataSet)
{
  OrdersTaxTotal->Value = OrdersItemsTotal->Value * (OrdersTaxRate->Value / 100);
  OrdersAmountDue->Value = OrdersItemsTotal->Value + OrdersTaxTotal->Value +
                           OrdersFreight->Value - OrdersAmountPaid->Value;
}
//---------------------------------------------------------------------------
// Inititializes the record values as a result of an Orders.Insert.
void __fastcall TMastData::OrdersNewRecord(TDataSet *DataSet)
{
// Get the Next Order Value from the NextOrd Table

    NextOrd->Open();
    try
    {
      NextOrd->Edit();
      OrdersOrderNo->Value = NextOrdNewKey->Value;
      NextOrdNewKey->Value = NextOrdNewKey->Value + 1;
      NextOrd->Post();
      NextOrd->Close();
    } catch(...)
      {
        NextOrd->Close();
      }
  OrdersSaleDate->Value      = Date();
  OrdersShipVIA->Value       = "UPS";
  OrdersTerms->Value         = "net 30";
  OrdersPaymentMethod->Value = "Check";
  OrdersItemsTotal->Value    = 0;
  OrdersTaxRate->Value       = 0;
  OrdersFreight->Value       = 0;
  OrdersAmountPaid->Value    = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMastData::ItemsAfterDelete(TDataSet *DataSet)
{
  UpdateTotals();
}
//---------------------------------------------------------------------------

//  Reduce/increase Parts table's OnOrder field
void TMastData::UpdateParts(double PartNo, long Qty)
{
  if ((PartNo > 0) && (Qty != 0))
  try
  {
    Set<TLocateOption,0,1> flags;
    if (!Parts->Locate("PartNo", PartNo, flags))
     Abort();
    Parts->Edit();
    PartsOnOrder->Value = PartsOnOrder->Value + Qty;
    Parts->Post();
  }
  catch(Exception& E)
  {
     char msg[250];
     sprintf(msg,"Error updating parts table for PartNo: %d", PartNo);
      ShowMessage(msg);
  }
}

// Maintain next available item number
void __fastcall TMastData::ItemsAfterPost(TDataSet *DataSet)
{
  ++FItemNo;
  UpdateTotals();
  if (!((PrevPartNo == ItemsPartNo->Value) && (PrevQty == ItemsQty->Value)))
  {
   // Reduce previous Part#'s OnOrder field by previous Qty
    UpdateParts(PrevPartNo, -PrevQty);
   // Increase new Part#'s OnOrder field by previous Qty
    UpdateParts(ItemsPartNo->Value, ItemsQty->Value);
  }

}
//---------------------------------------------------------------------------
//  When a change to the detail table affects a field in the master, always make
//  sure the master (orders) table is in edit or insert mode before allowing the
//  detail table to be modified.
void __fastcall TMastData::EnsureOrdersEdit(TDataSet *DataSet)
{
  Orders->Edit();
}
//---------------------------------------------------------------------------
// Remember previous PartNo and Qty for updating Parts.OnOrder after post.
//  When a change to the detail table affects a field in the master, always make
//  sure the master table is in edit or insert mode before allowing the
//  detail table to be modified.
void __fastcall TMastData::ItemsBeforeEdit(TDataSet *DataSet)
{
  Orders->Edit();
  PrevPartNo = ItemsPartNo->Value;
  PrevQty = ItemsQty->Value;
}
//---------------------------------------------------------------------------
// Make sure the Parts table opens before the Items table, since there are
//  lookups which depend on it.
void __fastcall TMastData::ItemsBeforeOpen(TDataSet *DataSet)
{
  Parts->Open();
}
//---------------------------------------------------------------------------
// Complete the item's key by initializing its NextItemNo field
void __fastcall TMastData::ItemsBeforePost(TDataSet *DataSet)
{
  ItemsItemNo->Value = FItemNo;
}
//---------------------------------------------------------------------------
// Lookup PartNo info for the item; calculate its extended price
void __fastcall TMastData::ItemsCalcFields(TDataSet *DataSet)
{
  ItemsExtPrice->Value = ItemsQty->Value *
    ItemsSellPrice->Value * (100 - ItemsDiscount->Value) / 100;
}
//---------------------------------------------------------------------------
// New item. Zero the "prev" buckets, initialize the key
void __fastcall TMastData::ItemsNewRecord(TDataSet *DataSet)
{
  PrevPartNo = 0;
  PrevQty = 0;
  ItemsOrderNo->Value = OrdersOrderNo->Value;
  ItemsQty->Value = 1;
  ItemsDiscount->Value = 0;
}
//---------------------------------------------------------------------------
// Concatenate last name + first name for the order's SoldBy DBLookupCombo
void __fastcall TMastData::EmpsCalcFields(TDataSet *DataSet)
{
  char buf[250];
  sprintf(buf,"%s, %s",EmpsLastName->Value.c_str(), EmpsFirstName->Value.c_str());
  EmpsFullName->Value = buf;
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersCustNoChange(TField *Sender)
{
  OrdersShipToContact->Value = "";
  OrdersShipToPhone->Value = "";
  OrdersShipToAddr1->Value = "";
  OrdersShipToAddr2->Value = "";
  OrdersShipToCity->Value  = "";
  OrdersShipToState->Value = "";
  OrdersShipToZip->Value = "";
  OrdersShipToCountry->Value = "";
  OrdersTaxRate->Value = Cust->Lookup("CustNo", OrdersCustNo->Value, "TaxRate");
}
//---------------------------------------------------------------------------

void __fastcall TMastData::CustBeforeOpen(TDataSet *DataSet)
{
  OrdByCust->Open();
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdByCustCalcFields(TDataSet *DataSet)
{
  OrdByCustAmountDue->Value = OrdByCustItemsTotal->Value +
    OrdByCustItemsTotal->Value * OrdByCustTaxRate->Value / 100 +
    OrdByCustFreight->Value - OrdByCustAmountPaid->Value;
}
//---------------------------------------------------------------------------
void __fastcall TMastData::CustBeforePost(TDataSet *DataSet)
{
  if (Cust->State == dsInsert)
  {
     NextCust->Open();
     try
     {
       NextCust->Edit();
       CustCustNo->Value = NextCustNewCust->Value;
       NextCustNewCust->Value = NextCustNewCust->Value + 1;
       NextCust->Post();
       NextCust->Close();
     }
     catch(...)
     {
       NextCust->Close();
     }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersAfterDelete(TDataSet *DataSet)
{
  TDBDataSet *dsArray[] = { Orders, Items, Parts, Cust };
  Database->ApplyUpdates((const TDBDataSet **)dsArray, 3);
}
//---------------------------------------------------------------------------
void __fastcall TMastData::OrdersBeforeEdit(TDataSet *DataSet)
{
  LastItemQuery->Close();
  LastItemQuery->Open();
  //SQL servers return Null for some aggregates if no items are present
  if (LastItemQuery->Fields->Fields[0]->IsNull)
    FItemNo = 1;
  else
    FItemNo = LastItemQuery->Fields->Fields[0]->AsInteger + 1;
}
//---------------------------------------------------------------------------
#pragma warn -stv
void __fastcall TMastData::EditUpdateError(TDataSet *DataSet, EDatabaseError *E,
	TUpdateKind UpdateKind, TUpdateAction &UpdateAction)
{
  Variant Key;
const char *  UpdErrMsg = "%s.\nDiscard the edits to %S %S and continue updating?";
char msgbuf[250];
  if (UpdateKind == ukDelete)
    Key = DataSet->Fields->Fields[0]->OldValue;
  else
    Key = DataSet->Fields->Fields[0]->NewValue;
  sprintf(msgbuf,UpdErrMsg,E->Message, DataSet->Fields->Fields[0]->DisplayLabel, Key);
  if (Confirm(msgbuf))
       UpdateAction = uaSkip;
  else
    UpdateAction = uaAbort;
}
#pragma warn .stv
//---------------------------------------------------------------------------
