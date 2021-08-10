object DisplayOptionsPage: TDisplayOptionsPage
  OldCreateOrder = False
  PageProducer = PageProducer
  Left = 254
  Top = 107
  Height = 264
  Width = 327
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object DisplayOptions: TAdapter
    Left = 64
    Top = 56
    object TAdapterActions
      object SubmitOptions: TAdapterAction
        OnExecute = SubmitOptionsExecute
        RedirectOptions = [roRedirectHTTPPost, roRedirectHTTPGet]
      end
    end
    object TAdapterFields
      object PreferredThumbWidth: TAdapterField
        OnGetValue = PreferredThumbWidthGetValue
        OnValidateValue = PreferredThumbWidthValidateValue
      end
      object MaxPicsPerPage: TAdapterField
        OnGetValue = MaxPicsPerPageGetValue
        OnValidateValue = MaxPicsPerPageValidateValue
      end
      object MaxPicsPerRow: TAdapterField
        OnGetValue = MaxPicsPerRowGetValue
      end
    end
  end
end
