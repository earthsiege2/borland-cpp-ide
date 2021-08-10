#pragma option push -b -a8 -pc -A- /*P_O_Push_S*/
/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Sat Nov 08 05:10:46 1997
 */
/* Compiler settings for mtxspm.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __mtxspm_h__
#define __mtxspm_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISharedProperty_FWD_DEFINED__
#define __ISharedProperty_FWD_DEFINED__
typedef interface ISharedProperty ISharedProperty;
#endif 	/* __ISharedProperty_FWD_DEFINED__ */


#ifndef __ISharedPropertyGroup_FWD_DEFINED__
#define __ISharedPropertyGroup_FWD_DEFINED__
typedef interface ISharedPropertyGroup ISharedPropertyGroup;
#endif 	/* __ISharedPropertyGroup_FWD_DEFINED__ */


#ifndef __ISharedPropertyGroupManager_FWD_DEFINED__
#define __ISharedPropertyGroupManager_FWD_DEFINED__
typedef interface ISharedPropertyGroupManager ISharedPropertyGroupManager;
#endif 	/* __ISharedPropertyGroupManager_FWD_DEFINED__ */


#ifndef __SharedProperty_FWD_DEFINED__
#define __SharedProperty_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedProperty SharedProperty;
#else
typedef struct SharedProperty SharedProperty;
#endif /* __cplusplus */

#endif 	/* __SharedProperty_FWD_DEFINED__ */


#ifndef __SharedPropertyGroup_FWD_DEFINED__
#define __SharedPropertyGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedPropertyGroup SharedPropertyGroup;
#else
typedef struct SharedPropertyGroup SharedPropertyGroup;
#endif /* __cplusplus */

#endif 	/* __SharedPropertyGroup_FWD_DEFINED__ */


#ifndef __SharedPropertyGroupManager_FWD_DEFINED__
#define __SharedPropertyGroupManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedPropertyGroupManager SharedPropertyGroupManager;
#else
typedef struct SharedPropertyGroupManager SharedPropertyGroupManager;
#endif /* __cplusplus */

#endif 	/* __SharedPropertyGroupManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_mtxspm_0000
 * at Sat Nov 08 05:10:46 1997
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


// -----------------------------------------------------------------------	
// mtxspm.h  -- Microsoft Transaction Server SPM Interfaces					
//																			
// This file provides the COM interfaces for the Microsoft Transaction		
// Server Shared Property Manager.											
//																			
// Microsoft Transaction Server 2.0											
// Copyright (c) 1996-1997 Microsoft Corporation.  All Rights Reserved.		
// -----------------------------------------------------------------------	


extern RPC_IF_HANDLE __MIDL_itf_mtxspm_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mtxspm_0000_v0_0_s_ifspec;

#ifndef __ISharedProperty_INTERFACE_DEFINED__
#define __ISharedProperty_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedProperty
 * at Sat Nov 08 05:10:46 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("2A005C01-A5DE-11CF-9E66-00AA00A3F464")
    ISharedProperty : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISharedProperty __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISharedProperty __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISharedProperty __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISharedProperty __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISharedProperty __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISharedProperty __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISharedProperty __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            ISharedProperty __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            ISharedProperty __RPC_FAR * This,
            /* [in] */ VARIANT val);
        
        END_INTERFACE
    } ISharedPropertyVtbl;

    interface ISharedProperty
    {
        CONST_VTBL struct ISharedPropertyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedProperty_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedProperty_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define ISharedProperty_put_Value(This,val)	\
    (This)->lpVtbl -> put_Value(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE ISharedProperty_get_Value_Proxy( 
    ISharedProperty __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB ISharedProperty_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE ISharedProperty_put_Value_Proxy( 
    ISharedProperty __RPC_FAR * This,
    /* [in] */ VARIANT val);


void __RPC_STUB ISharedProperty_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISharedProperty_INTERFACE_DEFINED__ */


#ifndef __ISharedPropertyGroup_INTERFACE_DEFINED__
#define __ISharedPropertyGroup_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedPropertyGroup
 * at Sat Nov 08 05:10:46 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedPropertyGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("2A005C07-A5DE-11CF-9E66-00AA00A3F464")
    ISharedPropertyGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE CreatePropertyByPosition( 
            /* [in] */ int Index,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyByPosition( 
            /* [in] */ int Index,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE CreateProperty( 
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISharedPropertyGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISharedPropertyGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePropertyByPosition )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ int Index,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertyByPosition )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ int Index,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateProperty )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            ISharedPropertyGroup __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty);
        
        END_INTERFACE
    } ISharedPropertyGroupVtbl;

    interface ISharedPropertyGroup
    {
        CONST_VTBL struct ISharedPropertyGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedPropertyGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedPropertyGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedPropertyGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedPropertyGroup_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedPropertyGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedPropertyGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedPropertyGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedPropertyGroup_CreatePropertyByPosition(This,Index,fExists,ppProp)	\
    (This)->lpVtbl -> CreatePropertyByPosition(This,Index,fExists,ppProp)

#define ISharedPropertyGroup_get_PropertyByPosition(This,Index,ppProperty)	\
    (This)->lpVtbl -> get_PropertyByPosition(This,Index,ppProperty)

#define ISharedPropertyGroup_CreateProperty(This,Name,fExists,ppProp)	\
    (This)->lpVtbl -> CreateProperty(This,Name,fExists,ppProp)

#define ISharedPropertyGroup_get_Property(This,Name,ppProperty)	\
    (This)->lpVtbl -> get_Property(This,Name,ppProperty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroup_CreatePropertyByPosition_Proxy( 
    ISharedPropertyGroup __RPC_FAR * This,
    /* [in] */ int Index,
    /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
    /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp);


void __RPC_STUB ISharedPropertyGroup_CreatePropertyByPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroup_get_PropertyByPosition_Proxy( 
    ISharedPropertyGroup __RPC_FAR * This,
    /* [in] */ int Index,
    /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty);


void __RPC_STUB ISharedPropertyGroup_get_PropertyByPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroup_CreateProperty_Proxy( 
    ISharedPropertyGroup __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
    /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProp);


void __RPC_STUB ISharedPropertyGroup_CreateProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroup_get_Property_Proxy( 
    ISharedPropertyGroup __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ ISharedProperty __RPC_FAR *__RPC_FAR *ppProperty);


void __RPC_STUB ISharedPropertyGroup_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISharedPropertyGroup_INTERFACE_DEFINED__ */


#ifndef __ISharedPropertyGroupManager_INTERFACE_DEFINED__
#define __ISharedPropertyGroupManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedPropertyGroupManager
 * at Sat Nov 08 05:10:46 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedPropertyGroupManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("2A005C0D-A5DE-11CF-9E66-00AA00A3F464")
    ISharedPropertyGroupManager : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE CreatePropertyGroup( 
            /* [in] */ BSTR Name,
            /* [out][in] */ LONG __RPC_FAR *dwIsoMode,
            /* [out][in] */ LONG __RPC_FAR *dwRelMode,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring][helpcontext][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyGroupManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISharedPropertyGroupManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISharedPropertyGroupManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePropertyGroup )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ LONG __RPC_FAR *dwIsoMode,
            /* [out][in] */ LONG __RPC_FAR *dwRelMode,
            /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
            /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Group )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring][helpcontext][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            ISharedPropertyGroupManager __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *retval);
        
        END_INTERFACE
    } ISharedPropertyGroupManagerVtbl;

    interface ISharedPropertyGroupManager
    {
        CONST_VTBL struct ISharedPropertyGroupManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedPropertyGroupManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedPropertyGroupManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedPropertyGroupManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedPropertyGroupManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedPropertyGroupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedPropertyGroupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedPropertyGroupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedPropertyGroupManager_CreatePropertyGroup(This,Name,dwIsoMode,dwRelMode,fExists,ppGroup)	\
    (This)->lpVtbl -> CreatePropertyGroup(This,Name,dwIsoMode,dwRelMode,fExists,ppGroup)

#define ISharedPropertyGroupManager_get_Group(This,Name,ppGroup)	\
    (This)->lpVtbl -> get_Group(This,Name,ppGroup)

#define ISharedPropertyGroupManager_get__NewEnum(This,retval)	\
    (This)->lpVtbl -> get__NewEnum(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroupManager_CreatePropertyGroup_Proxy( 
    ISharedPropertyGroupManager __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ LONG __RPC_FAR *dwIsoMode,
    /* [out][in] */ LONG __RPC_FAR *dwRelMode,
    /* [out] */ VARIANT_BOOL __RPC_FAR *fExists,
    /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB ISharedPropertyGroupManager_CreatePropertyGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroupManager_get_Group_Proxy( 
    ISharedPropertyGroupManager __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ ISharedPropertyGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB ISharedPropertyGroupManager_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE ISharedPropertyGroupManager_get__NewEnum_Proxy( 
    ISharedPropertyGroupManager __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *retval);


void __RPC_STUB ISharedPropertyGroupManager_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISharedPropertyGroupManager_INTERFACE_DEFINED__ */



#ifndef __MTxSpm_LIBRARY_DEFINED__
#define __MTxSpm_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: MTxSpm
 * at Sat Nov 08 05:10:46 1997
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][helpfile][version][uuid] */ 


typedef /* [public] */ 
enum __MIDL___MIDL_itf_mtxspm_0098_0001
    {	LockSetGet	= 0,
	LockMethod	= LockSetGet + 1
    }	LockModes;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_mtxspm_0098_0002
    {	Standard	= 0,
	Process	= Standard + 1
    }	ReleaseModes;


EXTERN_C const IID LIBID_MTxSpm;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedProperty;

class DECLSPEC_UUID("2A005C05-A5DE-11CF-9E66-00AA00A3F464")
SharedProperty;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedPropertyGroup;

class DECLSPEC_UUID("2A005C0B-A5DE-11CF-9E66-00AA00A3F464")
SharedPropertyGroup;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedPropertyGroupManager;

class DECLSPEC_UUID("2A005C11-A5DE-11CF-9E66-00AA00A3F464")
SharedPropertyGroupManager;
#endif
#endif /* __MTxSpm_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma option pop /*P_O_Pop*/
