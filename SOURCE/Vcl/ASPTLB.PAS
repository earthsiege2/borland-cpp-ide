{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Asptlb;

interface

uses
  ActiveX, ComObj, Mtx;

type
  IStringList = interface(IDispatch)
    ['{D97A6DA0-A85D-11CF-83AE-00A0C90C2BD8}']
    function Get_Item(i: OleVariant): OleVariant; safecall;
    function Get_Count: SYSINT; safecall;
    function Get__NewEnum: IUnknown; safecall;
    property Item[i: OleVariant]: OleVariant read Get_Item; default;
    property Count: SYSINT read Get_Count;
    property _NewEnum: IUnknown read Get__NewEnum;
  end;
  {$EXTERNALSYM IStringList}

  IRequestDictionary = interface(IDispatch)
    ['{D97A6DA0-A85F-11DF-83AE-00A0C90C2BD8}']
    function Get_Item(Var_: OleVariant): OleVariant; safecall;
    function Get__NewEnum: IUnknown; safecall;
    function Get_Count: SYSINT; safecall;
    function Get_Key(VarKey: OleVariant): OleVariant; safecall;
    property Item[Var_: OleVariant]: OleVariant read Get_Item; default;
    property _NewEnum: IUnknown read Get__NewEnum;
    property Count: SYSINT read Get_Count;
    property Key[VarKey: OleVariant]: OleVariant read Get_Key;
  end;
  {$EXTERNALSYM IRequestDictionary}

  IRequest = interface(IDispatch)
    ['{D97A6DA0-A861-11CF-93AE-00A0C90C2BD8}']
    function Get_Item(const bstrVar: WideString): IDispatch; safecall;
    function Get_QueryString: IRequestDictionary; safecall;
    function Get_Form: IRequestDictionary; safecall;
    function Get_Body: IRequestDictionary; safecall;
    function Get_ServerVariables: IRequestDictionary; safecall;
    function Get_ClientCertificate: IRequestDictionary; safecall;
    function Get_Cookies: IRequestDictionary; safecall;
    function Get_TotalBytes: Integer; safecall;
    function BinaryRead(var pvarCountToRead: OleVariant): OleVariant; safecall;
    property Item[const bstrVar: WideString]: IDispatch read Get_Item; default;
    property QueryString: IRequestDictionary read Get_QueryString;
    property Form: IRequestDictionary read Get_Form;
    property Body: IRequestDictionary read Get_Body;
    property ServerVariables: IRequestDictionary read Get_ServerVariables;
    property ClientCertificate: IRequestDictionary read Get_ClientCertificate;
    property Cookies: IRequestDictionary read Get_Cookies;
    property TotalBytes: Integer read Get_TotalBytes;
  end;
  {$EXTERNALSYM IRequest}

  IReadCookie = interface(IDispatch)
    ['{71EAF260-0CE0-11D0-A53E-00A0C90C2091}']
    function Get_Item(Var_: OleVariant): OleVariant; safecall;
    function Get_HasKeys: WordBool; safecall;
    function Get__NewEnum: IUnknown; safecall;
    function Get_Count: SYSINT; safecall;
    function Get_Key(VarKey: OleVariant): OleVariant; safecall;
    property Item[Var_: OleVariant]: OleVariant read Get_Item; default;
    property HasKeys: WordBool read Get_HasKeys;
    property _NewEnum: IUnknown read Get__NewEnum;
    property Count: SYSINT read Get_Count;
    property Key[VarKey: OleVariant]: OleVariant read Get_Key;
  end;
  {$EXTERNALSYM IReadCookie}

  IWriteCookie = interface(IDispatch)
    ['{D97A6DA0-A862-11CF-84AE-00A0C90C2BD8}']
    procedure Set_Item(Key: OleVariant; const Param2: WideString); safecall;
    procedure Set_Expires(Param1: TDateTime); safecall;
    procedure Set_Domain(const Param1: WideString); safecall;
    procedure Set_Path(const Param1: WideString); safecall;
    procedure Set_Secure(Param1: WordBool); safecall;
    function Get_HasKeys: WordBool; safecall;
    function Get__NewEnum: IUnknown; safecall;
    property Item[Key: OleVariant]: WideString write Set_Item; default;
    property Expires: TDateTime write Set_Expires;
    property Domain: WideString write Set_Domain;
    property Path: WideString write Set_Path;
    property Secure: WordBool write Set_Secure;
    property HasKeys: WordBool read Get_HasKeys;
    property _NewEnum: IUnknown read Get__NewEnum;
  end;
  {$EXTERNALSYM IWriteCookie}

  IResponse = interface(IDispatch)
    ['{D97A6DA0-A864-11CF-83BE-00A0C90C2BD8}']
    function Get_Buffer: WordBool; safecall;
    procedure Set_Buffer(fIsBuffering: WordBool); safecall;
    function Get_ContentType: WideString; safecall;
    procedure Set_ContentType(const pbstrContentTypeRet: WideString); safecall;
    function Get_Expires: OleVariant; safecall;
    procedure Set_Expires(pvarExpiresMinutesRet: Integer); safecall;
    function Get_ExpiresAbsolute: OleVariant; safecall;
    procedure Set_ExpiresAbsolute(pvarExpiresRet: TDateTime); safecall;
    function Get_Cookies: IRequestDictionary; safecall;
    function Get_Status: WideString; safecall;
    procedure Set_Status(const pbstrStatusRet: WideString); safecall;
    procedure Add(const bstrHeaderValue: WideString; const bstrHeaderName: WideString); safecall;
    procedure AddHeader(const bstrHeaderName: WideString; const bstrHeaderValue: WideString); safecall;
    procedure AppendToLog(const bstrLogEntry: WideString); safecall;
    procedure BinaryWrite(varInput: OleVariant); safecall;
    procedure Clear; safecall;
    procedure End_; safecall;
    procedure Flush; safecall;
    procedure Redirect(const bstrURL: WideString); safecall;
    procedure Write(varText: OleVariant); safecall;
    procedure WriteBlock(iBlockNumber: Smallint); safecall;
    function IsClientConnected: WordBool; safecall;
    function Get_CharSet: WideString; safecall;
    procedure Set_CharSet(const pbstrCharSetRet: WideString); safecall;
    procedure Pics(const bstrHeaderValue: WideString); safecall;
    function Get_CacheControl: WideString; safecall;
    procedure Set_CacheControl(const pbstrCacheControl: WideString); safecall;
    property Buffer: WordBool read Get_Buffer write Set_Buffer;
    property ContentType: WideString read Get_ContentType write Set_ContentType;
    property Cookies: IRequestDictionary read Get_Cookies;
    property Status: WideString read Get_Status write Set_Status;
    property CharSet: WideString read Get_CharSet write Set_CharSet;
    property CacheControl: WideString read Get_CacheControl write Set_CacheControl;
  end;
  {$EXTERNALSYM IResponse}

  IVariantDictionary = interface(IDispatch)
    ['{4A7DEB90-B069-11D0-B373-00A0C90C2BD8}']
    function Get_Item(VarKey: OleVariant): OleVariant; safecall;
    procedure _Set_Item(VarKey: OleVariant; pvar: OleVariant); safecall;
    procedure Set_Item(VarKey: OleVariant; pvar: OleVariant); safecall;
    function Get_Key(VarKey: OleVariant): OleVariant; safecall;
    function Get_Count: SYSINT; safecall;
    function Get__NewEnum: IUnknown; safecall;
    property Item[VarKey: OleVariant]: OleVariant read Get_Item write _Set_Item; default;
    property Key[VarKey: OleVariant]: OleVariant read Get_Key;
    property Count: SYSINT read Get_Count;
    property _NewEnum: IUnknown read Get__NewEnum;
  end;
  {$EXTERNALSYM IVariantDictionary}

  ISessionObject = interface(IDispatch)
    ['{D97A6DA0-A865-11CF-83AF-00A0C90C2BD8}']
    function Get_SessionID: WideString; safecall;
    function Get_Value(const bstrValue: WideString): OleVariant; safecall;
    procedure _Set_Value(const bstrValue: WideString; pvar: OleVariant); safecall;
    procedure Set_Value(const bstrValue: WideString; pvar: OleVariant); safecall;
    function Get_Timeout: Integer; safecall;
    procedure Set_Timeout(plvar: Integer); safecall;
    procedure Abandon; safecall;
    function Get_CodePage: Integer; safecall;
    procedure Set_CodePage(plvar: Integer); safecall;
    function Get_LCID: Integer; safecall;
    procedure Set_LCID(plvar: Integer); safecall;
    function Get_StaticObjects: IVariantDictionary; safecall;
    function Get_Contents: IVariantDictionary; safecall;
    property SessionID: WideString read Get_SessionID;
    property Value[const bstrValue: WideString]: OleVariant read Get_Value write _Set_Value; default;
    property Timeout: Integer read Get_Timeout write Set_Timeout;
    property CodePage: Integer read Get_CodePage write Set_CodePage;
    property LCID: Integer read Get_LCID write Set_LCID;
    property StaticObjects: IVariantDictionary read Get_StaticObjects;
    property Contents: IVariantDictionary read Get_Contents;
  end;
  {$EXTERNALSYM ISessionObject}

  IApplicationObject = interface(IDispatch)
    ['{D97A6DA0-A866-11CF-83AE-10A0C90C2BD8}']
    function Get_Value(const bstrValue: WideString): OleVariant; safecall;
    procedure _Set_Value(const bstrValue: WideString; pvar: OleVariant); safecall;
    procedure Set_Value(const bstrValue: WideString; pvar: OleVariant); safecall;
    procedure Lock; safecall;
    procedure UnLock; safecall;
    function Get_StaticObjects: IVariantDictionary; safecall;
    function Get_Contents: IVariantDictionary; safecall;
    property Value[const bstrValue: WideString]: OleVariant read Get_Value write _Set_Value; default;
    property StaticObjects: IVariantDictionary read Get_StaticObjects;
    property Contents: IVariantDictionary read Get_Contents;
  end;
  {$EXTERNALSYM IApplicationObject}

  IServer = interface(IDispatch)
    ['{D97A6DA0-A867-11CF-83AE-01A0C90C2BD8}']
    function Get_ScriptTimeout: Integer; safecall;
    procedure Set_ScriptTimeout(plTimeoutSeconds: Integer); safecall;
    function CreateObject(const bstrProgID: WideString): IDispatch; safecall;
    function HTMLEncode(const bstrIn: WideString): WideString; safecall;
    function MapPath(const bstrLogicalPath: WideString): WideString; safecall;
    function URLEncode(const bstrIn: WideString): WideString; safecall;
    function URLPathEncode(const bstrIn: WideString): WideString; safecall;
    property ScriptTimeout: Integer read Get_ScriptTimeout write Set_ScriptTimeout;
  end;
  {$EXTERNALSYM IServer}

  IScriptingContext = interface(IDispatch)
    ['{D97A6DA0-A868-11CF-83AE-00B0C90C2BD8}']
    function Get_Request: IRequest; safecall;
    function Get_Response: IResponse; safecall;
    function Get_Server: IServer; safecall;
    function Get_Session: ISessionObject; safecall;
    function Get_Application_: IApplicationObject; safecall;
    property Request: IRequest read Get_Request;
    property Response: IResponse read Get_Response;
    property Server: IServer read Get_Server;
    property Session: ISessionObject read Get_Session;
    property Application_: IApplicationObject read Get_Application_;
  end;
  {$EXTERNALSYM IScriptingContext}

  IASPObject = interface
  ['{7A8B9910-F33C-11D2-9EDD-00C04F6539EE}']
    procedure OnStartPage(AScriptingContext: IUnknown); safecall;
    procedure OnEndPage; safecall;
  end;

  TASPObject = class(TAutoObject, IASPObject)
  private
    FScriptingContext: IScriptingContext;
    function GetApplication: IApplicationObject;
    function GetRequest: IRequest;
    function GetResponse: IResponse;
    function GetScriptingContext: IScriptingContext;
    function GetServer: IServer;
    function GetSession: ISessionObject;
  public
    procedure OnStartPage(AScriptingContext: IUnknown); safecall;
    procedure OnEndPage; safecall;
    property ScriptingContext: IScriptingContext read GetScriptingContext;
    property Request: IRequest read GetRequest;
    property Response: IResponse read GetResponse;
    property Session: ISessionObject read GetSession;
    property Server: IServer read GetServer;
    property Application: IApplicationObject read GetApplication;
  end;

  TASPMTSObject = class(TAutoObject)
  private
    function GetApplication: IApplicationObject;
    function GetRequest: IRequest;
    function GetResponse: IResponse;
    function GetServer: IServer;
    function GetSession: ISessionObject;
  public
    property Request: IRequest read GetRequest;
    property Response: IResponse read GetResponse;
    property Session: ISessionObject read GetSession;
    property Server: IServer read GetServer;
    property Application: IApplicationObject read GetApplication;
  end;

implementation

{ TASPObject }

function TASPObject.GetApplication: IApplicationObject;
begin
  Result := FScriptingContext.Application_;
end;

function TASPObject.GetRequest: IRequest;
begin
  Result := FScriptingContext.Request;
end;

function TASPObject.GetResponse: IResponse;
begin
  Result := FScriptingContext.Response;
end;

function TASPObject.GetScriptingContext: IScriptingContext;
begin
  Result := FScriptingContext;
end;

function TASPObject.GetServer: IServer;
begin
  Result := FScriptingContext.Server;
end;

function TASPObject.GetSession: ISessionObject;
begin
  Result := FScriptingContext.Session;
end;

procedure TASPObject.OnEndPage;
begin
  FScriptingContext := nil;
end;

procedure TASPObject.OnStartPage(AScriptingContext: IUnknown);
begin
  FScriptingContext := (AScriptingContext as IScriptingContext);
end;

{ TASPMTSObject }

function TASPMTSObject.GetApplication: IApplicationObject;
begin
  Result := IUnknown((GetObjectContext as IGetContextProperties).GetProperty('Application')) as IApplicationObject;
end;

function TASPMTSObject.GetRequest: IRequest;
begin
  Result := IUnknown((GetObjectContext as IGetContextProperties).GetProperty('Request')) as IRequest;
end;

function TASPMTSObject.GetResponse: IResponse;
begin
  Result := IUnknown((GetObjectContext as IGetContextProperties).GetProperty('Response')) as IResponse;
end;

function TASPMTSObject.GetServer: IServer;
begin
  Result := IUnknown((GetObjectContext as IGetContextProperties).GetProperty('Server')) as IServer;
end;

function TASPMTSObject.GetSession: ISessionObject;
begin
  Result := IUnknown((GetObjectContext as IGetContextProperties).GetProperty('Session')) as ISessionObject;
end;

end.
