// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AdaptReq.pas' rev: 6.00

#ifndef AdaptReqHPP
#define AdaptReqHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SiteComp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <WebCntxt.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Adaptreq
{
//-- type declarations -------------------------------------------------------
__interface IActionFieldValues;
typedef System::DelphiInterface<IActionFieldValues> _di_IActionFieldValues;
__interface IActionFieldValue;
typedef System::DelphiInterface<IActionFieldValue> _di_IActionFieldValue;
__interface INTERFACE_UUID("{953B2DA3-7C6D-4F01-932B-0BD8B6C6DBB2}") IActionFieldValues  : public IInterface 
{
	
public:
	virtual int __fastcall IndexOfField(const AnsiString AName) = 0 ;
	virtual _di_IActionFieldValue __fastcall ValueOfField(const AnsiString AName) = 0 ;
	virtual _di_IActionFieldValue __fastcall OrigValueOfField(const AnsiString AName) = 0 ;
	virtual int __fastcall GetFieldCount(void) = 0 ;
	virtual AnsiString __fastcall GetFieldName(int I) = 0 ;
	virtual _di_IActionFieldValue __fastcall GetValue(int I) = 0 ;
	virtual _di_IActionFieldValue __fastcall AddValue(const AnsiString AName) = 0 ;
	virtual _di_IActionFieldValue __fastcall GetOrigValue(int I) = 0 ;
	__property int FieldCount = {read=GetFieldCount};
	__property AnsiString FieldNames[int I] = {read=GetFieldName};
	__property _di_IActionFieldValue OrigValues[int I] = {read=GetOrigValue};
	__property _di_IActionFieldValue Values[int I] = {read=GetValue};
};

__interface IAdapterRecordKeys;
typedef System::DelphiInterface<IAdapterRecordKeys> _di_IAdapterRecordKeys;
__interface INTERFACE_UUID("{96E79603-E01F-4F94-B1E0-6B4E87A5D954}") IAdapterRecordKeys  : public IInterface 
{
	
public:
	virtual int __fastcall GetRecordKeyCount(void) = 0 ;
	virtual AnsiString __fastcall GetRecordKeyName(int I) = 0 ;
	virtual AnsiString __fastcall GetRecordKeyValue(int I) = 0 ;
	__property AnsiString RecordKeyNames[int I] = {read=GetRecordKeyName};
	__property AnsiString RecordKeyValues[int I] = {read=GetRecordKeyValue};
};

__interface IAdapterModes;
typedef System::DelphiInterface<IAdapterModes> _di_IAdapterModes;
__interface INTERFACE_UUID("{7FD48996-5814-11D4-A492-00C04F6BB853}") IAdapterModes  : public IInterface 
{
	
public:
	virtual int __fastcall GetAdapterCount(void) = 0 ;
	virtual AnsiString __fastcall GetAdapterName(int I) = 0 ;
	virtual AnsiString __fastcall GetAdapterMode(int I) = 0 ;
	virtual bool __fastcall FindAdapterMode(System::TObject* AAdapter, AnsiString &AMode) = 0 ;
	__property AnsiString AdapterModes[int I] = {read=GetAdapterMode};
	__property AnsiString AdapterNames[int I] = {read=GetAdapterName};
	__property int AdapterCount = {read=GetAdapterCount};
};

__interface IEnumActionFieldValueRecords;
typedef System::DelphiInterface<IEnumActionFieldValueRecords> _di_IEnumActionFieldValueRecords;
__interface INTERFACE_UUID("{9C51CAD8-6297-4CCC-B9F4-F53020E42A00}") IEnumActionFieldValueRecords  : public IInterface 
{
	
public:
	virtual bool __fastcall GetNextRecord(void) = 0 ;
	virtual bool __fastcall GetFirstRecord(void) = 0 ;
	virtual void __fastcall EndIterator(void) = 0 ;
	virtual bool __fastcall GetEOF(void) = 0 ;
	virtual bool __fastcall GetRecord(int AIndex) = 0 ;
	virtual bool __fastcall FindPopulatedRecord(void) = 0 ;
	virtual int __fastcall GetRecordCount(void) = 0 ;
	virtual bool __fastcall GetInIterator(void) = 0 ;
	__property bool EOF = {read=GetEOF};
	__property int RecordCount = {read=GetRecordCount};
	__property bool InIterator = {read=GetInIterator};
};

__interface IActionFieldValuesOfAdapter;
typedef System::DelphiInterface<IActionFieldValuesOfAdapter> _di_IActionFieldValuesOfAdapter;
__interface INTERFACE_UUID("{F982888E-B049-46C0-AC14-8652E6AC8D97}") IActionFieldValuesOfAdapter  : public IInterface 
{
	
public:
	virtual bool __fastcall LocateActionFieldValuesOfAdapter(Classes::TComponent* AAdapter) = 0 ;
};

#pragma option push -b-
enum TAdapterActionRedirectOption { roRedirectHTTPPost, roRedirectHTTPGet };
#pragma option pop

typedef Set<TAdapterActionRedirectOption, roRedirectHTTPPost, roRedirectHTTPGet>  TAdapterActionRedirectOptions;

__interface IGetAdapterActionRedirectOptions;
typedef System::DelphiInterface<IGetAdapterActionRedirectOptions> _di_IGetAdapterActionRedirectOptions;
__interface INTERFACE_UUID("{79D27D03-D50B-11D4-A534-00C04F6BB853}") IGetAdapterActionRedirectOptions  : public IInterface 
{
	
public:
	virtual TAdapterActionRedirectOptions __fastcall GetSuccessOptions(void) = 0 ;
	virtual TAdapterActionRedirectOptions __fastcall GetFailureOptions(void) = 0 ;
	__property TAdapterActionRedirectOptions SuccessOptions = {read=GetSuccessOptions};
	__property TAdapterActionRedirectOptions FailureOptions = {read=GetFailureOptions};
};

__interface IAdapterRequestParams;
typedef System::DelphiInterface<IAdapterRequestParams> _di_IAdapterRequestParams;
__interface INTERFACE_UUID("{0394040F-414D-11D4-A47C-00C04F6BB853}") IAdapterRequestParams  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetParamName(int I) = 0 ;
	virtual AnsiString __fastcall GetParamValue(int I) = 0 ;
	virtual int __fastcall GetParamCount(void) = 0 ;
	virtual int __fastcall IndexOfParam(const AnsiString AName) = 0 ;
	virtual AnsiString __fastcall ValueOfParam(const AnsiString AName) = 0 ;
	virtual void __fastcall AssignTo(Classes::TStrings* AStrings) = 0 ;
	__property int ParamCount = {read=GetParamCount};
	__property AnsiString ParamNames[int I] = {read=GetParamName};
	__property AnsiString ParamValues[int I] = {read=GetParamValue};
};

__interface INTERFACE_UUID("{C5D4E556-A474-11D4-A4FA-00C04F6BB853}") IActionFieldValue  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetFieldName(void) = 0 ;
	virtual int __fastcall GetValueCount(void) = 0 ;
	virtual Variant __fastcall GetValue(int I) = 0 ;
	virtual int __fastcall GetFileCount(void) = 0 ;
	virtual Httpapp::TAbstractWebRequestFile* __fastcall GetFile(int I) = 0 ;
	__property int ValueCount = {read=GetValueCount};
	__property Variant Values[int I] = {read=GetValue};
	__property int FileCount = {read=GetFileCount};
	__property Httpapp::TAbstractWebRequestFile* Files[int I] = {read=GetFile};
	__property AnsiString FieldName = {read=GetFieldName};
};

__interface IActionRequest;
typedef System::DelphiInterface<IActionRequest> _di_IActionRequest;
__interface INTERFACE_UUID("{374E4AFC-D11F-11D4-A531-00C04F6BB853}") IActionRequest  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetActionName(void) = 0 ;
	virtual bool __fastcall GetHandled(void) = 0 ;
	virtual void __fastcall SetHandled(bool AValue) = 0 ;
	__property AnsiString ActionName = {read=GetActionName};
	__property bool Handled = {read=GetHandled, write=SetHandled};
};

__interface IImageRequest;
typedef System::DelphiInterface<IImageRequest> _di_IImageRequest;
__interface INTERFACE_UUID("{9387A216-4392-48FB-9880-BFA8C5CC306E}") IImageRequest  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetImageName(void) = 0 ;
	__property AnsiString ImageName = {read=GetImageName};
};

#pragma option push -b-
enum TExecuteStatus { esSuccess, esFail, esUndefined, esOther };
#pragma option pop

__interface IActionResponse;
typedef System::DelphiInterface<IActionResponse> _di_IActionResponse;
__interface INTERFACE_UUID("{03940410-414D-11D4-A47C-00C04F6BB853}") IActionResponse  : public IInterface 
{
	
public:
	virtual bool __fastcall GetHandled(void) = 0 ;
	virtual void __fastcall SetHandled(bool Value) = 0 ;
	virtual TExecuteStatus __fastcall GetExecuteStatus(void) = 0 ;
	virtual void __fastcall SetExecuteStatus(TExecuteStatus Value) = 0 ;
	__property TExecuteStatus ExecuteStatus = {read=GetExecuteStatus, write=SetExecuteStatus};
	__property bool Handled = {read=GetHandled, write=SetHandled};
};

#pragma option push -b-
enum TRespondWith { rwPage, rwURL, rwComponentPage, rwUndefined };
#pragma option pop

__interface IActionRespondWith;
typedef System::DelphiInterface<IActionRespondWith> _di_IActionRespondWith;
__interface INTERFACE_UUID("{0FE6EE49-1015-4206-92A9-65655939E4EC}") IActionRespondWith  : public IInterface 
{
	
public:
	virtual TRespondWith __fastcall GetRespondWith(void) = 0 ;
	virtual void __fastcall RespondWithPage(const AnsiString APageName) = 0 ;
	virtual void __fastcall RespondWithURL(const AnsiString AURL) = 0 ;
	virtual void __fastcall RespondWithComponentPage(const Classes::TComponent* AComponent) = 0 ;
	virtual void __fastcall SetExecuteStatus(TExecuteStatus Value) = 0 ;
	virtual TAdapterActionRedirectOptions __fastcall GetRedirectOptions(void) = 0 ;
	virtual void __fastcall SetRedirectOptions(TAdapterActionRedirectOptions AOptions) = 0 ;
	__property TRespondWith RespondWith = {read=GetRespondWith};
	__property TAdapterActionRedirectOptions RedirectOptions = {read=GetRedirectOptions, write=SetRedirectOptions};
};

__interface IActionHandleResponse;
typedef System::DelphiInterface<IActionHandleResponse> _di_IActionHandleResponse;
__interface INTERFACE_UUID("{BA0A46B9-519B-4733-B129-7680ADF33568}") IActionHandleResponse  : public IInterface 
{
	
public:
	virtual void __fastcall HandleResponse(void) = 0 ;
};

__interface IImageResponse;
typedef System::DelphiInterface<IImageResponse> _di_IImageResponse;
__interface INTERFACE_UUID("{739FE582-03BA-42CA-AE02-5557CD3856D3}") IImageResponse  : public IInterface 
{
	
};

class DELPHICLASS TAdapterRequestParamsImpl;
class PASCALIMPLEMENTATION TAdapterRequestParamsImpl : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FStrings;
	Sitecomp::_di_IAdapterDispatchParams FDispatchParams;
	
protected:
	AnsiString __fastcall GetParamName(int I);
	AnsiString __fastcall GetParamValue(int I);
	int __fastcall GetParamCount(void);
	int __fastcall IndexOfParam(const AnsiString AName);
	AnsiString __fastcall ValueOfParam(const AnsiString AName);
	void __fastcall AssignTo(Classes::TStrings* AStrings);
	__property int ParamCount = {read=GetParamCount, nodefault};
	__property AnsiString ParamNames[int I] = {read=GetParamName};
	__property AnsiString ParamValues[int I] = {read=GetParamValue};
	
public:
	__fastcall TAdapterRequestParamsImpl(Sitecomp::_di_IAdapterDispatchParams ADispatchParams);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterRequestParamsImpl(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterModes;
class PASCALIMPLEMENTATION TAdapterModes : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FStrings;
	
protected:
	int __fastcall GetAdapterCount(void);
	AnsiString __fastcall GetAdapterName(int I);
	AnsiString __fastcall GetAdapterMode(int I);
	bool __fastcall FindAdapterMode(System::TObject* AAdapter, AnsiString &AMode);
	__property int AdapterCount = {read=GetAdapterCount, nodefault};
	
public:
	__fastcall TAdapterModes(Httpapp::TWebRequest* ARequest);
	__fastcall virtual ~TAdapterModes(void);
};


class DELPHICLASS TActionFieldValueImpl;
class PASCALIMPLEMENTATION TActionFieldValueImpl : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TStrings* FValues;
	Contnrs::TObjectList* FFiles;
	AnsiString FFieldName;
	
protected:
	int __fastcall GetValueCount(void);
	Variant __fastcall GetValue(int I);
	int __fastcall GetFileCount(void);
	Httpapp::TAbstractWebRequestFile* __fastcall GetFile(int I);
	AnsiString __fastcall GetFieldName();
	
public:
	__fastcall TActionFieldValueImpl(const AnsiString AFieldName, Classes::TStrings* AStrings);
	__fastcall virtual ~TActionFieldValueImpl(void);
private:
	void *__IActionFieldValue;	/* Adaptreq::IActionFieldValue */
	
public:
	operator IActionFieldValue*(void) { return (IActionFieldValue*)&__IActionFieldValue; }
	
};


class DELPHICLASS TActionFieldValuesImpl;
class PASCALIMPLEMENTATION TActionFieldValuesImpl : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FEncodedRecordKeys;
	Classes::TStrings* FRecordKeys;
	Classes::TStrings* FFieldNames;
	Contnrs::TObjectList* FValues;
	Contnrs::TObjectList* FOrigValues;
	Classes::_di_IInterfaceList FOrigValuesIntf;
	Classes::_di_IInterfaceList FValuesIntf;
	int __fastcall GetFieldCount(void);
	_di_IActionFieldValue __fastcall GetValue(int I);
	_di_IActionFieldValue __fastcall GetOrigValue(int I);
	_di_IActionFieldValue __fastcall CreateValue(const AnsiString AName)/* overload */;
	_di_IActionFieldValue __fastcall CreateOrigValue(const AnsiString AName)/* overload */;
	_di_IActionFieldValue __fastcall CreateValue(int I)/* overload */;
	_di_IActionFieldValue __fastcall CreateOrigValue(int I)/* overload */;
	void __fastcall ExpandRecordKeys(void);
	
protected:
	int __fastcall IndexOfField(const AnsiString AName);
	_di_IActionFieldValue __fastcall OrigValueOfField(const AnsiString AName);
	_di_IActionFieldValue __fastcall ValueOfField(const AnsiString AName);
	AnsiString __fastcall GetFieldName(int I);
	_di_IActionFieldValue __fastcall AddValue(const AnsiString AName);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property AnsiString FieldNames[int I] = {read=GetFieldName};
	__property _di_IActionFieldValue OrigValues[int I] = {read=GetOrigValue};
	__property _di_IActionFieldValue Values[int I] = {read=GetValue};
	int __fastcall GetRecordKeyCount(void);
	AnsiString __fastcall GetRecordKeyName(int I);
	AnsiString __fastcall GetRecordKeyValue(int I);
	
public:
	__fastcall TActionFieldValuesImpl(Classes::TStrings* AValues);
	__fastcall virtual ~TActionFieldValuesImpl(void);
};


class DELPHICLASS TEnumActionFieldValueRecordsImpl;
class PASCALIMPLEMENTATION TEnumActionFieldValueRecordsImpl : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FAdapterName;
	Contnrs::TObjectList* FList;
	int FCurrentIndex;
	bool FInIterator;
	TActionFieldValuesImpl* __fastcall GetCurrentFieldValues(void);
	
protected:
	bool __fastcall GetNextRecord(void);
	void __fastcall EndIterator(void);
	bool __fastcall GetFirstRecord(void);
	bool __fastcall GetEOF(void);
	bool __fastcall GetRecord(int AIndex);
	bool __fastcall FindPopulatedRecord(void);
	int __fastcall GetRecordCount(void);
	bool __fastcall GetInIterator(void);
	__property bool EOF = {read=GetEOF, nodefault};
	
public:
	__fastcall TEnumActionFieldValueRecordsImpl(const AnsiString AAdapterName, Classes::TStrings* AFieldValues);
	__fastcall virtual ~TEnumActionFieldValueRecordsImpl(void);
	__property TActionFieldValuesImpl* CurrentFieldValues = {read=GetCurrentFieldValues};
	__property AnsiString AdapterName = {read=FAdapterName};
};


class DELPHICLASS TAdapterActionFieldValuesList;
class PASCALIMPLEMENTATION TAdapterActionFieldValuesList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	int FCurrentIndex;
	TEnumActionFieldValueRecordsImpl* __fastcall GetCurrentFieldValuesList(void);
	
protected:
	bool __fastcall LocateActionFieldValuesOfAdapter(Classes::TComponent* AAdapter);
	
public:
	__fastcall TAdapterActionFieldValuesList(Httpapp::TWebRequest* ARequest);
	__fastcall virtual ~TAdapterActionFieldValuesList(void);
	__property TEnumActionFieldValueRecordsImpl* CurrentActionFieldValuesList = {read=GetCurrentFieldValuesList};
};


class DELPHICLASS TBasicActionRequestImpl;
class PASCALIMPLEMENTATION TBasicActionRequestImpl : public Webcntxt::TAbstractAdapterRequest 
{
	typedef Webcntxt::TAbstractAdapterRequest inherited;
	
private:
	TAdapterRequestParamsImpl* FActionParams;
	Sitecomp::_di_IAdapterDispatchParams FDispatchParams;
	AnsiString FSuccessPage;
	AnsiString FFailurePage;
	bool FHandled;
	
protected:
	AnsiString __fastcall GetActionName();
	bool __fastcall GetHandled(void);
	void __fastcall SetHandled(bool AValue);
	AnsiString __fastcall GetSuccessPage();
	AnsiString __fastcall GetFailurePage();
	
public:
	__fastcall TBasicActionRequestImpl(Sitecomp::_di_IAdapterDispatchParams ADispatchParams);
	__fastcall virtual ~TBasicActionRequestImpl(void);
	__property AnsiString ActionName = {read=GetActionName};
	__property Sitecomp::_di_IAdapterDispatchParams DispatchParams = {read=FDispatchParams};
	__property TAdapterRequestParamsImpl* ActionParams = {read=FActionParams};
	__property AnsiString SuccessPage = {read=GetSuccessPage};
	__property AnsiString FailurePage = {read=GetFailurePage};
private:
	void *__IActionRequest;	/* Adaptreq::IActionRequest */
	void *__IAdapterRequestParams;	/* Adaptreq::IAdapterRequestParams */
	void *__IGetAdapterRequestDefaultResponse;	/* Sitecomp::IGetAdapterRequestDefaultResponse */
	
public:
	operator IGetAdapterRequestDefaultResponse*(void) { return (IGetAdapterRequestDefaultResponse*)&__IGetAdapterRequestDefaultResponse; }
	operator IAdapterRequestParams*(void) { return (IAdapterRequestParams*)&__IAdapterRequestParams; }
	operator IActionRequest*(void) { return (IActionRequest*)&__IActionRequest; }
	
};


class DELPHICLASS TSingleRecordActionRequestImpl;
class PASCALIMPLEMENTATION TSingleRecordActionRequestImpl : public TBasicActionRequestImpl 
{
	typedef TBasicActionRequestImpl inherited;
	
private:
	TActionFieldValuesImpl* FFieldValues;
	TAdapterModes* FAdapterModes;
	
protected:
	__property TActionFieldValuesImpl* ActionFieldValues = {read=FFieldValues};
	__property TAdapterModes* AdapterModes = {read=FAdapterModes};
	
public:
	__fastcall TSingleRecordActionRequestImpl(Sitecomp::_di_IAdapterDispatchParams ADispatchParams);
	__fastcall virtual ~TSingleRecordActionRequestImpl(void);
private:
	void *__IAdapterModes;	/* Adaptreq::IAdapterModes */
	void *__IActionFieldValues;	/* Adaptreq::IActionFieldValues */
	
public:
	operator IActionFieldValues*(void) { return (IActionFieldValues*)&__IActionFieldValues; }
	operator IAdapterModes*(void) { return (IAdapterModes*)&__IAdapterModes; }
	
};


class DELPHICLASS TMultiRecordActionRequestImpl;
class PASCALIMPLEMENTATION TMultiRecordActionRequestImpl : public TBasicActionRequestImpl 
{
	typedef TBasicActionRequestImpl inherited;
	
private:
	TAdapterActionFieldValuesList* FAdapterActionFieldValuesList;
	TAdapterModes* FAdapterModes;
	TActionFieldValuesImpl* __fastcall GetFieldValues(void);
	TEnumActionFieldValueRecordsImpl* __fastcall GetFieldValuesList(void);
	
protected:
	__property TActionFieldValuesImpl* ActionFieldValues = {read=GetFieldValues};
	__property TActionFieldValuesImpl* ActionFieldValues2 = {read=GetFieldValues};
	__property TAdapterModes* AdapterModes = {read=FAdapterModes};
	__property TEnumActionFieldValueRecordsImpl* ActionFieldValuesList = {read=GetFieldValuesList};
	__property TAdapterActionFieldValuesList* AdapterActionFieldValuesList = {read=FAdapterActionFieldValuesList};
	
public:
	__fastcall TMultiRecordActionRequestImpl(Sitecomp::_di_IAdapterDispatchParams ADispatchParams);
	__fastcall virtual ~TMultiRecordActionRequestImpl(void);
private:
	void *__IAdapterModes;	/* Adaptreq::IAdapterModes */
	void *__IActionFieldValues;	/* Adaptreq::IActionFieldValues */
	void *__IEnumActionFieldValueRecords;	/* Adaptreq::IEnumActionFieldValueRecords */
	void *__IAdapterRecordKeys;	/* Adaptreq::IAdapterRecordKeys */
	void *__IActionFieldValuesOfAdapter;	/* Adaptreq::IActionFieldValuesOfAdapter */
	
public:
	operator IActionFieldValuesOfAdapter*(void) { return (IActionFieldValuesOfAdapter*)&__IActionFieldValuesOfAdapter; }
	operator IAdapterRecordKeys*(void) { return (IAdapterRecordKeys*)&__IAdapterRecordKeys; }
	operator IEnumActionFieldValueRecords*(void) { return (IEnumActionFieldValueRecords*)&__IEnumActionFieldValueRecords; }
	operator IActionFieldValues*(void) { return (IActionFieldValues*)&__IActionFieldValues; }
	operator IAdapterModes*(void) { return (IAdapterModes*)&__IAdapterModes; }
	
};


class DELPHICLASS TBasicActionResponseImpl;
class PASCALIMPLEMENTATION TBasicActionResponseImpl : public Webcntxt::TAbstractAdapterResponse 
{
	typedef Webcntxt::TAbstractAdapterResponse inherited;
	
private:
	TExecuteStatus FExecuteStatus;
	bool FHandled;
	TRespondWith FRespondWith;
	AnsiString FPageName;
	TAdapterActionRedirectOptions FRedirectOptions;
	AnsiString FURL;
	Classes::TComponent* FComponent;
	TBasicActionRequestImpl* FActionRequest;
	TAdapterActionRedirectOptions __fastcall SuccessRedirect(void);
	TAdapterActionRedirectOptions __fastcall FailureRedirect(void);
	AnsiString __fastcall GetFailurePage();
	AnsiString __fastcall GetSuccessPage();
	
protected:
	void __fastcall RespondWithSuccessPage(void);
	void __fastcall RespondWithFailurePage(void);
	bool __fastcall GetHandled(void);
	void __fastcall SetHandled(bool Value);
	TExecuteStatus __fastcall GetExecuteStatus(void);
	void __fastcall SetExecuteStatus(TExecuteStatus Value);
	TRespondWith __fastcall GetRespondWith(void);
	void __fastcall RespondWithPage(const AnsiString APageName);
	void __fastcall RespondWithURL(const AnsiString AURL);
	void __fastcall RespondWithComponentPage(const Classes::TComponent* AComponent);
	TAdapterActionRedirectOptions __fastcall GetRedirectOptions(void);
	void __fastcall SetRedirectOptions(TAdapterActionRedirectOptions AOptions);
	void __fastcall HandleResponse(void);
	
public:
	__fastcall TBasicActionResponseImpl(TBasicActionRequestImpl* AActionRequest);
	__property TAdapterActionRedirectOptions RedirectOptions = {read=GetRedirectOptions, write=SetRedirectOptions, nodefault};
	__property TRespondWith RespondWith = {read=GetRespondWith, nodefault};
	__property TExecuteStatus ExecuteStatus = {read=GetExecuteStatus, write=SetExecuteStatus, nodefault};
	__property bool Handled = {read=GetHandled, write=SetHandled, nodefault};
	__property AnsiString FailurePage = {read=GetFailurePage};
	__property AnsiString SuccessPage = {read=GetSuccessPage};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBasicActionResponseImpl(void) { }
	#pragma option pop
	
private:
	void *__IActionResponse;	/* Adaptreq::IActionResponse */
	void *__IActionRespondWith;	/* Adaptreq::IActionRespondWith */
	void *__IActionHandleResponse;	/* Adaptreq::IActionHandleResponse */
	
public:
	operator IActionHandleResponse*(void) { return (IActionHandleResponse*)&__IActionHandleResponse; }
	operator IActionRespondWith*(void) { return (IActionRespondWith*)&__IActionRespondWith; }
	operator IActionResponse*(void) { return (IActionResponse*)&__IActionResponse; }
	
};


class DELPHICLASS TBasicImageRequestImpl;
class PASCALIMPLEMENTATION TBasicImageRequestImpl : public Webcntxt::TAbstractAdapterRequest 
{
	typedef Webcntxt::TAbstractAdapterRequest inherited;
	
private:
	TAdapterRequestParamsImpl* FImageParams;
	Sitecomp::_di_IAdapterDispatchParams FDispatchParams;
	
protected:
	AnsiString __fastcall GetImageName();
	__property AnsiString ImageName = {read=GetImageName};
	__property TAdapterRequestParamsImpl* ActionRequestParams = {read=FImageParams};
	
public:
	__fastcall TBasicImageRequestImpl(Sitecomp::_di_IAdapterDispatchParams ADispatchParams);
	__fastcall virtual ~TBasicImageRequestImpl(void);
	__property Sitecomp::_di_IAdapterDispatchParams DispatchParams = {read=FDispatchParams};
private:
	void *__IImageRequest;	/* Adaptreq::IImageRequest */
	void *__IAdapterRequestParams;	/* Adaptreq::IAdapterRequestParams */
	
public:
	operator IAdapterRequestParams*(void) { return (IAdapterRequestParams*)&__IAdapterRequestParams; }
	operator IImageRequest*(void) { return (IImageRequest*)&__IImageRequest; }
	
};


class DELPHICLASS TBasicImageResponseImpl;
class PASCALIMPLEMENTATION TBasicImageResponseImpl : public Webcntxt::TAbstractAdapterResponse 
{
	typedef Webcntxt::TAbstractAdapterResponse inherited;
	
public:
	__fastcall TBasicImageResponseImpl(TBasicImageRequestImpl* AImageRequest);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBasicImageResponseImpl(void) { }
	#pragma option pop
	
private:
	void *__IImageResponse;	/* Adaptreq::IImageResponse */
	
public:
	operator IImageResponse*(void) { return (IImageResponse*)&__IImageResponse; }
	
};


class DELPHICLASS EAdapterRequestException;
class PASCALIMPLEMENTATION EAdapterRequestException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAdapterRequestException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAdapterRequestException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAdapterRequestException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAdapterRequestException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAdapterRequestException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAdapterRequestException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAdapterRequestException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAdapterRequestException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAdapterRequestException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define roRedirect (System::Set<TAdapterActionRedirectOption, roRedirectHTTPPost, roRedirectHTTPGet> () << TAdapterActionRedirectOption(0) << TAdapterActionRedirectOption(1) )
#define sDelimAdapterMode "__am."
#define sDelimRecordKeys "__key."
#define sDelimOrigFieldValue "__ov."
#define sActionRequest "__act"
extern PACKAGE AnsiString __fastcall ExtractStringValue(const AnsiString S);
extern PACKAGE bool __fastcall TestRedirectOptions(TAdapterActionRedirectOptions AOptions, Httpapp::TMethodType AMethodType);

}	/* namespace Adaptreq */
using namespace Adaptreq;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AdaptReq
