{****************************************************************}
{                                                                }
{       Borland Delphi Visual Component Library                  }
{                                                                }
{       Copyright (c) 2000, 2001 Borland Software Corporation    }
{                                                                }
{****************************************************************}

unit AutoAdap;

interface

uses
  ComObj, ActiveX, WebScript_TLB, Windows, Classes, Contnrs, WebComp, WebAuto,
  SiteComp, HTTPProd, WebCntxt;

type

  TBaseAdapterWrapper = class(TWebComponentsWrapper, IComponentWrapper)
  protected
    FFields: IComponentsWrapper;
    FActions: IComponentsWrapper;
    { IComponentWrapper }
    function Get_Name_: WideString; safecall;
    function Get_ClassName_: WideString; safecall;
    { IAdapterWRapper }
    function  Get_Fields: IComponentsWrapper; safecall;
    function Get_Actions: IComponentsWrapper; safecall;
  public
  end;

  TAdapterWrapperClass = class of TBaseAdapterWrapper;

  TBaseRecordsAdapterWrapper = class(TBaseAdapterWrapper)
  protected
    { IAdapterWrapper }
    function  Get_Records: AdapterRecordsWrapper; safecall;
  end;

  TAdapterWrapper = class(TBaseRecordsAdapterWrapper, IAdapterWrapper)
  private
  protected
    function FindObject(const AName: string): TObject; override;
    { IAdapterWrapper }
    function  Get_Errors: IAdapterErrorsWrapper; safecall;
    function  Get_Mode: WideString; safecall;
    procedure Set_Mode({VT_8:0}const Value: WideString); safecall;
    function  Get_CanView: WordBool; safecall;
    function  Get_CanModify: WordBool; safecall;
    function  Get_HiddenFields: IAdapterHiddenFieldsWrapper; safecall;
    function  Get_HiddenRecordFields: IAdapterHiddenFieldsWrapper; safecall;
  end;

  TAdapterValuesListWrapper = class(TBaseRecordsAdapterWrapper, IAdapterValuesListWrapper)
  protected
    function FindObject(const AName: string): TObject; override;
    { IAdapterValuesListWrapper }
    function  Get_Records: IAdapterRecordsWrapper; safecall;
    function  Get_Value: OleVariant; safecall;
    function  Get_ValueName: WideString; safecall;
    function  Get_Image: IAdapterImageWrapper; safecall;
    function  NameOfValue(Value: OleVariant): WideString; safecall;
    function  ImageOfValue(Value: OleVariant): IAdapterImageWrapper; safecall;
  end;

  TAdapterFieldValuesWrapper = class(TBaseRecordsAdapterWrapper, IAdapterFieldValuesWrapper)
  protected
    function FindObject(const AName: string): TObject; override;
    { IAdapterFieldValuesWrapper }
    function  Get_Records: IAdapterRecordsWrapper; safecall;
    function  Get_Value: OleVariant; safecall;
    function  HasValue {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Value: OleVariant): WordBool; safecall;
  end;

  //GetThreadLocale

  TAdapterComponentsWrapper = class(TWebComponentsWrapper, IComponentsWrapper)
  private
    FEnumerator: IEnumVariant;
  protected
    { IAdapterComponentsWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    function FindObject(const AName: string): TObject; override;
 end;

  TAdapterRecordsWrapper = class(TScriptObject, IAdapterRecordsWrapper)
  private
    FAdapter: TComponent;
    FEnumerator: IEnumVariant;
  protected
    { IAdapterRecordsWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  public
    constructor Create(AAdapter: TComponent);
  end;

  TAdapterActionArrayWrapper = class(TScriptObject, IAdapterActionArrayWrapper)
  private
    FAction: IInterface;
    FEnumerator: IEnumVariant;
  protected
    { IAdapterActionArrayWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  public
    constructor Create(AAction: IInterface);
  end;

  TAdapterErrorsWrapper = class(TScriptObject, IAdapterErrorsWrapper)
  private
    FErrors: TObject;
    FEnumerator: IEnumVariant;
  protected
    { IAdapterErrorsWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    procedure DefineLabel {Flags(1), (2/2) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown;
                                                               {VT_8:1}const Value: WideString); safecall;
    function  FieldErrors {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown): IAdapterErrorsWrapper; safecall;
  public
    constructor Create(AErrors: TObject);
  end;

  TAdapterHiddenFieldsWrapper = class(TScriptObject, IAdapterHiddenFieldsWrapper)
  private
    FHiddenFields: TObject;
    FEnumerator: IEnumVariant;
  protected
    { IAdapterHiddenFieldsWrapper }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    procedure WriteFields(const Response: IDispatch); safecall;
  public
    constructor Create(AHiddenFields: TObject);
  end;

  TNotificationProc = procedure (AComponent: TComponent; Operation: TOperation) of object;
  TNotifier = class(TComponent)
  protected
    FNotify: TNotificationProc;
    FComponent: TComponent;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    destructor Destroy; override;
    constructor Create(ANotify: TNotificationProc; AComponent: TComponent); reintroduce;
  end;

  TAdapterSubComponentWrapper = class(TScriptObject, IInterfaceComponentReference)
  private
    FIntf: IUnknown;
    FNotifier: TNotifier;
  protected
    { IInterfaceComponentReference }
    function GetComponent: TComponent;
    function  Get_Name: OleVariant; safecall;
  public
    constructor Create(AObject: TComponent); overload;
    constructor Create(AObject: TInterfacedObject); overload;
    property ObjectIntf: IUnknown read FIntf;
    destructor Destroy; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); 
  end;

  TAdapterFieldWrapper = class(TAdapterSubComponentWrapper, IAdapterFieldWrapper)
  private
    function AsEditText(const Value: OleVariant): WideString;
  protected
    { IAdapterFieldWrapper }
    function  Get_Value: OleVariant; safecall;
    function  Get_Values: IAdapterFieldValuesWrapper; safecall;
    function  Get_DisplayText: WideString; safecall;
    function  Get_EditText: WideString; safecall;
    function  Get_InputName: WideString; safecall;
    function  Get_DisplayWidth: Integer; safecall;
    function  Get_MaxLength: Integer; safecall;
    function  Get_DisplayLabel: WideString; safecall;
    function  Get_ValuesList: IAdapterValuesListWrapper; safecall;
    function  Get_Image: IAdapterImageWrapper; safecall;
    function  Get_DisplayStyle: WideString; safecall;
    function  Get_InputStyle: WideString; safecall;
    function  Get_ViewMode: WideString; safecall;
    function  Get_CanView: WordBool; safecall;
    function  Get_Required: WordBool; safecall;
    function  Get_Visible: WordBool; safecall;
    function  Get_CanModify: WordBool; safecall;
    function  IsEqual(Value: OleVariant): WordBool; safecall;
  end;

  TAdapterActionWrapper = class(TAdapterSubComponentWrapper, IAdapterActionWrapper)
  protected
    { IAdapterActionWrapper }
    function  Get_AsFieldValue: WideString; safecall;
    function  Get_AsHREF: WideString; safecall;
    function  LinkToPage({VT_8:0}const PageSuccess: WideString;
                         {VT_8:0}const PageFail: WideString): IAdapterActionWrapper; safecall;
    function  Get_DisplayLabel: WideString; safecall;
    function  Get_Enabled: WordBool; safecall;
    function  Get_CanExecute: WordBool; safecall;
    function  Get_Visible: WordBool; safecall;
    function  Get_Array_: IAdapterActionArrayWrapper; safecall;
    function  Get_DisplayStyle: WideString; safecall;
  end;

  TAdapterImageWrapper = class(TScriptObject, IAdapterImageWrapper)
  private
    FIntf: IInterface;
  protected
    { IAdapterImageWrapper }
    function  Get_AsHREF: WideString; safecall;
  public
    constructor Create(AIntf: IInterface);
  end;

  TImageProducerWrapper = class(TScriptComponent, IImageProducerWrapper)
  protected
    { IImageProducerWrapper }
    function  GetImage {Flags(1), (3/2) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown;
                                                            {VT_8:0}const Caption: WideString): IAdapterImageWrapper; safecall;
    function  GetEventImage {Flags(1), (4/3) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown; 
                                                                 {VT_8:0}const Event: WideString; 
                                                                 {VT_8:0}const Caption: WideString): IAdapterImageWrapper; safecall;
    function  GetDisplayStyle {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown): WideString; safecall;
  end;

  TAdapterRecordEnumerator = class(TIteratorSupport)
  private
    FObjectIntf: IInterface;
    FCurrent: IGetScriptObject;
  protected
    function GetCurrent: IDispatch; override;
    property ObjectIntf: IInterface read FObjectIntf;
  public
    constructor Create(AObjectIntf: IInterface);
  end;

  TAdapterFieldRecordEnumerator = class(TIteratorSupport)
  private
    FObject: TObject;
    FCurrent: IGetScriptObject;
  protected
    function GetCurrent: IDispatch; override;
    property Obj: TObject read FObject;
  public
    constructor Create(AObject: TObject);
  end;

  TAdapterErrorEnumerator = class(TIteratorSupport)
  private
    FIterator: IIterateIntfSupport;
  protected
    function GetCurrent: IDispatch; override;
  public
    constructor Create(AErrors: TObject);
  end;

  TAdapterHiddenFieldsEnumerator = class(TIteratorSupport)
  private
    FIterator: IIterateIntfSupport;
  protected
    function GetCurrent: IDispatch; override;
  public
    constructor Create(AHiddenFields: TObject);
  end;

  TAdapterRecordWrapper = class(TScriptObject, IAdapterRecordWrapper)
  private
    FAdapter: TComponent;
    FAdapterWrapper: TBaseAdapterWrapper;
  public
    constructor Create(AAdapter: TComponent; AAdapterWrapperClass: TAdapterWrapperClass);
    property Impl: TBaseAdapterWrapper read FAdapterWrapper implements IAdapterRecordWrapper;
  end;

  TAdapterErrorWrapper = class(TScriptObject, IAdapterErrorWrapper)
  private
    FError: IAdapterError;
  protected
    { IAdapterError }
    function  Get_Message: WideString; safecall;
    function  Get_Field {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IDispatch; safecall;
    function  Get_ID {Flags(1), (1/0) CC:0, INV:2, DBG:6}: Integer; safecall;
  public
    constructor Create(const AError: IAdapterError);
  end;

  TAdapterHiddenFieldWrapper = class(TScriptObject, IAdapterHiddenFieldWrapper)
  private
    FParam: IAdapterHiddenField;
  protected
    { IAdapterHiddenFieldWrapper}
    function  Get_Name: WideString; safecall;
    function  Get_Value: WideString; safecall;
  public
    constructor Create(const AParam: IAdapterHiddenField);
  end;

  TActionLink = class(TInterfacedObject, IGetAdapterItemRequestParams,
    IGetAdapterRequestDefaultResponse, IInterfaceComponentReference)
  private
    FAction: IInterface;
    FPage: string;
    FErrorPage: string;
    // function GetObject: TComponent;
  protected
    { IGetAdapterRequestParams }
    procedure GetAdapterItemRequestParams(var AIdentifier: string; AParams: IAdapterItemRequestParams);
    { IGetAdapterRequestDefaultResponse }
    function GetSuccessPage: string;
    function GetFailurePage: string;
    { IInterfaceComponentReference }
    function GetComponent: TComponent;
  public
    constructor Create(AAction: IInterface; const APage, AErrorPage: string);
  end;

  TWebEndUserWrapper = class(TAdapterWrapper, IEndUserWrapper)
  private
    FContext: IScriptContext;
    FEndUser: IWebEndUser;
    function EndUser: IWebEndUser;
  protected
    { IWebEndUser }
    function  Get_DisplayName: WideString; safecall;
    function  Get_LoggedIn: WordBool; safecall;
    function  Get_LoginFormAction: IAdapterActionWrapper; safecall;
    function  Get_LogoutAction: IAdapterActionWrapper; safecall;
  public
    constructor Create(AContext: IScriptContext); reintroduce;
  end;

  TWebApplicationWrapper = class(TAdapterWrapper, IApplicationWrapper)
  private
    FContext: IScriptContext;
    FApplicationInfo: IWebApplicationInfo;
    function ApplicationInfo: IWebApplicationInfo;
  protected
    { IWebApplication }
    function  Get_Title: WideString; safecall;
    function  Get_Designing: WordBool; safecall;
    function  QualifyFileName({VT_8:0}const FileName: WideString): WideString; safecall;
    function  Get_ModulePath: WideString; safecall;
    function Get_ModuleFileName: WideString; safecall;
  public
    constructor Create(AContext: IScriptContext); reintroduce;
  end;

implementation

uses SysUtils, Variants, WebDisp, HTTPApp;

{ TAdapterWrapper }

function TAdapterWrapper.FindObject(const AName: string): TObject;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  if Supports(Obj, IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
  else
    Result := nil;
end;

function TAdapterWrapper.Get_CanModify: WordBool;
var
  Intf: IAdapterAccess;
begin
  if Supports(Obj, IAdapterAccess, Intf) then
    Result := Intf.HasModifyAccess
  else
    Result := True;
end;

function TAdapterWrapper.Get_CanView: WordBool;
var
  Intf: IAdapterAccess;
begin
  if Supports(Obj, IAdapterAccess, Intf) then
    Result := Intf.HasViewAccess
  else
    Result := True;
end;

function TAdapterWrapper.Get_Errors: IAdapterErrorsWrapper;
var
  Intf: IGetAdapterErrors;
begin
  if Supports(Obj, IGetAdapterErrors, Intf) then
    Result := TAdapterErrorsWrapper.Create(Intf.GetAdapterErrors)
  else
    Result := nil;
end;

function TAdapterWrapper.Get_HiddenFields: IAdapterHiddenFieldsWrapper;
var
  Intf: IGetAdapterHiddenFields;
  O: TObject;
begin
  if Supports(Obj, IGetAdapterHiddenFields, Intf) then
  begin
    O := Intf.GetAdapterHiddenFields;
    if O <> nil then
      Result := TAdapterHiddenFieldsWrapper.Create(O)
    else
      Result := nil
  end
  else
    Result := nil;
end;

function TAdapterWrapper.Get_HiddenRecordFields: IAdapterHiddenFieldsWrapper;
var
  Intf: IGetAdapterHiddenFields;
  O: TObject;
begin
  if Supports(Obj, IGetAdapterHiddenFields, Intf) then
  begin
    O := Intf.GetAdapterHiddenRecordFields;
    if O <> nil then
      Result := TAdapterHiddenFieldsWrapper.Create(O)
    else
      Result := nil;
  end
  else
    Result := nil;
end;

function TAdapterWrapper.Get_Mode: WideString;
var
  Intf: IAdapterMode;
begin
  if Supports(Obj, IAdapterMode, Intf) then
    Result := Intf.GetAdapterMode
  else
    Result := '';
end;

procedure TAdapterWrapper.Set_Mode(const Value: WideString);
var
  Intf: IAdapterMode;
begin
  if Supports(Obj, IAdapterMode, Intf) then
    Intf.SetAdapterMode(Value);
end;

{ TAdapterComponentsWrapper }

function TAdapterComponentsWrapper.FindObject(const AName: string): TObject;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  if Supports(Obj, IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
  else
    Result := nil;
end;

function TAdapterComponentsWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    FEnumerator := TComponentsEnumerator.Create(Obj) as IEnumVariant;
  Result := FEnumerator;
end;

{ TAdapterRecordsWrapper }

constructor TAdapterRecordsWrapper.Create(AAdapter: TComponent);
begin
  FAdapter := AAdapter;
  inherited Create;
end;

function TAdapterRecordsWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    FEnumerator := TAdapterRecordEnumerator.Create(FAdapter) as IEnumVariant;
  Result := FEnumerator;
end;

{ TAdapterActionArrayWrapper }

constructor TAdapterActionArrayWrapper.Create(AAction: IInterface);
begin
  FAction := AAction;
  inherited Create;
end;

function TAdapterActionArrayWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    FEnumerator := TAdapterRecordEnumerator.Create(FAction) as IEnumVariant;
  Result := FEnumerator;
end;

{ TAdapterErrorsWrapper }

constructor TAdapterErrorsWrapper.Create(AErrors: TObject);
begin
  FErrors := AErrors;
  inherited Create;
end;

procedure TAdapterErrorsWrapper.DefineLabel(const Object_: IUnknown;
  const Value: WideString);
var
  Intf: IAdapterErrors;
  ComponentIntf: IAdapterFieldWrapper;
begin
  if Supports(FErrors, IAdapterErrors, Intf) then
    if Supports(Object_, IAdapterFieldWrapper, ComponentIntf) then
      Intf.DefineLabel(ComponentIntf.Get_Name, Value);
end;

function TAdapterErrorsWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    if FErrors <> nil then
      FEnumerator := TAdapterErrorEnumerator.Create(FErrors) as IEnumVariant;
  Result := FEnumerator;
end;

function TAdapterErrorsWrapper.FieldErrors(
  const Object_: IUnknown): IAdapterErrorsWrapper;
var
  Intf: IAdapterErrors;
  ComponentIntf: IAdapterFieldWrapper;
begin
  if Supports(FErrors, IAdapterErrors, Intf) then
    if Supports(Object_, IAdapterFieldWrapper, ComponentIntf) then
      if Intf.HasObjectErrors(ComponentIntf.Get_Name) then
         Result := TAdapterErrorsWrapper.Create(Intf.GetObjectErrors(ComponentIntf.Get_Name));
end;

{ TAdapterHiddenFieldsWrapper }

constructor TAdapterHiddenFieldsWrapper.Create(AHiddenFields: TObject);
begin
  FHiddenFields := AHiddenFields;
  inherited Create;
end;

function TAdapterHiddenFieldsWrapper.Get_NewEnum: IUnknown;
begin
  if FEnumerator = nil then
    if FHiddenFields <> nil then
      FEnumerator := TAdapterHiddenFieldsEnumerator.Create(FHiddenFields) as IEnumVariant;
  Result := FEnumerator;
end;

procedure TAdapterHiddenFieldsWrapper.WriteFields(const Response: IDispatch);
var
  AdapterHiddenFields: IAdapterHiddenFields;
  I: Integer;
  Field: IAdapterHiddenField;
  ResponseWrapper: IResponseWrapper;
  S: string;
begin
  if Supports(Response, IResponseWrapper, ResponseWrapper) and
    Supports(FHiddenFields, IAdapterHiddenFields, AdapterHiddenFields) then
  begin
    for I := 0 to AdapterHiddenFields.FieldCount - 1 do
    begin
      Field := AdapterHiddenFields.Fields[I];
      S := Format('%s<input type="hidden" name="%s" value="%s">'#13#10, [S, Field.Name, Field.Value]); { do not localize }
    end;
    ResponseWrapper.Write(S);
  end;
end;

{ TAdapterSubComponentWrapper }

constructor TAdapterSubComponentWrapper.Create(AObject: TComponent);
begin
  FIntf := AObject;
  FNotifier := TNotifier.Create(Notification, AObject);
  inherited Create;
end;

constructor TAdapterSubComponentWrapper.Create(AObject: TInterfacedObject);
begin
  FIntf := AObject;
  FNotifier := nil;
  inherited Create;
end;

destructor TAdapterSubComponentWrapper.Destroy;
begin
  if FNotifier <> nil then
    FNotifier.Free;
  inherited;
end;

function TAdapterSubComponentWrapper.GetComponent: TComponent;
var
  GetComp: IInterfaceComponentReference;
begin
  if Supports(ObjectIntf, IInterfaceComponentReference, GetComp) then
    Result := GetComp.GetComponent
  else
    Result := nil;
end;

function TAdapterSubComponentWrapper.Get_Name: OleVariant;
var
  Intf: IWebVariableName;
begin
  if Supports(ObjectIntf, IWebVariableName, Intf) then
    Result := Intf.VariableName
  else
    Result := Unassigned;
end;

procedure TAdapterSubComponentWrapper.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and
    (AComponent = FNotifier.FComponent) then
  begin
    FIntf := nil; // release it safely now..
    FreeAndNil(FNotifier);
  end;
end;

{ TAdapterRecordEnumerator }

constructor TAdapterRecordEnumerator.Create(AObjectIntf: IInterface);
var
  Intf: IIteratorSupport;
begin
  FObjectIntf := AObjectIntf;         
  Supports(AObjectIntf, IIteratorSupport, Intf);
  Supports(AObjectIntf, IGetScriptObject, FCurrent);
  inherited Create(Intf);
end;

function TAdapterRecordEnumerator.GetCurrent: IDispatch;
begin
  if FCurrent <> nil then
    Result := FCurrent.GetScriptObject
  else
    Assert(False, 'IGetScriptObject not implemented');
end;

{ TAdapterFieldRecordEnumerator }

constructor TAdapterFieldRecordEnumerator.Create(AObject: TObject);
var
  Intf: IIteratorSupport;
begin
  FObject := AObject;
  Supports(AObject, IIteratorSupport, Intf);
  Supports(AObject, IGetScriptObject, FCurrent);
  inherited Create(Intf);
end;

function TAdapterFieldRecordEnumerator.GetCurrent: IDispatch;
begin
  if FCurrent <> nil then
    Result := FCurrent.GetScriptObject
  else
    Assert(False, 'IGetScriptObject not implemented');
end;

{ TAdapterErrorEnumerator }

constructor TAdapterErrorEnumerator.Create(AErrors: TObject);
begin
  Supports(AErrors, IIterateIntfSupport, FIterator);
  inherited Create(FIterator);
end;

function TAdapterErrorEnumerator.GetCurrent: IDispatch;
var
  Temp: Pointer;
begin
  Temp := nil;
  Result := TAdapterErrorWrapper.Create(FIterator.GetCurrentIntf(Temp) as IAdapterError) as IDispatch;
end;

{ TAdapterHiddenFieldsEnumerator }

constructor TAdapterHiddenFieldsEnumerator.Create(AHiddenFields: TObject);
begin
  Supports(AHiddenFields, IIterateIntfSupport, FIterator);
  inherited Create(FIterator);
end;

function TAdapterHiddenFieldsEnumerator.GetCurrent: IDispatch;
var
  Temp: Pointer;
begin
  Temp := nil;
  Result := TAdapterHiddenFieldWrapper.Create(FIterator.GetCurrentIntf(Temp) as IAdapterHiddenField) as IDispatch;
end;

{ TAdapterRecordWrapper }

constructor TAdapterRecordWrapper.Create(AAdapter: TComponent; AAdapterWrapperClass: TAdapterWrapperClass);
begin
  FAdapter := AAdapter;
  FAdapterWrapper := AAdapterWrapperClass.Create(AAdapter);
  inherited Create;
end;

{ TAdapterFieldWrapper }

function TAdapterFieldWrapper.Get_DisplayText: WideString;
var
  AsFormatted: IAsFormatted;
begin
  Supports(ObjectIntf, IAsFormatted, AsFormatted);
  if AsFormatted <> nil then
    Result := AsFormatted.AsFormatted
  else
    Result := Get_EditText;
end;

function TAdapterFieldWrapper.Get_DisplayWidth: Integer;
var
  GetDisplayWidth: IWebGetDisplayWidth;
begin
  if Supports(ObjectIntf, IWebGetDisplayWidth, GetDisplayWidth) then
    Result := GetDisplayWidth.GetDisplayWidth
  else
    Result := -1;
end;

function TAdapterFieldWrapper.Get_MaxLength: Integer;
var
  GetMax: IWebGetMaxLength;
begin
  if Supports(ObjectIntf, IWebGetMaxLength, GetMax) then
    Result := GetMax.GetMaxLength
  else
    Result := -1;
end;

function TAdapterFieldWrapper.Get_DisplayLabel: WideString;
var
  GetDisplayLabel: IWebGetDisplayLabel;
begin
  if Supports(ObjectIntf, IWebGetDisplayLabel, GetDisplayLabel) then
    Result := GetDisplayLabel.GetDisplayLabel
  else
    Result := '';
end;

function TAdapterFieldWrapper.Get_EditText: WideString;
begin
  Result := AsEditText(Get_Value);
end;

function TAdapterFieldWrapper.Get_InputName: WideString;
var
  Intf: IWebVariableName;
  InputName: IWebInputName;
begin
  if Supports(ObjectIntf, IWebInputName, InputName) then
    Result := InputName.InputName
  else if Supports(ObjectIntf, IWebVariableName, Intf) then
    Result := Intf.VariableName
  else
    Result := '';
end;

function TAdapterFieldWrapper.AsEditText(const Value: OleVariant): WideString;
begin
  if (not VarIsEmpty(Value)) and (not VarIsNull(Value)) then
    Result := HTMLEncode(Value)
  else
    Result := '';
end;

function TAdapterFieldWrapper.Get_ValuesList: IAdapterValuesListWrapper;
var
  GetIntf: IGetAdapterValuesList;
  AdapterValuesList: IValuesListAdapter;
  Intf: IInterfaceComponentReference;
begin
  if Supports(ObjectIntf, IGetAdapterValuesList, GetIntf) then
  begin
    AdapterValuesList := GetIntf.GetAdapterValuesList;
    if AdapterValuesList <> nil then
    begin
      if Supports(AdapterValuesList, IInterfaceComponentReference, Intf) and
        (Intf.GetComponent <> nil) then
        Result := TAdapterValuesListWrapper.Create(Intf.GetComponent)
      else
        Assert(False);  // Expected component implementation
      exit;
    end;
  end;
  Result := nil;
end;

function TAdapterFieldWrapper.Get_Image: IAdapterImageWrapper;
var
  GetIntf: IGetAdapterImage;
  AdapterImage: IInterface;
begin
  if Supports(ObjectIntf, IGetAdapterImage, GetIntf) then
  begin
    AdapterImage := GetIntf.GetAdapterImage;
    if AdapterImage <> nil then
    begin
      Result := TAdapterImageWrapper.Create(AdapterImage);
      exit;
    end;
  end;
  Result := nil;
end;

function TAdapterFieldWrapper.Get_DisplayStyle: WideString;
var
  Intf: IGetHTMLStyle;
begin
  if Supports(ObjectIntf, IGetHTMLStyle, Intf) then
    Result := Intf.GetDisplayStyle('')
  else
    Result := '';
end;

function TAdapterFieldWrapper.Get_InputStyle: WideString;
var
  Intf: IGetHTMLStyle;
begin
  if Supports(ObjectIntf, IGetHTMLStyle, Intf) then
    Result := Intf.GetInputStyle('')
  else
    Result := '';
end;

function TAdapterFieldWrapper.Get_CanModify: WordBool;
var
  Intf: IAdapterFieldAccess;
begin
  if Supports(ObjectIntf, IAdapterFieldAccess, Intf) then
    Result := Intf.HasModifyAccess
  else
    Result := True
end;

function TAdapterFieldWrapper.Get_CanView: WordBool;
var
  Intf: IAdapterFieldAccess;
begin
  if Supports(ObjectIntf, IAdapterFieldAccess, Intf) then
    Result := Intf.HasViewAccess
  else
    Result := True
end;

function TAdapterFieldWrapper.Get_Values: IAdapterFieldValuesWrapper;
var
  GetIntf: IGetFieldValuesAdapter;
  AdapterFieldValues: TComponent;
begin
  if Supports(ObjectIntf, IGetFieldValuesAdapter, GetIntf) then
  begin
    AdapterFieldValues := GetIntf.GetFieldValuesAdapter;
    if AdapterFieldValues <> nil then
    begin
      Result := TAdapterFieldValuesWrapper.Create(AdapterFieldValues);
      exit;
    end;
  end;
  Result := nil;

end;

function TAdapterFieldWrapper.Get_Value: OleVariant;
var
  Intf: IWebGetFieldValue;
begin
  if Supports(ObjectIntf, IWebGetFieldValue, Intf) then
    Result := Intf.GetValue
  else
    Result := Unassigned;
end;

function TAdapterFieldWrapper.IsEqual(Value: OleVariant): WordBool;
var
  Intf: IWebValueIsEqual;
  V: Variant;
begin
  if Supports(ObjectIntf, IWebValueIsEqual, Intf) then
    Result := Intf.IsEqual(Value)
  else
  begin
    V := Get_Value;
    try
      Result := (VarIsEmpty(Value) = VarIsEmpty(V)) and (Value = V);
    except
      Result := False
    end
  end;
end;

function TAdapterFieldWrapper.Get_ViewMode: WideString;
var
  Intf: IGetHTMLStyle;
begin
  if Supports(ObjectIntf, IGetHTMLStyle, Intf) then
    Result := Intf.GetViewMode('')
  else
    Result := '';
end;

function TAdapterFieldWrapper.Get_Required: WordBool;
var
  Intf: IAdapterFieldAttributes;
begin
  if Supports(ObjectIntf, IAdapterFieldAttributes, Intf) then
    Result := Intf.GetRequired
  else
    Result := False
end;

function TAdapterFieldWrapper.Get_Visible: WordBool;
var
  AdapterFieldAttributes: IAdapterFieldAttributes;
begin
  if Supports(ObjectIntf, IAdapterFieldAttributes, AdapterFieldAttributes) then
    Result := AdapterFieldAttributes.GetVisible
  else
    Result := True;
end;

function FindApplicationModuleOfObject(AObjectIntf: IInterface): TComponent;
var
  C: TComponent;
  CompRef: IInterfaceComponentReference;
begin
  if Supports(AObjectIntf, IInterfaceComponentReference, CompRef) then
    C := CompRef.GetComponent
  else
    C := nil;
  if C <> nil then
    begin
      while C.GetParentComponent <> nil do
        C := C.GetParentComponent;
      C := C.Owner;
    end;
  if WebContext <> nil then
    Result := WebContext.FindApplicationModule(C)
  else
    Result := nil;
end;

type

  TTempAdapterDispatcher = class(TInterfacedObject, IAdapterDispatcher)
  private
    FAdapterDispatcher: TAdapterDispatcher;
  protected
    property AdapterDispatcher: TAdapterDispatcher read FAdapterDispatcher implements IAdapterDispatcher;
  public
    constructor Create;
    destructor Destroy; override;
  end;

  constructor TTempAdapterDispatcher.Create;
  begin
    FAdapterDispatcher := TAdapterDispatcher.Create(nil);
    inherited;
  end;

  destructor TTempAdapterDispatcher.Destroy;
  begin
    FAdapterDispatcher.Free;
    inherited;
  end;

function FindAdapterDispatcher(AObjectIntf: IInterface): IAdapterDispatcher;
var
  GetIntf: IGetWebAppComponents;
  AppModule: TComponent;
begin
  AppModule := FindApplicationModuleOfObject(AObjectIntf);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    Result := GetIntf.GetAdapterDispatcher;
  if Result = nil then
    Result := TTempAdapterDispatcher.Create;
end;

{ TAdapterActionWrapper }

function TAdapterActionWrapper.Get_Array_: IAdapterActionArrayWrapper;
var
  Intf: IIsAdapterActionList;
begin
  if Supports(ObjectIntf, IIsAdapterActionList, Intf) and Intf.IsAdapterActionList then
    Result := TAdapterActionArrayWrapper.Create(ObjectIntf)
  else
    Result := nil;
end;

const
  sUnknown = 'Unknown'; // Do not localize

function TAdapterActionWrapper.Get_AsFieldValue: WideString;
var
  Intf: IAdapterDispatcher;
begin
  Intf := FindAdapterDispatcher(ObjectIntf);
  if Intf <> nil then
    Result := Intf.EncodeAdapterItemRequestAsFieldValue(ObjectIntf, [])
  else
    Result := sUnknown;
end;

function TAdapterActionWrapper.Get_AsHREF: WideString;
var
  Intf: IAdapterDispatcher;
begin
  Intf := FindAdapterDispatcher(ObjectIntf);
  if Intf <> nil then
    Result := Intf.EncodeAdapterItemRequestAsHREF(ObjectIntf, [])
  else
    Result := sUnknown;
end;

function TAdapterActionWrapper.Get_CanExecute: WordBool;
var
  Intf: IAdapterActionAccess;
begin
  if Supports(ObjectIntf, IAdapterActionAccess, Intf) then
    Result := Intf.HasExecuteAccess
  else
    Result := True
end;

function TAdapterActionWrapper.Get_DisplayLabel: WideString;
var
  GetDisplayLabel: IWebGetDisplayLabel;
begin
  if Supports(ObjectIntf, IWebGetDisplayLabel, GetDisplayLabel) then
    Result := GetDisplayLabel.GetDisplayLabel
  else
    Result := '';
end;

function TAdapterActionWrapper.Get_DisplayStyle: WideString;
var
  Intf: IGetHTMLStyle;
begin
  if Supports(ObjectIntf, IGetHTMLStyle, Intf) then
    Result := Intf.GetDisplayStyle('')
  else
    Result := '';
end;

function TAdapterActionWrapper.Get_Enabled: WordBool;
var
  Intf: IWebEnabled;
begin
  if Supports(ObjectIntf, IWebEnabled, Intf) then
    Result := Intf.WebEnabled
  else
    Result := True;
end;

function TAdapterActionWrapper.Get_Visible: WordBool;
var
  Intf: IAdapterActionAttributes;
begin
  if Supports(ObjectIntf, IAdapterActionAttributes, Intf) then
    Result := Intf.GetVisible
  else
    Result := True;
end;

function TAdapterActionWrapper.LinkToPage(const PageSuccess,
  PageFail: WideString): IAdapterActionWrapper;
var
  Link: TInterfacedObject;
  Wrapper: TAdapterActionWrapper;
begin
  Link := TActionLink.Create(ObjectIntf, PageSuccess, PageFail);
  Wrapper := TAdapterActionWrapper.Create(Link);
  Result := Wrapper;
end;

{ TActionLink }

procedure TActionLink.GetAdapterItemRequestParams(var AIdentifier: string; AParams: IAdapterItemRequestParams);
var
  Intf: IGetAdapterItemRequestParams;
begin
  AParams.ParamValues.Clear;
  if Supports(FAction, IGetAdapterItemRequestParams, Intf) then
    Intf.GetAdapterItemRequestParams(AIdentifier, AParams);
end;

constructor TActionLink.Create(AAction: IInterface; const APage, AErrorPage: string);
begin
  inherited Create;
  FPage := APage;
  FAction := AAction;
  FErrorPage := AErrorPage;
end;

function TActionLink.GetFailurePage: string;
begin
  Result := FErrorPage;
end;

function TActionLink.GetSuccessPage: string;
begin
  Result := FPage;
end;

function TActionLink.GetComponent: TComponent;
var
  CompRef: IInterfaceComponentReference;
begin
  if Supports(FAction, IInterfaceComponentReference, CompRef) then
    Result := CompRef.GetComponent
  else
    Result := nil;
end;

{ TAdapterErrorWrapper }

constructor TAdapterErrorWrapper.Create(const AError: IAdapterError);
begin
  FError := AError;
  inherited Create;
end;

function TAdapterErrorWrapper.Get_Field: IDispatch;
var
  GetIntf: IGetScriptObject;
begin
  if Supports(FError.GetField, IGetScriptObject, GetIntf) then
    Result := GetIntf.GetScriptObject
  else
    Result := nil;
end;

function TAdapterErrorWrapper.Get_ID: Integer;
begin
  Result := FError.ID;
end;

function TAdapterErrorWrapper.Get_Message: WideString;
begin
  Result := FError.ErrorText;
end;

{ TAdapterHiddenFieldWrapper }

constructor TAdapterHiddenFieldWrapper.Create(const AParam: IAdapterHiddenField);
begin
  FParam := AParam;
  inherited Create;
end;

function TAdapterHiddenFieldWrapper.Get_Name: WideString;
begin
  Result := FParam.Name;
end;

function TAdapterHiddenFieldWrapper.Get_Value: WideString;
begin
  Result := FParam.Value;
end;

{ TAdapterValuesListWrapper }

function TAdapterValuesListWrapper.FindObject(
  const AName: string): TObject;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  if Supports(Obj, IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
  else
    Result := nil;
end;

function TAdapterValuesListWrapper.Get_Image: IAdapterImageWrapper;
var
  Intf: IValuesListAdapter;
  AdapterImage: IInterface;
begin
  if Supports(Obj, IValuesListAdapter, Intf) then
  begin
    AdapterImage := Intf.GetListImage;
    if AdapterImage <> nil then
    begin
      Result := TAdapterImageWrapper.Create(AdapterImage);
      exit;
    end;
  end;
  Result := nil;
end;

function TAdapterValuesListWrapper.Get_Records: IAdapterRecordsWrapper;
begin
  Result := TAdapterRecordsWrapper.Create(Obj);
end;

function TAdapterValuesListWrapper.Get_Value: OleVariant;
var
  Intf: IValuesListAdapter;
begin
  if Supports(Obj, IValuesListAdapter, Intf) then
    Result := Intf.GetListValue
  else
    Result := Unassigned;
end;

function TAdapterValuesListWrapper.Get_ValueName: WideString;
var
  Intf: IValuesListAdapter;
begin
  if Supports(Obj, IValuesListAdapter, Intf) then
    Result := Intf.GetListName
  else
    Result := '';
end;

function TAdapterValuesListWrapper.ImageOfValue(
  Value: OleVariant): IAdapterImageWrapper;
var
  Intf: IValuesListAdapter;
  AdapterImage: IInterface;
begin
  if Supports(Obj, IValuesListAdapter, Intf) then
  begin
    AdapterImage := Intf.GetListImageOfValue(Value);
    if AdapterImage <> nil then
    begin
      Result := TAdapterImageWrapper.Create(AdapterImage);
      exit;
    end;
  end;
  Result := nil;

end;

function TAdapterValuesListWrapper.NameOfValue(Value: OleVariant): WideString;
var
  Intf: IValuesListAdapter;
begin
  if Supports(Obj, IValuesListAdapter, Intf) then
    Result := Intf.GetListNameOfValue(Value)
  else
    Result := '';
end;

{ TBaseAdapterWrapper }

function TBaseAdapterWrapper.Get_Actions: IComponentsWrapper;
var
  GetIntf: IGetAdapterActions;
begin
  if FActions = nil then
    if Supports(Obj, IGetAdapterActions, GetIntf) then
      FActions := TAdapterComponentsWrapper.Create(GetIntf.GetAdapterActions);
  Result := FActions;
end;

function TBaseAdapterWrapper.Get_ClassName_: WideString;
begin
  Result := Obj.ClassName;
end;

function TBaseAdapterWrapper.Get_Fields: IComponentsWrapper;
var
  GetIntf: IGetAdapterFields;
begin
  if FFields = nil then
    if Supports(Obj, IGetAdapterFields, GetIntf) then
      FFields := TAdapterComponentsWrapper.Create(GetIntf.GetAdapterFields);
  Result := FFields;
end;

function TBaseAdapterWrapper.Get_Name_: WideString;
var
  Intf: IWebVariableName;
begin
  if Supports(Obj, IWebVariableName, Intf) then
    Result := Intf.VariableName
  else
    Result := '';
end;

{ TBaseRecordsAdapterWrapper }

function TBaseRecordsAdapterWrapper.Get_Records: AdapterRecordsWrapper;
begin
  if Obj <> nil then
    Result := TAdapterRecordsWrapper.Create(Obj)
  else
    Result := nil;
end;

{ TAdapterImageWrapper }

constructor TAdapterImageWrapper.Create(AIntf: IInterface);
begin
  inherited Create;
  FIntf := AIntf;
end;

function TAdapterImageWrapper.Get_AsHREF: WideString;
var
  Dispatcher: IAdapterDispatcher;
  WebImageHREF: IWebImageHREF;
  S: string;
  CompRef: IInterfaceComponentReference;
begin
  if Supports(FIntf, IWebImageHREF, WebImageHREF) then
    if WebImageHREF.WebImageHREF(S) then
    begin
      Result := S;
      Exit;
    end;
  if Supports(FIntf, IInterfaceComponentReference, CompRef) then
    Dispatcher := FindAdapterDispatcher(CompRef.GetComponent)
  else
    Assert(False); // Can't find component
  if Dispatcher <> nil then
    Result := Dispatcher.EncodeAdapterItemRequestAsHREF(FIntf, [])
  else
  begin
    Result := sUnknown;
  end;
end;

{ TWebApplicationWrapper }

constructor TWebApplicationWrapper.Create(
  AContext: IScriptContext);
begin
  FContext := AContext;
  if ApplicationInfo <> nil then
    inherited Create(ApplicationInfo.ApplicationAdapter)
  else
    inherited Create(nil);
end;

function TWebApplicationWrapper.ApplicationInfo: IWebApplicationInfo;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FApplicationInfo) then
  begin
    if WebContext <> nil then
    begin
      AppModule := WebContext.FindApplicationModule(FContext.WebModuleContext);
      if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
        FApplicationInfo := GetIntf.WebApplicationInfo;
    end;
  end;
  Result := FApplicationInfo;
end;

function TWebApplicationWrapper.Get_Title: WideString;
begin
  if ApplicationInfo <> nil then
    Result := ApplicationInfo.ApplicationTitle
  else
    Result := '';
end;

function TWebApplicationWrapper.Get_Designing: WordBool;
begin
  if FContext.WebModuleContext is TComponent then
    Result := csDesigning in TComponent(FContext.WebModuleContext).ComponentState
  else
    Result := False;
end;

function TWebApplicationWrapper.Get_ModulePath: WideString;
begin
  Result := ExtractFilePath(Get_ModuleFileName)
end;

function TWebApplicationWrapper.Get_ModuleFileName: WideString;
begin
  if Assigned(GetModuleFileNameProc) then
    Result := GetModuleFileNameProc
  else
    Result := '';
end;

function TWebApplicationWrapper.QualifyFileName(
  const FileName: WideString): WideString;
begin
  Result := WebComp.QualifyFileName(FileName)
end;

{ TWebEndUserWrapper }

constructor TWebEndUserWrapper.Create(
  AContext: IScriptContext);
begin
  FContext := AContext;
  if EndUser <> nil then
    inherited Create(EndUser.EndUserAdapter)
  else
    inherited Create(nil);
end;

function TWebEndUserWrapper.EndUser: IWebEndUser;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FEndUser) then
  begin
    if WebContext <> nil then
    begin
      AppModule := WebContext.FindApplicationModule(FContext.WebModuleContext);
      if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
        FEndUser := GetIntf.GetWebEndUser;
    end;
  end;
  Result := FEndUser;
end;

function TWebEndUserWrapper.Get_DisplayName: WideString;
begin
  if EndUser <> nil then
    Result := EndUser.DisplayName
  else
    Result := '';
end;

function TWebEndUserWrapper.Get_LoggedIn: WordBool;
begin
  if EndUser <> nil then
    Result := EndUser.LoggedIn
  else
    Result := False;
end;

function TWebEndUserWrapper.Get_LoginFormAction: IAdapterActionWrapper;
var
  Obj: TComponent;
begin
  Result := nil;
  if EndUser <> nil then
  begin
    Obj := EndUser.LoginFormAction;
    if Obj <> nil then
      Result := TAdapterActionWrapper.Create(Obj);
  end;
end;

function TWebEndUserWrapper.Get_LogoutAction: IAdapterActionWrapper;
var
  Obj: TComponent;
begin
  Result := nil;
  if EndUser <> nil then
  begin
    Obj := EndUser.LogoutAction;
    if Obj <> nil then
      Result := TAdapterActionWrapper.Create(Obj);
  end;
end;

{ TAdapterFieldValuesWrapper }

function TAdapterFieldValuesWrapper.FindObject(
  const AName: string): TObject;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  if Supports(Obj, IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
  else
    Result := nil;
end;

function TAdapterFieldValuesWrapper.Get_Records: IAdapterRecordsWrapper;
begin
  Result := TAdapterRecordsWrapper.Create(Obj);
end;

function TAdapterFieldValuesWrapper.Get_Value: OleVariant;
var
  FieldIntf: IWebGetFieldValues;
  AdapterIntf: IFieldValuesAdapter;
begin
  if Supports(Obj, IFieldValuesAdapter, AdapterIntf) and
    Supports(AdapterIntf.GetField, IWebGetFieldValues, FieldIntf) then
    Result := FieldIntf.GetCurrentValue
  else
    Result := Unassigned;
end;

function TAdapterFieldValuesWrapper.HasValue(Value: OleVariant): WordBool;
var
  FieldIntf: IWebGetFieldValues;
  AdapterIntf: IFieldValuesAdapter;
begin
  if Supports(Obj, IFieldValuesAdapter, AdapterIntf) and
    Supports(AdapterIntf.GetField, IWebGetFieldValues, FieldIntf) then
    Result := FieldIntf.HasValue(Value)
  else
    Result := False;
end;

{ TImageProducerWrapper }

function TImageProducerWrapper.GetDisplayStyle(
  const Object_: IUnknown): WideString;
var
  ComponentReference: IInterfaceComponentReference;
  ImageProducer: IActionImageProducer;
begin
  Result := '';
  if Supports(Obj, IActionImageProducer, ImageProducer) then
    if Supports(Object_, IInterfaceComponentReference, ComponentReference) then
      Result := ImageProducer.GetDisplayStyle(ComponentReference.GetComponent)
    else
      Assert(False); // Expect support for IInterfaceComponentReference
end;

function TImageProducerWrapper.GetEventImage(const Object_: IUnknown;
  const Event, Caption: WideString): IAdapterImageWrapper;
var
  ComponentReference: IInterfaceComponentReference;
  ImageProducer: IActionImageProducer;
  Intf: IInterface;
begin
  Result := nil;
  if Supports(Obj, IActionImageProducer, ImageProducer) then
    if Supports(Object_, IInterfaceComponentReference, ComponentReference) then
    begin
      Intf := ImageProducer.GetAdapterEventImage(ComponentReference.GetComponent, Event, Caption);
      if Intf <> nil then
        Result := TAdapterImageWrapper.Create(Intf);
    end
    else
      Assert(False); // Expect support for IInterfaceComponentReference
end;

function TImageProducerWrapper.GetImage(const Object_: IUnknown;
  const Caption: WideString): IAdapterImageWrapper;
var
  ImageProducer: IImageProducer;
  ComponentReference: IInterfaceComponentReference;
begin
  if Supports(Obj, IImageProducer, ImageProducer) then
  begin
    if Supports(Object_, IInterfaceComponentReference, ComponentReference) then
      Result := TAdapterImageWrapper.Create(ImageProducer.GetAdapterImage(ComponentReference.GetComponent, Caption))
    else
      Assert(False); // Expect support for IInterfaceComponentReference
  end;
end;

{ TNotifier }

constructor TNotifier.Create(ANotify: TNotificationProc;
  AComponent: TComponent);
begin
  inherited Create(nil);
  FNotify := ANotify;
  FComponent := AComponent;
  AComponent.FreeNotification(Self);
end;

destructor TNotifier.Destroy;
begin
  FComponent.RemoveFreeNotification(Self);
  inherited;
end;

procedure TNotifier.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if Assigned(FNotify) then
    FNotify(AComponent, Operation);
  inherited;
end;

initialization
  InitScriptComServer;
  ScriptComServer.RegisterScriptClass(TAdapterWrapper, Class_AdapterWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterFieldWrapper, Class_AdapterFieldWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterActionWrapper, Class_AdapterActionWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterComponentsWrapper, Class_ComponentsWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterRecordEnumerator, Class_EnumVariantWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterRecordWrapper, Class_AdapterRecordWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterRecordsWrapper, Class_AdapterRecordsWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterErrorEnumerator, Class_EnumVariantWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterErrorWrapper, Class_AdapterErrorWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterErrorsWrapper, Class_AdapterErrorsWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterFieldValuesWrapper, Class_AdapterFieldValuesWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterValuesListWrapper, Class_AdapterValuesListWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterImageWrapper, Class_AdapterImageWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterImageWrapper, Class_AdapterImageWrapper);
  ScriptComServer.RegisterScriptClass(TImageProducerWrapper, Class_ImageProducerWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterHiddenFieldsWrapper, Class_AdapterHiddenFieldsWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterHiddenFieldWrapper, Class_AdapterHiddenFieldWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterHiddenFieldsEnumerator, Class_EnumVariantWrapper);
  ScriptComServer.RegisterScriptClass(TAdapterActionArrayWrapper, Class_AdapterActionArrayWrapper);
end.
