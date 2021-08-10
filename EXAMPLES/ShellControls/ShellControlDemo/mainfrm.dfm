object MainForm: TMainForm
  Left = 222
  Top = 129
  Width = 685
  Height = 493
  Caption = 'Simple File Browser'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pnlMain: TPanel
    Left = 0
    Top = 0
    Width = 677
    Height = 466
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 185
      Top = 30
      Width = 3
      Height = 436
      Cursor = crHSplit
    end
    object ShellListView1: TShellListView
      Left = 188
      Top = 30
      Width = 489
      Height = 436
      AutoRefresh = True
      ObjectTypes = [otFolders, otNonFolders]
      Root = 'rfDesktop'
      ShellTreeView = ShellTreeView1
      ShellComboBox = ShellComboBox1
      Sorted = True
      Align = alClient
      HideSelection = False
      ParentColor = False
      TabOrder = 0
      TabStop = True
    end
    object pnlLeft: TPanel
      Left = 0
      Top = 30
      Width = 185
      Height = 436
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
      DesignSize = (
        185
        436)
      object ShellComboBox1: TShellComboBox
        Left = 0
        Top = 1
        Width = 185
        Height = 22
        Root = 'rfDesktop'
        ShellTreeView = ShellTreeView1
        ShellListView = ShellListView1
        UseShellImages = True
        Anchors = [akLeft, akTop, akRight]
        DropDownCount = 8
        TabOrder = 0
      end
      object ShellTreeView1: TShellTreeView
        Left = 0
        Top = 26
        Width = 185
        Height = 410
        ObjectTypes = [otFolders]
        Root = 'rfDesktop'
        ShellComboBox = ShellComboBox1
        ShellListView = ShellListView1
        UseShellImages = True
        Align = alBottom
        Anchors = [akLeft, akTop, akRight, akBottom]
        AutoRefresh = True
        Indent = 19
        ParentColor = False
        RightClickSelect = True
        ShowRoot = False
        TabOrder = 1
        TabStop = True
      end
    end
    object CoolBar1: TCoolBar
      Left = 0
      Top = 0
      Width = 677
      Height = 30
      Bands = <>
      object SpeedButton1: TSpeedButton
        Left = 2
        Top = 2
        Width = 44
        Height = 22
        Action = actnBack
        Flat = True
      end
      object SpeedButton2: TSpeedButton
        Left = 46
        Top = 2
        Width = 44
        Height = 22
        Action = actnRefresh
        Flat = True
      end
      object SpeedButton3: TSpeedButton
        Left = 90
        Top = 2
        Width = 44
        Height = 22
        Action = actnIcon
        GroupIndex = 1
        Flat = True
      end
      object SpeedButton4: TSpeedButton
        Left = 134
        Top = 2
        Width = 44
        Height = 22
        Action = actnList
        GroupIndex = 1
        Flat = True
      end
      object SpeedButton5: TSpeedButton
        Left = 178
        Top = 2
        Width = 44
        Height = 22
        Action = actnReport
        GroupIndex = 1
        Flat = True
      end
      object SpeedButton6: TSpeedButton
        Left = 222
        Top = 2
        Width = 64
        Height = 22
        Action = actnSmallIcon
        GroupIndex = 1
        Flat = True
      end
      object SpeedButton7: TSpeedButton
        Left = 286
        Top = 2
        Width = 44
        Height = 22
        Action = actnSorted
        GroupIndex = 1
        Flat = True
      end
    end
  end
  object ActionList1: TActionList
    Left = 424
    Top = 176
    object actnBack: TAction
      Caption = '&Back'
      ImageIndex = 0
      OnExecute = actnBackExecute
      OnUpdate = actnBackUpdate
    end
    object actnRefresh: TAction
      Caption = '&Refresh'
      OnExecute = actnRefreshExecute
    end
    object actnIcon: TAction
      Caption = 'Icon'
      GroupIndex = 1
      OnExecute = actnIconExecute
      OnUpdate = actnIconUpdate
    end
    object actnList: TAction
      Tag = 1
      Caption = 'List'
      GroupIndex = 1
      OnExecute = actnIconExecute
    end
    object actnReport: TAction
      Tag = 2
      Caption = 'Report'
      GroupIndex = 1
      OnExecute = actnIconExecute
    end
    object actnSmallIcon: TAction
      Tag = 3
      Caption = 'Small Icon'
      GroupIndex = 1
      OnExecute = actnIconExecute
    end
    object actnSorted: TAction
      AutoCheck = True
      Caption = 'Sorted'
      OnExecute = actnSortedExecute
      OnUpdate = actnSortedUpdate
    end
  end
end
