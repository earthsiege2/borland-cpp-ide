// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NB30.pas' rev: 5.00

#ifndef NB30HPP
#define NB30HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nb30
{
//-- type declarations -------------------------------------------------------
struct TNCB;
typedef TNCB *PNCB;

typedef void __fastcall (*TNCBPostProc)(PNCB P);

#pragma pack(push, 1)
struct TNCB
{
	char ncb_command;
	char ncb_retcode;
	char ncb_lsn;
	char ncb_num;
	char *ncb_buffer;
	Word ncb_length;
	char ncb_callname[16];
	char ncb_name[16];
	char ncb_rto;
	char ncb_sto;
	TNCBPostProc ncb_post;
	char ncb_lana_num;
	char ncb_cmd_cplt;
	char ncb_reserve[10];
	unsigned ncb_event;
} ;
#pragma pack(pop)

struct TAdapterStatus;
typedef TAdapterStatus *PAdapterStatus;

#pragma pack(push, 1)
struct TAdapterStatus
{
	char adapter_address[6];
	char rev_major;
	char reserved0;
	char adapter_type;
	char rev_minor;
	Word duration;
	Word frmr_recv;
	Word frmr_xmit;
	Word iframe_recv_err;
	Word xmit_aborts;
	unsigned xmit_success;
	unsigned recv_success;
	Word iframe_xmit_err;
	Word recv_buff_unavail;
	Word t1_timeouts;
	Word ti_timeouts;
	unsigned reserved1;
	Word free_ncbs;
	Word max_cfg_ncbs;
	Word max_ncbs;
	Word xmit_buf_unavail;
	Word max_dgram_size;
	Word pending_sess;
	Word max_cfg_sess;
	Word max_sess;
	Word max_sess_pkt_size;
	Word name_count;
} ;
#pragma pack(pop)

struct TNameBuffer;
typedef TNameBuffer *PNameBuffer;

#pragma pack(push, 1)
struct TNameBuffer
{
	char name[16];
	char name_num;
	char name_flags;
} ;
#pragma pack(pop)

struct TSessionHeader;
typedef TSessionHeader *PSessionHeader;

#pragma pack(push, 1)
struct TSessionHeader
{
	char sess_name;
	char num_sess;
	char rcv_dg_outstanding;
	char rcv_any_outstanding;
} ;
#pragma pack(pop)

struct TSessionBuffer;
typedef TSessionBuffer *PSessionBuffer;

#pragma pack(push, 1)
struct TSessionBuffer
{
	char lsn;
	char state;
	char local_name[16];
	char remote_name[16];
	char rcvs_outstanding;
	char sends_outstanding;
} ;
#pragma pack(pop)

struct TLanaEnum;
typedef TLanaEnum *PLanaEnum;

#pragma pack(push, 1)
struct TLanaEnum
{
	char length;
	char lana[255];
} ;
#pragma pack(pop)

struct TFindNameHeader;
typedef TFindNameHeader *PFindNameHeader;

#pragma pack(push, 1)
struct TFindNameHeader
{
	Word node_count;
	char reserved;
	char unique_group;
} ;
#pragma pack(pop)

struct TFindNameBuffer;
typedef TFindNameBuffer *PFindNameBuffer;

#pragma pack(push, 1)
struct TFindNameBuffer
{
	char length;
	char access_control;
	char frame_control;
	char destination_addr[6];
	char source_addr[6];
	char routing_info[18];
} ;
#pragma pack(pop)

struct TActionHeader;
typedef TActionHeader *PActionHeader;

#pragma pack(push, 1)
struct TActionHeader
{
	int transport_id;
	Word action_code;
	Word reserved;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint NCBNAMSZ = 0x10;
static const Byte MAX_LANA = 0xfe;
static const Byte NAME_FLAGS_MASK = 0x87;
static const Byte GROUP_NAME = 0x80;
static const Shortint UNIQUE_NAME = 0x0;
static const Shortint REGISTERING = 0x0;
static const Shortint REGISTERED = 0x4;
static const Shortint DEREGISTERED = 0x5;
static const Shortint DUPLICATE = 0x6;
static const Shortint DUPLICATE_DEREG = 0x7;
static const Shortint LISTEN_OUTSTANDING = 0x1;
static const Shortint CALL_PENDING = 0x2;
static const Shortint SESSION_ESTABLISHED = 0x3;
static const Shortint HANGUP_PENDING = 0x4;
static const Shortint HANGUP_COMPLETE = 0x5;
static const Shortint SESSION_ABORTED = 0x6;
#define ALL_TRANSPORTS "M"
#define MS_NBF "MNBF"
static const Shortint NCBCALL = 0x10;
static const Shortint NCBLISTEN = 0x11;
static const Shortint NCBHANGUP = 0x12;
static const Shortint NCBSEND = 0x14;
static const Shortint NCBRECV = 0x15;
static const Shortint NCBRECVANY = 0x16;
static const Shortint NCBCHAINSEND = 0x17;
static const Shortint NCBDGSEND = 0x20;
static const Shortint NCBDGRECV = 0x21;
static const Shortint NCBDGSENDBC = 0x22;
static const Shortint NCBDGRECVBC = 0x23;
static const Shortint NCBADDNAME = 0x30;
static const Shortint NCBDELNAME = 0x31;
static const Shortint NCBRESET = 0x32;
static const Shortint NCBASTAT = 0x33;
static const Shortint NCBSSTAT = 0x34;
static const Shortint NCBCANCEL = 0x35;
static const Shortint NCBADDGRNAME = 0x36;
static const Shortint NCBENUM = 0x37;
static const Shortint NCBUNLINK = 0x70;
static const Shortint NCBSENDNA = 0x71;
static const Shortint NCBCHAINSENDNA = 0x72;
static const Shortint NCBLANSTALERT = 0x73;
static const Shortint NCBACTION = 0x77;
static const Shortint NCBFINDNAME = 0x78;
static const Shortint NCBTRACE = 0x79;
static const Byte ASYNCH = 0x80;
static const Shortint NRC_GOODRET = 0x0;
static const Shortint NRC_BUFLEN = 0x1;
static const Shortint NRC_ILLCMD = 0x3;
static const Shortint NRC_CMDTMO = 0x5;
static const Shortint NRC_INCOMP = 0x6;
static const Shortint NRC_BADDR = 0x7;
static const Shortint NRC_SNUMOUT = 0x8;
static const Shortint NRC_NORES = 0x9;
static const Shortint NRC_SCLOSED = 0xa;
static const Shortint NRC_CMDCAN = 0xb;
static const Shortint NRC_DUPNAME = 0xd;
static const Shortint NRC_NAMTFUL = 0xe;
static const Shortint NRC_ACTSES = 0xf;
static const Shortint NRC_LOCTFUL = 0x11;
static const Shortint NRC_REMTFUL = 0x12;
static const Shortint NRC_ILLNN = 0x13;
static const Shortint NRC_NOCALL = 0x14;
static const Shortint NRC_NOWILD = 0x15;
static const Shortint NRC_INUSE = 0x16;
static const Shortint NRC_NAMERR = 0x17;
static const Shortint NRC_SABORT = 0x18;
static const Shortint NRC_NAMCONF = 0x19;
static const Shortint NRC_IFBUSY = 0x21;
static const Shortint NRC_TOOMANY = 0x22;
static const Shortint NRC_BRIDGE = 0x23;
static const Shortint NRC_CANOCCR = 0x24;
static const Shortint NRC_CANCEL = 0x26;
static const Shortint NRC_DUPENV = 0x30;
static const Shortint NRC_ENVNOTDEF = 0x34;
static const Shortint NRC_OSRESNOTAV = 0x35;
static const Shortint NRC_MAXAPPS = 0x36;
static const Shortint NRC_NOSAPS = 0x37;
static const Shortint NRC_NORESOURCES = 0x38;
static const Shortint NRC_INVADDRESS = 0x39;
static const Shortint NRC_INVDDID = 0x3b;
static const Shortint NRC_LOCKFAIL = 0x3c;
static const Shortint NRC_OPENERR = 0x3f;
static const Shortint NRC_SYSTEM = 0x40;
static const Byte NRC_PENDING = 0xff;
extern "C" char __stdcall Netbios(PNCB P);

}	/* namespace Nb30 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nb30;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NB30
