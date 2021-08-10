#pragma option push -b -a8 -pc -A- /*P_O_Push*/
/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0158 */
/* at Mon May 18 01:55:13 1998
 */
/* Compiler settings for sspsidl.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
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

#ifndef __sspsidl_h__
#define __sspsidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IByteBuffer_FWD_DEFINED__
#define __IByteBuffer_FWD_DEFINED__
typedef interface IByteBuffer IByteBuffer;
#endif 	/* __IByteBuffer_FWD_DEFINED__ */


#ifndef __ISCardTypeConv_FWD_DEFINED__
#define __ISCardTypeConv_FWD_DEFINED__
typedef interface ISCardTypeConv ISCardTypeConv;
#endif 	/* __ISCardTypeConv_FWD_DEFINED__ */


#ifndef __ISCardCmd_FWD_DEFINED__
#define __ISCardCmd_FWD_DEFINED__
typedef interface ISCardCmd ISCardCmd;
#endif 	/* __ISCardCmd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_sspsidl_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Smart Card Support
//  Copyright (C) Microsoft Corporation, 1996 - 1999
//
//
// File: SspsIdl.h
//
//--------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//
// Imports
//




//////////////////////////////////////////////////////////////////
//
// Types and Constants
//
#ifndef _NULL_DEFINED
#define _NULL_DEFINED
#endif // !_NULL_DEFINED
#ifndef _BYTE_DEFINED
#define _BYTE_DEFINED
typedef /* [public] */ unsigned char BYTE;

#endif // !_BYTE_DEFINED
#ifndef _LPBYTE_DEFINED
#define _LPBYTE_DEFINED
typedef /* [public] */ BYTE __RPC_FAR *LPBYTE;

#endif // !_LPBYTE_DEFINED
#ifndef _LPCBYTE_DEFINED
#define _LPCBYTE_DEFINED
typedef /* [public] */ const BYTE __RPC_FAR *LPCBYTE;

#endif // !_LPCBYTE_DEFINED
#ifndef _BYTEARRAY_DEFINED
#define _BYTEARRAY_DEFINED
typedef /* [version][helpstring] */ struct  tagBYTEARRAY
    {
    HGLOBAL hMem;
    DWORD dwSize;
    /* [size_is] */ LPBYTE pbyData;
    }	BYTEARRAY;

#define _CB_BYTEARRAY_DEFINED
#define CB_BYTEARRAY     (sizeof(BYTEARRAY))
#define _PBYTEARRAY_DEFINED
typedef /* [public] */ BYTEARRAY __RPC_FAR *PBYTEARRAY;

#define _PCBYTEARRAY_DEFINED
typedef /* [public] */ const BYTEARRAY __RPC_FAR *PCBYTEARRAY;

#define _LPBYTEARRAY_DEFINED
typedef /* [public] */ BYTEARRAY __RPC_FAR *LPBYTEARRAY;

#define _LPCBYTEARRAY_DEFINED
typedef /* [public] */ const BYTEARRAY __RPC_FAR *LPCBYTEARRAY;

#endif // _BYTEARRAY_DEFINED
#ifndef _STATSTRUCT
#define _STATSTRUCT
typedef /* [version][helpstring] */ struct  tagSTATSTRUCT
    {
    LONG type;
    LONG cbSize;
    LONG grfMode;
    LONG grfLocksSupported;
    LONG grfStateBits;
    }	STATSTRUCT;

#define _CB_STATSTRUCT_DEFINED
#define CB_STATSTRUCT    (sizeof(STATSTRUCT))
#define _LPSTATSTRUCT_DEFINED
typedef /* [public] */ STATSTRUCT __RPC_FAR *LPSTATSTRUCT;

#endif // _STATSTRUCT_DEFINED
#ifndef _ISO_APDU_TYPE
#define _ISO_APDU_TYPE
typedef /* [version][helpstring] */ 
enum tagISO_APDU_TYPE
    {	ISO_CASE_1	= 1,
	ISO_CASE_2	= 2,
	ISO_CASE_3	= 3,
	ISO_CASE_4	= 4
    }	ISO_APDU_TYPE;

#endif // _ISO_APDU_TYPE

//////////////////////////////////////////////////////////////////
//
// IByteBuffer Interface
//
#ifndef _LPBYTEBUFFER_DEFINED
#define _LPBYTEBUFFER_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0000_v0_0_s_ifspec;

#ifndef __IByteBuffer_INTERFACE_DEFINED__
#define __IByteBuffer_INTERFACE_DEFINED__

/* interface IByteBuffer */
/* [unique][helpstring][uuid][object] */ 

typedef /* [unique] */ IByteBuffer __RPC_FAR *LPBYTEBUFFER;

typedef /* [unique] */ const IByteBuffer __RPC_FAR *LPCBYTEBUFFER;


EXTERN_C const IID IID_IByteBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E126F8FE-A7AF-11D0-B88A-00C04FD424B9")
    IByteBuffer : public IDispatch
    {
    public:
        virtual /* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_Stream( 
            /* [retval][out] */ LPSTREAM __RPC_FAR *ppStream) = 0;
        
        virtual /* [helpstring][hidden][propput][id] */ HRESULT STDMETHODCALLTYPE put_Stream( 
            /* [in] */ LPSTREAM pStream) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out][in] */ LPBYTEBUFFER __RPC_FAR *ppByteBuffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ LONG grfCommitFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [out][in] */ LPBYTEBUFFER __RPC_FAR *pByteBuffer,
            /* [in] */ LONG cb,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead = 0,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbWritten = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [defaultvalue][in] */ LONG lSize = 1,
            /* [defaultvalue][in] */ BYTE __RPC_FAR *pData = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockRegion( 
            /* [in] */ LONG libOffset,
            /* [in] */ LONG cb,
            /* [in] */ LONG dwLockType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [out][in] */ BYTE __RPC_FAR *pByte,
            /* [in] */ LONG cb,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Revert( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ LONG dLibMove,
            /* [in] */ LONG dwOrigin,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pLibnewPosition = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ LONG libNewSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stat( 
            /* [out][in] */ LPSTATSTRUCT pstatstg,
            /* [in] */ LONG grfStatFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockRegion( 
            /* [in] */ LONG libOffset,
            /* [in] */ LONG cb,
            /* [in] */ LONG dwLockType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [out][in] */ BYTE __RPC_FAR *pByte,
            /* [in] */ LONG cb,
            /* [out][in] */ LONG __RPC_FAR *pcbWritten) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IByteBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IByteBuffer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IByteBuffer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IByteBuffer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Stream )( 
            IByteBuffer __RPC_FAR * This,
            /* [retval][out] */ LPSTREAM __RPC_FAR *ppStream);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Stream )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LPSTREAM pStream);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IByteBuffer __RPC_FAR * This,
            /* [out][in] */ LPBYTEBUFFER __RPC_FAR *ppByteBuffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LONG grfCommitFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyTo )( 
            IByteBuffer __RPC_FAR * This,
            /* [out][in] */ LPBYTEBUFFER __RPC_FAR *pByteBuffer,
            /* [in] */ LONG cb,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbWritten);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IByteBuffer __RPC_FAR * This,
            /* [defaultvalue][in] */ LONG lSize,
            /* [defaultvalue][in] */ BYTE __RPC_FAR *pData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockRegion )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LONG libOffset,
            /* [in] */ LONG cb,
            /* [in] */ LONG dwLockType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Read )( 
            IByteBuffer __RPC_FAR * This,
            /* [out][in] */ BYTE __RPC_FAR *pByte,
            /* [in] */ LONG cb,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Revert )( 
            IByteBuffer __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LONG dLibMove,
            /* [in] */ LONG dwOrigin,
            /* [defaultvalue][out][in] */ LONG __RPC_FAR *pLibnewPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LONG libNewSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stat )( 
            IByteBuffer __RPC_FAR * This,
            /* [out][in] */ LPSTATSTRUCT pstatstg,
            /* [in] */ LONG grfStatFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnlockRegion )( 
            IByteBuffer __RPC_FAR * This,
            /* [in] */ LONG libOffset,
            /* [in] */ LONG cb,
            /* [in] */ LONG dwLockType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )( 
            IByteBuffer __RPC_FAR * This,
            /* [out][in] */ BYTE __RPC_FAR *pByte,
            /* [in] */ LONG cb,
            /* [out][in] */ LONG __RPC_FAR *pcbWritten);
        
        END_INTERFACE
    } IByteBufferVtbl;

    interface IByteBuffer
    {
        CONST_VTBL struct IByteBufferVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IByteBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IByteBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IByteBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IByteBuffer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IByteBuffer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IByteBuffer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IByteBuffer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IByteBuffer_get_Stream(This,ppStream)	\
    (This)->lpVtbl -> get_Stream(This,ppStream)

#define IByteBuffer_put_Stream(This,pStream)	\
    (This)->lpVtbl -> put_Stream(This,pStream)

#define IByteBuffer_Clone(This,ppByteBuffer)	\
    (This)->lpVtbl -> Clone(This,ppByteBuffer)

#define IByteBuffer_Commit(This,grfCommitFlags)	\
    (This)->lpVtbl -> Commit(This,grfCommitFlags)

#define IByteBuffer_CopyTo(This,pByteBuffer,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pByteBuffer,cb,pcbRead,pcbWritten)

#define IByteBuffer_Initialize(This,lSize,pData)	\
    (This)->lpVtbl -> Initialize(This,lSize,pData)

#define IByteBuffer_LockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType)

#define IByteBuffer_Read(This,pByte,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pByte,cb,pcbRead)

#define IByteBuffer_Revert(This)	\
    (This)->lpVtbl -> Revert(This)

#define IByteBuffer_Seek(This,dLibMove,dwOrigin,pLibnewPosition)	\
    (This)->lpVtbl -> Seek(This,dLibMove,dwOrigin,pLibnewPosition)

#define IByteBuffer_SetSize(This,libNewSize)	\
    (This)->lpVtbl -> SetSize(This,libNewSize)

#define IByteBuffer_Stat(This,pstatstg,grfStatFlag)	\
    (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag)

#define IByteBuffer_UnlockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType)

#define IByteBuffer_Write(This,pByte,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pByte,cb,pcbWritten)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_get_Stream_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [retval][out] */ LPSTREAM __RPC_FAR *ppStream);


void __RPC_STUB IByteBuffer_get_Stream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden][propput][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_put_Stream_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LPSTREAM pStream);


void __RPC_STUB IByteBuffer_put_Stream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Clone_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [out][in] */ LPBYTEBUFFER __RPC_FAR *ppByteBuffer);


void __RPC_STUB IByteBuffer_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Commit_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LONG grfCommitFlags);


void __RPC_STUB IByteBuffer_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_CopyTo_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [out][in] */ LPBYTEBUFFER __RPC_FAR *pByteBuffer,
    /* [in] */ LONG cb,
    /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead,
    /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbWritten);


void __RPC_STUB IByteBuffer_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Initialize_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [defaultvalue][in] */ LONG lSize,
    /* [defaultvalue][in] */ BYTE __RPC_FAR *pData);


void __RPC_STUB IByteBuffer_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_LockRegion_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LONG libOffset,
    /* [in] */ LONG cb,
    /* [in] */ LONG dwLockType);


void __RPC_STUB IByteBuffer_LockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Read_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [out][in] */ BYTE __RPC_FAR *pByte,
    /* [in] */ LONG cb,
    /* [defaultvalue][out][in] */ LONG __RPC_FAR *pcbRead);


void __RPC_STUB IByteBuffer_Read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Revert_Proxy( 
    IByteBuffer __RPC_FAR * This);


void __RPC_STUB IByteBuffer_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Seek_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LONG dLibMove,
    /* [in] */ LONG dwOrigin,
    /* [defaultvalue][out][in] */ LONG __RPC_FAR *pLibnewPosition);


void __RPC_STUB IByteBuffer_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_SetSize_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LONG libNewSize);


void __RPC_STUB IByteBuffer_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Stat_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [out][in] */ LPSTATSTRUCT pstatstg,
    /* [in] */ LONG grfStatFlag);


void __RPC_STUB IByteBuffer_Stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_UnlockRegion_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [in] */ LONG libOffset,
    /* [in] */ LONG cb,
    /* [in] */ LONG dwLockType);


void __RPC_STUB IByteBuffer_UnlockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IByteBuffer_Write_Proxy( 
    IByteBuffer __RPC_FAR * This,
    /* [out][in] */ BYTE __RPC_FAR *pByte,
    /* [in] */ LONG cb,
    /* [out][in] */ LONG __RPC_FAR *pcbWritten);


void __RPC_STUB IByteBuffer_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IByteBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sspsidl_0104 */
/* [local] */ 

#endif //_LPBYTEBUFFER_DEFINED

//////////////////////////////////////////////////////////////////
//
// ISCardTypeConv Interface Definition
//
#ifndef _LPSCARDTYPECONV_DEFINED
#define _LPSCARDTYPECONV_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0104_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0104_v0_0_s_ifspec;

#ifndef __ISCardTypeConv_INTERFACE_DEFINED__
#define __ISCardTypeConv_INTERFACE_DEFINED__

/* interface ISCardTypeConv */
/* [unique][version][helpstring][uuid][object] */ 

typedef /* [unique] */ ISCardTypeConv __RPC_FAR *LPSCARDTYPECONV;


EXTERN_C const IID IID_ISCardTypeConv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53B6AA63-3F56-11D0-916B-00AA00C18068")
    ISCardTypeConv : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertByteArrayToByteBuffer( 
            /* [in] */ LPBYTE pbyArray,
            /* [in] */ DWORD dwArraySize,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertByteBufferToByteArray( 
            /* [in] */ LPBYTEBUFFER pbyBuffer,
            /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertByteBufferToSafeArray( 
            /* [in] */ LPBYTEBUFFER pbyBuffer,
            /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppbyArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertSafeArrayToByteBuffer( 
            /* [in] */ LPSAFEARRAY pbyArray,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateByteArray( 
            /* [in] */ DWORD dwAllocSize,
            /* [retval][out] */ LPBYTE __RPC_FAR *ppbyArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateByteBuffer( 
            /* [in] */ DWORD dwAllocSize,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSafeArray( 
            /* [in] */ UINT nAllocSize,
            /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeIStreamMemoryPtr( 
            /* [in] */ LPSTREAM pStrm,
            /* [in] */ LPBYTE pMem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAtIStreamMemory( 
            /* [in] */ LPSTREAM pStrm,
            /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppMem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SizeOfIStream( 
            /* [in] */ LPSTREAM pStrm,
            /* [retval][out] */ ULARGE_INTEGER __RPC_FAR *puliSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCardTypeConvVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISCardTypeConv __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISCardTypeConv __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertByteArrayToByteBuffer )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPBYTE pbyArray,
            /* [in] */ DWORD dwArraySize,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertByteBufferToByteArray )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pbyBuffer,
            /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertByteBufferToSafeArray )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pbyBuffer,
            /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppbyArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertSafeArrayToByteBuffer )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPSAFEARRAY pbyArray,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateByteArray )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ DWORD dwAllocSize,
            /* [retval][out] */ LPBYTE __RPC_FAR *ppbyArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateByteBuffer )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ DWORD dwAllocSize,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSafeArray )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ UINT nAllocSize,
            /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeIStreamMemoryPtr )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPSTREAM pStrm,
            /* [in] */ LPBYTE pMem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAtIStreamMemory )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPSTREAM pStrm,
            /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppMem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SizeOfIStream )( 
            ISCardTypeConv __RPC_FAR * This,
            /* [in] */ LPSTREAM pStrm,
            /* [retval][out] */ ULARGE_INTEGER __RPC_FAR *puliSize);
        
        END_INTERFACE
    } ISCardTypeConvVtbl;

    interface ISCardTypeConv
    {
        CONST_VTBL struct ISCardTypeConvVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCardTypeConv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISCardTypeConv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISCardTypeConv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISCardTypeConv_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISCardTypeConv_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISCardTypeConv_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISCardTypeConv_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISCardTypeConv_ConvertByteArrayToByteBuffer(This,pbyArray,dwArraySize,ppbyBuffer)	\
    (This)->lpVtbl -> ConvertByteArrayToByteBuffer(This,pbyArray,dwArraySize,ppbyBuffer)

#define ISCardTypeConv_ConvertByteBufferToByteArray(This,pbyBuffer,ppArray)	\
    (This)->lpVtbl -> ConvertByteBufferToByteArray(This,pbyBuffer,ppArray)

#define ISCardTypeConv_ConvertByteBufferToSafeArray(This,pbyBuffer,ppbyArray)	\
    (This)->lpVtbl -> ConvertByteBufferToSafeArray(This,pbyBuffer,ppbyArray)

#define ISCardTypeConv_ConvertSafeArrayToByteBuffer(This,pbyArray,ppbyBuff)	\
    (This)->lpVtbl -> ConvertSafeArrayToByteBuffer(This,pbyArray,ppbyBuff)

#define ISCardTypeConv_CreateByteArray(This,dwAllocSize,ppbyArray)	\
    (This)->lpVtbl -> CreateByteArray(This,dwAllocSize,ppbyArray)

#define ISCardTypeConv_CreateByteBuffer(This,dwAllocSize,ppbyBuff)	\
    (This)->lpVtbl -> CreateByteBuffer(This,dwAllocSize,ppbyBuff)

#define ISCardTypeConv_CreateSafeArray(This,nAllocSize,ppArray)	\
    (This)->lpVtbl -> CreateSafeArray(This,nAllocSize,ppArray)

#define ISCardTypeConv_FreeIStreamMemoryPtr(This,pStrm,pMem)	\
    (This)->lpVtbl -> FreeIStreamMemoryPtr(This,pStrm,pMem)

#define ISCardTypeConv_GetAtIStreamMemory(This,pStrm,ppMem)	\
    (This)->lpVtbl -> GetAtIStreamMemory(This,pStrm,ppMem)

#define ISCardTypeConv_SizeOfIStream(This,pStrm,puliSize)	\
    (This)->lpVtbl -> SizeOfIStream(This,pStrm,puliSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_ConvertByteArrayToByteBuffer_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPBYTE pbyArray,
    /* [in] */ DWORD dwArraySize,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuffer);


void __RPC_STUB ISCardTypeConv_ConvertByteArrayToByteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_ConvertByteBufferToByteArray_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pbyBuffer,
    /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppArray);


void __RPC_STUB ISCardTypeConv_ConvertByteBufferToByteArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_ConvertByteBufferToSafeArray_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pbyBuffer,
    /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppbyArray);


void __RPC_STUB ISCardTypeConv_ConvertByteBufferToSafeArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_ConvertSafeArrayToByteBuffer_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPSAFEARRAY pbyArray,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff);


void __RPC_STUB ISCardTypeConv_ConvertSafeArrayToByteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_CreateByteArray_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ DWORD dwAllocSize,
    /* [retval][out] */ LPBYTE __RPC_FAR *ppbyArray);


void __RPC_STUB ISCardTypeConv_CreateByteArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_CreateByteBuffer_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ DWORD dwAllocSize,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppbyBuff);


void __RPC_STUB ISCardTypeConv_CreateByteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_CreateSafeArray_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ UINT nAllocSize,
    /* [retval][out] */ LPSAFEARRAY __RPC_FAR *ppArray);


void __RPC_STUB ISCardTypeConv_CreateSafeArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_FreeIStreamMemoryPtr_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPSTREAM pStrm,
    /* [in] */ LPBYTE pMem);


void __RPC_STUB ISCardTypeConv_FreeIStreamMemoryPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_GetAtIStreamMemory_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPSTREAM pStrm,
    /* [retval][out] */ LPBYTEARRAY __RPC_FAR *ppMem);


void __RPC_STUB ISCardTypeConv_GetAtIStreamMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardTypeConv_SizeOfIStream_Proxy( 
    ISCardTypeConv __RPC_FAR * This,
    /* [in] */ LPSTREAM pStrm,
    /* [retval][out] */ ULARGE_INTEGER __RPC_FAR *puliSize);


void __RPC_STUB ISCardTypeConv_SizeOfIStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISCardTypeConv_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sspsidl_0106 */
/* [local] */ 

#endif // _LPSCARDTYPECONV_DEFINED

//////////////////////////////////////////////////////////////////
//
// ISCardCmd Interface Definition
//
#ifndef _LPSCARDCMD_DEFINED
#define _LPSCARDCMD_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0106_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0106_v0_0_s_ifspec;

#ifndef __ISCardCmd_INTERFACE_DEFINED__
#define __ISCardCmd_INTERFACE_DEFINED__

/* interface ISCardCmd */
/* [unique][version][helpstring][uuid][object] */ 

typedef /* [unique] */ ISCardCmd __RPC_FAR *LPSCARDCMD;


EXTERN_C const IID IID_ISCardCmd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5778AE3-43DE-11D0-9171-00AA00C18068")
    ISCardCmd : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Apdu( 
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppApdu) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Apdu( 
            /* [in] */ LPBYTEBUFFER pApdu) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ApduLength( 
            /* [retval][out] */ LONG __RPC_FAR *plSize) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ApduReply( 
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppReplyApdu) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ApduReply( 
            /* [in] */ LPBYTEBUFFER pReplyApdu) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ApduReplyLength( 
            /* [retval][out] */ LONG __RPC_FAR *plSize) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ApduReplyLength( 
            /* [in] */ LONG lSize) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ClassId( 
            /* [retval][out] */ BYTE __RPC_FAR *pbyClass) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ClassId( 
            /* [defaultvalue][in] */ BYTE byClass = 0) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppData) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [in] */ LPBYTEBUFFER pData) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_InstructionId( 
            /* [retval][out] */ BYTE __RPC_FAR *pbyIns) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_InstructionId( 
            /* [in] */ BYTE byIns) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LeField( 
            /* [retval][out] */ LONG __RPC_FAR *plSize) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_P1( 
            /* [retval][out] */ BYTE __RPC_FAR *pbyP1) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_P1( 
            /* [in] */ BYTE byP1) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_P2( 
            /* [retval][out] */ BYTE __RPC_FAR *pbyP2) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_P2( 
            /* [in] */ BYTE byP2) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_P3( 
            /* [retval][out] */ BYTE __RPC_FAR *pbyP3) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReplyStatus( 
            /* [retval][out] */ LPWORD pwStatus) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ReplyStatus( 
            /* [in] */ WORD wStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReplyStatusSW1( 
            /* [retval][out] */ BYTE __RPC_FAR *pbySW1) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReplyStatusSW2( 
            /* [retval][out] */ BYTE __RPC_FAR *pbySW2) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ ISO_APDU_TYPE __RPC_FAR *pType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Nad( 
            /* [retval][out] */ BYTE __RPC_FAR *pbNad) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Nad( 
            /* [in] */ BYTE bNad) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReplyNad( 
            /* [retval][out] */ BYTE __RPC_FAR *pbNad) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ReplyNad( 
            /* [in] */ BYTE bNad) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BuildCmd( 
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [defaultvalue][in] */ BYTE byP1 = 0,
            /* [defaultvalue][in] */ BYTE byP2 = 0,
            /* [defaultvalue][in] */ LPBYTEBUFFER pbyData = 0,
            /* [defaultvalue][in] */ LONG __RPC_FAR *plLe = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encapsulate( 
            /* [in] */ LPBYTEBUFFER pApdu,
            /* [in] */ ISO_APDU_TYPE ApduType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCardCmdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISCardCmd __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISCardCmd __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISCardCmd __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Apdu )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppApdu);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Apdu )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pApdu);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ApduLength )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plSize);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ApduReply )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppReplyApdu);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ApduReply )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pReplyApdu);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ApduReplyLength )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plSize);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ApduReplyLength )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ LONG lSize);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClassId )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbyClass);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClassId )( 
            ISCardCmd __RPC_FAR * This,
            /* [defaultvalue][in] */ BYTE byClass);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Data )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppData);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Data )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pData);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InstructionId )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbyIns);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_InstructionId )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE byIns);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LeField )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plSize);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_P1 )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbyP1);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_P1 )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE byP1);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_P2 )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbyP2);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_P2 )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE byP2);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_P3 )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbyP3);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReplyStatus )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ LPWORD pwStatus);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReplyStatus )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ WORD wStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReplyStatusSW1 )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbySW1);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReplyStatusSW2 )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbySW2);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ ISO_APDU_TYPE __RPC_FAR *pType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Nad )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbNad);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Nad )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE bNad);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReplyNad )( 
            ISCardCmd __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pbNad);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReplyNad )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE bNad);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildCmd )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [defaultvalue][in] */ BYTE byP1,
            /* [defaultvalue][in] */ BYTE byP2,
            /* [defaultvalue][in] */ LPBYTEBUFFER pbyData,
            /* [defaultvalue][in] */ LONG __RPC_FAR *plLe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            ISCardCmd __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Encapsulate )( 
            ISCardCmd __RPC_FAR * This,
            /* [in] */ LPBYTEBUFFER pApdu,
            /* [in] */ ISO_APDU_TYPE ApduType);
        
        END_INTERFACE
    } ISCardCmdVtbl;

    interface ISCardCmd
    {
        CONST_VTBL struct ISCardCmdVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCardCmd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISCardCmd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISCardCmd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISCardCmd_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISCardCmd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISCardCmd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISCardCmd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISCardCmd_get_Apdu(This,ppApdu)	\
    (This)->lpVtbl -> get_Apdu(This,ppApdu)

#define ISCardCmd_put_Apdu(This,pApdu)	\
    (This)->lpVtbl -> put_Apdu(This,pApdu)

#define ISCardCmd_get_ApduLength(This,plSize)	\
    (This)->lpVtbl -> get_ApduLength(This,plSize)

#define ISCardCmd_get_ApduReply(This,ppReplyApdu)	\
    (This)->lpVtbl -> get_ApduReply(This,ppReplyApdu)

#define ISCardCmd_put_ApduReply(This,pReplyApdu)	\
    (This)->lpVtbl -> put_ApduReply(This,pReplyApdu)

#define ISCardCmd_get_ApduReplyLength(This,plSize)	\
    (This)->lpVtbl -> get_ApduReplyLength(This,plSize)

#define ISCardCmd_put_ApduReplyLength(This,lSize)	\
    (This)->lpVtbl -> put_ApduReplyLength(This,lSize)

#define ISCardCmd_get_ClassId(This,pbyClass)	\
    (This)->lpVtbl -> get_ClassId(This,pbyClass)

#define ISCardCmd_put_ClassId(This,byClass)	\
    (This)->lpVtbl -> put_ClassId(This,byClass)

#define ISCardCmd_get_Data(This,ppData)	\
    (This)->lpVtbl -> get_Data(This,ppData)

#define ISCardCmd_put_Data(This,pData)	\
    (This)->lpVtbl -> put_Data(This,pData)

#define ISCardCmd_get_InstructionId(This,pbyIns)	\
    (This)->lpVtbl -> get_InstructionId(This,pbyIns)

#define ISCardCmd_put_InstructionId(This,byIns)	\
    (This)->lpVtbl -> put_InstructionId(This,byIns)

#define ISCardCmd_get_LeField(This,plSize)	\
    (This)->lpVtbl -> get_LeField(This,plSize)

#define ISCardCmd_get_P1(This,pbyP1)	\
    (This)->lpVtbl -> get_P1(This,pbyP1)

#define ISCardCmd_put_P1(This,byP1)	\
    (This)->lpVtbl -> put_P1(This,byP1)

#define ISCardCmd_get_P2(This,pbyP2)	\
    (This)->lpVtbl -> get_P2(This,pbyP2)

#define ISCardCmd_put_P2(This,byP2)	\
    (This)->lpVtbl -> put_P2(This,byP2)

#define ISCardCmd_get_P3(This,pbyP3)	\
    (This)->lpVtbl -> get_P3(This,pbyP3)

#define ISCardCmd_get_ReplyStatus(This,pwStatus)	\
    (This)->lpVtbl -> get_ReplyStatus(This,pwStatus)

#define ISCardCmd_put_ReplyStatus(This,wStatus)	\
    (This)->lpVtbl -> put_ReplyStatus(This,wStatus)

#define ISCardCmd_get_ReplyStatusSW1(This,pbySW1)	\
    (This)->lpVtbl -> get_ReplyStatusSW1(This,pbySW1)

#define ISCardCmd_get_ReplyStatusSW2(This,pbySW2)	\
    (This)->lpVtbl -> get_ReplyStatusSW2(This,pbySW2)

#define ISCardCmd_get_Type(This,pType)	\
    (This)->lpVtbl -> get_Type(This,pType)

#define ISCardCmd_get_Nad(This,pbNad)	\
    (This)->lpVtbl -> get_Nad(This,pbNad)

#define ISCardCmd_put_Nad(This,bNad)	\
    (This)->lpVtbl -> put_Nad(This,bNad)

#define ISCardCmd_get_ReplyNad(This,pbNad)	\
    (This)->lpVtbl -> get_ReplyNad(This,pbNad)

#define ISCardCmd_put_ReplyNad(This,bNad)	\
    (This)->lpVtbl -> put_ReplyNad(This,bNad)

#define ISCardCmd_BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,plLe)	\
    (This)->lpVtbl -> BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,plLe)

#define ISCardCmd_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define ISCardCmd_Encapsulate(This,pApdu,ApduType)	\
    (This)->lpVtbl -> Encapsulate(This,pApdu,ApduType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_Apdu_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppApdu);


void __RPC_STUB ISCardCmd_get_Apdu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_Apdu_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pApdu);


void __RPC_STUB ISCardCmd_put_Apdu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ApduLength_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plSize);


void __RPC_STUB ISCardCmd_get_ApduLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ApduReply_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppReplyApdu);


void __RPC_STUB ISCardCmd_get_ApduReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_ApduReply_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pReplyApdu);


void __RPC_STUB ISCardCmd_put_ApduReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ApduReplyLength_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plSize);


void __RPC_STUB ISCardCmd_get_ApduReplyLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_ApduReplyLength_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ LONG lSize);


void __RPC_STUB ISCardCmd_put_ApduReplyLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ClassId_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbyClass);


void __RPC_STUB ISCardCmd_get_ClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_ClassId_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [defaultvalue][in] */ BYTE byClass);


void __RPC_STUB ISCardCmd_put_ClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_Data_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LPBYTEBUFFER __RPC_FAR *ppData);


void __RPC_STUB ISCardCmd_get_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_Data_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pData);


void __RPC_STUB ISCardCmd_put_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_InstructionId_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbyIns);


void __RPC_STUB ISCardCmd_get_InstructionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_InstructionId_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE byIns);


void __RPC_STUB ISCardCmd_put_InstructionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_LeField_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plSize);


void __RPC_STUB ISCardCmd_get_LeField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_P1_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbyP1);


void __RPC_STUB ISCardCmd_get_P1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_P1_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE byP1);


void __RPC_STUB ISCardCmd_put_P1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_P2_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbyP2);


void __RPC_STUB ISCardCmd_get_P2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_P2_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE byP2);


void __RPC_STUB ISCardCmd_put_P2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_P3_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbyP3);


void __RPC_STUB ISCardCmd_get_P3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ReplyStatus_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ LPWORD pwStatus);


void __RPC_STUB ISCardCmd_get_ReplyStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_ReplyStatus_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ WORD wStatus);


void __RPC_STUB ISCardCmd_put_ReplyStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ReplyStatusSW1_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbySW1);


void __RPC_STUB ISCardCmd_get_ReplyStatusSW1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ReplyStatusSW2_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbySW2);


void __RPC_STUB ISCardCmd_get_ReplyStatusSW2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_Type_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ ISO_APDU_TYPE __RPC_FAR *pType);


void __RPC_STUB ISCardCmd_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_Nad_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbNad);


void __RPC_STUB ISCardCmd_get_Nad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_Nad_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE bNad);


void __RPC_STUB ISCardCmd_put_Nad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_get_ReplyNad_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pbNad);


void __RPC_STUB ISCardCmd_get_ReplyNad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_put_ReplyNad_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE bNad);


void __RPC_STUB ISCardCmd_put_ReplyNad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_BuildCmd_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ BYTE byClassId,
    /* [in] */ BYTE byInsId,
    /* [defaultvalue][in] */ BYTE byP1,
    /* [defaultvalue][in] */ BYTE byP2,
    /* [defaultvalue][in] */ LPBYTEBUFFER pbyData,
    /* [defaultvalue][in] */ LONG __RPC_FAR *plLe);


void __RPC_STUB ISCardCmd_BuildCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_Clear_Proxy( 
    ISCardCmd __RPC_FAR * This);


void __RPC_STUB ISCardCmd_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISCardCmd_Encapsulate_Proxy( 
    ISCardCmd __RPC_FAR * This,
    /* [in] */ LPBYTEBUFFER pApdu,
    /* [in] */ ISO_APDU_TYPE ApduType);


void __RPC_STUB ISCardCmd_Encapsulate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISCardCmd_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sspsidl_0108 */
/* [local] */ 

#endif //!_LPSCARDCMD_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0108_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sspsidl_0108_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HGLOBAL_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HGLOBAL __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  HGLOBAL_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HGLOBAL __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  HGLOBAL_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HGLOBAL __RPC_FAR * ); 
void                      __RPC_USER  HGLOBAL_UserFree(     unsigned long __RPC_FAR *, HGLOBAL __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma option pop /*P_O_Pop*/
