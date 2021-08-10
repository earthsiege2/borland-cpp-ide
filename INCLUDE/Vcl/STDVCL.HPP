// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdVCL.pas' rev: 5.00

#ifndef StdVCLHPP
#define StdVCLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
// The following was extracted from OAIDL.H and brought in here to avoid bringing
// in OAIDL.H itself. It was conveniently guarded in the said header, which makes
// it ideal to be plucked out and replicated.
// 
#ifndef __IDispatch_INTERFACE_DEFINED__
#define __IDispatch_INTERFACE_DEFINED__

// Forward ref. OLE structures
struct    tagDISPPARAMS;
struct    tagEXCEPINFO;

// OAIDL.H would have declared DISPID as a typedef of a LONG but we don
// assume it has been included. Hence, we use a macro
//
#define DISPID LONG

/****************************************
 * Generated header for interface: IDispatch
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IDispatch __RPC_FAR *LPDISPATCH;

/* DISPID reserved to indicate an "unknown" name */
/* only reserved for data members (properties); reused as a method dispid below */
#define DISPID_UNKNOWN  ( -1 )

/* DISPID reserved for the "value" property */
#define DISPID_VALUE  ( 0 )

/* The following DISPID is reserved to indicate the param
 * that is the right-hand-side (or "put" value) of a PropertyPut
 */
#define DISPID_PROPERTYPUT  ( -3 )

/* DISPID reserved for the standard "NewEnum" method */
#define DISPID_NEWENUM  ( -4 )

/* DISPID reserved for the standard "Evaluate" method */
#define DISPID_EVALUATE ( -5 )

#define DISPID_CONSTRUCTOR  ( -6 )

#define DISPID_DESTRUCTOR ( -7 )

#define DISPID_COLLECT  ( -8 )

/* The range -500 through -999 is reserved for Controls */
/* The range 0x80010000 through 0x8001FFFF is reserved for Controls */
/* The range -5000 through -5499 is reserved for ActiveX Accessability */
/* The remainder of the negative DISPIDs are reserved for future use */

EXTERN_C const IID IID_IDispatch;

    
    interface IDispatch : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount( 
            /* [out] */ UINT __RPC_FAR *pctinfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeInfo( 
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames( 
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ tagDISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ tagVARIANT __RPC_FAR *pVarResult,
            /* [out] */ tagEXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr) = 0;
    };
    

HRESULT STDMETHODCALLTYPE IDispatch_GetTypeInfoCount_Proxy( 
    IDispatch __RPC_FAR * This,
    /* [out] */ UINT __RPC_FAR *pctinfo);

void __RPC_STUB IDispatch_GetTypeInfoCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

HRESULT STDMETHODCALLTYPE IDispatch_GetTypeInfo_Proxy( 
    IDispatch __RPC_FAR * This,
    /* [in] */ UINT iTInfo,
    /* [in] */ LCID lcid,
    /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

void __RPC_STUB IDispatch_GetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

HRESULT STDMETHODCALLTYPE IDispatch_GetIDsOfNames_Proxy( 
    IDispatch __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
    /* [in] */ UINT cNames,
    /* [in] */ LCID lcid,
    /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

void __RPC_STUB IDispatch_GetIDsOfNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

/* [call_as] */ HRESULT STDMETHODCALLTYPE IDispatch_RemoteInvoke_Proxy( 
    IDispatch __RPC_FAR * This,
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ DWORD dwFlags,
    /* [in] */ tagDISPPARAMS __RPC_FAR *pDispParams,
    /* [out] */ tagVARIANT __RPC_FAR *pVarResult,
    /* [out] */ tagEXCEPINFO __RPC_FAR *pExcepInfo,
    /* [out] */ UINT __RPC_FAR *pArgErr,
    /* [in] */ UINT cVarRef,
    /* [size_is][in] */ UINT __RPC_FAR *rgVarRefIdx,
    /* [size_is][out][in] */ tagVARIANT __RPC_FAR *rgVarRef);


void __RPC_STUB IDispatch_RemoteInvoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

// Remove DISPID macro defined if OAIDL was not included
//
#if defined(DISPID)
#undef DISPID
#endif

#endif  /* __IDispatch_INTERFACE_DEFINED__ */


namespace Stdvcl
{
//-- type declarations -------------------------------------------------------
__interface IProvider;
typedef System::DelphiInterface<IProvider> _di_IProvider;
__interface INTERFACE_UUID("{6E644935-51F7-11D0-8D41-00A0248E4B9A}") IProvider  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Data(OleVariant &Get_Data_result) = 0 ;
	virtual HRESULT __safecall ApplyUpdates(const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount
		, OleVariant &ApplyUpdates_result) = 0 ;
	virtual HRESULT __safecall GetMetaData(OleVariant &GetMetaData_result) = 0 ;
	virtual HRESULT __safecall GetRecords(int Count, /* out */ int &RecsOut, OleVariant &GetRecords_result
		) = 0 ;
	virtual HRESULT __safecall DataRequest(const OleVariant Input, OleVariant &DataRequest_result) = 0 
		;
	virtual HRESULT __safecall Get_Constraints(Word &Get_Constraints_result) = 0 ;
	virtual HRESULT __safecall Set_Constraints(Word Value) = 0 ;
	virtual HRESULT __safecall Reset(Word MetaData) = 0 ;
	virtual HRESULT __safecall SetParams(const OleVariant Values) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Data() { OleVariant r; HRESULT hr = Get_Data(r); System::CheckSafecallResult(hr); return r; }
		
	#pragma option pop
	__property OleVariant Data = {read=_scw_Get_Data};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Constraints() { Word r; HRESULT hr = Get_Constraints(r); System::CheckSafecallResult(hr); return r; }
		
	#pragma option pop
	__property Word Constraints = {read=_scw_Get_Constraints, write=Set_Constraints};
};

__dispinterface IProviderDisp;
typedef System::DelphiInterface<IProviderDisp> _di_IProviderDisp;
__dispinterface INTERFACE_UUID("{6E644935-51F7-11D0-8D41-00A0248E4B9A}") IProviderDisp  : public IDispatch 
	
{
	
};

__interface IStrings;
typedef System::DelphiInterface<IStrings> _di_IStrings;
__interface INTERFACE_UUID("{EE05DFE2-5549-11D0-9EA9-0020AF3D82DA}") IStrings  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_ControlDefault(int Index, OleVariant &Get_ControlDefault_result) = 0 
		;
	virtual HRESULT __safecall Set_ControlDefault(int Index, const OleVariant Value) = 0 ;
	virtual HRESULT __safecall Count(int &Count_result) = 0 ;
	virtual HRESULT __safecall Get_Item(int Index, OleVariant &Get_Item_result) = 0 ;
	virtual HRESULT __safecall Set_Item(int Index, const OleVariant Value) = 0 ;
	virtual HRESULT __safecall Remove(int Index) = 0 ;
	virtual HRESULT __safecall Clear(void) = 0 ;
	virtual HRESULT __safecall Add(const OleVariant Item, int &Add_result) = 0 ;
	virtual HRESULT __safecall _NewEnum(_di_IUnknown &_NewEnum_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_ControlDefault(int Index) { OleVariant r; HRESULT hr = Get_ControlDefault(
		Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant ControlDefault[int Index] = {read=_scw_Get_ControlDefault, write=Set_ControlDefault
		/*, default*/};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Item(int Index) { OleVariant r; HRESULT hr = Get_Item(
		Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Item[int Index] = {read=_scw_Get_Item, write=Set_Item};
};

__dispinterface IStringsDisp;
typedef System::DelphiInterface<IStringsDisp> _di_IStringsDisp;
__dispinterface INTERFACE_UUID("{EE05DFE2-5549-11D0-9EA9-0020AF3D82DA}") IStringsDisp  : public IDispatch 
	
{
	
};

__interface IDataBroker;
typedef System::DelphiInterface<IDataBroker> _di_IDataBroker;
__interface INTERFACE_UUID("{6539BF65-6FE7-11D0-9E8C-00A02457621F}") IDataBroker  : public IDispatch 
	
{
	
public:
	virtual HRESULT __safecall GetProviderNames(OleVariant &GetProviderNames_result) = 0 ;
};

__dispinterface IDataBrokerDisp;
typedef System::DelphiInterface<IDataBrokerDisp> _di_IDataBrokerDisp;
__dispinterface INTERFACE_UUID("{6539BF65-6FE7-11D0-9E8C-00A02457621F}") IDataBrokerDisp  : public IDispatch 
	
{
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID LIBID_StdVCL;
extern PACKAGE GUID IID_IProvider;
extern PACKAGE GUID IID_IStrings;
extern PACKAGE GUID IID_IDataBroker;

}	/* namespace Stdvcl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Stdvcl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdVCL
