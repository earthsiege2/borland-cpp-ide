
//---------------------------------------------------------------------------

#ifndef LoginPgH
#define LoginPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
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
  TLoginFormAdapter *LoginFormAdapter1;
  TAdapterPageProducer *AdapterPageProducer1;
  TAdapterForm *AdapterForm1;
  TAdapterFieldGroup *AdapterFieldGroup1;
  TAdapterDisplayField *FldUserName;
  TAdapterDisplayField *FldPassword;
  TAdapterCommandGroup *AdapterCommandGroup1;
  TAdapterUserNameField *AdaptUserName;
  TAdapterPasswordField *AdaptPassword;
  TAdapterNextPageField *AdaptNextPage;
  TAdapterErrorList *AdapterErrorList1;
  TAdapterActionButton *CmdLogin;
  void __fastcall LoginFormAdapter1Login(TObject *Sender, Variant &UserID);
private:	// User declarations
public:		// User declarations
};

TLoginPage *LoginPage();

//---------------------------------------------------------------------------
extern PACKAGE TLoginPage *LoginPage();
//---------------------------------------------------------------------------
#endif

