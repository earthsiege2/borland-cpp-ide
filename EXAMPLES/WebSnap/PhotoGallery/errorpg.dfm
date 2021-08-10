object ErrorPage: TErrorPage
  OldCreateOrder = False
  PageProducer = PageProducer
  Left = 254
  Top = 107
  Height = 150
  Width = 215
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object ErrorAdapter: TAdapter
    Left = 128
    Top = 40
    object TAdapterActions
    end
    object TAdapterFields
      object ErrorMessageField: TAdapterField
        FieldName = 'ErrorMessage'
        OnGetValue = ErrorMessageFieldGetValue
        DisplayLabel = 'ErrorMessage'
      end
    end
  end
end
