{ *********************************************************************** }
{                                                                         }
{ Delphi / Kylix Cross-Platform Runtime Library                           }
{                                                                         }
{ Copyright (c) 1995-2001 Borland Software Corporation                    }
{                                                                         }
{ *********************************************************************** }

unit ShareMem;

interface                             

{$IFDEF MEMORY_DIAG}
type
  TBlockEnumProc = function (Block: Pointer): Boolean;
{$ENDIF}

function SysGetMem(Size: Integer): Pointer;
function SysFreeMem(P: Pointer): Integer;
function SysReallocMem(P: Pointer; Size: Integer): Pointer;
function GetHeapStatus: THeapStatus;
function GetAllocMemCount: Integer;
function GetAllocMemSize: Integer;
procedure DumpBlocks;

{$IFDEF MEMORY_DIAG}
function InitBlockMarking: Boolean;
function MarkBlocks: Integer;
function GetMarkedBlocks(MarkID: Integer; Proc: TBlockEnumProc): Boolean;
{$ENDIF}

implementation

{$IFDEF GLOBALALLOC}
uses Windows;
{$ENDIF}

{$IFDEF MEMORY_DIAG}
type
  TInitBlockMarking = function: Boolean;
  TMarkBlocks = function: Integer;
  TGetMarkedBlocks = function (MarkID: Integer; Proc: TBlockEnumProc): Boolean;

var
  MMHandle: Integer = 0;
  SysInitBlockMarking: TInitBlockMarking = nil;
  SysMarkBlocks: TMarkBlocks = nil;
  SysGetMarkedBlocks: TGetMarkedBlocks = nil;
{$ENDIF}

const
  DelphiMM = 'borlndmm.dll';

function SysGetMem(Size: Integer): Pointer; external DelphiMM name '@Borlndmm@SysGetMem$qqri';
function SysFreeMem(P: Pointer): Integer; external DelphiMM name '@Borlndmm@SysFreeMem$qqrpv';
function SysReallocMem(P: Pointer; Size: Integer): Pointer; external DelphiMM name '@Borlndmm@SysReallocMem$qqrpvi';
function GetHeapStatus: THeapStatus; external DelphiMM;
function GetAllocMemCount: Integer; external DelphiMM;
function GetAllocMemSize: Integer; external DelphiMM;
procedure DumpBlocks; external DelphiMM;

function GetModuleHandle(lpModuleName: PChar): Integer; stdcall;
  external 'kernel32.dll' name 'GetModuleHandleA';
function GetProcAddress(hModule: Integer; lpProcName: PChar): Pointer; stdcall;
  external 'kernel32.dll' name 'GetProcAddress';

{$IFDEF MEMORY_DIAG}

procedure InitMMHandle;
begin
  if MMHandle = 0 then MMHandle := GetModuleHandle(DelphiMM);
end;

function InitBlockMarking: Boolean;
begin
  InitMMHandle;
  if @SysInitBlockMarking = nil then
    @SysInitBlockMarking := GetProcAddress(MMHandle, 'InitBlockMarking');
  if @SysInitBlockMarking <> nil then
    Result := SysInitBlockMarking
  else Result := False;
end;

function MarkBlocks: Integer;
begin
  InitMMHandle;
  if @SysMarkBlocks = nil then
    @SysMarkBlocks := GetProcAddress(MMHandle, 'MarkBlocks');
  if @SysMarkBlocks <> nil then
    Result := SysMarkBlocks
  else Result := -1;
end;

function GetMarkedBlocks(MarkID: Integer; Proc: TBlockEnumProc): Boolean;
begin
  InitMMHandle;
  if @SysGetMarkedBlocks = nil then
    @SysGetMarkedBlocks := GetProcAddress(MMHandle, 'GetMarkedBlocks');
  if @SysGetMarkedBlocks <> nil then
    Result := SysGetMarkedBlocks(MarkID, Proc)
  else Result := False;
end;
{$ENDIF}

{$IFDEF GLOBALALLOC}
function xSysGetMem(Size: Integer): Pointer;
begin
  Result := GlobalAllocPtr(HeapAllocFlags, Size);
end;

function xSysFreeMem(P: Pointer): Integer;
begin
  Result := GlobalFreePtr(P);
end;

function xSysReallocMem(P: Pointer; Size: Integer): Pointer;
begin
  Result := GlobalReallocPtr(P, Size, 0);
end;
{$ENDIF}


procedure InitMemoryManager;
var
  SharedMemoryManager: TMemoryManager;
  MM: Integer;
begin
  // force a static reference to borlndmm.dll, so we don't have to LoadLibrary
  SharedMemoryManager.GetMem := SysGetMem;

  MM := GetModuleHandle(DelphiMM);
{$IFDEF GLOBALALLOC}
  SharedMemoryManager.GetMem := xSysGetMem;
  SharedMemoryManager.FreeMem := xSysFreeMem;
  SharedMemoryManager.ReallocMem := xSysReallocMem;
{$ELSE}
  SharedMemoryManager.GetMem := GetProcAddress(MM,'@Borlndmm@SysGetMem$qqri');
  SharedMemoryManager.FreeMem := GetProcAddress(MM,'@Borlndmm@SysFreeMem$qqrpv');
  SharedMemoryManager.ReallocMem := GetProcAddress(MM, '@Borlndmm@SysReallocMem$qqrpvi');
{$ENDIF}
  SetMemoryManager(SharedMemoryManager);
end;

initialization
  if not IsMemoryManagerSet then
    InitMemoryManager;
end.
