object frmIBRestoreEditor: TfrmIBRestoreEditor
  Left = 225
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Restore Database Files'
  ClientHeight = 216
  ClientWidth = 269
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object sgDatabaseFiles: TStringGrid
    Left = 0
    Top = 0
    Width = 269
    Height = 180
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goEditing]
    TabOrder = 0
    OnDrawCell = sgDatabaseFilesDrawCell
    OnKeyDown = sgDatabaseFilesKeyDown
    OnSelectCell = sgDatabaseFilesSelectCell
    ColWidths = (
      181
      68)
  end
  object Panel1: TPanel
    Left = 0
    Top = 180
    Width = 269
    Height = 36
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object OKBtn: TButton
      Left = 24
      Top = 7
      Width = 75
      Height = 24
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelBtn: TButton
      Left = 105
      Top = 7
      Width = 74
      Height = 24
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
    object HelpBtn: TButton
      Left = 186
      Top = 7
      Width = 75
      Height = 24
      Caption = '&Help'
      TabOrder = 2
    end
  end
end
