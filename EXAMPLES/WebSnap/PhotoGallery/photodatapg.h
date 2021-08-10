//---------------------------------------------------------------------------

#ifndef PhotoDataPgH
#define PhotoDataPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <IBStoredProc.hpp>                                                            
#include <IBUpdateSQL.hpp>
#include <IBSQL.hpp>

enum TUserRights  {urAdmin = 0, urUser = 1, urNone = 2};
const char* const sUserRightStrings[] = {"urAdmin", "urUser", "urNone", NULL};
// Image types; gif support isn't enabled.
enum TDBImageType {itJpeg = 0, itGif = 1};

// Database constants
const char* const cImgId = "IMG_ID";
const char* const cImgVote = "IMG_VOTE";
const char* const cImgWidth = "IMG_WIDTH";
const char* const cImgHeight = "IMG_HEIGHT";
const char* const cImgVoteCount = "IMG_VOTE_COUNT";
const char* const cImgData = "IMG_DATA";
const char* const cImgSize = "IMG_SIZE";
const char* const cImgType = "IMG_TYPE";
const char* const cImgRatingScore = "IMG_RATING_SCORE";
const char* const cImgTitle = "IMG_TITLE";
const char* const cImgDescription = "IMG_DESCRIPTION";
const char* const cUserId = "USR_ID";
const char* const cUserRights = "USR_RIGHTS";
const char* const cUserLogin = "USR_LOGIN";
const char* const cUserPassword = "USR_PASSWORD";
const char* const cCatId = "CAT_ID";

//---------------------------------------------------------------------------
class TPhotoData : public TWebDataModule
{
__published:	// IDE-managed Components
  TIBDatabase *PhotoDatabase;
  TIBTransaction *MainTransaction;
  TDataSetAdapter *PicturesIterator;
  TAdapterPrevPageAction *ActionPrevPage;
  TAdapterGotoPageAction *ActionGotoPage;
  TAdapterNextPageAction *ActionNextPage;
  TAdapterAction *UpdateViewMode;
  TAdapterAction *DeletePicture;
  TDataSetAdapterField *AdaptIMG_ID;
  TDataSetAdapterField *AdaptIMG_WIDTH;
  TDataSetAdapterField *AdaptIMG_HEIGHT;
  TDataSetAdapterField *AdaptIMG_DATE;
  TDataSetAdapterMemoField *AdaptIMG_DESCRIPTION;
  TDataSetAdapterField *AdaptIMG_RATING_SCORE;
  TDataSetAdapterField *AdaptIMG_SIZE;
  TDataSetAdapterField *AdaptIMG_TITLE;
  TDataSetAdapterField *AdaptIMG_TYPE;
  TDataSetAdapterField *AdaptIMG_VOTE_COUNT;
  TDataSetAdapterField *AdaptUSR_ID;
  TDataSetAdapterField *AdaptIMG_VIEW_COUNT;
  TDataSetAdapterField *AdaptCAT_NAME;
  TAdapterImageField *Image;
  TAdapterImageField *Thumbnail;
  TAdapterField *ThumbWidth;
  TAdapterField *ThumbHeight;
  TAdapterField *MaxPicsPerRow;
  TAdapterField *ViewMode;
  TAdapterField *ActualRating;
  TAdapterField *AllPictures;
  TDataSetAdapter *Categories;
  TDataSetAdapterField *AdaptCAT_ID;
  TDataSetAdapterField *CategoriesCat_Name;
  TStringsValuesList *Resolutions;
  TAdapter *VoteAdapter;
  TAdapterAction *VoteForPicture;
  TAdapterField *NewVote;
  TIBQuery *qryAllPicturesInfo;
  TIntegerField *qryAllPicturesInfoIMG_ID;
  TIntegerField *qryAllPicturesInfoIMG_WIDTH;
  TIntegerField *qryAllPicturesInfoIMG_HEIGHT;
  TDateTimeField *qryAllPicturesInfoIMG_DATE;
  TMemoField *qryAllPicturesInfoIMG_DESCRIPTION;
  TIBStringField *qryAllPicturesInfoCAT_NAME;
  TIntegerField *qryAllPicturesInfoIMG_RATING_SCORE;
  TIntegerField *qryAllPicturesInfoIMG_SIZE;
  TIBStringField *qryAllPicturesInfoIMG_TITLE;
  TIntegerField *qryAllPicturesInfoIMG_TYPE;
  TIntegerField *qryAllPicturesInfoIMG_VOTE_COUNT;
  TIBStringField *qryAllPicturesInfoUSR_LOGIN;
  TIntegerField *qryAllPicturesInfoUSR_ID;
  TIntegerField *qryAllPicturesInfoIMG_VIEW_COUNT;
  TIBQuery *qryRecCount;
  TIBQuery *qryCategories;
  TIntegerField *qryCategoriesCAT_ID;
  TIBStringField *qryCategoriesCAT_NAME;
  TIBStoredProc *stdprcVoteForPicture;
  TIBStoredProc *stdprcAddImageView;
  TIBQuery *qryPicturesData;
  TBlobField *qryPicturesDataIMG_DATA;
  TIntegerField *qryPicturesDataIMG_HEIGHT;
  TIntegerField *qryPicturesDataIMG_WIDTH;
  TIntegerField *qryPicturesDataIMG_TYPE;
  TIBQuery *qryUsers;
  TIBUpdateSQL *updtUsers;
  TDataSetAdapter *Users;
  TIntegerField *qryUsersUSR_ID;
  TIBStringField *qryUsersUSR_LOGIN;
  TIntegerField *qryUsersUSR_RIGHTS;
  TIBStringField *qryUsersUSR_PASSWORD;
  TIBSQL *sqlDeletePicture;
  TIBQuery *qryAddImage;
  TDataSetAdapterDeleteRowAction *ActionDeleteRow;
  TDataSetAdapterNewRowAction *ActionNewRow;
  TIBUpdateSQL *updtCategories;
  TDataSetAdapterApplyRowAction *ActionApply;
  TDataSetAdapterDeleteRowAction *ActionDeleteRow2;
  TDataSetAdapterFirstRowAction *ActionFirstRow;
  TDataSetAdapterPrevRowAction *ActionPrevRow;
  TDataSetAdapterNextRowAction *ActionNextRow;
  TDataSetAdapterLastRowAction *ActionLastRow;
  TDataSetAdapterEditRowAction *ActionEditRow;
  TDataSetAdapterBrowseRowAction *ActionBrowseRow;
  TDataSetAdapterNewRowAction *ActionNewRow2;
  TDataSetAdapterCancelRowAction *ActionCancel;
  TDataSetAdapterApplyRowAction *ActionApply2;
  TDataSetAdapterRefreshRowAction *ActionRefreshRow;
  void __fastcall WebDataModuleCreate(TObject *Sender);
  void __fastcall WebDataModuleActivate(TObject *Sender);
  void __fastcall PicturesIteratorGetRecordCount(TObject *Sender,
          int &Count);
  void __fastcall VoteForPictureExecute(TObject *Sender, TStrings *Params);
  void __fastcall VoteForPictureGetParams(TObject *Sender,
          TStrings *Params);
  void __fastcall VoteForPictureGetEnabled(TObject *Sender, bool &Enabled);
  void __fastcall ThumbWidthGetValue(TObject *Sender, Variant &Value);
  void __fastcall MaxPicsPerRowGetValue(TObject *Sender, Variant &Value);
  void __fastcall ViewModeGetValue(TObject *Sender, Variant &Value);
  void __fastcall ImageGetParams(TObject *Sender, TStrings *Params);
  void __fastcall ImageGetImage(TObject *Sender, TStrings *Params,
          AnsiString &MimeType, TStream *&Image, bool &Owned);
  void __fastcall ThumbnailGetImage(TObject *Sender, TStrings *Params,
          AnsiString &MimeType, TStream *&Image, bool &Owned);
  void __fastcall ThumbHeightGetValue(TObject *Sender, Variant &Value);
  void __fastcall ActualRatingGetValue(TObject *Sender, Variant &Value);
  void __fastcall WebDataModuleDestroy(TObject *Sender);
  void __fastcall AllPicturesGetValue(TObject *Sender, Variant &Value);
  void __fastcall WebDataModuleDeactivate(TObject *Sender);
  void __fastcall UpdateViewModeExecute(TObject *Sender, TStrings *Params);
  void __fastcall DeletePictureGetEnabled(TObject *Sender, bool &Enabled);
  void __fastcall DeletePictureExecute(TObject *Sender, TStrings *Params);
  void __fastcall ActionApply2AfterExecute(TObject *Sender,
          TStrings *Params);
  void __fastcall ActionApplyAfterExecute(TObject *Sender,
          TStrings *Params);
private:	// User declarations
  int m_nThumbWidth;
  int m_nPicturesPerRow;
  int m_nPicturesPerPage;
  int m_nCurrentViewMode;

  int __fastcall GetImageThumbWidth(TDataSet *DataSet);
  int __fastcall GetImageThumbHeight(TDataSet *DataSet);
public:		// User declarations

  int GetThumbWidth() { return m_nThumbWidth; }
  void SetThumbWidth(const int n) { m_nThumbWidth = n; }

  int GetPicturesPerRow() { return m_nPicturesPerRow; }
  void SetPicturesPerRow(const int n) { m_nPicturesPerRow = n; }

  int GetPicturesPerPage() { return m_nPicturesPerPage; }
  void SetPicturesPerPage(const int n) { m_nPicturesPerPage = n; }
  void SetupQueries();

  TUserRights GetUserRights();
};

TPhotoData *PhotoData();

//---------------------------------------------------------------------------
extern PACKAGE TPhotoData *PhotoData();
//---------------------------------------------------------------------------
#endif

