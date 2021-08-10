
/*++

Copyright (c) 1999  Microsoft Corporation

Module Name:

    sfc.h

Abstract:

    Header file for public SFC interfaces.

Author:

    Wesley Witt (wesw) 2-Feb-1999

Revision History:

--*/



#ifndef _SFC_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define _SFC_


#ifdef __cplusplus
extern "C" {

#endif

#define SFC_DISABLE_NORMAL          0
#define SFC_DISABLE_ASK             1
#define SFC_DISABLE_ONCE            2
#define SFC_DISABLE_SETUP           3
#define SFC_DISABLE_NOPOPUPS        4

#define SFC_SCAN_NORMAL             0
#define SFC_SCAN_ALWAYS             1
#define SFC_SCAN_ONCE               2

#define SFC_QUOTA_DEFAULT           50
#define SFC_QUOTA_ALL_FILES         ((ULONG)-1)


typedef struct _PROTECTED_FILE_DATA {
    WCHAR   FileName[MAX_PATH];
    DWORD   FileNumber;
} PROTECTED_FILE_DATA, *PPROTECTED_FILE_DATA;


BOOL
WINAPI
SfcGetNextProtectedFile(
    IN HANDLE RpcHandle, // must be NULL
    IN PPROTECTED_FILE_DATA ProtFileData
    );

BOOL
WINAPI
SfcIsFileProtected(
    IN HANDLE RpcHandle, // must be NULL
    IN LPCWSTR ProtFileName
    );



#ifdef __cplusplus
}
#endif

#pragma option pop /*P_O_Pop*/
#endif // _SFC_
