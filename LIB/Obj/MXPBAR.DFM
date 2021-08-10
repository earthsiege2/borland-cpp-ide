object ProgressDialog: TProgressDialog
  Left = 205
  Top = 105
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'ProgressDialog'
  ClientHeight = 116
  ClientWidth = 394
  ParentFont = True
  Position = poScreenCenter
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ProgressBar: TProgressBar
    Left = 8
    Top = 48
    Width = 377
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 160
    Top = 80
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelButtonClick
  end
  object StatusText: TStaticText
    Left = 8
    Top = 8
    Width = 55
    Height = 17
    Alignment = taCenter
    Caption = 'StatusText'
    TabOrder = 2
    Visible = False
  end
end
