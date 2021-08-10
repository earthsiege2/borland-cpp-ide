// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPD.pas' rev: 6.00

#ifndef HTTPDHPP
#define HTTPDHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WinSock.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#if defined(__WIN32__)
#pragma link "ApacheCore.lib"
#endif

namespace Httpd
{
//-- type declarations -------------------------------------------------------
typedef char *ap_pchar;

typedef char * *ap_ppchar;

typedef char *ap_constpchar;

typedef Byte *ap_punsignedchar;

typedef short ap_short;

typedef short *ap_pshort;

typedef Word ap_unsignedshort;

typedef int ap_int;

typedef unsigned ap_unsigned;

typedef int ap_long;

typedef unsigned ap_unsignedlong;

typedef void *ap_pFILE;

typedef void * *ap_ppFILE;

typedef void *ap_pvoid;

typedef void *Ppool;

typedef void *Ptable;

typedef void *Pserver_addr_rec;

typedef void *Parray_header;

typedef void *Pregmatch_t;

typedef void *Pchild_info;

typedef void *AP_PMD5_CTX;

typedef void *Ptm;

typedef int uid_t;

typedef int gid_t;

typedef int time_t;

typedef int size_t;

typedef void *ap_Ppool;

typedef void *Phostent;

struct stat;
typedef stat *Pstat;

#pragma pack(push, 1)
struct stat
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
#pragma pack(pop)

struct uri_components;
typedef uri_components *Puri_components;

#pragma pack(push, 1)
struct uri_components
{
	char *scheme;
	char *hostinfo;
	char *user;
	char *password;
	char *hostname;
	char *port_str;
	char *path;
	char *query;
	char *fragment;
	void *hostent;
	Word port;
	unsigned is_initialized;
	unsigned dns_looked_up;
	unsigned dns_resolved;
} ;
#pragma pack(pop)

struct htaccess_result;
typedef htaccess_result *Phtaccess_result;

#pragma pack(push, 1)
struct htaccess_result
{
	char *dir;
	int override;
	void *htaccess;
	htaccess_result *next;
} ;
#pragma pack(pop)

struct SPerServer;
typedef SPerServer *PSPerServer;

#pragma pack(push, 1)
struct SPerServer
{
	char *szServer;
	char *szTag;
} ;
#pragma pack(pop)

struct server_rec;
typedef server_rec *Pserver_rec;

#pragma pack(push, 1)
struct server_rec
{
	server_rec *next;
	char *defn_name;
	unsigned defn_line_number;
	char *srm_confname;
	char *access_confname;
	char *server_admin;
	char *server_hostname;
	Word port;
	char *error_fname;
	void *error_log;
	int loglevel;
	int is_virtual;
	void *module_config;
	void *lookup_defaults;
	void *addrs;
	int timeout;
	int keep_alive_timeout;
	int keep_alive_max;
	int keep_alive;
	int send_buffer_size;
	char *path;
	int pathlen;
	void *names;
	void *wild_names;
	int server_uid;
	int server_gid;
	int limit_req_line;
	int limit_req_fieldsize;
	int limit_req_fields;
} ;
#pragma pack(pop)

struct SPerDir;
typedef SPerDir *PSPerDir;

#pragma pack(push, 1)
struct SPerDir
{
	char *szDir;
	char *szTag;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct BUFF
{
	
} ;
#pragma pack(pop)

typedef BUFF *PBUFF;

typedef PBUFF *PPBUFF;

struct conn_rec;
typedef conn_rec *Pconn_rec;

#pragma pack(push, 1)
struct conn_rec
{
	void *pool;
	server_rec *server;
	server_rec *base_server;
	void *vhost_lookup_data;
	int child_num;
	BUFF *client;
	sockaddr_in local_addr;
	sockaddr_in remote_addr;
	char *remote_ip;
	char *remote_host;
	char *remote_logname;
	char *user;
	char *ap_auth_type;
	int flags;
	int keepalives;
	char *local_ip;
	char *local_host;
} ;
#pragma pack(pop)

struct request_rec;
typedef request_rec *Prequest_rec;

#pragma pack(push, 1)
struct request_rec
{
	void *pool;
	conn_rec *connection;
	server_rec *server;
	request_rec *next;
	request_rec *prev;
	request_rec *main;
	char *the_request;
	int backwards;
	int proxyreq;
	int header_only;
	char *protocol;
	int proto_num;
	char *hostname;
	int request_time;
	char *status_line;
	int status;
	char *method;
	int method_number;
	int allowed;
	int sent_bodyct;
	int bytes_sent;
	int mtime;
	int chunked;
	int byterange;
	char *boundary;
	char *range;
	int clength;
	int remaining;
	int read_length;
	int read_body;
	int read_chunked;
	unsigned expecting_100;
	void *headers_in;
	void *headers_out;
	void *err_headers_out;
	void *subprocess_env;
	void *notes;
	char *content_type;
	char *handler;
	char *content_encoding;
	char *content_language;
	void *content_languages;
	char *vlist_validator;
	int no_cache;
	int no_local_copy;
	char *unparsed_uri;
	char *uri;
	char *filename;
	char *path_info;
	char *args;
	stat finfo;
	uri_components parsed_uri;
	void *per_dir_config;
	void *request_config;
	htaccess_result *htaccess;
} ;
#pragma pack(pop)

#pragma option push -b-
enum cmd_how { RAW_ARGS, TAKE1, TAKE2, ITERATE, ITERATE2, FLAG, NO_ARGS, TAKE12, TAKE3, TAKE23, TAKE123, TAKE13 };
#pragma option pop

typedef char * __fastcall (*TCommandFunc)(void);

struct command_rec;
typedef command_rec *Pcommand_rec;

#pragma pack(push, 1)
struct command_rec
{
	char *name;
	TCommandFunc func;
	void *cmd_data;
	int req_override;
	cmd_how args_how;
	char *errmsg;
} ;
#pragma pack(pop)

typedef int __cdecl (*THandlerFunc)(Prequest_rec rr);

struct handler_rec;
typedef handler_rec *Phandler_rec;

#pragma pack(push, 1)
struct handler_rec
{
	char *content_type;
	THandlerFunc handler;
} ;
#pragma pack(pop)

struct module;
typedef module *Pmodule;

#pragma pack(push, 1)
struct module
{
	int version;
	int minor_version;
	int module_index;
	char *name;
	void *dynamic_load_handle;
	module *next;
	int magic;
	void __cdecl (*init)(Pserver_rec s, void * p);
	void * __cdecl (*create_dir_config)(void * p, char * dir);
	void * __cdecl (*merge_dir_config)(void * p, void * base_conf, void * new_conf);
	void * __cdecl (*create_server_config)(void * p, Pserver_rec s);
	void * __cdecl (*merge_server_config)(void * p, void * base_conf, void * new_conf);
	command_rec *cmds;
	handler_rec *handlers;
	THandlerFunc translate_handler;
	THandlerFunc ap_check_user_id;
	THandlerFunc auth_checker;
	THandlerFunc access_checker;
	THandlerFunc type_checker;
	THandlerFunc fixer_upper;
	THandlerFunc logger;
	THandlerFunc header_parser;
	void __cdecl (*child_init)(Pserver_rec s, void * p);
	void __cdecl (*child_exit)(Pserver_rec s, void * p);
	int __cdecl (*post_read_request)(Prequest_rec r);
} ;
#pragma pack(pop)

typedef int __fastcall (*TCompFunc)(void * rec, const char * key, const char * value);

typedef void __fastcall (*TCleanupFunc)(void * p);

typedef void __fastcall (*TSpawnFunc)(void * p, void * ci);

typedef int __fastcall (*TbSpawnFunc)(void * p, void * ci);

struct regex_t;
typedef regex_t *Pregex_t;

#pragma pack(push, 1)
struct regex_t
{
	int re_magic;
	int re_nsub;
	char *re_endp;
	void *re_g;
} ;
#pragma pack(pop)

#pragma option push -b-
enum kill_conditions { kill_never, kill_always, kill_after_timeout, just_wait, kill_only_once };
#pragma option pop

struct configfile_t;
typedef configfile_t *Pconfigfile_t;

#pragma pack(push, 1)
struct configfile_t
{
	int __fastcall (*getch)(void * param);
	void * __fastcall (*getstr)(void * buf, int bufsiz, void * param);
	int __fastcall (*close)(void * param);
	void *param;
	char *filename;
	unsigned line_number;
} ;
#pragma pack(pop)

struct cmd_parms;
typedef cmd_parms *Pcmd_parms;

#pragma pack(push, 4)
struct cmd_parms
{
	void *info;
	int override;
	int limited;
	configfile_t *config_file;
	void *pool;
	void *temp_pool;
	server_rec *server;
	char *path;
	command_rec *cmd;
	char *end_token;
	void *context;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define ApacheCore "ApacheCore.dll"
#define TARGET "apache"
static const Shortint DYNAMIC_MODULE_LIMIT = 0x40;
#define DEFAULT_ADMIN "[no address given]"
static const int MODULE_MAGIC_COOKIE = 0x41503133;
static const int MODULE_MAGIC_NUMBER_MAJOR = 0x1310730;
static const Shortint MODULE_MAGIC_NUMBER_MINOR = 0x6;
static const int MODULE_MAGIC_NUMBER = 0x1310730;
static const int APACHE_RELEASE = 0x9d4dec;
#define SERVER_PROTOCOL "HTTP/1.1"
static const Shortint AP_DECLINED = 0xffffffff;
static const Shortint AP_DONE = 0xfffffffe;
static const Shortint AP_OK = 0x0;
static const Shortint REQUEST_NO_BODY = 0x0;
static const Shortint REQUEST_CHUNKED_ERROR = 0x1;
static const Shortint REQUEST_CHUNKED_DECHUNK = 0x2;
static const Shortint REQUEST_CHUNKED_PASS = 0x3;
static const Shortint M_GET = 0x0;
static const Shortint M_PUT = 0x1;
static const Shortint M_POST = 0x2;
static const Shortint M_DELETE = 0x3;
static const Shortint M_CONNECT = 0x4;
static const Shortint M_OPTIONS = 0x5;
static const Shortint M_TRACE = 0x6;
static const Shortint M_PATCH = 0x7;
static const Shortint M_PROPFIND = 0x8;
static const Shortint M_PROPPATCH = 0x9;
static const Shortint M_MKCOL = 0xa;
static const Shortint M_COPY = 0xb;
static const Shortint M_MOVE = 0xc;
static const Shortint M_LOCK = 0xd;
static const Shortint M_UNLOCK = 0xe;
static const Shortint M_INVALID = 0xf;
static const Shortint METHODS = 0x10;
static const Shortint REMOTE_HOST = 0x0;
static const Shortint REMOTE_NAME = 0x1;
static const Shortint REMOTE_NOLOOKUP = 0x2;
static const Shortint REMOTE_DOUBLE_REV = 0x3;
#define CGI_MAGIC_TYPE "application/x-httpd-cgi"
#define INCLUDES_MAGIC_TYPE "text/x-server-parsed-html"
#define INCLUDES_MAGIC_TYPE3 "text/x-server-parsed-html3"
#define MAP_FILE_MAGIC_TYPE "application/x-type-map"
#define ASIS_MAGIC_TYPE "httpd/send-as-is"
#define DIR_MAGIC_TYPE "httpd/unix-directory"
#define STATUS_MAGIC_TYPE "application/x-httpd-status"
static const Shortint RESPONSE_CODES = 0x37;
static const Shortint HTTP_CONTINUE = 0x64;
static const Shortint HTTP_SWITCHING_PROTOCOLS = 0x65;
static const Shortint HTTP_PROCESSING = 0x66;
static const Byte HTTP_OK = 0xc8;
static const Byte HTTP_CREATED = 0xc9;
static const Byte HTTP_ACCEPTED = 0xca;
static const Byte HTTP_NON_AUTHORITATIVE = 0xcb;
static const Byte HTTP_NO_CONTENT = 0xcc;
static const Byte HTTP_RESET_CONTENT = 0xcd;
static const Byte HTTP_PARTIAL_CONTENT = 0xce;
static const Byte HTTP_MULTI_STATUS = 0xcf;
static const Word HTTP_MULTIPLE_CHOICES = 0x12c;
static const Word HTTP_MOVED_PERMANENTLY = 0x12d;
static const Word HTTP_MOVED_TEMPORARILY = 0x12e;
static const Word HTTP_SEE_OTHER = 0x12f;
static const Word HTTP_NOT_MODIFIED = 0x130;
static const Word HTTP_USE_PROXY = 0x131;
static const Word HTTP_TEMPORARY_REDIRECT = 0x133;
static const Word HTTP_BAD_REQUEST = 0x190;
static const Word HTTP_UNAUTHORIZED = 0x191;
static const Word HTTP_PAYMENT_REQUIRED = 0x192;
static const Word HTTP_FORBIDDEN = 0x193;
static const Word HTTP_NOT_FOUND = 0x194;
static const Word HTTP_METHOD_NOT_ALLOWED = 0x195;
static const Word HTTP_NOT_ACCEPTABLE = 0x196;
static const Word HTTP_PROXY_AUTHENTICATION_REQUIRED = 0x197;
static const Word HTTP_REQUEST_TIME_OUT = 0x198;
static const Word HTTP_CONFLICT = 0x199;
static const Word HTTP_GONE = 0x19a;
static const Word HTTP_LENGTH_REQUIRED = 0x19b;
static const Word HTTP_PRECONDITION_FAILED = 0x19c;
static const Word HTTP_REQUEST_ENTITY_TOO_LARGE = 0x19d;
static const Word HTTP_REQUEST_URI_TOO_LARGE = 0x19e;
static const Word HTTP_UNSUPPORTED_MEDIA_TYPE = 0x19f;
static const Word HTTP_RANGE_NOT_SATISFIABLE = 0x1a0;
static const Word HTTP_EXPECTATION_FAILED = 0x1a1;
static const Word HTTP_UNPROCESSABLE_ENTITY = 0x1a6;
static const Word HTTP_LOCKED = 0x1a7;
static const Word HTTP_FAILED_DEPENDENCY = 0x1a8;
static const Word HTTP_INTERNAL_SERVER_ERROR = 0x1f4;
static const Word HTTP_NOT_IMPLEMENTED = 0x1f5;
static const Word HTTP_BAD_GATEWAY = 0x1f6;
static const Word HTTP_SERVICE_UNAVAILABLE = 0x1f7;
static const Word HTTP_GATEWAY_TIME_OUT = 0x1f8;
static const Word HTTP_VERSION_NOT_SUPPORTED = 0x1f9;
static const Word HTTP_VARIANT_ALSO_VARIES = 0x1fa;
static const Word HTTP_INSUFFICIENT_STORAGE = 0x1fb;
static const Word HTTP_NOT_EXTENDED = 0x1fe;
static const Byte DOCUMENT_FOLLOWS = 0xc8;
static const Byte PARTIAL_CONTENT = 0xce;
static const Word MULTIPLE_CHOICES = 0x12c;
static const Word MOVED = 0x12d;
static const Word REDIRECT = 0x12e;
static const Word USE_LOCAL_COPY = 0x130;
static const Word BAD_REQUEST = 0x190;
static const Word AUTH_REQUIRED = 0x191;
static const Word FORBIDDEN = 0x193;
static const Word NOT_FOUND = 0x194;
static const Word METHOD_NOT_ALLOWED = 0x195;
static const Word NOT_ACCEPTABLE = 0x196;
static const Word LENGTH_REQUIRED = 0x19b;
static const Word PRECONDITION_FAILED = 0x19c;
static const Word SERVER_ERROR = 0x1f4;
static const Word NOT_IMPLEMENTED = 0x1f5;
static const Word BAD_GATEWAY = 0x1f6;
static const Word VARIANT_ALSO_VARIES = 0x1fa;
static const Shortint APLOG_EMERG = 0x0;
static const Shortint APLOG_ALERT = 0x1;
static const Shortint APLOG_CRIT = 0x2;
static const Shortint APLOG_ERR = 0x3;
static const Shortint APLOG_WARNING = 0x4;
static const Shortint APLOG_NOTICE = 0x5;
static const Shortint APLOG_INFO = 0x6;
static const Shortint APLOG_DEBUG = 0x7;
static const Shortint APLOG_LEVELMASK = 0x7;
static const Shortint APLOG_NOERRNO = 0x8;
static const Shortint APLOG_WIN32ERROR = 0x10;
static const Shortint OR_NONE = 0x0;
static const Shortint OR_LIMIT = 0x1;
static const Shortint OR_OPTIONS = 0x2;
static const Shortint OR_FILEINFO = 0x4;
static const Shortint OR_AUTHCFG = 0x8;
static const Shortint OR_INDEXES = 0x10;
static const Shortint OR_UNSET = 0x20;
static const Shortint ACCESS_CONF = 0x40;
static const Byte RSRC_CONF = 0x80;
static const Shortint OR_ALL = 0x1f;
extern "C" void __fastcall ap_note_auth_failure(Prequest_rec r);
extern "C" void __fastcall ap_note_basic_auth_failure(Prequest_rec r);
extern "C" void __fastcall ap_note_digest_auth_failure(Prequest_rec r);

}	/* namespace Httpd */
using namespace Httpd;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPD
