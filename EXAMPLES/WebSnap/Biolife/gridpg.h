
//---------------------------------------------------------------------------

#ifndef GridPgH
#define GridPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <CompProd.hpp>
#include <HTTPApp.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TGridPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TAdapterGrid *AdapterGrid1;
  TAdapterDisplayColumn *ColSpeciesNo;
  TAdapterDisplayColumn *ColCategory;
  TAdapterDisplayColumn *ColCommon_Name;
  TAdapterDisplayColumn *ColSpeciesName;
  TAdapterDisplayColumn *ColGraphic;
  TAdapterCommandColumn *AdapterCommandColumn1;
  TAdapterActionButton *CmdEditRow;
private:	// User declarations
public:		// User declarations
};

TGridPage *GridPage();

//---------------------------------------------------------------------------
extern PACKAGE TWebPageModule *WebPageModule;
//---------------------------------------------------------------------------
#endif

