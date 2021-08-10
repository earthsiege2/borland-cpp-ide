{ *********************************************************************** }
{                                                                         }
{ Delphi / Kylix Cross-Platform Runtime Library                           }
{                                                                         }
{ Copyright (c) 2000, 2001 Borland Software Corporation                   }
{                                                                         }
{ *********************************************************************** }

unit Types;

interface

type
  PLongint = System.PLongint;
  {$EXTERNALSYM PLongint}
  PInteger = System.PInteger;
  {$EXTERNALSYM PInteger}
  PSmallInt = System.PSmallInt;
  {$EXTERNALSYM PSmallInt}
  PDouble = System.PDouble;
  {$EXTERNALSYM PDouble}
  PByte = System.PByte;
  {$EXTERNALSYM PByte}

  TIntegerDynArray      = array of Integer;
  {$EXTERNALSYM TIntegerDynArray}
  TCardinalDynArray     = array of Cardinal;
  {$EXTERNALSYM TCardinalDynArray}
  TWordDynArray         = array of Word;
  {$EXTERNALSYM TWordDynArray}
  TSmallIntDynArray     = array of SmallInt;
  {$EXTERNALSYM TSmallIntDynArray}
  TByteDynArray         = array of Byte;
  {$EXTERNALSYM TByteDynArray}
  TShortIntDynArray     = array of ShortInt;
  {$EXTERNALSYM TShortIntDynArray}
  TInt64DynArray        = array of Int64;
  {$EXTERNALSYM TInt64DynArray}
  TLongWordDynArray     = array of LongWord;
  {$EXTERNALSYM TLongWordDynArray}
  TSingleDynArray       = array of Single;
  {$EXTERNALSYM TSingleDynArray}
  TDoubleDynArray       = array of Double;
  {$EXTERNALSYM TDoubleDynArray}
  TBooleanDynArray      = array of Boolean;
  {$EXTERNALSYM TBooleanDynArray}
  TStringDynArray       = array of string;
  {$EXTERNALSYM TStringDynArray}
  TWideStringDynArray   = array of WideString;
  {$EXTERNALSYM TWideStringDynArray}

  PPoint = ^TPoint;
  TPoint = packed record
    X: Longint;
    Y: Longint;
  end;
  {$NODEFINE TPoint}
  tagPOINT = TPoint;
  {$NODEFINE tagPOINT}

  PRect = ^TRect;
  TRect = packed record
    case Integer of
      0: (Left, Top, Right, Bottom: Longint);
      1: (TopLeft, BottomRight: TPoint);
  end;
  {$NODEFINE TRect}

  PSize = ^TSize;
  tagSIZE = packed record
    cx: Longint;
    cy: Longint;
  end;
  {$EXTERNALSYM tagSIZE}
  TSize = tagSIZE;
  SIZE = tagSIZE;
  {$EXTERNALSYM SIZE}

  PSmallPoint = ^TSmallPoint;
  TSmallPoint = packed record
    x: SmallInt;
    y: SmallInt;
  end;

  (*$HPPEMIT 'namespace Types'*)
  (*$HPPEMIT '{'*)
  (*$HPPEMIT '  struct TPoint : public POINT'*)
  (*$HPPEMIT '  {'*)
  (*$HPPEMIT '    TPoint() {}'*)
  (*$HPPEMIT '    TPoint(int _x, int _y) { x=_x; y=_y; }'*)
  (*$HPPEMIT '    TPoint(POINT& pt)'*)
  (*$HPPEMIT '    {'*)
  (*$HPPEMIT '      x = pt.x;'*)
  (*$HPPEMIT '      y = pt.y;'*)
  (*$HPPEMIT '    }'*)
  (*$HPPEMIT '  };'*)
  (*$HPPEMIT ' '*)
  (*$HPPEMIT '  typedef TPoint tagPoint;'*)
  (*$HPPEMIT ' '*)
  (*$HPPEMIT '  struct TRect : public RECT'*)
  (*$HPPEMIT '  {'*)
  (*$HPPEMIT '    TRect() {}'*)
  (*$HPPEMIT '    TRect(const TPoint& TL, const TPoint& BR) { left=TL.x; top=TL.y; right=BR.x; bottom=BR.y; }'*)
  (*$HPPEMIT '    TRect(int l, int t, int r, int b)         { left=l;    top=t;    right=r;    bottom=b;    }'*)
  (*$HPPEMIT '    TRect(RECT& r)'*)
  (*$HPPEMIT '    {'*)
  (*$HPPEMIT '      left    = r.left;'*)
  (*$HPPEMIT '      top     = r.top;'*)
  (*$HPPEMIT '      right   = r.right;'*)
  (*$HPPEMIT '      bottom  = r.bottom;'*)
  (*$HPPEMIT '    }'*)
  (*$HPPEMIT '    int Width () const { return right  - left; }'*)
  (*$HPPEMIT '    int Height() const { return bottom - top ; }'*)
  (*$HPPEMIT '    bool operator ==(const TRect& rc) const '*)
  (*$HPPEMIT '    {'*)
  (*$HPPEMIT '       return left ==  rc.left  && top==rc.top &&     '*)
  (*$HPPEMIT '              right == rc.right && bottom==rc.bottom; '*)
  (*$HPPEMIT '    }'*)
  (*$HPPEMIT '    bool operator !=(const TRect& rc) const '*)
  (*$HPPEMIT '    {  return !(rc==*this); }'*)
  (*$HPPEMIT ' '*)
  (*$HPPEMIT '       __property LONG Left    = { read=left,   write=left   }; '*)
  (*$HPPEMIT '       __property LONG Top     = { read=top,       write=top }; '*)
  (*$HPPEMIT '       __property LONG Right   = { read=right,  write=right  }; '*)
  (*$HPPEMIT '       __property LONG Bottom  = { read=bottom, write=bottom }; '*)
  (*$HPPEMIT '  };'*)
  (*$HPPEMIT '} /* namespace Types */ ;'*)

  DWORD = LongWord;
  {$EXTERNALSYM DWORD}
const
  RT_RCDATA       = PChar(10);
  {$EXTERNALSYM RT_RCDATA}

{$IFDEF LINUX}
type
  PDisplay = Pointer;
  PEvent = Pointer;
  TXrmOptionDescRec = record end;
  XrmOptionDescRec = TXrmOptionDescRec;
  PXrmOptionDescRec = ^TXrmOptionDescRec;
  Widget = Pointer;
  WidgetClass = Pointer;
  ArgList = Pointer;
  Region = Pointer;

const
  {$EXTERNALSYM STGTY_STORAGE}
  STGTY_STORAGE   = 1;
  {$EXTERNALSYM STGTY_STREAM}
  STGTY_STREAM    = 2;
  {$EXTERNALSYM STGTY_LOCKBYTES}
  STGTY_LOCKBYTES = 3;
  {$EXTERNALSYM STGTY_PROPERTY}
  STGTY_PROPERTY  = 4;

  {$EXTERNALSYM STREAM_SEEK_SET}
  STREAM_SEEK_SET = 0;
  {$EXTERNALSYM STREAM_SEEK_CUR}
  STREAM_SEEK_CUR = 1;
  {$EXTERNALSYM STREAM_SEEK_END}
  STREAM_SEEK_END = 2;

  {$EXTERNALSYM LOCK_WRITE}
  LOCK_WRITE     = 1;
  {$EXTERNALSYM LOCK_EXCLUSIVE}
  LOCK_EXCLUSIVE = 2;
  {$EXTERNALSYM LOCK_ONLYONCE}
  LOCK_ONLYONCE  = 4;

  { Unspecified error }
  E_FAIL = HRESULT($80004005);
  {$EXTERNALSYM E_FAIL}

  { Unable to perform requested operation. }
  STG_E_INVALIDFUNCTION = HRESULT($80030001);
  {$EXTERNALSYM STG_E_INVALIDFUNCTION}

  { %l could not be found. }
  STG_E_FILENOTFOUND = HRESULT($80030002);
  {$EXTERNALSYM STG_E_FILENOTFOUND}

  { The path %l could not be found. }
  STG_E_PATHNOTFOUND = HRESULT($80030003);
  {$EXTERNALSYM STG_E_PATHNOTFOUND}

  { There are insufficient resources to open another file. }
  STG_E_TOOMANYOPENFILES = HRESULT($80030004);
  {$EXTERNALSYM STG_E_TOOMANYOPENFILES}

  { Access Denied. }
  STG_E_ACCESSDENIED = HRESULT($80030005);
  {$EXTERNALSYM STG_E_ACCESSDENIED}

  { Attempted an operation on an invalid object. }
  STG_E_INVALIDHANDLE = HRESULT($80030006);
  {$EXTERNALSYM STG_E_INVALIDHANDLE}

  { There is insufficient memory available to complete operation. }
  STG_E_INSUFFICIENTMEMORY = HRESULT($80030008);
  {$EXTERNALSYM STG_E_INSUFFICIENTMEMORY}

  { Invalid pointer error. }
  STG_E_INVALIDPOINTER = HRESULT($80030009);
  {$EXTERNALSYM STG_E_INVALIDPOINTER}

  { There are no more entries to return. }
  STG_E_NOMOREFILES = HRESULT($80030012);
  {$EXTERNALSYM STG_E_NOMOREFILES}

  { Disk is write-protected. }
  STG_E_DISKISWRITEPROTECTED = HRESULT($80030013);
  {$EXTERNALSYM STG_E_DISKISWRITEPROTECTED}

  { An error occurred during a seek operation. }
  STG_E_SEEKERROR = HRESULT($80030019);
  {$EXTERNALSYM STG_E_SEEKERROR}

  { A disk error occurred during a write operation. }
  STG_E_WRITEFAULT = HRESULT($8003001D);
  {$EXTERNALSYM STG_E_WRITEFAULT}

  { A disk error occurred during a read operation. }
  STG_E_READFAULT = HRESULT($8003001E);
  {$EXTERNALSYM STG_E_READFAULT}

  { A share violation has occurred. }
  STG_E_SHAREVIOLATION = HRESULT($80030020);
  {$EXTERNALSYM STG_E_SHAREVIOLATION}

  { A lock violation has occurred. }
  STG_E_LOCKVIOLATION = HRESULT($80030021);
  {$EXTERNALSYM STG_E_LOCKVIOLATION}

  { %l already exists. }
  STG_E_FILEALREADYEXISTS = HRESULT($80030050);
  {$EXTERNALSYM STG_E_FILEALREADYEXISTS}

  { Invalid parameter error. }
  STG_E_INVALIDPARAMETER = HRESULT($80030057);
  {$EXTERNALSYM STG_E_INVALIDPARAMETER}

  { There is insufficient disk space to complete operation. }
  STG_E_MEDIUMFULL = HRESULT($80030070);
  {$EXTERNALSYM STG_E_MEDIUMFULL}

  { Illegal write of non-simple property to simple property set. }
  STG_E_PROPSETMISMATCHED = HRESULT($800300F0);
  {$EXTERNALSYM STG_E_PROPSETMISMATCHED}

  { An API call exited abnormally. }
  STG_E_ABNORMALAPIEXIT = HRESULT($800300FA);
  {$EXTERNALSYM STG_E_ABNORMALAPIEXIT}

  { The file %l is not a valid compound file. }
  STG_E_INVALIDHEADER = HRESULT($800300FB);
  {$EXTERNALSYM STG_E_INVALIDHEADER}

  { The name %l is not valid. }
  STG_E_INVALIDNAME = HRESULT($800300FC);
  {$EXTERNALSYM STG_E_INVALIDNAME}

  { An unexpected error occurred. }
  STG_E_UNKNOWN = HRESULT($800300FD);
  {$EXTERNALSYM STG_E_UNKNOWN}

  { That function is not implemented. }
  STG_E_UNIMPLEMENTEDFUNCTION = HRESULT($800300FE);
  {$EXTERNALSYM STG_E_UNIMPLEMENTEDFUNCTION}

  { Invalid flag error. }
  STG_E_INVALIDFLAG = HRESULT($800300FF);
  {$EXTERNALSYM STG_E_INVALIDFLAG}

  { Attempted to use an object that is busy. }
  STG_E_INUSE = HRESULT($80030100);
  {$EXTERNALSYM STG_E_INUSE}

  { The storage has been changed since the last commit. }
  STG_E_NOTCURRENT = HRESULT($80030101);
  {$EXTERNALSYM STG_E_NOTCURRENT}

  { Attempted to use an object that has ceased to exist. }
  STG_E_REVERTED = HRESULT($80030102);
  {$EXTERNALSYM STG_E_REVERTED}

  { Can't save. }
  STG_E_CANTSAVE = HRESULT($80030103);
  {$EXTERNALSYM STG_E_CANTSAVE}

  { The compound file %l was produced with an incompatible version of storage. }
  STG_E_OLDFORMAT = HRESULT($80030104);
  {$EXTERNALSYM STG_E_OLDFORMAT}

  { The compound file %l was produced with a newer version of storage. }
  STG_E_OLDDLL = HRESULT($80030105);
  {$EXTERNALSYM STG_E_OLDDLL}

  { Share.exe or equivalent is required for operation. }
  STG_E_SHAREREQUIRED = HRESULT($80030106);
  {$EXTERNALSYM STG_E_SHAREREQUIRED}

  { Illegal operation called on non-file based storage. }
  STG_E_NOTFILEBASEDSTORAGE = HRESULT($80030107);
  {$EXTERNALSYM STG_E_NOTFILEBASEDSTORAGE}

  { Illegal operation called on object with extant marshallings. }
  STG_E_EXTANTMARSHALLINGS = HRESULT($80030108);
  {$EXTERNALSYM STG_E_EXTANTMARSHALLINGS}

  { The docfile has been corrupted. }
  STG_E_DOCFILECORRUPT = HRESULT($80030109);
  {$EXTERNALSYM STG_E_DOCFILECORRUPT}

  { OLE32.DLL has been loaded at the wrong address. }
  STG_E_BADBASEADDRESS = HRESULT($80030110);
  {$EXTERNALSYM STG_E_BADBASEADDRESS}

  { The file download was aborted abnormally.  The file is incomplete. }
  STG_E_INCOMPLETE = HRESULT($80030201);
  {$EXTERNALSYM STG_E_INCOMPLETE}

  { The file download has been terminated. }
  STG_E_TERMINATED = HRESULT($80030202);
  {$EXTERNALSYM STG_E_TERMINATED}

  { The underlying file was converted to compound file format. }
  STG_S_CONVERTED = $00030200;
  {$EXTERNALSYM STG_S_CONVERTED}

  { The storage operation should block until more data is available. }
  STG_S_BLOCK = $00030201;
  {$EXTERNALSYM STG_S_BLOCK}

  { The storage operation should retry immediately. }
  STG_S_RETRYNOW = $00030202;
  {$EXTERNALSYM STG_S_RETRYNOW}

  { The notified event sink will not influence the storage operation. }
  STG_S_MONITORING = $00030203;
  {$EXTERNALSYM STG_S_MONITORING}

  GUID_NULL: TGUID = '{00000000-0000-0000-0000-000000000000}';

type
  TOleChar = WideChar;
  POleStr = PWideChar;
  PPOleStr = ^POleStr;

  PCLSID = PGUID;
  TCLSID = TGUID;

{ 64-bit large integer }

  Largeint = Int64;
  {$EXTERNALSYM Largeint}

//  DWORD = LongWord;
//  {$EXTERNALSYM DWORD}
  PDWORD = ^DWORD;
  {$EXTERNALSYM PDWORD}

  { File System time stamps are represented with the following structure: }
  PFileTime = ^TFileTime;
  _FILETIME = packed record
    dwLowDateTime: DWORD;
    dwHighDateTime: DWORD;
  end;
  {$EXTERNALSYM _FILETIME}
  TFileTime = _FILETIME;
  FILETIME = _FILETIME;
  {$EXTERNALSYM FILETIME}

{ IStream interface }

  PStatStg = ^TStatStg;
  {$EXTERNALSYM tagSTATSTG}
  tagSTATSTG = packed record
    pwcsName: POleStr;
    dwType: Longint;
    cbSize: Largeint;
    mtime: TFileTime;
    ctime: TFileTime;
    atime: TFileTime;
    grfMode: Longint;
    grfLocksSupported: Longint;
    clsid: TCLSID;
    grfStateBits: Longint;
    reserved: Longint;
  end;
  TStatStg = tagSTATSTG;
  {$EXTERNALSYM STATSTG}
  STATSTG = TStatStg;

  IClassFactory = interface(IUnknown)
    ['{00000001-0000-0000-C000-000000000046}']
    function CreateInstance(const unkOuter: IUnknown; const iid: TGUID;
      out obj): HResult; stdcall;
    function LockServer(fLock: LongBool): HResult; stdcall;
  end;

  {$EXTERNALSYM ISequentialStream}
  ISequentialStream = interface(IUnknown)
    ['{0c733a30-2a1c-11ce-ade5-00aa0044773d}']
    function Read(pv: Pointer; cb: Longint; pcbRead: PLongint): HResult;
      stdcall;
    function Write(pv: Pointer; cb: Longint; pcbWritten: PLongint): HResult;
      stdcall;
  end;

  {$EXTERNALSYM IStream}
  IStream = interface(ISequentialStream)
    ['{0000000C-0000-0000-C000-000000000046}']
    function Seek(dlibMove: Largeint; dwOrigin: Longint;
      out libNewPosition: Largeint): HResult; stdcall;
    function SetSize(libNewSize: Largeint): HResult; stdcall;
    function CopyTo(stm: IStream; cb: Largeint; out cbRead: Largeint;
      out cbWritten: Largeint): HResult; stdcall;
    function Commit(grfCommitFlags: Longint): HResult; stdcall;
    function Revert: HResult; stdcall;
    function LockRegion(libOffset: Largeint; cb: Largeint;
      dwLockType: Longint): HResult; stdcall;
    function UnlockRegion(libOffset: Largeint; cb: Largeint;
      dwLockType: Longint): HResult; stdcall;
    function Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult;
      stdcall;
    function Clone(out stm: IStream): HResult; stdcall;
  end;
{$ENDIF} { LINUX }

function EqualRect(const R1, R2: TRect): Boolean;
function Rect(Left, Top, Right, Bottom: Integer): TRect;
{$EXTERNALSYM Rect}
function Bounds(ALeft, ATop, AWidth, AHeight: Integer): TRect;
{$EXTERNALSYM Bounds}
function Point(X, Y: Integer): TPoint;
{$EXTERNALSYM Point}
function PtInRect(const Rect: TRect; const P: TPoint): Boolean;
function IntersectRect(out Rect: TRect; const R1, R2: TRect): Boolean;
function UnionRect(out Rect: TRect; const R1, R2: TRect): Boolean;
function IsRectEmpty(const Rect: TRect): Boolean;
function OffsetRect(var Rect: TRect; DX: Integer; DY: Integer): Boolean;
function CenterPoint(const Rect: TRect): TPoint;

type
  TValueRelationship = -1..1;

const
  LessThanValue = Low(TValueRelationship);
  EqualsValue = 0;
  GreaterThanValue = High(TValueRelationship);

implementation

function EqualRect(const R1, R2: TRect): Boolean;
begin
  Result := (R1.Left = R2.Left) and (R1.Right = R2.Right) and
    (R1.Top = R2.Top) and (R1.Bottom = R2.Bottom);
end;

function Rect(Left, Top, Right, Bottom: Integer): TRect;
begin
  Result.Left := Left;
  Result.Top := Top;
  Result.Bottom := Bottom;
  Result.Right := Right;
end;

function Point(X, Y: Integer): TPoint;
begin
  Result.X := X;
  Result.Y := Y;
end;

function PtInRect(const Rect: TRect; const P: TPoint): Boolean;
begin
  Result := (P.X >= Rect.Left) and (P.X < Rect.Right) and (P.Y >= Rect.Top)
    and (P.Y < Rect.Bottom);
end;

function IntersectRect(out Rect: TRect; const R1, R2: TRect): Boolean;
begin
  Rect := R1;
  if R2.Left > R1.Left then Rect.Left := R2.Left;
  if R2.Top > R1.Top then Rect.Top := R2.Top;
  if R2.Right < R1.Right then Rect.Right := R2.Right;
  if R2.Bottom < R1.Bottom then Rect.Bottom := R2.Bottom;
  Result := not IsRectEmpty(Rect);
  if not Result then FillChar(Rect, SizeOf(Rect), 0);
end;

function UnionRect(out Rect: TRect; const R1, R2: TRect): Boolean;
begin
  Rect := R1;
  if not IsRectEmpty(R2) then
  begin
    if R2.Left < R1.Left then Rect.Left := R2.Left;
    if R2.Top < R1.Top then Rect.Top := R2.Top;
    if R2.Right > R1.Right then Rect.Right := R2.Right;
    if R2.Bottom > R1.Bottom then Rect.Bottom := R2.Bottom;
  end;
  Result := not IsRectEmpty(Rect);
  if not Result then FillChar(Rect, SizeOf(Rect), 0);
end;

function IsRectEmpty(const Rect: TRect): Boolean;
begin
  Result := (Rect.Right <= Rect.Left) or (Rect.Bottom <= Rect.Top);
end;

function OffsetRect(var Rect: TRect; DX: Integer; DY: Integer): Boolean;
begin
  if @Rect <> nil then // Test to increase compatiblity with Windows
  begin
    Inc(Rect.Left, DX);
    Inc(Rect.Right, DX);
    Inc(Rect.Top, DY);
    Inc(Rect.Bottom, DY);
    Result := True;
  end
  else
    Result := False;
end;

function Bounds(ALeft, ATop, AWidth, AHeight: Integer): TRect;
begin
  with Result do
  begin
    Left := ALeft;
    Top := ATop;
    Right := ALeft + AWidth;
    Bottom :=  ATop + AHeight;
  end;
end;

function CenterPoint(const Rect: TRect): TPoint;
begin
  with Rect do
  begin
    Result.X := (Right - Left) div 2 + Left;
    Result.Y := (Bottom - Top) div 2 + Top;
  end;
end;

end.

