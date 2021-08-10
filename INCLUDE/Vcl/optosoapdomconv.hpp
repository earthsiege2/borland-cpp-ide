// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OPToSOAPDomConv.pas' rev: 6.00

#ifndef OPToSOAPDomConvHPP
#define OPToSOAPDomConvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <SOAPDomConv.hpp>	// Pascal unit
#include <SOAPEnv.hpp>	// Pascal unit
#include <WSDLNode.hpp>	// Pascal unit
#include <OPConvert.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Optosoapdomconv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ESOAPDomConvertError;
class PASCALIMPLEMENTATION ESOAPDomConvertError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESOAPDomConvertError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESOAPDomConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESOAPDomConvertError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESOAPDomConvertError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESOAPDomConvertError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESOAPDomConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESOAPDomConvertError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESOAPDomConvertError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESOAPDomConvertError(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TSOAPArrayElemDesc
{
	bool MultiDim;
	DynamicArray<int >  Dims;
} ;
#pragma pack(pop)

typedef DynamicArray<TSOAPArrayElemDesc >  TSOAPArrayDesc;

#pragma pack(push, 4)
struct TMultiRefNodeMapElem
{
	void *Instance;
	AnsiString ID;
} ;
#pragma pack(pop)

typedef DynamicArray<TMultiRefNodeMapElem >  TMultiRefNodeMap;

typedef DynamicArray<Xmlintf::_di_IXMLNode >  TXMLNodeArray;

#pragma pack(push, 4)
struct TMultiRefNodeElem
{
	Xmlintf::_di_IXMLNode Node;
	DynamicArray<Xmlintf::_di_IXMLNode >  MultiRefChildren;
} ;
#pragma pack(pop)

typedef DynamicArray<TMultiRefNodeElem >  TMultiRefNodes;

#pragma option push -b-
enum ConvNodeState { nsClientSend, nsServerReceive, nsServerSend, nsClientReceive };
#pragma option pop

typedef DynamicArray<System::TObject* >  OPToSOAPDomConv__3;

class DELPHICLASS TSOAPDomConv;
class PASCALIMPLEMENTATION TSOAPDomConv : public Soapdomconv::TSOAPDOMProcessor 
{
	typedef Soapdomconv::TSOAPDOMProcessor inherited;
	
private:
	int FIDs;
	DynamicArray<TMultiRefNodeMapElem >  RefMap;
	DynamicArray<TMultiRefNodeElem >  MultiRefNodes;
	Opconvert::TSOAPConvertOptions FOptions;
	DynamicArray<System::TObject* >  ObjsWriting;
	
protected:
	bool __fastcall NodeIsNULL(Xmlintf::_di_IXMLNode Node);
	bool __fastcall ChildNodesAreNull(Xmlintf::_di_IXMLNode Node);
	Xmlintf::_di_IXMLNode __fastcall CreateNULLNode(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode ParentNode, WideString Name, bool UseParentNode = false);
	AnsiString __fastcall GetNewID();
	WideString __fastcall FindPrefixForURI(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString URI, bool DeclIfNone = false);
	WideString __fastcall AddNamespaceDecl(Xmlintf::_di_IXMLNode Node, WideString URI);
	void __fastcall SetAttributeNS(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Attr, WideString NS, WideString Value);
	bool __fastcall GetElementType(Xmlintf::_di_IXMLNode Node, WideString &TypeURI, WideString &TypeName);
	Xmlintf::_di_IXMLNode __fastcall CreateScalarNodeXS(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode ParentNode, WideString NodeName, WideString URI, WideString TypeName, WideString Value, bool GenPre = false);
	Variant __fastcall GetTypeBySchemaNS(Xmlintf::_di_IXMLNode Node, WideString URI);
	Xmlintf::_di_IXMLNode __fastcall CreateTypedNode(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode ParentNode, WideString NodeName, WideString URI, WideString TypeName, bool GenPre = false);
	void __fastcall SetNodeType(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode InstNode, const WideString ElemURI, const WideString TypeName);
	WideString __fastcall GetNodeAsText(Xmlintf::_di_IXMLNode Node);
	Xmlintf::_di_IXMLNode __fastcall GetDataNode(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString &ID);
	void __fastcall CheckEncodingStyle(Xmlintf::_di_IXMLNode Node);
	void __fastcall AddMultiRefNode(AnsiString ID, void * Instance);
	AnsiString __fastcall FindMultiRefNodeByInstance(void * Instance);
	void * __fastcall FindMultiRefNodeByID(AnsiString ID);
	Xmlintf::_di_IXMLNode __fastcall CreateMultiRefNode(Xmlintf::_di_IXMLNode RootNode, WideString Name, WideString ID);
	void __fastcall FinalizeMultiRefNodes(void);
	Xmlintf::_di_IXMLNode __fastcall FindNodeByHREF(Xmlintf::_di_IXMLNode RootNode, WideString HREF);
	void __fastcall AddObjectAsWriting(System::TObject* Instance);
	void __fastcall RemoveObjectAsWriting(System::TObject* Instance);
	bool __fastcall IsObjectWriting(System::TObject* Instance);
	void __fastcall ResetMultiRef(void);
	void __fastcall ConvertVariantToSoap(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, Typinfo::PTypeInfo Info, PVarData P, int NumIndirect, const Variant &V, bool UseVariant);
	void __fastcall ConvertSoapToVariant(Xmlintf::_di_IXMLNode Node, void * InvData);
	bool __fastcall IsNodeAVarArray(const Xmlintf::_di_IXMLNode Node, Word &VT);
	void __fastcall WriteVarArray(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, const Variant &V);
	void __fastcall WriteVariant(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, const Variant &V);
	void __fastcall ReadVariant(Xmlintf::_di_IXMLNode Node, void * P);
	Variant __fastcall ReadVarArrayDim(Xmlintf::_di_IXMLNode Node, bool IsVarVArray = false, Word VT = (Word)(0x0));
	void __fastcall WriteVarArrayAsB64(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, const Variant &V);
	Xmlintf::_di_IXMLNode __fastcall MakeArrayNode(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, WideString URI, WideString TypeName, const int * Indices, const int Indices_Size);
	void __fastcall ConvertNativeArrayToSoap(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, Typinfo::PTypeInfo Info, void * P, int NumIndirect, bool InlineElements = false);
	void __fastcall WriteNonRectDynArray(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, Typinfo::PTypeInfo Info, WideString URI, WideString TypeName, void * P, int Dims);
	int __fastcall WriteNonRectDynArrayElem(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, Typinfo::PTypeInfo Info, WideString URI, WideString TypeName, void * P, int Dim);
	void * __fastcall ConvertSoapToNativeArray(void * DataP, Typinfo::PTypeInfo TypeInfo, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node);
	void * __fastcall ConvertSoapToNativeArrayElem(Typinfo::PTypeInfo ArrayInfo, Typinfo::PTypeInfo ElemInfo, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, TSOAPArrayDesc ArrayDesc, int Dims, int CurDim, void * DataP);
	void __fastcall WriteRectDynArrayElem(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, Typinfo::PTypeInfo Info, int Size, int Dim, void * P, WideString TypeName);
	void __fastcall WriteRectDynArray(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, Typinfo::PTypeInfo Info, int Dims, void * P, WideString TypeName);
	void __fastcall ReadRectDynArray(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, Typinfo::PTypeInfo Info, int Dims, void * P, int CurElem);
	void __fastcall ReadRectDynArrayElem(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, Typinfo::PTypeInfo Info, int Size, int Dim, void * P, int &CurElem);
	void __fastcall ReadRow(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, int &CurElem, int Size, void * P, Typinfo::PTypeInfo Info);
	WideString __fastcall ConvertEnumToSoap(Typinfo::PTypeInfo Info, void * P, int NumIndirect);
	int __fastcall ConvertSoapToEnum(Typinfo::PTypeInfo Info, WideString S, bool IsNull);
	bool __fastcall MultiRefObject(TMetaClass* Cls);
	void __fastcall ConvertObjectToSOAP(WideString Name, void * ObjP, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, int NumIndirect);
	System::TObject* __fastcall ConvertSOAPToObject(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, TMetaClass* AClass, WideString URI, WideString TypeName, void * ObjP, int NumIndirect);
	WideString __fastcall CreateObjectNode(System::TObject* Instance, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, WideString URI, bool UsePrefix = true);
	void __fastcall LoadObject(System::TObject* Instance, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node);
	void __fastcall SetObjectPropFromText(System::TObject* Instance, Typinfo::PPropInfo PropInfo, WideString SoapData);
	WideString __fastcall GetObjectPropAsText(System::TObject* Instance, Typinfo::PPropInfo PropInfo);
	Opconvert::TSOAPConvertOptions __fastcall GetOptions(void);
	void __fastcall SetOptions(Opconvert::TSOAPConvertOptions Value);
	
public:
	__fastcall virtual TSOAPDomConv(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall ConvertNativeDataToSoap(Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, WideString Name, Typinfo::PTypeInfo Info, void * P, int NumIndirect);
	DYNAMIC void __fastcall ConvertSoapToNativeData(void * DataP, Typinfo::PTypeInfo TypeInfo, Invokeregistry::TDataContext* Context, Xmlintf::_di_IXMLNode RootNode, Xmlintf::_di_IXMLNode Node, bool Translate, bool ByRef, int NumIndirect);
	
__published:
	__property Opconvert::TSOAPConvertOptions Options = {read=FOptions, write=FOptions, nodefault};
public:
	#pragma option push -w-inl
	/* TSOAPDOMProcessor.Destroy */ inline __fastcall virtual ~TSOAPDomConv(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOPToSoapDomConvert;
class PASCALIMPLEMENTATION TOPToSoapDomConvert : public TSOAPDomConv 
{
	typedef TSOAPDomConv inherited;
	
private:
	Wsdlnode::TWSDLView* FWSDLView;
	Soapenv::TSoapEnvelope* Envelope;
	WideString __fastcall GetSoapNS(const Intfinfo::TIntfMetaData &MD);
	void __fastcall ProcessFault(Xmlintf::_di_IXMLNode FaultNode);
	void __fastcall ProcessSuccess(Xmlintf::_di_IXMLNode RespNode, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* InvContext);
	WideString __fastcall GetPartName(const Intfinfo::TIntfMetaData &MethMD, WideString ParamName);
	void __fastcall CheckWSDL(void);
	WideString __fastcall GetBinding();
	void __fastcall SetWSDLView(const Wsdlnode::TWSDLView* WSDLView);
	
public:
	__fastcall virtual TOPToSoapDomConvert(Classes::TComponent* AOwner);
	__fastcall virtual ~TOPToSoapDomConvert(void);
	virtual void __fastcall MsgToInvContext(const WideString Request, const Intfinfo::TIntfMetaData &IntfMD, int &MethNum, Invokeregistry::TInvContext* Context)/* overload */;
	virtual void __fastcall MsgToInvContext(const Classes::TStream* Request, const Intfinfo::TIntfMetaData &IntfMD, int &MethNum, Invokeregistry::TInvContext* Context)/* overload */;
	WideString __fastcall InvContextToMsg(const Intfinfo::TIntfMetaData &IntfMD, int MethNum, Invokeregistry::TInvContext* Con);
	virtual void __fastcall MakeResponse(const Intfinfo::TIntfMetaData &IntfMD, const int MethNum, Invokeregistry::TInvContext* Context, Classes::TStream* Response);
	virtual WideString __fastcall MakeFault(const Sysutils::Exception* Ex);
	virtual void __fastcall ProcessResponse(const WideString Resp, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* Context)/* overload */;
	virtual void __fastcall ProcessResponse(const Classes::TStream* Resp, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* Context)/* overload */;
	virtual void __fastcall ProcessResponse(const Xmlintf::_di_IXMLDocument XMLDoc, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* Context)/* overload */;
	
__published:
	__property Wsdlnode::TWSDLView* WSDLView = {read=FWSDLView, write=SetWSDLView};
private:
	void *__IOPConvert;	/* Opconvert::IOPConvert */
	
public:
	operator IOPConvert*(void) { return (IOPConvert*)&__IOPConvert; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define SVarArrayType "VarArrayType"
extern PACKAGE AnsiString DefArrayElemName;

}	/* namespace Optosoapdomconv */
using namespace Optosoapdomconv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OPToSOAPDomConv
