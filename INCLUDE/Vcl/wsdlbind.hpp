// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLBind.pas' rev: 6.00

#ifndef WSDLBindHPP
#define WSDLBindHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <XMLSchema.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <urlmon.h>
namespace Wsdlbind {
using Xmlintf::IXMLDocument;
};

namespace Wsdlbind
{
//-- type declarations -------------------------------------------------------
__interface IDocumentation;
typedef System::DelphiInterface<IDocumentation> _di_IDocumentation;
__interface INTERFACE_UUID("{22E6AC24-DEC1-4EB6-A305-C966250CD56F}") IDocumentation  : public IXMLNode 
{
	
};

__interface IDocumentationCollection;
typedef System::DelphiInterface<IDocumentationCollection> _di_IDocumentationCollection;
__interface INTERFACE_UUID("{2BA090C5-A91E-42BA-928B-75FB816B195F}") IDocumentationCollection  : public IXMLNodeCollection 
{
	
public:
	_di_IDocumentation operator[](int Index) { return Documentation[Index]; }
	
public:
	virtual _di_IDocumentation __fastcall GetDocumentation(int Index) = 0 ;
	virtual _di_IDocumentation __fastcall Add(const WideString Text) = 0 ;
	virtual _di_IDocumentation __fastcall Insert(int Index) = 0 ;
	__property _di_IDocumentation Documentation[int Index] = {read=GetDocumentation/*, default*/};
};

__interface IDocumented;
typedef System::DelphiInterface<IDocumented> _di_IDocumented;
__interface INTERFACE_UUID("{DC197A33-3BB6-4415-A1E1-995FB3BE35A9}") IDocumented  : public IXMLNode 
{
	
public:
	virtual _di_IDocumentationCollection __fastcall GetDocumentationCollection(void) = 0 ;
	__property _di_IDocumentationCollection Documentation = {read=GetDocumentationCollection};
};

__interface IImport;
typedef System::DelphiInterface<IImport> _di_IImport;
__interface INTERFACE_UUID("{B50B5058-46EA-46CE-A737-23ECE26F5711}") IImport  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetNamespace(void) = 0 ;
	virtual WideString __fastcall GetLocation(void) = 0 ;
	virtual void __fastcall SetNamespace(WideString Value) = 0 ;
	virtual void __fastcall SetLocation(WideString Value) = 0 ;
	__property WideString Namespace = {read=GetNamespace, write=SetNamespace};
	__property WideString Location = {read=GetLocation, write=SetLocation};
};

__interface IImports;
typedef System::DelphiInterface<IImports> _di_IImports;
__interface INTERFACE_UUID("{2BA090C5-A91E-42BA-928B-75FB816B195F}") IImports  : public IXMLNodeCollection 
{
	
public:
	_di_IImport operator[](int Index) { return Import[Index]; }
	
public:
	virtual _di_IImport __fastcall GetImport(int Index) = 0 ;
	virtual _di_IImport __fastcall Add(const WideString Namespace, const WideString Location) = 0 ;
	virtual _di_IImport __fastcall Insert(int Index) = 0 ;
	__property _di_IImport Import[int Index] = {read=GetImport/*, default*/};
};

__interface IXMLSchemaDefs;
typedef System::DelphiInterface<IXMLSchemaDefs> _di_IXMLSchemaDefs;
__interface INTERFACE_UUID("{9657EAAE-DEC2-4A79-AED1-9114578F72BC}") IXMLSchemaDefs  : public IXMLNodeCollection 
{
	
public:
	Xmlschema::_di_IXMLSchemaDef operator[](int Index) { return SchemaDef[Index]; }
	
public:
	virtual Xmlschema::_di_IXMLSchemaDef __fastcall GetXMLSchemaDef(int Index) = 0 ;
	virtual Xmlschema::_di_IXMLSchemaDef __fastcall Add(const WideString NamespaceURI = L"", const WideString TargetNamespace = L"") = 0 ;
	__property Xmlschema::_di_IXMLSchemaDef SchemaDef[int Index] = {read=GetXMLSchemaDef/*, default*/};
};

__interface ITypes;
typedef System::DelphiInterface<ITypes> _di_ITypes;
__interface INTERFACE_UUID("{AAB2EBF2-79E2-42AA-A3D2-5C4ADCF51B93}") ITypes  : public IDocumented 
{
	
public:
	virtual _di_IXMLSchemaDefs __fastcall GetSchemaDefs(void) = 0 ;
	__property _di_IXMLSchemaDefs SchemaDefs = {read=GetSchemaDefs};
};

__interface IPart;
typedef System::DelphiInterface<IPart> _di_IPart;
__interface INTERFACE_UUID("{EFD70258-38DE-4BF8-B503-C17022588EAF}") IPart  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual WideString __fastcall GetType_(void) = 0 ;
	virtual WideString __fastcall GetElement(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	virtual void __fastcall SetType_(WideString Value) = 0 ;
	virtual void __fastcall SetElement(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString Type_ = {read=GetType_, write=SetType_};
	__property WideString Element = {read=GetElement, write=SetElement};
};

__interface IParts;
typedef System::DelphiInterface<IParts> _di_IParts;
__interface INTERFACE_UUID("{7D69B10B-77BA-43AE-8581-F2A5E3B36C95}") IParts  : public IXMLNodeCollection 
{
	
public:
	_di_IPart operator[](int Index) { return Part[Index]; }
	
public:
	virtual _di_IPart __fastcall GetPart(int Index) = 0 ;
	virtual _di_IPart __fastcall Add(const WideString Name, const WideString Element, const WideString AType = L"") = 0 ;
	virtual _di_IPart __fastcall Insert(int Index) = 0 ;
	__property _di_IPart Part[int Index] = {read=GetPart/*, default*/};
};

__interface IMessage;
typedef System::DelphiInterface<IMessage> _di_IMessage;
__interface INTERFACE_UUID("{6DD2446C-7E8C-4CBA-BCB0-C318EFFE722A}") IMessage  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IParts __fastcall GetParts(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property _di_IParts Parts = {read=GetParts};
};

__interface IMessages;
typedef System::DelphiInterface<IMessages> _di_IMessages;
__interface INTERFACE_UUID("{1716B6D5-6087-4DB3-B729-1003C7424C2B}") IMessages  : public IXMLNodeCollection 
{
	
public:
	_di_IMessage operator[](int Index) { return Message[Index]; }
	
public:
	virtual _di_IMessage __fastcall GetMessage(int Index) = 0 ;
	virtual _di_IMessage __fastcall Add(const WideString Name) = 0 ;
	virtual _di_IMessage __fastcall Insert(int Index) = 0 ;
	__property _di_IMessage Message[int Index] = {read=GetMessage/*, default*/};
};

__interface IParam;
typedef System::DelphiInterface<IParam> _di_IParam;
__interface INTERFACE_UUID("{66FF002F-6534-421F-93B8-57FDADBE23B5}") IParam  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual WideString __fastcall GetMessage(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	virtual void __fastcall SetMessage(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString Message = {read=GetMessage, write=SetMessage};
};

__interface IFault;
typedef System::DelphiInterface<IFault> _di_IFault;
__interface INTERFACE_UUID("{6B1A1E80-231D-4D0C-AFB9-9E2ECBC5A323}") IFault  : public IParam 
{
	
};

__interface IFaults;
typedef System::DelphiInterface<IFaults> _di_IFaults;
__interface INTERFACE_UUID("{67FD5C06-F745-4AD1-8B12-92552EA4AB92}") IFaults  : public IXMLNodeCollection 
{
	
public:
	_di_IFault operator[](int Index) { return Fault[Index]; }
	
public:
	virtual _di_IFault __fastcall GetFault(int Index) = 0 ;
	virtual _di_IFault __fastcall Add(const WideString Name, const WideString Message) = 0 ;
	virtual _di_IFault __fastcall Insert(int Index) = 0 ;
	__property _di_IFault Fault[int Index] = {read=GetFault/*, default*/};
};

__interface IOperation;
typedef System::DelphiInterface<IOperation> _di_IOperation;
__interface INTERFACE_UUID("{84BC9B4C-019A-4614-A050-A0BB165E7CC2}") IOperation  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IParam __fastcall GetInput(void) = 0 ;
	virtual _di_IParam __fastcall GetOutput(void) = 0 ;
	virtual _di_IFaults __fastcall GetFaults(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property _di_IParam Input = {read=GetInput};
	__property _di_IParam Output = {read=GetOutput};
	__property _di_IFaults Faults = {read=GetFaults};
};

__interface IOperations;
typedef System::DelphiInterface<IOperations> _di_IOperations;
__interface INTERFACE_UUID("{52270B19-5C86-4C77-AF4F-A620655ED9E2}") IOperations  : public IXMLNodeCollection 
{
	
public:
	_di_IOperation operator[](int Index) { return Operation[Index]; }
	
public:
	virtual _di_IOperation __fastcall GetOperation(int Index) = 0 ;
	virtual _di_IOperation __fastcall Add(const WideString Name) = 0 /* overload */;
	virtual _di_IOperation __fastcall Add(const WideString Name, const WideString InputMessage, const WideString InputName, const WideString OutputMessage) = 0 /* overload */;
	virtual _di_IOperation __fastcall Insert(int Index) = 0 ;
	__property _di_IOperation Operation[int Index] = {read=GetOperation/*, default*/};
};

__interface IPortType;
typedef System::DelphiInterface<IPortType> _di_IPortType;
__interface INTERFACE_UUID("{53334349-D65E-44A6-8FBA-3694418BA70A}") IPortType  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IOperations __fastcall GetOperations(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property _di_IOperations Operations = {read=GetOperations};
};

__interface IPortTypes;
typedef System::DelphiInterface<IPortTypes> _di_IPortTypes;
__interface INTERFACE_UUID("{5A702461-CE49-44FE-A665-74E7D3974FBE}") IPortTypes  : public IXMLNodeCollection 
{
	
public:
	_di_IPortType operator[](int Index) { return PortType[Index]; }
	
public:
	virtual _di_IPortType __fastcall GetPortType(int Index) = 0 ;
	virtual _di_IPortType __fastcall Add(const WideString Name) = 0 ;
	virtual _di_IPortType __fastcall Insert(int Index) = 0 ;
	__property _di_IPortType PortType[int Index] = {read=GetPortType/*, default*/};
};

__interface IBindingInput;
typedef System::DelphiInterface<IBindingInput> _di_IBindingInput;
__interface INTERFACE_UUID("{B4EB7EA0-A298-4527-BF5B-DCC6DD36EE12}") IBindingInput  : public IParam 
{
	
};

__interface IBindingOutput;
typedef System::DelphiInterface<IBindingOutput> _di_IBindingOutput;
__interface INTERFACE_UUID("{EEA06E96-EF0D-409D-BBE2-DFE554C50F23}") IBindingOutput  : public IParam 
{
	
};

__interface IBindingOperation;
typedef System::DelphiInterface<IBindingOperation> _di_IBindingOperation;
__interface INTERFACE_UUID("{2A4A10F1-269F-427C-9FAC-305B53743F8B}") IBindingOperation  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IBindingInput __fastcall GetInput(void) = 0 ;
	virtual _di_IBindingOutput __fastcall GetOutput(void) = 0 ;
	virtual _di_IFaults __fastcall GetFaults(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property _di_IBindingInput Input = {read=GetInput};
	__property _di_IBindingOutput Output = {read=GetOutput};
	__property _di_IFaults Faults = {read=GetFaults};
};

__interface IBindingOperations;
typedef System::DelphiInterface<IBindingOperations> _di_IBindingOperations;
__interface INTERFACE_UUID("{D579620B-8339-4271-98A4-D3FDBAF3B0A6}") IBindingOperations  : public IXMLNodeCollection 
{
	
public:
	_di_IBindingOperation operator[](int Index) { return BindingOperation[Index]; }
	
public:
	virtual _di_IBindingOperation __fastcall GetBindingOperation(int Index) = 0 ;
	virtual _di_IBindingOperation __fastcall Add(const WideString Name) = 0 ;
	virtual _di_IBindingOperation __fastcall Insert(int Index) = 0 ;
	__property _di_IBindingOperation BindingOperation[int Index] = {read=GetBindingOperation/*, default*/};
};

__interface IBinding;
typedef System::DelphiInterface<IBinding> _di_IBinding;
__interface INTERFACE_UUID("{1910D8C3-7492-405E-9D9F-62311D24B603}") IBinding  : public IDocumented 
{
	
public:
	virtual _di_IBindingOperations __fastcall GetBindingOperations(void) = 0 ;
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual WideString __fastcall GetType_(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	virtual void __fastcall SetType_(WideString Value) = 0 ;
	__property _di_IBindingOperations BindingOperations = {read=GetBindingOperations};
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString Type_ = {read=GetType_, write=SetType_};
};

__interface IBindings;
typedef System::DelphiInterface<IBindings> _di_IBindings;
__interface INTERFACE_UUID("{C8FE02C7-D726-4214-9FF4-90782EB7ACCA}") IBindings  : public IXMLNodeCollection 
{
	
public:
	_di_IBinding operator[](int Index) { return Binding[Index]; }
	
public:
	virtual _di_IBinding __fastcall GetBinding(int Index) = 0 ;
	virtual _di_IBinding __fastcall Add(const WideString Name, const WideString AType) = 0 ;
	virtual _di_IBinding __fastcall Insert(int Index) = 0 ;
	__property _di_IBinding Binding[int Index] = {read=GetBinding/*, default*/};
};

__interface IPort;
typedef System::DelphiInterface<IPort> _di_IPort;
__interface INTERFACE_UUID("{10D0E981-A053-4C0F-AE5A-785D2B0D97FD}") IPort  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual WideString __fastcall GetBinding(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	virtual void __fastcall SetBinding(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString Binding = {read=GetBinding, write=SetBinding};
};

__interface IPorts;
typedef System::DelphiInterface<IPorts> _di_IPorts;
__interface INTERFACE_UUID("{360DDA1F-E58E-4355-8711-25140D488497}") IPorts  : public IXMLNodeCollection 
{
	
public:
	_di_IPort operator[](int Index) { return Port[Index]; }
	
public:
	virtual _di_IPort __fastcall GetPort(int Index) = 0 ;
	virtual _di_IPort __fastcall Add(const WideString Name, const WideString ABinding) = 0 ;
	virtual _di_IPort __fastcall Insert(int Index) = 0 ;
	__property _di_IPort Port[int Index] = {read=GetPort/*, default*/};
};

__interface IService;
typedef System::DelphiInterface<IService> _di_IService;
__interface INTERFACE_UUID("{360DDA1F-E58E-4355-8711-25140D488497}") IService  : public IDocumented 
{
	
public:
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IPorts __fastcall GetPorts(void) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property _di_IPorts Ports = {read=GetPorts};
};

__interface IServices;
typedef System::DelphiInterface<IServices> _di_IServices;
__interface INTERFACE_UUID("{A791AA0C-C8C5-48A1-8B6A-DEF9302B7E17}") IServices  : public IXMLNodeCollection 
{
	
public:
	_di_IService operator[](int Index) { return Service[Index]; }
	
public:
	virtual _di_IService __fastcall GetService(int Index) = 0 ;
	virtual _di_IService __fastcall Add(const WideString Name) = 0 ;
	virtual _di_IService __fastcall Insert(int Index) = 0 ;
	__property _di_IService Service[int Index] = {read=GetService/*, default*/};
};

__interface IDefinition;
typedef System::DelphiInterface<IDefinition> _di_IDefinition;
__interface INTERFACE_UUID("{F3DF8F67-804A-40C4-A6C6-EDFBEA22FC47}") IDefinition  : public IXMLNode 
{
	
public:
	virtual WideString __fastcall GetTargetNamespace(void) = 0 ;
	virtual WideString __fastcall GetName(void) = 0 ;
	virtual _di_IImports __fastcall GetImports(void) = 0 ;
	virtual _di_ITypes __fastcall GetTypes(void) = 0 ;
	virtual _di_IMessages __fastcall GetMessages(void) = 0 ;
	virtual _di_IPortTypes __fastcall GetPortTypes(void) = 0 ;
	virtual _di_IBindings __fastcall GetBindings(void) = 0 ;
	virtual _di_IServices __fastcall GetServices(void) = 0 ;
	virtual void __fastcall SetTargetNamespace(WideString Value) = 0 ;
	virtual void __fastcall SetName(WideString Value) = 0 ;
	__property WideString Name = {read=GetName, write=SetName};
	__property WideString TargetNamespace = {read=GetTargetNamespace, write=SetTargetNamespace};
	__property _di_IImports Imports = {read=GetImports};
	__property _di_ITypes Types = {read=GetTypes};
	__property _di_IMessages Messages = {read=GetMessages};
	__property _di_IPortTypes PortTypes = {read=GetPortTypes};
	__property _di_IBindings Bindings = {read=GetBindings};
	__property _di_IServices Services = {read=GetServices};
};

__interface IWSDLDocument;
typedef System::DelphiInterface<IWSDLDocument> _di_IWSDLDocument;
__interface IWSDLDocument  : public IXMLDocument 
{
	
public:
	virtual _di_IDefinition __fastcall GetDefinition(void) = 0 ;
	virtual void __fastcall SetDefinition(const _di_IDefinition Value) = 0 ;
	__property _di_IDefinition Definition = {read=GetDefinition, write=SetDefinition};
};

class DELPHICLASS TDocumentation;
class PASCALIMPLEMENTATION TDocumentation : public Xmldoc::TXMLNode 
{
	typedef Xmldoc::TXMLNode inherited;
	
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TDocumentation(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TDocumentation(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TDocumentation(void) { }
	#pragma option pop
	
private:
	void *__IDocumentation;	/* Wsdlbind::IDocumentation */
	
public:
	operator IDocumentation*(void) { return (IDocumentation*)&__IDocumentation; }
	
};


class DELPHICLASS TDocumentationCollection;
class PASCALIMPLEMENTATION TDocumentationCollection : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IDocumentation __fastcall Add(const WideString Text);
	_di_IDocumentation __fastcall Insert(int Index);
	_di_IDocumentation __fastcall GetDocumentation(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TDocumentationCollection(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TDocumentationCollection(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TDocumentationCollection(void) { }
	#pragma option pop
	
private:
	void *__IDocumentationCollection;	/* Wsdlbind::IDocumentationCollection */
	
public:
	operator IDocumentationCollection*(void) { return (IDocumentationCollection*)&__IDocumentationCollection; }
	
};


class DELPHICLASS TDocumented;
class PASCALIMPLEMENTATION TDocumented : public Xmldoc::TXMLNode 
{
	typedef Xmldoc::TXMLNode inherited;
	
private:
	_di_IDocumentationCollection FDocumentation;
	
protected:
	_di_IDocumentationCollection __fastcall GetDocumentationCollection();
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TDocumented(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TDocumented(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TDocumented(void) { }
	#pragma option pop
	
private:
	void *__IDocumented;	/* Wsdlbind::IDocumented */
	
public:
	operator IDocumented*(void) { return (IDocumented*)&__IDocumented; }
	
};


class DELPHICLASS TImport;
class PASCALIMPLEMENTATION TImport : public TDocumented 
{
	typedef TDocumented inherited;
	
protected:
	WideString __fastcall GetNamespace();
	WideString __fastcall GetLocation();
	void __fastcall SetNamespace(WideString Value);
	void __fastcall SetLocation(WideString Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TImport(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TImport(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TImport(void) { }
	#pragma option pop
	
private:
	void *__IImport;	/* Wsdlbind::IImport */
	
public:
	operator IImport*(void) { return (IImport*)&__IImport; }
	
};


class DELPHICLASS TImports;
class PASCALIMPLEMENTATION TImports : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IImport __fastcall GetImport(int Index);
	_di_IImport __fastcall Add(const WideString Namespace, const WideString Location);
	_di_IImport __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TImports(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TImports(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TImports(void) { }
	#pragma option pop
	
private:
	void *__IImports;	/* Wsdlbind::IImports */
	
public:
	operator IImports*(void) { return (IImports*)&__IImports; }
	
};


class DELPHICLASS TXMLSchemaDefs;
class PASCALIMPLEMENTATION TXMLSchemaDefs : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	Xmlschema::_di_IXMLSchemaDef __fastcall Add(const WideString NamespaceURI = L"", const WideString TargetNamespace = L"");
	Xmlschema::_di_IXMLSchemaDef __fastcall GetXMLSchemaDef(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLSchemaDefs(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLSchemaDefs(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLSchemaDefs(void) { }
	#pragma option pop
	
private:
	void *__IXMLSchemaDefs;	/* Wsdlbind::IXMLSchemaDefs */
	
public:
	operator IXMLSchemaDefs*(void) { return (IXMLSchemaDefs*)&__IXMLSchemaDefs; }
	
};


class DELPHICLASS TTypes;
class PASCALIMPLEMENTATION TTypes : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IXMLSchemaDefs FSchemaDefs;
	
protected:
	_di_IXMLSchemaDefs __fastcall GetSchemaDefs();
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TTypes(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TTypes(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TTypes(void) { }
	#pragma option pop
	
private:
	void *__ITypes;	/* Wsdlbind::ITypes */
	
public:
	operator ITypes*(void) { return (ITypes*)&__ITypes; }
	
};


class DELPHICLASS TPart;
class PASCALIMPLEMENTATION TPart : public TDocumented 
{
	typedef TDocumented inherited;
	
protected:
	WideString __fastcall GetName();
	WideString __fastcall GetType_();
	WideString __fastcall GetElement();
	void __fastcall SetName(WideString Value);
	void __fastcall SetType_(WideString Value);
	void __fastcall SetElement(WideString Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TPart(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TPart(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TPart(void) { }
	#pragma option pop
	
private:
	void *__IPart;	/* Wsdlbind::IPart */
	
public:
	operator IPart*(void) { return (IPart*)&__IPart; }
	
};


class DELPHICLASS TParts;
class PASCALIMPLEMENTATION TParts : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IPart __fastcall GetPart(int Index);
	_di_IPart __fastcall Add(const WideString Name, const WideString Element, const WideString AType = L"");
	_di_IPart __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TParts(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TParts(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TParts(void) { }
	#pragma option pop
	
private:
	void *__IParts;	/* Wsdlbind::IParts */
	
public:
	operator IParts*(void) { return (IParts*)&__IParts; }
	
};


class DELPHICLASS TMessage;
class PASCALIMPLEMENTATION TMessage : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IParts FParts;
	
protected:
	WideString __fastcall GetName();
	_di_IParts __fastcall GetParts();
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TMessage(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TMessage(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TMessage(void) { }
	#pragma option pop
	
private:
	void *__IMessage;	/* Wsdlbind::IMessage */
	
public:
	operator IMessage*(void) { return (IMessage*)&__IMessage; }
	
};


class DELPHICLASS TMessages;
class PASCALIMPLEMENTATION TMessages : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IMessage __fastcall GetMessage(int Index);
	_di_IMessage __fastcall Add(const WideString Name);
	_di_IMessage __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TMessages(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TMessages(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TMessages(void) { }
	#pragma option pop
	
private:
	void *__IMessages;	/* Wsdlbind::IMessages */
	
public:
	operator IMessages*(void) { return (IMessages*)&__IMessages; }
	
};


class DELPHICLASS TParam;
class PASCALIMPLEMENTATION TParam : public TDocumented 
{
	typedef TDocumented inherited;
	
protected:
	WideString __fastcall GetName();
	WideString __fastcall GetMessage();
	void __fastcall SetName(WideString Value);
	void __fastcall SetMessage(WideString Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TParam(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TParam(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TParam(void) { }
	#pragma option pop
	
private:
	void *__IBindingInput;	/* Wsdlbind::IBindingInput */
	void *__IBindingOutput;	/* Wsdlbind::IBindingOutput */
	
public:
	operator IBindingOutput*(void) { return (IBindingOutput*)&__IBindingOutput; }
	operator IBindingInput*(void) { return (IBindingInput*)&__IBindingInput; }
	operator IParam*(void) { return (IParam*)&__IBindingOutput; }
	
};


class DELPHICLASS TFaults;
class PASCALIMPLEMENTATION TFaults : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IFault __fastcall GetFault(int Index);
	_di_IFault __fastcall Add(const WideString Name, const WideString Message);
	_di_IFault __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TFaults(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TFaults(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TFaults(void) { }
	#pragma option pop
	
private:
	void *__IFaults;	/* Wsdlbind::IFaults */
	
public:
	operator IFaults*(void) { return (IFaults*)&__IFaults; }
	
};


class DELPHICLASS TOperation;
class PASCALIMPLEMENTATION TOperation : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IFaults FFaults;
	
protected:
	WideString __fastcall GetName();
	_di_IParam __fastcall GetInput();
	_di_IParam __fastcall GetOutput();
	_di_IFaults __fastcall GetFaults();
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TOperation(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TOperation(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TOperation(void) { }
	#pragma option pop
	
private:
	void *__IOperation;	/* Wsdlbind::IOperation */
	
public:
	operator IOperation*(void) { return (IOperation*)&__IOperation; }
	
};


class DELPHICLASS TOperations;
class PASCALIMPLEMENTATION TOperations : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IOperation __fastcall Add(const WideString Name)/* overload */;
	_di_IOperation __fastcall Add(const WideString Name, const WideString InputMessage, const WideString InputName, const WideString OutputMessage)/* overload */;
	_di_IOperation __fastcall GetOperation(int Index);
	_di_IOperation __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TOperations(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TOperations(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TOperations(void) { }
	#pragma option pop
	
private:
	void *__IOperations;	/* Wsdlbind::IOperations */
	
public:
	operator IOperations*(void) { return (IOperations*)&__IOperations; }
	
};


class DELPHICLASS TPortType;
class PASCALIMPLEMENTATION TPortType : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IOperations FOperations;
	
protected:
	WideString __fastcall GetName();
	_di_IOperations __fastcall GetOperations();
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TPortType(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TPortType(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TPortType(void) { }
	#pragma option pop
	
private:
	void *__IPortType;	/* Wsdlbind::IPortType */
	
public:
	operator IPortType*(void) { return (IPortType*)&__IPortType; }
	
};


class DELPHICLASS TPortTypes;
class PASCALIMPLEMENTATION TPortTypes : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IPortType __fastcall Add(const WideString Name)/* overload */;
	_di_IPortType __fastcall Insert(int Index);
	_di_IPortType __fastcall GetPortType(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TPortTypes(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TPortTypes(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TPortTypes(void) { }
	#pragma option pop
	
private:
	void *__IPortTypes;	/* Wsdlbind::IPortTypes */
	
public:
	operator IPortTypes*(void) { return (IPortTypes*)&__IPortTypes; }
	
};


class DELPHICLASS TBindingOperation;
class PASCALIMPLEMENTATION TBindingOperation : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IFaults FFaults;
	
protected:
	WideString __fastcall GetName();
	_di_IBindingInput __fastcall GetInput();
	_di_IBindingOutput __fastcall GetOutput();
	_di_IFaults __fastcall GetFaults();
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TBindingOperation(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TBindingOperation(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TBindingOperation(void) { }
	#pragma option pop
	
private:
	void *__IBindingOperation;	/* Wsdlbind::IBindingOperation */
	
public:
	operator IBindingOperation*(void) { return (IBindingOperation*)&__IBindingOperation; }
	
};


class DELPHICLASS TBindingOperations;
class PASCALIMPLEMENTATION TBindingOperations : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IBindingOperation __fastcall GetBindingOperation(int Index);
	_di_IBindingOperation __fastcall Add(const WideString Name);
	_di_IBindingOperation __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TBindingOperations(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TBindingOperations(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TBindingOperations(void) { }
	#pragma option pop
	
private:
	void *__IBindingOperations;	/* Wsdlbind::IBindingOperations */
	
public:
	operator IBindingOperations*(void) { return (IBindingOperations*)&__IBindingOperations; }
	
};


class DELPHICLASS TBinding;
class PASCALIMPLEMENTATION TBinding : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IBindingOperations FBindingOperations;
	
protected:
	_di_IBindingOperations __fastcall GetBindingOperations();
	WideString __fastcall GetName();
	WideString __fastcall GetType_();
	void __fastcall SetName(WideString Value);
	void __fastcall SetType_(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TBinding(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TBinding(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TBinding(void) { }
	#pragma option pop
	
private:
	void *__IBinding;	/* Wsdlbind::IBinding */
	
public:
	operator IBinding*(void) { return (IBinding*)&__IBinding; }
	
};


class DELPHICLASS TBindings;
class PASCALIMPLEMENTATION TBindings : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IBinding __fastcall GetBinding(int Index);
	_di_IBinding __fastcall Add(const WideString Name, const WideString AType);
	_di_IBinding __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TBindings(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TBindings(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TBindings(void) { }
	#pragma option pop
	
private:
	void *__IBindings;	/* Wsdlbind::IBindings */
	
public:
	operator IBindings*(void) { return (IBindings*)&__IBindings; }
	
};


class DELPHICLASS TPort;
class PASCALIMPLEMENTATION TPort : public TDocumented 
{
	typedef TDocumented inherited;
	
protected:
	WideString __fastcall GetName();
	WideString __fastcall GetBinding();
	void __fastcall SetName(WideString Value);
	void __fastcall SetBinding(WideString Value);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TPort(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TPort(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TPort(void) { }
	#pragma option pop
	
private:
	void *__IPort;	/* Wsdlbind::IPort */
	
public:
	operator IPort*(void) { return (IPort*)&__IPort; }
	
};


class DELPHICLASS TPorts;
class PASCALIMPLEMENTATION TPorts : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IPort __fastcall GetPort(int Index);
	_di_IPort __fastcall Add(const WideString Name, const WideString Binding);
	_di_IPort __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TPorts(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TPorts(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TPorts(void) { }
	#pragma option pop
	
private:
	void *__IPorts;	/* Wsdlbind::IPorts */
	
public:
	operator IPorts*(void) { return (IPorts*)&__IPorts; }
	
};


class DELPHICLASS TService;
class PASCALIMPLEMENTATION TService : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IPorts FPorts;
	
protected:
	WideString __fastcall GetName();
	_di_IPorts __fastcall GetPorts();
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TService(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TService(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TService(void) { }
	#pragma option pop
	
private:
	void *__IService;	/* Wsdlbind::IService */
	
public:
	operator IService*(void) { return (IService*)&__IService; }
	
};


class DELPHICLASS TServices;
class PASCALIMPLEMENTATION TServices : public Xmldoc::TXMLNodeCollection 
{
	typedef Xmldoc::TXMLNodeCollection inherited;
	
protected:
	_di_IService __fastcall GetService(int Index);
	_di_IService __fastcall Add(const WideString Name);
	_di_IService __fastcall Insert(int Index);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TServices(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : Xmldoc::TXMLNodeCollection(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TServices(Xmldoc::TXMLNode* HostNode) : Xmldoc::TXMLNodeCollection(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TServices(void) { }
	#pragma option pop
	
private:
	void *__IServices;	/* Wsdlbind::IServices */
	
public:
	operator IServices*(void) { return (IServices*)&__IServices; }
	
};


class DELPHICLASS TDefinition;
class PASCALIMPLEMENTATION TDefinition : public TDocumented 
{
	typedef TDocumented inherited;
	
private:
	_di_IImports FImports;
	_di_IMessages FMessages;
	_di_IPortTypes FPortTypes;
	_di_IBindings FBindings;
	_di_IServices FServices;
	
protected:
	WideString __fastcall GetTargetNamespace();
	WideString __fastcall GetName();
	_di_IImports __fastcall GetImports();
	_di_ITypes __fastcall GetTypes();
	_di_IMessages __fastcall GetMessages();
	_di_IPortTypes __fastcall GetPortTypes();
	_di_IBindings __fastcall GetBindings();
	_di_IServices __fastcall GetServices();
	void __fastcall SetTargetNamespace(WideString Value);
	void __fastcall SetName(WideString Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TDefinition(const Xmldom::_di_IDOMNode ADOMNode, const Xmldoc::TXMLNode* AParentNode, const Xmldoc::TXMLDocument* OwnerDoc) : TDocumented(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TDefinition(Xmldoc::TXMLNode* HostNode) : TDocumented(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TDefinition(void) { }
	#pragma option pop
	
private:
	void *__IDefinition;	/* Wsdlbind::IDefinition */
	
public:
	operator IDefinition*(void) { return (IDefinition*)&__IDefinition; }
	
};


class DELPHICLASS TWSDLDocument;
class PASCALIMPLEMENTATION TWSDLDocument : public Xmldoc::TXMLDocument 
{
	typedef Xmldoc::TXMLDocument inherited;
	
protected:
	_di_IDefinition __fastcall GetDefinition();
	void __fastcall SetDefinition(const _di_IDefinition Value);
	DYNAMIC void __fastcall LoadData(void);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property _di_IDefinition Definition = {read=GetDefinition, write=SetDefinition};
public:
	#pragma option push -w-inl
	/* TXMLDocument.Create */ inline __fastcall TWSDLDocument(const WideString AFileName)/* overload */ : Xmldoc::TXMLDocument(AFileName) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TWSDLDocument(void) { }
	#pragma option pop
	
private:
	void *__IWSDLDocument;	/* Wsdlbind::IWSDLDocument */
	
public:
	operator IWSDLDocument*(void) { return (IWSDLDocument*)&__IWSDLDocument; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define SBinding "binding"
#define SDefinitions "definitions"
#define SFault "fault"
#define SImport "import"
#define SInput "input"
#define SLocation "location"
#define SMessage "message"
#define SNamespace "namespace"
#define SOperation "operation"
#define SOutput "output"
#define SPart "part"
#define SPort "port"
#define SPortType "portType"
#define SService "service"
#define SType "type"
#define STypes "types"
extern PACKAGE _di_IDefinition __fastcall GetDefinition(Xmldoc::TXMLDocument* Doc);
extern PACKAGE _di_IWSDLDocument __fastcall LoadWSDLDoc(const WideString FileName);
extern PACKAGE _di_IWSDLDocument __fastcall NewWSDLDoc();

}	/* namespace Wsdlbind */
using namespace Wsdlbind;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLBind
