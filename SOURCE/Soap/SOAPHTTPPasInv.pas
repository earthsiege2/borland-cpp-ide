{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPHTTPPasInv;

interface

uses
  Invoker, Classes, SOAPPasInv, SOAPHTTPDisp;

type
  THTTPSoapPascalInvoker = class(TSoapPascalInvoker, IHTTPSoapDispatch)
  public
    procedure DispatchSOAP(const Path, SoapAction: WideString; const Request: TStream;
       Response: TStream); virtual;
  end;
  { A new typename to be more C++ friendly }
  THTTPSoapCppInvoker = class(THTTPSoapPascalInvoker)
  end;

implementation

uses SOAPConst, InvokeRegistry, SysUtils, InvConst, TypInfo, IntfInfo,
  OPConvert, OPToSOAPDomConv, HTTPSOAPToPasBind;

procedure THTTPSoapPascalInvoker.DispatchSOAP(const Path, SoapAction: WideString; const Request: TStream;
   Response: TStream);
var
  IntfInfo: PTypeInfo;
  PascalBind: IHTTPSOAPToPasBind;
  InvClassType: TClass;
  ActionMeth: String;
  MD: TIntfMetaData;

  procedure RaiseNoIntfException(const str: string);
  var
   IntfName: WideString;
  begin
    IntfName := SUnknownInterface;
    try
     GetIntfMetaData(IntfInfo, MD);
     IntfName := MD.UnitName + '.' + MD.Name;
    except
    { Ignore }
    end;
    raise Exception.CreateFmt(SInvClassNotRegistered,  [IntfName, str]);
  end;

begin
  PascalBind := THTTPSOAPToPasBind.Create as IHTTPSOAPToPasBind;
  if (SoapAction <> '') and (SoapAction <> '""') then
  begin
    if not PascalBind.BindToPascalByAction(SoapAction, InvClassType, IntfInfo, ActionMeth) or (InvClassType = nil) then
    begin
      if IntfInfo = nil then
        raise Exception.CreateFmt(SInvInterfaceNotReg, [SoapAction])
      else if InvClassType = nil then
        RaiseNoIntfException(SoapAction)
      else
        raise Exception.CreateFmt(SUnknownSoapAction, [SoapAction]);
    end;
  end else
  begin
    if not PascalBind.BindToPascalByPath(Path, InvClassType, IntfInfo, ActionMeth)  or (InvClassType = nil) then
    begin
      if IntfInfo = nil then
        raise Exception.CreateFmt(SInvInterfaceNotRegURL, [Path])
      else if InvClassType = nil then
        RaiseNoIntfException(Path)
      else
        raise Exception.CreateFmt(SNoServiceForURL, [Path]);
    end;
  end;
  { Here we've found the interface/method to invoke }
  Invoke(InvClassType, IntfInfo, ActionMeth, Request, Response);
end;

end.
