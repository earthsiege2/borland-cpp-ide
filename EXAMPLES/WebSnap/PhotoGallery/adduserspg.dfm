object AddUsersPage: TAddUsersPage
  OldCreateOrder = False
  OnCreate = WebPageModuleCreate
  PageProducer = AdapterPageProducer1
  Left = 505
  Top = 226
  Height = 288
  Width = 279
  object AccessRightsList: TStringsValuesList
    Left = 40
    Top = 80
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
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
    Left = 184
    Top = 80
  end
end
