//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

TMainPage *MainPage()
{
  return (TMainPage*)WebContext()->FindModuleClass(__classid (TMainPage));
}

static TWebPageAccess PageAccess;
static TWebAppPageInit WebInit(__classid(TMainPage), caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");

void __fastcall TMainPage::ImageDataGetImage(
      TObject *Sender, TStrings *Params, AnsiString &MimeType,
      TStream *&Image, bool &Owned)
{
  Image = new TMemoryStream; // First, create the stream
  // Then, save the image out to the stream
  m_pjpgImage->SaveToStream(Image);
  // Be sure to set the MimeType to a jpeg
  MimeType = "image/jpeg";
}
//---------------------------------------------------------------------------

void __fastcall TMainPage::WebAppPageModuleCreate(TObject *Sender)
{
  // Create a JPEGImage to keep around. This way we can dynamically
  // set the width and height of the image inside of the HTML.
  m_pjpgImage = new TJPEGImage;

  // Notice how I use QualifyFileName to find the full path to the
  // image from the current directory.
  AnsiString FileName = QualifyFileName("test.jpg");
  TFileStream *fsImage = new TFileStream(FileName, fmOpenRead | fmShareDenyNone);
  __try {
    m_pjpgImage->LoadFromStream(fsImage);
  }
  __finally {
    delete fsImage;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainPage::WebAppPageModuleDestroy(
      TObject *Sender)
{
  delete m_pjpgImage;
}
//---------------------------------------------------------------------------

void __fastcall TMainPage::ImageWidthGetValue(TObject *Sender,
      Variant &Value)
{
  Value = m_pjpgImage->Width;
}
//---------------------------------------------------------------------------

void __fastcall TMainPage::ImageHeightGetValue(TObject *Sender,
      Variant &Value)
{
  Value = m_pjpgImage->Height;
}
//---------------------------------------------------------------------------

