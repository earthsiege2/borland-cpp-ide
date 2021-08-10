object GridPage: TGridPage
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 254
  Top = 107
  Height = 177
  Width = 224
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
      object AdapterGrid1: TAdapterGrid
        RowAttributes.VAlign = haTop
        Adapter = BioDataModule.DataSetAdapter1
        object ColSpeciesNo: TAdapterDisplayColumn
          Caption = 'Species No'
          FieldName = 'SpeciesNo'
        end
        object ColCategory: TAdapterDisplayColumn
          FieldName = 'Category'
        end
        object ColCommon_Name: TAdapterDisplayColumn
          FieldName = 'Common_Name'
        end
        object ColSpeciesName: TAdapterDisplayColumn
          Caption = 'Species Name'
          FieldName = 'SpeciesName'
        end
        object ColGraphic: TAdapterDisplayColumn
          FieldName = 'Graphic'
        end
        object AdapterCommandColumn1: TAdapterCommandColumn
          Caption = ' '
          object CmdEditRow: TAdapterActionButton
            ActionName = 'EditRow'
            Caption = 'Details...'
            PageName = 'DetailsPage'
          end
        end
      end
    end
  end
end
