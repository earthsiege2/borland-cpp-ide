object Form1: TForm1
  Left = 303
  Top = 442
  Width = 309
  Height = 134
  Caption = 'Echo Server Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 12
    Width = 67
    Height = 13
    Caption = 'Server Status:'
  end
  object lblStatus: TLabel
    Left = 80
    Top = 12
    Width = 28
    Height = 13
    Caption = '[ idle ]'
  end
  object btnExit: TButton
    Left = 220
    Top = 72
    Width = 75
    Height = 25
    Caption = 'E&xit'
    TabOrder = 0
    OnClick = btnExitClick
  end
  object IdECHOServer1: TIdECHOServer
    Active = True
    Bindings = <>
    OnConnect = IdECHOServer1Connect
    OnDisconnect = IdECHOServer1Disconnect
    Left = 4
    Top = 32
  end
end
