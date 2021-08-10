// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLItems.pas' rev: 6.00

#ifndef WSDLItemsHPP
#define WSDLItemsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPUtil.hpp>	// Pascal unit
#include <WSDLBind.hpp>	// Pascal unit
#include <WSDLIntf.hpp>	// Pascal unit
#include <msxmldom.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Wsdlitems
{
//-- type declarations -------------------------------------------------------
__interface IWSDLItems;
typedef System::DelphiInterface<IWSDLItems> _di_IWSDLItems;
class DELPHICLASS TWSDLItems;
__interface INTERFACE_UUID("{F71B4B05-C5AB-4484-B994-64F3F9E805C7}") IWSDLItems  : public IInterface 
{
	
public:
	virtual TWSDLItems* __fastcall GetWSDLItems(void) = 0 ;
	virtual Wsdlbind::_di_IWSDLDocument __fastcall GetWSDLDoc(void) = 0 ;
	virtual void __fastcall Load(const WideString WSDLFileName) = 0 ;
};

__interface IQualifiedName;
typedef System::DelphiInterface<IQualifiedName> _di_IQualifiedName;
__interface INTERFACE_UUID("{0173ABA2-34AB-4CB1-ADF0-AA99C98FCFBD}") IQualifiedName  : public IInterface 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual void __fastcall SetName(const WideString name) = 0 ;
	virtual WideString __fastcall GetNamespace(void) = 0 ;
	virtual void __fastcall SetNamespace(const WideString ns) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString Namespace = {read=GetNamespace, write=SetNamespace};
};

#pragma option push -b-
enum IterateImportOptions { ioBeforeLoad, ioLoaded };
#pragma option pop

typedef void __fastcall (__closure *TWSDLIterateProc)(const IterateImportOptions Options, const _di_IWSDLItems WSDLItems, const Xmlschema::_di_IXMLSchemaDoc XMLSchemaDoc, const WideString Name);

class PASCALIMPLEMENTATION TWSDLItems : public Wsdlbind::TWSDLDocument 
{
	typedef Wsdlbind::TWSDLDocument inherited;
	
private:
	Httputil::_di_IStreamLoader FWSDLStreamLoader;
	WideString __fastcall GetGenericBindingAttribute(const WideString BindingName, const WideString NodeName, const WideString Namespace, WideString Attribute);
	WideString __fastcall MakeTNSName(const WideString Name);
	
public:
	__fastcall virtual TWSDLItems(Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual TWSDLItems(const TWSDLItems* WSDLItems, const Httputil::_di_IStreamLoader StreamLoader)/* overload */;
	TWSDLItems* __fastcall GetWSDLItems(void);
	Wsdlbind::_di_IWSDLDocument __fastcall GetWSDLDoc();
	void __fastcall Load(const WideString WSDLFileName);
	bool __fastcall CompareName(const WideString NodeName, const WideString OtherName, const WideString TNS = L"");
	WideString __fastcall GetName();
	WideString __fastcall GetTargetNamespace();
	WideString __fastcall GetTargetNamespacePrefix();
	void __fastcall GetServices(Wsdlintf::TWideStrings* ServiceNames, bool QualifiedNames = false);
	Xmlintf::_di_IXMLNode __fastcall GetServiceNode(const WideString ServiceName);
	void __fastcall GetMessages(Wsdlintf::TWideStrings* MessageNames, bool QualifiedNames = false);
	Xmlintf::_di_IXMLNode __fastcall GetMessageNode(const WideString MessageName);
	void __fastcall GetParts(const WideString MessageName, Wsdlintf::TWideStrings* PartNames, bool QualifiedNames = false);
	Xmlintf::_di_IXMLNode __fastcall GetPartNode(const WideString MessageName, const WideString PartName);
	void __fastcall GetPortTypes(Wsdlintf::TWideStrings* PortTypeNames, bool SkipHttpBindings = true, bool QualifiedNames = false);
	Xmlintf::_di_IXMLNode __fastcall GetPortTypeNode(const WideString PortTypeName);
	void __fastcall GetOperations(const WideString PortTypeName, Wsdlintf::TWideStrings* OperationNames, bool QualifiedNames = false);
	Xmlintf::_di_IXMLNode __fastcall GetOperationNode(const WideString PortTypeName, const WideString OperationName);
	void __fastcall GetPortsForService(const WideString ServiceName, Wsdlintf::TWideStrings* PortNames, bool SkipHttpBindings = true, bool QualifiedNames = false);
	_di_IQualifiedName __fastcall GetBindingForServicePort(const WideString ServiceName, const WideString PortName);
	bool __fastcall GetServiceAndPortOfBinding(const _di_IQualifiedName BindingName, WideString &ServiceName, WideString &PortName);
	WideString __fastcall GetSoapAddressForServicePort(const WideString ServiceName, const WideString PortName);
	void __fastcall GetImports(Wsdlintf::TWideStrings* ImportNames);
	void __fastcall IterateImports(TWSDLIterateProc IterateProc);
	WideString __fastcall GetLocationForImport(const WideString ImportNameSpace);
	bool __fastcall HasTypesNode(void);
	void __fastcall GetSchemas(Wsdlintf::TWideStrings* SchemaNames);
	Xmlintf::_di_IXMLNode __fastcall GetSchemaNode(const WideString SchemaTns);
	void __fastcall GetBindings(Wsdlintf::TWideStrings* BindingNames, bool QualifiedNames = false);
	WideString __fastcall GetBindingType(const WideString BindingName);
	_di_IQualifiedName __fastcall GetBindingOfType(const WideString BindingTypeName, const WideString TNS = L"");
	WideString __fastcall GetSoapBindingAttribute(const WideString BindingName, WideString Attribute);
	WideString __fastcall GetHttpBindingAttribute(const WideString BindingName, WideString Attribute)/* overload */;
	WideString __fastcall GetHttpBindingAttribute(const _di_IQualifiedName QualifiedName, WideString Attribute)/* overload */;
	void __fastcall GetOperationsForBinding(const WideString BindingName, Wsdlintf::TWideStrings* OperationNames, bool QualifiedNames = false);
	WideString __fastcall GetSoapOperationAttribute(const WideString BindingName, const WideString Operation, const WideString Attribute);
	WideString __fastcall GetSoapAction(const WideString BindingName, const WideString Operation);
	WideString __fastcall GetSoapOperationStyle(const WideString BindingName, const WideString Operation);
	void __fastcall GetSoapActionList(const WideString BindingName, Wsdlintf::TWideStrings* ActionList, bool QualifiedNames = false);
	WideString __fastcall GetSoapBodyAttribute(const WideString BindingName, const WideString Operation, const WideString IOType, const WideString Attribute);
	WideString __fastcall GetSoapBodyInputAttribute(const WideString BindingName, const WideString Operation, const WideString Attribute);
	WideString __fastcall GetSoapBodyOutputAttribute(const WideString BindingName, const WideString Operation, const WideString Attribute);
	WideString __fastcall GetSoapBodyNamespace(const WideString BindingPortType);
	bool __fastcall GetPartsForOperation(const WideString PortTypeName, const WideString OperationName, int OperationIndex, Wsdlintf::TWideStrings* PartNames);
	__property Httputil::_di_IStreamLoader StreamLoader = {read=FWSDLStreamLoader};
	__property WideString TargetNamespace = {read=GetTargetNamespace};
public:
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TWSDLItems(void) { }
	#pragma option pop
	
private:
	void *__IWSDLItems;	/* Wsdlitems::IWSDLItems */
	
public:
	operator IWSDLItems*(void) { return (IWSDLItems*)&__IWSDLItems; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IQualifiedName __fastcall NewQualifiedName(const WideString Name = L"", const WideString Namespace = L"");
extern PACKAGE bool __fastcall HasDefinition(const Wsdlbind::_di_IWSDLDocument WSDLDoc)/* overload */;
extern PACKAGE bool __fastcall HasDefinition(const _di_IWSDLItems WSDLItems)/* overload */;

}	/* namespace Wsdlitems */
using namespace Wsdlitems;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLItems
