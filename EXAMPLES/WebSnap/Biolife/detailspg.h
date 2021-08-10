
//---------------------------------------------------------------------------

#ifndef DetailsPgH
#define DetailsPgH
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
class TDetailsPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TAdapterErrorList *AdapterErrorList1;
  TAdapterCommandGroup *AdapterButtonGroup1;
  TAdapterActionButton *BtnFirstRow;
  TAdapterActionButton *BtnPrevRow;
  TAdapterActionButton *BtnNextRow;
  TAdapterActionButton *BtnLastRow;
  TAdapterActionButton *BtnApply;
  TAdapterActionButton *BtnRefreshRow;
  TAdapterFieldGroup *AdapterFieldGroup1;
  TAdapterDisplayField *FldSpeciesNo;
  TAdapterDisplayField *FldCategory;
  TAdapterDisplayField *FldCommon_Name;
  TAdapterDisplayField *FldSpeciesName;
  TAdapterDisplayField *FldLengthcm;
  TAdapterDisplayField *FldLength_In;
  TAdapterDisplayField *FldNotes;
  TAdapterDisplayField *FldGraphic;
  TAdapterDisplayField *AdapterDisplayField;
private:	// User declarations
public:		// User declarations
};

TDetailsPage *DetailsPage();

//---------------------------------------------------------------------------
extern PACKAGE TWebPageModule *WebPageModule;
//---------------------------------------------------------------------------
#endif

