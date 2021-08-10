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
      object ImgDataNavigator1: TImgDataNavigator
        XMLComponent = FieldGroup1
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
      object ImgDataNavigator2: TImgDataNavigator
        XMLComponent = DataGrid1
      end
      object DataNavigator1: TDataNavigator
        XMLComponent = DataGrid1
        object ShowXMLButton1: TShowXMLButton
          XMLComponent = DataGrid1
          Caption = 'Show XML'
        end
        object ShowDeltaButton1: TShowDeltaButton
          XMLComponent = DataGrid1
          Caption = 'Show Delta'
        end
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
    ReconcileProducer = ReconcilePageProducer1
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
  object ReconcilePageProducer1: TReconcilePageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#INCLUDES><#STYLES><#WARNINGS>'
      '<P>'
      '<FORM name="FORM1">'
      '<TABLE>'
      '<TR>'
      '<TD valign=top><H3>Error message:</H3></TD>'
      
        '<TD valign=top><textarea name="ErrMessage" rows=2 cols=58 readon' +
        'ly onfocus='#39'blur();'#39'></textarea></TD>'
      '<TD valign=top><H3>on</H3></TD>'
      
        '<TD valign=top><input type=text name="ErrAction" size=12 readonl' +
        'y onfocus='#39'blur();'#39'/></TD>'
      '</TR>'
      '</TABLE>'
      '<P>'
      '<#RECONCILEGRID>'
      '</FORM>'
      '<P>'
      '<FORM>'
      '<H3> Reconcile Action </H3>'
      
        '<input type=radio name="action" value="Cancel" onclick='#39'if(self.' +
        'grid1!=null)grid1.cancel();'#39'/> Cancel'
      
        '<input type=radio name="action" value="Correct" onclick='#39'if(self' +
        '.grid1!=null)grid1.correct();'#39'/> Correct'
      
        '<input type=radio name="action" value="Merge" onclick='#39'if(self.g' +
        'rid1!=null)grid1.merge();'#39'/> Merge'
      '<P>'
      
        '<input type=button value="<" onclick='#39'if(self.grid1!=null)grid1.' +
        'up();'#39' />'
      
        '<input type=button value=">" onclick='#39'if(self.grid1!=null)grid1.' +
        'down();'#39' />'
      
        '<input type=button value="Post/Next" onclick='#39'if(self.grid1!=nul' +
        'l)grid1.post();'#39'/>'
      '<P>'
      
        '<input type=button value="Reapply Updates" onclick='#39'if(self.grid' +
        '1!=null)grid1.Reapply(Submitfrm1, Submitfrm1.postdelta);'#39'/>'
      '</FORM>'
      '<#FORMS><#SCRIPT>'
      '</BODY>'
      '</HTML>')
    ReconcileGrid.ConflictingColumn.Caption = 'Conflicting Value'
    ReconcileGrid.ConflictingColumn.DisplayWidth = 24
    ReconcileGrid.FieldNameColumn.Caption = 'Field Name'
    ReconcileGrid.FieldNameColumn.DisplayWidth = 18
    ReconcileGrid.ModifiedColumn.Caption = 'Submitted Value'
    ReconcileGrid.ModifiedColumn.DisplayWidth = 24
    ReconcileGrid.OriginalColumn.Caption = 'Original Value'
    ReconcileGrid.OriginalColumn.DisplayWidth = 24
    Left = 64
    Top = 184
  end
end
