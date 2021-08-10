
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SecondPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TSecondPage *SecondPage()
{
  return (TSecondPage*)WebContext()->FindModuleClass(__classid (TSecondPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TSecondPage), crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "Second Page", "", "");
 