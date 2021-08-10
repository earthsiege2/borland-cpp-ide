
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ToolIntf;

interface

uses Windows, ActiveX, Classes, VirtIntf, EditIntf, FileIntf;

type
  TIMenuItemIntf = class;

  TIMenuFlag = (mfInvalid, mfEnabled, mfVisible, mfChecked, mfBreak, mfBarBreak,
    mfRadioItem);
  TIMenuFlags = set of TIMenuFlag;

  TIMenuClickEvent = procedure (Sender: TIMenuItemIntf) of object;

  { The TIMenuItemIntf class is created by Delphi.  This is simply a virtual
    interface to an actual menu item found in the IDE. It is the responsibility
    of the client to destroy *all* menu items which it created.  Failure to
    properly clean-up will result in unpredictable behaviour.

    NOTE: Using functions that returns a TIMenuItemIntf should be done with
          care. Unless created by a particular add-in tool, do not hold these
          interfaces for long as the underlying actual VCL TMenuItem may be
          destroyed without any notification.  In practice, this only pertains
          to Delphi created menus or menus created by other add-in tools.
          It is also the responsibility of the user to free these interfaces
          when finished. Any attempt to modify a menu item that was created
          by Delphi will fail.

    DestroyMenuItem  - If this menu was created by through the interface, use
                       this function to destroy the associated menu item.  This
                       function will *not* allow any Delphi created menus to
                       be destroyed.

    GetItemCount
    GetItem          - Use these functions to iterate through the menu tree.
                       All TIMenuItemIntfs must be freed by the caller.

    GetName          - Returns the menu item name associated with the VCL menu
                       object. (Including internal Delphi menu names).

    GetParent        - Returns an interface to the parent menu item.

    GetCaption
    SetCaption       - Methods to get/set the caption of the menu item.

    GetShortCut
    SetShortCut      - Methods to get/set the short cut of the menu item.

    GetFlags
    SetFlags         - Use GetFlags and SetFlags to query and set the state of
                       the menu item.  For SetFlags, a mask indicating which
                       items to affect must be passed along with the actual
                       value of the flag.

    GetGroupIndex
    SetGroupIndex    - Methods to get/set the GroupIndex property of a
                       TMenuItem. This is useful for specifying values for
                       grouped radio menus.
    GetHint
    SetHint          - Methods to get/set the Hint proeprty of a TMenuItem.
                       NOTE: The IDE currently ignores this property.

    GetContext
    SetContext       - Methods to get/set the help context ID of a TMenuItem.

    GetOnClick
    SetOnClick       - Methods to get/set the OnClick property if the TMenuItem.

    InsertItem       - Creates and inserts a new sub menu item into the menu.
                       If (Index < 0) or (Index >= ItemCount) then the
                       operation is an append.
  }

  TIMenuItemIntf = class(TInterface)
  public
    function DestroyMenuItem: Boolean; virtual; stdcall; abstract;
    function GetIndex: Integer; virtual; stdcall; abstract;
    function GetItemCount: Integer; virtual; stdcall; abstract;
    function GetItem(Index: Integer): TIMenuItemIntf; virtual; stdcall; abstract;
    function GetName: string; virtual; stdcall; abstract;
    function GetParent: TIMenuItemIntf; virtual; stdcall; abstract;
    function GetCaption: string; virtual; stdcall; abstract;
    function SetCaption(const Caption: string): Boolean; virtual; stdcall; abstract;
    function GetShortCut: Integer; virtual; stdcall; abstract;
    function SetShortCut(ShortCut: Integer): Boolean; virtual; stdcall; abstract;
    function GetFlags: TIMenuFlags; virtual; stdcall; abstract;
    function SetFlags(Mask, Flags: TIMenuFlags): Boolean; virtual; stdcall; abstract;
    function GetGroupIndex: Integer; virtual; stdcall; abstract;
    function SetGroupIndex(GroupIndex: Integer): Boolean; virtual; stdcall; abstract;
    function GetHint: string; virtual; stdcall; abstract;
    function SetHint(Hint: string): Boolean; virtual; stdcall; abstract;
    function getContext: Integer; virtual; stdcall; abstract;
    function setContext(Context: Integer): Boolean; virtual; stdcall; abstract;
    function GetOnClick: TIMenuClickEvent; virtual; stdcall; abstract;
    function SetOnClick(Click: TIMenuClickEvent): Boolean; virtual; stdcall; abstract;
    function InsertItem(Index: Integer; Caption, Name, Hint: string;
      ShortCut, Context, GroupIndex: Integer; Flags: TIMenuFlags;
      EventHandler: TIMenuClickEvent): TIMenuItemIntf; virtual; stdcall; abstract;
  end;

  { The TIMainMenuIntf class represents the Delphi main menu.

    GetMenuItems     - Returns the menu representing the top level menus.

    FinMenuItem      - Given the VCL component name, returns the corresponding
                       TIMenuItemIntf.
  }

  TIMainMenuIntf = class(TInterface)
  public
    function GetMenuItems: TIMenuItemIntf; virtual; stdcall; abstract;
    function FindMenuItem(const Name: string): TIMenuItemIntf; virtual; stdcall; abstract;
  end;

  { The TIAddInNotifier allows an add-in tool to register a descendant of this
    type with Delphi in order to receive notifications about certian events
    within Delphi.  It is the resposibility of the add-in tool to unregister
    and free this class when shutting down.

    FileNotification   - Called whenever an operation is performed from the
                         FileMenu (or through the TIToolInterface).
      fnFileOpening    - The given filename is about to be opened. Set
                         Cancel to True to prevent the operation.
      fnFileOpened     - The given file has been successfully opened.
                         Modifications to Cancel have no effect.
      fnFileClosing    - The given file is about to be closed.  Set Cancel
                         to True to prevent the file from closing.
      fnProjectOpening - The given project is about to be opened.  Set
                         Cancel to True to prevent the operation.
      fnProjectOpened  - The given project has been successfully opened.
                         Modifications to Cancel have no effect.
      fnProjectClosing - The given project is about to be closed.  Set
                         Cancel to True to prevent the project from closing.
      fnAddedToProject - The given file was added to the project.
      fnRemovedFromProject - The given file was removed from the project.
      fnDefaultDesktopSave
      fnDefaultDekstopLoad
      fnProjectDesktopSave
      fnProjectDesktopLoad - The given filename represents a desktop is
                             being loaded or saved.  The desktop file is
                             in standard .INI file format. Add in written
                             using Delphi can use the TIniFile component
                             to add and retrieve information from this file.
                             Modifying Cancel has no effect.

      fnPackageInstalled - Sent when a package has been installed/uninstalled.
                           Modifying Cancel has no effect.

      EventNotification - Called whenever various non-file related events occur.

      enBeforeCompile - Called right before a project compile is started.  All
                        source modules have been updated. Set Cancel to True to
                        cancel the compile.
      enAfterCompile  - Called right after the compile is completed.  Cancel
                        will be True if successful, False otherwise.

      NOTE: Modifying Cancel should be done with care.  Multiple notifiers
            could interact, yielding unpredictable results.  Notifiers are
            called in the reverse order in which they are registered.  There
            is also no way to guarantee the registration order of the
            notifiers.
  }

  TFileNotification = (fnFileOpening, fnFileOpened, fnFileClosing,
    fnProjectOpening, fnProjectOpened, fnProjectClosing, fnAddedToProject,
    fnRemovedFromProject, fnDefaultDesktopLoad, fnDefaultDesktopSave,
    fnProjectDesktopLoad, fnprojectDesktopSave, fnPackageInstalled,
    fnPackageUninstalled);

  TEventNotification = (enBeforeCompile, enAfterCompile);  

  TIAddInNotifier = class(TInterface)
  public
    procedure FileNotification(NotifyCode: TFileNotification;
      const FileName: string; var Cancel: Boolean); virtual; stdcall; abstract;
    procedure EventNotification(NotifyCode: TEventNotification;
      var Cancel: Boolean); virtual; stdcall; abstract;
  end;

  { The Tool services object is created on the application side, and is
    passed to the VCS/Expert Manager DLL during initialization.  Note that
    the application is responsible for creating and freeing the interface
    object, and the client should never free the interface.

    The following functions are available to the client:

    ( Actions )

    CloseProject     - returns True if no project open, or if the currently
                       open project can be closed.

    OpenProject      - returns True if the named project can be opened.  Pass an
                       empty string to create a new project and main form.

    OpenProjectInfo  - returns True if the named project file can be opened.
                       This routine bypasses all the normal project load
                       features (such as loading a desktop file, showing
                       the source code, etc), and simply opens the .DPR and
                       .DOF files.

    SaveProject      - returns True if the project is unmodified, if there
                       is no project open, or if the open project can be saved.

    CloseFile        - returns True if the specified file is not currently
                       open, or if it can be closed.

    OpenFile         - returns True if the specified file is already open
                       or can be opened.

    ReloadFile       - returns True if the file is already open and was
                       reloaded from disk.  (NOTE: This will not perform any
                       checking of the current editor state).

    ModalDialogBox   - used by non-VCL DLL's to present a dialog box which is
                       modal.  Note that DLLs written using VCL can simply call
                       a form's ShowModal function.

    CreateModule     - Will create new module from memory images of the source
                       and, optionally, the form file.  The TCreateModuleFlags are:
      cmAddToProject - Add the new module to the currently open project.
      cmShowSource   - Show the source file in the top-most editor window.
      cmShowForm     - If a form is created, show it above the source.
      cmUnNamed      - Will mark the module as unnamed which will cause the
                       SaveAs dialog to show the first time the user attempts to
                       save the file.
      cmNewUnit      - Creates a new unit and adds it to the current project.
                       NOTE: all other parameters are ignored.
      cmNewForm      - Creates a new form and adds it to the current project.
                       NOTE: all other parameters are ignored.
      cmNewModel     - Creates a new Data Model and adds it to the current
                       project. NOTE: all other parameters are ignored.
      cmMainForm     - If the module includes a form, make it the main form of
                       the currently open project. Only valid with the
                       cmAddToProject option.
      cmMarkModified - Will insure that the new module is marked as modified.
      cmExisting     - Will Create a module from an existing file on disk

    CreateModuleEx   - New extended form of CreateModule.  This will return a
                       TIModuleInterface. All CreateModes from CreateModule are
                       supported with only the following differences:
      cmExisting     - Will create an existing module from the given file
                       system.
      AncestorClass  - This must specify an existing base class in the project.
                       (use the cmAddToProject flag to add a module to the
                        project first).


              NOTES:   Pass an empty string for the file system parameter in
                       order to use the default file system.  The file system
                       parameter *must* be a valid file system previously
                       registered through the RegisiterFilesystem API.

    ( Informational )

    GetParentHandle  - returns a HWND, which should be used as the parent for
                       any windows created by the client.

    GetProjectName   - returns a fully qualified path name of the currently
                       open project file, or an empty string if no project is
                       open.

    GetUnitCount     - returns the current number of units belonging to the
                       project.

    GetUnitName      - returns a fully qualified name of the specified unit.

    EnumProjectUnits - Calls EnumProc once for each unit in the project.

    GetFormCount     - returns the current number of forms belonging to the
                       project.

    GetFormName      - returns a fully qualified name of the specified form
                       file.

    GetCurrentFile   - returns a fully qualified name of the current file,
                       which could either be a form or unit (.PAS).
                       Returns a blank string if no file is currently selected.

    IsFileOpen       - returns True if the named file is currently open.

    GetNewModuleName - Automatically generates a valid Filename and Unit
                       identifier.  Uses the same mechanism as used by the IDE.

    ( Component library interface )

    GetModuleCount   - Returns the number of currently installed modules in the
                       component library.

    GetModuleName    - Returns then name of the module given its index.

    GetComponentCount- Returns the number of components installed in a particular
                       module.

    GetComponentName - Returns the name of the component given its module index
                       and index in that mnodule.

    ( Virtual file system interface )

    RegisterFileSystem   - Registers an externally defined file system.
    UnRegisterFileSystem - UnRegisters an externally defined file system.

    ( Module Interfaces )

    GetModuleInterface - Return an module interface associated with the given
                         file.  NOTE: This function returns the same interface
                         instance for a given module, only the reference count
                         is adjusted.  The user of this interface owns it and
                         must call release when finished.

    GetFormModuleInterface - Return an module interface associated with the
                            given form.  NOTE: See GetModuleInterface.

    ( Menu Interface )

    GetMainMenu        - Returns an interface to the IDE's main menu.
                         See TIMainMenuIntf for details.

    ( Notification registration )

    AddNotifier        - Registers an instance of a descendant to TIAddIn-
                         Notifier.
    RemoveNotifier     - Removes a registered instance of a TIAddInNotifier.

    ( Pascal string handling functions )

    NOTE: These functions are provided for IDE add-in writers to use a language
          other than Pascal. (C++, for example).  Add-in writers using Delphi
          will never need to use these functions  (see doc about the ShareMem
          unit and DELPHIMM.DLL)

    NewPascalString    - Allocates and returns a pascal long string from the
                         provided PChar (char *, in C parlance).  Passing an
                         empty string or nil for the PChar will return nil for
                         the string (Pascal's equivilant of an empty string).

    FreePascalString   - Attempts to free the given Pascal string by
                         decrementing the internal reference count and
                         releasing the memory if the count returns to zero.

    ReferencePascalString - Increments the reference count of the given Pascal
                            string.  This allows the calling function to
                            manually extend the lifetime of the string.  NOTE:
                            a corresponding call to FreePascalString must be
                            made in order to actually release the string's
                            memory.

    AssignPascalString - Assigns one Pascal string to another.  NOTE: NEVER
                         directly assign Pascal strings to each other.  Doing
                         so will orphan memory and cause a memory leak.  The
                         destination may be referencing another string, so
                         the reference count of that string must be decremented.
                         Likewise, the reference count of the source string
                         must be incremented.

    ( Error handling )

    RaiseException   - This will cause an Exception to be raised with the IDE
                       with the string passed to this function.  ***NOTE: This
                       will cause the stack to unwind and control will **NOT**
                       return to this point.  It is the resposibility of the
                       Library to be sure it has correctly handled the error
                       condition before calling this procedure.

    ( Configuration Access )

    GetBaseRegistryKey - returns a string representing the full path to
                         Delphi's base registry key.  This key is relative
                         to HKEY_CURRENT_USER.

    ( Extensions )

    GetFormBounds - Returns the default bounds of an initial form or custom
                    module.

    ProjectCreate - Creates a project using the new TIProjectCreator interface.
                    This allows finer control over the creation process

    ModuleCreate  - Creates a module using the new TIModuleCreator interface.
                    Same as above.

    ( Extended Notification registration )

    AddNotifierEx      - Registers an instance of a descendant to TIAddIn-
                         Notifier.  Only notifiers registered using this
                         function will have EventNotification interface
                         function called.
  }

  TCreateModuleFlag = (cmAddToProject, cmShowSource, cmShowForm,
    cmUnNamed, cmNewUnit, cmNewForm, cmMainForm, cmMarkModified,
    cmNewFile, cmExisting);
  TCreateModuleFlags = set of TCreateModuleFlag;
  TCreateProjectFlag = (cpCustom, cpApplication, cpLibrary, cpCanShowSource,
    cpExisting, cpConsole);
  TCreateProjectFlags = set of TCreateProjectFlag;
  TBoundsType = (btForm, btCustomModule);
  TProjectEnumProc = function (Param: Pointer; const FileName, UnitName,
    FormName: string): Boolean stdcall;
  TProjectEnumModuleProc = function (Param: Pointer; const FileName, UnitName,
    FormName, DesignClass: string): Boolean stdcall;

  TIToolServices = class(TInterface)
  public
    { Action interfaces }
    function CloseProject: Boolean; virtual; stdcall; abstract;
    function OpenProject(const ProjName: string): Boolean; virtual; stdcall; abstract;
    function OpenProjectInfo(const ProjName: string): Boolean; virtual; stdcall; abstract;
    function SaveProject: Boolean; virtual; stdcall; abstract;
    function CloseFile(const FileName: string): Boolean; virtual; stdcall; abstract;
    function SaveFile(const FileName: string): Boolean; virtual; stdcall; abstract;
    function OpenFile(const FileName: string): Boolean; virtual; stdcall; abstract;
    function ReloadFile(const FileName: string): Boolean; virtual; stdcall; abstract;
    function ModalDialogBox(Instance: THandle; TemplateName: PChar;  WndParent: HWnd;
      DialogFunc: TFarProc; InitParam: LongInt): Integer; virtual; stdcall; abstract;
    function CreateModule(const ModuleName: string;
      Source, Form: IStream; CreateFlags: TCreateModuleFlags): Boolean;
      virtual; stdcall; abstract;
    function CreateModuleEx(const ModuleName, FormName, AncestorClass,
      FileSystem: string; Source, Form: IStream;
      CreateFlags: TCreateModuleFlags): TIModuleInterface; virtual; stdcall; abstract;

    { Project/UI information }
    function GetParentHandle: HWND; virtual; stdcall; abstract;
    function GetProjectName: string; virtual; stdcall; abstract;
    function GetUnitCount: Integer; virtual; stdcall; abstract;
    function GetUnitName(Index: Integer): string; virtual; stdcall; abstract;
    function EnumProjectUnits(EnumProc: TProjectEnumProc; Param: Pointer): Boolean;
      virtual; stdcall; abstract;
    function GetFormCount: Integer; virtual; stdcall; abstract;
    function GetFormName(Index: Integer): string; virtual; stdcall; abstract;
    function GetCurrentFile: string; virtual; stdcall; abstract;
    function IsFileOpen(const FileName: string): Boolean; virtual; stdcall; abstract;
    function GetNewModuleName(var UnitIdent, FileName: string): Boolean; virtual; stdcall; abstract;

    { Component Library interface }
    function GetModuleCount: Integer; virtual; stdcall; abstract;
    function GetModuleName(Index: Integer): string; virtual; stdcall; abstract;
    function GetComponentCount(ModIndex: Integer): Integer; virtual; stdcall; abstract;
    function GetComponentName(ModIndex, CompIndex: Integer): string; virtual; stdcall; abstract;
    {function InstallModule(const ModuleName: string): Boolean; virtual; stdcall; abstract;
    function CompileLibrary: Boolean; virtual; stdcall; abstract;}

    { Virtual File system interfaces }
    function RegisterFileSystem(AVirtualFileSystem: TIVirtualFileSystem): Boolean; virtual; stdcall; abstract;
    function UnRegisterFileSystem(const Ident: string): Boolean; virtual; stdcall; abstract;
    function GetFileSystem(const Ident: string): TIVirtualFileSystem; virtual; stdcall; abstract;

    { Editor Interfaces }
    function GetModuleInterface(const FileName: string): TIModuleInterface;
      virtual; stdcall; abstract;
    function GetFormModuleInterface(const FormName: string): TIModuleInterface;
      virtual; stdcall; abstract;

    { Menu Interfaces }
    function GetMainMenu: TIMainMenuIntf; virtual; stdcall; abstract;

    { Notification registration }
    function AddNotifier(AddInNotifier: TIAddInNotifier): Boolean;
      virtual; stdcall; abstract;
    function RemoveNotifier(AddInNotifier: TIAddInNotifier): Boolean;
      virtual; stdcall; abstract;

    { Pascal string handling functions }
    function NewPascalString(Str: PChar): Pointer; virtual; stdcall; abstract;
    procedure FreePascalString(var Str: Pointer); virtual; stdcall; abstract;
    procedure ReferencePascalString(var Str: Pointer); virtual; stdcall; abstract;
    procedure AssignPascalString(var Dest, Src: Pointer); virtual; stdcall; abstract;

    { Error handling }
    procedure RaiseException(const Message: string); virtual; stdcall; abstract;

    { Configuration Access }
    function GetBaseRegistryKey: string; virtual; stdcall; abstract;

    { Extensions }
    function GetFormBounds(BoundsType: TBoundsType): TRect; virtual; stdcall; abstract;
    function ProjectCreate(ProjectCreator: TIProjectCreator;
      CreateFlags: TCreateProjectFlags): TIModuleInterface; virtual; stdcall; abstract;
    function ModuleCreate(ModuleCreator: TIModuleCreator;
      CreateFlags: TCreateModuleFlags): TIModuleInterface; virtual; stdcall; abstract;

    { Extended Notification registration }
    function AddNotifierEx(AddInNotifier: TIAddInNotifier): Boolean;
      virtual; stdcall; abstract;

    { Create a unique unit name and class name }
    function GetNewModuleAndClassName(const Prefix: string; var UnitIdent,
      ClassName, FileName: string): Boolean; virtual; stdcall; abstract;

    function CreateCppModule(const ModuleName, FormName, AncestorClass,
      FileSystem: string; HdrSource, Source, Form: IStream;
      CreateFlags: TCreateModuleFlags): TIModuleInterface; virtual; stdcall; abstract;
    function GetVcsCount: Integer; virtual; stdcall; abstract;
    procedure GetVcsList(List: TStringList); virtual; stdcall; abstract;
    function GetVcsName(Index: Integer): string; virtual; stdcall; abstract;

    function EnumProjectModules(EnumProc: TProjectEnumModuleProc; Param: Pointer): Boolean;
      virtual; stdcall; abstract;

    function ProjectCreateEx(ProjectCreator: TIProjectCreatorEx;
      CreateFlags: TCreateProjectFlags): TIModuleInterface; virtual; stdcall; abstract;
    function ModuleCreateEx(ModuleCreator: TIModuleCreatorEx;
      CreateFlags: TCreateModuleFlags): TIModuleInterface; virtual; stdcall; abstract;
  end;

implementation

end.
