�
 TSHAPEFORM 0I  TPF0
TShapeForm	ShapeFormLeft� TopzWidthHeight�Caption
Shape DemoColor	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OldCreateOrderPositionpoScreenCenterPixelsPerInch`
TextHeight TPanelPanel1Left Top WidthHeight`AlignalTop
BevelOuterbvNoneTabOrder  TLabelDataSourceLabelLeftTop;WidthXHeight	AlignmenttaRightJustifyAutoSizeCaptionData Source=  TLabelDataProviderLabelLeftTop!WidthYHeight	AlignmenttaRightJustifyAutoSizeCaptionData Provider=  TLabelProviderLabelLeftTop
WidthPHeight	AlignmenttaRightJustifyAutoSizeCaption	Provider=  TLabelLabel4Left�TopWidth� Height4CaptioneIf needed, update the path for the Data Source to point to the location of the C++ Builder demo data.WordWrap	  TEditProviderLeftdTopWidthQHeightEnabledTabOrder TextMSDataShape.1  TEditDataProviderLeftdTopWidthQHeightTabOrderTextMicrosoft.Jet.OLEDB.4.0  TEdit
DataSourceLeftdTop8WidthQHeightTabOrderText;..\..\..\..\..\Common Files\Borland Shared\Data\bcdemos.mdb  TButton
OpenButtonLeft�TopWidthKHeightCaption&OpenTabOrderOnClickOpenButtonClick   TDBGridDBGrid1Left Top`WidthHeight� AlignalTop
DataSource
CustSourceTabOrderTitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style   TDBGridDBGrid2Left Top� WidthHeight� AlignalClient
DataSourceOrderSourceTabOrderTitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style   TADOConnectionADOConnection1ConnectionString�Provider=MSDataShape.1;Persist Security Info=True;Data Source=C:\Program Files\Common Files\Borland Shared\Data\BCDemos.mdb;Data Provider=Microsoft.Jet.OLEDB.4.0LoginPromptProviderMSDataShape.1LeftTop  TDataSource
CustSourceDataSet	CustomersLeft1Top�   TADODataSet	Customers
ConnectionADOConnection1
CursorTypectStaticCommandTexthSHAPE  {select * from customer} 
APPEND ({select * from orders} AS Orders
   RELATE CustNo TO CustNo) 
Parameters LeftTop�  TFloatFieldCustomersCustNo	FieldNameCustNo  TWideStringFieldCustomersCompany	FieldNameCompanySize  TWideStringFieldCustomersAddr1	FieldNameAddr1Size  TWideStringFieldCustomersAddr2	FieldNameAddr2Size  TWideStringFieldCustomersCity	FieldNameCitySize  TWideStringFieldCustomersState	FieldNameState  TWideStringFieldCustomersZip	FieldNameZipSize
  TWideStringFieldCustomersCountry	FieldNameCountry  TWideStringFieldCustomersPhone	FieldNamePhoneSize  TWideStringFieldCustomersFAX	FieldNameFAXSize  TFloatFieldCustomersTaxRate	FieldNameTaxRate  TWideStringFieldCustomersContact	FieldNameContact  
TDateFieldCustomersLastInvoiceDate	FieldNameLastInvoiceDate  TDataSetFieldCustomersOrders	FieldNameOrdersReadOnly	IncludeObjectField   TDataSourceOrderSourceDataSetOrdersLeft1TopQ  TADODataSetOrders
CursorTypectStaticDataSetFieldCustomersOrders
Parameters LeftTopQ TFloatFieldOrdersOrderNo	FieldNameOrderNo  TFloatFieldOrdersCustNo	FieldNameCustNo  
TDateFieldOrdersSaleDate	FieldNameSaleDate  
TDateFieldOrdersShipDate	FieldNameShipDate  TIntegerFieldOrdersEmpNo	FieldNameEmpNo  TWideStringFieldOrdersShipToContact	FieldNameShipToContact  TWideStringFieldOrdersShipToAddr1	FieldNameShipToAddr1Size  TWideStringFieldOrdersShipToAddr2	FieldNameShipToAddr2Size  TWideStringFieldOrdersShipToCity	FieldName
ShipToCitySize  TWideStringFieldOrdersShipToState	FieldNameShipToState  TWideStringFieldOrdersShipToZip	FieldName	ShipToZipSize
  TWideStringFieldOrdersShipToCountry	FieldNameShipToCountry  TWideStringFieldOrdersShipToPhone	FieldNameShipToPhoneSize  TWideStringFieldOrdersShipVIA	FieldNameShipVIASize  TWideStringFieldOrdersPO	FieldNamePOSize  TWideStringFieldOrdersTerms	FieldNameTermsSize  TWideStringFieldOrdersPaymentMethod	FieldNamePaymentMethodSize  TFloatFieldOrdersItemsTotal	FieldName
ItemsTotal  TFloatFieldOrdersTaxRate	FieldNameTaxRate  TFloatFieldOrdersFreight	FieldNameFreight  TFloatFieldOrdersAmountPaid	FieldName
AmountPaid    