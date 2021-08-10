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
  Left = 157
  Top = 259
  Height = 375
  Width = 544
  object DCOMConnection1: TDCOMConnection
    ServerGUID = '{C074BDB7-D037-11D3-A404-00C04F6BB853}'
    ServerName = 'rdmCustomerData_bcb.rdmCustomerData_bcb'
    Left = 48
    Top = 24
  end
  object Data: TMidasPageProducer
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
    OnHTMLTag = DataHTMLTag
    OnBeforeGetContent = DataBeforeGetContent
    Styles.Strings = (
      'H1 {color: green; font-style: italic; font-size: 20}'
      '.caption {font-weight: bold}')
    EnableXMLIslands = False
    Left = 16
    Top = 96
    object DataForm1: TDataForm
      object FieldGroup1: TFieldGroup
        XMLBroker = XMLBroker1
        object OrderNo: TFieldText
          DisplayWidth = 10
          Caption = 'OrderNo'
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'OrderNo'
        end
        object SaleDate: TFieldText
          DisplayWidth = 18
          Caption = 'SaleDate'
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'SaleDate'
        end
        object ShipDate: TFieldText
          DisplayWidth = 18
          Caption = 'ShipDate'
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'ShipDate'
        end
        object ItemsTotal: TFieldText
          DisplayWidth = 10
          Caption = 'ItemsTotal'
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'ItemsTotal'
        end
        object AmountPaid: TFieldText
          DisplayWidth = 10
          Caption = 'AmountPaid'
          CaptionAttributes.StyleRule = 'caption'
          FieldName = 'AmountPaid'
        end
      end
      object DataNavigator1: TDataNavigator
        XMLComponent = FieldGroup1
        Style = 'margin-bottom: 20'
      end
      object DataGrid1: TDataGrid
        XMLBroker = XMLBroker1
        XMLDataSetField = 'OrderItems'
        TableAttributes.BgColor = 'Silver'
        object OrderNo2: TTextColumn
          DisplayWidth = 10
          Caption = 'OrderNo'
          FieldName = 'OrderNo'
        end
        object ItemNo: TTextColumn
          DisplayWidth = 10
          Caption = 'ItemNo'
          FieldName = 'ItemNo'
        end
        object PartNo: TTextColumn
          DisplayWidth = 10
          Caption = 'PartNo'
          FieldName = 'PartNo'
        end
        object Qty: TTextColumn
          DisplayWidth = 10
          Caption = 'Qty'
          FieldName = 'Qty'
        end
        object Discount: TTextColumn
          DisplayWidth = 10
          Caption = 'Discount'
          FieldName = 'Discount'
        end
        object StatusColumn1: TStatusColumn
          Caption = '*'
        end
      end
      object DataNavigator2: TDataNavigator
        XMLComponent = DataGrid1
      end
    end
  end
  object CustList: TMidasPageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#STYLES><#CUSTOMERLIST>'
      '</BODY>'
      '</HTML>')
    OnHTMLTag = CustListHTMLTag
    Styles.Strings = (
      'A {font-size: 20}')
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
    ReconcileProducer = ReconcileError
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
  object ReconcileError: TMidasPageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#INCLUDES><#STYLES><#WARNINGS>'
      
        'One or more of your changes could not be applied.  Typical cause' +
        's of reconcile'
      
        'errors are key violations and  concurrent changes made by anothe' +
        'r user.'
      '<p>'
      '<A HREF='#39'<#HREFCUSTLIST>'#39'>Return to customer list</A>'
      '<p>'
      '<A HREF='#39'<#REDIRECT>'#39'>Return to customer data</A>'
      ''
      '<#FORMS><#SCRIPT>'
      '</BODY>'
      '</HTML>')
    OnHTMLTag = ReconcileErrorHTMLTag
    Left = 200
    Top = 184
  end
end
