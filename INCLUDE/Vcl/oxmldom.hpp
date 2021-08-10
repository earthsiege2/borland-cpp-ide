// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'oxmldom.pas' rev: 6.00

#ifndef oxmldomHPP
#define oxmldomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xdom.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "oxmldom.obj"

namespace Oxmldom
{
//-- type declarations -------------------------------------------------------
__interface IOXDOMNodeRef;
typedef System::DelphiInterface<IOXDOMNodeRef> _di_IOXDOMNodeRef;
__interface INTERFACE_UUID("{921E0E60-BC17-11D4-9ABD-9039FDE1134E}") IOXDOMNodeRef  : public IInterface 
{
	
public:
	virtual Xdom::TdomNode* __fastcall GetDOMNode(void) = 0 ;
};

class DELPHICLASS TOXDOMInterface;
class PASCALIMPLEMENTATION TOXDOMInterface : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TOXDOMInterface(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOXDOMInterface(void) { }
	#pragma option pop
	
};


struct TParseErrorInfo;
typedef TParseErrorInfo *PParseErrorInfo;

#pragma pack(push, 4)
struct TParseErrorInfo
{
	int errorCode;
	WideString url;
	WideString reason;
	WideString srcText;
	int line;
	int linePos;
	int filePos;
} ;
#pragma pack(pop)

class DELPHICLASS TOXDOMImplementation;
class DELPHICLASS TOXDOMDocument;
class PASCALIMPLEMENTATION TOXDOMImplementation : public TOXDOMInterface 
{
	typedef TOXDOMInterface inherited;
	
private:
	Xdom::TDomImplementation* FDOMImpl;
	TParseErrorInfo *FParseError;
	Xdom::TXmlDocBuilder* FDocBuilder1;
	Xdom::TXmlDocBuilder* FDocBuilder2;
	Xdom::TXmlStandardDomReader* FXMLDomReader;
	Xdom::TXmlStandardProcessorAgent* FXMLAgent;
	Xdom::TdomDocument* FTempDoc;
	Xdom::TDomImplementation* __fastcall GetDOMImpl(void);
	
protected:
	Word __fastcall hasFeature(const WideString feature, const WideString version);
	HRESULT __safecall createDocumentType(const WideString qualifiedName, const WideString publicId, const WideString systemId, Xmldom::_di_IDOMDocumentType &createDocumentType_result);
	HRESULT __safecall createDocument(const WideString namespaceURI, const WideString qualifiedName, Xmldom::_di_IDOMDocumentType doctype, Xmldom::_di_IDOMDocument &createDocument_result);
	void __fastcall OnXMLDeclaration(Xdom::TXmlCustomProcessorAgent* processorAgent, Xdom::TdomStandardLocator* locator, WideString &verDl, WideString &encDl, WideString &sdDl);
	
public:
	__fastcall TOXDOMImplementation(void);
	__fastcall virtual ~TOXDOMImplementation(void);
	void __fastcall FreeDocument(Xdom::TdomDocument* &Doc);
	void __fastcall InitParserAgent(void);
	Word __fastcall loadFromStream(const Classes::TStream* stream, const TOXDOMDocument* Doc, TParseErrorInfo &ParseError);
	Word __fastcall loadxml(const WideString Value, const Xdom::TdomDocument* Doc, TParseErrorInfo &ParseError);
	void __fastcall ParseErrorHandler(Xdom::TXmlCustomProcessorAgent* processorAgent, Xdom::TXmlParserError* e);
	__property Xdom::TDomImplementation* DOMImpl = {read=GetDOMImpl};
private:
	void *__IDOMImplementation;	/* Xmldom::IDOMImplementation */
	
public:
	operator IDOMImplementation*(void) { return (IDOMImplementation*)&__IDOMImplementation; }
	
};


typedef TMetaClass*TOXDOMNodeClass;

class DELPHICLASS TOXDOMNode;
class PASCALIMPLEMENTATION TOXDOMNode : public TOXDOMInterface 
{
	typedef TOXDOMInterface inherited;
	
private:
	Xdom::TdomNode* FNode;
	TOXDOMDocument* FOXDOMDocument;
	Xmldom::_di_IDOMNodeList FChildNodes;
	Xmldom::_di_IDOMNamedNodeMap FAttributes;
	Xmldom::_di_IDOMDocument FOwnerDocument;
	
protected:
	Xdom::TdomNode* __fastcall GetDOMNode(void);
	HRESULT __safecall get_nodeName(WideString &get_nodeName_result);
	HRESULT __safecall get_nodeValue(WideString &get_nodeValue_result);
	void __fastcall set_nodeValue(WideString value);
	HRESULT __safecall get_nodeType(Word &get_nodeType_result);
	HRESULT __safecall get_parentNode(Xmldom::_di_IDOMNode &get_parentNode_result);
	virtual HRESULT __safecall get_childNodes(Xmldom::_di_IDOMNodeList &get_childNodes_result);
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
	virtual HRESULT __safecall hasChildNodes(Word &hasChildNodes_result);
	HRESULT __safecall cloneNode(Word deep, Xmldom::_di_IDOMNode &cloneNode_result);
	void __fastcall normalize(void);
	Word __fastcall supports(const WideString feature, const WideString version);
	HRESULT __safecall get_text(WideString &get_text_result);
	HRESULT __safecall get_xml(WideString &get_xml_result);
	HRESULT __safecall set_text(const WideString Value);
	void __fastcall transformNode(const Xmldom::_di_IDOMNode stylesheet, WideString &output)/* overload */;
	void __fastcall transformNode(const Xmldom::_di_IDOMNode stylesheet, const Xmldom::_di_IDOMDocument output)/* overload */;
	HRESULT __safecall selectNode(const WideString nodePath, Xmldom::_di_IDOMNode &selectNode_result);
	HRESULT __safecall selectNodes(const WideString nodePath, Xmldom::_di_IDOMNodeList &selectNodes_result);
	
public:
	__fastcall virtual TOXDOMNode(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument);
	__fastcall virtual ~TOXDOMNode(void);
	__property Xdom::TdomNode* Node = {read=FNode};
	__property TOXDOMDocument* OXDOMDocument = {read=FOXDOMDocument};
private:
	void *__IOXDOMNodeRef;	/* Oxmldom::IOXDOMNodeRef */
	void *__IDOMNodeEx;	/* Xmldom::IDOMNodeEx */
	void *__IDOMNodeSelect;	/* Xmldom::IDOMNodeSelect */
	
public:
	operator IDOMNodeSelect*(void) { return (IDOMNodeSelect*)&__IDOMNodeSelect; }
	operator IDOMNodeEx*(void) { return (IDOMNodeEx*)&__IDOMNodeEx; }
	operator IDOMNode*(void) { return (IDOMNode*)&__IDOMNodeEx; }
	operator IOXDOMNodeRef*(void) { return (IOXDOMNodeRef*)&__IOXDOMNodeRef; }
	
};


class DELPHICLASS TOXDOMNodeList;
class PASCALIMPLEMENTATION TOXDOMNodeList : public TOXDOMInterface 
{
	typedef TOXDOMInterface inherited;
	
private:
	Xdom::TdomNodeList* FNodeList;
	TOXDOMNode* FOXDOMNode;
	
protected:
	HRESULT __safecall get_item(int index, Xmldom::_di_IDOMNode &get_item_result);
	HRESULT __safecall get_length(int &get_length_result);
	
public:
	__fastcall TOXDOMNodeList(Xdom::TdomNodeList* ANodeList, TOXDOMNode* OXDOMNode);
	__property Xdom::TdomNodeList* NodeList = {read=FNodeList};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOXDOMNodeList(void) { }
	#pragma option pop
	
private:
	void *__IDOMNodeList;	/* Xmldom::IDOMNodeList */
	
public:
	operator IDOMNodeList*(void) { return (IDOMNodeList*)&__IDOMNodeList; }
	
};


class DELPHICLASS TOXDOMNamedNodeMap;
class PASCALIMPLEMENTATION TOXDOMNamedNodeMap : public TOXDOMInterface 
{
	typedef TOXDOMInterface inherited;
	
private:
	Xdom::TdomNamedNodeMap* FNamedNodeMap;
	TOXDOMNode* FOXDOMNode;
	void __fastcall CheckNamespaceAware(void);
	
protected:
	HRESULT __safecall get_item(int index, Xmldom::_di_IDOMNode &get_item_result);
	int __fastcall get_length(void);
	HRESULT __safecall getNamedItem(const WideString name, Xmldom::_di_IDOMNode &getNamedItem_result);
	HRESULT __safecall setNamedItem(const Xmldom::_di_IDOMNode arg, Xmldom::_di_IDOMNode &setNamedItem_result);
	HRESULT __safecall removeNamedItem(const WideString name, Xmldom::_di_IDOMNode &removeNamedItem_result);
	HRESULT __safecall getNamedItemNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNode &getNamedItemNS_result);
	HRESULT __safecall setNamedItemNS(const Xmldom::_di_IDOMNode arg, Xmldom::_di_IDOMNode &setNamedItemNS_result);
	HRESULT __safecall removeNamedItemNS(const WideString namespaceURI, const WideString localName, Xmldom::_di_IDOMNode &removeNamedItemNS_result);
	
public:
	__fastcall TOXDOMNamedNodeMap(Xdom::TdomNamedNodeMap* ANamedNodeMap, TOXDOMNode* OXDOMNode);
	__property Xdom::TdomNamedNodeMap* NamedNodeMap = {read=FNamedNodeMap};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOXDOMNamedNodeMap(void) { }
	#pragma option pop
	
private:
	void *__IDOMNamedNodeMap;	/* Xmldom::IDOMNamedNodeMap */
	
public:
	operator IDOMNamedNodeMap*(void) { return (IDOMNamedNodeMap*)&__IDOMNamedNodeMap; }
	
};


class DELPHICLASS TOXDOMCharacterData;
class PASCALIMPLEMENTATION TOXDOMCharacterData : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomCharacterData* __fastcall GetCharacterData(void);
	
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
	__property Xdom::TdomCharacterData* CharacterData = {read=GetCharacterData};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMCharacterData(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMCharacterData(void) { }
	#pragma option pop
	
private:
	void *__IDOMCharacterData;	/* Xmldom::IDOMCharacterData */
	
public:
	operator IDOMCharacterData*(void) { return (IDOMCharacterData*)&__IDOMCharacterData; }
	
};


class DELPHICLASS TOXDOMAttr;
class PASCALIMPLEMENTATION TOXDOMAttr : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomAttr* __fastcall GetAttribute(void);
	
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
	__property Xdom::TdomAttr* Attribute = {read=GetAttribute};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMAttr(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMAttr(void) { }
	#pragma option pop
	
private:
	void *__IDOMAttr;	/* Xmldom::IDOMAttr */
	
public:
	operator IDOMAttr*(void) { return (IDOMAttr*)&__IDOMAttr; }
	
};


class DELPHICLASS TOXDOMElement;
class PASCALIMPLEMENTATION TOXDOMElement : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomElement* __fastcall GetElement(void);
	void __fastcall CheckNamespaceAware(void);
	
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
	__property Xdom::TdomElement* Element = {read=GetElement};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMElement(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMElement(void) { }
	#pragma option pop
	
private:
	void *__IDOMElement;	/* Xmldom::IDOMElement */
	
public:
	operator IDOMElement*(void) { return (IDOMElement*)&__IDOMElement; }
	
};


class DELPHICLASS TOXDOMText;
class PASCALIMPLEMENTATION TOXDOMText : public TOXDOMCharacterData 
{
	typedef TOXDOMCharacterData inherited;
	
protected:
	HRESULT __safecall splitText(int offset, Xmldom::_di_IDOMText &splitText_result);
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMText(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMCharacterData(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMText(void) { }
	#pragma option pop
	
private:
	void *__IDOMText;	/* Xmldom::IDOMText */
	
public:
	operator IDOMText*(void) { return (IDOMText*)&__IDOMText; }
	
};


class DELPHICLASS TOXDOMComment;
class PASCALIMPLEMENTATION TOXDOMComment : public TOXDOMCharacterData 
{
	typedef TOXDOMCharacterData inherited;
	
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMComment(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMCharacterData(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMComment(void) { }
	#pragma option pop
	
private:
	void *__IDOMComment;	/* Xmldom::IDOMComment */
	
public:
	operator IDOMComment*(void) { return (IDOMComment*)&__IDOMComment; }
	
};


class DELPHICLASS TOXDOMCDATASection;
class PASCALIMPLEMENTATION TOXDOMCDATASection : public TOXDOMText 
{
	typedef TOXDOMText inherited;
	
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMCDATASection(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMText(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMCDATASection(void) { }
	#pragma option pop
	
private:
	void *__IDOMCDATASection;	/* Xmldom::IDOMCDATASection */
	
public:
	operator IDOMCDATASection*(void) { return (IDOMCDATASection*)&__IDOMCDATASection; }
	
};


class DELPHICLASS TOXDOMDocumentType;
class DELPHICLASS TOXDOMDocumentTypeChildren;
class PASCALIMPLEMENTATION TOXDOMDocumentTypeChildren : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TOXDOMDocumentType* FDocumentType;
	
protected:
	HRESULT __safecall get_item(int index, Xmldom::_di_IDOMNode &get_item_result);
	HRESULT __safecall get_length(int &get_length_result);
	
public:
	__fastcall TOXDOMDocumentTypeChildren(TOXDOMDocumentType* DocumentType);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOXDOMDocumentTypeChildren(void) { }
	#pragma option pop
	
private:
	void *__IDOMNodeList;	/* Xmldom::IDOMNodeList */
	
public:
	operator IDOMNodeList*(void) { return (IDOMNodeList*)&__IDOMNodeList; }
	
};


class PASCALIMPLEMENTATION TOXDOMDocumentType : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	TOXDOMDocumentTypeChildren* FDocumentTypeChildren;
	Xmldom::_di_IDOMNamedNodeMap FEntities;
	Xmldom::_di_IDOMNamedNodeMap FNotations;
	Xdom::TdomDocumentType* __fastcall GetDocumentType(void);
	
protected:
	virtual HRESULT __safecall get_childNodes(Xmldom::_di_IDOMNodeList &get_childNodes_result);
	virtual HRESULT __safecall hasChildNodes(Word &hasChildNodes_result);
	HRESULT __safecall get_name(WideString &get_name_result);
	HRESULT __safecall get_entities(Xmldom::_di_IDOMNamedNodeMap &get_entities_result);
	HRESULT __safecall get_notations(Xmldom::_di_IDOMNamedNodeMap &get_notations_result);
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	HRESULT __safecall get_internalSubset(WideString &get_internalSubset_result);
	
public:
	__fastcall virtual TOXDOMDocumentType(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument);
	__fastcall virtual ~TOXDOMDocumentType(void);
	__property Xdom::TdomDocumentType* DocumentType = {read=GetDocumentType};
private:
	void *__IDOMDocumentType;	/* Xmldom::IDOMDocumentType */
	
public:
	operator IDOMDocumentType*(void) { return (IDOMDocumentType*)&__IDOMDocumentType; }
	
};


class DELPHICLASS TOXDOMNotation;
class PASCALIMPLEMENTATION TOXDOMNotation : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomNotation* __fastcall GetNotation(void);
	
protected:
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	
public:
	__property Xdom::TdomNotation* Notation = {read=GetNotation};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMNotation(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMNotation(void) { }
	#pragma option pop
	
private:
	void *__IDOMNotation;	/* Xmldom::IDOMNotation */
	
public:
	operator IDOMNotation*(void) { return (IDOMNotation*)&__IDOMNotation; }
	
};


class DELPHICLASS TOXDOMEntity;
class PASCALIMPLEMENTATION TOXDOMEntity : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomEntity* __fastcall GetEntity(void);
	
protected:
	HRESULT __safecall get_publicId(WideString &get_publicId_result);
	HRESULT __safecall get_systemId(WideString &get_systemId_result);
	HRESULT __safecall get_notationName(WideString &get_notationName_result);
	
public:
	__property Xdom::TdomEntity* Entity = {read=GetEntity};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMEntity(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMEntity(void) { }
	#pragma option pop
	
private:
	void *__IDOMEntity;	/* Xmldom::IDOMEntity */
	
public:
	operator IDOMEntity*(void) { return (IDOMEntity*)&__IDOMEntity; }
	
};


class DELPHICLASS TOXDOMEntityReference;
class PASCALIMPLEMENTATION TOXDOMEntityReference : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMEntityReference(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMEntityReference(void) { }
	#pragma option pop
	
private:
	void *__IDOMEntityReference;	/* Xmldom::IDOMEntityReference */
	
public:
	operator IDOMEntityReference*(void) { return (IDOMEntityReference*)&__IDOMEntityReference; }
	
};


class DELPHICLASS TOXDOMProcessingInstruction;
class PASCALIMPLEMENTATION TOXDOMProcessingInstruction : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	Xdom::TdomProcessingInstruction* __fastcall GetProcessingInstruction(void);
	
protected:
	HRESULT __safecall get_target(WideString &get_target_result);
	HRESULT __safecall get_data(WideString &get_data_result);
	void __fastcall set_data(const WideString value);
	
public:
	__property Xdom::TdomProcessingInstruction* ProcessingInstruction = {read=GetProcessingInstruction};
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMProcessingInstruction(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMProcessingInstruction(void) { }
	#pragma option pop
	
private:
	void *__IDOMProcessingInstruction;	/* Xmldom::IDOMProcessingInstruction */
	
public:
	operator IDOMProcessingInstruction*(void) { return (IDOMProcessingInstruction*)&__IDOMProcessingInstruction; }
	
};


class DELPHICLASS TOXDOMDocumentFragment;
class PASCALIMPLEMENTATION TOXDOMDocumentFragment : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
public:
	#pragma option push -w-inl
	/* TOXDOMNode.Create */ inline __fastcall virtual TOXDOMDocumentFragment(Xdom::TdomNode* ANode, TOXDOMDocument* OXDOMDocument) : TOXDOMNode(ANode, OXDOMDocument) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOXDOMNode.Destroy */ inline __fastcall virtual ~TOXDOMDocumentFragment(void) { }
	#pragma option pop
	
private:
	void *__IDOMDocumentFragment;	/* Xmldom::IDOMDocumentFragment */
	
public:
	operator IDOMDocumentFragment*(void) { return (IDOMDocumentFragment*)&__IDOMDocumentFragment; }
	
};


class PASCALIMPLEMENTATION TOXDOMDocument : public TOXDOMNode 
{
	typedef TOXDOMNode inherited;
	
private:
	TOXDOMImplementation* FDOMImpl;
	bool FDocIsOwned;
	TParseErrorInfo FParseError;
	bool FPreserveWhitespace;
	Xmldom::_di_IDOMElement FDocumentElement;
	Xdom::TdomElement* FDocElementSource;
	Xdom::TdomDocument* __fastcall GetDocument(void);
	
protected:
	HRESULT __safecall get_doctype(Xmldom::_di_IDOMDocumentType &get_doctype_result);
	HRESULT __safecall get_domImplementation(Xmldom::_di_IDOMImplementation &get_domImplementation_result);
	HRESULT __safecall get_documentElement(Xmldom::_di_IDOMElement &get_documentElement_result);
	void __fastcall set_documentElement(const Xmldom::_di_IDOMElement DOMElement);
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
	HRESULT __safecall get_Encoding(WideString &get_Encoding_result);
	HRESULT __safecall get_Standalone(WideString &get_Standalone_result);
	HRESULT __safecall get_Version(WideString &get_Version_result);
	HRESULT __safecall set_Encoding(const WideString Value);
	HRESULT __safecall set_Standalone(const WideString Value);
	HRESULT __safecall set_Version(const WideString Value);
	
public:
	__fastcall TOXDOMDocument(TOXDOMImplementation* OXDOMImpl, Xdom::TdomDocument* ADoc, bool DocIsOwned);
	__fastcall virtual ~TOXDOMDocument(void);
	__property Xdom::TdomDocument* Document = {read=GetDocument};
	__property bool PreserveWhitespace = {read=FPreserveWhitespace, nodefault};
private:
	void *__IDOMDocument;	/* Xmldom::IDOMDocument */
	void *__IDOMParseOptions;	/* Xmldom::IDOMParseOptions */
	void *__IDOMPersist;	/* Xmldom::IDOMPersist */
	void *__IDOMParseError;	/* Xmldom::IDOMParseError */
	void *__IDOMXMLProlog;	/* Xmldom::IDOMXMLProlog */
	
public:
	operator IDOMXMLProlog*(void) { return (IDOMXMLProlog*)&__IDOMXMLProlog; }
	operator IDOMParseError*(void) { return (IDOMParseError*)&__IDOMParseError; }
	operator IDOMPersist*(void) { return (IDOMPersist*)&__IDOMPersist; }
	operator IDOMParseOptions*(void) { return (IDOMParseOptions*)&__IDOMParseOptions; }
	operator IDOMDocument*(void) { return (IDOMDocument*)&__IDOMDocument; }
	
};


class DELPHICLASS TOXDOMImplementationFactory;
class PASCALIMPLEMENTATION TOXDOMImplementationFactory : public Xmldom::TDOMVendor 
{
	typedef Xmldom::TDOMVendor inherited;
	
private:
	Xmldom::_di_IDOMImplementation FGlobalDOMImpl;
	
public:
	virtual Xmldom::_di_IDOMImplementation __fastcall DOMImplementation();
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TOXDOMImplementationFactory(void) : Xmldom::TDOMVendor() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOXDOMImplementationFactory(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define SOpenXML "Open XML"
extern PACKAGE TOXDOMImplementationFactory* OpenXMLFactory;

}	/* namespace Oxmldom */
using namespace Oxmldom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// oxmldom
