
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CountryFormPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include "CountryTablePg.h"
#include <WebInit.h>
//---------------------------------------------------------------------------
USEADDITIONALFILES("*.html");

#pragma package(smart_init)
#pragma resource "*.dfm"

TCountryForm *CountryForm()
{
  return (TCountryForm*)WebContext()->FindModuleClass(__classid (TCountryForm));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TCountryForm), crOnDemand, caCache,
  PageAccess /*<< wpPublished  << wpLoginRequired */, ".html", "", "", "", "");


