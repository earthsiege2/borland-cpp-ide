
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DumpModulesPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TDumpModulesPage *DumpModulesPage()
{
  return (TDumpModulesPage*)WebContext()->FindModuleClass(__classid (TDumpModulesPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TDumpModulesPage), crOnDemand, caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

