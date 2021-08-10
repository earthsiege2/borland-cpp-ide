object Form1: TForm1
  Left = 192
  Top = 107
  Width = 392
  Height = 312
  Caption = 'URI Parse Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblProtocol: TLabel
    Left = 74
    Top = 80
    Width = 39
    Height = 13
    Caption = '&Protocol'
  end
  object lblHost: TLabel
    Left = 91
    Top = 120
    Width = 22
    Height = 13
    Caption = '&Host'
  end
  object lblPort: TLabel
    Left = 94
    Top = 160
    Width = 19
    Height = 13
    Caption = 'P&ort'
  end
  object lblPath: TLabel
    Left = 91
    Top = 200
    Width = 22
    Height = 13
    Caption = 'P&ath'
  end
  object lblDocument: TLabel
    Left = 64
    Top = 240
    Width = 49
    Height = 13
    Caption = '&Document'
  end
  object lblURI: TLabel
    Left = 91
    Top = 40
    Width = 22
    Height = 13
    Caption = '&URL'
  end
  object lblInstructions: TLabel
    Left = 16
    Top = 8
    Width = 318
    Height = 13
    Caption = 
      'Enter the URL you wish to parse in the URL entry and click "Do I' +
      't".'
  end
  object edtURI: TEdit
    Left = 120
    Top = 40
    Width = 257
    Height = 21
    TabOrder = 0
  end
  object edtProtocol: TEdit
    Left = 120
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object edtHost: TEdit
    Left = 120
    Top = 120
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object edtPort: TEdit
    Left = 120
    Top = 160
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object edtPath: TEdit
    Left = 120
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object edtDocument: TEdit
    Left = 120
    Top = 240
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object btnDoIt: TButton
    Left = 280
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Do &It'
    TabOrder = 6
    OnClick = btnDoItClick
  end
end
