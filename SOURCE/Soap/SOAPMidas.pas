{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPMidas;

interface

uses Midas, InvokeRegistry, Types;

type

  {
    IAppServerSOAP: IAppServer for SOAP
    IAppServerSOAP is essentially IAppServer with __stdcall instead of __safecall.
    This allows environment that don't support safecall to receive packets analogous
    to IAppServer.
  }
  IAppServerSOAP = interface(IInvokable)
    ['{C99F4735-D6D2-495C-8CA2-E53E5A439E61}']
    function  SAS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant;
                              MaxErrors: Integer; out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; stdcall;
    function  SAS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                            Options: Integer; const CommandText: WideString;
                            var Params: OleVariant; var OwnerData: OleVariant): OleVariant; stdcall;
    function  SAS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; stdcall;
    function  SAS_GetProviderNames: TWideStringDynArray; stdcall;
    function  SAS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; stdcall;
    function  SAS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                            var OwnerData: OleVariant): OleVariant; stdcall;
    procedure SAS_Execute(const ProviderName: WideString; const CommandText: WideString;
                         var Params: OleVariant; var OwnerData: OleVariant); stdcall;
  end;

procedure RegDefIAppServerInvClass;

implementation

uses SOAPConst, SOAPDm;

procedure RegDefIAppServerInvClass;
begin
  InvRegistry.RegisterInvokableClass(TSoapDataModule);
end;

initialization
  { For backwards compatibility, we'll set the namespace of IAppServer explicitly -
    therefore allowing this code to move to a different module; and also handling
    the case where the AppNameSpacePrefix is defined }
  InvRegistry.RegisterInterface(TypeInfo(IAppServer), 'urn:Midas-IAppServer');      { Do not localize }
  InvRegistry.RegisterInterface(TypeInfo(IAppServerSOAP), SBorlandTypeNamespace);   { Do not localize }
  InvRegistry.RegisterDefaultSOAPAction(TypeInfo(IAppServerSOAP),
                                        SBorlandTypeNamespace + '-IAppServerSOAP'); { Do not localize }
end.
