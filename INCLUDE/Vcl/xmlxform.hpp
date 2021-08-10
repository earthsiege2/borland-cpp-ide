// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Xmlxform.pas' rev: 6.00

#ifndef XmlxformHPP
#define XmlxformHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmlutil.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <DSIntf.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlxform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TranslateException;
class PASCALIMPLEMENTATION TranslateException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall TranslateException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall TranslateException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall TranslateException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall TranslateException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall TranslateException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall TranslateException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall TranslateException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall TranslateException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TranslateException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TTranslateEvent)(System::TObject* Sender, AnsiString Id, Xmldom::_di_IDOMNode SrcNode, AnsiString &Value, Xmldom::_di_IDOMNode DestNode);

typedef void __fastcall (__closure *TRowEvent)(System::TObject* Sender, AnsiString Id, Xmldom::_di_IDOMNode SrcNode, Xmldom::_di_IDOMNode DestNode);

class DELPHICLASS TXMLTransform;
class PASCALIMPLEMENTATION TXMLTransform : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FEncoding;
	AnsiString FEncodingTrans;
	bool FDirectionToCds;
	AnsiString FVersion;
	AnsiString FSourceXmlFile;
	Xmldom::_di_IDOMDocument FSourceXmlDocument;
	AnsiString FSourceXml;
	AnsiString FTransformationFile;
	Xmldom::_di_IDOMDocument FTransformationDocument;
	Xmldom::_di_IDOMDocument FEmptyDestinationDocument;
	Xmldom::_di_IDOMDocument FResultDocument;
	AnsiString FResultString;
	TTranslateEvent FOnTranslate;
	TRowEvent FBeforeEachRow;
	TRowEvent FAfterEachRow;
	TRowEvent FBeforeEachRowSet;
	TRowEvent FAfterEachRowSet;
	
protected:
	DYNAMIC void __fastcall Translate(const AnsiString Id, const Xmldom::_di_IDOMNode SrcNode, AnsiString &SrcValue, const Xmldom::_di_IDOMNode DestNode);
	AnsiString __fastcall DoTransform(const Xmldom::_di_IDOMDocument XMLSrc, const Xmldom::_di_IDOMDocument XMLExtract, const Xmldom::_di_IDOMDocument XMLOut);
	void __fastcall Transform(Xmldom::_di_IDOMNode TransNode, Xmldom::_di_IDOMNode SrcNode, Xmldom::_di_IDOMNode DestNode, int Count, Classes::TStringList* InFromList, Classes::TStringList* InDestList, Classes::TStringList* InIdStrList, Classes::TStringList* InValueList, Classes::TStringList* InOptionalList, Classes::TStringList* InDateFormatList, Classes::TStringList* InDateFormatTypeList, Classes::TStringList* InMapValuesList);
	AnsiString __fastcall GetData();
	AnsiString __fastcall GetResultString();
	
public:
	AnsiString __fastcall TransformXML(const AnsiString SourceXml, const AnsiString ATransformationFile = "");
	__property AnsiString Data = {read=GetData};
	__property Xmldom::_di_IDOMDocument SourceXmlDocument = {read=FSourceXmlDocument, write=FSourceXmlDocument};
	__property AnsiString SourceXmlFile = {read=FSourceXmlFile, write=FSourceXmlFile};
	__property AnsiString SourceXml = {read=FSourceXml, write=FSourceXml};
	__property Xmldom::_di_IDOMDocument TransformationDocument = {read=FTransformationDocument, write=FTransformationDocument};
	__property Xmldom::_di_IDOMDocument EmptyDestinationDocument = {read=FEmptyDestinationDocument, write=FEmptyDestinationDocument};
	__property Xmldom::_di_IDOMDocument ResultDocument = {read=FResultDocument};
	__property AnsiString ResultString = {read=GetResultString};
	
__published:
	__property AnsiString TransformationFile = {read=FTransformationFile, write=FTransformationFile};
	__property TTranslateEvent OnTranslate = {read=FOnTranslate, write=FOnTranslate};
	__property TRowEvent BeforeEachRow = {read=FBeforeEachRow, write=FBeforeEachRow};
	__property TRowEvent AfterEachRow = {read=FAfterEachRow, write=FAfterEachRow};
	__property TRowEvent BeforeEachRowSet = {read=FBeforeEachRowSet, write=FBeforeEachRowSet};
	__property TRowEvent AfterEachRowSet = {read=FAfterEachRowSet, write=FAfterEachRowSet};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXMLTransform(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXMLTransform(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXMLTransformProvider;
class PASCALIMPLEMENTATION TXMLTransformProvider : public Provider::TCustomProvider 
{
	typedef Provider::TCustomProvider inherited;
	
private:
	Dbclient::TClientDataSet* FDataCache;
	Provider::TDataSetProvider* FResolver;
	TXMLTransform* FTransformRead;
	TXMLTransform* FTransformWrite;
	bool FCacheData;
	AnsiString __fastcall GetXMLDataFile();
	void __fastcall SetXMLDataFile(const AnsiString Value);
	
protected:
	virtual OleVariant __fastcall InternalApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount);
	virtual OleVariant __fastcall InternalGetRecords(int Count, /* out */ int &RecsOut, Provider::TGetRecordOptions Options, const WideString CommandText, OleVariant &Params);
	
public:
	__fastcall virtual TXMLTransformProvider(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLTransformProvider(void);
	
__published:
	__property TXMLTransform* TransformRead = {read=FTransformRead};
	__property TXMLTransform* TransformWrite = {read=FTransformWrite};
	__property AnsiString XMLDataFile = {read=GetXMLDataFile, write=SetXMLDataFile};
	__property bool CacheData = {read=FCacheData, write=FCacheData, default=0};
	__property BeforeApplyUpdates ;
	__property AfterApplyUpdates ;
	__property BeforeGetRecords ;
	__property AfterGetRecords ;
	__property BeforeRowRequest ;
	__property AfterRowRequest ;
	__property OnDataRequest ;
};


class DELPHICLASS TXMLTransformClient;
class PASCALIMPLEMENTATION TXMLTransformClient : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Dbclient::TClientDataSet* FDataCache;
	Dbclient::TClientDataSet* FSetParamsDataCache;
	Provider::TLocalAppServer* FLocalAppServer;
	TXMLTransform* FTransformGetData;
	TXMLTransform* FTransformApplyUpdates;
	TXMLTransform* FTransformSetParams;
	AnsiString __fastcall GetProviderName();
	Dbclient::TCustomRemoteServer* __fastcall GetRemoteServer(void);
	void __fastcall SetProviderName(const AnsiString Value);
	void __fastcall SetRemoteServer(const Dbclient::TCustomRemoteServer* Value);
	
protected:
	void __fastcall SetupAppServer(void);
	
public:
	__fastcall virtual TXMLTransformClient(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLTransformClient(void);
	virtual AnsiString __fastcall GetDataAsXml(const AnsiString PublishTransformFile);
	virtual int __fastcall ApplyUpdates(const AnsiString UpdateXML, const AnsiString UpdateTransformFile, int MaxErrors);
	void __fastcall SetParams(const AnsiString ParamsXml, const AnsiString ParamsTransformFile);
	
__published:
	__property Dbclient::TCustomRemoteServer* RemoteServer = {read=GetRemoteServer, write=SetRemoteServer};
	__property AnsiString ProviderName = {read=GetProviderName, write=SetProviderName};
	__property TXMLTransform* TransformGetData = {read=FTransformGetData};
	__property TXMLTransform* TransformApplyUpdates = {read=FTransformApplyUpdates};
	__property TXMLTransform* TransformSetParams = {read=FTransformSetParams};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Xmlxform */
using namespace Xmlxform;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Xmlxform
