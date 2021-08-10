object UploadPicturesPage: TUploadPicturesPage
  OldCreateOrder = False
  OnActivate = WebPageModuleActivate
  PageProducer = PageProducer
  Left = 254
  Top = 107
  Height = 208
  Width = 246
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object UploadAdapter: TAdapter
    OnBeforeExecuteAction = UploadAdapterBeforeExecuteAction
    Left = 48
    Top = 64
    object TAdapterActions
      object Upload: TAdapterAction
        OnExecute = UploadExecute
      end
    end
    object TAdapterFields
      object UploadFile: TAdapterFileField
        OnUploadFiles = UploadFileUploadFiles
        Required = True
      end
      object Title: TAdapterField
        Required = True
      end
      object Description: TAdapterMemoField
      end
      object Category: TAdapterField
      end
    end
  end
  object UploadedFiles: TStringsValuesList
    Left = 104
    Top = 32
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
end
