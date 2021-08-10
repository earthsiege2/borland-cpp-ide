object MainPage: TMainPage
  OldCreateOrder = False
  PageProducer = PageProducer
  AppServices = WebAppComponents
  Left = 254
  Top = 107
  Height = 346
  Width = 358
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object WebAppComponents: TWebAppComponents
    Sessions = SessionsService1
    LocateFileService = LocateFileService1
    PageDispatcher = PageDispatcher
    AdapterDispatcher = AdapterDispatcher
    ApplicationAdapter = ApplicationAdapter
    EndUserAdapter = EndUserSessionAdapter1
    UserListService = WebUserList1
    Left = 48
    Top = 56
  end
  object ApplicationAdapter: TApplicationAdapter
    ApplicationTitle = 'WebSnap Biolife Demo'
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
  object WebUserList1: TWebUserList
    UserItems = <
      item
        UserName = 'Ellen'
        AccessRights = 'Modify'
      end
      item
        UserName = 'Will'
      end>
    Left = 144
    Top = 24
  end
  object EndUserSessionAdapter1: TEndUserSessionAdapter
    LoginPage = 'LoginPage'
    Left = 136
    Top = 80
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object SessionsService1: TSessionsService
    Left = 144
    Top = 144
  end
  object LocateFileService1: TLocateFileService
    OnFindStream = LocateFileService1FindStream
    Left = 200
    Top = 112
  end
end
