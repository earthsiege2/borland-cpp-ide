object PhotoData: TPhotoData
  OldCreateOrder = False
  OnCreate = WebDataModuleCreate
  OnDestroy = WebDataModuleDestroy
  OnActivate = WebDataModuleActivate
  OnDeactivate = WebDataModuleDeactivate
  Left = 346
  Top = 169
  Height = 362
  Width = 478
  object PhotoDatabase: TIBDatabase
    Params.Strings = (
      'user_name=sysdba'
      'password=masterke')
    LoginPrompt = False
    DefaultTransaction = MainTransaction
    IdleTimer = 0
    SQLDialect = 1
    TraceFlags = []
    AllowStreamedConnected = False
    Left = 40
    Top = 16
  end
  object MainTransaction: TIBTransaction
    Active = False
    DefaultDatabase = PhotoDatabase
    Params.Strings = (
      'concurrency'
      'nowait')
    AutoStopAction = saCommit
    Left = 144
    Top = 16
  end
  object PicturesIterator: TDataSetAdapter
    DataSet = qryAllPicturesInfo
    OnGetRecordCount = PicturesIteratorGetRecordCount
    PageSize = 1
    Left = 40
    Top = 144
    object TAdapterDefaultActions
      object ActionPrevPage: TAdapterPrevPageAction
      end
      object ActionGotoPage: TAdapterGotoPageAction
      end
      object ActionNextPage: TAdapterNextPageAction
      end
      object UpdateViewMode: TAdapterAction
        OnExecute = UpdateViewModeExecute
      end
      object DeletePicture: TAdapterAction
        OnExecute = DeletePictureExecute
        OnGetParams = VoteForPictureGetParams
        OnGetEnabled = DeletePictureGetEnabled
      end
    end
    object TAdapterDefaultFields
      object AdaptIMG_ID: TDataSetAdapterField
        DataSetField = 'IMG_ID'
        FieldFlags = []
      end
      object AdaptIMG_WIDTH: TDataSetAdapterField
        DataSetField = 'IMG_WIDTH'
        FieldFlags = []
      end
      object AdaptIMG_HEIGHT: TDataSetAdapterField
        DataSetField = 'IMG_HEIGHT'
        FieldFlags = []
      end
      object AdaptIMG_DATE: TDataSetAdapterField
        DataSetField = 'IMG_DATE'
        FieldFlags = []
      end
      object AdaptIMG_DESCRIPTION: TDataSetAdapterMemoField
        DataSetField = 'IMG_DESCRIPTION'
      end
      object AdaptIMG_RATING_SCORE: TDataSetAdapterField
        DataSetField = 'IMG_RATING_SCORE'
        FieldFlags = []
      end
      object AdaptIMG_SIZE: TDataSetAdapterField
        DataSetField = 'IMG_SIZE'
        FieldFlags = []
      end
      object AdaptIMG_TITLE: TDataSetAdapterField
        DataSetField = 'IMG_TITLE'
        FieldFlags = []
      end
      object AdaptIMG_TYPE: TDataSetAdapterField
        DataSetField = 'IMG_TYPE'
        FieldFlags = []
      end
      object AdaptIMG_VOTE_COUNT: TDataSetAdapterField
        DataSetField = 'IMG_VOTE_COUNT'
        FieldFlags = []
      end
      object AdaptUSR_ID: TDataSetAdapterField
        DataSetField = 'USR_ID'
        FieldFlags = []
      end
      object AdaptIMG_VIEW_COUNT: TDataSetAdapterField
        DataSetField = 'IMG_VIEW_COUNT'
        FieldFlags = []
      end
      object AdaptCAT_NAME: TDataSetAdapterField
        DataSetField = 'CAT_NAME'
        FieldFlags = []
      end
      object Image: TAdapterImageField
        OnGetParams = ImageGetParams
        OnGetImage = ImageGetImage
      end
      object Thumbnail: TAdapterImageField
        OnGetParams = ImageGetParams
        OnGetImage = ThumbnailGetImage
      end
      object ThumbWidth: TAdapterField
        OnGetValue = ThumbWidthGetValue
      end
      object ThumbHeight: TAdapterField
        OnGetValue = ThumbHeightGetValue
      end
      object MaxPicsPerRow: TAdapterField
        OnGetValue = MaxPicsPerRowGetValue
      end
      object ViewMode: TAdapterField
        OnGetValue = ViewModeGetValue
      end
      object ActualRating: TAdapterField
        OnGetValue = ActualRatingGetValue
      end
      object AllPictures: TAdapterField
        OnGetValue = AllPicturesGetValue
      end
    end
  end
  object Categories: TDataSetAdapter
    DataSet = qryCategories
    Left = 144
    Top = 136
    object TAdapterDefaultActions
      object ActionDeleteRow: TDataSetAdapterDeleteRowAction
      end
      object ActionNewRow: TDataSetAdapterNewRowAction
      end
      object ActionApply: TDataSetAdapterApplyRowAction
        OnAfterExecute = ActionApplyAfterExecute
      end
    end
    object TAdapterDefaultFields
      object AdaptCAT_ID: TDataSetAdapterField
        DataSetField = 'CAT_ID'
        FieldFlags = []
      end
      object CategoriesCat_Name: TDataSetAdapterField
        DataSetField = 'CAT_NAME'
        FieldFlags = []
      end
    end
  end
  object Resolutions: TStringsValuesList
    Strings.Strings = (
      '50'
      '100'
      '150'
      '200'
      '250')
    Left = 232
    Top = 16
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object VoteAdapter: TAdapter
    Left = 232
    Top = 128
    object TAdapterActions
      object VoteForPicture: TAdapterAction
        OnExecute = VoteForPictureExecute
        OnGetParams = VoteForPictureGetParams
        OnGetEnabled = VoteForPictureGetEnabled
        RedirectOptions = [roRedirectHTTPPost, roRedirectHTTPGet]
      end
    end
    object TAdapterFields
      object NewVote: TAdapterField
      end
    end
  end
  object qryAllPicturesInfo: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select '
      
        'IMG_ID, IMG_WIDTH, IMG_HEIGHT, IMG_DATE, IMG_DESCRIPTION, CAT_NA' +
        'ME, IMG_RATING_SCORE, IMG_SIZE, IMG_TITLE, IMG_TYPE, IMG_VOTE_CO' +
        'UNT, USERS.USR_LOGIN, IMAGES.USR_ID, IMAGES.IMG_VIEW_COUNT'
      'from IMAGES, CATEGORIES, USERS '
      'where '
      '  IMAGES.CAT_ID = CATEGORIES.CAT_ID AND '
      '  IMAGES.USR_ID = USERS.USR_ID'
      '  AND IMAGES.IMG_PRIVATE = 0')
    Left = 40
    Top = 80
    object qryAllPicturesInfoIMG_ID: TIntegerField
      FieldName = 'IMG_ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object qryAllPicturesInfoIMG_WIDTH: TIntegerField
      FieldName = 'IMG_WIDTH'
      Required = True
    end
    object qryAllPicturesInfoIMG_HEIGHT: TIntegerField
      FieldName = 'IMG_HEIGHT'
      Required = True
    end
    object qryAllPicturesInfoIMG_DATE: TDateTimeField
      FieldName = 'IMG_DATE'
      Required = True
    end
    object qryAllPicturesInfoIMG_DESCRIPTION: TMemoField
      FieldName = 'IMG_DESCRIPTION'
      BlobType = ftMemo
      Size = 8
    end
    object qryAllPicturesInfoCAT_NAME: TIBStringField
      FieldName = 'CAT_NAME'
      Required = True
      Size = 255
    end
    object qryAllPicturesInfoIMG_RATING_SCORE: TIntegerField
      FieldName = 'IMG_RATING_SCORE'
      Required = True
    end
    object qryAllPicturesInfoIMG_SIZE: TIntegerField
      FieldName = 'IMG_SIZE'
      Required = True
    end
    object qryAllPicturesInfoIMG_TITLE: TIBStringField
      FieldName = 'IMG_TITLE'
      Required = True
      Size = 255
    end
    object qryAllPicturesInfoIMG_TYPE: TIntegerField
      FieldName = 'IMG_TYPE'
      Required = True
    end
    object qryAllPicturesInfoIMG_VOTE_COUNT: TIntegerField
      FieldName = 'IMG_VOTE_COUNT'
      Required = True
    end
    object qryAllPicturesInfoUSR_LOGIN: TIBStringField
      FieldName = 'USR_LOGIN'
      Required = True
      Size = 255
    end
    object qryAllPicturesInfoUSR_ID: TIntegerField
      FieldName = 'USR_ID'
      Required = True
    end
    object qryAllPicturesInfoIMG_VIEW_COUNT: TIntegerField
      FieldName = 'IMG_VIEW_COUNT'
    end
  end
  object qryRecCount: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    Left = 32
    Top = 208
  end
  object qryCategories: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from categories'
      'order by CAT_ID')
    UpdateObject = updtCategories
    GeneratorField.Field = 'CAT_ID'
    GeneratorField.Generator = 'CAT_GENERATOR'
    Left = 144
    Top = 72
    object qryCategoriesCAT_ID: TIntegerField
      FieldName = 'CAT_ID'
      ProviderFlags = [pfInKey]
    end
    object qryCategoriesCAT_NAME: TIBStringField
      FieldName = 'CAT_NAME'
      Required = True
      Size = 255
    end
  end
  object stdprcVoteForPicture: TIBStoredProc
    Database = PhotoDatabase
    Transaction = MainTransaction
    StoredProcName = 'VOTE_FOR_PICTURE'
    Left = 232
    Top = 72
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IMG_ID'
        ParamType = ptInput
      end
      item
        DataType = ftInteger
        Name = 'IMG_VOTE'
        ParamType = ptInput
      end>
  end
  object stdprcAddImageView: TIBStoredProc
    Database = PhotoDatabase
    Transaction = MainTransaction
    StoredProcName = 'ADD_IMAGE_VIEW'
    Left = 320
    Top = 16
  end
  object qryPicturesData: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select '
      '  IMG_DATA, IMG_HEIGHT, IMG_WIDTH, IMG_TYPE'
      'from '
      '  IMAGES '
      'where IMG_ID = :IMG_ID')
    Left = 328
    Top = 72
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IMG_ID'
        ParamType = ptUnknown
      end>
    object qryPicturesDataIMG_DATA: TBlobField
      FieldName = 'IMG_DATA'
      Size = 8
    end
    object qryPicturesDataIMG_HEIGHT: TIntegerField
      FieldName = 'IMG_HEIGHT'
      Required = True
    end
    object qryPicturesDataIMG_WIDTH: TIntegerField
      FieldName = 'IMG_WIDTH'
      Required = True
    end
    object qryPicturesDataIMG_TYPE: TIntegerField
      FieldName = 'IMG_TYPE'
      Required = True
    end
  end
  object qryUsers: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from USERS')
    UpdateObject = updtUsers
    GeneratorField.Field = 'USR_ID'
    GeneratorField.Generator = 'USR_GENERATOR'
    Left = 144
    Top = 200
    object qryUsersUSR_ID: TIntegerField
      FieldName = 'USR_ID'
      Origin = 'USERS.USR_ID'
      ProviderFlags = [pfInKey]
    end
    object qryUsersUSR_LOGIN: TIBStringField
      FieldName = 'USR_LOGIN'
      Origin = 'USERS.USR_LOGIN'
      ProviderFlags = [pfInUpdate]
      Required = True
      Size = 255
    end
    object qryUsersUSR_RIGHTS: TIntegerField
      FieldName = 'USR_RIGHTS'
      Origin = 'USERS.USR_RIGHTS'
      ProviderFlags = [pfInUpdate]
      Required = True
    end
    object qryUsersUSR_PASSWORD: TIBStringField
      FieldName = 'USR_PASSWORD'
      Origin = 'USERS.USR_PASSWORD'
      ProviderFlags = [pfInUpdate]
      Required = True
      Size = 255
    end
  end
  object updtUsers: TIBUpdateSQL
    RefreshSQL.Strings = (
      'Select '
      '  USR_ID,'
      '  USR_LOGIN,'
      '  USR_RIGHTS,'
      '  USR_PASSWORD'
      'from USERS '
      'where'
      '  USR_ID = :USR_ID')
    ModifySQL.Strings = (
      'update USERS'
      'set'
      '  USR_ID = :USR_ID,'
      '  USR_LOGIN = :USR_LOGIN,'
      '  USR_RIGHTS = :USR_RIGHTS,'
      '  USR_PASSWORD = :USR_PASSWORD'
      'where'
      '  USR_ID = :OLD_USR_ID')
    InsertSQL.Strings = (
      'insert into USERS'
      '  (USR_ID, USR_LOGIN, USR_RIGHTS, USR_PASSWORD)'
      'values'
      '  (:USR_ID, :USR_LOGIN, :USR_RIGHTS, :USR_PASSWORD)')
    DeleteSQL.Strings = (
      'delete from USERS'
      'where'
      '  USR_ID = :OLD_USR_ID')
    Left = 200
    Top = 200
  end
  object Users: TDataSetAdapter
    DataSet = qryUsers
    Left = 144
    Top = 256
    object TAdapterDefaultActions
      object ActionDeleteRow2: TDataSetAdapterDeleteRowAction
      end
      object ActionFirstRow: TDataSetAdapterFirstRowAction
      end
      object ActionPrevRow: TDataSetAdapterPrevRowAction
      end
      object ActionNextRow: TDataSetAdapterNextRowAction
      end
      object ActionLastRow: TDataSetAdapterLastRowAction
      end
      object ActionEditRow: TDataSetAdapterEditRowAction
      end
      object ActionBrowseRow: TDataSetAdapterBrowseRowAction
      end
      object ActionNewRow2: TDataSetAdapterNewRowAction
      end
      object ActionCancel: TDataSetAdapterCancelRowAction
      end
      object ActionApply2: TDataSetAdapterApplyRowAction
        OnAfterExecute = ActionApply2AfterExecute
      end
      object ActionRefreshRow: TDataSetAdapterRefreshRowAction
      end
    end
    object TAdapterDefaultFields
    end
  end
  object sqlDeletePicture: TIBSQL
    Database = PhotoDatabase
    ParamCheck = True
    SQL.Strings = (
      'delete from IMAGES '
      'where'
      '  IMG_ID = :IMG_ID')
    Transaction = MainTransaction
    Left = 312
    Top = 128
  end
  object qryAddImage: TIBQuery
    Database = PhotoDatabase
    Transaction = MainTransaction
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'execute procedure add_image'
      ' (:IMG_TYPE,'
      '  :IMG_WIDTH,'
      '  :IMG_HEIGHT,'
      '  :IMG_DATA,'
      '  :IMG_TITLE,'
      '  :IMG_SIZE,'
      '  :IMG_DESCRIPTION,'
      '  :CAT_ID, '
      '  :USR_ID)')
    Left = 280
    Top = 200
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IMG_TYPE'
        ParamType = ptInput
      end
      item
        DataType = ftUnknown
        Name = 'IMG_WIDTH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IMG_HEIGHT'
        ParamType = ptUnknown
      end
      item
        DataType = ftBlob
        Name = 'IMG_DATA'
        ParamType = ptInput
      end
      item
        DataType = ftString
        Name = 'IMG_TITLE'
        ParamType = ptInput
      end
      item
        DataType = ftInteger
        Name = 'IMG_SIZE'
        ParamType = ptInput
      end
      item
        DataType = ftBlob
        Name = 'IMG_DESCRIPTION'
        ParamType = ptInput
      end
      item
        DataType = ftInteger
        Name = 'CAT_ID'
        ParamType = ptInput
      end
      item
        DataType = ftInteger
        Name = 'USR_ID'
        ParamType = ptInput
      end>
  end
  object updtCategories: TIBUpdateSQL
    RefreshSQL.Strings = (
      'Select '
      '  CAT_ID,'
      '  CAT_NAME'
      'from categories '
      'where'
      '  CAT_ID = :CAT_ID')
    ModifySQL.Strings = (
      'update categories'
      'set'
      '  CAT_ID = :CAT_ID,'
      '  CAT_NAME = :CAT_NAME'
      'where'
      '  CAT_ID = :OLD_CAT_ID')
    InsertSQL.Strings = (
      'insert into categories'
      '  (CAT_ID, CAT_NAME)'
      'values'
      '  (:CAT_ID, :CAT_NAME)')
    DeleteSQL.Strings = (
      'delete from categories'
      'where'
      '  CAT_ID = :OLD_CAT_ID')
    Left = 256
    Top = 264
  end
end
