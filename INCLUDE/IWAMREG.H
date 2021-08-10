#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Sep 01 16:14:37 1999
 */
/* Compiler settings for .\wamreg.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __iwamreg_h__
#define __iwamreg_h__

/* Forward Declarations */ 

#ifndef __IWamAdmin_FWD_DEFINED__
#define __IWamAdmin_FWD_DEFINED__
typedef interface IWamAdmin IWamAdmin;
#endif 	/* __IWamAdmin_FWD_DEFINED__ */


#ifndef __IWamAdmin2_FWD_DEFINED__
#define __IWamAdmin2_FWD_DEFINED__
typedef interface IWamAdmin2 IWamAdmin2;
#endif 	/* __IWamAdmin2_FWD_DEFINED__ */


#ifndef __WamAdmin_FWD_DEFINED__
#define __WamAdmin_FWD_DEFINED__

#ifdef __cplusplus
typedef class WamAdmin WamAdmin;
#else
typedef struct WamAdmin WamAdmin;
#endif /* __cplusplus */

#endif 	/* __WamAdmin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_wamreg_0000 */
/* [local] */ 

/*++
                                                                                
Copyright (c) 1997-1999 Microsoft Corporation
                                                                                
Module Name: iwamreg.h
                                                                                
    WAM (Web Application Manager) Interfaces
                                                                                
--*/
#ifndef __WAMREG_IADM__IID
#define __WAMREG_IADM__IID
DEFINE_GUID(IID_IWamAdmin, 0x29822AB7, 0xF302, 0x11D0, 0x99, 0x53, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0xC1);
DEFINE_GUID(IID_IWamAdmin2, 0x29822AB8, 0xF302, 0x11D0, 0x99, 0x53, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0xC1);
DEFINE_GUID(LIBID_WAMREGLib, 0x29822AA8, 0xF302, 0x11D0, 0x99, 0x53, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0xC1);
DEFINE_GUID(CLSID_WamAdmin, 0x61738644, 0xF196, 0x11D0, 0x99, 0x53, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0xC1);
#endif //__WAMREG_IADM__IID
#define APPSTATUS_STOPPED	0
#define APPSTATUS_RUNNING	1
#define APPSTATUS_NOTDEFINED	2
typedef /* [public] */ 
enum __MIDL___MIDL_itf_wamreg_0000_0001
    {	eAppRunInProc	= 0,
	eAppRunOutProcIsolated	= eAppRunInProc + 1,
	eAppRunOutProcInDefaultPool	= eAppRunOutProcIsolated + 1
    }	EAppMode;



extern RPC_IF_HANDLE __MIDL_itf_wamreg_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wamreg_0000_v0_0_s_ifspec;

#ifndef __IWamAdmin_INTERFACE_DEFINED__
#define __IWamAdmin_INTERFACE_DEFINED__

/* interface IWamAdmin */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IWamAdmin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29822AB7-F302-11D0-9953-00C04FD919C1")
    IWamAdmin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppCreate( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fInProc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppDelete( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppUnLoad( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppGetStatus( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [out] */ DWORD __RPC_FAR *pdwAppStatus) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppDeleteRecoverable( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppRecover( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWamAdminVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWamAdmin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWamAdmin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWamAdmin __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppCreate )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fInProc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppDelete )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppUnLoad )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppGetStatus )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [out] */ DWORD __RPC_FAR *pdwAppStatus);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppDeleteRecoverable )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppRecover )( 
            IWamAdmin __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        END_INTERFACE
    } IWamAdminVtbl;

    interface IWamAdmin
    {
        CONST_VTBL struct IWamAdminVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWamAdmin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWamAdmin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWamAdmin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWamAdmin_AppCreate(This,szMDPath,fInProc)	\
    (This)->lpVtbl -> AppCreate(This,szMDPath,fInProc)

#define IWamAdmin_AppDelete(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppDelete(This,szMDPath,fRecursive)

#define IWamAdmin_AppUnLoad(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppUnLoad(This,szMDPath,fRecursive)

#define IWamAdmin_AppGetStatus(This,szMDPath,pdwAppStatus)	\
    (This)->lpVtbl -> AppGetStatus(This,szMDPath,pdwAppStatus)

#define IWamAdmin_AppDeleteRecoverable(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppDeleteRecoverable(This,szMDPath,fRecursive)

#define IWamAdmin_AppRecover(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppRecover(This,szMDPath,fRecursive)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppCreate_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ BOOL fInProc);


void __RPC_STUB IWamAdmin_AppCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppDelete_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ BOOL fRecursive);


void __RPC_STUB IWamAdmin_AppDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppUnLoad_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ BOOL fRecursive);


void __RPC_STUB IWamAdmin_AppUnLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppGetStatus_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [out] */ DWORD __RPC_FAR *pdwAppStatus);


void __RPC_STUB IWamAdmin_AppGetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppDeleteRecoverable_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ BOOL fRecursive);


void __RPC_STUB IWamAdmin_AppDeleteRecoverable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin_AppRecover_Proxy( 
    IWamAdmin __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ BOOL fRecursive);


void __RPC_STUB IWamAdmin_AppRecover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWamAdmin_INTERFACE_DEFINED__ */


#ifndef __IWamAdmin2_INTERFACE_DEFINED__
#define __IWamAdmin2_INTERFACE_DEFINED__

/* interface IWamAdmin2 */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IWamAdmin2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29822AB8-F302-11D0-9953-00C04FD919C1")
    IWamAdmin2 : public IWamAdmin
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppCreate2( 
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ DWORD dwAppMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWamAdmin2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWamAdmin2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWamAdmin2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppCreate )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fInProc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppDelete )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppUnLoad )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppGetStatus )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [out] */ DWORD __RPC_FAR *pdwAppStatus);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppDeleteRecoverable )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppRecover )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ BOOL fRecursive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AppCreate2 )( 
            IWamAdmin2 __RPC_FAR * This,
            /* [string][unique][in] */ LPCWSTR szMDPath,
            /* [in] */ DWORD dwAppMode);
        
        END_INTERFACE
    } IWamAdmin2Vtbl;

    interface IWamAdmin2
    {
        CONST_VTBL struct IWamAdmin2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWamAdmin2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWamAdmin2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWamAdmin2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWamAdmin2_AppCreate(This,szMDPath,fInProc)	\
    (This)->lpVtbl -> AppCreate(This,szMDPath,fInProc)

#define IWamAdmin2_AppDelete(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppDelete(This,szMDPath,fRecursive)

#define IWamAdmin2_AppUnLoad(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppUnLoad(This,szMDPath,fRecursive)

#define IWamAdmin2_AppGetStatus(This,szMDPath,pdwAppStatus)	\
    (This)->lpVtbl -> AppGetStatus(This,szMDPath,pdwAppStatus)

#define IWamAdmin2_AppDeleteRecoverable(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppDeleteRecoverable(This,szMDPath,fRecursive)

#define IWamAdmin2_AppRecover(This,szMDPath,fRecursive)	\
    (This)->lpVtbl -> AppRecover(This,szMDPath,fRecursive)


#define IWamAdmin2_AppCreate2(This,szMDPath,dwAppMode)	\
    (This)->lpVtbl -> AppCreate2(This,szMDPath,dwAppMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWamAdmin2_AppCreate2_Proxy( 
    IWamAdmin2 __RPC_FAR * This,
    /* [string][unique][in] */ LPCWSTR szMDPath,
    /* [in] */ DWORD dwAppMode);


void __RPC_STUB IWamAdmin2_AppCreate2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWamAdmin2_INTERFACE_DEFINED__ */



#ifndef __WAMREGLib_LIBRARY_DEFINED__
#define __WAMREGLib_LIBRARY_DEFINED__

/* library WAMREGLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WAMREGLib;

EXTERN_C const CLSID CLSID_WamAdmin;

#ifdef __cplusplus

class DECLSPEC_UUID("61738644-F196-11D0-9953-00C04FD919C1")
WamAdmin;
#endif
#endif /* __WAMREGLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
