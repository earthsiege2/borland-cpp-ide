object formMain: TformMain
  Left = 269
  Top = 333
  BorderStyle = bsDialog
  Caption = 'SSL Tunnel'
  ClientHeight = 140
  ClientWidth = 253
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lablLocal: TLabel
    Left = 18
    Top = 32
    Width = 42
    Height = 13
    Caption = 'lablLocal'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlight
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 2
    Top = 0
    Width = 249
    Height = 13
    Caption = 'Usage: SSLTunnel <Local Port> <Host> <Host Port>'
  end
  object lablHost: TLabel
    Left = 18
    Top = 48
    Width = 32
    Height = 13
    Caption = 'Label1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlight
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label1: TLabel
    Left = 2
    Top = 88
    Width = 218
    Height = 13
    Caption = 'Winshoes 8/Indy OpenSSL DLLs available at:'
  end
  object Label3: TLabel
    Left = 18
    Top = 104
    Width = 182
    Height = 13
    Caption = 'http://www.intelicom.si/download.html'
  end
  object MappedPort: TIdMappedPortTCP
    Bindings = <>
    DefaultPort = 0
    MappedHost = 'forums.borland.com'
    OnBeforeClientConnect = MappedPortBeforeClientConnect
    Left = 106
    Top = 16
  end
end
