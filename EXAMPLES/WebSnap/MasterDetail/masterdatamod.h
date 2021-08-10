
//---------------------------------------------------------------------------

#ifndef MasterDataModH
#define MasterDataModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBTables.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>


//---------------------------------------------------------------------------
class TMasterDataModule : public TWebDataModule
{
__published:	// IDE-managed Components
  TTable *OrdersTable;
  TFloatField *OrdersTableOrderNo;
  TFloatField *OrdersTableCustNo;
  TDateTimeField *OrdersTableSaleDate;
  TDateTimeField *OrdersTableShipDate;
  TIntegerField *OrdersTableEmpNo;
  TStringField *OrdersTableShipToContact;
  TStringField *OrdersTableShipToAddr1;
  TStringField *OrdersTableShipToAddr2;
  TStringField *OrdersTableShipToCity;
  TStringField *OrdersTableShipToState;
  TStringField *OrdersTableShipToZip;
  TStringField *OrdersTableShipToCountry;
  TStringField *OrdersTableShipToPhone;
  TStringField *OrdersTableShipVIA;
  TStringField *OrdersTablePO;
  TStringField *OrdersTableTerms;
  TStringField *OrdersTablePaymentMethod;
  TCurrencyField *OrdersTableItemsTotal;
  TFloatField *OrdersTableTaxRate;
  TCurrencyField *OrdersTableFreight;
  TCurrencyField *OrdersTableAmountPaid;
  TSession *Session1;
  TTable *ItemsTable;
  TFloatField *ItemsTableOrderNo;
  TFloatField *ItemsTableItemNo;
  TFloatField *ItemsTablePartNo;
  TIntegerField *ItemsTableQty;
  TFloatField *ItemsTableDiscount;
  TDataSource *DataSource1;
  TDataSetAdapter *OrdersAdapter;
  TDataSetAdapterDeleteRowAction *ActionDeleteRow2;
  TDataSetAdapterFirstRowAction *ActionFirstRow2;
  TDataSetAdapterPrevRowAction *ActionPrevRow2;
  TDataSetAdapterNextRowAction *ActionNextRow2;
  TDataSetAdapterLastRowAction *ActionLastRow2;
  TDataSetAdapterEditRowAction *ActionEditRow2;
  TDataSetAdapterBrowseRowAction *ActionBrowseRow2;
  TDataSetAdapterNewRowAction *ActionNewRow2;
  TDataSetAdapterCancelRowAction *ActionCancel2;
  TDataSetAdapterApplyRowAction *ActionApply2;
  TDataSetAdapterRefreshRowAction *ActionRefreshRow2;
  TDataSetAdapter *ItemsAdapter;
  TDataSetAdapterDeleteRowAction *ActionDeleteRow;
  TDataSetAdapterNewRowAction *ActionNewRow;
  TDataSetAdapterCancelRowAction *ActionCancel;
  TDataSetAdapterApplyRowAction *ActionApply;
  TDataSetAdapterRefreshRowAction *ActionRefreshRow;
  TDataSetAdapterField *AdaptOrderNo;
  TDataSetAdapterField *AdaptItemNo;
  TDataSetAdapterField *AdaptPartNo;
  TDataSetAdapterField *AdaptQty;
  TDataSetAdapterField *AdaptDiscount;
  TDataSetValuesList *PartNoValuesList;
  TQuery *PartNoQuery;
  TDataSetAdapter *QueryAdapter;
  TAdapterPrevPageAction *ActionPrevPage;
  TAdapterGotoPageAction *ActionGotoPage;
  TAdapterNextPageAction *ActionNextPage;
  TDataSetAdapterBrowseRowAction *ActionBrowseRow;
  TAdapterAction *BrowseOrder;
  TQuery *Query1;
  TFloatField *Query1CustNo;
  TStringField *Query1Company;
  TFloatField *Query1OrderNo;
  TDateTimeField *Query1SaleDate;
  TDateTimeField *Query1ShipDate;
  TIntegerField *Query1EmpNo;
  TCurrencyField *Query1ItemsTotal;
  TCurrencyField *Query1AmountPaid;
  void __fastcall ActionBrowseRow2AfterExecute(TObject *Sender,
          TStrings *Params);
  void __fastcall ActionEditRow2AfterExecute(TObject *Sender,
          TStrings *Params);
  void __fastcall ActionCancelBeforeExecute(TObject *Sender,
          TStrings *Params, bool &Handled);
  void __fastcall ActionBrowseRowAfterExecute(TObject *Sender,
          TStrings *Params);
  void __fastcall BrowseOrderGetParams(TObject *Sender, TStrings *Params);
  void __fastcall BrowseOrderExecute(TObject *Sender, TStrings *Params);
private:	// User declarations
public:		// User declarations
};

TMasterDataModule *MasterDataModule();

//---------------------------------------------------------------------------
extern PACKAGE TMasterDataModule *MasterDataModule();
//---------------------------------------------------------------------------
#endif

