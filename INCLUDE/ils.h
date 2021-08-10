#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Sat Sep 04 23:41:54 1999
 */
/* Compiler settings for ILS.Idl:
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

#ifndef __ILS_h__
#define __ILS_h__

/* Forward Declarations */ 

#ifndef __IIlsServer_FWD_DEFINED__
#define __IIlsServer_FWD_DEFINED__
typedef interface IIlsServer IIlsServer;
#endif 	/* __IIlsServer_FWD_DEFINED__ */


#ifndef __IIlsMain_FWD_DEFINED__
#define __IIlsMain_FWD_DEFINED__
typedef interface IIlsMain IIlsMain;
#endif 	/* __IIlsMain_FWD_DEFINED__ */


#ifndef __IIlsNotify_FWD_DEFINED__
#define __IIlsNotify_FWD_DEFINED__
typedef interface IIlsNotify IIlsNotify;
#endif 	/* __IIlsNotify_FWD_DEFINED__ */


#ifndef __IIlsUser_FWD_DEFINED__
#define __IIlsUser_FWD_DEFINED__
typedef interface IIlsUser IIlsUser;
#endif 	/* __IIlsUser_FWD_DEFINED__ */


#ifndef __IIlsProtocol_FWD_DEFINED__
#define __IIlsProtocol_FWD_DEFINED__
typedef interface IIlsProtocol IIlsProtocol;
#endif 	/* __IIlsProtocol_FWD_DEFINED__ */


#ifndef __IIlsProtocolNotify_FWD_DEFINED__
#define __IIlsProtocolNotify_FWD_DEFINED__
typedef interface IIlsProtocolNotify IIlsProtocolNotify;
#endif 	/* __IIlsProtocolNotify_FWD_DEFINED__ */


#ifndef __IIlsUserNotify_FWD_DEFINED__
#define __IIlsUserNotify_FWD_DEFINED__
typedef interface IIlsUserNotify IIlsUserNotify;
#endif 	/* __IIlsUserNotify_FWD_DEFINED__ */


#ifndef __IIlsAttributes_FWD_DEFINED__
#define __IIlsAttributes_FWD_DEFINED__
typedef interface IIlsAttributes IIlsAttributes;
#endif 	/* __IIlsAttributes_FWD_DEFINED__ */


#ifndef __IIlsFilter_FWD_DEFINED__
#define __IIlsFilter_FWD_DEFINED__
typedef interface IIlsFilter IIlsFilter;
#endif 	/* __IIlsFilter_FWD_DEFINED__ */


#ifndef __IEnumIlsProtocols_FWD_DEFINED__
#define __IEnumIlsProtocols_FWD_DEFINED__
typedef interface IEnumIlsProtocols IEnumIlsProtocols;
#endif 	/* __IEnumIlsProtocols_FWD_DEFINED__ */


#ifndef __IEnumIlsUsers_FWD_DEFINED__
#define __IEnumIlsUsers_FWD_DEFINED__
typedef interface IEnumIlsUsers IEnumIlsUsers;
#endif 	/* __IEnumIlsUsers_FWD_DEFINED__ */


#ifndef __IEnumIlsNames_FWD_DEFINED__
#define __IEnumIlsNames_FWD_DEFINED__
typedef interface IEnumIlsNames IEnumIlsNames;
#endif 	/* __IEnumIlsNames_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_ILS_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright 1996-1997 Microsoft Corporation. All Rights Reserved.
//
//  File: ils.h
//
//--------------------------------------------------------------------------













////////////////////////////////////////////////////////////////////////////
//  Error Codes

#define ILS_E(e)    (0x81000000UL | (ULONG) (e))
#define ILS_S(e)    (0x01000000UL | (ULONG) (e))

enum {

//  COM specific error codes
//
    ILS_S_SERVER_MAY_NOT_SUPPORT      = ILS_S (1),
    ILS_E_FAIL                 = E_FAIL,
    ILS_E_POINTER              = E_POINTER,
    ILS_E_HANDLE               = E_HANDLE,
    ILS_E_ABORT                = E_ABORT,
    ILS_E_ACCESS_DENIED        = E_ACCESSDENIED,
    ILS_E_NOT_IMPL             = E_NOTIMPL,
    ILS_E_NO_INTERFACE         = E_NOINTERFACE,
    ILS_E_MEMORY               = E_OUTOFMEMORY,
    ILS_E_PARAMETER            = E_INVALIDARG,

//  General error codes
//
    ILS_E_SERVER_SERVICE       = ILS_E (1),
    ILS_E_SERVER_NAME          = ILS_E (2),
    ILS_E_TIMEOUT              = ILS_E (3),
    ILS_E_BIND                 = ILS_E (4),
    ILS_E_THREAD               = ILS_E (5),
    ILS_E_SERVER_EXEC          = ILS_E (6),
    ILS_E_WINSOCK              = ILS_E (7),
    ILS_E_NO_MORE              = ILS_E (8),
    ILS_E_NOT_INITIALIZED      = ILS_E (9),
    ILS_E_NOTIFY_ID            = ILS_E (10),
    ILS_E_NO_SUCH_OBJECT       = ILS_E (11),
    ILS_E_NEED_RELOGON         = ILS_E (12),
    ILS_E_NAME_CONFLICTS       = ILS_E (13),
    ILS_E_NETWORK_DOWN         = ILS_E (14),
    ILS_E_FILTER_STRING        = ILS_E (15),
    ILS_E_FILTER_OBJECT        = ILS_E (16),
    ILS_E_FILTER_TYPE          = ILS_E (17),
    ILS_E_ACCESS_CONTROL       = ILS_E (18),
    ILS_E_NOT_REGISTERED       = ILS_E (19),
    ILS_E_NO_SUCH_MEMBER       = ILS_E (20),
    ILS_E_NO_WRITE_ACCESS      = ILS_E (21),
    ILS_E_ALREADY_REGISTERED   = ILS_E (22),

//  LDAP specific error codes
//
    ILS_E_LDAP_OPERATIONS_ERROR             = ILS_E (0x101),
    ILS_E_LDAP_PROTOCOL_ERROR               = ILS_E (0x102),
    ILS_E_LDAP_TIMELIMIT_EXCEEDED           = ILS_E (0x103),
    ILS_E_LDAP_SIZELIMIT_EXCEEDED           = ILS_E (0x104),
    ILS_E_LDAP_COMPARE_FALSE                = ILS_E (0x105),
    ILS_E_LDAP_COMPARE_TRUE                 = ILS_E (0x106),
    ILS_E_LDAP_AUTH_METHOD_NOT_SUPPORTED    = ILS_E (0x107),
    ILS_E_LDAP_STRONG_AUTH_REQUIRED         = ILS_E (0x108),
    ILS_E_LDAP_REFERRAL_V2                  = ILS_E (0x109),
    ILS_E_LDAP_PARTIAL_RESULTS              = ILS_E (0x10A),
    ILS_E_LDAP_REFERRAL                     = ILS_E (0x10B),
    ILS_E_LDAP_ADMIN_LIMIT_EXCEEDED         = ILS_E (0x10C),
    ILS_E_LDAP_UNAVAILABLE_CRIT_EXTENSION   = ILS_E (0x10D),
    ILS_E_LDAP_NO_SUCH_ATTRIBUTE            = ILS_E (0x10E),
    ILS_E_LDAP_UNDEFINED_TYPE               = ILS_E (0x10F),
    ILS_E_LDAP_INAPPROPRIATE_MATCHING       = ILS_E (0x110),
    ILS_E_LDAP_CONSTRAINT_VIOLATION         = ILS_E (0x111),
    ILS_E_LDAP_ATTRIBUTE_OR_VALUE_EXISTS    = ILS_E (0x112),
    ILS_E_LDAP_INVALID_SYNTAX               = ILS_E (0x113),
    ILS_E_LDAP_ALIAS_PROBLEM                = ILS_E (0x114),
    ILS_E_LDAP_INVALID_DN_SYNTAX            = ILS_E (0x115),
    ILS_E_LDAP_IS_LEAF                      = ILS_E (0x116),
    ILS_E_LDAP_ALIAS_DEREF_PROBLEM          = ILS_E (0x117),
    ILS_E_LDAP_INAPPROPRIATE_AUTH           = ILS_E (0x118),
    ILS_E_LDAP_INVALID_CREDENTIALS          = ILS_E (0x119),
    ILS_E_LDAP_INSUFFICIENT_RIGHTS          = ILS_E (0x11A),
    ILS_E_LDAP_BUSY                         = ILS_E (0x11B),
    ILS_E_LDAP_UNAVAILABLE                  = ILS_E (0x11C),
    ILS_E_LDAP_UNWILLING_TO_PERFORM         = ILS_E (0x11D),
    ILS_E_LDAP_LOOP_DETECT                  = ILS_E (0x11E),
    ILS_E_LDAP_NAMING_VIOLATION             = ILS_E (0x11F),
    ILS_E_LDAP_OBJECT_CLASS_VIOLATION       = ILS_E (0x120),
    ILS_E_LDAP_NOT_ALLOWED_ON_NONLEAF       = ILS_E (0x121),
    ILS_E_LDAP_NOT_ALLOWED_ON_RDN           = ILS_E (0x122),
    ILS_E_LDAP_NO_OBJECT_CLASS_MODS         = ILS_E (0x123),
    ILS_E_LDAP_RESULTS_TOO_LARGE            = ILS_E (0x124),
    ILS_E_LDAP_AFFECTS_MULTIPLE_DSAS        = ILS_E (0x125),
    ILS_E_LDAP_OTHER                        = ILS_E (0x126),
    ILS_E_LDAP_SERVER_DOWN                  = ILS_E (0x127),
    ILS_E_LDAP_LOCAL_ERROR                  = ILS_E (0x128),
    ILS_E_LDAP_ENCODING_ERROR               = ILS_E (0x129),
    ILS_E_LDAP_DECODING_ERROR               = ILS_E (0x12A),
    ILS_E_LDAP_TIMEOUT                      = ILS_E (0x12B),
    ILS_E_LDAP_AUTH_UNKNOWN                 = ILS_E (0x12C),
    ILS_E_LDAP_FILTER_ERROR                 = ILS_E (0x12D),
    ILS_E_LDAP_USER_CANCELLED               = ILS_E (0x12E),
    ILS_E_LDAP_NO_MEMORY                    = ILS_E (0x12F),
}; // end of enum

////////////////////////////////////////////////////////////////////////////
//  Constants Definitions

enum __MIDL___MIDL_itf_ILS_0000_0001
    {	ILS_INVALID_REQ_ID	= 0
    };
typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0002
    {	ILS_UNREGISTERED	= 0,
	ILS_REGISTERING	= 1,
	ILS_REGISTERED	= 2,
	ILS_UNREGISTERING	= 3,
	ILS_REGISTERED_BUT_INVALID	= 4,
	ILS_NETWORK_DOWN	= 5,
	ILS_IN_SYNC	= 6
    }	ILS_STATE;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0003
    {	ILS_ATTRTYPE_NONE	= 0,
	ILS_ATTRTYPE_NAME_ONLY	= 1,
	ILS_ATTRTYPE_NAME_VALUE	= 2
    }	ILS_ATTR_TYPE;


////////////////////////////////////////////////////////////////////////////
//  Filters Definitions
typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0004
    {	ILS_FILTERTYPE_UNKNOWN	= 0,
	ILS_FILTERTYPE_SIMPLE	= 1,
	ILS_FILTERTYPE_COMPOSITE	= 2
    }	ILS_FILTER_TYPE;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0005
    {	ILS_FILTEROP_NONE	= 0,
	ILS_FILTEROP_EQUAL	= 1,
	ILS_FILTEROP_APPROX	= 2,
	ILS_FILTEROP_LESS_THAN	= 3,
	ILS_FILTEROP_GREATER_THAN	= 4,
	ILS_FILTEROP_EXIST	= 5,
	ILS_FILTEROP_AND	= 21,
	ILS_FILTEROP_OR	= 22,
	ILS_FILTEROP_NOT	= 23
    }	ILS_FILTER_OP;

typedef /* [public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0006
    {	ILS_STDATTR_NULL	= 0,
	ILS_STDATTR_USER_ID	= 1,
	ILS_STDATTR_IP_ADDRESS	= 2,
	ILS_STDATTR_EMAIL_NAME	= 3,
	ILS_STDATTR_FIRST_NAME	= 4,
	ILS_STDATTR_LAST_NAME	= 5,
	ILS_STDATTR_CITY_NAME	= 6,
	ILS_STDATTR_COUNTRY_NAME	= 7,
	ILS_STDATTR_COMMENT	= 8,
	ILS_STDATTR_FLAGS	= 9,
	ILS_STDATTR_APP_NAME	= 10,
	ILS_STDATTR_APP_MIME_TYPE	= 11,
	ILS_STDATTR_APP_GUID	= 12,
	ILS_STDATTR_PROTOCOL_NAME	= 13,
	ILS_STDATTR_PROTOCOL_MIME_TYPE	= 14,
	ILS_STDATTR_PROTOCOL_PORT	= 15,
	ILS_NUM_OF_STDATTRS	= 16
    }	ILS_STD_ATTR_NAME;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILS_0000_0007
    {	ILS_AUTH_ANONYMOUS	= 0,
	ILS_AUTH_CLEAR_TEXT	= 1,
	ILS_AUTH_NTLM	= 3,
	ILS_AUTH_DPA	= 4,
	ILS_AUTH_MSN	= 5,
	ILS_AUTH_SICILY	= 6,
	ILS_AUTH_SSPI	= 7,
	ILS_NUM_OF_AUTH_METHODS	= 8
    }	ILS_ENUM_AUTH_METHOD;


////////////////////////////////////////////////////////////////////////////
//  Interface Definitions


extern RPC_IF_HANDLE __MIDL_itf_ILS_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ILS_0000_v0_0_s_ifspec;

#ifndef __IIlsServer_INTERFACE_DEFINED__
#define __IIlsServer_INTERFACE_DEFINED__

/* interface IIlsServer */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsServer __RPC_FAR *LPILS_SERVER;


EXTERN_C const IID IID_IIlsServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BCE6B64-85CE-11d0-9CA7-00A0C913B21E")
    IIlsServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAuthenticationMethod( 
            /* [in] */ ILS_ENUM_AUTH_METHOD enumAuthMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogonName( 
            /* [in] */ BSTR bstrLogonName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogonPassword( 
            /* [in] */ BSTR bstrLogonPassword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDomain( 
            /* [in] */ BSTR bstrDomain) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCredential( 
            /* [in] */ BSTR bstrCredential) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeout( 
            /* [in] */ ULONG uTimeoutInSecond) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBaseDN( 
            /* [in] */ BSTR bstrBaseDN) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsServer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsServer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuthenticationMethod )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ ILS_ENUM_AUTH_METHOD enumAuthMethod);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogonName )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ BSTR bstrLogonName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogonPassword )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ BSTR bstrLogonPassword);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDomain )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ BSTR bstrDomain);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCredential )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ BSTR bstrCredential);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeout )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ ULONG uTimeoutInSecond);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseDN )( 
            IIlsServer __RPC_FAR * This,
            /* [in] */ BSTR bstrBaseDN);
        
        END_INTERFACE
    } IIlsServerVtbl;

    interface IIlsServer
    {
        CONST_VTBL struct IIlsServerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsServer_SetAuthenticationMethod(This,enumAuthMethod)	\
    (This)->lpVtbl -> SetAuthenticationMethod(This,enumAuthMethod)

#define IIlsServer_SetLogonName(This,bstrLogonName)	\
    (This)->lpVtbl -> SetLogonName(This,bstrLogonName)

#define IIlsServer_SetLogonPassword(This,bstrLogonPassword)	\
    (This)->lpVtbl -> SetLogonPassword(This,bstrLogonPassword)

#define IIlsServer_SetDomain(This,bstrDomain)	\
    (This)->lpVtbl -> SetDomain(This,bstrDomain)

#define IIlsServer_SetCredential(This,bstrCredential)	\
    (This)->lpVtbl -> SetCredential(This,bstrCredential)

#define IIlsServer_SetTimeout(This,uTimeoutInSecond)	\
    (This)->lpVtbl -> SetTimeout(This,uTimeoutInSecond)

#define IIlsServer_SetBaseDN(This,bstrBaseDN)	\
    (This)->lpVtbl -> SetBaseDN(This,bstrBaseDN)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsServer_SetAuthenticationMethod_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ ILS_ENUM_AUTH_METHOD enumAuthMethod);


void __RPC_STUB IIlsServer_SetAuthenticationMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetLogonName_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ BSTR bstrLogonName);


void __RPC_STUB IIlsServer_SetLogonName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetLogonPassword_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ BSTR bstrLogonPassword);


void __RPC_STUB IIlsServer_SetLogonPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetDomain_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ BSTR bstrDomain);


void __RPC_STUB IIlsServer_SetDomain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetCredential_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ BSTR bstrCredential);


void __RPC_STUB IIlsServer_SetCredential_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetTimeout_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ ULONG uTimeoutInSecond);


void __RPC_STUB IIlsServer_SetTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsServer_SetBaseDN_Proxy( 
    IIlsServer __RPC_FAR * This,
    /* [in] */ BSTR bstrBaseDN);


void __RPC_STUB IIlsServer_SetBaseDN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsServer_INTERFACE_DEFINED__ */


#ifndef __IIlsMain_INTERFACE_DEFINED__
#define __IIlsMain_INTERFACE_DEFINED__

/* interface IIlsMain */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsMain __RPC_FAR *LPILS_MAIN;


EXTERN_C const IID IID_IIlsMain;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34526E14-4D7D-11d0-8F4B-00C04FC29FEE")
    IIlsMain : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateServer( 
            /* [in] */ BSTR bstrServerName,
            /* [out] */ IIlsServer __RPC_FAR *__RPC_FAR *ppServer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateUser( 
            /* [in] */ BSTR bstrUserID,
            /* [in] */ BSTR bstrAppName,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUser( 
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ BSTR bstrUserID,
            /* [in] */ BSTR bstrAppName,
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUserNames( 
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumUserNames,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUsers( 
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
            /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUsers,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Abort( 
            /* [in] */ ULONG uReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAttributes( 
            /* [in] */ ILS_ATTR_TYPE AttrType,
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFilter( 
            /* [in] */ ILS_FILTER_TYPE FilterType,
            /* [in] */ ILS_FILTER_OP FilterOp,
            /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StringToFilter( 
            /* [in] */ BSTR bstrFilterString,
            /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsMainVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsMain __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsMain __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IIlsMain __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateServer )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ BSTR bstrServerName,
            /* [out] */ IIlsServer __RPC_FAR *__RPC_FAR *ppServer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateUser )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ BSTR bstrUserID,
            /* [in] */ BSTR bstrAppName,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUser )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ BSTR bstrUserID,
            /* [in] */ BSTR bstrAppName,
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumUserNames )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumUserNames,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumUsers )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
            /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUsers,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ ULONG uReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateAttributes )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ ILS_ATTR_TYPE AttrType,
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFilter )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ ILS_FILTER_TYPE FilterType,
            /* [in] */ ILS_FILTER_OP FilterOp,
            /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StringToFilter )( 
            IIlsMain __RPC_FAR * This,
            /* [in] */ BSTR bstrFilterString,
            /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Uninitialize )( 
            IIlsMain __RPC_FAR * This);
        
        END_INTERFACE
    } IIlsMainVtbl;

    interface IIlsMain
    {
        CONST_VTBL struct IIlsMainVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsMain_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsMain_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsMain_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsMain_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IIlsMain_CreateServer(This,bstrServerName,ppServer)	\
    (This)->lpVtbl -> CreateServer(This,bstrServerName,ppServer)

#define IIlsMain_CreateUser(This,bstrUserID,bstrAppName,ppUser)	\
    (This)->lpVtbl -> CreateUser(This,bstrUserID,bstrAppName,ppUser)

#define IIlsMain_GetUser(This,pServer,bstrUserID,bstrAppName,bstrProtocolName,pAttrib,ppUser,puReqID)	\
    (This)->lpVtbl -> GetUser(This,pServer,bstrUserID,bstrAppName,bstrProtocolName,pAttrib,ppUser,puReqID)

#define IIlsMain_EnumUserNames(This,pServer,pFilter,ppEnumUserNames,puReqID)	\
    (This)->lpVtbl -> EnumUserNames(This,pServer,pFilter,ppEnumUserNames,puReqID)

#define IIlsMain_EnumUsers(This,pServer,pFilter,pAttrib,ppEnumUsers,puReqID)	\
    (This)->lpVtbl -> EnumUsers(This,pServer,pFilter,pAttrib,ppEnumUsers,puReqID)

#define IIlsMain_Abort(This,uReqID)	\
    (This)->lpVtbl -> Abort(This,uReqID)

#define IIlsMain_CreateAttributes(This,AttrType,ppAttributes)	\
    (This)->lpVtbl -> CreateAttributes(This,AttrType,ppAttributes)

#define IIlsMain_CreateFilter(This,FilterType,FilterOp,ppFilter)	\
    (This)->lpVtbl -> CreateFilter(This,FilterType,FilterOp,ppFilter)

#define IIlsMain_StringToFilter(This,bstrFilterString,ppFilter)	\
    (This)->lpVtbl -> StringToFilter(This,bstrFilterString,ppFilter)

#define IIlsMain_Uninitialize(This)	\
    (This)->lpVtbl -> Uninitialize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsMain_Initialize_Proxy( 
    IIlsMain __RPC_FAR * This);


void __RPC_STUB IIlsMain_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_CreateServer_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ BSTR bstrServerName,
    /* [out] */ IIlsServer __RPC_FAR *__RPC_FAR *ppServer);


void __RPC_STUB IIlsMain_CreateServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_CreateUser_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ BSTR bstrUserID,
    /* [in] */ BSTR bstrAppName,
    /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser);


void __RPC_STUB IIlsMain_CreateUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_GetUser_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ IIlsServer __RPC_FAR *pServer,
    /* [in] */ BSTR bstrUserID,
    /* [in] */ BSTR bstrAppName,
    /* [in] */ BSTR bstrProtocolName,
    /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
    /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsMain_GetUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_EnumUserNames_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ IIlsServer __RPC_FAR *pServer,
    /* [in] */ IIlsFilter __RPC_FAR *pFilter,
    /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumUserNames,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsMain_EnumUserNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_EnumUsers_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ IIlsServer __RPC_FAR *pServer,
    /* [in] */ IIlsFilter __RPC_FAR *pFilter,
    /* [in] */ IIlsAttributes __RPC_FAR *pAttrib,
    /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUsers,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsMain_EnumUsers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_Abort_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ ULONG uReqID);


void __RPC_STUB IIlsMain_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_CreateAttributes_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ ILS_ATTR_TYPE AttrType,
    /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);


void __RPC_STUB IIlsMain_CreateAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_CreateFilter_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ ILS_FILTER_TYPE FilterType,
    /* [in] */ ILS_FILTER_OP FilterOp,
    /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter);


void __RPC_STUB IIlsMain_CreateFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_StringToFilter_Proxy( 
    IIlsMain __RPC_FAR * This,
    /* [in] */ BSTR bstrFilterString,
    /* [out] */ IIlsFilter __RPC_FAR *__RPC_FAR *ppFilter);


void __RPC_STUB IIlsMain_StringToFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsMain_Uninitialize_Proxy( 
    IIlsMain __RPC_FAR * This);


void __RPC_STUB IIlsMain_Uninitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsMain_INTERFACE_DEFINED__ */


#ifndef __IIlsNotify_INTERFACE_DEFINED__
#define __IIlsNotify_INTERFACE_DEFINED__

/* interface IIlsNotify */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsNotify __RPC_FAR *LPILS_NOTIFY;


EXTERN_C const IID IID_IIlsNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("551D25EE-4D7D-11d0-8F4B-00C04FC29FEE")
    IIlsNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUserResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ IIlsUser __RPC_FAR *pUser,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUserNamesResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsNames __RPC_FAR *pEnumUserName,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUsersResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsUsers __RPC_FAR *pEnumUser,
            /* [in] */ HRESULT hResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsNotify __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUserResult )( 
            IIlsNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ IIlsUser __RPC_FAR *pUser,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumUserNamesResult )( 
            IIlsNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsNames __RPC_FAR *pEnumUserName,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumUsersResult )( 
            IIlsNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsUsers __RPC_FAR *pEnumUser,
            /* [in] */ HRESULT hResult);
        
        END_INTERFACE
    } IIlsNotifyVtbl;

    interface IIlsNotify
    {
        CONST_VTBL struct IIlsNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsNotify_GetUserResult(This,uReqID,pUser,hResult)	\
    (This)->lpVtbl -> GetUserResult(This,uReqID,pUser,hResult)

#define IIlsNotify_EnumUserNamesResult(This,uReqID,pEnumUserName,hResult)	\
    (This)->lpVtbl -> EnumUserNamesResult(This,uReqID,pEnumUserName,hResult)

#define IIlsNotify_EnumUsersResult(This,uReqID,pEnumUser,hResult)	\
    (This)->lpVtbl -> EnumUsersResult(This,uReqID,pEnumUser,hResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsNotify_GetUserResult_Proxy( 
    IIlsNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ IIlsUser __RPC_FAR *pUser,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsNotify_GetUserResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsNotify_EnumUserNamesResult_Proxy( 
    IIlsNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ IEnumIlsNames __RPC_FAR *pEnumUserName,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsNotify_EnumUserNamesResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsNotify_EnumUsersResult_Proxy( 
    IIlsNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ IEnumIlsUsers __RPC_FAR *pEnumUser,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsNotify_EnumUsersResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsNotify_INTERFACE_DEFINED__ */


#ifndef __IIlsUser_INTERFACE_DEFINED__
#define __IIlsUser_INTERFACE_DEFINED__

/* interface IIlsUser */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsUser __RPC_FAR *LPILS_USER;


EXTERN_C const IID IID_IIlsUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC982-20E6-11d0-8796-444553540000")
    IIlsUser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ ILS_STATE __RPC_FAR *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStandardAttribute( 
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [out] */ BSTR __RPC_FAR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStandardAttribute( 
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedAttribute( 
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtendedAttribute( 
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveExtendedAttribute( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllExtendedAttributes( 
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWritable( 
            /* [in] */ BOOL __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Register( 
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unregister( 
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ DWORD __RPC_FAR *pfVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ DWORD fVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuid( 
            /* [out] */ GUID __RPC_FAR *pGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGuid( 
            /* [in] */ GUID __RPC_FAR *pGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateProtocol( 
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ ULONG uPortNumber,
            /* [in] */ BSTR bstrMimeType,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProtocol( 
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveProtocol( 
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProtocol( 
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProtocols( 
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
            /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsUser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsUser __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetState )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ ILS_STATE __RPC_FAR *pState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStandardAttribute )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [out] */ BSTR __RPC_FAR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStandardAttribute )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [in] */ BSTR bstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtendedAttribute )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExtendedAttribute )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveExtendedAttribute )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BSTR bstrName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllExtendedAttributes )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsWritable )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BOOL __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Register )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ IIlsServer __RPC_FAR *pServer,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pfVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ DWORD fVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGuid )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ GUID __RPC_FAR *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGuid )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ GUID __RPC_FAR *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateProtocol )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ ULONG uPortNumber,
            /* [in] */ BSTR bstrMimeType,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddProtocol )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveProtocol )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProtocol )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ BSTR bstrProtocolName,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumProtocols )( 
            IIlsUser __RPC_FAR * This,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter,
            /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
            /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IIlsUser __RPC_FAR * This,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser);
        
        END_INTERFACE
    } IIlsUserVtbl;

    interface IIlsUser
    {
        CONST_VTBL struct IIlsUserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsUser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsUser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsUser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsUser_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IIlsUser_GetStandardAttribute(This,StdAttr,pbstrValue)	\
    (This)->lpVtbl -> GetStandardAttribute(This,StdAttr,pbstrValue)

#define IIlsUser_SetStandardAttribute(This,StdAttr,bstrValue)	\
    (This)->lpVtbl -> SetStandardAttribute(This,StdAttr,bstrValue)

#define IIlsUser_GetExtendedAttribute(This,bstrName,pbstrValue)	\
    (This)->lpVtbl -> GetExtendedAttribute(This,bstrName,pbstrValue)

#define IIlsUser_SetExtendedAttribute(This,bstrName,bstrValue)	\
    (This)->lpVtbl -> SetExtendedAttribute(This,bstrName,bstrValue)

#define IIlsUser_RemoveExtendedAttribute(This,bstrName)	\
    (This)->lpVtbl -> RemoveExtendedAttribute(This,bstrName)

#define IIlsUser_GetAllExtendedAttributes(This,ppAttributes)	\
    (This)->lpVtbl -> GetAllExtendedAttributes(This,ppAttributes)

#define IIlsUser_IsWritable(This,pValue)	\
    (This)->lpVtbl -> IsWritable(This,pValue)

#define IIlsUser_Register(This,pServer,puReqID)	\
    (This)->lpVtbl -> Register(This,pServer,puReqID)

#define IIlsUser_Unregister(This,puReqID)	\
    (This)->lpVtbl -> Unregister(This,puReqID)

#define IIlsUser_Update(This,puReqID)	\
    (This)->lpVtbl -> Update(This,puReqID)

#define IIlsUser_GetVisible(This,pfVisible)	\
    (This)->lpVtbl -> GetVisible(This,pfVisible)

#define IIlsUser_SetVisible(This,fVisible)	\
    (This)->lpVtbl -> SetVisible(This,fVisible)

#define IIlsUser_GetGuid(This,pGuid)	\
    (This)->lpVtbl -> GetGuid(This,pGuid)

#define IIlsUser_SetGuid(This,pGuid)	\
    (This)->lpVtbl -> SetGuid(This,pGuid)

#define IIlsUser_CreateProtocol(This,bstrProtocolName,uPortNumber,bstrMimeType,ppProtocol)	\
    (This)->lpVtbl -> CreateProtocol(This,bstrProtocolName,uPortNumber,bstrMimeType,ppProtocol)

#define IIlsUser_AddProtocol(This,pProtocol,puReqID)	\
    (This)->lpVtbl -> AddProtocol(This,pProtocol,puReqID)

#define IIlsUser_RemoveProtocol(This,pProtocol,puReqID)	\
    (This)->lpVtbl -> RemoveProtocol(This,pProtocol,puReqID)

#define IIlsUser_GetProtocol(This,bstrProtocolName,pAttributes,ppProtocol,puReqID)	\
    (This)->lpVtbl -> GetProtocol(This,bstrProtocolName,pAttributes,ppProtocol,puReqID)

#define IIlsUser_EnumProtocols(This,pFilter,pAttributes,ppEnumProtocol,puReqID)	\
    (This)->lpVtbl -> EnumProtocols(This,pFilter,pAttributes,ppEnumProtocol,puReqID)

#define IIlsUser_Clone(This,ppUser)	\
    (This)->lpVtbl -> Clone(This,ppUser)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsUser_GetState_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ ILS_STATE __RPC_FAR *pState);


void __RPC_STUB IIlsUser_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetStandardAttribute_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ ILS_STD_ATTR_NAME StdAttr,
    /* [out] */ BSTR __RPC_FAR *pbstrValue);


void __RPC_STUB IIlsUser_GetStandardAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_SetStandardAttribute_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ ILS_STD_ATTR_NAME StdAttr,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IIlsUser_SetStandardAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetExtendedAttribute_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [out] */ BSTR __RPC_FAR *pbstrValue);


void __RPC_STUB IIlsUser_GetExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_SetExtendedAttribute_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IIlsUser_SetExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_RemoveExtendedAttribute_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IIlsUser_RemoveExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetAllExtendedAttributes_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);


void __RPC_STUB IIlsUser_GetAllExtendedAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_IsWritable_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BOOL __RPC_FAR *pValue);


void __RPC_STUB IIlsUser_IsWritable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_Register_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ IIlsServer __RPC_FAR *pServer,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_Unregister_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_Unregister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_Update_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetVisible_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pfVisible);


void __RPC_STUB IIlsUser_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_SetVisible_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ DWORD fVisible);


void __RPC_STUB IIlsUser_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetGuid_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ GUID __RPC_FAR *pGuid);


void __RPC_STUB IIlsUser_GetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_SetGuid_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ GUID __RPC_FAR *pGuid);


void __RPC_STUB IIlsUser_SetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_CreateProtocol_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BSTR bstrProtocolName,
    /* [in] */ ULONG uPortNumber,
    /* [in] */ BSTR bstrMimeType,
    /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol);


void __RPC_STUB IIlsUser_CreateProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_AddProtocol_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_AddProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_RemoveProtocol_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_RemoveProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_GetProtocol_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ BSTR bstrProtocolName,
    /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
    /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *ppProtocol,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_GetProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_EnumProtocols_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [in] */ IIlsFilter __RPC_FAR *pFilter,
    /* [in] */ IIlsAttributes __RPC_FAR *pAttributes,
    /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsUser_EnumProtocols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUser_Clone_Proxy( 
    IIlsUser __RPC_FAR * This,
    /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *ppUser);


void __RPC_STUB IIlsUser_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsUser_INTERFACE_DEFINED__ */


#ifndef __IIlsProtocol_INTERFACE_DEFINED__
#define __IIlsProtocol_INTERFACE_DEFINED__

/* interface IIlsProtocol */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsProtocol __RPC_FAR *LPILS_PROTOCOL;


EXTERN_C const IID IID_IIlsProtocol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC985-20E6-11d0-8796-444553540000")
    IIlsProtocol : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsWritable( 
            /* [in] */ BOOL __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPortNumber( 
            /* [out] */ ULONG __RPC_FAR *pulPortNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStandardAttribute( 
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [out] */ BSTR __RPC_FAR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStandardAttribute( 
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedAttribute( 
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtendedAttribute( 
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveExtendedAttribute( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllExtendedAttributes( 
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [out] */ ULONG __RPC_FAR *puReqID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsProtocolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsProtocol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsProtocol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsWritable )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ BOOL __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPortNumber )( 
            IIlsProtocol __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pulPortNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStandardAttribute )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [out] */ BSTR __RPC_FAR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStandardAttribute )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ ILS_STD_ATTR_NAME StdAttr,
            /* [in] */ BSTR bstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtendedAttribute )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExtendedAttribute )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveExtendedAttribute )( 
            IIlsProtocol __RPC_FAR * This,
            /* [in] */ BSTR bstrName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllExtendedAttributes )( 
            IIlsProtocol __RPC_FAR * This,
            /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )( 
            IIlsProtocol __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *puReqID);
        
        END_INTERFACE
    } IIlsProtocolVtbl;

    interface IIlsProtocol
    {
        CONST_VTBL struct IIlsProtocolVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsProtocol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsProtocol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsProtocol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsProtocol_IsWritable(This,pValue)	\
    (This)->lpVtbl -> IsWritable(This,pValue)

#define IIlsProtocol_GetPortNumber(This,pulPortNumber)	\
    (This)->lpVtbl -> GetPortNumber(This,pulPortNumber)

#define IIlsProtocol_GetStandardAttribute(This,StdAttr,pbstrValue)	\
    (This)->lpVtbl -> GetStandardAttribute(This,StdAttr,pbstrValue)

#define IIlsProtocol_SetStandardAttribute(This,StdAttr,bstrValue)	\
    (This)->lpVtbl -> SetStandardAttribute(This,StdAttr,bstrValue)

#define IIlsProtocol_GetExtendedAttribute(This,bstrName,pbstrValue)	\
    (This)->lpVtbl -> GetExtendedAttribute(This,bstrName,pbstrValue)

#define IIlsProtocol_SetExtendedAttribute(This,bstrName,bstrValue)	\
    (This)->lpVtbl -> SetExtendedAttribute(This,bstrName,bstrValue)

#define IIlsProtocol_RemoveExtendedAttribute(This,bstrName)	\
    (This)->lpVtbl -> RemoveExtendedAttribute(This,bstrName)

#define IIlsProtocol_GetAllExtendedAttributes(This,ppAttributes)	\
    (This)->lpVtbl -> GetAllExtendedAttributes(This,ppAttributes)

#define IIlsProtocol_Update(This,puReqID)	\
    (This)->lpVtbl -> Update(This,puReqID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsProtocol_IsWritable_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ BOOL __RPC_FAR *pValue);


void __RPC_STUB IIlsProtocol_IsWritable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_GetPortNumber_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pulPortNumber);


void __RPC_STUB IIlsProtocol_GetPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_GetStandardAttribute_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ ILS_STD_ATTR_NAME StdAttr,
    /* [out] */ BSTR __RPC_FAR *pbstrValue);


void __RPC_STUB IIlsProtocol_GetStandardAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_SetStandardAttribute_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ ILS_STD_ATTR_NAME StdAttr,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IIlsProtocol_SetStandardAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_GetExtendedAttribute_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [out] */ BSTR __RPC_FAR *pbstrValue);


void __RPC_STUB IIlsProtocol_GetExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_SetExtendedAttribute_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IIlsProtocol_SetExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_RemoveExtendedAttribute_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IIlsProtocol_RemoveExtendedAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_GetAllExtendedAttributes_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [out] */ IIlsAttributes __RPC_FAR *__RPC_FAR *ppAttributes);


void __RPC_STUB IIlsProtocol_GetAllExtendedAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsProtocol_Update_Proxy( 
    IIlsProtocol __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *puReqID);


void __RPC_STUB IIlsProtocol_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsProtocol_INTERFACE_DEFINED__ */


#ifndef __IIlsProtocolNotify_INTERFACE_DEFINED__
#define __IIlsProtocolNotify_INTERFACE_DEFINED__

/* interface IIlsProtocolNotify */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsProtocolNotify __RPC_FAR *LPILS_PROTOCOLNOTIFY;


EXTERN_C const IID IID_IIlsProtocolNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC986-20E6-11d0-8796-444553540000")
    IIlsProtocolNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UpdateResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsProtocolNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsProtocolNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsProtocolNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsProtocolNotify __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateResult )( 
            IIlsProtocolNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult);
        
        END_INTERFACE
    } IIlsProtocolNotifyVtbl;

    interface IIlsProtocolNotify
    {
        CONST_VTBL struct IIlsProtocolNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsProtocolNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsProtocolNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsProtocolNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsProtocolNotify_UpdateResult(This,uReqID,hResult)	\
    (This)->lpVtbl -> UpdateResult(This,uReqID,hResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsProtocolNotify_UpdateResult_Proxy( 
    IIlsProtocolNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsProtocolNotify_UpdateResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsProtocolNotify_INTERFACE_DEFINED__ */


#ifndef __IIlsUserNotify_INTERFACE_DEFINED__
#define __IIlsUserNotify_INTERFACE_DEFINED__

/* interface IIlsUserNotify */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsUserNotify __RPC_FAR *LPILS_USERNOTIFY;


EXTERN_C const IID IID_IIlsUserNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC988-20E6-11d0-8796-444553540000")
    IIlsUserNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProtocolChangeResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProtocolResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProtocolsResult( 
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsNames __RPC_FAR *pEnumProtocol,
            /* [in] */ HRESULT hResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StateChanged( 
            /* [in] */ ULONG fPrimary,
            /* [in] */ BSTR bstrServerName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsUserNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsUserNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsUserNotify __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterResult )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateResult )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProtocolChangeResult )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProtocolResult )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumProtocolsResult )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG uReqID,
            /* [in] */ IEnumIlsNames __RPC_FAR *pEnumProtocol,
            /* [in] */ HRESULT hResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StateChanged )( 
            IIlsUserNotify __RPC_FAR * This,
            /* [in] */ ULONG fPrimary,
            /* [in] */ BSTR bstrServerName);
        
        END_INTERFACE
    } IIlsUserNotifyVtbl;

    interface IIlsUserNotify
    {
        CONST_VTBL struct IIlsUserNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsUserNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsUserNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsUserNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsUserNotify_RegisterResult(This,uReqID,hResult)	\
    (This)->lpVtbl -> RegisterResult(This,uReqID,hResult)

#define IIlsUserNotify_UpdateResult(This,uReqID,hResult)	\
    (This)->lpVtbl -> UpdateResult(This,uReqID,hResult)

#define IIlsUserNotify_ProtocolChangeResult(This,uReqID,hResult)	\
    (This)->lpVtbl -> ProtocolChangeResult(This,uReqID,hResult)

#define IIlsUserNotify_GetProtocolResult(This,uReqID,pProtocol,hResult)	\
    (This)->lpVtbl -> GetProtocolResult(This,uReqID,pProtocol,hResult)

#define IIlsUserNotify_EnumProtocolsResult(This,uReqID,pEnumProtocol,hResult)	\
    (This)->lpVtbl -> EnumProtocolsResult(This,uReqID,pEnumProtocol,hResult)

#define IIlsUserNotify_StateChanged(This,fPrimary,bstrServerName)	\
    (This)->lpVtbl -> StateChanged(This,fPrimary,bstrServerName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsUserNotify_RegisterResult_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsUserNotify_RegisterResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUserNotify_UpdateResult_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsUserNotify_UpdateResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUserNotify_ProtocolChangeResult_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsUserNotify_ProtocolChangeResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUserNotify_GetProtocolResult_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ IIlsProtocol __RPC_FAR *pProtocol,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsUserNotify_GetProtocolResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUserNotify_EnumProtocolsResult_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG uReqID,
    /* [in] */ IEnumIlsNames __RPC_FAR *pEnumProtocol,
    /* [in] */ HRESULT hResult);


void __RPC_STUB IIlsUserNotify_EnumProtocolsResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsUserNotify_StateChanged_Proxy( 
    IIlsUserNotify __RPC_FAR * This,
    /* [in] */ ULONG fPrimary,
    /* [in] */ BSTR bstrServerName);


void __RPC_STUB IIlsUserNotify_StateChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsUserNotify_INTERFACE_DEFINED__ */


#ifndef __IIlsAttributes_INTERFACE_DEFINED__
#define __IIlsAttributes_INTERFACE_DEFINED__

/* interface IIlsAttributes */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsAttributes __RPC_FAR *LPILS_ATTRIBUTES;


EXTERN_C const IID IID_IIlsAttributes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC98C-20E6-11d0-8796-444553540000")
    IIlsAttributes : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAttribute( 
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttribute( 
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumAttributes( 
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumAttribute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributeName( 
            /* [in] */ BSTR bstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsAttributesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsAttributes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsAttributes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsAttributes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttribute )( 
            IIlsAttributes __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttribute )( 
            IIlsAttributes __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [out] */ BSTR __RPC_FAR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumAttributes )( 
            IIlsAttributes __RPC_FAR * This,
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumAttribute);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributeName )( 
            IIlsAttributes __RPC_FAR * This,
            /* [in] */ BSTR bstrName);
        
        END_INTERFACE
    } IIlsAttributesVtbl;

    interface IIlsAttributes
    {
        CONST_VTBL struct IIlsAttributesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsAttributes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsAttributes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsAttributes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsAttributes_SetAttribute(This,bstrName,bstrValue)	\
    (This)->lpVtbl -> SetAttribute(This,bstrName,bstrValue)

#define IIlsAttributes_GetAttribute(This,bstrName,pbstrValue)	\
    (This)->lpVtbl -> GetAttribute(This,bstrName,pbstrValue)

#define IIlsAttributes_EnumAttributes(This,ppEnumAttribute)	\
    (This)->lpVtbl -> EnumAttributes(This,ppEnumAttribute)

#define IIlsAttributes_SetAttributeName(This,bstrName)	\
    (This)->lpVtbl -> SetAttributeName(This,bstrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsAttributes_SetAttribute_Proxy( 
    IIlsAttributes __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IIlsAttributes_SetAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsAttributes_GetAttribute_Proxy( 
    IIlsAttributes __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [out] */ BSTR __RPC_FAR *pbstrValue);


void __RPC_STUB IIlsAttributes_GetAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsAttributes_EnumAttributes_Proxy( 
    IIlsAttributes __RPC_FAR * This,
    /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumAttribute);


void __RPC_STUB IIlsAttributes_EnumAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsAttributes_SetAttributeName_Proxy( 
    IIlsAttributes __RPC_FAR * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IIlsAttributes_SetAttributeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsAttributes_INTERFACE_DEFINED__ */


#ifndef __IIlsFilter_INTERFACE_DEFINED__
#define __IIlsFilter_INTERFACE_DEFINED__

/* interface IIlsFilter */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IIlsFilter __RPC_FAR *LPILS_FILTER;

// Composite filter operations
// Simple filter operations

EXTERN_C const IID IID_IIlsFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC98D-20E6-11d0-8796-444553540000")
    IIlsFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddSubFilter( 
            /* [in] */ IIlsFilter __RPC_FAR *pFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveSubFilter( 
            /* [in] */ IIlsFilter __RPC_FAR *pFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG __RPC_FAR *pcElements) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStandardAttributeName( 
            /* [in] */ ILS_STD_ATTR_NAME usrStdAttr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtendedAttributeName( 
            /* [in] */ BSTR bstrAnyAttrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributeValue( 
            /* [in] */ BSTR bstrAttrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIlsFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIlsFilter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIlsFilter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSubFilter )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveSubFilter )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ IIlsFilter __RPC_FAR *pFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IIlsFilter __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pcElements);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStandardAttributeName )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ ILS_STD_ATTR_NAME usrStdAttr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExtendedAttributeName )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ BSTR bstrAnyAttrName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributeValue )( 
            IIlsFilter __RPC_FAR * This,
            /* [in] */ BSTR bstrAttrValue);
        
        END_INTERFACE
    } IIlsFilterVtbl;

    interface IIlsFilter
    {
        CONST_VTBL struct IIlsFilterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIlsFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIlsFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIlsFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIlsFilter_AddSubFilter(This,pFilter)	\
    (This)->lpVtbl -> AddSubFilter(This,pFilter)

#define IIlsFilter_RemoveSubFilter(This,pFilter)	\
    (This)->lpVtbl -> RemoveSubFilter(This,pFilter)

#define IIlsFilter_GetCount(This,pcElements)	\
    (This)->lpVtbl -> GetCount(This,pcElements)

#define IIlsFilter_SetStandardAttributeName(This,usrStdAttr)	\
    (This)->lpVtbl -> SetStandardAttributeName(This,usrStdAttr)

#define IIlsFilter_SetExtendedAttributeName(This,bstrAnyAttrName)	\
    (This)->lpVtbl -> SetExtendedAttributeName(This,bstrAnyAttrName)

#define IIlsFilter_SetAttributeValue(This,bstrAttrValue)	\
    (This)->lpVtbl -> SetAttributeValue(This,bstrAttrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IIlsFilter_AddSubFilter_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [in] */ IIlsFilter __RPC_FAR *pFilter);


void __RPC_STUB IIlsFilter_AddSubFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsFilter_RemoveSubFilter_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [in] */ IIlsFilter __RPC_FAR *pFilter);


void __RPC_STUB IIlsFilter_RemoveSubFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsFilter_GetCount_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcElements);


void __RPC_STUB IIlsFilter_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsFilter_SetStandardAttributeName_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [in] */ ILS_STD_ATTR_NAME usrStdAttr);


void __RPC_STUB IIlsFilter_SetStandardAttributeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsFilter_SetExtendedAttributeName_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [in] */ BSTR bstrAnyAttrName);


void __RPC_STUB IIlsFilter_SetExtendedAttributeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IIlsFilter_SetAttributeValue_Proxy( 
    IIlsFilter __RPC_FAR * This,
    /* [in] */ BSTR bstrAttrValue);


void __RPC_STUB IIlsFilter_SetAttributeValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIlsFilter_INTERFACE_DEFINED__ */


#ifndef __IEnumIlsProtocols_INTERFACE_DEFINED__
#define __IEnumIlsProtocols_INTERFACE_DEFINED__

/* interface IEnumIlsProtocols */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IEnumIlsProtocols __RPC_FAR *LPENUM_ILS_PROTOCOLS;


EXTERN_C const IID IID_IEnumIlsProtocols;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC98E-20E6-11d0-8796-444553540000")
    IEnumIlsProtocols : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cProtocols,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *rgpProtocol,
            /* [out] */ ULONG __RPC_FAR *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cProtocols) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumIlsProtocolsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumIlsProtocols __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumIlsProtocols __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumIlsProtocols __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumIlsProtocols __RPC_FAR * This,
            /* [in] */ ULONG cProtocols,
            /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *rgpProtocol,
            /* [out] */ ULONG __RPC_FAR *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumIlsProtocols __RPC_FAR * This,
            /* [in] */ ULONG cProtocols);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumIlsProtocols __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumIlsProtocols __RPC_FAR * This,
            /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol);
        
        END_INTERFACE
    } IEnumIlsProtocolsVtbl;

    interface IEnumIlsProtocols
    {
        CONST_VTBL struct IEnumIlsProtocolsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumIlsProtocols_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumIlsProtocols_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumIlsProtocols_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumIlsProtocols_Next(This,cProtocols,rgpProtocol,pcFetched)	\
    (This)->lpVtbl -> Next(This,cProtocols,rgpProtocol,pcFetched)

#define IEnumIlsProtocols_Skip(This,cProtocols)	\
    (This)->lpVtbl -> Skip(This,cProtocols)

#define IEnumIlsProtocols_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumIlsProtocols_Clone(This,ppEnumProtocol)	\
    (This)->lpVtbl -> Clone(This,ppEnumProtocol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumIlsProtocols_Next_Proxy( 
    IEnumIlsProtocols __RPC_FAR * This,
    /* [in] */ ULONG cProtocols,
    /* [out] */ IIlsProtocol __RPC_FAR *__RPC_FAR *rgpProtocol,
    /* [out] */ ULONG __RPC_FAR *pcFetched);


void __RPC_STUB IEnumIlsProtocols_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsProtocols_Skip_Proxy( 
    IEnumIlsProtocols __RPC_FAR * This,
    /* [in] */ ULONG cProtocols);


void __RPC_STUB IEnumIlsProtocols_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsProtocols_Reset_Proxy( 
    IEnumIlsProtocols __RPC_FAR * This);


void __RPC_STUB IEnumIlsProtocols_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsProtocols_Clone_Proxy( 
    IEnumIlsProtocols __RPC_FAR * This,
    /* [out] */ IEnumIlsProtocols __RPC_FAR *__RPC_FAR *ppEnumProtocol);


void __RPC_STUB IEnumIlsProtocols_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumIlsProtocols_INTERFACE_DEFINED__ */


#ifndef __IEnumIlsUsers_INTERFACE_DEFINED__
#define __IEnumIlsUsers_INTERFACE_DEFINED__

/* interface IEnumIlsUsers */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IEnumIlsUsers __RPC_FAR *LPENUM_ILS_USERS;


EXTERN_C const IID IID_IEnumIlsUsers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC98F-20E6-11d0-8796-444553540000")
    IEnumIlsUsers : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cUsers,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *rgpUsers,
            /* [out] */ ULONG __RPC_FAR *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cUsers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUser) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumIlsUsersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumIlsUsers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumIlsUsers __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumIlsUsers __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumIlsUsers __RPC_FAR * This,
            /* [in] */ ULONG cUsers,
            /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *rgpUsers,
            /* [out] */ ULONG __RPC_FAR *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumIlsUsers __RPC_FAR * This,
            /* [in] */ ULONG cUsers);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumIlsUsers __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumIlsUsers __RPC_FAR * This,
            /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUser);
        
        END_INTERFACE
    } IEnumIlsUsersVtbl;

    interface IEnumIlsUsers
    {
        CONST_VTBL struct IEnumIlsUsersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumIlsUsers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumIlsUsers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumIlsUsers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumIlsUsers_Next(This,cUsers,rgpUsers,pcFetched)	\
    (This)->lpVtbl -> Next(This,cUsers,rgpUsers,pcFetched)

#define IEnumIlsUsers_Skip(This,cUsers)	\
    (This)->lpVtbl -> Skip(This,cUsers)

#define IEnumIlsUsers_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumIlsUsers_Clone(This,ppEnumUser)	\
    (This)->lpVtbl -> Clone(This,ppEnumUser)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumIlsUsers_Next_Proxy( 
    IEnumIlsUsers __RPC_FAR * This,
    /* [in] */ ULONG cUsers,
    /* [out] */ IIlsUser __RPC_FAR *__RPC_FAR *rgpUsers,
    /* [out] */ ULONG __RPC_FAR *pcFetched);


void __RPC_STUB IEnumIlsUsers_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsUsers_Skip_Proxy( 
    IEnumIlsUsers __RPC_FAR * This,
    /* [in] */ ULONG cUsers);


void __RPC_STUB IEnumIlsUsers_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsUsers_Reset_Proxy( 
    IEnumIlsUsers __RPC_FAR * This);


void __RPC_STUB IEnumIlsUsers_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsUsers_Clone_Proxy( 
    IEnumIlsUsers __RPC_FAR * This,
    /* [out] */ IEnumIlsUsers __RPC_FAR *__RPC_FAR *ppEnumUser);


void __RPC_STUB IEnumIlsUsers_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumIlsUsers_INTERFACE_DEFINED__ */


#ifndef __IEnumIlsNames_INTERFACE_DEFINED__
#define __IEnumIlsNames_INTERFACE_DEFINED__

/* interface IEnumIlsNames */
/* [unique][uuid][object] */ 

typedef /* [unique] */ IEnumIlsNames __RPC_FAR *LPENUM_ILS_NAMES;


EXTERN_C const IID IID_IEnumIlsNames;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("440CC990-20E6-11d0-8796-444553540000")
    IEnumIlsNames : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cNames,
            /* [out] */ BSTR __RPC_FAR *rgpbstrName,
            /* [out] */ ULONG __RPC_FAR *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cNames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumIlsNamesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumIlsNames __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumIlsNames __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumIlsNames __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumIlsNames __RPC_FAR * This,
            /* [in] */ ULONG cNames,
            /* [out] */ BSTR __RPC_FAR *rgpbstrName,
            /* [out] */ ULONG __RPC_FAR *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumIlsNames __RPC_FAR * This,
            /* [in] */ ULONG cNames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumIlsNames __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumIlsNames __RPC_FAR * This,
            /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumName);
        
        END_INTERFACE
    } IEnumIlsNamesVtbl;

    interface IEnumIlsNames
    {
        CONST_VTBL struct IEnumIlsNamesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumIlsNames_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumIlsNames_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumIlsNames_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumIlsNames_Next(This,cNames,rgpbstrName,pcFetched)	\
    (This)->lpVtbl -> Next(This,cNames,rgpbstrName,pcFetched)

#define IEnumIlsNames_Skip(This,cNames)	\
    (This)->lpVtbl -> Skip(This,cNames)

#define IEnumIlsNames_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumIlsNames_Clone(This,ppEnumName)	\
    (This)->lpVtbl -> Clone(This,ppEnumName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumIlsNames_Next_Proxy( 
    IEnumIlsNames __RPC_FAR * This,
    /* [in] */ ULONG cNames,
    /* [out] */ BSTR __RPC_FAR *rgpbstrName,
    /* [out] */ ULONG __RPC_FAR *pcFetched);


void __RPC_STUB IEnumIlsNames_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsNames_Skip_Proxy( 
    IEnumIlsNames __RPC_FAR * This,
    /* [in] */ ULONG cNames);


void __RPC_STUB IEnumIlsNames_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsNames_Reset_Proxy( 
    IEnumIlsNames __RPC_FAR * This);


void __RPC_STUB IEnumIlsNames_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIlsNames_Clone_Proxy( 
    IEnumIlsNames __RPC_FAR * This,
    /* [out] */ IEnumIlsNames __RPC_FAR *__RPC_FAR *ppEnumName);


void __RPC_STUB IEnumIlsNames_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumIlsNames_INTERFACE_DEFINED__ */


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
