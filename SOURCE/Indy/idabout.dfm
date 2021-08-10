object formAbout: TformAbout
  Left = 157
  Top = 42
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'formAbout'
  ClientHeight = 453
  ClientWidth = 625
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 412
    Width = 625
    Height = 41
    Align = alBottom
    TabOrder = 0
    object lblPleaseVisitUs: TLabel
      Left = 8
      Top = 4
      Width = 494
      Height = 17
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object lblURL: TLabel
      Left = 8
      Top = 20
      Width = 494
      Height = 13
      Cursor = crHandPoint
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      Transparent = True
      OnClick = lblURLClick
    end
    object btnOk: TButton
      Left = 539
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
  end
  object Panel2: TPanel
    Left = 420
    Top = 0
    Width = 205
    Height = 412
    Align = alRight
    TabOrder = 1
    object bvlDialogBorder: TBevel
      Left = 1
      Top = 1
      Width = 203
      Height = 410
      Align = alClient
      Style = bsRaised
    end
    object lblCopyright: TLabel
      Left = 6
      Top = 80
      Width = 193
      Height = 65
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Transparent = True
      WordWrap = True
    end
    object lblVersion: TLabel
      Left = 6
      Top = 56
      Width = 193
      Height = 26
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object lblName: TLabel
      Left = 6
      Top = 16
      Width = 193
      Height = 49
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
  end
  object tmrScroll: TTimer
    Enabled = False
    Interval = 25
    OnTimer = tmrScrollTimer
    Left = 400
    Top = 296
  end
end
