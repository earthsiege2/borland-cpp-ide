{****************************************************************}
{                                                                }
{       Borland Delphi Visual Component Library                  }
{                                                                }
{       Copyright (c) 2000, 2001 Borland Software Corporation    }
{                                                                }
{****************************************************************}

unit ComApp;

interface

uses
  ComObj, ActiveX, WebLib, StdVCL, ComHTTP, Classes, Windows, Forms;

type
  TComWebAppImpl = class(TComObject, IWebBroker)
  protected
    procedure HandleRequest(const Request: IWebRequest); safecall;
    { Protected declarations }
  end;
  {$EXTERNALSYM TComWebAppImpl}

{ TThreadedClassFactory }

  TThreadedClassFactory = class(TComObjectFactory, IClassFactory)
  protected
    function CreateInstance(const UnkOuter: IUnknown; const IID: TGUID;
      out Obj): HResult; stdcall;
    function DoCreateInstance(const UnkOuter: IUnknown; const IID: TGUID;
      out Obj): HResult; stdcall;
  end;
  {$EXTERNALSYM TThreadedClassFactory}

  TWebAppAutoObjectFactory = class(TThreadedClassFactory)
  public
    procedure UpdateRegistry(Register: Boolean); override;
    constructor Create(
      const ClassID: TGUID; const ClassName, Description: string);
  end;
  {$EXTERNALSYM TWebAppAutoObjectFactory}


{ TApartmentThread }

  TApartmentThread = class(TThread)
  private
    FClassFactory: TThreadedClassFactory;
    FUnkOuter: IUnknown;
    FIID: TGuid;
    FSemaphore: THandle;
    FStream: Pointer;
    FCreateResult: HResult;
  protected
    procedure Execute; override;
  public
    constructor Create(ClassFactory: TThreadedClassFactory; UnkOuter: IUnknown; IID: TGuid);
    destructor Destroy; override;
    property Semaphore: THandle read FSemaphore;
    property CreateResult: HResult read FCreateResult;
    property ObjStream: Pointer read FStream;
  end;
  {$EXTERNALSYM TApartmentThread}

procedure InitializeHandler;

var
  FComWebRequestHandler: TCOMWebRequestHandler;

implementation

uses ComServ, SysUtils, WebCat, WebReq, WebCntxt, WebBroker;

function ComWebRequestHandler: TWebRequestHandler;
begin
  if not Assigned(FComWebRequestHandler) then
    FComWebRequestHandler := TCOMWebRequestHandler.Create(nil);
  Result := FComWebRequestHandler;
end;

procedure TComWebAppImpl.HandleRequest(const Request: IWebRequest);
begin
  TComWebRequestHandler(ComWebRequestHandler).Run(Request);
end;

constructor TWebAppAutoObjectFactory.Create(const ClassID: TGUID;
  const ClassName, Description: string);
begin
  inherited Create(ComServ.ComServer, TComWebAppImpl, ClassID, ClassName, Description,
    ciMultiInstance, tmApartment);
end;

procedure TWebAppAutoObjectFactory.UpdateRegistry(Register: Boolean);
var
  CatReg: ICatRegister;
  Rslt: HResult;
  CatInfo: TCATEGORYINFO;
  Description: string;
  SClassID: string;
begin
  if Register then
    Inherited UpdateRegistry(Register);
  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatRegister, CatReg);
  SClassID := GUIDToString(ClassID);
  if Succeeded(Rslt) then
  begin
    if Register then
    begin
      CatInfo.catid := CATID_WebAppServer;
      CatInfo.lcid := $0409;
      StringToWideChar(Web_CatDesc, CatInfo.szDescription,
        Length(Web_CatDesc) + 1);
      CatReg.RegisterCategories(1, @CatInfo);
      CatReg.RegisterClassImplCategories(ClassID, 1, @CATID_WebAppServer);
    end else
    begin
      // No ole check here.  Win98 returns an error code if already unregistered
      CatReg.UnRegisterClassImplCategories(ClassID, 1, @CATID_WebAppServer);
      DeleteRegKey(Format(SCatImplBaseKey, [SClassID]));
    end;
  end else
  begin
    if Register then
    begin
      CreateRegKey('Component Categories\' + GUIDToString(CATID_WebAppServer), '409', Web_CatDesc);
      CreateRegKey(Format(SCatImplKey, [SClassID, GUIDToString(CATID_WebAppServer)]), '', '');
    end else
    begin
      DeleteRegKey(Format(SCatImplKey, [SClassID, GUIDToString(CATID_WebAppServer)]));
      DeleteRegKey(Format(SCatImplBaseKey, [SClassID]));
    end;
  end;
  if not Register then
    // Unregister class after category unregistration.  Win98's UnRegisterClassImplCategories
    // reports an error if the class is not found.
    Inherited UpdateRegistry(Register);
  if Register then
  begin
    Description := GetRegStringValue('CLSID\' + SClassID, '');
    CreateRegKey('AppID\' + SClassID, '', Description);
    CreateRegKey('CLSID\' + SClassID, 'AppID', SClassID);
  end else
    DeleteRegKey('AppID\' + SClassID);
end;

{ TThreadedAutoObjectFactory }

function TThreadedClassFactory.DoCreateInstance(const UnkOuter: IUnknown;
  const IID: TGUID; out Obj): HResult; stdcall;
begin
  Result := inherited CreateInstance(UnkOuter, IID, Obj);
end;

function TThreadedClassFactory.CreateInstance(const UnkOuter: IUnknown;
  const IID: TGUID; out Obj): HResult; stdcall;
begin
  with TApartmentThread.Create(Self, UnkOuter, IID) do
  begin
    if WaitForSingleObject(Semaphore, INFINITE) = WAIT_OBJECT_0 then
    begin
      Result := CreateResult;
      if Result <> S_OK then Exit;
      Result := CoGetInterfaceAndReleaseStream(IStream(ObjStream), IID, Obj);
    end else
      Result := E_FAIL
  end;
end;

{ TApartmentThread }

constructor TApartmentThread.Create(ClassFactory: TThreadedClassFactory;
  UnkOuter: IUnknown; IID: TGuid);
begin
  FClassFactory := ClassFactory;
  FUnkOuter := UnkOuter;
  FIID := IID;
  FSemaphore := CreateSemaphore(nil, 0, 1, nil);
  FreeOnTerminate := True;
  inherited Create(False);
end;

destructor TApartmentThread.Destroy;
begin
  FUnkOuter := nil;
  CloseHandle(FSemaphore);
  inherited Destroy;
  // Specify Form. because the WebBroker unit also has TApplication defined
  Forms.Application.ProcessMessages; {???}
end;

procedure TApartmentThread.Execute;
var
  msg: TMsg;
  Unk: IUnknown;
begin
  CoInitialize(nil);
  FCreateResult := FClassFactory.DoCreateInstance(FUnkOuter, FIID, Unk);
  if FCreateResult = S_OK then
    CoMarshalInterThreadInterfaceInStream(FIID, Unk, IStream(FStream));
  ReleaseSemaphore(FSemaphore, 1, nil);
  if FCreateResult = S_OK then
    while GetMessage(msg, 0, 0, 0) do
    begin
      DispatchMessage(msg);
      Unk._AddRef;
      if Unk._Release = 1 then break;
    end;
  Unk := nil;
  CoUninitialize;
end;


procedure InitializeHandler;
begin
  if not Assigned(WebReq.WebRequestHandlerProc) then
    WebReq.WebRequestHandlerProc := ComWebRequestHandler;
end;

procedure DoneApplication;
begin
  try
    WebReq.WebRequestHandlerProc :=  nil;
    FreeAndNil(FComWebRequestHandler);
  except
    on E:Exception do
      if Assigned(HandleShutdownException) then
      begin
        Classes.ApplicationHandleException := nil;
        HandleShutdownException(E);
      end;
  end;
end;

initialization
  WebReq.WebRequestHandlerProc := ComWebRequestHandler;
  AddExitProc(DoneApplication);
end.
