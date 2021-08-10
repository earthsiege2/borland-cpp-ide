object CountryForm: TCountryForm
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 254
  Top = 107
  Height = 150
  Width = 215
  object AdapterPageProducer: TAdapterPageProducer
    HTMLDoc.Strings = (
      '<html>'
      '<head>'
      '</head>'
      '<body>'
      '<#STYLES><#WARNINGS><#SERVERSCRIPT>'
      '</body>'
      '</html>')
    Left = 48
    Top = 8
    object AdapterForm1: TAdapterForm
      object AdapterErrorList1: TAdapterErrorList
      end
      object AdapterFieldGroup1: TAdapterFieldGroup
        Adapter = CountryTable.Adapter
      end
      object AdapterButtonGroup1: TAdapterCommandGroup
        DisplayComponent = AdapterFieldGroup1
        object BtnApply: TAdapterActionButton
          ActionName = 'Apply'
          PageName = 'CountryTable'
        end
        object BtnRefreshRow: TAdapterActionButton
          ActionName = 'RefreshRow'
          Caption = 'Refresh'
          HideOptions = [bhoHideOnActionNotVisible, bhoHideOnDisabledAction]
        end
        object BtnCancel: TAdapterActionButton
          ActionName = 'Cancel'
          PageName = 'CountryTable'
        end
      end
    end
  end
end
