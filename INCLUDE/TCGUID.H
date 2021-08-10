/*++

Copyright (c) 1996-1998 Microsoft Corporation

Module Name:

    tcguid.h

Abstract:

    This module contains QoS guid definitions for use by the
    Traffic Control users.

--*/

#ifndef __TCGUID_H
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __TCGUID_H

#ifdef __cplusplus
extern  "C" {
#endif

//---------------------------------------------------------------------------
//
//	Remaining Bandwidth guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_REMAINING_BANDWIDTH, 0xc4c51720L, 0x40ec, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Default Shape Mode for Controlled Load guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_DEFAULT_SHAPEMODE_CONTROLLEDLOAD, 0xde7a83b0L, 0x40ec, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Default Shape Mode for Guaranteed Service guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_DEFAULT_SHAPEMODE_GUARANTEED, 0xae85e4e2L, 0x611f, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Best Effort Bandwidth guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_BESTEFFORT_BANDWIDTH, 0xed885290L, 0x40ec, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Latency guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_LATENCY, 0xfc408ef0L, 0x40ec, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Supported Service Types
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_SERVICETYPES_SUPPORTED, 0x38797240L, 0x4665, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Flow Count guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_FLOW_COUNT, 0x1147f880L, 0x40ed, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Non Best Effort Limit guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_NON_BESTEFFORT_LIMIT, 0x185c44e0L, 0x40ed, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Supported Scheduling Profiles List guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_SCHEDULING_PROFILES_SUPPORTED, 0x1ff890f0L, 0x40ed, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Current Scheduling Profile guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_CURRENT_SCHEDULING_PROFILE, 0x2966ed30L, 0x40ed, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Maximum Outstanding Sends guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_MAX_OUTSTANDING_SENDS, 0x161ffa86L, 0x6120, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
//	Disable DRR guid
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_DISABLE_DRR, 0x1fa6dc7aL, 0x6120, 0x11d1, 0x2c, 0x91, 0x00, 0xaa, 0x00, 0x57, 0x49, 0x15);

//---------------------------------------------------------------------------
//
// Packet scheduler statistics
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_STATISTICS_BUFFER, 0xbb2c0980L,0xe900,0x11d1,0xb0,0x7e,0x00,0x80,0xc7,0x13,0x82,0xbf);

//---------------------------------------------------------------------------
//
// Packet Scheduler Logging ( Log Threshold reached )
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_LOG_THRESHOLD_REACHED, 0x357b74d2L,0x6134,0x11d1,0xab,0x5b,0x00,0xa0,0xc9,0x24,0x88,0x37);

//---------------------------------------------------------------------------
//
// Packet Scheduler Logging ( Log Buffer Size )
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_LOG_BUFFER_SIZE, 0x357b74d3L,0x6134,0x11d1,0xab,0x5b,0x00,0xa0,0xc9,0x24,0x88,0x37);

//---------------------------------------------------------------------------
//
// Packet Scheduler Logging ( Log Threshold )
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_LOG_THRESHOLD, 0x357b74d0L,0x6134,0x11d1,0xab,0x5b,0x00,0xa0,0xc9,0x24,0x88,0x37);

//---------------------------------------------------------------------------
//
// Packet Scheduler Logging ( Log Data )
//
//---------------------------------------------------------------------------

DEFINE_GUID( GUID_QOS_LOG_DATA, 0x357b74d1L,0x6134,0x11d1,0xab,0x5b,0x00,0xa0,0xc9,0x24,0x88,0x37);

#ifdef __cplusplus
}
#endif


#pragma option pop /*P_O_Pop*/
#endif __TCGUID_H
