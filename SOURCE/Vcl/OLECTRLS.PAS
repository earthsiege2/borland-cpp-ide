
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit OleCtrls;

{$R-,T-,H+,X+}

interface

uses Windows, Messages, ActiveX, SysUtils, Classes, Controls, Forms,
  Menus, Graphics, ComObj, AxCtrls;

type

  TOleControl = class;

  TEventDispatch = class(TObject, IUnknown, IDispatch)
  private
    FControl: TOleControl;
  protected    
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
    property Control: TOleControl read FControl;
  public
    constructor Create(Control: TOleControl);
  end;

  TOleEnum = ActiveX.TOleEnum;
  {$NODEFINE TOleEnum}

  TEnumValue = record
    Value: Longint;
    Ident: string;
  end;

  PEnumValueList = ^TEnumValueList;
  TEnumValueList = array[0..32767] of TEnumValue;

  TEnumPropDesc = class
  private
    FDispID: Integer;
    FValueCount: Integer;
    FValues: PEnumValueList;
  public
    constructor Create(DispID, ValueCount: Integer;
      const TypeInfo: ITypeInfo);
    destructor Destroy; override;
    procedure GetStrings(Proc: TGetStrProc);
    function StringToValue(const S: string): Integer;
    function ValueToString(V: Integer): string;
  end;

  PControlData = ^TControlData;
  TControlData = record
    ClassID: TGUID;
    EventIID: TGUID;
    EventCount: Longint;
    EventDispIDs: Pointer;
    LicenseKey: Pointer;
    Flags: DWORD;
    Version: Integer;
    FontCount: Integer;
    FontIDs: PDispIDList;
    PictureCount: Integer;
    PictureIDs: PDispIDList;
    Reserved: Integer;
    InstanceCount: Integer;
    EnumPropDescs: TList;
  end;

  PControlData2 = ^TControlData2;
  TControlData2 = record
    ClassID: TGUID;
    EventIID: TGUID;
    EventCount: Longint;
    EventDispIDs: Pointer;
    LicenseKey: Pointer;
    Flags: DWORD;
    Version: Integer;
    FontCount: Integer;
    FontIDs: PDispIDList;
    PictureCount: Integer;
    PictureIDs: PDispIDList;
    Reserved: Integer;
    InstanceCount: Integer;
    EnumPropDescs: TList;
    FirstEventOfs: Cardinal;
  end;

  TOleControl = class(TWinControl, IUnknown, IOleClientSite,
    IOleControlSite, IOleInPlaceSite, IOleInPlaceFrame, IDispatch,
    IPropertyNotifySink, ISimpleFrameSite)
  private
    FControlData: PControlData;
    FRefCount: Longint;
    FEventDispatch: TEventDispatch;
    FObjectData: HGlobal;
    FOleObject: IOleObject;
    FPersistStream: IPersistStreamInit;
    FOleControl: IOleControl;
    FControlDispatch: IDispatch;
    FPropBrowsing: IPerPropertyBrowsing;
    FOleInPlaceObject: IOleInPlaceObject;
    FOleInPlaceActiveObject: IOleInPlaceActiveObject;
    FPropConnection: Longint;
    FEventsConnection: Longint;
    FMiscStatus: Longint;
    FFonts: TList;
    FPictures: TList;
    FUpdatingPictures: Boolean;
    FUpdatingColor: Boolean;
    FUpdatingFont: Boolean;
    FUpdatingEnabled: Boolean;
    { TOleControl }
    procedure CreateControl;
    procedure CreateEnumPropDescs;
    procedure CreateInstance;
    procedure CreateStorage;
    procedure DesignModified;
    procedure DestroyControl;
    procedure DestroyEnumPropDescs;
    procedure DestroyStorage;
    procedure GetEventMethod(DispID: TDispID; var Method: TMethod);
    function GetMainMenu: TMainMenu;
    function GetOleObject: Variant;
    function GetDefaultDispatch: IDispatch;
    procedure HookControlWndProc;
    procedure InvokeEvent(DispID: TDispID; var Params: TDispParams);
    procedure ReadData(Stream: TStream);
    procedure SetUIActive(Active: Boolean);
    procedure StandardEvent(DispID: TDispID; var Params: TDispParams);
    procedure WriteData(Stream: TStream);
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
    procedure CMDocWindowActivate(var Message: TMessage); message CM_DOCWINDOWACTIVATE;
    procedure CMColorChanged(var Message: TMessage); message CM_COLORCHANGED;
    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMFontChanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure CMDialogKey(var Message: TMessage); message CM_DIALOGKEY;
    procedure CMUIActivate(var Message: TMessage); message CM_UIACTIVATE;
    procedure CMUIDeactivate(var Message: TMessage); message CM_UIDEACTIVATE;
    procedure D2InvokeEvent(DispID: TDispID; var Params: TDispParams);
  protected
    FEvents: Integer;
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; override;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IOleClientSite }
    function SaveObject: HResult; stdcall;
    function GetMoniker(dwAssign: Longint; dwWhichMoniker: Longint;
      out mk: IMoniker): HResult; stdcall;
    function GetContainer(out container: IOleContainer): HResult; stdcall;
    function ShowObject: HResult; stdcall;
    function OnShowWindow(fShow: BOOL): HResult; stdcall;
    function RequestNewObjectLayout: HResult; stdcall;
    { IOleControlSite }
    function OnControlInfoChanged: HResult; stdcall;
    function LockInPlaceActive(fLock: BOOL): HResult; stdcall;
    function GetExtendedControl(out disp: IDispatch): HResult; stdcall;
    function TransformCoords(var ptlHimetric: TPoint; var ptfContainer: TPointF;
      flags: Longint): HResult; stdcall;
    function IOleControlSite.TranslateAccelerator = OleControlSite_TranslateAccelerator;
    function OleControlSite_TranslateAccelerator(msg: PMsg;
      grfModifiers: Longint): HResult; stdcall;
    function OnFocus(fGotFocus: BOOL): HResult; stdcall;
    function ShowPropertyFrame: HResult; stdcall;
    { IOleWindow }
    function ContextSensitiveHelp(fEnterMode: BOOL): HResult; stdcall;
    { IOleInPlaceSite }
    function IOleInPlaceSite.GetWindow = OleInPlaceSite_GetWindow;
    function OleInPlaceSite_GetWindow(out wnd: HWnd): HResult; stdcall;
    function CanInPlaceActivate: HResult; stdcall;
    function OnInPlaceActivate: HResult; stdcall;
    function OnUIActivate: HResult; stdcall;
    function GetWindowContext(out frame: IOleInPlaceFrame;
      out doc: IOleInPlaceUIWindow; out rcPosRect: TRect;
      out rcClipRect: TRect; out frameInfo: TOleInPlaceFrameInfo): HResult;
      stdcall;
    function Scroll(scrollExtent: TPoint): HResult; stdcall;
    function OnUIDeactivate(fUndoable: BOOL): HResult; stdcall;
    function OnInPlaceDeactivate: HResult; stdcall;
    function DiscardUndoState: HResult; stdcall;
    function DeactivateAndUndo: HResult; stdcall;
    function OnPosRectChange(const rcPosRect: TRect): HResult; stdcall;
    { IOleInPlaceUIWindow }
    function GetBorder(out rectBorder: TRect): HResult; stdcall;
    function RequestBorderSpace(const borderwidths: TRect): HResult; stdcall;
    function SetBorderSpace(pborderwidths: PRect): HResult; stdcall;
    function SetActiveObject(const activeObject: IOleInPlaceActiveObject;
      pszObjName: POleStr): HResult; stdcall;
    { IOleInPlaceFrame }
    function IOleInPlaceFrame.GetWindow = OleInPlaceFrame_GetWindow;
    function OleInPlaceFrame_GetWindow(out wnd: HWnd): HResult; stdcall;
    function InsertMenus(hmenuShared: HMenu;
      var menuWidths: TOleMenuGroupWidths): HResult; stdcall;
    function SetMenu(hmenuShared: HMenu; holemenu: HMenu;
      hwndActiveObject: HWnd): HResult; stdcall;
    function RemoveMenus(hmenuShared: HMenu): HResult; stdcall;
    function SetStatusText(pszStatusText: POleStr): HResult; stdcall;
    function EnableModeless(fEnable: BOOL): HResult; stdcall;
    function IOleInPlaceFrame.TranslateAccelerator = OleInPlaceFrame_TranslateAccelerator;
    function OleInPlaceFrame_TranslateAccelerator(var msg: TMsg;
      wID: Word): HResult; stdcall;
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
    { ISimpleFrameSite }
    function PreMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
      out res: Integer; out Cookie: Longint): HResult; stdcall;
    function PostMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
      out res: Integer; Cookie: Longint): HResult; stdcall;
    { TOleControl }
    procedure CreateWnd; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DestroyWindowHandle; override;
    function GetByteProp(Index: Integer): Byte;
    function GetColorProp(Index: Integer): TColor;
    function GetTColorProp(Index: Integer): TColor;
    function GetCompProp(Index: Integer): Comp;
    function GetCurrencyProp(Index: Integer): Currency;
    function GetDoubleProp(Index: Integer): Double;
    function GetIDispatchProp(Index: Integer): IDispatch;
    function GetIntegerProp(Index: Integer): Integer;
    function GetIUnknownProp(Index: Integer): IUnknown;
    function GetWordBoolProp(Index: Integer): WordBool;
    function GetTDateTimeProp(Index: Integer): TDateTime;
    function GetTFontProp(Index: Integer): TFont;
    function GetOleBoolProp(Index: Integer): TOleBool;
    function GetOleDateProp(Index: Integer): TOleDate;
    function GetOleEnumProp(Index: Integer): TOleEnum;
    function GetTOleEnumProp(Index: Integer): TOleEnum;
    function GetOleVariantProp(Index: Integer): OleVariant;
    function GetTPictureProp(Index: Integer): TPicture;
    procedure GetProperty(Index: Integer; var Value: TVarData);
    function GetShortIntProp(Index: Integer): ShortInt;
    function GetSingleProp(Index: Integer): Single;
    function GetSmallintProp(Index: Integer): Smallint;
    function GetStringProp(Index: Integer): string;
    function GetVariantProp(Index: Integer): Variant;
    function GetWideStringProp(Index: Integer): WideString;
    function GetWordProp(Index: Integer): Word;
    procedure InitControlData; virtual; abstract;
    procedure InitControlInterface(const Obj: IUnknown); virtual;
    procedure InvokeMethod(const DispInfo; Result: Pointer);
    function PaletteChanged(Foreground: Boolean): Boolean; override;
    procedure PictureChanged(Sender: TObject);
    procedure SetByteProp(Index: Integer; Value: Byte);
    procedure SetColorProp(Index: Integer; Value: TColor);
    procedure SetTColorProp(Index: Integer; Value: TColor);
    procedure SetCompProp(Index: Integer; const Value: Comp);
    procedure SetCurrencyProp(Index: Integer; const Value: Currency);
    procedure SetDoubleProp(Index: Integer; const Value: Double);
    procedure SetIDispatchProp(Index: Integer; const Value: IDispatch);
    procedure SetIntegerProp(Index: Integer; Value: Integer);
    procedure SetIUnknownProp(Index: Integer; const Value: IUnknown);
    procedure SetName(const Value: TComponentName); override;
    procedure SetWordBoolProp(Index: Integer; Value: WordBool);
    procedure SetTDateTimeProp(Index: Integer; const Value: TDateTime);
    procedure SetTFontProp(Index: Integer; Value: TFont);
    procedure SetOleBoolProp(Index: Integer; Value: TOleBool);
    procedure SetOleDateProp(Index: Integer; const Value: TOleDate);
    procedure SetOleEnumProp(Index: Integer; Value: TOleEnum);
    procedure SetTOleEnumProp(Index: Integer; Value: TOleEnum);
    procedure SetOleVariantProp(Index: Integer; const Value: OleVariant);
    procedure SetParent(AParent: TWinControl); override;
    procedure SetTPictureProp(Index: Integer;  Value: TPicture);
    procedure SetProperty(Index: Integer; const Value: TVarData);
    procedure SetShortIntProp(Index: Integer; Value: Shortint);
    procedure SetSingleProp(Index: Integer; const Value: Single);
    procedure SetSmallintProp(Index: Integer; Value: Smallint);
    procedure SetStringProp(Index: Integer; const Value: string);
    procedure SetVariantProp(Index: Integer; const Value: Variant);
    procedure SetWideStringProp(Index: Integer; const Value: WideString);
    procedure SetWordProp(Index: Integer; Value: Word);
    procedure WndProc(var Message: TMessage); override;
    property ControlData: PControlData read FControlData write FControlData;
    { IPropertyNotifySink }
    function OnChanged(dispid: TDispID): HResult; virtual; stdcall;
    function OnRequestEdit(dispid: TDispID): HResult; virtual; stdcall;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BrowseProperties;
    procedure DefaultHandler(var Message); override;
    procedure DoObjectVerb(Verb: Integer);
    function GetEnumPropDesc(DispID: Integer): TEnumPropDesc;
    function GetHelpContext(Member: string; var HelpCtx: Integer;
      var HelpFile: string): Boolean;
    procedure GetObjectVerbs(List: TStrings);
    function GetPropDisplayString(DispID: Integer): string;
    procedure GetPropDisplayStrings(DispID: Integer; List: TStrings);
    function IsCustomProperty(DispID: Integer): Boolean;
    function IsPropPageProperty(DispID: Integer): Boolean;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure SetPropDisplayString(DispID: Integer; const Value: string);
    procedure ShowAboutBox;
    property OleObject: Variant read GetOleObject;
    property PerPropBrowsing: IPerPropertyBrowsing read FPropBrowsing;
    property DefaultDispatch: IDispatch read GetDefaultDispatch;
    property TabStop default True;
  end;

  EOleCtrlError = class(Exception);

function FontToOleFont(Font: TFont): Variant;
procedure OleFontToFont(const OleFont: Variant; Font: TFont);

implementation

uses OleConst;

const
  OCM_BASE = $2000;

{ Control flags }

const
  cfBackColor = $00000001;
  cfForeColor = $00000002;
  cfFont      = $00000004;
  cfEnabled   = $00000008;
  cfCaption   = $00000010;
  cfText      = $00000020;

const
  MaxDispArgs = 32;

type

  PDispInfo = ^TDispInfo;
  TDispInfo = packed record
    DispID: TDispID;
    ResType: Byte;
    CallDesc: TCallDesc;
  end;

  TArgKind = (akDWord, akSingle, akDouble);

  PEventArg = ^TEventArg;
  TEventArg = record
    Kind: TArgKind;
    Data: array[0..1] of Integer;
  end;

  TEventInfo = record
    Method: TMethod;
    Sender: TObject;
    ArgCount: Integer;
    Args: array[0..MaxDispArgs - 1] of TEventArg;
  end;

function FontToOleFont(Font: TFont): Variant;
var
  Temp: IFontDisp;
begin
  GetOleFont(Font, Temp);
  Result := Temp;
end;

procedure OleFontToFont(const OleFont: Variant; Font: TFont);
begin
  SetOleFont(Font, IUnknown(OleFont) as IFontDisp);
end;

function StringToVarOleStr(const S: string): Variant;
begin
  VarClear(Result);
  TVarData(Result).VOleStr := StringToOleStr(S);
  TVarData(Result).VType := varOleStr;
end;

{ TEventDispatch }

constructor TEventDispatch.Create(Control: TOleControl);
begin
  FControl := Control;
end;

{ TEventDispatch.IUnknown }

function TEventDispatch.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then
  begin
    Result := S_OK;
    Exit;
  end;
  if IsEqualIID(IID, FControl.FControlData^.EventIID) then
  begin
    GetInterface(IDispatch, Obj);
    Result := S_OK;
    Exit;
  end;
  Result := E_NOINTERFACE;
end;

function TEventDispatch._AddRef: Integer;
begin
  Result := FControl._AddRef;
end;

function TEventDispatch._Release: Integer;
begin
  Result := FControl._Release;
end;

{ TEventDispatch.IDispatch }

function TEventDispatch.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Count := 0;
  Result := S_OK;
end;

function TEventDispatch.GetTypeInfo(Index, LocaleID: Integer;
  out TypeInfo): HResult;
begin
  Pointer(TypeInfo) := nil;
  Result := E_NOTIMPL;
end;

function TEventDispatch.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TEventDispatch.Invoke(DispID: Integer; const IID: TGUID;
  LocaleID: Integer; Flags: Word; var Params;
  VarResult, ExcepInfo, ArgErr: Pointer): HResult;
begin
  if (DispID >= DISPID_MOUSEUP) and (DispID <= DISPID_CLICK) then
    FControl.StandardEvent(DispID, TDispParams(Params)) else
    FControl.InvokeEvent(DispID, TDispParams(Params));
  Result := S_OK;
end;

{ TEnumPropDesc }

constructor TEnumPropDesc.Create(DispID, ValueCount: Integer;
  const TypeInfo: ITypeInfo);
var
  I: Integer;
  VarDesc: PVarDesc;
  Name: WideString;
begin
  FDispID := DispID;
  FValueCount := ValueCount;
  FValues := AllocMem(ValueCount * SizeOf(TEnumValue));
  for I := 0 to ValueCount - 1 do
  begin
    OleCheck(TypeInfo.GetVarDesc(I, VarDesc));
    try
      OleCheck(TypeInfo.GetDocumentation(VarDesc^.memid, @Name,
        nil, nil, nil));
      with FValues^[I] do
      begin
        Value := TVarData(VarDesc^.lpVarValue^).VInteger;
        Ident := Name;
        while (Length(Ident) > 1) and (Ident[1] = '_') do
          Delete(Ident, 1, 1);
      end;
    finally
      TypeInfo.ReleaseVarDesc(VarDesc);
    end;
  end;
end;

destructor TEnumPropDesc.Destroy;
begin
  if FValues <> nil then
  begin
    Finalize(FValues^[0], FValueCount);
    FreeMem(FValues, FValueCount * SizeOf(TEnumValue));
  end;
end;

procedure TEnumPropDesc.GetStrings(Proc: TGetStrProc);
var
  I: Integer;
begin
  for I := 0 to FValueCount - 1 do
    with FValues^[I] do Proc(Format('%d - %s', [Value, Ident]));
end;

function TEnumPropDesc.StringToValue(const S: string): Integer;
var
  I: Integer;
begin
  I := 1;
  while (I <= Length(S)) and (S[I] in ['0'..'9', '-']) do Inc(I);
  if I > 1 then
  begin
    Result := StrToInt(Copy(S, 1, I - 1));
    for I := 0 to FValueCount - 1 do
      if Result = FValues^[I].Value then Exit;
  end else
    for I := 0 to FValueCount - 1 do
      with FValues^[I] do
        if AnsiCompareText(S, Ident) = 0 then
        begin
          Result := Value;
          Exit;
        end;
  raise EOleError.CreateResFmt(@SBadPropValue, [S]);
end;

function TEnumPropDesc.ValueToString(V: Integer): string;
var
  I: Integer;
begin
  for I := 0 to FValueCount - 1 do
    with FValues^[I] do
      if V = Value then
      begin
        Result := Format('%d - %s', [Value, Ident]);
        Exit;
      end;
  Result := IntToStr(V);
end;

{ TOleControl }

const
  // The following flags may be or'd into the TControlData.Reserved field to override
  // default behaviors.

  // cdForceSetClientSite:
  //   Call SetClientSite early (in constructor) regardless of misc status flags
  cdForceSetClientSite = 1;

  // cdDeferSetClientSite:
  //   Don't call SetClientSite early.  Takes precedence over cdForceSetClientSite and misc status flags
  cdDeferSetClientSite = 2;

constructor TOleControl.Create(AOwner: TComponent);
var
  I: Integer;
begin
  inherited Create(AOwner);
  Include(FComponentStyle, csCheckPropAvail);
  InitControlData;
  Inc(FControlData^.InstanceCount);
  if FControlData^.FontCount > 0 then
  begin
    FFonts := TList.Create;
    FFonts.Count := FControlData^.FontCount;
    for I := 0 to FFonts.Count-1 do
      FFonts[I] := TFont.Create;
  end;
  if FControlData^.PictureCount > 0 then
  begin
    FPictures := TList.Create;
    FPictures.Count := FControlData^.PictureCount;
    for I := 0 to FPictures.Count-1 do
    begin
      FPictures[I] := TPicture.Create;
      TPicture(FPictures[I]).OnChange := PictureChanged;
    end;
  end;
  FEventDispatch := TEventDispatch.Create(Self);
  CreateInstance;
  InitControlInterface(FOleObject);
  OleCheck(FOleObject.GetMiscStatus(DVASPECT_CONTENT, FMiscStatus));
  if (FControlData^.Reserved and cdDeferSetClientSite) = 0 then
    if ((FMiscStatus and OLEMISC_SETCLIENTSITEFIRST) <> 0) or
      ((FControlData^.Reserved and cdForceSetClientSite) <> 0) then
      OleCheck(FOleObject.SetClientSite(Self));
  OleCheck(FOleObject.QueryInterface(IPersistStreamInit, FPersistStream));
  if FMiscStatus and OLEMISC_INVISIBLEATRUNTIME <> 0 then
    Visible := False;
  if FMiscStatus and OLEMISC_SIMPLEFRAME <> 0 then
    ControlStyle := [csAcceptsControls, csDoubleClicks, csNoStdEvents] else
    ControlStyle := [csDoubleClicks, csNoStdEvents];
  TabStop := FMiscStatus and (OLEMISC_ACTSLIKELABEL or
    OLEMISC_NOUIACTIVATE) = 0;
  OleCheck(RequestNewObjectLayout);
end;

destructor TOleControl.Destroy;

  procedure FreeList(var L: TList);
  var
    I: Integer;
  begin
    if L <> nil then
    begin
      for I := 0 to L.Count-1 do
        TObject(L[I]).Free;
      L.Free;
      L := nil;
    end;
  end;

begin
  SetUIActive(False);
  if FOleObject <> nil then FOleObject.Close(OLECLOSE_NOSAVE);
  DestroyControl;
  DestroyStorage;
  FPersistStream := nil;
  if FOleObject <> nil then FOleObject.SetClientSite(nil);
  FOleObject := nil;
  FEventDispatch.Free;
  FreeList(FFonts);
  FreeList(FPictures);
  Dec(FControlData^.InstanceCount);
  if FControlData^.InstanceCount = 0 then DestroyEnumPropDescs;
  inherited Destroy;
end;

procedure TOleControl.BrowseProperties;
begin
  DoObjectVerb(OLEIVERB_PROPERTIES);
end;

procedure TOleControl.CreateControl;
var
  Stream: IStream;
  CS: IOleClientSite;
  X: Integer;
begin
  if FOleControl = nil then
    try
      try  // work around ATL bug
        X := FOleObject.GetClientSite(CS);
      except
        X := -1;
      end;
      if (X <> 0) or (CS = nil) then
        OleCheck(FOleObject.SetClientSite(Self));
      if FObjectData = 0 then OleCheck(FPersistStream.InitNew) else
      begin
        OleCheck(CreateStreamOnHGlobal(FObjectData, False, Stream));
        OleCheck(FPersistStream.Load(Stream));
        DestroyStorage;
      end;
      OleCheck(FOleObject.QueryInterface(IOleControl, FOleControl));
      OleCheck(FOleObject.QueryInterface(IDispatch, FControlDispatch));
      FOleObject.QueryInterface(IPerPropertyBrowsing, FPropBrowsing);
      InterfaceConnect(FOleObject, IPropertyNotifySink,
        Self, FPropConnection);
      InterfaceConnect(FOleObject, FControlData^.EventIID,
        FEventDispatch, FEventsConnection);
      if FControlData^.Flags and cfBackColor <> 0 then
        OnChanged(DISPID_BACKCOLOR);
      if FControlData^.Flags and cfEnabled <> 0 then
        OnChanged(DISPID_ENABLED);
      if FControlData^.Flags and cfFont <> 0 then
        OnChanged(DISPID_FONT);
      if FControlData^.Flags and cfForeColor <> 0 then
        OnChanged(DISPID_FORECOLOR);
      FOleControl.OnAmbientPropertyChange(DISPID_UNKNOWN);
      RequestNewObjectLayout;
    except
      DestroyControl;
      raise;
    end;
end;

procedure TOleControl.CreateEnumPropDescs;

  function FindMember(DispId: Integer): Boolean;
  var
    I: Integer;
  begin
    for I := 0 to FControlData^.EnumPropDescs.Count - 1 do
      if TEnumPropDesc(FControlData^.EnumPropDescs).FDispID = DispID then
      begin
        Result := True;
        Exit;
      end;
    Result := False;
  end;

  procedure CreateEnum(TypeDesc: TTypeDesc; const TypeInfo: ITypeInfo;
    DispId: Integer);
  var
    RefInfo: ITypeInfo;
    RefAttr: PTypeAttr;
  begin
    if TypeDesc.vt <> VT_USERDEFINED then Exit;
    OleCheck(TypeInfo.GetRefTypeInfo(TypeDesc.hreftype, RefInfo));
    OleCheck(RefInfo.GetTypeAttr(RefAttr));
    try
      if RefAttr^.typekind = TKIND_ENUM then
        FControlData^.EnumPropDescs.Expand.Add(
          TEnumPropDesc.Create(Dispid, RefAttr^.cVars, RefInfo));
    finally
      RefInfo.ReleaseTypeAttr(RefAttr);
    end;
  end;

  procedure ProcessTypeInfo(const TypeInfo: ITypeInfo);
  var
    I: Integer;
    RefInfo: ITypeInfo;
    TypeAttr: PTypeAttr;
    VarDesc: PVarDesc;
    FuncDesc: PFuncDesc;
    RefType: HRefType;
  begin
    OleCheck(TypeInfo.GetTypeAttr(TypeAttr));
    try
      if IsEqualGUID(TypeAttr^.guid, IDispatch) then Exit;
      if ((TypeAttr.typekind = TKIND_INTERFACE) or
        (TypeAttr.wTypeFlags and TYPEFLAG_FDUAL <> 0)) and
        (TypeAttr.wTypeFlags and TYPEFLAG_FNONEXTENSIBLE <> 0) then
      begin
        OleCheck(TypeInfo.GetRefTypeOfImplType(0, RefType));
        OleCheck(TypeInfo.GetRefTypeInfo(RefType, RefInfo));
        ProcessTypeInfo(RefInfo);
      end;
      for I := 0 to TypeAttr^.cVars - 1 do
      begin
        OleCheck(TypeInfo.GetVarDesc(I, VarDesc));
        try
          CreateEnum(VarDesc^.elemdescVar.tdesc, TypeInfo, VarDesc^.memid);
        finally
          TypeInfo.ReleaseVarDesc(VarDesc);
        end;
      end;
      for I := 0 to TypeAttr^.cFuncs - 1 do
      begin
        OleCheck(TypeInfo.GetFuncDesc(I, FuncDesc));
        try
          if not FindMember(FuncDesc^.memid) then
            case FuncDesc^.invkind of
              INVOKE_PROPERTYGET:
                CreateEnum(FuncDesc^.elemdescFunc.tdesc, TypeInfo, FuncDesc^.memid);
              INVOKE_PROPERTYPUT:
                CreateEnum(FuncDesc^.lprgelemdescParam[FuncDesc.cParams - 1].tdesc,
                  TypeInfo, FuncDesc^.memid);
              INVOKE_PROPERTYPUTREF:
                if FuncDesc^.lprgelemdescParam[FuncDesc.cParams - 1].tdesc.vt = VT_PTR then
                  CreateEnum(FuncDesc^.lprgelemdescParam[FuncDesc.cParams - 1].tdesc.ptdesc^,
                    TypeInfo, FuncDesc^.memid);
            end;
        finally
          TypeInfo.ReleaseFuncDesc(FuncDesc);
        end;
      end;
    finally
      TypeInfo.ReleaseTypeAttr(TypeAttr);
    end;
  end;

var
  TypeInfo: ITypeInfo;
begin
  CreateControl;
  FControlData^.EnumPropDescs := TList.Create;
  try
    OleCheck(FControlDispatch.GetTypeInfo(0, 0, TypeInfo));
    ProcessTypeInfo(TypeInfo);
  except
    DestroyEnumPropDescs;
    raise;
  end;
end;

procedure TOleControl.CreateInstance;
var
  ClassFactory2: IClassFactory2;
  LicKeyStr: WideString;

  procedure LicenseCheck(Status: HResult; const Ident: string);
  begin
    if Status = CLASS_E_NOTLICENSED then
      raise EOleError.CreateFmt(Ident, [ClassName]);
    OleCheck(Status);
  end;

begin
  if not (csDesigning in ComponentState) and
    (FControlData^.LicenseKey <> nil) then
  begin
    OleCheck(CoGetClassObject(FControlData^.ClassID, CLSCTX_INPROC_SERVER or
      CLSCTX_LOCAL_SERVER, nil, IClassFactory2, ClassFactory2));
    LicKeyStr := PWideChar(FControlData^.LicenseKey);
    LicenseCheck(ClassFactory2.CreateInstanceLic(nil, nil, IOleObject,
      LicKeyStr, FOleObject), SInvalidLicense);
  end else
    LicenseCheck(CoCreateInstance(FControlData^.ClassID, nil,
      CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, IOleObject,
      FOleObject), SNotLicensed);
end;

procedure TOleControl.CreateStorage;
var
  Stream: IStream;
begin
  DestroyStorage;
  FObjectData := GlobalAlloc(GMEM_MOVEABLE, 0);
  if FObjectData = 0 then OutOfMemoryError;
  try
    OleCheck(CreateStreamOnHGlobal(FObjectData, False, Stream));
    OleCheck(FPersistStream.Save(Stream, True));
  except
    DestroyStorage;
    raise;
  end;
end;

procedure TOleControl.CreateWnd;
begin
  CreateControl;
  if FMiscStatus and OLEMISC_INVISIBLEATRUNTIME = 0 then
  begin
    FOleObject.DoVerb(OLEIVERB_INPLACEACTIVATE, nil, Self, 0,
      GetParentHandle, BoundsRect);
    if FOleInPlaceObject = nil then
      raise EOleError.CreateRes(@SCannotActivate);
    HookControlWndProc;
    if not Visible and IsWindowVisible(Handle) then
      ShowWindow(Handle, SW_HIDE);
  end else
    inherited CreateWnd;
end;

procedure TOleControl.DefaultHandler(var Message);
begin
  if HandleAllocated then
    with TMessage(Message) do
    begin
      if (Msg >= CN_BASE) and (Msg < CN_BASE + WM_USER) then
        Msg := Msg - (CN_BASE - OCM_BASE);
      if FMiscStatus and OLEMISC_SIMPLEFRAME = 0 then
      begin
        Result := CallWindowProc(DefWndProc, Handle, Msg, WParam, LParam);
        Exit;
      end;
    end;
  inherited DefaultHandler(Message);
end;

procedure TOleControl.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('ControlData', ReadData, WriteData, FOleObject <> nil);
end;

procedure TOleControl.DesignModified;
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if (Form <> nil) and (Form.Designer <> nil) then Form.Designer.Modified;
end;

procedure TOleControl.DestroyControl;
begin
  InterfaceDisconnect(FOleObject, FControlData^.EventIID, FEventsConnection);
  InterfaceDisconnect(FOleObject, IPropertyNotifySink, FPropConnection);
  FPropBrowsing := nil;
  FControlDispatch := nil;
  FOleControl := nil;
end;

procedure TOleControl.DestroyEnumPropDescs;
var
  I: Integer;
begin
  with FControlData^ do
    if EnumPropDescs <> nil then
    begin
      for I := 0 to EnumPropDescs.Count - 1 do
        TEnumPropDesc(EnumPropDescs[I]).Free;
      EnumPropDescs.Free;
      EnumPropDescs := nil;
    end;
end;

procedure TOleControl.DestroyStorage;
begin
  if FObjectData <> 0 then
  begin
    GlobalFree(FObjectData);
    FObjectData := 0;
  end;
end;

procedure TOleControl.DestroyWindowHandle;
begin
  if FMiscStatus and OLEMISC_INVISIBLEATRUNTIME = 0 then
  begin
    SetWindowLong(WindowHandle, GWL_WNDPROC, Longint(DefWndProc));
    if FOleObject <> nil then FOleObject.Close(OLECLOSE_NOSAVE);
    WindowHandle := 0;
  end else
    inherited DestroyWindowHandle;
end;

procedure TOleControl.DoObjectVerb(Verb: Integer);
var
  ActiveWindow: HWnd;
  WindowList: Pointer;
begin
  CreateControl;
  ActiveWindow := GetActiveWindow;
  WindowList := DisableTaskWindows(0);
  try
    OleCheck(FOleObject.DoVerb(Verb, nil, Self, 0,
      GetParentHandle, BoundsRect));
  finally
    EnableTaskWindows(WindowList);
    SetActiveWindow(ActiveWindow);
    Windows.SetFocus(ActiveWindow);
  end;
  if FPersistStream.IsDirty <> S_FALSE then DesignModified;
end;

function TOleControl.GetByteProp(Index: Integer): Byte;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetColorProp(Index: Integer): TColor;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetTColorProp(Index: Integer): TColor;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetCompProp(Index: Integer): Comp;
begin
  Result := GetDoubleProp(Index);
end;

function TOleControl.GetCurrencyProp(Index: Integer): Currency;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VCurrency;
end;

function TOleControl.GetDoubleProp(Index: Integer): Double;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VDouble;
end;

function TOleControl.GetEnumPropDesc(DispID: Integer): TEnumPropDesc;
var
  I: Integer;
begin
  with FControlData^ do
  begin
    if EnumPropDescs = nil then CreateEnumPropDescs;
    for I := 0 to EnumPropDescs.Count - 1 do
    begin
      Result := EnumPropDescs[I];
      if Result.FDispID = DispID then Exit;
    end;
    Result := nil;
  end;
end;

procedure TOleControl.GetEventMethod(DispID: TDispID; var Method: TMethod);
asm
        PUSH    EBX
        PUSH    ESI
        PUSH    EDI
        PUSH    ECX
        MOV     EBX,EAX
        MOV     ECX,[EBX].TOleControl.FControlData
        MOV     EDI,[ECX].TControlData.EventCount
        MOV     ESI,[ECX].TControlData.EventDispIDs
        XOR     EAX,EAX
        JMP     @@1
@@0:    CMP     EDX,[ESI].Integer[EAX*4]
        JE      @@2
        INC     EAX
@@1:    CMP     EAX,EDI
        JNE     @@0
        XOR     EAX,EAX
        XOR     EDX,EDX
        JMP     @@3
@@2:    PUSH    EAX
        CMP     [ECX].TControlData.Version, 401
        JB      @@2a
        MOV     EAX, [ECX].TControlData2.FirstEventOfs
        TEST    EAX, EAX
        JNE     @@2b
@@2a:   MOV     EAX, [EBX]
        CALL    TObject.ClassParent
        CALL    TObject.InstanceSize
        ADD     EAX, 7
        AND     EAX, not 7  // 8 byte alignment
@@2b:   ADD     EBX, EAX
        POP     EAX
        MOV     EDX,[EBX][EAX*8].TMethod.Data
        MOV     EAX,[EBX][EAX*8].TMethod.Code
@@3:    POP     ECX
        MOV     [ECX].TMethod.Code,EAX
        MOV     [ECX].TMethod.Data,EDX
        POP     EDI
        POP     ESI
        POP     EBX
end;

procedure Exchange(var A,B); register;
asm
  MOV   ECX, [EDX]
  XCHG  ECX, [EAX]
  MOV   [EDX], ECX
end;

{ TOleControl.GetHelpContext:  Fetch the help file name and help context
  id of the given member (property, event, or method) of the Ole Control from
  the control's ITypeInfo interfaces.  GetHelpContext returns False if
  the member name is not found in the control's ITypeInfo.
  To obtain a help context for the entire control class, pass an empty
  string as the Member name.  }

function TOleControl.GetHelpContext(Member: string;
  var HelpCtx: Integer; var HelpFile: string): Boolean;
var
  TypeInfo: ITypeInfo;
  HlpFile: TBStr;
  ImplTypes, MemberID: Integer;
  TypeAttr: PTypeAttr;

  function Find(const MemberStr: string; var TypeInfo: ITypeInfo): Boolean;
  var
    Code: HResult;
    I, Flags: Integer;
    RefType: HRefType;
    Name: TBStr;
    Temp: ITypeInfo;
  begin
    Result := False;
    Name := StringToOleStr(Member);
    try
      I := 0;
      while (I < ImplTypes) do
      begin
        OleCheck(TypeInfo.GetImplTypeFlags(I, Flags));
        if Flags and (IMPLTYPEFLAG_FDEFAULT or IMPLTYPEFLAG_FSOURCE) <> 0 then
        begin
          OleCheck(TypeInfo.GetRefTypeOfImplType(I, RefType));
          OleCheck(TypeInfo.GetRefTypeInfo(RefType, Temp));
          Code := Temp.GetIDsOfNames(@Name, 1, @MemberID);
          if Code <> DISP_E_UNKNOWNNAME then
          begin
            OleCheck(Code);
            Exchange(TypeInfo, Temp);
            Result := True;
            Break;
          end;
        end;
        Inc(I);
      end;
    finally
      SysFreeString(Name);
    end;
  end;

begin
  HelpCtx := 0;
  HelpFile := '';
  CreateControl;
  OleCheck((FOleObject as IProvideClassInfo).GetClassInfo(TypeInfo));
  MemberID := MEMBERID_NIL;
  if Length(Member) > 0 then
  begin
    OleCheck(TypeInfo.GetTypeAttr(TypeAttr));
    ImplTypes := TypeAttr.cImplTypes;
    TypeInfo.ReleaseTypeAttr(TypeAttr);
    Result := Find(Member, TypeInfo);
    if (not Result) and (Member[Length(Member)] = '_') then
    begin
      Delete(Member, Length(Member)-1, 1);
      Result := Find(Member, TypeInfo);
    end;
    if (not Result) and (Pos('On', Member) = 1) then
    begin
      Delete(Member, 1, 2);
      Result := Find(Member, TypeInfo);
    end;
    if not Result then Exit;
  end;
  OleCheck(TypeInfo.GetDocumentation(MemberID, nil, nil, @HelpCtx, @HlpFile));
  HelpFile := OleStrToString(HlpFile);
  SysFreeString(HlpFile);
  Result := True;
end;

function TOleControl.GetIDispatchProp(Index: Integer): IDispatch;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := IDispatch(Temp.VDispatch);
end;

function TOleControl.GetIntegerProp(Index: Integer): Integer;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VInteger;
end;

function TOleControl.GetIUnknownProp(Index: Integer): IUnknown;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := IUnknown(Temp.VUnknown);
end;

function TOleControl.GetMainMenu: TMainMenu;
var
  Form: TCustomForm;
begin
  Result := nil;
  Form := GetParentForm(Self);
  if Form <> nil then
    if (Form is TForm) and (TForm(Form).FormStyle <> fsMDIChild) then
      Result := Form.Menu
    else
      if Application.MainForm <> nil then
        Result := Application.MainForm.Menu;
end;

procedure TOleControl.GetObjectVerbs(List: TStrings);
var
  EnumOleVerb: IEnumOleVerb;
  OleVerb: TOleVerb;
  Code: HResult;
begin
  CreateControl;
  List.Clear;
  Code := FOleObject.EnumVerbs(EnumOleVerb);
  if Code = OLE_S_USEREG then
    Code := OleRegEnumVerbs(FControlData.ClassID, EnumOleVerb);
  if Code = 0 then
    while (EnumOleVerb.Next(1, OleVerb, nil) = 0) do
      if (OleVerb.grfAttribs and OLEVERBATTRIB_ONCONTAINERMENU <> 0) then
      begin
        List.AddObject(StripHotkey(OleVerb.lpszVerbName), TObject(OleVerb.lVerb));
      end;
end;

function TOleControl.GetWordBoolProp(Index: Integer): WordBool;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VBoolean;
end;

function TOleControl.GetTDateTimeProp(Index: Integer): TDateTime;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VDate;
end;

function TOleControl.GetTFontProp(Index: Integer): TFont;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to FFonts.Count-1 do
    if FControlData^.FontIDs^[I] = Index then
    begin
      Result := TFont(FFonts[I]);
      if Result.FontAdapter = nil then
        SetOleFont(Result, GetIDispatchProp(Index) as IFontDisp);
    end;
end;

function TOleControl.GetOleBoolProp(Index: Integer): TOleBool;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VBoolean;
end;

function TOleControl.GetOleDateProp(Index: Integer): TOleDate;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VDate;
end;

function TOleControl.GetOleEnumProp(Index: Integer): TOleEnum;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetTOleEnumProp(Index: Integer): TOleEnum;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetOleObject: Variant;
begin
  CreateControl;
  Result := Variant(FOleObject as IDispatch);
end;

function TOleControl.GetDefaultDispatch: IDispatch;
begin
  CreateControl;
  Result := FOleObject as IDispatch;
end;

function TOleControl.GetOleVariantProp(Index: Integer): OleVariant;
begin
  VarClear(Result);
  GetProperty(Index, TVarData(Result));
end;

function TOleControl.GetTPictureProp(Index: Integer): TPicture;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to FPictures.Count-1 do
    if FControlData^.PictureIDs^[I] = Index then
    begin
      Result := TPicture(FPictures[I]);
      if Result.PictureAdapter = nil then
        SetOlePicture(Result, GetIDispatchProp(Index) as IPictureDisp);
    end;
end;


function TOleControl.GetPropDisplayString(DispID: Integer): string;
var
  S: WideString;
begin
  CreateControl;
  if (FPropBrowsing <> nil) and
    (FPropBrowsing.GetDisplayString(DispID, S) = 0) then
    Result := S else
    Result := GetStringProp(DispID);
end;

procedure TOleControl.GetPropDisplayStrings(DispID: Integer; List: TStrings);
var
  Strings: TCAPOleStr;
  Cookies: TCALongint;
  I: Integer;
begin
  CreateControl;
  List.Clear;
  if (FPropBrowsing <> nil) and
    (FPropBrowsing.GetPredefinedStrings(DispID, Strings, Cookies) = 0) then
    try
      for I := 0 to Strings.cElems - 1 do
        List.AddObject(Strings.pElems^[I], TObject(Cookies.pElems^[I]));
    finally
      for I := 0 to Strings.cElems - 1 do
        CoTaskMemFree(Strings.pElems^[I]);
      CoTaskMemFree(Strings.pElems);
      CoTaskMemFree(Cookies.pElems);
    end;
end;

var  // init to zero, never written to
  DispParams: TDispParams = ();

procedure TOleControl.GetProperty(Index: Integer; var Value: TVarData);
var
  Status: HResult;
  ExcepInfo: TExcepInfo;
begin
  CreateControl;
  Value.VType := varEmpty;
  Status := FControlDispatch.Invoke(Index, GUID_NULL, 0,
    DISPATCH_PROPERTYGET, DispParams, @Value, @ExcepInfo, nil);
  if Status <> 0 then DispatchInvokeError(Status, ExcepInfo);
end;

function TOleControl.GetShortIntProp(Index: Integer): ShortInt;
begin
  Result := GetIntegerProp(Index);
end;

function TOleControl.GetSingleProp(Index: Integer): Single;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VSingle;
end;

function TOleControl.GetSmallintProp(Index: Integer): Smallint;
var
  Temp: TVarData;
begin
  GetProperty(Index, Temp);
  Result := Temp.VSmallint;
end;

function TOleControl.GetStringProp(Index: Integer): string;
begin
  Result := GetVariantProp(Index);
end;

function TOleControl.GetVariantProp(Index: Integer): Variant;
begin
  Result := GetOleVariantProp(Index);
end;

function TOleControl.GetWideStringProp(Index: Integer): WideString;
var
  Temp: TVarData;
begin
  Result := '';
  GetProperty(Index, Temp);
  Pointer(Result) := Temp.VOleStr;
end;

function TOleControl.GetWordProp(Index: Integer): Word;
begin
  Result := GetIntegerProp(Index);
end;

procedure TOleControl.HookControlWndProc;
var
  WndHandle: HWnd;
begin
  if (FOleInPlaceObject <> nil) and (WindowHandle = 0) then
  begin
    WndHandle := 0;
    FOleInPlaceObject.GetWindow(WndHandle);
    if WndHandle = 0 then raise EOleError.CreateRes(@SNoWindowHandle);
    WindowHandle := WndHandle;
    DefWndProc := Pointer(GetWindowLong(WindowHandle, GWL_WNDPROC));
    CreationControl := Self;
    SetWindowLong(WindowHandle, GWL_WNDPROC, Longint(@InitWndProc));
    SendMessage(WindowHandle, WM_NULL, 0, 0);
  end;
end;

procedure CallEventMethod(const EventInfo: TEventInfo);
asm
        PUSH    EBX
        PUSH    ESI
        PUSH    EBP
        MOV     EBP,ESP
        MOV     EBX,EAX
        MOV     EDX,[EBX].TEventInfo.ArgCount
        TEST    EDX,EDX
        JE      @@5
        XOR     EAX,EAX
        LEA     ESI,[EBX].TEventInfo.Args
@@1:    MOV     AL,[ESI].TEventArg.Kind
        CMP     AL,1
        JA      @@2
        JE      @@3
        TEST    AH,AH
        JNE     @@3
        MOV     ECX,[ESI].Integer[4]
        MOV     AH,1
        JMP     @@4
@@2:    PUSH    [ESI].Integer[8]
@@3:    PUSH    [ESI].Integer[4]
@@4:    ADD     ESI,12
        DEC     EDX
        JNE     @@1
@@5:    MOV     EDX,[EBX].TEventInfo.Sender
        MOV     EAX,[EBX].TEventInfo.Method.Data
        CALL    [EBX].TEventInfo.Method.Code
        MOV     ESP,EBP
        POP     EBP
        POP     ESI
        POP     EBX
end;

type
  PVarArg = ^TVarArg;
  TVarArg = array[0..3] of DWORD;

procedure TOleControl.D2InvokeEvent(DispID: TDispID; var Params: TDispParams);
type
  TStringDesc = record
    PStr: Pointer;
    BStr: PBStr;
  end;
var
  I, J, K, ArgType, ArgCount, StrCount: Integer;
  ArgPtr: PEventArg;
  ParamPtr: PVarArg;
  Strings: array[0..MaxDispArgs - 1] of TStringDesc;
  EventInfo: TEventInfo;
begin
  GetEventMethod(DispID, EventInfo.Method);
  if Integer(EventInfo.Method.Code) >= $10000 then
  begin
    StrCount := 0;
    try
      ArgCount := Params.cArgs;
      EventInfo.Sender := Self;
      EventInfo.ArgCount := ArgCount;
      if ArgCount <> 0 then
      begin
        ParamPtr := @Params.rgvarg^[EventInfo.ArgCount];
        ArgPtr := @EventInfo.Args;
        I := 0;
        repeat
          Dec(Integer(ParamPtr), SizeOf(TVarArg));
          ArgType := ParamPtr^[0] and $0000FFFF;
          if ArgType and varTypeMask = varOleStr then
          begin
            ArgPtr^.Kind := akDWord;
            with Strings[StrCount] do
            begin
              PStr := nil;
              if ArgType and varByRef <> 0 then
              begin
                OleStrToStrVar(PBStr(ParamPtr^[2])^, string(PStr));
                BStr := PBStr(ParamPtr^[2]);
                ArgPtr^.Data[0] := Integer(@PStr);
              end else
              begin
                OleStrToStrVar(TBStr(ParamPtr^[2]), string(PStr));
                BStr := nil;
                ArgPtr^.Data[0] := Integer(PStr);
              end;
            end;
            Inc(StrCount);
          end else
          begin
            case ArgType of
              varSingle:
                begin
                  ArgPtr^.Kind := akSingle;
                  ArgPtr^.Data[0] := ParamPtr^[2];
                end;
              varDouble..varDate:
                begin
                  ArgPtr^.Kind := akDouble;
                  ArgPtr^.Data[0] := ParamPtr^[2];
                  ArgPtr^.Data[1] := ParamPtr^[3];
                end;
              varDispatch:
                begin
                  ArgPtr^.Kind := akDWord;
                  ArgPtr^.Data[0] := Integer(ParamPtr)
                end;
            else
              ArgPtr^.Kind := akDWord;
              if (ArgType and varArray) <> 0 then
                ArgPtr^.Data[0] := Integer(ParamPtr)
              else
                ArgPtr^.Data[0] := ParamPtr^[2];
            end;
          end;
          Inc(Integer(ArgPtr), SizeOf(TEventArg));
          Inc(I);
        until I = EventInfo.ArgCount;
      end;
      CallEventMethod(EventInfo);
      J := StrCount;
      while J <> 0 do
      begin
        Dec(J);
        with Strings[J] do
          if BStr <> nil then BStr^ := StringToOleStr(string(PStr));
      end;
    except
      Application.HandleException(Self);
    end;
    K := StrCount;
    while K <> 0 do
    begin
      Dec(K);
      string(Strings[K].PStr) := '';
    end;
  end;
end;

procedure TOleControl.InvokeEvent(DispID: TDispID; var Params: TDispParams);
var
  EventMethod: TMethod;
begin
  if ControlData.Version < 300 then
    D2InvokeEvent(DispID, Params)
  else
  begin
    GetEventMethod(DispID, EventMethod);
    if Integer(EventMethod.Code) < $10000 then Exit;

    try
      asm
                PUSH    EBX
                PUSH    ESI
                MOV     ESI, Params
                MOV     EBX, [ESI].TDispParams.cArgs
                TEST    EBX, EBX
                JZ      @@7
                MOV     ESI, [ESI].TDispParams.rgvarg
                MOV     EAX, EBX
                SHL     EAX, 4     // count * sizeof(TVarArg)
                XOR     EDX, EDX
                ADD     ESI, EAX   // EDI = Params.rgvarg^[ArgCount]
        @@1:    SUB     ESI, 16    // Sizeof(TVarArg)
                MOV     EAX, dword ptr [ESI]
                CMP     AX, varSingle
                JA      @@3
                JE      @@4
        @@2:    TEST    DL,DL
                JNE     @@2a
                MOV     ECX, ESI
                INC     DL
                TEST    EAX, varArray
                JNZ     @@6
                MOV     ECX, dword ptr [ESI+8]
                JMP     @@6
        @@2a:   TEST    EAX, varArray
                JZ      @@5
                PUSH    ESI
                JMP     @@6
        @@3:    CMP     AX, varDate
                JA      @@2
        @@4:    PUSH    dword ptr [ESI+12]
        @@5:    PUSH    dword ptr [ESI+8]
        @@6:    DEC     EBX
                JNE     @@1
        @@7:    MOV     EDX, Self
                MOV     EAX, EventMethod.Data
                CALL    EventMethod.Code
                POP     ESI
                POP     EBX
      end;
    except
      Application.HandleException(Self);
    end;
  end;
end;

procedure GetStringResult(BStr: TBStr; var Result: string);
begin
  try
    OleStrToStrVar(BStr, Result);
  finally
    SysFreeString(BStr);
  end;
end;

procedure TOleControl.InitControlInterface;
begin
end;

procedure TOleControl.InvokeMethod(const DispInfo; Result: Pointer); assembler;
asm
        PUSH    EBX
        PUSH    ESI
        PUSH    EDI
        MOV     EBX,EAX
        MOV     ESI,EDX
        MOV     EDI,ECX
        CALL    TOleControl.CreateControl
        PUSH    [ESI].TDispInfo.DispID
        MOV     ECX,ESP
        XOR     EAX,EAX
        PUSH    EAX
        PUSH    EAX
        PUSH    EAX
        PUSH    EAX
        MOV     EDX,ESP
        LEA     EAX,[EBP+16]
        CMP     [ESI].TDispInfo.ResType,varOleStr
        JE      @@1
        CMP     [ESI].TDispInfo.ResType,varVariant
        JE      @@1
        LEA     EAX,[EBP+12]
@@1:    PUSH    EAX
        PUSH    EDX
        LEA     EDX,[ESI].TDispInfo.CallDesc
        MOV     EAX,[EBX].TOleControl.FControlDispatch
        CALL    DispatchInvoke
        XOR     EAX,EAX
        MOV     AL,[ESI].TDispInfo.ResType
        JMP     @ResultTable.Pointer[EAX*4]

@ResultTable:
        DD      @ResEmpty
        DD      @ResNull
        DD      @ResSmallint
        DD      @ResInteger
        DD      @ResSingle
        DD      @ResDouble
        DD      @ResCurrency
        DD      @ResDate
        DD      @ResString
        DD      @ResDispatch
        DD      @ResError
        DD      @ResBoolean
        DD      @ResVariant

@ResSmallint:
@ResBoolean:
        MOV     AX,[ESP+8]
        MOV     [EDI],AX
        JMP     @ResDone

@ResString:
        MOV     EAX,[ESP+8]
        MOV     EDX,EDI
        CALL    GetStringResult
        JMP     @ResDone

@ResVariant:
        MOV     EAX,EDI
        CALL    System.@VarClear
        MOV     ESI,ESP
        MOV     ECX,4
        REP     MOVSD
        JMP     @ResDone

@ResDouble:
@ResCurrency:
@ResDate:
        MOV     EAX,[ESP+12]
        MOV     [EDI+4],EAX

@ResInteger:
@ResSingle:
        MOV     EAX,[ESP+8]
        MOV     [EDI],EAX

@ResEmpty:
@ResNull:
@ResDispatch:
@ResError:
@ResDone:
        ADD     ESP,20
        POP     EDI
        POP     ESI
        POP     EBX
end;

function TOleControl.IsCustomProperty(DispID: Integer): Boolean;
var
  W: WideString;
begin
  Result := (FPropBrowsing <> nil) and
    (FPropBrowsing.GetDisplayString(DispID, W) = 0);
end;

function TOleControl.IsPropPageProperty(DispID: Integer): Boolean;
var
  PPID: TCLSID;
begin
  Result := (FPropBrowsing <> nil) and
    (FPropBrowsing.MapPropertyToPage(DispID, PPID) = S_FALSE) and not
    IsEqualCLSID(PPID, GUID_NULL);
end;

function TOleControl.PaletteChanged(Foreground: Boolean): Boolean;
begin
  Result := False;
  if HandleAllocated and Foreground then
    Result := CallWindowProc(DefWndProc, Handle, WM_QUERYNEWPALETTE, 0, 0) <> 0;
  if not Result then
    Result := inherited PaletteChanged(Foreground);
end;

procedure TOleControl.PictureChanged(Sender: TObject);
var
  I: Integer;
begin
  if (FPictures = nil) or not (Sender is TPicture) then Exit;
  for I := 0 to FPictures.Count - 1 do
    if FPictures[I] = Sender then
    begin
      if (TPicture(Sender).PictureAdapter <> nil) then
        SetTPictureProp(FControlData.PictureIDs^[I], TPicture(Sender));
      Exit;
    end;
end;

procedure TOleControl.ReadData(Stream: TStream);
var
  Buffer: Pointer;
begin
  DestroyStorage;
  try
    FObjectData := GlobalAlloc(GMEM_MOVEABLE, Stream.Size);
    if FObjectData = 0 then OutOfMemoryError;
    Buffer := GlobalLock(FObjectData);
    try
      Stream.Read(Buffer^, Stream.Size);
    finally
      GlobalUnlock(FObjectData);
    end;
  except
    DestroyStorage;
  end;
end;

procedure TOleControl.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if ((AWidth <> Width) and (Width > 0)) or ((AHeight <> Height) and (Height > 0)) then
    if (FMiscStatus and OLEMISC_INVISIBLEATRUNTIME <> 0) or
      ((FOleObject.SetExtent(DVASPECT_CONTENT, Point(
        MulDiv(AWidth, 2540, Screen.PixelsPerInch),
        MulDiv(AHeight, 2540, Screen.PixelsPerInch))) <> S_OK)) then
    begin
      AWidth := Width;
      AHeight := Height;
    end;
  inherited SetBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TOleControl.SetByteProp(Index: Integer; Value: Byte);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetColorProp(Index: Integer; Value: TColor);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetTColorProp(Index: Integer; Value: TColor);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetCompProp(Index: Integer; const Value: Comp);
var
  Temp: TVarData;
begin
  Temp.VType := VT_I8;
  Temp.VDouble := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetCurrencyProp(Index: Integer; const Value: Currency);
var
  Temp: TVarData;
begin
  Temp.VType := varCurrency;
  Temp.VCurrency := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetDoubleProp(Index: Integer; const Value: Double);
var
  Temp: TVarData;
begin
  Temp.VType := varDouble;
  Temp.VDouble := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetIDispatchProp(Index: Integer; const Value: IDispatch);
var
  Temp: TVarData;
begin
  Temp.VType := varDispatch;
  Temp.VDispatch := Pointer(Value);
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetIntegerProp(Index: Integer; Value: Integer);
var
  Temp: TVarData;
begin
  Temp.VType := varInteger;
  Temp.VInteger := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetIUnknownProp(Index: Integer; const Value: IUnknown);
var
  Temp: TVarData;
begin
  Temp.VType := VT_UNKNOWN;
  Temp.VUnknown := Pointer(Value);
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetName(const Value: TComponentName);
var
  OldName: string;
  DispID: Integer;
begin
  OldName := Name;
  inherited SetName(Value);
  if FOleControl <> nil then
  begin
    FOleControl.OnAmbientPropertyChange(DISPID_AMBIENT_DISPLAYNAME);
    if FControlData^.Flags and (cfCaption or cfText) <> 0 then
    begin
      if FControlData^.Flags and cfCaption <> 0 then
        DispID := DISPID_CAPTION else
        DispID := DISPID_TEXT;
      if OldName = GetStringProp(DispID) then SetStringProp(DispID, Value);
    end;
  end;
end;

procedure TOleControl.SetWordBoolProp(Index: Integer; Value: WordBool);
var
  Temp: TVarData;
begin
  Temp.VType := varBoolean;
  if Value then
    Temp.VBoolean := WordBool(-1) else
    Temp.VBoolean := WordBool(0);
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetTDateTimeProp(Index: Integer; const Value: TDateTime);
var
  Temp: TVarData;
begin
  Temp.VType := varDate;
  Temp.VDate := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetTFontProp(Index: Integer; Value: TFont);
var
  I: Integer;
  F: TFont;
  Temp: IFontDisp;
begin
  for I := 0 to FFonts.Count-1 do
    if FControlData^.FontIDs^[I] = Index then
    begin
      F := TFont(FFonts[I]);
      F.Assign(Value);
      if F.FontAdapter = nil then
      begin
        GetOleFont(F, Temp);
        SetIDispatchProp(Index, Temp);
      end;
    end;
end;

procedure TOleControl.SetOleBoolProp(Index: Integer; Value: TOleBool);
var
  Temp: TVarData;
begin
  Temp.VType := varBoolean;
  if Value then
    Temp.VBoolean := WordBool(-1) else
    Temp.VBoolean := WordBool(0);
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetOleDateProp(Index: Integer; const Value: TOleDate);
var
  Temp: TVarData;
begin
  Temp.VType := varDate;
  Temp.VDate := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetOleEnumProp(Index: Integer; Value: TOleEnum);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetTOleEnumProp(Index: Integer; Value: TOleEnum);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetOleVariantProp(Index: Integer; const Value: OleVariant);
begin
  SetProperty(Index, TVarData(Value));
end;

procedure TOleControl.SetParent(AParent: TWinControl);
var
  CS: IOleClientSite;
  X: Integer;
begin
  inherited SetParent(AParent);
  if (AParent <> nil) then
  begin
    try  // work around ATL bug
      X := FOleObject.GetClientSite(CS);
    except
      X := -1;
    end;
    if (X <> 0) or (CS = nil) then
      OleCheck(FOleObject.SetClientSite(Self));
    if FOleControl <> nil then
      FOleControl.OnAmbientPropertyChange(DISPID_UNKNOWN);
  end;
end;

procedure TOleControl.SetTPictureProp(Index: Integer; Value: TPicture);
var
  I: Integer;
  P: TPicture;
  Temp: IPictureDisp;
begin
  if FUpdatingPictures then Exit;
  FUpdatingPictures := True;
  try
    for I := 0 to FPictures.Count-1 do
      if FControlData^.PictureIDs^[I] = Index then
      begin
        P := TPicture(FPictures[I]);
        P.Assign(Value);
        GetOlePicture(P, Temp);
        SetIDispatchProp(Index, Temp);
      end;
  finally
    FUpdatingPictures := False;
  end;
end;

procedure TOleControl.SetPropDisplayString(DispID: Integer;
  const Value: string);
var
  I: Integer;
  Values: TStringList;
  V: OleVariant;
begin
  Values := TStringList.Create;
  try
    GetPropDisplayStrings(DispID, Values);
    for I := 0 to Values.Count - 1 do
      if AnsiCompareText(Value, Values[I]) = 0 then
      begin
        OleCheck(FPropBrowsing.GetPredefinedValue(DispID,
          Integer(Values.Objects[I]), V));
        SetProperty(DispID, TVarData(V));
        Exit;
      end;
  finally
    Values.Free;
  end;
  SetStringProp(DispID, Value);
end;

procedure TOleControl.SetProperty(Index: Integer; const Value: TVarData);
const
  DispIDArgs: Longint = DISPID_PROPERTYPUT;
var
  Status, InvKind: Integer;
  DispParams: TDispParams;
  ExcepInfo: TExcepInfo;
begin
  CreateControl;
  DispParams.rgvarg := @Value;
  DispParams.rgdispidNamedArgs := @DispIDArgs;
  DispParams.cArgs := 1;
  DispParams.cNamedArgs := 1;
  if Value.VType <> varDispatch then
    InvKind := DISPATCH_PROPERTYPUT else
    InvKind := DISPATCH_PROPERTYPUTREF;
  Status := FControlDispatch.Invoke(Index, GUID_NULL, 0,
    InvKind, DispParams, nil, @ExcepInfo, nil);
  if Status <> 0 then DispatchInvokeError(Status, ExcepInfo);
end;

procedure TOleControl.SetShortintProp(Index: Integer; Value: ShortInt);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.SetSingleProp(Index: Integer; const Value: Single);
var
  Temp: TVarData;
begin
  Temp.VType := varSingle;
  Temp.VSingle := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetSmallintProp(Index: Integer; Value: Smallint);
var
  Temp: TVarData;
begin
  Temp.VType := varSmallint;
  Temp.VSmallint := Value;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetStringProp(Index: Integer; const Value: string);
var
  Temp: TVarData;
begin
  Temp.VType := varOleStr;
  Temp.VOleStr := StringToOleStr(Value);
  try
    SetProperty(Index, Temp);
  finally
    SysFreeString(Temp.VOleStr);
  end;
end;

procedure TOleControl.SetUIActive(Active: Boolean);
var
  Form: TCustomForm;
begin
  Form := GetParentForm(Self);
  if Form <> nil then
    if Active then
    begin
      if (Form.ActiveOleControl <> nil) and
        (Form.ActiveOleControl <> Self) then
        Form.ActiveOleControl.Perform(CM_UIDEACTIVATE, 0, 0);
      Form.ActiveOleControl := Self;
    end else
      if Form.ActiveOleControl = Self then Form.ActiveOleControl := nil;
end;

procedure TOleControl.SetVariantProp(Index: Integer; const Value: Variant);
begin
  SetOleVariantProp(Index, Value);
end;

procedure TOleControl.SetWideStringProp(Index: Integer; const Value: WideString);
var
  Temp: TVarData;
begin
  Temp.VType := varOleStr;
  if Value <> '' then
    Temp.VOleStr := PWideChar(Value)
  else
    Temp.VOleStr := nil;
  SetProperty(Index, Temp);
end;

procedure TOleControl.SetWordProp(Index: Integer; Value: Word);
begin
  SetIntegerProp(Index, Value);
end;

procedure TOleControl.ShowAboutBox;
const
  DispInfo: array[0..7] of Byte = ($D8,$FD,$FF,$FF,$00,$01,$00,$00);
begin
  InvokeMethod(DispInfo, nil);
end;

procedure TOleControl.StandardEvent(DispID: TDispID; var Params: TDispParams);
type
  PVarDataList = ^TVarDataList;
  TVarDataList = array[0..3] of TVarData;
const
  ShiftMap: array[0..7] of TShiftState = (
    [],
    [ssShift],
    [ssCtrl],
    [ssShift, ssCtrl],
    [ssAlt],
    [ssShift, ssAlt],
    [ssCtrl, ssAlt],
    [ssShift, ssCtrl, ssAlt]);
  MouseMap: array[0..7] of TShiftState = (
    [],
    [ssLeft],
    [ssRight],
    [ssLeft, ssRight],
    [ssMiddle],
    [ssLeft, ssMiddle],
    [ssRight, ssMiddle],
    [ssLeft, ssRight, ssMiddle]);
  ButtonMap: array[0..7] of TMouseButton = (
    mbLeft, mbLeft, mbRight, mbLeft, mbMiddle, mbLeft, mbRight, mbLeft);
var
  Args: PVarDataList;
  Shift: TShiftState;
  Button: TMouseButton;
  X, Y: Integer;
  Key: Word;
  Ch: Char;
begin
  Args := PVarDataList(Params.rgvarg);
  try
    case DispID of
      DISPID_CLICK:
        Click;
      DISPID_DBLCLICK:
        DblClick;
      DISPID_KEYDOWN, DISPID_KEYUP:
        if Params.cArgs >= 2 then
        begin
          Key := Variant(Args^[1]);
          X := Variant(Args^[0]);
          case DispID of
            DISPID_KEYDOWN: KeyDown(Key, ShiftMap[X and 7]);
            DISPID_KEYUP:   KeyUp(Key, ShiftMap[X and 7]);
          end;
          if ((Args^[1].vType and varByRef) <> 0) then
            Word(Args^[1].VPointer^) := Key;
        end;
      DISPID_KEYPRESS:
        if Params.cArgs > 0 then
        begin
          Ch := Char(Integer(Variant(Args^[0])));
          KeyPress(Ch);
          if ((Args^[0].vType and varByRef) <> 0) then
            Char(Args^[0].VPointer^) := Ch;
        end;
      DISPID_MOUSEDOWN, DISPID_MOUSEMOVE, DISPID_MOUSEUP:
        if Params.cArgs >= 4 then
        begin
          X := Integer(Variant(Args^[3])) and 7;
          Y := Integer(Variant(Args^[2])) and 7;
          Button := ButtonMap[X];
          Shift := ShiftMap[Y] + MouseMap[X];
          X := Variant(Args^[1]);
          Y := Variant(Args^[0]);
          case DispID of
            DISPID_MOUSEDOWN:
              MouseDown(Button, Shift, X, Y);
            DISPID_MOUSEMOVE:
              MouseMove(Shift, X, Y);
            DISPID_MOUSEUP:
              MouseUp(Button, Shift, X, Y);
          end;
        end;
    end;
  except
    Application.HandleException(Self);
  end;
end;

procedure TOleControl.WndProc(var Message: TMessage);
var
  WinMsg: TMsg;
begin
  if (Message.Msg >= CN_BASE + WM_KEYFIRST) and
    (Message.Msg <= CN_BASE + WM_KEYLAST) and
    (FOleInPlaceActiveObject <> nil) then
  begin
    WinMsg.HWnd := Handle;
    WinMsg.Message := Message.Msg - CN_BASE;
    WinMsg.WParam := Message.WParam;
    WinMsg.LParam := Message.LParam;
    WinMsg.Time := GetMessageTime;
    WinMsg.Pt.X := $115DE1F1;
    WinMsg.Pt.Y := $115DE1F1;
    if FOleInPlaceActiveObject.TranslateAccelerator(WinMsg) = S_OK then
    begin
      Message.Result := 1;
      Exit;
    end;
  end;
  case TMessage(Message).Msg of
    CM_PARENTFONTCHANGED:
      if ParentFont and (FOleControl <> nil) then
      begin
        FOleControl.OnAmbientPropertyChange(DISPID_AMBIENT_FONT);
        FOleControl.OnAmbientPropertyChange(DISPID_AMBIENT_FORECOLOR);
      end;
    CM_PARENTCOLORCHANGED:
      if ParentColor and (FOleControl <> nil) then
        FOleControl.OnAmbientPropertyChange(DISPID_AMBIENT_BACKCOLOR);
  end;
  inherited WndProc(Message);
end;

procedure TOleControl.WriteData(Stream: TStream);
var
  StorageExists: Boolean;
  Buffer: Pointer;
begin
  StorageExists := FObjectData <> 0;
  if not StorageExists then CreateStorage;
  try
    Buffer := GlobalLock(FObjectData);
    try
      Stream.Write(Buffer^, GlobalSize(FObjectData));
    finally
      GlobalUnlock(FObjectData);
    end;
  finally
    if not StorageExists then DestroyStorage;
  end;
end;

procedure TOleControl.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  if FMiscStatus and OLEMISC_INVISIBLEATRUNTIME = 0 then
    DefaultHandler(Message) else
    inherited;
end;

procedure TOleControl.WMPaint(var Message: TWMPaint);
var
  DC: HDC;
  PS: TPaintStruct;
begin
  if FMiscStatus and OLEMISC_INVISIBLEATRUNTIME <> 0 then
  begin
    DC := Message.DC;
    if DC = 0 then DC := BeginPaint(Handle, PS);
    OleDraw(FOleObject, DVASPECT_CONTENT, DC, ClientRect);
    if Message.DC = 0 then EndPaint(Handle, PS);
  end else
    inherited;
end;

procedure TOleControl.CMDocWindowActivate(var Message: TMessage);
var
  Form: TCustomForm;
  F: TForm;
begin
  Form := GetParentForm(Self);
  F := nil;
  if Form is TForm then F := TForm(Form);
  if (F <> nil) and (F.FormStyle = fsMDIChild) then
  begin
    FOleInPlaceActiveObject.OnDocWindowActivate(LongBool(Message.WParam));
    if Message.WParam = 0 then SetMenu(0, 0, 0);
  end;
end;

procedure TOleControl.CMColorChanged(var Message: TMessage);
begin
  inherited;
  if (FControlData^.Flags and cfBackColor <> 0) and not FUpdatingColor and
    HandleAllocated then
  begin
    FUpdatingColor := True;
    try
      SetColorProp(DISPID_BACKCOLOR, Color);
    finally
      FUpdatingColor := False;
    end;
  end;
end;

procedure TOleControl.CMEnabledChanged(var Message: TMessage);
begin
  inherited;
  if (FControlData^.Flags and cfEnabled <> 0) and not FUpdatingEnabled and
    HandleAllocated then
  begin
    FUpdatingEnabled := True;
    try
      SetWordBoolProp(DISPID_ENABLED, Enabled);
    finally
      FUpdatingEnabled := False;
    end;
  end;
end;

procedure TOleControl.CMFontChanged(var Message: TMessage);
begin
  inherited;
  if (FControlData^.Flags and (cfForeColor or cfFont) <> 0) and
    not FUpdatingFont and HandleAllocated then
  begin
    FUpdatingFont := True;
    try
      if FControlData^.Flags and cfForeColor <> 0 then
        SetIntegerProp(DISPID_FORECOLOR, Font.Color);
      if FControlData^.Flags and cfFont <> 0 then
        SetVariantProp(DISPID_FONT, FontToOleFont(Font));
    finally
      FUpdatingFont := False;
    end;
  end;
end;

procedure TOleControl.CMDialogKey(var Message: TMessage);
var
  Info: TControlInfo;
  Msg: TMsg;
  Cmd: Word;
begin
  if CanFocus then
  begin
    Info.cb := SizeOf(Info);
    if (FOleControl.GetControlInfo(Info) = S_OK) and (Info.cAccel <> 0) then
    begin
      FillChar(Msg, SizeOf(Msg), 0);
      Msg.hwnd := Handle;
      Msg.message := WM_KEYDOWN;
      Msg.wParam := Message.WParam;
      Msg.lParam := Message.LParam;
      if IsAccelerator(Info.hAccel, Info.cAccel, @Msg, Cmd) then
      begin
        FOleControl.OnMnemonic(@Msg);
        Message.Result := 1;
        Exit;
      end;
    end;
  end;
  inherited;
end;

procedure TOleControl.CMUIActivate(var Message: TMessage);
var
  F: TCustomForm;
begin
  F := GetParentForm(Self);
  if (F = nil) or (F.ActiveOleControl <> Self) then
    FOleObject.DoVerb(OLEIVERB_UIACTIVATE, nil, Self, 0,
      GetParentHandle, BoundsRect);
end;

procedure TOleControl.CMUIDeactivate(var Message: TMessage);
var
  F: TCustomForm;
begin
  F := GetParentForm(Self);
  if (F = nil) or (F.ActiveOleControl = Self) then
  begin
    if FOleInPlaceObject <> nil then FOleInPlaceObject.UIDeactivate;
    if (F <> nil) and (F.ActiveControl = Self) then OnUIDeactivate(False);
  end;
end;

{ TOleControl.IUnknown }

function TOleControl.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK else Result := E_NOINTERFACE;
end;

function TOleControl._AddRef: Integer;
begin
  Inc(FRefCount);
  Result := FRefCount;
end;

function TOleControl._Release: Integer;
begin
  Dec(FRefCount);
  Result := FRefCount;
end;

{ TOleControl.IOleClientSite }

function TOleControl.SaveObject: HResult;
begin
  Result := S_OK;
end;

function TOleControl.GetMoniker(dwAssign: Longint; dwWhichMoniker: Longint;
  out mk: IMoniker): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.GetContainer(out container: IOleContainer): HResult;
begin
  Result := E_NOINTERFACE;
end;

function TOleControl.ShowObject: HResult;
begin
  HookControlWndProc;
  Result := S_OK;
end;

function TOleControl.OnShowWindow(fShow: BOOL): HResult;
begin
  Result := S_OK;
end;

function TOleControl.RequestNewObjectLayout: HResult;
var
  Extent: TPoint;
  W, H: Integer;
begin
  Result := FOleObject.GetExtent(DVASPECT_CONTENT, Extent);
  if Result <> S_OK then Exit;
  W := MulDiv(Extent.X, Screen.PixelsPerInch, 2540);
  H := MulDiv(Extent.Y, Screen.PixelsPerInch, 2540);
  if (FMiscStatus and OLEMISC_INVISIBLEATRUNTIME <> 0) and (FOleControl = nil) then
  begin
    if W > 32 then W := 32;
    if H > 32 then H := 32;
  end;
  SetBounds(Left, Top, W, H);
end;

{ TOleControl.IOleControlSite }

function TOleControl.OnControlInfoChanged: HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.LockInPlaceActive(fLock: BOOL): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.GetExtendedControl(out disp: IDispatch): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.TransformCoords(var ptlHimetric: TPoint;
  var ptfContainer: TPointF; flags: Longint): HResult;
begin
  if flags and XFORMCOORDS_HIMETRICTOCONTAINER <> 0 then
  begin
    ptfContainer.X := MulDiv(ptlHimetric.X, Screen.PixelsPerInch, 2540);
    ptfContainer.Y := MulDiv(ptlHimetric.Y, Screen.PixelsPerInch, 2540);
  end else
  begin
    ptlHimetric.X := Integer(Round(ptfContainer.X * 2540 / Screen.PixelsPerInch));
    ptlHimetric.Y := Integer(Round(ptfContainer.Y * 2540 / Screen.PixelsPerInch));
  end;
  Result := S_OK;
end;

function TOleControl.OleControlSite_TranslateAccelerator(
  msg: PMsg; grfModifiers: Longint): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.OnFocus(fGotFocus: BOOL): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.ShowPropertyFrame: HResult;
begin
  Result := E_NOTIMPL;
end;

{ TOleControl.IOleWindow }

function TOleControl.ContextSensitiveHelp(fEnterMode: BOOL): HResult;
begin
  Result := S_OK;
end;

{ TOleControl.IOleInPlaceSite }

function TOleControl.OleInPlaceSite_GetWindow(out wnd: HWnd): HResult;
begin
  Result := S_OK;
  wnd := GetParentHandle;
  if wnd = 0 then Result := E_FAIL;
end;

function TOleControl.CanInPlaceActivate: HResult;
begin
  Result := S_OK;
end;

function TOleControl.OnInPlaceActivate: HResult;
begin
  FOleObject.QueryInterface(IOleInPlaceObject, FOleInPlaceObject);
  FOleObject.QueryInterface(IOleInPlaceActiveObject, FOleInPlaceActiveObject);
  Result := S_OK;
end;

function TOleControl.OnUIActivate: HResult;
begin
  SetUIActive(True);
  Result := S_OK;
end;

function TOleControl.GetWindowContext(out frame: IOleInPlaceFrame;
  out doc: IOleInPlaceUIWindow; out rcPosRect: TRect;
  out rcClipRect: TRect; out frameInfo: TOleInPlaceFrameInfo): HResult;
begin
  frame := Self;
  doc := nil;
  rcPosRect := BoundsRect;
  SetRect(rcClipRect, 0, 0, 32767, 32767);
  with frameInfo do
  begin
    fMDIApp := False;
    hWndFrame := GetTopParentHandle;
    hAccel := 0;
    cAccelEntries := 0;
  end;
  Result := S_OK;
end;

function TOleControl.Scroll(scrollExtent: TPoint): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.OnUIDeactivate(fUndoable: BOOL): HResult;
begin
  SetMenu(0, 0, 0);
  SetUIActive(False);
  Result := S_OK;
end;

function TOleControl.OnInPlaceDeactivate: HResult;
begin
  FOleInPlaceActiveObject := nil;
  FOleInPlaceObject := nil;
  Result := S_OK;
end;

function TOleControl.DiscardUndoState: HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.DeactivateAndUndo: HResult;
begin
  FOleInPlaceObject.UIDeactivate;
  Result := S_OK;
end;

function TOleControl.OnPosRectChange(const rcPosRect: TRect): HResult;
begin
  FOleInPlaceObject.SetObjectRects(rcPosRect, Rect(0, 0, 32767, 32767));
  Result := S_OK;
end;

{ TOleControl.IOleInPlaceUIWindow }

function TOleControl.GetBorder(out rectBorder: TRect): HResult;
begin
  Result := INPLACE_E_NOTOOLSPACE;
end;

function TOleControl.RequestBorderSpace(const borderwidths: TRect): HResult;
begin
  Result := INPLACE_E_NOTOOLSPACE;
end;

function TOleControl.SetBorderSpace(pborderwidths: PRect): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.SetActiveObject(const activeObject: IOleInPlaceActiveObject;
  pszObjName: POleStr): HResult;
begin
  Result := S_OK;
end;

{ TOleControl.IOleInPlaceFrame }

function TOleControl.OleInPlaceFrame_GetWindow(out wnd: HWnd): HResult;
begin
  wnd := GetTopParentHandle;
  Result := S_OK;
end;

function TOleControl.InsertMenus(hmenuShared: HMenu;
  var menuWidths: TOleMenuGroupWidths): HResult;
var
  Menu: TMainMenu;
begin
  Menu := GetMainMenu;
  if Menu <> nil then
    Menu.PopulateOle2Menu(hmenuShared, [0, 2, 4], menuWidths.width);
  Result := S_OK;
end;

function TOleControl.SetMenu(hmenuShared: HMenu; holemenu: HMenu;
  hwndActiveObject: HWnd): HResult;
var
  Menu: TMainMenu;
begin
  Menu := GetMainMenu;
  Result := S_OK;
  if Menu <> nil then
  begin
    Menu.SetOle2MenuHandle(hmenuShared);
    Result := OleSetMenuDescriptor(holemenu, Menu.WindowHandle,
      hwndActiveObject, nil, nil);
  end;
end;

function TOleControl.RemoveMenus(hmenuShared: HMenu): HResult;
begin
  while GetMenuItemCount(hmenuShared) > 0 do
    RemoveMenu(hmenuShared, 0, MF_BYPOSITION);
  Result := S_OK;
end;

function TOleControl.SetStatusText(pszStatusText: POleStr): HResult;
begin
  Result := S_OK;
end;

function TOleControl.EnableModeless(fEnable: BOOL): HResult;
begin
  Result := S_OK;
end;

function TOleControl.OleInPlaceFrame_TranslateAccelerator(
  var msg: TMsg; wID: Word): HResult;
begin
  Result := S_FALSE;
end;

{ TOleControl.IDispatch }

function TOleControl.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Count := 0;
  Result := S_OK;
end;

function TOleControl.GetTypeInfo(Index, LocaleID: Integer;
  out TypeInfo): HResult;
begin
  Pointer(TypeInfo) := nil;
  Result := E_NOTIMPL;
end;

function TOleControl.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := E_NOTIMPL;
end;

function TOleControl.Invoke(DispID: Integer; const IID: TGUID;
  LocaleID: Integer; Flags: Word; var Params;
  VarResult, ExcepInfo, ArgErr: Pointer): HResult;
var
  F: TFont;
begin
  if (Flags and DISPATCH_PROPERTYGET <> 0) and (VarResult <> nil) then
  begin
    Result := S_OK;
    case DispID of
      DISPID_AMBIENT_BACKCOLOR:
        PVariant(VarResult)^ := Color;
      DISPID_AMBIENT_DISPLAYNAME:
        PVariant(VarResult)^ := StringToVarOleStr(Name);
      DISPID_AMBIENT_FONT:
      begin
        if (Parent <> nil) and ParentFont then
          F := TOleControl(Parent).Font
        else
          F := Font;
        PVariant(VarResult)^ := FontToOleFont(F);
      end;
      DISPID_AMBIENT_FORECOLOR:
        PVariant(VarResult)^ := Font.Color;
      DISPID_AMBIENT_LOCALEID:
        PVariant(VarResult)^ := Integer(GetUserDefaultLCID);
      DISPID_AMBIENT_MESSAGEREFLECT:
        PVariant(VarResult)^ := True;
      DISPID_AMBIENT_USERMODE:
        PVariant(VarResult)^ := not (csDesigning in ComponentState);
      DISPID_AMBIENT_UIDEAD:
        PVariant(VarResult)^ := csDesigning in ComponentState;
      DISPID_AMBIENT_SHOWGRABHANDLES:
        PVariant(VarResult)^ := False;
      DISPID_AMBIENT_SHOWHATCHING:
        PVariant(VarResult)^ := False;
      DISPID_AMBIENT_SUPPORTSMNEMONICS:
        PVariant(VarResult)^ := True;
      DISPID_AMBIENT_AUTOCLIP:
        PVariant(VarResult)^ := True;
    else
      Result := DISP_E_MEMBERNOTFOUND;
    end;
  end else
    Result := DISP_E_MEMBERNOTFOUND;
end;

{ TOleControl.IPropertyNotifySink }

function TOleControl.OnChanged(dispid: TDispID): HResult;
begin
  try
    case dispid of
      DISPID_BACKCOLOR:
        if not FUpdatingColor then
        begin
          FUpdatingColor := True;
          try
            Color := GetIntegerProp(DISPID_BACKCOLOR);
          finally
            FUpdatingColor := False;
          end;
        end;
      DISPID_ENABLED:
        if not FUpdatingEnabled then
        begin
          FUpdatingEnabled := True;
          try
            Enabled := GetWordBoolProp(DISPID_ENABLED);
          finally
            FUpdatingEnabled := False;
          end;
        end;
      DISPID_FONT:
        if not FUpdatingFont then
        begin
          FUpdatingFont := True;
          try
            OleFontToFont(GetVariantProp(DISPID_FONT), Font);
          finally
            FUpdatingFont := False;
          end;
        end;
      DISPID_FORECOLOR:
        if not FUpdatingFont then
        begin
          FUpdatingFont := True;
          try
            Font.Color := GetIntegerProp(DISPID_FORECOLOR);
          finally
            FUpdatingFont := False;
          end;
        end;
    end;
  except  // control sent us a notification for a dispid it doesn't have.
    on EOleError do ;
  end;
  Result := S_OK;
end;

function TOleControl.OnRequestEdit(dispid: TDispID): HResult;
begin
  Result := S_OK;
end;

{ TOleControl.ISimpleFrameSite }

function TOleControl.PreMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
  out res: Integer; out Cookie: Longint): HResult;
begin
  Result := S_OK;
end;

function TOleControl.PostMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
  out res: Integer; Cookie: Longint): HResult;
begin
  Result := S_OK;
end;

end.
