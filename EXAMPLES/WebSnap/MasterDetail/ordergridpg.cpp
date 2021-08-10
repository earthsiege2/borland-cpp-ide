
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "OrderGridPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TOrderGridPage *OrderGridPage()
{
  return (TOrderGridPage*)WebContext()->FindModuleClass(__classid (TOrderGridPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TOrderGridPage), crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "Order Grid", "", "");


