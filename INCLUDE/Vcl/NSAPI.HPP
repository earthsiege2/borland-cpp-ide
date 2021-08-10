// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NSApi.pas' rev: 5.00

#ifndef NSApiHPP
#define NSApiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WinSock.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Nsapi
{
    struct TSession;
    char *servact_translate_uri(char *uri, TSession *sn);
}

namespace Nsapi
{
//-- type declarations -------------------------------------------------------
typedef void *PASSWD;

typedef void * *PPASSWD;

typedef char *TCAddr;

typedef char *caddr_t;

typedef void __cdecl (*TAtRestart)(void * Data);

typedef void __cdecl (*TMagnusAtRestart)(void * Data);

typedef void __cdecl (*TDaemonAtRestart)(void * Data);

typedef void *pool_handle_t;

typedef void *TPoolHandle;

typedef void * *PPoolHandle;

typedef unsigned Semaphore;

typedef void *CRITICAL;

typedef void *CONDVAR;

struct TFile
{
	unsigned fh;
	char *fname;
	unsigned flsem;
} ;

typedef TFile *SYS_FILE;

typedef TFile  file_s;

typedef unsigned pid_t;

typedef unsigned TPid;

struct TStat;
typedef TStat *PStat;

struct TStat
{
	Word st_dev;
	Word st_ino;
	Word st_mode;
	short st_nlink;
	short st_uid;
	short st_gid;
	Word st_rdev;
	int st_size;
	int st_atime;
	int st_mtime;
	int st_ctime;
} ;

typedef TStat  Stat;

#pragma pack(push, 1)
struct TDirEnt
{
	char *d_name;
} ;
#pragma pack(pop)

typedef TDirEnt *PDirEnt;

typedef TDirEnt  dirent_s;

struct TDir;
typedef TDir *PDir;

struct TDir
{
	unsigned dp;
	_WIN32_FIND_DATAA fdata;
	TDirEnt de;
} ;

typedef TDir  dir_s;

typedef TDir *SYS_DIR;

typedef TDir  SYS_DIRENT;

struct tm
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
} ;

typedef tm *ptm;

struct TPbParam
{
	char *name;
	char *value;
} ;

typedef TPbParam *PPbParam;

typedef TPbParam  pb_param;

struct TPbEntry;
typedef TPbEntry *PPbEntry;

struct TPbEntry
{
	TPbParam *param;
	TPbEntry *next;
} ;

typedef TPbEntry  pb_entry;

typedef PPbEntry *PPPbEntry;

struct TPblock;
typedef TPblock *PPblock;

struct TPblock
{
	int hsize;
	PPbEntry *ht;
} ;

typedef TPblock  pblock;

typedef char *TPCharArray[134217727];

typedef char * *PPCharArray;

typedef int SYS_NETFD;

struct TFileBuffer
{
	TFile *fd;
	unsigned fdmap;
	char *fp;
	int len;
	char *inbuf;
	int cursize;
	int pos;
	char *errmsg;
} ;

typedef TFileBuffer *PFileBuffer;

typedef TFileBuffer  filebuffer;

typedef TFileBuffer  filebuf;

struct TNetBuf;
typedef TNetBuf *PNetBuf;

struct TNetBuf
{
	int sd;
	int pos;
	int cursize;
	int maxsize;
	int rdtimeout;
	char address[64];
	char *inbuf;
	char *errmsg;
} ;

typedef TNetBuf  netbuf;

struct TSession;
typedef TSession *PSession;

struct TSession
{
	TPblock *client;
	int csd;
	TNetBuf *inbuf;
	int csd_open;
	in_addr iaddr;
	void * *pool;
	void *clauth;
} ;

typedef TSession  Session;

struct TCInfo
{
	char *ctype;
	char *encoding;
	char *language;
} ;

typedef TCInfo *PCInfo;

typedef TCInfo  cinfo;

struct TShMem
{
	void *data;
	unsigned fdmap;
	int size;
	char *name;
	TFile *fd;
} ;

typedef TShMem *PShMem;

typedef TShMem  shmem_s;

typedef void *SYS_THREAD;

typedef void __cdecl (*TSysThreadFunc)(void * Arg);

struct TMultipleDomains
{
	char *address;
	char *docroot;
	int sd;
	int threads;
	int AddressNumber;
} ;

typedef TMultipleDomains *PMultipleDomains;

typedef TMultipleDomains  multiple_domains;

typedef void __cdecl (*TChildCallback)(PSession sn);

typedef void __cdecl (*TRotateCallback)(void);

typedef void __cdecl (*TRCBack)(int Param);

struct TDaemon
{
	char *ipstr;
	int port;
	TChildCallback child_callback;
	TRotateCallback rotate_callback;
	char *servid;
	TMultipleDomains *domains;
	TRCBack rcback;
	int maxprocs;
	int minprocs;
	int proclife;
	int maxthreads;
	int minthreads;
} ;

typedef TDaemon *PDaemon;

typedef TDaemon  daemon_s;

struct TDirective
{
	TPblock *param;
	TPblock *client;
} ;

typedef TDirective *PDirective;

typedef TDirective  directive;

struct TDtable
{
	int ni;
	TDirective *inst;
} ;

typedef TDtable *PDtable;

typedef TDtable  dtable;

struct THttpdObject
{
	TPblock *name;
	int nd;
	TDtable *dt;
} ;

typedef THttpdObject *PHttpdObject;

typedef THttpdObject  httpd_object;

struct THttpdObjSet;
typedef THttpdObjSet *PHttpdObjSet;

struct THttpdObjSet
{
	int pos;
	PHttpdObject *obj;
	PPblock *initfns;
} ;

typedef THttpdObjSet  httpd_objset;

struct TConfGlobalVars
{
	int Vport;
	char *Vaddr;
	void * *Vuserpw;
	char *Vchr;
	char *Vpidfn;
	int Vpool_max;
	int Vpool_min;
	int Vpool_life;
	int Vpool_maxthreads;
	int Vpool_minthreads;
	char *Vserver_hostname;
	char *Vroot_object;
	THttpdObjSet *Vstd_os;
	void *Vacl_root;
	char *Vmaster_error_log;
	char *Vserver_root;
	char *Vserver_id;
} ;

typedef TConfGlobalVars *PConfGlobalVars;

typedef TConfGlobalVars  conf_global_vars_s;

struct TRequest;
typedef TRequest *PRequest;

struct TRequest
{
	TPblock *vars;
	TPblock *reqpb;
	int loadhdrs;
	TPblock *headers;
	int senthdrs;
	TPblock *srvhdrs;
	THttpdObjSet *os;
	THttpdObjSet *tmpos;
	char *statpath;
	char *staterr;
	TStat *finfo;
	int aclstate;
	int acldirno;
	char *aclname;
	TPblock *aclpb;
	BOOL request_is_cacheable;
	BOOL directive_is_cacheable;
	char *cached_headers;
	int cached_headers_len;
	char *cached_date_header;
} ;

typedef TRequest  Request;

typedef int __cdecl (*TFunction)(PPblock pb, PSession sn, PRequest rq);

struct TFuncStruct;
typedef TFuncStruct *PFuncStruct;

struct TFuncStruct
{
	char *name;
	TFunction func;
	TFuncStruct *next;
} ;

//-- var, const, procedure ---------------------------------------------------
#define PROXY_VERSION_DEF "2.0b4"
#define PROXY_VERSION_STRING "Netscape-Proxy/2.0b4"
#define ADMSERV_VERSION_DEF "2.0"
#define ADMSERV_VERSION_STRING "Netscape-Administrator/2.0"
#define PERSONAL_VERSION_DEF "2.0b4"
#define PERSONAL_VERSION_STRING "Netscape-FastTrack/2.0b4"
#define CATALOG_VERSION_DEF "1.0b2"
#define CATALOG_VERSION_STRING "Netscape-Catalog/1.0b2"
#define RDS_VERSION_DEF "1.0b2"
#define RDS_VERSION_STRING "Netscape-RDS/1.0b2"
#define ENTERPRISE_VERSION_DEF "2.0b4"
#define ENTERPRISE_VERSION_STRING "Netscape-Enterprise/2.0b4"
#define NEWS_VERSION_STRING "Netscape 1.1"
#define BATMAN_VERSION_DEF "1.0a1"
#define BATMAN_VERSION_STRING "Batman/1.0a1"
static const Shortint DAEMON_LISTEN_SIZE = 0x64;
static const Word MAGNUS_ERROR_LEN = 0x2000;
static const Shortint CR = 0xd;
static const Shortint LF = 0xa;
#define ENDLINE "\r\n"
static const Shortint ENTERPRISE_VERSION = 0x1;
static const Shortint PERSONAL_VERSION = 0x2;
static const Shortint CATALOG_VERSION = 0x3;
static const Shortint RDS_VERSION = 0x4;
static const Shortint SEM_ERROR = 0x0;
static const Word SEM_MAXVALUE = 0x7fff;
static const Shortint IO_OKAY = 0x1;
static const Shortint IO_ERROR = 0xffffffff;
static const Shortint IO_EOF = 0x0;
static const Word FILE_BUFFERSIZE = 0x1000;
#define SYS_ERROR_FD (void *)(0x0)
#define SYS_STDERR (void *)(0x0)
static const Word ERROR_PIPE = 0x2ff;
static const char FILE_PATHSEP = '\x2f';
#define FILE_PARENT "..\\"
static const Word NET_BUFFERSIZE = 0x2000;
static const Shortint NET_READ_TIMEOUT = 0x78;
static const Word NET_WRITE_TIMEOUT = 0x12c;
static const Shortint NET_INFINITE_TIMEOUT = 0x0;
static const Shortint NET_ZERO_TIMEOUT = 0xffffffff;
static const Word SSL_HANDSHAKE_TIMEOUT = 0x12c;
static const Shortint SYS_NET_ERRORFD = 0xffffffff;
static const Shortint SESSION_HASHSIZE = 0x5;
#define MCC_MT_MAGIC "#--Mosaic Communications Corporation MIME Information"
static const Shortint MCC_MT_MAGIC_LEN = 0x35;
#define NCC_MT_MAGIC "#--Netscape Communications Corporation MIME Information"
static const Shortint NCC_MT_MAGIC_LEN = 0x37;
static const char CINFO_SEPARATOR = '\x2e';
static const Word CINFO_MAX_LEN = 0x400;
static const Shortint CINFO_HASHSIZE = 0x1b;
static const Word MAX_ERROR_LEN = 0x2000;
static const Shortint LOG_WARN = 0x0;
static const Shortint LOG_MISCONFIG = 0x1;
static const Shortint LOG_SECURITY = 0x2;
static const Shortint LOG_FAILURE = 0x3;
static const Shortint LOG_CATASTROPHE = 0x4;
static const Shortint LOG_INFORM = 0x5;
#define ERR_TIMEFMT "[%d/%b/%Y:%H:%M:%S]"
static const Shortint ERRORS_TO_SYSLOG = 0xffffffff;
static const Shortint NON_SXP = 0xffffffff;
static const Shortint INVALID_SXP = 0xfffffffe;
static const Shortint VALID_SXP = 0x1;
static const Shortint NON_WILDPAT = 0xffffffff;
static const Shortint INVALID_WILDPAT = 0xfffffffe;
static const Shortint VALID_WILDPAT = 0x1;
static const Shortint NON_REGEXP = 0xffffffff;
static const Shortint INVALID_REGEXP = 0xfffffffe;
static const Shortint VALID_REGEXP = 0x1;
#define SYS_THREAD_ERROR (void *)(0x0)
static const Shortint SYSTHREAD_DEFAULT_PRIORITY = 0x10;
static const Byte CHILD_EMPTY_SLOT = 0xfe;
static const Byte CHILD_AWAIT_CONNECT = 0xff;
static const Shortint CHILD_PROCESSING = 0x0;
static const Shortint CHILD_READING = 0x1;
static const Shortint CHILD_WRITING = 0x2;
static const Shortint CHILD_RESOLVING = 0x3;
static const Shortint CHILD_DONE_PROCESSING = 0x14;
static const Shortint CHILD_DONE_READING = 0x15;
static const Shortint CHILD_DONE_WRITING = 0x16;
static const Shortint CHILD_DONE_RESOLVING = 0x17;
static const Word MAX_IP_DOMAINS = 0x100;
static const Shortint OBJSET_INCSIZE = 0x8;
static const Word MAX_DIRECTIVE_LEN = 0x320;
static const Shortint PARAMETER_HASH_SIZE = 0x3;
static const Word CONF_MAXLEN = 0x4000;
static const Shortint DEFAULT_PORT = 0x50;
static const Shortint DEFAULT_POOL_MAX = 0x32;
static const Shortint REQ_HASHSIZE = 0xa;
static const Word REQ_MAX_LINE = 0x1000;
static const Shortint REQ_PROCEED = 0x0;
static const Shortint REQ_ABORTED = 0xffffffff;
static const Shortint REQ_NOACTION = 0xfffffffe;
static const Shortint REQ_EXIT = 0xfffffffd;
static const Shortint REQ_RESTART = 0xfffffffc;
static const Byte HTTP_DATE_LEN = 0x80;
#define HTTP_DATE_FMT "%A, %d-%b-%y %H:%M:%S GMT"
static const Shortint HTTP_DEFAULT_KEEPALIVE_TIMEOUT = 0xf;
static const Byte HTTP_MAX_HEADERS = 0xc8;
static const Byte PROTOCOL_OK = 0xc8;
static const Byte PROTOCOL_CREATED = 0xc9;
static const Byte PROTOCOL_NO_RESPONSE = 0xcc;
static const Byte PROTOCOL_PARTIAL_CONTENT = 0xce;
static const Word PROTOCOL_REDIRECT = 0x12e;
static const Word PROTOCOL_NOT_MODIFIED = 0x130;
static const Word PROTOCOL_BAD_REQUEST = 0x190;
static const Word PROTOCOL_UNAUTHORIZED = 0x191;
static const Word PROTOCOL_FORBIDDEN = 0x193;
static const Word PROTOCOL_NOT_FOUND = 0x194;
static const Word PROTOCOL_PROXY_UNAUTHORIZED = 0x197;
static const Word PROTOCOL_SERVER_ERROR = 0x1f4;
static const Word PROTOCOL_NOT_IMPLEMENTED = 0x1f5;
static const Shortint HTTP_PORT = 0x50;
#define HTTP_URL "http"
static const Shortint NUM_HASH = 0x14;
extern PACKAGE bool __fastcall server_fasttrack(void);
extern PACKAGE bool __fastcall server_enterprise(void);
extern PACKAGE void __fastcall CONVERT_TO_PRINTABLE_FORMAT(char * Filename);
extern PACKAGE void __fastcall CONVERT_TO_NATIVE_FS(char * Filename);
extern PACKAGE BOOL __fastcall system_rename(char * Old, char * New);
extern PACKAGE BOOL __fastcall system_unlink(char * path);
extern PACKAGE int __fastcall system_lseek(SYS_FILE fd, int off, int wh);
extern PACKAGE int __fastcall system_flock(SYS_FILE fd);
extern PACKAGE int __fastcall system_ulock(SYS_FILE fd);
extern PACKAGE int __fastcall dir_create(char * Path);
extern PACKAGE int __fastcall dir_remove(char * Path);
extern PACKAGE PPbParam __fastcall pblock_find(char * name, PPblock pb);
extern PACKAGE PPbParam __fastcall pblock_remove(char * name, PPblock pb);
extern PACKAGE int __fastcall netbuf_getc(PNetBuf b);
extern PACKAGE int __fastcall filebuf_getc(PFileBuffer b);
extern PACKAGE int __fastcall pipebuf_getc(PFileBuffer b);
extern PACKAGE char * __fastcall session_dns(PSession sn);
extern PACKAGE char * __fastcall session_maxdns(PSession sn);
extern PACKAGE char __fastcall CINFO_HASH(char * s);
extern PACKAGE int __fastcall request_loadheaders(PSession sn, PRequest rq);
extern PACKAGE PPASSWD __fastcall userpw(void);
extern PACKAGE int __fastcall pool_max(void);
extern PACKAGE int __fastcall pool_min(void);
extern PACKAGE int __fastcall pool_life(void);
extern PACKAGE int __fastcall pool_maxthreads(void);
extern PACKAGE int __fastcall pool_minthreads(void);
extern PACKAGE char * __fastcall server_hostname(void);
extern PACKAGE char * __fastcall root_object(void);
extern PACKAGE PHttpdObjSet __fastcall std_os(void);
extern PACKAGE void * __fastcall acl_root(void);
extern PACKAGE char * __fastcall master_error_log(void);
extern PACKAGE char * __fastcall server_root(void);
extern PACKAGE char * __fastcall server_id(void);
extern PACKAGE AnsiString __fastcall NSstr2String(char * nsStr);
extern "C" int __cdecl strcasecmp(char * s1, char * s2);
extern "C" int __cdecl strncasecmp(char * s1, char * s2, int n);
extern "C" int __cdecl util_strcasecmp(char * s1, char * s2);
extern "C" int __cdecl util_strncasecmp(char * s1, char * s2, int n);
extern "C" char * __cdecl system_version(void);
extern "C" char * __cdecl MAGNUS_VERSION_STRING(void);
extern "C" void __cdecl system_version_set(char * ptr);
extern "C" void * __cdecl MALLOC(int size);
extern "C" void * __cdecl system_malloc(int size);
extern "C" void * __cdecl CALLOC(int size);
extern "C" void * __cdecl system_calloc(int size);
extern "C" void * __cdecl REALLOC(void * ptr, int size);
extern "C" void * __cdecl system_realloc(void * ptr, int size);
extern "C" void __cdecl FREE(void * ptr);
extern "C" void __cdecl system_free(void * ptr);
extern "C" char * __cdecl STRDUP(char * ptr);
extern "C" char * __cdecl system_strdup(char * ptr);
extern "C" void * __cdecl PERM_MALLOC(int size);
extern "C" void * __cdecl system_malloc_perm(int size);
extern "C" void * __cdecl PERM_CALLOC(int size);
extern "C" void * __cdecl system_calloc_perm(int size);
extern "C" void * __cdecl PERM_REALLOC(void * ptr, int size);
extern "C" void * __cdecl system_realloc_perm(void * ptr, int size);
extern "C" void __cdecl PERM_FREE(void * ptr);
extern "C" void __cdecl system_free_perm(void * ptr);
extern "C" char * __cdecl PERM_STRDUP(char * ptr);
extern "C" char * __cdecl system_strdup_perm(char * ptr);
extern "C" void __cdecl magnus_atrestart(TAtRestart fn, void * data);
extern "C" PPoolHandle __cdecl pool_create(void);
extern "C" void __cdecl pool_destroy(PPoolHandle pool_handle);
extern "C" BOOL __cdecl pool_enabled(void);
extern "C" void * __cdecl pool_malloc(PPoolHandle pool_handle, int size);
extern "C" void __cdecl pool_free(PPoolHandle pool_handle, void * ptr);
extern "C" void * __cdecl pool_calloc(PPoolHandle pool_handle, int nelem, int elsize);
extern "C" void * __cdecl pool_realloc(PPoolHandle pool_handle, void * ptr, int size);
extern "C" char * __cdecl pool_strdup(PPoolHandle pool_handle, char * orig_str);
extern "C" unsigned __cdecl sem_init(char * name, int Number);
extern "C" void __cdecl sem_terminate(unsigned id);
extern "C" int __cdecl sem_grab(unsigned id);
extern "C" int __cdecl sem_tgrab(unsigned id);
extern "C" int __cdecl sem_release(unsigned id);
extern "C" void * __cdecl crit_init(void);
extern "C" void __cdecl crit_enter(void * id);
extern "C" void __cdecl crit_exit(void * id);
extern "C" void __cdecl crit_terminate(void * id);
extern "C" void * __cdecl condvar_init(void * id);
extern "C" void __cdecl condvar_wait(void * cv);
extern "C" void __cdecl condvar_notify(void * cv);
extern "C" void __cdecl condvar_terminate(void * cv);
extern "C" BOOL __stdcall system_chdir(char * Path);
extern "C" int __cdecl system_stat(char * name, TStat &finfo);
extern "C" int __cdecl system_fread(SYS_FILE fd, void * buf, int sz);
extern "C" int __cdecl system_pread(SYS_FILE fd, void * buf, int sz);
extern "C" SYS_FILE __cdecl system_fopenRO(char * path);
extern "C" SYS_FILE __cdecl system_fopenWA(char * path);
extern "C" SYS_FILE __cdecl system_fopenRW(char * path);
extern "C" SYS_FILE __cdecl system_fopenWT(char * path);
extern "C" void __cdecl system_fclose(SYS_FILE fd);
extern "C" int __cdecl system_nocoredumps(void);
extern "C" char * __cdecl system_winsockerr(void);
extern "C" char * __cdecl system_winerr(void);
extern "C" int __cdecl system_fwrite(SYS_FILE fd, void * buf, int sz);
extern "C" int __cdecl system_fwrite_atomic(SYS_FILE fd, void * buf, int sz);
extern "C" int __cdecl file_notfound(void);
extern "C" char * __cdecl system_errmsg(void);
extern "C" char * __cdecl system_errmsg_fn(void);
extern "C" int __cdecl system_initlock(SYS_FILE fd);
extern "C" int __cdecl file_setinherit(SYS_FILE fd, int value);
extern "C" void __cdecl file_unix2local(char * path, char * p2);
extern "C" PDir __cdecl dir_open(char * path);
extern "C" PDirEnt __cdecl dir_read(PDir ds);
extern "C" void __cdecl dir_close(PDir ds);
extern "C" int __cdecl dir_create_all(char * dir);
extern "C" PPbParam __cdecl param_create(char * name, char * value);
extern "C" int __cdecl param_free(PPbParam pp);
extern "C" PPblock __cdecl pblock_create(int n);
extern "C" void __cdecl pblock_free(PPblock pb);
extern "C" char * __cdecl pblock_findval(char * name, PPblock pb);
extern "C" PPbParam __cdecl pblock_nvinsert(char * name, char * value, PPblock pb);
extern "C" PPbParam __cdecl pblock_nninsert(char * name, int value, PPblock pb);
extern "C" void __cdecl pblock_pinsert(PPbParam pp, PPblock pb);
extern "C" int __cdecl pblock_str2pblock(char * str, PPblock pb);
extern "C" char * __cdecl pblock_pblock2str(PPblock pb, char * str);
extern "C" void __cdecl pblock_copy(PPblock src, PPblock dst);
extern "C" PPblock __cdecl pblock_dup(PPblock src);
extern "C" PPCharArray __fastcall pblock_pb2env(PPblock pb, PPCharArray env);
extern PACKAGE PPbParam __cdecl _pblock_fr(char * name, PPblock pb, BOOL remove);
extern "C" int __cdecl net_socket(int domain, int nettype, int protocol);
extern "C" int __cdecl net_getsockopt(int s, int level, int optname, void * optval, int &optlen);
extern "C" int __cdecl net_setsockopt(int s, int level, int optname, void * optval, int optlen);
extern "C" int __cdecl net_listen(int s, int backlog);
extern "C" int __cdecl net_create_listener(char * ipaddr, int port);
extern "C" int __cdecl net_select(int nfds, Winsock::PFDSet r, Winsock::PFDSet w, Winsock::PFDSet e, 
	Winsock::PTimeVal timeout);
extern "C" int __cdecl net_connect(int s, void * sockaddr, int namelen);
extern "C" int __cdecl net_ioctl(int s, int tag, void * result);
extern "C" int __cdecl net_getpeername(int s, sockaddr_in &name, int &namelen);
extern "C" int __cdecl net_close(int s);
extern "C" int __cdecl net_bind(int s, sockaddr_in &name, int namelen);
extern "C" int __cdecl net_accept(int s, PSOCKADDR addr, Windows::PInteger addrlen);
extern "C" int __cdecl net_read(int sd, char * buf, int sz, int timeout);
extern "C" int __cdecl net_write(int sd, char * buf, int sz);
extern "C" BOOL __cdecl net_isalive(int sd);
extern "C" char * __cdecl net_ip2host(char * ip, BOOL verify);
extern "C" PFileBuffer __cdecl filebuf_open(SYS_FILE fd, int sz);
extern "C" PNetBuf __cdecl netbuf_open(int sd, int sz);
extern "C" PFileBuffer __cdecl filebuf_create(SYS_FILE fd, char * mmap_ptr, int mmap_len, int bufsz)
	;
extern "C" void __cdecl filebuf_close_buffer(PFileBuffer buf, BOOL clean_mmap);
extern "C" PFileBuffer __cdecl filebuf_open_nostat(SYS_FILE fd, int sz, TStat &finfo);
extern "C" PFileBuffer __cdecl pipebuf_open(SYS_FILE fd, int sz, TStat &finfo);
extern "C" int __cdecl filebuf_next(PFileBuffer buf, int advance);
extern "C" int __cdecl netbuf_next(PNetBuf buf, int advance);
extern "C" int __cdecl pipebuf_next(PFileBuffer buf, int advance);
extern "C" void __cdecl filebuf_close(PFileBuffer buf);
extern "C" void __cdecl netbuf_close(PNetBuf buf);
extern "C" void __cdecl pipebuf_close(PFileBuffer buf);
extern "C" int __cdecl filebuf_grab(PFileBuffer buf, int sz);
extern "C" int __cdecl netbuf_grab(PNetBuf buf, int sz);
extern "C" int __cdecl pipebuf_grab(PFileBuffer buf, int sz);
extern "C" int __cdecl netbuf_buf2sd(PNetBuf buf, int sd, int len);
extern "C" int __cdecl filebuf_buf2sd(PFileBuffer buf, int sd);
extern "C" int __cdecl pipebuf_buf2sd(PFileBuffer buf, int sd, int len);
extern "C" int __cdecl pipebuf_netbuf2sd(PNetBuf buf, SYS_FILE sd, int len);
extern "C" PSession __cdecl session_create(int csd, Winsock::PSockAddrIn sac);
extern "C" void __fastcall session_free(PSession sn);
extern "C" char * __cdecl session_dns_lookup(PSession sn, BOOL verify);
extern "C" void __cdecl cinfo_init(void);
extern "C" void __cdecl cinfo_terminate(void);
extern "C" char * __cdecl cinfo_merge(char * fn);
extern "C" PCInfo __cdecl cinfo_find(char * uri);
extern "C" PCInfo __cdecl cinfo_lookup(char * ctype);
extern "C" char * __cdecl ereport_init(char * err_fn, char * email, void * &pw);
extern "C" void __cdecl ereport_terminate(void);
extern "C" SYS_FILE __cdecl ereport_getfd(void);
extern "C" int __cdecl shexp_valid(char * exp);
extern "C" int __cdecl shexp_match(char * str, char * exp);
extern "C" int __cdecl shexp_cmp(char * str, char * exp);
extern "C" int __cdecl shexp_casecmp(char * str, char * exp);
extern "C" PShMem __cdecl shmem_alloc(char * name, int size, BOOL expose);
extern "C" void __cdecl shmem_free(PShMem region);
extern "C" void * __cdecl systhread_start(int prio, int stksz, TSysThreadFunc fn, void * arg);
extern "C" void * __fastcall systhread_current(void);
extern "C" void __cdecl systhread_yield(void);
extern "C" void * __cdecl systhread_attach(void);
extern "C" void __fastcall systhread_terminate(void * thr);
extern "C" void __cdecl systhread_sleep(int milliseconds);
extern "C" void __cdecl systhread_init(char * name);
extern "C" void __cdecl systhread_timerset(int usec);
extern "C" int __cdecl systhread_newkey(void);
extern "C" void * __cdecl systhread_getdata(int key);
extern "C" void __cdecl systhread_setdata(int key, void * data);
extern PACKAGE void __cdecl _ntdaemon_run(void * Param);
extern "C" void __cdecl daemon_atrestart(TAtRestart fn, void * data);
extern "C" unsigned __fastcall child_fork(void);
extern "C" int __cdecl util_getline(PFileBuffer buf, int lineno, int maxlen, char * l);
extern "C" PPCharArray __cdecl util_env_create(PPCharArray env, int n, int &pos);
extern "C" char * __cdecl util_env_str(char * name, char * value);
extern "C" void __cdecl util_env_replace(PPCharArray env, char * name, char * value);
extern "C" void __cdecl util_env_free(PPCharArray env);
extern "C" PPCharArray __cdecl util_env_copy(PPCharArray src, PPCharArray dst);
extern "C" char * __cdecl util_env_find(PPCharArray env, char * name);
extern "C" char * __cdecl util_hostname(void);
extern "C" int __fastcall util_chdir2path(char * path);
extern "C" BOOL __cdecl util_is_mozilla(char * ua, char * major, char * minor);
extern "C" BOOL __cdecl util_is_url(char * url);
extern "C" BOOL __cdecl util_later_than(tm &lms, char * ims);
extern "C" BOOL __cdecl util_time_equal(tm &lms, char * ims);
extern "C" int __cdecl util_str_time_equal(char * t1, char * t2);
extern "C" BOOL __cdecl util_uri_is_evil(char * t);
extern "C" void __cdecl util_uri_parse(char * uri);
extern "C" void __cdecl util_uri_unescape(char * s);
extern "C" char * __cdecl util_uri_escape(char * d, char * s);
extern "C" char * __cdecl util_url_escape(char * d, char * s);
extern "C" char * __cdecl util_sh_escape(char * s);
extern "C" int __fastcall util_mime_separator(char * sep);
extern "C" int __fastcall util_itoa(int i, char * a);
extern "C" void __cdecl util_delete_directory(char * FileName, BOOL delete_directory);
extern "C" int __cdecl util_strftime(char * s, char * format, tm &t);
extern "C" PHttpdObject __cdecl object_create(int nd, PPblock name);
extern "C" void __cdecl object_free(PHttpdObject obj);
extern "C" void __cdecl object_add_directive(int dc, PPblock p, PPblock c, PHttpdObject obj);
extern "C" int __cdecl object_execute(PDirective inst, PSession sn, void * rq);
extern "C" PHttpdObjSet __cdecl objset_scan_buffer(PFileBuffer buf, char * errstr, PHttpdObjSet os);
	
extern "C" PHttpdObjSet __cdecl objset_create(void);
extern "C" void __cdecl objset_free(PHttpdObjSet os);
extern "C" void __cdecl objset_free_setonly(PHttpdObjSet os);
extern "C" PHttpdObjSet __cdecl objset_new_object(PPblock name, PHttpdObjSet os);
extern "C" void __cdecl objset_add_object(PHttpdObject obj, PHttpdObjSet os);
extern "C" void __cdecl objset_add_init(PPblock initfn, PHttpdObjSet os);
extern "C" PHttpdObject __cdecl objset_findbyname(char * name, PHttpdObjSet ign, PHttpdObjSet os);
extern "C" PHttpdObject __cdecl objset_findbyppath(char * ppath, PHttpdObjSet ign, PHttpdObjSet os);
	
extern "C" PHttpdObjSet __cdecl objset_copydirs(PHttpdObjSet dst_os, PHttpdObjSet os, int dir);
extern "C" PHttpdObjSet __cdecl objset_scan_registry(char * errstr, PHttpdObjSet os, char * product_key
	);
extern "C" void __cdecl ProcessObject(PHttpdObjSet nos, HKEY hObjectKey, char * Obj, unsigned ObjectIndex
	);
extern "C" BOOL __cdecl ProcessClient(PHttpdObject cobj, HKEY hObjectKey, char * Client, unsigned ObjectIndex
	);
extern "C" BOOL __cdecl ProcessDirective(PHttpdObject cobj, PPblock param, PPblock client, HKEY hObjectKey
	, char * Directive, unsigned ObjectIndex, unsigned DirectiveIndex, unsigned &clrefs, BOOL IsObject)
	;
extern "C" BOOL __cdecl ProcessFunction(PPblock &param, HKEY hDirectiveKey, char * Func, unsigned ObjectIndex
	, unsigned DirectiveIndex, unsigned FunctionIndex);
extern PACKAGE int __cdecl _ntverify_parameter(char * str);
extern "C" int __cdecl ntpblock_str2pblock(int ParameterIndex, char * name, char * value, int namelength
	, int valuelength, PPblock pb);
extern "C" int __cdecl ntpblock_pblock2str(PPbEntry p, char * &ParameterName, char * &ParameterValue
	);
extern "C" BOOL __cdecl ClearConfigurationParameters(HKEY hParentKey, char * CompleteKeyName, char * 
	KeyName);
extern "C" char * __cdecl GetProductKey(void);
extern "C" char * __cdecl conf_init(char * cfn);
extern "C" void __cdecl conf_terminate(void);
extern "C" PConfGlobalVars __cdecl conf_getglobals(void);
extern "C" void __cdecl conf_vars2daemon(PDaemon d);
extern "C" BOOL __cdecl GetDomainAddresses(char * ErrMsg);
extern "C" PRequest __cdecl request_create(void);
extern "C" void __cdecl request_free(PRequest req);
extern "C" PRequest __cdecl request_restart_internal(char * uri, PRequest rq);
extern "C" int __cdecl request_header(char * name, PPCharArray value, PSession sn, PRequest rq);
extern "C" PStat __cdecl request_stat_path(char * path, PRequest rq);
extern "C" void __cdecl request_handle(PSession sn);
extern "C" char * __cdecl request_translate_uri(char * uri, PSession sn);
extern "C" PRequest __cdecl protocol_find_request(PNetBuf buf, PSession sn, int &reply);
extern "C" PRequest __cdecl http_find_request(PNetBuf buf, PSession sn, int &reply);
extern "C" int __cdecl protocol_parse_request(char * t, PRequest rq, PSession sn);
extern "C" int __cdecl http_parse_request(char * t, PRequest rq, PSession sn);
extern "C" int __cdecl protocol_scan_headers(PSession sn, PNetBuf buf, char * t, PPblock headers);
extern "C" int __cdecl http_scan_headers(PSession sn, PNetBuf buf, char * t, PPblock headers);
extern "C" int __cdecl protocol_start_response(PSession sn, PRequest rq);
extern "C" int __cdecl http_start_response(PSession sn, PRequest rq);
extern "C" PPCharArray __cdecl http_hdrs2env(PPblock pb);
extern "C" void __cdecl protocol_status(PSession sn, PRequest rq, int n, char * r);
extern "C" void __cdecl http_status(PSession sn, PRequest rq, int n, char * r);
extern "C" int __cdecl protocol_set_finfo(PSession sn, PRequest rq, TStat &finfo);
extern "C" int __cdecl http_set_finfo(PSession sn, PRequest rq, TStat &finfo);
extern "C" char * __cdecl http_dump822(PPblock pb, char * t, int &pos, int tsz);
extern "C" void __cdecl protocol_finish_request(PSession sn, PRequest rq);
extern "C" void __cdecl http_finish_request(PSession sn, PRequest rq);
extern "C" void __cdecl protocol_handle_session(PSession sn);
extern "C" void __cdecl http_handle_session(PSession sn);
extern "C" char * __cdecl protocol_uri2url(char * prefix, char * suffix);
extern "C" char * __cdecl protocol_uri2url_dynamic(char * prefix, char * suffix, PSession sn, PRequest 
	rq);
extern "C" char * __cdecl http_uri2url(char * prefix, char * suffix);
extern "C" char * __cdecl http_uri2url_dynamic(char * prefix, char * suffix, PSession sn, PRequest rq
	);
extern "C" void __cdecl protocol_set_keepalive_timeout(int secs);
extern "C" void __cdecl http_set_keepalive_timeout(int secs);
extern "C" void __cdecl func_init(void);
extern "C" TFunction __cdecl func_find(char * name);
extern "C" int __cdecl func_exec(PPblock pb, PSession sn, PRequest rq);
extern "C" PFuncStruct __fastcall func_insert(char * name, TFunction fn);
#pragma option push -w-inl
inline void * __cdecl MALLOC(int size)
{
	return system_malloc(size);
}
#pragma option pop


#pragma option push -w-inl
inline void * __cdecl CALLOC(int size)
{
	return system_calloc(size);
}
#pragma option pop


#pragma option push -w-inl
inline void * __cdecl REALLOC(void * ptr, int size)
{
	return system_realloc(ptr, size);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl FREE(void * ptr)
{
	system_free(ptr);
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl STRDUP(char * ptr)
{
	return system_strdup(ptr);
}
#pragma option pop


#pragma option push -w-inl
inline void * __cdecl PERM_MALLOC(int size)
{
	return system_malloc_perm(size);
}
#pragma option pop


#pragma option push -w-inl
inline void * __cdecl PERM_CALLOC(int size)
{
	return system_calloc_perm(size);
}
#pragma option pop


#pragma option push -w-inl
inline void * __cdecl PERM_REALLOC(void * ptr, int size)
{
	return system_realloc_perm(ptr, size);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl PERM_FREE(void * ptr)
{
	system_free_perm(ptr);
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl PERM_STRDUP(char * ptr)
{
	return system_strdup_perm(ptr);
}
#pragma option pop


#pragma option push -w-inl
inline BOOL __stdcall system_chdir(char * Path)
{
	return SetCurrentDirectory(Path);
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl system_errmsg(void)
{
	return system_errmsg_fn();
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl request_translate_uri(char * uri, PSession sn)
{
	return servact_translate_uri(uri, sn);
}
#pragma option pop


#pragma option push -w-inl
inline PRequest __cdecl protocol_find_request(PNetBuf buf, PSession sn, int &reply)
{
	return http_find_request(buf, sn, reply);
}
#pragma option pop


#pragma option push -w-inl
inline int __cdecl protocol_parse_request(char * t, PRequest rq, PSession sn)
{
	return http_parse_request(t, rq, sn);
}
#pragma option pop


#pragma option push -w-inl
inline int __cdecl protocol_scan_headers(PSession sn, PNetBuf buf, char * t, PPblock headers)
{
	return http_scan_headers(sn, buf, t, headers);
}
#pragma option pop


#pragma option push -w-inl
inline int __cdecl protocol_start_response(PSession sn, PRequest rq)
{
	return http_start_response(sn, rq);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl protocol_status(PSession sn, PRequest rq, int n, char * r)
{
	http_status(sn, rq, n, r);
}
#pragma option pop


#pragma option push -w-inl
inline int __cdecl protocol_set_finfo(PSession sn, PRequest rq, TStat &finfo)
{
	return http_set_finfo(sn, rq, finfo);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl protocol_finish_request(PSession sn, PRequest rq)
{
	http_finish_request(sn, rq);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl protocol_handle_session(PSession sn)
{
	http_handle_session(sn);
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl protocol_uri2url(char * prefix, char * suffix)
{
	return http_uri2url(prefix, suffix);
}
#pragma option pop


#pragma option push -w-inl
inline char * __cdecl protocol_uri2url_dynamic(char * prefix, char * suffix, PSession sn, PRequest rq
	)
{
	return http_uri2url_dynamic(prefix, suffix, sn, rq);
}
#pragma option pop


#pragma option push -w-inl
inline void __cdecl protocol_set_keepalive_timeout(int secs)
{
	http_set_keepalive_timeout(secs);
}
#pragma option pop



}	/* namespace Nsapi */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nsapi;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NSApi
