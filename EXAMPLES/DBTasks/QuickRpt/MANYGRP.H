//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef manygrpH
#define manygrpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <Quickrpt.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TManyGrpForm : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRGroup *QRGroup1;
	TQRDBText *QRDBText1;
	TQRGroup *QRGroup2;
	TQRExpr *QRExpr2;
	TQRExpr *QRExpr3;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRBand *QRBand1;
	TQRExpr *QRExpr4;
	TQRLabel *QRLabel5;
	TQRBand *QRBand2;
	TQRExpr *QRExpr1;
	TQRLabel *QRLabel4;
	TQRChildBand *ChildBand1;
	TQuery *RepQuery;
	TFloatField *RepQueryCustNo;
	TStringField *RepQueryCompany;
	TStringField *RepQueryAddr1;
	TStringField *RepQueryAddr2;
	TStringField *RepQueryCity;
	TStringField *RepQueryState;
	TStringField *RepQueryZip;
	TStringField *RepQueryCountry;
	TStringField *RepQueryPhone;
	TStringField *RepQueryFAX;
	TFloatField *RepQueryTaxRate;
	TStringField *RepQueryContact;
	TDateTimeField *RepQueryLastInvoiceDate;
	TFloatField *RepQueryOrderNo;
	TFloatField *RepQueryCustNo_1;
	TDateTimeField *RepQuerySaleDate;
	TDateTimeField *RepQueryShipDate;
	TIntegerField *RepQueryEmpNo;
	TStringField *RepQueryShipToContact;
	TStringField *RepQueryShipToAddr1;
	TStringField *RepQueryShipToAddr2;
	TStringField *RepQueryShipToCity;
	TStringField *RepQueryShipToState;
	TStringField *RepQueryShipToZip;
	TStringField *RepQueryShipToCountry;
	TStringField *RepQueryShipToPhone;
	TStringField *RepQueryShipVIA;
	TStringField *RepQueryPO;
	TStringField *RepQueryTerms;
	TStringField *RepQueryPaymentMethod;
	TCurrencyField *RepQueryItemsTotal;
	TFloatField *RepQueryTaxRate_1;
	TCurrencyField *RepQueryFreight;
	TCurrencyField *RepQueryAmountPaid;
	TFloatField *RepQueryOrderNo_1;
	TFloatField *RepQueryItemNo;
	TFloatField *RepQueryPartNo;
	TIntegerField *RepQueryQty;
	TFloatField *RepQueryDiscount;
	TFloatField *RepQueryPartNo_1;
	TFloatField *RepQueryVendorNo;
	TStringField *RepQueryDescription;
	TFloatField *RepQueryOnHand;
	TFloatField *RepQueryOnOrder;
	TCurrencyField *RepQueryCost;
	TCurrencyField *RepQueryListPrice;
private:	// User declarations
public:		// User declarations
	__fastcall TManyGrpForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TManyGrpForm *ManyGrpForm;
//---------------------------------------------------------------------------
#endif
