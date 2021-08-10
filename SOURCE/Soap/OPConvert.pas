{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                 SOAP Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit OPConvert;

interface

uses IntfInfo, InvokeRegistry, SysUtils, Classes, XMLIntf;

type

  { Various options that control how data is [de]serialized. }
  TSOAPConvertOption = (soSendUntyped,            { Skip "xsi:type="xxx:xxxx" attribute }
                        soSendMultiRefObj,        { Use HREF/ID for remotable types     }
                        soSendMultiRefArray,      { Use HREF/ID for arrays              }
                        soTryAllSchema,           { Allow 1999/2010/2001 mixing         }
                        soRootRefNodesToBody,     { HREF/ID nodes are siblings          }
                        soDocument,               { Don't use sec. 5 Encoding           }
                        soReturnSuccessForFault,  { Don't set statuscode 500 upon error }
                        soUTF8InHeader,           { Put charset="UTF-8" in header       }
                        soDontSendEmptyNodes);    { Skip empty string/array & nil object nodes }

  TSOAPConvertOptions = set of TSOAPConvertOption;

  IOPConvert = interface
  ['{918CDE63-20E4-427D-8455-24489FF959D8}']
    { Property Accessors }
    function GetOptions: TSOAPConvertOptions;
    procedure SetOptions(Value: TSOAPConvertOptions);

    { client methods }
    function InvContextToMsg(const IntfMD: TIntfMetaData;
                             MethNum: Integer;
                             Con: TInvContext): InvString;
    procedure ProcessResponse(const Resp: TStream;
                              const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry;
                              Context: TInvContext);  overload;
    procedure ProcessResponse(const Resp: InvString;
                              const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry;
                              Context: TInvContext);  overload;
                              
    { server methods }
    procedure MsgToInvContext(const Request: InvString;
                              const IntfMD: TIntfMetaData;
                              var MethNum: Integer;
                              Context: TInvContext); overload;
    procedure MsgToInvContext(const Request: TStream;
                              const IntfMD: TIntfMetaData;
                              var MethNum: Integer;
                              Context: TInvContext);  overload;
    procedure MakeResponse(const IntfMD: TIntfMetaData;
                              const MethNum: Integer;
                              Context: TInvContext;
                              Response: TStream);
    function MakeFault(const Ex: Exception): InvString;

    property Options:  TSOAPConvertOptions read GetOptions write SetOptions;
  end;


implementation

end.
