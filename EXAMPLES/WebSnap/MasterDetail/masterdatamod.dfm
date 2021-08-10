object MasterDataModule: TMasterDataModule
  OldCreateOrder = False
  Left = 192
  Top = 107
  Height = 347
  Width = 528
  object OrdersTable: TTable
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    IndexName = 'CustNo'
    TableName = 'orders.db'
    Left = 32
    Top = 24
    object OrdersTableOrderNo: TFloatField
      FieldName = 'OrderNo'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      DisplayFormat = #39'#'#39'0000'
    end
    object OrdersTableCustNo: TFloatField
      Alignment = taLeftJustify
      CustomConstraint = 'CustNo IS NOT NULL'
      ConstraintErrorMessage = 'CustNo cannot be blank'
      FieldName = 'CustNo'
      Required = True
      DisplayFormat = 'CN 0000'
      MaxValue = 9999
      MinValue = 1000
    end
    object OrdersTableSaleDate: TDateTimeField
      FieldName = 'SaleDate'
    end
    object OrdersTableShipDate: TDateTimeField
      FieldName = 'ShipDate'
    end
    object OrdersTableEmpNo: TIntegerField
      CustomConstraint = 'Value > 0'
      ConstraintErrorMessage = 'EmpNo cannot be 0 or negative'
      FieldName = 'EmpNo'
      Required = True
      DisplayFormat = 'Emp'#39'#'#39' 0000'
      MaxValue = 9999
      MinValue = 1
    end
    object OrdersTableShipToContact: TStringField
      FieldName = 'ShipToContact'
    end
    object OrdersTableShipToAddr1: TStringField
      FieldName = 'ShipToAddr1'
      Size = 30
    end
    object OrdersTableShipToAddr2: TStringField
      FieldName = 'ShipToAddr2'
      Size = 30
    end
    object OrdersTableShipToCity: TStringField
      FieldName = 'ShipToCity'
      Size = 15
    end
    object OrdersTableShipToState: TStringField
      FieldName = 'ShipToState'
    end
    object OrdersTableShipToZip: TStringField
      FieldName = 'ShipToZip'
      Size = 10
    end
    object OrdersTableShipToCountry: TStringField
      FieldName = 'ShipToCountry'
    end
    object OrdersTableShipToPhone: TStringField
      FieldName = 'ShipToPhone'
      Size = 15
    end
    object OrdersTableShipVIA: TStringField
      FieldName = 'ShipVIA'
      Size = 7
    end
    object OrdersTablePO: TStringField
      FieldName = 'PO'
      Size = 15
    end
    object OrdersTableTerms: TStringField
      FieldName = 'Terms'
      Size = 6
    end
    object OrdersTablePaymentMethod: TStringField
      FieldName = 'PaymentMethod'
      Size = 7
    end
    object OrdersTableItemsTotal: TCurrencyField
      FieldName = 'ItemsTotal'
    end
    object OrdersTableTaxRate: TFloatField
      FieldName = 'TaxRate'
      DisplayFormat = '0.00%'
      MaxValue = 100
    end
    object OrdersTableFreight: TCurrencyField
      FieldName = 'Freight'
    end
    object OrdersTableAmountPaid: TCurrencyField
      FieldName = 'AmountPaid'
    end
  end
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 96
    Top = 16
  end
  object ItemsTable: TTable
    Active = True
    DatabaseName = 'DBDEMOS'
    SessionName = 'Session1_1'
    IndexName = 'ByOrderNo'
    MasterFields = 'OrderNo'
    MasterSource = DataSource1
    TableName = 'items.db'
    Left = 32
    Top = 112
    object ItemsTableOrderNo: TFloatField
      FieldName = 'OrderNo'
      DisplayFormat = #39'#'#39'0000'
    end
    object ItemsTableItemNo: TFloatField
      FieldName = 'ItemNo'
      ProviderFlags = [pfInUpdate]
    end
    object ItemsTablePartNo: TFloatField
      Alignment = taLeftJustify
      FieldName = 'PartNo'
      DisplayFormat = 'PN-00000'
    end
    object ItemsTableQty: TIntegerField
      FieldName = 'Qty'
    end
    object ItemsTableDiscount: TFloatField
      FieldName = 'Discount'
      DisplayFormat = '0#%'
      MaxValue = 100
    end
  end
  object DataSource1: TDataSource
    DataSet = OrdersTable
    Left = 96
    Top = 72
  end
  object OrdersAdapter: TDataSetAdapter
    DataSet = OrdersTable
    Left = 224
    Top = 32
    object TAdapterDefaultActions
      object ActionDeleteRow2: TDataSetAdapterDeleteRowAction
      end
      object ActionFirstRow2: TDataSetAdapterFirstRowAction
      end
      object ActionPrevRow2: TDataSetAdapterPrevRowAction
      end
      object ActionNextRow2: TDataSetAdapterNextRowAction
      end
      object ActionLastRow2: TDataSetAdapterLastRowAction
      end
      object ActionEditRow2: TDataSetAdapterEditRowAction
        OnAfterExecute = ActionEditRow2AfterExecute
      end
      object ActionBrowseRow2: TDataSetAdapterBrowseRowAction
        OnAfterExecute = ActionBrowseRow2AfterExecute
      end
      object ActionNewRow2: TDataSetAdapterNewRowAction
      end
      object ActionCancel2: TDataSetAdapterCancelRowAction
      end
      object ActionApply2: TDataSetAdapterApplyRowAction
      end
      object ActionRefreshRow2: TDataSetAdapterRefreshRowAction
      end
    end
    object TAdapterDefaultFields
    end
  end
  object ItemsAdapter: TDataSetAdapter
    DataSet = ItemsTable
    MasterAdapter = OrdersAdapter
    Left = 264
    Top = 160
    object TAdapterDefaultActions
      object ActionDeleteRow: TDataSetAdapterDeleteRowAction
      end
      object ActionNewRow: TDataSetAdapterNewRowAction
      end
      object ActionCancel: TDataSetAdapterCancelRowAction
        OnBeforeExecute = ActionCancelBeforeExecute
        RedirectOptions = [roRedirectHTTPPost, roRedirectHTTPGet]
      end
      object ActionApply: TDataSetAdapterApplyRowAction
      end
      object ActionRefreshRow: TDataSetAdapterRefreshRowAction
      end
    end
    object TAdapterDefaultFields
      object AdaptOrderNo: TDataSetAdapterField
        DataSetField = 'OrderNo'
      end
      object AdaptItemNo: TDataSetAdapterField
        DataSetField = 'ItemNo'
      end
      object AdaptPartNo: TDataSetAdapterField
        DataSetField = 'PartNo'
        ValuesList = PartNoValuesList
      end
      object AdaptQty: TDataSetAdapterField
        DataSetField = 'Qty'
      end
      object AdaptDiscount: TDataSetAdapterField
        DataSetField = 'Discount'
      end
    end
  end
  object PartNoValuesList: TDataSetValuesList
    ValueField = 'PartNo'
    DataSet = PartNoQuery
    Left = 184
    Top = 112
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object PartNoQuery: TQuery
    Active = True
    DatabaseName = 'DBDEMOS'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'select PartNo from parts order by PartNo')
    Left = 168
    Top = 184
  end
  object QueryAdapter: TDataSetAdapter
    DataSet = Query1
    PageSize = 20
    Left = 272
    Top = 104
    object TAdapterDefaultActions
      object ActionPrevPage: TAdapterPrevPageAction
      end
      object ActionGotoPage: TAdapterGotoPageAction
      end
      object ActionNextPage: TAdapterNextPageAction
      end
      object ActionBrowseRow: TDataSetAdapterBrowseRowAction
        OnAfterExecute = ActionBrowseRowAfterExecute
      end
      object BrowseOrder: TAdapterAction
        OnExecute = BrowseOrderExecute
        OnGetParams = BrowseOrderGetParams
      end
    end
    object TAdapterDefaultFields
    end
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'DBDEMOS'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'Select * from customer, orders where customer.CustNo = orders.Cu' +
        'stNo')
    Left = 64
    Top = 176
    object Query1CustNo: TFloatField
      Alignment = taLeftJustify
      CustomConstraint = 'CustNo IS NOT NULL'
      ConstraintErrorMessage = 'CustNo cannot be blank'
      FieldName = 'CustNo'
      Origin = 'DBDEMOS."customer.DB".CustNo'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      DisplayFormat = 'CN 0000'
      MaxValue = 9999
      MinValue = 1000
    end
    object Query1Company: TStringField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'Company'
      Origin = 'DBDEMOS."customer.DB".Company'
      Size = 30
    end
    object Query1OrderNo: TFloatField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'OrderNo'
      Origin = 'DBDEMOS."customer.DB".Company'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object Query1SaleDate: TDateTimeField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'SaleDate'
      Origin = 'DBDEMOS."customer.DB".Company'
    end
    object Query1ShipDate: TDateTimeField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'ShipDate'
      Origin = 'DBDEMOS."customer.DB".Company'
    end
    object Query1EmpNo: TIntegerField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'EmpNo'
      Origin = 'DBDEMOS."customer.DB".Company'
    end
    object Query1ItemsTotal: TCurrencyField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'ItemsTotal'
      Origin = 'DBDEMOS."customer.DB".Company'
    end
    object Query1AmountPaid: TCurrencyField
      CustomConstraint = 'X IS NOT NULL'
      ConstraintErrorMessage = 'Company Field has to have a value'
      FieldName = 'AmountPaid'
      Origin = 'DBDEMOS."customer.DB".Company'
    end
  end
end
