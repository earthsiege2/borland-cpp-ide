{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}
unit StubAction;

interface

uses
  Windows, Messages, SysUtils, Classes, HTTPApp;

type

  TStubActionModule = class(TWebModule)
    procedure WebModule2WebActionItem1Action(Sender: TObject;
      Request: TWebRequest; Response: TWebResponse; var Handled: Boolean);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  StubActionModule: TStubActionModule;

implementation

{$R *.dfm}

uses ActiveX, ReqImpl, WebLib, ComObj;

procedure TStubActionModule.WebModule2WebActionItem1Action(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse; var Handled: Boolean);
var
  ClsID: TGUID;
  ComWebApp: IWebBroker;
  HaveCoClass: Boolean;
  ID: string;
begin
  try
    CoInitialize(nil);
    HaveCoClass := ReqImpl.SearchForCoClass(Request, ID, ClsID);
    if not HaveCoClass then
      raise Exception.CreateFmt('Invalid ID: %s', [ID]) {do not localize}
    else
    begin
      ComWebApp := CreateComObject(ClsID) as IWebBroker;
      ComWebApp.HandleRequest(TWebRequestImpl.Create(Request, Response, True));
    end;
  except
    On E: Exception do
    begin
       Request.WriteHeaders(200, '200', 'Content'#13#10#13#10); { Do not localize }
       Request.WriteString(E.message);
    end;
  end;
end;


end.


