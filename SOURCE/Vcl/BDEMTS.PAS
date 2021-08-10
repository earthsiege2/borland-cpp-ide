
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit BdeMts;

{$H+,X+}

interface

implementation

uses Mtx, DbTables;

function GetObjectContext: IUnknown;
var
  ObjectContext: IObjectContext;
begin
  try
    ObjectContext := Mtx.GetObjectContext;
  except
    ;
  end;
  if Assigned(ObjectContext) then Result := ObjectContext
  else Result := nil;
end;

begin
  if not Assigned(GetObjectContextProc) then
    GetObjectContextProc := GetObjectContext;
end.
