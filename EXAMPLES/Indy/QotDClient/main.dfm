object frmQuoteOfTheDayDemo: TfrmQuoteOfTheDayDemo
  Left = 364
  Top = 224
  Width = 371
  Height = 205
  Caption = 'Quote of the Day'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    363
    178)
  PixelsPerInch = 96
  TextHeight = 13
  object lblServer: TLabel
    Left = 24
    Top = 8
    Width = 66
    Height = 13
    Caption = 'Quote &Server:'
    FocusControl = edtQuoteDayServer
  end
  object lblQuote: TLabel
    Left = 8
    Top = 48
    Width = 32
    Height = 13
    Caption = 'Qu&ote:'
    FocusControl = mmoQuoteOfTheDay
  end
  object mmoQuoteOfTheDay: TMemo
    Left = 10
    Top = 64
    Width = 329
    Height = 94
    Anchors = [akLeft, akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object edtQuoteDayServer: TEdit
    Left = 96
    Top = 8
    Width = 153
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 1
  end
  object btnQuote: TButton
    Left = 264
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '&Quote'
    Default = True
    TabOrder = 2
    OnClick = btnQuoteClick
  end
  object IdQtdDemo: TIdQOTD
    RecvBufferSize = 1024
    Left = 80
    Top = 32
  end
end
