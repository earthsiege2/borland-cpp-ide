
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "OrderPg.h"
#include "MasterDataMod.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TOrderPage *OrderPage()
{
  return (TOrderPage*)WebContext()->FindModuleClass(__classid (TOrderPage));
}


static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TOrderPage), crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "Order Page", "", "");

