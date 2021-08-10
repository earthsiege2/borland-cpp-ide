object BioDataModule: TBioDataModule
  OldCreateOrder = False
  Left = 192
  Top = 107
  Height = 197
  Width = 212
  object Table1: TTable
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_3'
    TableName = 'biolife.db'
    Left = 16
    Top = 8
    object Table1SpeciesNo: TFloatField
      FieldName = 'Species No'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object Table1Category: TStringField
      FieldName = 'Category'
      Size = 15
    end
    object Table1Common_Name: TStringField
      FieldName = 'Common_Name'
      Size = 30
    end
    object Table1SpeciesName: TStringField
      FieldName = 'Species Name'
      Size = 40
    end
    object Table1Lengthcm: TFloatField
      FieldName = 'Length (cm)'
    end
    object Table1Length_In: TFloatField
      FieldName = 'Length_In'
    end
    object Table1Notes: TMemoField
      FieldName = 'Notes'
      BlobType = ftMemo
      Size = 50
    end
    object Table1Graphic: TGraphicField
      FieldName = 'Graphic'
      BlobType = ftGraphic
    end
  end
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 88
    Top = 16
  end
  object DataSetAdapter1: TDataSetAdapter
    DataSet = Table1
    Left = 40
    Top = 64
    object TAdapterDefaultActions
      object ActionDeleteRow: TDataSetAdapterDeleteRowAction
        ExecuteAccess = 'Modify'
      end
      object ActionFirstRow: TDataSetAdapterFirstRowAction
      end
      object ActionPrevRow: TDataSetAdapterPrevRowAction
      end
      object ActionNextRow: TDataSetAdapterNextRowAction
      end
      object ActionLastRow: TDataSetAdapterLastRowAction
      end
      object ActionNewRow: TDataSetAdapterNewRowAction
      end
      object ActionEditRow: TDataSetAdapterEditRowAction
      end
      object ActionCancel: TDataSetAdapterCancelRowAction
      end
      object ActionApply: TDataSetAdapterApplyRowAction
        ExecuteAccess = 'Modify'
      end
      object ActionRefreshRow: TDataSetAdapterRefreshRowAction
      end
    end
    object TAdapterDefaultFields
      object AdaptSpeciesNo: TDataSetAdapterField
        DataSetField = 'Species No'
        ModifyAccess = 'Modify'
      end
      object AdaptCategory: TDataSetAdapterField
        DataSetField = 'Category'
        ModifyAccess = 'Modify'
      end
      object AdaptCommon_Name: TDataSetAdapterField
        DataSetField = 'Common_Name'
        ModifyAccess = 'Modify'
      end
      object AdaptSpeciesName: TDataSetAdapterField
        DataSetField = 'Species Name'
        ModifyAccess = 'Modify'
      end
      object AdaptLengthcm: TDataSetAdapterField
        DataSetField = 'Length (cm)'
        ModifyAccess = 'Modify'
      end
      object AdaptLength_In: TDataSetAdapterField
        DataSetField = 'Length_In'
        ModifyAccess = 'Modify'
      end
      object AdaptNotes: TDataSetAdapterMemoField
        DataSetField = 'Notes'
        ModifyAccess = 'Modify'
      end
      object AdaptGraphic: TDataSetAdapterImageField
        DataSetField = 'Graphic'
        ModifyAccess = 'Modify'
        FieldModes = [amInsert, amEdit, amBrowse]
      end
    end
  end
end
