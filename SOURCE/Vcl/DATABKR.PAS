
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Remote Data Module support                      }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DataBkr;

{$T-,H+,X+}

interface

uses Windows, ActiveX, Classes, Midas, Forms, Provider, SysUtils;

type
  { TRemoteDataModule }

  TRemoteDataModule = class(TDataModule, IAppServer)
  private
    FProviders: TList;
    FLock: TRTLCriticalSection;
  protected
    function GetProvider(const ProviderName: string): TCustomProvider; virtual;
    class procedure UpdateRegistry(Register: Boolean; const ClassID, ProgID: string); override;
    { IAppServer }
    function AS_GetProviderNames: OleVariant; safecall;
    function AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant;
      MaxErrors: Integer; out ErrorCount: Integer;
      var OwnerData: OleVariant): OleVariant; safecall;
    function AS_GetRecords(const ProviderName: WideString; Count: Integer;
      out RecsOut: Integer; Options: Integer; const CommandText: WideString;
      var Params, OwnerData: OleVariant): OleVariant; safecall;
    function AS_DataRequest(const ProviderName: WideString;
      Data: OleVariant): OleVariant; safecall;
    function AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
    function AS_RowRequest(const ProviderName: WideString; Row: OleVariant;
      RequestType: Integer; var OwnerData: OleVariant): OleVariant; safecall;
    procedure AS_Execute(const ProviderName: WideString;
      const CommandText: WideString; var Params, OwnerData: OleVariant); safecall;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure RegisterProvider(Value: TCustomProvider); virtual;
    procedure UnRegisterProvider(Value: TCustomProvider); virtual;
    procedure Lock; virtual;
    procedure Unlock; virtual;
    property Providers[const ProviderName: string]: TCustomProvider read GetProvider;
  end;

{ TCRemoteDataModule --- a slimmed down RDM that doesn't implement IAppServer,
  used in C++Builder. +}
 type
 TCRemoteDataModule = class(TDataModule)
 private
  FProviders: TList;
  FLock: TRTLCriticalSection;
 public
  constructor Create(AOwner: TComponent); override;
  destructor Destroy; override;
  procedure RegisterProvider(Value: TCustomProvider); virtual;
  procedure UnRegisterProvider(Value: TCustomProvider); virtual;
  procedure Lock; virtual;
  procedure UnLock; virtual;
  function CRDMGetProviderNames: OleVariant;
  function GetProvider(const ProviderName: string): TCustomProvider; virtual;
  property Providers[const ProviderName:string]:TCustomProvider read GetProvider;
 end;

procedure RegisterPooled(const ClassID: string; Max, Timeout: Integer; Singleton: Boolean = False);
procedure UnregisterPooled(const ClassID: string);
procedure EnableSocketTransport(const ClassID: string);
procedure DisableSocketTransport(const ClassID: string);
procedure EnableWebTransport(const ClassID: string);
procedure DisableWebTransport(const ClassID: string);

implementation

uses ComObj, MidConst;

{ Utility routines }

procedure RegisterPooled(const ClassID: string; Max, Timeout: Integer;
  Singleton: Boolean = False);
begin
{ Do not localize }
  CreateRegKey(SClsid + ClassID, SPooled, SFlagOn);
  CreateRegKey(SClsid + ClassID, SMaxObjects, IntToStr(Max));
  CreateRegKey(SClsid + ClassID, STimeout, IntToStr(Timeout));
  if Singleton then
    CreateRegKey(SClsid + ClassID, SSingleton, SFlagOn) else
    CreateRegKey(SClsid + ClassID, SSingleton, SFlagOff);
end;

procedure DeleteRegValue(const Key, ValueName: string);
var
  Handle: HKey;
  Status: Integer;
begin
  Status := RegOpenKey(HKEY_CLASSES_ROOT, PChar(Key), Handle);
  if Status = 0 then
    RegDeleteValue(Handle, PChar(ValueName));
end;

procedure UnregisterPooled(const ClassID: string);
begin
  DeleteRegValue(SClsid + ClassID, SPooled);
  DeleteRegValue(SClsid + ClassID, SMaxObjects);
  DeleteRegValue(SClsid + ClassID, STimeout);
  DeleteRegValue(SClsid + ClassID, SSingleton);
end;

procedure EnableSocketTransport(const ClassID: string);
begin
  CreateRegKey(SClsid + ClassID, SSockets, SFlagOn);
end;

procedure DisableSocketTransport(const ClassID: string);
begin
  DeleteRegValue(SClsid + ClassID, SSockets);
end;

procedure EnableWebTransport(const ClassID: string);
begin
  CreateRegKey(SClsid + ClassID, SWeb, SFlagOn);
end;

procedure DisableWebTransport(const ClassID: string);
begin
  DeleteRegValue(SClsid + ClassID, SWeb);
end;

function VarArrayFromStrings(Strings: TStrings): Variant;
var
  I: Integer;
begin
  Result := Null;
  if Strings.Count > 0 then
  begin
    Result := VarArrayCreate([0, Strings.Count - 1], varOleStr);
    for I := 0 to Strings.Count - 1 do Result[I] := WideString(Strings[I]);
  end;
end;

{ TRemoteDataModule }

constructor TRemoteDataModule.Create(AOwner: TComponent);
begin
  InitializeCriticalSection(FLock);
  FProviders := TList.Create;
  inherited Create(AOwner);
end;

destructor TRemoteDataModule.Destroy;
begin
  inherited Destroy;
  FProviders.Free;
  DeleteCriticalSection(FLock);
end;

procedure TRemoteDataModule.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TRemoteDataModule.Unlock;
begin
  LeaveCriticalSection(FLock);
end;

procedure TRemoteDataModule.RegisterProvider(Value: TCustomProvider);
begin
  FProviders.Add(Value);
end;

procedure TRemoteDataModule.UnRegisterProvider(Value: TCustomProvider);
begin
  FProviders.Remove(Value);
end;

function TRemoteDataModule.GetProvider(const ProviderName: string): TCustomProvider;
var
  i: Integer;
begin
  Result := nil;
  for i := 0 to FProviders.Count - 1 do
    if AnsiCompareStr(TCustomProvider(FProviders[i]).Name, ProviderName) = 0 then
    begin
      Result := TCustomProvider(FProviders[i]);
      if not Result.Exported then
        Result := nil;
      Exit;
    end;
  if not Assigned(Result) then
    raise Exception.CreateResFmt(@SProviderNotExported, [ProviderName]);
end;

function TRemoteDataModule.AS_GetProviderNames: OleVariant;
var
  List: TStringList;
  i: Integer;
begin
  Lock;
  try
    List := TStringList.Create;
    try
      for i := 0 to FProviders.Count - 1 do
        if TCustomProvider(FProviders[i]).Exported then
          List.Add(TCustomProvider(FProviders[i]).Name);
      List.Sort;
      Result := VarArrayFromStrings(List);
    finally
      List.Free;
    end;
  finally
    UnLock;
  end;
end;

function TRemoteDataModule.AS_ApplyUpdates(const ProviderName: WideString;
  Delta: OleVariant; MaxErrors: Integer; out ErrorCount: Integer;
  var OwnerData: OleVariant): OleVariant;
begin
  Lock;
  try
    Result := Providers[ProviderName].ApplyUpdates(Delta, MaxErrors, ErrorCount, OwnerData);
  finally
    UnLock;
  end;
end;

function TRemoteDataModule.AS_GetRecords(const ProviderName: WideString; Count: Integer;
  out RecsOut: Integer; Options: Integer; const CommandText: WideString;
  var Params, OwnerData: OleVariant): OleVariant;
begin
  Lock;
  try
    Result := Providers[ProviderName].GetRecords(Count, RecsOut, Options,
      CommandText, Params, OwnerData);
  finally
    UnLock;
  end;
end;

function TRemoteDataModule.AS_RowRequest(const ProviderName: WideString;
  Row: OleVariant; RequestType: Integer; var OwnerData: OleVariant): OleVariant;
begin
  Lock;
  try
    Result := Providers[ProviderName].RowRequest(Row, RequestType, OwnerData);
  finally
    UnLock;
  end;
end;

function TRemoteDataModule.AS_DataRequest(const ProviderName: WideString;
  Data: OleVariant): OleVariant; safecall;
begin
  Lock;
  try
    Result := Providers[ProviderName].DataRequest(Data);
  finally
    UnLock;
  end;
end;

function TRemoteDataModule.AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant;
begin
  Lock;
  try
    Result := Providers[ProviderName].GetParams(OwnerData);
  finally
    UnLock;
  end;
end;

procedure TRemoteDataModule.AS_Execute(const ProviderName: WideString;
  const CommandText: WideString; var Params, OwnerData: OleVariant);
begin
  Lock;
  try
    Providers[ProviderName].Execute(CommandText, Params, OwnerData);
  finally
    UnLock;
  end;
end;

class procedure TRemoteDataModule.UpdateRegistry(Register: Boolean;
  const ClassID, ProgID: string);
var
  CatReg: ICatRegister;
  Rslt: HResult;
  CatInfo: TCATEGORYINFO;
  Description: string;
begin
  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatRegister, CatReg);
  if Succeeded(Rslt) then
  begin
    if Register then
    begin
      CatInfo.catid := CATID_MIDASAppServer;
      CatInfo.lcid := $0409;
      StringToWideChar(MIDAS_CatDesc, CatInfo.szDescription,
        Length(MIDAS_CatDesc) + 1);
      OleCheck(CatReg.RegisterCategories(1, @CatInfo));
      OleCheck(CatReg.RegisterClassImplCategories(StringToGUID(ClassID), 1, @CATID_MIDASAppServer));
    end else
    begin
      OleCheck(CatReg.UnRegisterClassImplCategories(StringToGUID(ClassID), 1, @CATID_MIDASAppServer));
      DeleteRegKey(Format(SCatImplBaseKey, [ClassID]));
    end;
  end else
  begin
    if Register then
    begin
      CreateRegKey('Component Categories\' + GUIDToString(CATID_MIDASAppServer), '409', MIDAS_CatDesc);
      CreateRegKey(Format(SCatImplKey, [ClassID, GUIDToString(CATID_MIDASAppServer)]), '', '');
    end else
    begin
      DeleteRegKey(Format(SCatImplKey, [ClassID, GUIDToString(CATID_MIDASAppServer)]));
      DeleteRegKey(Format(SCatImplBaseKey, [ClassID]));
    end;
  end;
  if Register then
  begin
    Description := GetRegStringValue('CLSID\' + ClassID, '');
    CreateRegKey('AppID\' + ClassID, '', Description);
    CreateRegKey('CLSID\' + ClassID, 'AppID', ClassID);
  end else
    DeleteRegKey('AppID\' + ClassID);
end;

{TCRemoteDataModule}

constructor TCRemoteDataModule.Create(AOwner: TComponent);
begin
  InitializeCriticalSection(FLock);
  FProviders := TList.Create;
  inherited Create(AOwner);
end;

destructor TCRemoteDataModule.Destroy;
begin
  inherited Destroy;
  FProviders.Free;
  DeleteCriticalSection(FLock);
end;

procedure TCRemoteDataModule.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TCRemoteDataModule.Unlock;
begin
  LeaveCriticalSection(FLock);
end;

procedure TCRemoteDataModule.RegisterProvider(Value: TCustomProvider);
begin
  FProviders.Add(Value);
end;

procedure TCRemoteDataModule.UnRegisterProvider(Value: TCustomProvider);
begin
  FProviders.Remove(Value);
end;

function TCRemoteDataModule.CRDMGetProviderNames: OleVariant;
var
  List: TStringList;
  I, J: Integer;
begin
  Lock;
  try
    List := TStringList.Create;
    try
      for I := 0 to FProviders.Count - 1 do
        if TCustomProvider(FProviders[I]).Exported then
          List.Add(TCustomProvider(FProviders[I]).Name);
      List.Sort;
      if List.Count > 0 then
      begin
       Result := VarArrayCreate([0, List.Count -1], varOleStr);
       for J := 0 to List.Count -1 do Result[J] := WideString(List[J]);
    end;
    finally
      List.Free;
    end;
  finally
    UnLock;
  end;
end;


function TCRemoteDataModule.GetProvider(const ProviderName: string): TCustomProvider;
var
  i: Integer;
begin
  Result := nil;
  for i := 0 to FProviders.Count - 1 do
    if AnsiCompareStr(TCustomProvider(FProviders[i]).Name, ProviderName) = 0 then
    begin
      Result := TCustomProvider(FProviders[i]);
      if not Result.Exported then
        Result := nil;
      Exit;
    end;
  if not Assigned(Result) then
    raise Exception.CreateResFmt(@SProviderNotExported, [ProviderName]);
end;

end.
