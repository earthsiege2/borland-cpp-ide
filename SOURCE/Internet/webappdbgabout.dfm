object AboutBox: TAboutBox
  Left = 343
  Top = 112
  BorderStyle = bsDialog
  Caption = 'About Web App Debugger'
  ClientHeight = 202
  ClientWidth = 275
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 21
    Top = 121
    Width = 241
    Height = 3
    HelpType = htKeyword
    Shape = bsBottomLine
  end
  object Label3: TLabel
    Left = 21
    Top = 146
    Width = 145
    Height = 13
    HelpType = htKeyword
    Caption = 'Memory Available to Windows:'
  end
  object PhysMem: TLabel
    Left = 253
    Top = 146
    Width = 6
    Height = 13
    HelpType = htKeyword
    Alignment = taRightJustify
    Caption = '0'
  end
  object OS: TLabel
    Left = 21
    Top = 129
    Width = 240
    Height = 13
    HelpType = htKeyword
    AutoSize = False
    Caption = 'OS'
  end
  object OKButton: TButton
    Left = 187
    Top = 172
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object DetailsPanel: TPanel
    Left = 20
    Top = 8
    Width = 241
    Height = 100
    BevelOuter = bvNone
    TabOrder = 1
    object Painter: TPaintBox
      Left = 0
      Top = 0
      Width = 241
      Height = 100
      HelpType = htKeyword
    end
    object Copyright: TLabel
      Left = 9
      Top = 67
      Width = 113
      Height = 13
      HelpType = htKeyword
      Caption = 'Copyright '#169' 1983, 2001'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Version: TLabel
      Left = 9
      Top = 52
      Width = 53
      Height = 13
      HelpType = htKeyword
      Caption = 'Version 6.0'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SKUName: TLabel
      Left = 9
      Top = 34
      Width = 188
      Height = 16
      HelpType = htKeyword
      Caption = 'Web Application Debugger'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Logo: TImage
      Left = 7
      Top = 2
      Width = 130
      Height = 29
      HelpType = htKeyword
      Picture.Data = {
        07544269746D6170A6140000424DA61400000000000076000000280000008200
        00004C0000000100040000000000301400000000000000000000100000001000
        000000000000000080000080000000808000800000008000800080800000C0C0
        C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777770000007777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777700000077777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777000000777777777777777777777777777777777777
        7777777777777777777777777770000000007777777777777777777777777777
        7777777777777777777777777777770000007777777777777777777777777777
        7777777777777777777777777777777777700000000077777777777777777777
        7777777777777777777777777777777777777700000077777777777777777777
        7777777777777777777777777777777777777777777000000000777777777777
        7777777777777777777777777777777777777777777777000000777777777777
        7777777777777777777777777777777777777777777777777770000000007777
        7777777777777777777777777777777777777777777777777777770000007777
        7777777777777777777777777777777777777777777777777777777777700000
        0000778800007777777777777777777777777777777777777777777777777700
        0000777000000000000000008777777777777788000000008777777700000000
        0770000000007000000008777700000000077700000000077000000000777777
        7777770000007770000000000000000000077777777770000000000000877777
        0000000007700000000000000000007777000000000777000000000770000000
        0077777777777700000077700000000000000000000077777778000000000000
        0000777700000000077000000000000000000007770000000007770000000007
        7000000000777777777777000000777000000000000000000000077777700000
        0000000000008777000000000770000000000000000000087700000000077700
        0000000770000000007777777777770000007770000000000000000000000077
        7700000000000000000007770000000007700000000000000000000877000000
        0007770000000007700000000077777777777700000077700000000000000000
        0000008778000000000000000000087700000000077000000000000000000000
        7700000000077700000000077000000000777777777777000000777000000000
        7778000000000007780000000077700000000077000000000770000000000770
        0000000077000000000777000000000770000000007777777777770000007770
        0000000077777000000000077000000000777000000000770000000007700000
        0000777000000000770000000007770000000007700000000077777777777700
        0000777000000000777778000000000770000000007770000000007700000000
        0770000000007770000000007700000000077700000000077000000000777777
        7777770000007770000000007777770000000007700000000077700000000077
        0000000007700000000077700000000077000000000777000000000770000000
        0077777777777700000077700000000077777700000000077000000000777000
        0000007700000000077000000000777000000000770000000007770000000007
        7000000000777777777777000000777000000000777777000000000770000000
        0077777777777777000000000770000000007770000000007700000000077700
        0000000770000000007777777777770000007770000000007777770000000007
        7000000000777777777777770000000007700000000077700000000077000000
        0007770000000007700000000077777777777700000077700000000077777700
        0000000770000000007777777777777700000000077000000000777000000000
        7700000000077700000000077000000000777777777777000000777000000000
        7777770000000007700000000000000000000077000000000770000000007770
        0000000077000000000777000000000770000000007777777777770000007770
        0000000077777700000000077000000000000000000000770000000007700000
        0000777000000000770000000007770000000007700000000077777777777700
        0000777000000000777777000000000770000000000000000000007700000000
        0770000000007770000000007700000000077700000000077000000000777777
        7777770000007770000000007777770000000007700000000000000000000077
        0000000007700000000077700000000077000000000777000000000770000000
        0077777777777700000077700000000077777700000000077000000000000000
        0000007700000000077000000000777000000000770000000007770000000007
        7000000000777777777777000000777000000000777777000000000770000000
        0000000000000077000000000770000000007770000000007700000000077700
        0000000770000000007777777777770000007770000000007777770000000007
        7000000000777000000000770000000007700000000077700000000077000000
        0007770000000007700000000077777777777700000077700000000077777700
        0000000770000000007770000000007700000000077000000000777000000000
        7700000000077700000000077000000000777777777777000000777000000000
        7777770000000007700000000077700000000077000000000770000000007770
        0000000077000000000777000000000770000000007777777777770000007770
        0000000077777700000000077000000000777000000000770000000007700000
        0000777000000000770000000000700000000007700000000077777777777700
        0000777000000000777777000000000778000000007770000000087700000000
        0770000000000700000000007700000000000000000000077000000000777777
        7777770000007770000000007777770000000007780000000000000000000877
        0000000007700000000000000000000077000000000000000000000770000000
        0077777777777700000077700000000077777700000000077700000000000000
        0000077700000000077000000000000000000008770000000000000000000007
        7000000000777777777777000000777000000000777777000000000777700000
        0000000000007777000000000770000000000000000000087700000000000000
        0000008770000000007777777777770000007770000000007777770000000007
        7778000000000000000877770000000007700000000000000000000777000000
        0000000000000077700000000077777777777700000077700000000077777700
        0000000777777000000000000077777700000000077000000000000000000077
        7700000000000000000007777000000000777777777777000000777000000000
        7777780000000007777777800000000087777777000000000770000000007700
        0000877777000000000778000008777770000000007777777777770000007770
        0000000077777000000000077777777777777777777777770000000007777777
        7777777777777777770000000007777777777777777777777777777777777700
        0000777000000000777800000000000777777777777777777777777700000000
        0777777777777777777777777700000000077777777777777777777777777777
        7777770000007770000000000000000000000087777777777777777777777777
        0000000007777777777777777777777777000000000777777777777770000000
        0077777777777700000077700000000000000000000000777777777777777777
        7777777700000000077777777777777777777777770000000007777777777777
        7000000000777777777777000000777000000000000000000000087777777777
        7777777777777777000000000777777777777777777777777700000000077777
        7777777770000000007777777777770000007770000000000000000000000777
        7777777777777777777777770000000007777777777777777777777777000000
        0007777777777777700000000077777777777700000077700000000000000000
        0008777777777777777777777777777700000000077777777777777777777777
        7700000000077777777777777000000000777777777777000000777000000000
        0000000088777777777777777777777777777777000000000777777777777777
        7777777777000000000777777777777770000000007777777777770000007777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777700
        0000777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777770000007777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777700000077777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777000000777000000077777000077700077700077000
        7000700077000770007000777777777777777777777777777777777777777777
        7777777777777777777777777777770000007770000000077700000077000777
        0007000000007000770007000000007777777777777777777777777777777777
        7777777777777777777777777777777777777700000077700077700078007700
        8700077700070007700070007700070000000077777777777777777777777777
        7777777777777777777777777777777777777777777777000000777000777000
        7000770007000777000700077000700077000700077000777777777777777777
        7777777777777777777777777777777777777777777777777777770000007770
        0077700070007700070007770007000770007000770007000770007777777777
        7777777777777777777777777777777777777777777777777777777777777700
        0000777000777000700077000700077700078000700070007700070007700077
        7777777777777777777777777777777777777777777777777777777777777777
        7777770000007770007770007000770007000777000777000000700077000700
        0770007777777777777777777777777777777777777777777777777777777777
        7777777777777700000077700000000770007700070007770007777700007000
        7700070007700077777777777777777777777777777777777777777777777777
        7777777777777777777777000000777000000007700077000700000700070007
        7000700077000700077000777777777777777777777777777777777777777777
        7777777777777777777777777777770000007770007770007800770087000007
        0007000770007000000007000000007777777777777777777777777777777777
        7777777777777777777777777777777777777700000077700077700077000000
        7700000700078000000870000000870000000077777777777777777777777777
        7777777777777777777777777777777777777777777777000000777000777000
        7770000777000707000777000007700070007770008000777777777777777777
        7777777777777777777777777777777777777777777777777777770000007770
        0077700077777777777777770007777777777777777777777770007777777777
        7777777777777777777777777777777777777777777777777777777777777700
        0000777000000008777777777777777700077777777777777777777777700077
        7777777777777777777777777777777777777777777777777777777777777777
        7777770000007770000000877777777777777777000777777777777777777777
        7770007777777777777777777777777777777777777777777777777777777777
        7777777777777700000077777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777000000777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777770000007777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777700000077777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777000000777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777770000007777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777700
        0000777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777770000007777777777777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777700000077777777777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        7777777777777777777777000000777777777777777777777777777777777777
        7777777777777777777777777777777777777777777777777777777777777777
        777777777777777777777777777777000000}
      Transparent = True
    end
    object CompanyName: TLabel
      Left = 9
      Top = 82
      Width = 138
      Height = 13
      HelpType = htKeyword
      Caption = 'Borland Software Corporation'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
