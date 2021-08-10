/*

Copyright (c) 1998-1999  Microsoft Corporation

Module Name:
    blberr.h

Abstract:


Author:

*/

#ifndef __SDPBLB_ERROR_CODES__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __SDPBLB_ERROR_CODES__

#include <sdperr.h>

// First four bits - SEVERITY(11), CUSTOMER FLAG(1), RESERVED(0)
#define SDPBLB_CONF_BLOB_DESTROYED                  0xe0000300



#pragma option pop /*P_O_Pop*/
#endif // __SDPBLB_ERROR_CODES__

