//***************************************************************************
//
//  WBEMSEC.H
//
//  Purpose: Provides prototypes for some security helper functions.
//
//  Copyright (c)1998 Microsoft Corporation, All Rights Reserved
//
//***************************************************************************

#ifndef _WBEMSEC_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define _WBEMSEC_H_

HRESULT InitializeSecurity(BOOL bAuthenticate);
HRESULT SetInterfaceSecurity(IUnknown * pInterface, LPWSTR pDomain, LPWSTR pUser, LPWSTR pPassword,bool bAuthenticate);
bool IsAuthenticated(IUnknown * pFrom);

#pragma option pop /*P_O_Pop*/
#endif // _WBEMSEC_H_
