
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{                                                       }
{       Copyright (C) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ComConst;

interface

resourcestring
  SCreateRegKeyError = 'Error creating system registry entry';
  SOleError = 'OLE error %.8x';
  SObjectFactoryMissing = 'Object factory for class %s missing';
  STypeInfoMissing = 'Type information missing for class %s';
  SBadTypeInfo = 'Incorrect type information for class %s';
  SDispIntfMissing = 'Dispatch interface missing from class %s';
  SNoMethod = 'Method ''%s'' not supported by automation object';
  SVarNotObject = 'Variant does not reference an automation object';
  SDCOMNotInstalled = 'DCOM not installed';
  SDAXError = 'DAX Error';

  SAutomationWarning = 'COM Server Warning';
  SNoCloseActiveServer1 = 'There are still active COM objects in this ' +
    'application.  One or more clients may have references to these objects, ' +
    'so manually closing ';
  SNoCloseActiveServer2 = 'this application may cause those client ' +
    'application(s) to fail.'#13#10#13#10'Are you sure you want to close this ' +
    'application?';

implementation

end.
