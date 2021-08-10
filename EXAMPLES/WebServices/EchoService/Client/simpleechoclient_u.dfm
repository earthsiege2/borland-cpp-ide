object Form1: TForm1
  Left = 307
  Top = 107
  Width = 457
  Height = 514
  Caption = 'Simple Echo Server Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 67
    Height = 13
    Caption = 'Server URL'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 105
    Top = 64
    Width = 61
    Height = 13
    Caption = 'Send Data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 272
    Top = 64
    Width = 79
    Height = 13
    Caption = 'Receive Data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 64
    Width = 44
    Height = 13
    Caption = 'Service'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 104
    Top = 262
    Width = 16
    Height = 13
    Caption = '[0]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 104
    Top = 286
    Width = 16
    Height = 13
    Caption = '[1]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 104
    Top = 310
    Width = 16
    Height = 13
    Caption = '[2]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 104
    Top = 334
    Width = 16
    Height = 13
    Caption = '[3]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 104
    Top = 360
    Width = 16
    Height = 13
    Caption = '[4]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 279
    Top = 262
    Width = 16
    Height = 13
    Caption = '[0]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 279
    Top = 286
    Width = 16
    Height = 13
    Caption = '[1]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 279
    Top = 310
    Width = 16
    Height = 13
    Caption = '[2]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label13: TLabel
    Left = 279
    Top = 334
    Width = 16
    Height = 13
    Caption = '[3]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label14: TLabel
    Left = 279
    Top = 360
    Width = 16
    Height = 13
    Caption = '[4]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label15: TLabel
    Left = 104
    Top = 392
    Width = 274
    Height = 52
    Caption = 
      'This will take the above  Send Data from { Integer, String. Bool' +
      'ean, Float} and put it in a Class and send that class to the ech' +
      'oServer. The return values will be put in the Receive Data field' +
      's for each type'
    WordWrap = True
  end
  object EditSendInteger: TEdit
    Left = 100
    Top = 90
    Width = 158
    Height = 21
    TabOrder = 0
    Text = '3276'
  end
  object ButtonEchoInteger: TButton
    Left = 5
    Top = 88
    Width = 90
    Height = 25
    Caption = 'echoInteger'
    TabOrder = 1
    OnClick = ButtonEchoIntegerClick
  end
  object CBServerURL: TComboBox
    Left = 81
    Top = 24
    Width = 352
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    Text = 'Select URL and Press SetRioURL'
    Items.Strings = (
      'http://localhost/scripts/CGI_SimpleEcho.exe/soap'
      'http://localhost/scripts/ISAPI_SimpleEcho.dll/soap')
  end
  object ButtonSetRioURL: TButton
    Left = 5
    Top = 23
    Width = 75
    Height = 25
    Caption = 'SetRioURL'
    TabOrder = 3
    OnClick = ButtonSetRioURLClick
  end
  object ButtonEchoString: TButton
    Left = 5
    Top = 112
    Width = 90
    Height = 25
    Caption = 'echoString'
    TabOrder = 4
    OnClick = ButtonEchoStringClick
  end
  object ButtonEchoBoolean: TButton
    Left = 5
    Top = 136
    Width = 90
    Height = 25
    Caption = 'echoBoolean'
    TabOrder = 5
    OnClick = ButtonEchoBooleanClick
  end
  object ButtonEchoFloat: TButton
    Left = 5
    Top = 160
    Width = 90
    Height = 25
    Caption = 'echoFloat'
    TabOrder = 6
    OnClick = ButtonEchoFloatClick
  end
  object ButtonEchoDate: TButton
    Left = 5
    Top = 184
    Width = 90
    Height = 25
    Caption = 'echoDate'
    TabOrder = 7
    OnClick = ButtonEchoDateClick
  end
  object ButtonEchoVoid: TButton
    Left = 5
    Top = 208
    Width = 90
    Height = 25
    Caption = 'echoVoid'
    TabOrder = 8
    OnClick = ButtonEchoVoidClick
  end
  object ButtonEchoHexBinary: TButton
    Left = 5
    Top = 232
    Width = 90
    Height = 25
    Caption = 'echoHexBin'
    TabOrder = 9
    OnClick = ButtonEchoHexBinaryClick
  end
  object EditSendString: TEdit
    Left = 100
    Top = 114
    Width = 158
    Height = 21
    TabOrder = 10
    Text = 'HangTen'
  end
  object EditSendBoolean: TEdit
    Left = 100
    Top = 138
    Width = 158
    Height = 21
    TabOrder = 11
    Text = 'True'
  end
  object EditSendFloat: TEdit
    Left = 100
    Top = 162
    Width = 158
    Height = 21
    TabOrder = 12
    Text = '7.99'
  end
  object EditSendDate: TEdit
    Left = 100
    Top = 186
    Width = 158
    Height = 21
    TabOrder = 13
    Text = '12/12/01'
  end
  object EditSendHexBinary: TEdit
    Left = 100
    Top = 234
    Width = 158
    Height = 21
    TabOrder = 14
    Text = 'FFFFFFFF'
  end
  object EditSendVoid: TEdit
    Left = 100
    Top = 209
    Width = 158
    Height = 21
    Enabled = False
    TabOrder = 15
    Text = 'void'
  end
  object EditRecvInteger: TEdit
    Left = 267
    Top = 90
    Width = 165
    Height = 21
    TabOrder = 16
  end
  object EditRecvString: TEdit
    Left = 267
    Top = 114
    Width = 165
    Height = 21
    TabOrder = 17
  end
  object EditRecvBoolean: TEdit
    Left = 267
    Top = 138
    Width = 165
    Height = 21
    TabOrder = 18
  end
  object EditRecvFloat: TEdit
    Left = 267
    Top = 162
    Width = 165
    Height = 21
    TabOrder = 19
  end
  object EditRecvDate: TEdit
    Left = 267
    Top = 186
    Width = 165
    Height = 21
    TabOrder = 20
  end
  object EditRecvHexBinary: TEdit
    Left = 267
    Top = 234
    Width = 165
    Height = 21
    TabOrder = 21
  end
  object EditRecvVoid: TEdit
    Left = 267
    Top = 209
    Width = 165
    Height = 21
    TabOrder = 22
  end
  object Button1: TButton
    Left = 5
    Top = 256
    Width = 90
    Height = 25
    BiDiMode = bdLeftToRight
    Caption = 'echoStringArray'
    ParentBiDiMode = False
    TabOrder = 23
    OnClick = Button1Click
  end
  object EditSendStringArray0: TEdit
    Left = 128
    Top = 259
    Width = 129
    Height = 21
    TabOrder = 24
    Text = 'element 0'
  end
  object EditSendStringArray1: TEdit
    Left = 128
    Top = 283
    Width = 129
    Height = 21
    TabOrder = 25
    Text = 'element 1'
  end
  object Edit3: TEdit
    Left = 128
    Top = 307
    Width = 129
    Height = 21
    TabOrder = 26
    Text = 'Edit1'
  end
  object EditSendStringArray2: TEdit
    Left = 128
    Top = 307
    Width = 129
    Height = 21
    TabOrder = 27
    Text = 'element 2'
  end
  object EditSendStringArray3: TEdit
    Left = 128
    Top = 331
    Width = 129
    Height = 21
    TabOrder = 28
    Text = 'element 3'
  end
  object EditSendStringArray4: TEdit
    Left = 128
    Top = 355
    Width = 129
    Height = 21
    TabOrder = 29
    Text = 'element 4'
  end
  object EditRecvStringArray0: TEdit
    Left = 303
    Top = 259
    Width = 129
    Height = 21
    TabOrder = 30
    Text = 'Edit1'
  end
  object EditRecvStringArray1: TEdit
    Left = 303
    Top = 283
    Width = 129
    Height = 21
    TabOrder = 31
    Text = 'Edit1'
  end
  object EditRecvStringArray2: TEdit
    Left = 303
    Top = 307
    Width = 129
    Height = 21
    TabOrder = 32
    Text = 'Edit1'
  end
  object EditRecvStringArray3: TEdit
    Left = 303
    Top = 331
    Width = 129
    Height = 21
    TabOrder = 33
    Text = 'Edit1'
  end
  object EditRecvStringArray4: TEdit
    Left = 303
    Top = 355
    Width = 129
    Height = 21
    TabOrder = 34
    Text = 'Edit1'
  end
  object ButtonEchoSimpleClass: TButton
    Left = 6
    Top = 384
    Width = 91
    Height = 25
    Caption = 'echoSimpleClass'
    TabOrder = 35
    OnClick = ButtonEchoSimpleClassClick
  end
  object HTTPRIO1: THTTPRIO
    URL = 'http://localhost/soap/CGI_SimpleEcho.exe/soap'
    HTTPWebNode.Agent = 'Borland SOAP 1.1'
    HTTPWebNode.UseUTF8InHeader = False
    HTTPWebNode.InvokeOptions = []
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soRootRefNodesToBody]
    Left = 416
  end
  object MainMenu1: TMainMenu
    Left = 384
    object File1: TMenuItem
      Caption = '&File'
      object Exit1: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit1Click
      end
    end
    object ClearValues1: TMenuItem
      Caption = '&ClearValues'
      object SendData1: TMenuItem
        Caption = 'Clear &SendData'
        OnClick = SendData1Click
      end
      object RecieveData1: TMenuItem
        Caption = 'Clear &ReceiveData'
        OnClick = RecieveData1Click
      end
    end
  end
end
