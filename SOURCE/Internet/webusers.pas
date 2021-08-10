
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1999-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit WebUsers;

interface

uses Classes, HTTPApp, WebComp, SiteComp, SysUtils;

type
  TWebUserItem = class;

  TWebUserItem = class(TCollectionItem)
  private
    FUserName: string;
    FPassword: string;
    FAccessRights: string;
    FAccessRightsStrings: TStrings;
    function GetUserID: Variant;
    function GetAccessRightsStrings: TStrings;
    procedure SetAccessRights(const Value: string);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    property UserID: Variant read GetUserID;
    function CheckRights(const ARights: string): Boolean;
    property AccessRightsStrings: TStrings read GetAccessRightsStrings;
  published
    property UserName: string read FUserName write FUserName;
    property Password: string read FPassword write FPassword;
    property AccessRights: string read FAccessRights write SetAccessRights;
  end;

  TWebUserItems = class(TCollection)
  private
    FOwner: TComponent;
    function GetUserItem(Index: Integer): TWebUserItem;
    procedure SetUserItem(Index: Integer; const Value: TWebUserItem);
  protected
    function GetAttrCount: Integer; override;
    function GetAttr(Index: Integer): string; override;
    function GetItemAttr(Index, ItemIndex: Integer): string; override;
    function GetOwner: TPersistent; override;
  public
    function FindUserName(AUserName: string): TWebUserItem;
    function FindUserID(AUserID: Variant): TWebUserItem;
    constructor Create(AOwner: TComponent; ItemClass: TCollectionItemClass);
    property Items[Index: Integer]: TWebUserItem read GetUserItem
      write SetUserItem; default;
  end;

  TValidateUserError = (vuBlankPassword, vuBlankUserName, vuUnknownUserName, vuUnknownPassword);

  TCheckAccessRightsEvent = procedure(UserID: Variant; Rights: string; var HasRight: Boolean) of object;
  TCheckAccessRightsHandledEvent = procedure(UserID: Variant; Rights: string; var HasRight: Boolean; var Handled: Boolean) of object;
  TValidateUserEvent = procedure(Strings: TStrings; var UserID: Variant) of object;
  TValidateUserHandledEvent = procedure(Strings: TStrings; var UserID: Variant; var Handled: Boolean) of object;
  TValidateUserErrorEvent = procedure(Error: TValidateUserError; Strings: TStrings; var UserID: Variant; var Handled: Boolean) of object;

  TCustomWebUserList = class(TComponent, IWebUserList)
  private
    FItems: TWebUserItems;
    FLock: TMultiReadExclusiveWriteSynchronizer;
    FOnAfterCheckAccessRights: TCheckAccessRightsEvent;
    FOnBeforeCheckAccessRights: TCheckAccessRightsHandledEvent;
    FOnUserIDNotFound: TCheckAccessRightsHandledEvent;
    FOnAfterValidateUser: TValidateUserEvent;
    FOnBeforeValidateUser: TValidateUserHandledEvent;
    FOnValidateUserError: TValidateUserErrorEvent;
    procedure SetItems(const Value: TWebUserItems);
    function GetItem(I: Integer): TWebUserItem;
  protected
    { IWebUserList }
    function ValidateUser(Strings: TStrings): Variant;
    function CheckAccessRights(AUserID: Variant; ARights: string): Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure LoadFromFile(FileName: string);
    procedure SaveToFile(FileName: string);
    property UserItems: TWebUserItems read FItems write SetItems;
    property Users[I: Integer]: TWebUserItem read GetItem;
    property OnBeforeCheckAccessRights: TCheckAccessRightsHandledEvent read FOnBeforeCheckAccessRights write FOnBeforeCheckAccessRights;
    property OnAfterCheckAccessRights: TCheckAccessRightsEvent read FOnAfterCheckAccessRights write FOnAfterCheckAccessRights;
    property OnUserIDNotFound: TCheckAccessRightsHandledEvent read FOnUserIDNotFound write FOnUserIDNotFound;
    property OnBeforeValidateUser: TValidateUserHandledEvent read FOnBeforeValidateUser write FOnBeforeValidateUser;
    property OnAfterValidateUser: TValidateUserEvent read FOnAfterValidateUser write FOnAfterValidateUser;
    property OnValidateUserError: TValidateUserErrorEvent read FOnValidateUserError write FOnValidateUserError;
  end;

  TWebUserList = class(TCustomWebUserList)
  published
    property UserItems;
    property OnBeforeCheckAccessRights;
    property OnAfterCheckAccessRights;
    property OnUserIDNotFound;
    property OnBeforeValidateUser;
    property OnAfterValidateUser;
    property OnValidateUserError;
  end;

  EWebUsersListException = class(EWebBrokerException)
  end;

  EUserIDNotFoundException = class(EWebUsersListException);

  EValidateUserException = class(EWebUsersListException)
  end;

implementation

uses
  Variants, SiteConst, WebAdapt;
  
procedure TWebUserItem.Assign(Source: TPersistent);
begin
  if Source is TWebUserItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      UserName := TWebUserItem(Source).UserName;
      Password := TWebUserItem(Source).Password;
      AccessRights := TWebUserItem(Source).AccessRights;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;


{ TWebUserItems }

constructor TWebUserItems.Create(AOwner: TComponent; ItemClass: TCollectionItemClass);
begin
  FOwner := AOwner;
  inherited Create(ItemClass);
end;

function TWebUserItems.FindUserID(AUserID: Variant): TWebUserItem;
begin
  { UserID and UserName are the same }
  Result := FindUserName(AUserID);
end;

function TWebUserItems.FindUserName(AUserName: string): TWebUserItem;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Items[I] as TWebUserItem;
    if Result.UserName = AUserName then
      Exit;
  end;
  Result := nil;
end;

function RightsAsStrings(const S: string): TStrings;
begin
  Result := TStringList.Create;
  try
    ExtractStrings([',', ';', ' '], [], PChar(S), Result);
  except
    Result.Free;
    raise;
  end;
end;

// Grant access if there are no required rights or
// a user has a right that matches one of the required rights.
function TWebUserItem.CheckRights(const ARights: string): Boolean;
var
  S: TStrings;
  I: Integer;
begin
  Result := True;
  S := RightsAsStrings(ARights);
  try
    if S.Count = 0 then Exit;
    for I := 0 to S.Count - 1 do
      if AccessRightsStrings.IndexOf(S[I]) >= 0 then
        Exit;
    Result := False;
  finally
    S.Free;
  end;
end;

constructor TWebUserItem.Create(Collection: TCollection);
begin
  inherited;

end;

destructor TWebUserItem.Destroy;
begin
  inherited;
  FAccessRightsStrings.Free;
end;

function TWebUserItems.GetAttrCount: Integer;
begin
  Result := 3;
end;

function TWebUserItems.GetAttr(Index: Integer): string;
begin
  case Index of
    0: Result := sWebUserName;
    1: Result := sWebUserPassword;
    2: Result := sWebUserAccessRights;
  else
    Result := '';
  end;
end;

function TWebUserItems.GetItemAttr(Index, ItemIndex: Integer): string;
begin
  case Index of
    0: Result := Items[ItemIndex].UserName;
    1: Result := Items[ItemIndex].Password;
    2: Result := Items[ItemIndex].AccessRights;
  else
    Result := '';
  end;
end;

function TWebUserItems.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

function TWebUserItems.GetUserItem(Index: Integer): TWebUserItem;
begin
  Result := TWebUserItem(inherited Items[Index]);
end;

procedure TWebUserItems.SetUserItem(Index: Integer;
  const Value: TWebUserItem);
begin
  Items[Index].Assign(Value);
end;

{ TCustomWebUserList }

function TCustomWebUserList.CheckAccessRights(AUserID: Variant;
  ARights: string): Boolean;
var
  Item: TWebUserItem;
  Handled: Boolean;
begin
  Handled := False;
  if Assigned(OnBeforeCheckAccessRights) then
    OnBeforeCheckAccessRights(AUserID, ARights, Result, Handled);
  if not Handled then
  begin
    if ARights = '' then
      Result := True
    else if VarIsEmpty(AUserID) then
      Result := False
    else
    begin
      Item := FItems.FindUserID(AUserID);
      if Item <> nil then
        Result := Item.CheckRights(ARights)
      else
      begin
        if Assigned(OnUserIDNotFound) then
          OnUserIDNotFound(AUserID, ARights, Result, Handled);
        if not Handled then
          raise EUserIDNotFoundException.Create(sUserIDNotFound);
      end;
    end;
  end;
  if Assigned(OnAfterCheckAccessRights) then
    OnAfterCheckAccessRights(AUserID, ARights, Result);

end;

constructor TCustomWebUserList.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItems := TWebUserItems.Create(Self, TWebUserItem);
  FLock := TMultiReadExclusiveWriteSynchronizer.Create;
end;

destructor TCustomWebUserList.Destroy;
begin
  inherited;
  FLock.Free;
  FItems.Free;
end;

procedure TCustomWebUserList.LoadFromFile(FileName: string);
begin
  FLock.BeginRead;
  try
    ReadComponentResFile(FileName, Self)
  finally
    FLock.EndRead;
  end;
end;

procedure TCustomWebUserList.SaveToFile(FileName: string);
begin
  FLock.BeginWrite;
  try
    WriteComponentResFile(FileName, Self);
  finally
    FLock.EndWrite;
  end;
end;

function TCustomWebUserList.GetItem(I: Integer): TWebUserItem;
begin
  Result := FItems[I];
end;

procedure TCustomWebUserList.SetItems(const Value: TWebUserItems);
begin
  FItems.Assign(Value);
end;

function TCustomWebUserList.ValidateUser(Strings: TStrings): Variant;
var
  Item: TWebUserItem;
  Handled: Boolean;
begin
  Handled := False;
  if Assigned(OnBeforeValidateUser) then
    OnBeforeValidateUser(Strings, Result, Handled);
  if not Handled then
  begin
    if Strings.IndexOfName(sLoginUserName) >= 0 then
    begin
      Item := FItems.FindUserName(Strings.Values[sLoginUserName]);
      if Item <> nil then
      begin
        Result := Item.UserID;
        if Item.Password <> '' then
          if Strings.IndexOfName(sLoginPassword) >= 0 then
            if Strings.Values[sLoginPassword] = Item.Password then
            else
            begin
              if Assigned(OnValidateUserError) then
                OnValidateUserError(vuUnknownPassword, Strings, Result, Handled);
              if not Handled then
                raise EValidateUserException.Create(sInvalidPassword);
            end
          else
          begin
            if Assigned(OnValidateUserError) then
              OnValidateUserError(vuBlankPassword, Strings, Result, Handled);
            if not Handled then
              raise EValidateUserException.Create(sMissingPassword);
          end;
      end
      else
      begin
        if Assigned(OnValidateUserError) then
          OnValidateUserError(vuUnknownUserName, Strings, Result, Handled);
        if not Handled then
          raise EValidateUserException.Create(sUnknownUserName);
      end
    end
    else
    begin
      if Assigned(OnValidateUserError) then
        OnValidateUserError(vuBlankUserName, Strings, Result, Handled);
      if not Handled then
        raise EValidateUserException.Create(sMissingUserName);
    end;
  end;
  if Assigned(OnAfterValidateUser) then
    OnAfterValidateUser(Strings, Result);
end;

function TWebUserItem.GetAccessRightsStrings: TStrings;
begin
  if FAccessRightsStrings = nil then
    FAccessRightsStrings := RightsAsStrings(FAccessRights);
  Result := FAccessRightsStrings;
end;

function TWebUserItem.GetUserID: Variant;
begin
  Result := FUserName;
end;

procedure TWebUserItem.SetAccessRights(const Value: string);
begin
  FreeAndNil(FAccessRightsStrings);
  FAccessRights := Value;
end;

end.

