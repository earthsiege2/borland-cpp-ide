//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LoginPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USEADDITIONALFILES("*.html");

TLoginPage *LoginPage()
{
  return (TLoginPage*)WebContext()->FindModuleClass(__classid (TLoginPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TLoginPage),
  crOnDemand, caCache, PageAccess /* << wpPublished  << wpLoginRequired */, ".html", "",
  "Login", "", "");
