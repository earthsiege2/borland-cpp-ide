// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ADOInt.pas' rev: 6.00

#ifndef ADOIntHPP
#define ADOIntHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Adoint
{
//-- type declarations -------------------------------------------------------
__interface _Connection;
typedef System::DelphiInterface<_Connection> _di__Connection;
typedef _Connection Connection;
;

__interface _Command;
typedef System::DelphiInterface<_Command> _di__Command;
typedef _Command Command;
;

__interface _Recordset;
typedef System::DelphiInterface<_Recordset> _di__Recordset;
typedef _Recordset Recordset;
;

__interface _Parameter;
typedef System::DelphiInterface<_Parameter> _di__Parameter;
typedef _Parameter Parameter;
;

__interface IDataspace;
typedef System::DelphiInterface<IDataspace> _di_IDataspace;
typedef IDataspace DataSpace;
;

__interface _Collection;
typedef System::DelphiInterface<_Collection> _di__Collection;
__interface INTERFACE_UUID("{00000512-0000-0010-8000-00AA006D2EA4}") _Collection  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall _NewEnum(System::_di_IInterface &_NewEnum_result) = 0 ;
	virtual HRESULT __safecall Refresh(void) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__dispinterface _CollectionDisp;
typedef System::DelphiInterface<_CollectionDisp> _di__CollectionDisp;
__dispinterface INTERFACE_UUID("{00000512-0000-0010-8000-00AA006D2EA4}") _CollectionDisp  : public IDispatch 
{
	
};

__interface _DynaCollection;
typedef System::DelphiInterface<_DynaCollection> _di__DynaCollection;
__interface INTERFACE_UUID("{00000513-0000-0010-8000-00AA006D2EA4}") _DynaCollection  : public _Collection 
{
	
public:
	virtual HRESULT __safecall Append(const _di_IDispatch Object_) = 0 ;
	virtual HRESULT __safecall Delete(const OleVariant Index) = 0 ;
};

__dispinterface _DynaCollectionDisp;
typedef System::DelphiInterface<_DynaCollectionDisp> _di__DynaCollectionDisp;
__dispinterface INTERFACE_UUID("{00000513-0000-0010-8000-00AA006D2EA4}") _DynaCollectionDisp  : public IDispatch 
{
	
};

__interface _ADO;
typedef System::DelphiInterface<_ADO> _di__ADO;
__interface Properties;
typedef System::DelphiInterface<Properties> _di_Properties;
__interface INTERFACE_UUID("{00000534-0000-0010-8000-00AA006D2EA4}") _ADO  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Properties(_di_Properties &Get_Properties_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Properties _scw_Get_Properties() { _di_Properties r; HRESULT hr = Get_Properties(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Properties Properties = {read=_scw_Get_Properties};
};

__dispinterface _ADODisp;
typedef System::DelphiInterface<_ADODisp> _di__ADODisp;
__dispinterface INTERFACE_UUID("{00000534-0000-0010-8000-00AA006D2EA4}") _ADODisp  : public IDispatch 
{
	
};

__interface Property_;
typedef System::DelphiInterface<Property_> _di_Property_;
__interface INTERFACE_UUID("{00000504-0000-0010-8000-00AA006D2EA4}") Properties  : public _Collection 
{
	
public:
	_di_Property_ operator[](OleVariant Index) { return Item[Index]; }
	
public:
	virtual HRESULT __safecall Get_Item(const OleVariant Index, _di_Property_ &Get_Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Property_ _scw_Get_Item(const OleVariant Index) { _di_Property_ r; HRESULT hr = Get_Item(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Property_ Item[OleVariant Index] = {read=_scw_Get_Item/*, default*/};
};

__dispinterface PropertiesDisp;
typedef System::DelphiInterface<PropertiesDisp> _di_PropertiesDisp;
__dispinterface INTERFACE_UUID("{00000504-0000-0010-8000-00AA006D2EA4}") PropertiesDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{00000503-0000-0010-8000-00AA006D2EA4}") Property_  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Set_Value(const OleVariant pval) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_Type_(Activex::TOleEnum &Get_Type__result) = 0 ;
	virtual HRESULT __safecall Get_Attributes(int &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall Set_Attributes(int plAttributes) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value, write=Set_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Type_() { Activex::TOleEnum r; HRESULT hr = Get_Type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Type_ = {read=_scw_Get_Type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Attributes() { int r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Attributes = {read=_scw_Get_Attributes, write=Set_Attributes};
};

__dispinterface Property_Disp;
typedef System::DelphiInterface<Property_Disp> _di_Property_Disp;
__dispinterface INTERFACE_UUID("{00000503-0000-0010-8000-00AA006D2EA4}") Property_Disp  : public IDispatch 
{
	
};

__interface Error;
typedef System::DelphiInterface<Error> _di_Error;
__interface INTERFACE_UUID("{00000500-0000-0010-8000-00AA006D2EA4}") Error  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Number(int &Get_Number_result) = 0 ;
	virtual HRESULT __safecall Get_Source(WideString &Get_Source_result) = 0 ;
	virtual HRESULT __safecall Get_Description(WideString &Get_Description_result) = 0 ;
	virtual HRESULT __safecall Get_HelpFile(WideString &Get_HelpFile_result) = 0 ;
	virtual HRESULT __safecall Get_HelpContext(int &Get_HelpContext_result) = 0 ;
	virtual HRESULT __safecall Get_SQLState(WideString &Get_SQLState_result) = 0 ;
	virtual HRESULT __safecall Get_NativeError(int &Get_NativeError_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Number() { int r; HRESULT hr = Get_Number(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Number = {read=_scw_Get_Number};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Source() { WideString r; HRESULT hr = Get_Source(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Source = {read=_scw_Get_Source};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Description() { WideString r; HRESULT hr = Get_Description(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Description = {read=_scw_Get_Description};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_HelpFile() { WideString r; HRESULT hr = Get_HelpFile(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString HelpFile = {read=_scw_Get_HelpFile};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_HelpContext() { int r; HRESULT hr = Get_HelpContext(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int HelpContext = {read=_scw_Get_HelpContext};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_SQLState() { WideString r; HRESULT hr = Get_SQLState(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString SQLState = {read=_scw_Get_SQLState};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_NativeError() { int r; HRESULT hr = Get_NativeError(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int NativeError = {read=_scw_Get_NativeError};
};

__dispinterface ErrorDisp;
typedef System::DelphiInterface<ErrorDisp> _di_ErrorDisp;
__dispinterface INTERFACE_UUID("{00000500-0000-0010-8000-00AA006D2EA4}") ErrorDisp  : public IDispatch 
{
	
};

__interface Errors;
typedef System::DelphiInterface<Errors> _di_Errors;
__interface INTERFACE_UUID("{00000501-0000-0010-8000-00AA006D2EA4}") Errors  : public _Collection 
{
	
public:
	_di_Error operator[](OleVariant Index) { return Item[Index]; }
	
public:
	virtual HRESULT __safecall Get_Item(const OleVariant Index, _di_Error &Get_Item_result) = 0 ;
	virtual HRESULT __safecall Clear(void) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Error _scw_Get_Item(const OleVariant Index) { _di_Error r; HRESULT hr = Get_Item(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Error Item[OleVariant Index] = {read=_scw_Get_Item/*, default*/};
};

__dispinterface ErrorsDisp;
typedef System::DelphiInterface<ErrorsDisp> _di_ErrorsDisp;
__dispinterface INTERFACE_UUID("{00000501-0000-0010-8000-00AA006D2EA4}") ErrorsDisp  : public IDispatch 
{
	
};

__interface Command15;
typedef System::DelphiInterface<Command15> _di_Command15;
__interface Parameters;
typedef System::DelphiInterface<Parameters> _di_Parameters;
__interface INTERFACE_UUID("{00000508-0000-0010-8000-00AA006D2EA4}") Command15  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_ActiveConnection(_di__Connection &Get_ActiveConnection_result) = 0 ;
	virtual HRESULT __safecall Set_ActiveConnection(const _di__Connection ppvObject) = 0 ;
	virtual HRESULT __safecall _Set_ActiveConnection(const OleVariant ppvObject) = 0 ;
	virtual HRESULT __safecall Get_CommandText(WideString &Get_CommandText_result) = 0 ;
	virtual HRESULT __safecall Set_CommandText(const WideString pbstr) = 0 ;
	virtual HRESULT __safecall Get_CommandTimeout(int &Get_CommandTimeout_result) = 0 ;
	virtual HRESULT __safecall Set_CommandTimeout(int pl) = 0 ;
	virtual HRESULT __safecall Get_Prepared(Word &Get_Prepared_result) = 0 ;
	virtual HRESULT __safecall Set_Prepared(Word pfPrepared) = 0 ;
	virtual HRESULT __safecall Execute(/* out */ OleVariant &RecordsAffected, const OleVariant &Parameters, int Options, _di__Recordset &Execute_result) = 0 ;
	virtual HRESULT __safecall CreateParameter(const WideString Name, Activex::TOleEnum Type_, Activex::TOleEnum Direction, int Size, const OleVariant Value, _di__Parameter &CreateParameter_result) = 0 ;
	virtual HRESULT __safecall Get_Parameters(_di_Parameters &Get_Parameters_result) = 0 ;
	virtual HRESULT __safecall Set_CommandType(Activex::TOleEnum plCmdType) = 0 ;
	virtual HRESULT __safecall Get_CommandType(Activex::TOleEnum &Get_CommandType_result) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Set_Name(const WideString pbstrName) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_CommandText() { WideString r; HRESULT hr = Get_CommandText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString CommandText = {read=_scw_Get_CommandText, write=Set_CommandText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_CommandTimeout() { int r; HRESULT hr = Get_CommandTimeout(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int CommandTimeout = {read=_scw_Get_CommandTimeout, write=Set_CommandTimeout};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Prepared() { Word r; HRESULT hr = Get_Prepared(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Prepared = {read=_scw_Get_Prepared, write=Set_Prepared};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Parameters _scw_Get_Parameters() { _di_Parameters r; HRESULT hr = Get_Parameters(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Parameters Parameters = {read=_scw_Get_Parameters};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_CommandType() { Activex::TOleEnum r; HRESULT hr = Get_CommandType(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum CommandType = {read=_scw_Get_CommandType, write=Set_CommandType};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name, write=Set_Name};
};

__dispinterface Command15Disp;
typedef System::DelphiInterface<Command15Disp> _di_Command15Disp;
__dispinterface INTERFACE_UUID("{00000508-0000-0010-8000-00AA006D2EA4}") Command15Disp  : public IDispatch 
{
	
};

__interface Connection15;
typedef System::DelphiInterface<Connection15> _di_Connection15;
__interface INTERFACE_UUID("{00000515-0000-0010-8000-00AA006D2EA4}") Connection15  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_ConnectionString(WideString &Get_ConnectionString_result) = 0 ;
	virtual HRESULT __safecall Set_ConnectionString(const WideString pbstr) = 0 ;
	virtual HRESULT __safecall Get_CommandTimeout(int &Get_CommandTimeout_result) = 0 ;
	virtual HRESULT __safecall Set_CommandTimeout(int plTimeout) = 0 ;
	virtual HRESULT __safecall Get_ConnectionTimeout(int &Get_ConnectionTimeout_result) = 0 ;
	virtual HRESULT __safecall Set_ConnectionTimeout(int plTimeout) = 0 ;
	virtual HRESULT __safecall Get_Version(WideString &Get_Version_result) = 0 ;
	virtual HRESULT __safecall Close(void) = 0 ;
	virtual HRESULT __safecall Execute(const WideString CommandText, /* out */ OleVariant &RecordsAffected, int Options, _di__Recordset &Execute_result) = 0 ;
	virtual HRESULT __safecall BeginTrans(int &BeginTrans_result) = 0 ;
	virtual HRESULT __safecall CommitTrans(void) = 0 ;
	virtual HRESULT __safecall RollbackTrans(void) = 0 ;
	virtual HRESULT __safecall Open(const WideString ConnectionString, const WideString UserID, const WideString Password, int Options) = 0 ;
	virtual HRESULT __safecall Get_Errors(_di_Errors &Get_Errors_result) = 0 ;
	virtual HRESULT __safecall Get_DefaultDatabase(WideString &Get_DefaultDatabase_result) = 0 ;
	virtual HRESULT __safecall Set_DefaultDatabase(const WideString pbstr) = 0 ;
	virtual HRESULT __safecall Get_IsolationLevel(Activex::TOleEnum &Get_IsolationLevel_result) = 0 ;
	virtual HRESULT __safecall Set_IsolationLevel(Activex::TOleEnum Level) = 0 ;
	virtual HRESULT __safecall Get_Attributes(int &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall Set_Attributes(int plAttr) = 0 ;
	virtual HRESULT __safecall Get_CursorLocation(Activex::TOleEnum &Get_CursorLocation_result) = 0 ;
	virtual HRESULT __safecall Set_CursorLocation(Activex::TOleEnum plCursorLoc) = 0 ;
	virtual HRESULT __safecall Get_Mode(Activex::TOleEnum &Get_Mode_result) = 0 ;
	virtual HRESULT __safecall Set_Mode(Activex::TOleEnum plMode) = 0 ;
	virtual HRESULT __safecall Get_Provider(WideString &Get_Provider_result) = 0 ;
	virtual HRESULT __safecall Set_Provider(const WideString pbstr) = 0 ;
	virtual HRESULT __safecall Get_State(int &Get_State_result) = 0 ;
	virtual HRESULT __safecall OpenSchema(Activex::TOleEnum Schema, const OleVariant Restrictions, const OleVariant SchemaID, _di__Recordset &OpenSchema_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ConnectionString() { WideString r; HRESULT hr = Get_ConnectionString(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ConnectionString = {read=_scw_Get_ConnectionString, write=Set_ConnectionString};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_CommandTimeout() { int r; HRESULT hr = Get_CommandTimeout(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int CommandTimeout = {read=_scw_Get_CommandTimeout, write=Set_CommandTimeout};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_ConnectionTimeout() { int r; HRESULT hr = Get_ConnectionTimeout(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int ConnectionTimeout = {read=_scw_Get_ConnectionTimeout, write=Set_ConnectionTimeout};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Version() { WideString r; HRESULT hr = Get_Version(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Version = {read=_scw_Get_Version};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Errors _scw_Get_Errors() { _di_Errors r; HRESULT hr = Get_Errors(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Errors Errors = {read=_scw_Get_Errors};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DefaultDatabase() { WideString r; HRESULT hr = Get_DefaultDatabase(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DefaultDatabase = {read=_scw_Get_DefaultDatabase, write=Set_DefaultDatabase};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_IsolationLevel() { Activex::TOleEnum r; HRESULT hr = Get_IsolationLevel(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum IsolationLevel = {read=_scw_Get_IsolationLevel, write=Set_IsolationLevel};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Attributes() { int r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Attributes = {read=_scw_Get_Attributes, write=Set_Attributes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_CursorLocation() { Activex::TOleEnum r; HRESULT hr = Get_CursorLocation(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum CursorLocation = {read=_scw_Get_CursorLocation, write=Set_CursorLocation};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Mode() { Activex::TOleEnum r; HRESULT hr = Get_Mode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Mode = {read=_scw_Get_Mode, write=Set_Mode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Provider() { WideString r; HRESULT hr = Get_Provider(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Provider = {read=_scw_Get_Provider, write=Set_Provider};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_State() { int r; HRESULT hr = Get_State(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int State = {read=_scw_Get_State};
};

__dispinterface Connection15Disp;
typedef System::DelphiInterface<Connection15Disp> _di_Connection15Disp;
__dispinterface INTERFACE_UUID("{00000515-0000-0010-8000-00AA006D2EA4}") Connection15Disp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{00000550-0000-0010-8000-00AA006D2EA4}") _Connection  : public Connection15 
{
	
public:
	virtual HRESULT __safecall Cancel(void) = 0 ;
};

__dispinterface _ConnectionDisp;
typedef System::DelphiInterface<_ConnectionDisp> _di__ConnectionDisp;
__dispinterface INTERFACE_UUID("{00000550-0000-0010-8000-00AA006D2EA4}") _ConnectionDisp  : public IDispatch 
{
	
};

__interface Recordset15;
typedef System::DelphiInterface<Recordset15> _di_Recordset15;
__interface Fields;
typedef System::DelphiInterface<Fields> _di_Fields;
__interface INTERFACE_UUID("{0000050E-0000-0010-8000-00AA006D2EA4}") Recordset15  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_AbsolutePosition(Activex::TOleEnum &Get_AbsolutePosition_result) = 0 ;
	virtual HRESULT __safecall Set_AbsolutePosition(Activex::TOleEnum pl) = 0 ;
	virtual HRESULT __safecall Set_ActiveConnection(const _di_IDispatch pvar) = 0 ;
	virtual HRESULT __safecall _Set_ActiveConnection(const OleVariant pvar) = 0 ;
	virtual HRESULT __safecall Get_ActiveConnection(OleVariant &Get_ActiveConnection_result) = 0 ;
	virtual HRESULT __safecall Get_BOF(Word &Get_BOF_result) = 0 ;
	virtual HRESULT __safecall Get_Bookmark(OleVariant &Get_Bookmark_result) = 0 ;
	virtual HRESULT __safecall Set_Bookmark(const OleVariant pvBookmark) = 0 ;
	virtual HRESULT __safecall Get_CacheSize(int &Get_CacheSize_result) = 0 ;
	virtual HRESULT __safecall Set_CacheSize(int pl) = 0 ;
	virtual HRESULT __safecall Get_CursorType(Activex::TOleEnum &Get_CursorType_result) = 0 ;
	virtual HRESULT __safecall Set_CursorType(Activex::TOleEnum plCursorType) = 0 ;
	virtual HRESULT __safecall Get_EOF(Word &Get_EOF_result) = 0 ;
	virtual HRESULT __safecall Get_Fields(_di_Fields &Get_Fields_result) = 0 ;
	virtual HRESULT __safecall Get_LockType(Activex::TOleEnum &Get_LockType_result) = 0 ;
	virtual HRESULT __safecall Set_LockType(Activex::TOleEnum plLockType) = 0 ;
	virtual HRESULT __safecall Get_MaxRecords(int &Get_MaxRecords_result) = 0 ;
	virtual HRESULT __safecall Set_MaxRecords(int plMaxRecords) = 0 ;
	virtual HRESULT __safecall Get_RecordCount(int &Get_RecordCount_result) = 0 ;
	virtual HRESULT __safecall Set_Source(const _di_IDispatch pvSource) = 0 ;
	virtual HRESULT __safecall _Set_Source(const WideString pvSource) = 0 ;
	virtual HRESULT __safecall Get_Source(OleVariant &Get_Source_result) = 0 ;
	virtual HRESULT __safecall AddNew(const OleVariant FieldList, const OleVariant Values) = 0 ;
	virtual HRESULT __safecall CancelUpdate(void) = 0 ;
	virtual HRESULT __safecall Close(void) = 0 ;
	virtual HRESULT __safecall Delete(Activex::TOleEnum AffectRecords) = 0 ;
	virtual HRESULT __safecall GetRows(int Rows, const OleVariant Start, const OleVariant Fields, OleVariant &GetRows_result) = 0 ;
	virtual HRESULT __safecall Move(int NumRecords, const OleVariant Start) = 0 ;
	virtual HRESULT __safecall MoveNext(void) = 0 ;
	virtual HRESULT __safecall MovePrevious(void) = 0 ;
	virtual HRESULT __safecall MoveFirst(void) = 0 ;
	virtual HRESULT __safecall MoveLast(void) = 0 ;
	virtual HRESULT __safecall Open(const OleVariant Source, const OleVariant ActiveConnection, Activex::TOleEnum CursorType, Activex::TOleEnum LockType, int Options) = 0 ;
	virtual HRESULT __safecall Requery(int Options) = 0 ;
	virtual HRESULT __safecall _xResync(Activex::TOleEnum AffectRecords) = 0 ;
	virtual HRESULT __safecall Update(const OleVariant Fields, const OleVariant Values) = 0 ;
	virtual HRESULT __safecall Get_AbsolutePage(Activex::TOleEnum &Get_AbsolutePage_result) = 0 ;
	virtual HRESULT __safecall Set_AbsolutePage(Activex::TOleEnum pl) = 0 ;
	virtual HRESULT __safecall Get_EditMode(Activex::TOleEnum &Get_EditMode_result) = 0 ;
	virtual HRESULT __safecall Get_Filter(OleVariant &Get_Filter_result) = 0 ;
	virtual HRESULT __safecall Set_Filter(const OleVariant Criteria) = 0 ;
	virtual HRESULT __safecall Get_PageCount(int &Get_PageCount_result) = 0 ;
	virtual HRESULT __safecall Get_PageSize(int &Get_PageSize_result) = 0 ;
	virtual HRESULT __safecall Set_PageSize(int pl) = 0 ;
	virtual HRESULT __safecall Get_Sort(WideString &Get_Sort_result) = 0 ;
	virtual HRESULT __safecall Set_Sort(const WideString Criteria) = 0 ;
	virtual HRESULT __safecall Get_Status(int &Get_Status_result) = 0 ;
	virtual HRESULT __safecall Get_State(int &Get_State_result) = 0 ;
	virtual HRESULT __safecall _xClone(_di__Recordset &_xClone_result) = 0 ;
	virtual HRESULT __safecall UpdateBatch(Activex::TOleEnum AffectRecords) = 0 ;
	virtual HRESULT __safecall CancelBatch(Activex::TOleEnum AffectRecords) = 0 ;
	virtual HRESULT __safecall Get_CursorLocation(Activex::TOleEnum &Get_CursorLocation_result) = 0 ;
	virtual HRESULT __safecall Set_CursorLocation(Activex::TOleEnum plCursorLoc) = 0 ;
	virtual HRESULT __safecall NextRecordset(/* out */ OleVariant &RecordsAffected, _di__Recordset &NextRecordset_result) = 0 ;
	virtual HRESULT __safecall Supports(Activex::TOleEnum CursorOptions, Word &Supports_result) = 0 ;
	virtual HRESULT __safecall Get_Collect(const OleVariant Index, OleVariant &Get_Collect_result) = 0 ;
	virtual HRESULT __safecall Set_Collect(const OleVariant Index, const OleVariant pvar) = 0 ;
	virtual HRESULT __safecall Get_MarshalOptions(Activex::TOleEnum &Get_MarshalOptions_result) = 0 ;
	virtual HRESULT __safecall Set_MarshalOptions(Activex::TOleEnum peMarshal) = 0 ;
	virtual HRESULT __safecall Find(const WideString Criteria, int SkipRecords, Activex::TOleEnum SearchDirection, const OleVariant Start) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_AbsolutePosition() { Activex::TOleEnum r; HRESULT hr = Get_AbsolutePosition(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum AbsolutePosition = {read=_scw_Get_AbsolutePosition, write=Set_AbsolutePosition};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_BOF() { Word r; HRESULT hr = Get_BOF(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word BOF = {read=_scw_Get_BOF};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Bookmark() { OleVariant r; HRESULT hr = Get_Bookmark(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Bookmark = {read=_scw_Get_Bookmark, write=Set_Bookmark};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_CacheSize() { int r; HRESULT hr = Get_CacheSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int CacheSize = {read=_scw_Get_CacheSize, write=Set_CacheSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_CursorType() { Activex::TOleEnum r; HRESULT hr = Get_CursorType(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum CursorType = {read=_scw_Get_CursorType, write=Set_CursorType};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_EOF() { Word r; HRESULT hr = Get_EOF(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Eof = {read=_scw_Get_EOF};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Fields _scw_Get_Fields() { _di_Fields r; HRESULT hr = Get_Fields(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Fields Fields = {read=_scw_Get_Fields};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_LockType() { Activex::TOleEnum r; HRESULT hr = Get_LockType(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum LockType = {read=_scw_Get_LockType, write=Set_LockType};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_MaxRecords() { int r; HRESULT hr = Get_MaxRecords(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int MaxRecords = {read=_scw_Get_MaxRecords, write=Set_MaxRecords};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_RecordCount() { int r; HRESULT hr = Get_RecordCount(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int RecordCount = {read=_scw_Get_RecordCount};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_AbsolutePage() { Activex::TOleEnum r; HRESULT hr = Get_AbsolutePage(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum AbsolutePage = {read=_scw_Get_AbsolutePage, write=Set_AbsolutePage};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_EditMode() { Activex::TOleEnum r; HRESULT hr = Get_EditMode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum EditMode = {read=_scw_Get_EditMode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Filter() { OleVariant r; HRESULT hr = Get_Filter(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Filter = {read=_scw_Get_Filter, write=Set_Filter};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_PageCount() { int r; HRESULT hr = Get_PageCount(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int PageCount = {read=_scw_Get_PageCount};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_PageSize() { int r; HRESULT hr = Get_PageSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int PageSize = {read=_scw_Get_PageSize, write=Set_PageSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Sort() { WideString r; HRESULT hr = Get_Sort(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Sort = {read=_scw_Get_Sort, write=Set_Sort};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Status() { int r; HRESULT hr = Get_Status(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Status = {read=_scw_Get_Status};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_State() { int r; HRESULT hr = Get_State(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int State = {read=_scw_Get_State};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_CursorLocation() { Activex::TOleEnum r; HRESULT hr = Get_CursorLocation(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum CursorLocation = {read=_scw_Get_CursorLocation, write=Set_CursorLocation};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Collect(const OleVariant Index) { OleVariant r; HRESULT hr = Get_Collect(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Collect[OleVariant Index] = {read=_scw_Get_Collect, write=Set_Collect};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_MarshalOptions() { Activex::TOleEnum r; HRESULT hr = Get_MarshalOptions(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum MarshalOptions = {read=_scw_Get_MarshalOptions, write=Set_MarshalOptions};
};

__dispinterface Recordset15Disp;
typedef System::DelphiInterface<Recordset15Disp> _di_Recordset15Disp;
__dispinterface INTERFACE_UUID("{0000050E-0000-0010-8000-00AA006D2EA4}") Recordset15Disp  : public IDispatch 
{
	
};

__interface Recordset20;
typedef System::DelphiInterface<Recordset20> _di_Recordset20;
__interface INTERFACE_UUID("{0000054F-0000-0010-8000-00AA006D2EA4}") Recordset20  : public Recordset15 
{
	
public:
	virtual HRESULT __safecall Cancel(void) = 0 ;
	virtual HRESULT __safecall Get_DataSource(System::_di_IInterface &Get_DataSource_result) = 0 ;
	virtual HRESULT __safecall Set_DataSource(const System::_di_IInterface ppunkDataSource) = 0 ;
	virtual HRESULT __safecall Save(const WideString FileName, Activex::TOleEnum PersistFormat) = 0 ;
	virtual HRESULT __safecall Get_ActiveCommand(_di_IDispatch &Get_ActiveCommand_result) = 0 ;
	virtual HRESULT __safecall Set_StayInSync(Word pbStayInSync) = 0 ;
	virtual HRESULT __safecall Get_StayInSync(Word &Get_StayInSync_result) = 0 ;
	virtual HRESULT __safecall GetString(Activex::TOleEnum StringFormat, int NumRows, const WideString ColumnDelimeter, const WideString RowDelimeter, const WideString NullExpr, WideString &GetString_result) = 0 ;
	virtual HRESULT __safecall Get_DataMember(WideString &Get_DataMember_result) = 0 ;
	virtual HRESULT __safecall Set_DataMember(const WideString pbstrDataMember) = 0 ;
	virtual HRESULT __safecall CompareBookmarks(const OleVariant Bookmark1, const OleVariant Bookmark2, Activex::TOleEnum &CompareBookmarks_result) = 0 ;
	virtual HRESULT __safecall Clone(Activex::TOleEnum LockType, _di__Recordset &Clone_result) = 0 ;
	virtual HRESULT __safecall Resync(Activex::TOleEnum AffectRecords, Activex::TOleEnum ResyncValues) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get_DataSource() { System::_di_IInterface r; HRESULT hr = Get_DataSource(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface DataSource = {read=_scw_Get_DataSource, write=Set_DataSource};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDispatch _scw_Get_ActiveCommand() { _di_IDispatch r; HRESULT hr = Get_ActiveCommand(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDispatch ActiveCommand = {read=_scw_Get_ActiveCommand};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_StayInSync() { Word r; HRESULT hr = Get_StayInSync(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word StayInSync = {read=_scw_Get_StayInSync, write=Set_StayInSync};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DataMember() { WideString r; HRESULT hr = Get_DataMember(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DataMember = {read=_scw_Get_DataMember, write=Set_DataMember};
};

__dispinterface Recordset20Disp;
typedef System::DelphiInterface<Recordset20Disp> _di_Recordset20Disp;
__dispinterface INTERFACE_UUID("{0000054F-0000-0010-8000-00AA006D2EA4}") Recordset20Disp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{00000555-0000-0010-8000-00AA006D2EA4}") _Recordset  : public Recordset20 
{
	
public:
	virtual HRESULT __safecall Seek(const OleVariant KeyValues, Activex::TOleEnum SeekOption) = 0 ;
	virtual HRESULT __safecall Set_Index(const WideString pbstrIndex) = 0 ;
	virtual HRESULT __safecall Get_Index(WideString &Get_Index_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Index() { WideString r; HRESULT hr = Get_Index(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Index = {read=_scw_Get_Index, write=Set_Index};
};

__dispinterface _RecordsetDisp;
typedef System::DelphiInterface<_RecordsetDisp> _di__RecordsetDisp;
__dispinterface INTERFACE_UUID("{00000555-0000-0010-8000-00AA006D2EA4}") _RecordsetDisp  : public IDispatch 
{
	
};

__interface Fields15;
typedef System::DelphiInterface<Fields15> _di_Fields15;
__interface Field;
typedef System::DelphiInterface<Field> _di_Field;
__interface INTERFACE_UUID("{00000506-0000-0010-8000-00AA006D2EA4}") Fields15  : public _Collection 
{
	
public:
	_di_Field operator[](OleVariant Index) { return Item[Index]; }
	
public:
	virtual HRESULT __safecall Get_Item(const OleVariant Index, _di_Field &Get_Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_Field _scw_Get_Item(const OleVariant Index) { _di_Field r; HRESULT hr = Get_Item(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_Field Item[OleVariant Index] = {read=_scw_Get_Item/*, default*/};
};

__dispinterface Fields15Disp;
typedef System::DelphiInterface<Fields15Disp> _di_Fields15Disp;
__dispinterface INTERFACE_UUID("{00000506-0000-0010-8000-00AA006D2EA4}") Fields15Disp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0000054D-0000-0010-8000-00AA006D2EA4}") Fields  : public Fields15 
{
	
public:
	virtual HRESULT __safecall Append(const WideString Name, Activex::TOleEnum Type_, int DefinedSize, Activex::TOleEnum Attrib) = 0 ;
	virtual HRESULT __safecall Delete(const OleVariant Index) = 0 ;
};

__dispinterface FieldsDisp;
typedef System::DelphiInterface<FieldsDisp> _di_FieldsDisp;
__dispinterface INTERFACE_UUID("{0000054D-0000-0010-8000-00AA006D2EA4}") FieldsDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0000054C-0000-0010-8000-00AA006D2EA4}") Field  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_ActualSize(int &Get_ActualSize_result) = 0 ;
	virtual HRESULT __safecall Get_Attributes(int &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall Get_DefinedSize(int &Get_DefinedSize_result) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_Type_(Activex::TOleEnum &Get_Type__result) = 0 ;
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Set_Value(const OleVariant pvar) = 0 ;
	virtual HRESULT __safecall Get_Precision(Byte &Get_Precision_result) = 0 ;
	virtual HRESULT __safecall Get_NumericScale(Byte &Get_NumericScale_result) = 0 ;
	virtual HRESULT __safecall AppendChunk(const OleVariant Data) = 0 ;
	virtual HRESULT __safecall GetChunk(int Length, OleVariant &GetChunk_result) = 0 ;
	virtual HRESULT __safecall Get_OriginalValue(OleVariant &Get_OriginalValue_result) = 0 ;
	virtual HRESULT __safecall Get_UnderlyingValue(OleVariant &Get_UnderlyingValue_result) = 0 ;
	virtual HRESULT __safecall Get_DataFormat(System::_di_IInterface &Get_DataFormat_result) = 0 ;
	virtual HRESULT __safecall Set_DataFormat(const System::_di_IInterface ppiDF) = 0 ;
	virtual HRESULT __safecall Set_Precision(Byte pbPrecision) = 0 ;
	virtual HRESULT __safecall Set_NumericScale(Byte pbNumericScale) = 0 ;
	virtual HRESULT __safecall Set_Type_(Activex::TOleEnum pDataType) = 0 ;
	virtual HRESULT __safecall Set_DefinedSize(int pl) = 0 ;
	virtual HRESULT __safecall Set_Attributes(int pl) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_ActualSize() { int r; HRESULT hr = Get_ActualSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int ActualSize = {read=_scw_Get_ActualSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Attributes() { int r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Attributes = {read=_scw_Get_Attributes, write=Set_Attributes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_DefinedSize() { int r; HRESULT hr = Get_DefinedSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int DefinedSize = {read=_scw_Get_DefinedSize, write=Set_DefinedSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Type_() { Activex::TOleEnum r; HRESULT hr = Get_Type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Type_ = {read=_scw_Get_Type_, write=Set_Type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value, write=Set_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_Precision() { Byte r; HRESULT hr = Get_Precision(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte Precision = {read=_scw_Get_Precision, write=Set_Precision};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_NumericScale() { Byte r; HRESULT hr = Get_NumericScale(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte NumericScale = {read=_scw_Get_NumericScale, write=Set_NumericScale};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_OriginalValue() { OleVariant r; HRESULT hr = Get_OriginalValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant OriginalValue = {read=_scw_Get_OriginalValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_UnderlyingValue() { OleVariant r; HRESULT hr = Get_UnderlyingValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant UnderlyingValue = {read=_scw_Get_UnderlyingValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get_DataFormat() { System::_di_IInterface r; HRESULT hr = Get_DataFormat(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface DataFormat = {read=_scw_Get_DataFormat, write=Set_DataFormat};
};

__dispinterface FieldDisp;
typedef System::DelphiInterface<FieldDisp> _di_FieldDisp;
__dispinterface INTERFACE_UUID("{0000054C-0000-0010-8000-00AA006D2EA4}") FieldDisp  : public IDispatch 
{
	
};

__interface Field15;
typedef System::DelphiInterface<Field15> _di_Field15;
__interface INTERFACE_UUID("{00000505-0000-0010-8000-00AA006D2EA4}") Field15  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_ActualSize(int &Get_ActualSize_result) = 0 ;
	virtual HRESULT __safecall Get_Attributes(int &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall Get_DefinedSize(int &Get_DefinedSize_result) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_Type_(Activex::TOleEnum &Get_Type__result) = 0 ;
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Set_Value(const OleVariant pvar) = 0 ;
	virtual HRESULT __safecall Get_Precision(Byte &Get_Precision_result) = 0 ;
	virtual HRESULT __safecall Get_NumericScale(Byte &Get_NumericScale_result) = 0 ;
	virtual HRESULT __safecall AppendChunk(const OleVariant Data) = 0 ;
	virtual HRESULT __safecall GetChunk(int Length, OleVariant &GetChunk_result) = 0 ;
	virtual HRESULT __safecall Get_OriginalValue(OleVariant &Get_OriginalValue_result) = 0 ;
	virtual HRESULT __safecall Get_UnderlyingValue(OleVariant &Get_UnderlyingValue_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_ActualSize() { int r; HRESULT hr = Get_ActualSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int ActualSize = {read=_scw_Get_ActualSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Attributes() { int r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Attributes = {read=_scw_Get_Attributes};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_DefinedSize() { int r; HRESULT hr = Get_DefinedSize(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int DefinedSize = {read=_scw_Get_DefinedSize};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Type_() { Activex::TOleEnum r; HRESULT hr = Get_Type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Type_ = {read=_scw_Get_Type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value, write=Set_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_Precision() { Byte r; HRESULT hr = Get_Precision(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte Precision = {read=_scw_Get_Precision};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_NumericScale() { Byte r; HRESULT hr = Get_NumericScale(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte NumericScale = {read=_scw_Get_NumericScale};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_OriginalValue() { OleVariant r; HRESULT hr = Get_OriginalValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant OriginalValue = {read=_scw_Get_OriginalValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_UnderlyingValue() { OleVariant r; HRESULT hr = Get_UnderlyingValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant UnderlyingValue = {read=_scw_Get_UnderlyingValue};
};

__dispinterface Field15Disp;
typedef System::DelphiInterface<Field15Disp> _di_Field15Disp;
__dispinterface INTERFACE_UUID("{00000505-0000-0010-8000-00AA006D2EA4}") Field15Disp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0000050C-0000-0010-8000-00AA006D2EA4}") _Parameter  : public _ADO 
{
	
public:
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Set_Name(const WideString pbstr) = 0 ;
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Set_Value(const OleVariant pvar) = 0 ;
	virtual HRESULT __safecall Get_Type_(Activex::TOleEnum &Get_Type__result) = 0 ;
	virtual HRESULT __safecall Set_Type_(Activex::TOleEnum psDataType) = 0 ;
	virtual HRESULT __safecall Set_Direction(Activex::TOleEnum plParmDirection) = 0 ;
	virtual HRESULT __safecall Get_Direction(Activex::TOleEnum &Get_Direction_result) = 0 ;
	virtual HRESULT __safecall Set_Precision(Byte pbPrecision) = 0 ;
	virtual HRESULT __safecall Get_Precision(Byte &Get_Precision_result) = 0 ;
	virtual HRESULT __safecall Set_NumericScale(Byte pbScale) = 0 ;
	virtual HRESULT __safecall Get_NumericScale(Byte &Get_NumericScale_result) = 0 ;
	virtual HRESULT __safecall Set_Size(int pl) = 0 ;
	virtual HRESULT __safecall Get_Size(int &Get_Size_result) = 0 ;
	virtual HRESULT __safecall AppendChunk(const OleVariant Val) = 0 ;
	virtual HRESULT __safecall Get_Attributes(int &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall Set_Attributes(int plParmAttribs) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name, write=Set_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value, write=Set_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Type_() { Activex::TOleEnum r; HRESULT hr = Get_Type_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Type_ = {read=_scw_Get_Type_, write=Set_Type_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Direction() { Activex::TOleEnum r; HRESULT hr = Get_Direction(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Direction = {read=_scw_Get_Direction, write=Set_Direction};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_Precision() { Byte r; HRESULT hr = Get_Precision(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte Precision = {read=_scw_Get_Precision, write=Set_Precision};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Byte _scw_Get_NumericScale() { Byte r; HRESULT hr = Get_NumericScale(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Byte NumericScale = {read=_scw_Get_NumericScale, write=Set_NumericScale};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Size() { int r; HRESULT hr = Get_Size(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Size = {read=_scw_Get_Size, write=Set_Size};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Attributes() { int r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Attributes = {read=_scw_Get_Attributes, write=Set_Attributes};
};

__dispinterface _ParameterDisp;
typedef System::DelphiInterface<_ParameterDisp> _di__ParameterDisp;
__dispinterface INTERFACE_UUID("{0000050C-0000-0010-8000-00AA006D2EA4}") _ParameterDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0000050D-0000-0010-8000-00AA006D2EA4}") Parameters  : public _DynaCollection 
{
	
public:
	_di__Parameter operator[](OleVariant Index) { return Item[Index]; }
	
public:
	virtual HRESULT __safecall Get_Item(const OleVariant Index, _di__Parameter &Get_Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di__Parameter _scw_Get_Item(const OleVariant Index) { _di__Parameter r; HRESULT hr = Get_Item(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di__Parameter Item[OleVariant Index] = {read=_scw_Get_Item/*, default*/};
};

__dispinterface ParametersDisp;
typedef System::DelphiInterface<ParametersDisp> _di_ParametersDisp;
__dispinterface INTERFACE_UUID("{0000050D-0000-0010-8000-00AA006D2EA4}") ParametersDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0000054E-0000-0010-8000-00AA006D2EA4}") _Command  : public Command15 
{
	
public:
	virtual HRESULT __safecall Get_State(int &Get_State_result) = 0 ;
	virtual HRESULT __safecall Cancel(void) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_State() { int r; HRESULT hr = Get_State(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int State = {read=_scw_Get_State};
};

__dispinterface _CommandDisp;
typedef System::DelphiInterface<_CommandDisp> _di__CommandDisp;
__dispinterface INTERFACE_UUID("{0000054E-0000-0010-8000-00AA006D2EA4}") _CommandDisp  : public IDispatch 
{
	
};

__interface ConnectionEventsVt;
typedef System::DelphiInterface<ConnectionEventsVt> _di_ConnectionEventsVt;
__interface INTERFACE_UUID("{00000402-0000-0010-8000-00AA006D2EA4}") ConnectionEventsVt  : public IInterface 
{
	
public:
	virtual HRESULT __safecall InfoMessage(const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall BeginTransComplete(int TransactionLevel, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall CommitTransComplete(const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall RollbackTransComplete(const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall WillExecute(WideString &Source, Activex::TOleEnum &CursorType, Activex::TOleEnum &LockType, int &Options, Activex::TOleEnum &adStatus, const _di__Command pCommand, const _di__Recordset pRecordset, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall ExecuteComplete(int RecordsAffected, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Command pCommand, const _di__Recordset pRecordset, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall WillConnect(WideString &ConnectionString, WideString &UserID, WideString &Password, int &Options, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall ConnectComplete(const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
	virtual HRESULT __safecall Disconnect(Activex::TOleEnum &adStatus, const _di__Connection pConnection) = 0 ;
};

__interface RecordsetEventsVt;
typedef System::DelphiInterface<RecordsetEventsVt> _di_RecordsetEventsVt;
__interface INTERFACE_UUID("{00000403-0000-0010-8000-00AA006D2EA4}") RecordsetEventsVt  : public IInterface 
{
	
public:
	virtual HRESULT __safecall WillChangeField(int cFields, const OleVariant Fields, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall FieldChangeComplete(int cFields, const OleVariant Fields, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall WillChangeRecord(Activex::TOleEnum adReason, int cRecords, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall RecordChangeComplete(Activex::TOleEnum adReason, int cRecords, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall WillChangeRecordset(Activex::TOleEnum adReason, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall RecordsetChangeComplete(Activex::TOleEnum adReason, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall WillMove(Activex::TOleEnum adReason, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall MoveComplete(Activex::TOleEnum adReason, const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall EndOfRecordset(Word &fMoreData, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall FetchProgress(int Progress, int MaxProgress, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
	virtual HRESULT __safecall FetchComplete(const _di_Error pError, Activex::TOleEnum &adStatus, const _di__Recordset pRecordset) = 0 ;
};

__dispinterface ConnectionEvents;
typedef System::DelphiInterface<ConnectionEvents> _di_ConnectionEvents;
__dispinterface INTERFACE_UUID("{00000400-0000-0010-8000-00AA006D2EA4}") ConnectionEvents  : public IDispatch 
{
	
};

__dispinterface RecordsetEvents;
typedef System::DelphiInterface<RecordsetEvents> _di_RecordsetEvents;
__dispinterface INTERFACE_UUID("{00000266-0000-0010-8000-00AA006D2EA4}") RecordsetEvents  : public IDispatch 
{
	
};

__interface ADOConnectionConstruction15;
typedef System::DelphiInterface<ADOConnectionConstruction15> _di_ADOConnectionConstruction15;
__interface INTERFACE_UUID("{00000516-0000-0010-8000-00AA006D2EA4}") ADOConnectionConstruction15  : public IInterface 
{
	
public:
	virtual HRESULT __safecall Get_DSO(System::_di_IInterface &Get_DSO_result) = 0 ;
	virtual HRESULT __safecall Get_Session(System::_di_IInterface &Get_Session_result) = 0 ;
	virtual HRESULT __safecall WrapDSOandSession(const System::_di_IInterface pDSO, const System::_di_IInterface pSession) = 0 ;
};

__interface ADOConnectionConstruction;
typedef System::DelphiInterface<ADOConnectionConstruction> _di_ADOConnectionConstruction;
__interface INTERFACE_UUID("{00000551-0000-0010-8000-00AA006D2EA4}") ADOConnectionConstruction  : public ADOConnectionConstruction15 
{
	
};

__interface ADOCommandConstruction;
typedef System::DelphiInterface<ADOCommandConstruction> _di_ADOCommandConstruction;
__interface INTERFACE_UUID("{00000517-0000-0010-8000-00AA006D2EA4}") ADOCommandConstruction  : public IInterface 
{
	
public:
	virtual HRESULT __safecall Get_OLEDBCommand(System::_di_IInterface &Get_OLEDBCommand_result) = 0 ;
	virtual HRESULT __safecall Set_OLEDBCommand(const System::_di_IInterface ppOLEDBCommand) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get_OLEDBCommand() { System::_di_IInterface r; HRESULT hr = Get_OLEDBCommand(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface OLEDBCommand = {read=_scw_Get_OLEDBCommand, write=Set_OLEDBCommand};
};

__interface ADORecordsetConstruction;
typedef System::DelphiInterface<ADORecordsetConstruction> _di_ADORecordsetConstruction;
__interface INTERFACE_UUID("{00000283-0000-0010-8000-00AA006D2EA4}") ADORecordsetConstruction  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Rowset(System::_di_IInterface &Get_Rowset_result) = 0 ;
	virtual HRESULT __safecall Set_Rowset(const System::_di_IInterface ppRowset) = 0 ;
	virtual HRESULT __safecall Get_Chapter(int &Get_Chapter_result) = 0 ;
	virtual HRESULT __safecall Set_Chapter(int plChapter) = 0 ;
	virtual HRESULT __safecall Get_RowPosition(System::_di_IInterface &Get_RowPosition_result) = 0 ;
	virtual HRESULT __safecall Set_RowPosition(const System::_di_IInterface ppRowPos) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get_Rowset() { System::_di_IInterface r; HRESULT hr = Get_Rowset(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface Rowset = {read=_scw_Get_Rowset, write=Set_Rowset};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Chapter() { int r; HRESULT hr = Get_Chapter(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Chapter = {read=_scw_Get_Chapter, write=Set_Chapter};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get_RowPosition() { System::_di_IInterface r; HRESULT hr = Get_RowPosition(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface RowPosition = {read=_scw_Get_RowPosition, write=Set_RowPosition};
};

__interface INTERFACE_UUID("{BD96C556-65A3-11D0-983A-00C04FC29E34}") IDataspace  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall CreateObject(const WideString bstrProgid, const WideString bstrConnection, OleVariant &CreateObject_result) = 0 ;
	virtual HRESULT __safecall Get_InternetTimeout(int &Get_InternetTimeout_result) = 0 ;
	virtual HRESULT __safecall Set_InternetTimeout(int plInetTimeout) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_InternetTimeout() { int r; HRESULT hr = Get_InternetTimeout(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int InternetTimeout = {read=_scw_Get_InternetTimeout, write=Set_InternetTimeout};
};

__dispinterface IDataspaceDisp;
typedef System::DelphiInterface<IDataspaceDisp> _di_IDataspaceDisp;
__dispinterface INTERFACE_UUID("{BD96C556-65A3-11D0-983A-00C04FC29E34}") IDataspaceDisp  : public IDispatch 
{
	
};

class DELPHICLASS CoConnection;
class PASCALIMPLEMENTATION CoConnection : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di__Connection __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di__Connection __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoConnection(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoCommand;
class PASCALIMPLEMENTATION CoCommand : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di__Command __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di__Command __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCommand(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCommand(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoRecordset;
class PASCALIMPLEMENTATION CoRecordset : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di__Recordset __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di__Recordset __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoRecordset(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoRecordset(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoParameter;
class PASCALIMPLEMENTATION CoParameter : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di__Parameter __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di__Parameter __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoParameter(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoParameter(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID LIBID_ADODB;
extern PACKAGE GUID CLASS_Connection;
extern PACKAGE GUID CLASS_Command;
extern PACKAGE GUID CLASS_Recordset;
extern PACKAGE GUID CLASS_Parameter;
extern PACKAGE GUID CLASS_DataSpace;
extern PACKAGE GUID CLASS_DataFactory;
extern PACKAGE GUID IID__Collection;
extern PACKAGE GUID IID__DynaCollection;
extern PACKAGE GUID IID__ADO;
extern PACKAGE GUID IID_Properties;
extern PACKAGE GUID IID_Property_;
extern PACKAGE GUID IID_Error;
extern PACKAGE GUID IID_Errors;
extern PACKAGE GUID IID_Command15;
extern PACKAGE GUID IID_Connection15;
extern PACKAGE GUID IID__Connection;
extern PACKAGE GUID IID_Recordset15;
extern PACKAGE GUID IID_Recordset20;
extern PACKAGE GUID IID__Recordset;
extern PACKAGE GUID IID_Fields15;
extern PACKAGE GUID IID_Fields;
extern PACKAGE GUID IID_Field;
extern PACKAGE GUID IID__Parameter;
extern PACKAGE GUID IID_Parameters;
extern PACKAGE GUID IID__Command;
extern PACKAGE GUID IID_ConnectionEventsVt;
extern PACKAGE GUID DIID_ConnectionEvents;
extern PACKAGE GUID IID_RecordsetEventsVt;
extern PACKAGE GUID DIID_RecordsetEvents;
extern PACKAGE GUID IID_ADOConnectionConstruction15;
extern PACKAGE GUID IID_ADOConnectionConstruction;
extern PACKAGE GUID IID_ADOCommandConstruction;
extern PACKAGE GUID IID_ADORecordsetConstruction;
extern PACKAGE GUID IID_Field15;
extern PACKAGE GUID IID_IDataspace;
#define CT_USERID "USER ID="
#define CT_PROVIDER "PROVIDER="
#define CT_FILENAME "FILE NAME="

}	/* namespace Adoint */
using namespace Adoint;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ADOInt
