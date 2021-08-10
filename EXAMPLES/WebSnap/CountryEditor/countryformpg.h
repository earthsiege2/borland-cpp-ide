
//---------------------------------------------------------------------------

#ifndef CountryFormPgH
#define CountryFormPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <CompProd.hpp>
#include <HTTPApp.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <MidItems.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TCountryForm : public TWebPageModule
{
__published:	// IDE-managed Components
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TAdapterErrorList *AdapterErrorList1;
  TAdapterFieldGroup *AdapterFieldGroup1;
  TAdapterCommandGroup *AdapterButtonGroup1;
  TAdapterActionButton *BtnApply;
  TAdapterActionButton *BtnRefreshRow;
  TAdapterActionButton *BtnCancel;
private:	// User declarations
public:		// User declarations
};

TCountryForm *CountryForm();

//---------------------------------------------------------------------------
extern PACKAGE TCountryForm *CountryForm();
//---------------------------------------------------------------------------
#endif

