object DimEditor: TDimEditor
  Left = 62
  Top = 611
  BorderStyle = bsSizeToolWin
  AutoScroll = False
  Caption = 'Form1.Table1'
  ClientHeight = 188
  ClientWidth = 140
  ParentFont = True
  PixelsPerInch = 96
  TextHeight = 13
  object DimListBox1: TListBox
    Left = 0
    Top = 0
    Width = 140
    Height = 188
    Align = alClient
    DragMode = dmAutomatic
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 0
    OnClick = DimListBox1Click
  end
end
