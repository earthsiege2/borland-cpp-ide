//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PhotoDataPg.h"
#include "MainPg.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <Jpeg.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

// Some consts used for cookies
const char *cThumbWidth = "Thumb Width";
const char *cPicturesPerRow = "Pictures Per Row";
const char *cPicturesPerPage = "Pictures Per Page";
const char *cCurrentViewMode = "Current View Mode";
const int cAllPictures = -1;

const char *rInvalidVote = "Invalid vote value (none may have been selected)";
const char *rUnknownImageType = "Unknown image type in the database!";
const char *rNoImageId = "No image id passed to get image procedure";
const char *rNullImageData = "NULL image data!";


const char* cSqlColSelect = "IMG_ID, IMG_WIDTH, IMG_HEIGHT, "
  "IMG_DATE, IMG_DESCRIPTION, CAT_NAME, IMG_RATING_SCORE, IMG_SIZE, "
  "IMG_TITLE, IMG_TYPE, IMG_VOTE_COUNT, USERS.USR_LOGIN, USERS.USR_ID, IMAGES.USR_ID, "
  "IMAGES.IMG_VIEW_COUNT";
const char* cSqlCountSelect = "COUNT(*)";

const char* cSqlSelectPictures = "select %s "
  "from IMAGES, CATEGORIES, USERS where %s";
const char* cSqlSelectAllPictures =
  "  IMAGES.CAT_ID = CATEGORIES.CAT_ID AND "
  "  IMAGES.USR_ID = USERS.USR_ID ";
const char* cSqlSelectCategory =
  " AND CATEGORIES.CAT_ID = %d";

TPhotoData *PhotoData() {
  return (TPhotoData*)WebContext()->FindModuleClass(__classid (TPhotoData));
}

static TWebDataModuleInit WebInit(__classid(TPhotoData),
  crOnDemand, caCache);

void __fastcall TPhotoData::WebDataModuleCreate(TObject *Sender)
{
  // setup the database name dynamically at runtime. We assume it is
  // in the same directory as the executable.
  // We must use localhost, otherwise Interbase will have threading issues.
  PhotoDatabase->DatabaseName = "localhost:" + QualifyFileName("PHOTODATABASE.GDB");
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::WebDataModuleActivate(TObject *Sender)
{
  GetCookieValue(cThumbWidth, &m_nThumbWidth, 200, 5);
  GetCookieValue(cPicturesPerRow, &m_nPicturesPerRow, 3, 0);
  GetCookieValue(cPicturesPerPage, &m_nPicturesPerPage, m_nPicturesPerRow, 0);
  GetCookieValue(cCurrentViewMode, &m_nCurrentViewMode, cAllPictures, 0);

  PhotoDatabase->Connected = true; // make sure we are still connected
  MainTransaction->Active = true; // and that the transaction is active.

  SetupQueries();
}
//---------------------------------------------------------------------------
void __fastcall TPhotoData::PicturesIteratorGetRecordCount(TObject *Sender,
      int &Count)
{
  qryRecCount->Close();
  qryRecCount->SQL->Text = Format(cSqlSelectPictures,
    OPENARRAY(TVarRec, (cSqlCountSelect, cSqlSelectAllPictures)));
  qryRecCount->Open();
  Count = qryRecCount->FieldByName("COUNT")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::VoteForPictureExecute(TObject *Sender,
      TStrings *Params)
{
  try {
    IActionFieldValue *Value = NewVote->ActionValue;
    if (Value) {
      int Vote = StrToInt(Value->Values[0]);
      if ((Vote < 1) || (Vote > 5))
        throw Exception(rInvalidVote);
        
      // Do the actual voting, with the stored procedure
      stdprcVoteForPicture->ParamByName(cImgId)->AsInteger =
        StrToInt(Params->Values[cImgId]);
      stdprcVoteForPicture->ParamByName(cImgVote)->AsInteger = Vote;
      stdprcVoteForPicture->ExecProc();
    }
    else
      throw Exception(rInvalidVote);
  }
  catch (Exception &E) {
      // don't redirect to allow the error to display
      TAdapterActionRedirectOptions r; 
      VoteForPicture->RedirectOptions = r;
      PicturesIterator->Errors->AddError(&E, "");
  }
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::VoteForPictureGetParams(TObject *Sender,
      TStrings *Params)
{
  Params->Values[cImgId] =
    PicturesIterator->DataSet->FieldByName(cImgId)->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::VoteForPictureGetEnabled(TObject *Sender,
      bool &Enabled)
{
/* TODO -ocorbin : This! */
//  Enabled = MainPageModule->GetCurrentUserName != "";
  Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ThumbWidthGetValue(TObject *Sender,
      Variant &Value)
{
  try  {
    Value = GetImageThumbWidth(PicturesIterator->DataSet);
  }
  catch (Exception &E) {
      PicturesIterator->Errors->AddError(&E, "");
      Value = 0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::MaxPicsPerRowGetValue(TObject *Sender,
      Variant &Value)
{
  Value = m_nPicturesPerRow;  
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ViewModeGetValue(TObject *Sender,
      Variant &Value)
{
  Value = m_nCurrentViewMode;
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ImageGetParams(TObject *Sender,
      TStrings *Params)
{
  Params->Values[cImgId] =
    PicturesIterator->DataSet->FieldByName(cImgId)->AsString;  
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ImageGetImage(TObject *Sender,
      TStrings *Params, AnsiString &MimeType, TStream *&Image, bool &Owned)
{
  if (Params->Values[cImgId] == "")
    throw Exception(rNoImageId);

  // Add an image view
  stdprcAddImageView->ParamByName(cImgId)->Value =
    Params->Values[cImgId];
  stdprcAddImageView->ExecProc();

  qryPicturesData->ParamByName(cImgId)->AsString =
    Params->Values[cImgId];
  qryPicturesData->Open();
  __try {
    Image = new TMemoryStream;
    qryPicturesDataIMG_DATA->SaveToStream(Image);
    Image->Position = 0;
    // The image types in this example are all jpegs. If
    // you support gifs, you can easily use the IMG_TYPE field
    // to store what format the image is in.
    TDBImageType ImageType = (TDBImageType)qryPicturesDataIMG_TYPE->AsInteger;
    if (ImageType == itJpeg) 
      MimeType = "image/jpeg";
//    else if (ImageType == itGif) 
//        MimeType = "image/gif"; 
    else
      throw Exception(rUnknownImageType);
  }
  __finally {
      qryPicturesData->Close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ThumbnailGetImage(TObject *Sender,
      TStrings *Params, AnsiString &MimeType, TStream *&Image, bool &Owned)
{
  TMemoryStream *Stream;
  TDBImageType ImageType;
  // Return the thumbnail image, resizing it based on the user"s
  // thumbnail preference saved in a cookie
  qryPicturesData->Close();
  qryPicturesData->ParamByName(cImgId)->AsInteger =
    StrToInt(Params->Values[cImgId]);

  qryPicturesData->Open();
  __try {
    if (qryPicturesDataIMG_DATA->IsNull)
      throw Exception(rNullImageData);

    // Save the data to the output stream
    Stream = new TMemoryStream;                                      
    Image = Stream;
    qryPicturesDataIMG_DATA->SaveToStream(Stream);
    ImageType = (TDBImageType)qryPicturesDataIMG_TYPE->AsInteger;
  }
  __finally {
    qryPicturesData->Close();
  }

  if (ImageType == itJpeg) {
    MimeType = "image/jpeg";
    // Resize the Jpeg
    TJPEGImage *jpeg = new TJPEGImage;
    __try {
      Stream->Position = 0;
      // Load the jpeg from the memory stream
      jpeg->LoadFromStream(Stream);
      // The output image is now our Memorystream that we
      // are workingw ith

      // Resize it to be a thumbnail
      Graphics::TBitmap *ThumbPicture = new Graphics::TBitmap;
      __try {
        ThumbPicture->IgnorePalette = True; // Important - if your server's display isn't set up to be 24-bit
        ThumbPicture->PixelFormat = pf24bit;
        ThumbPicture->Palette = jpeg->Palette;

        if (m_nThumbWidth > jpeg->Width)
          ThumbPicture->Width = jpeg->Width;
        else
          ThumbPicture->Width = m_nThumbWidth;
          
        ThumbPicture->Height = (int)((double)ThumbPicture->Width *
          ((double)jpeg->Height/(double)jpeg->Width));
          
        ThumbPicture->Canvas->StretchDraw(Rect(0, 0,
          ThumbPicture->Width-1, ThumbPicture->Height-1), jpeg);
        // Convert the bitmap to a jpeg
        jpeg->Assign(ThumbPicture);
      }
      __finally {
        delete ThumbPicture;
      }
      Stream->Clear();
      jpeg->SaveToStream(Stream);
    }
    __finally {
      delete jpeg;
    }
  }
//  else if (ImageType = itGif) {
//    MimeType = "image/gif";
// ...resize the gif to be a thumbnail
//  }
  else
    throw Exception(rUnknownImageType);
}

int __fastcall TPhotoData::GetImageThumbWidth(TDataSet *DataSet) {
  int width = DataSet->FieldByName(cImgWidth)->AsInteger;
  if (width > m_nThumbWidth)
    return m_nThumbWidth;
  else
    return width;
}

int __fastcall TPhotoData::GetImageThumbHeight(TDataSet *DataSet) {
  int PicWidth = DataSet->FieldByName(cImgWidth)->AsInteger;
  // No need to resize a small picture
  if (PicWidth <= m_nThumbWidth)
    return DataSet->FieldByName(cImgHeight)->AsInteger;
  else
    // Resize the height based on the requested thumb width
    return m_nThumbWidth * ((double)DataSet->FieldByName(cImgHeight)->AsInteger /
        (double)PicWidth);
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ThumbHeightGetValue(TObject *Sender,
      Variant &Value)
{
  try  {
    Value = GetImageThumbHeight(PicturesIterator->DataSet);
  }
  catch (Exception &E) {
      PicturesIterator->Errors->AddError(&E, "");
      Value = 0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ActualRatingGetValue(TObject *Sender,
      Variant &Value)
{
  int nVoteCount = qryAllPicturesInfo->FieldByName(cImgVoteCount)->AsInteger;
  if (nVoteCount)
    Value = Format("%1.2f", OPENARRAY(TVarRec,
      ((double)qryAllPicturesInfo->FieldByName(cImgRatingScore)->AsInteger /
       (double)nVoteCount)));
  else
    Value = "N/A";
}
//---------------------------------------------------------------------------



void __fastcall TPhotoData::WebDataModuleDestroy(TObject *Sender)
{
  PicturesIterator->DataSet = NULL;
  PhotoDatabase->Connected = false;
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::AllPicturesGetValue(TObject *Sender,
      Variant &Value)
{
  Value = cAllPictures; // Pass this on so it can be accessed in script
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::WebDataModuleDeactivate(TObject *Sender)
{
  SetCookieValue(cThumbWidth, m_nThumbWidth);
  SetCookieValue(cPicturesPerRow, m_nPicturesPerRow);
  SetCookieValue(cPicturesPerPage, m_nPicturesPerPage);
  SetCookieValue(cCurrentViewMode, m_nCurrentViewMode);
  // By committing the transaction, all other threads see
  // any changes (new votes, pictures, etc.).
  if (MainTransaction->Active)
    MainTransaction->Commit();
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::UpdateViewModeExecute(TObject *Sender,
      TStrings *Params)
{
  IActionFieldValue *ViewValue = ViewMode->ActionValue;
  if (ViewValue)
    m_nCurrentViewMode = StrToInt(ViewValue->Values[0]);
  // Possibly refresh the queries
  SetupQueries();
}
//---------------------------------------------------------------------------

void TPhotoData::SetupQueries() {
  // Set the SQL, only if it has changed
  AnsiString sNewSql = Format(cSqlSelectPictures,
    OPENARRAY(TVarRec, (cSqlColSelect, cSqlSelectAllPictures)));

  // Add on the category to the selection.. if not viewing all pictures
  if (m_nCurrentViewMode != cAllPictures)
  {
    AnsiString sCatSql = Format(cSqlSelectCategory, OPENARRAY(TVarRec,
      (m_nCurrentViewMode)));
    sNewSql += sCatSql; // append the category sql
  }

  // Possibly refresh the category sql
  if (sNewSql != qryAllPicturesInfo->SQL->Text) {
    qryAllPicturesInfo->Close();
    qryAllPicturesInfo->SQL->Text = sNewSql;
  }

  PicturesIterator->PageSize = m_nPicturesPerPage;
}

//---------------------------------------------------------------------------
void __fastcall TPhotoData::DeletePictureGetEnabled(TObject *Sender,
      bool &Enabled)
{
  // Enable the delete picture option only for admins, or the current
  // "owner" of the picture
  if (GetUserRights() == urAdmin)
    Enabled = true;
  else
  {
    AnsiString sUserId = Session->Values[cUserId];
    if (sUserId != "")
    {
      Enabled =
        (qryAllPicturesInfo->FieldByName(cUserId)->AsString == sUserId);
    }
    else
      Enabled = false;
  }

}
//---------------------------------------------------------------------------

TUserRights TPhotoData::GetUserRights()
{                                            
  qryUsers->Open();
  AnsiString sUserId = Session->Values[cUserId];
  try {
    TLocateOptions o;
    Variant V = sUserId;
    if ((sUserId != "") && (qryUsers->Locate(cUserId, VarArrayOf(&V, 1), o)))
      return TUserRights(qryUsers->FieldByName(cUserRights)->AsInteger);
    else
      return urNone;
  }
  catch(...)
  {
    return urNone;
  }
}

void __fastcall TPhotoData::DeletePictureExecute(TObject *Sender,
      TStrings *Params)
{
  sqlDeletePicture->ParamByName(cImgId)->AsInteger =
    StrToInt(Params->Values[cImgId]);
  sqlDeletePicture->ExecQuery();
}
//---------------------------------------------------------------------------


void __fastcall TPhotoData::ActionApply2AfterExecute(TObject *Sender,
      TStrings *Params)
{
  // Refresh the dataset
  qryUsers->Close();
  qryUsers->Open();
}
//---------------------------------------------------------------------------

void __fastcall TPhotoData::ActionApplyAfterExecute(TObject *Sender,
      TStrings *Params)
{
  // Refresh the dataset
  qryCategories->Close();
  qryCategories->Open();
}
//---------------------------------------------------------------------------

