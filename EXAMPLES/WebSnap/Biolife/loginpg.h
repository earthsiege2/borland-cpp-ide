//---------------------------------------------------------------------------

#ifndef LoginPgH
#define LoginPgH
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
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TLoginPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TAdapterPageProducer *AdapterPageProducer;
  TAdapterForm *AdapterForm1;
  TAdapterErrorList *AdapterErrorList1;
  TAdapterFieldGroup *AdapterFieldGroup1;
  TAdapterCommandGroup *AdapterButtonGroup1;
  TAdapterActionButton *BtnLogin;
  TLoginFormAdapter *LoginFormAdapter1;
private:	// User declarations
public:		// User declarations
};

TLoginPage *LoginPage();

//---------------------------------------------------------------------------
extern PACKAGE TWebPageModule *WebPageModule;
//---------------------------------------------------------------------------
#endif

