object Form1: TForm1
  Left = 192
  Top = 107
  Width = 740
  Height = 440
  Caption = 'Biolife SOAP DataModule Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    732
    413)
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 16
    Width = 681
    Height = 321
    ActivePage = TabSheet1
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = '&Data'
      DesignSize = (
        673
        293)
      object DBGrid1: TDBGrid
        Left = 304
        Top = 12
        Width = 361
        Height = 237
        Anchors = [akLeft, akTop, akRight, akBottom]
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object DBImage1: TDBImage
        Left = 10
        Top = 12
        Width = 281
        Height = 237
        Anchors = [akLeft, akTop, akBottom]
        DataField = 'Graphic'
        DataSource = DataSource1
        TabOrder = 1
      end
      object DBNavigator1: TDBNavigator
        Left = 192
        Top = 260
        Width = 240
        Height = 25
        DataSource = DataSource1
        Anchors = [akLeft, akBottom]
        TabOrder = 2
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'SOAP Packets'
      ImageIndex = 1
      DesignSize = (
        673
        293)
      object Memo1: TMemo
        Left = 5
        Top = 4
        Width = 308
        Height = 285
        Anchors = [akLeft, akTop, akBottom]
        TabOrder = 0
      end
      object Memo2: TMemo
        Left = 328
        Top = 4
        Width = 341
        Height = 285
        Anchors = [akLeft, akTop, akRight, akBottom]
        TabOrder = 1
      end
    end
  end
  object Panel1: TPanel
    Left = 16
    Top = 350
    Width = 681
    Height = 41
    Anchors = [akLeft, akRight, akBottom]
    BevelOuter = bvLowered
    TabOrder = 1
    object CheckBox1: TCheckBox
      Left = 9
      Top = 13
      Width = 97
      Height = 17
      Caption = '&Connect'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
  end
  object SoapConnection1: TSoapConnection
    Agent = 'Borland SOAP 1.1'
    Connected = True
    URL = 'http://localhost/scripts/BiolifeSOAPCGI.exe/soap'
    UseSOAPAdapter = True
    OnAfterExecute = SoapConnection1AfterExecute
    OnBeforeExecute = SoapConnection1BeforeExecute
    Left = 640
    Top = 400
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    RemoteServer = SoapConnection1
    Left = 608
    Top = 400
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 672
    Top = 400
  end
end
