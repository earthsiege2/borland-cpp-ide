object DetailsPage: TDetailsPage
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 254
  Top = 107
  Height = 264
  Width = 314
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
        Adapter = BioDataModule.DataSetAdapter1
      end
      object AdapterButtonGroup1: TAdapterCommandGroup
        DisplayComponent = AdapterFieldGroup1
        object BtnFirstRow: TAdapterActionButton
          ActionName = 'FirstRow'
        end
        object BtnPrevRow: TAdapterActionButton
          ActionName = 'PrevRow'
        end
        object BtnNextRow: TAdapterActionButton
          ActionName = 'NextRow'
        end
        object BtnLastRow: TAdapterActionButton
          ActionName = 'LastRow'
        end
        object BtnApply: TAdapterActionButton
          ActionName = 'Apply'
          HideOptions = [bhoHideOnNoExecuteAccess, bhoHideOnActionNotVisible]
        end
        object BtnRefreshRow: TAdapterActionButton
          ActionName = 'RefreshRow'
        end
      end
      object AdapterFieldGroup1: TAdapterFieldGroup
        Adapter = BioDataModule.DataSetAdapter1
        AdapterMode = 'Edit'
        object FldSpeciesNo: TAdapterDisplayField
          Caption = 'Species No'
          DisplayWidth = 10
          FieldName = 'SpeciesNo'
          ViewMode = vmToggleOnAccess
        end
        object FldCategory: TAdapterDisplayField
          DisplayWidth = 15
          FieldName = 'Category'
          ViewMode = vmToggleOnAccess
        end
        object FldCommon_Name: TAdapterDisplayField
          DisplayWidth = 30
          FieldName = 'Common_Name'
          ViewMode = vmToggleOnAccess
        end
        object FldSpeciesName: TAdapterDisplayField
          Caption = 'Species Name'
          DisplayWidth = 40
          FieldName = 'SpeciesName'
          ViewMode = vmToggleOnAccess
        end
        object FldLengthcm: TAdapterDisplayField
          Caption = 'Length (cm)'
          DisplayWidth = 10
          FieldName = 'Lengthcm'
          ViewMode = vmToggleOnAccess
        end
        object FldLength_In: TAdapterDisplayField
          DisplayWidth = 10
          FieldName = 'Length_In'
          ImageHeight = 0
          ViewMode = vmToggleOnAccess
        end
        object FldNotes: TAdapterDisplayField
          DisplayWidth = 40
          FieldName = 'Notes'
          ImageHeight = 0
          TextAreaWrap = wrVirtual
          DisplayRows = 5
          ViewMode = vmToggleOnAccess
        end
        object FldGraphic: TAdapterDisplayField
          DisplayWidth = 10
          FieldName = 'Graphic'
          HideOptions = [hoHideOnNoInputAccess, hoHideOnFieldNotVisible]
        end
        object AdapterDisplayField: TAdapterDisplayField
          DisplayWidth = 10
          FieldName = 'Graphic'
          ViewMode = vmDisplay
        end
      end
    end
  end
end
