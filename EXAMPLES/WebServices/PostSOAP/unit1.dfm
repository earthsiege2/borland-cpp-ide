object Form1: TForm1
  Left = 266
  Top = 100
  Width = 736
  Height = 616
  Caption = 'SOAP - PostTool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 287
    Width = 728
    Height = 3
    Cursor = crVSplit
    Align = alBottom
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 85
    Width = 728
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object PanelTop: TPanel
    Left = 0
    Top = 0
    Width = 728
    Height = 85
    Align = alTop
    TabOrder = 0
    DesignSize = (
      728
      85)
    object Label1: TLabel
      Left = 36
      Top = 23
      Width = 22
      Height = 13
      Caption = '&URL'
      FocusControl = URL
    end
    object Label2: TLabel
      Left = 10
      Top = 56
      Width = 62
      Height = 13
      Caption = 'SOAP &Action'
      FocusControl = SOAPAction
    end
    object PostBtn: TButton
      Left = 613
      Top = 25
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = '&Post'
      TabOrder = 0
      OnClick = PostBtnClick
    end
    object URL: TEdit
      Left = 78
      Top = 23
      Width = 492
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 1
    end
    object SOAPAction: TEdit
      Left = 78
      Top = 52
      Width = 492
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 2
    end
  end
  object PanelMid: TPanel
    Left = 0
    Top = 88
    Width = 728
    Height = 199
    Align = alClient
    TabOrder = 1
    DesignSize = (
      728
      199)
    object Label3: TLabel
      Left = 23
      Top = 13
      Width = 40
      Height = 13
      Caption = '&Request'
      FocusControl = Request
    end
    object Request: TMemo
      Left = 23
      Top = 29
      Width = 678
      Height = 156
      Anchors = [akLeft, akTop, akRight, akBottom]
      TabOrder = 0
    end
  end
  object PanelBottom: TPanel
    Left = 0
    Top = 290
    Width = 728
    Height = 280
    Align = alBottom
    TabOrder = 2
    DesignSize = (
      728
      280)
    object Label4: TLabel
      Left = 23
      Top = 10
      Width = 48
      Height = 13
      Caption = 'Re&sponse'
      FocusControl = Response
    end
    object Response: TMemo
      Left = 23
      Top = 26
      Width = 682
      Height = 241
      Anchors = [akLeft, akTop, akRight, akBottom]
      TabOrder = 0
    end
  end
  object MainMenu1: TMainMenu
    Left = 576
    Top = 8
    object File: TMenuItem
      Caption = '&File'
      object FileNew: TMenuItem
        Caption = '&New'
        OnClick = FileNewClick
      end
      object FileOpen: TMenuItem
        Caption = '&Open...'
        OnClick = FileOpenClick
      end
      object FileSave: TMenuItem
        Caption = '&Save...'
        OnClick = FileSaveClick
      end
      object FileExit: TMenuItem
        Caption = '&Exit'
        OnClick = FileExitClick
      end
    end
  end
  object HTTPReqResp1: THTTPReqResp
    Agent = 'Borland SOAP 1.1'
    UseUTF8InHeader = False
    InvokeOptions = [soIgnoreInvalidCerts]
    Left = 608
    Top = 8
  end
  object OpenDialog1: TOpenDialog
    Left = 640
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Left = 672
    Top = 8
  end
end