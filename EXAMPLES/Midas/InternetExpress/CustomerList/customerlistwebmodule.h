//---------------------------------------------------------------------------
#ifndef CustomerListWebModuleH
#define CustomerListWebModuleH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <MidItems.hpp>
#include <MidProd.hpp>
#include <PagItems.hpp>
#include <XMLBrokr.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        TDCOMConnection *DCOMConnection1;
        TMidasPageProducer *Data;
        TDataForm *DataForm1;
        TFieldGroup *FieldGroup1;
        TFieldText *OrderNo;
        TFieldText *SaleDate;
        TFieldText *ShipDate;
        TFieldText *ItemsTotal;
        TFieldText *AmountPaid;
        TDataNavigator *DataNavigator1;
        TDataGrid *DataGrid1;
        TTextColumn *OrderNo2;
        TTextColumn *ItemNo;
        TTextColumn *PartNo;
        TTextColumn *Qty;
        TTextColumn *Discount;
        TStatusColumn *StatusColumn1;
        TDataNavigator *DataNavigator2;
        TMidasPageProducer *CustList;
        TXMLBroker *XMLBroker1;
        TClientDataSet *CustNames;
        TMidasPageProducer *ReconcileError;
        void __fastcall DataHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall CustListHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall XMLBroker1RequestRecords(TObject *Sender,
          TWebRequest *Request, int RecCount, OleVariant &OwnerData,
          AnsiString &Records);
        void __fastcall DataBeforeGetContent(TObject *Sender);
        void __fastcall ReconcileErrorHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
private:	// User declarations
void __fastcall AddScript(void * Data, _di_IAddScriptElements AddScriptElements);
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
