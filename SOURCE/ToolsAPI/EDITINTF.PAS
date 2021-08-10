
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit EditIntf;

interface

uses SysUtils, Windows, VirtIntf;

const
  cursorPos = Integer(0);
  ViewTopPos = Integer(1);

  atWhiteSpace     = 0;
  atComment        = 1;
  atReservedWord   = 2;
  atIdentifier     = 3;
  atSymbol         = 4;
  atString         = 5;
  atNumber         = 6;
  atFloat          = 7; // not used in Pascal tokenizer
  atOctal          = 8; // not used in Pascal tokenizer
  atHex            = 9; // not used in Pascal tokenizer
  atCharacter      = 10; // not used in Pascal tokenizer
  atPreproc        = 11; // not used in Pascal tokenizer
  atIllegal        = 12; // not used in Pascal tokenizer
  atAssembler      = 13;
  SyntaxOff        = 14;

  MarkedBlock      = 15;
  SearchMatch      = 16;

  lfCurrentCSIP         = $0001;
  lfBreakpointEnabled   = $0002;
  lfBreakpointDisabled  = $0004;
  lfBreakpointInvalid   = $0008;
  lfErrorLine           = $0010;
  lfBreakpointVerified  = $0020;

type
  { Editor position expressed as column/line after tabs are expanded to spaces
    and include the "virtual" editor space (columns beyond the end of lines) }
  TEditPos = packed record
    Col: SmallInt; { Col is one-based }
    Line: Longint; { Line is one-based }
  end;

  { Editor position expressed as character index/line before tabs are expanded
    and does not include the indecies beyond the end of a line }
  TCharPos = packed record
    CharIndex: SmallInt; { CharIndex is zero-based }
    Line: Longint; { Line is one-based }
  end;

  { Use the TIEditReader class to gain read access to an editor buffer:

    NOTES:
      The buffer is accessed as a linear "file" with line breaks included.
      This reader interface could be accessed through a custom read-only
      TStream descendant.

    WARNING!!!
     o A TIEditReader should never be active at the same time as a TIEditWriter.
  }

  TIEditReader = class(TInterface)
  public
    function GetText(Position: Longint; Buffer: PChar; Count: Longint): Longint;
      virtual; stdcall; abstract;
  end;

  { Use the TIEditWriter class to gain write access to an editor buffer:

    NOTES:
     o As with the reader, the buffer is accessed as a linear "file" with
       line breaks included.  The writer uses a "copy in place" metaphor for
       modifying the editor buffer.  In other words, the writer can be thought
       of as simply copying from one buffer to another.  All positions (Pos)
       passed to the function are positions relative to the original file.  Due
       to the "copy" metaphor of the writer it does not support moving backward
       in the editor buffer. It is recommended that all modifications that must
       be performed should be done from the start to the finish.
     o After the TIEditWriter is freed(released), the undo-buffer of the editor
       is flushed unless CreateUndoableWriter was called to obtain the
       TIEditWriter.

    WARNING!!!
     o A TIEditWriter should never be active at the same time as a TIEditReader.
  }

  TIEditWriter = class(TInterface)
  public
    function CopyTo(Pos: Longint): Boolean; virtual; stdcall; abstract;
    function DeleteTo(Pos: Longint): Boolean; virtual; stdcall; abstract;
    function Insert(Text: PChar): Boolean; virtual; stdcall; abstract;
    function Position: Longint; virtual; stdcall; abstract;
    function GetCurrentPos: TCharPos; virtual; stdcall; abstract;

    property CurrentPos: TCharPos read GetCurrentPos;
  end;

  { The TIEditView represents an individual view on an edit buffer:

    This interface allows the cursor and view positions to be accessed and
    updated.  The only restriction on using this interface is that it should
    not be held for any length of time.  Since a view can be deleted at any
    time, the interface could become invalid.
  }

  TIEditView = class(TInterface)
  public
    function GetPos(Index: Integer): TEditPos; virtual; stdcall; abstract;
    procedure SetPos(Index: Integer; Value: TEditPos); virtual; stdcall; abstract;
    function GetViewSize: TSize; virtual; stdcall; abstract;
    function PosToCharPos(Pos: Longint): TCharPos; virtual; stdcall; abstract;
    function CharPosToPos(CharPos: TCharPos): Longint; virtual; stdcall; abstract;
    procedure ConvertPos(EdPosToCharPos: Boolean; var EditPos: TEditPos;
      var CharPos: TCharPos); virtual; stdcall; abstract;
    procedure GetAttributeAtPos(const EdPos: TEditPos; var Element, LineFlag: Integer);
      virtual; stdcall; abstract;

    property CursorPos: TEditPos index CursorPos read GetPos write SetPos;
    property TopPos: TEditPos index ViewTopPos read GetPos write SetPos;
    property ViewSize: TSize read GetViewSize;
  end;

  { The TIEditorInterface is the base interface to an editor buffer:

    Use this interface to obtain TIEditReader, TIEditWriter, and TIEditView
    interfaces.

    NOTE: If the block type is btColumn then the values for BlockStart and
          BlockAfter are actually expressing as TEditPos records.  This
          applies both to getting and setting the values

  }

  TSyntaxHighlighter = (shNone, shPascal, shC, shSQL, shQuery);
  TBlockType = (btInclusive, btLine, btColumn, btNonInclusive, btUnknown);

  TIEditorInterface = class(TInterface)
  public
    function CreateReader: TIEditReader; virtual; stdcall; abstract;
    function CreateWriter: TIEditWriter; virtual; stdcall; abstract;
    function FileName: string; virtual; stdcall; abstract;
    function LinesInBuffer: Longint; virtual; stdcall; abstract;
    function BufferModified: Boolean; virtual; stdcall; abstract;
    function MarkModified: Boolean; virtual; stdcall; abstract;
    function SetSyntaxHighlighter(SyntaxHighlighter: TSyntaxHighlighter): TSyntaxHighlighter;
      virtual; stdcall; abstract;
    function GetViewCount: Integer; virtual; stdcall; abstract;
    function GetView(Index: Integer): TIEditView; virtual; stdcall; abstract;
    function CreateUndoableWriter: TIEditWriter; virtual; stdcall; abstract;
    // These functions will affect all views on this buffer.
    function GetBlockAfter: TCharPos; virtual; stdcall; abstract;
    function GetBlockStart: TCharPos; virtual; stdcall; abstract;
    function GetBlockType: TBlockType; virtual; stdcall; abstract;
    function GetBlockVisible: Boolean; virtual; stdcall; abstract;
    procedure SetBlockAfter(Value: TCharPos); virtual; stdcall; abstract;
    procedure SetBlockStart(Value: TCharPos); virtual; stdcall; abstract;
    procedure SetBlockType(Value: TBlockType); virtual; stdcall; abstract;
    procedure SetBlockVisible(Value: Boolean); virtual; stdcall; abstract;

    property BlockStart: TCharPos read GetBlockStart write SetBlockStart;
    property BlockAfter: TCharPos read GetBlockAfter write SetBlockAfter;
    property BlockType: TBlockType read GetBlockType write SetBlockType;
    property BlockVisible: Boolean read GetBlockVisible write SetBlockVisible;
  end;

  { The TIComponentInterface is the base interface for a component living
    on a form/data module.  Never hold this interface for very long, since
    the component may be deleted at any time.

    GetComponentType   - Returns a string representing the type of the
                         component.
    GetParent          - Returns the interface corresponding to the parent
                         control if a TControl, otherwise returns the owner
                         of the control.  If a TPersistent or the root object
                         then it returns nil.
    IsTControl         - Returns True if component is a TControl descendant
    GetPropCount       - Returns the number of published properties on this
                         component.
    GetPropName        - Given the index, returns the property name.
    GetPropType        - Given the index, returns the property type.
    GetPropTypeByName  - Given the name, returns the property type
    GetPropValue
    GetPropValueByName - Given the index or name, returns the property value.
                         The untyped var must be large enough to hold the
                         returned value.  If the property is a descendant of
                         TPersistent, the return value is a TIComponent-
                         Interface. For properties of any other object type,
                         the return value is nil.
    SetPropValue
    SetPropValueByName - Given the index or name, sets the property value.
    GetControlCount    - Returns the number of child controls (if a TControl
                         descendant, else returns 0).
    GetControl         - Given the index, returns an interface to the
                         child control.
    GetComponentCount  - Returns the number of child components (if a
                         TComponent descendant, else returns 0).
    GetComponent       - Given the index, returns an interface to the
                         child component.
    Select             - Selects the component and updates the Object Inspector.
    Focus              - Same as Select except it brings the form to front with
                         the component selected.  If this interface is a Form/
                         Data Module, then Focus only brings the form to front.
    Delete             - Deletes the component from the form.  Following this
                         call, this interface will now be invalid and must be
                         freed.
  }

  TIComponentInterface = class;

  TPropertyType = (ptUnknown, ptInteger, ptChar, ptEnumeration, ptFloat,
    ptString, ptSet, ptClass, ptMethod, ptWChar, ptLString, ptLWString,
    ptVariant);

  TGetChildCallback = function (Param: Pointer;
    ComponentInterface: TIComponentInterface): Boolean stdcall;

  TIComponentInterface = class(TInterface)
  public
    function GetComponentType: string; virtual; stdcall; abstract;
    function GetComponentHandle: Pointer; virtual; stdcall; abstract;
    function GetParent: TIComponentInterface; virtual; stdcall; abstract;
    function IsTControl: Boolean; virtual; stdcall; abstract;
    function GetPropCount: Integer; virtual; stdcall; abstract;
    function GetPropName(Index: Integer): string; virtual; stdcall; abstract;
    function GetPropType(Index: Integer): TPropertyType; virtual; stdcall; abstract;
    function GetPropTypeByName(const Name: string): TPropertyType;
      virtual; stdcall; abstract;
    function GetPropValue(Index: Integer; var Value): Boolean;
      virtual; stdcall; abstract;
    function GetPropValueByName(const Name: string; var Value): Boolean;
      virtual; stdcall; abstract;
    function SetProp(Index: Integer; const Value): Boolean;
      virtual; stdcall; abstract;
    function SetPropByName(const Name: string; const Value): Boolean;
      virtual; stdcall; abstract;
    function GetChildren(Param: Pointer; Proc: TGetChildCallback): Boolean;
      virtual; stdcall; abstract;
    function GetControlCount: Integer; virtual; stdcall; abstract;
    function GetControl(Index: Integer): TIComponentInterface;
      virtual; stdcall; abstract;
    function GetComponentCount: Integer; virtual; stdcall; abstract;
    function GetComponent(Index: Integer): TIComponentInterface;
      virtual; stdcall; abstract;
    function Select: Boolean; virtual; stdcall; abstract;
    function Focus: Boolean; virtual; stdcall; abstract;
    function Delete: Boolean; virtual; stdcall; abstract;
  end;

  { The TIFormInterface is the base interface to a designed form/data module:

     FileName          - Returns the actual filename of the form.
     FormModified      - Returns True if the form has been modified. This is
                         independent of the source code.
     MarkModified      - Forces the form to be marked as modified.  Returns
                         True is successful.
     GetFormComponent  - Returns a TIComponentInterface representing the root
                         component of the Form/Data module.
     FincComponent     - Given the name, returns a component interface of the
                         component on the Form/Data module.  Nil if the
                         component is not found.
     GetComponentFromHandle - Given the component handle (from
                         TIModuleNotifier.ComponentRenamed or
                         TIComponentInterface.GetComponentHandle) returns a
                         TIComponentInterface for that component.
     GetSelCount       - Returns the number of Selected components
     GetSelComponent   - Returns the index'th selected component on the form/
                         Data Module.
     GetCreateParent   - Returns a TIComponentInterface used to parent the
                         component currently being created.
                         NOTE: This is only valid from a TIModuleNotifier.
                         ComponentRenamed callback when OldName = '' and
                         NewName <> ''
     CreateComponent   - Adds a new component of type "TypeName" to the form.
                         if Container is nil, and the component to be added is
                         a TWinControl, then it is parented to the currently
                         selected container.  If Container is non-nil, and it
                         is a TWinControl, then the component is parented to
                         that control.  Set Name to an empty string to allow
                         the component's name to be auto-generated.  Set W and
                         H to -1 to use the default size of the component. Set
                         X and Y to -1 to center the component on the form.
  }

  TIFormInterface = class(TInterface)
  public
    function FileName: string; virtual; stdcall; abstract;
    function FormModified: Boolean; virtual; stdcall; abstract;
    function MarkModified: Boolean; virtual; stdcall; abstract;
    function GetFormComponent: TIComponentInterface; virtual; stdcall; abstract;
    function FindComponent(const Name: string): TIComponentInterface;
      virtual; stdcall; abstract;
    function GetComponentFromHandle(ComponentHandle: Pointer): TIComponentInterface;
      virtual; stdcall; abstract;
    function GetSelCount: Integer; virtual; stdcall; abstract;
    function GetSelComponent(Index: Integer): TIComponentInterface;
      virtual; stdcall; abstract;
    function GetCreateParent: TIComponentInterface; virtual; stdcall; abstract;
    function CreateComponent(Container: TIComponentInterface;
      const TypeName: string; X, Y, W, H: Integer): TIComponentInterface;
      virtual; stdcall; abstract;
  end;

  TResHeaderValue = (hvFlags, hvLanguage, hvDataVersion, hvVersion,
    hvCharacteristics);

  { TIResourceEntry is a raw interface to a resource entry in the project's
    resource file (<projectname>.RES).

    This interface is a very raw.  No implication on what is contained within
    a particular entry is made.  It if up to the add-in developer to interpret
    the data accessed through this interface.  NOTE: The 'MAINICON' entry and
    related entries should not be modified as these are maintained by Delphi.

    GetResourceType
    SetResourceType   - Sets and gets the resource type of this entry.  Follows
                        Windows standard of specifying a type by name or value.
                        If the high-word is 0, then the low-word is the
                        resource type value, otherwise it is a pointer to a
                        null terminated ANSI (byte per char) string. Most
                        predefined types are by value.

    GetResourceName
    SetResourceName   - Sets and gets the resource name of this entry.  Follows
                        Windows standard of specifying a type by name or value.
                        If the high-word is 0, then the low-word is the
                        resource type value, otherwise it is a pointer to a
                        null terminated ANSI (byte per char) string.

    GetHeaderValue
    SetHeaderValue    - Gets and sets various resource header values.  Pass in
                        one of the TResHeaderValues enums to indicate which
                        value to get/set.  Although some values are 16bits
                        (Word) these functions operation only on 32bits
                        (Integer).

    GetData           - Returns a raw pointer to the actual resource data buffer.

    GetDataSize       - Returns the current size of the data buffer.

    SetDataSize       - Resizes the current data buffer.  If the size is
                        smaller than the current size, the data is simply
                        truncated without regard to its current contents.

    GetEntryHandle    - Returns a unique handle value identifying the resource
                        entry.
  }

  TIResourceEntry = class(TInterface)
  public
    function GetResourceType: PChar; virtual; stdcall; abstract;
    function GetResourceName: PChar; virtual; stdcall; abstract;
    function Change(NewType, NewName: PChar): Boolean; virtual; stdcall; abstract;
    function GetHeaderValue(HeaderValue: TResHeaderValue;
      var Value: Integer): Boolean; virtual; stdcall; abstract;
    function SetHeaderValue(HeaderValue: TResHeaderValue;
      Value: Integer): Boolean; virtual; stdcall; abstract;
    function GetData: Pointer; virtual; stdcall; abstract;
    function GetDataSize: Integer; virtual; stdcall; abstract;
    function SetDataSize(NewSize: Integer): Boolean; virtual; stdcall; abstract;
    function GetEntryHandle: Pointer; virtual; stdcall; abstract;
  end;

  { The TIResourceFile is an interface on the project's resource file
    (<projectname>.RES).

    GetEntryCount     - Returns the number of Resource entries.

    GetEntry          - Given an index, returns a TIResourceEntry of the
                        index'th entry.

    FindEntry         - Given a Resource type and name, return a
                        TIResourceEntry or nil if not found.

    DeleteEntry       - Given an entry handle, delete the given resource
                        entry.

    CreateEntry       - Creates a new resource entry of the given type and name
                        and returns a TIResourceEntry.  Returns nil if the
                        entry already exists or any other error occurs.
  }

  TIResourceFile = class(TInterface)
  public
    function FileName: string; virtual; stdcall; abstract;
    function GetEntryCount: Integer; virtual; stdcall; abstract;
    function GetEntry(Index: Integer): TIResourceEntry; virtual; stdcall; abstract;
    function GetEntryFromHandle(EntryHandle: Pointer): TIResourceEntry; virtual; stdcall; abstract;
    function FindEntry(ResType, Name: PChar): TIResourceEntry; virtual; stdcall; abstract;
    function DeleteEntry(EntryHandle: Pointer): Boolean; virtual; stdcall; abstract;
    function CreateEntry(ResType, Name: PChar; Flags, LanguageId: Word;
      DataVersion, Version, Characteristics: Integer): TIResourceEntry; virtual; stdcall; abstract;
  end;

  { The TIModuleNotifer interface is a client provided interface:

    Use this interface as a base to a client defined implementation.  An
    instance of the TIModuleNotifer descendant is the registered with a
    TIModuleInterface in order to receive notifications for the events
    defined by the TNotifyCode.

      ncModuleDeleted    - the Module associated with the TIModule is being
                           freed.  Perform any clean-up and free all references
                           to a TIModuleInterface, including un-registering
                           the notifier class.
      ncModuleRenamed    - The module was renamed by a "save as" operation.
      ncEditorModified   - The edit buffer was modified by the user or through
                           a TIEditWriter interface (internal or external).
      ncFormModified     - The form was modified by the user or through
                           a TIFormInterface (internal of external).
      ncEditorSelected   - An edit view was selected and focused.
      ncFormSelected     - The associated form was selected and focused.
      ncBeforeSave       - This is sent right before the module (editor and
                           possibly the form) is actually saved to the file
                           system
      ncAfterSave        - Like the ncBeforeSave this is after all saving has
                           occurred and was successful.
      ncFormSaving       - This is sent just prior to the associated form is
                           actually streamed out.  This *may* be sent after an
                           ncBeforeSave, but not always.  This may be sent as
                           a result of a project compile operated without an
                           ncBeforSave being sent.
      ncProjResModified  - If this notifier is attached to a project module,
                           this event will be sent when the project resource
                           file changes (mainly when the user changes the
                           Icon, or other changes are made through the
                           TIResourceFile interface).

      ComponentRenamed   - Before any component on the associated form/data
                           model is renamed, this event is triggered allowing
                           the interface to track any changes to component on
                           a form.  If NewName is an empty string, component,
                           OldName was deleted.  If OldName is an empty string,
                           component NewName was added and you may call
                           TIFormInterface.GetCreateParent to determine the
                           container in which this component is being created.
                           .GetCreateParent is only valid if component is a
                           TControl.
                           NOTE: This procedure will *NOT* be called when the
                           form is being destroyed due to the form designer
                           being destroyed.
  }

  TNotifyCode = (ncModuleDeleted, ncModuleRenamed, ncEditorModified,
    ncFormModified, ncEditorSelected, ncFormSelected, ncBeforeSave,
    ncAfterSave, ncFormSaving, ncProjResModified);

  TIModuleNotifier = class(TInterface)
  public
    procedure Notify(NotifyCode: TNotifyCode); virtual; stdcall; abstract;
    procedure ComponentRenamed(ComponentHandle: Pointer;
      const OldName, NewName: string); virtual; stdcall; abstract;
  end;

  { The TIModuleInterface represents any file/module open in the IDE:

    A module is simply a file, or a file and form.  Use this interface to gain
    access to the edit buffer and form. There is only one instance of a
    TIModuleInterface per module, but is reference counted so it can be treated
    as separate instances.  When finished with the interface, the owner *must*
    "free" it. For instance, if a TIModuleNotifier object is told that the
    module was deleted.

    Functions:

    GetEditorInterface - This returns an interface to the associated edit
                         buffer.
    GetFormInterface   - This returns an interface to the associated form, if
                         one exists.  Returns nil otherwise.
    GetAncestortModule - Return the ancestor module to this Form/Data module
                         if not a direct descendent of a TForm or TDataModule.
    GetProjectResource - If this module interface is referencing a project
                         module, this will return an interface on the project's
                         resource.  Returns nil if this is not a project module
                         interface. (this resource contains the application's
                         main ICON as entry 'MAINICON').
    IsProjectModule    - Returns True if this is a project module interface,
                         False, otherwise.
    Close              - Returns true if the module was closed.
                         This may cause the ncModuleDeleted notification to
                         be triggered.  If another form references this module
                         through form inheritance, or form linking, the module
                         will remain "open" but is marked for deletion.
                         NOTE: This will close the module without saving or
                               even asking the user to save. See the Save
                               function.
    Save               - Returns true if successfully saved. Pass True in order
                         force the save operation without the user being asked.
                         Otherwise the user will be asked.  If the module is
                         marked UnNamed, the "Save As" dialog will be
                         presented to the user.
    Rename             - Renames the current module. The form file name will be
                         derived from the new name. An ncModuleRenamed
                         notification will be sent.
    GetFileSystem      - Returns true if able to get the current file system
                         associated with this module. An empty string indicates
                         the default file system.
    SetFileSystem      - Returns true if able to set the file system to the
                         indicated file system. An empty string indicates the
                         default file system.  One use is in response to an
                         ncModuleRenamed notification and the new name is
                         unavailable in the current file system.
    ShowSource         - Selects and focuses the top-most edit buffer view.
    ShowForm           - Selects and focused the form, if present.
    AddNotifier        - Registers an instance of a descendant to TIModule-
                         Notifier.
    RemoveNotifier     - Removes a registered instance of a TIModuleNotifier.
    GetAuxEditorInterface - Obtains a TIEditorInterface to the .H file if the
                         main file is a .c/.cpp file.  Used only in C++Builder.
  }

  TIModuleInterface = class(TInterface)
  public
    function GetEditorInterface: TIEditorInterface; virtual; stdcall; abstract;
    function GetFormInterface: TIFormInterface; virtual; stdcall; abstract;
    function GetAncestorModule: TIModuleInterface; virtual; stdcall; abstract;
    function GetProjectResource: TIResourceFile; virtual; stdcall; abstract;
    function IsProjectModule: Boolean; virtual; stdcall; abstract;
    function Close: Boolean; virtual; stdcall; abstract;
    function Save(ForceSave: Boolean): Boolean; virtual; stdcall; abstract;
    function Rename(const NewName: string): Boolean; virtual; stdcall; abstract;
    function GetFileSystem(var FileSystem: string): Boolean; virtual; stdcall; abstract;
    function SetFileSystem(const FileSystem: string): Boolean; virtual; stdcall; abstract;
    function ShowSource: Boolean; virtual; stdcall; abstract;
    function ShowForm: Boolean; virtual; stdcall; abstract;
    function AddNotifier(AModuleNotifier: TIModuleNotifier): Boolean; virtual; stdcall; abstract;
    function RemoveNotifier(AModuleNotifier: TIModuleNotifier): Boolean; virtual; stdcall; abstract;
    function GetAuxEditorInterface: TIEditorInterface; virtual; stdcall; abstract;
  end;

  { TIProjectCreator interface

  }

  TIProjectCreator = class(TInterface)
  public
    function Existing: Boolean; virtual; stdcall; abstract;
    function GetFileName: string; virtual; stdcall; abstract;
    function GetFileSystem: string; virtual; stdcall; abstract;
    function NewProjectSource(const ProjectName: string): string; virtual; stdcall; abstract;
    procedure NewDefaultModule; virtual; stdcall; abstract;
    procedure NewProjectResource(Module: TIModuleInterface); virtual; stdcall; abstract;
  end;

  TIProjectCreatorEx = class(TIProjectCreator)
  public
    function GetOptionName: string; virtual; stdcall; abstract; 
    function NewOptionSource(const ProjectName: string): string; virtual; stdcall; abstract;
  end;

  { TIModuleCreator interface
  }

  TIModuleCreator = class(TInterface)
  public
    function Existing: Boolean; virtual; stdcall; abstract;
    function GetAncestorName: string; virtual; stdcall; abstract;
    function GetFileName: string; virtual; stdcall; abstract;
    function GetFileSystem: string; virtual; stdcall; abstract;
    function GetFormName: string; virtual; stdcall; abstract;
    function NewModuleSource(const UnitIdent, FormIdent,
      AncestorIdent: string): string; virtual; stdcall; abstract;
    procedure FormCreated(Form: TIFormInterface); virtual; stdcall; abstract;
  end;

  TIModuleCreatorEx = class(TIModuleCreator)
  public
    function GetIntfName: string; virtual; stdcall; abstract;
    function NewIntfSource(const UnitIdent, FormIdent,
      AncestorIdent: string): string; virtual; stdcall; abstract;
  end;

implementation

end.
