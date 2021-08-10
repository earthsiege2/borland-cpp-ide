/*

    Copyright (c) 1997-1999  Microsoft Corporation

    Module Name:
        rnderr.h

*/

#ifndef __RND_ERROR_CODES__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __RND_ERROR_CODES__

#include <blberr.h>


// rendezvous component error codes

// First four bits - SEVERITY(11), CUSTOMER FLAG(1), RESERVED(0)
#define RND_INVALID_TIME                  0xe0000200
#define RND_NULL_SERVER_NAME              0xe0000201
#define RND_ALREADY_CONNECTED             0xe0000202
#define RND_NOT_CONNECTED                 0xe0000203

#pragma option pop /*P_O_Pop*/
#endif // __RND_ERROR_CODES__