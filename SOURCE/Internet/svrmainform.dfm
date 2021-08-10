object WebAppDbgMainForm: TWebAppDbgMainForm
  Left = 739
  Top = 540
  Width = 473
  Height = 379
  Action = MainUpdateAction
  Caption = 'MainUpdateAction'
  Color = clBtnFace
  ParentFont = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClick = MainUpdateActionExecute
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  DesignSize = (
    465
    333)
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 100
    Top = 21
    Width = 62
    Height = 13
    HelpType = htKeyword
    Caption = 'Default URL:'
  end
  object Home: TLabel
    Left = 167
    Top = 20
    Width = 28
    Height = 13
    HelpType = htKeyword
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Home'
    OnClick = HomeClick
  end
  object Label1: TLabel
    Left = 101
    Top = 0
    Width = 22
    Height = 13
    HelpType = htKeyword
    Caption = 'Port:'
  end
  object Port: TLabel
    Left = 168
    Top = 0
    Width = 289
    Height = 13
    HelpType = htKeyword
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
    Caption = 'Port'
  end
  object pbToggle: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Action = ToggleServerAction
    TabOrder = 0
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 40
    Width = 453
    Height = 284
    ActivePage = TabSheet2
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabIndex = 0
    TabOrder = 1
    object TabSheet2: TTabSheet
      Caption = 'Statistics'
      ImageIndex = 1
      inline StatsFrame: TStatsFrame
        Left = 5
        Top = 3
        Width = 438
        Height = 169
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 0
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Log'
      DesignSize = (
        445
        256)
      object GroupBox1: TGroupBox
        Left = 5
        Top = 0
        Width = 434
        Height = 248
        Anchors = [akLeft, akTop, akRight, akBottom]
        TabOrder = 0
        DesignSize = (
          434
          248)
        inline LogFrame: TLogFrame
          Left = 10
          Top = 38
          Width = 413
          Height = 201
          Anchors = [akLeft, akTop, akRight, akBottom]
          TabOrder = 0
          inherited lvLog: TListView
            Width = 413
            Height = 201
          end
        end
        object CheckBox1: TCheckBox
          Left = 12
          Top = 14
          Width = 97
          Height = 17
          Action = ToggleLogAction
          Caption = '&Log To List'
          TabOrder = 1
        end
      end
    end
  end
  object ActionList1: TActionList
    Left = 208
    Top = 32
    object ToggleServerAction: TAction
      Caption = 'Toggle'
      OnExecute = ToggleServerActionExecute
      OnUpdate = ToggleServerActionUpdate
    end
    object ExitAction: TAction
      Caption = 'E&xit'
      OnExecute = ExitActionExecute
    end
    object StopAction: TAction
      Caption = 'S&top Server'
      OnExecute = StopActionExecute
      OnUpdate = StopActionUpdate
    end
    object StartAction: TAction
      Caption = '&Start Server'
      OnExecute = StartActionExecute
      OnUpdate = StartActionUpdate
    end
    object AboutAction: TAction
      Caption = '&About...'
      OnExecute = AboutActionExecute
    end
    object PropertiesAction: TAction
      Caption = '&Options...'
      OnExecute = PropertiesActionExecute
    end
    object BrowseAction: TAction
      Caption = 'BrowseAction'
    end
    object MainUpdateAction: TAction
      Caption = 'MainUpdateAction'
      OnExecute = MainUpdateActionExecute
      OnUpdate = MainUpdateActionUpdate
    end
    object ClearAction: TAction
      Caption = '&Clear'
    end
    object ToggleLogAction: TAction
      Caption = '&Log Traffic'
      OnExecute = ToggleLogActionExecute
      OnUpdate = ToggleLogActionUpdate
    end
  end
  object MainMenu1: TMainMenu
    Left = 208
    Top = 64
    object PropertiesItem: TMenuItem
      Caption = '&Server'
      object StartServer1: TMenuItem
        Action = StartAction
      end
      object StopServer1: TMenuItem
        Action = StopAction
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Properties1: TMenuItem
        Action = PropertiesAction
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Action = ExitAction
      end
    end
    object Help1: TMenuItem
      Caption = '&Help'
      object About1: TMenuItem
        Action = AboutAction
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 248
    Top = 64
    object StopServer2: TMenuItem
      Action = StopAction
    end
    object StartServer2: TMenuItem
      Action = StartAction
    end
    object Properties2: TMenuItem
      Action = PropertiesAction
    end
    object Exit2: TMenuItem
      Action = ExitAction
    end
  end
end
