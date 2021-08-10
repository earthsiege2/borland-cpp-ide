object LoginPage: TLoginPage
  OldCreateOrder = False
  PageProducer = AdapterPageProducer1
  Left = 254
  Top = 107
  Height = 150
  Width = 216
  object LoginFormAdapter1: TLoginFormAdapter
    OnLogin = LoginFormAdapter1Login
    Left = 112
    Top = 40
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
      object AdaptUserName: TAdapterUserNameField
        FieldName = 'UserName'
      end
      object AdaptPassword: TAdapterPasswordField
        FieldName = 'Password'
      end
      object AdaptNextPage: TAdapterNextPageField
        FieldName = 'NextPage'
      end
    end
  end
  object AdapterPageProducer1: TAdapterPageProducer
    HTMLDoc.Strings = (
      '<html>'
      '<head>'
      '</head>'
      '<body>'
      '<#STYLES><#WARNINGS><#SERVERSCRIPT>'
      '</body>'
      '</html>')
    Left = 40
    Top = 24
    object AdapterForm1: TAdapterForm
      object AdapterErrorList1: TAdapterErrorList
        Adapter = LoginFormAdapter1
      end
      object AdapterFieldGroup1: TAdapterFieldGroup
        Adapter = LoginFormAdapter1
        object FldUserName: TAdapterDisplayField
          Caption = 'User Name'
          FieldName = 'UserName'
        end
        object FldPassword: TAdapterDisplayField
          FieldName = 'Password'
        end
      end
      object AdapterCommandGroup1: TAdapterCommandGroup
        DisplayComponent = AdapterFieldGroup1
        object CmdLogin: TAdapterActionButton
          ActionName = 'Login'
          StyleRule = 'submitButton'
        end
      end
    end
  end
end
