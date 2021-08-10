object Form2: TForm2
  Left = 274
  Top = 208
  Width = 409
  Height = 250
  Caption = 'Basic Indy Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lstMain: TListBox
    Left = 0
    Top = 41
    Width = 401
    Height = 182
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 0
  end
  object pnlTop: TPanel
    Left = 0
    Top = 0
    Width = 401
    Height = 41
    Align = alTop
    BevelOuter = bvLowered
    TabOrder = 1
    object btnGo: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Go'
      Default = True
      TabOrder = 0
      OnClick = btnGoClick
    end
  end
  object TCPClient: TIdTCPClient
    RecvBufferSize = 1024
    Host = '127.0.0.1'
    Port = 8090
    Left = 8
    Top = 48
  end
end
