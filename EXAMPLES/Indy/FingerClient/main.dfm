object frmFingerDemo: TfrmFingerDemo
  Left = 270
  Top = 150
  Width = 425
  Height = 280
  Caption = 'Finger Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    417
    253)
  PixelsPerInch = 96
  TextHeight = 13
  object lblQuerry: TLabel
    Left = 56
    Top = 56
    Width = 31
    Height = 13
    HelpType = htKeyword
    Caption = '&Query:'
    FocusControl = edtQuerry
  end
  object lblInstructions: TLabel
    Left = 16
    Top = 8
    Width = 385
    Height = 33
    HelpType = htKeyword
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
    Caption = 
      'Please enter your Finger query in the form query@host.  For exam' +
      'ple, sample@host.example.com   To list all users in this example' +
      ', send a blank query.'
    WordWrap = True
  end
  object edtQuerry: TEdit
    Left = 104
    Top = 52
    Width = 289
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
  end
  object mmoQuerryResults: TMemo
    Left = 16
    Top = 136
    Width = 385
    Height = 97
    Anchors = [akLeft, akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object chkVerboseQuerry: TCheckBox
    Left = 104
    Top = 80
    Width = 257
    Height = 17
    Caption = '&Verbose Query (not supported on most systems)'
    TabOrder = 2
  end
  object bbtnQuerry: TBitBtn
    Left = 104
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Finger'
    Default = True
    TabOrder = 3
    OnClick = bbtnQuerryClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000130B0000130B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333333333333FF3FF3333333333CC30003333333333773777333333333C33
      3000333FF33337F33777339933333C3333333377F33337F3333F339933333C33
      33003377333337F33377333333333C333300333F333337F33377339333333C33
      3333337FF3333733333F33993333C33333003377FF33733333773339933C3333
      330033377FF73F33337733339933C33333333FF377F373F3333F993399333C33
      330077F377F337F33377993399333C33330077FF773337F33377399993333C33
      33333777733337F333FF333333333C33300033333333373FF7773333333333CC
      3000333333333377377733333333333333333333333333333333}
    NumGlyphs = 2
  end
  object IdFngFinger: TIdFinger
    RecvBufferSize = 1024
    CompleteQuery = '@'
    Left = 192
    Top = 176
  end
end
