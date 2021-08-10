
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DisplayOptionsPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "PhotoDataPg.h"
#include "MainPg.h"


USEADDITIONALFILES("*.html");

const
  char *rInvalidThumbWidth = "Invalid thumb width %d";
  char *rNoThumbWidth = "No preferred thumb width given";
  char *rPixPerRowGreaterThanZero = "Pictures per row must be greater than 0";
  char *rNoPixPerRow = "No pictures per row given";

  char *rPicGreaterThanZero = "Pictures per page must be greater than 0";
  char *rNoPicsPerPage = "No pictures per page value given";


TDisplayOptionsPage *DisplayOptionsPage()
{
  return (TDisplayOptionsPage*)WebContext()->FindModuleClass(__classid (TDisplayOptionsPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TDisplayOptionsPage),
  crOnDemand, caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "",
  "Display Options", "", "");

void __fastcall TDisplayOptionsPage::PreferredThumbWidthGetValue(
      TObject *Sender, Variant &Value)
{
  Value = PhotoData()->GetThumbWidth();
}
//---------------------------------------------------------------------------
void __fastcall TDisplayOptionsPage::MaxPicsPerPageGetValue(
      TObject *Sender, Variant &Value)
{
  Value = PhotoData()->GetPicturesPerPage();
}
//---------------------------------------------------------------------------
void __fastcall TDisplayOptionsPage::MaxPicsPerRowGetValue(TObject *Sender,
      Variant &Value)
{
  Value = PhotoData()->GetPicturesPerRow();
}
//---------------------------------------------------------------------------
void __fastcall TDisplayOptionsPage::PreferredThumbWidthValidateValue(
      TObject *Sender, IActionFieldValue *AValue, bool &Handled)
{
  int nNewWidth;
  Handled = True;
  if (AValue)
  {
    nNewWidth = AValue->Values[0];
    if (nNewWidth < 10)
      throw Exception(rInvalidThumbWidth,
        OPENARRAY(TVarRec, (nNewWidth)));
    PhotoData()->SetThumbWidth(nNewWidth);
  }
  else
    throw Exception(rNoThumbWidth);
}
//---------------------------------------------------------------------------
void __fastcall TDisplayOptionsPage::MaxPicsPerPageValidateValue(
      TObject *Sender, IActionFieldValue *AValue, bool &Handled)
{
  Handled = True;
  if (AValue)
  {
    int nValue = StrToInt(AValue->Values[0]);
    if (nValue <= 0)
      throw Exception(rPicGreaterThanZero);
    PhotoData()->SetPicturesPerPage(nValue);
  }
  else
    throw Exception(rNoPicsPerPage);
}
//---------------------------------------------------------------------------
void __fastcall TDisplayOptionsPage::SubmitOptionsExecute(TObject *Sender,
      TStrings *Params)
{
  // Update and validate the stuff
  DisplayOptions->UpdateRecords();
  // Redirect to the viewing page (safely- otherwise cookies will not get set)
  SafeRedirect(WebContext()->Response,
    WebContext()->Request->InternalScriptName + '/' +
    MainPage()->Name);

}
//---------------------------------------------------------------------------

