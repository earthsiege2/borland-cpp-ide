object LogColSettingsFrame: TLogColSettingsFrame
  Left = 0
  Top = 0
  Width = 196
  Height = 205
  TabOrder = 0
  OnResize = FrameResize
  object lvColumns: TListView
    Left = 0
    Top = 0
    Width = 196
    Height = 205
    Align = alClient
    Checkboxes = True
    Columns = <
      item
      end>
    RowSelect = True
    ShowColumnHeaders = False
    TabOrder = 0
    ViewStyle = vsReport
  end
end
