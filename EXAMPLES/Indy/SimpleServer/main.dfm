object frmMain: TfrmMain
  Left = 192
  Top = 465
  Width = 316
  Height = 114
  Caption = 'Simple Server'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnAccept: TButton
    Left = 112
    Top = 24
    Width = 137
    Height = 25
    Caption = '&Accept One Connection'
    TabOrder = 0
    OnClick = btnAcceptClick
  end
  object SServ: TIdSimpleServer
    RecvBufferSize = 1024
    BoundPort = 1000
    Left = 40
    Top = 24
  end
end
