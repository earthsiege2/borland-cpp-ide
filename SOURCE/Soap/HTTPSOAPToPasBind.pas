{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{       SOAP Support                                    }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit HTTPSOAPToPasBind;

interface

uses TypInfo;

type
   IHTTPSOAPToPasBind = interface
   ['{FDA9957E-F8A1-4E46-9107-9DB7E90E0DBE}']
     function BindToPascalByAction(const Action: WideString; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: string): Boolean;
     function BindToPascalByPath(Path: string; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: string): Boolean;
   end;

   THTTPSOAPToPasBind = class(TInterfacedObject, IHTTPSOAPToPasBind)
   public
     function BindToPascalByAction(const Action: WideString; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: string): Boolean; virtual;
     function BindToPascalByPath(Path: String; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: String): Boolean; virtual;
   end;

implementation

uses InvokeRegistry;

function THTTPSOAPToPasBind.BindToPascalByAction(const Action: WideString; var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: string): Boolean;
begin
  Result := InvRegistry.GetInfoForURI('', Action, ACLass, IntfInfo, AMeth);
end;

function THTTPSOAPToPasBind.BindToPascalByPath(Path: String;
  var AClass: TClass; var IntfInfo: PTypeInfo; var AMeth: String): Boolean;
begin
  Result := InvRegistry.GetInfoForURI(Path, '', AClass, IntfInfo, AMeth);
end;

end.
