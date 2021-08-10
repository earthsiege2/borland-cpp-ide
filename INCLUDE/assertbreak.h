#pragma option push -b -a8 -pc -A- /*P_O_Push*/
//=================================================================
//
// AssertBreak.h -- AssertBreak macro definition
//
// Copyright 1997- 1999 Microsoft Corporation
//
// Revisions:    10/15/97    Created
//
//=================================================================

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _ASSERT_BREAK_HMH_
#define _ASSERT_BREAK_HMH_

#include <stdio.h>

// We'll need both of these values in case we're running in NT.
// Since our project is not an NT-only project, these are #ifdefd
// out of windows.h

#ifndef _WIN32_WINNT
#define MB_SERVICE_NOTIFICATION          0x00200000L
#define MB_SERVICE_NOTIFICATION_NT3X     0x00040000L
#endif

void POLARITY WINAPI assert_break( const char* pszReason, const char* pszFilename, int nLine );

#if (defined DEBUG || defined _DEBUG)
#define ASSERT_BREAK(exp)    \
    if (!(exp)) { \
		assert_break( #exp, __FILE__, __LINE__ ); \
    }
#else
#define ASSERT_BREAK(exp)
#endif

#endif
#pragma option pop /*P_O_Pop*/
