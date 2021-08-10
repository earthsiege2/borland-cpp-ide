object LogFrame: TLogFrame
  Left = 0
  Top = 0
  Width = 343
  Height = 155
  TabOrder = 0
  object lvLog: TListView
    Left = 0
    Top = 0
    Width = 343
    Height = 155
    Align = alClient
    Columns = <>
    FullDrag = True
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    PopupMenu = PopupMenu2
    TabOrder = 0
    ViewStyle = vsReport
    OnColumnClick = lvLogColumnClick
    OnColumnDragged = lvLogColumnDragged
    OnCompare = lvLogCompare
    OnDblClick = lvLogDblClick
  end
  object PopupMenu2: TPopupMenu
    Left = 204
    Top = 77
    object Clear1: TMenuItem
      Action = ClearAction
    end
    object DetailAction1: TMenuItem
      Action = DetailAction
    end
  end
  object ActionList1: TActionList
    Left = 200
    Top = 40
    object ClearAction: TAction
      Caption = '&Clear'
      OnExecute = ClearActionExecute
      OnUpdate = ClearActionUpdate
    end
    object DetailAction: TAction
      Caption = '&Details...'
      OnExecute = DetailActionExecute
    end
  end
end
