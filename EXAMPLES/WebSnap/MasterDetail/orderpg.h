
//---------------------------------------------------------------------------

#ifndef OrderPgH
#define OrderPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TOrderPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TLayoutGroup *LayoutGroup1;
  TLayoutGroup *OrdersLayoutGroup;
  TAdapterErrorList *OrderErrors;
  TAdapterFieldGroup *OrderFieldGroup;
  TAdapterDisplayField *FldOrderNo;
  TAdapterDisplayField *FldCustNo;
  TAdapterDisplayField *FldSaleDate;
  TAdapterDisplayField *FldShipDate;
  TAdapterDisplayField *FldEmpNo;
  TAdapterDisplayField *FldShipToContact;
  TAdapterDisplayField *FldShipToAddr1;
  TAdapterDisplayField *FldShipToAddr2;
  TAdapterDisplayField *FldShipToCity;
  TAdapterDisplayField *FldShipToState;
  TAdapterDisplayField *FldShipToZip;
  TAdapterDisplayField *FldShipToCountry;
  TAdapterDisplayField *FldShipToPhone;
  TAdapterDisplayField *FldShipVIA;
  TAdapterDisplayField *FldPO;
  TAdapterDisplayField *FldTerms;
  TAdapterDisplayField *FldPaymentMethod;
  TAdapterDisplayField *FldItemsTotal;
  TAdapterDisplayField *FldTaxRate;
  TAdapterDisplayField *FldFreight;
  TAdapterDisplayField *FldAmountPaid;
  TLayoutGroup *ItemsLayoutGroup;
  TAdapterErrorList *ItemsErrors;
  TAdapterGrid *ItemsGrid;
  TAdapterDisplayColumn *ColItemNo;
  TAdapterEditColumn *ColEditQty;
  TAdapterEditColumn *ColEditPartNo;
  TAdapterEditColumn *ColEditDiscount;
  TAdapterCommandGroup *OrderCommandGroup;
  TAdapterActionButton *CmdEditRow;
  TAdapterActionButton *CmdBrowseRow;
  TAdapterActionButton *CmdCancel;
  TAdapterActionButton *CmdApply;
  TAdapterActionButton *CmdRefreshRow;
private:	// User declarations
public:		// User declarations
};

TOrderPage *OrderPage();

//---------------------------------------------------------------------------
extern PACKAGE TOrderPage *OrderPage();
//---------------------------------------------------------------------------
#endif

