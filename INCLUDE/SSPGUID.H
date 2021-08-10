/*++

Copyright (C) Microsoft Corporation, 1996 - 1999

Module Name:

    SspGUID

Abstract:

    This file contains the GUIDS for the low level COM objects/interfaces
    
Author:

    Chris Dudley (cdudley) 1/6/1997

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

    Chris Dudley (cdudley) 2/10/1997

Notes:

--*/

#ifndef __SSPGUID_H__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __SSPGUID_H__

#define IID_DEFINED

// SSPsIDL <common interfaces>
#include <sspsidl_i.c>

// SCardDat
#include <scarddat_i.c>

//SCardMgr
#include <scardmgr_i.c>

//SCardSrv
#include <scardsrv_i.c>

#ifndef CLSCTX_LOCAL
#define CLSCTX_LOCAL            (CLSCTX_INPROC_SERVER| \
                                 CLSCTX_INPROC_HANDLER| \
                                 CLSCTX_LOCAL_SERVER)
#endif
#pragma option pop /*P_O_Pop*/
#endif //__SSPGUID_H__
