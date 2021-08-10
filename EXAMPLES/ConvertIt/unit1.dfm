object Form1: TForm1
  Left = 269
  Top = 239
  Width = 400
  Height = 431
  Caption = 'ConvUtils'
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 400
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ConvFamilies: TTabControl
    Left = 0
    Top = 0
    Width = 392
    Height = 358
    Align = alClient
    TabOrder = 0
    Tabs.Strings = (
      'Testing')
    TabIndex = 0
    OnChange = ConvFamiliesChange
    DesignSize = (
      392
      358)
    object ConvTypes: TListBox
      Left = 16
      Top = 32
      Width = 177
      Height = 317
      Anchors = [akLeft, akTop, akBottom]
      ItemHeight = 13
      Sorted = True
      TabOrder = 0
      OnClick = ConvTypesClick
    end
    object ConvValueIncDec: TUpDown
      Left = 361
      Top = 32
      Width = 15
      Height = 21
      Anchors = [akTop, akRight]
      Associate = ConvValue
      Min = -32000
      Max = 32000
      Position = 1
      TabOrder = 2
      Thousands = False
      Wrap = False
    end
    object ConvResults: TListBox
      Left = 200
      Top = 56
      Width = 176
      Height = 293
      TabStop = False
      Anchors = [akLeft, akTop, akRight, akBottom]
      ItemHeight = 13
      ParentColor = True
      TabOrder = 3
    end
    object ConvValue: TEdit
      Left = 200
      Top = 32
      Width = 161
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 1
      Text = '1'
      OnChange = ConvValueChange
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 358
    Width = 392
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object MainMenu1: TMainMenu
    Left = 56
    Top = 56
    object Exit1: TMenuItem
      Caption = 'E&xit'
      OnClick = Exit1Click
    end
    object About1: TMenuItem
      Caption = '&About'
      OnClick = About1Click
    end
  end
end
