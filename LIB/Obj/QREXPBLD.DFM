object QRExpressionBuilder: TQRExpressionBuilder
  Left = 174
  Top = 133
  BorderStyle = bsDialog
  Caption = 'Expression Wizard'
  ClientHeight = 269
  ClientWidth = 376
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object VariablePage: TPanel
    Left = 0
    Top = 0
    Width = 376
    Height = 269
    Align = alClient
    BevelOuter = bvNone
    Caption = 'VariablePage'
    Enabled = False
    TabOrder = 4
    object GroupBox5: TGroupBox
      Left = 18
      Top = 10
      Width = 343
      Height = 205
      Caption = 'Select variable'
      TabOrder = 0
      object VariableValue: TLabel
        Left = 54
        Top = 180
        Width = 65
        Height = 13
        Caption = 'VariableValue'
      end
      object Label1: TLabel
        Left = 18
        Top = 180
        Width = 33
        Height = 13
        Caption = 'Value :'
      end
      object AvailableVariables: TListBox
        Left = 16
        Top = 20
        Width = 311
        Height = 155
        ItemHeight = 13
        TabOrder = 0
        OnClick = AvailableVariablesClick
        OnDblClick = VariableOKBtnClick
      end
    end
    object VariableOKBtn: TButton
      Left = 252
      Top = 233
      Width = 49
      Height = 21
      Caption = 'OK'
      TabOrder = 1
      OnClick = VariableOKBtnClick
    end
    object VariableCancelBtn: TButton
      Left = 312
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Cancel'
      TabOrder = 2
      OnClick = VariableCancelBtnClick
    end
    object ModifyVariables: TButton
      Left = 20
      Top = 233
      Width = 111
      Height = 21
      Caption = '&Modify variables'
      TabOrder = 3
      OnClick = ModifyVariablesClick
    end
  end
  object MainPage: TPanel
    Left = 0
    Top = 0
    Width = 376
    Height = 269
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Heading: TLabel
      Left = 18
      Top = 16
      Width = 81
      Height = 13
      Caption = 'Enter expression:'
    end
    object GroupBox1: TGroupBox
      Left = 18
      Top = 134
      Width = 343
      Height = 81
      Caption = 'Insert at cursor position'
      TabOrder = 0
      object InsertDataFieldBtn: TButton
        Left = 10
        Top = 18
        Width = 100
        Height = 25
        Caption = '&Database field'
        TabOrder = 0
        OnClick = InsertDataFieldBtnClick
      end
      object InsertFunctionBtn: TButton
        Left = 120
        Top = 18
        Width = 100
        Height = 25
        Caption = '&Function'
        TabOrder = 1
        OnClick = InsertFunctionBtnClick
      end
      object InsertVariableBtn: TButton
        Left = 234
        Top = 18
        Width = 100
        Height = 25
        Caption = '&Variable'
        TabOrder = 2
        OnClick = InsertVariableBtnClick
      end
      object AddPlus: TButton
        Left = 10
        Top = 50
        Width = 25
        Height = 21
        Caption = '+'
        TabOrder = 3
        OnClick = AddSomeClick
      end
      object AddMinus: TButton
        Left = 35
        Top = 50
        Width = 25
        Height = 21
        Caption = '-'
        TabOrder = 4
        OnClick = AddSomeClick
      end
      object AddMul: TButton
        Left = 60
        Top = 50
        Width = 25
        Height = 21
        Caption = '*'
        TabOrder = 5
        OnClick = AddSomeClick
      end
      object AddDiv: TButton
        Left = 85
        Top = 50
        Width = 25
        Height = 21
        Caption = '/'
        TabOrder = 6
        OnClick = AddSomeClick
      end
      object AddEqual: TButton
        Left = 110
        Top = 50
        Width = 25
        Height = 21
        Caption = '='
        TabOrder = 7
        OnClick = AddSomeClick
      end
      object AddSmaller: TButton
        Left = 135
        Top = 50
        Width = 25
        Height = 21
        Caption = '<'
        TabOrder = 8
        OnClick = AddSomeClick
      end
      object AddLarger: TButton
        Left = 160
        Top = 50
        Width = 25
        Height = 21
        Caption = '>'
        TabOrder = 9
        OnClick = AddSomeClick
      end
      object AddNotEqual: TButton
        Left = 185
        Top = 50
        Width = 25
        Height = 21
        Caption = '<>'
        TabOrder = 10
        OnClick = AddSomeClick
      end
      object AddLessEqual: TButton
        Left = 210
        Top = 50
        Width = 25
        Height = 21
        Caption = '<='
        TabOrder = 11
        OnClick = AddSomeClick
      end
      object AddGreaterEqual: TButton
        Left = 235
        Top = 50
        Width = 25
        Height = 21
        Caption = '>='
        TabOrder = 12
        OnClick = AddSomeClick
      end
      object AddNot: TButton
        Left = 260
        Top = 50
        Width = 25
        Height = 21
        Caption = 'Not'
        TabOrder = 13
        OnClick = AddSomeClick
      end
      object AddAnd: TButton
        Left = 285
        Top = 50
        Width = 25
        Height = 21
        Caption = 'And'
        TabOrder = 14
        OnClick = AddSomeClick
      end
      object AddOr: TButton
        Left = 310
        Top = 50
        Width = 25
        Height = 21
        Caption = 'Or'
        TabOrder = 15
        OnClick = AddSomeClick
      end
    end
    object ValidateBtn: TButton
      Left = 78
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Valida&te'
      TabOrder = 1
      OnClick = ValidateBtnClick
    end
    object Clear: TButton
      Left = 20
      Top = 233
      Width = 49
      Height = 21
      Caption = '&Clear'
      TabOrder = 2
      OnClick = ClearClick
    end
    object OK: TButton
      Left = 252
      Top = 233
      Width = 49
      Height = 21
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 3
      OnClick = OKClick
    end
    object Cancel: TButton
      Left = 312
      Top = 233
      Width = 49
      Height = 21
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 4
      OnClick = CancelClick
    end
  end
  object DataFieldPage: TPanel
    Left = 0
    Top = 0
    Width = 376
    Height = 269
    Align = alClient
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 1
    object DataFieldOKBtn: TButton
      Left = 252
      Top = 233
      Width = 49
      Height = 21
      Caption = 'OK'
      TabOrder = 0
      OnClick = DataFieldOKBtnClick
    end
    object DataFieldCancelBtn: TButton
      Left = 312
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = DataFieldCancelBtnClick
    end
    object DataFieldGB: TGroupBox
      Left = 18
      Top = 10
      Width = 343
      Height = 205
      Caption = 'Insert database field in expression'
      TabOrder = 2
      object Label2: TLabel
        Left = 12
        Top = 18
        Width = 68
        Height = 13
        Caption = 'Select dataset'
      end
      object Label3: TLabel
        Left = 12
        Top = 60
        Width = 70
        Height = 13
        Caption = 'Available fields'
      end
      object DataSet: TComboBox
        Left = 10
        Top = 36
        Width = 317
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
      end
      object DataField: TListBox
        Left = 10
        Top = 76
        Width = 315
        Height = 117
        Columns = 2
        ItemHeight = 13
        Items.Strings = (
          'Custno'
          'Name'
          'Contact'
          'Contact-e-mail'
          'Address1'
          'Address2'
          'Address3'
          'Address4'
          'Country'
          'Phone'
          'Fax'
          'Web'
          'Credit-limit'
          'Rating'
          'Default-Discount'
          'OurContact')
        TabOrder = 1
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 0
        Width = 343
        Height = 205
        Caption = 'Insert database field in expression'
        TabOrder = 2
        object Label4: TLabel
          Left = 16
          Top = 20
          Width = 68
          Height = 13
          Caption = 'Select dataset'
        end
        object Label5: TLabel
          Left = 186
          Top = 20
          Width = 70
          Height = 13
          Caption = 'Available fields'
        end
        object AvailableFields: TListBox
          Left = 184
          Top = 40
          Width = 139
          Height = 150
          ItemHeight = 13
          TabOrder = 0
          OnDblClick = DataFieldOKBtnClick
        end
        object AvailableDatasets: TListBox
          Left = 14
          Top = 40
          Width = 140
          Height = 150
          ItemHeight = 13
          TabOrder = 1
          OnClick = AvailableDatasetsClick
        end
      end
    end
  end
  object FunctionPage: TPanel
    Left = 0
    Top = 0
    Width = 376
    Height = 269
    Align = alClient
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 2
    object FunctionOKBtn: TButton
      Left = 252
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Continue'
      TabOrder = 0
      OnClick = FunctionOKBtnClick
    end
    object FunctionCancelBtn: TButton
      Left = 312
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = FunctionCancelBtnClick
    end
    object GroupBox4: TGroupBox
      Left = 18
      Top = 10
      Width = 343
      Height = 205
      Caption = 'Select function'
      TabOrder = 2
      object Label6: TLabel
        Left = 18
        Top = 22
        Width = 42
        Height = 13
        Caption = 'Category'
      end
      object Label7: TLabel
        Left = 186
        Top = 22
        Width = 89
        Height = 13
        Caption = 'Available functions'
      end
      object FuncName: TLabel
        Left = 18
        Top = 160
        Width = 61
        Height = 13
        Caption = 'FuncName'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Default'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object FuncDescription: TLabel
        Left = 18
        Top = 174
        Width = 307
        Height = 27
        AutoSize = False
        Caption = 'FuncDescription'
        WordWrap = True
      end
      object Categories: TListBox
        Left = 16
        Top = 42
        Width = 140
        Height = 113
        ItemHeight = 13
        Items.Strings = (
          'All'
          'Date & time'
          'Math & trig'
          'Statistical'
          'Database'
          'Logical'
          'Information'
          'Other')
        TabOrder = 0
        OnClick = CategoriesClick
      end
      object AvailableFunc: TListBox
        Left = 184
        Top = 42
        Width = 140
        Height = 113
        ItemHeight = 13
        TabOrder = 1
        OnClick = AvailableFuncClick
        OnDblClick = FunctionOKBtnClick
      end
    end
  end
  object FuncParamsPage: TPanel
    Left = 0
    Top = 0
    Width = 376
    Height = 269
    Align = alClient
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 3
    object GroupBox3: TGroupBox
      Left = 18
      Top = 10
      Width = 343
      Height = 205
      Caption = 'Enter parameters for function'
      TabOrder = 0
      object CopyFuncName: TLabel
        Left = 16
        Top = 16
        Width = 61
        Height = 13
        Caption = 'FuncName'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Default'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CopyFuncDescription: TLabel
        Left = 16
        Top = 30
        Width = 307
        Height = 27
        AutoSize = False
        Caption = 'FuncDescription'
        WordWrap = True
      end
      object FuncParamSB: TScrollBox
        Left = 4
        Top = 72
        Width = 335
        Height = 129
        BorderStyle = bsNone
        TabOrder = 0
      end
    end
    object FuncParamOkBtn: TButton
      Left = 252
      Top = 233
      Width = 49
      Height = 21
      Caption = 'OK'
      TabOrder = 1
      OnClick = FuncParamOkBtnClick
    end
    object FuncArgCancelBtn: TButton
      Left = 312
      Top = 233
      Width = 49
      Height = 21
      Caption = 'Cancel'
      TabOrder = 2
      OnClick = FuncArgCancelBtnClick
    end
  end
end
