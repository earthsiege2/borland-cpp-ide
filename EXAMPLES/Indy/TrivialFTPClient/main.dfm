object frmMain: TfrmMain
  Left = 192
  Top = 107
  Width = 305
  Height = 238
  Caption = 'TFTP client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 99
    Height = 13
    Caption = 'TFTP server address'
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 82
    Height = 13
    Caption = 'Remote file name'
  end
  object Label3: TLabel
    Left = 8
    Top = 104
    Width = 71
    Height = 13
    Caption = 'Local file name'
  end
  object edtRemoteFile: TEdit
    Left = 8
    Top = 72
    Width = 283
    Height = 21
    TabOrder = 0
  end
  object btnUpload: TButton
    Left = 10
    Top = 168
    Width = 64
    Height = 25
    Caption = '&Upload'
    TabOrder = 1
    OnClick = btnUploadClick
  end
  object edtHost: TEdit
    Left = 8
    Top = 24
    Width = 145
    Height = 21
    TabOrder = 2
    Text = 'localhost'
  end
  object edtLocalFile: TEdit
    Left = 8
    Top = 120
    Width = 283
    Height = 21
    TabOrder = 3
  end
  object btnDownload: TButton
    Left = 82
    Top = 168
    Width = 64
    Height = 25
    Caption = '&Download'
    TabOrder = 4
    OnClick = btnDownloadClick
  end
  object TrivialFTP: TIdTrivialFTP
    BufferSize = 516
    Port = 69
    ReceiveTimeout = 4000
    Left = 200
    Top = 152
  end
end
