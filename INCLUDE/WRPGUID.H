/*++

Copyright (C) Microsoft Corporation, 1996 - 1999

Module Name:

    wrpguid.h 

Abstract:

	This file includes the GUIDS for the Vendor wrapper COM object (interfaces,
	type library, etc.)
	
Author:

    Chris Dudley (cdudley) 1/2/1997

Environment:

    Win32, C++ w/Exceptions, COM/OLE

Revision History:

    Chris Dudley (cdudley) 2/10/1997

Notes:


--*/

#ifndef __WRPGUID_H__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __WRPGUID_H__

////////////////////////////////////////////////////////////////////////////
//
// include the header files
//
#define IID_DEFINED
#include <scardcom_i.c>

////////////////////////////////////////////////////////////////////////////////

#pragma option pop /*P_O_Pop*/
#endif
