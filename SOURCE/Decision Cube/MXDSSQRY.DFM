object DSSQueryEditor: TDSSQueryEditor
  Left = 309
  Top = 212
  HelpContext = 30180
  BorderStyle = bsToolWindow
  Caption = 'Decision Query Editor'
  ClientHeight = 324
  ClientWidth = 420
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object Pager: TPageControl
    Left = 1
    Top = 4
    Width = 417
    Height = 273
    ActivePage = Dimensions
    TabIndex = 0
    TabOrder = 1
    OnChanging = PagerChanging
    object Dimensions: TTabSheet
      HelpContext = 30181
      Caption = 'Dimensions/Summaries'
      object Label2: TLabel
        Left = 254
        Top = 5
        Width = 116
        Height = 16
        AutoSize = False
        Caption = '&Dimensions:'
        FocusControl = ActiveDimList
      end
      object Label3: TLabel
        Left = 255
        Top = 99
        Width = 129
        Height = 17
        AutoSize = False
        Caption = '&Summaries:'
        FocusControl = SummaryList
      end
      object Label4: TLabel
        Left = 11
        Top = 3
        Width = 123
        Height = 19
        AutoSize = False
        Caption = '&List of Available Fields:'
        FocusControl = FieldList
      end
      object Label5: TLabel
        Left = 10
        Top = 201
        Width = 67
        Height = 22
        AutoSize = False
        Caption = '&Table:'
        FocusControl = TableCombo
      end
      object Label6: TLabel
        Left = 153
        Top = 201
        Width = 67
        Height = 22
        AutoSize = False
        Caption = 'Databas&e:'
        FocusControl = DatabaseCombo
      end
      object Label7: TLabel
        Left = 204
        Top = 171
        Width = 38
        Height = 21
        Alignment = taCenter
        AutoSize = False
        Caption = '&Add'
        FocusControl = AddAgg
      end
      object FieldList: TListBox
        Left = 8
        Top = 19
        Width = 181
        Height = 164
        DragMode = dmAutomatic
        ItemHeight = 13
        MultiSelect = True
        TabOrder = 0
        OnClick = FieldListClick
        OnDblClick = FieldListDblClick
        OnDragDrop = FieldListDragDrop
        OnDragOver = FieldListDragOver
        OnKeyPress = FieldListKeyPress
      end
      object ActiveDimList: TListBox
        Left = 254
        Top = 22
        Width = 146
        Height = 73
        DragMode = dmAutomatic
        ItemHeight = 13
        MultiSelect = True
        TabOrder = 1
        OnClick = ActiveDimListClick
        OnDblClick = RemoveButtonClick
        OnDragDrop = ActiveDimListDragDrop
        OnDragOver = ActiveDimListDragOver
        OnKeyPress = ActiveDimListKeyPress
      end
      object SummaryList: TListBox
        Left = 254
        Top = 113
        Width = 146
        Height = 68
        DragMode = dmAutomatic
        ItemHeight = 13
        MultiSelect = True
        TabOrder = 3
        OnClick = SummaryListClick
        OnDblClick = RemoveAggClick
        OnDragDrop = SummaryListDragDrop
        OnDragOver = SummaryListDragOver
        OnKeyPress = SummaryListKeyPress
      end
      object SelectAllFields: TButton
        Left = 301
        Top = 214
        Width = 100
        Height = 25
        Hint = 'List all fields or List only the fields in the query'
        Caption = 'All &Fields'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = SelectAllFieldsClick
      end
      object TableCombo: TComboBox
        Left = 8
        Top = 216
        Width = 135
        Height = 21
        Hint = 'Start a new query using a table from the database'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        Sorted = True
        TabOrder = 4
        OnChange = TableComboChange
        OnExit = TableComboExit
        OnKeyDown = TableComboKeyDown
        OnKeyPress = TableComboKeyPress
      end
      object DatabaseCombo: TComboBox
        Left = 152
        Top = 216
        Width = 135
        Height = 21
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        Sorted = True
        TabOrder = 5
        OnChange = DatabaseComboChange
        OnExit = DatabaseComboExit
        OnKeyDown = DatabaseComboKeyDown
        OnKeyPress = DatabaseComboKeyPress
      end
      object AddButton: TBitBtn
        Left = 211
        Top = 61
        Width = 25
        Height = 25
        TabOrder = 6
        TabStop = False
        OnClick = AddButtonClick
        Glyph.Data = {
          EE000000424DEE0000000000000076000000280000000F0000000F0000000100
          0400000000007800000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00111111111111
          1110111111101111111011111110011111101111111080111110111111108801
          111011111110888011101100000088880110118888888888801011FFFFF08888
          F11011111110888F11101111111088F11110111111108F11111011111110F111
          111011111110111111101111111111111110}
      end
      object AddAgg: TBitBtn
        Left = 211
        Top = 142
        Width = 25
        Height = 25
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Default'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        TabStop = False
        OnClick = AddAggClick
        Glyph.Data = {
          EE000000424DEE0000000000000076000000280000000F0000000F0000000100
          0400000000007800000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00111111111111
          1110111111101111111011111110011111101111111080111110111111108801
          111011111110888011101100000088880110118888888888801011FFFFF08888
          F11011111110888F11101111111088F11110111111108F11111011111110F111
          111011111110111111101111111111111110}
        Layout = blGlyphTop
      end
      object RemoveButton: TBitBtn
        Left = 210
        Top = 29
        Width = 25
        Height = 25
        TabOrder = 8
        TabStop = False
        OnClick = RemoveButtonClick
        Glyph.Data = {
          EE000000424DEE0000000000000076000000280000000F0000000F0000000100
          0400000000007800000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00111111111111
          1110111111101111111011111100111111101111108011111110111108801111
          111011108880111111101108888000000110108888888888811011F88880FFFF
          F110111F8880111111101111F8801111111011111F8011111110111111F01111
          111011111110111111101111111111111110}
      end
      object RemoveAgg: TBitBtn
        Left = 210
        Top = 111
        Width = 25
        Height = 25
        TabOrder = 9
        TabStop = False
        OnClick = RemoveAggClick
        Glyph.Data = {
          EE000000424DEE0000000000000076000000280000000F0000000F0000000100
          0400000000007800000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00111111111111
          1110111111101111111011111100111111101111108011111110111108801111
          111011108880111111101108888000000110108888888888811011F88880FFFF
          F110111F8880111111101111F8801111111011111F8011111110111111F01111
          111011111110111111101111111111111110}
      end
      object CountStarAvg: TCheckBox
        Left = 260
        Top = 188
        Width = 144
        Height = 17
        Hint = 'Use count(*) to calculate averages (counts null values)'
        Caption = 'Count (*) for Averages'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 10
        OnClick = CountStarAvgClick
      end
    end
    object Query: TTabSheet
      HelpContext = 30182
      Caption = 'SQL Query'
      object Label1: TLabel
        Left = 10
        Top = 5
        Width = 94
        Height = 21
        AutoSize = False
        Caption = '&Query Text:'
        FocusControl = ShowBox
      end
      object ShowBox: TMemo
        Left = 7
        Top = 21
        Width = 392
        Height = 171
        TabStop = False
        ScrollBars = ssVertical
        TabOrder = 0
        OnChange = ShowBoxChange
        OnKeyPress = ShowBoxKeyPress
      end
      object CancelQryMod: TButton
        Left = 223
        Top = 206
        Width = 75
        Height = 25
        Caption = '&Cancel Edit'
        TabOrder = 1
        OnClick = CancelQryModClick
      end
      object EditQry: TButton
        Left = 112
        Top = 205
        Width = 75
        Height = 25
        Hint = 'Type in the query directly'
        Caption = '&Edit Query'
        ParentShowHint = False
        ShowHint = False
        TabOrder = 2
        OnClick = EditQryClick
      end
    end
  end
  object Cancel: TBitBtn
    Left = 246
    Top = 291
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
    NumGlyphs = 2
  end
  object OKButton: TButton
    Left = 154
    Top = 291
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKButtonClick
  end
  object HelpButton: TButton
    Left = 337
    Top = 291
    Width = 75
    Height = 25
    HelpContext = 5510
    Caption = '&Help'
    TabOrder = 4
    OnClick = HelpButtonClick
  end
  object VQB: TButton
    Left = 20
    Top = 291
    Width = 100
    Height = 25
    Hint = 'Add/Join Tables and Create Field List with SQL Builder'
    Caption = 'SQL &Builder ...'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnClick = VQBClick
  end
  object AggPopup: TPopupMenu
    Left = 123
    Top = 286
    object count1: TMenuItem
      Caption = '&sum'
      OnClick = Sum1Click
    end
    object count2: TMenuItem
      Caption = '&count'
      OnClick = count1Click
    end
    object average1: TMenuItem
      Caption = '&average'
      OnClick = average1Click
    end
  end
end
