object TfrmPing: TTfrmPing
  Left = 304
  Top = 297
  Width = 490
  Height = 247
  Caption = 'Ping'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lstReplies: TListBox
    Left = 0
    Top = 33
    Width = 482
    Height = 187
    Align = alClient
    ItemHeight = 13
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 482
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object btnPing: TButton
      Left = 232
      Top = 3
      Width = 75
      Height = 25
      Caption = '&Ping'
      Default = True
      TabOrder = 0
      OnClick = btnPingClick
    end
    object edtHost: TEdit
      Left = 4
      Top = 4
      Width = 221
      Height = 21
      TabOrder = 1
      Text = 'www.nevrona.com'
    end
  end
  object ICMP: TIdIcmpClient
    ReceiveTimeout = 1000
    OnReply = ICMPReply
    Left = 112
    Top = 128
  end
end
