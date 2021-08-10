#pragma option push -b -a8 -pc -A- /*P_O_Push*/
/*++

Copyright (c) 1992-1999 Microsoft Corporation

Module Name:

    scode.h

Abstract:

    Obsolete SCODE header file.  Use WINERROR.H

--*/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef  _WINERROR_
#include <winerror.h>
#endif

#pragma option pop /*P_O_Pop*/
