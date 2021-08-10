object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      PathInfo = '/CustList'
      Producer = CustList
    end
    item
      Name = 'WebActionItem2'
      PathInfo = '/Data'
      Producer = Data
    end>
  Left = 311
  Top = 230
  Height = 375
  Width = 544
  object DCOMConnection1: TDCOMConnection
    ServerGUID = '{C074BDB7-D037-11D3-A404-00C04F6BB853}'
    ServerName = 'rdmCustomerData_bcb.rdmCustomerData_bcb'
    Left = 48
    Top = 24
  end
  object Data: TMidasPageProducer
    OnHTMLTag = DataHTMLTag
    OnBeforeGetContent = DataBeforeGetContent
    Styles.Strings = (
      'H1 {color: green; font-style: italic; font-size: 20}'
      '.caption {font-weight: bold}')
    EnableXMLIslands = False
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#INCLUDES><#STYLES>'
      
        '<A HREF='#39'<#HREFCUSTLIST>'#39' onclick='#39'return CheckData();'#39'>Return t' +
        'o customer list</A><BR>'
      '<#CUSTOMER>'
      '<#WARNINGS><#FORMS><#SCRIPT>'
      '</SCRIPT>'
      '</BODY>'
      '</HTML>')
    Left = 16
    Top = 96
    object DataForm1: TDataForm
      object FieldGroup1: TFieldGroup
        XMLBroker = XMLBroker1
        object OrderNo: TFieldText
          DisplayWidth = 10
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'OrderNo'
        end
        object SaleDate: TFieldText
          DisplayWidth = 18
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'SaleDate'
        end
        object ShipDate: TFieldText
          DisplayWidth = 18
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'ShipDate'
        end
        object ItemsTotal: TFieldText
          DisplayWidth = 10
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'ItemsTotal'
        end
        object AmountPaid: TFieldText
          DisplayWidth = 10
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'AmountPaid'
        end
      end
      object DataGrid1: TDataGrid
        XMLBroker = XMLBroker1
        XMLDataSetField = 'OrderItems'
        TableAttributes.BgColor = 'Silver'
        object OrderNo2: TTextColumn
          DisplayWidth = 10
          FieldName = 'OrderNo'
        end
        object ItemNo: TTextColumn
          DisplayWidth = 10
          FieldName = 'ItemNo'
        end
        object PartNo: TTextColumn
          DisplayWidth = 10
          FieldName = 'PartNo'
        end
        object Qty: TTextColumn
          DisplayWidth = 10
          FieldName = 'Qty'
        end
        object Discount: TTextColumn
          DisplayWidth = 10
          FieldName = 'Discount'
        end
        object StatusColumn1: TStatusColumn
          Caption = '*'
        end
      end
      object DataNavigator1: TDataNavigator
        XMLComponent = DataGrid1
      end
    end
  end
  object CustList: TMidasPageProducer
    OnHTMLTag = CustListHTMLTag
    Styles.Strings = (
      'A {font-size: 20}')
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#STYLES><#CUSTOMERLIST>'
      '</BODY>'
      '</HTML>')
    Left = 104
    Top = 96
  end
  object XMLBroker1: TXMLBroker
    Params = <
      item
        DataType = ftSmallint
        Name = 'CustNo'
        ParamType = ptUnknown
        Value = 1221
      end>
    ProviderName = 'CustOrders'
    RemoteServer = DCOMConnection1
    WebDispatch.PathInfo = 'XMLBroker1'
    OnRequestRecords = XMLBroker1RequestRecords
    Left = 152
    Top = 24
  end
  object CustNames: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'CustNames'
    RemoteServer = DCOMConnection1
    Left = 200
    Top = 96
  end
end
