object QRExprEditorForm: TQRExprEditorForm
  Left = 309
  Top = 531
  BorderStyle = bsDialog
  Caption = 'Expression settings'
  ClientHeight = 210
  ClientWidth = 367
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 6
    Top = 6
    Width = 355
    Height = 151
    Caption = 'Properties'
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 28
      Width = 51
      Height = 13
      Caption = 'Expression'
    end
    object Label2: TLabel
      Left = 10
      Top = 90
      Width = 28
      Height = 13
      Caption = 'Width'
    end
    object Label3: TLabel
      Left = 10
      Top = 118
      Width = 31
      Height = 13
      Caption = 'Height'
    end
    object ShowExprBuilder: TSpeedButton
      Left = 320
      Top = 24
      Width = 23
      Height = 22
      Caption = '...'
      OnClick = ShowExprBuilderClick
    end
    object Label4: TLabel
      Left = 10
      Top = 56
      Width = 60
      Height = 13
      Caption = 'Format mask'
    end
    object Value: TEdit
      Left = 86
      Top = 26
      Width = 227
      Height = 21
      TabOrder = 0
      Text = 'Value'
    end
    object AutoSize: TCheckBox
      Left = 182
      Top = 84
      Width = 95
      Height = 17
      Caption = 'Autosize'
      TabOrder = 4
    end
    object Stretch: TCheckBox
      Left = 182
      Top = 104
      Width = 97
      Height = 17
      Caption = 'Stretch'
      TabOrder = 5
    end
    object Transparent: TCheckBox
      Left = 182
      Top = 124
      Width = 97
      Height = 17
      Caption = 'Transparent'
      TabOrder = 6
    end
    object Width: TMaskEdit
      Left = 86
      Top = 86
      Width = 51
      Height = 21
      EditMask = '9999'
      MaxLength = 4
      TabOrder = 2
      Text = '    '
    end
    object Height: TMaskEdit
      Left = 86
      Top = 114
      Width = 51
      Height = 21
      EditMask = '9999'
      MaxLength = 4
      TabOrder = 3
      Text = '    '
    end
    object Mask: TComboBox
      Left = 86
      Top = 54
      Width = 227
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      Text = 'Mask'
    end
  end
  object OKBtn: TButton
    Left = 196
    Top = 172
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object Button4: TButton
    Left = 284
    Top = 172
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 262
    Top = 114
  end
end
