
{*******************************************************}
{                                                       }
{       Delphi Visual Component Library                 }
{       NSAPI to ISAPI interface library                }
{                                                       }
{       Copyright (c) 1997,98 Inprise Corporation       }
{                                                       }
{*******************************************************}

{$IMAGEBASE $40000000}

library ISAPIter;

uses
  SysUtils,
  Classes,
  NSAPI,
  {$IFDEF NETSCAPE3}
  NS30Fix,
  {$ENDIF}
  {$IFDEF NETSCAPE35}
  NS35Fix,
  {$ENDIF}
  {$IFDEF NETSCAPE36}
  NS36Fix,
  {$ENDIF}
  NSToIS;

{$R *.RES}

function GetDocumentRoot(os: PHttpdObjSet): string;
var
  obj: PHttpdObject;
  dt: PDtable;
  dir: PDirective;
  I, J: Integer;
begin
  Result := '';
  if os <> nil then
  begin
    obj := objset_findbyname('default', nil, os);
    if obj <> nil then
    begin
      dt := obj.dt;
      for I := 0 to obj.nd - 1 do
      begin
        dir := dt.inst;
        for J := 0 to dt.ni - 1 do
        begin
          if (dir <> nil) and (dir.param <> nil) then
            if CompareText(NSstr2String(pblock_findval('fn', dir.param)), 'document-root') = 0 then
            begin
              Result := NSstr2String(pblock_findval('root', dir.param));
              Exit;
            end;
          Inc(dir);
        end;
        Inc(dt);
      end;
    end;
  end;
end;

const
  sInternalServerError = '<html><title>Internal Server Error 500</title>'#13#10 +
    '<h1>Internal Server Error 500</h1><hr>'#13#10 +
    'Exception: %s<br>'#13#10 +
    'Message: %s<br></html>'#13#10;

function HandleServerException(E: Exception; pb: PPblock; sn: PSession; rq: Prequest): Integer;
var
  ResultText: string;
  ContentLen: Integer;
begin
  if net_isalive(sn.csd) then
  begin
    http_status(sn, rq, PROTOCOL_SERVER_ERROR, PChar(E.Message));
    ResultText := Format(sInternalServerError, [E.ClassName, E.Message]);
    ContentLen := Length(ResultText);
    param_free(pblock_remove('content-type', rq.srvhdrs));
    pblock_nvinsert('content-type', 'text/html', rq.srvhdrs);
    pblock_nninsert('content-length', ContentLen, rq.srvhdrs);
    if http_start_response(sn, rq) <> REQ_NOACTION then
      net_write(sn.csd, PChar(ResultText), ContentLen);
  end;
  Result := REQ_ABORTED;
end;

procedure terminate_isapi(parameter: Pointer); cdecl; export;
begin
  DoneISAPIApplicationList;
end;

function init_isapi(pb: PPblock; sn: PSession; rq: Prequest): Integer; cdecl; export;
begin
  InitISAPIApplicationList;
  magnus_atrestart(terminate_isapi, nil);
  Result := REQ_PROCEED;
end;

function handle_isapi(pb: PPblock; sn: PSession; rq: Prequest): Integer; cdecl; export;
var
  DLLPath: string;
  ISAPIApplication: TISAPIApplication;
  ISAPISession: TISAPISession;
begin
  try
    DLLPath := UnixPathToDosPath(NSstr2String(pblock_findval('dll-path', rq.vars)));
    InitISAPIApplicationList;
    ISAPIApplication := ISAPIApplicationList.LoadApplication(DLLPath);
    ISAPISession := TISAPISession.Create(pb, sn, rq, ISAPIApplication);
    try
      ISAPISession.ProcessExtension;
      Result := REQ_PROCEED;
    finally
      ISAPISession.Free;
    end;
  except
    Result := HandleServerException(Exception(ExceptObject), pb, sn, rq);
  end;
end;

function check_isapi(pb: PPblock; sn: PSession; rq: Prequest): Integer; cdecl; export;
var
  Path, PathInfo: string;
begin
  try
    Path := NSstr2String(pblock_findval('path', rq.vars));
    pblock_nvinsert('dll-path', PChar(Path), rq.vars);
    PathInfo := NSstr2String(pblock_findval('path-info', rq.vars));
    pblock_nvinsert('path-translated', PChar(GetDocumentRoot(rq.os) + PathInfo), rq.vars);
    Result := REQ_PROCEED;
  except
    Result := HandleServerException(Exception(ExceptObject), pb, sn, rq);
  end;
end;

function log_isapi(pb: PPblock; sn: PSession; rq: Prequest): Integer; cdecl; export;
begin
  InitISAPIApplicationList;
  Result := ISAPIApplicationList.InitLog(pb, sn, rq);
end;

exports
  handle_isapi,
  check_isapi,
  log_isapi,
  init_isapi;

begin
end.
