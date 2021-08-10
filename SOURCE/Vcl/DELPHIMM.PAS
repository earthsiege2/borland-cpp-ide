
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       Memory Manager Unit                             }
{                                                       }
{       Copyright (C) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

library DelphiMM;

{$IMAGEBASE $41008000}
{$R *.RES}

const
  BorlandMM = 'borlndmm.dll';

function SysGetMem(Size: Integer): Pointer; external BorlandMM name '@Borlndmm@SysGetMem$qqri';
function SysFreeMem(P: Pointer): Integer; external BorlandMM name '@Borlndmm@SysFreeMem$qqrpv';
function SysReallocMem(P: Pointer; Size: Integer): Pointer; external BorlandMM name '@Borlndmm@SysReallocMem$qqrpvi';
function GetHeapStatus: THeapStatus; external BorlandMM;
function GetAllocMemCount: Integer; external BorlandMM;
function GetAllocMemSize: Integer; external BorlandMM;
procedure DumpBlocks; external BorlandMM;
function GetMemory(Size: Integer): Pointer; cdecl; external BorlandMM;
function FreeMemory(P: Pointer): Integer; cdecl; external BorlandMM;
function ReallocMemory(P: Pointer; Size: Integer): Pointer; cdecl; external BorlandMM;

exports
  SysGetMem,
  SysFreeMem,
  SysReallocMem,
  GetMemory,
  FreeMemory,
  ReallocMemory,
  DumpBlocks,
  GetHeapStatus,
  GetAllocMemCount,
  GetAllocMemSize;

begin
end.
