#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Aug 25 16:06:21 1999
 */
/* Compiler settings for certbase.idl:
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


#ifndef __certbase_h__
#define __certbase_h__

/* Forward Declarations */ 

/* header files for imported files */
#include "wtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_certbase_0000 */
/* [local] */ 

typedef struct _CERTTRANSBLOB
    {
    unsigned long cb;
    /* [unique][size_is] */ BYTE __RPC_FAR *pb;
    }	CERTTRANSBLOB;

typedef struct _CERTVIEWRESTRICTION
    {
    DWORD ColumnIndex;
    LONG SeekOperator;
    LONG SortOrder;
    /* [unique][size_is] */ BYTE __RPC_FAR *pbValue;
    DWORD cbValue;
    }	CERTVIEWRESTRICTION;



extern RPC_IF_HANDLE __MIDL_itf_certbase_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_certbase_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
