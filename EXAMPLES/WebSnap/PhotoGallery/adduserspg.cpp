
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "AddUsersPg.h"
#include "PhotoDataPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TAddUsersPage *AddUsersPage()
{
  return (TAddUsersPage*)WebContext()->FindModuleClass(__classid (TAddUsersPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TAddUsersPage), crOnDemand, caCache,
  PageAccess << wpPublished << wpLoginRequired, ".html", "",
  "Add/Modify Users", "",
  sUserRightStrings[urAdmin] // Limit view access to admin's
  );
void __fastcall TAddUsersPage::WebPageModuleCreate(TObject *Sender)
{
  for (int i=0; sUserRightStrings[i]; i++)
    AccessRightsList->Strings->Values[sUserRightStrings[i]] = IntToStr(i);
}
//---------------------------------------------------------------------------

