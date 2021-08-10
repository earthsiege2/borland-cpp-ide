{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Midas;

interface

uses ActiveX;

const
  LIBID_Midas: TGUID = '{83F57D68-CA9A-11D2-9088-00C04FA35CFA}';
  IID_IAppServer: TGUID = '{1AEFCC20-7A24-11D2-98B0-C69BEB4B5B6D}';
type

  IAppServer = interface(IDispatch)
    ['{1AEFCC20-7A24-11D2-98B0-C69BEB4B5B6D}']
    function  AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant;
                              MaxErrors: Integer; out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer;
                            Options: Integer; const CommandText: WideString;
                            var Params: OleVariant; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; safecall;
    function  AS_GetProviderNames: OleVariant; safecall;
    function  AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; safecall;
    function  AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer;
                            var OwnerData: OleVariant): OleVariant; safecall;
    procedure AS_Execute(const ProviderName: WideString; const CommandText: WideString;
                         var Params: OleVariant; var OwnerData: OleVariant); safecall;
  end;

  IAppServerDisp = dispinterface
    ['{1AEFCC20-7A24-11D2-98B0-C69BEB4B5B6D}']
    function  AS_ApplyUpdates(const ProviderName: WideString; Delta: OleVariant; 
                              MaxErrors: Integer; out ErrorCount: Integer; var OwnerData: OleVariant): OleVariant; dispid 20000000;
    function  AS_GetRecords(const ProviderName: WideString; Count: Integer; out RecsOut: Integer; 
                            Options: Integer; const CommandText: WideString; 
                            var Params: OleVariant; var OwnerData: OleVariant): OleVariant; dispid 20000001;
    function  AS_DataRequest(const ProviderName: WideString; Data: OleVariant): OleVariant; dispid 20000002;
    function  AS_GetProviderNames: OleVariant; dispid 20000003;
    function  AS_GetParams(const ProviderName: WideString; var OwnerData: OleVariant): OleVariant; dispid 20000004;
    function  AS_RowRequest(const ProviderName: WideString; Row: OleVariant; RequestType: Integer; 
                            var OwnerData: OleVariant): OleVariant; dispid 20000005;
    procedure AS_Execute(const ProviderName: WideString; const CommandText: WideString; 
                         var Params: OleVariant; var OwnerData: OleVariant); dispid 20000006;
  end;

implementation

end.
