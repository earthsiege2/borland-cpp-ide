object frmIBSecurityEditor: TfrmIBSecurityEditor
  Left = 225
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Service Editor'
  ClientHeight = 259
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 334
    Height = 81
    Align = alTop
    Caption = 'Connection'
    TabOrder = 0
    object Label7: TLabel
      Left = 24
      Top = 33
      Width = 34
      Height = 13
      Caption = '&Server:'
      Enabled = False
      FocusControl = ServerName
    end
    object Label8: TLabel
      Left = 137
      Top = 33
      Width = 42
      Height = 13
      Caption = '&Protocol:'
      Enabled = False
      FocusControl = Protocol
    end
    object LocalRbtn: TRadioButton
      Left = 24
      Top = 15
      Width = 48
      Height = 17
      Caption = '&Local'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = LocalRbtnClick
    end
    object RemoteRbtn: TRadioButton
      Left = 89
      Top = 15
      Width = 56
      Height = 17
      Caption = '&Remote'
      TabOrder = 1
      OnClick = RemoteRbtnClick
    end
    object ServerName: TEdit
      Left = 24
      Top = 46
      Width = 94
      Height = 21
      Enabled = False
      TabOrder = 2
    end
    object Protocol: TComboBox
      Left = 136
      Top = 46
      Width = 93
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      TabOrder = 3
      Items.Strings = (
        'TCP'
        'NamedPipe'
        'SPX')
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 223
    Width = 334
    Height = 36
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object OKBtn: TButton
      Left = 88
      Top = 7
      Width = 75
      Height = 24
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelBtn: TButton
      Left = 169
      Top = 7
      Width = 74
      Height = 24
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
    object HelpBtn: TButton
      Left = 250
      Top = 7
      Width = 75
      Height = 24
      Caption = '&Help'
      TabOrder = 2
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 81
    Width = 334
    Height = 142
    Align = alClient
    Caption = 'Database Parameters'
    TabOrder = 1
    object Label2: TLabel
      Left = 24
      Top = 18
      Width = 56
      Height = 13
      Caption = '&User Name:'
      FocusControl = UserName
    end
    object Label3: TLabel
      Left = 24
      Top = 53
      Width = 49
      Height = 13
      Caption = 'Pass&word:'
      FocusControl = Password
    end
    object Label5: TLabel
      Left = 136
      Top = 19
      Width = 41
      Height = 13
      Caption = 'Se&ttings:'
      FocusControl = ServiceParams
    end
    object UserName: TEdit
      Left = 24
      Top = 32
      Width = 94
      Height = 21
      TabOrder = 0
      OnChange = UserNameChange
      OnExit = UserNameChange
    end
    object Password: TEdit
      Left = 24
      Top = 67
      Width = 94
      Height = 21
      TabOrder = 1
      OnChange = PasswordChange
      OnExit = PasswordChange
    end
    object ServiceParams: TMemo
      Left = 136
      Top = 33
      Width = 183
      Height = 96
      TabOrder = 4
    end
    object LoginPrompt: TCheckBox
      Left = 24
      Top = 116
      Width = 100
      Height = 14
      Caption = 'Lo&gin Prompt'
      TabOrder = 3
    end
    object chkActive: TCheckBox
      Left = 24
      Top = 92
      Width = 100
      Height = 14
      Caption = '&Active'
      TabOrder = 2
    end
  end
end
