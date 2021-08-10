object frmTimeDemo: TfrmTimeDemo
  Left = 192
  Top = 107
  Width = 376
  Height = 136
  Caption = 'Time Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblTimeServer: TLabel
    Left = 40
    Top = 24
    Width = 60
    Height = 13
    Caption = '&Time Server:'
  end
  object Label1: TLabel
    Left = 16
    Top = 56
    Width = 86
    Height = 13
    Caption = 'Time &From Server:'
    FocusControl = btnGetTime
  end
  object edtTimeResult: TEdit
    Left = 112
    Top = 56
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 0
  end
  object btnGetTime: TButton
    Left = 248
    Top = 24
    Width = 75
    Height = 25
    Caption = '&Get Time'
    Default = True
    TabOrder = 1
    OnClick = btnGetTimeClick
  end
  object cmboTimeServer: TComboBox
    Left = 112
    Top = 24
    Width = 121
    Height = 21
    ItemHeight = 13
    Sorted = True
    TabOrder = 2
    Text = 'ben.cs.wisc.edu'
    Items.Strings = (
      '127.0.0.1'
      'ben.cs.wisc.edu'
      'bigben.cac.washington.edu'
      'bitsy.mit.edu'
      'bonehed.lcs.mit.edu'
      'canon.inria.fr'
      'chronos.cru.fr')
  end
  object IdDemoTime: TIdTime
    RecvBufferSize = 1024
    Port = 37
    BaseDate = 2
    Left = 264
    Top = 64
  end
end
