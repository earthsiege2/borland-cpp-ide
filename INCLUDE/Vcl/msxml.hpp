// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'msxml.pas' rev: 6.00

#ifndef msxmlHPP
#define msxmlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <msxml.h>"

namespace Msxml
{
//-- type declarations -------------------------------------------------------
__interface IXMLDOMDocument;
typedef System::DelphiInterface<IXMLDOMDocument> _di_IXMLDOMDocument;
typedef IXMLDOMDocument DOMDocument;
;

typedef IXMLDOMDocument DOMFreeThreadedDocument;
;

__interface IXMLHttpRequest;
typedef System::DelphiInterface<IXMLHttpRequest> _di_IXMLHttpRequest;
typedef IXMLHttpRequest XMLHTTPRequest;
;

__interface IXMLDSOControl;
typedef System::DelphiInterface<IXMLDSOControl> _di_IXMLDSOControl;
typedef IXMLDSOControl XMLDSOControl;
;

__interface IXMLDocument2;
typedef System::DelphiInterface<IXMLDocument2> _di_IXMLDocument2;
typedef IXMLDocument2 XMLDocument;
;

typedef _xml_error *PUserType1;

__interface IXMLDOMImplementation;
typedef System::DelphiInterface<IXMLDOMImplementation> _di_IXMLDOMImplementation;
__interface INTERFACE_UUID("{2933BF8F-7B36-11D2-B20E-00C04F983E60}") IXMLDOMImplementation  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall hasFeature(const WideString feature, const WideString version, Word &hasFeature_result) = 0 ;
};

__dispinterface IXMLDOMImplementationDisp;
typedef System::DelphiInterface<IXMLDOMImplementationDisp> _di_IXMLDOMImplementationDisp;
__dispinterface INTERFACE_UUID("{2933BF8F-7B36-11D2-B20E-00C04F983E60}") IXMLDOMImplementationDisp  : public IDispatch 
{
	
};

__interface IXMLDOMNode;
typedef System::DelphiInterface<IXMLDOMNode> _di_IXMLDOMNode;
__interface IXMLDOMNodeList;
typedef System::DelphiInterface<IXMLDOMNodeList> _di_IXMLDOMNodeList;
__interface IXMLDOMNamedNodeMap;
typedef System::DelphiInterface<IXMLDOMNamedNodeMap> _di_IXMLDOMNamedNodeMap;
__interface INTERFACE_UUID("{2933BF80-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNode  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_nodeName(WideString &Get_nodeName_result) = 0 ;
	virtual HRESULT __safecall Get_nodeValue(OleVariant &Get_nodeValue_result) = 0 ;
	virtual HRESULT __safecall Set_nodeValue(const OleVariant value) = 0 ;
	virtual HRESULT __safecall Get_nodeType(Activex::TOleEnum &Get_nodeType_result) = 0 ;
	virtual HRESULT __safecall Get_parentNode(_di_IXMLDOMNode &Get_parentNode_result) = 0 ;
	virtual HRESULT __safecall Get_childNodes(_di_IXMLDOMNodeList &Get_childNodes_result) = 0 ;
	virtual HRESULT __safecall Get_firstChild(_di_IXMLDOMNode &Get_firstChild_result) = 0 ;
	virtual HRESULT __safecall Get_lastChild(_di_IXMLDOMNode &Get_lastChild_result) = 0 ;
	virtual HRESULT __safecall Get_previousSibling(_di_IXMLDOMNode &Get_previousSibling_result) = 0 ;
	virtual HRESULT __safecall Get_nextSibling(_di_IXMLDOMNode &Get_nextSibling_result) = 0 ;
	virtual HRESULT __safecall Get_attributes(_di_IXMLDOMNamedNodeMap &Get_attributes_result) = 0 ;
	virtual HRESULT __safecall insertBefore(const _di_IXMLDOMNode newChild, const OleVariant refChild, _di_IXMLDOMNode &insertBefore_result) = 0 ;
	virtual HRESULT __safecall replaceChild(const _di_IXMLDOMNode newChild, const _di_IXMLDOMNode oldChild, _di_IXMLDOMNode &replaceChild_result) = 0 ;
	virtual HRESULT __safecall removeChild(const _di_IXMLDOMNode childNode, _di_IXMLDOMNode &removeChild_result) = 0 ;
	virtual HRESULT __safecall appendChild(const _di_IXMLDOMNode newChild, _di_IXMLDOMNode &appendChild_result) = 0 ;
	virtual HRESULT __safecall hasChildNodes(Word &hasChildNodes_result) = 0 ;
	virtual HRESULT __safecall Get_ownerDocument(_di_IXMLDOMDocument &Get_ownerDocument_result) = 0 ;
	virtual HRESULT __safecall cloneNode(Word deep, _di_IXMLDOMNode &cloneNode_result) = 0 ;
	virtual HRESULT __safecall Get_nodeTypeString(WideString &Get_nodeTypeString_result) = 0 ;
	virtual HRESULT __safecall Get_text(WideString &Get_text_result) = 0 ;
	virtual HRESULT __safecall Set_text(const WideString text) = 0 ;
	virtual HRESULT __safecall Get_specified(Word &Get_specified_result) = 0 ;
	virtual HRESULT __safecall Get_definition(_di_IXMLDOMNode &Get_definition_result) = 0 ;
	virtual HRESULT __safecall Get_nodeTypedValue(OleVariant &Get_nodeTypedValue_result) = 0 ;
	virtual HRESULT __safecall Set_nodeTypedValue(const OleVariant typedValue) = 0 ;
	virtual HRESULT __safecall Get_dataType(OleVariant &Get_dataType_result) = 0 ;
	virtual HRESULT __safecall Set_dataType(const WideString dataTypeName) = 0 ;
	virtual HRESULT __safecall Get_xml(WideString &Get_xml_result) = 0 ;
	virtual HRESULT __safecall transformNode(const _di_IXMLDOMNode stylesheet, WideString &transformNode_result) = 0 ;
	virtual HRESULT __safecall selectNodes(const WideString queryString, _di_IXMLDOMNodeList &selectNodes_result) = 0 ;
	virtual HRESULT __safecall selectSingleNode(const WideString queryString, _di_IXMLDOMNode &selectSingleNode_result) = 0 ;
	virtual HRESULT __safecall Get_parsed(Word &Get_parsed_result) = 0 ;
	virtual HRESULT __safecall Get_namespaceURI(WideString &Get_namespaceURI_result) = 0 ;
	virtual HRESULT __safecall Get_prefix(WideString &Get_prefix_result) = 0 ;
	virtual HRESULT __safecall Get_baseName(WideString &Get_baseName_result) = 0 ;
	virtual HRESULT __safecall transformNodeToObject(const _di_IXMLDOMNode stylesheet, const OleVariant outputObject) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_nodeName() { WideString r; HRESULT hr = Get_nodeName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString nodeName = {read=_scw_Get_nodeName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_nodeValue() { OleVariant r; HRESULT hr = Get_nodeValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant nodeValue = {read=_scw_Get_nodeValue, write=Set_nodeValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_nodeType() { Activex::TOleEnum r; HRESULT hr = Get_nodeType(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum nodeType = {read=_scw_Get_nodeType};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_parentNode() { _di_IXMLDOMNode r; HRESULT hr = Get_parentNode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode parentNode = {read=_scw_Get_parentNode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNodeList _scw_Get_childNodes() { _di_IXMLDOMNodeList r; HRESULT hr = Get_childNodes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNodeList childNodes = {read=_scw_Get_childNodes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_firstChild() { _di_IXMLDOMNode r; HRESULT hr = Get_firstChild(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode firstChild = {read=_scw_Get_firstChild};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_lastChild() { _di_IXMLDOMNode r; HRESULT hr = Get_lastChild(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode lastChild = {read=_scw_Get_lastChild};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_previousSibling() { _di_IXMLDOMNode r; HRESULT hr = Get_previousSibling(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode previousSibling = {read=_scw_Get_previousSibling};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_nextSibling() { _di_IXMLDOMNode r; HRESULT hr = Get_nextSibling(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode nextSibling = {read=_scw_Get_nextSibling};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNamedNodeMap _scw_Get_attributes() { _di_IXMLDOMNamedNodeMap r; HRESULT hr = Get_attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNamedNodeMap attributes = {read=_scw_Get_attributes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMDocument _scw_Get_ownerDocument() { _di_IXMLDOMDocument r; HRESULT hr = Get_ownerDocument(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMDocument ownerDocument = {read=_scw_Get_ownerDocument};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_nodeTypeString() { WideString r; HRESULT hr = Get_nodeTypeString(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString nodeTypeString = {read=_scw_Get_nodeTypeString};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_text() { WideString r; HRESULT hr = Get_text(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString text = {read=_scw_Get_text, write=Set_text};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_specified() { Word r; HRESULT hr = Get_specified(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word specified = {read=_scw_Get_specified};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_definition() { _di_IXMLDOMNode r; HRESULT hr = Get_definition(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode definition = {read=_scw_Get_definition};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_nodeTypedValue() { OleVariant r; HRESULT hr = Get_nodeTypedValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant nodeTypedValue = {read=_scw_Get_nodeTypedValue, write=Set_nodeTypedValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_xml() { WideString r; HRESULT hr = Get_xml(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString xml = {read=_scw_Get_xml};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_parsed() { Word r; HRESULT hr = Get_parsed(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word parsed = {read=_scw_Get_parsed};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_namespaceURI() { WideString r; HRESULT hr = Get_namespaceURI(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString namespaceURI = {read=_scw_Get_namespaceURI};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_prefix() { WideString r; HRESULT hr = Get_prefix(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString prefix = {read=_scw_Get_prefix};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_baseName() { WideString r; HRESULT hr = Get_baseName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString baseName = {read=_scw_Get_baseName};
};

__dispinterface IXMLDOMNodeDisp;
typedef System::DelphiInterface<IXMLDOMNodeDisp> _di_IXMLDOMNodeDisp;
__dispinterface INTERFACE_UUID("{2933BF80-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNodeDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF82-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNodeList  : public IDispatch 
{
	
public:
	_di_IXMLDOMNode operator[](int index) { return item[index]; }
	
public:
	virtual HRESULT __safecall Get_item(int index, _di_IXMLDOMNode &Get_item_result) = 0 ;
	virtual HRESULT __safecall Get_length(int &Get_length_result) = 0 ;
	virtual HRESULT __safecall nextNode(_di_IXMLDOMNode &nextNode_result) = 0 ;
	virtual HRESULT __safecall reset(void) = 0 ;
	virtual HRESULT __safecall Get__newEnum(System::_di_IInterface &Get__newEnum_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_item(int index) { _di_IXMLDOMNode r; HRESULT hr = Get_item(index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode item[int index] = {read=_scw_Get_item/*, default*/};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_length() { int r; HRESULT hr = Get_length(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int length = {read=_scw_Get_length};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__newEnum() { System::_di_IInterface r; HRESULT hr = Get__newEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _newEnum = {read=_scw_Get__newEnum};
};

__dispinterface IXMLDOMNodeListDisp;
typedef System::DelphiInterface<IXMLDOMNodeListDisp> _di_IXMLDOMNodeListDisp;
__dispinterface INTERFACE_UUID("{2933BF82-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNodeListDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF83-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNamedNodeMap  : public IDispatch 
{
	
public:
	_di_IXMLDOMNode operator[](int index) { return item[index]; }
	
public:
	virtual HRESULT __safecall getNamedItem(const WideString name, _di_IXMLDOMNode &getNamedItem_result) = 0 ;
	virtual HRESULT __safecall setNamedItem(const _di_IXMLDOMNode newItem, _di_IXMLDOMNode &setNamedItem_result) = 0 ;
	virtual HRESULT __safecall removeNamedItem(const WideString name, _di_IXMLDOMNode &removeNamedItem_result) = 0 ;
	virtual HRESULT __safecall Get_item(int index, _di_IXMLDOMNode &Get_item_result) = 0 ;
	virtual HRESULT __safecall Get_length(int &Get_length_result) = 0 ;
	virtual HRESULT __safecall getQualifiedItem(const WideString baseName, const WideString namespaceURI, _di_IXMLDOMNode &getQualifiedItem_result) = 0 ;
	virtual HRESULT __safecall removeQualifiedItem(const WideString baseName, const WideString namespaceURI, _di_IXMLDOMNode &removeQualifiedItem_result) = 0 ;
	virtual HRESULT __safecall nextNode(_di_IXMLDOMNode &nextNode_result) = 0 ;
	virtual HRESULT __safecall reset(void) = 0 ;
	virtual HRESULT __safecall Get__newEnum(System::_di_IInterface &Get__newEnum_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNode _scw_Get_item(int index) { _di_IXMLDOMNode r; HRESULT hr = Get_item(index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNode item[int index] = {read=_scw_Get_item/*, default*/};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_length() { int r; HRESULT hr = Get_length(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int length = {read=_scw_Get_length};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__newEnum() { System::_di_IInterface r; HRESULT hr = Get__newEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _newEnum = {read=_scw_Get__newEnum};
};

__dispinterface IXMLDOMNamedNodeMapDisp;
typedef System::DelphiInterface<IXMLDOMNamedNodeMapDisp> _di_IXMLDOMNamedNodeMapDisp;
__dispinterface INTERFACE_UUID("{2933BF83-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNamedNodeMapDisp  : public IDispatch 
{
	
};

__interface IXMLDOMDocumentType;
typedef System::DelphiInterface<IXMLDOMDocumentType> _di_IXMLDOMDocumentType;
__interface IXMLDOMElement;
typedef System::DelphiInterface<IXMLDOMElement> _di_IXMLDOMElement;
__interface IXMLDOMDocumentFragment;
typedef System::DelphiInterface<IXMLDOMDocumentFragment> _di_IXMLDOMDocumentFragment;
__interface IXMLDOMText;
typedef System::DelphiInterface<IXMLDOMText> _di_IXMLDOMText;
__interface IXMLDOMComment;
typedef System::DelphiInterface<IXMLDOMComment> _di_IXMLDOMComment;
__interface IXMLDOMCDATASection;
typedef System::DelphiInterface<IXMLDOMCDATASection> _di_IXMLDOMCDATASection;
__interface IXMLDOMProcessingInstruction;
typedef System::DelphiInterface<IXMLDOMProcessingInstruction> _di_IXMLDOMProcessingInstruction;
__interface IXMLDOMAttribute;
typedef System::DelphiInterface<IXMLDOMAttribute> _di_IXMLDOMAttribute;
__interface IXMLDOMEntityReference;
typedef System::DelphiInterface<IXMLDOMEntityReference> _di_IXMLDOMEntityReference;
__interface IXMLDOMParseError;
typedef System::DelphiInterface<IXMLDOMParseError> _di_IXMLDOMParseError;
__interface INTERFACE_UUID("{2933BF81-7B36-11D2-B20E-00C04F983E60}") IXMLDOMDocument  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_doctype(_di_IXMLDOMDocumentType &Get_doctype_result) = 0 ;
	virtual HRESULT __safecall Get_implementation_(_di_IXMLDOMImplementation &Get_implementation__result) = 0 ;
	virtual HRESULT __safecall Get_documentElement(_di_IXMLDOMElement &Get_documentElement_result) = 0 ;
	virtual HRESULT __safecall Set_documentElement(const _di_IXMLDOMElement DOMElement) = 0 ;
	virtual HRESULT __safecall createElement(const WideString tagName, _di_IXMLDOMElement &createElement_result) = 0 ;
	virtual HRESULT __safecall createDocumentFragment(_di_IXMLDOMDocumentFragment &createDocumentFragment_result) = 0 ;
	virtual HRESULT __safecall createTextNode(const WideString data, _di_IXMLDOMText &createTextNode_result) = 0 ;
	virtual HRESULT __safecall createComment(const WideString data, _di_IXMLDOMComment &createComment_result) = 0 ;
	virtual HRESULT __safecall createCDATASection(const WideString data, _di_IXMLDOMCDATASection &createCDATASection_result) = 0 ;
	virtual HRESULT __safecall createProcessingInstruction(const WideString target, const WideString data, _di_IXMLDOMProcessingInstruction &createProcessingInstruction_result) = 0 ;
	virtual HRESULT __safecall createAttribute(const WideString name, _di_IXMLDOMAttribute &createAttribute_result) = 0 ;
	virtual HRESULT __safecall createEntityReference(const WideString name, _di_IXMLDOMEntityReference &createEntityReference_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagName(const WideString tagName, _di_IXMLDOMNodeList &getElementsByTagName_result) = 0 ;
	virtual HRESULT __safecall createNode(const OleVariant type_, const WideString name, const WideString namespaceURI, _di_IXMLDOMNode &createNode_result) = 0 ;
	virtual HRESULT __safecall nodeFromID(const WideString idString, _di_IXMLDOMNode &nodeFromID_result) = 0 ;
	virtual HRESULT __safecall load(const OleVariant xmlSource, Word &load_result) = 0 ;
	virtual HRESULT __safecall Get_readyState(int &Get_readyState_result) = 0 ;
	virtual HRESULT __safecall Get_parseError(_di_IXMLDOMParseError &Get_parseError_result) = 0 ;
	virtual HRESULT __safecall Get_url(WideString &Get_url_result) = 0 ;
	virtual HRESULT __safecall Get_async(Word &Get_async_result) = 0 ;
	virtual HRESULT __safecall Set_async(Word isAsync) = 0 ;
	virtual HRESULT __safecall abort(void) = 0 ;
	virtual HRESULT __safecall loadXML(const WideString bstrXML, Word &loadXML_result) = 0 ;
	virtual HRESULT __safecall save(const OleVariant desination) = 0 ;
	virtual HRESULT __safecall Get_validateOnParse(Word &Get_validateOnParse_result) = 0 ;
	virtual HRESULT __safecall Set_validateOnParse(Word isValidating) = 0 ;
	virtual HRESULT __safecall Get_resolveExternals(Word &Get_resolveExternals_result) = 0 ;
	virtual HRESULT __safecall Set_resolveExternals(Word isResolving) = 0 ;
	virtual HRESULT __safecall Get_preserveWhiteSpace(Word &Get_preserveWhiteSpace_result) = 0 ;
	virtual HRESULT __safecall Set_preserveWhiteSpace(Word isPreserving) = 0 ;
	virtual HRESULT __safecall Set_onreadystatechange(const OleVariant Param1) = 0 ;
	virtual HRESULT __safecall Set_ondataavailable(const OleVariant Param1) = 0 ;
	virtual HRESULT __safecall Set_ontransformnode(const OleVariant Param1) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMDocumentType _scw_Get_doctype() { _di_IXMLDOMDocumentType r; HRESULT hr = Get_doctype(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMDocumentType doctype = {read=_scw_Get_doctype};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMImplementation _scw_Get_implementation_() { _di_IXMLDOMImplementation r; HRESULT hr = Get_implementation_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMImplementation implementation_ = {read=_scw_Get_implementation_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMElement _scw_Get_documentElement() { _di_IXMLDOMElement r; HRESULT hr = Get_documentElement(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMElement documentElement = {read=_scw_Get_documentElement, write=Set_documentElement};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_readyState() { int r; HRESULT hr = Get_readyState(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int readyState = {read=_scw_Get_readyState};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMParseError _scw_Get_parseError() { _di_IXMLDOMParseError r; HRESULT hr = Get_parseError(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMParseError parseError = {read=_scw_Get_parseError};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_url() { WideString r; HRESULT hr = Get_url(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString url = {read=_scw_Get_url};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_async() { Word r; HRESULT hr = Get_async(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word async = {read=_scw_Get_async, write=Set_async};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_validateOnParse() { Word r; HRESULT hr = Get_validateOnParse(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word validateOnParse = {read=_scw_Get_validateOnParse, write=Set_validateOnParse};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_resolveExternals() { Word r; HRESULT hr = Get_resolveExternals(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word resolveExternals = {read=_scw_Get_resolveExternals, write=Set_resolveExternals};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_preserveWhiteSpace() { Word r; HRESULT hr = Get_preserveWhiteSpace(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word preserveWhiteSpace = {read=_scw_Get_preserveWhiteSpace, write=Set_preserveWhiteSpace};
	__property OleVariant onreadystatechange = {write=Set_onreadystatechange};
	__property OleVariant ondataavailable = {write=Set_ondataavailable};
	__property OleVariant ontransformnode = {write=Set_ontransformnode};
};

__dispinterface IXMLDOMDocumentDisp;
typedef System::DelphiInterface<IXMLDOMDocumentDisp> _di_IXMLDOMDocumentDisp;
__dispinterface INTERFACE_UUID("{2933BF81-7B36-11D2-B20E-00C04F983E60}") IXMLDOMDocumentDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF8B-7B36-11D2-B20E-00C04F983E60}") IXMLDOMDocumentType  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_name(WideString &Get_name_result) = 0 ;
	virtual HRESULT __safecall Get_entities(_di_IXMLDOMNamedNodeMap &Get_entities_result) = 0 ;
	virtual HRESULT __safecall Get_notations(_di_IXMLDOMNamedNodeMap &Get_notations_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_name() { WideString r; HRESULT hr = Get_name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString name = {read=_scw_Get_name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNamedNodeMap _scw_Get_entities() { _di_IXMLDOMNamedNodeMap r; HRESULT hr = Get_entities(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNamedNodeMap entities = {read=_scw_Get_entities};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMNamedNodeMap _scw_Get_notations() { _di_IXMLDOMNamedNodeMap r; HRESULT hr = Get_notations(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMNamedNodeMap notations = {read=_scw_Get_notations};
};

__dispinterface IXMLDOMDocumentTypeDisp;
typedef System::DelphiInterface<IXMLDOMDocumentTypeDisp> _di_IXMLDOMDocumentTypeDisp;
__dispinterface INTERFACE_UUID("{2933BF8B-7B36-11D2-B20E-00C04F983E60}") IXMLDOMDocumentTypeDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF86-7B36-11D2-B20E-00C04F983E60}") IXMLDOMElement  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_tagName(WideString &Get_tagName_result) = 0 ;
	virtual HRESULT __safecall getAttribute(const WideString name, OleVariant &getAttribute_result) = 0 ;
	virtual HRESULT __safecall setAttribute(const WideString name, const OleVariant value) = 0 ;
	virtual HRESULT __safecall removeAttribute(const WideString name) = 0 ;
	virtual HRESULT __safecall getAttributeNode(const WideString name, _di_IXMLDOMAttribute &getAttributeNode_result) = 0 ;
	virtual HRESULT __safecall setAttributeNode(const _di_IXMLDOMAttribute DOMAttribute, _di_IXMLDOMAttribute &setAttributeNode_result) = 0 ;
	virtual HRESULT __safecall removeAttributeNode(const _di_IXMLDOMAttribute DOMAttribute, _di_IXMLDOMAttribute &removeAttributeNode_result) = 0 ;
	virtual HRESULT __safecall getElementsByTagName(const WideString tagName, _di_IXMLDOMNodeList &getElementsByTagName_result) = 0 ;
	virtual HRESULT __safecall normalize(void) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_tagName() { WideString r; HRESULT hr = Get_tagName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString tagName = {read=_scw_Get_tagName};
};

__dispinterface IXMLDOMElementDisp;
typedef System::DelphiInterface<IXMLDOMElementDisp> _di_IXMLDOMElementDisp;
__dispinterface INTERFACE_UUID("{2933BF86-7B36-11D2-B20E-00C04F983E60}") IXMLDOMElementDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF85-7B36-11D2-B20E-00C04F983E60}") IXMLDOMAttribute  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_name(WideString &Get_name_result) = 0 ;
	virtual HRESULT __safecall Get_value(OleVariant &Get_value_result) = 0 ;
	virtual HRESULT __safecall Set_value(const OleVariant attributeValue) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_name() { WideString r; HRESULT hr = Get_name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString name = {read=_scw_Get_name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_value() { OleVariant r; HRESULT hr = Get_value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant value = {read=_scw_Get_value, write=Set_value};
};

__dispinterface IXMLDOMAttributeDisp;
typedef System::DelphiInterface<IXMLDOMAttributeDisp> _di_IXMLDOMAttributeDisp;
__dispinterface INTERFACE_UUID("{2933BF85-7B36-11D2-B20E-00C04F983E60}") IXMLDOMAttributeDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{3EFAA413-272F-11D2-836F-0000F87A7782}") IXMLDOMDocumentFragment  : public IXMLDOMNode 
{
	
};

__dispinterface IXMLDOMDocumentFragmentDisp;
typedef System::DelphiInterface<IXMLDOMDocumentFragmentDisp> _di_IXMLDOMDocumentFragmentDisp;
__dispinterface INTERFACE_UUID("{3EFAA413-272F-11D2-836F-0000F87A7782}") IXMLDOMDocumentFragmentDisp  : public IDispatch 
{
	
};

__interface IXMLDOMCharacterData;
typedef System::DelphiInterface<IXMLDOMCharacterData> _di_IXMLDOMCharacterData;
__interface INTERFACE_UUID("{2933BF84-7B36-11D2-B20E-00C04F983E60}") IXMLDOMCharacterData  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_data(WideString &Get_data_result) = 0 ;
	virtual HRESULT __safecall Set_data(const WideString data) = 0 ;
	virtual HRESULT __safecall Get_length(int &Get_length_result) = 0 ;
	virtual HRESULT __safecall substringData(int offset, int count, WideString &substringData_result) = 0 ;
	virtual HRESULT __safecall appendData(const WideString data) = 0 ;
	virtual HRESULT __safecall insertData(int offset, const WideString data) = 0 ;
	virtual HRESULT __safecall deleteData(int offset, int count) = 0 ;
	virtual HRESULT __safecall replaceData(int offset, int count, const WideString data) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_data() { WideString r; HRESULT hr = Get_data(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString data = {read=_scw_Get_data, write=Set_data};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_length() { int r; HRESULT hr = Get_length(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int length = {read=_scw_Get_length};
};

__dispinterface IXMLDOMCharacterDataDisp;
typedef System::DelphiInterface<IXMLDOMCharacterDataDisp> _di_IXMLDOMCharacterDataDisp;
__dispinterface INTERFACE_UUID("{2933BF84-7B36-11D2-B20E-00C04F983E60}") IXMLDOMCharacterDataDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF87-7B36-11D2-B20E-00C04F983E60}") IXMLDOMText  : public IXMLDOMCharacterData 
{
	
public:
	virtual HRESULT __safecall splitText(int offset, _di_IXMLDOMText &splitText_result) = 0 ;
};

__dispinterface IXMLDOMTextDisp;
typedef System::DelphiInterface<IXMLDOMTextDisp> _di_IXMLDOMTextDisp;
__dispinterface INTERFACE_UUID("{2933BF87-7B36-11D2-B20E-00C04F983E60}") IXMLDOMTextDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF88-7B36-11D2-B20E-00C04F983E60}") IXMLDOMComment  : public IXMLDOMCharacterData 
{
	
};

__dispinterface IXMLDOMCommentDisp;
typedef System::DelphiInterface<IXMLDOMCommentDisp> _di_IXMLDOMCommentDisp;
__dispinterface INTERFACE_UUID("{2933BF88-7B36-11D2-B20E-00C04F983E60}") IXMLDOMCommentDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF8A-7B36-11D2-B20E-00C04F983E60}") IXMLDOMCDATASection  : public IXMLDOMText 
{
	
};

__dispinterface IXMLDOMCDATASectionDisp;
typedef System::DelphiInterface<IXMLDOMCDATASectionDisp> _di_IXMLDOMCDATASectionDisp;
__dispinterface INTERFACE_UUID("{2933BF8A-7B36-11D2-B20E-00C04F983E60}") IXMLDOMCDATASectionDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF89-7B36-11D2-B20E-00C04F983E60}") IXMLDOMProcessingInstruction  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_target(WideString &Get_target_result) = 0 ;
	virtual HRESULT __safecall Get_data(WideString &Get_data_result) = 0 ;
	virtual HRESULT __safecall Set_data(const WideString value) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_target() { WideString r; HRESULT hr = Get_target(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString target = {read=_scw_Get_target};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_data() { WideString r; HRESULT hr = Get_data(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString data = {read=_scw_Get_data, write=Set_data};
};

__dispinterface IXMLDOMProcessingInstructionDisp;
typedef System::DelphiInterface<IXMLDOMProcessingInstructionDisp> _di_IXMLDOMProcessingInstructionDisp;
__dispinterface INTERFACE_UUID("{2933BF89-7B36-11D2-B20E-00C04F983E60}") IXMLDOMProcessingInstructionDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{2933BF8E-7B36-11D2-B20E-00C04F983E60}") IXMLDOMEntityReference  : public IXMLDOMNode 
{
	
};

__dispinterface IXMLDOMEntityReferenceDisp;
typedef System::DelphiInterface<IXMLDOMEntityReferenceDisp> _di_IXMLDOMEntityReferenceDisp;
__dispinterface INTERFACE_UUID("{2933BF8E-7B36-11D2-B20E-00C04F983E60}") IXMLDOMEntityReferenceDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{3EFAA426-272F-11D2-836F-0000F87A7782}") IXMLDOMParseError  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_errorCode(int &Get_errorCode_result) = 0 ;
	virtual HRESULT __safecall Get_url(WideString &Get_url_result) = 0 ;
	virtual HRESULT __safecall Get_reason(WideString &Get_reason_result) = 0 ;
	virtual HRESULT __safecall Get_srcText(WideString &Get_srcText_result) = 0 ;
	virtual HRESULT __safecall Get_line(int &Get_line_result) = 0 ;
	virtual HRESULT __safecall Get_linepos(int &Get_linepos_result) = 0 ;
	virtual HRESULT __safecall Get_filepos(int &Get_filepos_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_errorCode() { int r; HRESULT hr = Get_errorCode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int errorCode = {read=_scw_Get_errorCode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_url() { WideString r; HRESULT hr = Get_url(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString url = {read=_scw_Get_url};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_reason() { WideString r; HRESULT hr = Get_reason(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString reason = {read=_scw_Get_reason};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_srcText() { WideString r; HRESULT hr = Get_srcText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString srcText = {read=_scw_Get_srcText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_line() { int r; HRESULT hr = Get_line(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int line = {read=_scw_Get_line};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_linepos() { int r; HRESULT hr = Get_linepos(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int linepos = {read=_scw_Get_linepos};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_filepos() { int r; HRESULT hr = Get_filepos(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int filepos = {read=_scw_Get_filepos};
};

__dispinterface IXMLDOMParseErrorDisp;
typedef System::DelphiInterface<IXMLDOMParseErrorDisp> _di_IXMLDOMParseErrorDisp;
__dispinterface INTERFACE_UUID("{3EFAA426-272F-11D2-836F-0000F87A7782}") IXMLDOMParseErrorDisp  : public IDispatch 
{
	
};

__interface IXMLDOMNotation;
typedef System::DelphiInterface<IXMLDOMNotation> _di_IXMLDOMNotation;
__interface INTERFACE_UUID("{2933BF8C-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNotation  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_publicId(OleVariant &Get_publicId_result) = 0 ;
	virtual HRESULT __safecall Get_systemId(OleVariant &Get_systemId_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_publicId() { OleVariant r; HRESULT hr = Get_publicId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant publicId = {read=_scw_Get_publicId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_systemId() { OleVariant r; HRESULT hr = Get_systemId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant systemId = {read=_scw_Get_systemId};
};

__dispinterface IXMLDOMNotationDisp;
typedef System::DelphiInterface<IXMLDOMNotationDisp> _di_IXMLDOMNotationDisp;
__dispinterface INTERFACE_UUID("{2933BF8C-7B36-11D2-B20E-00C04F983E60}") IXMLDOMNotationDisp  : public IDispatch 
{
	
};

__interface IXMLDOMEntity;
typedef System::DelphiInterface<IXMLDOMEntity> _di_IXMLDOMEntity;
__interface INTERFACE_UUID("{2933BF8D-7B36-11D2-B20E-00C04F983E60}") IXMLDOMEntity  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall Get_publicId(OleVariant &Get_publicId_result) = 0 ;
	virtual HRESULT __safecall Get_systemId(OleVariant &Get_systemId_result) = 0 ;
	virtual HRESULT __safecall Get_notationName(WideString &Get_notationName_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_publicId() { OleVariant r; HRESULT hr = Get_publicId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant publicId = {read=_scw_Get_publicId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_systemId() { OleVariant r; HRESULT hr = Get_systemId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant systemId = {read=_scw_Get_systemId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_notationName() { WideString r; HRESULT hr = Get_notationName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString notationName = {read=_scw_Get_notationName};
};

__dispinterface IXMLDOMEntityDisp;
typedef System::DelphiInterface<IXMLDOMEntityDisp> _di_IXMLDOMEntityDisp;
__dispinterface INTERFACE_UUID("{2933BF8D-7B36-11D2-B20E-00C04F983E60}") IXMLDOMEntityDisp  : public IDispatch 
{
	
};

__interface IXTLRuntime;
typedef System::DelphiInterface<IXTLRuntime> _di_IXTLRuntime;
__interface INTERFACE_UUID("{3EFAA425-272F-11D2-836F-0000F87A7782}") IXTLRuntime  : public IXMLDOMNode 
{
	
public:
	virtual HRESULT __safecall uniqueID(const _di_IXMLDOMNode pNode, int &uniqueID_result) = 0 ;
	virtual HRESULT __safecall depth(const _di_IXMLDOMNode pNode, int &depth_result) = 0 ;
	virtual HRESULT __safecall childNumber(const _di_IXMLDOMNode pNode, int &childNumber_result) = 0 ;
	virtual HRESULT __safecall ancestorChildNumber(const WideString bstrNodeName, const _di_IXMLDOMNode pNode, int &ancestorChildNumber_result) = 0 ;
	virtual HRESULT __safecall absoluteChildNumber(const _di_IXMLDOMNode pNode, int &absoluteChildNumber_result) = 0 ;
	virtual HRESULT __safecall formatIndex(int lIndex, const WideString bstrFormat, WideString &formatIndex_result) = 0 ;
	virtual HRESULT __safecall formatNumber(double dblNumber, const WideString bstrFormat, WideString &formatNumber_result) = 0 ;
	virtual HRESULT __safecall formatDate(const OleVariant varDate, const WideString bstrFormat, const OleVariant varDestLocale, WideString &formatDate_result) = 0 ;
	virtual HRESULT __safecall formatTime(const OleVariant varTime, const WideString bstrFormat, const OleVariant varDestLocale, WideString &formatTime_result) = 0 ;
};

__dispinterface IXTLRuntimeDisp;
typedef System::DelphiInterface<IXTLRuntimeDisp> _di_IXTLRuntimeDisp;
__dispinterface INTERFACE_UUID("{3EFAA425-272F-11D2-836F-0000F87A7782}") IXTLRuntimeDisp  : public IDispatch 
{
	
};

__dispinterface XMLDOMDocumentEvents;
typedef System::DelphiInterface<XMLDOMDocumentEvents> _di_XMLDOMDocumentEvents;
__dispinterface INTERFACE_UUID("{3EFAA427-272F-11D2-836F-0000F87A7782}") XMLDOMDocumentEvents  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{ED8C108D-4349-11D2-91A4-00C04F7969E8}") IXMLHttpRequest  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall open(const WideString bstrMethod, const WideString bstrUrl, const OleVariant varAsync, const OleVariant bstrUser, const OleVariant bstrPassword) = 0 ;
	virtual HRESULT __safecall setRequestHeader(const WideString bstrHeader, const WideString bstrValue) = 0 ;
	virtual HRESULT __safecall getResponseHeader(const WideString bstrHeader, WideString &getResponseHeader_result) = 0 ;
	virtual HRESULT __safecall getAllResponseHeaders(WideString &getAllResponseHeaders_result) = 0 ;
	virtual HRESULT __safecall send(const OleVariant varBody) = 0 ;
	virtual HRESULT __safecall abort(void) = 0 ;
	virtual HRESULT __safecall Get_status(int &Get_status_result) = 0 ;
	virtual HRESULT __safecall Get_statusText(WideString &Get_statusText_result) = 0 ;
	virtual HRESULT __safecall Get_responseXML(_di_IDispatch &Get_responseXML_result) = 0 ;
	virtual HRESULT __safecall Get_responseText(WideString &Get_responseText_result) = 0 ;
	virtual HRESULT __safecall Get_responseBody(OleVariant &Get_responseBody_result) = 0 ;
	virtual HRESULT __safecall Get_responseStream(OleVariant &Get_responseStream_result) = 0 ;
	virtual HRESULT __safecall Get_readyState(int &Get_readyState_result) = 0 ;
	virtual HRESULT __safecall Set_onreadystatechange(const _di_IDispatch Param1) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_status() { int r; HRESULT hr = Get_status(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int status = {read=_scw_Get_status};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_statusText() { WideString r; HRESULT hr = Get_statusText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString statusText = {read=_scw_Get_statusText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDispatch _scw_Get_responseXML() { _di_IDispatch r; HRESULT hr = Get_responseXML(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDispatch responseXML = {read=_scw_Get_responseXML};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_responseText() { WideString r; HRESULT hr = Get_responseText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString responseText = {read=_scw_Get_responseText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_responseBody() { OleVariant r; HRESULT hr = Get_responseBody(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant responseBody = {read=_scw_Get_responseBody};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_responseStream() { OleVariant r; HRESULT hr = Get_responseStream(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant responseStream = {read=_scw_Get_responseStream};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_readyState() { int r; HRESULT hr = Get_readyState(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int readyState = {read=_scw_Get_readyState};
	__property _di_IDispatch onreadystatechange = {write=Set_onreadystatechange};
};

__dispinterface IXMLHttpRequestDisp;
typedef System::DelphiInterface<IXMLHttpRequestDisp> _di_IXMLHttpRequestDisp;
__dispinterface INTERFACE_UUID("{ED8C108D-4349-11D2-91A4-00C04F7969E8}") IXMLHttpRequestDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{310AFA62-0575-11D2-9CA9-0060B0EC3D39}") IXMLDSOControl  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_XMLDocument(_di_IXMLDOMDocument &Get_XMLDocument_result) = 0 ;
	virtual HRESULT __safecall Set_XMLDocument(const _di_IXMLDOMDocument ppDoc) = 0 ;
	virtual HRESULT __safecall Get_JavaDSOCompatible(int &Get_JavaDSOCompatible_result) = 0 ;
	virtual HRESULT __safecall Set_JavaDSOCompatible(int fJavaDSOCompatible) = 0 ;
	virtual HRESULT __safecall Get_readyState(int &Get_readyState_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLDOMDocument _scw_Get_XMLDocument() { _di_IXMLDOMDocument r; HRESULT hr = Get_XMLDocument(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLDOMDocument XMLDocument = {read=_scw_Get_XMLDocument, write=Set_XMLDocument};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_JavaDSOCompatible() { int r; HRESULT hr = Get_JavaDSOCompatible(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int JavaDSOCompatible = {read=_scw_Get_JavaDSOCompatible, write=Set_JavaDSOCompatible};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_readyState() { int r; HRESULT hr = Get_readyState(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int readyState = {read=_scw_Get_readyState};
};

__dispinterface IXMLDSOControlDisp;
typedef System::DelphiInterface<IXMLDSOControlDisp> _di_IXMLDSOControlDisp;
__dispinterface INTERFACE_UUID("{310AFA62-0575-11D2-9CA9-0060B0EC3D39}") IXMLDSOControlDisp  : public IDispatch 
{
	
};

__interface IXMLElementCollection;
typedef System::DelphiInterface<IXMLElementCollection> _di_IXMLElementCollection;
__interface INTERFACE_UUID("{65725580-9B5D-11D0-9BFE-00C04FC99C8E}") IXMLElementCollection  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Set_length(int p) = 0 ;
	virtual HRESULT __safecall Get_length(int &Get_length_result) = 0 ;
	virtual HRESULT __safecall Get__newEnum(System::_di_IInterface &Get__newEnum_result) = 0 ;
	virtual HRESULT __safecall item(const OleVariant var1, const OleVariant var2, _di_IDispatch &item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_length() { int r; HRESULT hr = Get_length(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int length = {read=_scw_Get_length, write=Set_length};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__newEnum() { System::_di_IInterface r; HRESULT hr = Get__newEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _newEnum = {read=_scw_Get__newEnum};
};

__dispinterface IXMLElementCollectionDisp;
typedef System::DelphiInterface<IXMLElementCollectionDisp> _di_IXMLElementCollectionDisp;
__dispinterface INTERFACE_UUID("{65725580-9B5D-11D0-9BFE-00C04FC99C8E}") IXMLElementCollectionDisp  : public IDispatch 
{
	
};

__dispinterface IXMLDocumentDisp;
typedef System::DelphiInterface<IXMLDocumentDisp> _di_IXMLDocumentDisp;
__interface IXMLElement;
typedef System::DelphiInterface<IXMLElement> _di_IXMLElement;
__interface INTERFACE_UUID("{3F7F31AC-E15F-11D0-9C25-00C04FC99C8E}") IXMLElement  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_tagName(WideString &Get_tagName_result) = 0 ;
	virtual HRESULT __safecall Set_tagName(const WideString p) = 0 ;
	virtual HRESULT __safecall Get_parent(_di_IXMLElement &Get_parent_result) = 0 ;
	virtual HRESULT __safecall setAttribute(const WideString strPropertyName, const OleVariant PropertyValue) = 0 ;
	virtual HRESULT __safecall getAttribute(const WideString strPropertyName, OleVariant &getAttribute_result) = 0 ;
	virtual HRESULT __safecall removeAttribute(const WideString strPropertyName) = 0 ;
	virtual HRESULT __safecall Get_children(_di_IXMLElementCollection &Get_children_result) = 0 ;
	virtual HRESULT __safecall Get_type_(int &Get_type__result) = 0 ;
	virtual HRESULT __safecall Get_text(WideString &Get_text_result) = 0 ;
	virtual HRESULT __safecall Set_text(const WideString p) = 0 ;
	virtual HRESULT __safecall addChild(const _di_IXMLElement pChildElem, int lIndex, int lReserved) = 0 ;
	virtual HRESULT __safecall removeChild(const _di_IXMLElement pChildElem) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_tagName() { WideString r; HRESULT hr = Get_tagName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString tagName = {read=_scw_Get_tagName, write=Set_tagName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLElement _scw_Get_parent() { _di_IXMLElement r; HRESULT hr = Get_parent(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLElement parent = {read=_scw_Get_parent};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLElementCollection _scw_Get_children() { _di_IXMLElementCollection r; HRESULT hr = Get_children(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLElementCollection children = {read=_scw_Get_children};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_type_() { int r; HRESULT hr = Get_type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int type_ = {read=_scw_Get_type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_text() { WideString r; HRESULT hr = Get_text(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString text = {read=_scw_Get_text, write=Set_text};
};

__dispinterface INTERFACE_UUID("{F52E2B61-18A1-11D1-B105-00805F49916B}") IXMLDocumentDisp  : public IDispatch 
{
	
};

__dispinterface IXMLElementDisp;
typedef System::DelphiInterface<IXMLElementDisp> _di_IXMLElementDisp;
__dispinterface INTERFACE_UUID("{3F7F31AC-E15F-11D0-9C25-00C04FC99C8E}") IXMLElementDisp  : public IDispatch 
{
	
};

__interface IXMLElement2;
typedef System::DelphiInterface<IXMLElement2> _di_IXMLElement2;
__interface INTERFACE_UUID("{2B8DE2FE-8D2D-11D1-B2FC-00C04FD915A9}") IXMLDocument2  : public IDispatch 
{
	
public:
	virtual HRESULT __stdcall Get_root(/* out */ _di_IXMLElement2 &p) = 0 ;
	virtual HRESULT __stdcall Get_fileSize(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_fileModifiedDate(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_fileUpdatedDate(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_url(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Set_url(const WideString p) = 0 ;
	virtual HRESULT __stdcall Get_mimeType(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_readyState(/* out */ int &pl) = 0 ;
	virtual HRESULT __stdcall Get_charset(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Set_charset(const WideString p) = 0 ;
	virtual HRESULT __stdcall Get_version(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_doctype(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall Get_dtdURL(/* out */ WideString &p) = 0 ;
	virtual HRESULT __stdcall createElement(const OleVariant vType, const OleVariant var1, /* out */ _di_IXMLElement2 &ppElem) = 0 ;
	virtual HRESULT __stdcall Get_async(/* out */ Word &pf) = 0 ;
	virtual HRESULT __stdcall Set_async(Word pf) = 0 ;
};

__interface INTERFACE_UUID("{2B8DE2FF-8D2D-11D1-B2FC-00C04FD915A9}") IXMLElement2  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_tagName(WideString &Get_tagName_result) = 0 ;
	virtual HRESULT __safecall Set_tagName(const WideString p) = 0 ;
	virtual HRESULT __safecall Get_parent(_di_IXMLElement2 &Get_parent_result) = 0 ;
	virtual HRESULT __safecall setAttribute(const WideString strPropertyName, const OleVariant PropertyValue) = 0 ;
	virtual HRESULT __safecall getAttribute(const WideString strPropertyName, OleVariant &getAttribute_result) = 0 ;
	virtual HRESULT __safecall removeAttribute(const WideString strPropertyName) = 0 ;
	virtual HRESULT __safecall Get_children(_di_IXMLElementCollection &Get_children_result) = 0 ;
	virtual HRESULT __safecall Get_type_(int &Get_type__result) = 0 ;
	virtual HRESULT __safecall Get_text(WideString &Get_text_result) = 0 ;
	virtual HRESULT __safecall Set_text(const WideString p) = 0 ;
	virtual HRESULT __safecall addChild(const _di_IXMLElement2 pChildElem, int lIndex, int lReserved) = 0 ;
	virtual HRESULT __safecall removeChild(const _di_IXMLElement2 pChildElem) = 0 ;
	virtual HRESULT __safecall Get_attributes(_di_IXMLElementCollection &Get_attributes_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_tagName() { WideString r; HRESULT hr = Get_tagName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString tagName = {read=_scw_Get_tagName, write=Set_tagName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLElement2 _scw_Get_parent() { _di_IXMLElement2 r; HRESULT hr = Get_parent(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLElement2 parent = {read=_scw_Get_parent};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLElementCollection _scw_Get_children() { _di_IXMLElementCollection r; HRESULT hr = Get_children(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLElementCollection children = {read=_scw_Get_children};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_type_() { int r; HRESULT hr = Get_type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int type_ = {read=_scw_Get_type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_text() { WideString r; HRESULT hr = Get_text(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString text = {read=_scw_Get_text, write=Set_text};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IXMLElementCollection _scw_Get_attributes() { _di_IXMLElementCollection r; HRESULT hr = Get_attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IXMLElementCollection attributes = {read=_scw_Get_attributes};
};

__dispinterface IXMLElement2Disp;
typedef System::DelphiInterface<IXMLElement2Disp> _di_IXMLElement2Disp;
__dispinterface INTERFACE_UUID("{2B8DE2FF-8D2D-11D1-B2FC-00C04FD915A9}") IXMLElement2Disp  : public IDispatch 
{
	
};

__interface IXMLAttribute;
typedef System::DelphiInterface<IXMLAttribute> _di_IXMLAttribute;
__interface INTERFACE_UUID("{D4D4A0FC-3B73-11D1-B2B4-00C04FB92596}") IXMLAttribute  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_name(WideString &Get_name_result) = 0 ;
	virtual HRESULT __safecall Get_value(WideString &Get_value_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_name() { WideString r; HRESULT hr = Get_name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString name = {read=_scw_Get_name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_value() { WideString r; HRESULT hr = Get_value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString value = {read=_scw_Get_value};
};

__dispinterface IXMLAttributeDisp;
typedef System::DelphiInterface<IXMLAttributeDisp> _di_IXMLAttributeDisp;
__dispinterface INTERFACE_UUID("{D4D4A0FC-3B73-11D1-B2B4-00C04FB92596}") IXMLAttributeDisp  : public IDispatch 
{
	
};

__interface IXMLError;
typedef System::DelphiInterface<IXMLError> _di_IXMLError;
__interface INTERFACE_UUID("{948C5AD3-C58D-11D0-9C0B-00C04FC99C8E}") IXMLError  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetErrorInfo(_xml_error &pErrorReturn) = 0 ;
};

class DELPHICLASS CoDOMDocument;
class PASCALIMPLEMENTATION CoDOMDocument : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IXMLDOMDocument __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IXMLDOMDocument __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDOMDocument(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDOMDocument(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDOMFreeThreadedDocument;
class PASCALIMPLEMENTATION CoDOMFreeThreadedDocument : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IXMLDOMDocument __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IXMLDOMDocument __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDOMFreeThreadedDocument(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDOMFreeThreadedDocument(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoXMLHTTPRequest;
class PASCALIMPLEMENTATION CoXMLHTTPRequest : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IXMLHttpRequest __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IXMLHttpRequest __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoXMLHTTPRequest(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoXMLHTTPRequest(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoXMLDSOControl;
class PASCALIMPLEMENTATION CoXMLDSOControl : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IXMLDSOControl __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IXMLDSOControl __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoXMLDSOControl(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoXMLDSOControl(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoXMLDocument;
class PASCALIMPLEMENTATION CoXMLDocument : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IXMLDocument2 __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IXMLDocument2 __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoXMLDocument(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoXMLDocument(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MSXMLMajorVersion = 0x2;
static const Shortint MSXMLMinorVersion = 0x0;
extern PACKAGE GUID LIBID_MSXML;
extern PACKAGE GUID IID_IXMLDOMImplementation;
extern PACKAGE GUID IID_IXMLDOMNode;
extern PACKAGE GUID IID_IXMLDOMNodeList;
extern PACKAGE GUID IID_IXMLDOMNamedNodeMap;
extern PACKAGE GUID IID_IXMLDOMDocument;
extern PACKAGE GUID IID_IXMLDOMDocumentType;
extern PACKAGE GUID IID_IXMLDOMElement;
extern PACKAGE GUID IID_IXMLDOMAttribute;
extern PACKAGE GUID IID_IXMLDOMDocumentFragment;
extern PACKAGE GUID IID_IXMLDOMCharacterData;
extern PACKAGE GUID IID_IXMLDOMText;
extern PACKAGE GUID IID_IXMLDOMComment;
extern PACKAGE GUID IID_IXMLDOMCDATASection;
extern PACKAGE GUID IID_IXMLDOMProcessingInstruction;
extern PACKAGE GUID IID_IXMLDOMEntityReference;
extern PACKAGE GUID IID_IXMLDOMParseError;
extern PACKAGE GUID IID_IXMLDOMNotation;
extern PACKAGE GUID IID_IXMLDOMEntity;
extern PACKAGE GUID IID_IXTLRuntime;
extern PACKAGE GUID DIID_XMLDOMDocumentEvents;
extern PACKAGE GUID CLASS_DOMDocument;
extern PACKAGE GUID CLASS_DOMFreeThreadedDocument;
extern PACKAGE GUID IID_IXMLHttpRequest;
extern PACKAGE GUID CLASS_XMLHTTPRequest;
extern PACKAGE GUID IID_IXMLDSOControl;
extern PACKAGE GUID CLASS_XMLDSOControl;
extern PACKAGE GUID IID_IXMLElementCollection;
extern PACKAGE GUID IID_IXMLDocument;
extern PACKAGE GUID IID_IXMLElement;
extern PACKAGE GUID IID_IXMLDocument2;
extern PACKAGE GUID IID_IXMLElement2;
extern PACKAGE GUID IID_IXMLAttribute;
extern PACKAGE GUID IID_IXMLError;
extern PACKAGE GUID CLASS_XMLDocument;

}	/* namespace Msxml */
using namespace Msxml;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// msxml
