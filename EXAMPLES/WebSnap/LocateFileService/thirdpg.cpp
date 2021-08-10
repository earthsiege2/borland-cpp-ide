
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ThirdPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TThirdPage *ThirdPage()
{
  return (TThirdPage*)WebContext()->FindModuleClass(__classid (TThirdPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TThirdPage), crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "Third Page", "", "");
