
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit FileIntf;

interface

uses ActiveX, SysUtils, VirtIntf;

{
  This is the definition of the IDE's virtual file system.  An expert,
  VCS manager, property editor, or component editor can register a new
  file system interface with the IDE.  This allows for re-vectoring of
  file operations to the editor and form/data model designer.
  NOTE: Currently the only way to specify an alternate file system for
        a file, is to open it through the Tools API (See ToolIntf.pas).
        This is also only for saving/loading of files.  The default file
        open/save dialogs and file system will always be used by the IDE
        except in the case mentioned above.

  All references to the term "file" depend on how it is defined by the
  file system.  The "file" could be a Memo Blob field, SQL text, etc...

  A file system instance must provide the following;

  GetFileStream     -  This is the core of the file system.  The file system
                       must return an instance of a TIStream for reading/
                       writing according to the Mode (see Classes.pas for
                       mode values).
  FileAge           -  This should return long value corresponding to the DOS
                       file date format.
  RenameFile        -  Returns True if the file system was able to rename the
                       file.
  IsReadonly        -  Return True if the given file is read only.
  IsFileBased       -  Return True if the file system closely matches the OS
                       file system.  If this is False, certain operations
                       are not performed.
  DeleteFile        -  Return True is the file was successfully deleted.
  FileExists        -  Return True if the specifiedl file exists in this
                       file system.
  GetTempFileName   -  Returns a Temporary file name based on the name given.
  GetBackupFileName -  Returns a backup file name based on the name given.
                       By convention, the extension is shifted one character
                       to the right and a tilde '~' character is inserted.
                       (eg unit1.pas -> unit1.~pa).
  GetIDString       -  Returns a unique ID string used to identify the file
                       system. By conventions this string should be in the
                       form <Vendor or Product>.<FileSystemName>.
                       (eg. Borland.SQLFileSystem ).
}

type
  TIVirtualFileSystem = class(TInterface)
  public
    function GetFileStream(const FileName: TFileName; Mode: Integer): IStream;
      virtual; stdcall; abstract;
    function FileAge(const FileName: TFileName): Longint;
      virtual; stdcall; abstract;
    function RenameFile(const OldName, NewName: TFileName): Boolean;
      virtual; stdcall; abstract;
    function IsReadonly(const FileName: TFileName): Boolean;
      virtual; stdcall; abstract;
    function IsFileBased: Boolean; virtual; stdcall; abstract;
    function DeleteFile(const FileName: TFileName): Boolean;
      virtual; stdcall; abstract;
    function FileExists(const FileName: TFileName): Boolean;
      virtual; stdcall; abstract;
    function GetTempFileName(const FileName: TFileName): TFileName;
      virtual; stdcall; abstract;
    function GetBackupFileName(const FileName: TFileName): TFileName;
      virtual; stdcall; abstract;
    function GetIDString: string; virtual; stdcall; abstract;
  end;

implementation

end.
