
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ReportPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TReportPage *ReportPage()
{
  return (TReportPage*)WebContext()->FindModuleClass(__classid (TReportPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TReportPage), crOnDemand,
  caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

