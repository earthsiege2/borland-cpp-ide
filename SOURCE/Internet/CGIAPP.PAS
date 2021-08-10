{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


{$DENYPACKAGEUNIT}

unit CGIApp;

interface

uses WebBroker, CGIHTTP;

type

  TCGIFactory = class;

  TCGIApplication = class(TWebApplication)
  private
    FOutputFileName: string;
    FFactory: TCGIFactory;
    function NewRequest: TCGIRequest;
    function NewResponse(CGIRequest: TCGIRequest): TCGIResponse;
    procedure SetFactory(Value: TCGIFactory);
    function GetFactory: TCGIFactory;
    procedure CGIHandleException(Sender: TObject);
  public
    destructor Destroy; override;
    procedure Run; override;
  end;

  TCGIFactory = class(TObject)
  private
    FApplication: TCGIApplication;
    function GetOutputFileName: string;
    procedure SetOutputFileName(const Value: string);
  protected
    function NewRequest: TCGIRequest; virtual;
    function NewResponse(CGIRequest: TCGIRequest): TCGIResponse; virtual;
    property OutputFileName: string read GetOutputFileName write SetOutputFileName;
  public
    constructor Create;
  end;

implementation

uses SysUtils, BrkrConst, Classes, IniFiles, HTTPApp;

{ TCGIApplication }

procedure HandleServerException(E: TObject; const OutputFile: string);
var
  ResultText, ResultHeaders, EMsg: string;
  OutFile: TStream;
begin
  if E is Exception then
    EMsg := Exception(E).Message
  else
    EMsg := '';
  ResultText := Format(sInternalServerError, [E.ClassName, EMsg]);
  ResultHeaders := Format(
    'Status: 500 %s'#13#10+               { do not localize }
    'Content-Type: text/html'#13#10 +     { do not localize }
    'Content-Length: %d'#13#10 +          { do not localize }
    'Content:'#13#10#13#10, [EMsg, Length(ResultText)]); { do not localize }
  if IsConsole then
  begin
    FileWrite(TTextRec(Output).Handle, Pointer(ResultHeaders)^, Length(ResultHeaders));
    FileWrite(TTextRec(Output).Handle, Pointer(ResultText)^, Length(ResultText));
  end else
  begin
    if FileExists(OutputFile) then
      OutFile := TFileStream.Create(OutputFile, fmOpenWrite or fmShareDenyNone)
    else OutFile := TFileStream.Create(OutputFile, fmCreate);
    try
      OutFile.Write(Pointer(ResultHeaders)^, Length(ResultHeaders));
      OutFile.Write(Pointer(ResultText)^, Length(ResultText));
    finally
      OutFile.Free;
    end;
  end;
end;

destructor TCGIApplication.Destroy;
begin
  inherited;
  FFactory.Free;
end;

function TCGIApplication.NewRequest: TCGIRequest;
begin
  Result := GetFactory.NewRequest;
end;

function TCGIApplication.NewResponse(CGIRequest: TCGIRequest): TCGIResponse;
begin
  Result := GetFactory.NewResponse(CGIRequest);
end;

procedure TCGIApplication.Run;
var
  HTTPRequest: TCGIRequest;
  HTTPResponse: TCGIResponse;
begin
  inherited Run;
  if IsConsole then
  begin
    Rewrite(Output);
    Reset(Input);
  end;
  try
    HTTPRequest := NewRequest;
    try
      HTTPResponse := NewResponse(HTTPRequest);
      try
        HandleRequest(HTTPRequest, HTTPResponse);
      finally
        HTTPResponse.Free;
      end;
    finally
      HTTPRequest.Free;
    end;
  except
    HandleServerException(ExceptObject, FOutputFileName);
  end;
end;

procedure InitApplication;
begin
  Application := TCGIApplication.Create(nil);
end;

procedure TCGIApplication.SetFactory(Value: TCGIFactory);
begin
  Assert(FFactory = nil, 'Duplication CGIFactory');  { do not localize }
  FFactory := Value;
end;

function TCGIApplication.GetFactory: TCGIFactory;
begin
  if not Assigned(FFactory) then
    FFactory := TCGIFactory.Create;
  Result := FFactory;
end;

procedure TCGIApplication.CGIHandleException(Sender: TObject);
var
  Handled: Boolean;
  Intf: IWebExceptionHandler;
  E: TObject;
begin
  Handled := False;
  if (ExceptObject is Exception) and
    Supports(Sender, IWebExceptionHandler, Intf) then
    Intf.HandleException(Exception(ExceptObject), Handled);
  if not Handled then
  begin
    E := ExceptObject;
    AcquireExceptionObject;
    raise E;
  end;
end;

{ TCGIFactory }

constructor TCGIFactory.Create;
begin
  inherited;
  FApplication := Application as TCGIApplication;
  FApplication.SetFactory(Self);
  Classes.ApplicationHandleException := TCGIApplication(FApplication).CGIHandleException;
end;

function TCGIFactory.GetOutputFileName: string;
begin
  Result := FApplication.FOutputFileName;
end;

function TCGIFactory.NewRequest: TCGIRequest;
var
  Ini: TIniFile;
begin
  if IsConsole then
    Result := TCGIRequest.Create
  else
  begin
    Result := TWinCGIRequest.Create(ParamStr(1), ParamStr(2), ParamStr(3));
    OutputFileName := ParamStr(3);
    if OutputFileName = '' then
    begin
      Ini := TIniFile.Create(ParamStr(1));
      try
        OutputFileName := Ini.ReadString('System','Output File',''); {do not localize}
      finally
        Ini.Free;
      end;
    end;
  end;
end;

function TCGIFactory.NewResponse(CGIRequest: TCGIRequest): TCGIResponse;
begin
  if IsConsole then
    Result := TCGIResponse.Create(CGIRequest)
  else Result := TWinCGIResponse.Create(CGIRequest);
end;

procedure TCGIFactory.SetOutputFileName(const Value: string);
begin
  FApplication.FOutputFileName := Value;
end;

procedure DoneApplication;
begin
  try
    Application.Free;
    Application := nil;
  except
    on E:Exception do
      if Assigned(HandleShutdownException) then
      begin
        Application := nil;  // Application of no use at this point so clear it
        Classes.ApplicationHandleException := nil;
        HandleShutdownException(E);
      end;
  end;
end;

initialization
  InitApplication;
  AddExitProc(DoneApplication);
end.

