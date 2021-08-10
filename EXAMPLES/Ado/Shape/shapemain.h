//---------------------------------------------------------------------------
#ifndef ShapeMainH
#define ShapeMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TShapeForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *DataSourceLabel;
        TLabel *DataProviderLabel;
        TLabel *ProviderLabel;
        TEdit *Provider;
        TEdit *DataProvider;
        TEdit *DataSource;
        TLabel *Label4;
        TButton *OpenButton;
        TADOConnection *ADOConnection1;
        TDBGrid *DBGrid1;
        TDataSource *CustSource;
        TADODataSet *Customers;
        TFloatField *CustomersCustNo;
        TWideStringField *CustomersCompany;
        TWideStringField *CustomersAddr1;
        TWideStringField *CustomersAddr2;
        TWideStringField *CustomersCity;
        TWideStringField *CustomersState;
        TWideStringField *CustomersZip;
        TWideStringField *CustomersCountry;
        TWideStringField *CustomersPhone;
        TWideStringField *CustomersFAX;
        TFloatField *CustomersTaxRate;
        TWideStringField *CustomersContact;
        TDateField *CustomersLastInvoiceDate;
        TDataSetField *CustomersOrders;
        TDBGrid *DBGrid2;
        TDataSource *OrderSource;
        TADODataSet *Orders;
        TFloatField *OrdersOrderNo;
        TFloatField *OrdersCustNo;
        TDateField *OrdersSaleDate;
        TDateField *OrdersShipDate;
        TIntegerField *OrdersEmpNo;
        TWideStringField *OrdersShipToContact;
        TWideStringField *OrdersShipToAddr1;
        TWideStringField *OrdersShipToAddr2;
        TWideStringField *OrdersShipToCity;
        TWideStringField *OrdersShipToState;
        TWideStringField *OrdersShipToZip;
        TWideStringField *OrdersShipToCountry;
        TWideStringField *OrdersShipToPhone;
        TWideStringField *OrdersShipVIA;
        TWideStringField *OrdersPO;
        TWideStringField *OrdersTerms;
        TWideStringField *OrdersPaymentMethod;
        TFloatField *OrdersItemsTotal;
        TFloatField *OrdersTaxRate;
        TFloatField *OrdersFreight;
        TFloatField *OrdersAmountPaid;
        void __fastcall OpenButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TShapeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TShapeForm *ShapeForm;
//---------------------------------------------------------------------------
#endif
