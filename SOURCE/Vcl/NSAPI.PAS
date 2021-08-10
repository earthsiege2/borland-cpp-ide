
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       Structure definitions and prototypes for the    }
{       Netscape Internet Server API (NSAPI)            }
{                                                       }
{       Copyright (C) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit NSApi;

{$WEAKPACKAGEUNIT}

interface

uses Windows, WinSock;

{*****************************************************************************}
{* From version.h                                                             }
{*****************************************************************************}
{

  This file is included from both C source and the NT installation compiler.
  Because of that, no ifdefs are allowed, and strings must be simple strings
  (not concatenated).

  Because macros called PERSONAL_VERSION and ENTERPRISE_VERSION already
  exist, the PRODUCT_VERSION define has _DEF appended.
}

const
  PROXY_VERSION_DEF = '2.0b4';
  PROXY_VERSION_STRING = 'Netscape-Proxy/2.0b4';

  ADMSERV_VERSION_DEF = '2.0';
  ADMSERV_VERSION_STRING = 'Netscape-Administrator/2.0';

  PERSONAL_VERSION_DEF = '2.0b4';
  PERSONAL_VERSION_STRING = 'Netscape-FastTrack/2.0b4';

  CATALOG_VERSION_DEF = '1.0b2';
  CATALOG_VERSION_STRING = 'Netscape-Catalog/1.0b2';

  RDS_VERSION_DEF = '1.0b2';
  RDS_VERSION_STRING = 'Netscape-RDS/1.0b2';

  ENTERPRISE_VERSION_DEF = '2.0b4';
  ENTERPRISE_VERSION_STRING = 'Netscape-Enterprise/2.0b4';

  NEWS_VERSION_STRING = 'Netscape 1.1';

  BATMAN_VERSION_DEF = '1.0a1';
  BATMAN_VERSION_STRING = 'Batman/1.0a1';

{*****************************************************************************}
{* From systems.h                                                             }
{*****************************************************************************}
{
  Lists of defines for systems
  This sets what general flavor the system is (UNIX, etc.),
  and defines what extra functions your particular system needs.
}

  DAEMON_LISTEN_SIZE = 100;

function strcasecmp(s1, s2: PChar): Integer; cdecl;
function strncasecmp(s1, s2: PChar; n: Integer): Integer; cdecl;
function util_strcasecmp(s1, s2: PChar): Integer; cdecl;
function util_strncasecmp(s1, s2: PChar; n: Integer): Integer; cdecl;

type
  PASSWD = Pointer;
  PPASSWD = ^PASSWD;
  TCAddr = PChar; {caddr_t}
  caddr_t = TCAddr;
  TAtRestart = procedure (Data: Pointer) cdecl;
  TMagnusAtRestart = TAtRestart;
  TDaemonAtRestart = TAtRestart;

{*****************************************************************************}
{* From netsite.h                                                             }
{*****************************************************************************}
{
   Standard defs for NetSite servers.
}

const
  {* Used in some places as a length limit on error messages *}
  MAGNUS_ERROR_LEN = 8192;

  {* Carraige return and line feed *}
  CR = 13;
  LF = 10;
  ENDLINE = #13#10;

  {* -------------------------- System version on NT------------------------- *}

  {* Encode the server version as a number to be able to provide inexpensive
   * dynamic checks on server version - this isn't added in yet. *}

  ENTERPRISE_VERSION = 1;
  PERSONAL_VERSION = 2;
  CATALOG_VERSION = 3;
  RDS_VERSION = 4;

{* Return server version *}
function system_version: PChar; cdecl;
function MAGNUS_VERSION_STRING: PChar; cdecl;

function server_fasttrack: Boolean;
function server_enterprise: Boolean;

{* Set server's version dynamically *}
procedure system_version_set(ptr: PChar); cdecl;

{* -------------------------- Memory allocation --------------------------- *}


{*
   Depending on the system, memory allocated via these macros may come from
   an arena. If these functions are called from within an Init function, they
   will be allocated from permanent storage. Otherwise, they will be freed
   when the current request is finished.
*}

function MALLOC(size: Integer): Pointer; cdecl;
function system_malloc(size: Integer): Pointer; cdecl;

function CALLOC(size: Integer): Pointer; cdecl;
function system_calloc(size: Integer): Pointer; cdecl;

function REALLOC(ptr: Pointer; size: Integer): Pointer; cdecl;
function system_realloc(ptr: Pointer; size: Integer): Pointer; cdecl;

procedure FREE(ptr: Pointer); cdecl;
procedure system_free(ptr: Pointer); cdecl;

function STRDUP(ptr: PChar): PChar; cdecl;
function system_strdup(ptr: PChar): PChar; cdecl;

{*
   These macros always provide permanent storage, for use in global variables
   and such. They are checked at runtime to prevent them from returning NULL.
*}

function PERM_MALLOC(size: Integer): Pointer; cdecl;
function system_malloc_perm(size: Integer): Pointer; cdecl;

function PERM_CALLOC(size: Integer): Pointer; cdecl;
function system_calloc_perm(size: Integer): Pointer; cdecl;

function PERM_REALLOC(ptr: Pointer; size: Integer): Pointer; cdecl;
function system_realloc_perm(ptr: Pointer; size: Integer): Pointer; cdecl;

procedure PERM_FREE(ptr: Pointer); cdecl;
procedure system_free_perm(ptr: Pointer); cdecl;

function PERM_STRDUP(ptr: PChar): PChar; cdecl;
function system_strdup_perm(ptr: PChar): PChar; cdecl;

{* Not sure where to put this. *}
procedure magnus_atrestart(fn: TMagnusAtRestart; data: Pointer); cdecl;

{*****************************************************************************}
{* From pool.h                                                                }
{*****************************************************************************}
{
  Module for handling memory allocations.

  Notes:
  This module is used instead of the NSPR prarena module because the prarenas
  did not fit as cleanly into the existing server.
}

type
  pool_handle_t = Pointer;
  TPoolHandle = pool_handle_t;
  PPoolHandle = ^TPoolHandle;

{ pool_create
  Function to create a new pool.
  Returns non-NULL on success, NULL on failure.
}
function pool_create: PPoolHandle; cdecl;

{ pool_destroy
  Frees all memory associated with a pool and destroys the pool.
}
procedure pool_destroy(pool_handle: PPoolHandle); cdecl;

{ pool_enabled
  Check if the pools are enabled and a pool is currently set
  for this thread.  Return 1 if enabled, 0 if not enabled.
}
function pool_enabled: BOOL; cdecl;
function pool_malloc(pool_handle: PPoolHandle; size: Integer): Pointer; cdecl;
procedure pool_free(pool_handle: PPoolHandle; ptr: Pointer); cdecl;
function pool_calloc(pool_handle: PPoolHandle; nelem, elsize: Integer): Pointer; cdecl;
function pool_realloc(pool_handle: PPoolHandle; ptr: Pointer; size: Integer): Pointer; cdecl;
function pool_strdup(pool_handle: PPoolHandle; orig_str: PChar): PChar; cdecl;

{*****************************************************************************}
{* From sem.h                                                                 }
{*****************************************************************************}
{
  Attempt to provide multi-process semaphores across platforms
}

type
  Semaphore = THandle;

const
  SEM_ERROR    = 0;
  {* That oughta hold them (I hope) *}
  SEM_MAXVALUE = 32767;

{
  sem_init creates a semaphore using the given name and unique
  identification number. filename should be a file accessible to the
  process. Returns SEM_ERROR on error.
}
function sem_init(name: PChar; Number: Integer): Semaphore; cdecl;

{
  sem_terminate de-allocates the given semaphore.
}
procedure sem_terminate(id: Semaphore); cdecl;

{
  sem_grab attempts to gain exclusive access to the given semaphore. If
  it can't get it, the caller will block. Returns -1 on error.
}
function sem_grab(id: Semaphore): Integer; cdecl;
function sem_tgrab(id: Semaphore): Integer; cdecl;

{
  sem_release releases this process's exclusive control over the given
  semaphore. Returns -1 on error.
}
function sem_release(id: Semaphore): Integer; cdecl;

{*****************************************************************************}
{* From crit.h                                                                }
{*****************************************************************************}
{
  Critical section abstraction. Used in threaded servers to protect
  areas where two threads can interfere with each other.

  Condvars are condition variables that are used for thread-thread
  synchronization.
}

type
  CRITICAL = Pointer;

{
  crit_init creates and returns a new critical section variable. At the
  time of creation no one has entered it.
}
function crit_init: CRITICAL; cdecl;

{
  crit_enter enters a critical section. If someone is already in the
  section, the calling thread is blocked until that thread exits.
}
procedure crit_enter(id: CRITICAL); cdecl;

{
  crit_exit exits a critical section. If another thread is blocked waiting
  to enter, it will be unblocked and given ownership of the section.
}
procedure crit_exit(id: CRITICAL); cdecl;

{
  crit_terminate removes a previously allocated critical section variable.
}
procedure crit_terminate(id: CRITICAL); cdecl;

type
  CONDVAR = Pointer;

{
  condvar_init initializes and returns a new condition variable. You
  must provide a critical section to be associated with this condition
  variable.
}
function condvar_init(id: CRITICAL): CONDVAR; cdecl;

{
  condvar_wait blocks on the given condition variable. The calling thread
  will be blocked until another thread calls condvar_notify on this variable.
  The caller must have entered the critical section associated with this
  condition variable prior to waiting for it.
}
procedure condvar_wait(cv: CONDVAR); cdecl;

{
  condvar_notify awakens any threads blocked on the given condition
  variable. The caller must have entered the critical section associated
  with this variable first.
}
procedure condvar_notify(cv: CONDVAR); cdecl;

{
  condvar_terminate frees the given previously allocated condition variable
}
procedure condvar_terminate(cv: CONDVAR); cdecl;

{*****************************************************************************}
{* From file.h                                                                }
{*****************************************************************************}
{
  system specific functions for reading/writing files
}

{
  I cheat: These are set up such that system_read can be a macro for read
  under UNIX. IO_OKAY is anything positive.
}

const
  IO_OKAY = 1;
  IO_ERROR = -1;
  IO_EOF = 0;

{* -------------------------- File related defs --------------------------- *}

{* The disk page size on this machine. *}
  FILE_BUFFERSIZE = 4096;

{
  The fd data type for this system.
}

type
  SYS_FILE = ^TFile;
  TFile = record
    fh: THandle;
	fname: PChar;
    flsem: Semaphore;
  end;
  file_s = TFile;

const
  SYS_ERROR_FD = nil;
  SYS_STDERR = nil;

type
  pid_t = THandle;
  TPid = pid_t;

const
  ERROR_PIPE = ERROR_BROKEN_PIPE or ERROR_BAD_PIPE or ERROR_PIPE_BUSY or
    ERROR_PIPE_LISTENING or ERROR_PIPE_NOT_CONNECTED;

procedure CONVERT_TO_PRINTABLE_FORMAT(Filename: PChar);
procedure CONVERT_TO_NATIVE_FS(Filename: PChar);

{!!! uses errno from C RTL }
{ #define rtfile_notfound() ((errno == ENOENT) || (errno == ESRCH)) }

const
  FILE_PATHSEP = '/';
  FILE_PARENT  = '..\';

function system_chdir(Path: PChar): BOOL; stdcall;

{
  Wrapper for stat system call
}
type
  PStat = ^TStat;
  TStat = record
    st_dev: Word;
    st_ino: Word;
    st_mode: Word;
    st_nlink: SmallInt;
    st_uid: SmallInt;
    st_gid: SmallInt;
    st_rdev: Word;
    st_size: Longint;
    st_atime: Longint;
    st_mtime: Longint;
    st_ctime: Longint;
  end;
  Stat = TStat;

function system_stat(name: PChar; var finfo: TStat): Integer; cdecl;

{
  Wrapper for rename system call
}
function system_rename(Old, New: PChar): BOOL;

{
  Wrapper to remove file
}
function system_unlink(path: PChar): BOOL;

{
  system_fread reads sz bytes from fd into to buf, return number of bytes
  read, or IO_EOF if EOF, or IO_ERROR if error.
}
function system_fread(fd: SYS_FILE; buf: Pointer; sz: Integer): Integer; cdecl;
function system_pread(fd: SYS_FILE; buf: Pointer; sz: Integer): Integer; cdecl;

{
  system_fopenRO opens a given file for reading only
  system_fopenWA opens a given file for writing, appending new output
}
function system_fopenRO(path: PChar): SYS_FILE; cdecl;
function system_fopenWA(path: PChar): SYS_FILE; cdecl;
function system_fopenRW(path: PChar): SYS_FILE; cdecl;
function system_fopenWT(path: PChar): SYS_FILE; cdecl;

{
  system_fclose closes the file fd
}
procedure system_fclose(fd: SYS_FILE); cdecl;

{
  This call stops core dumps in a portable way. Returns -1 on error.
}
function system_nocoredumps: Integer; cdecl;

function system_winsockerr: PChar; cdecl;
function system_winerr: PChar; cdecl;
function system_lseek(fd: SYS_FILE; off: Longint; wh: Longint): Longint;

{
  system_write writes sz bytes from buf to fd. The handler function should
  handle partial writes and anything else like that. Returns IO_*
}
function system_fwrite(fd: SYS_FILE; buf: Pointer; sz: Integer): Integer; cdecl;

{
  system_fwrite_atomic locks the given fd before writing to it. This avoids
  interference between simultaneous writes. Returns IO_*
}
function system_fwrite_atomic(fd: SYS_FILE; buf: Pointer; sz: Integer): Integer; cdecl;

{
  system_errmsg returns the last error that occured while processing file
  descriptor fd. fd does not have to be specified (if the error is a global
  such as in UNIX systems). PPS: Rob is a halfwit. This parameter is useless.
}
function file_notfound: Integer; cdecl;
function system_errmsg: PChar; cdecl; {system_errmsg_fn}
function system_errmsg_fn: PChar; cdecl;

{
  flock locks a file against interference from other processes
  ulock unlocks it.
}
function system_initlock(fd: SYS_FILE): Integer; cdecl;
function system_flock(fd: SYS_FILE): Integer;
function system_ulock(fd: SYS_FILE): Integer;

{
  setinherit sets whether the file descriptor fd can be inherited by child
  processes. A non-zero value means they can. Return of -1 means error.
}
function file_setinherit(fd: SYS_FILE; value: Integer): Integer; cdecl;

{
  unix2local converts a unix-style pathname to a local one
}
procedure file_unix2local(path, p2: PChar); cdecl;

{* -------------------------- Dir related defs ---------------------------- *}


type
  PDirEnt = ^TDirEnt;
  TDirEnt = packed record
    d_name: PChar;
  end;
  dirent_s = TDirEnt;

  PDir = ^TDir;
  TDir = record
    dp: THandle;
    fdata: TWin32FindData;
    de: dirent_s;
  end;
  dir_s = TDir;

  SYS_DIR = PDir;
  SYS_DIRENT = TDir;

function dir_open(path: PChar): SYS_DIR; cdecl;
function dir_read(ds: SYS_DIR): PDirEnt; cdecl;
procedure dir_close(ds: SYS_DIR); cdecl;
function dir_create(Path: PChar): Integer;
function dir_remove(Path: PChar): Integer;

{
  create a directory and any of its parents
}
function dir_create_all(dir: PChar): Integer; cdecl;

{
  Thread-safe variants of localtime and gmtime
}
type
  tm = record
    tm_sec: Integer;
    tm_min: Integer;
    tm_hour: Integer;
    tm_mday: Integer;
    tm_mon: Integer;
    tm_year: Integer;
    tm_wday: Integer;
    tm_yday: Integer;
    tm_isdst: Integer;
  end;
  ptm = ^tm;

{!!! need conversion }
{function system_localtime(curtime: Longint) localtime(curtime)
function system_gmtime(curtime: Longint) gmtime(curtime) }

{*****************************************************************************}
{* From pblock.h                                                              }
{*****************************************************************************}
{
  pblock.h: Header for Parameter Block handling functions

  A parameter block is a set of name=value pairs which are generally used
  as parameters, but can be anything. They are kept in a hash table for
  reasonable speed, but if you are doing any intensive modification or
  access of them you should probably make a local copy of each parameter
  while working.

  When creating a pblock, you specify the hash table size for that pblock.
  You should set this size larger if you know that many items will be in
  that pblock, and smaller if only a few will be used or if speed is not
  a concern.

  The hashing function is very simple right now, and only looks at the
  first character of name.

}

{* ------------------------------ Structures ------------------------------ *}


type
  PPbParam = ^TPbParam;
  TPbParam = record
    name: PChar;
    value: PChar;
  end;
  pb_param = TPbParam;

  PPbEntry = ^TPbEntry;
  TPbEntry = record
    param: PPbParam;
    next: PPbEntry;
  end;
  pb_entry = TPbEntry;
  PPPbEntry = ^PPbEntry;

  PPblock = ^TPblock;
  TPblock = record
    hsize: Integer;
    ht: PPPbEntry;
  end;
  pblock = TPblock;

  TPCharArray = array[0..MaxInt div 16 - 1] of PChar;
  PPCharArray = ^TPCharArray;

{* ------------------------------ Prototypes ------------------------------ *}


{
  param_create creates a parameter with the given name and value. If name
  and value are non-NULL, they are copied and placed into the new pb_param
  struct.
}
function param_create(name, value: PChar): PPbParam; cdecl;

{
  param_free frees a given parameter if it's non-NULL, and returns 1 if
  p was non-NULL, and 0 if p was NULL.

  Useful for error checking pblock_remove.
}
function param_free(pp: PPbParam): Integer; cdecl;

{
  pblock_create creates a new pblock with hash table size n.

  It returns the newly allocated pblock.
}
function pblock_create(n: Integer): PPblock; cdecl;

{
  pblock_free frees the given pblock and any entries inside it.

  If you want to save anything in a pblock, remove its entities with
  pblock_remove first and save the pointers you get.
}
procedure pblock_free(pb: PPblock); cdecl;

{
  pblock_find finds the entry with the given name in pblock pb.

  If it is successful, it returns the param block. If not, it returns NULL.
}
function pblock_find(name: PChar; pb: PPblock): PPbParam;

{
  pblock_findval finds the entry with the given name in pblock pb, and
  returns its value, otherwise returns NULL.
}
function pblock_findval(name: PChar; pb: PPblock): PChar; cdecl;

{
  pblock_remove behaves exactly like pblock_find, but removes the given
  entry from pb.
}
function pblock_remove(name: PChar; pb: PPblock): PPbParam;

{
  pblock_nvinsert creates a new parameter with the given name and value
  and inserts it into pblock pb. The name and value in the parameter are
  also newly allocated. Returns the pb_param it allocated (in case you
  need it).

  pblock_nninsert inserts a numerical value.
}
function pblock_nvinsert(name, value: PChar; pb: PPblock): PPbParam; cdecl;
function pblock_nninsert(name: PChar; value: Integer; pb: PPblock): PPbParam; cdecl;

{
  pblock_pinsert inserts a pb_param into a pblock.
}
procedure pblock_pinsert(pp: PPbParam; pb: PPblock); cdecl;

{
  pblock_str2pblock scans the given string str for parameter pairs
  name=value, or name="value". Any \ must be followed by a literal
  character. If a string value is found, with no unescaped = signs, it
  will be added with the name 1, 2, 3, etc. depending on whether it was
  first, second, third, etc. in the stream (zero doesn't count).

  Returns the number of parameters added to the table, or -1 upon error.
}
function pblock_str2pblock(str: PChar; pb: PPblock): Integer; cdecl;

{
  pblock_pblock2str places all of the parameters in the given pblock
  into the given string (NULL if it needs creation). It will re-allocate
  more space for the string. Each parameter is separated by a space and of
  the form name="value"
}
function pblock_pblock2str(pb: PPblock; str: PChar): PChar; cdecl;

{
  pblock_copy copies the entries in the given source pblock to the
  destination one. The entries are newly allocated so that the original
  pblock may be freed or the new one changed without affecting the other.
}
procedure pblock_copy(src, dst: PPblock); cdecl;

{
  pblock_dup creates a new pblock and copies the given source pblock
  into it.  The entries are newly allocated so that the original pblock
  may be freed or the new one changed without affecting the other.
}
function pblock_dup(src: PPblock): PPblock; cdecl;

{
  pblock_pb2env copies the given pblock into the given environment, with
  one new env entry for each name/value pair in the pblock.
}
function pblock_pb2env(pb: PPblock; env: PPCharArray): PPCharArray;

{* --------------------------- Internal things ---------------------------- *}
function _pblock_fr(name: PChar; pb: PPblock; remove: BOOL): PPbParam; cdecl;

{*****************************************************************************}
{* From net.h                                                                 }
{*****************************************************************************}
{
  system specific networking definitions
}

const
{* This should be a user-given parameter later *}
  NET_BUFFERSIZE = 8192;
{* So should this. *}
  NET_READ_TIMEOUT = 120;
  NET_WRITE_TIMEOUT = 300;
  NET_INFINITE_TIMEOUT = 0;
  NET_ZERO_TIMEOUT = -1;

  SSL_HANDSHAKE_TIMEOUT = 300;

{* ------------------------------ Data types ------------------------------ *}
type
  SYS_NETFD = Integer;

const
  SYS_NET_ERRORFD = (-1);

{* -------------------------------- Global -------------------------------- *}

{!!!
extern int net_enabledns;
extern int net_listenqsize;


int net_accept_init(int port);
void net_accept_terminate(void);
void net_accept_enter(void);
int net_accept_tenter(void);
void net_accept_exit(void);
void net_accept_texit(void);
}

{* ------------------------------ Prototypes ------------------------------ *}


function net_socket(domain, nettype, protocol: Integer): SYS_NETFD; cdecl;
function net_getsockopt(s: SYS_NETFD; level, optname: Integer; optval: Pointer;
  var optlen: Integer): Integer; cdecl;
function net_setsockopt(s: SYS_NETFD; level, optname: Integer; optval: Pointer;
  optlen: Integer): Integer; cdecl;
function net_listen(s: SYS_NETFD; backlog: Integer): Integer; cdecl;
function net_create_listener(ipaddr: PChar; port: Integer): SYS_NETFD; cdecl;
function net_select(nfds: Integer; r, w, e: PFDSet; timeout: PTimeVal): Integer; cdecl;
function net_connect(s: SYS_NETFD; sockaddr: Pointer; namelen: Integer): Integer; cdecl;
function net_ioctl(s: SYS_NETFD; tag: Integer; result: Pointer): Integer; cdecl;
function net_getpeername(s: SYS_NETFD; var name: TSockAddr; var namelen: Integer): Integer; cdecl;
function net_close(s: SYS_NETFD): Integer; cdecl;
function net_bind(s: SYS_NETFD; var name: TSockAddr; namelen: Integer): Integer; cdecl;
function net_accept(s: SYS_NETFD; addr: PSockAddr; addrlen: PInteger): SYS_NETFD; cdecl;
function net_read(sd: SYS_NETFD; buf: PChar; sz, timeout: Integer): Integer; cdecl;
function net_write(sd: SYS_NETFD; buf: PChar; sz: Integer): Integer; cdecl;
{!!! what is iovec???? }
// function _net_writev(sd: SYS_NETFD; struct iovec *iov, int iovlen);

{
  net_isalive checks to see if the given sd is still connected to a remote
  host. It returns 0 if the socket is no longer connected, or 1 if it is
  still there. The remote host will not see any side effects.
}
function net_isalive(sd: SYS_NETFD): BOOL; cdecl;

{!!! what is iovec???
int _net_simulated_writev(SYS_NETFD sd, struct iovec *iov, int iovlen);
NSAPI_PUBLIC extern int
(*net_writev)(SYS_NETFD sd, struct iovec *iov, int iovlen);
}

{
  net_ip2host transforms the given textual IP number into a FQDN. If it
  can't find a FQDN, it will return what it can get. Otherwise, NULL.

  verify is whether or not the function should verify the hostname it
  gets. This takes an extra query but is safer for use in access control.
}
function net_ip2host(ip: PChar; verify: BOOL): PChar; cdecl;

{*****************************************************************************}
{* From buffer.h                                                              }
{*****************************************************************************}
{
  For performing buffered I/O on a file or socket descriptor.

  This is an abstraction to allow I/O to be performed regardless of the
  current system. That way, an integer file descriptor can be used under
  UNIX but a stdio FILE structure could be used on systems which don't
  support that or don't support it as efficiently.

  Two abstractions are defined: A file buffer, and a network buffer. A
  distinction is made so that mmap() can be used on files (but is not
  required). Also, the file buffer takes a file name as the object to
  open instead of a file descriptor. A lot of the network buffering
  is almost an exact duplicate of the non-mmap file buffering.

  If an error occurs, system-independent means to obtain an error string
  are also provided. However, if the underlying system is UNIX the error
  may not be accurate in a threaded environment.
}

{* ------------------------------ Structures ------------------------------ *}

type
  PFileBuffer = ^TFileBuffer;
  TFileBuffer = record
    fd: SYS_FILE;
    fdmap: THandle;
    fp: PChar;
    len: Integer;
    inbuf: PChar;   // for buffer_grab
    cursize: Integer;
    pos: Integer;
    errmsg: PChar;
  end;
  filebuffer = TFileBuffer;
  filebuf = filebuffer;

  PNetBuf = ^TNetBuf;
  TNetBuf = record
    sd: SYS_NETFD;
    pos,
    cursize,
    maxsize,
    rdtimeout: Integer;
    address: array[0..63] of Char;
    inbuf: PChar;
    errmsg: PChar;
  end;
  netbuf = TNetBuf;


{* -------------------------------- Macros -------------------------------- *}

{
  netbuf_getc gets a character from the given network buffer and returns
  it. (as an integer).

  It will return (int) IO_ERROR for an error and (int) IO_EOF for
  an error condition or EOF respectively.
}
function netbuf_getc(b: PNetBuf): Integer;
function filebuf_getc(b: PFileBuffer): Integer;
function pipebuf_getc(b: PFileBuffer): Integer;

{
  buffer_error returns the last error that occurred with buffer. Don't use
  this unless you know an error occurred. Independent of network/file type.
}
//!!! #define buffer_error(b) ((b)->errmsg)

{* ------------------------------ Prototypes ------------------------------ *}


{
  buffer_open opens a new buffer reading the specified file, with an I/O
  buffer of size sz, and returns a new buffer structure which will hold
  the data.

  If FILE_UNIX_MMAP is defined, this may return NULL. If it does, check
  system_errmsg to get a message about the error.
}

function filebuf_open(fd: SYS_FILE; sz: Integer): PFileBuffer; cdecl;
function netbuf_open(sd: SYS_NETFD; sz: Integer): PNetBuf; cdecl;

{
  filebuf_create is a convenience function if the file is already open
  or mmap'd.  It creates a new filebuf for use with the mmap'd file.
  If mmap_ptr is NULL, or MMAP is not supported on this system, it
  creates a buffer with buffer size bufsz.
}

function filebuf_create(fd: SYS_FILE; mmap_ptr: caddr_t; mmap_len,
  bufsz: Integer): PFileBuffer; cdecl;

{
  filebuf_close_buffer is provided to cleanup a filebuf without closing
  the underlying file.  If clean_mmap is 1, and the file is memory mapped,
  the file will be unmapped.  If clean_mmap is 0, the file will not
  be unmapped.
}
procedure filebuf_close_buffer(buf: PFileBuffer; clean_mmap: BOOL); cdecl;

{
  filebuf_open_nostat is a convenience function for mmap() buffer opens,
  if you happen to have the stat structure already.
}
function filebuf_open_nostat(fd: SYS_FILE; sz: Integer; var finfo: TStat): PFileBuffer; cdecl;
function pipebuf_open(fd: SYS_FILE; sz: Integer; var finfo: TStat): PFileBuffer; cdecl;

{
  buffer_next loads size more bytes into the given buffer and returns the
  first one, or BUFFER_EOF on EOF and BUFFER_ERROR on error.
}
function filebuf_next(buf: PFileBuffer; advance: Integer): Integer; cdecl;
function netbuf_next(buf: PNetBuf; advance: Integer): Integer; cdecl;
function pipebuf_next(buf: PFileBuffer; advance: Integer): Integer; cdecl;

{
  buffer_close deallocates a buffer and closes its associated files
  (does not close a network socket).
}
procedure filebuf_close(buf: PFileBuffer); cdecl;
procedure netbuf_close(buf: PNetBuf); cdecl;
procedure pipebuf_close(buf: PFileBuffer); cdecl;

{
  buffer_grab will set the buffer's inbuf array to an array of sz bytes
  from the buffer's associated object. It returns the number of bytes
  actually read (between 1 and sz). It returns IO_EOF upon EOF or IO_ERROR
  upon error. The cursize entry of the structure will reflect the size
  of the iobuf array.

  The buffer will take care of allocation and deallocation of this array.
}
function filebuf_grab(buf: PFileBuffer; sz: Integer): Integer; cdecl;
function netbuf_grab(buf: PNetBuf; sz: Integer): Integer; cdecl;
function pipebuf_grab(buf: PFileBuffer; sz: Integer): Integer; cdecl;

{
  netbuf_buf2sd will send n bytes from the (probably previously read)
  buffer and send them to sd. If sd is -1, they are discarded. If n is
  -1, it will continue until EOF is recieved. Returns IO_ERROR on error
  and the number of bytes sent any other time.
}
function netbuf_buf2sd(buf: PNetBuf; sd: SYS_NETFD; len: Integer): Integer; cdecl;

{
  filebuf_buf2sd assumes that nothing has been read from the filebuf,
  and just sends the file out to the given socket. Returns IO_ERROR on error
  and the number of bytes sent otherwise.

  Does not currently support you having read from the buffer previously. This
  can be changed transparently.
}
function filebuf_buf2sd(buf: PFileBuffer; sd: SYS_NETFD): Integer; cdecl;

{
  NT pipe version of filebuf_buf2sd.
}
function pipebuf_buf2sd(buf: PFileBuffer; sd: SYS_NETFD; len: Integer): Integer; cdecl;

{
  NT pipe version of netbuf_buf2sd.
}
function pipebuf_netbuf2sd(buf: PNetBuf; sd: SYS_FILE; len: Integer): Integer; cdecl;

{*****************************************************************************}
{* From session.h                                                             }
{*****************************************************************************}
{
  Deals with virtual sessions

  A session is the time between when a client connects and when it
  disconnects. Several requests may be handled in one session.
}

{* ------------------------------ Structures ------------------------------ *}

const
  SESSION_HASHSIZE = 5;

type
  PSession = ^TSession;
  TSession = record
    {* Client-specific information *}
    client: PPblock;
    csd: SYS_NETFD;
    inbuf: PNetBuf;
    csd_open: Integer;
    iaddr: TInAddr;
    pool: PPoolHandle;
    clauth: Pointer;   {* ACL client authentication information *}
  end;
  Session = TSession;

{* ------------------------------ Prototypes ------------------------------ *}

{
  session_create creates a new request structure for the client with the
  given socket descriptor and sockaddr.
}
function session_create(csd: SYS_NETFD; sac: PSockAddrIn): PSession; cdecl;

{
  session_free frees the given session
}
procedure session_free(sn: PSession);

{
  session_dns returns the DNS hostname of the client of this session,
  and inserts it into the client pblock. Returns NULL if unavailable.
}
function session_dns(sn: PSession): PChar;

{
  session_maxdns looks up a hostname from an IP address, and then verifies
  that the host is really who they claim to be.
}
function session_maxdns(sn: PSession): PChar;

function session_dns_lookup(sn: PSession; verify: BOOL): PChar; cdecl;

{*****************************************************************************}
{* From cinfo.h                                                               }
{*****************************************************************************}
{
  Content Information for a file, i.e. its type, etc.
}

{* ------------------------------ Constants ------------------------------- *}

{
  This will be the first string in the file, followed by x.x version
  where x is an integer.

  Updated due to trendy name change
}
const
  MCC_MT_MAGIC = '#--Mosaic Communications Corporation MIME Information';
  MCC_MT_MAGIC_LEN = 53;
  NCC_MT_MAGIC = '#--Netscape Communications Corporation MIME Information';
  NCC_MT_MAGIC_LEN = 55;

{* The character which separates extensions with cinfo_find *}

  CINFO_SEPARATOR = '.';

{* The maximum length of a line in this file *}

  CINFO_MAX_LEN = 1024;

{* The hash table size for that function *}
  CINFO_HASHSIZE = 27;

{* The hash function for the database. Hashed on extension. *}
function CINFO_HASH(s: PChar): Char;

{* ------------------------------ Structures ------------------------------ *}
{
  The ContentInfo structure.

  Currently, we support the following attributes:

  1. Type: This identifies what kind of data is in the file.
  2. Encoding: Identifies any compression or otherwise content-independent
     transformation which has been applied to the file (uuencode, etc.)
  3. Language: Identifies the language a text document is in.
  4. Description: A text string describing the file.
  5. Viewer: The program to use to view the file.

  Multiple items are separated with a comma, e.g.
  encoding="x-gzip, x-uuencode"
}

type
  PCInfo = ^TCInfo;
  TCInfo = record
    ctype: PChar;
    encoding: PChar;
    language: PChar;
  end;
  cinfo = TCInfo;

{* ------------------------------ Prototypes ------------------------------ *}

{
  cinfo_init initializes the content info system. Call this before
  cinfo_merge.
}
procedure cinfo_init; cdecl;

{
  cinfo_terminate frees the database for shutdown.
}
procedure cinfo_terminate; cdecl;

{
  cinfo_merge merges the contents of the given filename with the current
  cinfo database. It returns NULL upon success and a string (which you
  must deallocate) upon error.
}
function cinfo_merge(fn: PChar): PChar; cdecl;

{
  cinfo_find finds any content information for the given uri. The file name
  is the string following the last / in the uri. Multiple extensions are
  separated by CINFO_SEPARATOR. You may pass in a filename instead of uri.

  Returns a newly allocated cinfo structure with the information it
  finds. The elements of this structure are coming right out of the types
  database and so if you change it or want to keep it around for long you
  should strdup it. You should free only the structure itself when finished
  with it.

  If there is no information for any one of the extensions it
  finds, it will ignore that extension. If it cannot find information for
  any of the extensions, it will return NULL.
}
function cinfo_find(uri: PChar): PCInfo; cdecl;

{
  cinfo_lookup finds the information about the given content-type, and
  returns a cinfo structure so you can look up description and icon.
}
function cinfo_lookup(ctype: PChar): PCInfo; cdecl;

{
  cinfo_dump_database dumps the current database to the given file desc.
}
{!!! requires C RTL _iobuf or FILE }
// NSAPI_PUBLIC void cinfo_dump_database(FILE *dump);

{*****************************************************************************}
{* From ereport.h                                                             }
{*****************************************************************************}
{
  Records transactions, reports errors to administrators, etc.
}

{* ------------------------------ Constants ------------------------------- *}

const
{
  The maximum length of an error message. NOT RUN-TIME CHECKED
}
  MAX_ERROR_LEN = 8192;

{* A warning is a minor mishap, such as a 404 being issued. *}
  LOG_WARN = 0;

{
  A misconfig is when there is a syntax error or permission violation in
  a config. file.
}
  LOG_MISCONFIG = 1;

{
  Security warnings are issued when authentication fails, or a host is
  given a 403 return code.
}
  LOG_SECURITY = 2;

{
  A failure is when a request could not be fulfilled due to an internal
  problem, such as a CGI script exiting prematurely, or a filesystem
  permissions problem.
}
  LOG_FAILURE = 3;

{
  A catastrophe is a fatal server error such as running out of
  memory or processes, or a system call failing, or even a server crash.
  The server child cannot recover from a catastrophe.
}
  LOG_CATASTROPHE = 4;

{
  Informational message, of no concern.
}
  LOG_INFORM = 5;

{
  The time format to use in the error log
}
  ERR_TIMEFMT = '[%d/%b/%Y:%H:%M:%S]';


{* The fd you will get if you are reporting errors to SYSLOG *}

  ERRORS_TO_SYSLOG = -1;

{* ------------------------------ Prototypes ------------------------------ *}

{
  ereport logs an error of the given degree and formats the arguments with
  the printf() style fmt. Returns whether the log was successful. Records
  the current date.
}
{!!! require C/C++ varargs support !!!}
//NSAPI_PUBLIC int ereport(int degree, char *fmt, ...);

{
  ereport_init initializes the error logging subsystem and opens the static
  file descriptors. It returns NULL upon success and an error string upon
  error. If a userpw is given, the logs will be chowned to that user.

  email is the address of a person to mail upon catastrophic error. It
  can be NULL if no e-mail is desired. ereport_init will not duplicate
  its own copy of this string; you must make sure it stays around and free
  it when you shut down the server.
}
function ereport_init(err_fn, email: PChar; var pw: PASSWD): PChar; cdecl;

{
  log_terminate closes the error and common log file descriptors.
}
procedure ereport_terminate; cdecl;

{* For restarts *}
function ereport_getfd: SYS_FILE; cdecl;

{*****************************************************************************}
{* From shexp.h                                                               }
{*****************************************************************************}
{
  Defines and prototypes for shell exp. match routines


  This routine will match a string with a shell expression. The expressions
  accepted are based loosely on the expressions accepted by zsh.

  o * matches anything
  o ? matches one character
  o \ will escape a special character
  o $ matches the end of the string
  o [abc] matches one occurence of a, b, or c. The only character that needs
          to be escaped in this is ], all others are not special.
  o [a-z] matches any character between a and z
  o [^az] matches any character except a or z
  o ~ followed by another shell expression will remove any pattern
      matching the shell expression from the match list
  o (foo|bar) will match either the substring foo, or the substring bar.
              These can be shell expressions as well.

  The public interface to these routines is documented below.
}

{* --------------------------- Public routines ---------------------------- *}

{
  shexp_valid takes a shell expression exp as input. It returns:

   NON_SXP      if exp is a standard string
   INVALID_SXP  if exp is a shell expression, but invalid
   VALID_SXP    if exp is a valid shell expression
}

const
   NON_SXP = -1;
   INVALID_SXP = -2;
   VALID_SXP = 1;

{* and generic shexp/regexp versions *}
   NON_WILDPAT     = NON_SXP;
   INVALID_WILDPAT = INVALID_SXP;
   VALID_WILDPAT   = VALID_SXP;

{* and regexp versions *}
   NON_REGEXP      = NON_SXP;
   INVALID_REGEXP  = INVALID_SXP;
   VALID_REGEXP    = VALID_SXP;

function shexp_valid(exp: PChar): Integer; cdecl;

{
  shexp_match

  Takes a prevalidated shell expression exp, and a string str.

  Returns 0 on match and 1 on non-match.
}
function shexp_match(str, exp: PChar): Integer; cdecl;

{
  shexp_cmp

  Same as above, but validates the exp first. 0 on match, 1 on non-match,
  -1 on invalid exp. shexp_casecmp does the same thing but is case
  insensitive.
}
function shexp_cmp(str, exp: PChar): Integer; cdecl;
function shexp_casecmp(str, exp: PChar): Integer; cdecl;

{*****************************************************************************}
{* From shmem.h                                                               }
{*****************************************************************************}
{
  Portable abstraction for memory shared among a server's workers
}

{* --------------------------- Data structures ---------------------------- *}

type
  PShMem = ^TShMem;
  TShMem = record
    data: Pointer;   {* the data *}
    fdmap: THandle;
    size: Integer;   {* the maximum length of the data *}
    name: PChar;     {* internal use: filename to unlink if exposed *}
    fd: SYS_FILE;    {* internal use: file descriptor for region *}
  end;
  shmem_s = TShMem;

{* ------------------------------ Prototypes ------------------------------ *}

{
  shmem_alloc allocates a region of shared memory of the given size, using
  the given name to avoid conflicts between multiple regions within the
  program. The region will not be automatically grown if its boundaries
  are over-run, use shmem_realloc for that.

  If expose is non-zero and the underlying system supports it, the
  file used to create the shared region will be visible to other processes
  running on the system.

  name should be unique to the program which calls this routine, otherwise
  conflicts will arise.

  Returns a new shared memory region, with the data element being a
  pointer to the shared memory. This function must be called before any
  daemon workers are spawned, in order for the handle to the shared region
  to be inherited by the children.

  Because of the requirement that the region must be inherited by the
  children, the region cannot be re-allocated with a larger size when
  necessary.
}
function shmem_alloc(name: PChar; size: Integer; expose: BOOL): PShMem; cdecl;

{
  shmem_free de-allocates the specified region of shared memory.
}
procedure shmem_free(region: PShMem); cdecl;

{*****************************************************************************}
{* From systhr.h                                                              }
{*****************************************************************************}
{
  Abstracted threading mechanisms
}

type
  SYS_THREAD = Pointer;
  TSysThreadFunc = procedure (Arg: Pointer) cdecl;

const
  SYS_THREAD_ERROR = nil;
  SYSTHREAD_DEFAULT_PRIORITY = 16;

{
  systhread_start creates a thread with the given priority, will allocate
  a stack of stksz bytes, and calls fn with arg as its argument. stksz
  of zero will allocate a default stack size.

  Returns a new SYS_THREAD pointer on success, SYS_THREAD_ERROR on failure.
  XXX Priorities are system dependent
}
function systhread_start(prio, stksz: Integer; fn: TSysThreadFunc; arg: Pointer): SYS_THREAD; cdecl;

{
  systhread_current returns a pointer to the current thread.
}
function systhread_current: SYS_THREAD;

{
  systhread_yield yields the processor to another thread
}
procedure systhread_yield; cdecl;

{
  systhread_attach makes an existing thread an NSPR thread.
}
function systhread_attach: SYS_THREAD; cdecl;

{
  systhread_terminate terminates the thread that is passed in.
}
procedure systhread_terminate(thr: SYS_THREAD);

{
  systhread_sleep puts the calling thread to sleep for the given number
  of milliseconds.
}
procedure systhread_sleep(milliseconds: Integer); cdecl;

{
  systhread_init initializes the threading system. name is a name for the
  program for debugging.
}
procedure systhread_init(name: PChar); cdecl;

{
  systhread_timerset starts or re-sets the interrupt timer for a thread
  system. This should be considered a suggestion as most systems don't allow
  the timer interval to be changed.
}
procedure systhread_timerset(usec: Integer); cdecl;

{
  newkey allocates a new integer id for thread-private data. Use this
  key to identify a variable which you want to appear differently
  between threads, and then use setdata to associate a value with this
  key for each thread.
}
function systhread_newkey: Integer; cdecl;

{
  Get data that has been previously associated with key in this thread.
  Returns NULL if setkey has not been called with this key by this
  thread previously, or the data that was previously used with setkey
  by this thread with this key.
}
function systhread_getdata(key: Integer): Pointer; cdecl;

{
  Associate data with the given key number in this thread.
}
procedure systhread_setdata(key: Integer; data: Pointer); cdecl;

{*****************************************************************************}
{* From daemon.h                                                              }
{*****************************************************************************}
{
  Things related to the accepting connections
}

{* ------------------------------- Defines -------------------------------- *}

// NSAPI_PUBLIC void child_exit(int status);

const
{* Codes for child_status *}
  CHILD_EMPTY_SLOT = $fe;
  CHILD_AWAIT_CONNECT = $ff;
  CHILD_PROCESSING = $00;
  CHILD_READING = $01;
  CHILD_WRITING = $02;
  CHILD_RESOLVING = $03;
{* Need completors to handle async IO *}
  CHILD_DONE_PROCESSING = $14;
  CHILD_DONE_READING = $15;
  CHILD_DONE_WRITING = $16;
  CHILD_DONE_RESOLVING = $17;

  MAX_IP_DOMAINS = 256;

type
  PMultipleDomains = ^TMultipleDomains;
  TMultipleDomains = record
	address: PChar;
	docroot: PChar;
	sd: SYS_NETFD;
	threads: Integer;
	AddressNumber: Integer;
  end;
  multiple_domains = TMultipleDomains;

  TChildCallback = procedure (sn: PSession) cdecl;
  TRotateCallback = procedure cdecl;
  TRCBack = procedure (Param: Integer) cdecl;

  PDaemon = ^TDaemon;
  TDaemon = record
    ipstr: PChar;
    port: Integer;
    child_callback: TChildCallback;
    rotate_callback: TRotateCallback;
    servid: PChar;
    domains: PMultipleDomains;
    rcback: TRCBack;
    maxprocs: Integer;
    minprocs: Integer;
    proclife: Integer;
    maxthreads: Integer;
    minthreads: Integer;
{$ifdef NET_SSL}
    char *secure_keyfn;
    char *secure_certfn;
    int secure_auth;
    int secure_session_timeout;
    long ssl3_secure_session_timeout;
    int security;
    int ssl3;
    int ssl2;
{$endif}
  end;
  daemon_s = TDaemon;

{* ------------------------------ Prototypes ------------------------------ *}

{
  daemon_run accepts whether or not it should detach from its parent process,
  and a daemon structure as its arguments. The daemon structure contains
  a port number, a root directory to chroot to (can be NULL), a filename to
  log the daemon pid to (can be NULL). daemon_run never returns.

  child_callback is a function which will be called every time a new
  connection is recieved. Session is a new session ID.

  rcback is a function which is a restart function: When SIGHUP is received,
  this function will be called. You may give SIG_DFL if you don't want to
  support restarting. The rcback will be passed SIGHUP.

  pw is the passwd entry to run the daemon as. If the effective user id is
  root, daemon_run will try to set its uid and gid to the user pointed
  to by this structure. You may pass NULL.
}
procedure _ntdaemon_run(Param: Pointer); cdecl;

{
  daemon_atrestart registers a function to be called fn, with the given
  void pointer as an argument, when the server is restarted.
}
procedure daemon_atrestart(fn: TDaemonAtRestart; data: Pointer); cdecl;

{
  fork is a wrapper for the system's fork function. This closes the listen
  socket for the mob. This also makes sure that a threaded daemon only gets
  the calling thread and not all of them.
}
function child_fork: pid_t;

{* servssl_init is in base/servssl.c *}
{$ifdef NET_SSL}
procedure servssl_init(keyfn, certfn: PChar; stimeout: Integer; ssl3timeout: Longint;
  servid: PChar); cdecl;
{$endif NET_SSL}

{*****************************************************************************}
{* From util.h                                                                }
{*****************************************************************************}
{
  A hodge podge of utility functions and standard functions which
  are unavailable on certain systems
}

{* ------------------------------ Prototypes ------------------------------ *}


{
  getline scans in buf until it finds a LF or CRLF, storing the string in
  l. It will terminate the string and return:

   0 when done, with the scanned line (minus CR or LF) in l
   1 upon EOF, with the scanned line (minus CR or LF) in l
  -1 on error with the error description in l (uses lineno for information)
}
function util_getline(buf: PFileBuffer; lineno, maxlen: Integer; l: PChar): Integer; cdecl;

{
  env_create creates a new environment with the given env, with n new
  entries, and places the current position that you should add your
  entries with at pos.

  If env is NULL, it will allocate a new one. If not, it will reallocate
  that one.
}
function util_env_create(env: PPCharArray; n: Integer; var pos: Integer): PPCharArray; cdecl;

{
  util_env_str allocates a string from the given name and value and
  returns it. It does not check for things like = signs in name.
}
function util_env_str(name, value: PChar): PChar; cdecl;

{
  env_replace replaces the occurrence of the given variable with the
  value you give.
}
procedure util_env_replace(env: PPCharArray; name, value: PChar); cdecl;

{
  util_env_free frees an environment.
}
procedure util_env_free(env: PPCharArray); cdecl;

{
  util_env_copy copies an env
}
function util_env_copy(src, dst: PPCharArray): PPCharArray; cdecl;

{
  util_env_find looks through env for the named string. Returns the
  corresponding value if the named string is found, or NULL if not.
}
function util_env_find(env: PPCharArray; name: PChar): PChar; cdecl;

{
  hostname gets the local hostname. Returns NULL if it can't find a FQDN.
  You are free to realloc or free this string.
}
function util_hostname: PChar; cdecl;

{
  chdir2path changes the current directory to the one that the file
  path is in. path should point to a file. Caveat: path must be a writable
  string. It won't get modified permanently.
}
function util_chdir2path(path: PChar): Integer;

{
  is_mozilla checks if the given user-agent is mozilla, of at least
  the given major and minor revisions. These are strings to avoid
  ambiguities like 1.56 > 1.5
}
function util_is_mozilla(ua, major, minor: PChar): BOOL; cdecl;

{
  is_url will return 1 if the given string seems to be a URL, or will
  return 0 otherwise.

  Because of stupid news URLs, this will return 1 if the string has
  all alphabetic characters up to the first colon and will not check for
  the double slash.
}
function util_is_url(url: PChar): BOOL; cdecl;

{
  util_later_than checks the date in the string ims, and if that date is
  later than or equal to the one in the tm struct lms, then it returns 1.

  util_time_equal is above, but checks for exact equality.

  Handles RFC 822, 850, and ctime formats.
}

function util_later_than(var lms: tm; ims: PChar): BOOL; cdecl;
function util_time_equal(var lms: tm; ims: PChar): BOOL; cdecl;

{
  util_str_time_equal checks the character-string dates are equal.
  Supports rfc1123 and rfc850 formats.  t1 must be rfc1123
  Returns 0 if equal, -1 otherwise
}
function util_str_time_equal(t1, t2: PChar): Integer; cdecl;

{
  util_uri_is_evil returns 1 if a URL has ../ or // in it.
}
function util_uri_is_evil(t: PChar): BOOL; cdecl;

{
  util_uri_parse gets rid of /../, /./, and //.

  Assumes that either the string starts with a /, or the string will
  not .. right off of its beginning.  As such, ../foo.gif will
  not be changed, although /../foo.gif will become /foo.gif.
}
procedure util_uri_parse(uri: PChar); cdecl;

{
  util_uri_unescape unescapes the given URI in place (% conversions only).
}
procedure util_uri_unescape(s: PChar); cdecl;

{
  util_uri_escape escapes any nasty chars in s and copies the string into d.
  If d is NULL, it will allocate and return a properly sized string.
  Warning: does not check bounds on a given d.

  util_url_escape does the same thing but does it for a url, i.e. ?:+ is
  not escaped.
}
function util_uri_escape(d, s: PChar): PChar; cdecl;
function util_url_escape(d, s: PChar): PChar; cdecl;

{
  util_sh_escape places a \ in front of any shell-special characters.
  Returns a newly-allocated copy of the string.
}
function util_sh_escape(s: PChar): PChar cdecl;

{
  util_mime_separator generates a new MIME separator into the given buffer.
  The buffer should be more than 4 + 3*10 + 1 bytes long. A CRLF is prepended
  to the beginning of the string, along with two dashes. The string is null
  terminated, with no CRLF. The intent is that you create your content-type
  header by accessing &sep[4], and afterwards print sep followed by CRLF
  for message boundaries.

  Returns the length of the string.
}
function util_mime_separator(sep: PChar): Integer;

{
  util_itoa converts the given integer to a string into a.
}
function util_itoa(i: Integer; a: PChar): Integer;

{
  util_vsprintf and util_sprintf are simplified clones of the System V
  vsprintf and sprintf routines.

  Returns the number of characters printed. Only handles %d and %s,
  does not handle any width or precision.
}
{!!! requires vararg support !!!
#include <stdarg.h>

NSAPI_PUBLIC int util_vsprintf(char *s, register char *fmt, va_list args);
NSAPI_PUBLIC int util_sprintf(char *s, char *fmt, ...);

/* These routines perform bounds checks. */
NSAPI_PUBLIC int util_vsnprintf(char *s, int n, register char *fmt,
                                va_list args);
NSAPI_PUBLIC int util_snprintf(char *s, int n, char *fmt, ...);
}

{ util_delete_directory()
  This routine deletes all the files in a directory.  If delete_directory is
  TRUE it will also delete the directory itself.
}
procedure util_delete_directory(FileName: PChar; delete_directory: BOOL); cdecl;

{ util_strftime()
  Thread safe version of strftime.
  No bounds checking is done s.  t must be a valid tm structure.
}
function util_strftime(s: PChar; format: PChar; var t: tm): Integer; cdecl;

{*****************************************************************************}
{* From object.h                                                              }
{*****************************************************************************}
{
  Handle httpd objects

  Manages information about a document from config. files. Called mainly
  by objset.c.

  This module does not assume anything about the directives being parsed.
  That is handled by objset.c.

  This module requires the pblock module from the base library.
}

{* ------------------------------ Structures ------------------------------ *}

{
  Hierarchy of httpd_object

  An object contains dtables.

  Each dtable is a table of directives that were entered of a certain type.
  There is one dtable for each unique type of directive.

  Each dtable contains an array of directives, each of which is equivalent
  to one directive that occurred in a config. file.

  It is up to the caller to determine how many dtables will be allocated
  and to keep track of which of their directive types maps to which dtable
  number.
}

type
{
  directive is a structure containing the protection and parameters to an
  instance of a directive within an httpd_object.

  param is the parameters, client is the protection.
}
  PDirective = ^TDirective;
  TDirective = record
    param: PPblock;
    client: PPblock;
  end;
  directive = TDirective;

{
  dtable is a structure for creating tables of directives
}
  PDtable = ^TDtable;
  TDtable = record
    ni: Integer;
    inst: PDirective;
  end;
  dtable = TDtable;

{
  The httpd_object structure.

  The name pblock array contains the names for this object, such as its
  virtual location, its physical location, or its identifier.

  tmpl contains any templates allocated to this object.
}
  PHttpdObject = ^THttpdObject;
  THttpdObject = record
    name: PPblock;
    nd: Integer;
    dt: PDtable;
  end;
  httpd_object = THttpdObject;

{* ------------------------------ Prototypes ------------------------------ *}

{
  object_create will create a new object and return a pointer to it.
  It will allocate space for nd directive types and set name accordingly.
}
function object_create(nd: Integer; name: PPblock): PHttpdObject; cdecl;

{
  object_free will free an object and any data associated with it.
}
procedure object_free(obj: PHttpdObject); cdecl;

{
  object_add_directive will add a new directive to the dtable for
  the directive class at position dc.
}
procedure object_add_directive(dc: Integer; p: PPblock; c: PPblock;
  obj: PHttpdObject); cdecl;

{
  Executes the directive specified by inst within the context of the
  given session and request structures. Returns what the executed function
  returned (one of the REQ_* codes defined in req.h).

  This prototype uses void * for Request * in order to avoid including
  all of req.h.
}
function object_execute(inst: PDirective; sn: PSession; rq: Pointer): Integer; cdecl;

{*****************************************************************************}
{* From objset.h                                                              }
{*****************************************************************************}
{
  Handles object sets

  Each object is produced by reading a config file of some form. See the
  server documentation for descriptions of the directives that are
  recognized, what they do, and how they are parsed.

  This module requires the pblock and buffer modules from the base library.
}

{* ------------------------------ Constants ------------------------------- *}

const
{
  The default number of objects to leave room for in an object set,
  and the number of new entries by which to increase the size when that
  room is filled.
}
  OBJSET_INCSIZE = 8;

{
  When parsing config. files, httpd will put a limit on how long
  the parameters to a directive can be (in characters).

  Currently set to 10 lines (80 chars/line).
}
  MAX_DIRECTIVE_LEN = 800;

{
  The size of the hash tables that store a directive's parameters
}
  PARAMETER_HASH_SIZE = 3;

{* ------------------------------ Structures ------------------------------ *}

{
  httpd_objset is a container for a bunch of objects. obj is a
  NULL-terminated array of objects. pos points to the entry after the last
  one in the array. You should not mess with pos, but can read it to find
  the last entry.

  The initfns array is a NULL-terminated array of the Init functions
  associated with this object set. If there are no Init functions associated
  with this object set, initfns can be NULL. Each pblock specifies the
  parameters which are passed to the function when it's executed.
}

type
  PHttpdObjSet = ^THttpdObjSet;
  THttpdObjSet = record
    pos: Integer;
    obj: ^PHttpdObject;
    initfns: ^PPblock;
  end;
  httpd_objset = THttpdObjSet;

{* ------------------------------ Prototypes ------------------------------ *}


{
  objset_scan_buffer will scan through buffer, looking for object
  configuration information, and adding them to the object set os if it
  finds any. If os is NULL it will allocate a new object set.

  If any error occurs (syntax error, premature EOF) this function will
  free os, print an error message into errstr, and return NULL.
  This is because a config. file error is viewed as a catastrophic error
  from which httpd should not try to recover. If httpd were to continue
  after an error, it would not behave as the admin. expected and he/she
  may not notice until it's too late.

  Upon EOF the file will not be closed.
}
function objset_scan_buffer(buf: PFileBuffer; errstr: PChar;
  os: PHttpdObjSet): PHttpdObjSet; cdecl;

{
  objset_create creates a new object set and returns a pointer to it.
}
function objset_create: PHttpdObjSet; cdecl;

{
  objset_free will free an object set, any associated objects, and any
  associated Init functions.
}
procedure objset_free(os: PHttpdObjSet); cdecl;

{
  objset_free_setonly frees only the object set, and not the associated
  objects or init functions.
}
procedure objset_free_setonly(os: PHttpdObjSet); cdecl;

{
  objset_new_object will add a new object to objset with the specified
  name. It returns a pointer to the new object (which may be anywhere in
  the objset).
}
function objset_new_object(name: PPblock; os: PHttpdObjSet): PHttpdObjSet; cdecl;

{
  objset_add_object will add the existing object to os.
}
procedure objset_add_object(obj: PHttpdObject; os: PHttpdObjSet); cdecl;

{
  objset_add_init will add the initialization function specified by
  initfn to the given object set. Modifies os->initfns.
}
procedure objset_add_init(initfn: PPblock; os: PHttpdObjSet); cdecl;

{
  objset_findbyname will find the object in objset having the given name,
  and return the object if found, and NULL otherwise.
  ign is a set of objects to ignore.
}
function objset_findbyname(name: PChar; ign, os: PHttpdObjSet): PHttpdObject; cdecl;

{
  objset_findbyppath will find the object in objset having the given
  partial path entry. Returns object if found, NULL otherwise.
  ign is a set of objects to ignore.
}
function objset_findbyppath(ppath: Pchar; ign, os: PHttpdObjSet): PHttpdObject; cdecl;

{
  objset_copydirs takes a given objset and copies all of the
  directive in directive set <dir> into a new objset, dst_os.  If
  dst_os is NULL, it creates a new objset.
  The newly created objset only has one object in it.
}
function objset_copydirs(dst_os, os: PHttpdObjSet; dir: Integer): PHttpdObjSet; cdecl;

{* Read the registry configuration parameters into memory *}
function objset_scan_registry(errstr: PChar; os: PHttpdObjSet;
  product_key: PChar): PHttpdObjSet; cdecl;

{* Recursively scan the object key *}

procedure ProcessObject(nos: PHttpdObjSet; hObjectKey: HKEY; Obj: PChar;
  ObjectIndex: DWORD); cdecl;

{* Recursively scan the client key *}

function ProcessClient(cobj: PHttpdObject; hObjectKey: HKEY; Client: PChar;
  ObjectIndex: DWORD): BOOL; cdecl;

{* Recursively scan the directive key *}

function ProcessDirective(cobj: PHttpdObject; param, client: PPblock;
  hObjectKey: HKEY; Directive: PChar; ObjectIndex, DirectiveIndex: DWORD;
  var clrefs: DWORD; IsObject: BOOL): BOOL; cdecl;

{* Recursively scan the function key *}

function ProcessFunction(var param: PPblock; hDirectiveKey: HKEY; Func: PChar;
  ObjectIndex, DirectiveIndex, FunctionIndex: DWORD): BOOL; cdecl;

{* Verify the name value pair *}

function _ntverify_parameter(str: PChar): Integer; cdecl;

{* Enter name value pair into pblock *}
function ntpblock_str2pblock(ParameterIndex: Integer; name, value: PChar;
  namelength, valuelength: Integer; pb: PPblock): Integer; cdecl;

{* Get name value pair from a pblock entry *}
function ntpblock_pblock2str(p: PPbEntry; var ParameterName,
	ParameterValue: PChar): Integer; cdecl;

{* Given a key and its parent, delete the key recursively *}
function ClearConfigurationParameters(hParentKey: HKEY; CompleteKeyName,
  KeyName: PChar): BOOL; cdecl;

{ Look at the hidden file in the server's directory structure to
  figure out the name of this server }
function GetProductKey: PChar; cdecl;

{*****************************************************************************}
{* From conf.h                                                                }
{*****************************************************************************}
{
  conf.h: Deals with the server configuration file.

  Object configuration is an entirely different matter. This deals with
  things like what port the server runs on, how many children it spawns,
  and other server-related issues. Information related configuration is
  handled by the object conf.
}

{* ------------------------------ Constants ------------------------------- *}

const
{* The longest line in the configuration file *}
  CONF_MAXLEN = 16384;
  DEFAULT_PORT = 80;
  DEFAULT_POOL_MAX = 50;

{* ------------------------------- Globals -------------------------------- *}

{
  These server parameters are made global because they really don't
  belong anywhere else.
}

{* These can't be macros because they're used in daemon.h. */
extern char *pidfn;
extern int port;
extern char *chr;

#ifdef NET_SSL
extern char *secure_keyfn;
extern char *secure_certfn;
extern int secure_auth;
#endif}

type
  PConfGlobalVars = ^TConfGlobalVars;
  TConfGlobalVars = record
    {* What port we listen to *}
    Vport: Integer;
    {* What address to bind to *}
    Vaddr: PChar;
    {* User to run as *}
    Vuserpw: PPASSWD;
    {* Directory to chroot to *}
    Vchr: PChar;
    {* Where to log our pid to *}
    Vpidfn: PChar;
    {* The maximum number of processes to keep in the pool *}
    Vpool_max: Integer;
    {* The minimum number of processes to keep in the pool *}
    Vpool_min: Integer;
    {* The maximum number of requests each process should handle. -1=default *}
    Vpool_life: Integer;
    {* For multiprocess UNIX servers, the maximum threads per process *}
    Vpool_maxthreads: Integer;
    {* For multiprocess UNIX servers, the minimum threads per process *}
    Vpool_minthreads: Integer;
{$ifdef NET_SSL}
    Vsecure_keyfn: PChar;
    Vsecure_certfn: PChar;
    Vsecurity_active: Integer;
    Vssl3_active: Integer;
    Vssl2_active: Integer;
    Vsecure_auth: Integer;
    Vsecurity_session_timeout: Integer;
    Vssl3_session_timeout: Longint;
{$endif} {* NET_SSL *}
    {* The server's hostname as should be reported in self-ref URLs *}
    Vserver_hostname: PChar;
    {* The main object from which all are derived *}
    Vroot_object: PChar;
    {* The object set the administrator has asked us to load *}
    Vstd_os: PHttpdObjSet;
    {* The root of ACL data structures *}
    Vacl_root: Pointer;
    {* The main error log, where all errors are logged *}
    Vmaster_error_log: PChar;
    {* The server root ( in which the server sits while executing ) *}
    Vserver_root: PChar;
    {* This server's id *}
    Vserver_id: PChar;
  end;
  conf_global_vars_s = TConfGlobalVars;

function userpw: PPASSWD;
function pool_max: Integer;
function pool_min: Integer;
function pool_life: Integer;
function pool_maxthreads: Integer;
function pool_minthreads: Integer;






function server_hostname: PChar;
function root_object: PChar;
function std_os: PHttpdObjSet;
function acl_root: Pointer;
function master_error_log: PChar;
function server_root: PChar;
function server_id: PChar;

{* ------------------------------ Prototypes ------------------------------ *}

{
  conf_init reads the given configuration file and sets any non-default
  parameters to their given setting.
}
function conf_init(cfn: PChar): PChar; cdecl;

{
  conf_terminate frees any data the conf routines may be holding.
}
procedure conf_terminate; cdecl;

{
  Get a structure with the global variables for this server.
}
function conf_getglobals: PConfGlobalVars; cdecl;

{
  conf_vars2daemon transfers these globals to a daemon structure
}
procedure conf_vars2daemon(d: PDaemon); cdecl;

function GetDomainAddresses(ErrMsg: PChar): BOOL; cdecl;

{*****************************************************************************}
{* From req.h                                                                 }
{*****************************************************************************}
{
  Request-specific data structures and functions
}

{* ------------------------------ Constants ------------------------------- *}

const
  REQ_HASHSIZE = 10;
  REQ_MAX_LINE = 4096;

{
  The REQ_ return codes. These codes are used to determine what the server
  should do after a particular module completes its task.

  Func type functions return these as do many internal functions.
}

{* The function performed its task, proceed with the request *}
  REQ_PROCEED = 0;
{* The entire request should be aborted: An error occurred *}
  REQ_ABORTED = -1;
{* The function performed no task, but proceed anyway. *}
  REQ_NOACTION = -2;
{* Tear down the session and exit *}
  REQ_EXIT = -3;
{* Restart the entire request-response process *}
  REQ_RESTART = -4;


{* ------------------------------ Structures ------------------------------ *}


type
  PRequest = ^TRequest;
  TRequest = record
    {* Server working variables *}
    vars: PPblock;
    {* The method, URI, and protocol revision of this request *}
    reqpb: PPblock;
    {* Protocol specific headers *}
    loadhdrs: Integer;
    headers: PPblock;
    {* Server's response headers *}
    senthdrs: Integer;
    srvhdrs: PPblock;
    {* The object set constructed to fulfill this request *}
    os: PHttpdObjSet;
    {* Array of objects that were created from .nsconfig files *}
    tmpos: PHttpdObjSet;
    {* The stat last returned by request_stat_path *}
    statpath: PChar;
    staterr: PChar;
    finfo: PStat;
    {* access control state *}
    aclstate: Integer;	{* ACL decision state *}
    acldirno: Integer;	{* deciding ACL directive number *}
    aclname: PChar;		{* name of deciding ACL *}
    aclpb: PPblock;     {* parameter block for ACL PathCheck *}
    request_is_cacheable: BOOL;   {* default TRUE *}
    directive_is_cacheable: BOOL; {* default FALSE *}

    cached_headers: PChar;
    cached_headers_len: Integer;  {* length of the valid headers *}
    cached_date_header: PChar;
  end;
  Request = TRequest;

{* ------------------------------ Prototypes ------------------------------ *}

{
  request_create creates a new request structure.
}
function request_create: PRequest; cdecl;

{
  request_free destroys a request structure.
}
procedure request_free(req: PRequest); cdecl;

{
  Restarts a request for a given URI internally. If rq is non-NULL, the
  function will keep the old request's headers and protocol, but with a new
  URI and method of GET. If the previous method was HEAD, this is preserved.
  Any other method becomes GET. You may assume that if you give it a request
  structure that it will use the same structure.

  Once you have this new Request, you must then do what you want with
  it (e.g. send the object back, perform uri2path translation, etc.)
}
function request_restart_internal(uri: PChar; rq: PRequest): PRequest; cdecl;

{
  request_header finds the named header depending on the requesting
  protocol. If possible, it will not load headers until the first is
  requested. You have to watch out because this can return REQ_ABORTED.
}
function request_header(name: PChar; value: PPCharArray; sn: PSession;
  rq: PRequest): Integer; cdecl;

{
  request_loadheaders just makes sure the headers have been loaded.
}
function request_loadheaders(sn: PSession; rq: PRequest): Integer;

{
  request_stat_path tries to stat path. If path is NULL, it will look in
  the vars pblock for "path". If the stat is successful, it returns the stat
  structure. If not, returns NULL and leaves a message in rq->staterr. If a
  previous call to this function was successful, and path is the same, the
  function will simply return the previously found value.

  User functions should not free this structure.
}
function request_stat_path(path: PChar; rq: PRequest): PStat; cdecl;

{
  request_handle handles one request from the session's inbuf.
}
procedure request_handle(sn: PSession); cdecl;

{
  request_translate_uri performs virtual to physical mapping on
  a specified URI during a specified session.
}
function request_translate_uri(uri: PChar; sn: PSession): PChar; cdecl;

(*$HPPEMIT 'namespace Nsapi'*)
(*$HPPEMIT '{'*)
(*$HPPEMIT '    struct TSession;'*)
(*$HPPEMIT '    char *servact_translate_uri(char *uri, TSession *sn);'*)
(*$HPPEMIT '}'*)

(* XXXrobm temporary compatibility */
#define request_uri2path servact_uri2path
#define request_pathchecks servact_pathchecks
#define request_fileinfo servact_fileinfo
#define request_service servact_service

#define request_handle_processed servact_handle_processed
#define request_translate_uri servact_translate_uri
#define request_finderror servact_finderror *)

{*****************************************************************************}
{* From http.h                                                                }
{*****************************************************************************}
{
  Deals with HTTP-related issues
}

{* ------------------------------ Constants ------------------------------- *}

const
  HTTP_DATE_LEN = 128;
  HTTP_DATE_FMT = '%A, %d-%b-%y %H:%M:%S GMT';

{ Number of seconds to allow a second request to come over a persistent
  connection, zero to disable *}
  HTTP_DEFAULT_KEEPALIVE_TIMEOUT = 15;

{* The maximum number of RFC-822 headers we'll allow *}
{* This would be smaller if a certain browser wasn't so damn stupid. *}
  HTTP_MAX_HEADERS = 200;

{* HTTP status codes *}
  PROTOCOL_OK = 200;
  PROTOCOL_CREATED = 201;
  PROTOCOL_NO_RESPONSE = 204;
  PROTOCOL_PARTIAL_CONTENT = 206;
  PROTOCOL_REDIRECT = 302;
  PROTOCOL_NOT_MODIFIED = 304;
  PROTOCOL_BAD_REQUEST = 400;
  PROTOCOL_UNAUTHORIZED = 401;
  PROTOCOL_FORBIDDEN = 403;
  PROTOCOL_NOT_FOUND = 404;
  PROTOCOL_PROXY_UNAUTHORIZED = 407;
  PROTOCOL_SERVER_ERROR = 500;
  PROTOCOL_NOT_IMPLEMENTED = 501;

{$ifdef NET_SSL}
  HTTPS_PORT = 443;
  HTTPS_URL = 'https';
{$endif}
  HTTP_PORT = 80;
  HTTP_URL = 'http';

{* -------------------------- http_scan_headers --------------------------- *}

{
  gets the first line of an HTTP request
}
function protocol_find_request(buf: PNetBuf; sn: PSession; var reply: Integer): PRequest; cdecl;
function http_find_request(buf: PNetBuf; sn: PSession; var reply: Integer): PRequest; cdecl;

{
  parses the first line of an HTTP request
}
function protocol_parse_request(t: PChar; rq: PRequest; sn: PSession): Integer; cdecl;
function http_parse_request(t: PChar; rq: PRequest; sn: PSession): Integer; cdecl;

{
  Scans HTTP headers from the given netbuf, and places them in headers.
  If netbuf is NULL, the session's inbuf is used.

  Folded lines are joined and the linefeed removed (but not the whitespace).
  If there are any repeat headers they are joined and the two field bodies
  separated by a comma and space.

  t should be a string of length REQ_MAX_LINE. This is a convenience to
  req.c so that we don't use too much runtime stack.

  Session is an optional parameter. Use NULL if you wish. It's used for
  error logs.
}
function protocol_scan_headers(sn: PSession; buf: PNetBuf; t: PChar;
  headers: PPblock): Integer; cdecl;
function http_scan_headers(sn: PSession; buf: PNetBuf; t: PChar;
  headers: PPblock): Integer; cdecl;

{
  Starts the HTTP response. If HTTP/0.9, does nothing. If 1.0, sends header.
  If this returns REQ_NOACTION, the method was head and no body should be
  sent. Otherwise, it will return REQ_PROCEED.
}
function protocol_start_response(sn: PSession; rq: PRequest): Integer; cdecl;
function http_start_response(sn: PSession; rq: PRequest): Integer; cdecl;

{
  http_hdrs2env takes the entries from the given pblock and converts them
  to an environment.

  Each name entry will be made uppercase, prefixed with HTTP_ and any
  occurrence of - will be converted to _.
}
function http_hdrs2env(pb: PPblock): PPCharArray; cdecl;

{
  http_status sets status to the code n, with reason string r. If r is
  NULL, the server will attempt to find one for the given status code.
  If it finds none, it will give "Because I felt like it."
}
procedure protocol_status(sn: PSession; rq: PRequest; n: Integer; r: PChar); cdecl;
procedure http_status(sn: PSession; rq: PRequest; n: Integer; r: PChar); cdecl;

{
  http_set_finfo sets content-length and last-modified
}
function protocol_set_finfo(sn: PSession; rq: PRequest; var finfo: TStat): Integer; cdecl;
function http_set_finfo(sn: PSession; rq: PRequest; var finfo: TStat): Integer; cdecl;

{
  Takes the given pblock and prints headers into the given buffer at
  position pos. Returns the buffer, reallocated if needed. Modifies pos.
}
function http_dump822(pb: PPblock; t: PChar; var pos: Integer; tsz: Integer): Pchar; cdecl;

{
  Finishes a request. For HTTP, this just closes the socket.
}
procedure protocol_finish_request(sn: PSession; rq: PRequest); cdecl;
procedure http_finish_request(sn: PSession; rq: PRequest); cdecl;

{
  http_handle_session processes each request generated by Session
}
procedure protocol_handle_session(sn: PSession); cdecl;
procedure http_handle_session(sn: PSession); cdecl;

{
  http_uri2url takes the give URI prefix and URI suffix and creates a
  newly-allocated full URL from them of the form
  http://(server):(port)(prefix)(suffix)

  If you want either prefix or suffix to be skipped, use "" instead of NULL.

  Normally, the server hostname is taken from the ServerName parameter in
  magnus.conf. The newer function http_uri2url_dynamic should be used when
  a Session and Request structure are available, to ensure that the browser
  gets redirected to the exact host they were originally referencing.
}
function protocol_uri2url(prefix, suffix: PChar): PChar; cdecl;
function protocol_uri2url_dynamic(prefix, suffix: PChar; sn: PSession;
  rq: PRequest): PChar; cdecl;
function http_uri2url(prefix, suffix: PChar): PChar; cdecl;
function http_uri2url_dynamic(prefix, suffix: PChar; sn: PSession;
  rq: PRequest): PChar; cdecl;

{
  http_set_keepalive_timeout sets the number of seconds to wait for a new
  request to come from a persistent connection. Returns nothing. Intended
  to be called at server startup only.

  Specifying a timeout of zero will disable persistent connections and allow
  browsers to request only one file per connection.
}
procedure protocol_set_keepalive_timeout(secs: Integer); cdecl;
procedure http_set_keepalive_timeout(secs: Integer); cdecl;

{*****************************************************************************}
{* From func.h                                                                }
{*****************************************************************************}
{
  func.h: Handles the function hash table

  httpd uses a table of internal functions hashed by a name string such that
  users can reference specific functions from the configuration files.

  Any function referenced by configuration files will be passed a
  parameter, a Request structure. The functions do not return anything.
}

{* -------------------------- Structure and Type -------------------------- *}


{
  FuncPtr is a pointer to our kind of functions
}

type
  TFunction = function (pb: PPblock; sn: PSession; rq: PRequest): Integer cdecl;

{
  FuncStruct is a structure used in the static declaration of the
  functions. This static declaration is parsed into a hash table at
  startup. You should initialize the next entry to NULL.
}

  PFuncStruct = ^TFuncStruct;
  TFuncStruct = record
    name: PChar;
    func: TFunction;
    next: PFuncStruct;
  end;

{* --------------------------- Hash definitions --------------------------- *}

{
  This is a primitive hash function. Once more is known about the names of
  the functions, this will be optimized.
}
const
  NUM_HASH = 20;

// #define FUNC_HASH(s) (s[0] % NUM_HASH)

{* ------------------------------ Prototypes ------------------------------ *}

{
  func_init reads the static FuncStruct arrays and creates the global
  function table from them.

  func_init will only read from the static arrays defined in func.c.
}
procedure func_init; cdecl;

{
  func_find returns a pointer to the function named name, or NULL if none
  exists.
}
function func_find(name: PChar): TFunction; cdecl;

{
  func_exec will try to execute the function whose name is the "fn" entry
  in the given pblock. If name is not found, it will log a misconfig of
  missing fn parameter. If it can't find it, it will log that. In these
  cases it will return REQ_ABORTED. Otherwise, it will return what the
  function being executed returns.
}
function func_exec(pb: PPblock; sn: PSession; rq: PRequest): Integer; cdecl;

{
  func_insert dynamically inserts a named function into the server's
  table of functions. Returns the FuncStruct it keeps in internal
  databases, because on server restart you are responsible for freeing
  (or not) its contents.
}
function func_insert(name: PChar; fn: TFunction): PFuncStruct;

function NSstr2String(nsStr: PChar): string;

implementation

uses SysUtils;

const
  nshttp = 'ns-httpd20.dll';

function server_fasttrack: Boolean;
begin
  Result := StrComp(MAGNUS_VERSION_STRING, PERSONAL_VERSION_STRING) = 0;
end;

function server_enterprise: Boolean;
begin
  Result := StrComp(MAGNUS_VERSION_STRING, ENTERPRISE_VERSION_STRING) = 0;
end;

procedure CONVERT_TO_PRINTABLE_FORMAT(Filename: PChar);
var
  S: PChar;
begin
  if Filename = nil then
  begin
    S := FileName;
    while S^ <> #0 do
    begin
      if S^ = '\' then
        S^ := '/';
      Inc(S);
    end;
  end;
end;

procedure CONVERT_TO_NATIVE_FS(Filename: PChar);
var
  S: PChar;
begin
  if Filename = nil then
  begin
    S := FileName;
    while S^ <> #0 do
    begin
      if S^ = '/' then
        S^ := '\';
      Inc(S);
    end;
  end;
end;

function system_rename(Old, New: PChar): BOOL;
begin
  Result := MoveFile(old, new);
end;

function system_unlink(path: PChar): BOOL;
begin
  Result := DeleteFile(path);
end;

function system_lseek(fd: SYS_FILE; off: Longint; wh: Longint): Longint;
begin
  Result := SetFilePointer(fd.fh, Off, nil, wh);
end;

function system_flock(fd: SYS_FILE): Integer;
begin
  Result := sem_grab(fd.flsem);
end;

function system_ulock(fd: SYS_FILE): Integer;
begin
  Result := sem_release(fd.flsem);
end;

function dir_create(Path: PChar): Integer;
begin
  if CreateDirectory(Path, nil) then
    Result := 0
  else Result := -1;
end;

function dir_remove(Path: PChar): Integer;
begin
  if RemoveDirectory(Path) then
    Result := 0
  else Result := -1;
end;

function pblock_find(name: PChar; pb: PPblock): PPbParam;
begin
  Result := _pblock_fr(name,pb,False);
end;

function pblock_remove(name: PChar; pb: PPblock): PPbParam;
begin
  Result := _pblock_fr(name,pb,True);
end;

function netbuf_getc(b: PNetBuf): Integer;
begin
  with b^ do
    if pos <> cursize then
    begin
      Result := Integer(Byte(inbuf[pos]));
      Inc(pos);
    end else Result := netbuf_next(b, 1);
end;

function filebuf_getc(b: PFileBuffer): Integer;
begin
  with b^ do
    if pos = len then
      Result := IO_EOF
    else
    begin
      Result := Integer(Byte(fp[pos]));
      Inc(pos);
    end;
end;

function pipebuf_getc(b: PFileBuffer): Integer;
begin
  with b^ do
    if pos <> cursize then
    begin
      Result := Integer(Byte(inbuf[pos]));
      Inc(pos);
    end else Result := pipebuf_next(b, 1);
end;

function session_dns(sn: PSession): PChar;
begin
  Result := session_dns_lookup(sn, False);
end;

function session_maxdns(sn: PSession): PChar;
begin
  Result := session_dns_lookup(sn, True);
end;

function CINFO_HASH(s: PChar): Char;
begin
  if IsCharAlpha(s[0]) then
    Result := Char(Byte(CharLower(PChar(s[0]))) - Ord('a'))
  else Result := #26;
end;

function request_loadheaders(sn: PSession; rq: PRequest): Integer;
begin
  Result := REQ_PROCEED;
end;

function userpw: PPASSWD;
begin
  Result := conf_getglobals.Vuserpw;
end;

function pool_max: Integer;
begin
  Result := conf_getglobals.Vpool_max;
end;

function pool_min: Integer;
begin
  Result := conf_getglobals.Vpool_min;
end;

function pool_life: Integer;
begin
  Result := conf_getglobals.Vpool_life;
end;

function pool_maxthreads: Integer;
begin
  Result := conf_getglobals.Vpool_maxthreads;
end;

function pool_minthreads: Integer;
begin
  Result := conf_getglobals.Vpool_minthreads;
end;




























function server_hostname: PChar;
begin
  Result := conf_getglobals.Vserver_hostname;
end;

function root_object: PChar;
begin
  Result := conf_getglobals.Vroot_object;
end;

function std_os: PHttpdObjSet;
begin
  Result := conf_getglobals.Vstd_os;
end;

function acl_root: Pointer;
begin
  Result := conf_getglobals.Vacl_root;
end;

function master_error_log: PChar;
begin
  Result := conf_getglobals.Vmaster_error_log;
end;

function server_root: PChar;
begin
  Result := conf_getglobals.Vserver_root;
end;

function server_id: PChar;
begin
  Result := conf_getglobals.Vserver_id;
end;

function NSstr2String(nsStr: PChar): string;
begin
  Result := nsStr;
  system_free(nsStr);
end;

{ imports }

function strcasecmp; external nshttp name 'strcasecmp';
function strncasecmp; external nshttp name 'strncasecmp';
function util_strcasecmp; external nshttp name 'util_strcasecmp';
function util_strncasecmp; external nshttp name 'util_strncasecmp';
function system_version; external nshttp name 'system_version';
function MAGNUS_VERSION_STRING; external nshttp name 'MAGNUS_VERSION_STRING';
procedure system_version_set; external nshttp name 'system_version_set';
function MALLOC; external nshttp name 'system_malloc';
function system_malloc; external nshttp name 'system_malloc';
function CALLOC; external nshttp name 'system_calloc';
function system_calloc; external nshttp name 'system_calloc';
function REALLOC; external nshttp name 'system_realloc';
function system_realloc; external nshttp name 'system_realloc';
procedure FREE; external nshttp name 'system_free';
procedure system_free; external nshttp name 'system_free';
function STRDUP; external nshttp name 'system_strdup';
function system_strdup; external nshttp name 'system_strdup';
function PERM_MALLOC; external nshttp name 'system_malloc_perm';
function system_malloc_perm; external nshttp name 'system_malloc_perm';
function PERM_CALLOC; external nshttp name 'system_calloc_perm';
function system_calloc_perm; external nshttp name 'system_calloc_perm';
function PERM_REALLOC; external nshttp name 'system_realloc_perm';
function system_realloc_perm; external nshttp name 'system_realloc_perm';
procedure PERM_FREE; external nshttp name 'system_free_perm';
procedure system_free_perm; external nshttp name 'system_free_perm';
function PERM_STRDUP; external nshttp name 'system_strdup_perm';
function system_strdup_perm; external nshttp name 'system_strdup_perm';
procedure magnus_atrestart; external nshttp name 'magnus_atrestart';
function pool_create; external nshttp name 'pool_create';
procedure pool_destroy; external nshttp name 'pool_destroy';
function pool_enabled; external nshttp name 'pool_enabled';
function pool_malloc; external nshttp name 'pool_malloc';
procedure pool_free; external nshttp name 'pool_free';
function pool_calloc; external nshttp name 'pool_calloc';
function pool_realloc; external nshttp name 'pool_realloc';
function pool_strdup; external nshttp name 'pool_strdup';
function sem_init; external nshttp name 'sem_init';
procedure sem_terminate; external nshttp name 'sem_terminate';
function sem_grab; external nshttp name 'sem_grab';
function sem_tgrab; external nshttp name 'sem_tgrab';
function sem_release; external nshttp name 'sem_release';
function crit_init; external nshttp name 'crit_init';
procedure crit_enter; external nshttp name 'crit_enter';
procedure crit_exit; external nshttp name 'crit_exit';
procedure crit_terminate; external nshttp name 'crit_terminate';
function condvar_init; external nshttp name 'condvar_init';
procedure condvar_wait; external nshttp name 'condvar_wait';
procedure condvar_notify; external nshttp name 'condvar_notify';
procedure condvar_terminate; external nshttp name 'condvar_terminate';
function system_chdir; external 'kernel32.dll' name 'SetCurrentDirectory';
function system_stat; external nshttp name 'system_stat';
function system_fread; external nshttp name 'system_fread';
function system_pread; external nshttp name 'system_pread';
function system_fopenRO; external nshttp name 'system_fopenRO';
function system_fopenWA; external nshttp name 'system_fopenWA';
function system_fopenRW; external nshttp name 'system_fopenRW';
function system_fopenWT; external nshttp name 'system_fopenWT';
procedure system_fclose; external nshttp name 'system_fclose';
function system_nocoredumps; external nshttp name 'system_nocoredumps';
function system_winsockerr; external nshttp name 'system_winsockerr';
function system_winerr; external nshttp name 'system_winerr';
function system_fwrite; external nshttp name 'system_fwrite';
function system_fwrite_atomic; external nshttp name 'system_fwrite_atomic';
function file_notfound; external nshttp name 'file_notfound';
function system_errmsg; external nshttp name 'system_errmsg_fn';
function system_errmsg_fn; external nshttp name 'system_errmsg_fn';
function system_initlock; external nshttp name 'system_initlock';
function file_setinherit; external nshttp name 'file_setinherit';
procedure file_unix2local; external nshttp name 'file_unix2local';
function dir_open; external nshttp name 'dir_open';
function dir_read; external nshttp name 'dir_read';
procedure dir_close; external nshttp name 'dir_close';
function dir_create_all; external nshttp name 'dir_create_all';
function param_create; external nshttp name 'param_create';
function param_free; external nshttp name 'param_free';
function pblock_create; external nshttp name 'pblock_create';
procedure pblock_free; external nshttp name 'pblock_free';
function pblock_findval; external nshttp name 'pblock_findval';
function pblock_nvinsert; external nshttp name 'pblock_nvinsert';
function pblock_nninsert; external nshttp name 'pblock_nninsert';
procedure pblock_pinsert; external nshttp name 'pblock_pinsert';
function pblock_str2pblock; external nshttp name 'pblock_str2pblock';
function pblock_pblock2str; external nshttp name 'pblock_pblock2str';
procedure pblock_copy; external nshttp name 'pblock_copy';
function pblock_dup; external nshttp name 'pblock_dup';
function pblock_pb2env; external nshttp name 'pblock_pb2env';
function _pblock_fr; external nshttp name '_pblock_fr';
function net_socket; external nshttp name 'net_socket';
function net_getsockopt; external nshttp name 'net_getsockopt';
function net_setsockopt; external nshttp name 'net_setsockopt';
function net_listen; external nshttp name 'net_listen';
function net_create_listener; external nshttp name 'net_create_listener';
function net_select; external nshttp name 'net_select';
function net_connect; external nshttp name 'net_connect';
function net_ioctl; external nshttp name 'net_ioctl';
function net_getpeername; external nshttp name 'net_getpeername';
function net_close; external nshttp name 'net_close';
function net_bind; external nshttp name 'net_bind';
function net_accept; external nshttp name 'net_accept';
function net_read; external nshttp name 'net_read';
function net_write; external nshttp name 'net_write';
function net_isalive; external nshttp name 'net_isalive';
function net_ip2host; external nshttp name 'net_ip2host';
function filebuf_open; external nshttp name 'filebuf_open';
function netbuf_open; external nshttp name 'netbuf_open';
function filebuf_create; external nshttp name 'filebuf_create';
procedure filebuf_close_buffer; external nshttp name 'filebuf_close_buffer';
function filebuf_open_nostat; external nshttp name 'filebuf_open_nostat';
function pipebuf_open; external nshttp name 'pipebuf_open';
function filebuf_next; external nshttp name 'filebuf_next';
function netbuf_next; external nshttp name 'netbuf_next';
function pipebuf_next; external nshttp name 'pipebuf_next';
procedure filebuf_close; external nshttp name 'filebuf_close';
procedure netbuf_close; external nshttp name 'netbuf_close';
procedure pipebuf_close; external nshttp name 'pipebuf_close';
function filebuf_grab; external nshttp name 'filebuf_grab';
function netbuf_grab; external nshttp name 'netbuf_grab';
function pipebuf_grab; external nshttp name 'pipebuf_grab';
function netbuf_buf2sd; external nshttp name 'netbuf_buf2sd';
function filebuf_buf2sd; external nshttp name 'filebuf_buf2sd';
function pipebuf_buf2sd; external nshttp name 'pipebuf_buf2sd';
function pipebuf_netbuf2sd; external nshttp name 'pipebuf_netbuf2sd';
function session_create; external nshttp name 'session_create';
procedure session_free; external nshttp name 'session_free';
function session_dns_lookup; external nshttp name 'session_dns_lookup';
procedure cinfo_init; external nshttp name 'cinfo_init';
procedure cinfo_terminate; external nshttp name 'cinfo_terminate';
function cinfo_merge; external nshttp name 'cinfo_merge';
function cinfo_find; external nshttp name 'cinfo_find';
function cinfo_lookup; external nshttp name 'cinfo_lookup';
function ereport_init; external nshttp name 'ereport_init';
procedure ereport_terminate; external nshttp name 'ereport_terminate';
function ereport_getfd; external nshttp name 'ereport_getfd';
function shexp_valid; external nshttp name 'shexp_valid';
function shexp_match; external nshttp name 'shexp_match';
function shexp_cmp; external nshttp name 'shexp_cmp';
function shexp_casecmp; external nshttp name 'shexp_casecmp';
function shmem_alloc; external nshttp name 'shmem_alloc';
procedure shmem_free; external nshttp name 'shmem_free';
function systhread_start; external nshttp name 'systhread_start';
function systhread_current; external nshttp name 'systhread_current';
procedure systhread_yield; external nshttp name 'systhread_yield';
function systhread_attach; external nshttp name 'systhread_attach';
procedure systhread_terminate; external nshttp name 'systhread_terminate';
procedure systhread_sleep; external nshttp name 'systhread_sleep';
procedure systhread_init; external nshttp name 'systhread_init';
procedure systhread_timerset; external nshttp name 'systhread_timerset';
function systhread_newkey; external nshttp name 'systhread_newkey';
function systhread_getdata; external nshttp name 'systhread_getdata';
procedure systhread_setdata; external nshttp name 'systhread_setdata';
procedure _ntdaemon_run; external nshttp name '_ntdaemon_run';
procedure daemon_atrestart; external nshttp name 'daemon_atrestart';
function child_fork; external nshttp name 'child_fork';
{$ifdef NET_SSL}
procedure servssl_init; external nshttp name 'servssl_init';
{$endif NET_SSL}
function util_getline; external nshttp name 'util_getline';
function util_env_create; external nshttp name 'util_env_create';
function util_env_str; external nshttp name 'util_env_str';
procedure util_env_replace; external nshttp name 'util_env_replace';
procedure util_env_free; external nshttp name 'util_env_free';
function util_env_copy; external nshttp name 'util_env_copy';
function util_env_find; external nshttp name 'util_env_find';
function util_hostname; external nshttp name 'util_hostname';
function util_chdir2path; external nshttp name 'util_chdir2path';
function util_is_mozilla; external nshttp name 'util_is_mozilla';
function util_is_url; external nshttp name 'util_is_url';
function util_later_than; external nshttp name 'util_later_than';
function util_time_equal; external nshttp name 'util_time_equal';
function util_str_time_equal; external nshttp name 'util_str_time_equal';
function util_uri_is_evil; external nshttp name 'util_uri_is_evil';
procedure util_uri_parse; external nshttp name 'util_uri_parse';
procedure util_uri_unescape; external nshttp name 'util_uri_unescape';
function util_uri_escape; external nshttp name 'util_uri_escape';
function util_url_escape; external nshttp name 'util_url_escape';
function util_sh_escape; external nshttp name 'util_sh_escape';
function util_mime_separator; external nshttp name 'util_mime_separator';
function util_itoa; external nshttp name 'util_itoa';
procedure util_delete_directory; external nshttp name 'util_delete_directory';
function util_strftime; external nshttp name 'util_strftime';
function object_create; external nshttp name 'object_create';
procedure object_free; external nshttp name 'object_free';
procedure object_add_directive; external nshttp name 'object_add_directive';
function object_execute; external nshttp name 'object_execute';
function objset_scan_buffer; external nshttp name 'objset_scan_buffer';
function objset_create; external nshttp name 'objset_create';
procedure objset_free; external nshttp name 'objset_free';
procedure objset_free_setonly; external nshttp name 'objset_free_setonly';
function objset_new_object; external nshttp name 'objset_new_object';
procedure objset_add_object; external nshttp name 'objset_add_object';
procedure objset_add_init; external nshttp name 'objset_add_init';
function objset_findbyname; external nshttp name 'objset_findbyname';
function objset_findbyppath; external nshttp name 'objset_findbyppath';
function objset_copydirs; external nshttp name 'objset_copydirs';
function objset_scan_registry; external nshttp name 'objset_scan_registry';
procedure ProcessObject; external nshttp name 'ProcessObject';
function ProcessClient; external nshttp name 'ProcessClient';
function ProcessDirective; external nshttp name 'ProcessDirective';
function ProcessFunction; external nshttp name 'ProcessFunction';
function _ntverify_parameter; external nshttp name '_ntverify_parameter';
function ntpblock_str2pblock; external nshttp name 'ntpblock_str2pblock';
function ntpblock_pblock2str; external nshttp name 'ntpblock_pblock2str';
function ClearConfigurationParameters; external nshttp name 'ClearConfigurationParameters';
function GetProductKey; external nshttp name 'GetProductKey';
function conf_init; external nshttp name 'conf_init';
procedure conf_terminate; external nshttp name 'conf_terminate';
function conf_getglobals; external nshttp name 'conf_getglobals';
procedure conf_vars2daemon; external nshttp name 'conf_vars2daemon';
function GetDomainAddresses; external nshttp name 'GetDomainAddresses';
function request_create; external nshttp name 'request_create';
procedure request_free; external nshttp name 'request_free';
function request_restart_internal; external nshttp name 'request_restart_internal';
function request_header; external nshttp name 'request_header';
function request_stat_path; external nshttp name 'request_stat_path';
procedure request_handle; external nshttp name 'request_handle';
function request_translate_uri; external nshttp name 'servact_translate_uri';
function protocol_find_request; external nshttp name 'http_find_request';
function http_find_request; external nshttp name 'http_find_request';
function protocol_parse_request; external nshttp name 'http_parse_request';
function http_parse_request; external nshttp name 'http_parse_request';
function protocol_scan_headers; external nshttp name 'http_scan_headers';
function http_scan_headers; external nshttp name 'http_scan_headers';
function protocol_start_response; external nshttp name 'http_start_response';
function http_start_response; external nshttp name 'http_start_response';
function http_hdrs2env; external nshttp name 'http_hdrs2env';
procedure protocol_status; external nshttp name 'http_status';
procedure http_status; external nshttp name 'http_status';
function protocol_set_finfo; external nshttp name 'http_set_finfo';
function http_set_finfo; external nshttp name 'http_set_finfo';
function http_dump822; external nshttp name 'http_dump822';
procedure protocol_finish_request; external nshttp name 'http_finish_request';
procedure http_finish_request; external nshttp name 'http_finish_request';
procedure protocol_handle_session; external nshttp name 'http_handle_session';
procedure http_handle_session; external nshttp name 'http_handle_session';
function protocol_uri2url; external nshttp name 'http_uri2url';
function protocol_uri2url_dynamic; external nshttp name 'http_uri2url_dynamic';
function http_uri2url; external nshttp name 'http_uri2url';
function http_uri2url_dynamic; external nshttp name 'http_uri2url_dynamic';
procedure protocol_set_keepalive_timeout; external nshttp name 'http_set_keepalive_timeout';
procedure http_set_keepalive_timeout; external nshttp name 'http_set_keepalive_timeout';
procedure func_init; external nshttp name 'func_init';
function func_find; external nshttp name 'func_find';
function func_exec; external nshttp name 'func_exec';
function func_insert; external nshttp name 'func_insert';

end.
