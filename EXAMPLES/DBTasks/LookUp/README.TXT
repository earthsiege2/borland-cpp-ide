//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  LOOKUP

DESCRIPTION:
  Demonstrates lookup fields and calculated fields.

DEMONSTRATES:
  + TDBNavigator
  + TDBGrid
  + TDataSource
  + TTable
  + TStringField, TFloatField, TCurrencyField

COMMENTS:
  This is a demo of lookup fields and calculated Fields.  

  Shown in the grid is the Orders table. Three Lookup fields were added to it: 
  CustomerName, EmployeeLastName and EmployeeFirst Name.  Notice that if you tab 
  to one of these fields and press [F2], you can see a button for the drop-down list.  
  If you select a new value from the list, the corresponding Key field (CustNo or EmpNo) 
  will change.  However, if you type into the field, the corresponding Key field does 
  not change, nor is the value retained when you post the record.

  The calculated field EmployeeFullName demonstrates how a calculated field can
  be made from two Lookup fields.  Like any calculated field, it is not editable by the   user.

