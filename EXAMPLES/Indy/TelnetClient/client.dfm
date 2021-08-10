object TelnetForm: TTelnetForm
  Left = 265
  Top = 210
  BorderStyle = bsDialog
  Caption = 'Telnet Demo'
  ClientHeight = 340
  ClientWidth = 521
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
  object lblServer: TLabel
    Left = 16
    Top = 8
    Width = 34
    Height = 13
    HelpType = htKeyword
    Caption = '&Server:'
  end
  object lblPort: TLabel
    Left = 248
    Top = 8
    Width = 19
    Height = 13
    HelpType = htKeyword
    Caption = '&Port'
  end
  object edtServer: TEdit
    Left = 56
    Top = 5
    Width = 161
    Height = 21
    TabOrder = 0
  end
  object btnConnect: TButton
    Left = 56
    Top = 40
    Width = 75
    Height = 25
    Caption = '&Connect'
    TabOrder = 1
    OnClick = btnConnectClick
  end
  object btnDisconnect: TButton
    Left = 144
    Top = 40
    Width = 75
    Height = 25
    Caption = '&Disconnect'
    TabOrder = 2
    OnClick = btnDisconnectClick
  end
  object spnedtPort: TEdit
    Left = 276
    Top = 5
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object UpDown1: TUpDown
    Left = 394
    Top = 3
    Width = 16
    Height = 24
    Min = 0
    Position = 0
    TabOrder = 4
    Wrap = False
    OnClick = UpDown1Click
  end
  object Memo1: TRichEdit
    Left = 0
    Top = 78
    Width = 521
    Height = 243
    Align = alBottom
    ScrollBars = ssBoth
    TabOrder = 5
    WordWrap = False
    OnKeyPress = Memo1KeyPress
  end
  object sbrStatus: TStatusBar
    Left = 0
    Top = 321
    Width = 521
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object IdTelnetDemo: TIdTelnet
    RecvBufferSize = 8192
    OnConnected = IdTelnetDemoConnected
    Port = 23
    OnDataAvailable = IdTelnetDemoDataAvailable
    Terminal = 'dumb'
    OnConnect = IdTelnetDemoConnect
    Left = 272
    Top = 40
  end
end
