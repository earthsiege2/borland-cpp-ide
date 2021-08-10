// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'xmldom.pas' rev: 6.00

#ifndef xmldomHPP
#define xmldomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmldom
{
//-- type declarations -------------------------------------------------------
typedef WideString DOMString;

typedef __int64 DOMTimeStamp;

class DELPHICLASS DOMException;
class PASCALIMPLEMENTATION DOMException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	Word code;
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall DOMException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall DOMException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall DOMException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall DOMException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall DOMException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall DOMException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall DOMException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall DOMException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~DOMException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EDOMParseError;
__interface IDOMParseError;
typedef System::DelphiInterface<IDOMParseError> _di_IDOMParseError;
__interface INTERFACE_UUID("{2BF4C0F2-096E-11D4-83DA-00C04F60B2DD}") IDOMParseError  : public IInterface 
{
	
public:
	virtual int __fastcall get_errorCode(void) = 0 ;
	virtual HRESULT __safecall get_url(WideString &get_url_result) = 0 ;
	virtual HRESULT __safecall get_reason(WideString &get_reason_result) = 0 ;
	virtual HRESULT __safecall get_srcText(WideString &get_srcText_result) = 0 ;
	virtual int __fastcall get_line(void) = 0 ;
	virtual int __fastcall get_linepos(void) = 0 ;
	virtual int __fastcall get_filepos(void) = 0 ;
	__property int errorCode = {read=get_errorCode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_url() { WideString r; HRESULT hr = get_url(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString url = {read=_scw_get_url};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_reason() { WideString r; HRESULT hr = get_reason(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString reason = {read=_scw_get_reason};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_srcText() { WideString r; HRESULT hr = get_srcText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString srcText = {read=_scw_get_srcText};
	__property int line = {read=get_line};
	__property int linePos = {read=get_linepos};
	__property int filePos = {read=get_filepos};
};

class PASCALIMPLEMENTATION EDOMParseError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	_di_IDOMParseError FParseError;
	int __fastcall GetFilePos(void);
	int __fastcall GetLine(void);
	int __fastcall GetLinePos(void);
	WideString __fastcall GetReason();
	WideString __fastcall GetSrcText();
	WideString __fastcall GetURL();
	int __fastcall GetErrorCode(void);
	
protected:
	__property _di_IDOMParseError ParseError = {read=FParseError};
	
public:
	__fastcall EDOMParseError(const _di_IDOMParseError ParseError, const AnsiString Msg);
	__property int ErrorCode = {read=GetErrorCode, nodefault};
	__property WideString URL = {read=GetURL};
	__property WideString Reason = {read=GetReason};
	__property WideString SrcText = {read=GetSrcText};
	__property int Line = {read=GetLine, nodefault};
	__property int LinePos = {read=GetLinePos, nodefault};
	__property int FilePos = {read=GetFilePos, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDOMParseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDOMParseError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDOMParseError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDOMParseError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDOMParseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDOMParseError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDOMParseError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDOMParseError(void) { }
	#pragma option pop
	
};


__interface IDOMImplementation;
typedef System::DelphiInterface<IDOMImplementation> _di_IDOMImplementation;
__interface IDOMDocumentType;
typedef System::DelphiInterface<IDOMDocumentType> _di_IDOMDocumentType;
__interface IDOMDocument;
typedef System::DelphiInterface<IDOMDocument> _di_IDOMDocument;
__interface INTERFACE_UUID("{2BF4C0E0-096E-11D4-83DA-00C04F60B2DD}") IDOMImplementation  : public IInterface 
{
	
public:
	virtual Word __fastcall hasFeature(const WideString feature, const WideString version) = 0 ;
	virtual HRESULT __safecall createDocumentType(const WideString qualifiedName, const WideString publicId, const WideString systemId, _di_IDOMDocumentType &createDocumentType_result) = 0 ;
	virtual HRESULT __safecall createDocument(const WideString namespaceURI, const WideString qualifiedName, _di_IDOMDocumentType doctype, _di_IDOMDocument &createDocument_result) = 0 ;
};

__interface IDOMNode;
typedef System::DelphiInterface<IDOMNode> _di_IDOMNode;
__interface IDOMNodeList;
typedef System::DelphiInterface<IDOMNodeList> _di_IDOMNodeList;
__interface IDOMNamedNodeMap;
typedef System::DelphiInterface<IDOMNamedNodeMap> _di_IDOMNamedNodeMap;
__interface INTERFACE_UUID("{2BF4C0E1-096E-11D4-83DA-00C04F60B2DD}") IDOMNode  : public IInterface 
{
	
public:
	virtual HRESULT __safecall get_nodeName(WideString &get_nodeName_result) = 0 ;
	virtual HRESULT __safecall get_nodeValue(WideString &get_nodeValue_result) = 0 ;
	virtual void __fastcall set_nodeValue(WideString value) = 0 ;
	virtual HRESULT __safecall get_nodeType(Word &get_nodeType_result) = 0 ;
	virtual HRESULT __safecall get_parentNode(_di_IDOMNode &get_parentNode_result) = 0 ;
	virtual HRESULT __safecall get_childNodes(_di_IDOMNodeList &get_childNodes_result) = 0 ;
	virtual HRESULT __safecall get_firstChild(_di_IDOMNode &get_firstChild_result) = 0 ;
	virtual HRESULT __safecall get_lastChild(_di_IDOMNode &get_lastChild_result) = 0 ;
	virtual HRESULT __safecall get_previousSibling(_di_IDOMNode &get_previousSibling_result) = 0 ;
	virtual HRESULT __safecall get_nextSibling(_di_IDOMNode &get_nextSibling_result) = 0 ;
	virtual HRESULT __safecall get_attributes(_di_IDOMNamedNodeMap &get_attributes_result) = 0 ;
	virtual HRESULT __safecall get_ownerDocument(_di_IDOMDocument &get_ownerDocument_result) = 0 ;
	virtual HRESULT __safecall get_namespaceURI(WideString &get_namespaceURI_result) = 0 ;
	virtual HRESULT __safecall get_prefix(WideString &get_prefix_result) = 0 ;
	virtual HRESULT __safecall get_localName(WideString &get_localName_result) = 0 ;
	virtual HRESULT __safecall insertBefore(const _di_IDOMNode newChild, const _di_IDOMNode refChild, _di_IDOMNode &insertBefore_result) = 0 ;
	virtual HRESULT __safecall replaceChild(const _di_IDOMNode newChild, const _di_IDOMNode oldChild, _di_IDOMNode &replaceChild_result) = 0 ;
	virtual HRESULT __safecall removeChild(const _di_IDOMNode childNode, _di_IDOMNode &removeChild_result) = 0 ;
	virtual HRESULT __safecall appendChild(const _di_IDOMNode newChild, _di_IDOMNode &appendChild_result) = 0 ;
	virtual HRESULT __safecall hasChildNodes(Word &hasChildNodes_result) = 0 ;
	virtual HRESULT __safecall cloneNode(Word deep, _di_IDOMNode &cloneNode_result) = 0 ;
	virtual void __fastcall normalize(void) = 0 ;
	virtual Word __fastcall supports(const WideString feature, const WideString version) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_nodeName() { WideString r; HRESULT hr = get_nodeName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString nodeName = {read=_scw_get_nodeName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_nodeValue() { WideString r; HRESULT hr = get_nodeValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString nodeValue = {read=_scw_get_nodeValue, write=set_nodeValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_get_nodeType() { Word r; HRESULT hr = get_nodeType(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word nodeType = {read=_scw_get_nodeType};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_parentNode() { _di_IDOMNode r; HRESULT hr = get_parentNode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode parentNode = {read=_scw_get_parentNode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNodeList _scw_get_childNodes() { _di_IDOMNodeList r; HRESULT hr = get_childNodes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNodeList childNodes = {read=_scw_get_childNodes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_firstChild() { _di_IDOMNode r; HRESULT hr = get_firstChild(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode firstChild = {read=_scw_get_firstChild};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_lastChild() { _di_IDOMNode r; HRESULT hr = get_lastChild(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode lastChild = {read=_scw_get_lastChild};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_previousSibling() { _di_IDOMNode r; HRESULT hr = get_previousSibling(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode previousSibling = {read=_scw_get_previousSibling};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_nextSibling() { _di_IDOMNode r; HRESULT hr = get_nextSibling(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode nextSibling = {read=_scw_get_nextSibling};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNamedNodeMap _scw_get_attributes() { _di_IDOMNamedNodeMap r; HRESULT hr = get_attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNamedNodeMap attributes = {read=_scw_get_attributes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMDocument _scw_get_ownerDocument() { _di_IDOMDocument r; HRESULT hr = get_ownerDocument(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMDocument ownerDocument = {read=_scw_get_ownerDocument};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_namespaceURI() { WideString r; HRESULT hr = get_namespaceURI(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString namespaceURI = {read=_scw_get_namespaceURI};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_prefix() { WideString r; HRESULT hr = get_prefix(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString prefix = {read=_scw_get_prefix};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_localName() { WideString r; HRESULT hr = get_localName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString localName = {read=_scw_get_localName};
};

__interface INTERFACE_UUID("{2BF4C0E2-096E-11D4-83DA-00C04F60B2DD}") IDOMNodeList  : public IInterface 
{
	
public:
	_di_IDOMNode operator[](int index) { return item[index]; }
	
public:
	virtual HRESULT __safecall get_item(int index, _di_IDOMNode &get_item_result) = 0 ;
	virtual HRESULT __safecall get_length(int &get_length_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_item(int index) { _di_IDOMNode r; HRESULT hr = get_item(index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode item[int index] = {read=_scw_get_item/*, default*/};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_get_length() { int r; HRESULT hr = get_length(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int length = {read=_scw_get_length};
};

__interface INTERFACE_UUID("{2BF4C0E3-096E-11D4-83DA-00C04F60B2DD}") IDOMNamedNodeMap  : public IInterface 
{
	
public:
	_di_IDOMNode operator[](int index) { return item[index]; }
	
public:
	virtual HRESULT __safecall get_item(int index, _di_IDOMNode &get_item_result) = 0 ;
	virtual int __fastcall get_length(void) = 0 ;
	virtual HRESULT __safecall getNamedItem(const WideString name, _di_IDOMNode &getNamedItem_result) = 0 ;
	virtual HRESULT __safecall setNamedItem(const _di_IDOMNode arg, _di_IDOMNode &setNamedItem_result) = 0 ;
	virtual HRESULT __safecall removeNamedItem(const WideString name, _di_IDOMNode &removeNamedItem_result) = 0 ;
	virtual HRESULT __safecall getNamedItemNS(const WideString namespaceURI, const WideString localName, _di_IDOMNode &getNamedItemNS_result) = 0 ;
	virtual HRESULT __safecall setNamedItemNS(const _di_IDOMNode arg, _di_IDOMNode &setNamedItemNS_result) = 0 ;
	virtual HRESULT __safecall removeNamedItemNS(const WideString namespaceURI, const WideString localName, _di_IDOMNode &removeNamedItemNS_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNode _scw_get_item(int index) { _di_IDOMNode r; HRESULT hr = get_item(index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNode item[int index] = {read=_scw_get_item/*, default*/};
	__property int length = {read=get_length};
};

__interface IDOMCharacterData;
typedef System::DelphiInterface<IDOMCharacterData> _di_IDOMCharacterData;
__interface INTERFACE_UUID("{2BF4C0E4-096E-11D4-83DA-00C04F60B2DD}") IDOMCharacterData  : public IDOMNode 
{
	
public:
	virtual WideString __fastcall get_data(void) = 0 ;
	virtual void __fastcall set_data(const WideString data) = 0 ;
	virtual int __fastcall get_length(void) = 0 ;
	virtual WideString __fastcall substringData(int offset, int count) = 0 ;
	virtual void __fastcall appendData(const WideString data) = 0 ;
	virtual void __fastcall insertData(int offset, const WideString data) = 0 ;
	virtual void __fastcall deleteData(int offset, int count) = 0 ;
	virtual void __fastcall replaceData(int offset, int count, const WideString data) = 0 ;
	__property WideString data = {read=get_data, write=set_data};
	__property int length = {read=get_length};
};

__interface IDOMAttr;
typedef System::DelphiInterface<IDOMAttr> _di_IDOMAttr;
__interface IDOMElement;
typedef System::DelphiInterface<IDOMElement> _di_IDOMElement;
__interface INTERFACE_UUID("{2BF4C0E5-096E-11D4-83DA-00C04F60B2DD}") IDOMAttr  : public IDOMNode 
{
	
public:
	virtual WideString __fastcall get_name(void) = 0 ;
	virtual Word __fastcall get_specified(void) = 0 ;
	virtual WideString __fastcall get_value(void) = 0 ;
	virtual void __fastcall set_value(const WideString attributeValue) = 0 ;
	virtual _di_IDOMElement __fastcall get_ownerElement(void) = 0 ;
	__property WideString name = {read=get_name};
	__property Word specified = {read=get_specified};
	__property WideString value = {read=get_value, write=set_value};
	__property _di_IDOMElement ownerElement = {read=get_ownerElement};
};

__interface INTERFACE_UUID("{2BF4C0E6-096E-11D4-83DA-00C04F60B2DD}") IDOMElement  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_tagName(WideString &get_tagName_result) = 0 ;
	virtual HRESULT __safecall getAttribute(const WideString name, WideString &getAttribute_result) = 0 ;
	virtual void __fastcall setAttribute(const WideString name, const WideString value) = 0 ;
	virtual void __fastcall removeAttribute(const WideString name) = 0 ;
	virtual HRESULT __safecall getAttributeNode(const WideString name, _di_IDOMAttr &getAttributeNode_result) = 0 ;
	virtual HRESULT __safecall setAttributeNode(const _di_IDOMAttr newAttr, _di_IDOMAttr &setAttributeNode_result) = 0 ;
	virtual HRESULT __safecall removeAttributeNode(const _di_IDOMAttr oldAttr, _di_IDOMAttr &removeAttributeNode_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagName(const WideString name, _di_IDOMNodeList &getElementsByTagName_result) = 0 ;
	virtual HRESULT __safecall getAttributeNS(const WideString namespaceURI, const WideString localName, WideString &getAttributeNS_result) = 0 ;
	virtual void __fastcall setAttributeNS(const WideString namespaceURI, const WideString qulifiedName, const WideString value) = 0 ;
	virtual void __fastcall removeAttributeNS(const WideString namespaceURI, const WideString localName) = 0 ;
	virtual HRESULT __safecall getAttributeNodeNS(const WideString namespaceURI, const WideString localName, _di_IDOMAttr &getAttributeNodeNS_result) = 0 ;
	virtual HRESULT __safecall setAttributeNodeNS(const _di_IDOMAttr newAttr, _di_IDOMAttr &setAttributeNodeNS_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName, _di_IDOMNodeList &getElementsByTagNameNS_result) = 0 ;
	virtual HRESULT __safecall hasAttribute(const WideString name, Word &hasAttribute_result) = 0 ;
	virtual Word __fastcall hasAttributeNS(const WideString namespaceURI, const WideString localName) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_tagName() { WideString r; HRESULT hr = get_tagName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString tagName = {read=_scw_get_tagName};
};

__interface IDOMText;
typedef System::DelphiInterface<IDOMText> _di_IDOMText;
__interface INTERFACE_UUID("{2BF4C0E7-096E-11D4-83DA-00C04F60B2DD}") IDOMText  : public IDOMCharacterData 
{
	
public:
	virtual HRESULT __safecall splitText(int offset, _di_IDOMText &splitText_result) = 0 ;
};

__interface IDOMComment;
typedef System::DelphiInterface<IDOMComment> _di_IDOMComment;
__interface INTERFACE_UUID("{2BF4C0E8-096E-11D4-83DA-00C04F60B2DD}") IDOMComment  : public IDOMCharacterData 
{
	
};

__interface IDOMCDATASection;
typedef System::DelphiInterface<IDOMCDATASection> _di_IDOMCDATASection;
__interface INTERFACE_UUID("{2BF4C0E9-096E-11D4-83DA-00C04F60B2DD}") IDOMCDATASection  : public IDOMText 
{
	
};

__interface INTERFACE_UUID("{2BF4C0EA-096E-11D4-83DA-00C04F60B2DD}") IDOMDocumentType  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_name(WideString &get_name_result) = 0 ;
	virtual HRESULT __safecall get_entities(_di_IDOMNamedNodeMap &get_entities_result) = 0 ;
	virtual HRESULT __safecall get_notations(_di_IDOMNamedNodeMap &get_notations_result) = 0 ;
	virtual HRESULT __safecall get_publicId(WideString &get_publicId_result) = 0 ;
	virtual HRESULT __safecall get_systemId(WideString &get_systemId_result) = 0 ;
	virtual HRESULT __safecall get_internalSubset(WideString &get_internalSubset_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_name() { WideString r; HRESULT hr = get_name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString name = {read=_scw_get_name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNamedNodeMap _scw_get_entities() { _di_IDOMNamedNodeMap r; HRESULT hr = get_entities(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNamedNodeMap entities = {read=_scw_get_entities};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMNamedNodeMap _scw_get_notations() { _di_IDOMNamedNodeMap r; HRESULT hr = get_notations(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMNamedNodeMap notations = {read=_scw_get_notations};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_publicId() { WideString r; HRESULT hr = get_publicId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString publicId = {read=_scw_get_publicId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_systemId() { WideString r; HRESULT hr = get_systemId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString systemId = {read=_scw_get_systemId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_internalSubset() { WideString r; HRESULT hr = get_internalSubset(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString internalSubset = {read=_scw_get_internalSubset};
};

__interface IDOMNotation;
typedef System::DelphiInterface<IDOMNotation> _di_IDOMNotation;
__interface INTERFACE_UUID("{2BF4C0EB-096E-11D4-83DA-00C04F60B2DD}") IDOMNotation  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_publicId(WideString &get_publicId_result) = 0 ;
	virtual HRESULT __safecall get_systemId(WideString &get_systemId_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_publicId() { WideString r; HRESULT hr = get_publicId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString publicId = {read=_scw_get_publicId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_systemId() { WideString r; HRESULT hr = get_systemId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString systemId = {read=_scw_get_systemId};
};

__interface IDOMEntity;
typedef System::DelphiInterface<IDOMEntity> _di_IDOMEntity;
__interface INTERFACE_UUID("{2BF4C0EC-096E-11D4-83DA-00C04F60B2DD}") IDOMEntity  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_publicId(WideString &get_publicId_result) = 0 ;
	virtual HRESULT __safecall get_systemId(WideString &get_systemId_result) = 0 ;
	virtual HRESULT __safecall get_notationName(WideString &get_notationName_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_publicId() { WideString r; HRESULT hr = get_publicId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString publicId = {read=_scw_get_publicId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_systemId() { WideString r; HRESULT hr = get_systemId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString systemId = {read=_scw_get_systemId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_notationName() { WideString r; HRESULT hr = get_notationName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString notationName = {read=_scw_get_notationName};
};

__interface IDOMEntityReference;
typedef System::DelphiInterface<IDOMEntityReference> _di_IDOMEntityReference;
__interface INTERFACE_UUID("{2BF4C0ED-096E-11D4-83DA-00C04F60B2DD}") IDOMEntityReference  : public IDOMNode 
{
	
};

__interface IDOMProcessingInstruction;
typedef System::DelphiInterface<IDOMProcessingInstruction> _di_IDOMProcessingInstruction;
__interface INTERFACE_UUID("{2BF4C0EE-096E-11D4-83DA-00C04F60B2DD}") IDOMProcessingInstruction  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_target(WideString &get_target_result) = 0 ;
	virtual HRESULT __safecall get_data(WideString &get_data_result) = 0 ;
	virtual void __fastcall set_data(const WideString value) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_target() { WideString r; HRESULT hr = get_target(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString target = {read=_scw_get_target};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_data() { WideString r; HRESULT hr = get_data(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString data = {read=_scw_get_data, write=set_data};
};

__interface IDOMDocumentFragment;
typedef System::DelphiInterface<IDOMDocumentFragment> _di_IDOMDocumentFragment;
__interface INTERFACE_UUID("{2BF4C0EF-096E-11D4-83DA-00C04F60B2DD}") IDOMDocumentFragment  : public IDOMNode 
{
	
};

__interface INTERFACE_UUID("{2BF4C0F0-096E-11D4-83DA-00C04F60B2DD}") IDOMDocument  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_doctype(_di_IDOMDocumentType &get_doctype_result) = 0 ;
	virtual HRESULT __safecall get_domImplementation(_di_IDOMImplementation &get_domImplementation_result) = 0 ;
	virtual HRESULT __safecall get_documentElement(_di_IDOMElement &get_documentElement_result) = 0 ;
	virtual void __fastcall set_documentElement(const _di_IDOMElement Element) = 0 ;
	virtual HRESULT __safecall createElement(const WideString tagName, _di_IDOMElement &createElement_result) = 0 ;
	virtual HRESULT __safecall createDocumentFragment(_di_IDOMDocumentFragment &createDocumentFragment_result) = 0 ;
	virtual HRESULT __safecall createTextNode(const WideString data, _di_IDOMText &createTextNode_result) = 0 ;
	virtual HRESULT __safecall createComment(const WideString data, _di_IDOMComment &createComment_result) = 0 ;
	virtual HRESULT __safecall createCDATASection(const WideString data, _di_IDOMCDATASection &createCDATASection_result) = 0 ;
	virtual HRESULT __safecall createProcessingInstruction(const WideString target, const WideString data, _di_IDOMProcessingInstruction &createProcessingInstruction_result) = 0 ;
	virtual HRESULT __safecall createAttribute(const WideString name, _di_IDOMAttr &createAttribute_result) = 0 ;
	virtual HRESULT __safecall createEntityReference(const WideString name, _di_IDOMEntityReference &createEntityReference_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagName(const WideString tagName, _di_IDOMNodeList &getElementsByTagName_result) = 0 ;
	virtual HRESULT __safecall importNode(_di_IDOMNode importedNode, Word deep, _di_IDOMNode &importNode_result) = 0 ;
	virtual HRESULT __safecall createElementNS(const WideString namespaceURI, const WideString qualifiedName, _di_IDOMElement &createElementNS_result) = 0 ;
	virtual HRESULT __safecall createAttributeNS(const WideString namespaceURI, const WideString qualifiedName, _di_IDOMAttr &createAttributeNS_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName, _di_IDOMNodeList &getElementsByTagNameNS_result) = 0 ;
	virtual _di_IDOMElement __fastcall getElementById(const WideString elementId) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMDocumentType _scw_get_doctype() { _di_IDOMDocumentType r; HRESULT hr = get_doctype(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMDocumentType doctype = {read=_scw_get_doctype};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMImplementation _scw_get_domImplementation() { _di_IDOMImplementation r; HRESULT hr = get_domImplementation(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMImplementation domImplementation = {read=_scw_get_domImplementation};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDOMElement _scw_get_documentElement() { _di_IDOMElement r; HRESULT hr = get_documentElement(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDOMElement documentElement = {read=_scw_get_documentElement, write=set_documentElement};
};

__interface IDOMNodeSelect;
typedef System::DelphiInterface<IDOMNodeSelect> _di_IDOMNodeSelect;
__interface INTERFACE_UUID("{2A3602E0-2B39-11D4-83DA-00C04F60B2DD}") IDOMNodeSelect  : public IInterface 
{
	
public:
	virtual HRESULT __safecall selectNode(const WideString nodePath, _di_IDOMNode &selectNode_result) = 0 ;
	virtual HRESULT __safecall selectNodes(const WideString nodePath, _di_IDOMNodeList &selectNodes_result) = 0 ;
};

__interface IDOMNodeEx;
typedef System::DelphiInterface<IDOMNodeEx> _di_IDOMNodeEx;
__interface INTERFACE_UUID("{B06BFFDD-337B-48DA-980B-6F7AA8ADE85C}") IDOMNodeEx  : public IDOMNode 
{
	
public:
	virtual HRESULT __safecall get_text(WideString &get_text_result) = 0 ;
	virtual HRESULT __safecall get_xml(WideString &get_xml_result) = 0 ;
	virtual HRESULT __safecall set_text(const WideString Value) = 0 ;
	virtual void __fastcall transformNode(const _di_IDOMNode stylesheet, WideString &output) = 0 /* overload */;
	virtual void __fastcall transformNode(const _di_IDOMNode stylesheet, const _di_IDOMDocument output) = 0 /* overload */;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_text() { WideString r; HRESULT hr = get_text(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString text = {read=_scw_get_text, write=set_text};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_xml() { WideString r; HRESULT hr = get_xml(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString xml = {read=_scw_get_xml};
};

typedef void __fastcall (__closure *TAsyncEventHandler)(System::TObject* Sender, int AsyncLoadState);

__interface IDOMPersist;
typedef System::DelphiInterface<IDOMPersist> _di_IDOMPersist;
__interface INTERFACE_UUID("{2BF4C0F1-096E-11D4-83DA-00C04F60B2DD}") IDOMPersist  : public IInterface 
{
	
public:
	virtual HRESULT __safecall get_xml(WideString &get_xml_result) = 0 ;
	virtual HRESULT __safecall asyncLoadState(int &asyncLoadState_result) = 0 ;
	virtual HRESULT __safecall load(const OleVariant source, Word &load_result) = 0 ;
	virtual HRESULT __safecall loadFromStream(const Classes::TStream* stream, Word &loadFromStream_result) = 0 ;
	virtual HRESULT __safecall loadxml(const WideString Value, Word &loadxml_result) = 0 ;
	virtual HRESULT __safecall save(const OleVariant destination) = 0 ;
	virtual HRESULT __safecall saveToStream(const Classes::TStream* stream) = 0 ;
	virtual HRESULT __safecall set_OnAsyncLoad(const System::TObject* Sender, TAsyncEventHandler EventHandler) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_xml() { WideString r; HRESULT hr = get_xml(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString xml = {read=_scw_get_xml};
};

__interface IDOMParseOptions;
typedef System::DelphiInterface<IDOMParseOptions> _di_IDOMParseOptions;
__interface INTERFACE_UUID("{2BF4C0F3-096E-11D4-83DA-00C04F60B2DD}") IDOMParseOptions  : public IInterface 
{
	
public:
	virtual bool __fastcall get_async(void) = 0 ;
	virtual bool __fastcall get_preserveWhiteSpace(void) = 0 ;
	virtual bool __fastcall get_resolveExternals(void) = 0 ;
	virtual bool __fastcall get_validate(void) = 0 ;
	virtual void __fastcall set_async(bool Value) = 0 ;
	virtual void __fastcall set_preserveWhiteSpace(bool Value) = 0 ;
	virtual void __fastcall set_resolveExternals(bool Value) = 0 ;
	virtual void __fastcall set_validate(bool Value) = 0 ;
	__property bool async = {read=get_async, write=set_async};
	__property bool preserveWhiteSpace = {read=get_preserveWhiteSpace, write=set_preserveWhiteSpace};
	__property bool resolveExternals = {read=get_resolveExternals, write=set_resolveExternals};
	__property bool validate = {read=get_validate, write=set_validate};
};

__interface IDOMXMLProlog;
typedef System::DelphiInterface<IDOMXMLProlog> _di_IDOMXMLProlog;
__interface INTERFACE_UUID("{7C192633-C267-483C-B0D5-89289A14D522}") IDOMXMLProlog  : public IInterface 
{
	
public:
	virtual HRESULT __safecall get_Encoding(WideString &get_Encoding_result) = 0 ;
	virtual HRESULT __safecall get_Standalone(WideString &get_Standalone_result) = 0 ;
	virtual HRESULT __safecall get_Version(WideString &get_Version_result) = 0 ;
	virtual HRESULT __safecall set_Encoding(const WideString Value) = 0 ;
	virtual HRESULT __safecall set_Standalone(const WideString Value) = 0 ;
	virtual HRESULT __safecall set_Version(const WideString Value) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_Encoding() { WideString r; HRESULT hr = get_Encoding(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Encoding = {read=_scw_get_Encoding, write=set_Encoding};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_Standalone() { WideString r; HRESULT hr = get_Standalone(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Standalone = {read=_scw_get_Standalone, write=set_Standalone};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_get_Version() { WideString r; HRESULT hr = get_Version(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Version = {read=_scw_get_Version, write=set_Version};
};

class DELPHICLASS TDOMVendor;
class PASCALIMPLEMENTATION TDOMVendor : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual AnsiString __fastcall Description(void) = 0 ;
	virtual _di_IDOMImplementation __fastcall DOMImplementation(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDOMVendor(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDOMVendor(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TDOMVendor* >  TDOMVendorArray;

class DELPHICLASS TDOMVendorList;
class PASCALIMPLEMENTATION TDOMVendorList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TDOMVendor* operator[](int Index) { return Vendors[Index]; }
	
private:
	DynamicArray<TDOMVendor* >  FVendors;
	
protected:
	TDOMVendor* __fastcall GetVendors(int Index);
	
public:
	void __fastcall Add(const TDOMVendor* Vendor);
	int __fastcall Count(void);
	TDOMVendor* __fastcall Find(const AnsiString VendorDesc);
	void __fastcall Remove(const TDOMVendor* Vendor);
	__property TDOMVendor* Vendors[int Index] = {read=GetVendors/*, default*/};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDOMVendorList(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDOMVendorList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define DOMWrapperVersion  (1.000000E+00)
static const Shortint ELEMENT_NODE = 0x1;
static const Shortint ATTRIBUTE_NODE = 0x2;
static const Shortint TEXT_NODE = 0x3;
static const Shortint CDATA_SECTION_NODE = 0x4;
static const Shortint ENTITY_REFERENCE_NODE = 0x5;
static const Shortint ENTITY_NODE = 0x6;
static const Shortint PROCESSING_INSTRUCTION_NODE = 0x7;
static const Shortint COMMENT_NODE = 0x8;
static const Shortint DOCUMENT_NODE = 0x9;
static const Shortint DOCUMENT_TYPE_NODE = 0xa;
static const Shortint DOCUMENT_FRAGMENT_NODE = 0xb;
static const Shortint NOTATION_NODE = 0xc;
static const Shortint INDEX_SIZE_ERR = 0x1;
static const Shortint DOMSTRING_SIZE_ERR = 0x2;
static const Shortint HIERARCHY_REQUEST_ERR = 0x3;
static const Shortint WRONG_DOCUMENT_ERR = 0x4;
static const Shortint INVALID_CHARACTER_ERR = 0x5;
static const Shortint NO_DATA_ALLOWED_ERR = 0x6;
static const Shortint NO_MODIFICATION_ALLOWED_ERR = 0x7;
static const Shortint NOT_FOUND_ERR = 0x8;
static const Shortint NOT_SUPPORTED_ERR = 0x9;
static const Shortint INUSE_ATTRIBUTE_ERR = 0xa;
static const Shortint INVALID_STATE_ERR = 0xb;
static const Shortint SYNTAX_ERR = 0xc;
static const Shortint INVALID_MODIFICATION_ERR = 0xd;
static const Shortint NAMESPACE_ERR = 0xe;
static const Shortint INVALID_ACCESS_ERR = 0xf;
static const char NSDelim = '\x3a';
#define SXML "xml"
#define SVersion "version"
#define SEncoding "encoding"
#define SStandalone "standalone"
#define SXMLNS "xmlns"
#define SHttp "http:/"
#define SXMLNamespaceURI "http://www.w3.org/2000/xmlns/"
extern PACKAGE AnsiString DefaultDOMVendor;
extern PACKAGE TDOMVendorList* DOMVendors;
extern PACKAGE bool __fastcall IsPrefixed(const WideString AName);
extern PACKAGE WideString __fastcall ExtractLocalName(const WideString AName);
extern PACKAGE WideString __fastcall ExtractPrefix(const WideString AName);
extern PACKAGE WideString __fastcall MakeNodeName(const WideString Prefix, const WideString LocalName);
extern PACKAGE bool __fastcall SameNamespace(const _di_IDOMNode Node, const WideString namespaceURI)/* overload */;
extern PACKAGE bool __fastcall SameNamespace(const WideString URI1, const WideString URI2)/* overload */;
extern PACKAGE bool __fastcall NodeMatches(const _di_IDOMNode Node, const WideString TagName, const WideString NamespaceURI)/* overload */;
extern PACKAGE _di_IDOMNodeEx __fastcall GetDOMNodeEx(const _di_IDOMNode Node);
extern PACKAGE void __fastcall RegisterDOMVendor(const TDOMVendor* Vendor);
extern PACKAGE void __fastcall UnRegisterDOMVendor(const TDOMVendor* Vendor);
extern PACKAGE TDOMVendor* __fastcall GetDOMVendor(AnsiString VendorDesc);
extern PACKAGE _di_IDOMImplementation __fastcall GetDOM(const AnsiString VendorDesc = "");
extern PACKAGE void __fastcall DOMVendorNotSupported(const AnsiString PropOrMethod, const AnsiString VendorName);

}	/* namespace Xmldom */
using namespace Xmldom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// xmldom
