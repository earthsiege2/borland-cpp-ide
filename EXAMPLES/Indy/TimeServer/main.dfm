object frmMain: TfrmMain
  Left = 266
  Top = 235
  Width = 337
  Height = 115
  Caption = 'Time Server'
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
    Left = 8
    Top = 12
    Width = 33
    Height = 13
    Caption = 'Status:'
  end
  object lblStatus: TLabel
    Left = 48
    Top = 12
    Width = 28
    Height = 13
    Caption = '[ idle ]'
  end
  object IdTimeServer1: TIdTimeServer
    Active = True
    Bindings = <
      item
        Port = 37
      end>
    DefaultPort = 37
    OnConnect = IdTimeServer1Connect
    OnDisconnect = IdTimeServer1Disconnect
    BaseDate = 2
    Left = 8
    Top = 36
  end
end
