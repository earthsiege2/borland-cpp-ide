
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
#include <WebUsers.hpp>

//---------------------------------------------------------------------------
class TMainPage : public TWebAppPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
	TWebAppComponents *WebAppComponents;
	TApplicationAdapter *ApplicationAdapter;
	TPageDispatcher *PageDispatcher;
	TAdapterDispatcher *AdapterDispatcher;
  TWebUserList *WebUserList1;
  TEndUserSessionAdapter *EndUserSessionAdapter1;
  TSessionsService *SessionsService1;
  TLocateFileService *LocateFileService1;
  void __fastcall LocateFileService1FindStream(TObject *ASender,
          TComponent *AComponent, const AnsiString AFileName,
          TStream *&AFoundStream, bool &AOwned, bool &AHandled);
private:	// User declarations
public:		// User declarations
};

TMainPage *MainPage();

//---------------------------------------------------------------------------
extern PACKAGE TWebAppPageModule *WebAppPageModule;
//---------------------------------------------------------------------------
#endif

