object LoginPage: TLoginPage
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 254
  Top = 107
  Height = 290
  Width = 282
  object AdapterPageProducer: TAdapterPageProducer
    HTMLDoc.Strings = (
      '<html>'
      '<head>'
      '</head>'
      '<body>'
      '<#STYLES><#WARNINGS><#SERVERSCRIPT>'
      '</body>'
      '</html>')
    Left = 80
    Top = 32
    object AdapterForm1: TAdapterForm
      object AdapterErrorList1: TAdapterErrorList
        Adapter = LoginFormAdapter1
      end
      object AdapterFieldGroup1: TAdapterFieldGroup
        Adapter = LoginFormAdapter1
      end
      object AdapterButtonGroup1: TAdapterCommandGroup
        DisplayComponent = AdapterFieldGroup1
        object BtnLogin: TAdapterActionButton
          ActionName = 'Login'
        end
      end
    end
  end
  object LoginFormAdapter1: TLoginFormAdapter
    Left = 176
    Top = 48
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
end
