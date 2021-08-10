/*********************************************************/
/**               Microsoft LAN Manager                 **/
/**                                                     **/
/**     Rpc Error Codes from the compiler and runtime   **/
/**                                                     **/
/*********************************************************/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */

/*
If you change this file, you must also change rpcerr.h.
*/

#ifndef __RPCNTERR_H__
#define __RPCNTERR_H__
#define __RPCNTERR_H

#define RPC_S_OK                          ERROR_SUCCESS
#define RPC_S_INVALID_ARG                 ERROR_INVALID_PARAMETER
#define RPC_S_OUT_OF_MEMORY               ERROR_OUTOFMEMORY
#define RPC_S_OUT_OF_THREADS              ERROR_MAX_THRDS_REACHED
#define RPC_S_INVALID_LEVEL               ERROR_INVALID_PARAMETER
#define RPC_S_BUFFER_TOO_SMALL            ERROR_INSUFFICIENT_BUFFER
#define RPC_S_INVALID_SECURITY_DESC       ERROR_INVALID_SECURITY_DESCR
#define RPC_S_ACCESS_DENIED               ERROR_ACCESS_DENIED
#define RPC_S_SERVER_OUT_OF_MEMORY        ERROR_NOT_ENOUGH_SERVER_MEMORY

#define RPC_X_NO_MEMORY                   RPC_S_OUT_OF_MEMORY
#define RPC_X_INVALID_BOUND               RPC_S_INVALID_BOUND
#define RPC_X_INVALID_TAG                 RPC_S_INVALID_TAG
#define RPC_X_ENUM_VALUE_TOO_LARGE        RPC_X_ENUM_VALUE_OUT_OF_RANGE
#define RPC_X_SS_CONTEXT_MISMATCH         ERROR_INVALID_HANDLE
#define RPC_X_INVALID_BUFFER              ERROR_INVALID_USER_BUFFER

#endif /* __RPCNTERR_H__ */
