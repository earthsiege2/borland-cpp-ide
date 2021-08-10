{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ This unit is a pascal wrapper for the Apache interface header files. Those  }
{ files were released under the following copyright:                          }
{                                                                             }
{ ====================================================================        }
{ Copyright (c) 1995-2000 The Apache Group.  All rights reserved.             }
{                                                                             }
{ Redistribution and use in source and binary forms, with or without          }
{ modification, are permitted provided that the following conditions          }
{ are met:                                                                    }
{                                                                             }
{ 1. Redistributions of source code must retain the above copyright           }
{    notice, this list of conditions and the following disclaimer.            }
{                                                                             }
{ 2. Redistributions in binary form must reproduce the above copyright        }
{    notice, this list of conditions and the following disclaimer in          }
{    the documentation and/or other materials provided with the               }
{    distribution.                                                            }
{                                                                             }
{ 3. All advertising materials mentioning features or use of this             }
{   software must display the following acknowledgment:                       }
{    "This product includes software developed by the Apache Group            }
{    for use in the Apache HTTP server project http://httpd.apache.org/       }
{                                                                             }
{ 4. The names "Apache Server" and "Apache Group" must not be used to         }
{    endorse or promote products derived from this software without           }
{    prior written permission. For written permission, please contact         }
{    apache@apache.org.                                                       }
{                                                                             }
{ 5. Products derived from this software may not be called "Apache"           }
{    nor may "Apache" appear in their names without prior written             }
{    permission of the Apache Group.                                          }
{                                                                             }
{ 6. Redistributions of any form whatsoever must retain the following         }
{     acknowledgment:                                                         }
{    "This product includes software developed by the Apache Group            }
{    for use in the Apache HTTP server project (http://httpd.apache.org       }
{                                                                             }
{ THIS SOFTWARE IS PROVIDED BY THE APACHE GROUP ``AS IS'' AND ANY             }
{ EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE         }
{ IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR          }
{ PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE APACHE GROUP OR              }
{ ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,            }
{ SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT                }
{ NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                }
{ LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)                    }
{ HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,         }
{ STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)               }
{ ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED         }
{ OF THE POSSIBILITY OF SUCH DAMAGE.                                          }
{ ====================================================================        }
{                                                                             }
{ This software consists of voluntary contributions made by many              }
{ individuals on behalf of the Apache Group and was originally based          }
{ on public domain software written at the National Center for                }
{ Supercomputing Applications, University of Illinois, Urbana-Champaign.      }
{ For more information on the Apache Group and the Apache HTTP server         }
{ project, please see <http://www.apache.org/>.                               }
{                                                                             }
{ *************************************************************************** }

unit HTTPD;

{ Pull in importlib for ApacheCore.dll }
(*$HPPEMIT '#if defined(__WIN32__)'         *)
(*$HPPEMIT '#pragma link "ApacheCore.lib"'  *)
(*$HPPEMIT '#endif'                         *)

interface

{$IFDEF MSWINDOWS}
uses WinSock;
{$ENDIF}
{$IFDEF Linux}
uses Libc;
{$ENDIF}

const

//* ----------------------------- config dir ------------------------------ */

//* Define this to be the default server home dir. Most things later in this
//* file with a relative pathname will have this added.
//*
//* The target name of the installed Apache */
{$IFDEF MSWINDOWS}
  ApacheCore = 'ApacheCore.dll'; {do not localize}
//  HTTPD_ROOT = '/apache'; {do not localize}
  TARGET = 'apache';  {do not localize}
{$ENDIF}

{$IFDEF LINUX}
  ApacheCore = 'libhttpd.so'; {do not localize}
//  HTTPD_ROOT = '/usr/local/apache';  {do not localize}
  TARGET = 'httpd';   {do not localize}
{$ENDIF}

//* Default location of documents. Can be overridden by the DocumentRoot directive
//  DOCUMENT_LOCATION = HTTPD_ROOT + '/htdocs';  {do not localize}

//* Max. number of dynamically loaded modules */
  DYNAMIC_MODULE_LIMIT = 64;

//* Default administrator's address */
  DEFAULT_ADMIN = '[no address given]';  {do not localize}

//* Initializer for the first few module slots, which are only
// * really set up once we start running.  Note that the first two slots
// * provide a version check; this should allow us to deal with changes to
// * the API. The major number should reflect changes to the API handler table
// * itself or removal of functionality. The minor number should reflect
// * additions of functionality to the existing API. (the server can detect
// * an old-format module, and either handle it back-compatibly, or at least
// * signal an error). See src/include/ap_mmn.h for MMN version history.
// */

  MODULE_MAGIC_COOKIE = $41503133;                 ///* "AP13" */
  MODULE_MAGIC_NUMBER_MAJOR = 19990320;
  MODULE_MAGIC_NUMBER_MINOR = 6;                   ///* 0...n */
  MODULE_MAGIC_NUMBER = MODULE_MAGIC_NUMBER_MAJOR; ///* backward compat */

// STANDARD_MODULE_STUFF
// must appear in all module records.
//    version := MODULE_MAGIC_NUMBER_MAJOR;
//    minor_version := MODULE_MAGIC_NUMBER_MINOR;
//    module_index := -1;
//    name := __FILE__;
//    dynamic_load_handle := nil;
//    next := nil;
//    magic := MODULE_MAGIC_COOKIE;

///* Numeric release version identifier: MMNNFFRBB: major minor fix final beta
// * Always increases along the same track as the source branch.
// * For example, Apache 1.4.2 would be '10402100', 2.5b7 would be '20500007'.
// */

  APACHE_RELEASE = 10309100;
  SERVER_PROTOCOL = 'HTTP/1.1';  {do not localize}

  AP_DECLINED = -1;             ///* Module declines to handle */
  AP_DONE = -2;			///* Module has served the response completely
				// *  - it's safe to die() with no more output
				// */
  AP_OK = 0;			///* Module has handled this stage. */

// Constants for reading client input

  REQUEST_NO_BODY  = 0;
  REQUEST_CHUNKED_ERROR = 1;
  REQUEST_CHUNKED_DECHUNK = 2;
  REQUEST_CHUNKED_PASS = 3;

///* Methods recognized (but not necessarily handled) by the server.
// * These constants are used in bit shifting masks of size int, so it is
// * unsafe to have more methods than bits in an int.  HEAD == M_GET.
// */
  M_GET        = 0;
  M_PUT        = 1;
  M_POST       = 2;
  M_DELETE     = 3;
  M_CONNECT    = 4;
  M_OPTIONS    = 5;
  M_TRACE      = 6;
  M_PATCH      = 7;
  M_PROPFIND   = 8;
  M_PROPPATCH  = 9;
  M_MKCOL      = 10;
  M_COPY       = 11;
  M_MOVE       = 12;
  M_LOCK       = 13;
  M_UNLOCK     = 14;
  M_INVALID    = 15;

  METHODS      = 16;

  REMOTE_HOST  = 0;
  REMOTE_NAME  = 1;
  REMOTE_NOLOOKUP = 2;
  REMOTE_DOUBLE_REV = 3;

  CGI_MAGIC_TYPE = 'application/x-httpd-cgi';
  INCLUDES_MAGIC_TYPE = 'text/x-server-parsed-html';
  INCLUDES_MAGIC_TYPE3 = 'text/x-server-parsed-html3';
  MAP_FILE_MAGIC_TYPE = 'application/x-type-map';
  ASIS_MAGIC_TYPE = 'httpd/send-as-is';
  DIR_MAGIC_TYPE = 'httpd/unix-directory';
  STATUS_MAGIC_TYPE = 'application/x-httpd-status';

///* ----------------------- HTTP Status Codes  ------------------------- */

///* The size of the static array in http_protocol.c for storing
// * all of the potential response status-lines (a sparse table).
// * A future version should dynamically generate the table at startup.
// */

  RESPONSE_CODES = 55;

  HTTP_CONTINUE                      = 100;
  HTTP_SWITCHING_PROTOCOLS           = 101;
  HTTP_PROCESSING                    = 102;
  HTTP_OK                            = 200;
  HTTP_CREATED                       = 201;
  HTTP_ACCEPTED                      = 202;
  HTTP_NON_AUTHORITATIVE             = 203;
  HTTP_NO_CONTENT                    = 204;
  HTTP_RESET_CONTENT                 = 205;
  HTTP_PARTIAL_CONTENT               = 206;
  HTTP_MULTI_STATUS                  = 207;
  HTTP_MULTIPLE_CHOICES              = 300;
  HTTP_MOVED_PERMANENTLY             = 301;
  HTTP_MOVED_TEMPORARILY             = 302;
  HTTP_SEE_OTHER                     = 303;
  HTTP_NOT_MODIFIED                  = 304;
  HTTP_USE_PROXY                     = 305;
  HTTP_TEMPORARY_REDIRECT            = 307;
  HTTP_BAD_REQUEST                   = 400;
  HTTP_UNAUTHORIZED                  = 401;
  HTTP_PAYMENT_REQUIRED              = 402;
  HTTP_FORBIDDEN                     = 403;
  HTTP_NOT_FOUND                     = 404;
  HTTP_METHOD_NOT_ALLOWED            = 405;
  HTTP_NOT_ACCEPTABLE                = 406;
  HTTP_PROXY_AUTHENTICATION_REQUIRED = 407;
  HTTP_REQUEST_TIME_OUT              = 408;
  HTTP_CONFLICT                      = 409;
  HTTP_GONE                          = 410;
  HTTP_LENGTH_REQUIRED               = 411;
  HTTP_PRECONDITION_FAILED           = 412;
  HTTP_REQUEST_ENTITY_TOO_LARGE      = 413;
  HTTP_REQUEST_URI_TOO_LARGE         = 414;
  HTTP_UNSUPPORTED_MEDIA_TYPE        = 415;
  HTTP_RANGE_NOT_SATISFIABLE         = 416;
  HTTP_EXPECTATION_FAILED            = 417;
  HTTP_UNPROCESSABLE_ENTITY          = 422;
  HTTP_LOCKED                        = 423;
  HTTP_FAILED_DEPENDENCY             = 424;
  HTTP_INTERNAL_SERVER_ERROR         = 500;
  HTTP_NOT_IMPLEMENTED               = 501;
  HTTP_BAD_GATEWAY                   = 502;
  HTTP_SERVICE_UNAVAILABLE           = 503;
  HTTP_GATEWAY_TIME_OUT              = 504;
  HTTP_VERSION_NOT_SUPPORTED         = 505;
  HTTP_VARIANT_ALSO_VARIES           = 506;
  HTTP_INSUFFICIENT_STORAGE          = 507;
  HTTP_NOT_EXTENDED                  = 510;

// backward compatibility codes

  DOCUMENT_FOLLOWS    = HTTP_OK;
  PARTIAL_CONTENT     = HTTP_PARTIAL_CONTENT;
  MULTIPLE_CHOICES    = HTTP_MULTIPLE_CHOICES;
  MOVED               = HTTP_MOVED_PERMANENTLY;
  REDIRECT            = HTTP_MOVED_TEMPORARILY;
  USE_LOCAL_COPY      = HTTP_NOT_MODIFIED;
  BAD_REQUEST         = HTTP_BAD_REQUEST;
  AUTH_REQUIRED       = HTTP_UNAUTHORIZED;
  FORBIDDEN           = HTTP_FORBIDDEN;
  NOT_FOUND           = HTTP_NOT_FOUND;
  METHOD_NOT_ALLOWED  = HTTP_METHOD_NOT_ALLOWED;
  NOT_ACCEPTABLE      = HTTP_NOT_ACCEPTABLE;
  LENGTH_REQUIRED     = HTTP_LENGTH_REQUIRED;
  PRECONDITION_FAILED = HTTP_PRECONDITION_FAILED;
  SERVER_ERROR        = HTTP_INTERNAL_SERVER_ERROR;
  NOT_IMPLEMENTED     = HTTP_NOT_IMPLEMENTED;
  BAD_GATEWAY         = HTTP_BAD_GATEWAY;
  VARIANT_ALSO_VARIES = HTTP_VARIANT_ALSO_VARIES;

  // Error Level constants
//  APLOG_MARK    = __FILE__, __LINE__
  APLOG_EMERG   = 0;	///* system is unusable */
  APLOG_ALERT   = 1;	///* action must be taken immediately */
  APLOG_CRIT	= 2;	///* critical conditions */
  APLOG_ERR	= 3;	///* error conditions */
  APLOG_WARNING	= 4;	///* warning conditions */
  APLOG_NOTICE	= 5;	///* normal but significant condition */
  APLOG_INFO	= 6;	///* informational */
  APLOG_DEBUG	= 7;	///* debug-level messages */

  APLOG_LEVELMASK = 7;	///* mask off the level value */
  APLOG_NOERRNO	  = (APLOG_LEVELMASK + 1);
  APLOG_WIN32ERROR = ((APLOG_LEVELMASK + 1) * 2);

type
  ap_pchar = pchar;             // char *
  ap_ppchar = ^ap_pchar;        // char **
  ap_constpchar = pchar;        // const char *
  ap_punsignedchar = ^byte;     // unsigned char *
  ap_short = smallint;          // short
  ap_pshort = ^ap_short;        // short *
  ap_unsignedshort = word;      // unsigned short
  ap_int = integer;             // int
  ap_unsigned = cardinal;       // unsigned
  ap_long = longint;            // long
  ap_unsignedlong = longword;   // unsigned long
  ap_pFILE = pointer;           // FILE *
  ap_ppFILE = ^ap_pFILE;        // FILE **
  ap_pvoid = pointer;           // void *

  // pending ...
  Ppool = pointer;              // pool *
  Ptable = pointer;             // table *
  Pserver_addr_rec = pointer;   // server_addr_rec *
  Parray_header = pointer;      // array_header *
  Pregmatch_t = pointer;        // regmatch_t *
  Pchild_info = pointer;        // child_info *
  AP_PMD5_CTX = pointer;        // AP_MD5_CTX *
  Ptm = pointer;                // tm *
  uid_t = integer;              // system type
  gid_t = integer;              // system type
  time_t = longint;             // system type
  size_t = integer;             // system type

  ap_Ppool = Ppool;
  Phostent = pointer;

///* The allowed locations for a configuration directive are the union of
// * those indicated by each set bit in the req_override mask.
// *
// * (req_override & RSRC_CONF)   => *.conf outside <Directory> or <Location>
// * (req_override & ACCESS_CONF) => *.conf inside <Directory> or <Location>
// * (req_override & OR_AUTHCFG)  => *.conf inside <Directory> or<Location>
// *                                 and .htaccess when AllowOverride AuthConfig
// * (req_override & OR_LIMIT)    => *.conf inside <Directory> or <Location>
// *                                 and .htaccess when AllowOverride Limit
// * (req_override & OR_OPTIONS)  => *.conf anywhere
// *                                 and .htaccess when AllowOverride Options
// * (req_override & OR_FILEINFO) => *.conf anywhere
// *                                 and .htaccess when AllowOverride FileInfo
// * (req_override & OR_INDEXES)  => *.conf anywhere
// *                                 and .htaccess when AllowOverride Indexes
// */

 const
   OR_NONE     =   0;
   OR_LIMIT    =   1;
   OR_OPTIONS  =   2;
   OR_FILEINFO =   4;
   OR_AUTHCFG  =   8;
   OR_INDEXES  =  16;
   OR_UNSET    =  32;
   ACCESS_CONF =  64;
   RSRC_CONF   = 128;
   OR_ALL      = (OR_LIMIT or OR_OPTIONS or OR_FILEINFO or OR_AUTHCFG or OR_INDEXES);

type
  Pstat = ^stat;
  stat = packed record
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

// Apache data structures ======================================================

  Puri_components = ^uri_components;
  uri_components = packed record
    scheme: pchar;		///* scheme ("http"/"ftp"/...) */
    hostinfo: pchar;            ///* combined [user[:password]@]host[:port] */
    user: pchar;		///* user name, as in http://user:passwd@host:port/ */
    password: pchar;		///* password, as in http://user:passwd@host:port/ */
    hostname: pchar;		///* hostname from URI (or from Host: header) */
    port_str: pchar;		///* port string (integer representation is in "port") */
    path: pchar;		///* the request path (or "/" if only scheme://host was given) */
    query: pchar;		///* Everything after a '?' in the path, if present */
    fragment: pchar;		///* Trailing "#fragment" string, if present */

    hostent: Phostent;

    port: word;	                ///* The port number, numeric, valid only if port_str != NULL */

    is_initialized: cardinal;   // = 1;

    dns_looked_up: cardinal;    // = 1;
    dns_resolved: cardinal;     // = 1;
  end;

///* Things which may vary per file-lookup WITHIN a request ---
// * e.g., state of MIME config.  Basically, the name of an object, info
// * about the object, and any other info we may ahve which may need to
// * change as we go poking around looking for it (e.g., overridden by
// * .htaccess files).
// *
// * Note how the default state of almost all these things is properly
// * zero, so that allocating it with pcalloc does the right thing without
// * a whole lot of hairy initialization... so long as we are willing to
// * make the (fairly) portable assumption that the bit pattern of a NULL
// * pointer is, in fact, zero.
// */

///* This represents the result of calling htaccess; these are cached for
// * each request.
// */
  Phtaccess_result = ^htaccess_result;
  htaccess_result = packed record
    dir: ap_pchar;      	///* the directory to which this applies */
    override: ap_int;		///* the overrides allowed for the .htaccess file */
    htaccess: ap_pvoid;		///* the configuration directives */

    ///* the next one, or NULL if no more; N.B. never change this */
    next: Phtaccess_result;
  end;

  PSPerServer = ^SPerServer;
  SPerServer = packed record
    szServer: ap_pchar;
    szTag: ap_pchar;
  end;

  Pserver_rec = ^server_rec;
  server_rec = packed record
    next: Pserver_rec;

    ///* description of where the definition came from */
    defn_name: ap_constpchar;
    defn_line_number: ap_unsigned;

    ///* Full locations of server config info */

    srm_confname: ap_pchar;
    access_confname: ap_pchar;

    ///* Contact information */

    server_admin: ap_pchar;
    server_hostname: ap_pchar;
    port: ap_unsignedshort;	///* for redirects, etc. */

    ///* Log files --- note that transfer log is now in the modules... */

    error_fname: ap_pchar;
    error_log: ap_pFILE;
    loglevel: ap_int;

    ///* Module-specific configuration for server, and defaults... */

    is_virtual: ap_int;		///* true if this is the virtual server */
    module_config: ap_pvoid;	///* Config vector containing pointers to
				// * modules' per-server config structures.
				// */
    lookup_defaults: ap_pvoid;	///* MIME type info, etc., before we start
				// * checking per-directory info.
				// */
    ///* Transaction handling */

    addrs: Pserver_addr_rec;
    timeout: ap_int;		///* Timeout, in seconds, before we give up */
    keep_alive_timeout: ap_int;	///* Seconds we'll wait for another request */
    keep_alive_max: ap_int;	///* Maximum requests per connection */
    keep_alive: ap_int;		///* Use persistent connections? */
    send_buffer_size: ap_int;	///* size of TCP send buffer (in bytes) */

    path: ap_pchar;		///* Pathname for ServerPath */
    pathlen: ap_int;		///* Length of path */

    names: Parray_header;	///* Normal names for ServerAlias servers */
    wild_names: Parray_header;	///* Wildcarded names for ServerAlias servers */

    server_uid: uid_t;          ///* effective user id when calling exec wrapper */
    server_gid: gid_t;          ///* effective group id when calling exec wrapper */

    limit_req_line: ap_int;      ///* limit on size of the HTTP request line    */
    limit_req_fieldsize: ap_int; ///* limit on size of any request header field */
    limit_req_fields: ap_int;    ///* limit on number of request header fields  */
  end;

  PSPerDir = ^SPerDir;
  SPerDir = packed record
    szDir: ap_pchar;
    szTag: ap_pchar;
  end;

  PBUFF = ^BUFF;                // BUFF *
  PPBUFF = ^PBUFF;              // BUFF **
  BUFF = packed record
  end;

  Pconn_rec = ^conn_rec;
  conn_rec = packed record
    pool: ap_Ppool;
    server: Pserver_rec;
    base_server: Pserver_rec;	///* Physical vhost this conn come in on */
    vhost_lookup_data: ap_pvoid;	///* used by http_vhost.c */

    ///* Information about the connection itself */

    child_num: integer;		///* The number of the child handling conn_rec */
    client: PBUFF;		///* Connection to the guy */

    ///* Who is the client? */

    local_addr: sockaddr_in;   ///* local address */
    remote_addr: sockaddr_in;  ///* remote address */
    remote_ip: ap_pchar;       ///* Client's IP address */
    remote_host: ap_pchar;     ///* Client's DNS name, if known.
			       // * NULL if DNS hasn't been checked,
			       // * "" if it has and no address was found.
			       // * N.B. Only access this though
			       // * get_remote_host() */
    remote_logname: ap_pchar;  ///* Only ever set if doing rfc1413 lookups.
			       // * N.B. Only access this through
			       // * get_remote_logname() */
    user: ap_pchar;	       ///* If an authentication check was made,
			       // * this gets set to the user name.  We assume
			       // * that there's only one user per connection(!)
			       // */
    ap_auth_type: ap_pchar;    ///* Ditto. */

    flags: integer;
    		                ///* Are we still talking? */
    	                        ///* Are we using HTTP Keep-Alive?
				// * -1 fatal error, 0 undecided, 1 yes */
    	                        ///* Did we use HTTP Keep-Alive? */
                                ///* have we done double-reverse DNS?
				// * -1 yes/failure, 0 not yet, 1 yes/success */
    keepalives: integer;	///* How many times have we used it? */
    local_ip: ap_pchar;		///* server IP address */
    local_host: ap_pchar;	///* used for ap_get_server_name when
				// * UseCanonicalName is set to DNS
				// * (ignores setting of HostnameLookups) */
  end;

  Prequest_rec = ^request_rec;
  request_rec = packed record
    pool: ap_Ppool;
    connection: Pconn_rec;
    server: Pserver_rec;

    next: Prequest_rec;      ///* If we wind up getting redirected,
				// * pointer to the request we redirected to.
				// */
    prev: Prequest_rec; 	///* If this is an internal redirect,
				// * pointer to where we redirected *from*.
				// */

    main: Prequest_rec; 	///* If this is a sub_request (see request.h)
				// * pointer back to the main request.
				// */

    ///* Info about the request itself... we begin with stuff that only
    // * protocol.c should ever touch...
    // */

    the_request: ap_pchar;  	///* First line of request, so we can log it */
    backwards: ap_int; 	        ///* HTTP/0.9, "simple" request */
    proxyreq: ap_int;		///* A proxy request (calculated during
				// * post_read_request or translate_name) */
    header_only: ap_int; 	///* HEAD request, as opposed to GET */
    protocol: ap_pchar;		///* Protocol, as given to us, or HTTP/0.9 */
    proto_num: ap_int;		///* Number version of protocol; 1.1 = 1001 */
    hostname: ap_constpchar;	///* Host, as set by full URI or Host: */

    request_time: time_t;	///* When the request started */

    status_line: ap_constpchar; ///* Status line, if set by script */
    status: ap_int;		///* In any case */

    ///* Request method, two ways; also, protocol, etc..  Outside of protocol.c,
    // * look, but don't touch.
    // */

    method: ap_constpchar;      ///* GET, HEAD, POST, etc. */
    method_number: ap_int;	///* M_GET, M_POST, etc. */

    ///*
    //	allowed is a bitvector of the allowed methods.

    //	A handler must ensure that the request method is one that
    //	it is capable of handling.  Generally modules should DECLINE
    //	any request methods they do not handle.  Prior to aborting the
    //	handler like this the handler should set r->allowed to the list
    //	of methods that it is willing to handle.  This bitvector is used
    //	to construct the "Allow:" header required for OPTIONS requests,
    //	and METHOD_NOT_ALLOWED and NOT_IMPLEMENTED status codes.

    //	Since the default_handler deals with OPTIONS, all modules can
    //	usually decline to deal with OPTIONS.  TRACE is always allowed,
    //	modules don't need to set it explicitly.

    //	Since the default_handler will always handle a GET, a
    //	module which does *not* implement GET should probably return
    //	METHOD_NOT_ALLOWED.  Unfortunately this means that a Script GET
    //	handler can't be installed by mod_actions.
    //*/
    allowed: ap_int;		///* Allowed methods - for 405, OPTIONS, etc */

    sent_bodyct: ap_int;	///* byte count in stream is for body */
    bytes_sent: ap_long;        ///* body byte count, for easy access */
    mtime: time_t;		///* Time the resource was last modified */

    ///* HTTP/1.1 connection-level features */

    chunked: ap_int;		///* sending chunked transfer-coding */
    byterange: ap_int;		///* number of byte ranges */
    boundary: ap_pchar;		///* multipart/byteranges boundary */
    range: ap_constpchar; 	///* The Range: header */
    clength: ap_long;		///* The "real" content length */

    remaining: ap_long;		///* bytes left to read */
    read_length: ap_long;	///* bytes that have been read */
    read_body: ap_int;		///* how the request body should be read */
    read_chunked: ap_int;	///* reading chunked transfer-coding */
    expecting_100: ap_unsigned;	///* is client waiting for a 100 response? */

    ///* MIME header environments, in and out.  Also, an array containing
    // * environment variables to be passed to subprocesses, so people can
    // * write modules to add to that environment.
    // *
    // * The difference between headers_out and err_headers_out is that the
    // * latter are printed even on error, and persist across internal redirects
    // * (so the headers printed for ErrorDocument handlers will have them).
    // *
    // * The 'notes' table is for notes from one module to another, with no
    // */ other set purpose in mind...
    // */

    headers_in: Ptable;
    headers_out: Ptable;
    err_headers_out: Ptable;
    subprocess_env: Ptable;
    notes: Ptable;

    ///* content_type, handler, content_encoding, content_language, and all
    // * content_languages MUST be lowercased strings.  They may be pointers
    // * to static strings; they should not be modified in place.
    // */
    content_type: ap_constpchar; ///* Break these out --- we dispatch on 'em */
    handler: ap_constpchar;      ///* What we *really* dispatch on           */

    content_encoding: ap_constpchar;
    content_language: ap_constpchar;	///* for back-compat. only -- do not use */
    content_languages: Parray_header;   ///* array of (char*) */

    vlist_validator: ap_pchar;  ///* variant list validator (if negotiated) */

    no_cache: ap_int;
    no_local_copy: ap_int;

    ///* What object is being requested (either directly, or via include
    // * or content-negotiation mapping).
    // */

    unparsed_uri: ap_pchar;	///* the uri without any parsing performed */
    uri: ap_pchar;			///* the path portion of the URI */
    filename: ap_pchar;
    path_info: ap_pchar;
    args: ap_pchar;		///* QUERY_ARGS, if any */
    finfo: stat;		///* ST_MODE set to zero if no such file */
    parsed_uri: uri_components; ///* components of uri, dismantled */

    ///* Various other config info which may change with .htaccess files
    // * These are config vectors, with one void* pointer for each module
    // * (the thing pointed to being the module's business).
    // */

    per_dir_config: ap_pvoid;	///* Options set in config files, etc. */
    request_config: ap_pvoid;	///* Notes on *this* request */

///*
// * a linked list of the configuration directives in the .htaccess files
// * accessed by this request.
// * N.B. always add to the head of the list, _never_ to the end.
// * that way, a sub request's list can (temporarily) point to a parent's list
// */
    htaccess: Phtaccess_result; // pointer to constant. * gcm *

///* Things placed at the end of the record to avoid breaking binary
// * compatibility.  It would be nice to remember to reorder the entire
// * record to improve 64bit alignment the next time we need to break
// * binary compatibility for some other reason.
// */
  end;

///* Note that for all of these except RAW_ARGS, the config routine is
// * passed a freshly allocated string which can be modified or stored
// * or whatever... it's only necessary to do pstrdup() stuff with
// * RAW_ARGS.
// */

  cmd_how = (
    RAW_ARGS,			///* cmd_func parses command line itself */
    TAKE1,			///* one argument only */
    TAKE2,			///* two arguments only */
    ITERATE,			///* one argument, occuring multiple times
				// * (e.g., IndexIgnore)
				// */
    ITERATE2,			///* two arguments, 2nd occurs multiple times
				// * (e.g., AddIcon)
				// */
    FLAG,			///* One of 'On' or 'Off' */
    NO_ARGS,			///* No args at all, e.g. </Directory> */
    TAKE12,			///* one or two arguments */
    TAKE3,			///* three arguments only */
    TAKE23,			///* two or three arguments */
    TAKE123,			///* one, two or three arguments */
    TAKE13			///* one or three arguments */
);


  TCommandFunc = function : pchar;
  Pcommand_rec = ^command_rec;
  command_rec = packed record
    name: pchar;		///* Name of this command */
    func: TCommandFunc;	        ///* Function invoked */
    cmd_data: pointer;		///* Extra data, for functions which
                                // * implement multiple commands...
                                // */
    req_override: integer;	///* What overrides need to be allowed to
                                // * enable this command.
                                // */
    args_how: cmd_how;	        ///* What the command expects as arguments */
    errmsg: pchar;		///* 'usage' message, in case of syntax errors */
  end;

///* This structure records the existence of handlers in a module... */

  THandlerFunc = function (rr: Prequest_rec): integer; cdecl;
  Phandler_rec = ^handler_rec;
  handler_rec = packed record
    content_type: pchar;	///* MUST be all lower case */
    handler: THandlerFunc;
  end;

  Pmodule = ^module;
  module = packed record
    version: integer;  	        ///* API version, *not* module version;
                                // * check that module is compatible with this
                                // * version of the server.
                                // */
    minor_version: integer;     ///* API minor version. Provides API feature
                                // * milestones. Not checked during module init
                                // */
    module_index: integer;	///* Index to this modules structures in
                                // * config vectors.
                                // */

    name: pchar;
    dynamic_load_handle: pointer;
    next: Pmodule;
    magic: integer;             ///* Magic Cookie to identify a module structure;
                                // * It's mainly important for the DSO facility
                                // * (see also mod_so).
                                // */

    ///* init() occurs after config parsing, but before any children are
    // * forked.
    // * Modules should not rely on the order in which create_server_config
    // * and create_dir_config are called.
    // */

    init: procedure (s: Pserver_rec; p: Ppool); cdecl;
    create_dir_config: function (p: Ppool; dir: pchar): pointer; cdecl;
    merge_dir_config: function (p: Ppool; base_conf, new_conf: pointer): pointer; cdecl;
    create_server_config: function (p: Ppool; s: Pserver_rec): pointer; cdecl;
    merge_server_config: function (p: Ppool; base_conf, new_conf: pointer): pointer; cdecl;

    cmds: Pcommand_rec;
    handlers: Phandler_rec;

    ///* Hooks for getting into the middle of server ops...

    // * translate_handler --- translate URI to filename
    // * access_checker --- check access by host address, etc.   All of these
    // *                    run; if all decline, that's still OK.
    // * check_user_id --- get and validate user id from the HTTP request
    // * auth_checker --- see if the user (from check_user_id) is OK *here*.
    // *                  If all of *these* decline, the request is rejected
    // *                  (as a SERVER_ERROR, since the module which was
    // *                  supposed to handle this was configured wrong).
    // * type_checker --- Determine MIME type of the requested entity;
    // *                  sets content_type, _encoding and _language fields.
    // * logger --- log a transaction.
    // * post_read_request --- run right after read_request or internal_redirect,
    // *                  and not run during any subrequests.
    // */

    translate_handler: THandlerFunc;
    ap_check_user_id: THandlerFunc;
    auth_checker: THandlerFunc;
    access_checker: THandlerFunc;
    type_checker: THandlerFunc;
    fixer_upper: THandlerFunc;
    logger: THandlerFunc;
    header_parser: THandlerFunc;

    //* Regardless of the model the server uses for managing "units of
    // * execution", i.e. multi-process, multi-threaded, hybrids of those,
    // * there is the concept of a "heavy weight process".  That is, a
    // * process with its own memory space, file spaces, etc.  This method,
    // * child_init, is called once for each heavy-weight process before
    // * any requests are served.  Note that no provision is made yet for
    // * initialization per light-weight process (i.e. thread).  The
    // * parameters passed here are the same as those passed to the global
    // * init method above.
    // */
    child_init: procedure (s: Pserver_rec; p: Ppool); cdecl;
    child_exit: procedure (s: Pserver_rec; p: Ppool); cdecl;

    post_read_request: function (r: Prequest_rec): integer; cdecl;
  end;

  TCompFunc = function (rec: ap_pvoid; const key, value: ap_pchar): ap_int;
  TCleanupFunc = procedure (p: ap_pvoid);
  TSpawnFunc = procedure (p: ap_pvoid; ci: Pchild_info);
  TbSpawnFunc = function (p: ap_pvoid; ci: Pchild_info): ap_int;

  Pregex_t = ^regex_t;
  regex_t = packed record
    re_magic: ap_int;
    re_nsub: size_t;	        ///* number of parenthesized subexpressions */
    re_endp: ap_pchar;	        ///* end pointer for REG_PEND */
    re_g: pointer;	        ///* none of your business :-) */
  end;

  kill_conditions = (
    kill_never,			///* process is never sent any signals */
    kill_always,		///* process is sent SIGKILL on pool cleanup */
    kill_after_timeout,		///* SIGTERM, wait 3 seconds, SIGKILL */
    just_wait,			///* wait forever for the process to complete */
    kill_only_once		///* send SIGTERM and then wait */
);

///* Common structure for reading of config files / passwd files etc. */
Pconfigfile_t = ^configfile_t;
configfile_t = packed record
    ///* a getc()-like function */
    getch: function (param: ap_pvoid): integer;
    ///* a fgets()-like function */
    getstr: function (buf: ap_pvoid; bufsiz: size_t; param: ap_pvoid): ap_pvoid;
    ///* a close hander function */
    close: function (param: ap_pvoid): integer;
    param: ap_pvoid;		///* the argument passed to getch/getstr/close */
    filename: ap_constpchar;   	///* the filename / description */
    line_number: ap_unsigned;	///* current line number, starting at 1 */
end;

///*
// * This structure is passed to a command which is being invoked,
// * to carry a large variety of miscellaneous data which is all of
// * use to *somebody*...
// */

 type
   Pcmd_parms = ^cmd_parms;
   cmd_parms = record
     info: pointer;              ///* Argument to command from cmd_table */
     override: ap_int;                ///* Which allow-override bits are set */
     limited: ap_int;            ///* Which methods are <Limit>ed */

     config_file: Pconfigfile_t;  ///* Config file structure from pcfg_openfile() */

     pool: Ppool;                ///* Pool to allocate new storage in */
     temp_pool: Ppool;           ///* Pool for scratch memory; persists during
                                 // * configuration, but wiped before the first
                                 // * request is served...
                                 // */
     server: Pserver_rec;        ///* Server_rec being configured for */
     path: PChar;                ///* If configuring for a directory,
                                 // * pathname of that directory.
                                 // * NOPE!  That's what it meant previous to the
                                 // * existance of <Files>, <Location>  and regex
                                 // * matching.  Now the only usefulness that can
                                 // * be derived from this field is whether a command
                                 // * is being called in a server context (path == NULL)
                                 // * or being called in a dir context (path != NULL).
                                 // */
     cmd: Pcommand_rec;          ///* configuration command */
     end_token: PChar;           ///* end token required to end a nested section */
     context: Pointer;           ///* per_dir_config vector passed
                                 // * to handle_command */
   end;

// HTTP status info

{$EXTERNALSYM ap_is_HTTP_INFO}
function ap_is_HTTP_INFO(x: ap_int): boolean;
{$EXTERNALSYM ap_is_HTTP_SUCCESS}
function ap_is_HTTP_SUCCESS(x: ap_int): boolean;
{$EXTERNALSYM ap_is_HTTP_REDIRECT}
function ap_is_HTTP_REDIRECT(x: ap_int): boolean;
{$EXTERNALSYM ap_is_HTTP_ERROR}
function ap_is_HTTP_ERROR(x: ap_int): boolean;
{$EXTERNALSYM ap_is_HTTP_CLIENT_ERROR}
function ap_is_HTTP_CLIENT_ERROR(x: ap_int): boolean;
{$EXTERNALSYM ap_is_HTTP_SERVER_ERROR}
function ap_is_HTTP_SERVER_ERROR(x: ap_int): boolean;


{$IFDEF MSWINDOWS}
// Pool functions

{$EXTERNALSYM ap_make_sub_pool}
function ap_make_sub_pool(p: Ppool): Ppool; stdcall;
{$EXTERNALSYM ap_clear_pool}
procedure ap_clear_pool(p: Ppool); stdcall;
{$EXTERNALSYM ap_destroy_pool}
procedure ap_destroy_pool(p: Ppool); stdcall;
{$EXTERNALSYM ap_bytes_in_pool}
function ap_bytes_in_pool(p: Ppool): ap_long; stdcall;
{$EXTERNALSYM ap_bytes_in_free_blocks}
function ap_bytes_in_free_blocks: ap_long; stdcall;
{$EXTERNALSYM ap_palloc}
function ap_palloc(p: Ppool; size: ap_int): ap_pvoid; stdcall;
{$EXTERNALSYM ap_pcalloc}
function ap_pcalloc(p: Ppool; size: ap_int): ap_pvoid; stdcall;
{$EXTERNALSYM ap_pstrdup}
function ap_pstrdup(p: Ppool; const s: ap_pchar): ap_pchar; stdcall;
{$EXTERNALSYM ap_pstrndup}
function ap_pstrndup(p: Ppool; const s: ap_pchar; n: ap_int): ap_pchar; stdcall;
// function ap_pstrcat(p: Ppool; ..): ap_pchar; stdcall;

// Array functions

{$EXTERNALSYM ap_make_array}
function ap_make_array(p: Ppool; nelts, elt_size: ap_int): Parray_header; stdcall;
{$EXTERNALSYM ap_push_array}
function ap_push_array(arr: Parray_header): ap_pvoid; stdcall;
{$EXTERNALSYM ap_array_cat}
procedure ap_array_cat(dst: Parray_header; const src: Parray_header); stdcall;
{$EXTERNALSYM ap_copy_array}
function ap_copy_array(p: Ppool; const arr: Parray_header): Parray_header; stdcall;
{$EXTERNALSYM ap_copy_array_hdr}
function ap_copy_array_hdr(p: Ppool; const arr: Parray_header): Parray_header; stdcall;
{$EXTERNALSYM ap_append_arrays}
function ap_append_arrays(p: Ppool; const first, second: Parray_header): Parray_header; stdcall;

// Table functions
{$EXTERNALSYM ap_make_table}
function ap_make_table(p: Ppool; nelts: ap_int): Ptable; stdcall;
{$EXTERNALSYM ap_copy_table}
function ap_copy_table(p: Ppool; const t: Ptable): Ptable; stdcall;
{$EXTERNALSYM ap_table_elts}
function ap_table_elts(t: Ptable): Parray_header; stdcall;
{$EXTERNALSYM ap_is_empty_table}
function ap_is_empty_table(t: Ptable): ap_int; stdcall;
{$EXTERNALSYM ap_table_set}
procedure ap_table_set(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_setn}
procedure ap_table_setn(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_merge}
procedure ap_table_merge(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_mergen}
procedure ap_table_mergen(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_add}
procedure ap_table_add(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_addn}
procedure ap_table_addn(t: Ptable; const key, value: pchar); stdcall;
{$EXTERNALSYM ap_table_unset}
procedure ap_table_unset(t: Ptable; const key: pchar); stdcall;
{$EXTERNALSYM ap_table_get}
function ap_table_get(t: Ptable; const key: pchar): ap_constpchar; stdcall;
{$EXTERNALSYM ap_table_do}
procedure ap_table_do(comp: TCompFunc; rec: ap_pvoid; const t: Ptable; tag: ap_pchar = nil); stdcall;
{$EXTERNALSYM ap_overlay_tables}
function ap_overlay_tables(p: Ppool; const overlay, base: Ptable): Ptable; stdcall;
{$EXTERNALSYM ap_clear_table}
procedure ap_clear_table(t: Ptable); stdcall;

// Cleanup functions

{$EXTERNALSYM ap_register_cleanup}
procedure ap_register_cleanup(p: Ppool; data: ap_pvoid; plain_cleanup, child_cleanup: TCleanupFunc); stdcall;
{$EXTERNALSYM ap_kill_cleanup}
procedure ap_kill_cleanup(p: Ppool; data: ap_pvoid; plain_cleanup: TCleanupFunc); stdcall;
{$EXTERNALSYM ap_cleanup_for_exec}
procedure ap_cleanup_for_exec; stdcall;
{$EXTERNALSYM ap_note_cleanups_for_fd}
procedure ap_note_cleanups_for_fd(p: Ppool; fd: ap_int); stdcall;
{$EXTERNALSYM ap_kill_cleanups_for_fd}
procedure ap_kill_cleanups_for_fd(p: Ppool; fd: ap_int); stdcall;
{$EXTERNALSYM ap_note_cleanups_for_socket}
procedure ap_note_cleanups_for_socket(p: Ppool; fd: ap_int); stdcall;
{$EXTERNALSYM ap_kill_cleanups_for_socket}
procedure ap_kill_cleanups_for_socket(p: Ppool; fd: ap_int); stdcall;
{$EXTERNALSYM ap_note_cleanups_for_file}
procedure ap_note_cleanups_for_file(p: Ppool; f: ap_pFILE); stdcall;
{$EXTERNALSYM ap_run_cleanup}
procedure ap_run_cleanup(p: Ppool; data: ap_pvoid; cleanup: TCleanupFunc); stdcall;

// File and socket functions

{$EXTERNALSYM ap_popenf}
function ap_popenf(p: Ppool; const name: ap_pchar; flg, mode: ap_int): ap_int; stdcall;
{$EXTERNALSYM ap_pclosef}
function ap_pclosef(p: Ppool; fd: ap_int): ap_int; stdcall;
{$EXTERNALSYM ap_pfopen}
function ap_pfopen(p: Ppool; const name, mode: ap_pchar): ap_pFILE; stdcall;
{$EXTERNALSYM ap_pfdopen}
function ap_pfdopen(p: Ppool; fd: ap_int; const mode: ap_pchar): ap_pFILE; stdcall;
{$EXTERNALSYM ap_pfclose}
function ap_pfclose(p: Ppool; fd: ap_pFILE): ap_int; stdcall;
{$EXTERNALSYM ap_psocket}
function ap_psocket(p: Ppool; domain, _type, protocol: ap_int): ap_int; stdcall;
{$EXTERNALSYM ap_pclosesocket}
function ap_pclosesocket(p: Ppool; sock: ap_int): ap_int; stdcall;

// Regular expression functions

{$EXTERNALSYM ap_pregcomp}
function ap_pregcomp(p: Ppool; const pattern: ap_pchar; cflags: ap_int): Pregex_t; stdcall;
{$EXTERNALSYM ap_pregsub}
function ap_pregsub(p: Ppool; const input, source: ap_pchar; nmatch: size_t; pmatch: Pregmatch_t): ap_pchar; stdcall;
{$EXTERNALSYM ap_pregfree}
procedure ap_pregfree(p: Ppool; reg: Pregex_t); stdcall;
{$EXTERNALSYM ap_os_is_path_absolute}
function ap_os_is_path_absolute(const _file: ap_pchar): ap_int; stdcall;

// Process and CGI functions

{$EXTERNALSYM ap_note_subprocess}
procedure ap_note_subprocess(p: Ppool; pid: ap_int; how: kill_conditions); stdcall;
{$EXTERNALSYM ap_spawn_child}
function ap_spawn_child(p: Ppool; func: TSpawnFunc; data: ap_pvoid; how: kill_conditions; pipe_in, pipe_out, pipe_err: ap_ppFILE): ap_int; stdcall;
{$EXTERNALSYM ap_bspawn_child}
function ap_bspawn_child(p: Ppool; func: TbSpawnFunc; data: ap_pvoid; kill_how: kill_conditions; pipe_in, pipe_out, pipe_err: PPBUFF): ap_int; stdcall;
{$EXTERNALSYM ap_call_exec}
function ap_call_exec(r: Prequest_rec; pinfo: Pchild_info; argv0: ap_pchar; env: ap_ppchar; shellcmd: ap_int): ap_int; stdcall;
{$EXTERNALSYM ap_can_exec}
function ap_can_exec(const finfo: Pstat): ap_int; stdcall;
{$EXTERNALSYM ap_add_cgi_vars}
procedure ap_add_cgi_vars(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_add_common_vars}
procedure ap_add_common_vars(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_scan_script_header_err}
function ap_scan_script_header_err(r: Prequest_rec; f: ap_pFILE; buffer: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_scan_script_header_err_buff}
function ap_scan_script_header_err_buff(r: Prequest_rec; f: PBUFF; buffer: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_scan_script_header}
function ap_scan_script_header(r: Prequest_rec; f: ap_pFILE): ap_int; stdcall;

// MD5 functions

{$EXTERNALSYM ap_md5}
function ap_md5(p: Ppool; _string: ap_pchar): pchar; stdcall;
{$EXTERNALSYM ap_md5contextTo64}
function ap_md5contextTo64(a: Ppool; context: AP_PMD5_CTX): ap_pchar; stdcall;
{$EXTERNALSYM ap_md5digest}
function ap_md5digest(p: Ppool; infile: ap_pFILE): ap_pchar; stdcall;
{$EXTERNALSYM ap_MD5Init}
procedure ap_MD5Init(context: AP_PMD5_CTX); stdcall;
{$EXTERNALSYM ap_MD5Final}
procedure ap_MD5Final(digest: ap_pchar; context: AP_PMD5_CTX); stdcall;
{$EXTERNALSYM ap_MD5Update}
procedure ap_MD5Update(context: AP_PMD5_CTX; const input: ap_pchar; inputLen: ap_unsigned); stdcall;

// Time and Date functions

{$EXTERNALSYM ap_get_time}
function ap_get_time: ap_pchar; stdcall;
{$EXTERNALSYM ap_ht_time}
function ap_ht_time(p: Ppool; t: time_t; const fmt: ap_pchar; gmt: ap_int): ap_pchar; stdcall;
{$EXTERNALSYM ap_gm_timestr_822}
function ap_gm_timestr_822(p: Ppool; t: time_t): ap_pchar; stdcall;
{$EXTERNALSYM ap_get_gmtoff}
function ap_get_gmtoff(var tz: ap_long): Ptm; stdcall;
{$EXTERNALSYM ap_tm2sec}
function ap_tm2sec(const t: Ptm): time_t; stdcall;
{$EXTERNALSYM ap_parseHTTPdate}
function ap_parseHTTPdate(const date: ap_pchar): time_t; stdcall;

// Path, Filename, and URL Manipulation Fuctions

{$EXTERNALSYM ap_getparents}
procedure ap_getparents(name: ap_pchar); stdcall;
{$EXTERNALSYM ap_no2slash}
procedure ap_no2slash(name: ap_pchar); stdcall;
{$EXTERNALSYM ap_make_dirstr}
function ap_make_dirstr(p: Ppool; const path: ap_pchar; n: ap_int): ap_pchar; stdcall;
{$EXTERNALSYM ap_make_dirstr_parent}
function ap_make_dirstr_parent(p: Ppool; const s: ap_pchar): ap_pchar; stdcall;
{$EXTERNALSYM ap_make_dirstr_prefix}
function ap_make_dirstr_prefix(d: ap_pchar; const s: ap_pchar; n: ap_int): ap_pchar; stdcall;
{$EXTERNALSYM ap_count_dirs}
function ap_count_dirs(const path: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_chdir_file}
procedure ap_chdir_file(const _file: ap_pchar); stdcall;
{$EXTERNALSYM ap_unescape_url}
function ap_unescape_url(url: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_construct_server}
function ap_construct_server(p: Ppool; const hostname: ap_pchar; port: ap_int; r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_construct_url}
function ap_construct_url(p: Ppool; const uri: ap_pchar; const r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_escape_path_segment}
function ap_escape_path_segment(p: Ppool; const segment: ap_pchar): ap_pchar; stdcall;
{$EXTERNALSYM ap_os_escape_path}
function ap_os_escape_path(p: Ppool; const path: ap_pchar; partial: ap_int): ap_pchar; stdcall;
{$EXTERNALSYM ap_is_directory}
function ap_is_directory(const path: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_make_full_path}
function ap_make_full_path(p: Ppool; const path1, path2: ap_pchar): ap_pchar; stdcall;
{$EXTERNALSYM ap_is_url}
function ap_is_url(const url: ap_pchar): ap_int; stdcall;
{$EXTERNALSYM ap_server_root_relative}
function ap_server_root_relative(p: Ppool; _file: ap_pchar): ap_pchar; stdcall;
{$EXTERNALSYM ap_os_canonical_filename}
function ap_os_canonical_filename(p: Ppool; const szfile: ap_pchar): ap_int; stdcall;

// TCP/IP and I/O functions

{$EXTERNALSYM ap_get_virthost_addr}
function ap_get_virthost_addr(const hostname: ap_pchar; ports: ap_pshort): ap_unsignedlong; stdcall;
{$EXTERNALSYM ap_get_local_host}
function ap_get_local_host(p: Ppool): ap_constpchar; stdcall;
{$EXTERNALSYM ap_get_remote_host}
function ap_get_remote_host(conn: Pconn_rec; dir_config: ap_pvoid; _type: ap_int): ap_constpchar; stdcall;
{$EXTERNALSYM ap_send_fd}
function ap_send_fd(f: ap_pFILE; r: Prequest_rec): ap_long; stdcall;
{$EXTERNALSYM ap_send_fd_length}
function ap_send_fd_length(f: ap_pFILE; r: Prequest_rec; length: ap_long): ap_long; stdcall;
{$EXTERNALSYM ap_send_fb}
function ap_send_fb(fb: pBUFF; r: Prequest_rec): ap_long; stdcall;
{$EXTERNALSYM ap_send_fb_length}
function ap_send_fb_length(f: pBUFF; r: Prequest_rec; length: ap_long): ap_long; stdcall;
{$EXTERNALSYM ap_rwrite}
function ap_rwrite(var buf; n_byte: ap_int; r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_rputc}
function ap_rputc(c: ap_int; r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_rputs}
function ap_rputs(const s: pchar; r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_rflush}
function ap_rflush(r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_setup_client_block}
function ap_setup_client_block(r: Prequest_rec; read_policy: ap_int): ap_int; stdcall;
{$EXTERNALSYM ap_should_client_block}
function ap_should_client_block(r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_get_client_block}
function ap_get_client_block(r: Prequest_rec; buffer: ap_pchar; bufsiz: ap_int): ap_long; stdcall;
{$EXTERNALSYM ap_send_http_header}
procedure ap_send_http_header(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_send_size}
procedure ap_send_size(size: size_t; r: Prequest_rec); stdcall;

// Request handling functions

{$EXTERNALSYM ap_sub_req_lookup_uri}
function ap_sub_req_lookup_uri(const new_uri: ap_pchar; const r: Prequest_rec): Prequest_rec; stdcall;
{$EXTERNALSYM ap_sub_req_lookup_file}
function ap_sub_req_lookup_file(const new_file: ap_pchar; const r: Prequest_rec): Prequest_rec; stdcall;
{$EXTERNALSYM ap_run_sub_req}
function ap_run_sub_req(r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_destroy_sub_req}
procedure ap_destroy_sub_req(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_internal_redirect}
procedure ap_internal_redirect(const uri: ap_pchar; r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_internal_redirect_handler}
procedure ap_internal_redirect_handler(const uri: ap_pchar; r: Prequest_rec); stdcall;

// Timeout & Alarm functions

{$EXTERNALSYM ap_hard_timeout}
procedure ap_hard_timeout(name: ap_pchar; r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_keepalive_timeout}
procedure ap_keepalive_timeout(name: ap_pchar; r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_soft_timeout}
procedure ap_soft_timeout(name: ap_pchar; r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_reset_timeout}
procedure ap_reset_timeout(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_kill_timeout}
procedure ap_kill_timeout(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_block_alarms}
procedure ap_block_alarms; stdcall;
{$EXTERNALSYM ap_unblock_alarms}
procedure ap_unblock_alarms; stdcall;
{$EXTERNALSYM ap_check_alarm}
procedure ap_check_alarm; stdcall;

// Logging functions

{$EXTERNALSYM ap_log_error}
procedure ap_log_error(const filename: pchar; line, level: ap_int; const s: Pserver_rec; const fmt: pchar); stdcall;
{$EXTERNALSYM ap_log_rerror}
procedure ap_log_rerror(const filename: pchar; line, level: ap_int; const s: Prequest_rec; const fmt: pchar); stdcall;

// URI functions

{$EXTERNALSYM ap_parse_uri_components}
function ap_parse_uri_components(p: Ppool; const uri: ap_pchar; uptr: Puri_components): ap_int; stdcall;
{$EXTERNALSYM ap_parse_hostinfo_components}
function ap_parse_hostinfo_components(p: Ppool; const hostinfo: ap_pchar; uptr: Puri_components): ap_int; stdcall;
{$EXTERNALSYM ap_unparse_uri_components}
function ap_unparse_uri_components(p: Ppool; const uptr: Puri_components; flags: ap_unsigned): ap_pchar; stdcall;
{$EXTERNALSYM ap_pgethostbyname}
function ap_pgethostbyname(p: Ppool; const hostname: ap_pchar): Phostent; stdcall;
{$EXTERNALSYM ap_pduphostent}
function ap_pduphostent(p: Ppool; const hp: Phostent): Phostent; stdcall;

// Miscellaneous functions

{$EXTERNALSYM ap_child_terminate}
procedure ap_child_terminate(r: Prequest_rec); stdcall;
{$EXTERNALSYM ap_default_port}
function ap_default_port(r: Prequest_rec): ap_unsignedshort; stdcall;
{$EXTERNALSYM ap_is_default_port}
function ap_is_default_port(port: ap_int; r: Prequest_rec): ap_int; stdcall;
{$EXTERNALSYM ap_default_port_for_scheme}
function ap_default_port_for_scheme(const scheme_str: ap_pchar): ap_unsignedshort; stdcall;
{$EXTERNALSYM ap_http_method}
function ap_http_method(r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_default_type}
function ap_default_type(r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_get_basic_auth_pw}
function ap_get_basic_auth_pw(r: Prequest_rec; const pw: ap_ppchar): ap_int; stdcall;
{$EXTERNALSYM ap_get_module_config}
function ap_get_module_config(conf_vector: ap_pvoid; m: Pmodule): ap_pvoid; stdcall;
{$EXTERNALSYM ap_get_remote_logname}
function ap_get_remote_logname(r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_get_server_name}
function ap_get_server_name(r: Prequest_rec): ap_pchar; stdcall;
{$EXTERNALSYM ap_get_server_port}
function ap_get_server_port(r: Prequest_rec): ap_unsigned; stdcall;
{$EXTERNALSYM ap_is_initial_req}
function ap_is_initial_req(r: Prequest_rec): ap_int; stdcall;

///* Open a configfile_t as FILE, return open configfile_t struct pointer */
function ap_pcfg_openfile(p: Ppool; filename: ap_constpchar): Pconfigfile_t; stdcall;
{$EXTERNALSYM ap_pcfg_openfile}
///* Read one line from open configfile_t, strip LF, increase line number */
function ap_cfg_getline(buf: ap_pchar; bufsize: size_t; cfp: Pconfigfile_t): integer; stdcall;
{$EXTERNALSYM ap_cfg_getline}
///* Read one char from open configfile_t, increase line number upon LF */
function ap_cfg_getc(cfp: Pconfigfile_t): integer; stdcall;
{$EXTERNALSYM ap_cfg_getc}
///* Detach from open configfile_t, calling the close handler */
function ap_cfg_closefile(cfp: Pconfigfile_t): integer; stdcall;
{$EXTERNALSYM ap_cfg_closefile}
function ap_getword(p: Ppool; line: ap_ppchar; stop: char): ap_pchar; stdcall;
{$EXTERNALSYM ap_getword}
{$ENDIF}

{$IFDEF LINUX}
// Pool functions

{$EXTERNALSYM ap_make_sub_pool}
function ap_make_sub_pool(p: Ppool): Ppool; cdecl;
{$EXTERNALSYM ap_clear_pool}
procedure ap_clear_pool(p: Ppool); cdecl;
{$EXTERNALSYM ap_destroy_pool}
procedure ap_destroy_pool(p: Ppool); cdecl;
{$EXTERNALSYM ap_bytes_in_pool}
function ap_bytes_in_pool(p: Ppool): ap_long; cdecl;
{$EXTERNALSYM ap_bytes_in_free_blocks}
function ap_bytes_in_free_blocks: ap_long; cdecl;
{$EXTERNALSYM ap_palloc}
function ap_palloc(p: Ppool; size: ap_int): ap_pvoid; cdecl;
{$EXTERNALSYM ap_pcalloc}
function ap_pcalloc(p: Ppool; size: ap_int): ap_pvoid; cdecl;
{$EXTERNALSYM ap_pstrdup}
function ap_pstrdup(p: Ppool; const s: ap_pchar): ap_pchar; cdecl;
{$EXTERNALSYM ap_pstrndup}
function ap_pstrndup(p: Ppool; const s: ap_pchar; n: ap_int): ap_pchar; cdecl;
// function ap_pstrcat(p: Ppool; ..): ap_pchar; cdecl;

// Array functions

{$EXTERNALSYM ap_make_array}
function ap_make_array(p: Ppool; nelts, elt_size: ap_int): Parray_header; cdecl;
{$EXTERNALSYM ap_push_array}
function ap_push_array(arr: Parray_header): ap_pvoid; cdecl;
{$EXTERNALSYM ap_array_cat}
procedure ap_array_cat(dst: Parray_header; const src: Parray_header); cdecl;
{$EXTERNALSYM ap_copy_array}
function ap_copy_array(p: Ppool; const arr: Parray_header): Parray_header; cdecl;
{$EXTERNALSYM ap_copy_array_hdr}
function ap_copy_array_hdr(p: Ppool; const arr: Parray_header): Parray_header; cdecl;
{$EXTERNALSYM ap_append_arrays}
function ap_append_arrays(p: Ppool; const first, second: Parray_header): Parray_header; cdecl;

// Table functions
{$EXTERNALSYM ap_make_table}
function ap_make_table(p: Ppool; nelts: ap_int): Ptable; cdecl;
{$EXTERNALSYM ap_copy_table}
function ap_copy_table(p: Ppool; const t: Ptable): Ptable; cdecl;
{$EXTERNALSYM ap_table_elts}
function ap_table_elts(t: Ptable): Parray_header; cdecl;
{$EXTERNALSYM ap_is_empty_table}
function ap_is_empty_table(t: Ptable): ap_int; cdecl;
{$EXTERNALSYM ap_table_set}
procedure ap_table_set(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_setn}
procedure ap_table_setn(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_merge}
procedure ap_table_merge(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_mergen}
procedure ap_table_mergen(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_add}
procedure ap_table_add(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_addn}
procedure ap_table_addn(t: Ptable; const key, value: pchar); cdecl;
{$EXTERNALSYM ap_table_unset}
procedure ap_table_unset(t: Ptable; const key: pchar); cdecl;
{$EXTERNALSYM ap_table_get}
function ap_table_get(t: Ptable; const key: pchar): ap_constpchar; cdecl;
{$EXTERNALSYM ap_table_do}
procedure ap_table_do(comp: TCompFunc; rec: ap_pvoid; const t: Ptable; tag: ap_pchar = nil); cdecl;
{$EXTERNALSYM ap_overlay_tables}
function ap_overlay_tables(p: Ppool; const overlay, base: Ptable): Ptable; cdecl;
{$EXTERNALSYM ap_clear_table}
procedure ap_clear_table(t: Ptable); cdecl;

// Cleanup functions

{$EXTERNALSYM ap_register_cleanup}
procedure ap_register_cleanup(p: Ppool; data: ap_pvoid; plain_cleanup, child_cleanup: TCleanupFunc); cdecl;
{$EXTERNALSYM ap_kill_cleanup}
procedure ap_kill_cleanup(p: Ppool; data: ap_pvoid; plain_cleanup: TCleanupFunc); cdecl;
{$EXTERNALSYM ap_cleanup_for_exec}
procedure ap_cleanup_for_exec; cdecl;
{$EXTERNALSYM ap_note_cleanups_for_fd}
procedure ap_note_cleanups_for_fd(p: Ppool; fd: ap_int); cdecl;
{$EXTERNALSYM ap_kill_cleanups_for_fd}
procedure ap_kill_cleanups_for_fd(p: Ppool; fd: ap_int); cdecl;
{$EXTERNALSYM ap_note_cleanups_for_socket}
procedure ap_note_cleanups_for_socket(p: Ppool; fd: ap_int); cdecl;
{$EXTERNALSYM ap_kill_cleanups_for_socket}
procedure ap_kill_cleanups_for_socket(p: Ppool; fd: ap_int); cdecl;
{$EXTERNALSYM ap_note_cleanups_for_file}
procedure ap_note_cleanups_for_file(p: Ppool; f: ap_pFILE); cdecl;
{$EXTERNALSYM ap_run_cleanup}
procedure ap_run_cleanup(p: Ppool; data: ap_pvoid; cleanup: TCleanupFunc); cdecl;

// File and socket functions

{$EXTERNALSYM ap_popenf}
function ap_popenf(p: Ppool; const name: ap_pchar; flg, mode: ap_int): ap_int; cdecl;
{$EXTERNALSYM ap_pclosef}
function ap_pclosef(p: Ppool; fd: ap_int): ap_int; cdecl;
{$EXTERNALSYM ap_pfopen}
function ap_pfopen(p: Ppool; const name, mode: ap_pchar): ap_pFILE; cdecl;
{$EXTERNALSYM ap_pfdopen}
function ap_pfdopen(p: Ppool; fd: ap_int; const mode: ap_pchar): ap_pFILE; cdecl;
{$EXTERNALSYM ap_pfclose}
function ap_pfclose(p: Ppool; fd: ap_pFILE): ap_int; cdecl;
{$EXTERNALSYM ap_psocket}
function ap_psocket(p: Ppool; domain, _type, protocol: ap_int): ap_int; cdecl;
{$EXTERNALSYM ap_pclosesocket}
function ap_pclosesocket(p: Ppool; sock: ap_int): ap_int; cdecl;

// Regular expression functions

{$EXTERNALSYM ap_pregcomp}
function ap_pregcomp(p: Ppool; const pattern: ap_pchar; cflags: ap_int): Pregex_t; cdecl;
{$EXTERNALSYM ap_pregsub}
function ap_pregsub(p: Ppool; const input, source: ap_pchar; nmatch: size_t; pmatch: Pregmatch_t): ap_pchar; cdecl;
{$EXTERNALSYM ap_pregfree}
procedure ap_pregfree(p: Ppool; reg: Pregex_t); cdecl;
{$EXTERNALSYM ap_os_is_path_absolute}
function ap_os_is_path_absolute(const _file: ap_pchar): ap_int; cdecl;

// Process and CGI functions

{$EXTERNALSYM ap_note_subprocess}
procedure ap_note_subprocess(p: Ppool; pid: ap_int; how: kill_conditions); cdecl;
{$EXTERNALSYM ap_spawn_child}
function ap_spawn_child(p: Ppool; func: TSpawnFunc; data: ap_pvoid; how: kill_conditions; pipe_in, pipe_out, pipe_err: ap_ppFILE): ap_int; cdecl;
{$EXTERNALSYM ap_bspawn_child}
function ap_bspawn_child(p: Ppool; func: TbSpawnFunc; data: ap_pvoid; kill_how: kill_conditions; pipe_in, pipe_out, pipe_err: PPBUFF): ap_int; cdecl;
{$EXTERNALSYM ap_call_exec}
function ap_call_exec(r: Prequest_rec; pinfo: Pchild_info; argv0: ap_pchar; env: ap_ppchar; shellcmd: ap_int): ap_int; cdecl;
{$EXTERNALSYM ap_can_exec}
function ap_can_exec(const finfo: Pstat): ap_int; cdecl;
{$EXTERNALSYM ap_add_cgi_vars}
procedure ap_add_cgi_vars(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_add_common_vars}
procedure ap_add_common_vars(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_scan_script_header_err}
function ap_scan_script_header_err(r: Prequest_rec; f: ap_pFILE; buffer: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_scan_script_header_err_buff}
function ap_scan_script_header_err_buff(r: Prequest_rec; f: PBUFF; buffer: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_scan_script_header}
function ap_scan_script_header(r: Prequest_rec; f: ap_pFILE): ap_int; cdecl;

// MD5 functions

{$EXTERNALSYM ap_md5}
function ap_md5(p: Ppool; _string: ap_pchar): pchar; cdecl;
{$EXTERNALSYM ap_md5contextTo64}
function ap_md5contextTo64(a: Ppool; context: AP_PMD5_CTX): ap_pchar; cdecl;
{$EXTERNALSYM ap_md5digest}
function ap_md5digest(p: Ppool; infile: ap_pFILE): ap_pchar; cdecl;
{$EXTERNALSYM ap_MD5Init}
procedure ap_MD5Init(context: AP_PMD5_CTX); cdecl;
{$EXTERNALSYM ap_MD5Final}
procedure ap_MD5Final(digest: ap_pchar; context: AP_PMD5_CTX); cdecl;
{$EXTERNALSYM ap_MD5Update}
procedure ap_MD5Update(context: AP_PMD5_CTX; const input: ap_pchar; inputLen: ap_unsigned); cdecl;

// Time and Date functions

{$EXTERNALSYM ap_get_time}
function ap_get_time: ap_pchar; cdecl;
{$EXTERNALSYM ap_ht_time}
function ap_ht_time(p: Ppool; t: time_t; const fmt: ap_pchar; gmt: ap_int): ap_pchar; cdecl;
{$EXTERNALSYM ap_gm_timestr_822}
function ap_gm_timestr_822(p: Ppool; t: time_t): ap_pchar; cdecl;
{$EXTERNALSYM ap_get_gmtoff}
function ap_get_gmtoff(var tz: ap_long): Ptm; cdecl;
{$EXTERNALSYM ap_tm2sec}
function ap_tm2sec(const t: Ptm): time_t; cdecl;
{$EXTERNALSYM ap_parseHTTPdate}
function ap_parseHTTPdate(const date: ap_pchar): time_t; cdecl;

// Path, Filename, and URL Manipulation Fuctions

{$EXTERNALSYM ap_getparents}
procedure ap_getparents(name: ap_pchar); cdecl;
{$EXTERNALSYM ap_no2slash}
procedure ap_no2slash(name: ap_pchar); cdecl;
{$EXTERNALSYM ap_make_dirstr}
function ap_make_dirstr(p: Ppool; const path: ap_pchar; n: ap_int): ap_pchar; cdecl;
{$EXTERNALSYM ap_make_dirstr_parent}
function ap_make_dirstr_parent(p: Ppool; const s: ap_pchar): ap_pchar; cdecl;
{$EXTERNALSYM ap_make_dirstr_prefix}
function ap_make_dirstr_prefix(d: ap_pchar; const s: ap_pchar; n: ap_int): ap_pchar; cdecl;
{$EXTERNALSYM ap_count_dirs}
function ap_count_dirs(const path: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_chdir_file}
procedure ap_chdir_file(const _file: ap_pchar); cdecl;
{$EXTERNALSYM ap_unescape_url}
function ap_unescape_url(url: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_construct_server}
function ap_construct_server(p: Ppool; const hostname: ap_pchar; port: ap_int; r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_construct_url}
function ap_construct_url(p: Ppool; const uri: ap_pchar; const r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_escape_path_segment}
function ap_escape_path_segment(p: Ppool; const segment: ap_pchar): ap_pchar; cdecl;
{$EXTERNALSYM ap_os_escape_path}
function ap_os_escape_path(p: Ppool; const path: ap_pchar; partial: ap_int): ap_pchar; cdecl;
{$EXTERNALSYM ap_is_directory}
function ap_is_directory(const path: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_make_full_path}
function ap_make_full_path(p: Ppool; const path1, path2: ap_pchar): ap_pchar; cdecl;
{$EXTERNALSYM ap_is_url}
function ap_is_url(const url: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_server_root_relative}
function ap_server_root_relative(p: Ppool; _file: ap_pchar): ap_int; cdecl;
{$EXTERNALSYM ap_os_canonical_filename}
function ap_os_canonical_filename(p: Ppool; const szfile: ap_pchar): ap_int; cdecl;

// TCP/IP and I/O functions

{$EXTERNALSYM ap_get_virthost_addr}
function ap_get_virthost_addr(const hostname: ap_pchar; ports: ap_pshort): ap_unsignedlong; cdecl;
{$EXTERNALSYM ap_get_local_host}
function ap_get_local_host(p: Ppool): ap_constpchar; cdecl;
{$EXTERNALSYM ap_get_remote_host}
function ap_get_remote_host(conn: Pconn_rec; dir_config: ap_pvoid; _type: ap_int): ap_constpchar; cdecl;
{$EXTERNALSYM ap_send_fd}
function ap_send_fd(f: ap_pFILE; r: Prequest_rec): ap_long; cdecl;
{$EXTERNALSYM ap_send_fd_length}
function ap_send_fd_length(f: ap_pFILE; r: Prequest_rec; length: ap_long): ap_long; cdecl;
{$EXTERNALSYM ap_send_fb}
function ap_send_fb(fb: pBUFF; r: Prequest_rec): ap_long; cdecl;
{$EXTERNALSYM ap_send_fb_length}
function ap_send_fb_length(f: pBUFF; r: Prequest_rec; length: ap_long): ap_long; cdecl;
{$EXTERNALSYM ap_rwrite}
function ap_rwrite(var buf; n_byte: ap_int; r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_rputc}
function ap_rputc(c: ap_int; r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_rputs}
function ap_rputs(const s: pchar; r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_rflush}
function ap_rflush(r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_setup_client_block}
function ap_setup_client_block(r: Prequest_rec; read_policy: ap_int): ap_int; cdecl;
{$EXTERNALSYM ap_should_client_block}
function ap_should_client_block(r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_get_client_block}
function ap_get_client_block(r: Prequest_rec; buffer: ap_pchar; bufsiz: ap_int): ap_long; cdecl;
{$EXTERNALSYM ap_send_http_header}
procedure ap_send_http_header(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_send_size}
procedure ap_send_size(size: size_t; r: Prequest_rec); cdecl;

// Request handling functions

{$EXTERNALSYM ap_sub_req_lookup_uri}
function ap_sub_req_lookup_uri(const new_uri: ap_pchar; const r: Prequest_rec): Prequest_rec; cdecl;
{$EXTERNALSYM ap_sub_req_lookup_file}
function ap_sub_req_lookup_file(const new_file: ap_pchar; const r: Prequest_rec): Prequest_rec; cdecl;
{$EXTERNALSYM ap_run_sub_req}
function ap_run_sub_req(r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_destroy_sub_req}
procedure ap_destroy_sub_req(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_internal_redirect}
procedure ap_internal_redirect(const uri: ap_pchar; r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_internal_redirect_handler}
procedure ap_internal_redirect_handler(const uri: ap_pchar; r: Prequest_rec); cdecl;

// Timeout & Alarm functions

{$EXTERNALSYM ap_hard_timeout}
procedure ap_hard_timeout(name: ap_pchar; r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_keepalive_timeout}
procedure ap_keepalive_timeout(name: ap_pchar; r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_soft_timeout}
procedure ap_soft_timeout(name: ap_pchar; r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_reset_timeout}
procedure ap_reset_timeout(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_kill_timeout}
procedure ap_kill_timeout(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_block_alarms}
procedure ap_block_alarms; cdecl;
{$EXTERNALSYM ap_unblock_alarms}
procedure ap_unblock_alarms; cdecl;
{$EXTERNALSYM ap_check_alarm}
procedure ap_check_alarm; cdecl;

// Logging functions

{$EXTERNALSYM ap_log_error}
procedure ap_log_error(const filename: pchar; line, level: ap_int; const s: Pserver_rec; const fmt: pchar); cdecl;
{$EXTERNALSYM ap_log_rerror}
procedure ap_log_rerror(const filename: pchar; line, level: ap_int; const s: Prequest_rec; const fmt: pchar); cdecl;

// URI functions

{$EXTERNALSYM ap_parse_uri_components}
function ap_parse_uri_components(p: Ppool; const uri: ap_pchar; uptr: Puri_components): ap_int; cdecl;
{$EXTERNALSYM ap_parse_hostinfo_components}
function ap_parse_hostinfo_components(p: Ppool; const hostinfo: ap_pchar; uptr: Puri_components): ap_int; cdecl;
{$EXTERNALSYM ap_unparse_uri_components}
function ap_unparse_uri_components(p: Ppool; const uptr: Puri_components; flags: ap_unsigned): ap_pchar; cdecl;
{$EXTERNALSYM ap_pgethostbyname}
function ap_pgethostbyname(p: Ppool; const hostname: ap_pchar): Phostent; cdecl;
{$EXTERNALSYM ap_pduphostent}
function ap_pduphostent(p: Ppool; const hp: Phostent): Phostent; cdecl;

// Miscellaneous functions

{$EXTERNALSYM ap_child_terminate}
procedure ap_child_terminate(r: Prequest_rec); cdecl;
{$EXTERNALSYM ap_default_port}
function ap_default_port(r: Prequest_rec): ap_unsignedshort; cdecl;
{$EXTERNALSYM ap_is_default_port}
function ap_is_default_port(port: ap_int; r: Prequest_rec): ap_int; cdecl;
{$EXTERNALSYM ap_default_port_for_scheme}
function ap_default_port_for_scheme(const scheme_str: ap_pchar): ap_unsignedshort; cdecl;
{$EXTERNALSYM ap_http_method}
function ap_http_method(r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_default_type}
function ap_default_type(r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_get_basic_auth_pw}
function ap_get_basic_auth_pw(r: Prequest_rec; const pw: ap_ppchar): ap_int; cdecl;
{$EXTERNALSYM ap_get_module_config}
function ap_get_module_config(conf_vector: ap_pvoid; m: Pmodule): ap_pvoid; cdecl;
{$EXTERNALSYM ap_get_remote_logname}
function ap_get_remote_logname(r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_get_server_name}
function ap_get_server_name(r: Prequest_rec): ap_pchar; cdecl;
{$EXTERNALSYM ap_get_server_port}
function ap_get_server_port(r: Prequest_rec): ap_unsigned; cdecl;
{$EXTERNALSYM ap_is_initial_req}
function ap_is_initial_req(r: Prequest_rec): ap_int; cdecl;

///* Open a configfile_t as FILE, return open configfile_t struct pointer */
function ap_pcfg_openfile(p: Ppool; filename: ap_constpchar): Pconfigfile_t; cdecl;
{$EXTERNALSYM ap_pcfg_openfile}
///* Read one line from open configfile_t, strip LF, increase line number */
function ap_cfg_getline(buf: ap_pchar; bufsize: size_t; cfp: Pconfigfile_t): integer; cdecl;
{$EXTERNALSYM ap_cfg_getline}
///* Read one char from open configfile_t, increase line number upon LF */
function ap_cfg_getc(cfp: Pconfigfile_t): integer; cdecl;
{$EXTERNALSYM ap_cfg_getc}
///* Detach from open configfile_t, calling the close handler */
function ap_cfg_closefile(cfp: Pconfigfile_t): integer; cdecl;
{$EXTERNALSYM ap_cfg_closefile}
function ap_getword(p: Ppool; line: ap_ppchar; stop: char): ap_pchar; cdecl;
{$EXTERNALSYM ap_getword}
{$ENDIF}

// http_protocol.h

procedure ap_note_auth_failure(r: Prequest_rec);
procedure ap_note_basic_auth_failure(r: Prequest_rec);
procedure ap_note_digest_auth_failure(r: Prequest_rec);

implementation

function ap_is_HTTP_INFO(x: ap_int): boolean;
begin
  result :=  (x >= 100) and (x < 200);
end;

function ap_is_HTTP_SUCCESS(x: ap_int): boolean;
begin
  result :=  (x >= 200) and (x < 300);
end;

function ap_is_HTTP_REDIRECT(x: ap_int): boolean;
begin
  result :=  (x >= 300) and (x < 400);
end;

function ap_is_HTTP_ERROR(x: ap_int): boolean;
begin
  result :=  (x >= 400) and (x < 600);
end;

function ap_is_HTTP_CLIENT_ERROR(x: ap_int): boolean;
begin
  result :=  (x >= 400) and (x < 500);
end;

function ap_is_HTTP_SERVER_ERROR(x: ap_int): boolean;
begin
  result :=  (x >= 500) and (x < 600);
end;

// Pool functions

function ap_make_sub_pool;              external ApacheCore name 'ap_make_sub_pool';
procedure ap_clear_pool;                external ApacheCore name 'ap_clear_pool';
procedure ap_destroy_pool;              external ApacheCore name 'ap_destroy_pool';
function ap_bytes_in_pool;              external ApacheCore name 'ap_bytes_in_pool';
function ap_bytes_in_free_blocks;       external ApacheCore name 'ap_bytes_in_free_pool';
function ap_palloc;                     external ApacheCore name 'ap_palloc';
function ap_pcalloc;                    external ApacheCore name 'ap_pcalloc';
function ap_pstrdup;                    external ApacheCore name 'ap_pstrdup';
function ap_pstrndup;                   external ApacheCore name 'ap_pstrndup';
// function ap_pstrcat; external ApacheCore name 'ap_pstrcat';

// Array functions

function ap_make_array;                 external ApacheCore name 'ap_make_array';
function ap_push_array;                 external ApacheCore name 'ap_push_array';
procedure ap_array_cat;                 external ApacheCore name 'ap_array_cat';
function ap_copy_array;                 external ApacheCore name 'ap_copy_array';
function ap_copy_array_hdr;             external ApacheCore name 'ap_copy_array_hdr';
function ap_append_arrays;              external ApacheCore name 'ap_append_arrays';

// Table functions

function ap_make_table;                 external ApacheCore name 'ap_make_table';
function ap_copy_table;                 external ApacheCore name 'ap_copy_table';
function ap_table_elts;                 external ApacheCore name 'ap_table_elts';
function ap_is_empty_table;             external ApacheCore name 'ap_is_empty_table';
procedure ap_table_set;                 external ApacheCore name 'ap_table_set';
procedure ap_table_setn;                external ApacheCore name 'ap_table_setn';
procedure ap_table_merge;               external ApacheCore name 'ap_table_merge';
procedure ap_table_mergen;              external ApacheCore name 'ap_table_mergen';
procedure ap_table_add;                 external ApacheCore name 'ap_table_add';
procedure ap_table_addn;                external ApacheCore name 'ap_table_addn';
procedure ap_table_unset;               external ApacheCore name 'ap_table_unset';
function ap_table_get;                  external ApacheCore name 'ap_table_get';
procedure ap_table_do;                  external ApacheCore name 'ap_table_do';
function ap_overlay_tables;             external ApacheCore name 'ap_overlay_tables';
procedure ap_clear_table;               external ApacheCore name 'ap_clear_table';

// Cleanup functions

procedure ap_register_cleanup;          external ApacheCore name 'ap_register_cleanup';
procedure ap_kill_cleanup;              external ApacheCore name 'ap_kill_cleanup';
procedure ap_cleanup_for_exec;          external ApacheCore name 'ap_cleanup_for_exec';
procedure ap_note_cleanups_for_fd;      external ApacheCore name 'ap_note_cleanups_for_fd';
procedure ap_kill_cleanups_for_fd;      external ApacheCore name 'ap_kill_cleanups_for_fd';
procedure ap_note_cleanups_for_socket;  external ApacheCore name 'ap_note_cleanups_for_socket';
procedure ap_kill_cleanups_for_socket;  external ApacheCore name 'ap_kill_cleanups_for_socket';
procedure ap_note_cleanups_for_file;    external ApacheCore name 'ap_note_cleanups_for_file';
procedure ap_run_cleanup;               external ApacheCore name 'ap_run_cleanup';

// File and socket functions

function ap_popenf;                     external ApacheCore name 'ap_popenf';
function ap_pclosef;                    external ApacheCore name 'ap_pclosef';
function ap_pfopen;                     external ApacheCore name 'ap_pfopen';
function ap_pfdopen;                    external ApacheCore name 'ap_pfdopen';
function ap_pfclose;                    external ApacheCore name 'ap_pfclose';
function ap_psocket;                    external ApacheCore name 'ap_psocket';
function ap_pclosesocket;               external ApacheCore name 'ap_pclosesocket';

// Regular expression functions

function ap_pregcomp;                   external ApacheCore name 'ap_pregcomp';
function ap_pregsub;                    external ApacheCore name 'ap_pregsub';
procedure ap_pregfree;                  external ApacheCore name 'ap_pregfree';
function ap_os_is_path_absolute;        external ApacheCore name 'ap_os_is_path_absolute';

// Process and CGI functions

procedure ap_note_subprocess;           external ApacheCore name 'ap_note_subprocess';
function ap_spawn_child;                external ApacheCore name 'ap_spawn_child';
function ap_bspawn_child;               external ApacheCore name 'ap_bspawn_child';
function ap_call_exec;                  external ApacheCore name 'ap_call_exec';
function ap_can_exec;                   external ApacheCore name 'ap_can_exec';
procedure ap_add_cgi_vars;              external ApacheCore name 'ap_add_cgi_vars';
procedure ap_add_common_vars;           external ApacheCore name 'ap_add_common_vars';
function ap_scan_script_header_err;     external ApacheCore name 'ap_scan_script_header_err';
function ap_scan_script_header_err_buff; external ApacheCore name 'ap_scan_script_header_err_buff';
function ap_scan_script_header;         external ApacheCore name 'ap_scan_script_header';

// MD5 functions

function ap_md5;                        external ApacheCore name 'ap_md5';
function ap_md5contextTo64;             external ApacheCore name 'ap_md5contextTo64';
function ap_md5digest;                  external ApacheCore name 'ap_md5digest';
procedure ap_MD5Init;                   external ApacheCore name 'ap_MD5Init';
procedure ap_MD5Final;                  external ApacheCore name 'ap_MD5Final';
procedure ap_MD5Update;                 external ApacheCore name 'ap_MD5Update';

// Time and Date functions

function ap_get_time: ap_pchar;         external ApacheCore name 'ap_get_time';
function ap_ht_time;                    external ApacheCore name 'ap_ht_time';
function ap_gm_timestr_822;             external ApacheCore name 'ap_gm_timestr_822';
function ap_get_gmtoff;                 external ApacheCore name 'ap_get_gmtoff';
function ap_tm2sec;                     external ApacheCore name 'ap_tm2sec';
function ap_parseHTTPdate;              external ApacheCore name 'ap_parseHTTPdate';

// Path, Filename, and URL Manipulation Fuctions

procedure ap_getparents;                external ApacheCore name 'ap_getparents';
procedure ap_no2slash;                  external ApacheCore name 'ap_no2slash';
function ap_make_dirstr;                external ApacheCore name 'ap_make_dirstr';
function ap_make_dirstr_parent;         external ApacheCore name 'ap_make_dirstr_parent';
function ap_make_dirstr_prefix;         external ApacheCore name 'ap_make_dirstr_prefix';
function ap_count_dirs;                 external ApacheCore name 'ap_count_dirs';
procedure ap_chdir_file;                external ApacheCore name 'ap_chdir_file';
function ap_unescape_url;               external ApacheCore name 'ap_unescape_url';
function ap_construct_server;           external ApacheCore name 'ap_construct_server';
function ap_construct_url;              external ApacheCore name 'ap_construct_url';
function ap_escape_path_segment;        external ApacheCore name 'ap_escape_path_segment';
function ap_os_escape_path;             external ApacheCore name 'ap_os_escape_path';
function ap_is_directory;               external ApacheCore name 'ap_is_directory';
function ap_make_full_path;             external ApacheCore name 'ap_make_full_path';
function ap_is_url;                     external ApacheCore name 'ap_is_url';
function ap_server_root_relative;       external ApacheCore name 'ap_server_root_relative';
function ap_os_canonical_filename;      external ApacheCore name 'ap_os_canonical_filename';

// TCP/IP and I/O functions

function ap_get_virthost_addr;          external ApacheCore name 'ap_get_virthost_addr';
function ap_get_local_host;             external ApacheCore name 'ap_get_local_host';
function ap_get_remote_host;            external ApacheCore name 'ap_get_remote_host';
function ap_send_fd;                    external ApacheCore name 'ap_send_fd';
function ap_send_fd_length;             external ApacheCore name 'ap_send_fd_lentgh';
function ap_send_fb;                    external ApacheCore name 'ap_send_fb';
function ap_send_fb_length;             external ApacheCore name 'ap_send_fb_lentgh';
function ap_rwrite;                     external ApacheCore name 'ap_rwrite';
function ap_rputc;                      external ApacheCore name 'ap_rputc';
function ap_rputs;                      external ApacheCore name 'ap_rputs';
function ap_rflush;                     external ApacheCore name 'ap_rflush';
function ap_setup_client_block;         external ApacheCore name 'ap_setup_client_block';
function ap_should_client_block;        external ApacheCore name 'ap_should_client_block';
function ap_get_client_block;           external ApacheCore name 'ap_get_client_block';
procedure ap_send_http_header;          external ApacheCore name 'ap_send_http_header';
procedure ap_send_size;                 external ApacheCore name 'ap_send_size';

// Request handling functions

function ap_sub_req_lookup_uri;         external ApacheCore name 'ap_sub_req_lookup_uri';
function ap_sub_req_lookup_file;        external ApacheCore name 'ap_sub_req_lookup_uri';
function ap_run_sub_req;                external ApacheCore name 'ap_run_sub_req';
procedure ap_destroy_sub_req;           external ApacheCore name 'ap_destroy_sub_req';
procedure ap_internal_redirect;         external ApacheCore name 'ap_internal_redirect';
procedure ap_internal_redirect_handler; external ApacheCore name 'ap_internal_redirect_handler';

// Timeout & Alarm functions

procedure ap_hard_timeout;              external ApacheCore name 'ap_hard_timeout';
procedure ap_keepalive_timeout;         external ApacheCore name 'ap_keepalive_timeout';
procedure ap_soft_timeout;              external ApacheCore name 'ap_soft_timeout';
procedure ap_reset_timeout;             external ApacheCore name 'ap_reset_timeout';
procedure ap_kill_timeout;              external ApacheCore name 'ap_kill_timeout';
procedure ap_block_alarms;              external ApacheCore name 'ap_block_alarms';
procedure ap_unblock_alarms;            external ApacheCore name 'ap_unblock_alarms';
procedure ap_check_alarm;               external ApacheCore name 'ap_check_alarm';

// Logging functions

procedure ap_log_error;                 external ApacheCore name 'ap_log_error';
procedure ap_log_rerror;                external ApacheCore name 'ap_log_error';

// URI functions

function ap_parse_uri_components;       external ApacheCore name 'ap_parse_uri_components';
function ap_parse_hostinfo_components;  external ApacheCore name 'ap_parse_hostinfo_components';
function ap_unparse_uri_components;     external ApacheCore name 'ap_unparse_uri_components';
function ap_pgethostbyname;             external ApacheCore name 'ap_pgethostbyname';
function ap_pduphostent;                external ApacheCore name 'ap_pduphostent';

// Miscellaneous functions

procedure ap_child_terminate;           external ApacheCore name 'ap_child_terminate';
function ap_default_port;               external ApacheCore name 'ap_default_port';
function ap_is_default_port;            external ApacheCore name 'ap_is_default_port';
function ap_default_port_for_scheme;    external ApacheCore name 'ap_default_port_for_scheme';
function ap_http_method;                external ApacheCore name 'ap_http_method';
function ap_default_type;               external ApacheCore name 'ap_default_type';
function ap_get_basic_auth_pw;          external ApacheCore name 'ap_get_basic_auth_pw';
function ap_get_module_config;          external ApacheCore name 'ap_get_module_config';
function ap_get_remote_logname;         external ApacheCore name 'ap_get_remote_logname';
function ap_get_server_name;            external ApacheCore name 'ap_get_server_name';
function ap_get_server_port;            external ApacheCore name 'ap_get_server_port';
function ap_is_initial_req;             external ApacheCore name 'ap_is_initial_req';

function ap_pcfg_openfile;              external ApacheCore name 'ap_pcfg_openfile';
function ap_cfg_getline;                external ApacheCore name 'ap_cfg_getline';
function ap_cfg_getc;                   external ApacheCore name 'ap_cfg_getc';
function ap_cfg_closefile;              external ApacheCore name 'ap_cfg_closefile';

function ap_getword;                    external ApacheCore name 'ap_getword';

// http_protocol.h

procedure ap_note_auth_failure;         external ApacheCore name 'ap_note_auth_failure';
procedure ap_note_basic_auth_failure;   external ApacheCore name 'ap_note_basic_auth_failure';
procedure ap_note_digest_auth_failure;  external ApacheCore name 'ap_note_digest_auth_failure';

end.

