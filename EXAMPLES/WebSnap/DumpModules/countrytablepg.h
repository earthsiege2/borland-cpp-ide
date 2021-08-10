
//---------------------------------------------------------------------------

#ifndef CountryTablePgH
#define CountryTablePgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBTables.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TCountryTablePage : public TWebPageModule
{
__published:	// IDE-managed Components
  TTable *Country;
  TStringField *CountryName;
  TStringField *CountryCapital;
  TStringField *CountryContinent;
  TFloatField *CountryArea;
  TFloatField *CountryPopulation;
  TSession *Session1;
  TDataSetAdapter *Adapter;
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TAdapterErrorList *AdapterErrorList1;
  TAdapterGrid *AdapterGrid1;
  TAdapterDisplayColumn *ColName;
  TAdapterDisplayColumn *ColCapital;
  TAdapterDisplayColumn *ColContinent;
  TAdapterDisplayColumn *ColArea;
  TAdapterDisplayColumn *ColPopulation;
  TAdapterCommandColumn *AdapterCommandColumn1;
  TAdapterActionButton *NewRow;
  TAdapterActionButton *EditRow;
        TAdapterActionButton *DeleteRow;
private:	// User declarations
public:		// User declarations
};

TCountryTablePage *CountryTablePage();

//---------------------------------------------------------------------------
extern PACKAGE TCountryTablePage *CountryTablePage();
//---------------------------------------------------------------------------
#endif

