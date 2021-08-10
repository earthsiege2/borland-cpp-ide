object fmMain: TfmMain
  Left = 234
  Top = 272
  Width = 655
  Height = 440
  Caption = 'WhoIs Lookup'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 36
    Height = 13
    HelpType = htKeyword
    Caption = 'Domain'
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 35
    Height = 13
    HelpType = htKeyword
    Caption = 'Results'
  end
  object btLookup: TSpeedButton
    Left = 544
    Top = 11
    Width = 23
    Height = 22
    HelpType = htKeyword
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333FFFFF3333333333F797F3333333333F737373FF333333BFB999BFB
      33333337737773773F3333BFBF797FBFB33333733337333373F33BFBFBFBFBFB
      FB3337F33333F33337F33FBFBFB9BFBFBF3337333337F333373FFBFBFBF97BFB
      FBF37F333337FF33337FBFBFBFB99FBFBFB37F3333377FF3337FFBFBFBFB99FB
      FBF37F33333377FF337FBFBF77BF799FBFB37F333FF3377F337FFBFB99FB799B
      FBF373F377F3377F33733FBF997F799FBF3337F377FFF77337F33BFBF99999FB
      FB33373F37777733373333BFBF999FBFB3333373FF77733F7333333BFBFBFBFB
      3333333773FFFF77333333333FBFBF3333333333377777333333}
    NumGlyphs = 2
    OnClick = btLookupClick
  end
  object edDomain: TEdit
    Left = 56
    Top = 12
    Width = 481
    Height = 21
    TabOrder = 0
    OnKeyPress = edDomainKeyPress
  end
  object meResults: TMemo
    Left = 6
    Top = 56
    Width = 641
    Height = 337
    TabOrder = 1
  end
  object IdWhois: TIdWhois
    ASCIIFilter = True
    Host = 'whois.internic.net'
    Left = 112
    Top = 120
  end
end
