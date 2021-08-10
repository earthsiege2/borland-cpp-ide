object rdmCustomerData_bcb: TrdmCustomerData_bcb
  OldCreateOrder = False
  Height = 0
  Width = 0
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 32
    Top = 24
  end
  object SelectCustNames: TQuery
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'Select CustNo, Company from Customer order by Company')
    Left = 120
    Top = 16
  end
  object SelectCustOrders: TQuery
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'Select * from orders where CustNo = :CustNo')
    Left = 32
    Top = 80
    ParamData = <
      item
        DataType = ftSmallint
        Name = 'CustNo'
        ParamType = ptUnknown
        Value = 1221
      end>
  end
  object OrderItems: TTable
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    IndexName = 'ByOrderNo'
    MasterFields = 'OrderNo'
    MasterSource = SelectCustOrderSrc
    TableName = 'items.db'
    Left = 112
    Top = 80
  end
  object CustNames: TDataSetProvider
    DataSet = SelectCustNames
    Constraints = True
    Left = 192
    Top = 72
  end
  object CustOrders: TDataSetProvider
    DataSet = SelectCustOrders
    Constraints = True
    Left = 128
    Top = 144
  end
  object SelectCustOrderSrc: TDataSource
    DataSet = SelectCustOrders
    Left = 32
    Top = 144
  end
end
