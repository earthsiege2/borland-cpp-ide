{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 2000-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit WebAuto;

interface

uses
  ComObj, ActiveX, WebScript_TLB, Windows, Classes, Contnrs, SiteComp, HTTPProd;

type

  TIDOfName = class
  private
    FID: Integer;
    FName: WideString;
    FDispatch: IDispatch;
  public
    constructor Create(AID: Integer; const AName: WideString; ADispatch: IDispatch);
    property ID: Integer read FID;
    property DispatchIntf: IDispatch read FDispatch;
  end;

  TIDsOfNames = class
  private
    FNextID: Integer;
    FList: TObjectList;
  public
    constructor Create;
    destructor Destroy; override;
    function FindID(AID: Integer): TIDOfName;
    function FindName(AName: PWideChar): TIDOfName;
    function Add(const AName: WideString; ADispatch: IDispatch): TIDOfName;
  end;

  TWebComponentsWrapper = class(TScriptComponent, IDispatch)
  private
    FIDsOfNames: TIDsOfNames;
  protected
    { IDispatch }
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; override;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; override;

    function DispatchOfName(const AName: string): IDispatch; virtual;
    function FindObject(const AName: string): TObject; virtual;
    function DispatchOfObject(const AObject: TObject): IDispatch; virtual;
  public
    constructor Create(AObject: TComponent); override;
    destructor Destroy; override;
  end;

  TWebModuleWrapper = class(TWebComponentsWrapper, IComponentWrapper, IModuleWrapper)
  protected
    { IComponentWrapper }
    function  Get_ClassName_: WideString; safecall;
    function  Get_Name_: WideString; safecall;
    function FindObject(const AName: string): TObject; override;
    { IWebModule }
    function  Get_Objects: IComponentsWrapper; safecall;
  public
    property Name: WideString read Get_Name_;
  end;

  TModuleObjectsWrapper = class(TScriptObject, IComponentsWrapper)
  private
    FModule: TObject;
    FEnumerator: IEnumVariant;
  protected
    { IAdapterRecordsWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  public
    constructor Create(AModule: TObject);
  end;

  TWebComponentsWrapperClass = class of TWebComponentsWrapper;

  TAbstractScriptComServerObject = class(TComServerObject)
  private
    FTypeLib: ITypeLib;
  protected
    function CountObject(Created: Boolean): Integer; override;
    function CountFactory(Created: Boolean): Integer; override;
    function GetHelpFileName: string; override;
    function GetServerFileName: string; override;
    function GetServerKey: string; override;
    function GetServerName: string; override;
    function GetStartSuspended: Boolean; override;
    function GetTypeLib: ITypeLib; override;
    function ImplGetTypeLib: ITypeLib; virtual; abstract;
    procedure SetHelpFileName(const Value: string); override;
  public
    function HaveTypeLib: Boolean;
    procedure RegisterScriptClass(AClass: TScriptClass; AClassID: TGUID);
  end;

  TScriptComServerObject = class(TAbstractScriptComServerObject)
  protected
    function ImplGetTypeLib: ITypeLib; override;
  end;

  TIteratorSupport = class(TScriptObject, IEnumVariant)
  private
    FIterator: IIteratorSupport;
    FEOF: Boolean;
    FReset: Boolean;
    FOwnerData: Pointer;
    FIterating: Boolean;
  protected
    function GetCurrent: IDispatch; virtual;
    property Iterator: IIteratorSupport read FIterator;
    property OwnerData: Pointer read FOwnerData;

    { IEnumVariant }
    function Clone(out ppenum: IEnumVARIANT): HResult; stdcall;
    function Next(celt: LongWord; var rgvar: OleVariant;
      out pceltFetched: LongWord): HResult; stdcall;
    function Reset: HResult; stdcall;
    function Skip(celt: LongWord): HResult; stdcall;
  public
    constructor Create(AIterator: IIteratorSupport);
    destructor Destroy; override;
  end;

  TComponentsEnumerator = class(TIteratorSupport)
  private
    FObject: TObject;
    FIterator: IIterateObjectSupport;
  protected
    function GetCurrent: IDispatch; override;
  public
    constructor Create(AObject: TObject);
    property Iterator: IIterateObjectSupport read FIterator;
  end;

var
  ScriptComServer: TAbstractScriptComServerObject;

procedure InitScriptComServer;

implementation

uses SysUtils, Variants, WebScript, SiteConst;

var
  FactoryList: TObjectList;

function FFactoryList: TObjectList;
begin
  if FactoryList = nil then
    FactoryList := TObjectList.Create;
  Result := FactoryList;
end;

procedure RaiseObjectDoesNotSupportScripting(AObject: TObject);
begin
  if AObject is TComponent then
    raise EActiveScriptError.CreateFmt(sComponentDoesNotSupportScripting,
      [TComponent(AObject).ClassName, TComponent(AObject).Name])
  else
    raise EActiveScriptError.CreateFmt(sClassDoesNotSupportScripting,
      [AObject.ClassName]);
end;

{ TAbstractScriptComServerObject }

function TAbstractScriptComServerObject.CountFactory(Created: Boolean): Integer;
begin
  Result := 0;
end;

function TAbstractScriptComServerObject.CountObject(Created: Boolean): Integer;
begin
  Result := 0;
end;

function TAbstractScriptComServerObject.GetHelpFileName: string;
begin
  Result := '';
end;

function TAbstractScriptComServerObject.GetServerFileName: string;
begin
  Result := '';
end;

function TAbstractScriptComServerObject.GetServerKey: string;
begin
  Result := '';
end;

function TAbstractScriptComServerObject.GetServerName: string;
begin
  Result := '';
end;

function TAbstractScriptComServerObject.GetStartSuspended: Boolean;
begin
  Result := False;
end;

function TAbstractScriptComServerObject.GetTypeLib: ITypeLib;
begin
  if FTypeLib = nil then
    FTypeLib := ImplGetTypeLib;
  Result := FTypeLib;
end;

function TAbstractScriptComServerObject.HaveTypeLib: Boolean;
begin
  Result := TypeLib <> nil;
end;

procedure TAbstractScriptComServerObject.RegisterScriptClass(
  AClass: TScriptClass; AClassID: TGUID);
begin
  if HaveTypeLib then
    FFactoryList.Add(TAutoObjectFactory.Create(Self, AClass, AClassID,
      ciInternal, tmApartment));
end;

procedure TAbstractScriptComServerObject.SetHelpFileName(const Value: string);
begin
  // Do nothing
end;

{ TIDOfName }

constructor TIDOfName.Create(AID: Integer; const AName: WideString;
  ADispatch: IDispatch);
begin
  FID := AID;
  FName := AName;
  FDispatch := ADispatch;
end;

{ TIDsOfNames }

function TIDsOfNames.Add(const AName: WideString;
  ADispatch: IDispatch): TIDOfName;
begin
  Result := TIDOfName.Create(FNextID, AName, ADispatch);
  try
    FList.Add(Result);
  except
    Result.Free;
    raise;
  end;
  Inc(FNextID);
end;

const
  IDFirst = 100;

constructor TIDsOfNames.Create;
begin
  FNextID := IDFirst;
  FList := TObjectList.Create(True); // owned
end;

destructor TIDsOfNames.Destroy;
begin
  inherited;
  FList.Free;

end;

function TIDsOfNames.FindID(AID: Integer): TIDOfName;
begin
  if (AID <> 0) and (AID - IDFirst < FList.Count) then
    Result := TIDOfName(FList[AID - IDFirst])
  else
    Result := nil;
end;

function TIDsOfNames.FindName(AName: PWideChar): TIDOfName;
var
  I: Integer;
begin
  for I := 0 to FList.Count - 1 do
  begin
    Result := TIDOfName(FList[I]);
    if WideSameText(Result.FName, AName) then
      Exit;
  end;
  Result := nil;
end;

{ TWebComponentsWrapper }

constructor TWebComponentsWrapper.Create(AObject: TComponent);
begin
  inherited Create(AObject);
  FIDsOfNames := TIDsOfNames.Create;
end;

function TWebComponentsWrapper.DispatchOfName(
  const AName: string): IDispatch;
var
 Obj: TObject;
begin
  Result := nil;
  Obj := FindObject(AName);
  if Obj <> nil then
    Result := DispatchOfObject(Obj);
end;

function TWebComponentsWrapper.DispatchOfObject(const AObject: TObject): IDispatch;
var
  GetIntf: IGetScriptObject;
begin
  if AObject <> nil then
    if Supports(AObject, IGetScriptObject, GetIntf) then
      Result := GetIntf.GetScriptObject
    else
      RaiseObjectDoesNotSupportScripting(AObject)
  else
    Result := nil;
end;

destructor TWebComponentsWrapper.Destroy;
begin
  inherited;
  FIdsOfNames.Free;
end;

function TWebComponentsWrapper.FindObject(const AName: string): TObject;
begin
  Assert(False, 'FindObject not implemented');
  Result := nil;
end;

function TWebComponentsWrapper.GetIDsOfNames(const IID: TGUID;
  Names: Pointer; NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
var
  I: Integer;
  P: POleStrList;
  IDOfName: TIDOfName;
  ID: Integer;
  Intf: IDispatch;
begin
  Result := inherited GetIDsOfNames(IID, Names, NameCount, LocaleID, DispIDs);
  if Result = DISP_E_UNKNOWNNAME then
  begin
    P := POleStrList(Names);
    IDOfName := FIdsOfNames.FindName(P^[0]);
    if IDOfName = nil then
    begin
      Intf := DispatchOfName(P^[0]);
      IDOfName := FIdsOfNames.Add(P^[0], Intf);
    end;
    if Assigned(IDOfName) then
      ID := IDOfName.ID
    else
      ID := -1;
    PDispIDList(DispIDs)[0] := ID;
    if NameCount > 1 then
      for I := 1 to NameCount - 1 do PDispIDList(DispIDs)[I] := -1;
    if (ID = -1) or (NameCount > 1) then
      Result := DISP_E_UNKNOWNNAME else
      Result := S_OK;
  end;
end;

function TWebComponentsWrapper.Invoke(DispID: Integer;
  const IID: TGUID; LocaleID: Integer; Flags: Word; var Params; VarResult,
  ExcepInfo, ArgErr: Pointer): HResult;
var
  IDOfName: TIDOfName;
begin
  Result := inherited Invoke(DispID, IID, LocaleID, Flags, Params,
    VarResult, ExcepInfo, ArgErr);
  if Result = DISP_E_MEMBERNOTFOUND then
  begin
    IDOfName := FIDsOfNames.FindID(DispID);
    if (IDOfName <> nil) and (VarResult <> nil) then
    begin
      VariantClear((POleVariant(VarResult))^);
      if IDOfName.DispatchIntf <> nil then
        POleVariant(VarResult)^ := IDOfName.DispatchIntf
      else
        POleVariant(VarResult)^ := Null;
      Result := S_OK;
    end;
  end;
end;

{ TScriptComServerObject }

function TScriptComServerObject.ImplGetTypeLib: ITypeLib;
begin
  if LoadRegTypeLib(LIBID_WebScript, 1, 0, 0, Result) <> S_OK then
    Result := nil;
end;

{ TWebModuleWrapper }

function TWebModuleWrapper.FindObject(const AName: string): TObject;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  if Supports(Obj, IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
  else
    Result := nil;
end;

function TWebModuleWrapper.Get_ClassName_: WideString;
begin
  Result := Obj.ClassName;
end;

function TWebModuleWrapper.Get_Name_: WideString;
begin
  if Obj <> nil then
    Result := Obj.Name
  else
    Result := '';
end;

function TWebModuleWrapper.Get_Objects: IComponentsWrapper;
begin
  if Obj <> nil then
    Result := TModuleObjectsWrapper.Create(Obj)
  else
    Result := nil;
end;

{ TModuleObjectsWrapper }

constructor TModuleObjectsWrapper.Create(AModule: TObject);
begin
  FModule := AModule;
  inherited Create;
end;

function TModuleObjectsWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    FEnumerator := TComponentsEnumerator.Create(FModule) as IEnumVariant;
  Result := FEnumerator;
end;

{ TIteratorSupport }

function TIteratorSupport.Clone(out ppenum: IEnumVARIANT): HResult;
begin
  Assert(False, 'Clone not implemented');
  Result := E_NOTIMPL;
end;

constructor TIteratorSupport.Create(AIterator: IIteratorSupport);
begin
  FIterator := AIterator;
  FReset := True;
  inherited Create;
end;

function TIteratorSupport.Next(celt: LongWord;
  var rgvar: OleVariant; out pceltFetched: LongWord): HResult;
begin
  if Assigned(FIterator) then
  try
    if FReset then
    begin
      try
        if FIterating then
          FIterator.EndIterator(FOwnerData);
      finally
        FIterating := False;
      end;
      FReset := False;
      FOwnerData := nil;
      FIterating := True;
      FEOF := not FIterator.StartIterator(FOwnerData);
    end
    else
      FEOF := not FIterator.NextIteration(FOwnerData);
    if not FEOF then
    begin
      if celt = 1 then
      begin
        rgVar := GetCurrent;
        if @pceltFetched <> nil then
          pceltFetched := celt;
      end
      else
      begin
        Result := E_NOTIMPL;
        Exit;
      end;
    end;
    if FEOF then
      Result := S_FALSE
    else
      Result := S_OK;
  except
    Result := E_NOTIMPL;
  end
  else
    Result := E_NOTIMPL;
end;

function TIteratorSupport.GetCurrent: IDispatch;
begin
  Assert(False, 'GetCurrent not implemented');
end;

function TIteratorSupport.Reset: HResult;
begin
  if Assigned(FIterator) then
  begin
    FReset := True;
    Result := S_OK;
  end
  else
    Result := E_NOTIMPL;
end;

function TIteratorSupport.Skip(celt: LongWord): HResult;
var
  I: LongWord;
  P: Pointer;
begin
  if Assigned(FIterator) then
  begin
    if FEOF then
      Result := S_FALSE
    else
    begin
      I := 0;
      while (not FEOF) and (I < celt) do
      begin
        FEOF := FIterator.NextIteration(P);
        Inc(I);
      end;
      if not FEOF then
        Result := S_OK
      else
        Result := S_FALSE
    end
  end
  else
    Result := E_NOTIMPL;
end;

destructor TIteratorSupport.Destroy;
begin
  inherited;
  if FIterating then
    try
      FIterator.EndIterator(FOwnerData);
    except
    end;
end;

{ TComponentsEnumerator }

constructor TComponentsEnumerator.Create(AObject: TObject);
begin
  FObject := AObject;
  Supports(AObject, IIterateObjectSupport, FIterator);
  inherited Create(FIterator);
end;

function TComponentsEnumerator.GetCurrent: IDispatch;
var
  Current: TObject;
  GetIntf: IGetScriptObject;
begin
  Current := Iterator.GetCurrentObject(FOwnerData);
  Assert(Assigned(Current));
  if Supports(Current, IGetScriptObject, GetIntf) then
    Result := GetIntf.GetScriptObject
  else
    Assert(False, 'GetScriptObject not supported');
end;

procedure InitScriptComServer;
begin
  if ScriptComServer = nil then
  begin
    ScriptComServer := TScriptComServerObject.Create;
    ScriptComServer.RegisterScriptClass(TWebModuleWrapper, Class_ModuleWrapper);
    ScriptComServer.RegisterScriptClass(TComponentsEnumerator, Class_EnumVariantWrapper);
    ScriptComServer.RegisterScriptClass(TModuleObjectsWrapper, Class_ComponentsWrapper);
  end;
end;

initialization
  InitScriptComServer;
finalization
  if Assigned(FactoryList) then
    FactoryList.Free;
  FreeAndNil(ScriptComServer);
end.
