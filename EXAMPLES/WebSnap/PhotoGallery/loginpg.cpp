
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LoginPg.h"
#include "PhotoDataPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <ReqMulti.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)   
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");
                                          
TLoginPage *LoginPage()
{
  return (TLoginPage*)WebContext()->FindModuleClass(__classid (TLoginPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TLoginPage), crOnDemand,
  caCache, PageAccess /* << wpPublished << wpLoginRequired */, ".html", "",
    "Login", "", "");

void __fastcall TLoginPage::LoginFormAdapter1Login(TObject *Sender,
      Variant &UserID)
{
  // Empty the previous (possibly empty) user id in the session
  Session->Values[cUserId] = "";

  // Login the given user, if possible
  AnsiString sLoginName = "";
  AnsiString sPassword = "";
  if (AdaptUserName->ActionValue)
    sLoginName = AdaptUserName->ActionValue->Values[0];
  if (AdaptPassword->ActionValue)
    sPassword = AdaptPassword->ActionValue->Values[0];

  // Look up the current user in the database, and see if they are there.
  // Return their rights from the database.
  TIBQuery *pUsers = PhotoData()->qryUsers;
  pUsers->Open();
  TLocateOptions o;
  Variant V = sLoginName;
  if (pUsers->Locate(cUserLogin, VarArrayOf(&V, 0), o))
  {
    // Save their user id in the session, to mark they are logged in.
    if (pUsers->FieldByName(cUserPassword)->AsString == sPassword)
      Session->Values[cUserId] = pUsers->FieldByName(cUserId)->AsString;
    else
      throw Exception("I found you in the database, but that is an invalid password");
  }
  else
    throw Exception("User name not found in database!");
}
//---------------------------------------------------------------------------

