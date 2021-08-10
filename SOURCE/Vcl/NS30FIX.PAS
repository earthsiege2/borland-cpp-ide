
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       This module contains only the prototypes for    }
{       the Netscape 3.0 Internet Server API used in    }
{       the ISAPITER.DLL                                }
{                                                       }
{       Note: To recompile ISAPITER.DLL for Netscape    }
{       3.0 servers you must conditionally define       }
{       NETSCAPE3.                                      }
{                                                       }
{       Copyright (C) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit NS30Fix;

{$WEAKPACKAGEUNIT}

interface

uses Windows, NSAPI;

const
  nshttp = 'ns-httpd30.dll';

function system_version: PChar; cdecl;
procedure system_free(ptr: Pointer); cdecl;
procedure magnus_atrestart(fn: TMagnusAtRestart; data: Pointer); cdecl;
function system_fopenWA(path: PChar): SYS_FILE; cdecl;
procedure system_fclose(fd: SYS_FILE); cdecl;
function system_fwrite_atomic(fd: SYS_FILE; buf: Pointer; sz: Integer): Integer; cdecl;
function param_free(pp: PPbParam): Integer; cdecl;
function pblock_create(n: Integer): PPblock; cdecl;
procedure pblock_free(pb: PPblock); cdecl;
function pblock_findval(name: PChar; pb: PPblock): PChar; cdecl;
function pblock_nvinsert(name, value: PChar; pb: PPblock): PPbParam; cdecl;
function pblock_nninsert(name: PChar; value: Integer; pb: PPblock): PPbParam; cdecl;
function pblock_pblock2str(pb: PPblock; str: PChar): PChar; cdecl;
procedure pblock_copy(src, dst: PPblock); cdecl;
function _pblock_fr(name: PChar; pb: PPblock; remove: BOOL): PPbParam; cdecl;
function net_read(sd: SYS_NETFD; buf: PChar; sz, timeout: Integer): Integer; cdecl;
function net_write(sd: SYS_NETFD; buf: PChar; sz: Integer): Integer; cdecl;
function net_isalive(sd: SYS_NETFD): BOOL; cdecl;
function session_dns_lookup(sn: PSession; verify: BOOL): PChar; cdecl;
function shexp_casecmp(str, exp: PChar): Integer; cdecl;
function util_env_create(env: PPCharArray; n: Integer; var pos: Integer): PPCharArray; cdecl;
function util_env_str(name, value: PChar): PChar; cdecl;
procedure util_env_free(env: PPCharArray); cdecl;
function util_env_find(env: PPCharArray; name: PChar): PChar; cdecl;
function objset_findbyname(name: PChar; ign, os: PHttpdObjSet): PHttpdObject; cdecl;
function conf_getglobals: PConfGlobalVars; cdecl;
function request_translate_uri(uri: PChar; sn: PSession): PChar; cdecl;
function http_scan_headers(sn: PSession; buf: PNetBuf; t: PChar;
  headers: PPblock): Integer; cdecl;
function http_start_response(sn: PSession; rq: PRequest): Integer; cdecl;
function http_hdrs2env(pb: PPblock): PPCharArray; cdecl;
procedure http_status(sn: PSession; rq: PRequest; n: Integer; r: PChar); cdecl;

function pblock_remove(name: PChar; pb: PPblock): PPbParam;
function session_dns(sn: PSession): PChar;
function NSstr2String(nsStr: PChar): string;

implementation

function pblock_remove(name: PChar; pb: PPblock): PPbParam;
begin
  Result := _pblock_fr(name,pb,True);
end;

function session_dns(sn: PSession): PChar;
begin
  Result := session_dns_lookup(sn, False);
end;

function NSstr2String(nsStr: PChar): string;
begin
  Result := nsStr;
  system_free(nsStr);
end;

{ imports }

function system_version; external nshttp name 'INTsystem_version';
procedure system_free; external nshttp name 'INTsystem_free';
procedure magnus_atrestart; external nshttp name 'INTmagnus_atrestart';
function system_fopenWA; external nshttp name 'INTsystem_fopenWA';
procedure system_fclose; external nshttp name 'INTsystem_fclose';
function system_fwrite_atomic; external nshttp name 'INTsystem_fwrite_atomic';
function param_free; external nshttp name 'INTparam_free';
function pblock_create; external nshttp name 'INTpblock_create';
procedure pblock_free; external nshttp name 'INTpblock_free';
function pblock_findval; external nshttp name 'INTpblock_findval';
function pblock_nvinsert; external nshttp name 'INTpblock_nvinsert';
function pblock_nninsert; external nshttp name 'INTpblock_nninsert';
function pblock_pblock2str; external nshttp name 'INTpblock_pblock2str';
procedure pblock_copy; external nshttp name 'INTpblock_copy';
function _pblock_fr; external nshttp name 'INTpblock_fr';
function net_read; external nshttp name 'INTnet_read';
function net_write; external nshttp name 'INTnet_write';
function net_isalive; external nshttp name 'INTnet_isalive';
function session_dns_lookup; external nshttp name 'INTsession_dns_lookup';
function shexp_casecmp; external nshttp name 'INTshexp_casecmp';
function util_env_create; external nshttp name 'INTutil_env_create';
function util_env_str; external nshttp name 'INTutil_env_str';
procedure util_env_free; external nshttp name 'INTutil_env_free';
function util_env_find; external nshttp name 'INTutil_env_find';
function objset_findbyname; external nshttp name 'INTobjset_findbyname';
function conf_getglobals; external nshttp name 'INTconf_getglobals';
function request_translate_uri; external nshttp name 'servact_translate_uri';
function http_scan_headers; external nshttp name 'INThttp_scan_headers';
function http_start_response; external nshttp name 'INThttp_start_response';
function http_hdrs2env; external nshttp name 'INThttp_hdrs2env';
procedure http_status; external nshttp name 'INThttp_status';

end.
