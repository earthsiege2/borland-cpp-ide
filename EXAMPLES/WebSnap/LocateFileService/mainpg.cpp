//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>

#include "MainPg.h"
#include "ResourceLocator.h"

USEADDITIONALFILES("*.html");

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainPage *MainPage()
{
  return (TMainPage*)WebContext()->FindModuleClass(__classid (TMainPage));
}

static TWebPageAccess PageAccess;
static TWebAppPageInit WebInit(__classid(TMainPage), caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

void __fastcall TMainPage::LocateFileService1FindStream(TObject *ASender,
      TComponent *AComponent, const AnsiString AFileName,
      TStream *&AFoundStream, bool &AOwned, bool &AHandled)
{
  // After dropping down the LocateFileService component,
  // I double clicked on the OnFindStream event. This event will
  // get fired anytime a template is located, or an include file is requested.
  AHandled = TemplateFileStreamFromResource(AFileName, AFoundStream);
}
//---------------------------------------------------------------------------





