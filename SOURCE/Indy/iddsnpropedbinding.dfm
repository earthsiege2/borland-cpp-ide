object IdPropEdBindingEntry: TIdPropEdBindingEntry
  Left = 188
  Top = 125
  AutoScroll = False
  Caption = 'Binding Editor'
  ClientHeight = 230
  ClientWidth = 410
  Color = clBtnFace
  Constraints.MinHeight = 257
  Constraints.MinWidth = 418
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 40
    Height = 13
    Caption = 'Bindings'
  end
  object Label2: TLabel
    Left = 247
    Top = 8
    Width = 51
    Height = 13
    Caption = 'IP Address'
  end
  object Label3: TLabel
    Left = 247
    Top = 56
    Width = 19
    Height = 13
    Caption = 'Port'
  end
  object btnOk: TButton
    Left = 249
    Top = 201
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object btnCancel: TButton
    Left = 331
    Top = 201
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object lstBindings: TListBox
    Left = 8
    Top = 24
    Width = 149
    Height = 169
    Anchors = [akLeft, akTop, akBottom]
    ItemHeight = 13
    TabOrder = 2
    OnClick = lstBindingsClick
  end
  object btnAdd: TButton
    Left = 164
    Top = 32
    Width = 71
    Height = 25
    Action = actAdd
    TabOrder = 3
  end
  object btnRemove: TButton
    Left = 164
    Top = 64
    Width = 71
    Height = 25
    Action = actRemove
    TabOrder = 4
  end
  object cmbPort: TComboBox
    Left = 245
    Top = 72
    Width = 161
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    TabOrder = 5
    OnKeyPress = cmbPortKeyPress
  end
  object cmbHostname: TComboBox
    Left = 245
    Top = 24
    Width = 161
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    TabOrder = 6
    OnKeyPress = cmbHostnameKeyPress
  end
  object actBndEditor: TActionList
    Left = 200
    Top = 112
    object actAdd: TAction
      Caption = '&Add'
      OnExecute = actAddExecute
      OnUpdate = actAddUpdate
    end
    object actRemove: TAction
      Caption = '&Remove'
      OnExecute = actRemoveExecute
      OnUpdate = actRemoveUpdate
    end
  end
end
