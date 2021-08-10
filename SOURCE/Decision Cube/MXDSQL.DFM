object SQLWindow: TSQLWindow
  Left = 221
  Top = 108
  Width = 517
  Height = 319
  Caption = 'Form2'
  ParentFont = True
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 509
    Height = 215
    Align = alTop
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Default'
    TitleFont.Style = []
  end
  object Memo1: TMemo
    Left = 0
    Top = 215
    Width = 509
    Height = 77
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Query1: TQuery
    Left = 32
    Top = 80
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 72
    Top = 80
  end
end
