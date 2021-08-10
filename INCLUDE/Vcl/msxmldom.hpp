// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'msxmldom.pas' rev: 6.00

#ifndef msxmldomHPP
#define msxmldomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <msxml.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Msxmldom
{
//-- type declarations -------------------------------------------------------
__interface IXMLDOMNodeRef;
typedef System::DelphiInterface<IXMLDOMNodeRef> _di_IXMLDOMNodeRef;
__interface INTERFACE_UUID("{5EF5DAA1-2729-11D4-83DA-00C04F60B2DD}") IXMLDOMNodeRef  : public IInterface 
{
	
public:
	virtual Msxml::_di_IXMLDOMNode __fastcall GetXMLDOMNode(void) = 0 ;
};

class DELPHICLASS TMSDOMInterface;
class PASCALIMPLEMENTATION TMSDOMInterface : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMSDOMInterface(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMInterface(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMSDOMImplementation;
class PASCALIMPLEMENTATION TMSDOMImplementation : public TMSDOMInterface 
{
	typedef TMSDOMInterface inherited;
	
private:
	Msxml::_di_IXMLDOMImplementation FMSDOMImpl;
	
protected:
	Word __fastcall hasFeature(const WideString feature, const WideString version);
	HRESULT __safecall createDocumentType(const WideString qualifiedName, const WideString publicId, const WideString systemId, Xmldom::_di_IDOMDocumentType &createDocumentType_result);
	HRESULT __safecall createDocument(const WideString namespaceURI, const WideString qualifiedName, Xmldom::_di_IDOMDocumentType doctype, Xmldom::_di_IDOMDocument &createDocument_result);
	
public:
	__fastcall TMSDOMImplementation(Msxml::_di_IXMLDOMImplementation DOMImpl);
	__property Msxml::_di_IXMLDOMImplementation MSDOMImpl = {read=FMSDOMImpl};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMImplementation(void) { }
	#pragma option pop
	
private:
	void *__IDOMImplementation;	/* Xmldom::IDOMImplementation */
	
public:
	operator IDOMImplementation*(void) { return (IDOMImplementation*)&__IDOMImplementation; }
	
};


typedef TMetaClass*TMSDOMNodeClass;

class DELPHICLASS TMSDOMNode;
class PASCALIMPLEMENTATION TMSDOMNode : public TMSDOMInterface 
{
	typedef TMSDOMInterface inherited;
	
private:
	Msxml::_di_IXMLDOMNode FMSNode;
	Xmldom::_di_IDOMNodeList FChildNodes;
	Xmldom::_di_IDOMNamedNodeMap FAttributes;
	Xmldom::_di_IDOMDocument FOwnerDocument;
	
protected:
	Msxml::_di_IXMLDOMNode __fastcall GetXMLDOMNode();
	HRESULT __safecall get_nodeName(WideString &get_nodeName_result);
	HRESULT __safecall get_nodeValue(WideString &get_nodeValue_result);
	void __fastcall set_nodeValue(WideString value);
	HRESULT __safecall get_nodeType(Word &get_nodeType_result);
	HRESULT __safecall get_parentNode(Xmldom::_di_IDOMNode &get_parentNode_result);
	HRESULT __safecall get_childNodes(Xmldom::_di_IDOMNodeList &get_childNodes_result);
	HRESULT __safecall get_firstChild(Xmldom::_di_IDOMNode &get_firstChild_result);
	HRESULT __safecall get_lastChild(Xmldom::_di_IDOMNode &get_lastChild_result);
	HRESULT __safecall get_previousSibling(Xmldom::_di_IDOMNode &get_previousSibling_result);
	HRESULT __safecall get_nextSibling(Xmldom::_di_IDOMNode &get_nextSibling_result);
	HRESULT __safecall get_attributes(Xmldom::_di_IDOMNamedNodeMap &get_attributes_result);
	HRESULT __safecall get_ownerDocument(Xmldom::_di_IDOMDocument &get_ownerDocument_result);
	HRESULT __safecall get_namespaceURI(WideString &get_namespaceURI_result);
	HRESULT __safecall get_prefix(WideString &get_prefix_result);
	HRESULT __safecall get_localName(WideString &get_localName_result);
	HRESULT __safecall insertBefore(const Xmldom::_di_IDOMNode newChild, const Xmldom::_di_IDOMNode refChild, Xmldom::_di_IDOMNode &insertBefore_result);
	HRESULT __safecall replaceChild(const Xmldom::_di_IDOMNode newChild, const Xmldom::_di_IDOMNode oldChild, Xmldom::_di_IDOMNode &replaceChild_result);
	HRESULT __safecall removeChild(const Xmldom::_di_IDOMNode childNode, Xmldom::_di_IDOMNode &removeChild_result);
	HRESULT __safecall appendChild(const Xmldom::_di_IDOMNode newChild, Xmldom::_di_IDOMNode &appendChild_result);
	HRESULT __safecall hasChildNodes(Word &hasChildNodes_result);
	HRESULT __safecall cloneNode(Word deep, Xmldom::_di_IDOMNode &cloneNode_result);
	void __fastcall normalize(void);
	Word __fastcall supports(const WideString feature, const WideString version);
	HRESULT __safecall get_text(WideString &get_text_result);
	HRESULT __safecall get_xml(WideString &get_xml_result);
	void __fastcall transformNode(const Xmldom::_di_IDOMNode stylesheet, WideString &output)/* overload */;
	void __fastcall transformNode(const Xmldom::_di_IDOMNode stylesheet, const Xmldom::_di_IDOMDocument output)/* overload */;
	HRESULT __safecall selectNode(const WideString nodePath, Xmldom::_di_IDOMNode &selectNode_result);
	HRESULT __safecall selectNodes(const WideString nodePath, Xmldom::_di_IDOMNodeList &selectNodes_result);
	HRESULT __safecall set_text(const WideString Value);
	
public:
	__fastcall TMSDOMNode(Msxml::_di_IXMLDOMNode ANode);
	__property Msxml::_di_IXMLDOMNode MSNode = {read=FMSNode};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMNode(void) { }
	#pragma option pop
	
private:
	void *__IXMLDOMNodeRef;	/* Msxmldom::IXMLDOMNodeRef */
	void *__IDOMNodeEx;	/* Xmldom::IDOMNodeEx */
	void *__IDOMNodeSelect;	/* Xmldom::IDOMNodeSelect */
	
public:
	operator IDOMNodeSelect*(void) { return (IDOMNodeSelect*)&__IDOMNodeSelect; }
	operator IDOMNodeEx*(void) { return (IDOMNodeEx*)&__IDOMNodeEx; }
	operator IDOMNode*(void) { return (IDOMNode*)&__IDOMNodeEx; }
	operator IXMLDOMNodeRef*(void) { return (IXMLDOMNodeRef*)&__IXMLDOMNodeRef; }
	
};


class DELPHICLASS TMSDOMNodeList;
class PASCALIMPLEMENTATION TMSDOMNodeList : public TMSDOMInterface 
{
	typedef TMSDOMInterface inherited;
	
private:
	Msxml::_di_IXMLDOMNodeList FMSNodeList;
	
protected:
	HRESULT __safecall get_item(int index, Xmldom::_di_IDOMNode &get_item_result);
	HRESULT __safecall get_length(int &get_length_result);
	
public:
	__fastcall TMSDOMNodeList(Msxml::_di_IXMLDOMNodeList ANodeList);
	__property Msxml::_di_IXMLDOMNodeList MSNodeList = {read=FMSNodeList};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMNodeList(void) { }
	#pragma option pop
	
private:
	void *__IDOMNodeList;	/* Xmldom::IDOMNodeList */
	
public:
	operator IDOMNodeList*(void) { return (IDOMNodeList*)&__IDOMNodeList; }
	
};


class DELPHICLASS TMSDOMNamedNodeMap;
class PASCALIMPLEMENTATION TMSDOMNamedNodeMap : public TMSDOMInterface 
{
	typedef TMSDOMInterface inherited;
	
private:
	Msxml::_di_IXMLDOMNamedNodeMap FMSNamedNodeMap;
	
protected:
	HRESULT __safecall get_item(int index, Xmldom::_di_IDOMNode &get_item_result);
	int __fastcall get_length(void);
	HRESULT __safecall getNamedItem(const WideString name, Xmldom::_di_IDOMNode &getNamedItem_result);
	HRESULT __safecall setNamedItem(const Xmldom::_di_IDOMNode newItem, Xmldom::_di_IDOMNode &setNamedItem_result);
	HRESULT __safecall removeNamedItem(const WideString name, Xmldom::_di_IDOMNode &removeNamedItem_result);
	HRESULT __safecall getNamedItemNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNode &getNamedItemNS_result);
	HRESULT __safecall setNamedItemNS(const Xmldom::_di_IDOMNode arg, Xmldom::_di_IDOMNode &setNamedItemNS_result);
	HRESULT __safecall removeNamedItemNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNode &removeNamedItemNS_result);
	
public:
	__fastcall TMSDOMNamedNodeMap(Msxml::_di_IXMLDOMNamedNodeMap ANamedNodeMap);
	__property Msxml::_di_IXMLDOMNamedNodeMap MSNamedNodeMap = {read=FMSNamedNodeMap};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMNamedNodeMap(void) { }
	#pragma option pop
	
private:
	void *__IDOMNamedNodeMap;	/* Xmldom::IDOMNamedNodeMap */
	
public:
	operator IDOMNamedNodeMap*(void) { return (IDOMNamedNodeMap*)&__IDOMNamedNodeMap; }
	
};


class DELPHICLASS TMSDOMCharacterData;
class PASCALIMPLEMENTATION TMSDOMCharacterData : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMCharacterData __fastcall GetMSCharacterData();
	
protected:
	WideString __fastcall get_data();
	void __fastcall set_data(const WideString data);
	int __fastcall get_length(void);
	WideString __fastcall substringData(int offset, int count);
	void __fastcall appendData(const WideString data);
	void __fastcall insertData(int offset, const WideString data);
	void __fastcall deleteData(int offset, int count);
	void __fastcall replaceData(int offset, int count, const WideString data);
	
public:
	__property Msxml::_di_IXMLDOMCharacterData MSCharacterData = {read=GetMSCharacterData};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMCharacterData(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMCharacterData(void) { }
	#pragma option pop
	
private:
	void *__IDOMCharacterData;	/* Xmldom::IDOMCharacterData */
	
public:
	operator IDOMCharacterData*(void) { return (IDOMCharacterData*)&__IDOMCharacterData; }
	
};


class DELPHICLASS TMSDOMAttr;
class PASCALIMPLEMENTATION TMSDOMAttr : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMAttribute __fastcall GetMSAttribute();
	
protected:
	WideString __fastcall get_name();
	Word __fastcall get_specified(void);
	WideString __fastcall get_value();
	void __fastcall set_value(const WideString attributeValue);
	Xmldom::_di_IDOMElement __fastcall get_ownerElement();
	__property WideString name = {read=get_name};
	__property Word specified = {read=get_specified, nodefault};
	__property WideString value = {read=get_value, write=set_value};
	__property Xmldom::_di_IDOMElement ownerElement = {read=get_ownerElement};
	
public:
	__property Msxml::_di_IXMLDOMAttribute MSAttribute = {read=GetMSAttribute};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMAttr(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMAttr(void) { }
	#pragma option pop
	
private:
	void *__IDOMAttr;	/* Xmldom::IDOMAttr */
	
public:
	operator IDOMAttr*(void) { return (IDOMAttr*)&__IDOMAttr; }
	
};


class DELPHICLASS TMSDOMElement;
class PASCALIMPLEMENTATION TMSDOMElement : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMElement __fastcall GetMSElement();
	
protected:
	HRESULT __safecall get_tagName(WideString &get_tagName_result);
	HRESULT __safecall getAttribute(const WideString name, WideString &getAttribute_result);
	void __fastcall setAttribute(const WideString name, const WideString value);
	void __fastcall removeAttribute(const WideString name);
	HRESULT __safecall getAttributeNode(const WideString name, Xmldom::_di_IDOMAttr &getAttributeNode_result);
	HRESULT __safecall setAttributeNode(const Xmldom::_di_IDOMAttr newAttr, Xmldom::_di_IDOMAttr &setAttributeNode_result);
	HRESULT __safecall removeAttributeNode(const Xmldom::_di_IDOMAttr oldAttr, Xmldom::_di_IDOMAttr &removeAttributeNode_result);
	HRESULT __safecall getElementsByTagName(const WideString name, Xmldom::_di_IDOMNodeList &getElementsByTagName_result);
	HRESULT __safecall getAttributeNS(const WideString namespaceURI, const WideString localName, WideString &getAttributeNS_result);
	void __fastcall setAttributeNS(const WideString namespaceURI, const WideString qualifiedName, const WideString value);
	void __fastcall removeAttributeNS(const WideString namespaceURI, const WideString localName);
	HRESULT __safecall getAttributeNodeNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMAttr &getAttributeNodeNS_result);
	HRESULT __safecall setAttributeNodeNS(const Xmldom::_di_IDOMAttr newAttr, Xmldom::_di_IDOMAttr &setAttributeNodeNS_result);
	HRESULT __safecall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNodeList &getElementsByTagNameNS_result);
	HRESULT __safecall hasAttribute(const WideString name, Word &hasAttribute_result);
	Word __fastcall hasAttributeNS(const WideString namespaceURI, const WideString localName);
	HIDESBASE void __fastcall normalize(void);
	
public:
	__property Msxml::_di_IXMLDOMElement MSElement = {read=GetMSElement};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMElement(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMElement(void) { }
	#pragma option pop
	
private:
	void *__IDOMElement;	/* Xmldom::IDOMElement */
	
public:
	operator IDOMElement*(void) { return (IDOMElement*)&__IDOMElement; }
	
};


class DELPHICLASS TMSDOMText;
class PASCALIMPLEMENTATION TMSDOMText : public TMSDOMCharacterData 
{
	typedef TMSDOMCharacterData inherited;
	
protected:
	HRESULT __safecall splitText(int offset, Xmldom::_di_IDOMText &splitText_result);
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMText(Msxml::_di_IXMLDOMNode ANode) : TMSDOMCharacterData(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMText(void) { }
	#pragma option pop
	
private:
	void *__IDOMText;	/* Xmldom::IDOMText */
	
public:
	operator IDOMText*(void) { return (IDOMText*)&__IDOMText; }
	
};


class DELPHICLASS TMSDOMComment;
class PASCALIMPLEMENTATION TMSDOMComment : public TMSDOMCharacterData 
{
	typedef TMSDOMCharacterData inherited;
	
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMComment(Msxml::_di_IXMLDOMNode ANode) : TMSDOMCharacterData(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMComment(void) { }
	#pragma option pop
	
private:
	void *__IDOMComment;	/* Xmldom::IDOMComment */
	
public:
	operator IDOMComment*(void) { return (IDOMComment*)&__IDOMComment; }
	
};


class DELPHICLASS TMSDOMCDATASection;
class PASCALIMPLEMENTATION TMSDOMCDATASection : public TMSDOMText 
{
	typedef TMSDOMText inherited;
	
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMCDATASection(Msxml::_di_IXMLDOMNode ANode) : TMSDOMText(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMCDATASection(void) { }
	#pragma option pop
	
private:
	void *__IDOMCDATASection;	/* Xmldom::IDOMCDATASection */
	
public:
	operator IDOMCDATASection*(void) { return (IDOMCDATASection*)&__IDOMCDATASection; }
	
};


class DELPHICLASS TMSDOMDocumentType;
class PASCALIMPLEMENTATION TMSDOMDocumentType : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Xmldom::_di_IDOMNamedNodeMap FEntities;
	Xmldom::_di_IDOMNamedNodeMap FNotations;
	Msxml::_di_IXMLDOMDocumentType __fastcall GetMSDocumentType();
	
protected:
	HRESULT __safecall get_name(WideString &get_name_result);
	HRESULT __safecall get_entities(Xmldom::_di_IDOMNamedNodeMap &get_entities_result);
	HRESULT __safecall get_notations(Xmldom::_di_IDOMNamedNodeMap &get_notations_result);
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	HRESULT __safecall get_internalSubset(WideString &get_internalSubset_result);
	
public:
	__property Msxml::_di_IXMLDOMDocumentType MSDocumentType = {read=GetMSDocumentType};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMDocumentType(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMDocumentType(void) { }
	#pragma option pop
	
private:
	void *__IDOMDocumentType;	/* Xmldom::IDOMDocumentType */
	
public:
	operator IDOMDocumentType*(void) { return (IDOMDocumentType*)&__IDOMDocumentType; }
	
};


class DELPHICLASS TMSDOMNotation;
class PASCALIMPLEMENTATION TMSDOMNotation : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMNotation __fastcall GetMSNotation();
	
protected:
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	
public:
	__property Msxml::_di_IXMLDOMNotation MSNotation = {read=GetMSNotation};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMNotation(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMNotation(void) { }
	#pragma option pop
	
private:
	void *__IDOMNotation;	/* Xmldom::IDOMNotation */
	
public:
	operator IDOMNotation*(void) { return (IDOMNotation*)&__IDOMNotation; }
	
};


class DELPHICLASS TMSDOMEntity;
class PASCALIMPLEMENTATION TMSDOMEntity : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMEntity __fastcall GetMSEntity();
	
protected:
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	HRESULT __safecall get_notationName(WideString &get_notationName_result);
	
public:
	__property Msxml::_di_IXMLDOMEntity MSEntity = {read=GetMSEntity};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMEntity(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMEntity(void) { }
	#pragma option pop
	
private:
	void *__IDOMEntity;	/* Xmldom::IDOMEntity */
	
public:
	operator IDOMEntity*(void) { return (IDOMEntity*)&__IDOMEntity; }
	
};


class DELPHICLASS TMSDOMEntityReference;
class PASCALIMPLEMENTATION TMSDOMEntityReference : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMEntityReference(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMEntityReference(void) { }
	#pragma option pop
	
private:
	void *__IDOMEntityReference;	/* Xmldom::IDOMEntityReference */
	
public:
	operator IDOMEntityReference*(void) { return (IDOMEntityReference*)&__IDOMEntityReference; }
	
};


class DELPHICLASS TMSDOMProcessingInstruction;
class PASCALIMPLEMENTATION TMSDOMProcessingInstruction : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMProcessingInstruction __fastcall GetMSProcessingInstruction();
	
protected:
	HRESULT __safecall get_target(WideString &get_target_result);
	HRESULT __safecall get_data(WideString &get_data_result);
	void __fastcall set_data(const WideString value);
	
public:
	__property Msxml::_di_IXMLDOMProcessingInstruction MSProcessingInstruction = {read=GetMSProcessingInstruction};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMProcessingInstruction(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMProcessingInstruction(void) { }
	#pragma option pop
	
private:
	void *__IDOMProcessingInstruction;	/* Xmldom::IDOMProcessingInstruction */
	
public:
	operator IDOMProcessingInstruction*(void) { return (IDOMProcessingInstruction*)&__IDOMProcessingInstruction; }
	
};


class DELPHICLASS TMSDOMDocumentFragment;
class PASCALIMPLEMENTATION TMSDOMDocumentFragment : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMDocumentFragment(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMDocumentFragment(void) { }
	#pragma option pop
	
private:
	void *__IDOMDocumentFragment;	/* Xmldom::IDOMDocumentFragment */
	
public:
	operator IDOMDocumentFragment*(void) { return (IDOMDocumentFragment*)&__IDOMDocumentFragment; }
	
};


class DELPHICLASS TMSDOMEventHandler;
class DELPHICLASS TMSDOMDocument;
class PASCALIMPLEMENTATION TMSDOMDocument : public TMSDOMNode 
{
	typedef TMSDOMNode inherited;
	
private:
	Msxml::_di_IXMLDOMDocument __fastcall GetMSDocument();
	
protected:
	HRESULT __safecall get_doctype(Xmldom::_di_IDOMDocumentType &get_doctype_result);
	HRESULT __safecall get_domImplementation(Xmldom::_di_IDOMImplementation &get_domImplementation_result);
	HRESULT __safecall get_documentElement(Xmldom::_di_IDOMElement &get_documentElement_result);
	void __fastcall set_documentElement(const Xmldom::_di_IDOMElement IDOMElement);
	HRESULT __safecall createElement(const WideString tagName, Xmldom::_di_IDOMElement &createElement_result);
	HRESULT __safecall createDocumentFragment(Xmldom::_di_IDOMDocumentFragment &createDocumentFragment_result);
	HRESULT __safecall createTextNode(const WideString data, Xmldom::_di_IDOMText &createTextNode_result);
	HRESULT __safecall createComment(const WideString data, Xmldom::_di_IDOMComment &createComment_result);
	HRESULT __safecall createCDATASection(const WideString data, Xmldom::_di_IDOMCDATASection &createCDATASection_result);
	HRESULT __safecall createProcessingInstruction(const WideString target, const WideString data, Xmldom::_di_IDOMProcessingInstruction &createProcessingInstruction_result);
	HRESULT __safecall createAttribute(const WideString name, Xmldom::_di_IDOMAttr &createAttribute_result);
	HRESULT __safecall createEntityReference(const WideString name, Xmldom::_di_IDOMEntityReference &createEntityReference_result);
	HRESULT __safecall getElementsByTagName(const WideString tagName, Xmldom::_di_IDOMNodeList &getElementsByTagName_result);
	HRESULT __safecall importNode(Xmldom::_di_IDOMNode importedNode, Word deep, Xmldom::_di_IDOMNode &importNode_result);
	HRESULT __safecall createElementNS(const WideString namespaceURI, const WideString qualifiedName, Xmldom::_di_IDOMElement &createElementNS_result);
	HRESULT __safecall createAttributeNS(const WideString namespaceURI, const WideString qualifiedName, Xmldom::_di_IDOMAttr &createAttributeNS_result);
	HRESULT __safecall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNodeList &getElementsByTagNameNS_result);
	Xmldom::_di_IDOMElement __fastcall getElementById(const WideString elementId);
	bool __fastcall get_async(void);
	bool __fastcall get_preserveWhiteSpace(void);
	bool __fastcall get_resolveExternals(void);
	bool __fastcall get_validate(void);
	void __fastcall set_async(bool Value);
	void __fastcall set_preserveWhiteSpace(bool Value);
	void __fastcall set_resolveExternals(bool Value);
	void __fastcall set_validate(bool Value);
	HIDESBASE HRESULT __safecall get_xml(WideString &get_xml_result);
	HRESULT __safecall asyncLoadState(int &asyncLoadState_result);
	HRESULT __safecall load(const OleVariant source, Word &load_result);
	HRESULT __safecall loadFromStream(const Classes::TStream* stream, Word &loadFromStream_result);
	HRESULT __safecall loadxml(const WideString Value, Word &loadxml_result);
	HRESULT __safecall save(const OleVariant destination);
	HRESULT __safecall saveToStream(const Classes::TStream* stream);
	HRESULT __safecall set_OnAsyncLoad(const System::TObject* Sender, Xmldom::TAsyncEventHandler EventHandler);
	int __fastcall get_errorCode(void);
	HRESULT __safecall get_url(WideString &get_url_result);
	HRESULT __safecall get_reason(WideString &get_reason_result);
	HRESULT __safecall get_srcText(WideString &get_srcText_result);
	int __fastcall get_line(void);
	int __fastcall get_linepos(void);
	int __fastcall get_filepos(void);
	
public:
	__property Msxml::_di_IXMLDOMDocument MSDocument = {read=GetMSDocument};
public:
	#pragma option push -w-inl
	/* TMSDOMNode.Create */ inline __fastcall TMSDOMDocument(Msxml::_di_IXMLDOMNode ANode) : TMSDOMNode(ANode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMDocument(void) { }
	#pragma option pop
	
private:
	void *__IDOMDocument;	/* Xmldom::IDOMDocument */
	void *__IDOMParseOptions;	/* Xmldom::IDOMParseOptions */
	void *__IDOMPersist;	/* Xmldom::IDOMPersist */
	void *__IDOMParseError;	/* Xmldom::IDOMParseError */
	
public:
	operator IDOMParseError*(void) { return (IDOMParseError*)&__IDOMParseError; }
	operator IDOMPersist*(void) { return (IDOMPersist*)&__IDOMPersist; }
	operator IDOMParseOptions*(void) { return (IDOMParseOptions*)&__IDOMParseOptions; }
	operator IDOMDocument*(void) { return (IDOMDocument*)&__IDOMDocument; }
	
};


class PASCALIMPLEMENTATION TMSDOMEventHandler : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::TObject* FSender;
	TMSDOMDocument* FDocument;
	Xmldom::TAsyncEventHandler FEventHandler;
	
protected:
	virtual HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	virtual HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	virtual HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	virtual HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	
public:
	__fastcall TMSDOMEventHandler(const TMSDOMDocument* Document, Xmldom::TAsyncEventHandler AsyncEventHandler, System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMEventHandler(void) { }
	#pragma option pop
	
private:
	void *__IDispatch;	/* IDispatch */
	
public:
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	
};


class DELPHICLASS TMSDOMImplementationFactory;
class PASCALIMPLEMENTATION TMSDOMImplementationFactory : public Xmldom::TDOMVendor 
{
	typedef Xmldom::TDOMVendor inherited;
	
public:
	virtual Xmldom::_di_IDOMImplementation __fastcall DOMImplementation();
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMSDOMImplementationFactory(void) : Xmldom::TDOMVendor() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMSDOMImplementationFactory(void) { }
	#pragma option pop
	
};


typedef Msxml::_di_IXMLDOMDocument __fastcall (*TMSXMLDOMDocumentCreateFunc)(void);

//-- var, const, procedure ---------------------------------------------------
#define SMSXML "MSXML"
extern PACKAGE TMSDOMImplementationFactory* MSXML_DOM;
extern PACKAGE TMSXMLDOMDocumentCreateFunc MSXMLDOMDocumentCreate;
extern PACKAGE bool __fastcall LoadFromXMLString(const Msxml::_di_IXMLDOMDocument Doc, const AnsiString XML);
extern PACKAGE Msxml::_di_IXMLDOMDocument __fastcall CreateDOMDocument();

}	/* namespace Msxmldom */
using namespace Msxmldom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// msxmldom
