{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}
unit ReqImpl;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, Messages, SysUtils, Classes, HTTPApp, WebLib,
  ComObj;
{$ENDIF}
{$IFDEF LINUX}
SysUtils, Classes, HTTPApp, WebLib;
{$ENDIF}

type

  TWebRequestImpl = class(TInterfacedObject, IWebRequest)
  private
    FWebRequest: TWebRequest;
    FWebResponse: TWebResponse;
    FUsingStub: Boolean;
  public
    constructor Create(AWebRequest: TWebRequest; AWebResponse: TWebResponse;
      AUsingStub: Boolean);
    function  GetFieldByName(const Name: WideString): WideString; safecall;
    function  ReadClient(var ABuffer: OleVariant; ACount: Integer): Integer; safecall;
    function  ReadString(var ABuffer: OleVariant; ACount: Integer): Integer; safecall;
    function  TranslateURI(const Value: WideString): WideString; safecall;
    function  WriteClient(Buffer: OleVariant): Integer; safecall;
    function  GetStringVariable(Index: Integer): OleVariant; safecall;
    function  WriteHeaders(StatusCode: Integer; StatusText: OleVariant;
                           Headers: OleVariant): WordBool; safecall;
    function  UsingStub: WordBool; safecall;
  end;

  function SearchForCoClass(Request: TWebRequest; var ID: string; var ClsID: TGuid): Boolean;
  function FileNameToClassID(const AFileName: string; var AGuid: TGUID): Boolean;

implementation

uses WebCat, ActiveX, Variants;

type
  TWebRequestCracker = class(TWebRequest);
  TWebResponseCracker = class(TWebResponse);

{ TWebRequestImpl}

constructor TWebRequestImpl.Create(AWebRequest: TWebRequest; AWebResponse: TWebResponse;
  AUsingStub: Boolean);
begin
  FWebRequest := AWebRequest;
  FWebResponse := AWebResponse;
  FUsingStub := AUsingStub;
  inherited Create;
end;

function TWebRequestImpl.GetFieldByName(
  const Name: WideString): WideString;
begin
   Result := FWebRequest.GetFieldByName(Name);
end;

function StringToVariantArray(const S: string): OleVariant; forward;

function TWebRequestImpl.GetStringVariable(Index: Integer): OleVariant;
begin
  Result := StringToVariantArray(TWebRequestCracker(FWebRequest).GetStringVariable(Index));
end;

function TWebRequestImpl.ReadClient(var ABuffer: OleVariant;
  ACount: Integer): Integer;
var
  P: Pointer;
begin
  ABuffer := VarArrayCreate([0, ACount - 1], varByte);
  P := VarArrayLock(Result);
  try
    Result := FWebRequest.ReadClient(P^, ACount);
  finally
    VarArrayUnlock(Result);
  end;
end;

function VariantArrayToString(const V: OleVariant): string;
var
  P: Pointer;
  Size: Integer;
begin
  Result := '';
  if VarIsArray(V) and (VarType(V) and varTypeMask = varByte) then
  begin
    Size := VarArrayHighBound(V, 1) - VarArrayLowBound(V, 1) + 1;
    if Size > 0 then
    begin
      SetLength(Result, Size);
      P := VarArrayLock(V);
      try
        Move(P^, Result[1], Size);
      finally
        VarArrayUnlock(V);
      end;
    end;
  end;
end;

function StringToVariantArray(const S: string): OleVariant;
var
  P: Pointer;
begin
  Result := NULL;
  if Length(S) > 0 then
  begin
    Result := VarArrayCreate([0, Length(S) - 1], varByte);
    P := VarArrayLock(Result);
    try
      Move(S[1], P^, Length(S));
    finally
      VarArrayUnlock(Result);
    end;
  end;
end;

function TWebRequestImpl.ReadString(var ABuffer: OleVariant;
  ACount: Integer): Integer;
var
  S: string;
begin
  SetLength(S, ACount);
  S := FWebRequest.ReadString(ACount);
  ABuffer := StringToVariantArray(S);
end;

function TWebRequestImpl.UsingStub: WordBool;
begin
  Result := FUsingStub;
end;

function TWebRequestImpl.TranslateURI(
  const Value: WideString): WideString;
begin
  Result := FWebRequest.TranslateURI(Value);
end;

function TWebRequestImpl.WriteClient(Buffer: OleVariant): Integer;
var
  S: string;
  P: Pointer;
  Size: Integer;
begin
  if VarIsType(Buffer, varOleStr) then
  begin
    S := Buffer;
    Result := FWebRequest.WriteClient(Pointer(S)^, Length(S));
  end
  else if VarisType(Buffer, varByte or varArray) then
  begin
    Size := VarArrayHighBound(Buffer, 1) - VarArrayLowBound(Buffer, 1) + 1;
    if Size > 0 then
    begin
      P := VarArrayLock(Buffer);
      try
        Result := FWebRequest.WriteClient(P^, Size);
      finally
        VarArrayUnlock(Buffer);
      end;
    end;
  end
  else
    Assert(False, 'Unknown variant type');
end;

function TWebRequestImpl.WriteHeaders(StatusCode: Integer;
  StatusText, Headers: OleVariant): WordBool;
begin
  Result := FWebRequest.WriteHeaders(StatusCode, VariantArrayToString(StatusText), VariantArrayToString(Headers));
end;

function SearchForCoClass(Request: TWebRequest; var ID: string; var ClsID: TGuid): Boolean;
var
  P: Integer;
begin
  ID := Request.PathInfo;
  if (Length(ID) > 0) and (ID[1] = '/') then
    Delete(ID, 1, 1);
  P := Pos('/', ID);
  if P > 0 then
    Delete(ID, P, MaxInt);
  Result := False;
  if ID <> '' then
  begin
    if not Result and (ID[1] = '{') then
    begin
      try
        ClsID := StringToGUID(ID);
        Result := True;
      except
      end;
    end;

    if not Result and (CompareText(ExtractFileExt(ID), '.exe') = 0) then
    begin
      Result := FileNameToClassID(ID, ClsID);
    end;

    if not Result and (CompareText(ExtractFileExt(ID), '.js') <> 0) then
    begin
      try
        ClsID := ProgIDToClassID(ID);
        Result := True;
      except
      end;
    end;
  end;
end;

function FileNameToClassID(const AFileName: string; var AGuid: TGUID): Boolean;
var
  EnumGUID: IEnumGUID;
  Fetched: Cardinal;
  Rslt: HResult;
  CatInfo: ICatInformation;
  S: string;
begin
  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatInformation, CatInfo);
  if Succeeded(Rslt) then
  begin
    OleCheck(CatInfo.EnumClassesOfCategories(1, @CATID_WebAppServer, 0, nil, EnumGUID));
    while EnumGUID.Next(1, AGuid, Fetched) = S_OK do
    begin
      S := SClsid + GuidToString(AGuid) + '\LocalServer32';
      if AnsiCompareFileName(AFileName, ExtractFileName(GetRegStringValue(S, ''))) = 0 then
      begin
        Result := True;
        Exit;
      end;
    end;
  end else
  begin
    Assert(False);
  end;
  Result := False;
end;

end.

