object AxisIncrement: TAxisIncrement
  Left = 263
  Top = 191
  ActiveControl = BitBtn1
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Axis Increment'
  ClientHeight = 114
  ClientWidth = 327
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 18
    Top = 81
    Width = 50
    Height = 13
    Caption = '&Increment:'
    FocusControl = ECustom
  end
  object RadioGroup1: TRadioGroup
    Left = 4
    Top = 30
    Width = 234
    Height = 80
    Caption = 'Increment:'
    Items.Strings = (
      '&Standard:'
      '&Custom:')
    TabOrder = 1
    OnClick = RadioGroup1Click
  end
  object CBSteps: TComboBox
    Left = 96
    Top = 48
    Width = 129
    Height = 21
    HelpContext = 248
    Style = csDropDownList
    DropDownCount = 18
    ItemHeight = 13
    TabOrder = 2
    OnChange = CBStepsChange
    Items.Strings = (
      'One Second'
      'Five Seconds'
      'Ten Seconds'
      'Fifteen Seconds'
      'Thirty Seconds'
      'One Minute'
      'Five Minutes'
      'Ten Minutes'
      'Fifteen Minutes'
      'Thirty Minutes'
      'One Hour'
      'Two Hours'
      'Six Hours'
      'Twelve Hours'
      'One Day'
      'Two Days'
      'Three Days'
      'One Week'
      'Half Month'
      'One Month'
      'Two Months'
      'Three Months'
      'Four Months'
      'Six Months'
      'One Year')
  end
  object ECustom: TEdit
    Left = 96
    Top = 78
    Width = 129
    Height = 21
    HelpContext = 248
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
  end
  object BitBtn1: TButton
    Left = 246
    Top = 52
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 4
    OnClick = BitBtn1Click
  end
  object BitBtn2: TButton
    Left = 246
    Top = 85
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
  object CBExact: TCheckBox
    Left = 98
    Top = 10
    Width = 111
    Height = 17
    HelpContext = 204
    Caption = '&Exact Date Time'
    TabOrder = 0
    OnClick = CBExactClick
  end
end
