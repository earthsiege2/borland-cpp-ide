object MainPage: TMainPage
  OldCreateOrder = False
  OnCreate = WebAppPageModuleCreate
  OnDestroy = WebAppPageModuleDestroy
  PageProducer = PageProducer
  AppServices = WebAppComponents
  Left = 254
  Top = 107
  Height = 311
  Width = 193
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object WebAppComponents: TWebAppComponents
    PageDispatcher = PageDispatcher
    AdapterDispatcher = AdapterDispatcher
    ApplicationAdapter = ApplicationAdapter
    Left = 48
    Top = 56
  end
  object ApplicationAdapter: TApplicationAdapter
    Left = 48
    Top = 104
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object PageDispatcher: TPageDispatcher
    Left = 48
    Top = 152
  end
  object AdapterDispatcher: TAdapterDispatcher
    Left = 48
    Top = 200
  end
  object Adapter1: TAdapter
    Left = 128
    Top = 72
    object TAdapterActions
    end
    object TAdapterFields
      object ImageData: TAdapterImageField
        OnGetImage = ImageDataGetImage
      end
      object ImageWidth: TAdapterField
        OnGetValue = ImageWidthGetValue
      end
      object ImageHeight: TAdapterField
        OnGetValue = ImageHeightGetValue
      end
    end
  end
end
