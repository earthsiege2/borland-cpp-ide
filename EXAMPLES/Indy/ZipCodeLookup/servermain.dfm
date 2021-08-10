object formMain: TformMain
  Left = 301
  Top = 146
  Width = 364
  Height = 234
  Caption = 'Indy Zip Code Server'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object IdTCPServer1: TIdTCPServer
    Active = True
    Bindings = <>
    DefaultPort = 6000
    OnConnect = IdTCPServer1Connect
    OnExecute = IdTCPServer1Execute
    Left = 48
    Top = 40
  end
end
