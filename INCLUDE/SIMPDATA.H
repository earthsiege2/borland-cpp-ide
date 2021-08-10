#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0266 */
/* at Mon May 24 10:51:37 1999
 */
/* Compiler settings for simpdata.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
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

#ifndef __simpdata_h__
#define __simpdata_h__

/* Forward Declarations */ 

#ifndef __OLEDBSimpleProviderListener_FWD_DEFINED__
#define __OLEDBSimpleProviderListener_FWD_DEFINED__
typedef interface OLEDBSimpleProviderListener OLEDBSimpleProviderListener;
#endif 	/* __OLEDBSimpleProviderListener_FWD_DEFINED__ */


#ifndef __OLEDBSimpleProvider_FWD_DEFINED__
#define __OLEDBSimpleProvider_FWD_DEFINED__
typedef interface OLEDBSimpleProvider OLEDBSimpleProvider;
#endif 	/* __OLEDBSimpleProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_simpdata_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// simpdata.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//--------------------------------------------------------------------------
// OLE DB Simple Provider Toolkit

#ifndef SIMPDATA_H
#define SIMPDATA_H

#ifdef _WIN64

typedef LONGLONG		DBROWCOUNT;
typedef LONGLONG		DB_LORDINAL;

#else

typedef LONG DBROWCOUNT;

typedef LONG DB_LORDINAL;

#endif	// _WIN64
#define OSP_IndexLabel      (0)
#define OSP_IndexAll        (~0)
#define OSP_IndexUnknown    (~0)



extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_v0_0_s_ifspec;


#ifndef __MSDAOSP_LIBRARY_DEFINED__
#define __MSDAOSP_LIBRARY_DEFINED__

/* library MSDAOSP */
/* [version][lcid][helpstring][uuid] */ 

typedef 
enum OSPFORMAT
    {	OSPFORMAT_RAW	= 0,
	OSPFORMAT_DEFAULT	= 0,
	OSPFORMAT_FORMATTED	= 1,
	OSPFORMAT_HTML	= 2
    }	OSPFORMAT;

typedef 
enum OSPRW
    {	OSPRW_DEFAULT	= 1,
	OSPRW_READONLY	= 0,
	OSPRW_READWRITE	= 1,
	OSPRW_MIXED	= 2
    }	OSPRW;

typedef 
enum OSPFIND
    {	OSPFIND_DEFAULT	= 0,
	OSPFIND_UP	= 1,
	OSPFIND_CASESENSITIVE	= 2,
	OSPFIND_UPCASESENSITIVE	= 3
    }	OSPFIND;

typedef 
enum OSPCOMP
    {	OSPCOMP_EQ	= 1,
	OSPCOMP_DEFAULT	= 1,
	OSPCOMP_LT	= 2,
	OSPCOMP_LE	= 3,
	OSPCOMP_GE	= 4,
	OSPCOMP_GT	= 5,
	OSPCOMP_NE	= 6
    }	OSPCOMP;

typedef 
enum OSPXFER
    {	OSPXFER_COMPLETE	= 0,
	OSPXFER_ABORT	= 1,
	OSPXFER_ERROR	= 2
    }	OSPXFER;

typedef OLEDBSimpleProvider *LPOLEDBSimpleProvider;

EXTERN_C const IID LIBID_MSDAOSP;

#ifndef __OLEDBSimpleProviderListener_INTERFACE_DEFINED__
#define __OLEDBSimpleProviderListener_INTERFACE_DEFINED__

/* interface OLEDBSimpleProviderListener */
/* [version][oleautomation][unique][uuid][object] */ 


EXTERN_C const IID IID_OLEDBSimpleProviderListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0E270C1-C0BE-11d0-8FE4-00A0C90A6341")
    OLEDBSimpleProviderListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE aboutToChangeCell( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE cellChanged( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE aboutToDeleteRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deletedRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE aboutToInsertRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE insertedRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE rowsAvailable( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE transferComplete( 
            /* [in] */ OSPXFER xfer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct OLEDBSimpleProviderListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            OLEDBSimpleProviderListener __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            OLEDBSimpleProviderListener __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *aboutToChangeCell )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *cellChanged )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *aboutToDeleteRows )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *deletedRows )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *aboutToInsertRows )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *insertedRows )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *rowsAvailable )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *transferComplete )( 
            OLEDBSimpleProviderListener __RPC_FAR * This,
            /* [in] */ OSPXFER xfer);
        
        END_INTERFACE
    } OLEDBSimpleProviderListenerVtbl;

    interface OLEDBSimpleProviderListener
    {
        CONST_VTBL struct OLEDBSimpleProviderListenerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OLEDBSimpleProviderListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define OLEDBSimpleProviderListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define OLEDBSimpleProviderListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define OLEDBSimpleProviderListener_aboutToChangeCell(This,iRow,iColumn)	\
    (This)->lpVtbl -> aboutToChangeCell(This,iRow,iColumn)

#define OLEDBSimpleProviderListener_cellChanged(This,iRow,iColumn)	\
    (This)->lpVtbl -> cellChanged(This,iRow,iColumn)

#define OLEDBSimpleProviderListener_aboutToDeleteRows(This,iRow,cRows)	\
    (This)->lpVtbl -> aboutToDeleteRows(This,iRow,cRows)

#define OLEDBSimpleProviderListener_deletedRows(This,iRow,cRows)	\
    (This)->lpVtbl -> deletedRows(This,iRow,cRows)

#define OLEDBSimpleProviderListener_aboutToInsertRows(This,iRow,cRows)	\
    (This)->lpVtbl -> aboutToInsertRows(This,iRow,cRows)

#define OLEDBSimpleProviderListener_insertedRows(This,iRow,cRows)	\
    (This)->lpVtbl -> insertedRows(This,iRow,cRows)

#define OLEDBSimpleProviderListener_rowsAvailable(This,iRow,cRows)	\
    (This)->lpVtbl -> rowsAvailable(This,iRow,cRows)

#define OLEDBSimpleProviderListener_transferComplete(This,xfer)	\
    (This)->lpVtbl -> transferComplete(This,xfer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_aboutToChangeCell_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DB_LORDINAL iColumn);


void __RPC_STUB OLEDBSimpleProviderListener_aboutToChangeCell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_cellChanged_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DB_LORDINAL iColumn);


void __RPC_STUB OLEDBSimpleProviderListener_cellChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_aboutToDeleteRows_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows);


void __RPC_STUB OLEDBSimpleProviderListener_aboutToDeleteRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_deletedRows_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows);


void __RPC_STUB OLEDBSimpleProviderListener_deletedRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_aboutToInsertRows_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows);


void __RPC_STUB OLEDBSimpleProviderListener_aboutToInsertRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_insertedRows_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows);


void __RPC_STUB OLEDBSimpleProviderListener_insertedRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_rowsAvailable_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows);


void __RPC_STUB OLEDBSimpleProviderListener_rowsAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProviderListener_transferComplete_Proxy( 
    OLEDBSimpleProviderListener __RPC_FAR * This,
    /* [in] */ OSPXFER xfer);


void __RPC_STUB OLEDBSimpleProviderListener_transferComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __OLEDBSimpleProviderListener_INTERFACE_DEFINED__ */


#ifndef __OLEDBSimpleProvider_INTERFACE_DEFINED__
#define __OLEDBSimpleProvider_INTERFACE_DEFINED__

/* interface OLEDBSimpleProvider */
/* [version][oleautomation][unique][uuid][object] */ 


EXTERN_C const IID IID_OLEDBSimpleProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0E270C0-C0BE-11d0-8FE4-00A0C90A6341")
    OLEDBSimpleProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getRowCount( 
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getColumnCount( 
            /* [retval][out] */ DB_LORDINAL __RPC_FAR *pcColumns) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRWStatus( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [retval][out] */ OSPRW __RPC_FAR *prwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getVariant( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ OSPFORMAT format,
            /* [retval][out] */ VARIANT __RPC_FAR *pVar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setVariant( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ OSPFORMAT format,
            /* [in] */ VARIANT Var) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getLocale( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLocale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deleteRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsDeleted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE insertRows( 
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsInserted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE find( 
            /* [in] */ DBROWCOUNT iRowStart,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ VARIANT val,
            /* [in] */ OSPFIND findFlags,
            /* [in] */ OSPCOMP compType,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRowFound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE addOLEDBSimpleProviderListener( 
            /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE removeOLEDBSimpleProviderListener( 
            /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isAsync( 
            /* [retval][out] */ BOOL __RPC_FAR *pbAsynch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEstimatedRows( 
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopTransfer( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct OLEDBSimpleProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            OLEDBSimpleProvider __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            OLEDBSimpleProvider __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getRowCount )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getColumnCount )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [retval][out] */ DB_LORDINAL __RPC_FAR *pcColumns);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getRWStatus )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [retval][out] */ OSPRW __RPC_FAR *prwStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getVariant )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ OSPFORMAT format,
            /* [retval][out] */ VARIANT __RPC_FAR *pVar);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setVariant )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ OSPFORMAT format,
            /* [in] */ VARIANT Var);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getLocale )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLocale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *deleteRows )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsDeleted);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *insertRows )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRow,
            /* [in] */ DBROWCOUNT cRows,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsInserted);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *find )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ DBROWCOUNT iRowStart,
            /* [in] */ DB_LORDINAL iColumn,
            /* [in] */ VARIANT val,
            /* [in] */ OSPFIND findFlags,
            /* [in] */ OSPCOMP compType,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRowFound);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *addOLEDBSimpleProviderListener )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *removeOLEDBSimpleProviderListener )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *isAsync )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pbAsynch);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getEstimatedRows )( 
            OLEDBSimpleProvider __RPC_FAR * This,
            /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRows);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *stopTransfer )( 
            OLEDBSimpleProvider __RPC_FAR * This);
        
        END_INTERFACE
    } OLEDBSimpleProviderVtbl;

    interface OLEDBSimpleProvider
    {
        CONST_VTBL struct OLEDBSimpleProviderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OLEDBSimpleProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define OLEDBSimpleProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define OLEDBSimpleProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define OLEDBSimpleProvider_getRowCount(This,pcRows)	\
    (This)->lpVtbl -> getRowCount(This,pcRows)

#define OLEDBSimpleProvider_getColumnCount(This,pcColumns)	\
    (This)->lpVtbl -> getColumnCount(This,pcColumns)

#define OLEDBSimpleProvider_getRWStatus(This,iRow,iColumn,prwStatus)	\
    (This)->lpVtbl -> getRWStatus(This,iRow,iColumn,prwStatus)

#define OLEDBSimpleProvider_getVariant(This,iRow,iColumn,format,pVar)	\
    (This)->lpVtbl -> getVariant(This,iRow,iColumn,format,pVar)

#define OLEDBSimpleProvider_setVariant(This,iRow,iColumn,format,Var)	\
    (This)->lpVtbl -> setVariant(This,iRow,iColumn,format,Var)

#define OLEDBSimpleProvider_getLocale(This,pbstrLocale)	\
    (This)->lpVtbl -> getLocale(This,pbstrLocale)

#define OLEDBSimpleProvider_deleteRows(This,iRow,cRows,pcRowsDeleted)	\
    (This)->lpVtbl -> deleteRows(This,iRow,cRows,pcRowsDeleted)

#define OLEDBSimpleProvider_insertRows(This,iRow,cRows,pcRowsInserted)	\
    (This)->lpVtbl -> insertRows(This,iRow,cRows,pcRowsInserted)

#define OLEDBSimpleProvider_find(This,iRowStart,iColumn,val,findFlags,compType,piRowFound)	\
    (This)->lpVtbl -> find(This,iRowStart,iColumn,val,findFlags,compType,piRowFound)

#define OLEDBSimpleProvider_addOLEDBSimpleProviderListener(This,pospIListener)	\
    (This)->lpVtbl -> addOLEDBSimpleProviderListener(This,pospIListener)

#define OLEDBSimpleProvider_removeOLEDBSimpleProviderListener(This,pospIListener)	\
    (This)->lpVtbl -> removeOLEDBSimpleProviderListener(This,pospIListener)

#define OLEDBSimpleProvider_isAsync(This,pbAsynch)	\
    (This)->lpVtbl -> isAsync(This,pbAsynch)

#define OLEDBSimpleProvider_getEstimatedRows(This,piRows)	\
    (This)->lpVtbl -> getEstimatedRows(This,piRows)

#define OLEDBSimpleProvider_stopTransfer(This)	\
    (This)->lpVtbl -> stopTransfer(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getRowCount_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRows);


void __RPC_STUB OLEDBSimpleProvider_getRowCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getColumnCount_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [retval][out] */ DB_LORDINAL __RPC_FAR *pcColumns);


void __RPC_STUB OLEDBSimpleProvider_getColumnCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getRWStatus_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DB_LORDINAL iColumn,
    /* [retval][out] */ OSPRW __RPC_FAR *prwStatus);


void __RPC_STUB OLEDBSimpleProvider_getRWStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getVariant_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DB_LORDINAL iColumn,
    /* [in] */ OSPFORMAT format,
    /* [retval][out] */ VARIANT __RPC_FAR *pVar);


void __RPC_STUB OLEDBSimpleProvider_getVariant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_setVariant_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DB_LORDINAL iColumn,
    /* [in] */ OSPFORMAT format,
    /* [in] */ VARIANT Var);


void __RPC_STUB OLEDBSimpleProvider_setVariant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getLocale_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrLocale);


void __RPC_STUB OLEDBSimpleProvider_getLocale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_deleteRows_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows,
    /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsDeleted);


void __RPC_STUB OLEDBSimpleProvider_deleteRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_insertRows_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRow,
    /* [in] */ DBROWCOUNT cRows,
    /* [retval][out] */ DBROWCOUNT __RPC_FAR *pcRowsInserted);


void __RPC_STUB OLEDBSimpleProvider_insertRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_find_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ DBROWCOUNT iRowStart,
    /* [in] */ DB_LORDINAL iColumn,
    /* [in] */ VARIANT val,
    /* [in] */ OSPFIND findFlags,
    /* [in] */ OSPCOMP compType,
    /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRowFound);


void __RPC_STUB OLEDBSimpleProvider_find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_addOLEDBSimpleProviderListener_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener);


void __RPC_STUB OLEDBSimpleProvider_addOLEDBSimpleProviderListener_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_removeOLEDBSimpleProviderListener_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [in] */ OLEDBSimpleProviderListener __RPC_FAR *pospIListener);


void __RPC_STUB OLEDBSimpleProvider_removeOLEDBSimpleProviderListener_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_isAsync_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pbAsynch);


void __RPC_STUB OLEDBSimpleProvider_isAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_getEstimatedRows_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This,
    /* [retval][out] */ DBROWCOUNT __RPC_FAR *piRows);


void __RPC_STUB OLEDBSimpleProvider_getEstimatedRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OLEDBSimpleProvider_stopTransfer_Proxy( 
    OLEDBSimpleProvider __RPC_FAR * This);


void __RPC_STUB OLEDBSimpleProvider_stopTransfer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __OLEDBSimpleProvider_INTERFACE_DEFINED__ */

#endif /* __MSDAOSP_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_simpdata_0111 */
/* [local] */ 

#endif


extern RPC_IF_HANDLE __MIDL_itf_simpdata_0111_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simpdata_0111_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
