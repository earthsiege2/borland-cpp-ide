//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainPg.h" 
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TMainPage *MainPage()
{
  return (TMainPage*)WebContext()->FindModuleClass(__classid (TMainPage));
}


static TWebPageAccess PageAccess;
static TWebAppPageInit WebInit(__classid(TMainPage), caCache,
  PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

void __fastcall TMainPage::LocateFileService1FindStream(TObject *ASender,
      TComponent *AComponent, const AnsiString AFileName,
      TStream *&AFoundStream, bool &AOwned, bool &AHandled)
{
  // I wanted to make this demo dynamically add the "readme.txt" into the
  // MainPage. So, in MainPage.html I added:
  // <!--#include file="readme.txt"-->
  // Then, dropped a TLocateFileService down on the module and double clicked
  // on the OnFindStream event.
  if (SameText(AFileName, AnsiString("readme.txt"))) {
    // Notice that I use QualifyFileName. This is because we need the
    // full path to the file, based on the current executable's location
    // (which could be a DLL or an EXE, depending on how the project is built).
    TStringList *pReadmeText = new TStringList;
    pReadmeText->LoadFromFile(QualifyFileName("readme.txt"));
    // Replace all newlines with <br>'s for HTML
    TReplaceFlags fFlags;
    fFlags << rfReplaceAll;
    // Replace all HTML escapses, first
    AnsiString sResult = StringReplace(pReadmeText->Text, "<", "&lt;", fFlags);
    sResult = StringReplace(sResult, ">", "&gt;", fFlags);
    // Now, do the newlines
    sResult = StringReplace(sResult, "\n", "<br>", fFlags);
    // Create a StringStream to hold the result
    AFoundStream = new TStringStream(sResult);
  }
}
//---------------------------------------------------------------------------
