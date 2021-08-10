#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0268 */
/* at Fri Aug 13 14:26:31 1999
 */
/* Compiler settings for wia.idl, wia.acf:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
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

#ifndef __wia_h__
#define __wia_h__

/* Forward Declarations */ 

#ifndef __IWiaDevMgr_FWD_DEFINED__
#define __IWiaDevMgr_FWD_DEFINED__
typedef interface IWiaDevMgr IWiaDevMgr;
#endif 	/* __IWiaDevMgr_FWD_DEFINED__ */


#ifndef __IEnumWIA_DEV_INFO_FWD_DEFINED__
#define __IEnumWIA_DEV_INFO_FWD_DEFINED__
typedef interface IEnumWIA_DEV_INFO IEnumWIA_DEV_INFO;
#endif 	/* __IEnumWIA_DEV_INFO_FWD_DEFINED__ */


#ifndef __IWiaEventCallback_FWD_DEFINED__
#define __IWiaEventCallback_FWD_DEFINED__
typedef interface IWiaEventCallback IWiaEventCallback;
#endif 	/* __IWiaEventCallback_FWD_DEFINED__ */


#ifndef __IWiaDataCallback_FWD_DEFINED__
#define __IWiaDataCallback_FWD_DEFINED__
typedef interface IWiaDataCallback IWiaDataCallback;
#endif 	/* __IWiaDataCallback_FWD_DEFINED__ */


#ifndef __IWiaDataTransfer_FWD_DEFINED__
#define __IWiaDataTransfer_FWD_DEFINED__
typedef interface IWiaDataTransfer IWiaDataTransfer;
#endif 	/* __IWiaDataTransfer_FWD_DEFINED__ */


#ifndef __IWiaItem_FWD_DEFINED__
#define __IWiaItem_FWD_DEFINED__
typedef interface IWiaItem IWiaItem;
#endif 	/* __IWiaItem_FWD_DEFINED__ */


#ifndef __IWiaPropertyStorage_FWD_DEFINED__
#define __IWiaPropertyStorage_FWD_DEFINED__
typedef interface IWiaPropertyStorage IWiaPropertyStorage;
#endif 	/* __IWiaPropertyStorage_FWD_DEFINED__ */


#ifndef __IEnumWiaItem_FWD_DEFINED__
#define __IEnumWiaItem_FWD_DEFINED__
typedef interface IEnumWiaItem IEnumWiaItem;
#endif 	/* __IEnumWiaItem_FWD_DEFINED__ */


#ifndef __IEnumWIA_DEV_CAPS_FWD_DEFINED__
#define __IEnumWIA_DEV_CAPS_FWD_DEFINED__
typedef interface IEnumWIA_DEV_CAPS IEnumWIA_DEV_CAPS;
#endif 	/* __IEnumWIA_DEV_CAPS_FWD_DEFINED__ */


#ifndef __IEnumWIA_FORMAT_INFO_FWD_DEFINED__
#define __IEnumWIA_FORMAT_INFO_FWD_DEFINED__
typedef interface IEnumWIA_FORMAT_INFO IEnumWIA_FORMAT_INFO;
#endif 	/* __IEnumWIA_FORMAT_INFO_FWD_DEFINED__ */


#ifndef __WiaDevMgr_FWD_DEFINED__
#define __WiaDevMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class WiaDevMgr WiaDevMgr;
#else
typedef struct WiaDevMgr WiaDevMgr;
#endif /* __cplusplus */

#endif 	/* __WiaDevMgr_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"
#include "propidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_wia_0000 */
/* [local] */ 











typedef struct _WIA_DITHER_PATTERN_DATA
    {
    LONG lSize;
    BSTR bstrPatternName;
    LONG lPatternWidth;
    LONG lPatternLength;
    LONG cbPattern;
    /* [size_is] */ BYTE __RPC_FAR *pbPattern;
    }	WIA_DITHER_PATTERN_DATA;

typedef struct _WIA_DITHER_PATTERN_DATA __RPC_FAR *PWIA_DITHER_PATTERN_DATA;

typedef struct _WIA_PROPID_TO_NAME
    {
    PROPID propid;
    LPOLESTR pszName;
    }	WIA_PROPID_TO_NAME;

typedef struct _WIA_PROPID_TO_NAME __RPC_FAR *PWIA_PROPID_TO_NAME;

typedef struct _WIA_FORMAT_INFO
    {
    GUID guidFormatID;
    LONG lTymed;
    }	WIA_FORMAT_INFO;

typedef struct _WIA_FORMAT_INFO __RPC_FAR *PWIA_FORMAT_INFO;

#include "wiadef.h"


extern RPC_IF_HANDLE __MIDL_itf_wia_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wia_0000_v0_0_s_ifspec;

#ifndef __IWiaDevMgr_INTERFACE_DEFINED__
#define __IWiaDevMgr_INTERFACE_DEFINED__

/* interface IWiaDevMgr */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaDevMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5eb2502a-8cf1-11d1-bf92-0060081ed811")
    IWiaDevMgr : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumDeviceInfo( 
            /* [in] */ LONG lFlag,
            /* [retval][out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDevice( 
            /* [in] */ BSTR bstrDeviceID,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppWiaItemRoot) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SelectDeviceDlg( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [out][in] */ BSTR __RPC_FAR *pbstrDeviceID,
            /* [retval][out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppItemRoot) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SelectDeviceDlgID( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDeviceID) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetImageDlg( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [in] */ IWiaItem __RPC_FAR *pItemRoot,
            /* [in] */ BSTR bstrFilename,
            /* [out][in] */ GUID __RPC_FAR *pguidFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterEventLaunch( 
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [unique][in] */ IWiaItem __RPC_FAR *pItemRoot,
            /* [in] */ const GUID pEventGUID,
            /* [in] */ BSTR bstrAppName,
            /* [in] */ BSTR bstrCommandLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterEventCallbackInterface( 
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [unique][in] */ IWiaEventCallback __RPC_FAR *pIWiaEventCallback,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pEventObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterEventCallbackCLSID( 
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [unique][in] */ const GUID __RPC_FAR *pClsID,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrDescription,
            /* [in] */ BSTR bstrIcon) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDeviceDlg( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaDevMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaDevMgr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaDevMgr __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumDeviceInfo )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ LONG lFlag,
            /* [retval][out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateDevice )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ BSTR bstrDeviceID,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppWiaItemRoot);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectDeviceDlg )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [out][in] */ BSTR __RPC_FAR *pbstrDeviceID,
            /* [retval][out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppItemRoot);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectDeviceDlgID )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDeviceID);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageDlg )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lDeviceType,
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [in] */ IWiaItem __RPC_FAR *pItemRoot,
            /* [in] */ BSTR bstrFilename,
            /* [out][in] */ GUID __RPC_FAR *pguidFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterEventLaunch )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [unique][in] */ IWiaItem __RPC_FAR *pItemRoot,
            /* [in] */ const GUID pEventGUID,
            /* [in] */ BSTR bstrAppName,
            /* [in] */ BSTR bstrCommandLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterEventCallbackInterface )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [unique][in] */ IWiaEventCallback __RPC_FAR *pIWiaEventCallback,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pEventObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterEventCallbackCLSID )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [unique][in] */ const GUID __RPC_FAR *pClsID,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrDescription,
            /* [in] */ BSTR bstrIcon);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddDeviceDlg )( 
            IWiaDevMgr __RPC_FAR * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lFlags);
        
        END_INTERFACE
    } IWiaDevMgrVtbl;

    interface IWiaDevMgr
    {
        CONST_VTBL struct IWiaDevMgrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaDevMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaDevMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaDevMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaDevMgr_EnumDeviceInfo(This,lFlag,ppIEnum)	\
    (This)->lpVtbl -> EnumDeviceInfo(This,lFlag,ppIEnum)

#define IWiaDevMgr_CreateDevice(This,bstrDeviceID,ppWiaItemRoot)	\
    (This)->lpVtbl -> CreateDevice(This,bstrDeviceID,ppWiaItemRoot)

#define IWiaDevMgr_SelectDeviceDlg(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID,ppItemRoot)	\
    (This)->lpVtbl -> SelectDeviceDlg(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID,ppItemRoot)

#define IWiaDevMgr_SelectDeviceDlgID(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID)	\
    (This)->lpVtbl -> SelectDeviceDlgID(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID)

#define IWiaDevMgr_GetImageDlg(This,hwndParent,lDeviceType,lFlags,lIntent,pItemRoot,bstrFilename,pguidFormat)	\
    (This)->lpVtbl -> GetImageDlg(This,hwndParent,lDeviceType,lFlags,lIntent,pItemRoot,bstrFilename,pguidFormat)

#define IWiaDevMgr_RegisterEventLaunch(This,lFlags,lIntent,pItemRoot,pEventGUID,bstrAppName,bstrCommandLine)	\
    (This)->lpVtbl -> RegisterEventLaunch(This,lFlags,lIntent,pItemRoot,pEventGUID,bstrAppName,bstrCommandLine)

#define IWiaDevMgr_RegisterEventCallbackInterface(This,lFlags,bstrDeviceID,pEventGUID,pIWiaEventCallback,pEventObject)	\
    (This)->lpVtbl -> RegisterEventCallbackInterface(This,lFlags,bstrDeviceID,pEventGUID,pIWiaEventCallback,pEventObject)

#define IWiaDevMgr_RegisterEventCallbackCLSID(This,lFlags,bstrDeviceID,pEventGUID,pClsID,bstrName,bstrDescription,bstrIcon)	\
    (This)->lpVtbl -> RegisterEventCallbackCLSID(This,lFlags,bstrDeviceID,pEventGUID,pClsID,bstrName,bstrDescription,bstrIcon)

#define IWiaDevMgr_AddDeviceDlg(This,hwndParent,lFlags)	\
    (This)->lpVtbl -> AddDeviceDlg(This,hwndParent,lFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_EnumDeviceInfo_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ LONG lFlag,
    /* [retval][out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IWiaDevMgr_EnumDeviceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_CreateDevice_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ BSTR bstrDeviceID,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppWiaItemRoot);


void __RPC_STUB IWiaDevMgr_CreateDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_LocalSelectDeviceDlg_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [out][in] */ BSTR __RPC_FAR *pbstrDeviceID,
    /* [retval][out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppItemRoot);


void __RPC_STUB IWiaDevMgr_LocalSelectDeviceDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_LocalSelectDeviceDlgID_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDeviceID);


void __RPC_STUB IWiaDevMgr_LocalSelectDeviceDlgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_LocalGetImageDlg_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [in] */ IWiaItem __RPC_FAR *pItemRoot,
    /* [in] */ BSTR bstrFilename,
    /* [out][in] */ GUID __RPC_FAR *pguidFormat);


void __RPC_STUB IWiaDevMgr_LocalGetImageDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventLaunch_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [unique][in] */ IWiaItem __RPC_FAR *pItemRoot,
    /* [in] */ const GUID pEventGUID,
    /* [in] */ BSTR bstrAppName,
    /* [in] */ BSTR bstrCommandLine);


void __RPC_STUB IWiaDevMgr_RegisterEventLaunch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventCallbackInterface_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ BSTR bstrDeviceID,
    /* [in] */ const GUID __RPC_FAR *pEventGUID,
    /* [unique][in] */ IWiaEventCallback __RPC_FAR *pIWiaEventCallback,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pEventObject);


void __RPC_STUB IWiaDevMgr_RegisterEventCallbackInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventCallbackCLSID_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ BSTR bstrDeviceID,
    /* [in] */ const GUID __RPC_FAR *pEventGUID,
    /* [unique][in] */ const GUID __RPC_FAR *pClsID,
    /* [in] */ BSTR bstrName,
    /* [in] */ BSTR bstrDescription,
    /* [in] */ BSTR bstrIcon);


void __RPC_STUB IWiaDevMgr_RegisterEventCallbackCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_AddDeviceDlg_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lFlags);


void __RPC_STUB IWiaDevMgr_AddDeviceDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaDevMgr_INTERFACE_DEFINED__ */


#ifndef __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__
#define __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__

/* interface IEnumWIA_DEV_INFO */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumWIA_DEV_INFO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e38b83c-8cf1-11d1-bf92-0060081ed811")
    IEnumWIA_DEV_INFO : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IWiaPropertyStorage __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *celt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumWIA_DEV_INFOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IWiaPropertyStorage __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This,
            /* [out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IEnumWIA_DEV_INFO __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *celt);
        
        END_INTERFACE
    } IEnumWIA_DEV_INFOVtbl;

    interface IEnumWIA_DEV_INFO
    {
        CONST_VTBL struct IEnumWIA_DEV_INFOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumWIA_DEV_INFO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumWIA_DEV_INFO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumWIA_DEV_INFO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumWIA_DEV_INFO_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumWIA_DEV_INFO_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumWIA_DEV_INFO_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumWIA_DEV_INFO_Clone(This,ppIEnum)	\
    (This)->lpVtbl -> Clone(This,ppIEnum)

#define IEnumWIA_DEV_INFO_GetCount(This,celt)	\
    (This)->lpVtbl -> GetCount(This,celt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_INFO_Next_Proxy( 
    IEnumWIA_DEV_INFO __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IWiaPropertyStorage __RPC_FAR *__RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumWIA_DEV_INFO_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_INFO_Skip_Proxy( 
    IEnumWIA_DEV_INFO __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumWIA_DEV_INFO_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_INFO_Reset_Proxy( 
    IEnumWIA_DEV_INFO __RPC_FAR * This);


void __RPC_STUB IEnumWIA_DEV_INFO_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_INFO_Clone_Proxy( 
    IEnumWIA_DEV_INFO __RPC_FAR * This,
    /* [out] */ IEnumWIA_DEV_INFO __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IEnumWIA_DEV_INFO_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_INFO_GetCount_Proxy( 
    IEnumWIA_DEV_INFO __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *celt);


void __RPC_STUB IEnumWIA_DEV_INFO_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__ */


#ifndef __IWiaEventCallback_INTERFACE_DEFINED__
#define __IWiaEventCallback_INTERFACE_DEFINED__

/* interface IWiaEventCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaEventCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ae6287b0-0084-11d2-973b-00a0c9068f2e")
    IWiaEventCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ImageEventCallback( 
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [in] */ BSTR bstrEventDescription,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ BSTR bstrDeviceDescription,
            /* [in] */ DWORD dwDeviceType,
            /* [out][in] */ ULONG __RPC_FAR *pulEventType,
            /* [in] */ ULONG ulReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaEventCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaEventCallback __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaEventCallback __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaEventCallback __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImageEventCallback )( 
            IWiaEventCallback __RPC_FAR * This,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [in] */ BSTR bstrEventDescription,
            /* [in] */ BSTR bstrDeviceID,
            /* [in] */ BSTR bstrDeviceDescription,
            /* [in] */ DWORD dwDeviceType,
            /* [out][in] */ ULONG __RPC_FAR *pulEventType,
            /* [in] */ ULONG ulReserved);
        
        END_INTERFACE
    } IWiaEventCallbackVtbl;

    interface IWiaEventCallback
    {
        CONST_VTBL struct IWiaEventCallbackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaEventCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaEventCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaEventCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaEventCallback_ImageEventCallback(This,pEventGUID,bstrEventDescription,bstrDeviceID,bstrDeviceDescription,dwDeviceType,pulEventType,ulReserved)	\
    (This)->lpVtbl -> ImageEventCallback(This,pEventGUID,bstrEventDescription,bstrDeviceID,bstrDeviceDescription,dwDeviceType,pulEventType,ulReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWiaEventCallback_ImageEventCallback_Proxy( 
    IWiaEventCallback __RPC_FAR * This,
    /* [in] */ const GUID __RPC_FAR *pEventGUID,
    /* [in] */ BSTR bstrEventDescription,
    /* [in] */ BSTR bstrDeviceID,
    /* [in] */ BSTR bstrDeviceDescription,
    /* [in] */ DWORD dwDeviceType,
    /* [out][in] */ ULONG __RPC_FAR *pulEventType,
    /* [in] */ ULONG ulReserved);


void __RPC_STUB IWiaEventCallback_ImageEventCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaEventCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wia_0115 */
/* [local] */ 

typedef struct _WIA_DATA_CALLBACK_HEADER
    {
    LONG lSize;
    GUID guidFormatID;
    LONG lBufferSize;
    LONG lPageCount;
    }	WIA_DATA_CALLBACK_HEADER;

typedef struct _WIA_DATA_CALLBACK_HEADER __RPC_FAR *PWIA_DATA_CALLBACK_HEADER;



extern RPC_IF_HANDLE __MIDL_itf_wia_0115_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wia_0115_v0_0_s_ifspec;

#ifndef __IWiaDataCallback_INTERFACE_DEFINED__
#define __IWiaDataCallback_INTERFACE_DEFINED__

/* interface IWiaDataCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaDataCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a558a866-a5b0-11d2-a08f-00c04f72dc3c")
    IWiaDataCallback : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE BandedDataCallback( 
            /* [in] */ LONG lMessage,
            /* [in] */ LONG lStatus,
            /* [in] */ LONG lPercentComplete,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lLength,
            /* [in] */ LONG lReserved,
            /* [in] */ LONG lResLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaDataCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaDataCallback __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaDataCallback __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaDataCallback __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BandedDataCallback )( 
            IWiaDataCallback __RPC_FAR * This,
            /* [in] */ LONG lMessage,
            /* [in] */ LONG lStatus,
            /* [in] */ LONG lPercentComplete,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lLength,
            /* [in] */ LONG lReserved,
            /* [in] */ LONG lResLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer);
        
        END_INTERFACE
    } IWiaDataCallbackVtbl;

    interface IWiaDataCallback
    {
        CONST_VTBL struct IWiaDataCallbackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaDataCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaDataCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaDataCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaDataCallback_BandedDataCallback(This,lMessage,lStatus,lPercentComplete,lOffset,lLength,lReserved,lResLength,pbBuffer)	\
    (This)->lpVtbl -> BandedDataCallback(This,lMessage,lStatus,lPercentComplete,lOffset,lLength,lReserved,lResLength,pbBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataCallback_RemoteBandedDataCallback_Proxy( 
    IWiaDataCallback __RPC_FAR * This,
    /* [in] */ LONG lMessage,
    /* [in] */ LONG lStatus,
    /* [in] */ LONG lPercentComplete,
    /* [in] */ LONG lOffset,
    /* [in] */ LONG lLength,
    /* [in] */ LONG lReserved,
    /* [in] */ LONG lResLength,
    /* [unique][size_is][in] */ BYTE __RPC_FAR *pbBuffer);


void __RPC_STUB IWiaDataCallback_RemoteBandedDataCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaDataCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wia_0116 */
/* [local] */ 

typedef struct _WIA_DATA_TRANSFER_INFO
    {
    ULONG ulSize;
    ULONG ulSection;
    ULONG ulBufferSize;
    BOOL bDoubleBuffer;
    ULONG ulReserved1;
    ULONG ulReserved2;
    ULONG ulReserved3;
    }	WIA_DATA_TRANSFER_INFO;

typedef struct _WIA_DATA_TRANSFER_INFO __RPC_FAR *PWIA_DATA_TRANSFER_INFO;



extern RPC_IF_HANDLE __MIDL_itf_wia_0116_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wia_0116_v0_0_s_ifspec;

#ifndef __IWiaDataTransfer_INTERFACE_DEFINED__
#define __IWiaDataTransfer_INTERFACE_DEFINED__

/* interface IWiaDataTransfer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaDataTransfer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a6cef998-a5b0-11d2-a08f-00c04f72dc3c")
    IWiaDataTransfer : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE idtGetData( 
            /* [out] */ LPSTGMEDIUM pMedium,
            /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE idtGetBandedData( 
            /* [unique][in] */ PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo,
            /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE idtQueryGetData( 
            /* [unique][in] */ WIA_FORMAT_INFO __RPC_FAR *pfe) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE idtEnumWIA_FORMAT_INFO( 
            /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaDataTransferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaDataTransfer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaDataTransfer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaDataTransfer __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *idtGetData )( 
            IWiaDataTransfer __RPC_FAR * This,
            /* [out] */ LPSTGMEDIUM pMedium,
            /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *idtGetBandedData )( 
            IWiaDataTransfer __RPC_FAR * This,
            /* [unique][in] */ PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo,
            /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *idtQueryGetData )( 
            IWiaDataTransfer __RPC_FAR * This,
            /* [unique][in] */ WIA_FORMAT_INFO __RPC_FAR *pfe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *idtEnumWIA_FORMAT_INFO )( 
            IWiaDataTransfer __RPC_FAR * This,
            /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IWiaDataTransferVtbl;

    interface IWiaDataTransfer
    {
        CONST_VTBL struct IWiaDataTransferVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaDataTransfer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaDataTransfer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaDataTransfer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaDataTransfer_idtGetData(This,pMedium,pIWiaDataCallback)	\
    (This)->lpVtbl -> idtGetData(This,pMedium,pIWiaDataCallback)

#define IWiaDataTransfer_idtGetBandedData(This,pWiaDataTransInfo,pIWiaDataCallback)	\
    (This)->lpVtbl -> idtGetBandedData(This,pWiaDataTransInfo,pIWiaDataCallback)

#define IWiaDataTransfer_idtQueryGetData(This,pfe)	\
    (This)->lpVtbl -> idtQueryGetData(This,pfe)

#define IWiaDataTransfer_idtEnumWIA_FORMAT_INFO(This,ppEnum)	\
    (This)->lpVtbl -> idtEnumWIA_FORMAT_INFO(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetDataEx_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [out] */ LPSTGMEDIUM pMedium,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);


void __RPC_STUB IWiaDataTransfer_idtGetDataEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetBandedDataEx_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [unique][in] */ PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);


void __RPC_STUB IWiaDataTransfer_idtGetBandedDataEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtQueryGetData_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [unique][in] */ WIA_FORMAT_INFO __RPC_FAR *pfe);


void __RPC_STUB IWiaDataTransfer_idtQueryGetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtEnumWIA_FORMAT_INFO_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IWiaDataTransfer_idtEnumWIA_FORMAT_INFO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaDataTransfer_INTERFACE_DEFINED__ */


#ifndef __IWiaItem_INTERFACE_DEFINED__
#define __IWiaItem_INTERFACE_DEFINED__

/* interface IWiaItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4db1ad10-3391-11d2-9a33-00c04fa36145")
    IWiaItem : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetItemType( 
            /* [out] */ LONG __RPC_FAR *pItemType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AnalyzeItem( 
            /* [in] */ LONG lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumChildItems( 
            /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnumWiaItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteItem( 
            /* [in] */ LONG lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateChildItem( 
            /* [in] */ LONG lFlags,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumRegisterEventInfo( 
            /* [in] */ LONG lFlags,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindItemByName( 
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrFullItemName,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DeviceDlg( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [out] */ LONG __RPC_FAR *plItemCount,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *__RPC_FAR *ppIWiaItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeviceCommand( 
            /* [in] */ LONG lFlags,
            /* [in] */ const GUID __RPC_FAR *pCmdGUID,
            /* [out][in] */ IWiaItem __RPC_FAR *__RPC_FAR *pIWiaItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRootItem( 
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumDeviceCapabilities( 
            /* [in] */ LONG lFlags,
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnumWIA_DEV_CAPS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DumpItemData( 
            /* [out] */ BSTR __RPC_FAR *bstrData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DumpDrvItemData( 
            /* [out] */ BSTR __RPC_FAR *bstrData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DumpTreeItemData( 
            /* [out] */ BSTR __RPC_FAR *bstrData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaItem __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemType )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *pItemType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AnalyzeItem )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumChildItems )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnumWiaItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteItem )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateChildItem )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumRegisterEventInfo )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ const GUID __RPC_FAR *pEventGUID,
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindItemByName )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ BSTR bstrFullItemName,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeviceDlg )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LONG lFlags,
            /* [in] */ LONG lIntent,
            /* [out] */ LONG __RPC_FAR *plItemCount,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *__RPC_FAR *ppIWiaItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeviceCommand )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [in] */ const GUID __RPC_FAR *pCmdGUID,
            /* [out][in] */ IWiaItem __RPC_FAR *__RPC_FAR *pIWiaItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRootItem )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumDeviceCapabilities )( 
            IWiaItem __RPC_FAR * This,
            /* [in] */ LONG lFlags,
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnumWIA_DEV_CAPS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DumpItemData )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DumpDrvItemData )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DumpTreeItemData )( 
            IWiaItem __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bstrData);
        
        END_INTERFACE
    } IWiaItemVtbl;

    interface IWiaItem
    {
        CONST_VTBL struct IWiaItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaItem_GetItemType(This,pItemType)	\
    (This)->lpVtbl -> GetItemType(This,pItemType)

#define IWiaItem_AnalyzeItem(This,lFlags)	\
    (This)->lpVtbl -> AnalyzeItem(This,lFlags)

#define IWiaItem_EnumChildItems(This,ppIEnumWiaItem)	\
    (This)->lpVtbl -> EnumChildItems(This,ppIEnumWiaItem)

#define IWiaItem_DeleteItem(This,lFlags)	\
    (This)->lpVtbl -> DeleteItem(This,lFlags)

#define IWiaItem_CreateChildItem(This,lFlags,ppIWiaItem)	\
    (This)->lpVtbl -> CreateChildItem(This,lFlags,ppIWiaItem)

#define IWiaItem_EnumRegisterEventInfo(This,lFlags,pEventGUID,ppIEnum)	\
    (This)->lpVtbl -> EnumRegisterEventInfo(This,lFlags,pEventGUID,ppIEnum)

#define IWiaItem_FindItemByName(This,lFlags,bstrFullItemName,ppIWiaItem)	\
    (This)->lpVtbl -> FindItemByName(This,lFlags,bstrFullItemName,ppIWiaItem)

#define IWiaItem_DeviceDlg(This,hwndParent,lFlags,lIntent,plItemCount,ppIWiaItem)	\
    (This)->lpVtbl -> DeviceDlg(This,hwndParent,lFlags,lIntent,plItemCount,ppIWiaItem)

#define IWiaItem_DeviceCommand(This,lFlags,pCmdGUID,pIWiaItem)	\
    (This)->lpVtbl -> DeviceCommand(This,lFlags,pCmdGUID,pIWiaItem)

#define IWiaItem_GetRootItem(This,ppIWiaItem)	\
    (This)->lpVtbl -> GetRootItem(This,ppIWiaItem)

#define IWiaItem_EnumDeviceCapabilities(This,lFlags,ppIEnumWIA_DEV_CAPS)	\
    (This)->lpVtbl -> EnumDeviceCapabilities(This,lFlags,ppIEnumWIA_DEV_CAPS)

#define IWiaItem_DumpItemData(This,bstrData)	\
    (This)->lpVtbl -> DumpItemData(This,bstrData)

#define IWiaItem_DumpDrvItemData(This,bstrData)	\
    (This)->lpVtbl -> DumpDrvItemData(This,bstrData)

#define IWiaItem_DumpTreeItemData(This,bstrData)	\
    (This)->lpVtbl -> DumpTreeItemData(This,bstrData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_GetItemType_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *pItemType);


void __RPC_STUB IWiaItem_GetItemType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_AnalyzeItem_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags);


void __RPC_STUB IWiaItem_AnalyzeItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_EnumChildItems_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnumWiaItem);


void __RPC_STUB IWiaItem_EnumChildItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DeleteItem_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags);


void __RPC_STUB IWiaItem_DeleteItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_CreateChildItem_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);


void __RPC_STUB IWiaItem_CreateChildItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_EnumRegisterEventInfo_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ const GUID __RPC_FAR *pEventGUID,
    /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IWiaItem_EnumRegisterEventInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_FindItemByName_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ BSTR bstrFullItemName,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);


void __RPC_STUB IWiaItem_FindItemByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_LocalDeviceDlg_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [out] */ LONG __RPC_FAR *plItemCount,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *__RPC_FAR *pIWiaItem);


void __RPC_STUB IWiaItem_LocalDeviceDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DeviceCommand_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [in] */ const GUID __RPC_FAR *pCmdGUID,
    /* [out][in] */ IWiaItem __RPC_FAR *__RPC_FAR *pIWiaItem);


void __RPC_STUB IWiaItem_DeviceCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_GetRootItem_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem);


void __RPC_STUB IWiaItem_GetRootItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_EnumDeviceCapabilities_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ LONG lFlags,
    /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnumWIA_DEV_CAPS);


void __RPC_STUB IWiaItem_EnumDeviceCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DumpItemData_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bstrData);


void __RPC_STUB IWiaItem_DumpItemData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DumpDrvItemData_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bstrData);


void __RPC_STUB IWiaItem_DumpDrvItemData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DumpTreeItemData_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bstrData);


void __RPC_STUB IWiaItem_DumpTreeItemData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaItem_INTERFACE_DEFINED__ */


#ifndef __IWiaPropertyStorage_INTERFACE_DEFINED__
#define __IWiaPropertyStorage_INTERFACE_DEFINED__

/* interface IWiaPropertyStorage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWiaPropertyStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98B5E8A0-29CC-491a-AAC0-E6DB4FDCCEB6")
    IWiaPropertyStorage : public IPropertyStorage
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyAttributes( 
            /* [in] */ ULONG cpspec,
            /* [size_is][in] */ PROPSPEC __RPC_FAR rgpspec[  ],
            /* [size_is][out] */ ULONG __RPC_FAR rgflags[  ],
            /* [size_is][out] */ PROPVARIANT __RPC_FAR rgpropvar[  ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *pulNumProps) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyStream( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppIStream) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPropertyStream( 
            /* [in] */ IStream __RPC_FAR *pIStream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWiaPropertyStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWiaPropertyStorage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWiaPropertyStorage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadMultiple )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpspec,
            /* [size_is][in] */ const PROPSPEC __RPC_FAR rgpspec[  ],
            /* [size_is][out] */ PROPVARIANT __RPC_FAR rgpropvar[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteMultiple )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpspec,
            /* [size_is][in] */ const PROPSPEC __RPC_FAR rgpspec[  ],
            /* [size_is][in] */ const PROPVARIANT __RPC_FAR rgpropvar[  ],
            /* [in] */ PROPID propidNameFirst);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMultiple )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpspec,
            /* [size_is][in] */ const PROPSPEC __RPC_FAR rgpspec[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadPropertyNames )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpropid,
            /* [size_is][in] */ const PROPID __RPC_FAR rgpropid[  ],
            /* [size_is][out] */ LPOLESTR __RPC_FAR rglpwstrName[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WritePropertyNames )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpropid,
            /* [size_is][in] */ const PROPID __RPC_FAR rgpropid[  ],
            /* [size_is][in] */ const LPOLESTR __RPC_FAR rglpwstrName[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeletePropertyNames )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpropid,
            /* [size_is][in] */ const PROPID __RPC_FAR rgpropid[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Revert )( 
            IWiaPropertyStorage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Enum )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [out] */ IEnumSTATPROPSTG __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimes )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ const FILETIME __RPC_FAR *pctime,
            /* [in] */ const FILETIME __RPC_FAR *patime,
            /* [in] */ const FILETIME __RPC_FAR *pmtime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClass )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ REFCLSID clsid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stat )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [out] */ STATPROPSETSTG __RPC_FAR *pstatpsstg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropertyAttributes )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ ULONG cpspec,
            /* [size_is][in] */ PROPSPEC __RPC_FAR rgpspec[  ],
            /* [size_is][out] */ ULONG __RPC_FAR rgflags[  ],
            /* [size_is][out] */ PROPVARIANT __RPC_FAR rgpropvar[  ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pulNumProps);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropertyStream )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppIStream);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropertyStream )( 
            IWiaPropertyStorage __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pIStream);
        
        END_INTERFACE
    } IWiaPropertyStorageVtbl;

    interface IWiaPropertyStorage
    {
        CONST_VTBL struct IWiaPropertyStorageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWiaPropertyStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWiaPropertyStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWiaPropertyStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWiaPropertyStorage_ReadMultiple(This,cpspec,rgpspec,rgpropvar)	\
    (This)->lpVtbl -> ReadMultiple(This,cpspec,rgpspec,rgpropvar)

#define IWiaPropertyStorage_WriteMultiple(This,cpspec,rgpspec,rgpropvar,propidNameFirst)	\
    (This)->lpVtbl -> WriteMultiple(This,cpspec,rgpspec,rgpropvar,propidNameFirst)

#define IWiaPropertyStorage_DeleteMultiple(This,cpspec,rgpspec)	\
    (This)->lpVtbl -> DeleteMultiple(This,cpspec,rgpspec)

#define IWiaPropertyStorage_ReadPropertyNames(This,cpropid,rgpropid,rglpwstrName)	\
    (This)->lpVtbl -> ReadPropertyNames(This,cpropid,rgpropid,rglpwstrName)

#define IWiaPropertyStorage_WritePropertyNames(This,cpropid,rgpropid,rglpwstrName)	\
    (This)->lpVtbl -> WritePropertyNames(This,cpropid,rgpropid,rglpwstrName)

#define IWiaPropertyStorage_DeletePropertyNames(This,cpropid,rgpropid)	\
    (This)->lpVtbl -> DeletePropertyNames(This,cpropid,rgpropid)

#define IWiaPropertyStorage_Commit(This,grfCommitFlags)	\
    (This)->lpVtbl -> Commit(This,grfCommitFlags)

#define IWiaPropertyStorage_Revert(This)	\
    (This)->lpVtbl -> Revert(This)

#define IWiaPropertyStorage_Enum(This,ppenum)	\
    (This)->lpVtbl -> Enum(This,ppenum)

#define IWiaPropertyStorage_SetTimes(This,pctime,patime,pmtime)	\
    (This)->lpVtbl -> SetTimes(This,pctime,patime,pmtime)

#define IWiaPropertyStorage_SetClass(This,clsid)	\
    (This)->lpVtbl -> SetClass(This,clsid)

#define IWiaPropertyStorage_Stat(This,pstatpsstg)	\
    (This)->lpVtbl -> Stat(This,pstatpsstg)


#define IWiaPropertyStorage_GetPropertyAttributes(This,cpspec,rgpspec,rgflags,rgpropvar)	\
    (This)->lpVtbl -> GetPropertyAttributes(This,cpspec,rgpspec,rgflags,rgpropvar)

#define IWiaPropertyStorage_GetCount(This,pulNumProps)	\
    (This)->lpVtbl -> GetCount(This,pulNumProps)

#define IWiaPropertyStorage_GetPropertyStream(This,ppIStream)	\
    (This)->lpVtbl -> GetPropertyStream(This,ppIStream)

#define IWiaPropertyStorage_SetPropertyStream(This,pIStream)	\
    (This)->lpVtbl -> SetPropertyStream(This,pIStream)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaPropertyStorage_GetPropertyAttributes_Proxy( 
    IWiaPropertyStorage __RPC_FAR * This,
    /* [in] */ ULONG cpspec,
    /* [size_is][in] */ PROPSPEC __RPC_FAR rgpspec[  ],
    /* [size_is][out] */ ULONG __RPC_FAR rgflags[  ],
    /* [size_is][out] */ PROPVARIANT __RPC_FAR rgpropvar[  ]);


void __RPC_STUB IWiaPropertyStorage_GetPropertyAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaPropertyStorage_GetCount_Proxy( 
    IWiaPropertyStorage __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pulNumProps);


void __RPC_STUB IWiaPropertyStorage_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaPropertyStorage_GetPropertyStream_Proxy( 
    IWiaPropertyStorage __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppIStream);


void __RPC_STUB IWiaPropertyStorage_GetPropertyStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWiaPropertyStorage_SetPropertyStream_Proxy( 
    IWiaPropertyStorage __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pIStream);


void __RPC_STUB IWiaPropertyStorage_SetPropertyStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWiaPropertyStorage_INTERFACE_DEFINED__ */


#ifndef __IEnumWiaItem_INTERFACE_DEFINED__
#define __IEnumWiaItem_INTERFACE_DEFINED__

/* interface IEnumWiaItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumWiaItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e8383fc-3391-11d2-9a33-00c04fa36145")
    IEnumWiaItem : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *celt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumWiaItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumWiaItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumWiaItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumWiaItem __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumWiaItem __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumWiaItem __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumWiaItem __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumWiaItem __RPC_FAR * This,
            /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IEnumWiaItem __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *celt);
        
        END_INTERFACE
    } IEnumWiaItemVtbl;

    interface IEnumWiaItem
    {
        CONST_VTBL struct IEnumWiaItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumWiaItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumWiaItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumWiaItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumWiaItem_Next(This,celt,ppIWiaItem,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppIWiaItem,pceltFetched)

#define IEnumWiaItem_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumWiaItem_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumWiaItem_Clone(This,ppIEnum)	\
    (This)->lpVtbl -> Clone(This,ppIEnum)

#define IEnumWiaItem_GetCount(This,celt)	\
    (This)->lpVtbl -> GetCount(This,celt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWiaItem_Next_Proxy( 
    IEnumWiaItem __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppIWiaItem,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumWiaItem_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWiaItem_Skip_Proxy( 
    IEnumWiaItem __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumWiaItem_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWiaItem_Reset_Proxy( 
    IEnumWiaItem __RPC_FAR * This);


void __RPC_STUB IEnumWiaItem_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWiaItem_Clone_Proxy( 
    IEnumWiaItem __RPC_FAR * This,
    /* [out] */ IEnumWiaItem __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IEnumWiaItem_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWiaItem_GetCount_Proxy( 
    IEnumWiaItem __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *celt);


void __RPC_STUB IEnumWiaItem_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumWiaItem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wia_0120 */
/* [local] */ 

typedef struct _WIA_DEV_CAP
    {
    GUID guid;
    ULONG ulFlags;
    BSTR bstrName;
    BSTR bstrDescription;
    BSTR bstrIcon;
    }	WIA_DEV_CAP;

typedef struct _WIA_DEV_CAP __RPC_FAR *PWIA_DEV_CAP;

typedef struct _WIA_DEV_CAP WIA_EVENT_HANDLER;

typedef struct _WIA_DEV_CAP __RPC_FAR *PWIA_EVENT_HANDLER;



extern RPC_IF_HANDLE __MIDL_itf_wia_0120_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wia_0120_v0_0_s_ifspec;

#ifndef __IEnumWIA_DEV_CAPS_INTERFACE_DEFINED__
#define __IEnumWIA_DEV_CAPS_INTERFACE_DEFINED__

/* interface IEnumWIA_DEV_CAPS */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumWIA_DEV_CAPS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1fcc4287-aca6-11d2-a093-00c04f72dc3c")
    IEnumWIA_DEV_CAPS : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WIA_DEV_CAP __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *pcelt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumWIA_DEV_CAPSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WIA_DEV_CAP __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This,
            /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IEnumWIA_DEV_CAPS __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pcelt);
        
        END_INTERFACE
    } IEnumWIA_DEV_CAPSVtbl;

    interface IEnumWIA_DEV_CAPS
    {
        CONST_VTBL struct IEnumWIA_DEV_CAPSVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumWIA_DEV_CAPS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumWIA_DEV_CAPS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumWIA_DEV_CAPS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumWIA_DEV_CAPS_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumWIA_DEV_CAPS_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumWIA_DEV_CAPS_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumWIA_DEV_CAPS_Clone(This,ppIEnum)	\
    (This)->lpVtbl -> Clone(This,ppIEnum)

#define IEnumWIA_DEV_CAPS_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_CAPS_Next_Proxy( 
    IEnumWIA_DEV_CAPS __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ WIA_DEV_CAP __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumWIA_DEV_CAPS_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_CAPS_Skip_Proxy( 
    IEnumWIA_DEV_CAPS __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumWIA_DEV_CAPS_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_CAPS_Reset_Proxy( 
    IEnumWIA_DEV_CAPS __RPC_FAR * This);


void __RPC_STUB IEnumWIA_DEV_CAPS_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_CAPS_Clone_Proxy( 
    IEnumWIA_DEV_CAPS __RPC_FAR * This,
    /* [out] */ IEnumWIA_DEV_CAPS __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IEnumWIA_DEV_CAPS_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_DEV_CAPS_GetCount_Proxy( 
    IEnumWIA_DEV_CAPS __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcelt);


void __RPC_STUB IEnumWIA_DEV_CAPS_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumWIA_DEV_CAPS_INTERFACE_DEFINED__ */


#ifndef __IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED__
#define __IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED__

/* interface IEnumWIA_FORMAT_INFO */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumWIA_FORMAT_INFO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81BEFC5B-656D-44f1-B24C-D41D51B4DC81")
    IEnumWIA_FORMAT_INFO : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WIA_FORMAT_INFO __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *pcelt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumWIA_FORMAT_INFOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ WIA_FORMAT_INFO __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This,
            /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IEnumWIA_FORMAT_INFO __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pcelt);
        
        END_INTERFACE
    } IEnumWIA_FORMAT_INFOVtbl;

    interface IEnumWIA_FORMAT_INFO
    {
        CONST_VTBL struct IEnumWIA_FORMAT_INFOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumWIA_FORMAT_INFO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumWIA_FORMAT_INFO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumWIA_FORMAT_INFO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumWIA_FORMAT_INFO_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumWIA_FORMAT_INFO_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumWIA_FORMAT_INFO_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumWIA_FORMAT_INFO_Clone(This,ppIEnum)	\
    (This)->lpVtbl -> Clone(This,ppIEnum)

#define IEnumWIA_FORMAT_INFO_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_FORMAT_INFO_Next_Proxy( 
    IEnumWIA_FORMAT_INFO __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ WIA_FORMAT_INFO __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumWIA_FORMAT_INFO_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_FORMAT_INFO_Skip_Proxy( 
    IEnumWIA_FORMAT_INFO __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumWIA_FORMAT_INFO_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_FORMAT_INFO_Reset_Proxy( 
    IEnumWIA_FORMAT_INFO __RPC_FAR * This);


void __RPC_STUB IEnumWIA_FORMAT_INFO_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_FORMAT_INFO_Clone_Proxy( 
    IEnumWIA_FORMAT_INFO __RPC_FAR * This,
    /* [out] */ IEnumWIA_FORMAT_INFO __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IEnumWIA_FORMAT_INFO_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEnumWIA_FORMAT_INFO_GetCount_Proxy( 
    IEnumWIA_FORMAT_INFO __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcelt);


void __RPC_STUB IEnumWIA_FORMAT_INFO_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED__ */



#ifndef __WiaDevMgr_LIBRARY_DEFINED__
#define __WiaDevMgr_LIBRARY_DEFINED__

/* library WiaDevMgr */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WiaDevMgr;

EXTERN_C const CLSID CLSID_WiaDevMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("a1f4e726-8cf1-11d1-bf92-0060081ed811")
WiaDevMgr;
#endif
#endif /* __WiaDevMgr_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HWND __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  HWND_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HWND __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  HWND_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HWND __RPC_FAR * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long __RPC_FAR *, HWND __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

unsigned long             __RPC_USER  STGMEDIUM_UserSize(     unsigned long __RPC_FAR *, unsigned long            , STGMEDIUM __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  STGMEDIUM_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, STGMEDIUM __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  STGMEDIUM_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, STGMEDIUM __RPC_FAR * ); 
void                      __RPC_USER  STGMEDIUM_UserFree(     unsigned long __RPC_FAR *, STGMEDIUM __RPC_FAR * ); 

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlg_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [out][in] */ BSTR __RPC_FAR *pbstrDeviceID,
    /* [retval][out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppItemRoot);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlg_Stub( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [out][in] */ BSTR __RPC_FAR *pbstrDeviceID,
    /* [retval][out] */ IWiaItem __RPC_FAR *__RPC_FAR *ppItemRoot);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlgID_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDeviceID);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlgID_Stub( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDeviceID);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_GetImageDlg_Proxy( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [in] */ IWiaItem __RPC_FAR *pItemRoot,
    /* [in] */ BSTR bstrFilename,
    /* [out][in] */ GUID __RPC_FAR *pguidFormat);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDevMgr_GetImageDlg_Stub( 
    IWiaDevMgr __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lDeviceType,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [in] */ IWiaItem __RPC_FAR *pItemRoot,
    /* [in] */ BSTR bstrFilename,
    /* [out][in] */ GUID __RPC_FAR *pguidFormat);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDataCallback_BandedDataCallback_Proxy( 
    IWiaDataCallback __RPC_FAR * This,
    /* [in] */ LONG lMessage,
    /* [in] */ LONG lStatus,
    /* [in] */ LONG lPercentComplete,
    /* [in] */ LONG lOffset,
    /* [in] */ LONG lLength,
    /* [in] */ LONG lReserved,
    /* [in] */ LONG lResLength,
    /* [size_is][in] */ BYTE __RPC_FAR *pbBuffer);


/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataCallback_BandedDataCallback_Stub( 
    IWiaDataCallback __RPC_FAR * This,
    /* [in] */ LONG lMessage,
    /* [in] */ LONG lStatus,
    /* [in] */ LONG lPercentComplete,
    /* [in] */ LONG lOffset,
    /* [in] */ LONG lLength,
    /* [in] */ LONG lReserved,
    /* [in] */ LONG lResLength,
    /* [unique][size_is][in] */ BYTE __RPC_FAR *pbBuffer);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetData_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [out] */ LPSTGMEDIUM pMedium,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);


/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetData_Stub( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [out] */ LPSTGMEDIUM pMedium,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetBandedData_Proxy( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [unique][in] */ PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);


/* [helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaDataTransfer_idtGetBandedData_Stub( 
    IWiaDataTransfer __RPC_FAR * This,
    /* [unique][in] */ PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo,
    /* [unique][in] */ IWiaDataCallback __RPC_FAR *pIWiaDataCallback);

/* [local] */ HRESULT STDMETHODCALLTYPE IWiaItem_DeviceDlg_Proxy( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [out] */ LONG __RPC_FAR *plItemCount,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *__RPC_FAR *ppIWiaItem);


/* [nocode][helpstring][call_as][id] */ HRESULT STDMETHODCALLTYPE IWiaItem_DeviceDlg_Stub( 
    IWiaItem __RPC_FAR * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LONG lFlags,
    /* [in] */ LONG lIntent,
    /* [out] */ LONG __RPC_FAR *plItemCount,
    /* [out] */ IWiaItem __RPC_FAR *__RPC_FAR *__RPC_FAR *pIWiaItem);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
