{****************************************************************}
{                                                                }
{       Borland Delphi Visual Component Library                  }
{                                                                }
{       Copyright (c) 2000, 2001 Borland Software Corporation    }
{                                                                }
{****************************************************************}

unit AdaptReq;

interface

uses Classes, Messages, HTTPApp, HTTPProd, WebCntxt,
  Masks, WebComp, Contnrs, SysUtils, SiteComp;

type

  IActionFieldValue = interface;

  IActionFieldValues = interface
  ['{953B2DA3-7C6D-4F01-932B-0BD8B6C6DBB2}']
    function IndexOfField(const AName: string): Integer;
    function ValueOfField(const AName: string): IActionFieldValue;
    function OrigValueOfField(const AName: string): IActionFieldValue;
    function GetFieldCount: Integer;
    function GetFieldName(I: Integer): string;
    function GetValue(I: Integer): IActionFieldValue;
    function AddValue(const AName: string): IActionFieldValue;
    function GetOrigValue(I: Integer): IActionFieldValue;
    property FieldCount: Integer read GetFieldCount;
    property FieldNames[I: Integer]: string read GetFieldName;
    property OrigValues[I: Integer]: IActionFieldValue read GetOrigValue;
    property Values[I: Integer]: IActionFieldValue read GetValue;
  end;

  IAdapterRecordKeys = interface
  ['{96E79603-E01F-4F94-B1E0-6B4E87A5D954}']
    function GetRecordKeyCount: Integer;
    function GetRecordKeyName(I: Integer): string;
    function GetRecordKeyValue(I: Integer): string;
    property RecordKeyNames[I: Integer]: string read GetRecordKeyName;
    property RecordKeyValues[I: Integer]: string read GetRecordKeyValue;
  end;

  IAdapterModes = interface
  ['{7FD48996-5814-11D4-A492-00C04F6BB853}']
    function GetAdapterCount: Integer;
    function GetAdapterName(I: Integer): string;
    function GetAdapterMode(I: Integer): string;
    function FindAdapterMode(AAdapter: TObject; var AMode: string): Boolean;
    property AdapterModes[I: Integer]: string read GetAdapterMode;
    property AdapterNames[I: Integer]: string read GetAdapterName;
    property AdapterCount: Integer read GetAdapterCount;
  end;

  IEnumActionFieldValueRecords = interface
  ['{9C51CAD8-6297-4CCC-B9F4-F53020E42A00}']
    function GetNextRecord: Boolean;
    function GetFirstRecord: Boolean;
    procedure EndIterator;
    function GetEOF: Boolean;
    function GetRecord(AIndex: Integer): Boolean;
    function FindPopulatedRecord: Boolean;
    function GetRecordCount: Integer;
    function GetInIterator: Boolean;
    property EOF: Boolean read GetEOF;
    property RecordCount: Integer read GetRecordCount;
    property InIterator: Boolean read GetInIterator;
  end;

  IActionFieldValuesOfAdapter = interface
  ['{F982888E-B049-46C0-AC14-8652E6AC8D97}']
    function LocateActionFieldValuesOfAdapter(AAdapter: TComponent): Boolean;
  end;

  TAdapterActionRedirectOption = (roRedirectHTTPPost, roRedirectHTTPGet);
  TAdapterActionRedirectOptions = set of TAdapterActionRedirectOption;
  IGetAdapterActionRedirectOptions = interface
  ['{79D27D03-D50B-11D4-A534-00C04F6BB853}']
    function GetSuccessOptions: TAdapterActionRedirectOptions;
    function GetFailureOptions: TAdapterActionRedirectOptions;
    property SuccessOptions:  TAdapterActionRedirectOptions read GetSuccessOptions;
    property FailureOptions:  TAdapterActionRedirectOptions read GetFailureOptions;
  end;

  IAdapterRequestParams = interface
  ['{0394040F-414D-11D4-A47C-00C04F6BB853}']
    function GetParamName(I: Integer): string;
    function GetParamValue(I: Integer): string;
    function GetParamCount: Integer;
    function IndexOfParam(const AName: string): Integer;
    function ValueOfParam(const AName: string): string;
    procedure AssignTo(AStrings: TStrings);
    property ParamCount: Integer read GetParamCount;
    property ParamNames[I: Integer]: string read GetParamName;
    property ParamValues[I: Integer]: string read GetParamValue;
  end;

  IActionFieldValue = interface
  ['{C5D4E556-A474-11D4-A4FA-00C04F6BB853}']
    function GetFieldName: string;
    function GetValueCount: Integer;
    function GetValue(I: Integer): Variant;
    function GetFileCount: Integer;
    function GetFile(I: Integer): TAbstractWebRequestFile;
    property ValueCount: Integer read GetValueCount;
    property Values[I: Integer]: Variant read GetValue;
    property FileCount: Integer read GetFileCount;
    property Files[I: Integer]: TAbstractWebRequestFile read GetFile;
    property FieldName: string read GetFieldName;
  end;

  IActionRequest = interface
  ['{374E4AFC-D11F-11D4-A531-00C04F6BB853}']
    function GetActionName: string;
    function GetHandled: Boolean;
    procedure SetHandled(AValue: Boolean);
    property ActionName: string read GetActionName;
    property Handled: Boolean read GetHandled write SetHandled;
  end;

  IImageRequest = interface
  ['{9387A216-4392-48FB-9880-BFA8C5CC306E}']
    function GetImageName: string;
    property ImageName: string read GetImageName;
  end;

  TExecuteStatus = (esSuccess, esFail, esUndefined, esOther);
  IActionResponse = interface
  ['{03940410-414D-11D4-A47C-00C04F6BB853}']
    function GetHandled: Boolean;
    procedure SetHandled(Value: Boolean);
    function GetExecuteStatus: TExecuteStatus;
    procedure SetExecuteStatus(Value: TExecuteStatus);
    property ExecuteStatus: TExecuteStatus read GetExecuteStatus write SetExecuteStatus;
    property Handled: Boolean read GetHandled write SetHandled;
  end;

  TRespondWith = (rwPage, rwURL, rwComponentPage, rwUndefined);
  IActionRespondWith = interface
  ['{0FE6EE49-1015-4206-92A9-65655939E4EC}']
    function GetRespondWith: TRespondWith;
    procedure RespondWithPage(const APageName: string);
    procedure RespondWithURL(const AURL: string);
    procedure RespondWithComponentPage(const AComponent: TComponent);
    procedure SetExecuteStatus(Value: TExecuteStatus);
    function GetRedirectOptions: TAdapterActionRedirectOptions;
    procedure SetRedirectOptions(AOptions: TAdapterActionRedirectOptions);
    property RespondWith: TRespondWith read GetRespondWith;
    property RedirectOptions: TAdapterActionRedirectOptions read GetRedirectOptions write SetRedirectOptions;
  end;

  IActionHandleResponse = interface
  ['{BA0A46B9-519B-4733-B129-7680ADF33568}']
    procedure HandleResponse;
  end;

  IImageResponse = interface
  ['{739FE582-03BA-42CA-AE02-5557CD3856D3}']
  end;

  TBasicActionResponseImpl = class;

  TBasicImageResponseImpl = class;

  TAdapterRequestParamsImpl = class(TObject)
  private
    FStrings: TStrings;
    FDispatchParams: IAdapterDispatchParams;
  protected
    { IAdapterRequestParams }
    function GetParamName(I: Integer): string;
    function GetParamValue(I: Integer): string;
    function GetParamCount: Integer;
    function IndexOfParam(const AName: string): Integer;
    function ValueOfParam(const AName: string): string;
    procedure AssignTo(AStrings: TStrings);
    property ParamCount: Integer read GetParamCount;
    property ParamNames[I: Integer]: string read GetParamName;
    property ParamValues[I: Integer]: string read GetParamValue;
  public
    constructor Create(ADispatchParams: IAdapterDispatchParams);
  end;

  TAdapterModes = class(TObject)
  private
    FStrings: TStrings;
  protected
    { IAdapterModes }
    function GetAdapterCount: Integer;
    function GetAdapterName(I: Integer): string;
    function GetAdapterMode(I: Integer): string;
    function FindAdapterMode(AAdapter: TObject; var AMode: string): Boolean;
    property AdapterCount: Integer read GetAdapterCount;
  public
    constructor Create(ARequest: TWebRequest);
    destructor Destroy; override;
  end;

  TActionFieldValueImpl = class(TInterfacedObject, IActionFieldValue)
  private
    FValues: TStrings;
    FFiles: TObjectList;
    FFieldName: string;
  protected
    { IActionFieldValue }
    function GetValueCount: Integer;
    function GetValue(I: Integer): Variant;
    function GetFileCount: Integer;
    function GetFile(I: Integer): TAbstractWebRequestFile;
    function GetFieldName: string;
  public
    constructor Create(const AFieldName: string; AStrings: TStrings);
    destructor Destroy; override;
  end;

  TActionFieldValuesImpl = class(TObject)
  private
    FEncodedRecordKeys: TStrings;
    FRecordKeys: TStrings;
    FFieldNames: TStrings;
    FValues: TObjectList;
    FOrigValues: TObjectList;
    FOrigValuesIntf: IInterfaceList;
    FValuesIntf: IInterfaceList;
    function GetFieldCount: Integer;
    function GetValue(I: Integer): IActionFieldValue;
    function GetOrigValue(I: Integer): IActionFieldValue;
    function CreateValue(const AName: string): IActionFieldValue; overload;
    function CreateOrigValue(const AName: string): IActionFieldValue; overload;
    function CreateValue(I: Integer): IActionFieldValue; overload;
    function CreateOrigValue(I: Integer): IActionFieldValue; overload;
    procedure ExpandRecordKeys;
  protected
    { IActionFieldValues}
    function IndexOfField(const AName: string): Integer;
    function OrigValueOfField(const AName: string): IActionFieldValue;
    function ValueOfField(const AName: string): IActionFieldValue;
    function GetFieldName(I: Integer): string;
    function AddValue(const AName: string): IActionFieldValue;
    property FieldCount: Integer read GetFieldCount;
    property FieldNames[I: Integer]: string read GetFieldName;
    property OrigValues[I: Integer]: IActionFieldValue read GetOrigValue;
    property Values[I: Integer]: IActionFieldValue read GetValue;
    { IAdapterRecordKeys }
    function GetRecordKeyCount: Integer;
    function GetRecordKeyName(I: Integer): string;
    function GetRecordKeyValue(I: Integer): string;
  public
    constructor Create(AValues: TStrings);
    destructor Destroy; override;
  end;

  TEnumActionFieldValueRecordsImpl = class(TObject)
  private
    FAdapterName: string;
    FList: TObjectList;
    FCurrentIndex: Integer;
    FInIterator: Boolean;
    function GetCurrentFieldValues: TActionFieldValuesImpl;
  protected
    { IEnumActionFieldValueRecords }
    function GetNextRecord: Boolean;
    procedure EndIterator;
    function GetFirstRecord: Boolean;
    function GetEOF: Boolean;
    function GetRecord(AIndex: Integer): Boolean;
    function FindPopulatedRecord: Boolean;
    function GetRecordCount: Integer;
    function GetInIterator: Boolean;
    property EOF: Boolean read GetEOF;
  public
    constructor Create(const AAdapterName: string; AFieldValues: TStrings);
    destructor Destroy; override;
    property CurrentFieldValues: TActionFieldValuesImpl read GetCurrentFieldValues;
    property AdapterName: string read FAdapterName;
  end;

  TAdapterActionFieldValuesList = class(TObject)
  private
    FList: TObjectList;
    FCurrentIndex: Integer;
    function GetCurrentFieldValuesList: TEnumActionFieldValueRecordsImpl;
  protected
    { IActionFieldValuesOfAdapter }
    function LocateActionFieldValuesOfAdapter(AAdapter: TComponent): Boolean;
  public
    constructor Create(ARequest: TWebRequest);
    destructor Destroy; override;
    property CurrentActionFieldValuesList: TEnumActionFieldValueRecordsImpl read GetCurrentFieldValuesList;
  end;

  TBasicActionRequestImpl = class(TAbstractAdapterRequest, IActionRequest, IAdapterRequestParams,
    IGetAdapterRequestDefaultResponse)
  private
    FActionParams: TAdapterRequestParamsImpl;
    FDispatchParams: IAdapterDispatchParams;
    FSuccessPage: string;
    FFailurePage: string;
    FHandled: Boolean;
  protected
    { IActionRequest }
    function GetActionName: string;
    function GetHandled: Boolean;
    procedure SetHandled(AValue: Boolean);

    { IGetAdapterRequestDefaultResponse }
    function GetSuccessPage: string;
    function GetFailurePage: string;
  public
    constructor Create(ADispatchParams: IAdapterDispatchParams);
    destructor Destroy; override;
    property ActionName: string read GetActionName;
    property DispatchParams: IAdapterDispatchParams read FDispatchParams;
    property ActionParams: TAdapterRequestParamsImpl read FActionParams implements IAdapterRequestParams;
    property SuccessPage: string read GetSuccessPage;
    property FailurePage: string read GetFailurePage;
  end;

  TSingleRecordActionRequestImpl = class(TBasicActionRequestImpl, IAdapterModes,
    IActionFieldValues)
  private
    FFieldValues: TActionFieldValuesImpl;
    FAdapterModes: TAdapterModes;
  protected
    property ActionFieldValues: TActionFieldValuesImpl read FFieldValues implements IActionFieldValues;
    property AdapterModes: TAdapterModes read FAdapterModes implements IAdapterModes;
  public
    constructor Create(ADispatchParams: IAdapterDispatchParams);
    destructor Destroy; override;
  end;

  TMultiRecordActionRequestImpl = class(TBasicActionRequestImpl, IAdapterModes,
    IActionFieldValues, IEnumActionFieldValueRecords, IAdapterRecordKeys, IActionFieldValuesOfAdapter)
  private
    FAdapterActionFieldValuesList: TAdapterActionFieldValuesList;
    FAdapterModes: TAdapterModes;
    function GetFieldValues: TActionFieldValuesImpl;
    function GetFieldValuesList: TEnumActionFieldValueRecordsImpl;
  protected
    property ActionFieldValues: TActionFieldValuesImpl read GetFieldValues implements IAdapterRecordKeys;
    property ActionFieldValues2: TActionFieldValuesImpl read GetFieldValues implements IActionFieldValues;
    property AdapterModes: TAdapterModes read FAdapterModes implements IAdapterModes;
    property ActionFieldValuesList: TEnumActionFieldValueRecordsImpl read GetFieldValuesList implements IEnumActionFieldValueRecords;
    property AdapterActionFieldValuesList: TAdapterActionFieldValuesList read FAdapterActionFieldValuesList implements IActionFieldValuesOfAdapter;
  public
    constructor Create(ADispatchParams: IAdapterDispatchParams);
    destructor Destroy; override;
  end;

  TBasicActionResponseImpl = class(TAbstractAdapterResponse, IActionResponse,
    IActionRespondWith, IActionHandleResponse)
  private
    FExecuteStatus: TExecuteStatus;
    FHandled: Boolean;
    FRespondWith: TRespondWith;
    FPageName: string;
    FRedirectOptions: TAdapterActionRedirectOptions;
    FURL: string;
    FComponent: TComponent;
    FActionRequest: TBasicActionRequestImpl;
    function SuccessRedirect: TAdapterActionRedirectOptions;
    function FailureRedirect: TAdapterActionRedirectOptions;
    function GetFailurePage: string;
    function GetSuccessPage: string;
  protected
    procedure RespondWithSuccessPage;
    procedure RespondWithFailurePage;
    { IActionResponse }
    function GetHandled: Boolean;
    procedure SetHandled(Value: Boolean);
    function GetExecuteStatus: TExecuteStatus;
    procedure SetExecuteStatus(Value: TExecuteStatus);
    { IActionRespondWith }
    function GetRespondWith: TRespondWith;
    procedure RespondWithPage(const APageName: string);
    procedure RespondWithURL(const AURL: string);
    procedure RespondWithComponentPage(const AComponent: TComponent);
    function GetRedirectOptions: TAdapterActionRedirectOptions;
    procedure SetRedirectOptions(AOptions: TAdapterActionRedirectOptions);
    { IActionHandleResponse }
    procedure HandleResponse;
  public
    constructor Create(AActionRequest: TBasicActionRequestImpl);
    property RedirectOptions: TAdapterActionRedirectOptions read GetRedirectOptions write SetRedirectOptions;
    property RespondWith: TRespondWith read GetRespondWith;
    property ExecuteStatus: TExecuteStatus read GetExecuteStatus write SetExecuteStatus;
    property Handled: Boolean read GetHandled write SetHandled;
    property FailurePage: string read GetFailurePage;
    property SuccessPage: string read GetSuccessPage;
  end;

  TBasicImageRequestImpl = class(TAbstractAdapterRequest, IImageRequest,
    IAdapterRequestParams)
  private
    FImageParams: TAdapterRequestParamsImpl;
    FDispatchParams: IAdapterDispatchParams;
  protected
    { IImageRequest }
    function GetImageName: string;
    property ImageName: string read GetImageName;
    property ActionRequestParams: TAdapterRequestParamsImpl read FImageParams implements IAdapterRequestParams;
  public
    constructor Create(ADispatchParams: IAdapterDispatchParams);
    destructor Destroy; override;
    property DispatchParams: IAdapterDispatchParams read FDispatchParams;
  end;

  TBasicImageResponseImpl = class(TAbstractAdapterResponse, IImageResponse)
  public
    constructor Create(AImageRequest: TBasicImageRequestImpl);
  end;

  EAdapterRequestException = class(EWebBrokerException);

const
  roRedirect = [roRedirectHTTPPost, roRedirectHTTPGet];
  sDelimAdapterMode = '__am.';            { Do not localize }
  sDelimRecordKeys = '__key.';
  sDelimOrigFieldValue = '__ov.';    { Do not localize }
  sActionRequest = '__act';        { Do not localize }

  function ExtractStringValue(const S: string): string;

  function TestRedirectOptions(AOptions: TAdapterActionRedirectOptions; AMethodType: TMethodType): Boolean;


implementation

uses WebConst, Windows,
 WebScript, WebSess, Variants, WebDisp;

function FindDefaultComponentOwnerPageName(AComponent: TComponent): string;
var
  ComponentOwner: TComponent;
  Intf: IUnknown;
  PageInfo: TAbstractWebPageInfo;
begin
  Result := '';
  ComponentOwner := AComponent.Owner;
  if ComponentOwner = nil then
    ComponentOwner := AComponent;
  if Supports(IUnknown(ComponentOwner), IPageResult, Intf) then
    if WebContext.FindDefaultPageInfo(TComponentClass(ComponentOwner.ClassType), PageInfo) then
      Result := PageInfo.PageName
end;

function ExtractStringValue(const S: string): string;
var
  P: Integer;
begin
  P := AnsiPos('=', S);
  if (P <> 0) and (Length(S) > P) then
    Result := Copy(S, P+1, MaxInt) else
    SetLength(Result, 0);
end;

procedure RaiseActionDoesNotProvideResponse;
begin
  raise EAdapterRequestException.Create(sActionDoesNotProvideResponse);
end;

procedure RaiseCantResponseToUnknownHTTPMethod;
begin
  raise EAdapterRequestException.Create(sActionCantRespondToUnkownHTTPMethod);
end;

procedure RaiseActionCantRedirectToBlankURL;
begin
  raise EAdapterRequestException.Create(sActionCantRedirectToBlankURL);
end;

function TestRedirectOptions(AOptions: TAdapterActionRedirectOptions; AMethodType: TMethodType): Boolean;
begin
  Result := False;
  case AMethodType of
    mtGet:
      Result := roRedirectHTTPGet in AOptions;
    mtPost:
      Result := roRedirectHTTPPost in AOptions;
  else
    RaiseCantResponseToUnknownHTTPMethod;
  end;
end;

{ TAdapterRequestParamsImpl }

procedure TAdapterRequestParamsImpl.AssignTo(AStrings: TStrings);
begin
  AStrings.Assign(FStrings);
end;

constructor TAdapterRequestParamsImpl.Create(ADispatchParams: IAdapterDispatchParams);
begin
  inherited Create;
  FDispatchParams := ADispatchParams;
  FStrings := FDispatchParams.GetParams;
end;

function TAdapterRequestParamsImpl.GetParamCount: Integer;
begin
  Result := FStrings.Count;
end;

function TAdapterRequestParamsImpl.GetParamName(I: Integer): string;
begin
  Result := FStrings.Names[I];
end;

function TAdapterRequestParamsImpl.GetParamValue(I: Integer): string;
begin
  Result := ExtractStringValue(FStrings[I]);
end;

function TAdapterRequestParamsImpl.IndexOfParam(const AName: string): Integer;
begin
  Result := FStrings.IndexOf(AName);
end;

function TAdapterRequestParamsImpl.ValueOfParam(const AName: string): string;
begin
  Result := FStrings.Values[AName];
end;

{ TActionFieldValuesImpl }

constructor TActionFieldValuesImpl.Create(AValues: TStrings);

  procedure AddValues;
  var
    I, J: Integer;
    Name: string;
  begin
    for I := 0 to AValues.Count - 1 do
    begin
      Name := AValues.Names[I];
      if SameText(Copy(Name, 1, Length(sDelimOrigFieldValue)), sDelimOrigFieldValue) then
        Delete(Name, 1, Length(sDelimOrigFieldValue))
      else if SameText(Copy(Name, 1, Length(sDelimRecordKeys)), sDelimRecordKeys) then
      begin
        FEncodedRecordKeys.Add(ExtractStringValue(AValues[I]));
        Name := '';
      end
      else if Copy(Name, 1, 2) = '__' then
        Name := '';
      if (Name <> '') and (FFieldNames.IndexOf(Name) = -1) then
      begin
        FFieldNames.Add(Name);
        FValues.Add(TStringList.Create);
        FOrigValues.Add(TStringList.Create);
      end
    end;
    for I := 0 to AValues.Count - 1 do
    begin
      Name := AValues.Names[I];
      if SameText(Copy(Name, 1, Length(sDelimOrigFieldValue)), sDelimOrigFieldValue) then
      begin
        Delete(Name, 1, Length(sDelimOrigFieldValue));
        J := FFieldNames.IndexOf(Name);
        if J <> -1 then
          TStrings(FOrigValues[J]).Add(ExtractStringValue(AValues[I]));
      end
      else
      begin
        J := FFieldNames.IndexOf(Name);
        if J <> -1 then
          if AValues.Objects[I] <> nil then
            TStrings(FValues[J]).AddObject(ExtractStringValue(AValues[I]),
              AValues.Objects[I])
          else
            TStrings(FValues[J]).Add(ExtractStringValue(AValues[I]));
      end;
    end;
  end;

begin
  inherited Create;
  FEncodedRecordKeys := TStringList.Create;
  FRecordKeys := TStringList.Create;
  FFieldNames := TStringList.Create;
  FValues := TObjectList.Create(True {Owned});
  FOrigValues := TObjectList.Create(True {Owned});
  if AValues <> nil then
    AddValues;
end;

function TActionFieldValuesImpl.GetFieldCount: Integer;
begin
  Result := FValues.Count;
end;

function TActionFieldValuesImpl.GetFieldName(I: Integer): string;
begin
  Result := FFieldNames[I];
end;

function TActionFieldValuesImpl.AddValue(
  const AName: string): IActionFieldValue;
begin
  if FFieldNames.IndexOf(AName) < 0 then
  begin
    FFieldNames.Add(AName);
    FValues.Add(TStringList.Create);
    FOrigValues.Add(TStringList.Create);
  end
  else
    Assert(False);
end;

function TActionFieldValuesImpl.IndexOfField(const AName: string): Integer;
begin
  Result := FFieldNames.IndexOf(AName);
end;

function TActionFieldValuesImpl.CreateValue(I: Integer): IActionFieldValue;
var
  S: TStrings;
begin
  if I < FFieldNames.Count then
  begin
    if FValuesIntf = nil then
    begin
      FValuesIntf := TInterfaceList.Create;
      FValuesIntf.Count := FFieldNames.Count;
    end;
    if FValuesIntf[I] = nil then
    begin
      S := TStrings(FValues[I]);
      FValuesIntf[I] := (TActionFieldValueImpl.Create(FFieldNames[I], S) as IActionFieldValue);
    end;
    Result := IActionFieldValue(FValuesIntf[I]);
  end
  else
    Result := nil;
end;

function TActionFieldValuesImpl.CreateValue(const AName: string): IActionFieldValue;
var
  I: Integer;
begin
  I := IndexOfField(AName);
  if I >= 0 then
    Result := CreateValue(I)
  else
    Result := nil;
end;

function TActionFieldValuesImpl.CreateOrigValue(const AName: string): IActionFieldValue;
var
  I: Integer;
begin
  I := IndexOfField(AName);
  if I >= 0 then
    Result := CreateOrigValue(I)
  else
    Result := nil;
end;

function TActionFieldValuesImpl.CreateOrigValue(I: Integer): IActionFieldValue;
var
  S: TStrings;
begin
  if I < FFieldNames.Count then
  begin
    if FOrigValuesIntf = nil then
    begin
      FOrigValuesIntf := TInterfaceList.Create;
      FOrigValuesIntf.Count := FFieldNames.Count;
    end;
    if FOrigValuesIntf[I] = nil then
    begin
      S := TStrings(FOrigValues[I]);
      FOrigValuesIntf[I] := (TActionFieldValueImpl.Create(FFieldNames[I], S) as IActionFieldValue);
    end;
    Result := IActionFieldValue(FOrigValuesIntf[I]);
  end
  else
    Result := nil;
end;

function TActionFieldValuesImpl.ValueOfField(const AName: string): IActionFieldValue;
begin
  Result := CreateValue(AName);
end;

function TActionFieldValuesImpl.OrigValueOfField(const AName: string): IActionFieldValue;
begin
  Result := CreateOrigValue(AName);
end;

function TActionFieldValuesImpl.GetValue(I: Integer): IActionFieldValue;
begin
  Result := CreateValue(I);
end;

function TActionFieldValuesImpl.GetOrigValue(I: Integer): IActionFieldValue;
begin
  Result := CreateOrigValue(I);
end;

destructor TActionFieldValuesImpl.Destroy;
begin
  inherited;
  FValues.Free;
  FEncodedRecordKeys.Free;
  FRecordKeys.Free;
  FOrigValues.Free;
  FFieldNames.Free;
end;

{ TBasicActionRequestImpl }

constructor TBasicActionRequestImpl.Create(ADispatchParams: IAdapterDispatchParams);
var
  Intf: IGetAdapterRequestDefaultResponse;
begin
  inherited Create;
  FDispatchParams := ADispatchParams;
  FActionParams := TAdapterRequestParamsImpl.Create(ADispatchParams);
  if Supports(FDispatchParams, IGetAdapterRequestDefaultResponse, Intf) then
  begin
    FSuccessPage := Intf.SuccessPage;
    FFailurePage := Intf.FailurePage;
  end;
  if FSuccessPage = '' then
    FSuccessPage := PageNameOfRequest(Request);
  if FFailurePage = '' then
    FFailurePage := PageNameOfRequest(Request);
end;

destructor TBasicActionRequestImpl.Destroy;
begin
  inherited;
  FActionParams.Free;
end;

function TBasicActionRequestImpl.GetActionName: string;
begin
  Result := FDispatchParams.ObjectIdentifier;
end;

function TBasicActionRequestImpl.GetFailurePage: string;
begin
  Result := FFailurePage;
end;

function TBasicActionRequestImpl.GetHandled: Boolean;
begin
  Result := FHandled;
end;

function TBasicActionRequestImpl.GetSuccessPage: string;
begin
  Result := FSuccessPage;
end;

procedure TBasicActionRequestImpl.SetHandled(AValue: Boolean);
begin
  FHandled := AValue;
end;

{ TSingleRecordActionRequestImpl }

constructor TSingleRecordActionRequestImpl.Create(ADispatchParams: IAdapterDispatchParams);
var
  I: Integer;
  S: TStrings;
begin
  inherited Create(ADispatchParams);
  S := TStringList.Create;
  try
    S.AddStrings(Request.QueryFields);
    S.AddStrings(Request.ContentFields);
    if Request.Files <> nil then
      for I := 0 to Request.Files.Count - 1 do
        S.AddObject(Format('%s=%s', [Request.Files[I].FieldName, Request.Files[I].FileName]), Request.Files[I]);
    FFieldValues := TActionFieldValuesImpl.Create(S);
  finally
    S.Free;
  end;
  FAdapterModes := TAdapterModes.Create(Request);
end;

destructor TSingleRecordActionRequestImpl.Destroy;
begin
  inherited;
  FFieldValues.Free;
  FAdapterModes.Free;
end;

{ TBasicActionResponseImpl }

constructor TBasicActionResponseImpl.Create(AActionRequest: TBasicActionRequestImpl);
begin
  inherited Create;
  FActionRequest := AActionRequest;
  FExecuteStatus := esUndefined;
  FRespondWith := rwUndefined;
end;

function TBasicActionResponseImpl.GetExecuteStatus: TExecuteStatus;
begin
  Result := FExecuteStatus;
end;

function TBasicActionResponseImpl.GetHandled: Boolean;
begin
  Result := FHandled;
end;

function TBasicActionResponseImpl.GetRespondWith: TRespondWith;
begin
  Result := FRespondWith;
end;

procedure TBasicActionResponseImpl.SetExecuteStatus(Value: TExecuteStatus);
begin
  FExecuteStatus := Value;
  if RespondWith = rwUndefined then
  begin
    case FExecuteStatus of
      esFail: if FailurePage <> '' then begin RespondWithFailurePage end;
    else
      if SuccessPage <> '' then
        RespondWithSuccessPage;
    end;
  end;
end;

procedure TBasicActionResponseImpl.SetHandled(Value: Boolean);
begin
  FHandled := Value;
end;

procedure TBasicActionResponseImpl.RespondWithComponentPage(
  const AComponent: TComponent);
begin
  FComponent := AComponent;
  FRespondWith := rwComponentPage;
end;

procedure TBasicActionResponseImpl.RespondWithPage(const APageName: string);
begin
  FPageName := APageName;
  FRespondWith := rwPage;
end;

procedure TBasicActionResponseImpl.RespondWithURL(const AURL: string);
begin
  FURL := AURL;
  FRespondWith := rwURL;
end;

procedure TBasicActionResponseImpl.HandleResponse;

  procedure RespondWithPage(const APage: string);
  var
    Redirect: Boolean;
    S: TStrings;
  begin
    Redirect := False;
    if WebContext.Request <> nil then
      Redirect := TestRedirectOptions(RedirectOptions, WebContext.Request.MethodType);
    if Redirect then
    begin
      S := TStringList.Create;
      try
        RedirectToPageName(APage, S, Response, []);
      finally
        S.Free;
      end
    end
    else
      DispatchPageName(APage, Response, []);
  end;
begin
  case RespondWith of
    rwUndefined:
      RaiseActionDoesNotProvideResponse;
    rwComponentPage:
    begin
      Assert(FComponent <> nil);
      RespondWithPage(FindDefaultComponentOwnerPageName(FComponent));
    end;
    rwURL:
    begin
      if FURL = '' then
        RaiseActionCantRedirectToBlankURL;
      if Response.Cookies.Count > 0 then
        SafeRedirect(Response, FURL)
      else
        Response.SendRedirect(FURL);
    end;
    rwPage:
    begin
      RespondWithPage(FPageName);
    end;
  else
    Assert(False); // Unknown respondwith type
  end;
end;

function TBasicActionResponseImpl.GetRedirectOptions: TAdapterActionRedirectOptions;
begin
  Result := FRedirectOptions;
end;

procedure TBasicActionResponseImpl.SetRedirectOptions(
  AOptions: TAdapterActionRedirectOptions);
begin
  FRedirectOptions := AOptions;
end;

procedure TBasicActionResponseImpl.RespondWithFailurePage;
begin
  RespondWithPage(FailurePage);
  RedirectOptions := FailureRedirect;
end;

procedure TBasicActionResponseImpl.RespondWithSuccessPage;
begin
  RespondWithPage(SuccessPage);
  RedirectOptions := SuccessRedirect;
end;

function TBasicActionResponseImpl.FailureRedirect: TAdapterActionRedirectOptions;
var
  Intf: IGetAdapterActionRedirectOptions;
begin
  if Supports(FActionRequest.DispatchParams.Handler, IGetAdapterActionRedirectOptions,
     Intf) then
    Result := Intf.FailureOptions
  else
    Result := [];
end;

function TBasicActionResponseImpl.SuccessRedirect: TAdapterActionRedirectOptions;
var
  Intf: IGetAdapterActionRedirectOptions;
begin
  if Supports(FActionRequest.DispatchParams.Handler, IGetAdapterActionRedirectOptions,
     Intf) then
    Result := Intf.SuccessOptions
  else
    Result := [];
end;

function TBasicActionResponseImpl.GetFailurePage: string;
begin
  Result := FActionRequest.FailurePage;
end;

function TBasicActionResponseImpl.GetSuccessPage: string;
begin
  Result := FActionRequest.SuccessPage;
end;

{ TAdapterModes }

constructor TAdapterModes.Create(ARequest: TWebRequest);
  procedure GetModes(S: TStrings);
  var
    I: Integer;
  begin
    for I := 0 to S.Count - 1 do
      if SameText(Copy(S.Names[I], 1, Length(sDelimAdapterMode)), sDelimAdapterMode) then
        FStrings.Add(Copy(S[I], Length(sDelimAdapterMode)+1, MaxInt));
  end;
begin
  inherited Create;
  FStrings := TStringList.Create;
  GetModes(ARequest.QueryFields);
  GetModes(ARequest.ContentFields);
end;

function TAdapterModes.GetAdapterCount: Integer;
begin
  Result := FStrings.Count;
end;

function TAdapterModes.GetAdapterName(I: Integer): string;
begin
  Result := FStrings.Names[I];
end;

function TAdapterModes.GetAdapterMode(I: Integer): string;
begin
  Result := ExtractStringValue(FStrings[I]);
end;

function TAdapterModes.FindAdapterMode(AAdapter: TObject;
  var AMode: string): Boolean;
var
  WebVariableName: IWebVariableName;
  I: Integer;
  Name: string;
begin
  Result := False;
  if Supports(AAdapter, IWebVariableName, WebVariableName) then
  begin
    Name := WebVariableName.VariableName;
    for I := 0 to FStrings.Count - 1 do
    begin
      Assert(Pos('.', FStrings.Names[I])=0, 'Fully qualified adapter names not supported');
      if FStrings.Names[I] = Name then
      begin
        AMode := ExtractStringValue(FStrings[I]);
        Result := True;
        break;
      end;
    end;
  end;
end;

destructor TAdapterModes.Destroy;
begin
  inherited;
  FStrings.Free;
end;

{ TBasicImageRequestImpl }

constructor TBasicImageRequestImpl.Create(ADispatchParams: IAdapterDispatchParams);
begin
  inherited Create;
  FDispatchParams := ADispatchParams;
  FImageParams := TAdapterRequestParamsImpl.Create(ADispatchParams);
end;

destructor TBasicImageRequestImpl.Destroy;
begin
  inherited;
  FImageParams.Free;
end;

function TBasicImageRequestImpl.GetImageName: string;
begin
  Result := FDispatchParams.ObjectIdentifier;
end;

{ TBasicImageResponseImpl }

constructor TBasicImageResponseImpl.Create(AImageRequest: TBasicImageRequestImpl);
begin
  inherited Create;
end;

{ TActionFieldValueImpl }

constructor TActionFieldValueImpl.Create(const AFieldName: string; AStrings: TStrings);
var
  I: Integer;
begin
  FFieldName := AFieldName;
  FFiles := TObjectList.Create(False { not owned });
  FValues := TStringList.Create;
  if AStrings <> nil then
    for I := 0 to AStrings.Count - 1 do
    begin
      if AStrings.Objects[I] <> nil then
        FFiles.Add(AStrings.Objects[I])
      else
        FValues.Add(AStrings[I])
    end;

end;

destructor TActionFieldValueImpl.Destroy;
begin
  inherited;
  FFiles.Free;
  FValues.Free;
end;

function TActionFieldValueImpl.GetFieldName: string;
begin
  Result := FFieldName;
end;

function TActionFieldValueImpl.GetFile(I: Integer): TAbstractWebRequestFile;
begin
  Result := FFiles[I] as TAbstractWebRequestFile;
end;

function TActionFieldValueImpl.GetFileCount: Integer;
begin
  Result := FFiles.Count;
end;

function TActionFieldValueImpl.GetValue(I: Integer): Variant;
begin
  Result := FValues[I];
end;

function TActionFieldValueImpl.GetValueCount: Integer;
begin
  Result := FValues.Count;
end;

{ TMultiRecordActionRequestImpl }

constructor TMultiRecordActionRequestImpl.Create(
  ADispatchParams: IAdapterDispatchParams);
begin
  inherited Create(ADispatchParams);
  FAdapterActionFieldValuesList := TAdapterActionFieldValuesList.Create(Request);
  FAdapterModes := TAdapterModes.Create(Request);
end;

destructor TMultiRecordActionRequestImpl.Destroy;
begin
  inherited;
  FAdapterActionFieldValuesList.Free;
  FAdapterModes.Free;
end;

function TMultiRecordActionRequestImpl.GetFieldValues: TActionFieldValuesImpl;
begin
  Result := GetFieldValuesList.CurrentFieldValues;
  Assert(Result <> nil);
end;

{ TEnumActionFieldValueRecordsImpl }

constructor TEnumActionFieldValueRecordsImpl.Create(const AAdapterName: string; AFieldValues: TStrings);

  procedure MoveValues(ASrc, ADest: TActionFieldValuesImpl; const AName: string; AIndex: Integer);
  begin
    ADest.FFieldNames.Add(AName);
    ADest.FValues.Add(ASrc.FValues[AIndex]);
    ADest.FOrigValues.Add(ASrc.FOrigValues[AIndex]);
    ASrc.FFieldNames.Delete(AIndex);
    ASrc.FValues.Extract(ASrc.FValues[AIndex]);
    ASrc.FOrigValues.Extract(ASrc.FOrigValues[AIndex]);
  end;

  function NameAndIndex(const AName: string; var AIndex: Integer): string;
  var
    P: Integer;
  begin
    Result := AName;
    AIndex := -1;
    P := Pos('.', Result);
    if P > 0 then
    begin
      try
        AIndex := StrToInt(Copy(Result, P+1, MaxInt));
        Delete(Result, P, MaxInt);
      except
        // Ignore exception
      end;
    end;
  end;
var
  I, J: Integer;
  S: TStrings;
begin
  FList := TObjectList.Create(True {Owned});
  FAdapterName := AAdapterName;
  if (AFieldValues <> nil) and
     (AFieldValues.Count > 0) and
    (AFieldValues.Objects[0] <> nil) and
    AFieldValues.Objects[0].InheritsFrom(TStrings) then
  begin
    for I := 0 to AFieldValues.Count - 1 do
    begin
      S := TStringList.Create;
      try
        Assert(AFieldValues.Objects[I] <> nil);
        with AFieldValues.Objects[I] as TStrings do
          for J := 0 to Count - 1 do
            S.AddObject(Strings[J], Objects[J]);
        FList.Add(TActionFieldValuesImpl.Create(S))
      finally
        S.Free;
      end;
    end;
  end
  else
    FList.Add(TActionFieldValuesImpl.Create(AFieldValues));
end;

destructor TEnumActionFieldValueRecordsImpl.Destroy;
begin
  inherited;
  FList.Free;
end;

function TEnumActionFieldValueRecordsImpl.FindPopulatedRecord: Boolean;
var
  I: Integer;
  Value: TActionFieldValuesImpl;
begin
  for I := 0 to FList.Count - 1 do
  begin
    Value := FList[I] as TActionFieldValuesImpl;
    if Value.FieldCount > 0 then
    begin
      FCurrentIndex := I;
      Result := True;
      Exit;
    end;
  end;
  Result := False;
end;

function TEnumActionFieldValueRecordsImpl.GetRecordCount: Integer;
begin
  Result := FList.Count;
end;

function TEnumActionFieldValueRecordsImpl.GetInIterator: Boolean;
begin
  Result := FInIterator;
end;

function TEnumActionFieldValueRecordsImpl.GetCurrentFieldValues: TActionFieldValuesImpl;
begin
  if FCurrentIndex < FList.Count then
    Result := FList[FCurrentIndex] as TActionFieldValuesImpl
  else
  begin
    Assert(False);
    Result := nil;
  end;
end;

function TEnumActionFieldValueRecordsImpl.GetEOF: Boolean;
begin
  Result := FCurrentIndex >= FList.Count;
end;

function TEnumActionFieldValueRecordsImpl.GetFirstRecord: Boolean;
begin
  FCurrentIndex := 0;
  Result := not GetEOF;
  FInIterator := Result;
end;

function TEnumActionFieldValueRecordsImpl.GetNextRecord: Boolean;
begin
  Inc(FCurrentIndex);
  Result := not GetEOF;
  FInIterator := Result;
end;

procedure TEnumActionFieldValueRecordsImpl.EndIterator;
begin
  FInIterator := False;
  FCurrentIndex := 0;
end;

function TEnumActionFieldValueRecordsImpl.GetRecord(AIndex: Integer): Boolean;
begin
  Result := AIndex < FList.Count;
  if Result then
    FCurrentIndex := AIndex;
end;

procedure TActionFieldValuesImpl.ExpandRecordKeys;
begin
  if (FEncodedRecordKeys.Count > 0) and
    (FRecordKeys.Count = 0) then
  begin
    Assert(FEncodedRecordKeys.Count = 1);  // All keys are encoded in a single value
    ExtractParamNameValues(FEncodedRecordKeys[0], FRecordKeys);
  end;
end;

function TActionFieldValuesImpl.GetRecordKeyCount: Integer;
begin
  ExpandRecordKeys;
  Result := FRecordKeys.Count;
end;

function TActionFieldValuesImpl.GetRecordKeyName(I: Integer): string;
begin
  Result := FRecordKeys.Names[I];
end;

function TActionFieldValuesImpl.GetRecordKeyValue(I: Integer): string;
begin
  Result := ExtractStringValue(FRecordKeys[I]);
end;

{ TAdapterActionFieldValuesList }

constructor TAdapterActionFieldValuesList.Create(ARequest: TWebRequest);
var
  CollectStrings: TObjectList;
  AllAdapterStrings: TStrings;

  function NewStrings: TStrings;
  begin
    Result := TStringList.Create;
    CollectStrings.Add(Result);
  end;

  function FindAdapterStrings(const AAdapterName: string): TStrings;
  var
    IndexOfAdapter: Integer;
  begin
    IndexOfAdapter := AllAdapterStrings.IndexOf(AAdapterName);
    if IndexOfAdapter = -1 then
    begin
      AllAdapterStrings.AddObject(AAdapterName, NewStrings);
      IndexOfAdapter := AllAdapterStrings.Count-1;
    end;
    Result := (AllAdapterStrings.Objects[IndexOfAdapter]) as TStrings;
    Assert(Result <> nil);
  end;

  function FindAdapterRecordStrings(AAdapterStrings: TStrings; ARecordIndex: Integer): TStrings;
  begin
    if ARecordIndex >= 0 then
    begin
      while AAdapterStrings.Count <= ARecordIndex do
        AAdapterStrings.AddObject('', NewStrings);
      Result := AAdapterStrings.Objects[ARecordIndex] as TStrings;
    end
    else
      Result := AAdapterStrings;
    Assert(Result <> nil);
  end;

  function ExtractRecordIndex(var AName: string): Integer;
  var
    P: Integer;
  begin
    Result := -1;
    P := Pos('.', AName);
    if P > 0 then
      try
        Result := StrToInt(Copy(AName, P+1, MaxInt));
        Delete(AName, P, MaxInt);
      except
      end;
  end;

  function ExtractAdapterName(var AName: string): string;
  var
    P: Integer;
  begin
    Result := '';
    P := Pos('-', AName);
    if P > 0 then
    begin
      Result := Copy(AName, 1, P-1);
      Delete(AName, 1, P);
    end;
  end;

var
  S: TStrings;
  I: integer;
  Name, AdapterName: string;
  RecordIndex: Integer;
  OrigValue, RecordKeys, NewValue: Boolean;
  NameValue: string;
  AdapterStrings: TStrings;
  AdapterRecordStrings: TStrings;
begin
  inherited Create;
  FList := TObjectList.Create(True {Owned});
  CollectStrings := TObjectList.Create(True {Owned});
  try
    S := NewStrings;
    S.AddStrings(ARequest.QueryFields);
    S.AddStrings(ARequest.ContentFields);
    if ARequest.Files <> nil then
      for I := 0 to ARequest.Files.Count - 1 do
        S.AddObject(Format('%s=%s', [ARequest.Files[I].FieldName, ARequest.Files[I].FileName]), ARequest.Files[I]);

    AllAdapterStrings := NewStrings;
    for I := 0 to S.Count - 1 do
    begin
      OrigValue := False;
      RecordKeys := False;
      NewValue := False;
      RecordIndex := -1;
      AdapterName := '';
      Name := S.Names[I];
      if SameText(Copy(Name, 1, Length(sDelimOrigFieldValue)), sDelimOrigFieldValue) then
      begin
        Delete(Name, 1, Length(sDelimOrigFieldValue));
        OrigValue := True;
        AdapterName := ExtractAdapterName(Name);
        RecordIndex := ExtractRecordIndex(Name);
      end
      else if SameText(Copy(Name, 1, Length(sDelimRecordKeys)), sDelimRecordKeys) then
      begin
        RecordKeys := True;
        Delete(Name, 1, Length(sDelimRecordKeys));
        AdapterName := ExtractAdapterName(Name);
        RecordIndex := ExtractRecordIndex(Name);
      end
      else if Copy(Name, 1, 2) <> '__' then
      begin
        NewValue := True;
        AdapterName := ExtractAdapterName(Name);
        RecordIndex := ExtractRecordIndex(Name);
      end;
      if (OrigValue or RecordKeys or NewValue) then
      begin
        AdapterStrings := FindAdapterStrings(AdapterName);
        AdapterRecordStrings := FindAdapterRecordStrings(AdapterStrings, RecordIndex);
        if OrigValue or NewValue then
        begin
          NameValue := Format('%s=%s', [Name, ExtractStringValue(S[I])]);
          if OrigValue then
            NameValue := sDelimOrigFieldValue + NameValue;
        end
        else
        begin
          Assert(RecordKeys);
          NameValue := Format('%s=%s', [AdapterName, ExtractStringValue(S[I])]);
          if RecordKeys then
            NameValue := sDelimRecordKeys + NameValue;
        end;
        AdapterRecordStrings.AddObject(NameValue, S.Objects[I]);
      end;
    end;
    if AllAdapterStrings.Count = 0 then
    begin
      FList.Add(TEnumActionFieldValueRecordsImpl.Create('', nil));
    end
    else
      for I := 0 to AllAdapterStrings.Count - 1 do
      begin
        Assert(AllAdapterStrings.Objects[I] <> nil);
        FList.Add(TEnumActionFieldValueRecordsImpl.Create(AllAdapterStrings[I], AllAdapterStrings.Objects[I] as TStrings));
      end;
  finally
    CollectStrings.Free;
  end;
end;


destructor TAdapterActionFieldValuesList.Destroy;
begin
  inherited;
  FList.Free;
end;

function TAdapterActionFieldValuesList.GetCurrentFieldValuesList: TEnumActionFieldValueRecordsImpl;
begin
  if FCurrentIndex < FList.Count then
  begin
    Assert(FList[FCurrentIndex] <> nil);
    Result := FList[FCurrentIndex] as TEnumActionFieldValueRecordsImpl
  end
  else
  begin
    Assert(False);
    Result := nil;
  end;
end;

function TMultiRecordActionRequestImpl.GetFieldValuesList: TEnumActionFieldValueRecordsImpl;
begin
  Result := FAdapterActionFieldValuesList.CurrentActionFieldValuesList;
  Assert(Result <> nil);
end;

function TAdapterActionFieldValuesList.LocateActionFieldValuesOfAdapter(
  AAdapter: TComponent): Boolean;
var
  I: Integer;
  S: string;
  WebVariableName: IWebVariableName;
begin
  Result := False;
  if Supports(IInterface(AAdapter), IWebVariableName, WebVariableName) then
  begin
    S := WebVariableName.VariableName;
    for I := 0 to FList.Count - 1 do
    begin
      Assert(FList[I] <> nil);
      with FList[I] as TEnumActionFieldValueRecordsImpl do
        if SameText(AdapterName, S) then
        begin
          Result := True;
          Self.FCurrentIndex := I;
          break;
        end;
    end;
  end;
end;

end.

