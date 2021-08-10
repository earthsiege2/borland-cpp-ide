object frmMain: TfrmMain
  Left = 348
  Top = 204
  Width = 579
  Height = 357
  Caption = 'Briefcase Demo - C++ Builder'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pnlPanel: TPanel
    Left = 0
    Top = 0
    Width = 571
    Height = 41
    Align = alTop
    TabOrder = 0
    object btnUpdateButton: TButton
      Left = 166
      Top = 8
      Width = 85
      Height = 25
      Caption = 'Update Server'
      TabOrder = 0
      OnClick = btnUpdateButtonClick
    end
    object btnRefreshButton: TButton
      Left = 269
      Top = 8
      Width = 85
      Height = 25
      Caption = 'Refresh Button'
      TabOrder = 1
      OnClick = btnRefreshButtonClick
    end
    object btnSaveButton: TButton
      Left = 372
      Top = 8
      Width = 85
      Height = 25
      Caption = 'Save to disk'
      TabOrder = 2
      OnClick = btnSaveButtonClick
    end
    object ckbxConnectionInd: TCheckBox
      Left = 41
      Top = 13
      Width = 97
      Height = 17
      Caption = 'Connected'
      TabOrder = 3
      OnClick = ckbxConnectionIndClick
    end
  end
  object dbgrdDataDisplay: TDBGrid
    Left = 0
    Top = 41
    Width = 571
    Height = 289
    Align = alClient
    DataSource = dsEmpSource
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object adocnctnConnection: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 
      'E:\Program Files\Common Files\System\OLE DB\Data Links\DBDemos.U' +
      'DL'
    Left = 7
    Top = 6
  end
  object adodsEmployees: TADODataSet
    Connection = adocnctnConnection
    CursorType = ctStatic
    LockType = ltBatchOptimistic
    CommandText = 'employee'
    CommandType = cmdTable
    Parameters = <>
    Left = 24
    Top = 296
  end
  object dsEmpSource: TDataSource
    DataSet = adodsEmployees
    Left = 56
    Top = 296
  end
end
