
//---------------------------------------------------------------------------

#ifndef MainPgH
#define MainPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <ReqMulti.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <WebDisp.hpp>
#include <WebSess.hpp>

//---------------------------------------------------------------------------
class TMainPage : public TWebAppPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
	TWebAppComponents *WebAppComponents;
	TApplicationAdapter *ApplicationAdapter;
	TPageDispatcher *PageDispatcher;
	TAdapterDispatcher *AdapterDispatcher;
  TEndUserSessionAdapter *EndUserSessionAdapter1;
  TSessionsService *SessionsService1;
  void __fastcall WebAppPageModuleAfterDispatchPage(TObject *Sender,
          const AnsiString PageName);
  void __fastcall EndUserSessionAdapter1HasRights(TObject *Sender,
          TStrings *Rights, bool &HasRights, bool &Handled);
  void __fastcall WebAppComponentsException(TObject *Sender, Exception *E,
          bool &Handled);
private:	// User declarations
public:		// User declarations
};

TMainPage *MainPage();

void __fastcall GetCookieValue(const char *sCookieName, int *nVariable,
  const int nDefault, const int nMinimum);
void __fastcall SetCookieValue(const char *sCookieName, int nVariable);


//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage();
//---------------------------------------------------------------------------
#endif

