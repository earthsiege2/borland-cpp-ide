{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit WSDLSOAP;

interface

uses InvokeRegistry, Types;

type

  TWSDLSOAPPort = class(TRemotable)
  private
    FPortName: WideString;
    FAddresses: TWideStringDynArray;
  published
    property PortName: WideString read FPortName write FPortName;
    property Addresses: TWideStringDynArray read FAddresses write FAddresses;
  end;

  TWSDLSOAPPortArray = array of TWSDLSOAPPort;

implementation

uses SOAPConst;

initialization
  RemClassRegistry.RegisterXSClass(TWSDLSOAPPort, SBorlandTypeNamespace);
end.
