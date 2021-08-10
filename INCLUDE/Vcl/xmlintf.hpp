// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLIntf.pas' rev: 6.00

#ifndef XMLIntfHPP
#define XMLIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <msxml.h>

namespace Xmlintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TNodeType { ntReserved, ntElement, ntAttribute, ntText, ntCData, ntEntityRef, ntEntity, ntProcessingInstr, ntComment, ntDocument, ntDocType, ntDocFragment, ntNotation };
#pragma option pop

class DELPHICLASS EXMLDocError;
class PASCALIMPLEMENTATION EXMLDocError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EXMLDocError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EXMLDocError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EXMLDocError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EXMLDocError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EXMLDocError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EXMLDocError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EXMLDocError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EXMLDocError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EXMLDocError(void) { }
	#pragma option pop
	
};


__interface IXMLNode;
typedef System::DelphiInterface<IXMLNode> _di_IXMLNode;
__interface IXMLNodeList;
typedef System::DelphiInterface<IXMLNodeList> _di_IXMLNodeList;
__interface IXMLNodeCollection;
typedef System::DelphiInterface<IXMLNodeCollection> _di_IXMLNodeCollection;
__interface IXMLDocument;
typedef System::DelphiInterface<IXMLDocument> _di_IXMLDocument;
__interface INTERFACE_UUID("{395950C0-7E5D-11D4-83DA-00C04F60B2DD}") IXMLNode  : public IInterface 
{
	
public:
	OleVariant operator[](OleVariant IndexOrName) { return ChildValues[IndexOrName]; }
	
public:
	virtual OleVariant __fastcall GetAttribute(const WideString AttrName) = 0 ;
	virtual _di_IXMLNodeList __fastcall GetAttributeNodes(void) = 0 ;
	virtual _di_IXMLNodeList __fastcall GetChildNodes(void) = 0 ;
	virtual OleVariant __fastcall GetChildValue(const OleVariant &IndexOrName) = 0 ;
	virtual _di_IXMLNodeCollection __fastcall GetCollection(void) = 0 ;
	virtual Xmldom::_di_IDOMNode __fastcall GetDOMNode(void) = 0 ;
	virtual bool __fastcall GetHasChildNodes(void) = 0 ;
	virtual bool __fastcall GetIsTextElement(void) = 0 ;
	virtual WideString __fastcall GetLocalName(void) = 0 ;
	virtual WideString __fastcall GetNamespaceURI(void) = 0 ;
	virtual WideString __fastcall GetNodeName(void) = 0 ;
	virtual TNodeType __fastcall GetNodeType(void) = 0 ;
	virtual OleVariant __fastcall GetNodeValue(void) = 0 ;
	virtual _di_IXMLDocument __fastcall GetOwnerDocument(void) = 0 ;
	virtual _di_IXMLNode __fastcall GetParentNode(void) = 0 ;
	virtual WideString __fastcall GetPrefix(void) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual WideString __fastcall GetText(void) = 0 ;
	virtual WideString __fastcall GetXML(void) = 0 ;
	virtual void __fastcall SetAttribute(const WideString AttrName, const OleVariant &Value) = 0 ;
	virtual void __fastcall SetChildValue(const OleVariant &IndexOrName, const OleVariant &Value) = 0 ;
	virtual void __fastcall SetNodeValue(const OleVariant &Value) = 0 ;
	virtual void __fastcall SetReadOnly(const bool Value) = 0 ;
	virtual void __fastcall SetText(const WideString Value) = 0 ;
	virtual _di_IXMLNode __fastcall AddChild(const WideString TagName, int Index = 0xffffffff) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI, bool GenPrefix = false, int Index = 0xffffffff) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall CloneNode(bool Deep) = 0 ;
	virtual void __fastcall DeclareNamespace(const WideString Prefix, const WideString URI) = 0 ;
	virtual WideString __fastcall FindNamespaceURI(const WideString TagOrPrefix) = 0 ;
	virtual _di_IXMLNode __fastcall FindNamespaceDecl(const WideString NamespaceURI) = 0 ;
	virtual OleVariant __fastcall GetAttributeNS(const WideString AttrName, const WideString NamespaceURI) = 0 ;
	virtual bool __fastcall HasAttribute(const WideString Name) = 0 /* overload */;
	virtual bool __fastcall HasAttribute(const WideString Name, const WideString NamespaceURI) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall NextSibling(void) = 0 ;
	virtual void __fastcall Normalize(void) = 0 ;
	virtual _di_IXMLNode __fastcall PreviousSibling(void) = 0 ;
	virtual void __fastcall Resync(void) = 0 ;
	virtual void __fastcall SetAttributeNS(const WideString AttrName, const WideString NamespaceURI, const OleVariant &Value) = 0 ;
	virtual void __fastcall TransformNode(const _di_IXMLNode stylesheet, WideString &output) = 0 /* overload */;
	virtual void __fastcall TransformNode(const _di_IXMLNode stylesheet, const _di_IXMLDocument output) = 0 /* overload */;
	__property OleVariant Attributes[WideString AttrName] = {read=GetAttribute, write=SetAttribute};
	__property _di_IXMLNodeList AttributeNodes = {read=GetAttributeNodes};
	__property _di_IXMLNodeList ChildNodes = {read=GetChildNodes};
	__property OleVariant ChildValues[OleVariant IndexOrName] = {read=GetChildValue, write=SetChildValue/*, default*/};
	__property _di_IXMLNodeCollection Collection = {read=GetCollection};
	__property Xmldom::_di_IDOMNode DOMNode = {read=GetDOMNode};
	__property _di_IXMLDocument OwnerDocument = {read=GetOwnerDocument};
	__property bool HasChildNodes = {read=GetHasChildNodes};
	__property bool IsTextElement = {read=GetIsTextElement};
	__property WideString LocalName = {read=GetLocalName};
	__property WideString NamespaceURI = {read=GetNamespaceURI};
	__property WideString NodeName = {read=GetNodeName};
	__property TNodeType NodeType = {read=GetNodeType};
	__property OleVariant NodeValue = {read=GetNodeValue, write=SetNodeValue};
	__property _di_IXMLNode ParentNode = {read=GetParentNode};
	__property WideString Prefix = {read=GetPrefix};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly};
	__property WideString Text = {read=GetText, write=SetText};
	__property WideString XML = {read=GetXML};
};

__interface INTERFACE_UUID("{395950C1-7E5D-11D4-83DA-00C04F60B2DD}") IXMLNodeList  : public IInterface 
{
	
public:
	_di_IXMLNode operator[](OleVariant IndexOrName) { return Nodes[IndexOrName]; }
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLNode __fastcall GetNode(const OleVariant &IndexOrName) = 0 ;
	virtual int __fastcall GetUpdateCount(void) = 0 ;
	virtual int __fastcall Add(const _di_IXMLNode Node) = 0 ;
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual int __fastcall Delete(const int Index) = 0 /* overload */;
	virtual int __fastcall Delete(const WideString Name) = 0 /* overload */;
	virtual int __fastcall Delete(const WideString Name, const WideString NamespaceURI) = 0 /* overload */;
	virtual void __fastcall EndUpdate(void) = 0 ;
	virtual _di_IXMLNode __fastcall First(void) = 0 ;
	virtual _di_IXMLNode __fastcall FindNode(WideString NodeName) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall FindNode(WideString NodeName, WideString NamespaceURI) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall FindNode(const GUID &ChildNodeType) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall FindSibling(const _di_IXMLNode Node, int Delta) = 0 ;
	virtual _di_IXMLNode __fastcall Get(int Index) = 0 ;
	virtual int __fastcall IndexOf(const _di_IXMLNode Node) = 0 /* overload */;
	virtual int __fastcall IndexOf(const WideString Name) = 0 /* overload */;
	virtual int __fastcall IndexOf(const WideString Name, const WideString NamespaceURI) = 0 /* overload */;
	virtual void __fastcall Insert(int Index, const _di_IXMLNode Node) = 0 ;
	virtual _di_IXMLNode __fastcall Last(void) = 0 ;
	virtual int __fastcall Remove(const _di_IXMLNode Node) = 0 ;
	virtual _di_IXMLNode __fastcall ReplaceNode(const _di_IXMLNode OldNode, const _di_IXMLNode NewNode) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLNode Nodes[OleVariant IndexOrName] = {read=GetNode/*, default*/};
	__property int UpdateCount = {read=GetUpdateCount};
};

__interface INTERFACE_UUID("{395950C2-7E5D-11D4-83DA-00C04F60B2DD}") IXMLNodeCollection  : public IXMLNode 
{
	
public:
	_di_IXMLNode operator[](int Index) { return Nodes[Index]; }
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLNode __fastcall GetNode(int Index) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	virtual int __fastcall Remove(const _di_IXMLNode Node) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLNode Nodes[int Index] = {read=GetNode/*, default*/};
};

#pragma option push -b-
enum TXMLDocOption { doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl, doAutoSave };
#pragma option pop

typedef Set<TXMLDocOption, doNodeAutoCreate, doAutoSave>  TXMLDocOptions;

#pragma option push -b-
enum TParseOption { poResolveExternals, poValidateOnParse, poPreserveWhiteSpace, poAsyncLoad };
#pragma option pop

typedef Set<TParseOption, poResolveExternals, poAsyncLoad>  TParseOptions;

#pragma option push -b-
enum TXMLEncodingType { xetUnknown, xetUCS_4BE, xetUCS_4LE, xetUCS_4Order2134, xetUCS_4Order3412, xetUTF_16BE, xetUTF_16LE, xetUTF_8, xetUCS_4Like, xetUTF_16BELike, xetUTF_16LELike, xetUTF_8Like, xetEBCDICLike };
#pragma option pop

__interface INTERFACE_UUID("{395950C3-7E5D-11D4-83DA-00C04F60B2DD}") IXMLDocument  : public IInterface 
{
	
public:
	virtual bool __fastcall GetActive(void) = 0 ;
	virtual int __fastcall GetAsyncLoadState(void) = 0 ;
	virtual _di_IXMLNodeList __fastcall GetChildNodes(void) = 0 ;
	virtual _di_IXMLNode __fastcall GetDocumentElement(void) = 0 ;
	virtual _di_IXMLNode __fastcall GetDocumentNode(void) = 0 ;
	virtual Xmldom::_di_IDOMDocument __fastcall GetDOMDocument(void) = 0 ;
	virtual WideString __fastcall GetEncoding(void) = 0 ;
	virtual WideString __fastcall GetFileName(void) = 0 ;
	virtual bool __fastcall GetModified(void) = 0 ;
	virtual WideString __fastcall GetNodeIndentStr(void) = 0 ;
	virtual TXMLDocOptions __fastcall GetOptions(void) = 0 ;
	virtual TParseOptions __fastcall GetParseOptions(void) = 0 ;
	virtual WideString __fastcall GetSchemaRef(void) = 0 ;
	virtual WideString __fastcall GetStandAlone(void) = 0 ;
	virtual WideString __fastcall GetVersion(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetXML(void) = 0 ;
	virtual void __fastcall SetActive(const bool Value) = 0 ;
	virtual void __fastcall SetDocumentElement(const _di_IXMLNode Value) = 0 ;
	virtual void __fastcall SetDOMDocument(const Xmldom::_di_IDOMDocument Value) = 0 ;
	virtual void __fastcall SetEncoding(const WideString Value) = 0 ;
	virtual void __fastcall SetFileName(const WideString Value) = 0 ;
	virtual void __fastcall SetNodeIndentStr(const WideString Value) = 0 ;
	virtual void __fastcall SetOptions(const TXMLDocOptions Value) = 0 ;
	virtual void __fastcall SetParseOptions(const TParseOptions Value) = 0 ;
	virtual void __fastcall SetStandAlone(const WideString Value) = 0 ;
	virtual void __fastcall SetVersion(const WideString Value) = 0 ;
	virtual void __fastcall SetXML(const Classes::TStrings* Value) = 0 ;
	virtual _di_IXMLNode __fastcall AddChild(const WideString TagName) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI) = 0 /* overload */;
	virtual _di_IXMLNode __fastcall CreateElement(const WideString TagOrData, const WideString NamespaceURI) = 0 ;
	virtual _di_IXMLNode __fastcall CreateNode(const WideString NameOrData, TNodeType NodeType = (TNodeType)(0x1), const WideString AddlData = L"") = 0 ;
	virtual WideString __fastcall GeneratePrefix(const _di_IXMLNode Node) = 0 ;
	virtual _di_IXMLNode __fastcall GetDocBinding(const WideString TagName, TMetaClass* DocNodeClass, WideString NamespaceURI = L"") = 0 ;
	virtual bool __fastcall IsEmptyDoc(void) = 0 ;
	virtual void __fastcall LoadFromFile(const WideString AFileName) = 0 ;
	virtual void __fastcall LoadFromStream(const Classes::TStream* Stream, TXMLEncodingType EncodingType = (TXMLEncodingType)(0x0)) = 0 ;
	virtual void __fastcall LoadFromXML(const AnsiString XML) = 0 /* overload */;
	virtual void __fastcall LoadFromXML(const WideString XML) = 0 /* overload */;
	virtual void __fastcall Refresh(void) = 0 ;
	virtual void __fastcall RegisterDocBinding(const WideString TagName, TMetaClass* DocNodeClass, WideString NamespaceURI = L"") = 0 ;
	virtual void __fastcall Resync(void) = 0 ;
	virtual void __fastcall SaveToFile(const WideString AFileName) = 0 ;
	virtual void __fastcall SaveToStream(const Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SaveToXML(WideString &XML) = 0 /* overload */;
	virtual void __fastcall SaveToXML(AnsiString &XML) = 0 /* overload */;
	virtual void __fastcall SetOnAsyncLoad(const Xmldom::TAsyncEventHandler Value) = 0 ;
	__property bool Active = {read=GetActive, write=SetActive};
	__property int AsyncLoadState = {read=GetAsyncLoadState};
	__property _di_IXMLNodeList ChildNodes = {read=GetChildNodes};
	__property _di_IXMLNode DocumentElement = {read=GetDocumentElement, write=SetDocumentElement};
	__property Xmldom::_di_IDOMDocument DOMDocument = {read=GetDOMDocument, write=SetDOMDocument};
	__property WideString Encoding = {read=GetEncoding, write=SetEncoding};
	__property WideString FileName = {read=GetFileName, write=SetFileName};
	__property bool Modified = {read=GetModified};
	__property _di_IXMLNode Node = {read=GetDocumentNode};
	__property WideString NodeIndentStr = {read=GetNodeIndentStr, write=SetNodeIndentStr};
	__property TXMLDocOptions Options = {read=GetOptions, write=SetOptions};
	__property TParseOptions ParseOptions = {read=GetParseOptions, write=SetParseOptions};
	__property WideString SchemaRef = {read=GetSchemaRef};
	__property WideString StandAlone = {read=GetStandAlone, write=SetStandAlone};
	__property WideString Version = {read=GetVersion, write=SetVersion};
	__property Classes::TStrings* XML = {read=GetXML, write=SetXML};
};

typedef AnsiString XMLIntf__2[13];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString NodeTypeNames[13];

}	/* namespace Xmlintf */
using namespace Xmlintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLIntf
