//---------------------------------------------------------------------------

#ifndef ReportPgH
#define ReportPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBTables.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>

//---------------------------------------------------------------------------
class TReportPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TPageProducer *PageProducer;
  TTable *Table1;
  TStringField *Table1Name;
  TStringField *Table1Capital;
  TStringField *Table1Continent;
  TFloatField *Table1Area;
  TFloatField *Table1Population;
  TDataSetAdapter *Adapter;
  TSession *Session1;
private:	// User declarations
public:		// User declarations
};

TReportPage *ReportPage();

//---------------------------------------------------------------------------
extern PACKAGE TReportPage *ReportPage();
//---------------------------------------------------------------------------

#endif

