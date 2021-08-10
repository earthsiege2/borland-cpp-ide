/*++

Module Name:

    rpcdce2.h

Abstract:

    This file contains the prototypes of the RPC APIs which are not contained
    in the runtime dll, but in a seperate library.

Author:

    Michael Montague (mikemon) 12-Apr-1993

Revision History:

--*/

/* $Copyright: 1994$ */

#ifndef __RPCDCE2_H__
#define __RPCDCE2_H__
#define __RPCDCE2_H
#pragma option -b

#ifdef __cplusplus
extern "C" {
#endif

signed int RPC_ENTRY
UuidCompare (
    IN UUID __RPC_FAR * Uuid1,
    IN UUID __RPC_FAR * Uuid2,
    OUT RPC_STATUS __RPC_FAR * Status
    );

RPC_STATUS RPC_ENTRY
UuidCreateNil (
    OUT UUID __RPC_FAR * NilUuid
    );

int RPC_ENTRY
UuidEqual (
    IN UUID __RPC_FAR * Uuid1,
    IN UUID __RPC_FAR * Uuid2,
    OUT RPC_STATUS __RPC_FAR * Status
    );

unsigned short RPC_ENTRY
UuidHash (
    IN UUID __RPC_FAR * Uuid,
    OUT RPC_STATUS __RPC_FAR * Status
    );

int RPC_ENTRY
UuidIsNil (
    IN UUID __RPC_FAR * Uuid,
    OUT RPC_STATUS __RPC_FAR * Status
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS RPC_ENTRY
DceErrorInqTextA (
    IN RPC_STATUS RpcStatus,
    OUT unsigned char __RPC_FAR * ErrorText
    );

RPC_STATUS RPC_ENTRY
DceErrorInqTextW (
    IN RPC_STATUS RpcStatus,
    OUT unsigned short __RPC_FAR * ErrorText
    );

#ifdef UNICODE
#define DceErrorInqText DceErrorInqTextW
#else /* UNICODE */
#define DceErrorInqText DceErrorInqTextA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS RPC_ENTRY
DceErrorInqText (
    IN RPC_STATUS RpcStatus,
    OUT unsigned char __RPC_FAR * ErrorText
    );

#endif /* RPC_UNICODE_SUPPORTED */

#define DCE_C_ERROR_STRING_LEN 256

typedef void __RPC_FAR * RPC_EP_INQ_HANDLE;

#define  RPC_C_EP_ALL_ELTS        0
#define  RPC_C_EP_MATCH_BY_IF     1
#define  RPC_C_EP_MATCH_BY_OBJ    2
#define  RPC_C_EP_MATCH_BY_BOTH   3

#define  RPC_C_VERS_ALL           1
#define  RPC_C_VERS_COMPATIBLE    2
#define  RPC_C_VERS_EXACT         3
#define  RPC_C_VERS_MAJOR_ONLY    4
#define  RPC_C_VERS_UPTO          5

RPC_STATUS RPC_ENTRY
RpcMgmtEpEltInqBegin (
    IN RPC_BINDING_HANDLE EpBinding OPTIONAL,
    IN unsigned long InquiryType,
    IN RPC_IF_ID __RPC_FAR * IfId OPTIONAL,
    IN unsigned long VersOption OPTIONAL,
    IN UUID __RPC_FAR * ObjectUuid OPTIONAL,
    OUT RPC_EP_INQ_HANDLE __RPC_FAR * InquiryContext
    );

RPC_STATUS RPC_ENTRY
RpcMgmtEpEltInqDone (
    IN OUT RPC_EP_INQ_HANDLE __RPC_FAR * InquiryContext
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS RPC_ENTRY
RpcMgmtEpEltInqNextA (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID __RPC_FAR * IfId,
    OUT RPC_BINDING_HANDLE __RPC_FAR * Binding OPTIONAL,
    OUT UUID __RPC_FAR * ObjectUuid OPTIONAL,
    OUT unsigned char __RPC_FAR * __RPC_FAR * Annotation OPTIONAL
    );

RPC_STATUS RPC_ENTRY
RpcMgmtEpEltInqNextW (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID __RPC_FAR * IfId,
    OUT RPC_BINDING_HANDLE __RPC_FAR * Binding OPTIONAL,
    OUT UUID __RPC_FAR * ObjectUuid OPTIONAL,
    OUT unsigned short __RPC_FAR * __RPC_FAR * Annotation OPTIONAL
    );

#ifdef UNICODE
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextW
#else /* UNICODE */
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS RPC_ENTRY
RpcMgmtEpEltInqNext (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID __RPC_FAR * IfId,
    OUT RPC_BINDING_HANDLE __RPC_FAR * Binding OPTIONAL,
    OUT unsigned char __RPC_FAR * __RPC_FAR * Annotation OPTIONAL
    );

#endif /* RPC_UNICODE_SUPPORTED */

RPC_STATUS RPC_ENTRY
RpcMgmtEpUnregister (
    IN RPC_BINDING_HANDLE EpBinding OPTIONAL,
    IN RPC_IF_ID __RPC_FAR * IfId,
    IN RPC_BINDING_HANDLE Binding,
    IN UUID __RPC_FAR * ObjectUuid OPTIONAL
    );

typedef int
(__RPC_API * RPC_MGMT_AUTHORIZATION_FN) (
    IN RPC_BINDING_HANDLE ClientBinding,
    IN unsigned long RequestedMgmtOperation,
    OUT RPC_STATUS __RPC_FAR * Status
    );

#define RPC_C_MGMT_INQ_IF_IDS         0
#define RPC_C_MGMT_INQ_PRINC_NAME     1
#define RPC_C_MGMT_INQ_STATS          2
#define RPC_C_MGMT_IS_SERVER_LISTEN   3
#define RPC_C_MGMT_STOP_SERVER_LISTEN 4

RPC_STATUS RPC_ENTRY
RpcMgmtSetAuthorizationFn (
    IN RPC_MGMT_AUTHORIZATION_FN AuthorizationFn
    );

#ifdef __cplusplus
}
#endif

#pragma option -b.
#endif /* __RPCDCE2_H__ */

