object QRLabelEditorForm: TQRLabelEditorForm
  Left = 324
  Top = 272
  BorderStyle = bsDialog
  Caption = 'Text Settings'
  ClientHeight = 181
  ClientWidth = 329
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 6
    Top = 6
    Width = 311
    Height = 123
    Caption = 'Properties'
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 28
      Width = 21
      Height = 13
      Caption = 'Text'
    end
    object Label2: TLabel
      Left = 10
      Top = 58
      Width = 28
      Height = 13
      Caption = 'Width'
    end
    object Label3: TLabel
      Left = 10
      Top = 86
      Width = 31
      Height = 13
      Caption = 'Height'
    end
    object Value: TEdit
      Left = 54
      Top = 26
      Width = 227
      Height = 21
      TabOrder = 0
      Text = 'Value'
    end
    object AutoSize: TCheckBox
      Left = 182
      Top = 52
      Width = 95
      Height = 17
      Caption = 'Autosize'
      TabOrder = 1
    end
    object Stretch: TCheckBox
      Left = 182
      Top = 72
      Width = 97
      Height = 17
      Caption = 'Stretch'
      TabOrder = 2
    end
    object Transparent: TCheckBox
      Left = 182
      Top = 92
      Width = 97
      Height = 17
      Caption = 'Transparent'
      TabOrder = 3
    end
    object Width: TMaskEdit
      Left = 54
      Top = 54
      Width = 51
      Height = 21
      EditMask = '9999'
      MaxLength = 4
      TabOrder = 4
      Text = '    '
    end
    object Height: TMaskEdit
      Left = 54
      Top = 82
      Width = 51
      Height = 21
      EditMask = '9999'
      MaxLength = 4
      TabOrder = 5
      Text = '    '
    end
  end
  object OKBtn: TButton
    Left = 152
    Top = 144
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object Button4: TButton
    Left = 240
    Top = 144
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
