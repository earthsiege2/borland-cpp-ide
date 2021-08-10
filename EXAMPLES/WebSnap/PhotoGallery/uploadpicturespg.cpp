
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UploadPicturesPg.h"
#include "PhotoDataPg.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <Jpeg.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

USEADDITIONALFILES("*.html");

const char* rNoFilesUploaded = "No files uploaded - please select a file.";
const char* rRequiredImage = "Unsupported image. The supported image type is only jpeg.";
const char* rNoUploadFileFound = "No Upload File found! Did you select a file?";
const char* rUploadPageTitle = "Upload Pictures";
const char* rNoTitle = "(Untitled)";
const char* rNotLoggedIn = "Please login!";


TUploadPicturesPage *UploadPicturesPage()
{
  return (TUploadPicturesPage*)WebContext()->FindModuleClass(__classid (TUploadPicturesPage));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TUploadPicturesPage),
  crOnDemand, caCache,
  PageAccess << wpPublished << wpLoginRequired, ".html", "",
  "Upload Pictures", "",
  // Limit upload access to only user's and admin's
  AnsiString(sUserRightStrings[urAdmin]) + ";" + AnsiString(sUserRightStrings[urUser]));



void __fastcall TUploadPicturesPage::UploadFileUploadFiles(TObject *Sender,
      TUpdateFileList *Files)
{
  try
  {
    TIBQuery *qryAddImage = PhotoData()->qryAddImage;
    // the current user id is stored in the sessino
    AnsiString sUserId = Session->Values[cUserId];
    int nUserId = StrToInt(sUserId);
    for (int i = 0; i < Files->Count; i++)
    {
      TDBImageType ImageType = itJpeg;

      // Make sure that the file is jpeg content type
      if (SameText(Files->Files[i]->ContentType, "image/jpeg") ||
          SameText(Files->Files[i]->ContentType, "image/pjpeg")) 
      {
        // Try to get the image width and height. An exception will be
        // raised if it is an invalid image.
        TJPEGImage *Jpeg = new TJPEGImage;
        __try
        {
          Jpeg->LoadFromStream(Files->Files[i]->Stream);
          qryAddImage->ParamByName(cImgWidth)->AsInteger =
            Jpeg->Width;
          qryAddImage->ParamByName(cImgHeight)->AsInteger =
            Jpeg->Height;
        }
        __finally {
          delete Jpeg;
        }

        Files->Files[i]->Stream->Position = 0;
        // Save the file in the database
        qryAddImage->ParamByName(cImgData)->SetBlobData(
          ((TMemoryStream*)Files->Files[i]->Stream)->Memory,
          Files->Files[i]->Stream->Size);

        qryAddImage->ParamByName(cImgSize)->AsInteger =
          Files->Files[i]->Stream->Size;
      }
      /* TODO : You can add support for other image types here */
      else
        throw Exception(rRequiredImage);

      // Fill in things common to all image types
      qryAddImage->ParamByName(cImgType)->AsInteger = ImageType;
      qryAddImage->ParamByName(cUserId)->AsInteger = nUserId;

      if (Title->ActionValue)
        qryAddImage->ParamByName(cImgTitle)->AsString = Title->ActionValue->Values[0];
      else
        qryAddImage->ParamByName(cImgTitle)->AsString = rNoTitle;

      if (Description->ActionValue)
        qryAddImage->ParamByName(cImgDescription)->AsString =
          Description->ActionValue->Values[0];
      else
        qryAddImage->ParamByName(cImgDescription)->AsString = "";

      if (Category->ActionValue)
        qryAddImage->ParamByName(cCatId)->AsString = Category->ActionValue->Values[0];

      qryAddImage->ExecSQL();
      UploadedFiles->Strings->Values[ExtractFileName(Files->Files[i]->FileName)]
        = IntToStr(Files->Files[i]->Stream->Size);

    } // for loop
  } // try
  catch (Exception &e) {
    UploadAdapter->Errors->AddError(&e, "");
  }
}
//---------------------------------------------------------------------------
void __fastcall TUploadPicturesPage::UploadAdapterBeforeExecuteAction(
      TObject *Sender, TObject *Action, TStrings *Params, bool &Handled)
{
  if (Request->Files->Count <= 0)
    UploadAdapter->Errors->AddError(rNoFilesUploaded);
}
//---------------------------------------------------------------------------
void __fastcall TUploadPicturesPage::UploadExecute(TObject *Sender,
      TStrings *Params)
{
  UploadAdapter->UpdateRecords(); // Causes the fields to be updated, and files to be accepted
}
//---------------------------------------------------------------------------
void __fastcall TUploadPicturesPage::WebPageModuleActivate(TObject *Sender)
{
  UploadedFiles->Strings->Clear();
}
//---------------------------------------------------------------------------
