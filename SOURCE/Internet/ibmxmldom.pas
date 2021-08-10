
{*******************************************************}
{                                                       }
{     Borland Delphi Visual Component Library           }
{     IBM XML DOM Implementation Wrapper                }
{                                                       }
{   Copyright (c) 2000 Borland Software Corporation     }
{                                                       }
{*******************************************************}

unit ibmxmldom;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, 
{$ELSE}
  Libc,
{$ENDIF}
  SysUtils, xmldom;

type

{ TIBMDOMImplementationFactory }

  TIBMDOMImplementationFactory = class(TDOMVendor)
  private
    FLibHandle: Integer;
  public
    destructor Destroy; override;
    function DOMImplementation: IDOMImplementation; override;
    function Description: String; override;
  end;

var
  IBMXML_DOM: TIBMDOMImplementationFactory;

implementation

const
{$IFDEF MSWINDOWS}
  ModName = 'ibmxmldom.dll'; //!!!!!
{$ELSE}
  ModName = 'libibmxmldom.so'; //!!!!!

function LoadLibrary(LibraryName: PChar): Integer;
begin
  Result := Integer (dlopen(PChar(LibraryName), 0));
end;

function FreeLibrary(LibHandle: Integer): Integer;
begin
  Result := dlclose(Pointer(LibHandle));
end;

function GetProcAddress(Handle: THandle; ProcName: PChar): Pointer;
begin
  Result := dlsym(Pointer(Handle), ProcName);
end;

procedure RaiseLastWin32Error;
begin
  Writeln(dlerror);
  Assert(False);
end;

procedure  SetEnvironmentVariable(Vname: PChar; Value: PChar);
begin
  SetEnv(Vname, Value, 1);
end;

//TODO
procedure  GetModuleFileName(LibHandle: Integer; NameBuf: PChar; len: Integer);
begin
  NameBuf := '../../bin';
end;
{$ENDIF}

{ TIBMDOMImplementationFactory }

destructor TIBMDOMImplementationFactory.Destroy;
begin
  if FLibHandle > 0 then
    FreeLibrary(FLibHandle);
  FLibHandle := 0;
end;

function TIBMDOMImplementationFactory.Description: String;
begin
  Result := 'IBMXML';
end;

function TIBMDOMImplementationFactory.DOMImplementation: IDOMImplementation;
type
  TGetDOMProc = procedure(var DOMImplementation: IDOMImplementation); stdcall;
var
  GetDOMProc: TGetDOMProc;
  NameBuf: string;
begin
  if FLibHandle = 0 then
    FLibHandle := LoadLibrary(ModName);
  if FLibHandle = 0 then
    RaiseLastWin32Error;
  GetDOMProc := GetProcAddress(FLibHandle, 'GetDOMImplementation'); { Do not localize }
  SetLength(NameBuf, MAX_PATH);
  GetModuleFileName(FLibHandle, PChar(NameBuf), MAX_PATH);
  Assert(Assigned(GetDOMProc));
  SetEnvironmentVariable('ICU_DATA', PChar(ExtractFilePath(NameBuf)));  // do not localize
  GetDOMProc(Result);
end;

initialization
  IBMXML_DOM := TIBMDOMImplementationFactory.Create;
  RegisterDOMVendor(IBMXML_DOM);
finalization
  UnRegisterDOMVendor(IBMXML_DOM);
  IBMXML_DOM.Free;
end.
