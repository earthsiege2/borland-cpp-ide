unit IdVCard;

interface

uses
  Classes,
  IdBaseComponent, IdGlobal;

type
  TIdVCardEmbeddedObject = class(TPersistent)
  protected
    FObjectType: string;
    FObjectURL: string;
    FBase64Encoded: Boolean;
    FEmbeddedData: TStrings;
    procedure SetEmbeddedData(const Value: TStrings);
  public
    constructor Create;
    destructor Destroy; override;
  published
    property ObjectType: string read FObjectType write FObjectType;
    property ObjectURL: string read FObjectURL write FObjectURL;
    property Base64Encoded: Boolean read FBase64Encoded write FBase64Encoded;
    property EmbeddedData: TStrings read FEmbeddedData write SetEmbeddedData;
  end;

  TIdVCardBusinessInfo = class(TPersistent)
  protected
    FTitle: string;
    FRole: string;
    FOrganization: string;
    FDivisions: TStrings;
    procedure SetDivisions(Value: TStrings);
  public
    constructor Create;
    destructor Destroy; override;
  published
    property Organization: string read FOrganization write FOrganization;
    property Divisions: TStrings read FDivisions write SetDivisions;
    property Title: string read FTitle write FTitle;
    property Role: string read FRole write FRole;
  end;

  TIdVCardGeog = class(TPersistent)
  protected
    FLatitude: Real;
    FLongitude: Real;
    FTimeZoneStr: string;
  published
    property Latitude: Real read FLatitude write FLatitude;
    property Longitude: Real read FLongitude write FLongitude;
    property TimeZoneStr: string read FTimeZoneStr write FTimeZoneStr;
  end;

  TIdPhoneAttributes = set of
    (tpaHome, tpaVoiceMessaging, tpaWork, tpaPreferred, tpaVoice, tpaFax,
    paCellular, tpaVideo, tpaBBS, tpaModem, tpaCar, tpaISDN, tpaPCS, tpaPager);

  TIdCardPhoneNumber = class(TCollectionItem)
  protected
    FPhoneAttributes: TIdPhoneAttributes;
    FNumber: string;
  public
    procedure Assign(Source: TPersistent); override;
  published
    property PhoneAttributes: TIdPhoneAttributes
    read FPhoneAttributes write FPhoneAttributes;
    property Number: string read FNumber write FNumber;
  end;

  TIdVCardTelephones = class(TOwnedCollection)
  protected
    function GetItem(Index: Integer): TIdCardPhoneNumber;
    procedure SetItem(Index: Integer; const Value: TIdCardPhoneNumber);
  public
    constructor Create(AOwner: TPersistent); reintroduce;
    function Add: TIdCardPhoneNumber;
    property Items[Index: Integer]: TIdCardPhoneNumber read GetItem write
    SetItem; default;
  end;

  TIdCardAddressAttributes = set of (tatHome, tatDomestic, tatInternational,
    tatPostal,
    tatParcel, tatWork, tatPreferred);
  TIdCardAddressItem = class(TCollectionItem)
  protected
    FAddressAttributes: TIdCardAddressAttributes;
    FPOBox: string;
    FExtendedAddress: string;
    FStreetAddress: string;
    FLocality: string;
    FRegion: string;
    FPostalCode: string;
    FNation: string;
  public
    procedure Assign(Source: TPersistent); override;
  published
    property AddressAttributes: TIdCardAddressAttributes read
    FAddressAttributes write FAddressAttributes;
    property POBox: string read FPOBox write FPOBox;
    property ExtendedAddress: string read FExtendedAddress write
      FExtendedAddress;
    property StreetAddress: string read FStreetAddress write FStreetAddress;
    property Locality: string read FLocality write FLocality;
    property Region: string read FRegion write FRegion;
    property PostalCode: string read FPostalCode write FPostalCode;
    property Nation: string read FNation write FNation;
  end;

  TIdVCardAddresses = class(TOwnedCollection)
  protected
    function GetItem(Index: Integer): TIdCardAddressItem;
    procedure SetItem(Index: Integer; const Value: TIdCardAddressItem);
  public
    constructor Create(AOwner: TPersistent); reintroduce;
    function Add: TIdCardAddressItem;
    property Items[Index: Integer]: TIdCardAddressItem read GetItem write
    SetItem; default;
  end;

  TIdVCardMailingLabelItem = class(TCollectionItem)
  private
    FAddressAttributes: TIdCardAddressAttributes;
    FMailingLabel: TStrings;
    procedure SetMailingLabel(Value: TStrings);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property AddressAttributes: TIdCardAddressAttributes read
    FAddressAttributes write FAddressAttributes;
    property MailingLabel: TStrings read FMailingLabel write SetMailingLabel;
  end;

  TIdVCardMailingLabels = class(TOwnedCollection)
  protected
    function GetItem(Index: Integer): TIdVCardMailingLabelItem;
    procedure SetItem(Index: Integer; const Value: TIdVCardMailingLabelItem);
  public
    constructor Create(AOwner: TPersistent); reintroduce;
    function Add: TIdVCardMailingLabelItem;
    property Items[Index: Integer]: TIdVCardMailingLabelItem read GetItem write
      SetItem; default;
  end;

  TIdVCardEMailType = (ematAOL,
    ematAppleLink,
    ematATT,
    ematCIS,
    emateWorld,
    ematInternet,
    ematIBMMail,
    ematMCIMail,
    ematPowerShare,
    ematProdigy,
    ematTelex,
    ematX400);

  TIdVCardEMailItem = class(TCollectionItem)
  protected
    FEMailType: TIdVCardEMailType;
    FPreferred: Boolean;
    FAddress: string;
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Source: TPersistent); override;
  published
    property EMailType: TIdVCardEMailType read FEMailType write FEMailType;
    property Preferred: Boolean read FPreferred write FPreferred;
    property Address: string read FAddress write FAddress;
  end;

  TIdVCardEMailAddresses = class(TOwnedCollection)
  protected
    function GetItem(Index: Integer): TIdVCardEMailItem;
    procedure SetItem(Index: Integer; const Value: TIdVCardEMailItem);
  public
    constructor Create(AOwner: TPersistent); reintroduce;
    function Add: TIdVCardEMailItem;
    property Items[Index: Integer]: TIdVCardEMailItem read GetItem write
      SetItem; default;
  end;

  TIdVCardName = class(TPersistent)
  protected
    FFirstName: string;
    FSurName: string;
    FOtherNames: TStrings;
    FPrefix: string;
    FSuffix: string;
    FFormattedName: string;
    FSortName: string;
    FNickNames: TStrings;
    procedure SetOtherNames(Value: TStrings);
    procedure SetNickNames(Value: TStrings);
  public
    constructor Create;
    destructor Destroy; override;
  published
    property FirstName: string read FFirstName write FFirstName;
    property SurName: string read FSurName write FSurName;
    property OtherNames: TStrings read FOtherNames write SetOtherNames;
    property FormattedName: string read FFormattedName write FFormattedName;
    property Prefix: string read FPrefix write FPrefix;
    property Suffix: string read FSuffix write FSuffix;
    property SortName: string read FSortName write FSortName;
    property NickNames: TStrings read FNickNames write SetNickNames;
  end;

  TIdVCard = class(TIdBaseComponent)
  private
  protected
    FComments: TStrings;
    FCatagories: TStrings;
    FBusinessInfo: TIdVCardBusinessInfo;
    FGeography: TIdVCardGeog;
    FFullName: TIdVCardName;
    FRawForm: TStrings;
    FURLs: TStrings;
    FEMailProgram: string;
    FEMailAddresses: TIdVCardEMailAddresses;
    FAddresses: TIdVCardAddresses;
    FMailingLabels: TIdVCardMailingLabels;
    FTelephones: TIdVCardTelephones;
    FVCardVersion: Real;
    FProductID: string;
    FUniqueID: string;
    FClassification: string;
    FLastRevised: TDateTime;
    FBirthDay: TDateTime;
    FPhoto: TIdVCardEmbeddedObject;
    FLogo: TIdVCardEmbeddedObject;
    FSound: TIdVCardEmbeddedObject;
    FKey: TIdVCardEmbeddedObject;
    procedure SetComments(Value: TStrings);
    procedure SetCatagories(Value: TStrings);
    procedure SetURLs(Value: TStrings);
    procedure SetVariablesAfterRead;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure ReadFromTStrings(s: TStrings);
    property RawForm: TStrings read FRawForm;
  published
    property VCardVersion: Real read FVCardVersion;
    property URLs: TStrings read FURLs write SetURLs;
    property ProductID: string read FProductID write FProductID;
    property UniqueID: string read FUniqueID write FUniqueID;
    property Classification: string read FClassification write FClassification;
    property BirthDay: TDateTime read FBirthDay write FBirthDay;
    property FullName: TIdVCardName read FFullName write FFullName;
    property EMailProgram: string read FEMailProgram write FEMailProgram;
    property EMailAddresses: TIdVCardEMailAddresses read FEMailAddresses;
    property Telephones: TIdVCardTelephones read FTelephones;
    property BusinessInfo: TIdVCardBusinessInfo read FBusinessInfo;
    property Catagories: TStrings read FCatagories write SetCatagories;
    property Addresses: TIdVCardAddresses read FAddresses;
    property MailingLabels: TIdVCardMailingLabels read FMailingLabels;
    property Comments: TStrings read FComments write SetComments;
    property Photo: TIdVCardEmbeddedObject read FPhoto;
    property Logo: TIdVCardEmbeddedObject read FLogo;
    property Sound: TIdVCardEmbeddedObject read FSound;
    property Key: TIdVCardEmbeddedObject read FKey;
  end;

implementation

uses
  IdCoderText,
  SysUtils;

const
  VCardProperties: array[1..28] of string = (
    'FN', 'N', 'NICKNAME', 'PHOTO',
    'BDAY', 'ADR', 'LABEL', 'TEL',
    'EMAIL', 'MAILER', 'TZ', 'GEO',
    'TITLE', 'ROLE', 'LOGO', 'AGENT',
    'ORG', 'CATEGORIES', 'NOTE', 'PRODID',
    'REV', 'SORT-STRING', 'SOUND', 'URL',
    'UID', 'VERSION', 'CLASS', 'KEY');
{ These constants are for testing the VCard for E-Mail types.
  Don't alter these }
const
  EMailTypePropertyParameter: array[1..12] of string =
  ('AOL',
    'APPLELINK',
    'ATTMAIL',
    'CIS',
    'EWORLD',
    'INTERNET',
    'IBMMAIL',
    'MCIMAIL',
    'POWERSHARE',
    'PRODIGY',
    'TLX',
    'X400');

procedure AddValueToStrings(strs: TStrings; Value: string);
begin
  if (Length(Value) <> 0) then
  begin
    strs.Add(Value);
  end;
end;

procedure ParseDelinatorToTStrings(strs: TStrings; str: string;
  deliniator: Char = ',');
begin
  while (str <> '') do
  begin
    AddValueToStrings(strs, Fetch(str, deliniator));
  end;
end;

function ParseDateTimeStamp(DateString: string): TDateTime;
var
  Year, Day, Month: Integer;
  Hour, Minute, Second: Integer;
begin
  Year := StrToInt(Copy(DateString, 1, 4));
  Month := StrToInt(Copy(DateString, 5, 2));
  Day := StrToInt(Copy(DateString, 7, 2));
  if (Length(DateString) > 14) then
  begin
    Hour := StrToInt(Copy(DateString, 10, 2));
    Minute := StrToInt(Copy(DateString, 12, 2));
    Second := StrToInt(Copy(DateString, 14, 2));
  end
  else
  begin
    Hour := 0;
    Minute := 0;
    Second := 0;
  end;
  Result := EncodeDate(Year, Month, Day) + EncodeTime(Hour, Minute, Second, 0);
end;

function GetAttributesAndValue(data: string; var value: string): TStringList;
var
  Buff, Buff2: string;
begin
  Result := TStringList.Create;
  Result.Sorted := False;
  if Pos(':', Data) <> 0 then
  begin
    Buff := idGlobal.Fetch(Data, ':');
    StringReplace(Buff, ',', ';', [rfReplaceAll]);
    while (Buff <> '') do
    begin
      Buff2 := IdGlobal.Fetch(Buff, ';');
      if (Length(Buff2) > 0) then
      begin
        Result.Add(UpperCase(Buff2));
      end;
    end;
  end;
  Value := Data;
end;

procedure ParseOrg(OrgObj: TIdVCardBusinessInfo; OrgStr: string);
begin
  OrgObj.Organization := Fetch(OrgStr);
  ParseDelinatorToTStrings(OrgObj.Divisions, OrgStr, ';');
end;

procedure ParseGeography(Geog: TIdVCardGeog; GeogStr: string);
begin
  Geog.Latitude := StrToFloat(Fetch(GeogStr, ';'));
  Geog.Longitude := StrToFloat(Fetch(GeogStr, ';'));
end;

procedure ParseTelephone(PhoneObj: TIdCardPhoneNumber; PhoneStr: string);
var
  Value: string;
  idx: Integer;
  Attribs: TStringList;

const
  TelephoneTypePropertyParameter: array[0..13] of string =
  ('HOME', 'MSG', 'WORK', 'PREF', 'VOICE', 'FAX',
    'CELL', 'VIDEO', 'BBS', 'MODEM', 'CAR', 'ISDN',
    'PCS', 'PAGER');
begin
  attribs := GetAttributesAndValue(PhoneStr, Value);
  try
    idx := 0;
    while idx < Attribs.Count do
    begin
      case idGlobal.PosInStrArray(attribs[idx], TelephoneTypePropertyParameter)
        of
        0: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaHome];
        1: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes +
          [tpaVoiceMessaging];
        2: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaWork];
        3: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes +
          [tpaPreferred];
        4: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaVoice];
        5: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaFax];
        6: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [paCellular];
        7: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaVideo];
        8: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaBBS];
        9: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaModem];
        10: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaCar];
        11: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaISDN];
        12: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaPCS];
        13: PhoneObj.PhoneAttributes := PhoneObj.PhoneAttributes + [tpaPager];
      end;
      inc(idx);
    end;
    if (Attribs.Count = 0) then
    begin
      PhoneObj.PhoneAttributes := [tpaVoice];
    end;
    PhoneObj.Number := Value;
  finally
    FreeAndNil(attribs);
  end;
end;

procedure ParseAddress(AddressObj: TIdCardAddressItem; AddressStr: string);
var
  Value: string;
  Attribs: TStringList;
  idx: Integer;
const
  AttribsArray: array[0..6] of string =
  ('HOME', 'DOM', 'INTL', 'POSTAL', 'PARCEL', 'WORK', 'PREF');
begin
  Attribs := GetAttributesAndValue(AddressStr, Value);
  try
    idx := 0;
    while idx < Attribs.Count do
    begin
      case idGlobal.PosInStrArray(attribs[idx], AttribsArray) of
        0:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatHome];
        1:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatDomestic];
        2:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatInternational];
        3:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatPostal];
        4:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatParcel];
        5:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatWork];
        6:
          AddressObj.AddressAttributes :=
            AddressObj.AddressAttributes + [tatPreferred];
      end;
      inc(idx);
    end;
    if (Attribs.Count = 0) then
    begin
      AddressObj.AddressAttributes := [tatInternational, tatPostal, tatParcel,
        tatWork];
    end;
    AddressObj.POBox := idGlobal.Fetch(Value, ';');
    AddressObj.ExtendedAddress := idGlobal.Fetch(Value, ';');
    AddressObj.StreetAddress := idGlobal.Fetch(Value, ';');
    AddressObj.Locality := idGlobal.Fetch(Value, ';');
    AddressObj.Region := idGlobal.Fetch(Value, ';');
    AddressObj.PostalCode := idGlobal.Fetch(Value, ';');
    AddressObj.Nation := idGlobal.Fetch(Value, ';');
  finally
    FreeAndNil(Attribs);
  end;
end;

procedure ParseMailingLabel(LabelObj: TIdVCardMailingLabelItem; LabelStr:
  string);
var
  Value: string;
  Attribs: TStringList;
  idx: Integer;
const
  AttribsArray: array[0..6] of string =
  ('HOME', 'DOM', 'INTL', 'POSTAL', 'PARCEL', 'WORK', 'PREF');
begin
  Attribs := GetAttributesAndValue(LabelStr, Value);
  try
    idx := 0;
    while idx < Attribs.Count do
    begin
      case idGlobal.PosInStrArray(attribs[idx], AttribsArray) of
        0:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatHome];
        1:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatDomestic];
        2:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatInternational];
        3:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatPostal];
        4:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatParcel];
        5:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatWork];
        6:
          LabelObj.AddressAttributes :=
            LabelObj.AddressAttributes + [tatPreferred];
      end;
      inc(idx);
    end;
    if Attribs.Count = 0 then
    begin
      LabelObj.AddressAttributes := [tatInternational, tatPostal, tatParcel,
        tatWork];
    end;
    LabelObj.MailingLabel.Add(Value);
  finally
    FreeAndNil(Attribs);
  end;
end;

procedure ParseName(NameObj: TIdVCardName; NameStr: string);
var
  OtherNames: string;

begin
  NameObj.SurName := Fetch(NameStr, ';');
  NameObj.FirstName := Fetch(NameStr, ';');
  OtherNames := Fetch(NameStr, ';');
  NameObj.Prefix := Fetch(NameStr, ';');
  NameObj.Suffix := Fetch(NameStr, ';');
  OtherNames := StringReplace(OtherNames, ' ', ',', [rfReplaceAll]);
  ParseDelinatorToTStrings(NameObj.OtherNames, OtherNames);
end;

procedure ParseEMailAddress(EMailObj: TIdVCardEMailItem; EMailStr: string);
var
  Value: string;
  Attribs: TStringList;
  idx: Integer;
  ps: Integer;
begin
  Attribs := GetAttributesAndValue(EMailStr, Value);
  try
    EMailObj.Address := Value;
    EMailObj.Preferred := (attribs.IndexOf('PREF') <> -1);
    idx := 0;
    ps := -1;
    while (idx < Attribs.Count) and (ps = -1) do
    begin
      ps := PosInStrArray(Attribs[idx], EMailTypePropertyParameter);
      case ps of
        0: EMailObj.EMailType := ematAOL;
        1: EMailObj.EMailType := ematAppleLink;
        2: EMailObj.EMailType := ematATT;
        3: EMailObj.EMailType := ematCIS;
        4: EMailObj.EMailType := emateWorld;
        5: EMailObj.EMailType := ematInternet;
        6: EMailObj.EMailType := ematIBMMail;
        7: EMailObj.EMailType := ematMCIMail;
        8: EMailObj.EMailType := ematPowerShare;
        9: EMailObj.EMailType := ematProdigy;
        10: EMailObj.EMailType := ematTelex;
        11: EMailObj.EMailType := ematX400;
      end;
      inc(idx);
    end;
  finally
    FreeAndNil(Attribs);
  end;
end;

constructor TIdVCard.Create(AOwner: TComponent);
begin
  inherited;
  FPhoto := TIdVCardEmbeddedObject.Create;
  FLogo := TIdVCardEmbeddedObject.Create;
  FSound := TIdVCardEmbeddedObject.Create;
  FKey := TIdVCardEmbeddedObject.Create;
  FComments := TStringList.Create;
  FCatagories := TStringList.Create;
  FBusinessInfo := TIdVCardBusinessInfo.Create;
  FGeography := TIdVCardGeog.Create;
  FFullName := TIdVCardName.Create;
  FRawForm := TStringList.Create;
  FEMailAddresses := TIdVCardEMailAddresses.Create(Self);
  FAddresses := TIdVCardAddresses.Create(Self);
  FTelephones := TIdVCardTelephones.Create(Self);
  FURLs := TStringList.Create;
  FMailingLabels := TIdVCardMailingLabels.Create(Self);
end;

destructor TIdVCard.Destroy;
begin
  FreeAndNil(FKey);
  FreeAndNil(FPhoto);
  FreeAndNil(FLogo);
  FreeAndNil(FSound);
  FreeAndNil(FComments);
  FreeAndNil(FMailingLabels);
  FreeAndNil(FCatagories);
  FreeAndNil(FBusinessInfo);
  FreeAndNil(FGeography);
  FreeAndNil(FURLs);
  FreeAndNil(FTelephones);
  FreeAndNil(FAddresses);
  FreeAndNil(FEMailAddresses);
  FreeAndNil(FFullName);
  FreeAndNil(FRawForm);
  inherited;
end;

procedure TIdVCard.ReadFromTStrings(s: TStrings);
var
  idx, embedded: Integer;
begin
  FRawForm.Clear;
  idx := 0;
  embedded := 0;
  while (idx < s.Count) and
    (Trim(UpperCase(s[idx])) <> 'BEGIN:VCARD') do
  begin
    Inc(idx);
  end;
  while (idx < s.Count) do
  begin
    if Length(s[idx]) > 0 then
    begin
      if UpperCase(Trim(s[idx])) <> 'END:VCARD' then
      begin
        if embedded <> 0 then
        begin
          Dec(embedded);
        end;
      end
      else
        if UpperCase(Trim(s[idx])) <> 'BEGIN:VCARD' then
      begin
        Inc(embedded);
      end;
      FRawForm.Add(s[idx]);
    end;
    Inc(idx);
  end;
  if (idx < s.Count) and (Length(s[idx]) > 0) then
    FRawForm.Add(s[idx]);
  SetVariablesAfterRead;
end;

procedure TIdVCard.SetCatagories(Value: TStrings);
begin
  FCatagories.Assign(Value);
end;

procedure TIdVCard.SetComments(Value: TStrings);
begin
  FComments.Assign(Value);
end;

procedure TIdVCard.SetURLs(Value: TStrings);
begin
  FURLs.Assign(Value);
end;

procedure TIdVCard.SetVariablesAfterRead;
var
  idx: Integer;
  OrigLine: string;
  Line: string;
  Attribs: string;
  Data: string;
  Test: string;
  Colon: Integer;
  SColon: Integer;
  ColonFind: Integer;
  QPCoder: TIdQuotedPrintableDecoder;

  function UnfoldLines: string;
  begin
    Result := '';
    Inc(idx);
    while (idx < FRawForm.Count) and ((Length(FRawForm[idx]) > 0) and
      (FRawForm[idx][1] = ' ') or (FRawForm[idx][1] = #9)) do
    begin
      Result := Result + Trim(FRawForm[idx]);
      inc(idx);
    end;
    Dec(idx);
  end;

  procedure ProcessAgent;
  begin
  end;

  procedure ParseEmbeddedObject(EmObj: TIdVCardEmbeddedObject; StLn: string);
  var
    Value: string;
    Attribs: TStringList;
    idx2: Integer;
  begin
    attribs := GetAttributesAndValue(StLn, Value);
    try
      idx2 := 0;
      while (idx2 < attribs.Count) do
      begin
        if ((Attribs[idx2] = 'ENCODING=BASE64') or
          (Attribs[idx2] = 'BASE64')) then
        begin
          emObj.Base64Encoded := True;
        end
        else
        begin
          if not ((Attribs[idx2] = 'VALUE=URI') or
            (Attribs[idx2] = 'VALUE=URL') or
            (Attribs[idx2] = 'URI') or
            (Attribs[idx2] = 'URL')) then
          begin
            emObj.ObjectType := Attribs[idx2];
          end;
        end;
        Inc(idx2);
      end;
      if (Attribs.IndexOf('VALUE=URI') > -1) or
        (Attribs.IndexOf('VALUE=URL') > -1) or
        (Attribs.IndexOf('URI') > -1) or
        (Attribs.IndexOf('URL') > -1) then
      begin
        emObj.ObjectURL := Value + UnfoldLines;
      end
      else
      begin
        AddValueToStrings(EmObj.EmbeddedData, Value);
        Inc(idx);
        while (idx < FRawForm.Count) and ((Length(FRawForm[idx]) > 0) and
          (FRawForm[idx][1] = ' ') or (FRawForm[idx][1] = #9)) do
        begin
          AddValueToStrings(EmObj.EmbeddedData, Trim(FRawForm[idx2]));
          inc(idx);
        end;
        Dec(idx);
      end;
    finally
      FreeAndNil(Attribs);
    end;
  end;

begin

  QPCoder := TIdQuotedPrintableDecoder.Create(Self);
  try

    QPCoder.AddCRLF := False;
    QPCoder.UseEvent := False;
    QPCoder.IgnoreNotification := True;

    idx := 0;
    while idx < FRawForm.Count do
    begin
      Line := FRawForm[idx];
      Colon := Pos(':', Line);
      Attribs := Copy(Line, 1, Colon - 1);
      if Pos('QUOTED-PRINTABLE', UpperCase(Attribs)) > 0 then
      begin
        OrigLine := Line;
        Data := Copy(Line, Colon + 1, Length(Line));
        Inc(idx);
        ColonFind := Pos(':', FRawForm[idx]);
        while ColonFind = 0 do
        begin
          Data := Data + CR + LF + TrimLeft(FRawForm[idx]);
          Inc(idx);
          if idx <> FRawForm.Count then
          begin
            ColonFind := Pos(':', FRawForm[idx]);
          end
          else
            ColonFind := 1;

        end;
        Dec(idx);
        Test := QPCoder.CodeString(Data);
        Data := '';
        while Test <> '' do
        begin
          Fetch(Test, ';');
          Data := Data + Test;
          Test := QPCoder.GetCodedData;
        end;
        Test := QPCoder.CompletedInput;
        while Test <> '' do
        begin
          Fetch(Test, ';');
          Data := Data + Test;

          Test := QPCoder.GetCodedData;
        end;
        QPCoder.Reset;

        ColonFind := Pos(';', Attribs);
        Line := '';
        while ColonFind <> 0 do
        begin
          Test := Copy(Attribs, 1, ColonFind);
          if Pos('QUOTED-PRINTABLE', Test) = 0 then
          begin
            Line := Line + Test;
          end;
          Attribs := Copy(Attribs, ColonFind + 1, Length(Attribs));

          ColonFind := Pos(';', Attribs);
        end;

        if Length(Attribs) <> 0 then
        begin
          if Pos('QUOTED-PRINTABLE', Attribs) = 0 then
          begin
            Line := Line + Attribs;
          end;
        end;
        ColonFind := Length(Line);
        if ColonFind > 0 then
        begin
          if Line[ColonFind] = ';' then
          begin
            Line := Copy(Line, 1, ColonFind - 1);
          end;
        end;
        Line := Line + ':' + Data;
      end;
      Colon := Pos(':', Line);
      SColon := Pos(';', Line);
      if (Colon < SColon) or (SColon = 0) then
      begin
        Line := StringReplace(Line, ':', ';', []);
      end;

      Test := UpperCase(Fetch(Line, ';'));

      case PosInStrArray(Test, VCardProperties) of
        0: FFullName.FormattedName := Line + UnfoldLines;
        1: ParseName(FFullName, Line + UnfoldLines);
        2: ParseDelinatorToTStrings(FFullName.NickNames, Line + UnfoldLines);
        3: ParseEmbeddedObject(FPhoto, Line);
        4: FBirthDay := ParseDateTimeStamp(Line + UnfoldLines);
        5: ParseAddress(FAddresses.Add, Line + UnfoldLines);
        6: ParseMailingLabel(FMailingLabels.Add, Line + UnfoldLines);
        7: ParseTelephone(FTelephones.Add, Line + UnfoldLines);
        8: ParseEMailAddress(FEMailAddresses.Add, Line + UnfoldLines);
        9: FEMailProgram := Line + UnfoldLines;
        10: FGeography.TimeZoneStr := Line + UnfoldLines;
        11: ParseGeography(FGeography, Line + UnfoldLines);
        12: FBusinessInfo.Title := Line + UnfoldLines;
        13: FBusinessInfo.Role := Line + UnfoldLines;
        14: ParseEmbeddedObject(FLogo, Line);
        15: ProcessAgent;
        16: ParseOrg(FBusinessInfo, Line + UnfoldLines);
        17: ParseDelinatorToTStrings(FCatagories, Line + UnfoldLines);
        18: FComments.Add(Line + UnfoldLines);
        19: FProductID := Line + UnfoldLines;
        20: FLastRevised := ParseDateTimeStamp(Line + UnfoldLines);
        21: FFullName.SortName := Line + UnfoldLines;
        22: ParseEmbeddedObject(FSound, Line);
        23: AddValueToStrings(FURLs, Line + UnfoldLines);
        24: FUniqueID := Line + UnfoldLines;
        25: FVCardVersion := StrToFloat(Line + UnfoldLines);
        26: FClassification := Line + UnfoldLines;
        27: ParseEmbeddedObject(FKey, Line);
      end;
      inc(idx);
    end;

  finally
    QPCoder.Free;
  end;
end;

function TIdVCardEMailAddresses.Add: TIdVCardEMailItem;
begin
  Result := TIdVCardEMailItem(inherited Add);
end;

constructor TIdVCardEMailAddresses.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner, TIdVCardEMailItem);
end;

function TIdVCardEMailAddresses.GetItem(Index: Integer): TIdVCardEMailItem;
begin
  Result := TIdVCardEMailItem(inherited Items[Index]);
end;

procedure TIdVCardEMailAddresses.SetItem(Index: Integer;
  const Value: TIdVCardEMailItem);
begin
  inherited SetItem(Index, Value);
end;

procedure TIdVCardEMailItem.Assign(Source: TPersistent);
var
  EMail: TIdVCardEMailItem;
begin
  if ClassType <> Source.ClassType then
  begin
    inherited
  end
  else
  begin
    EMail := TIdVCardEMailItem(Source);
    EMailType := EMail.EMailType;
    Preferred := EMail.Preferred;
    Address := EMail.Address;
  end;
end;

constructor TIdVCardEMailItem.Create(Collection: TCollection);
begin
  inherited;
  FEMailType := ematInternet;
end;

function TIdVCardAddresses.Add: TIdCardAddressItem;
begin
  Result := TIdCardAddressItem(inherited Add);
end;

constructor TIdVCardAddresses.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner, TIdCardAddressItem);
end;

function TIdVCardAddresses.GetItem(Index: Integer): TIdCardAddressItem;
begin
  Result := TIdCardAddressItem(inherited Items[Index]);
end;

procedure TIdVCardAddresses.SetItem(Index: Integer;
  const Value: TIdCardAddressItem);
begin
  inherited SetItem(Index, Value);
end;

function TIdVCardTelephones.Add: TIdCardPhoneNumber;
begin
  Result := TIdCardPhoneNumber(inherited Add);
end;

constructor TIdVCardTelephones.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner, TIdCardPhoneNumber);
end;

function TIdVCardTelephones.GetItem(Index: Integer): TIdCardPhoneNumber;
begin
  Result := TIdCardPhoneNumber(inherited Items[Index]);
end;

procedure TIdVCardTelephones.SetItem(Index: Integer;
  const Value: TIdCardPhoneNumber);
begin
  inherited SetItem(Index, Value);
end;

constructor TIdVCardName.Create;
begin
  inherited;
  FOtherNames := TStringList.Create;
  FNickNames := TStringList.Create;
end;

destructor TIdVCardName.Destroy;
begin
  FreeAndNil(FNickNames);
  FreeAndNil(FOtherNames);
  inherited;
end;

procedure TIdVCardName.SetNickNames(Value: TStrings);
begin
  FNickNames.Assign(Value);
end;

procedure TIdVCardName.SetOtherNames(Value: TStrings);
begin
  FOtherNames.Assign(Value);
end;

constructor TIdVCardBusinessInfo.Create;
begin
  inherited;
  FDivisions := TStringList.Create;
end;

destructor TIdVCardBusinessInfo.Destroy;
begin
  FreeAndNil(FDivisions);
  inherited;
end;

procedure TIdVCardBusinessInfo.SetDivisions(Value: TStrings);
begin
  FDivisions.Assign(Value);
end;

procedure TIdVCardMailingLabelItem.Assign(Source: TPersistent);
var
  lbl: TIdVCardMailingLabelItem;
begin
  if ClassType <> Source.ClassType then
  begin
    inherited
  end
  else
  begin
    lbl := TIdVCardMailingLabelItem(Source);
    AddressAttributes := lbl.AddressAttributes;
    MailingLabel.Assign(lbl.MailingLabel);
  end;
end;

constructor TIdVCardMailingLabelItem.Create(Collection: TCollection);
begin
  inherited;
  FMailingLabel := TStringList.Create;
end;

destructor TIdVCardMailingLabelItem.Destroy;
begin
  FreeAndNil(FMailingLabel);
  inherited;
end;

procedure TIdVCardMailingLabelItem.SetMailingLabel(Value: TStrings);
begin
  FMailingLabel.Assign(Value);
end;

function TIdVCardMailingLabels.Add: TIdVCardMailingLabelItem;
begin
  Result := TIdVCardMailingLabelItem(inherited Add);
end;

constructor TIdVCardMailingLabels.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner, TIdVCardMailingLabelItem);
end;

function TIdVCardMailingLabels.GetItem(
  Index: Integer): TIdVCardMailingLabelItem;
begin
  Result := TIdVCardMailingLabelItem(inherited GetItem(Index));
end;

procedure TIdVCardMailingLabels.SetItem(Index: Integer;
  const Value: TIdVCardMailingLabelItem);
begin
  inherited SetItem(Index, Value);
end;

constructor TIdVCardEmbeddedObject.Create;
begin
  inherited;
  FEmbeddedData := TStringList.Create;
end;

destructor TIdVCardEmbeddedObject.Destroy;
begin
  FreeAndNil(FEmbeddedData);
  inherited;
end;

procedure TIdVCardEmbeddedObject.SetEmbeddedData(const Value: TStrings);
begin
  FEmbeddedData.Assign(Value);
end;

procedure TIdCardPhoneNumber.Assign(Source: TPersistent);
var
  Phone: TIdCardPhoneNumber;
begin
  if ClassType <> Source.ClassType then
  begin
    inherited;
  end
  else
  begin
    Phone := TIdCardPhoneNumber(Source);
    PhoneAttributes := Phone.PhoneAttributes;
    Number := Phone.Number;
  end;
end;

procedure TIdCardAddressItem.Assign(Source: TPersistent);
var
  Addr: TIdCardAddressItem;
begin
  if ClassType <> Source.ClassType then
  begin
    inherited;
  end
  else
  begin
    Addr := TIdCardAddressItem(Source);
    AddressAttributes := Addr.AddressAttributes;
    POBox := Addr.POBox;
    ExtendedAddress := Addr.ExtendedAddress;
    StreetAddress := Addr.StreetAddress;
    Locality := Addr.Locality;
    Region := Addr.Region;
    PostalCode := Addr.PostalCode;
    Nation := Addr.Nation;
  end;
end;

end.
