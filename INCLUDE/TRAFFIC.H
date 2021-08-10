/*++

Copyright (c) 1996-1998 Microsoft Corporation

Module Name:

    traffic.h

Abstract:

    This module contains API definitions for the traffic control interface.

--*/

#ifndef __TRAFFIC_H
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __TRAFFIC_H

#ifdef __cplusplus
extern  "C" {
#endif

//---------------------------------------------------------------------------
//
// Define's
//
#define CURRENT_TCI_VERSION       	0x0002

//
// Flow flags
//
#define TC_FLAGS_PERSIST			0x00000001
#define TC_FLAGS_SHUTDOWN			0x00000002

//
// Definitions of notification events. These may be passed
// to the client's notification handler, to identify the 
// notification type
//

//
// A TC interface has come up
//
#define TC_NOTIFY_IFC_UP		1
// 
// A TC interface has come down
//
#define TC_NOTIFY_IFC_CLOSE		2
//
// A change on a TC interface, typically a change in the 
// list of supported network addresses
//
#define TC_NOTIFY_IFC_CHANGE	3
//
// A TC parameter has changed
//
#define TC_NOTIFY_PARAM_CHANGED	4
//
// A flow has been closed by the TC interface
// for example: after a remote call close, or the whole interface
// is going down
//
#define TC_NOTIFY_FLOW_CLOSE		5

#define TC_INVALID_HANDLE	((HANDLE)0)

#define MAX_STRING_LENGTH	256


//---------------------------------------------------------------------------
//
// Typedef's and structures
//

#ifndef CALLBACK
#define CALLBACK __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY FAR __stdcall
#endif

//
// Handlers registered by the TCI client
//

typedef
VOID (CALLBACK * TCI_NOTIFY_HANDLER)(
    IN	HANDLE		ClRegCtx,
    IN	HANDLE		ClIfcCtx,
	IN	ULONG		Event, 		// See list below
	IN	ULONG		SubCode,
	IN	ULONG		BufSize,
	IN	PVOID		Buffer
	);

typedef
VOID (CALLBACK * TCI_ADD_FLOW_COMPLETE_HANDLER)(
	IN HANDLE 	ClFlowCtx,
	IN ULONG	Status
    );

typedef
VOID (CALLBACK * TCI_MOD_FLOW_COMPLETE_HANDLER)(
	IN HANDLE 	ClFlowCtx,
	IN ULONG	Status
    );

typedef
VOID (CALLBACK * TCI_DEL_FLOW_COMPLETE_HANDLER)(
	IN HANDLE 	ClFlowCtx,
	IN ULONG	Status
    );


typedef struct _TCI_CLIENT_FUNC_LIST {

    TCI_NOTIFY_HANDLER				ClNotifyHandler;
    TCI_ADD_FLOW_COMPLETE_HANDLER	ClAddFlowCompleteHandler;
    TCI_MOD_FLOW_COMPLETE_HANDLER	ClModifyFlowCompleteHandler;
    TCI_DEL_FLOW_COMPLETE_HANDLER	ClDeleteFlowCompleteHandler;

} TCI_CLIENT_FUNC_LIST, *PTCI_CLIENT_FUNC_LIST;


#ifndef _NTDDNDIS_
//
// The structures below need to be consistent with TRANSPORT_ADDRESS structures in TDI.H
//
typedef struct _NETWORK_ADDRESS
{
	USHORT		AddressLength;		// length in bytes of Address[] in this
	USHORT		AddressType;		// type of this address (NDIS_PROTOCOL_ID_XXX above)
	UCHAR		Address[1];			// actually AddressLength bytes long
} NETWORK_ADDRESS, *PNETWORK_ADDRESS;

//
// The following is used with OID_GEN_NETWORK_LAYER_ADDRESSES to set network layer addresses on an interface
//
typedef struct _NETWORK_ADDRESS_LIST
{
	LONG		AddressCount;		// number of addresses following
	USHORT		AddressType;		// type of this address (NDIS_PROTOCOL_ID_XXX above)
	NETWORK_ADDRESS Address[1];		// actually AddressCount elements long
} NETWORK_ADDRESS_LIST, *PNETWORK_ADDRESS_LIST;

//
// IP address - This must remain consistent with TDI_ADDRESS_IP in tdi.h
//
typedef struct _NETWORK_ADDRESS_IP
{
	USHORT		sin_port;
	ULONG		in_addr;
	UCHAR		sin_zero[8];
} NETWORK_ADDRESS_IP, *PNETWORK_ADDRESS_IP;

#define NETWORK_ADDRESS_LENGTH_IP sizeof (NETWORK_ADDRESS_IP)

//
// IPX address - This must remain consistent with TDI_ADDRESS_IPX in tdi.h.
//
typedef struct _NETWORK_ADDRESS_IPX
{
	ULONG		NetworkAddress;
	UCHAR		NodeAddress[6];
	USHORT		Socket;
} NETWORK_ADDRESS_IPX, *PNETWORK_ADDRESS_IPX;

#endif


//
// Network address descriptor
//
typedef struct _ADDRESS_LIST_DESCRIPTOR {

    ULONG					MediaType;
    NETWORK_ADDRESS_LIST	AddressList;

} ADDRESS_LIST_DESCRIPTOR, *PADDRESS_LIST_DESCRIPTOR;


//
// An interface ID that is returned by the enumerator
//
typedef struct _TC_IFC_DESCRIPTOR {

    ULONG					Length;
    LPWSTR					pInterfaceName;
	ADDRESS_LIST_DESCRIPTOR	AddressListDesc;

} TC_IFC_DESCRIPTOR, *PTC_IFC_DESCRIPTOR;


//
// Filters are used to match packets. The Pattern field
// indicates the values to which bits in corresponding
// positions in candidate packets should be compared. The
// Mask field indicates which bits are to be compared and
// which bits are don't cares.
//
// Different filters can be submitted on the TCI interface.
// The generic filter structure is defined to include an
// AddressType, which indicates the specific type of filter to
// follow.
//

typedef struct _TC_GEN_FILTER {

    USHORT	AddressType;	// IP, IPX, etc.
    ULONG	PatternSize;	// byte count of the pattern
	PVOID  	Pattern;		// specific format, e.g. IP_PATTERN
	PVOID  	Mask;			// same type as Pattern

} TC_GEN_FILTER, *PTC_GEN_FILTER;


//
// A generic flow includes two flowspecs and a freeform
// buffer which contains flow specific TC objects.
//
typedef struct _TC_GEN_FLOW {
	
    FLOWSPEC		SendingFlowspec;
	FLOWSPEC		ReceivingFlowspec;
	ULONG			TcObjectsLength;		// number of optional bytes
	QOS_OBJECT_HDR	TcObjects[1];

} TC_GEN_FLOW, *PTC_GEN_FLOW;


//
// Format of specific pattern or mask used by GPC for the IP protocol
//
typedef struct _IP_PATTERN {

    ULONG		Reserved1;
    ULONG		Reserved2;

    ULONG		SrcAddr;
    ULONG		DstAddr;

    union {
        struct { USHORT s_srcport,s_dstport; } S_un_ports;
        struct { UCHAR s_type,s_code; USHORT filler; } S_un_icmp;
        ULONG	S_Spi;
    } S_un;

    UCHAR		ProtocolId;
    UCHAR		Reserved3[3];

#define tcSrcPort S_un.S_un_ports.s_srcport
#define tcDstPort S_un.S_un_ports.s_dstport
#define tcIcmpType        S_un.S_un_icmp.s_type
#define tcIcmpCode        S_un.S_un_icmp.s_code
#define tcSpi             S_un.S_Spi

} IP_PATTERN, *PIP_PATTERN;

//
// Format of specific pattern or mask used by GPC for the IPX protocol
//
typedef struct _IPX_PATTERN {

    struct {
        ULONG 	NetworkAddress;
        UCHAR 	NodeAddress[6];
        USHORT 	Socket;
    } Src, Dest;

} IPX_PATTERN, *PIPX_PATTERN;


//
// The enumeration buffer is the flow parameters + a list of filters
//
typedef struct _ENUMERATION_BUFFER {

	ULONG			Length;
	ULONG			OwnerProcessId;
    USHORT			FlowNameLength;
    WCHAR			FlowName[MAX_STRING_LENGTH];
	PTC_GEN_FLOW	pFlow;
	ULONG			NumberOfFilters;
	TC_GEN_FILTER	GenericFilter[1]; 	// one for each filter

} ENUMERATION_BUFFER, *PENUMERATION_BUFFER;
	

//
// A class map structure is used by internal TC component
// such as the CBQ.
// This should have been in qos.h but we'll put it here until
// the time is ready
//

#define CLSMAP_ID_BASE                5000
#define CLSMAP_OBJECT_SERVICETYPE     (0x00000000 + CLSMAP_ID_BASE)
#define CLSMAP_OBJECT_END_OF_LIST     (0x00000001 + CLSMAP_ID_BASE)

//
// The servicetype object can be used to override the default class for // a given service type
//
typedef struct _CLSMAP_SERVICETYPE {
    QOS_OBJECT_HDR	Header;
    ULONG			ServiceType;
    ULONG			ClassId;
} CLSMAP_SERVICETYPE, *PCLSMAP_SERVICETYPE;

typedef struct _TC_CLASS_MAP_FLOW {

    ULONG       	DefaultClass;			// Default Class Id
    ULONG       	ObjectsLength;			// Length of Objects
    QOS_OBJECT_HDR	Objects;				// Offset to Objects

} TC_CLASS_MAP_FLOW, *PTC_CLASS_MAP_FLOW;


//
// class hierarchy definitions
//

typedef struct _QOS_HIERARCHY_CLASS {

	ULONG ClassId;				// Unique nonzero class identifier
    ULONG Allocation;			// Share of link bandwidth
    ULONG BurstLength;			// Maximum burst size
    ULONG Flags;				// See below
    ULONG ParentClassId;		// Id of parent class
    ULONG ObjectsLength;		// For possible future use
    UCHAR Objects[1];

} QOS_HIERARCHY_CLASS, *PQOS_HIERARCHY_CLASS;

#define HCLASS_FLAG_BOUNDED				1


//---------------------------------------------------------------------------
//
// Interface Function Definitions
//

ULONG
APIENTRY
TcRegisterClient(
	IN		ULONG					TciVersion,
    IN		HANDLE					ClRegCtx,
	IN		PTCI_CLIENT_FUNC_LIST	ClientHandlerList,
	OUT		PHANDLE					pClientHandle
    );

ULONG
APIENTRY
TcEnumerateInterfaces(
	IN 		HANDLE				ClientHandle,
	IN OUT	PULONG				pBufferSize,
	OUT		PTC_IFC_DESCRIPTOR 	InterfaceBuffer
    );

ULONG
APIENTRY
TcOpenInterfaceA(
	IN		LPSTR			pInterfaceName,
	IN 		HANDLE			ClientHandle,
	IN		HANDLE			ClIfcCtx,
	OUT		PHANDLE			pIfcHandle
    );

ULONG
APIENTRY
TcOpenInterfaceW(
	IN		LPWSTR			pInterfaceName,
	IN 		HANDLE			ClientHandle,
	IN		HANDLE			ClIfcCtx,
	OUT		PHANDLE			pIfcHandle
    );

ULONG
APIENTRY
TcCloseInterface(
    IN 		HANDLE       IfcHandle
    );

ULONG
APIENTRY
TcQueryInterface(
	IN 		HANDLE 		IfcHandle,
    IN		LPGUID		pGuidParam,
    IN		BOOLEAN		NotifyChange,
    IN OUT	PULONG		pBufferSize,
    OUT		PVOID		Buffer
    );

ULONG
APIENTRY
TcSetInterface(
	IN 		HANDLE 		IfcHandle,
    IN		LPGUID		pGuidParam,
    IN 		ULONG		BufferSize,
    IN		PVOID		Buffer
    );

ULONG
APIENTRY
TcQueryFlowA(
	IN 		LPSTR		pFlowName,
    IN		LPGUID		pGuidParam,
    IN OUT	PULONG		pBufferSize,
    OUT		PVOID		Buffer
    );

ULONG
APIENTRY
TcQueryFlowW(
	IN 		LPWSTR		pFlowName,
    IN		LPGUID		pGuidParam,
    IN OUT	PULONG		pBufferSize,
    OUT		PVOID		Buffer
    );

ULONG
APIENTRY
TcSetFlowA(
	IN 		LPSTR		pFlowName,
    IN		LPGUID		pGuidParam,
    IN 		ULONG		BufferSize,
    IN		PVOID		Buffer
    );

ULONG
APIENTRY
TcSetFlowW(
	IN 		LPWSTR		pFlowName,
    IN		LPGUID		pGuidParam,
    IN 		ULONG		BufferSize,
    IN		PVOID		Buffer
    );

ULONG
APIENTRY
TcAddFlow(
	IN  	HANDLE	     	IfcHandle,
    IN		HANDLE			ClFlowCtx,
    IN		ULONG			Flags,
    IN		PTC_GEN_FLOW	pGenericFlow,
    OUT		PHANDLE			pFlowHandle
);

ULONG
APIENTRY
TcGetFlowNameA(
	IN		HANDLE			FlowHandle,
    IN		ULONG			StrSize,
    OUT		LPSTR			pFlowName
);

ULONG
APIENTRY
TcGetFlowNameW(
	IN		HANDLE			FlowHandle,
    IN		ULONG			StrSize,
    OUT		LPWSTR			pFlowName
);

ULONG
APIENTRY
TcModifyFlow(	
	IN		HANDLE			FlowHandle,
    IN		PTC_GEN_FLOW	pGenericFlow
    );

ULONG
APIENTRY
TcAddFilter(
	IN		HANDLE			FlowHandle,
    IN		PTC_GEN_FILTER	pGenericFilter,
    OUT		PHANDLE			pFilterHandle
    );


ULONG
APIENTRY
TcDeregisterClient(
	IN 		HANDLE 			ClientHandle
    );


ULONG
APIENTRY
TcDeleteFlow(
    IN 		HANDLE  		FlowHandle
    );

ULONG
APIENTRY
TcDeleteFilter(
    IN 		HANDLE  		FilterHandle
    );

ULONG
APIENTRY
TcEnumerateFlows(	
    IN		HANDLE					IfcHandle,
	IN OUT 	PHANDLE					pEnumHandle,
    IN OUT	PULONG					pFlowCount,
    IN OUT	PULONG					pBufSize,
    OUT		PENUMERATION_BUFFER		Buffer
    );


ULONG
APIENTRY
TcAddClassMapFlow(
	IN  	HANDLE	     		IfcHandle,
    IN		HANDLE				ClFlowCtx,
    IN		ULONG				Flags,
    IN		PTC_CLASS_MAP_FLOW	pClassMapFlow,
    OUT		PHANDLE				pFlowHandle
);


#ifdef UNICODE

#define TcOpenInterface					TcOpenInterfaceW
#define TcQueryFlow						TcQueryFlowW
#define TcSetFlow						TcSetFlowW
#define TcGetFlowName					TcGetFlowNameW

#else	// UNICODE

#define TcOpenInterface		TcOpenInterfaceA
#define TcQueryFlow			TcQueryFlowA
#define TcSetFlow			TcSetFlowA
#define TcGetFlowName		TcGetFlowNameA

#endif	// UNICODE


#ifdef __cplusplus
}
#endif


#pragma option pop /*P_O_Pop*/
#endif

