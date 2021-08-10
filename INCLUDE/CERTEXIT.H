#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Aug 25 16:06:01 1999
 */
/* Compiler settings for certexit.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __certexit_h__
#define __certexit_h__

/* Forward Declarations */ 

#ifndef __ICertExit_FWD_DEFINED__
#define __ICertExit_FWD_DEFINED__
typedef interface ICertExit ICertExit;
#endif 	/* __ICertExit_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "certmod.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_certexit_0000 */
/* [local] */ 

#define	EXITEVENT_INVALID	( 0 )

#define	EXITEVENT_CERTISSUED	( 0x1 )

#define	EXITEVENT_CERTPENDING	( 0x2 )

#define	EXITEVENT_CERTDENIED	( 0x4 )

#define	EXITEVENT_CERTREVOKED	( 0x8 )

#define	EXITEVENT_CERTRETRIEVEPENDING	( 0x10 )

#define	EXITEVENT_CRLISSUED	( 0x20 )

#define	EXITEVENT_SHUTDOWN	( 0x40 )



extern RPC_IF_HANDLE __MIDL_itf_certexit_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_certexit_0000_v0_0_s_ifspec;

#ifndef __ICertExit_INTERFACE_DEFINED__
#define __ICertExit_INTERFACE_DEFINED__

/* interface ICertExit */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICertExit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e19ae1a0-7364-11d0-8816-00a0c903b83c")
    ICertExit : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ const BSTR strConfig,
            /* [retval][out] */ LONG __RPC_FAR *pEventMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [in] */ LONG ExitEvent,
            /* [in] */ LONG Context) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [retval][out] */ BSTR __RPC_FAR *pstrDescription) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICertExitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICertExit __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICertExit __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICertExit __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ const BSTR strConfig,
            /* [retval][out] */ LONG __RPC_FAR *pEventMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Notify )( 
            ICertExit __RPC_FAR * This,
            /* [in] */ LONG ExitEvent,
            /* [in] */ LONG Context);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ICertExit __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pstrDescription);
        
        END_INTERFACE
    } ICertExitVtbl;

    interface ICertExit
    {
        CONST_VTBL struct ICertExitVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICertExit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICertExit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICertExit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICertExit_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICertExit_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICertExit_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICertExit_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICertExit_Initialize(This,strConfig,pEventMask)	\
    (This)->lpVtbl -> Initialize(This,strConfig,pEventMask)

#define ICertExit_Notify(This,ExitEvent,Context)	\
    (This)->lpVtbl -> Notify(This,ExitEvent,Context)

#define ICertExit_GetDescription(This,pstrDescription)	\
    (This)->lpVtbl -> GetDescription(This,pstrDescription)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICertExit_Initialize_Proxy( 
    ICertExit __RPC_FAR * This,
    /* [in] */ const BSTR strConfig,
    /* [retval][out] */ LONG __RPC_FAR *pEventMask);


void __RPC_STUB ICertExit_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICertExit_Notify_Proxy( 
    ICertExit __RPC_FAR * This,
    /* [in] */ LONG ExitEvent,
    /* [in] */ LONG Context);


void __RPC_STUB ICertExit_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICertExit_GetDescription_Proxy( 
    ICertExit __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pstrDescription);


void __RPC_STUB ICertExit_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICertExit_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
