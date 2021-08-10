
//---------------------------------------------------------------------------

#ifndef AddUsersPgH
#define AddUsersPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <CompProd.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TAddUsersPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TStringsValuesList *AccessRightsList;
  TAdapterPageProducer *AdapterPageProducer1;
  void __fastcall WebPageModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
};

TAddUsersPage *AddUsersPage();

//---------------------------------------------------------------------------
extern PACKAGE TAddUsersPage *AddUsersPage();
//---------------------------------------------------------------------------
#endif

