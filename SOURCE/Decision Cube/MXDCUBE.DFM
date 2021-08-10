object DSSCubeEditor: TDSSCubeEditor
  Left = 281
  Top = 101
  HelpContext = 30170
  BorderStyle = bsToolWindow
  Caption = 'Decision Cube Editor'
  ClientHeight = 340
  ClientWidth = 491
  Color = clBtnFace
  ParentFont = True
  KeyPreview = True
  OldCreateOrder = True
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Pager: TPageControl
    Left = 6
    Top = 5
    Width = 480
    Height = 293
    ActivePage = DimensionInfo
    TabIndex = 0
    TabOrder = 0
    OnChange = PagerChange
    object DimensionInfo: TTabSheet
      HelpContext = 30171
      Caption = 'Dimension Settings'
      object CaptionLabel: TLabel
        Left = 216
        Top = 53
        Width = 70
        Height = 17
        AutoSize = False
        Caption = 'Display &Name'
        FocusControl = CaptionEdit
      end
      object ActiveLabel: TLabel
        Left = 216
        Top = 113
        Width = 70
        Height = 17
        AutoSize = False
        Caption = '&Active Type'
        FocusControl = ActiveEdit
      end
      object BinLabel: TLabel
        Left = 216
        Top = 174
        Width = 70
        Height = 17
        AutoSize = False
        Caption = '&Grouping'
        FocusControl = BinEdit
      end
      object StartLabel: TLabel
        Left = 216
        Top = 204
        Width = 70
        Height = 17
        AutoSize = False
        Caption = '&Initial Value'
        FocusControl = StartEdit
      end
      object TypeLabel: TLabel
        Left = 216
        Top = 83
        Width = 70
        Height = 17
        AutoSize = False
        Caption = '&Type'
        FocusControl = TypeEdit
      end
      object Label1: TLabel
        Left = 10
        Top = 23
        Width = 87
        Height = 19
        AutoSize = False
        Caption = 'Available &Fields'
        FocusControl = FieldList
      end
      object Label2: TLabel
        Left = 216
        Top = 144
        Width = 70
        Height = 17
        AutoSize = False
        Caption = 'For&mat'
        FocusControl = FormatEdit
      end
      object ValueCount: TLabel
        Left = 307
        Top = 230
        Width = 145
        Height = 21
        AutoSize = False
        Visible = False
      end
      object BaseNameLabel: TLabel
        Left = 216
        Top = 234
        Width = 70
        Height = 17
        AutoSize = False
        Caption = '&Base Field'
        FocusControl = BaseNameEdit
      end
      object FieldList: TListBox
        Left = 10
        Top = 43
        Width = 191
        Height = 186
        ExtendedSelect = False
        ItemHeight = 13
        TabOrder = 0
        OnClick = FieldListClick
        OnDblClick = FieldListClick
      end
      object CaptionEdit: TEdit
        Left = 307
        Top = 50
        Width = 145
        Height = 21
        TabOrder = 1
        Text = 'CaptionEdit'
        OnChange = HandleFieldEdit
      end
      object ActiveEdit: TComboBox
        Left = 307
        Top = 109
        Width = 145
        Height = 21
        Hint = 'Control of when the information for this field is loaded'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        Text = 'ActiveEdit'
        OnChange = HandleFieldEdit
        Items.Strings = (
          'Active'
          'As Needed'
          'Inactive')
      end
      object BinEdit: TComboBox
        Left = 307
        Top = 168
        Width = 145
        Height = 21
        Hint = 'Group values for this field into ranges'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        Text = 'BinEdit'
        OnChange = HandleFieldEdit
        Items.Strings = (
          'None'
          'Year'
          'Quarter'
          'Month'
          'Single Value')
      end
      object TypeEdit: TComboBox
        Left = 307
        Top = 79
        Width = 145
        Height = 21
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = False
        TabOrder = 2
        Text = 'TypeEdit'
        OnChange = HandleFieldEdit
        Items.Strings = (
          'Dimension'
          'Sum'
          'Count'
          'Average'
          'Min'
          'Max'
          'GenericAgg'
          'Unknown')
      end
      object FormatEdit: TEdit
        Left = 307
        Top = 138
        Width = 145
        Height = 21
        ParentShowHint = False
        ShowHint = False
        TabOrder = 5
        Text = 'FormatEdit'
        OnChange = HandleFieldEdit
      end
      object StartEdit: TMaskEdit
        Left = 307
        Top = 197
        Width = 145
        Height = 21
        Hint = 
          'Starting value for date ranges, Intial value for single valued d' +
          'imensions'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        OnChange = HandleFieldEdit
      end
      object BaseNameEdit: TMaskEdit
        Left = 307
        Top = 229
        Width = 145
        Height = 21
        Hint = 
          'Fieldname (for a summary, the original field used to calculate t' +
          'he summary)'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 7
        Text = 'BaseNameEdit'
        OnChange = HandleFieldEdit
      end
    end
    object MemoryControl: TTabSheet
      HelpContext = 30172
      Caption = 'Memory Control'
      object Panel1: TGroupBox
        Left = 9
        Top = 152
        Width = 454
        Height = 106
        Hint = 'Control whether to load the decision cube at design time'
        Caption = 'Designer Data Options'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        object RadioMetaData: TRadioButton
          Left = 44
          Top = 20
          Width = 153
          Height = 21
          Caption = 'Display Dimension &Names'
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          OnClick = RadioMetaDataClick
        end
        object RadioDimensionData: TRadioButton
          Left = 44
          Top = 40
          Width = 225
          Height = 21
          Caption = 'Display Names and &Values'
          TabOrder = 1
          OnClick = RadioDimensionDataClick
        end
        object RadioAllData: TRadioButton
          Left = 44
          Top = 60
          Width = 196
          Height = 21
          Caption = 'Display Names, Values, and &Totals'
          TabOrder = 2
          OnClick = RadioAllDataClick
        end
        object RadioNoData: TRadioButton
          Left = 44
          Top = 80
          Width = 147
          Height = 21
          Caption = '&Run Time Display Only'
          TabOrder = 3
          OnClick = RadioNoDataClick
        end
      end
      object CubeLimits: TGroupBox
        Left = 8
        Top = 3
        Width = 455
        Height = 141
        Caption = 'Cube Maximums'
        TabOrder = 1
        object NActiveDims: TLabel
          Left = 118
          Top = 113
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object nDemandDims: TLabel
          Left = 118
          Top = 88
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object Label4: TLabel
          Left = 27
          Top = 113
          Width = 93
          Height = 18
          AutoSize = False
          Caption = 'Active'
        end
        object Label7: TLabel
          Left = 27
          Top = 88
          Width = 93
          Height = 18
          AutoSize = False
          Caption = 'Active+Needed'
        end
        object Label9: TLabel
          Left = 119
          Top = 12
          Width = 63
          Height = 18
          AutoSize = False
          Caption = '&Dimensions'
          FocusControl = MaxDims
        end
        object NActiveSums: TLabel
          Left = 191
          Top = 113
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object NDemandSums: TLabel
          Left = 191
          Top = 88
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object Label6: TLabel
          Left = 186
          Top = 12
          Width = 67
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '&Summaries'
          FocusControl = MaxSums
        end
        object Label12: TLabel
          Left = 267
          Top = 11
          Width = 64
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '&Cells'
          FocusControl = MaxCells
        end
        object nDemandCells: TLabel
          Left = 266
          Top = 88
          Width = 65
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object Label5: TLabel
          Left = 27
          Top = 32
          Width = 50
          Height = 18
          AutoSize = False
          Caption = 'Maximum'
        end
        object Label3: TLabel
          Left = 27
          Top = 64
          Width = 93
          Height = 18
          AutoSize = False
          Caption = 'Current'
        end
        object nCurrDims: TLabel
          Left = 118
          Top = 64
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object nCurrSums: TLabel
          Left = 191
          Top = 64
          Width = 57
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object nCurrCells: TLabel
          Left = 266
          Top = 64
          Width = 65
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object MaxDims: TEdit
          Left = 118
          Top = 29
          Width = 57
          Height = 21
          Hint = 
            'Limit on the number of dimensions which can be loaded at one tim' +
            'e'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object MaxSums: TEdit
          Left = 191
          Top = 29
          Width = 57
          Height = 21
          Hint = 'Limit on the number of summaries which can be loaded at one time'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
        end
        object MaxCells: TEdit
          Left = 264
          Top = 29
          Width = 69
          Height = 21
          Hint = 
            'Limit on the number of storage cells which can be loaded at one ' +
            'time'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
        end
        object GetCellCounts: TButton
          Left = 343
          Top = 57
          Width = 102
          Height = 25
          Hint = 'Run a query to fetch information required to estimate cell usage'
          Caption = '&Get Cell Counts'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = GetCellCountsClick
        end
      end
    end
  end
  object OKButton: TButton
    Left = 218
    Top = 307
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 1
    OnClick = OKButtonClick
  end
  object CancelButton: TButton
    Left = 311
    Top = 307
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object HelpButton: TButton
    Left = 403
    Top = 307
    Width = 75
    Height = 25
    HelpContext = 5500
    Caption = '&Help'
    TabOrder = 3
    OnClick = HelpButtonClick
  end
end
