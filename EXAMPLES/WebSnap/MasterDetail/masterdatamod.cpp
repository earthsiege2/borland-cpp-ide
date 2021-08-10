//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MasterDataMod.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include "OrderPg.h"
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMasterDataModule *MasterDataModule()
{
  return (TMasterDataModule*)WebContext()->FindModuleClass(__classid (TMasterDataModule));
}

static TWebDataModuleInit WebInit(__classid(TMasterDataModule), crOnDemand,
  caCache);

void __fastcall TMasterDataModule::ActionBrowseRow2AfterExecute(
      TObject *Sender, TStrings *Params)
{
  // Browse button puts both adapter's into browse mode
  if (OrdersAdapter->Mode == amBrowse)
    ItemsAdapter->Mode = amBrowse;
}
//---------------------------------------------------------------------------
void __fastcall TMasterDataModule::ActionEditRow2AfterExecute(
      TObject *Sender, TStrings *Params)
{
  // Edit button puts both adapter's into edit mode
  if (OrdersAdapter->Mode == amEdit)
    ItemsAdapter->Mode = amEdit;
}
//---------------------------------------------------------------------------
void __fastcall TMasterDataModule::ActionCancelBeforeExecute(
      TObject *Sender, TStrings *Params, bool &Handled)
{
  // Set default action to execute when leave new... form
  if (OrdersAdapter->Mode == amEdit) 
    OrderPage()->DefaultAction->ActionName = ActionEditRow2->ActionName;
  else
    OrderPage()->DefaultAction->ActionName = ActionBrowseRow2->ActionName;

}
//---------------------------------------------------------------------------
void __fastcall TMasterDataModule::ActionBrowseRowAfterExecute(
      TObject *Sender, TStrings *Params)
{
/*
  if (!QueryAdapter->Errors->ErrorCount)
  {
    OrdersAdapter->DataSet->Open();
    if (!OrdersAdapter->DataSet->Locate("OrderNo",
      OrdersAdapter->DataSet->FieldByName("OrderNo")->Value, []..)
        throw new Exception("Record not found");
  }
*/
}
//---------------------------------------------------------------------------

void __fastcall TMasterDataModule::BrowseOrderGetParams(TObject *Sender,
      TStrings *Params)
{
  Params->Values["OrderNo"] =
    QueryAdapter->DataSet->FieldByName("OrderNo")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TMasterDataModule::BrowseOrderExecute(TObject *Sender,
      TStrings *Params)
{
  OrdersAdapter->DataSet->Open();
  TLocateOptions opt;
  if (!OrdersAdapter->DataSet->Locate("OrderNo",
        StrToInt(Params->Values["OrderNo"]), opt))
    throw new Exception("Record not found");  
}
//---------------------------------------------------------------------------

