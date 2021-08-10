
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CountryTablePg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TCountryTablePage *CountryTablePage()
{
  return (TCountryTablePage*)WebContext()->FindModuleClass(__classid (TCountryTablePage));
}

static TWebPageAccess PageAccess;
// Note:  Change the crewate from crOnDemand to crAlways so that this module
// is always available when all modules are traversed.
static TWebPageInit WebInit(__classid(TCountryTablePage), crAlways, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");


