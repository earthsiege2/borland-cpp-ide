
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       SQL Monitor Client Library Interface, V1.0      }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit SMIntf;

interface

const

  Class_SMClient: TGUID = '{CB9879E2-4395-11D0-9FFC-00A0248E4B9A}';

type

  ISMClient = interface(IUnknown)
    ['{CB9879E1-4395-11D0-9FFC-00A0248E4B9A}']
    function RegisterClient(ID: Integer; Name: PChar;
      Instance, SignalProc: Pointer): WordBool; stdcall;
    function AddStatement(Statement: PChar; Len: Integer): WordBool; stdcall;
  end;

implementation

end.
