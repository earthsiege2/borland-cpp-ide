object frmGeneratorEditor: TfrmGeneratorEditor
  Left = 365
  Top = 225
  BorderStyle = bsDialog
  Caption = 'frmGeneratorEditor'
  ClientHeight = 212
  ClientWidth = 274
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 10
    Top = 13
    Width = 79
    Height = 13
    Alignment = taRightJustify
    AutoSize = False
    Caption = '&Generator'
    FocusControl = cbxGenerators
  end
  object Label2: TLabel
    Left = 10
    Top = 41
    Width = 79
    Height = 13
    Alignment = taRightJustify
    AutoSize = False
    Caption = '&Field'
    FocusControl = cbxFields
  end
  object Label3: TLabel
    Left = 27
    Top = 68
    Width = 62
    Height = 13
    Alignment = taRightJustify
    Caption = 'Increment By'
  end
  object OKBtn: TButton
    Left = 10
    Top = 182
    Width = 61
    Height = 24
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 81
    Top = 182
    Width = 61
    Height = 24
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object cbxGenerators: TComboBox
    Left = 94
    Top = 10
    Width = 170
    Height = 21
    ItemHeight = 13
    Sorted = True
    TabOrder = 2
    Text = 'cbxGenerators'
  end
  object cbxFields: TComboBox
    Left = 94
    Top = 37
    Width = 170
    Height = 21
    ItemHeight = 13
    Sorted = True
    TabOrder = 3
    Text = 'cbxFields'
  end
  object grpApplyEvent: TRadioGroup
    Left = 10
    Top = 92
    Width = 254
    Height = 79
    Caption = '&Apply Event'
    ItemIndex = 0
    Items.Strings = (
      'On New Record'
      'On Post'
      'On Server')
    TabOrder = 4
  end
  object HelpBtn: TButton
    Left = 202
    Top = 182
    Width = 61
    Height = 24
    Caption = 'Help'
    TabOrder = 5
    Visible = False
  end
  object edtIncrement: TEdit
    Left = 96
    Top = 64
    Width = 165
    Height = 21
    TabOrder = 6
    Text = '1'
  end
end
