{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                Interface Invoker Support              }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit Rio;

{$IFDEF NO_SOAP_RUNTIME}
{ If SOAP components are not packaged }
(*$HPPEMIT '#pragma link "dclsoap.lib"' *)
{$ENDIF}

{ RIO is currently implemented with WININET }
(*$HPPEMIT '#if defined(__WIN32__)'     *)
(*$HPPEMIT '#pragma link "wininet.lib"' *)
(*$HPPEMIT '#endif'                     *)

interface

uses Classes, IntfInfo, OPConvert, InvokeRegistry, WebNode;

const
  StubSize = 19;    { Max size of call stubs in the generated vtables }

type

  TBeforeExecuteEvent = procedure(const MethodName: string; var SOAPRequest: InvString) of object;
  TAfterExecuteEvent  = procedure(const MethodName: string; SOAPResponse: TStream) of object;

  TRIO = class(TComponent, IUnknown)
  private
    FIID: TGUID;
    FInterfaceBound: Boolean;
    FRefCount: Integer;
    IntfTable: Pointer;             { Generated vtable for the object   }
    IntfTableP: Pointer;            { Pointer to the generated vtable   }
    IntfStubs: Pointer;             { Pointer to generated vtable thunks}
    StubAddr: Pointer;
    ErrorStubAddr: Pointer;
    IntfReg: Boolean;
    LegalCC: Boolean;
    HasRTTI: Boolean;
    { Could make these into a local object to be used by  }
    { GenVTable.  It would save space.  Consider it for the next release  }
    CallStub: array[0..StubSize-1] of Byte;
    CallStubIdx: Integer;

    FContext: TInvContext;
    FOnAfterExecute: TAfterExecuteEvent;
    FOnBeforeExecute: TBeforeExecuteEvent;

    function  Generic(CallID: Integer; Params: Pointer): Int64;
    procedure GenericStub;

    procedure ErrorEntry;

    function  GenVTable(const IID: TGUID): Boolean;

    { Mini codegenerator assist functions.  Could be bundled with }
    { CallStub in a separate object.  Maybe for next release. }
    procedure GenPushI(I: Integer);
    procedure GenDWORD(DW: LongWord);
    procedure GenByte(B: Byte);
    procedure GenRET(BytesPushed: Word = 0);

    { Pseudo AddRef/Release.  See the comment at TRIO._AddRef.  }
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  protected
    IntfMD: TIntfMetaData;
    FConverter: IOPConvert;
    FWebNode: IWebNode;
    function QueryInterface(const IID: TGUID; out Obj): HResult; override; stdcall;
    procedure DoAfterExecute(const MethodName: string; Response: TStream); virtual;
    procedure DoBeforeExecute(const MethodName: string; var Request: InvString); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    class function NewInstance: TObject; override;
    property RefCount: Integer read FRefCount;
    property Converter: IOPConvert read FConverter write FConverter;
    property WebNode: IWebNode read FWebNode write FWebNode;
  published
    property OnAfterExecute: TAfterExecuteEvent read FOnAfterExecute write FOnAfterExecute;
    property OnBeforeExecute: TBeforeExecuteEvent read FOnBeforeExecute write FOnBeforeExecute;
  end;

implementation

uses {$IFDEF MSWINDOWS}Windows{$ENDIF}{$IFDEF LINUX}Libc{$ENDIF},
  SysUtils, XMLDoc, SOAPConst, InvRules, TypInfo, XMLIntf;


type
  TProc =  procedure of object;
  TObjFunc = function: Integer of Object;  stdcall;
  TQIFunc =  function(const IID: TGUID; out Obj): HResult of object; stdcall;
  PProc = ^TProc;
  TCracker = record
    case integer of
      0: (Fn: TProc);
      1: (Ptr: Pointer);
      2: (ObjFn: TObjFunc);
      3: (QIFn: TQIFunc);
    end;

{
  IncPtr

  Slower than doing it inline, but not much.  This function just
  bumps a pointer value by the number of bytes specified.  It modifies
  the pointer in place, so you can use it just like Inc.  Also makes
  the code much more readable.
}
procedure IncPtr(var P; I: Integer = 1);
asm
        ADD     [EAX], EDX
end;

{
  AddPtr

  Slower than doing it inline, but not much.  This function just
  bumps a pointer value by the number of bytes specified.  It does
  not modify the pointer in place like IncPtr.  You use this where
  you want to do the addition, and then assign the result to some
  other variable.  Use it to make the code more readable.
}
function AddPtr(P: Pointer; I: Integer = 1): Pointer;
asm
        ADD     EAX, EDX
end;

{
  TRIO.GenPushI

  Generates a PUSH immediate instruction to the call stub buffer.  If the
  immediate value fits in a byte, we encode it efficiently, otherwise
  we use the PUSH imm32 encoding.
}
procedure TRIO.GenPushI(I: Integer);
begin
  if I < 256 then
  begin
    CallStub[CallStubIdx] := $6A;
    CallStub[CallStubIdx + 1] := I;
    Inc(CallStubIdx, 2);
  end
  else
  begin
    CallStub[CallStubIdx] := $68;
    PInteger(@CallStub[CallStubIdx + 1])^ := I;
    Inc(CallStubIdx, 5);
  end;
end;

{
  TRIO.GenByte

  Generates a byte to the call stub buffer.
}
procedure TRIO.GenByte(B: Byte);
begin
  CallStub[CallStubIdx] := B;
  Inc(CallStubIdx);
end;

{
  TRIO.GenDWORD

  Generates a DWORD (4 bytes) to the call stub buffer.
}
procedure TRIO.GenDWORD(DW: LongWord);
begin
{$R-}
  CallStub[CallStubIdx] := DW;
{$R+}
  PLongWord(@CallStub[CallStubIdx])^ := DW;
  Inc(CallStubIdx, 4);
end;

{
  TRIO.GenRet

  Generates a return instruction to the call stub buffer .  If BytesPushed
  is 0, then we generate a one byte return.  Otherwise, we generate the
  3 byte encoding.
}
procedure TRIO.GenRET(BytesPushed: Word);
begin
  if BytesPushed > 0 then
  begin
    GenByte($C2);
    GenByte(Byte(BytesPushed and $FF));
    GenByte(Byte((BytesPushed and $FF00) shr 8));
  end
  else
    GenByte($C3);
end;

const
  NumEntriesInIInterface = 3; { QI, AddRef, Release }

function TRIO.GenVTable(const IID: TGUID): Boolean;
var
  Info: Pointer;
  I, J, BytesPushed: Integer;
  VTable: PPointer;
  Thunk: Pointer;
  P: PByte;
  Crack: TCracker;
begin
  Result := True;
  FIID := IID;
  Info := InvRegistry.GetInterfaceTypeInfo(IID);
  if Info = nil then
  begin
    Result := False;
    IntfReg := False;
    Exit;
  end else
    IntfReg := True;
  try
    GetIntfMetaData(Info, IntfMD, True);
  except
    HasRTTI := False;
    Exit;
  end;
  HasRTTI := True;

  { Check to make sure that we don't have a bad calling convention in here. }
  { TODO: Should we check for unsupported types, parameter qualifiers
          ( i.e. do we support untyped params ? ),
          Also, what is checked here and what is checked in the IOPConvert methods ? }
  LegalCC := True;
  for I := 0 to Length(IntfMD.MDA) -1 do
  begin
    if IntfMD.MDA[I].HasRTTI then
      with IntfMD.MDA[I]  do
        if CC in [ccReg {, ccSafeCall} ] then
        begin
          Result := False;
          LegalCC := False;
          Exit;
        end;
  end;

  Crack.Fn := GenericStub;
  StubAddr := Crack.Ptr;

  Crack.Fn := ErrorEntry;
  ErrorStubAddr := Crack.Ptr;

  { Allocate two blocks - one for the vtable itself, one for }
  { the thunks. }
  GetMem(IntfTable, (Length(IntfMD.MDA) + NumEntriesInIInterface) * 4);
  IntfTableP := @IntfTable;
  GetMem(IntfStubs, (Length( IntfMD.MDA) + NumEntriesInIInterface) * StubSize );

  { Load the IUnknown vtable entries }
  VTable := PPointer(IntfTable);
  Crack.QIFn := QueryInterface;
  VTable^ := Crack.Ptr;
  IncPtr(VTable, 4);
  Crack.ObjFn := _AddRef;
  VTable^ := Crack.Ptr;
  IncPtr(VTable, 4);
  Crack.ObjFn := _Release;
  VTable^ := Crack.Ptr;
  IncPtr(VTable, 4);

  { Skip over the IInterface entries }
  VTable := AddPtr(IntfTable, NumEntriesInIInterface * 4);

  Thunk := AddPtr(IntfStubs, NumEntriesInIInterface * StubSize);

  { Now walk all the interface entries, and generate vtable thunks }
  for I := NumEntriesInIInterface to Length(IntfMD.MDA) - 1 do
  begin
    { Reset the call stub buffer }
    CallStubIdx := 0;

    if not IntfMD.MDA[I].HasRTTI then
    begin
      { Generate the CALL [mem] to the error stub }
      GenByte($FF);  { FF15xxxxxxxx Call [mem]    }
      GenByte($15);
      Crack.Fn := ErrorEntry;
      GenDWORD(LongWord(@ErrorStubAddr));
    end else
    begin
      { PUSH the method ID }
      GenPushI(I);

      { PUSH the info about return value location }
      if RetOnStack(IntfMD.MDA[I].ResultInfo)  then
      begin
        if IntfMD.MDA[I].CC in [ccStdcall, ccCdecl] then
          GenPushI(2)
        else
          GenPushI(1);
      end
      else
        GenPushI(0);

      { Generate the CALL [mem] to the generic stub }
      GenByte($FF);  { FF15xxxxxxxx Call [mem] }
      GenByte($15);
      GenDWORD(LongWord(@StubAddr));

      { Generate the return sequence }
      if IntfMD.MDA[I].CC in [ccCdecl] then
      begin
        { For cdecl calling convention, the caller will do the cleanup, so  }
        { we convert to a regular ret. }
        GenRet;
      end
      else
      begin
        { For all other calling conventions, the callee is supposed to do cleanup.  }
        { Figure out how many bytes we pushed in parameters, and clean it all up.   }
        BytesPushed := 0;
        for J := 0 to IntfMD.MDA[I].ParamCount - 1 do
        begin
           if IsParamByRef(IntfMD.MDA[I].Params[J].Flags, IntfMD.MDA[I].Params[J].Info, IntfMD.MDA[I].CC) then
             Inc(BytesPushed, 4)
           else
             Inc(BytesPushed, GetStackTypeSize(IntfMD.MDA[I].Params[J].Info, IntfMD.MDA[I].CC ));
        end;
        Inc(BytesPushed, GetStackTypeSize(IntfMD.MDA[I].SelfInfo, IntfMD.MDA[I].CC ));
        { TODO: Investigate why not always 4 ?? }
        if RetOnStack(IntfMD.MDA[I].ResultInfo) or (IntfMD.MDA[I].CC = ccSafeCall) then
          Inc(BytesPushed, 4);

        if BytesPushed > 252 then
          raise Exception.CreateFmt(STooManyParameters, [IntfMD.MDA[I].Name]);

        GenRET(BytesPushed);
      end;
    end;
    { Copy as much of the stub that we initialized over to the  }
    { block of memory we allocated. }
    P := PByte(Thunk);
    for J := 0 to CallStubIdx - 1 do
    begin
      P^ := CallStub[J];
      IncPtr(P);
    end;

    { And then fill the remainder with INT 3 instructions for             }
    { cleanliness and safety.  If we do the allocated more smartly, we    }
    { can remove all the wasted space, except for maybe alignment.        }
    for J := CallStubIdx to StubSize - 1 do
    begin
      P^ := $CC;
      IncPtr(P);
    end;

    { Finally, put the new thunk entry into the vtable slot.  }
    VTable^ := Thunk;
    IncPtr(VTable, 4);
    IncPtr(Thunk, StubSize);
  end;
end;

destructor TRIO.Destroy;
begin
  if IntfTable <> nil then
    FreeMem(IntfTable);
  if IntfStubs <> nil then
    FreeMem(IntfStubs);
  if FContext <> nil then
    FContext.Free;
  inherited;
end;

procedure TRIO.AfterConstruction;
begin
  { Release the constructor's implicit refcount }
  InterlockedDecrement(FRefCount);
end;

procedure TRIO.BeforeDestruction;
begin
  inherited;
{ TODO: Inform user of incorrect usage - object deleted before refCount reaches 0.
  if FRefCount <> 0 then
    raise Exception.Create(SInvalidPointer);
}
end;

{ Set an implicit refcount so that refcounting  }
{ during construction won't destroy the object. }
class function TRIO.NewInstance: TObject;
begin
  Result := inherited NewInstance;
  TRIO(Result).FRefCount := 1;
end;

function TRIO.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if FInterfaceBound then
  begin
    if IsEqualGuid(FIID, IID) then
    begin
      Result := 0;
      Pointer(Obj) := IntfTableP;
      InterlockedIncrement(FRefCount);
    end
    else
      { TODO: Investigate handling multiple interfaces. Issues are
             (a) Lifetime management of interfaces
             (b) Encoding enough information in thunk to allow discovering each interface }
      Result := E_NOINTERFACE;
  end
  else
  begin
    if GenVTable(IID) then
    begin
      Result := 0;
      FInterfaceBound := True;
      Pointer(Obj) := IntfTableP;
      InterlockedIncrement(FRefCount);
    end else
      Result := E_NOINTERFACE;
  end;
end;


{
  TRIO._AddRef

  This function, and TRIO._Release below, are both anomalies.  They will
  not participate in reference counting as you would normally expect of
  interfaced objects, because we prevent the normal interfaces from being
  acquired from this object in our implementation of QueryInterface.
  Whenever we enter these implementations of AddRef and Release, our
  interface pointers are not the normal interface pointers that have been
  properly adjusted by the compiler/RTL, but our generated interface
  pointers.  So we adjust these in our implementation to save space.
  The implication is that we cannot ever call these functions directly
  from our member functions, or from any derived members.  That's the
  reason that they're in the private section.
}
function TRIO._AddRef: Integer;
begin
  { Adjust the self pointer to point to the actual object, not  }
  { our little generated vtable slot. }
  Self := AddPtr(Self, -Integer(LongWord(@Self.IntfTable) - LongWord(Self)));
  Result := InterlockedIncrement(FRefCount);
end;

{
  TRIO._Release

  See the comment in TRIO._AddRef.
}
function TRIO._Release: Integer;
begin
  { Adjust the self pointer to point to the actual object, not  }
  { our little generated vtable slot.                           }
  Self := AddPtr(Self, -Integer(LongWord(@Self.IntfTable) - LongWord(Self)));
  Result := InterlockedDecrement(FRefCount);
  if (Result = 0) and not (Owner is TComponent) then
    Destroy;
end;


{ Assumes jmp to TRIO.Generic has register calling convention and
  the params are:
     eax: self (of a TRIO instance)
     edx: method # in interface
     ecx: address on stack of start of the params & return }
procedure TRIO.GenericStub;
asm
        POP     EAX  { Return address in runtime generated stub }
        POP     EDX  { Is there a pointer to return structure on stack and which CC is used?  }
        CMP     EDX, 2
        JZ      @@RETONSTACKRL
        CMP     EDX, 1
        JZ      @@RETONSTACKLR
        POP     EDX           { Method # pushed by stub  }
        PUSH    EAX           { Push back return address }
        LEA     ECX, [ESP+12] { Calc stack pointer to start of params }
        MOV     EAX, [ESP+8]  { Calc interface instance ptr }
        JMP     @@CONT
@@RETONSTACKLR:
        POP     EDX           { Method # pushed by stub   }
        PUSH    EAX           { Push back return address  }
        LEA     ECX, [ESP+12] { Calc stack pointer to start of params }
        MOV     EAX, [ESP+8]  { Calc interface instance ptr }
        JMP     @@CONT
@@RETONSTACKRL:
        POP     EDX           { Method # pushed by stub  }
        PUSH    EAX           { Push back return address }
        LEA     ECX, [ESP+8]  { Calc stack pointer to start of params }
        MOV     EAX, [ESP+12] { calc interface instance ptr }
@@CONT:
        SUB     EAX, OFFSET TRIO.IntfTable;  { Adjust intf pointer to object pointer }
        JMP     TRIO.Generic
end;

{
  LoadFloatReturn

  Handles the nuances of getting the various different sized floating
  point values from a buffer and onto the FPU for retrieval by the
  caller.
}
procedure LoadFloatReturn(RetP: Pointer; FloatType: TFloatType);
asm
        CMP     EDX, ftSingle
        JE      @@Single
        CMP     EDX, ftDouble
        JE      @@Double
        CMP     EDX, ftExtended
        JE      @@Extended
        CMP     EDX, ftCurr
        JE      @@Curr
        CMP     EDX, ftComp
        JE      @@Curr      { Same as Curr }
        { Should never get here!! }
@@Single:
        FLD     DWORD PTR [EAX]
        RET
@@Double:
        FLD     QWORD PTR [EAX]
        RET
@@Extended:
        FLD     TBYTE PTR [EAX]
        RET
@@Curr:
        FILD    QWORD PTR [EAX]
end;

function XMLDocFromStream(const Stream: TStream): IXMLDocument;
begin
  Result := NewXMLDocument;
  Result.Encoding := SUTF8;
  Stream.Position := 0;
  Result.LoadFromStream(Stream);
end;

function TRIO.Generic(CallID: Integer; Params: Pointer): Int64;
var
  MethMD: TIntfMethEntry;
  P: Pointer;
  ParamIdx, I, J, LeftRightOrder: Integer;
  RetP: Pointer;
  Req: InvString;
  MethNum: Integer;
  Stream: TMemoryStream;
begin
  Result := Int64(0);
  if not Assigned(FConverter) then
    raise Exception.Create(SNoMessageConverter);
  if not Assigned(FWebNode) then
    raise Exception.Create(SNoMsgProcessingNode);

  if not IntfReg then
    raise Exception.CreateFmt(SInterfaceNotReg, [GuidToString(FIID)]);
  if not HasRTTI then
    raise Exception.CreateFmt(SInterfaceNoRTTI, [GuidToString(FIID)]);
  if not LegalCC then
  begin
    for I := 0 to Length(IntfMD.MDA) -1 do
    begin
      if IntfMD.MDA[I].HasRTTI then
        with IntfMD.MDA[I] do
          if CC in [ccReg {, ccSafeCall} ] then
            raise Exception.CreateFmt(SUnsupportedCCIntfMeth, [CallingConventionName[CC], Name, IntfMD.Name]);
    end;
  end;

  { Get MethodEntry information }
  MethMD := IntfMD.MDA[CallID];

  FContext.SetMethodInfo(MethMD);
  P := Params;
  ParamIdx := 0;

  { Set up the parameter index and left right ordering, }
  { depending on calling convention }
  if MethMD.CC = ccPascal then
  begin
    ParamIdx := MethMD.ParamCount - 1;
    LeftRightOrder := -1;
  end else if MethMD.CC in [ccCdecl, ccStdCall, ccSafeCall]  then
  begin
    ParamIdx := 0;
    LeftRightOrder := 1;
  end else
    LeftRightOrder := 0; { todo: raise unsupported  }

  if MethMd.CC <> ccSafeCall then
  begin
    if RetOnStack(MethMD.ResultInfo) then
    begin
      RetP := Pointer(PInteger(P)^);
      if MethMD.ResultInfo.Kind = tkVariant then
        IncPtr(P, sizeof(Pointer))
      else
        IncPtr(P, GetStackTypeSize(MethMD.ResultInfo, MethMD.CC));
      if MethMD.CC in [ccCdecl, ccStdCall] then
      begin
        IncPtr(P, sizeof(Pointer));   { Step over self  }
      end;
    end else
      RetP := @Result;
    FContext.SetResultPointer(RetP);
  end;

  { Walk the parameters, setting pointers to each param's data into }
  { the parameter slots in the context  }
  for  J := 0 to  MethMD.ParamCount - 1 do
  begin
    FContext.SetParamPointer(ParamIdx, P);
    with MethMD.Params[J] do
    begin
      if (Info.Kind = tkVariant) and
         (MethMD.CC in [ccCdecl, ccStdCall, ccSafeCall]) and
         not (pfVar in Flags) and
         not (pfOut in Flags) then
      begin
        IncPtr(P, sizeof(TVarData)); { NOTE: better would be to dword-align!! }
      end
      else if IsParamByRef(Flags, Info, MethMD.CC) then
        IncPtr(P, 4)
      else
        IncPtr(P, GetStackTypeSize(Info, MethMD.CC));
    end;
    Inc(ParamIdx, LeftRightOrder);
  end;

  if MethMD.CC = ccSafeCall then
  begin
    RetP := Pointer(PInteger(P)^);
    FContext.SetResultPointer(RetP);
  end;
  MethNum := CallID;

  Req := FConverter.InvContextToMsg(IntfMD, MethNum, FContext);

  { Allow event to see packet we're sending }
  { Should be pass the interface method name or the external service
    name here ?? }
  DoBeforeExecute(MethMD.Name, Req);

  Stream := TMemoryStream.Create;
  try
    FWebNode.BeforeExecute(IntfMD, MethMD);
    FWebNode.Execute(Req, Stream);

    { Allow event to see data we received back }
    DoAfterExecute(MethMD.Name, Stream);

    FConverter.ProcessResponse(Stream, IntfMD, MethMD, FContext);
  finally
    Stream.Free;
  end;

  if (MethMD.CC <> ccSafeCall) and (MethMD.ResultInfo <> nil) and (MethMD.ResultInfo.Kind = tkFloat) then
    LoadFloatReturn(RetP, GetTypeData(MethMD.ResultInfo).FloatType);

  if (MethMD.ResultInfo <> nil) and (MethMD.ResultInfo.Kind = tkInt64) then
  begin
    asm
       PUSH   ECX
       MOV    ECX, DWORD PTR [RetP]
       MOV    EAX, DWORD PTR [ECX]
       MOV    EDX, DWORD PTR [ECX + 4]
       POP    ECX
    end;
  end;

  if MethMD.CC = ccSafeCall then
  asm
    XOR EAX, EAX  { TODO: handle safecall exceptions... }
    MOV DWORD PTR Result, EAX
  end;
  asm CLD end;
end;

constructor TRIO.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FInterfaceBound := False;
  FContext := TInvContext.Create;
end;

procedure TRIO.ErrorEntry;
begin
  raise Exception.Create(SMethNoRTTI);
end;

procedure TRIO.DoBeforeExecute(const MethodName: string; var Request: InvString);
begin
  if Assigned(FOnBeforeExecute) then
    FOnBeforeExecute(MethodName, Request);
end;

procedure TRIO.DoAfterExecute(const MethodName: string; Response: TStream);
begin
  if Assigned(FOnAfterExecute) then
    FOnAfterExecute(MethodName, Response);
end;

end.

