object Form1: TForm1
  Left = 341
  Top = 134
  Width = 354
  Height = 264
  Caption = 'Proxy Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 346
    Height = 237
    Align = alClient
    Lines.Strings = (
      
        'This is a simple proxy demo, which uses the Mapped Port componen' +
        't. '
      ''
      
        'To see a demonstration of this example, you will need to be onli' +
        'ne and '
      'have a direct connection to the Internet.'
      ''
      'Run this demo and then launch a browser. Then open this URL with'
      'your browser:'
      'http://127.0.0.1:81/'
      ''
      
        'It will then show you the Borland website. The mapped port compo' +
        'nent'
      'in this demo maps incoming connections on port 81 to '
      'www.borland.com'
      'on port 80 (The web port)')
    TabOrder = 0
  end
  object IdMappedPortTCP1: TIdMappedPortTCP
    Active = True
    Bindings = <
      item
        Port = 81
      end>
    DefaultPort = 81
    MappedHost = 'www.borland.com'
    MappedPort = 80
    Left = 136
    Top = 176
  end
end
