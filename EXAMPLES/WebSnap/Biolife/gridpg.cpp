
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GridPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USEADDITIONALFILES("*.html");

TGridPage *GridPage()
{
  return (TGridPage*)WebContext()->FindModuleClass(__classid (TGridPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TGridPage),
  crOnDemand, caCache, PageAccess << wpPublished  << wpLoginRequired , ".html", "",
  "Grid Page", "", "");

