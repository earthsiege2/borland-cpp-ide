object formMain: TformMain
  Left = 271
  Top = 118
  Width = 528
  Height = 255
  Caption = 'Zip Code Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 97
    Height = 228
    Align = alLeft
    TabOrder = 0
    object memoInput: TMemo
      Left = 1
      Top = 1
      Width = 95
      Height = 226
      Align = alClient
      Lines.Strings = (
        '37642'
        '16412'
        '72501')
      TabOrder = 0
    end
  end
  object Panel2: TPanel
    Left = 185
    Top = 0
    Width = 335
    Height = 228
    Align = alClient
    TabOrder = 1
    object lboxResults: TListBox
      Left = 1
      Top = 1
      Width = 333
      Height = 226
      Align = alClient
      ItemHeight = 13
      TabOrder = 0
    end
  end
  object Panel3: TPanel
    Left = 97
    Top = 0
    Width = 88
    Height = 228
    Align = alLeft
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 112
      Width = 73
      Height = 113
      AutoSize = False
      Caption = 
        'Enter Zip Codes one per line in the memo box to the left and the' +
        'n click Lookup.'
      WordWrap = True
    end
    object butnLookup: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Caption = '&Lookup'
      TabOrder = 0
      OnClick = butnLookupClick
    end
    object butnClear: TButton
      Left = 8
      Top = 40
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Clea&r'
      TabOrder = 1
      OnClick = butnClearClick
    end
  end
  object Client: TIdTCPClient
    RecvBufferSize = 8192
    Host = '127.0.0.1'
    Port = 6000
    Left = 209
    Top = 16
  end
  object IdAntiFreeze1: TIdAntiFreeze
    OnlyWhenIdle = False
    Left = 289
    Top = 16
  end
end
