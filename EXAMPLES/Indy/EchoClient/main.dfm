object formEchoTest: TformEchoTest
  Left = 294
  Top = 191
  Width = 389
  Height = 212
  Caption = 'Echo Test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object lblTextToEcho: TLabel
    Left = 24
    Top = 48
    Width = 52
    Height = 13
    Caption = 'Send &Text:'
  end
  object lblTotalTime: TLabel
    Left = 24
    Top = 80
    Width = 54
    Height = 13
    Caption = 'Echo Time:'
  end
  object lblEchoServer: TLabel
    Left = 16
    Top = 16
    Width = 62
    Height = 13
    Caption = 'Echo Server:'
  end
  object lblReceivedText: TLabel
    Left = 8
    Top = 112
    Width = 73
    Height = 13
    Caption = 'Received Text:'
  end
  object lablTime: TLabel
    Left = 88
    Top = 80
    Width = 113
    Height = 13
    AutoSize = False
  end
  object lablReceived: TLabel
    Left = 88
    Top = 112
    Width = 185
    Height = 13
    AutoSize = False
  end
  object edtSendText: TEdit
    Left = 88
    Top = 48
    Width = 185
    Height = 21
    Color = clSilver
    Enabled = False
    TabOrder = 0
  end
  object edtEchoServer: TEdit
    Left = 88
    Top = 16
    Width = 185
    Height = 21
    TabOrder = 1
    OnChange = edtEchoServerChange
  end
  object btnConnect: TButton
    Left = 280
    Top = 14
    Width = 81
    Height = 25
    Caption = '&Connect'
    TabOrder = 2
    OnClick = btnConnectClick
  end
  object btnDisconnect: TButton
    Left = 280
    Top = 144
    Width = 81
    Height = 25
    Caption = '&Disconnect'
    Enabled = False
    TabOrder = 3
    OnClick = btnDisconnectClick
  end
  object Button1: TButton
    Left = 281
    Top = 48
    Width = 75
    Height = 25
    Caption = '&Send'
    TabOrder = 4
    OnClick = Button1Click
  end
  object IdEcoTestConnection: TIdEcho
    RecvBufferSize = 1024
    Left = 16
    Top = 136
  end
end
