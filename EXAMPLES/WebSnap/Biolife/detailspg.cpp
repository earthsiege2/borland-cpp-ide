
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DetailsPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USEADDITIONALFILES("*.html");

TDetailsPage *DetailsPage()
{
  return (TDetailsPage*)WebContext()->FindModuleClass(__classid (TDetailsPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TDetailsPage),
  crOnDemand, caCache, PageAccess << wpPublished  << wpLoginRequired , ".html", "",
  "Details Page", "", "");

