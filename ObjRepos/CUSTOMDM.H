//----------------------------------------------------------------------------
#ifndef CustomDMH
#define CustomDMH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\DBTables.hpp>
#include <vcl\DB.hpp>
//----------------------------------------------------------------------------
class TCustomerData : public TDataModule
{
__published:
	TTable *Customers;
	TTable *Orders;
	TTable *LineItems;
	TFloatField *CustomersCustNo;
	TStringField *CustomersCompany;
	TStringField *CustomersAddr1;
	TStringField *CustomersAddr2;
	TStringField *CustomersCity;
	TStringField *CustomersState;
	TStringField *CustomersZip;
	TStringField *CustomersCountry;
	TStringField *CustomersPhone;
	TStringField *CustomersFAX;
	TFloatField *CustomersTaxRate;
	TStringField *CustomersContact;
	TDateTimeField *CustomersLastInvoiceDate;
	TFloatField *OrdersOrderNo;
	TFloatField *OrdersCustNo;
	TDateTimeField *OrdersSaleDate;
	TDateTimeField *OrdersShipDate;
	TIntegerField *OrdersEmpNo;
	TStringField *OrdersShipToContact;
	TStringField *OrdersShipToAddr1;
	TStringField *OrdersShipToAddr2;
	TStringField *OrdersShipToCity;
	TStringField *OrdersShipToState;
	TStringField *OrdersShipToZip;
	TStringField *OrdersShipToCountry;
	TStringField *OrdersShipToPhone;
	TStringField *OrdersShipVIA;
	TStringField *OrdersPO;
	TStringField *OrdersTerms;
	TStringField *OrdersPaymentMethod;
	TCurrencyField *OrdersItemsTotal;
	TFloatField *OrdersTaxRate;
	TCurrencyField *OrdersFreight;
	TCurrencyField *OrdersAmountPaid;
	TStringField *OrdersCustCompany;
	TFloatField *LineItemsOrderNo;
	TFloatField *LineItemsItemNo;
	TFloatField *LineItemsPartNo;
	TIntegerField *LineItemsQty;
	TFloatField *LineItemsDiscount;
	TCurrencyField *LineItemsPrice;
	TTable *Parts;
	TFloatField *PartsPartNo;
	TFloatField *PartsVendorNo;
	TStringField *PartsDescription;
	TFloatField *PartsOnHand;
	TFloatField *PartsOnOrder;
	TCurrencyField *PartsCost;
	TCurrencyField *PartsListPrice;
	TCurrencyField *LineItemsExtendedPrice;
	TCurrencyField *LineItemsTotal;
	TStringField *LineItemsPartName;
	TDataSource *CustomerSource;
	TDataSource *OrderSource;
	TDataSource *LineItemSource;
	TDataSource *PartSource;
	TTable *CustomerLookup;
	TFloatField *FloatField1;
	TStringField *StringField1;
	TStringField *StringField2;
	TStringField *StringField3;
	TStringField *StringField4;
	TStringField *StringField5;
	TStringField *StringField6;
	TStringField *StringField7;
	TStringField *StringField8;
	TStringField *StringField9;
	TFloatField *FloatField2;
	TStringField *StringField10;
	TDateTimeField *DateTimeField1;
	TTable *PartLookup;
	TFloatField *FloatField3;
	TFloatField *FloatField4;
	TStringField *StringField11;
	TFloatField *FloatField5;
	TFloatField *FloatField6;
	TCurrencyField *CurrencyField1;
	TCurrencyField *CurrencyField2;
	void __fastcall LineItemsCalcFields(TDataSet *DataSet);
private:
public:
	virtual __fastcall TCustomerData(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TCustomerData *CustomerData;
//----------------------------------------------------------------------------
#endif    
