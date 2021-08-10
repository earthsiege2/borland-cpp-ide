//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainPg.h"
#include "PhotoDataPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "ErrorPg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TMainPage *MainPage()
{
  return (TMainPage*)WebContext()->FindModuleClass(__classid (TMainPage));
}

static TWebPageAccess PageAccess;
static TWebAppPageInit WebInit(__classid(TMainPage), caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

void __fastcall TMainPage::WebAppPageModuleAfterDispatchPage(
      TObject *Sender, const AnsiString PageName)
{
  // Don't cache this page
  WebContext()->Response->CustomHeaders->Add("Cache-control=no-cache");
  WebContext()->Response->CustomHeaders->Add("Pragma=no-cache");
}
//---------------------------------------------------------------------------


void __fastcall GetCookieValue(const char *sCookieName, int *nVariable,
  const int nDefault, const int nMinimum)
{
  *nVariable = nDefault; 
  try {
    *nVariable = StrToInt(WebContext()->Request->CookieFields->Values[sCookieName]);
    if (*nVariable < nMinimum)
      *nVariable = nDefault;
  } catch (...) {}
}

void __fastcall SetCookieValue(const char *sCookieName, int nVariable)
{
  TCookie* cookie = WebContext()->Response->Cookies->Add();
  cookie->Name = sCookieName;
  cookie->Value = IntToStr(nVariable);
//  cookie->Domain = "";     /* TODO : Add your domain here! */
  cookie->Path = WebContext()->Request->InternalScriptName;
  // Note: The expires is in GMT, but our time is in a particular time zone.
  // Ideally, you should convert Now() to GMT.
  cookie->Expires = Now() + 100;
}
void __fastcall TMainPage::EndUserSessionAdapter1HasRights(TObject *Sender,
      TStrings *Rights, bool &HasRights, bool &Handled)
{
  Handled = true;
  // No rights in the strings, mean it is a page for everyone to access
  if (Rights->Count == 0)
  {
    HasRights = true;
    return;
  }
  HasRights = false;

  // Look up the current user in the database, and see if they are there.
  // Return their rights from the database.
  TUserRights rights = PhotoData()->GetUserRights();
  for (int i = 0; i < Rights->Count; i++)
  {                       
    if (strcmp(Rights->Strings[i].c_str(), sUserRightStrings[rights]) == 0)
    {
      HasRights = true;
      break;
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainPage::WebAppComponentsException(TObject *Sender,
      Exception *E, bool &Handled)
{
  // Respond with the error page
  try {
    ErrorPage()->ErrorMessage = E->Message;
    TDispatchPageFlags AFlags;
    DispatchPageName(ErrorPage()->Name, Response, AFlags);
    Handled = true;
  }
  catch (...) {
    Handled = false;
  }
}
//---------------------------------------------------------------------------

