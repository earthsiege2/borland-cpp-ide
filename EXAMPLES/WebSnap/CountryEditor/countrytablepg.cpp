
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
USEADDITIONALFILES("*.html");

TCountryTable *CountryTable()
{
  return (TCountryTable*)WebContext()->FindModuleClass(__classid (TCountryTable));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TCountryTable), crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");



void __fastcall TCountryTable::WebPageModuleCreate(TObject *Sender)
{
  Session1->Active = true;  
}
//---------------------------------------------------------------------------

