/*++

Copyright (c) 1997, Microsoft Corporation

Module Name:

    dxmrtp.h

Abstract:

    Master include file for Windows DirectX Media Based RTP implementation.

--*/

#ifndef __DXMRTP_INCLUDED__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __DXMRTP_INCLUDED__

/* Include all of the filter header files */
#include <amrtpnet.h>
#include <amrtpdmx.h>
#include <amrtpss.h>
#include <irtprph.h>
#include <irtpsph.h>
#include <amrtpuid.h>
#include <g711uids.h>

#pragma option pop /*P_O_Pop*/
#endif /* #ifndef __DXMRTP_INCLUDED__ */
