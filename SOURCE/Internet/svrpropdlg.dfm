object DlgProperties: TDlgProperties
  Left = 235
  Top = 110
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Options'
  ClientHeight = 379
  ClientWidth = 506
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  DesignSize = (
    506
    379)
  PixelsPerInch = 96
  TextHeight = 13
  object OkButton: TButton
    Left = 258
    Top = 350
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelButton: TButton
    Left = 340
    Top = 350
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object PageControl1: TPageControl
    Left = 9
    Top = 8
    Width = 488
    Height = 334
    ActivePage = TabConnection
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabIndex = 0
    TabOrder = 0
    object TabConnection: TTabSheet
      Caption = 'Connection'
      DesignSize = (
        480
        306)
      object GroupBox1: TGroupBox
        Left = 8
        Top = 3
        Width = 463
        Height = 292
        Anchors = [akLeft, akTop, akRight, akBottom]
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 17
          Width = 22
          Height = 13
          Caption = '&Port:'
          FocusControl = cbPort
        end
        object Label2: TLabel
          Left = 8
          Top = 78
          Width = 62
          Height = 13
          Caption = '&Search Path:'
          FocusControl = edPath
        end
        object Label3: TLabel
          Left = 8
          Top = 48
          Width = 62
          Height = 13
          Caption = '&Default URL:'
          FocusControl = edDefault
        end
        object cbPort: TComboBox
          Left = 88
          Top = 13
          Width = 65
          Height = 21
          ItemHeight = 13
          TabOrder = 0
          Text = 'cbPort'
          OnKeyPress = NumericKeyPress
        end
        object cbActiveAtStartup: TCheckBox
          Left = 185
          Top = 16
          Width = 144
          Height = 17
          Caption = '&Activate at Startup'
          TabOrder = 1
        end
        object edDefault: TEdit
          Left = 88
          Top = 45
          Width = 361
          Height = 21
          TabOrder = 2
          Text = 'edDefault'
        end
        object edPath: TEdit
          Left = 88
          Top = 75
          Width = 361
          Height = 21
          TabOrder = 3
          Text = 'edPath'
        end
      end
    end
    object TabLog: TTabSheet
      Caption = 'Log'
      ImageIndex = 1
      DesignSize = (
        480
        306)
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 464
        Height = 207
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = 'Show in Log'
        TabOrder = 0
        DesignSize = (
          464
          207)
        inline LogColSettingsFrame: TLogColSettingsFrame
          Left = 9
          Top = 24
          Width = 445
          Height = 167
          Anchors = [akLeft, akTop, akRight, akBottom]
          TabOrder = 0
          inherited lvColumns: TListView
            Width = 445
            Height = 167
          end
        end
      end
      object GroupBox6: TGroupBox
        Left = 8
        Top = 223
        Width = 465
        Height = 73
        Anchors = [akLeft]
        Caption = ' Log Size '
        TabOrder = 1
        DesignSize = (
          465
          73)
        object Label4: TLabel
          Left = 10
          Top = 21
          Width = 59
          Height = 13
          Anchors = [akLeft, akBottom]
          Caption = 'Max Events:'
        end
        object Label5: TLabel
          Left = 11
          Top = 45
          Width = 135
          Height = 13
          Anchors = [akLeft, akBottom]
          Caption = 'Delete when max exceeded:'
        end
        object edLogMax: TEdit
          Left = 88
          Top = 19
          Width = 41
          Height = 21
          Anchors = [akLeft, akBottom]
          TabOrder = 0
          Text = 'edLogMax'
          OnKeyPress = NumericKeyPress
        end
        object edLogDelete: TEdit
          Left = 168
          Top = 40
          Width = 41
          Height = 21
          Anchors = [akLeft, akBottom]
          TabOrder = 1
          OnKeyPress = NumericKeyPress
        end
      end
    end
  end
  object Button1: TButton
    Left = 422
    Top = 350
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 3
    OnClick = Button1Click
  end
end
