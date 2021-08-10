{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{       SOAP           Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}
unit InvRules;


interface

uses TypInfo, IntfInfo;

function RetOnStack(Info: PTypeInfo): Boolean;
function RetInFPU(Info: PTypeInfo): Boolean;
function GetTypeSize(P: PTypeInfo): Integer;
function GetStackTypeSize(P: PTypeInfo;  CC: TCallConv): Integer;
function IsParamByRef(Flags: TParamFlags; ParamInfo: PTypeInfo; CC: TCallConv): Boolean;
function IsRetInAXDX(Info: PTypeInfo): Boolean;

implementation

uses SysUtils;

function IsParamByRef(Flags: TParamFlags; ParamInfo: PTypeInfo; CC: TCallConv): Boolean;
begin
  Result := (pfVar in Flags) or (pfOut in Flags);
  if (ParamInfo.Kind = tkVariant) and ( CC = ccPascal ) then
    Result := True;
  if ParamInfo.Kind = tkString then
    Result := True;
//  if ParamInfo.Kind = tkDynArray then
//    Result := True;


 // if (ParamInfo.Kind = tkVariant) and (pfReference in Flags) then
  //  Result := True;
 { case ParamInfo.Kind of
    tkWString,
    tkString,
    tkLString,
    tkDynArray:
      Result := True;
  end;  }
end;


function GetTypeSize(P: PTypeInfo): Integer;
var
  TypeData: PTypeData;
begin
  Result := 4;
  TypeData := GetTypeData(P);
  case P.Kind of
    tkInteger:
      case TypeData^.OrdType of
        otSByte,
        otUByte:
            Result := sizeof(Byte);
        otSWord,
        otUWord:
          begin
            Result := sizeof(Word);
          end;
        otSLong,
        otULong:
          ;
      end;
    tkFloat:
      case TypeData.FloatType of
        ftSingle:
          Result := Sizeof(Single);
        ftDouble:
          Result := Sizeof(Double);
        ftComp:
          Result := Sizeof(Comp);
        ftCurr:
          Result := Sizeof(Currency);
        ftExtended:
          Result := Sizeof(Extended);
      end;
    tkChar:
      Result := 1;
    tkWChar:
      Result := 2;
    tkInt64:
      Result := sizeof(Int64);
    tkVariant:
      Result := sizeof(TVarData);
    tkEnumeration:
      Result := 1;
  end;
end;

function IsRetInAXDX(Info: PTypeInfo): Boolean;
begin
  Result := False;
   if Info <> nil then
    case Info.Kind of
      tkInt64:
        Result := True;
    end;
end;

function RetOnStack(Info: PTypeInfo): Boolean;
begin
  Result := False;
  if Info <> nil then
    case Info.Kind of
      tkLString,
      tkString,
      tkWString:
          Result := True;
      tkVariant:
          Result := True;
      tkDynArray:
         Result := True;
    end;
end;

function RetInFPU(Info: PTypeInfo): Boolean;
begin
  Result := False;
  if Info <> nil then
    case Info.Kind of
      tkFloat: Result := True;
    end;
end;

{
  GetStackTypeSize

  Returns the size that is actually allocated on the stack for a given
  type.  This is frequently different than the heap allocation for
  an object, because all stack pointers are allocated on 4 byte boundaries.
  So for example, the Extended type might occupy 10 bytes, but we will
  always allocate 12 bytes on the stack for it.
}
function GetStackTypeSize(P: PTypeInfo; CC: TCallConv): Integer;
var
  TypeData: PTypeData;
begin
  Result := 4;
  TypeData := GetTypeData(P);
  case P.Kind of
    tkFloat:
      case TypeData.FloatType of
        ftSingle:
          ;
        ftDouble,
        ftComp,
        ftCurr:
          Result := 8;
        ftExtended:
          Result := 10;
      end;
    tkInt64:
      Result := 8;
    tkVariant:
      if CC in [ccCdecl, ccStdCall, ccSafeCall] then
        Result := sizeof(TVarData);
  {
    tkSet,
    tkClass,
    tkMethod,
    tkVariant,
    tkArray,
    tkRecord,
    tkInterface,
    tkDynArray,
    tkEnumeration,
    tkWString,
    tkString,
    tkLString:
      ;
  }
  end;

  // Make sure we're aligned on a 4 byte boundary
  Result := (Result + 3) and $FFFFFFFC;
end;


end.
