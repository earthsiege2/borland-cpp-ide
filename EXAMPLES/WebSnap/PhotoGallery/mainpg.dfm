object MainPage: TMainPage
  OldCreateOrder = False
  OnAfterDispatchPage = WebAppPageModuleAfterDispatchPage
  PageProducer = PageProducer
  AppServices = WebAppComponents
  Left = 282
  Top = 104
  Height = 431
  Width = 226
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object WebAppComponents: TWebAppComponents
    Sessions = SessionsService1
    PageDispatcher = PageDispatcher
    AdapterDispatcher = AdapterDispatcher
    ApplicationAdapter = ApplicationAdapter
    EndUserAdapter = EndUserSessionAdapter1
    OnException = WebAppComponentsException
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
  object EndUserSessionAdapter1: TEndUserSessionAdapter
    LoginPage = 'LoginPage'
    OnHasRights = EndUserSessionAdapter1HasRights
    Left = 48
    Top = 264
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object SessionsService1: TSessionsService
    Left = 48
    Top = 312
  end
end
