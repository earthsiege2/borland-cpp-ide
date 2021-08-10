// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLDoc.pas' rev: 6.00

#ifndef XMLDocHPP
#define XMLDocHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLIntf.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Xmldoc {
using Xmlintf::IXMLDocument;
struct TNodeClassInfo;
__interface IXMLDocumentAccess;
__interface IXMLNodeAccess;
};
using Xmldoc::TNodeClassInfo;

namespace Xmldoc
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TNodeListOperation { nlInsert, nlRemove, nlCreateNode };
#pragma option pop

typedef void __fastcall (__closure *TNodeListNotification)(TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);

class DELPHICLASS TXMLNodeList;
class DELPHICLASS TXMLNode;
typedef DynamicArray<TNodeClassInfo >  TNodeClassArray;

class DELPHICLASS TXMLNodeCollection;
class DELPHICLASS TXMLDocument;
#pragma option push -b-
enum TXMLDocumentSource { xdsNone, xdsXMLProperty, xdsXMLData, xdsFile, xdsStream };
#pragma option pop

#pragma option push -b-
enum TNodeChange { ncUpdateValue, ncInsertChild, ncRemoveChild, ncAddAttribute, ncRemoveAttribute };
#pragma option pop

typedef void __fastcall (__closure *TNodeChangeEvent)(const Xmlintf::_di_IXMLNode Node, TNodeChange ChangeType);

#pragma option push -b-
enum TXMLPrologItem { xpVersion, xpEncoding, xpStandalone };
#pragma option pop

typedef TMetaClass*TXMLNodeClass;

class PASCALIMPLEMENTATION TXMLDocument : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	WideString FXMLData;
	Classes::TStream* FSrcStream;
	Classes::TStringList* FXMLStrings;
	Xmldom::TDOMVendor* FDOMVendor;
	int FRefCount;
	DynamicArray<TNodeClassInfo >  FDocBindingInfo;
	Xmldom::_di_IDOMPersist FDOMPersist;
	Xmldom::_di_IDOMDocument FDOMDocument;
	Xmldom::_di_IDOMImplementation FDOMImplementation;
	Xmldom::_di_IDOMParseOptions FDOMParseOptions;
	Xmlintf::TParseOptions FParseOptions;
	Xmlintf::_di_IXMLNode FDocumentNode;
	WideString FFileName;
	Xmlintf::TXMLDocOptions FOptions;
	int FPrefixID;
	WideString FNSPrefixBase;
	WideString FNodeIndentStr;
	bool FStreamedActive;
	int FModified;
	int FXMLStrRead;
	TXMLDocumentSource FDocSource;
	Classes::TNotifyEvent FAfterClose;
	Classes::TNotifyEvent FBeforeOpen;
	Classes::TNotifyEvent FBeforeClose;
	Classes::TNotifyEvent FAfterOpen;
	bool FOwnerIsComponent;
	TNodeChangeEvent FBeforeNodeChange;
	TNodeChangeEvent FAfterNodeChange;
	Xmldom::TAsyncEventHandler FOnAsyncLoad;
	Xmldom::_di_IDOMParseOptions __fastcall GetDOMParseOptions();
	bool __fastcall IsXMLStored(void);
	bool __fastcall NodeIndentStored(void);
	void __fastcall SetDOMImplementation(const Xmldom::_di_IDOMImplementation Value);
	void __fastcall SetDOMVendor(const Xmldom::TDOMVendor* Value);
	
protected:
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	virtual bool __fastcall GetActive(void);
	int __fastcall GetAsyncLoadState(void);
	Xmlintf::_di_IXMLNodeList __fastcall GetChildNodes();
	Xmlintf::_di_IXMLNode __fastcall GetDocumentElement();
	WideString __fastcall GetEncoding();
	Xmldom::_di_IDOMDocument __fastcall GetDOMDocument();
	Xmlintf::_di_IXMLNode __fastcall GetDocumentNode();
	WideString __fastcall GetFileName();
	bool __fastcall GetModified(void);
	WideString __fastcall GetNodeIndentStr();
	Xmlintf::TXMLDocOptions __fastcall GetOptions(void);
	Xmlintf::TParseOptions __fastcall GetParseOptions(void);
	WideString __fastcall GetSchemaRef();
	WideString __fastcall GetStandAlone();
	WideString __fastcall GetVersion();
	Classes::TStrings* __fastcall GetXML(void);
	virtual void __fastcall SetActive(const bool Value);
	void __fastcall SetDocumentElement(const Xmlintf::_di_IXMLNode Value);
	void __fastcall SetDOMDocument(const Xmldom::_di_IDOMDocument Value);
	void __fastcall SetEncoding(const WideString Value);
	void __fastcall SetNodeIndentStr(const WideString Value);
	void __fastcall SetOnAsyncLoad(const Xmldom::TAsyncEventHandler Value);
	void __fastcall SetOptions(const Xmlintf::TXMLDocOptions Value);
	void __fastcall SetParseOptions(const Xmlintf::TParseOptions Value);
	void __fastcall SetStandAlone(const WideString Value);
	void __fastcall SetVersion(const WideString Value);
	void __fastcall SetXML(const Classes::TStrings* Value);
	TXMLDocument* __fastcall GetDocumentObject(void);
	Xmldom::_di_IDOMPersist __fastcall GetDOMPersist();
	void __fastcall AssignParseOptions(void);
	void __fastcall CheckActive(void);
	DYNAMIC void __fastcall CheckAutoSave(void);
	DYNAMIC void __fastcall CheckDOM(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoAfterClose(void);
	DYNAMIC void __fastcall DoAfterOpen(void);
	DYNAMIC void __fastcall DoBeforeClose(void);
	DYNAMIC void __fastcall DoBeforeOpen(void);
	void __fastcall DoNodeChange(const Xmlintf::_di_IXMLNode Node, TNodeChange ChangeType, bool BeforeOperation);
	Xmlintf::_di_IXMLNode __fastcall GetPrologNode();
	WideString __fastcall GetPrologValue(TXMLPrologItem PrologItem, const WideString Default = L"");
	virtual TMetaClass* __fastcall GetChildNodeClass(const Xmldom::_di_IDOMNode Node);
	AnsiString __fastcall InternalSetPrologValue(const Xmlintf::_di_IXMLNode PrologNode, const Variant &Value, TXMLPrologItem PrologItem);
	DYNAMIC void __fastcall LoadData(void);
	virtual void __fastcall Loaded(void);
	void __fastcall ReadDOMVendor(Classes::TReader* Reader);
	DYNAMIC void __fastcall ReleaseDoc(const bool CheckSave = true);
	void __fastcall SaveToXMLStrings(void);
	void __fastcall SaveToUTF8String(AnsiString &XML);
	void __fastcall SetFileName(const WideString Value);
	void __fastcall SetModified(const bool Value);
	void __fastcall SetPrologValue(const Variant &Value, TXMLPrologItem PrologItem);
	void __fastcall SetXMLStrings(const AnsiString Value);
	void __fastcall WriteDOMVendor(Classes::TWriter* Writer);
	void __fastcall XMLStringsChanging(System::TObject* Sender);
	__property TNodeClassArray DocBindingInfo = {read=FDocBindingInfo};
	__property TXMLDocumentSource DocSource = {read=FDocSource, write=FDocSource, nodefault};
	__property Xmldom::_di_IDOMParseOptions DOMParseOptions = {read=GetDOMParseOptions};
	__property Xmldom::_di_IDOMPersist DOMPersist = {read=GetDOMPersist};
	__property int PrefixID = {read=FPrefixID, write=FPrefixID, nodefault};
	
public:
	__fastcall TXMLDocument(const WideString AFileName)/* overload */;
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	virtual void __fastcall AfterConstruction(void);
	__fastcall virtual ~TXMLDocument(void);
	Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall CreateElement(const WideString TagOrData, const WideString NamespaceURI);
	Xmlintf::_di_IXMLNode __fastcall CreateNode(const WideString NameOrData, Xmlintf::TNodeType NodeType = (Xmlintf::TNodeType)(0x1), const WideString AddlData = L"");
	Xmlintf::_di_IXMLNode __fastcall GetDocBinding(const WideString TagName, TMetaClass* DocNodeClass, WideString NamespaceURI = L"");
	bool __fastcall IsEmptyDoc(void);
	void __fastcall LoadFromFile(const WideString AFileName = L"");
	void __fastcall LoadFromStream(const Classes::TStream* Stream, Xmlintf::TXMLEncodingType EncodingType = (Xmlintf::TXMLEncodingType)(0x0));
	void __fastcall LoadFromXML(const AnsiString XML)/* overload */;
	void __fastcall LoadFromXML(const WideString XML)/* overload */;
	void __fastcall Refresh(void);
	void __fastcall RegisterDocBinding(const WideString TagName, TMetaClass* DocNodeClass, WideString NamespaceURI = L"");
	void __fastcall Resync(void);
	DYNAMIC void __fastcall SaveToFile(const WideString AFileName = L"");
	void __fastcall SaveToStream(const Classes::TStream* Stream);
	void __fastcall SaveToXML(WideString &XML)/* overload */;
	void __fastcall SaveToXML(AnsiString &XML)/* overload */;
	__property int AsyncLoadState = {read=GetAsyncLoadState, nodefault};
	__property Xmlintf::_di_IXMLNodeList ChildNodes = {read=GetChildNodes};
	__property Xmldom::_di_IDOMDocument DOMDocument = {read=GetDOMDocument, write=SetDOMDocument};
	__property Xmldom::_di_IDOMImplementation DOMImplementation = {read=FDOMImplementation, write=SetDOMImplementation};
	__property Xmlintf::_di_IXMLNode DocumentElement = {read=GetDocumentElement, write=SetDocumentElement};
	__property WideString Encoding = {read=GetEncoding, write=SetEncoding};
	WideString __fastcall GeneratePrefix(const Xmlintf::_di_IXMLNode Node);
	__property bool Modified = {read=GetModified, nodefault};
	__property Xmlintf::_di_IXMLNode Node = {read=GetDocumentNode};
	__property WideString NSPrefixBase = {read=FNSPrefixBase, write=FNSPrefixBase};
	__property WideString SchemaRef = {read=GetSchemaRef};
	__property WideString StandAlone = {read=GetStandAlone, write=SetStandAlone};
	__property WideString Version = {read=GetVersion, write=SetVersion};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property WideString FileName = {read=GetFileName, write=SetFileName};
	__property Xmldom::TDOMVendor* DOMVendor = {read=FDOMVendor, write=SetDOMVendor};
	__property WideString NodeIndentStr = {read=GetNodeIndentStr, write=SetNodeIndentStr, stored=NodeIndentStored};
	__property Xmlintf::TXMLDocOptions Options = {read=GetOptions, write=SetOptions, default=29};
	__property Xmlintf::TParseOptions ParseOptions = {read=GetParseOptions, write=SetParseOptions, default=0};
	__property Classes::TStrings* XML = {read=GetXML, write=SetXML, stored=IsXMLStored};
	__property Classes::TNotifyEvent BeforeOpen = {read=FBeforeOpen, write=FBeforeOpen};
	__property Classes::TNotifyEvent AfterOpen = {read=FAfterOpen, write=FAfterOpen};
	__property Classes::TNotifyEvent BeforeClose = {read=FBeforeClose, write=FBeforeClose};
	__property Classes::TNotifyEvent AfterClose = {read=FAfterClose, write=FAfterClose};
	__property TNodeChangeEvent BeforeNodeChange = {read=FBeforeNodeChange, write=FBeforeNodeChange};
	__property TNodeChangeEvent AfterNodeChange = {read=FAfterNodeChange, write=FAfterNodeChange};
	__property Xmldom::TAsyncEventHandler OnAsyncLoad = {read=FOnAsyncLoad, write=SetOnAsyncLoad};
private:
	void *__IXMLDocument;	/* Xmlintf::IXMLDocument */
	void *__IXMLDocumentAccess;	/* Xmldoc::IXMLDocumentAccess */
	
public:
	operator IXMLDocumentAccess*(void) { return (IXMLDocumentAccess*)&__IXMLDocumentAccess; }
	operator IXMLDocument*(void) { return (IXMLDocument*)&__IXMLDocument; }
	operator IInterface*(void) { return (IInterface*)&__IXMLDocumentAccess; }
	
};


typedef TMetaClass*TXMLNodeCollectionClass;

class PASCALIMPLEMENTATION TXMLNode : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Xmlintf::_di_IXMLNodeList FAttributeNodes;
	Xmlintf::_di_IXMLNodeList FChildNodes;
	DynamicArray<TNodeClassInfo >  FChildNodeClasses;
	TXMLNodeCollection* FCollection;
	TXMLDocument* FDocument;
	Xmldom::_di_IDOMNode FDOMNode;
	TXMLNode* FHostNode;
	TXMLNode* FParentNode;
	Classes::TList* FHostedNodes;
	bool FIsDocElement;
	bool FReadOnly;
	TNodeListNotification FOnHostChildNotify;
	TNodeListNotification FOnHostAttrNotify;
	
protected:
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	OleVariant __fastcall GetAttribute(const WideString AttrName);
	Xmlintf::_di_IXMLNodeList __fastcall GetAttributeNodes();
	OleVariant __fastcall GetAttributeNS(const WideString AttrName, const WideString NamespaceURI);
	Xmlintf::_di_IXMLNodeList __fastcall GetChildNodes();
	OleVariant __fastcall GetChildValue(const OleVariant &IndexOrName);
	Xmlintf::_di_IXMLNodeCollection __fastcall GetCollection();
	Xmldom::_di_IDOMNode __fastcall GetDOMNode();
	bool __fastcall GetHasChildNodes(void);
	bool __fastcall GetIsTextElement(void);
	WideString __fastcall GetLocalName();
	WideString __fastcall GetNamespaceURI();
	WideString __fastcall GetNodeName();
	Xmlintf::TNodeType __fastcall GetNodeType(void);
	OleVariant __fastcall GetNodeValue();
	Xmlintf::_di_IXMLDocument __fastcall GetOwnerDocument();
	Xmlintf::_di_IXMLNode __fastcall GetParentNode();
	WideString __fastcall GetPrefix();
	bool __fastcall GetReadOnly(void);
	WideString __fastcall GetText();
	WideString __fastcall GetXML();
	void __fastcall SetAttribute(const WideString AttrName, const OleVariant &Value);
	void __fastcall SetChildValue(const OleVariant &IndexOrName, const OleVariant &Value);
	void __fastcall SetNodeValue(const OleVariant &Value);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetText(const WideString Value);
	Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName, int Index = 0xffffffff)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI, bool GenPrefix = false, int Index = 0xffffffff)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall CloneNode(bool Deep);
	void __fastcall DeclareNamespace(const WideString Prefix, const WideString URI);
	Xmlintf::_di_IXMLNode __fastcall FindNamespaceDecl(const WideString NamespaceURI);
	WideString __fastcall FindNamespaceURI(const WideString TagOrPrefix);
	bool __fastcall HasAttribute(const WideString Name)/* overload */;
	bool __fastcall HasAttribute(const WideString Name, const WideString NamespaceURI)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall NextSibling();
	void __fastcall Normalize(void);
	Xmlintf::_di_IXMLNode __fastcall PreviousSibling();
	void __fastcall Resync(void);
	void __fastcall SetAttributeNS(const WideString AttrName, const WideString NamespaceURI, const OleVariant &Value);
	void __fastcall TransformNode(const Xmlintf::_di_IXMLNode stylesheet, WideString &output)/* overload */;
	void __fastcall TransformNode(const Xmlintf::_di_IXMLNode stylesheet, const Xmlintf::_di_IXMLDocument output)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI, TMetaClass* NodeClass, int Index = 0xffffffff)/* overload */;
	void __fastcall CheckTextNode(void);
	void __fastcall ClearDocumentRef(void);
	virtual Xmlintf::_di_IXMLNode __fastcall CreateAttributeNode(const Xmldom::_di_IDOMNode ADOMNode);
	virtual Xmlintf::_di_IXMLNode __fastcall CreateChildNode(const Xmldom::_di_IDOMNode ADOMNode);
	TXMLNodeCollection* __fastcall CreateCollection(const TMetaClass* CollectionClass, const GUID &ItemInterface, const WideString ItemTag, WideString ItemNS = L"");
	Xmldom::_di_IDOMElement __fastcall DOMElement();
	Xmlintf::_di_IXMLNode __fastcall FindHostedNode(const TMetaClass* NodeClass);
	TNodeClassArray __fastcall GetChildNodeClasses();
	Classes::TList* __fastcall GetHostedNodes(void);
	TXMLNode* __fastcall GetHostNode(void);
	TXMLNode* __fastcall GetNodeObject(void);
	bool __fastcall HasChildNode(const WideString ChildTag)/* overload */;
	bool __fastcall HasChildNode(const WideString ChildTag, const WideString NamespaceURI)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall InternalAddChild(TMetaClass* NodeClass, const WideString NodeName, const WideString NamespaceURI, int Index);
	int __fastcall NestingLevel(void);
	void __fastcall RegisterChildNode(const WideString TagName, TMetaClass* ChildNodeClass, WideString NamespaceURI = L"");
	void __fastcall RegisterChildNodes(const WideString * TagNames, const int TagNames_Size, TMetaClass* * NodeClasses, const int NodeClasses_Size);
	void __fastcall SetCollection(const TXMLNodeCollection* Value);
	virtual void __fastcall SetParentNode(const TXMLNode* Value);
	__property TNodeListNotification OnHostChildNotify = {read=FOnHostChildNotify, write=FOnHostChildNotify};
	__property TNodeListNotification OnHostAttrNotify = {read=FOnHostAttrNotify, write=FOnHostAttrNotify};
	void __fastcall AttributeListNotify(TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	void __fastcall CheckReadOnly(void);
	virtual void __fastcall ChildListNotify(TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	void __fastcall CheckNotHosted(void);
	DYNAMIC Xmlintf::_di_IXMLNodeList __fastcall CreateAttributeList();
	DYNAMIC Xmlintf::_di_IXMLNodeList __fastcall CreateChildList();
	virtual void __fastcall DoNodeChange(TNodeChange ChangeType, bool BeforeOperation);
	WideString __fastcall GetPrefixedName(const WideString Name, const WideString NamespaceURI);
	virtual void __fastcall SetAttributeNodes(const Xmlintf::_di_IXMLNodeList Value);
	virtual void __fastcall SetChildNodes(const Xmlintf::_di_IXMLNodeList Value);
	__property Xmlintf::_di_IXMLNodeList AttributeNodes = {read=GetAttributeNodes};
	__property Xmlintf::_di_IXMLNodeList ChildNodes = {read=GetChildNodes, write=SetChildNodes};
	__property TNodeClassArray ChildNodeClasses = {read=GetChildNodeClasses};
	__property TXMLNodeCollection* Collection = {read=FCollection, write=FCollection};
	__property Xmldom::_di_IDOMNode DOMNode = {read=FDOMNode};
	__property Classes::TList* HostedNodes = {read=GetHostedNodes};
	__property TXMLNode* HostNode = {read=FHostNode, write=FHostNode};
	__property TXMLDocument* OwnerDocument = {read=FDocument};
	__property TXMLNode* ParentNode = {read=FParentNode};
	
public:
	__fastcall TXMLNode(const Xmldom::_di_IDOMNode ADOMNode, const TXMLNode* AParentNode, const TXMLDocument* OwnerDoc);
	__fastcall TXMLNode(TXMLNode* HostNode);
	__fastcall virtual ~TXMLNode(void);
private:
	void *__IXMLNodeAccess;	/* Xmldoc::IXMLNodeAccess */
	
public:
	operator IXMLNodeAccess*(void) { return (IXMLNodeAccess*)&__IXMLNodeAccess; }
	operator IXMLNode*(void) { return (IXMLNode*)&__IXMLNodeAccess; }
	
};


class PASCALIMPLEMENTATION TXMLNodeCollection : public TXMLNode 
{
	typedef TXMLNode inherited;
	
private:
	#pragma pack(push, 1)
	GUID FItemInterface;
	#pragma pack(pop)
	
	WideString FItemNS;
	WideString FItemTag;
	Xmlintf::_di_IXMLNodeList FList;
	
protected:
	void __fastcall Clear(void);
	int __fastcall GetCount(void);
	virtual Xmlintf::_di_IXMLNodeList __fastcall GetList();
	Xmlintf::_di_IXMLNode __fastcall GetNode(int Index);
	void __fastcall Delete(int Index);
	int __fastcall Remove(const Xmlintf::_di_IXMLNode AItem);
	virtual void __fastcall ChildListNotify(TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	void __fastcall UpdateCollectionList(TNodeListOperation Operation, Xmlintf::_di_IXMLNode &Node, const OleVariant &IndexOrName, bool BeforeOperation);
	__property int Count = {read=GetCount, nodefault};
	virtual Xmlintf::_di_IXMLNode __fastcall AddItem(int Index);
	void __fastcall CreateItemList(bool CheckFirst = false);
	void __fastcall InsertInCollection(Xmlintf::_di_IXMLNode Node, int Index);
	bool __fastcall IsCollectionItem(const Xmlintf::_di_IXMLNode Node);
	virtual void __fastcall SetChildNodes(const Xmlintf::_di_IXMLNodeList Value);
	__property GUID ItemInterface = {read=FItemInterface, write=FItemInterface};
	__property WideString ItemNS = {read=FItemNS, write=FItemNS};
	__property WideString ItemTag = {read=FItemTag, write=FItemTag};
	__property Xmlintf::_di_IXMLNodeList List = {read=GetList};
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TXMLNode.Create */ inline __fastcall TXMLNodeCollection(const Xmldom::_di_IDOMNode ADOMNode, const TXMLNode* AParentNode, const TXMLDocument* OwnerDoc) : TXMLNode(ADOMNode, AParentNode, OwnerDoc) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.CreateHosted */ inline __fastcall TXMLNodeCollection(TXMLNode* HostNode) : TXMLNode(HostNode) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLNode.Destroy */ inline __fastcall virtual ~TXMLNodeCollection(void) { }
	#pragma option pop
	
private:
	void *__IXMLNodeCollection;	/* Xmlintf::IXMLNodeCollection */
	
public:
	operator IXMLNodeCollection*(void) { return (IXMLNodeCollection*)&__IXMLNodeCollection; }
	
};



class PASCALIMPLEMENTATION TXMLNodeList : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::_di_IInterfaceList FList;
	TNodeListNotification FNotificationProc;
	TXMLNode* FOwner;
	int FUpdateCount;
	WideString FDefaultNamespaceURI;
	
protected:
	int __fastcall Add(const Xmlintf::_di_IXMLNode Node);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	int __fastcall Delete(const int Index)/* overload */;
	int __fastcall Delete(const WideString Name)/* overload */;
	int __fastcall Delete(const WideString Name, const WideString NamespaceURI)/* overload */;
	void __fastcall EndUpdate(void);
	Xmlintf::_di_IXMLNode __fastcall First();
	Xmlintf::_di_IXMLNode __fastcall FindNode(WideString NodeName)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall FindNode(WideString NodeName, WideString NamespaceURI)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall FindNode(const GUID &ChildNodeType)/* overload */;
	Xmlintf::_di_IXMLNode __fastcall FindSibling(const Xmlintf::_di_IXMLNode Node, int Delta);
	Xmlintf::_di_IXMLNode __fastcall Get(int Index);
	int __fastcall GetCount(void);
	Xmlintf::_di_IXMLNode __fastcall GetNode(const OleVariant &IndexOrName);
	int __fastcall GetUpdateCount(void);
	int __fastcall IndexOf(const Xmlintf::_di_IXMLNode Node)/* overload */;
	int __fastcall IndexOf(const WideString Name)/* overload */;
	int __fastcall IndexOf(const WideString Name, const WideString NamespaceURI)/* overload */;
	void __fastcall Insert(int Index, const Xmlintf::_di_IXMLNode Node);
	Xmlintf::_di_IXMLNode __fastcall Last();
	int __fastcall Remove(const Xmlintf::_di_IXMLNode Node);
	Xmlintf::_di_IXMLNode __fastcall ReplaceNode(const Xmlintf::_di_IXMLNode OldNode, const Xmlintf::_di_IXMLNode NewNode);
	__property int Count = {read=GetCount, nodefault};
	__property int UpdateCount = {read=GetUpdateCount, nodefault};
	Xmlintf::_di_IXMLNode __fastcall DoNotify(TNodeListOperation Operation, const Xmlintf::_di_IXMLNode Node, const OleVariant &IndexOrName, bool BeforeOperation);
	__property WideString DefaultNamespaceURI = {read=FDefaultNamespaceURI};
	int __fastcall InternalInsert(int Index, const Xmlintf::_di_IXMLNode Node);
	__property Classes::_di_IInterfaceList List = {read=FList};
	__property TNodeListNotification NotificationProc = {read=FNotificationProc};
	__property TXMLNode* Owner = {read=FOwner};
	
public:
	__fastcall TXMLNodeList(TXMLNode* Owner, const WideString DefaultNamespaceURI, TNodeListNotification NotificationProc);
	__fastcall virtual ~TXMLNodeList(void);
private:
	void *__IXMLNodeList;	/* Xmlintf::IXMLNodeList */
	
public:
	operator IXMLNodeList*(void) { return (IXMLNodeList*)&__IXMLNodeList; }
	
};


#pragma pack(push, 4)
struct TNodeClassInfo
{
	WideString NodeName;
	WideString NamespaceURI;
	TMetaClass*NodeClass;
} ;
#pragma pack(pop)

__interface IXMLNodeAccess;
typedef System::DelphiInterface<IXMLNodeAccess> _di_IXMLNodeAccess;
__interface INTERFACE_UUID("{6C819037-AB66-4AA8-B2A5-958EDA8627B7}") IXMLNodeAccess  : public IXMLNode 
{
	
public:
	HIDESBASE virtual Xmlintf::_di_IXMLNode __fastcall AddChild(const WideString TagName, const WideString NamespaceURI, TMetaClass* NodeClass, int Index = 0xffffffff) = 0 /* overload */;
	virtual void __fastcall CheckTextNode(void) = 0 ;
	virtual void __fastcall ClearDocumentRef(void) = 0 ;
	virtual Xmlintf::_di_IXMLNode __fastcall CreateAttributeNode(const Xmldom::_di_IDOMNode ADOMNode) = 0 ;
	virtual Xmlintf::_di_IXMLNode __fastcall CreateChildNode(const Xmldom::_di_IDOMNode ADOMNode) = 0 ;
	virtual TXMLNodeCollection* __fastcall CreateCollection(const TMetaClass* CollectionClass, const GUID &ItemIterface, const WideString ItemTag, WideString ItemNS = L"") = 0 ;
	virtual Xmldom::_di_IDOMElement __fastcall DOMElement(void) = 0 ;
	virtual Xmlintf::_di_IXMLNode __fastcall FindHostedNode(const TMetaClass* NodeClass) = 0 ;
	virtual TNodeClassArray __fastcall GetChildNodeClasses(void) = 0 ;
	virtual TXMLNode* __fastcall GetHostNode(void) = 0 ;
	virtual TXMLNode* __fastcall GetNodeObject(void) = 0 ;
	virtual bool __fastcall HasChildNode(const WideString ChildTag) = 0 /* overload */;
	virtual bool __fastcall HasChildNode(const WideString ChildTag, const WideString NamespaceURI) = 0 /* overload */;
	virtual Xmlintf::_di_IXMLNode __fastcall InternalAddChild(TMetaClass* NodeClass, const WideString NodeName, const WideString NamespaceURI, int Index) = 0 ;
	virtual int __fastcall NestingLevel(void) = 0 ;
	virtual void __fastcall RegisterChildNode(const WideString TagName, TMetaClass* ChildNodeClass, WideString NamespaceURI = L"") = 0 ;
	virtual void __fastcall RegisterChildNodes(const WideString * TagNames, const int TagNames_Size, TMetaClass* * NodeClasses, const int NodeClasses_Size) = 0 ;
	virtual void __fastcall SetCollection(const TXMLNodeCollection* Value) = 0 ;
	virtual void __fastcall SetParentNode(const TXMLNode* Value) = 0 ;
	__property TNodeClassArray ChildNodeClasses = {read=GetChildNodeClasses};
	__property TXMLNode* HostNode = {read=GetHostNode};
};

__interface IXMLDocumentAccess;
typedef System::DelphiInterface<IXMLDocumentAccess> _di_IXMLDocumentAccess;
__interface INTERFACE_UUID("{933FDA52-B0D0-440C-B3E9-C37FFB4B906B}") IXMLDocumentAccess  : public IInterface 
{
	
public:
	virtual TXMLDocument* __fastcall GetDocumentObject(void) = 0 ;
	virtual Xmldom::_di_IDOMPersist __fastcall GetDOMPersist(void) = 0 ;
	__property TXMLDocument* DocumentObject = {read=GetDocumentObject};
	__property Xmldom::_di_IDOMPersist DOMPersist = {read=GetDOMPersist};
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall XMLDocError(const AnsiString Msg)/* overload */;
extern PACKAGE void __fastcall XMLDocError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size)/* overload */;
extern PACKAGE Xmldom::_di_IDOMNode __fastcall CreateDOMNode(Xmldom::_di_IDOMDocument Doc, const WideString NameOrData, Xmlintf::TNodeType NodeType = (Xmlintf::TNodeType)(0x1), const WideString AddlData = L"");
extern PACKAGE WideString __fastcall FormatXMLData(const WideString XMLData);
extern PACKAGE Xmlintf::_di_IXMLDocument __fastcall LoadXMLDocument(const WideString FileName);
extern PACKAGE Xmlintf::_di_IXMLDocument __fastcall LoadXMLData(const WideString XMLData)/* overload */;
extern PACKAGE Xmlintf::_di_IXMLDocument __fastcall LoadXMLData(const AnsiString XMLData)/* overload */;
extern PACKAGE Xmlintf::_di_IXMLDocument __fastcall NewXMLDocument(WideString Version = L"1.0");
extern PACKAGE Xmlintf::TXMLEncodingType __fastcall DetectCharEncoding(Classes::TStream* S);
extern PACKAGE void __fastcall CheckEncoding(WideString &XMLData, const AnsiString * ValidEncodings, const int ValidEncodings_Size);
extern PACKAGE WideString __fastcall XMLStringToWideString(const AnsiString XMLString);

}	/* namespace Xmldoc */
using namespace Xmldoc;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLDoc
