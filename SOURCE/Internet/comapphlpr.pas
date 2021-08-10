{****************************************************************}
{                                                                }
{       Borland Delphi Visual Component Library                  }
{                                                                }
{       Copyright (c) 2000, 2001 Borland Software Corporation    }
{                                                                }
{****************************************************************}
unit ComAppHlpr;

interface

uses ComObj;

procedure InitCOMAppFactory(const GUID: TGUID; const ClassName: String; const Description: String);

implementation

uses ComApp;

var
  WebAppFactory: TWebAppAutoObjectFactory;

procedure InitCOMAppFactory(const GUID: TGUID; const ClassName: String; const Description: String);
begin
  if (WebAppFactory <> nil) then
    WebAppFactory.Free;
  WebAppFactory := TWebAppAutoObjectFactory.Create(GUID, ClassName, Description);
end;


initialization
  WebAppFactory := nil;

finalization
  if (WebAppFactory <> nil) then
    WebAppFactory.Free;

end.




