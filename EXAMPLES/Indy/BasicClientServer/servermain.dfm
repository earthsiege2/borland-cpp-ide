object frmServer: TfrmServer
  Left = 365
  Top = 253
  Width = 273
  Height = 118
  Caption = 'Basic Indy Server'
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
  object TCPServer: TIdTCPServer
    Bindings = <
      item
        Port = 8090
      end>
    DefaultPort = 8090
    OnExecute = TCPServerExecute
    Left = 8
    Top = 8
  end
end
