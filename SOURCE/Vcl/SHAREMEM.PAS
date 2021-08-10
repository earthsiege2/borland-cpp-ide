
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{                                                       }
{       Copyright (C) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ShareMem;

interface





function SysGetMem(Size: Integer): Pointer;
function SysFreeMem(P: Pointer): Integer;
function SysReallocMem(P: Pointer; Size: Integer): Pointer;
function GetHeapStatus: THeapStatus;
function GetAllocMemCount: Integer;
function GetAllocMemSize: Integer;
procedure DumpBlocks;






implementation













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






































procedure InitMemoryManager;
var
  SharedMemoryManager: TMemoryManager;
  MM: Integer;
begin
  // force a static reference to borlndmm.dll, so we don't have to LoadLibrary
  SharedMemoryManager.GetMem := SysGetMem;

  MM := GetModuleHandle(DelphiMM);
  SharedMemoryManager.GetMem := GetProcAddress(MM,'@Borlndmm@SysGetMem$qqri');
  SharedMemoryManager.FreeMem := GetProcAddress(MM,'@Borlndmm@SysFreeMem$qqrpv');
  SharedMemoryManager.ReallocMem := GetProcAddress(MM, '@Borlndmm@SysReallocMem$qqrpvi');
  SetMemoryManager(SharedMemoryManager);
end;

initialization
  if not IsMemoryManagerSet then
    InitMemoryManager;
end.
