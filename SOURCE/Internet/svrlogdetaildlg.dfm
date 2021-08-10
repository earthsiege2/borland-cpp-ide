object LogDetail: TLogDetail
  Left = 247
  Top = 119
  Width = 360
  Height = 442
  HelpContext = 4314
  BorderIcons = [biSystemMenu]
  Caption = 'LogDetail'
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Scaled = False
  OnShow = FormShow
  DesignSize = (
    352
    413)
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 107
    Top = 385
    Width = 75
    Height = 25
    Action = PrevAction
    Anchors = [akRight, akBottom]
    TabOrder = 0
  end
  object Button2: TButton
    Left = 190
    Top = 385
    Width = 75
    Height = 25
    Action = NextAction
    Anchors = [akRight, akBottom]
    TabOrder = 1
  end
  object Button3: TButton
    Left = 273
    Top = 385
    Width = 75
    Height = 25
    Action = CloseAction
    Anchors = [akRight, akBottom]
    TabOrder = 2
  end
  inline LogDetailFrame: TLogDetailFrame
    Left = 7
    Top = 8
    Width = 339
    Height = 370
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 3
    inherited Memo1: TMemo
      Left = 0
      Width = 339
      Height = 346
    end
    inherited cbTranslateText: TCheckBox
      Top = 351
      Caption = '&Translate Post'
    end
    inherited cbWrapText: TCheckBox
      Top = 351
    end
  end
  object ActionList1: TActionList
    Left = 240
    Top = 288
    object PrevAction: TAction
      Caption = '&Previous'
      OnExecute = PrevActionExecute
      OnUpdate = PrevActionUpdate
    end
    object NextAction: TAction
      Caption = '&Next'
      OnExecute = NextActionExecute
      OnUpdate = NextActionUpdate
    end
    object CloseAction: TAction
      Caption = '&Close'
      OnExecute = CloseActionExecute
    end
  end
end
