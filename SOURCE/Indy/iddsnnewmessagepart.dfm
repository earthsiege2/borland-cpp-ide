object frmNewMessagePart: TfrmNewMessagePart
  Left = 384
  Top = 249
  BorderStyle = bsDialog
  Caption = 'New Message Part'
  ClientHeight = 141
  ClientWidth = 224
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 104
    Width = 224
    Height = 37
    Align = alBottom
    TabOrder = 0
    object btnOk: TButton
      Left = 64
      Top = 6
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Ok'
      Default = True
      Enabled = False
      ModalResult = 1
      TabOrder = 0
    end
    object btnCancel: TButton
      Left = 144
      Top = 6
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object lbTypes: TListBox
    Left = 0
    Top = 0
    Width = 224
    Height = 104
    Align = alClient
    ItemHeight = 13
    Items.Strings = (
      'Attachment'
      'Text')
    TabOrder = 1
    OnClick = lbTypesClick
    OnDblClick = lbTypesDblClick
  end
end
