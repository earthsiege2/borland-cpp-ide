{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}

unit WebNode;

interface

uses Classes, IntfInfo;

type

  IWebNode = interface
  ['{D8AFC380-2A17-4BED-8359-81B502CE61B3}']
    procedure Execute(const DataMsg: WideString; Response: TStream);
    procedure BeforeExecute(const IntfMD: TIntfMetaData; const MethMD: TIntfMethEntry);
  end;


implementation

end.
