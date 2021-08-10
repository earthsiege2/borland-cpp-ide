
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ErrorPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TErrorPage *ErrorPage()
{
  return (TErrorPage*)WebContext()->FindModuleClass(__classid (TErrorPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TErrorPage),
  crOnDemand, caCache,
  PageAccess /* << wpPublished << wpLoginRequired */, ".html", "", "", "", "");

void __fastcall TErrorPage::ErrorMessageFieldGetValue(TObject *Sender,
      Variant &Value)
{
  Value = ErrorMessage;  
}
//---------------------------------------------------------------------------
