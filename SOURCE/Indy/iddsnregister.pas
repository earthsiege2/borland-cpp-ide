unit IdDsnRegister;

interface

uses
{$IFDEF VER140}DesignIntf, DesignEditors;
{$ELSE}Dsgnintf;
{$ENDIF}

procedure Register;

implementation

uses
  IdDsnBaseCmpEdt,
  IdBaseComponent,
  IdDsnPropEdBinding, IdGlobal,
  IdComponent,
  IdMessage,
  IdResourceStrings,
  IdSocketHandle, IdTCPServer,
  SysUtils;

const
  MessagePartsType: array[0..1] of string = ('TIdAttachment', 'TIdText');

procedure Register;
begin
  RegisterPropertyEditor(TypeInfo(TIdSocketHandles), TIdTCPServer, '',
    TIdPropEdBinding);
  RegisterComponentEditor(TIdBaseComponent, TIdBaseComponentEditor);
end;

end.
