{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{       Interface RTTI Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

Unit IntfInfo;

interface

uses TypInfo, SysUtils;

type

  PIntfParamEntry = ^TIntfParamEntry;
  TIntfParamEntry = record
    Flags: TParamFlags;
    Name: string;
    Info: PTypeInfo;
  end;

  TIntfParamEntryArray = array of TIntfParamEntry;

  TCallConv = (ccReg, ccCdecl, ccPascal, ccStdCall, ccSafeCall);

  PIntfMethEntry = ^TIntfMethEntry;
  TIntfMethEntry = record
    Name: string;
    CC: TCallConv;              { Calling convention }
    Pos: Integer;               { Index (relative to whole interface VMT) }
    ParamCount: Integer;
    ResultInfo: PTypeInfo;
    SelfInfo: PTypeInfo;
    Params: TIntfParamEntryArray;
    HasRTTI: Boolean;
  end;
  TIntfMethEntryArray = array of TIntfMethEntry;
  TPIntfMethEntryArray = array of PIntfMethEntry;

  { Governs show the MDA array is filled }
  TFillMethodArrayOpt = (fmoAllBaseMethods, fmoRTTIBaseMethods, fmoNoBaseMethods);
  
  PIntfMetaData = ^TIntfMetaData;
  TIntfMetaData = record
    Name: string;
    UnitName: string;
    MDA: TIntfMethEntryArray;
    IID: TGUID;
    Info: PTypeInfo;
    AncInfo: PTypeInfo;
    NumAnc: Integer;      { #Methods in base interfaces }
  end;

  EInterfaceRTTIException = class(Exception);

procedure GetIntfMetaData(Info: PTypeInfo; var IntfMD: TIntfMetaData; MethodArrayOpt: TFillMethodArrayOpt); overload;
procedure GetIntfMetaData(Info: PTypeInfo; var IntfMD: TIntfMetaData; IncludeAllAncMethods: Boolean = False); overload;
function  GetMethNum(const IntfMD: TIntfMetaData; const MethName: string): Integer;
procedure GetDynArrayElTypeInfo(typeInfo: PTypeInfo; var EltInfo: PTypeInfo; var Dims: Integer);
function  GetDynArrayNextInfo(typeInfo: PTypeInfo): PTypeInfo;

function  TypeNamesMatch(const RegName: string; const OtherName: string): boolean;
function  OtherTypeName(const TypeName: string): string;
function  SameTypeInfo(const RegInfo: PTypeInfo; const OtherInfo: PTypeInfo): boolean;

function  GetPropListFlat(TypeInfo: PTypeInfo; out PropList: PPropList): Integer;
function  IsStoredPropConst(Instance: TObject; PropInfo: PPropInfo): Boolean;
function  GetClsMemberTypeInfo(const ObjectTypeInfo: PTypeInfo; const MemberName: string = ''): PTypeInfo;

{ The following routines are used from C++ to validate the compatibility of C++ interface generation}
{$IFDEF DEVELOPERS}
function  ReadString(var P: Pointer): String;
function  ReadByte(var P: Pointer): Byte;
function  ReadWord(var P: Pointer): Word;
function  ReadLong(var P: Pointer): Integer;
procedure FillMethodArray(P: Pointer; IntfMD: PIntfMetaData; Offset, Methods: Integer);
function  GetNumAncMeths(P: Pointer; WithRTTIOnly: Boolean = False): Integer;
function  WalkAncestors(PP: PPTypeInfo; AddMeths: Boolean; IntfMD: PIntfMetaData; WithRTTIOnly: Boolean): Integer;
{$ENDIF}

const
  CallingConventionName:  array[ccReg..ccSafeCall] of string =
     ('REGISTER', 'CDECL', 'PASCAL', 'STDCALL', 'SAFECALL');                    { do not localize }

  TypeInfoNames:  array[0..33] of string = ( 'Boolean',     'bool',             { do no localize }
                                             'Char',        'char',             { do no localize }
                                             'Char',        'signed char',      { do no localize }
                                             'Byte',        'unsigned char',    { do no localize }
                                             'SmallInt',    'short',            { do no localize }
                                             'Word',        'unsigned short',   { do no localize }
                                             'Integer',     'int',              { do no localize }
                                             'Cardinal',    'unsigned int',     { do no localize }
                                             'Integer',     'long',             { do no localize }
                                             'Cardinal',    'unsigned long',    { do no localize }
                                             'Int64',       '__int64',          { do no localize }
                                             'Int64',       'unsigned __int64', { do no localize }
                                             'Single',      'float',            { do no localize }
                                             'Double',      'double',           { do no localize }
                                             'Extended',    'long double',      { do no localize }
                                             'String',      'AnsiString',       { do no localize }
                                             'WideString',  'WideString');      { do no localize }


function GetDynArrayNextInfo2(typeInfo: PTypeInfo; var Name: string): PTypeInfo;

implementation

uses SOAPConst;

const
  CCMap:  array[0..4] of TCallConv = (ccReg, ccCdecl, ccPascal, ccStdCall, ccSafeCall);


function GetMethNum(const IntfMD: TIntfMetaData; const MethName: string): Integer;
var
  I, NumNames: Integer;
begin
  NumNames := 0;
  Result := -1;
  for I := 0 to Length(IntfMD.MDA) - 1 do
  begin
    { TODO OWNER:BB How will this fare under C++ where symbols are case-sensitive ??
           ??????? }
    if SameText(IntfMD.MDA[I].Name, MethName) then
    begin
      Result := I;
      Inc(NumNames);
    end;
  end;
  if NumNames > 1 then
    Result := -1; 
end;

function ReadString(var P: Pointer): String;
var
  B: Byte;
begin
  B := Byte(P^);
  SetLength(Result, B);
  P := Pointer( Integer(P) + 1);
  Move(P^, Result[1], Integer(B));
  P := Pointer( Integer(P) + B );
end;

function ReadByte(var P: Pointer): Byte;
begin
  Result := Byte(P^);
  P := Pointer( Integer(P) + 1);
end;

function ReadWord(var P: Pointer): Word;
begin
  Result := Word(P^);
  P := Pointer( Integer(P) + 2);
end;

function ReadLong(var P: Pointer): Integer;
begin
  Result := Integer(P^);
  P := Pointer( Integer(P) + 4);
end;

procedure FillMethodArray(P: Pointer; IntfMD: PIntfMetaData; Offset, Methods: Integer);
var
  S: string;
  I, J, K, L: Integer;
  ParamCount: Integer;
  Kind, Flags: Byte;
  ParamInfo: PTypeInfo;
  ParamName: string;
  IntfMethod: PIntfMethEntry;
  IntfParam: PIntfParamEntry;
begin
  for I := 0 to Methods -1 do
  begin
    IntfMethod := @IntfMD.MDA[Offset];
    IntfMethod.Name := ReadString(P);
    Kind := ReadByte(P);           { tkKind }
    IntfMethod.CC := CCMap[ReadByte(P)];
    ParamCount := ReadByte(P);     { Param count including self }
    IntfMethod.ParamCount := ParamCount - 1;
    IntfMethod.Pos := Offset;
    IntfMethod.HasRTTI := True;

    SetLength(IntfMethod.Params, ParamCount);
    K := 0;
    for J := 0 to ParamCount - 1 do
    begin
      Flags := ReadByte(P);       { Flags }
      ParamName := ReadString(P); { Param name }
      S := ReadString(P);         { Param type name }
      L := ReadLong(P);           { Param Type Info }
      if L <> 0 then
        ParamInfo := PPTypeInfo(L)^
      else
        raise EInterfaceRTTIException.CreateFmt(SNoRTTIParam, [ParamName, IntfMethod.Name, IntfMD.UnitName + '.' + IntfMd.Name]);
      if J = 0 then
        IntfMethod.SelfInfo := ParamInfo
      else
      begin
        IntfParam := @IntfMethod.Params[K];
        IntfParam.Flags := TParamFlags(Flags);
        IntfParam.Name := ParamName;
        IntfParam.Info := ParamInfo;
        Inc(K);
      end;
    end;
    if Kind = Byte(mkFunction) then
    begin
      S := ReadString(P);
      IntfMethod.ResultInfo := PPTypeInfo(ReadLong(P))^;
    end;
    Inc(Offset);
  end;
end;

function WalkAncestors(PP: PPTypeInfo; AddMeths: Boolean; IntfMD: PIntfMetaData; WithRTTIOnly: Boolean): Integer;
var
  S: string;
  AncTP: Pointer;
  P: Pointer;
  B: Byte;
  NumMethods, NumAncMeths, I: Integer;
  HasRTTI: Boolean;
begin
  P := Pointer(PP^);
  ReadByte(P);                       // Kind
  S := ReadString(P);                // Symbol name
  AncTP := Pointer(ReadLong(P));     // Ancestor TypeInfo
  P := Pointer(Integer(P) + 17);     // Intf.flags and GUID
  B := Byte(P^);                     // Length
  P := Pointer(Integer(P) + B + 1);  // Unit name  and count
  NumMethods :=  ReadWord(P);        // # methods
  I := ReadWord(P);                  // $FFFF if no RTTI, # methods again if has RTTI
  HasRTTI := (I <> $FFFF);

  { Compute the number of methods }
  if (AncTP <> nil) and (HasRTTI or (WithRTTIOnly = False)) then
  begin
    NumAncMeths  := WalkAncestors(AncTP, False, nil, WithRTTIOnly);
  end else
    NumAncMeths := 0;
  { Ancestor count }
  Result := NumAncMeths;
  { Plus our own }
  if (HasRTTI or (WithRTTIOnly = False)) then
    Result := Result + NumMethods;
  { Do we need to fill in method information too? }
  if AddMeths then
  begin
    if HasRTTI then
    begin
      FillMethodArray(P, IntfMD, NumAncMeths, NumMethods);
      if NumAncMeths > 0 then
         WalkAncestors(AncTP, AddMeths, IntfMD, WithRTTIOnly);
    end;
  end;
end;

function GetNumAncMeths(P: Pointer; WithRTTIOnly: Boolean = False): Integer;
var
  B: Byte;
  Anc: Pointer;
begin
  Result := 0;
  ReadByte(P);                      // tkKind
  B := Byte(P^);                    // Symbol length
  P := Pointer(Integer(P) + B + 1); // Skip sym name  and count
  Anc := Pointer(ReadLong(P));      // Ancestor pointer
  if Anc <> nil then
    Result := WalkAncestors(Anc, False, nil, WithRTTIOnly);
end;

procedure GetIntfMetaData(Info: PTypeInfo; var IntfMD: TIntfMetaData; MethodArrayOpt: TFillMethodArrayOpt);
var
  I, Offset: Integer;
  Methods: Integer;
  BaseRTTIMethods: Integer;
  HasRTTI: Integer;
  PP: PPTypeInfo;
  P: Pointer;
  SelfMethCount: Integer;
begin
  P := Pointer(Info);
  { Get total number of ancestor methods }
  IntfMD.NumAnc := GetNumAncMeths(P);
  { Get base methods we could expose }
  BaseRTTIMethods := GetNumAncMeths(P, True);
  IntfMD.Info := Info;
  { tkKind }
  ReadByte(P);
  IntfMD.Name := ReadString(P);
  PP := PPTypeInfo(ReadLong(P));
  { Ancestor typeinfo }
  if PP <> nil then
    IntfMD.AncInfo := PP^
  else
    IntfMD.AncInfo := nil;
  { Interface flags }
  ReadByte(P);
  IntfMD.IID.D1 := LongWord(ReadLong(P));
  IntfMD.IID.D2 := ReadWord(P);
  IntfMD.IID.D3 := ReadWord(P);
  for I := 0 to 7 do
    IntfMD.IID.D4[I] := ReadByte(P);
  IntfMD.UnitName := ReadString(P);
  Methods := ReadWord(P);   { # methods }
  HasRTTI := ReadWord(P);   { $FFFF if no RTTI, # methods again if has RTTI }
  if HasRTTI = $FFFF then
    raise EInterfaceRTTIException.CreateFmt(SNoRTTI, [IntfMD.UnitName + '.' + IntfMd.Name]);
  { Save my method count }
  SelfMethCount := Methods;
  { Update count of methods }
  if (MethodArrayOpt = fmoAllBaseMethods) then
  begin
    Methods := Methods + IntfMD.NumAnc;
    Offset := IntfMD.NumAnc;
  end else
  if (MethodArrayOpt = fmoRTTIBaseMethods) then
  begin
    Methods := Methods + BaseRTTIMethods;
    Offset := BaseRTTIMethods;
  end else
    Offset := 0;
  { Size array and fill in information }
  SetLength(IntfMD.MDA, Methods);
  FillMethodArray(P, @IntfMD, Offset, SelfMethCount);
  { Include method info. of base methods too?? }
  if (MethodArrayOpt = fmoAllBaseMethods) or
     (MethodArrayOpt = fmoRTTIBaseMethods)  then
  begin
    if PP <> nil then
      WalkAncestors(PP, True, @IntfMD, (MethodArrayOpt = fmoRTTIBaseMethods));
  end;
end;

procedure GetIntfMetaData(Info: PTypeInfo; var IntfMD: TIntfMetaData; IncludeAllAncMethods: Boolean);
var
  FillMethodArrayOpt: TFillMethodArrayOpt;
begin
  if (IncludeAllAncMethods) then
    FillMethodArrayOpt := fmoAllBaseMethods
  else
    FillMethodArrayOpt := fmoRTTIBaseMethods;
  GetIntfMetaData(Info, IntfMD, FillMethodArrayOpt);
end;

procedure GetDynArrayElTypeInfo(typeInfo: PTypeInfo; var EltInfo: PTypeInfo; var Dims: Integer);
var
  L: Integer;
  S: string;
  P: Pointer;
  Info: PTypeInfo;
begin
  Dims := 0;
  P := Pointer(typeInfo);
  ReadByte(P);            { kind }
  S := ReadString(P);     { symname }
  ReadLong(P);            { elsize }
  L := ReadLong(P);
  if (L <> 0) then
  begin
    Info := PPTypeInfo(L)^;
    if Info.Kind = tkDynArray then
    begin
      GetDynArrayElTypeInfo(Info, EltInfo, Dims);
    end;
  end;
  ReadLong(P);      { vartype }
  L := ReadLong(P); { elttype, even if not destructable, 0 if type has no RTTI }
  if L <> 0 then
    EltInfo := PPTypeInfo(L)^;
  Inc(Dims);
end;

function GetDynArrayNextInfo(typeInfo: PTypeInfo): PTypeInfo;
var
  S: string;
  P: Pointer;
  L: Integer;
begin
  Result := nil;
  P := Pointer(typeInfo);
  ReadByte(P);        { kind }
  S := ReadString(P); { symname }
  ReadLong(P);        { elsize }
  L := ReadLong(P);
  if L <> 0 then
    Result := PPTypeInfo(L)^;  { eltype or 0 if not destructable }
end;

function GetDynArrayNextInfo2(typeInfo: PTypeInfo; var Name: string): PTypeInfo;
var
  P: Pointer;
  L: Integer;
begin
  Result := nil;
  P := Pointer(typeInfo);
  ReadByte(P);            { kind }
  Name := ReadString(P);  { symname }
  ReadLong(P);            { elsize }
  L := ReadLong(P);
  if L <> 0 then
    Result := PPTypeInfo(L)^;   { eltype or 0 if not destructable }
end;

function SameTypeInfo(const RegInfo: PTypeInfo; const OtherInfo: PTypeInfo): boolean;
begin
  Result := (RegInfo = OtherInfo) or
            ((RegInfo.Kind=OtherInfo.Kind) and TypeNamesMatch(RegInfo^.Name, OtherInfo^.Name));
end;

function TypeNamesMatch(const RegName: string; const OtherName: string): boolean;
var
  I: Integer;
begin
  Result := (RegName = OtherName);
  if (not Result) then
  begin
    I := 1; { Start at one since we check OtherName first }
    while (I < Length(TypeInfoNames)) do
    begin
      if (OtherName = TypeInfoNames[I]) then
      begin
        Result := (RegName = TypeInfoNames[I-1]);
        Exit;
      end;
      I := I+2;
    end;
  end;
end;

function  OtherTypeName(const TypeName: string): string;
var
  I: Integer;
begin
  I := 0;
  while (I < (Length(TypeInfoNames)-1)) do
  begin
    if (TypeName = TypeInfoNames[I]) then
    begin
      Result := TypeInfoNames[I+1];
      Exit;
    end;
    I := I+2;
  end;
end;

{ Similar to TypInfo's GetPropInfos except that we don't walk up the base classes }
procedure GetPropInfosFlat(TypeInfo: PTypeInfo; PropList: PPropList); assembler;
asm
        { ->    EAX Pointer to type info        }
        {       EDX Pointer to prop list        }
        { <-    nothing                         }

        PUSH    EBX
        PUSH    ESI
        PUSH    EDI

        XOR     ECX,ECX
        MOV     ESI,EAX
        MOV     CL,[EAX].TTypeInfo.Name.Byte[0]
        MOV     EDI,EDX
        XOR     EAX,EAX
        MOVZX   ECX,[ESI].TTypeInfo.Name[ECX+1].TTypeData.PropCount
        REP     STOSD

@outerLoop:
        MOV     CL,[ESI].TTypeInfo.Name.Byte[0]
        LEA     ESI,[ESI].TTypeInfo.Name[ECX+1]
        MOV     CL,[ESI].TTypeData.UnitName.Byte[0]
        MOVZX   EAX,[ESI].TTypeData.UnitName[ECX+1].TPropData.PropCount
        TEST    EAX,EAX
        JE      @parent
        LEA     EDI,[ESI].TTypeData.UnitName[ECX+1].TPropData.PropList

@innerLoop:

        MOVZX   EBX,[EDI].TPropInfo.NameIndex
        MOV     CL,[EDI].TPropInfo.Name.Byte[0]
        CMP     dword ptr [EDX+EBX*4],0
        JNE     @alreadySet
        MOV     [EDX+EBX*4],EDI

@alreadySet:
        LEA     EDI,[EDI].TPropInfo.Name[ECX+1]
        DEC     EAX
        JNE     @innerLoop

@parent:
@exit:
        POP     EDI
        POP     ESI
        POP     EBX
end;

function GetPropListFlat(TypeInfo: PTypeInfo; out PropList: PPropList): Integer;
begin
  Result := GetTypeData(TypeInfo)^.PropCount;
  if Result > 0 then
  begin
    GetMem(PropList, Result * SizeOf(Pointer));
    FillChar(PropList^, Result * SizeOf(Pointer), 0);
    GetPropInfosFlat(TypeInfo, PropList);
  end;
end;

{ Similar to TypInfo's IsStoredProp although this version only handles cases
  where the attribute was assigned 'true' or 'false' directly }
function IsStoredPropConst(Instance: TObject; PropInfo: PPropInfo): Boolean;
asm
        { ->    EAX Pointer to Instance         }
        {       EDX Pointer to prop info        }
        { <-    AL  Function result             }

        MOV     ECX,[EDX].TPropInfo.StoredProc
        TEST    ECX,0FFFFFF00H
        JE      @@returnCL
        MOV     CL, 1
@@returnCL:
        MOV     AL,CL
@@exit:
end;

{ Returns the TypeInfo of a class member }
function GetClsMemberTypeInfo(const ObjectTypeInfo: PTypeInfo; const MemberName: string): PTypeInfo;
var
  PropList: PPropList;
  Size, Props: Integer;
begin
  Result := nil;
  Size := GetPropListFlat(ObjectTypeInfo, PropList);
  if Size > 0 then
  begin
    try
      for Props := 0 to Size -1 do
      begin
        if PropList[Props] <> nil then
        begin
          { Either there's a match or send the only member's TypeInfo back }
          if SameText(PropList[Props].Name, MemberName) or ((MemberName = '') and (Size = 1)) then
          begin
            Result := PropList[Props].PropType^;
            Exit;
          end;
        end;
      end;
    finally
      FreeMem(PropList);
    end;
  end;
end;


end.
