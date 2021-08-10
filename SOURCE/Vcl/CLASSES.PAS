
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Classes;

{$R-,T-,X+,H+}

{ ACTIVEX.HPP is not required by CLASSES.HPP }
(*$NOINCLUDE ActiveX*)


interface

uses SysUtils, Windows, ActiveX;

const

{ Maximum TList size }

  MaxListSize = Maxint div 16;

{ TStream seek origins }

  soFromBeginning = 0;
  soFromCurrent = 1;
  soFromEnd = 2;

{ TFileStream create mode }

  fmCreate = $FFFF;

{ TParser special tokens }

  toEOF     = Char(0);
  toSymbol  = Char(1);
  toString  = Char(2);
  toInteger = Char(3);
  toFloat   = Char(4);
  toWString = Char(5);

  {!! Moved here from menus.pas !!}
  { TShortCut special values }

  scShift = $2000;
  scCtrl = $4000;
  scAlt = $8000;
  scNone = 0;

type

{ Text alignment types }

  TAlignment = (taLeftJustify, taRightJustify, taCenter);
  TLeftRight = taLeftJustify..taRightJustify;
  TBiDiMode = (bdLeftToRight, bdRightToLeft, bdRightToLeftNoAlign,
    bdRightToLeftReadingOnly);

{ Types used by standard events }

  TShiftState = set of (ssShift, ssAlt, ssCtrl,
    ssLeft, ssRight, ssMiddle, ssDouble);

  THelpContext = -MaxLongint..MaxLongint;

  {!! Moved here from menus.pas !!}
  TShortCut = Low(Word)..High(Word);

{ Standard events }

  TNotifyEvent = procedure(Sender: TObject) of object;
  THelpEvent = function (Command: Word; Data: Longint;
    var CallHelp: Boolean): Boolean of object;
  TGetStrProc = procedure(const S: string) of object;

{ Exception classes }

  EStreamError = class(Exception);
  EFCreateError = class(EStreamError);
  EFOpenError = class(EStreamError);
  EFilerError = class(EStreamError);
  EReadError = class(EFilerError);
  EWriteError = class(EFilerError);
  EClassNotFound = class(EFilerError);
  EMethodNotFound = class(EFilerError);
  EInvalidImage = class(EFilerError);
  EResNotFound = class(Exception);
  EListError = class(Exception);
  EBitsError = class(Exception);
  EStringListError = class(Exception);
  EComponentError = class(Exception);
  EParserError = class(Exception);
  EOutOfResources = class(EOutOfMemory);
  EInvalidOperation = class(Exception);

{ Duplicate management }

  TDuplicates = (dupIgnore, dupAccept, dupError);

{ Forward class declarations }

  TStream = class;
  TFiler = class;
  TReader = class;
  TWriter = class;
  TComponent = class;

{ TList class }

  PPointerList = ^TPointerList;
  TPointerList = array[0..MaxListSize - 1] of Pointer;
  TListSortCompare = function (Item1, Item2: Pointer): Integer;
  TListNotification = (lnAdded, lnExtracted, lnDeleted);

  TList = class(TObject)
  private
    FList: PPointerList;
    FCount: Integer;
    FCapacity: Integer;
  protected
    function Get(Index: Integer): Pointer;
    procedure Grow; virtual;
    procedure Put(Index: Integer; Item: Pointer);
    procedure Notify(Ptr: Pointer; Action: TListNotification); virtual;
    procedure SetCapacity(NewCapacity: Integer);
    procedure SetCount(NewCount: Integer);
  public
    destructor Destroy; override;
    function Add(Item: Pointer): Integer;
    procedure Clear; virtual;
    procedure Delete(Index: Integer);
    class procedure Error(const Msg: string; Data: Integer); overload; virtual;
    class procedure Error(Msg: PResStringRec; Data: Integer); overload;
    procedure Exchange(Index1, Index2: Integer);
    function Expand: TList;
    function Extract(Item: Pointer): Pointer;
    function First: Pointer;
    function IndexOf(Item: Pointer): Integer;
    procedure Insert(Index: Integer; Item: Pointer);
    function Last: Pointer;
    procedure Move(CurIndex, NewIndex: Integer);
    function Remove(Item: Pointer): Integer;
    procedure Pack;
    procedure Sort(Compare: TListSortCompare);
    property Capacity: Integer read FCapacity write SetCapacity;
    property Count: Integer read FCount write SetCount;
    property Items[Index: Integer]: Pointer read Get write Put; default;
    property List: PPointerList read FList;
  end;

{ TThreadList class }

  TThreadList = class
  private
    FList: TList;
    FLock: TRTLCriticalSection;
    FDuplicates: TDuplicates;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(Item: Pointer);
    procedure Clear;
    function  LockList: TList;
    procedure Remove(Item: Pointer);
    procedure UnlockList;
    property Duplicates: TDuplicates read FDuplicates write FDuplicates;
  end;

{ IInterfaceList interface }

  IInterfaceList = interface
  ['{285DEA8A-B865-11D1-AAA7-00C04FB17A72}']
    function Get(Index: Integer): IUnknown;
    function GetCapacity: Integer;
    function GetCount: Integer;
    procedure Put(Index: Integer; Item: IUnknown);
    procedure SetCapacity(NewCapacity: Integer);
    procedure SetCount(NewCount: Integer);

    procedure Clear;
    procedure Delete(Index: Integer);
    procedure Exchange(Index1, Index2: Integer);
    function First: IUnknown;
    function IndexOf(Item: IUnknown): Integer;
    function Add(Item: IUnknown): Integer;
    procedure Insert(Index: Integer; Item: IUnknown);
    function Last: IUnknown;
    function Remove(Item: IUnknown): Integer;
    procedure Lock;
    procedure Unlock;
    property Capacity: Integer read GetCapacity write SetCapacity;
    property Count: Integer read GetCount write SetCount;
    property Items[Index: Integer]: IUnknown read Get write Put; default;
  end;

{ EXTERNALSYM IInterfaceList}

{ TInterfaceList class }

  TInterfaceList = class(TInterfacedObject, IInterfaceList)
  private
    FList: TThreadList;
  protected
    { IInterfaceList }
    function Get(Index: Integer): IUnknown;
    function GetCapacity: Integer;
    function GetCount: Integer;
    procedure Put(Index: Integer; Item: IUnknown);
    procedure SetCapacity(NewCapacity: Integer);
    procedure SetCount(NewCount: Integer);
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear;
    procedure Delete(Index: Integer);
    procedure Exchange(Index1, Index2: Integer);
    function Expand: TInterfaceList;
    function First: IUnknown;
    function IndexOf(Item: IUnknown): Integer;
    function Add(Item: IUnknown): Integer;
    procedure Insert(Index: Integer; Item: IUnknown);
    function Last: IUnknown;
    function Remove(Item: IUnknown): Integer;
    procedure Lock;
    procedure Unlock;
    property Capacity: Integer read GetCapacity write SetCapacity;
    property Count: Integer read GetCount write SetCount;
    property Items[Index: Integer]: IUnknown read Get write Put; default;
  end;

{ EXTERNALSYM TInterfaceList}

{ TBits class }

  TBits = class
  private
    FSize: Integer;
    FBits: Pointer;
    procedure Error;
    procedure SetSize(Value: Integer);
    procedure SetBit(Index: Integer; Value: Boolean);
    function GetBit(Index: Integer): Boolean;
  public
    destructor Destroy; override;
    function OpenBit: Integer;
    property Bits[Index: Integer]: Boolean read GetBit write SetBit; default;
    property Size: Integer read FSize write SetSize;
  end;

{ TPersistent abstract class }

{$M+}

  TPersistent = class(TObject)
  private
    procedure AssignError(Source: TPersistent);
  protected
    procedure AssignTo(Dest: TPersistent); virtual;
    procedure DefineProperties(Filer: TFiler); virtual;
    function  GetOwner: TPersistent; dynamic;
  public
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); virtual;
    function  GetNamePath: string; dynamic;
  end;

{$M-}

{ TPersistent class reference type }

  TPersistentClass = class of TPersistent;

{ TCollection class }

  TCollection = class;

  TCollectionItem = class(TPersistent)
  private
    FCollection: TCollection;
    FID: Integer;
    function GetIndex: Integer;
    procedure SetCollection(Value: TCollection);
  protected
    procedure Changed(AllItems: Boolean);
    function GetOwner: TPersistent; override;
    function GetDisplayName: string; virtual;
    procedure SetIndex(Value: Integer); virtual;
    procedure SetDisplayName(const Value: string); virtual;
  public
    constructor Create(Collection: TCollection); virtual;
    destructor Destroy; override;
    function GetNamePath: string; override;
    property Collection: TCollection read FCollection write SetCollection;
    property ID: Integer read FID;
    property Index: Integer read GetIndex write SetIndex;
    property DisplayName: string read GetDisplayName write SetDisplayName;
  end;

  TCollectionItemClass = class of TCollectionItem;

  TCollection = class(TPersistent)
  private
    FItemClass: TCollectionItemClass;
    FItems: TList;
    FUpdateCount: Integer;
    FNextID: Integer;
    FPropName: string;
    function GetCount: Integer;
    function GetPropName: string;   
    procedure InsertItem(Item: TCollectionItem);
    procedure RemoveItem(Item: TCollectionItem);
  protected
    property NextID: Integer read FNextID;
    { Design-time editor support }
    function GetAttrCount: Integer; dynamic;
    function GetAttr(Index: Integer): string; dynamic;
    function GetItemAttr(Index, ItemIndex: Integer): string; dynamic;
    procedure Changed;
    function GetItem(Index: Integer): TCollectionItem;
    procedure SetItem(Index: Integer; Value: TCollectionItem);
    procedure SetItemName(Item: TCollectionItem); virtual;
    procedure Update(Item: TCollectionItem); virtual;
    property PropName: string read GetPropName write FPropName;
    property UpdateCount: Integer read FUpdateCount;
  public
    constructor Create(ItemClass: TCollectionItemClass);
    destructor Destroy; override;
    function Add: TCollectionItem;
    procedure Assign(Source: TPersistent); override;
    procedure BeginUpdate; virtual;
    procedure Clear;
    procedure Delete(Index: Integer);
    procedure EndUpdate; virtual;
    function FindItemID(ID: Integer): TCollectionItem;
    function GetNamePath: string; override;
    function Insert(Index: Integer): TCollectionItem;
    property Count: Integer read GetCount;
    property ItemClass: TCollectionItemClass read FItemClass;
    property Items[Index: Integer]: TCollectionItem read GetItem write SetItem;
  end;

{ Collection class that maintains an "Owner" in order to obtain property
  path information at design-time }

  TOwnedCollection = class(TCollection)
  private
    FOwner: TPersistent;
  protected
    function GetOwner: TPersistent; override;
  public
    constructor Create(AOwner: TPersistent; ItemClass: TCollectionItemClass);
  end;

  TStrings = class;

{ TGetModuleProc }
{ Used in the TFormDesigner class to allow component/property editors access
  to project specific information }

  TGetModuleProc = procedure(const FileName, UnitName, FormName,
    DesignClass: string; CoClasses: TStrings) of object;

{ IStringsAdapter interface }
{ Maintains link between TStrings and IStrings implementations }

  IStringsAdapter = interface
    ['{739C2F34-52EC-11D0-9EA6-0020AF3D82DA}']
    procedure ReferenceStrings(S: TStrings);
    procedure ReleaseStrings;
  end;

{ TStrings class }

  TStrings = class(TPersistent)
  private
    FUpdateCount: Integer;
    FAdapter: IStringsAdapter;
    function GetCommaText: string;
    function GetName(Index: Integer): string;
    function GetValue(const Name: string): string;
    procedure ReadData(Reader: TReader);
    procedure SetCommaText(const Value: string);
    procedure SetStringsAdapter(const Value: IStringsAdapter);
    procedure SetValue(const Name, Value: string);
    procedure WriteData(Writer: TWriter);
  protected
    procedure DefineProperties(Filer: TFiler); override;
    procedure Error(const Msg: string; Data: Integer); overload;
    procedure Error(Msg: PResStringRec; Data: Integer); overload;
    function Get(Index: Integer): string; virtual; abstract;
    function GetCapacity: Integer; virtual;
    function GetCount: Integer; virtual; abstract;
    function GetObject(Index: Integer): TObject; virtual;
    function GetTextStr: string; virtual;
    procedure Put(Index: Integer; const S: string); virtual;
    procedure PutObject(Index: Integer; AObject: TObject); virtual;
    procedure SetCapacity(NewCapacity: Integer); virtual;
    procedure SetTextStr(const Value: string); virtual;
    procedure SetUpdateState(Updating: Boolean); virtual;
  public
    destructor Destroy; override;
    function Add(const S: string): Integer; virtual;
    function AddObject(const S: string; AObject: TObject): Integer; virtual;
    procedure Append(const S: string);
    procedure AddStrings(Strings: TStrings); virtual;
    procedure Assign(Source: TPersistent); override;
    procedure BeginUpdate;
    procedure Clear; virtual; abstract;
    procedure Delete(Index: Integer); virtual; abstract;
    procedure EndUpdate;
    function Equals(Strings: TStrings): Boolean;
    procedure Exchange(Index1, Index2: Integer); virtual;
    function GetText: PChar; virtual;
    function IndexOf(const S: string): Integer; virtual;
    function IndexOfName(const Name: string): Integer;
    function IndexOfObject(AObject: TObject): Integer;
    procedure Insert(Index: Integer; const S: string); virtual; abstract;
    procedure InsertObject(Index: Integer; const S: string;
      AObject: TObject);
    procedure LoadFromFile(const FileName: string); virtual;
    procedure LoadFromStream(Stream: TStream); virtual;
    procedure Move(CurIndex, NewIndex: Integer); virtual;
    procedure SaveToFile(const FileName: string); virtual;
    procedure SaveToStream(Stream: TStream); virtual;
    procedure SetText(Text: PChar); virtual;
    property Capacity: Integer read GetCapacity write SetCapacity;
    property CommaText: string read GetCommaText write SetCommaText;
    property Count: Integer read GetCount;
    property Names[Index: Integer]: string read GetName;
    property Objects[Index: Integer]: TObject read GetObject write PutObject;
    property Values[const Name: string]: string read GetValue write SetValue;
    property Strings[Index: Integer]: string read Get write Put; default;
    property Text: string read GetTextStr write SetTextStr;
    property StringsAdapter: IStringsAdapter read FAdapter write SetStringsAdapter;
  end;

{ TStringList class }

  TStringList = class;

  PStringItem = ^TStringItem;
  TStringItem = record
    FString: string;
    FObject: TObject;
  end;

  PStringItemList = ^TStringItemList;
  TStringItemList = array[0..MaxListSize] of TStringItem;
  TStringListSortCompare = function(List: TStringList; Index1, Index2: Integer): Integer;

  TStringList = class(TStrings)
  private
    FList: PStringItemList;
    FCount: Integer;
    FCapacity: Integer;
    FSorted: Boolean;
    FDuplicates: TDuplicates;
    FOnChange: TNotifyEvent;
    FOnChanging: TNotifyEvent;
    procedure ExchangeItems(Index1, Index2: Integer);
    procedure Grow;
    procedure QuickSort(L, R: Integer; SCompare: TStringListSortCompare);
    procedure InsertItem(Index: Integer; const S: string);
    procedure SetSorted(Value: Boolean);
  protected
    procedure Changed; virtual;
    procedure Changing; virtual;
    function Get(Index: Integer): string; override;
    function GetCapacity: Integer; override;
    function GetCount: Integer; override;
    function GetObject(Index: Integer): TObject; override;
    procedure Put(Index: Integer; const S: string); override;
    procedure PutObject(Index: Integer; AObject: TObject); override;
    procedure SetCapacity(NewCapacity: Integer); override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    destructor Destroy; override;
    function Add(const S: string): Integer; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Exchange(Index1, Index2: Integer); override;
    function Find(const S: string; var Index: Integer): Boolean; virtual;
    function IndexOf(const S: string): Integer; override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure Sort; virtual;
    procedure CustomSort(Compare: TStringListSortCompare); virtual;
    property Duplicates: TDuplicates read FDuplicates write FDuplicates;
    property Sorted: Boolean read FSorted write SetSorted;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChanging: TNotifyEvent read FOnChanging write FOnChanging;
  end;

{ TStream abstract class }

  TStream = class(TObject)
  private
    function GetPosition: Longint;
    procedure SetPosition(Pos: Longint);
    function GetSize: Longint;
  protected
    procedure SetSize(NewSize: Longint); virtual;
  public
    function Read(var Buffer; Count: Longint): Longint; virtual; abstract;
    function Write(const Buffer; Count: Longint): Longint; virtual; abstract;
    function Seek(Offset: Longint; Origin: Word): Longint; virtual; abstract;
    procedure ReadBuffer(var Buffer; Count: Longint);
    procedure WriteBuffer(const Buffer; Count: Longint);
    function CopyFrom(Source: TStream; Count: Longint): Longint;
    function ReadComponent(Instance: TComponent): TComponent;
    function ReadComponentRes(Instance: TComponent): TComponent;
    procedure WriteComponent(Instance: TComponent);
    procedure WriteComponentRes(const ResName: string; Instance: TComponent);
    procedure WriteDescendent(Instance, Ancestor: TComponent);
    procedure WriteDescendentRes(const ResName: string; Instance, Ancestor: TComponent);
    procedure WriteResourceHeader(const ResName: string; out FixupInfo: Integer);
    procedure FixupResourceHeader(FixupInfo: Integer);
    procedure ReadResHeader;
    property Position: Longint read GetPosition write SetPosition;
    property Size: Longint read GetSize write SetSize;
  end;

{ THandleStream class }

  THandleStream = class(TStream)
  private
    FHandle: Integer;
  protected
    procedure SetSize(NewSize: Longint); override;
  public
    constructor Create(AHandle: Integer);
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    property Handle: Integer read FHandle;
  end;

{ TFileStream class }

  TFileStream = class(THandleStream)
  public
    constructor Create(const FileName: string; Mode: Word);
    destructor Destroy; override;
  end;

{ TCustomMemoryStream abstract class }

  TCustomMemoryStream = class(TStream)
  private
    FMemory: Pointer;
    FSize, FPosition: Longint;
  protected
    procedure SetPointer(Ptr: Pointer; Size: Longint);
  public
    function Read(var Buffer; Count: Longint): Longint; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    procedure SaveToStream(Stream: TStream);
    procedure SaveToFile(const FileName: string);
    property Memory: Pointer read FMemory;
  end;

{ TMemoryStream }

  TMemoryStream = class(TCustomMemoryStream)
  private
    FCapacity: Longint;
    procedure SetCapacity(NewCapacity: Longint);
  protected
    function Realloc(var NewCapacity: Longint): Pointer; virtual;
    property Capacity: Longint read FCapacity write SetCapacity;
  public
    destructor Destroy; override;
    procedure Clear;
    procedure LoadFromStream(Stream: TStream);
    procedure LoadFromFile(const FileName: string);
    procedure SetSize(NewSize: Longint); override;
    function Write(const Buffer; Count: Longint): Longint; override;
  end;

{ TStringStream }

  TStringStream = class(TStream)
  private
    FDataString: string;
    FPosition: Integer;
  protected
    procedure SetSize(NewSize: Longint); override;
  public
    constructor Create(const AString: string);
    function Read(var Buffer; Count: Longint): Longint; override;
    function ReadString(Count: Longint): string;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    procedure WriteString(const AString: string);
    property DataString: string read FDataString;
  end;

{ TResourceStream }

  TResourceStream = class(TCustomMemoryStream)
  private
    HResInfo: HRSRC;
    HGlobal: THandle;
    procedure Initialize(Instance: THandle; Name, ResType: PChar);
  public
    constructor Create(Instance: THandle; const ResName: string; ResType: PChar);
    constructor CreateFromID(Instance: THandle; ResID: Integer; ResType: PChar);
    destructor Destroy; override;
    function Write(const Buffer; Count: Longint): Longint; override;
  end;

{ TStreamAdapter }
{ Implements OLE IStream on VCL TStream }

  TStreamOwnership = (soReference, soOwned);

  TStreamAdapter = class(TInterfacedObject, IStream)
  private
    FStream: TStream;
    FOwnership: TStreamOwnership;
  public
    constructor Create(Stream: TStream; Ownership: TStreamOwnership = soReference);
    destructor Destroy; override;
    function Read(pv: Pointer; cb: Longint;
      pcbRead: PLongint): HResult; virtual; stdcall;
    function Write(pv: Pointer; cb: Longint;
      pcbWritten: PLongint): HResult; virtual; stdcall;
    function Seek(dlibMove: Largeint; dwOrigin: Longint;
      out libNewPosition: Largeint): HResult; virtual; stdcall;
    function SetSize(libNewSize: Largeint): HResult; virtual; stdcall;
    function CopyTo(stm: IStream; cb: Largeint; out cbRead: Largeint;
      out cbWritten: Largeint): HResult; virtual; stdcall;
    function Commit(grfCommitFlags: Longint): HResult; virtual; stdcall;
    function Revert: HResult; virtual; stdcall;
    function LockRegion(libOffset: Largeint; cb: Largeint;
      dwLockType: Longint): HResult; virtual; stdcall;
    function UnlockRegion(libOffset: Largeint; cb: Largeint;
      dwLockType: Longint): HResult; virtual; stdcall;
    function Stat(out statstg: TStatStg;
      grfStatFlag: Longint): HResult; virtual; stdcall;
    function Clone(out stm: IStream): HResult; virtual; stdcall;
    property Stream: TStream read FStream;
    property StreamOwnership: TStreamOwnership read FOwnership write FOwnership;
  end;

{ TFiler }

  TValueType = (vaNull, vaList, vaInt8, vaInt16, vaInt32, vaExtended,
    vaString, vaIdent, vaFalse, vaTrue, vaBinary, vaSet, vaLString,
    vaNil, vaCollection, vaSingle, vaCurrency, vaDate, vaWString, vaInt64);

  TFilerFlag = (ffInherited, ffChildPos, ffInline);
  TFilerFlags = set of TFilerFlag;

  TReaderProc = procedure(Reader: TReader) of object;
  TWriterProc = procedure(Writer: TWriter) of object;
  TStreamProc = procedure(Stream: TStream) of object;

  TFiler = class(TObject)
  private
    FStream: TStream;
    FBuffer: Pointer;
    FBufSize: Integer;
    FBufPos: Integer;
    FBufEnd: Integer;
    FRoot: TComponent;
    FLookupRoot: TComponent;
    FAncestor: TPersistent;
    FIgnoreChildren: Boolean;
  protected
    procedure SetRoot(Value: TComponent); virtual;
  public
    constructor Create(Stream: TStream; BufSize: Integer);
    destructor Destroy; override;
    procedure DefineProperty(const Name: string;
      ReadData: TReaderProc; WriteData: TWriterProc;
      HasData: Boolean); virtual; abstract;
    procedure DefineBinaryProperty(const Name: string;
      ReadData, WriteData: TStreamProc;
      HasData: Boolean); virtual; abstract;
    procedure FlushBuffer; virtual; abstract;
    property Root: TComponent read FRoot write SetRoot;
    property LookupRoot: TComponent read FLookupRoot;
    property Ancestor: TPersistent read FAncestor write FAncestor;
    property IgnoreChildren: Boolean read FIgnoreChildren write FIgnoreChildren;
  end;

{ TComponent class reference type }

  TComponentClass = class of TComponent;

{ TReader }

  TFindMethodEvent = procedure(Reader: TReader; const MethodName: string;
    var Address: Pointer; var Error: Boolean) of object;
  TSetNameEvent = procedure(Reader: TReader; Component: TComponent;
    var Name: string) of object;
  TReferenceNameEvent = procedure(Reader: TReader; var Name: string) of object;
  TAncestorNotFoundEvent = procedure(Reader: TReader; const ComponentName: string;
    ComponentClass: TPersistentClass; var Component: TComponent) of object;
  TReadComponentsProc = procedure(Component: TComponent) of object;
  TReaderError = procedure(Reader: TReader; const Message: string; var Handled: Boolean) of object;
  TFindComponentClassEvent = procedure(Reader: TReader; const ClassName: string;
    var ComponentClass: TComponentClass) of object;
  TCreateComponentEvent = procedure(Reader: TReader;
    ComponentClass: TComponentClass; var Component: TComponent) of object;

  TReader = class(TFiler)
  private
    FOwner: TComponent;
    FParent: TComponent;
    FFixups: TList;
    FLoaded: TList;
    FOnFindMethod: TFindMethodEvent;
    FOnSetName: TSetNameEvent;
    FOnReferenceName: TReferenceNameEvent;
    FOnAncestorNotFound: TAncestorNotFoundEvent;
    FOnError: TReaderError;
    FOnFindComponentClass: TFindComponentClassEvent;
    FOnCreateComponent: TCreateComponentEvent;
    FPropName: string;
    FCanHandleExcepts: Boolean;
    procedure DoFixupReferences;
    procedure FreeFixups;
    function GetPosition: Longint;
    procedure ReadBuffer;
    procedure ReadDataInner(Instance: TComponent);
    function FindComponentClass(const ClassName: string): TComponentClass;
  protected
    function Error(const Message: string): Boolean; virtual;
    function FindAncestorComponent(const Name: string;
      ComponentClass: TPersistentClass): TComponent; virtual;
    function FindMethod(Root: TComponent; const MethodName: string): Pointer; virtual;
    procedure SetName(Component: TComponent; var Name: string); virtual;
    procedure ReadProperty(AInstance: TPersistent);
    procedure ReadPropValue(Instance: TPersistent; PropInfo: Pointer);
    procedure ReferenceName(var Name: string); virtual;
    procedure PropertyError;
    procedure ReadData(Instance: TComponent);
    function ReadSet(SetType: Pointer): Integer;
    procedure SetPosition(Value: Longint);
    procedure SkipSetBody;
    procedure SkipValue;
    procedure SkipProperty;
    procedure SkipComponent(SkipHeader: Boolean);
    property PropName: string read FPropName;
    property CanHandleExceptions: Boolean read FCanHandleExcepts;
  public
    destructor Destroy; override;
    procedure BeginReferences;
    procedure CheckValue(Value: TValueType);
    procedure DefineProperty(const Name: string;
      ReadData: TReaderProc; WriteData: TWriterProc;
      HasData: Boolean); override;
    procedure DefineBinaryProperty(const Name: string;
      ReadData, WriteData: TStreamProc;
      HasData: Boolean); override;
    function EndOfList: Boolean;
    procedure EndReferences;
    procedure FixupReferences;
    procedure FlushBuffer; override;
    function NextValue: TValueType;
    procedure Read(var Buf; Count: Longint);
    function ReadBoolean: Boolean;
    function ReadChar: Char;
    procedure ReadCollection(Collection: TCollection);
    function ReadComponent(Component: TComponent): TComponent;
    procedure ReadComponents(AOwner, AParent: TComponent;
      Proc: TReadComponentsProc);
    function ReadFloat: Extended;
    function ReadSingle: Single;
    function ReadCurrency: Currency;
    function ReadDate: TDateTime;
    function ReadIdent: string;
    function ReadInteger: Longint;
    function ReadInt64: Int64;
    procedure ReadListBegin;
    procedure ReadListEnd;
    procedure ReadPrefix(var Flags: TFilerFlags; var AChildPos: Integer); virtual;
    function ReadRootComponent(Root: TComponent): TComponent;
    procedure ReadSignature;
    function ReadStr: string;
    function ReadString: string;
    function ReadWideString: WideString;
    function ReadValue: TValueType;
    procedure CopyValue(Writer: TWriter);
    property Owner: TComponent read FOwner write FOwner;
    property Parent: TComponent read FParent write FParent;
    property Position: Longint read GetPosition write SetPosition;
    property OnError: TReaderError read FOnError write FOnError;
    property OnFindMethod: TFindMethodEvent read FOnFindMethod write FOnFindMethod;
    property OnSetName: TSetNameEvent read FOnSetName write FOnSetName;
    property OnReferenceName: TReferenceNameEvent read FOnReferenceName write FOnReferenceName;
    property OnAncestorNotFound: TAncestorNotFoundEvent read FOnAncestorNotFound write FOnAncestorNotFound;
    property OnCreateComponent: TCreateComponentEvent read FOnCreateComponent write FOnCreateComponent;
    property OnFindComponentClass: TFindComponentClassEvent read FOnFindComponentClass write FOnFindComponentClass;
  end;

{ TWriter }

  TFindAncestorEvent = procedure (Writer: TWriter; Component: TComponent;
    const Name: string; var Ancestor, RootAncestor: TComponent) of object;

  TWriter = class(TFiler)
  private
    FRootAncestor: TComponent;
    FPropPath: string;
    FAncestorList: TList;
    FAncestorPos: Integer;
    FChildPos: Integer;
    FOnFindAncestor: TFindAncestorEvent;
    procedure AddAncestor(Component: TComponent);
    function GetPosition: Longint;
    procedure SetPosition(Value: Longint);
    procedure WriteBuffer;
    procedure WriteData(Instance: TComponent); virtual; // linker optimization
  protected
    procedure SetRoot(Value: TComponent); override;
    procedure WriteBinary(WriteData: TStreamProc);
    procedure WritePrefix(Flags: TFilerFlags; AChildPos: Integer);
    procedure WriteProperty(Instance: TPersistent; PropInfo: Pointer);
    procedure WriteProperties(Instance: TPersistent);
    procedure WritePropName(const PropName: string);
    procedure WriteValue(Value: TValueType);
  public
    destructor Destroy; override;
    procedure DefineProperty(const Name: string;
      ReadData: TReaderProc; WriteData: TWriterProc;
      HasData: Boolean); override;
    procedure DefineBinaryProperty(const Name: string;
      ReadData, WriteData: TStreamProc;
      HasData: Boolean); override;
    procedure FlushBuffer; override;
    procedure Write(const Buf; Count: Longint);
    procedure WriteBoolean(Value: Boolean);
    procedure WriteCollection(Value: TCollection);
    procedure WriteComponent(Component: TComponent);
    procedure WriteChar(Value: Char);
    procedure WriteDescendent(Root: TComponent; AAncestor: TComponent);
    procedure WriteFloat(const Value: Extended);
    procedure WriteSingle(const Value: Single);
    procedure WriteCurrency(const Value: Currency);
    procedure WriteDate(const Value: TDateTime);
    procedure WriteIdent(const Ident: string);
    procedure WriteInteger(Value: Longint); overload;
    procedure WriteInteger(Value: Int64); overload;
    procedure WriteListBegin;
    procedure WriteListEnd;
    procedure WriteRootComponent(Root: TComponent);
    procedure WriteSignature;
    procedure WriteStr(const Value: string);
    procedure WriteString(const Value: string);
    procedure WriteWideString(const Value: WideString);
    property Position: Longint read GetPosition write SetPosition;
    property RootAncestor: TComponent read FRootAncestor write FRootAncestor;
    property OnFindAncestor: TFindAncestorEvent read FOnFindAncestor write FOnFindAncestor;
  end;

{ TParser }

  TParser = class(TObject)
  private
    FStream: TStream;
    FOrigin: Longint;
    FBuffer: PChar;
    FBufPtr: PChar;
    FBufEnd: PChar;
    FSourcePtr: PChar;
    FSourceEnd: PChar;
    FTokenPtr: PChar;
    FStringPtr: PChar;
    FSourceLine: Integer;
    FSaveChar: Char;
    FToken: Char;
    FFloatType: Char;
    FWideStr: WideString;
    procedure ReadBuffer;
    procedure SkipBlanks;
  public
    constructor Create(Stream: TStream);
    destructor Destroy; override;
    procedure CheckToken(T: Char);
    procedure CheckTokenSymbol(const S: string);
    procedure Error(const Ident: string);
    procedure ErrorFmt(const Ident: string; const Args: array of const);
    procedure ErrorStr(const Message: string);
    procedure HexToBinary(Stream: TStream);
    function NextToken: Char;
    function SourcePos: Longint;
    function TokenComponentIdent: string;
    function TokenFloat: Extended;
    function TokenInt: Int64;
    function TokenString: string;
    function TokenWideString: WideString;
    function TokenSymbolIs(const S: string): Boolean;
    property FloatType: Char read FFloatType;
    property SourceLine: Integer read FSourceLine;
    property Token: Char read FToken;
  end;

{ TThread }

  EThread = class(Exception);

  TThreadMethod = procedure of object;
  TThreadPriority = (tpIdle, tpLowest, tpLower, tpNormal, tpHigher, tpHighest,
    tpTimeCritical);

  TThread = class
  private
    FHandle: THandle;
    FThreadID: THandle;
    FTerminated: Boolean;
    FSuspended: Boolean;
    FFreeOnTerminate: Boolean;
    FFinished: Boolean;
    FReturnValue: Integer;
    FOnTerminate: TNotifyEvent;
    FMethod: TThreadMethod;
    FSynchronizeException: TObject;
    procedure CallOnTerminate;
    function GetPriority: TThreadPriority;
    procedure SetPriority(Value: TThreadPriority);
    procedure SetSuspended(Value: Boolean);
  protected
    procedure DoTerminate; virtual;
    procedure Execute; virtual; abstract;
    procedure Synchronize(Method: TThreadMethod);
    property ReturnValue: Integer read FReturnValue write FReturnValue;
    property Terminated: Boolean read FTerminated;
  public
    constructor Create(CreateSuspended: Boolean);
    destructor Destroy; override;
    procedure Resume;
    procedure Suspend;
    procedure Terminate;
    function WaitFor: LongWord;
    property FreeOnTerminate: Boolean read FFreeOnTerminate write FFreeOnTerminate;
    property Handle: THandle read FHandle;
    property Priority: TThreadPriority read GetPriority write SetPriority;
    property Suspended: Boolean read FSuspended write SetSuspended;
    property ThreadID: THandle read FThreadID;
    property OnTerminate: TNotifyEvent read FOnTerminate write FOnTerminate;
  end;

{ TComponent class }

  TOperation = (opInsert, opRemove);
  TComponentState = set of (csLoading, csReading, csWriting, csDestroying,
    csDesigning, csAncestor, csUpdating, csFixups, csFreeNotification,
    csInline, csDesignInstance);
  TComponentStyle = set of (csInheritable, csCheckPropAvail);
  TGetChildProc = procedure (Child: TComponent) of object;

  TComponentName = type string;

  IVCLComObject = interface
    ['{E07892A0-F52F-11CF-BD2F-0020AF0E5B81}']
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
    function SafeCallException(ExceptObject: TObject;
      ExceptAddr: Pointer): HResult;
    procedure FreeOnRelease;
  end;

  IDesignerNotify = interface
    ['{B971E807-E3A6-11D1-AAB1-00C04FB16FBC}']
    procedure Modified;
    procedure Notification(AnObject: TPersistent; Operation: TOperation);
  end;  

  TBasicAction = class;

  TComponent = class(TPersistent)
  private
    FOwner: TComponent;
    FName: TComponentName;
    FTag: Longint;
    FComponents: TList;
    FFreeNotifies: TList;
    FDesignInfo: Longint;
    FVCLComObject: Pointer;
    FComponentState: TComponentState;
    function GetComObject: IUnknown;
    function GetComponent(AIndex: Integer): TComponent;
    function GetComponentCount: Integer;
    function GetComponentIndex: Integer;
    procedure Insert(AComponent: TComponent);
    procedure ReadLeft(Reader: TReader);
    procedure ReadTop(Reader: TReader);
    procedure Remove(AComponent: TComponent);
    procedure RemoveNotification(AComponent: TComponent);
    procedure SetComponentIndex(Value: Integer);
    procedure SetReference(Enable: Boolean);
    procedure WriteLeft(Writer: TWriter);
    procedure WriteTop(Writer: TWriter);
  protected
    FComponentStyle: TComponentStyle;
    procedure ChangeName(const NewName: TComponentName);
    procedure DefineProperties(Filer: TFiler); override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); dynamic;
    function GetChildOwner: TComponent; dynamic;
    function GetChildParent: TComponent; dynamic;
    function GetOwner: TPersistent; override;
    procedure Loaded; virtual;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); virtual;
    procedure ReadState(Reader: TReader); virtual;
    procedure SetAncestor(Value: Boolean);
    procedure SetDesigning(Value: Boolean; SetChildren: Boolean = True);
    procedure SetInline(Value: Boolean);
    procedure SetDesignInstance(Value: Boolean);
    procedure SetName(const NewName: TComponentName); virtual;
    procedure SetChildOrder(Child: TComponent; Order: Integer); dynamic;
    procedure SetParentComponent(Value: TComponent); dynamic;
    procedure Updating; dynamic;
    procedure Updated; dynamic;
    class procedure UpdateRegistry(Register: Boolean; const ClassID, ProgID: string); virtual;
    procedure ValidateRename(AComponent: TComponent;
      const CurName, NewName: string); virtual;
    procedure ValidateContainer(AComponent: TComponent); dynamic;
    procedure ValidateInsert(AComponent: TComponent); dynamic;
    procedure WriteState(Writer: TWriter); virtual;
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
  public
    constructor Create(AOwner: TComponent); virtual;
    destructor Destroy; override;
    procedure BeforeDestruction; override;
    procedure DestroyComponents;
    procedure Destroying;
    function ExecuteAction(Action: TBasicAction): Boolean; dynamic;
    function FindComponent(const AName: string): TComponent;
    procedure FreeNotification(AComponent: TComponent);
    procedure RemoveFreeNotification(AComponent: TComponent);
    procedure FreeOnRelease;
    function GetParentComponent: TComponent; dynamic;
    function GetNamePath: string; override;
    function HasParent: Boolean; dynamic;
    procedure InsertComponent(AComponent: TComponent);
    procedure RemoveComponent(AComponent: TComponent);
    function SafeCallException(ExceptObject: TObject;
      ExceptAddr: Pointer): HResult; override;
    function UpdateAction(Action: TBasicAction): Boolean; dynamic;
    property ComObject: IUnknown read GetComObject;
    property Components[Index: Integer]: TComponent read GetComponent;
    property ComponentCount: Integer read GetComponentCount;
    property ComponentIndex: Integer read GetComponentIndex write SetComponentIndex;
    property ComponentState: TComponentState read FComponentState;
    property ComponentStyle: TComponentStyle read FComponentStyle;
    property DesignInfo: Longint read FDesignInfo write FDesignInfo;
    property Owner: TComponent read FOwner;
    property VCLComObject: Pointer read FVCLComObject write FVCLComObject;
  published
    property Name: TComponentName read FName write SetName stored False;
    property Tag: Longint read FTag write FTag default 0;
  end;

{ TBasicActionLink }

  TBasicActionLink = class(TObject)
  private
    FOnChange: TNotifyEvent;
  protected
    FAction: TBasicAction;
    procedure AssignClient(AClient: TObject); virtual;
    procedure Change; virtual;
    function IsOnExecuteLinked: Boolean; virtual;
    procedure SetAction(Value: TBasicAction); virtual;
    procedure SetOnExecute(Value: TNotifyEvent); virtual;
  public
    constructor Create(AClient: TObject); virtual;
    destructor Destroy; override;
    function Execute: Boolean; virtual;
    function Update: Boolean; virtual;
    property Action: TBasicAction read FAction write SetAction;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

  TBasicActionLinkClass = class of TBasicActionLink;

{ TBasicAction }

  TBasicAction = class(TComponent)
  private
    FOnChange: TNotifyEvent;
    FOnExecute: TNotifyEvent;
    FOnUpdate: TNotifyEvent;
  protected
    FClients: TList;
    procedure Change; virtual;
    procedure SetOnExecute(Value: TNotifyEvent); virtual;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function HandlesTarget(Target: TObject): Boolean; virtual;
    procedure UpdateTarget(Target: TObject); virtual;
    procedure ExecuteTarget(Target: TObject); virtual;
    function Execute: Boolean; dynamic;
    procedure RegisterChanges(Value: TBasicActionLink);
    procedure UnRegisterChanges(Value: TBasicActionLink);
    function Update: Boolean; virtual;
    property OnExecute: TNotifyEvent read FOnExecute write SetOnExecute;
    property OnUpdate: TNotifyEvent read FOnUpdate write FOnUpdate;
  end;

{ TBasicAction class reference type }

  TBasicActionClass = class of TBasicAction;

{ Component registration handlers }

  TActiveXRegType = (axrComponentOnly, axrIncludeDescendants);

var
  RegisterComponentsProc: procedure(const Page: string;
    ComponentClasses: array of TComponentClass) = nil;
  RegisterNoIconProc: procedure(ComponentClasses: array of TComponentClass) = nil;
  RegisterNonActiveXProc: procedure(ComponentClasses: array of TComponentClass;
    AxRegType: TActiveXRegType) = nil;
  CurrentGroup: Integer = -1; { Current design group }
  CreateVCLComObjectProc: procedure(Component: TComponent) = nil;

{ Point and rectangle constructors }

function Point(AX, AY: Integer): TPoint;
function SmallPoint(AX, AY: SmallInt): TSmallPoint;
function Rect(ALeft, ATop, ARight, ABottom: Integer): TRect;
function Bounds(ALeft, ATop, AWidth, AHeight: Integer): TRect;

{ Class registration routines }

procedure RegisterClass(AClass: TPersistentClass);
procedure RegisterClasses(AClasses: array of TPersistentClass);
procedure RegisterClassAlias(AClass: TPersistentClass; const Alias: string);
procedure UnRegisterClass(AClass: TPersistentClass);
procedure UnRegisterClasses(AClasses: array of TPersistentClass);
procedure UnRegisterModuleClasses(Module: HMODULE);
function FindClass(const ClassName: string): TPersistentClass;
function GetClass(const AClassName: string): TPersistentClass;

{ Component registration routines }

procedure RegisterComponents(const Page: string;
  ComponentClasses: array of TComponentClass);
procedure RegisterNoIcon(ComponentClasses: array of TComponentClass);
procedure RegisterNonActiveX(ComponentClasses: array of TComponentClass;
  AxRegType: TActiveXRegType);

var
  GlobalNameSpace: TMultiReadExclusiveWriteSynchronizer;

{ Object filing routines }

type
  TIdentMapEntry = record
    Value: Integer;
    Name: String;
  end;

  TIdentToInt = function(const Ident: string; var Int: Longint): Boolean;
  TIntToIdent = function(Int: Longint; var Ident: string): Boolean;
  TFindGlobalComponent = function(const Name: string): TComponent;

var
  FindGlobalComponent: TFindGlobalComponent;

procedure RegisterIntegerConsts(IntegerType: Pointer; IdentToInt: TIdentToInt;
  IntToIdent: TIntToIdent);
function IdentToInt(const Ident: string; var Int: Longint; const Map: array of TIdentMapEntry): Boolean;
function IntToIdent(Int: Longint; var Ident: string; const Map: array of TIdentMapEntry): Boolean;
function FindIntToIdent(AIntegerType: Pointer): TIntToIdent;
function FindIdentToInt(AIntegerType: Pointer): TIdentToInt;

function InitInheritedComponent(Instance: TComponent; RootAncestor: TClass): Boolean;
function InitComponentRes(const ResName: string; Instance: TComponent): Boolean;
function ReadComponentRes(const ResName: string; Instance: TComponent): TComponent;
function ReadComponentResEx(HInstance: THandle; const ResName: string): TComponent;
function ReadComponentResFile(const FileName: string; Instance: TComponent): TComponent;
procedure WriteComponentResFile(const FileName: string; Instance: TComponent);

procedure GlobalFixupReferences;
procedure GetFixupReferenceNames(Root: TComponent; Names: TStrings);
procedure GetFixupInstanceNames(Root: TComponent;
  const ReferenceRootName: string; Names: TStrings);
procedure RedirectFixupReferences(Root: TComponent; const OldRootName,
  NewRootName: string);
procedure RemoveFixupReferences(Root: TComponent; const RootName: string);
procedure RemoveFixups(Instance: TPersistent);
function FindNestedComponent(Root: TComponent; const NamePath: string): TComponent;

procedure BeginGlobalLoading;
procedure NotifyGlobalLoading;
procedure EndGlobalLoading;

function CollectionsEqual(C1, C2: TCollection): Boolean;

{ Object conversion routines }

type
  TStreamOriginalFormat = (sofUnknown, sofBinary, sofText);

procedure ObjectBinaryToText(Input, Output: TStream); overload;
procedure ObjectBinaryToText(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat); overload;
procedure ObjectTextToBinary(Input, Output: TStream); overload;
procedure ObjectTextToBinary(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat); overload;

procedure ObjectResourceToText(Input, Output: TStream); overload;
procedure ObjectResourceToText(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat); overload;
procedure ObjectTextToResource(Input, Output: TStream); overload;
procedure ObjectTextToResource(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat); overload;

function TestStreamFormat(Stream: TStream): TStreamOriginalFormat;

{ Utility routines }

function LineStart(Buffer, BufPos: PChar): PChar;
function ExtractStrings(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings): Integer;

procedure BinToHex(Buffer, Text: PChar; BufSize: Integer);
function HexToBin(Text, Buffer: PChar; BufSize: Integer): Integer;

function FindRootDesigner(Obj: TPersistent): IDesignerNotify;

implementation

uses Consts, TypInfo;

const
  FilerSignature: array[1..4] of Char = 'TPF0';

var
  ClassList: TThreadList;
  ClassAliasList: TStringList;
  IntConstList: TThreadList;

{ Point and rectangle constructors }

function Point(AX, AY: Integer): TPoint;
begin
  with Result do
  begin
    X := AX;
    Y := AY;
  end;
end;

function SmallPoint(AX, AY: SmallInt): TSmallPoint;
begin
  with Result do
  begin
    X := AX;
    Y := AY;
  end;
end;

function Rect(ALeft, ATop, ARight, ABottom: Integer): TRect;
begin
  with Result do
  begin
    Left := ALeft;
    Top := ATop;
    Right := ARight;
    Bottom := ABottom;
  end;
end;

function Bounds(ALeft, ATop, AWidth, AHeight: Integer): TRect;
begin
  with Result do
  begin
    Left := ALeft;
    Top := ATop;
    Right := ALeft + AWidth;
    Bottom :=  ATop + AHeight;
  end;
end;

{ Class registration routines }

type
  PFieldClassTable = ^TFieldClassTable;
  TFieldClassTable = packed record
    Count: Smallint;
    Classes: array[0..8191] of ^TPersistentClass;
  end;

function GetFieldClassTable(AClass: TClass): PFieldClassTable; assembler;
asm
        MOV     EAX,[EAX].vmtFieldTable
        OR      EAX,EAX
        JE      @@1
        MOV     EAX,[EAX+2].Integer
@@1:
end;

procedure ClassNotFound(const ClassName: string);
begin
  raise EClassNotFound.CreateFmt(SClassNotFound, [ClassName]);
end;

function GetClass(const AClassName: string): TPersistentClass;
var
  I: Integer;
begin
  with ClassList.LockList do
  try     // ClassAliasList protected by ClassList lock
    for I := 0 to Count - 1 do
    begin
      Result := Items[I];
      if Result.ClassNameIs(AClassName) then Exit;
    end;
    I := ClassAliasList.IndexOf(AClassName);
    if I >= 0 then
    begin
      Result := TPersistentClass(ClassAliasList.Objects[I]);
      Exit;
    end;
    Result := nil;
  finally
    ClassList.UnlockList;
  end;
end;

function FindClass(const ClassName: string): TPersistentClass;
begin
  Result := GetClass(ClassName);
  if Result = nil then ClassNotFound(ClassName);
end;

function GetFieldClass(Instance: TObject;
  const ClassName: string): TPersistentClass;
var
  I: Integer;
  ClassTable: PFieldClassTable;
  ClassType: TClass;
begin
  ClassType := Instance.ClassType;
  while ClassType <> TPersistent do
  begin
    ClassTable := GetFieldClassTable(ClassType);
    if ClassTable <> nil then
      for I := 0 to ClassTable^.Count - 1 do
      begin
        Result := ClassTable^.Classes[I]^;
        if SameText(Result.ClassName, ClassName) then Exit;
      end;
    ClassType := ClassType.ClassParent;
  end;
  Result := GetClass(ClassName);
end;

procedure RegisterClass(AClass: TPersistentClass);
var
  AClassName: string;
begin
  with ClassList.LockList do
  try
    while IndexOf(AClass) = -1 do
    begin
      AClassName := AClass.ClassName;
      if GetClass(AClassName) <> nil then
        raise EFilerError.CreateResFmt(@SDuplicateClass, [AClassName]);
      Add(AClass);
      if AClass = TPersistent then Break;
      AClass := TPersistentClass(AClass.ClassParent);
    end;
  finally
    ClassList.UnlockList;
  end;
end;

procedure RegisterClasses(AClasses: array of TPersistentClass);
var
  I: Integer;
begin
  for I := Low(AClasses) to High(AClasses) do RegisterClass(AClasses[I]);
end;

procedure RegisterClassAlias(AClass: TPersistentClass; const Alias: string);
begin
  ClassList.LockList; // ClassAliasList protected by ClassList lock
  try
    RegisterClass(AClass);
    ClassAliasList.AddObject(Alias, TObject(AClass));
  finally
    ClassList.UnlockList;
  end;
end;

procedure UnRegisterClass(AClass: TPersistentClass);
begin
  ClassList.Remove(AClass);
end;

procedure UnRegisterClasses(AClasses: array of TPersistentClass);
var
  I: Integer;
begin
  for I := Low(AClasses) to High(AClasses) do UnRegisterClass(AClasses[I]);
end;

procedure UnRegisterModuleClasses(Module: HMODULE);
var
  I: Integer;
  M: TMemoryBasicInformation;
begin
  with ClassList.LockList do
  try
    for I := Count - 1 downto 0 do
    begin
      VirtualQuery(Items[I], M, SizeOf(M));
      if (Module = 0) or (HMODULE(M.AllocationBase) = Module) then
        Delete(I);
    end;
    // ClassAliasList protected by ClassList lock
    for I := ClassAliasList.Count - 1 downto 0 do
    begin
      VirtualQuery(Pointer(ClassAliasList.Objects[I]), M, SizeOf(M));
      if (Module = 0) or (HMODULE(M.AllocationBase) = Module) then
        ClassAliasList.Delete(I);
    end;
  finally
    ClassList.UnlockList;
  end;
end;

{ Component registration routines }

procedure RegisterComponents(const Page: string;
  ComponentClasses: array of TComponentClass);
begin
  if Assigned(RegisterComponentsProc) then
    RegisterComponentsProc(Page, ComponentClasses)
  else
    raise EComponentError.CreateRes(@SRegisterError);
end;

procedure RegisterNoIcon(ComponentClasses: array of TComponentClass);
begin
  if Assigned(RegisterNoIconProc) then
    RegisterNoIconProc(ComponentClasses)
  else
    raise EComponentError.CreateRes(@SRegisterError);
end;

procedure RegisterNonActiveX(ComponentClasses: array of TComponentClass;
  AxRegType: TActiveXRegType);
begin
  if not Assigned(RegisterNonActiveXProc) then
    raise EComponentError.CreateRes(@SRegisterError);
  RegisterNonActiveXProc(ComponentClasses, AxRegType)
end;

{ Component filing }

type
  TIntConst = class
    IntegerType: PTypeInfo;
    IdentToInt: TIdentToInt;
    IntToIdent: TIntToIdent;
    constructor Create(AIntegerType: PTypeInfo; AIdentToInt: TIdentToInt;
      AIntToIdent: TIntToIdent);
  end;

constructor TIntConst.Create(AIntegerType: PTypeInfo; AIdentToInt: TIdentToInt;
  AIntToIdent: TIntToIdent);
begin
  IntegerType := AIntegerType;
  IdentToInt := AIdentToInt;
  IntToIdent := AIntToIdent;
end;

procedure RegisterIntegerConsts(IntegerType: Pointer; IdentToInt: TIdentToInt;
  IntToIdent: TIntToIdent);
begin
  IntConstList.Add(TIntConst.Create(IntegerType, IdentToInt, IntToIdent));
end;

function FindIntToIdent(AIntegerType: Pointer): TIntToIdent;
var
  I: Integer;
begin
  Result := nil;
  with IntConstList.LockList do
  try
    for I := 0 to Count - 1 do
      with TIntConst(Items[I]) do
        if AIntegerType = IntegerType then
        begin
          Result := @IntToIdent;
          Exit;
        end;
  finally
    IntConstList.UnlockList;
  end;
end;

function FindIdentToInt(AIntegerType: Pointer): TIdentToInt;
var
  I: Integer;
begin
  Result := nil;
  with IntConstList.LockList do
  try
    for I := 0 to Count - 1 do
      with TIntConst(Items[I]) do
        if AIntegerType = IntegerType then
        begin
          Result := @IdentToInt;
          Exit;
        end;
  finally
    IntConstList.UnlockList;
  end;
end;

function IdentToInt(const Ident: string; var Int: Longint; const Map: array of TIdentMapEntry): Boolean;
var
  I: Integer;
begin
  for I := Low(Map) to High(Map) do
    if SameText(Map[I].Name, Ident) then
    begin
      Result := True;
      Int := Map[I].Value;
      Exit;
    end;
  Result := False;
end;

function IntToIdent(Int: Longint; var Ident: string; const Map: array of TIdentMapEntry): Boolean;
var
  I: Integer;
begin
  for I := Low(Map) to High(Map) do
    if Map[I].Value = Int then
    begin
      Result := True;
      Ident := Map[I].Name;
      Exit;
    end;
  Result := False;
end;


function InternalReadComponentRes(const ResName: string; HInst: THandle; var Instance: TComponent): Boolean;
var
  HRsrc: THandle;
begin                   { avoid possible EResNotFound exception }
  if HInst = 0 then HInst := HInstance;
  HRsrc := FindResource(HInst, PChar(ResName), RT_RCDATA);
  Result := HRsrc <> 0;
  if not Result then Exit;
  with TResourceStream.Create(HInst, ResName, RT_RCDATA) do
  try
    Instance := ReadComponent(Instance);
  finally
    Free;
  end;
  Result := True;
end;

threadvar
  GlobalLoaded: TList;
  GlobalLists: TList;

procedure BeginGlobalLoading;
begin
  if GlobalLists = nil then GlobalLists := TList.Create;
  GlobalLists.Add(GlobalLoaded);
  GlobalLoaded := TList.Create;
end;

procedure NotifyGlobalLoading;
var
  I: Integer;
  G: TList;
begin
  G := GlobalLoaded;  // performance:  eliminate repeated trips through TLS lookup
  for I := 0 to G.Count - 1 do
    TComponent(G[I]).Loaded;
end;

procedure EndGlobalLoading;
begin
  GlobalLoaded.Free;
  GlobalLoaded := GlobalLists.Last;
  GlobalLists.Delete(GlobalLists.Count - 1);
  if GlobalLists.Count = 0 then
    FreeAndNil(GlobalLists);
end;

function InitInheritedComponent(Instance: TComponent; RootAncestor: TClass): Boolean;

  function InitComponent(ClassType: TClass): Boolean;
  begin
    Result := False;
    if (ClassType = TComponent) or (ClassType = RootAncestor) then Exit;
    Result := InitComponent(ClassType.ClassParent);
    Result := InternalReadComponentRes(ClassType.ClassName, FindResourceHInstance(
      FindClassHInstance(ClassType)), Instance) or Result;
  end;

var
  LocalizeLoading: Boolean;
begin
  GlobalNameSpace.BeginWrite;  // hold lock across all ancestor loads (performance)
  try
    LocalizeLoading := (Instance.ComponentState * [csInline, csLoading]) = [];
    if LocalizeLoading then BeginGlobalLoading;  // push new loadlist onto stack
    try
      Result := InitComponent(Instance.ClassType);
      if LocalizeLoading then NotifyGlobalLoading;  // call Loaded
    finally
      if LocalizeLoading then EndGlobalLoading;  // pop loadlist off stack
    end;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

function InitComponentRes(const ResName: string; Instance: TComponent): Boolean;
begin
  Result := InternalReadComponentRes(ResName, FindResourceHInstance(
    FindClassHInstance(Instance.ClassType)), Instance);
end;

function ReadComponentRes(const ResName: string; Instance: TComponent): TComponent;
var
  HInstance: THandle;
begin
  if Instance <> nil then
    HInstance := FindResourceHInstance(FindClassHInstance(Instance.ClassType))
  else HInstance := 0;
  if InternalReadComponentRes(ResName, HInstance, Instance) then
    Result := Instance else
    raise EResNotFound.CreateFmt(SResNotFound, [ResName]);
end;

function ReadComponentResEx(HInstance: THandle; const ResName: string): TComponent;
var
  Instance: TComponent;
begin
  Instance := nil;
  if InternalReadComponentRes(ResName, HInstance, Instance) then
    Result := Instance else
    raise EResNotFound.CreateFmt(SResNotFound, [ResName]);
end;

function ReadComponentResFile(const FileName: string; Instance: TComponent): TComponent;
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    Result := Stream.ReadComponentRes(Instance);
  finally
    Stream.Free;
  end;
end;

procedure WriteComponentResFile(const FileName: string; Instance: TComponent);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    Stream.WriteComponentRes(Instance.ClassName, Instance);
  finally
    Stream.Free;
  end;
end;

function CollectionsEqual(C1, C2: TCollection): Boolean;
var
  S1, S2: TMemoryStream;

  procedure WriteCollection(Stream: TStream; Collection: TCollection);
  var
    Writer: TWriter;
  begin
    Writer := TWriter.Create(Stream, 1024);
    try
      Writer.WriteCollection(Collection);
    finally
      Writer.Free;
    end;
  end;

begin
  Result := False;
  if C1.ClassType <> C2.ClassType then Exit;
  if C1.Count <> C2.Count then Exit;
  S1 := TMemoryStream.Create;
  try
    WriteCollection(S1, C1);
    S2 := TMemoryStream.Create;
    try
      WriteCollection(S2, C2);
      Result := (S1.Size = S2.Size) and CompareMem(S1.Memory, S2.Memory, S1.Size);
    finally
      S2.Free;
    end;
  finally
    S1.Free;
  end;
end;

{ Utility routines }

function LineStart(Buffer, BufPos: PChar): PChar; assembler;
asm
        PUSH    EDI
        MOV     EDI,EDX
        MOV     ECX,EDX
        SUB     ECX,EAX
        SUB     ECX,1
        JBE     @@1
        MOV     EDX,EAX
        DEC     EDI
        MOV     AL,0AH
        STD
        REPNE   SCASB
        CLD
        MOV     EAX,EDX
        JNE     @@1
        LEA     EAX,[EDI+2]
@@1:    POP     EDI
end;

function ExtractStrings(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings): Integer;
var
  Head, Tail: PChar;
  EOS, InQuote: Boolean;
  QuoteChar: Char;
  Item: string;
begin
  Result := 0;
  if (Content = nil) or (Content^=#0) or (Strings = nil) then Exit;
  Tail := Content;
  InQuote := False;
  QuoteChar := #0;
  Strings.BeginUpdate;
  try
    repeat
      while Tail^ in WhiteSpace + [#13, #10] do Inc(Tail);
      Head := Tail;
      while True do
      begin
        while (InQuote and not (Tail^ in ['''', '"', #0])) or
          not (Tail^ in Separators + [#0, #13, #10, '''', '"']) do Inc(Tail);
        if Tail^ in ['''', '"'] then
        begin
          if (QuoteChar <> #0) and (QuoteChar = Tail^) then
            QuoteChar := #0
          else QuoteChar := Tail^;
          InQuote := QuoteChar <> #0;
          Inc(Tail);
        end else Break;
      end;
      EOS := Tail^ = #0;
      if (Head <> Tail) and (Head^ <> #0) then
      begin
        if Strings <> nil then
        begin
          SetString(Item, Head, Tail - Head);
          Strings.Add(Item);
        end;
        Inc(Result);
      end;
      Inc(Tail);
    until EOS;
  finally
    Strings.EndUpdate;
  end;
end;

{ TList }

destructor TList.Destroy;
begin
  Clear;
end;

function TList.Add(Item: Pointer): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    Grow;
  FList^[Result] := Item;
  Inc(FCount);
  if Item <> nil then
    Notify(Item, lnAdded);
end;

procedure TList.Clear;
begin
  SetCount(0);
  SetCapacity(0);
end;

procedure TList.Delete(Index: Integer);
var
  Temp: Pointer;
begin
  if (Index < 0) or (Index >= FCount) then
    Error(@SListIndexError, Index);
  Temp := Items[Index];
  Dec(FCount);
  if Index < FCount then
    System.Move(FList^[Index + 1], FList^[Index],
      (FCount - Index) * SizeOf(Pointer));
  if Temp <> nil then
    Notify(Temp, lnDeleted);
end;

class procedure TList.Error(const Msg: string; Data: Integer);

  function ReturnAddr: Pointer;
  asm
          MOV     EAX,[EBP+4]
  end;

begin
  raise EListError.CreateFmt(Msg, [Data]) at ReturnAddr;
end;

class procedure TList.Error(Msg: PResStringRec; Data: Integer);
begin
  TList.Error(LoadResString(Msg), Data);
end;

procedure TList.Exchange(Index1, Index2: Integer);
var
  Item: Pointer;
begin
  if (Index1 < 0) or (Index1 >= FCount) then
    Error(@SListIndexError, Index1);
  if (Index2 < 0) or (Index2 >= FCount) then
    Error(@SListIndexError, Index2);
  Item := FList^[Index1];
  FList^[Index1] := FList^[Index2];
  FList^[Index2] := Item;
end;

function TList.Expand: TList;
begin
  if FCount = FCapacity then
    Grow;
  Result := Self;
end;

function TList.First: Pointer;
begin
  Result := Get(0);
end;

function TList.Get(Index: Integer): Pointer;
begin
  if (Index < 0) or (Index >= FCount) then
    Error(@SListIndexError, Index);
  Result := FList^[Index];
end;

procedure TList.Grow;
var
  Delta: Integer;
begin
  if FCapacity > 64 then
    Delta := FCapacity div 4
  else
    if FCapacity > 8 then
      Delta := 16
    else
      Delta := 4;
  SetCapacity(FCapacity + Delta);
end;

function TList.IndexOf(Item: Pointer): Integer;
begin
  Result := 0;
  while (Result < FCount) and (FList^[Result] <> Item) do
    Inc(Result);
  if Result = FCount then
    Result := -1;
end;

procedure TList.Insert(Index: Integer; Item: Pointer);
begin
  if (Index < 0) or (Index > FCount) then
    Error(@SListIndexError, Index);
  if FCount = FCapacity then
    Grow;
  if Index < FCount then
    System.Move(FList^[Index], FList^[Index + 1],
      (FCount - Index) * SizeOf(Pointer));
  FList^[Index] := Item;
  Inc(FCount);
  if Item <> nil then
    Notify(Item, lnAdded);
end;

function TList.Last: Pointer;
begin
  Result := Get(FCount - 1);
end;

procedure TList.Move(CurIndex, NewIndex: Integer);
var
  Item: Pointer;
begin
  if CurIndex <> NewIndex then
  begin
    if (NewIndex < 0) or (NewIndex >= FCount) then
      Error(@SListIndexError, NewIndex);
    Item := Get(CurIndex);
    FList^[CurIndex] := nil;
    Delete(CurIndex);
    Insert(NewIndex, nil);
    FList^[NewIndex] := Item;
  end;
end;

procedure TList.Put(Index: Integer; Item: Pointer);
var
  Temp: Pointer;
begin
  if (Index < 0) or (Index >= FCount) then
    Error(@SListIndexError, Index);
  Temp := FList^[Index];
  FList^[Index] := Item;
  if Temp <> nil then
    Notify(Temp, lnDeleted);
  if Item <> nil then
    Notify(Item, lnAdded);
end;

function TList.Remove(Item: Pointer): Integer;
begin
  Result := IndexOf(Item);
  if Result >= 0 then
    Delete(Result);
end;

procedure TList.Pack;
var
  I: Integer;
begin
  for I := FCount - 1 downto 0 do
    if Items[I] = nil then
      Delete(I);
end;

procedure TList.SetCapacity(NewCapacity: Integer);
begin
  if (NewCapacity < FCount) or (NewCapacity > MaxListSize) then
    Error(@SListCapacityError, NewCapacity);
  if NewCapacity <> FCapacity then
  begin
    ReallocMem(FList, NewCapacity * SizeOf(Pointer));
    FCapacity := NewCapacity;
  end;
end;

procedure TList.SetCount(NewCount: Integer);
var
  I: Integer;
begin
  if (NewCount < 0) or (NewCount > MaxListSize) then
    Error(@SListCountError, NewCount);
  if NewCount > FCapacity then
    SetCapacity(NewCount);
  if NewCount > FCount then
    FillChar(FList^[FCount], (NewCount - FCount) * SizeOf(Pointer), 0)
  else
    for I := FCount - 1 downto NewCount do
      Delete(I);
  FCount := NewCount;
end;

procedure QuickSort(SortList: PPointerList; L, R: Integer;
  SCompare: TListSortCompare);
var
  I, J: Integer;
  P, T: Pointer;
begin
  repeat
    I := L;
    J := R;
    P := SortList^[(L + R) shr 1];
    repeat
      while SCompare(SortList^[I], P) < 0 do
        Inc(I);
      while SCompare(SortList^[J], P) > 0 do
        Dec(J);
      if I <= J then
      begin
        T := SortList^[I];
        SortList^[I] := SortList^[J];
        SortList^[J] := T;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then
      QuickSort(SortList, L, J, SCompare);
    L := I;
  until I >= R;
end;

procedure TList.Sort(Compare: TListSortCompare);
begin
  if (FList <> nil) and (Count > 0) then
    QuickSort(FList, 0, Count - 1, Compare);
end;

function TList.Extract(Item: Pointer): Pointer;
var
  I: Integer;
begin
  Result := nil;
  I := IndexOf(Item);
  if I >= 0 then
  begin
    Result := Item;
    FList^[I] := nil;
    Delete(I);
    Notify(Result, lnExtracted);
  end;
end;

procedure TList.Notify(Ptr: Pointer; Action: TListNotification);
begin
end;

{ TThreadList }

constructor TThreadList.Create;
begin
  inherited Create;
  InitializeCriticalSection(FLock);
  FList := TList.Create;
  FDuplicates := dupIgnore;
end;

destructor TThreadList.Destroy;
begin
  LockList;    // Make sure nobody else is inside the list.
  try
    FList.Free;
    inherited Destroy;
  finally
    UnlockList;
    DeleteCriticalSection(FLock);
  end;
end;

procedure TThreadList.Add(Item: Pointer);
begin
  LockList;
  try
    if (Duplicates = dupAccept) or
       (FList.IndexOf(Item) = -1) then
      FList.Add(Item)
    else if Duplicates = dupError then
      FList.Error(@SDuplicateItem, Integer(Item));
  finally
    UnlockList;
  end;
end;

procedure TThreadList.Clear;
begin
  LockList;
  try
    FList.Clear;
  finally
    UnlockList;
  end;
end;

function  TThreadList.LockList: TList;
begin
  EnterCriticalSection(FLock);
  Result := FList;
end;

procedure TThreadList.Remove(Item: Pointer);
begin
  LockList;
  try
    FList.Remove(Item);
  finally
    UnlockList;
  end;
end;

procedure TThreadList.UnlockList;
begin
  LeaveCriticalSection(FLock);
end;

{ TInterfaceList }

constructor TInterfaceList.Create;
begin
  inherited Create;
  FList := TThreadList.Create;
end;

destructor TInterfaceList.Destroy;
begin
  Clear;
  FList.Free;
  inherited Destroy;
end;

procedure TInterfaceList.Clear;
var
  I: Integer;
begin
  if FList <> nil then
  begin
    with FList.LockList do
    try
      for I := 0 to Count - 1 do
        IUnknown(List[I]) := nil;
      Clear;
    finally
      Self.FList.UnlockList;
    end;
  end;
end;

procedure TInterfaceList.Delete(Index: Integer);
begin
  with FList.LockList do
  try
    Self.Put(Index, nil);
    Delete(Index);
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.Expand: TInterfaceList;
begin
  with FList.LockList do
  try
    Expand;
    Result := Self;
  finally
    Self.FList.Unlocklist;
  end;
end;

function TInterfaceList.First: IUnknown;
begin
  Result := Get(0);
end;

function TInterfaceList.Get(Index: Integer): IUnknown;
begin
  with FList.LockList do
  try
    if (Index < 0) or (Index >= Count) then Error(@SListIndexError, Index);
    Result := IUnknown(List[Index]);
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.GetCapacity: Integer;
begin
  with FList.LockList do
  try
    Result := Capacity;
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.GetCount: Integer;
begin
  with FList.LockList do
  try
    Result := Count;
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.IndexOf(Item: IUnknown): Integer;
begin
  with FList.LockList do
  try
    Result := IndexOf(Pointer(Item));
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.Add(Item: IUnknown): Integer;
begin
  with FList.LockList do
  try
    Result := Add(nil);
    IUnknown(List[Result]) := Item;
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.Insert(Index: Integer; Item: IUnknown);
begin
  with FList.LockList do
  try
    Insert(Index, nil);
    IUnknown(List[Index]) := Item;
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.Last: IUnknown;
begin
  with FList.LockList do
  try
    Result := Self.Get(Count - 1);
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.Put(Index: Integer; Item: IUnknown);
begin
  with FList.LockList do
  try
    if (Index < 0) or (Index >= Count) then Error(@SListIndexError, Index);
    IUnknown(List[Index]) := Item;
  finally
    Self.FList.UnlockList;
  end;
end;

function TInterfaceList.Remove(Item: IUnknown): Integer;
begin
  with FList.LockList do
  try
    Result := IndexOf(Pointer(Item));
    if Result > -1 then
    begin
      IUnknown(List[Result]) := nil;
      Delete(Result);
    end;
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.SetCapacity(NewCapacity: Integer);
begin
  with FList.LockList do
  try
    Capacity := NewCapacity;
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.SetCount(NewCount: Integer);
begin
  with FList.LockList do
  try
    Count := NewCount;
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.Exchange(Index1, Index2: Integer);
begin
  with FList.LockList do
  try
    Exchange(Index1, Index2);
  finally
    Self.FList.UnlockList;
  end;
end;

procedure TInterfaceList.Lock;
begin
  FList.LockList;
end;

procedure TInterfaceList.Unlock;
begin
  FList.UnlockList;
end;

{ TBits }

const
  BitsPerInt = SizeOf(Integer) * 8;

type
  TBitEnum = 0..BitsPerInt - 1;
  TBitSet = set of TBitEnum;
  PBitArray = ^TBitArray;
  TBitArray = array[0..4096] of TBitSet;

destructor TBits.Destroy;
begin
  SetSize(0);
  inherited Destroy;
end;

procedure TBits.Error;
begin
  raise EBitsError.CreateRes(@SBitsIndexError);
end;

procedure TBits.SetSize(Value: Integer);
var
  NewMem: Pointer;
  NewMemSize: Integer;
  OldMemSize: Integer;

  function Min(X, Y: Integer): Integer;
  begin
    Result := X;
    if X > Y then Result := Y;
  end;

begin
  if Value <> Size then
  begin
    if Value < 0 then Error;
    NewMemSize := ((Value + BitsPerInt - 1) div BitsPerInt) * SizeOf(Integer);
    OldMemSize := ((Size + BitsPerInt - 1) div BitsPerInt) * SizeOf(Integer);
    if NewMemSize <> OldMemSize then
    begin
      NewMem := nil;
      if NewMemSize <> 0 then
      begin
        GetMem(NewMem, NewMemSize);
        FillChar(NewMem^, NewMemSize, 0);
      end;
      if OldMemSize <> 0 then
      begin
        if NewMem <> nil then
          Move(FBits^, NewMem^, Min(OldMemSize, NewMemSize));
        FreeMem(FBits, OldMemSize);
      end;
      FBits := NewMem;
    end;
    FSize := Value;
  end;
end;

procedure TBits.SetBit(Index: Integer; Value: Boolean); assembler;
asm
        CMP     Index,[EAX].FSize
        JAE     @@Size

@@1:    MOV     EAX,[EAX].FBits
        OR      Value,Value
        JZ      @@2
        BTS     [EAX],Index
        RET

@@2:    BTR     [EAX],Index
        RET

@@Size: CMP     Index,0
        JL      TBits.Error
        PUSH    Self
        PUSH    Index
        PUSH    ECX {Value}
        INC     Index
        CALL    TBits.SetSize
        POP     ECX {Value}
        POP     Index
        POP     Self
        JMP     @@1
end;

function TBits.GetBit(Index: Integer): Boolean; assembler;
asm
        CMP     Index,[EAX].FSize
        JAE     TBits.Error
        MOV     EAX,[EAX].FBits
        BT      [EAX],Index
        SBB     EAX,EAX
        AND     EAX,1
end;

function TBits.OpenBit: Integer;
var
  I: Integer;
  B: TBitSet;
  J: TBitEnum;
  E: Integer;
begin
  E := (Size + BitsPerInt - 1) div BitsPerInt - 1;
  for I := 0 to E do
    if PBitArray(FBits)^[I] <> [0..BitsPerInt - 1] then
    begin
      B := PBitArray(FBits)^[I];
      for J := Low(J) to High(J) do
      begin
        if not (J in B) then
        begin
          Result := I * BitsPerInt + J;
          if Result >= Size then Result := Size;
          Exit;
        end;
      end;
    end;
  Result := Size;
end;

{ TPersistent }

destructor TPersistent.Destroy;
begin
  RemoveFixups(Self);
  inherited Destroy;
end;

procedure TPersistent.Assign(Source: TPersistent);
begin
  if Source <> nil then Source.AssignTo(Self) else AssignError(nil);
end;

procedure TPersistent.AssignError(Source: TPersistent);
var
  SourceName: string;
begin
  if Source <> nil then
    SourceName := Source.ClassName else
    SourceName := 'nil';
  raise EConvertError.CreateResFmt(@SAssignError, [SourceName, ClassName]);
end;

procedure TPersistent.AssignTo(Dest: TPersistent);
begin
  Dest.AssignError(Self);
end;

procedure TPersistent.DefineProperties(Filer: TFiler);
begin
end;

function TPersistent.GetNamePath: string;
var
  S: string;
begin
  Result := ClassName;
  if (GetOwner <> nil) then
  begin
    S := GetOwner.GetNamePath;
    if S <> '' then
      Result := S + '.' + Result;
  end;
end;

function TPersistent.GetOwner: TPersistent;
begin
  Result := nil;
end;

{ TCollectionItem }

constructor TCollectionItem.Create(Collection: TCollection);
begin
  SetCollection(Collection);
end;

destructor TCollectionItem.Destroy;
begin
  SetCollection(nil);
  inherited Destroy;
end;

procedure TCollectionItem.Changed(AllItems: Boolean);
var
  Item: TCollectionItem;
begin
  if (FCollection <> nil) and (FCollection.FUpdateCount = 0) then
  begin
    if AllItems then Item := nil else Item := Self;
    FCollection.Update(Item);
  end;
end;

function TCollectionItem.GetIndex: Integer;
begin
  if FCollection <> nil then
    Result := FCollection.FItems.IndexOf(Self) else
    Result := -1;
end;

function TCollectionItem.GetDisplayName: string;
begin
  Result := ClassName;
end;

function TCollectionItem.GetNamePath: string;
begin
  if FCollection <> nil then
    Result := Format('%s[%d]',[FCollection.GetNamePath, Index])
  else
    Result := ClassName;
end;

function TCollectionItem.GetOwner: TPersistent;
begin
  Result := FCollection;
end;

procedure TCollectionItem.SetCollection(Value: TCollection);
begin
  if FCollection <> Value then
  begin
    if FCollection <> nil then FCollection.RemoveItem(Self);
    if Value <> nil then Value.InsertItem(Self);
  end;
end;

procedure TCollectionItem.SetDisplayName(const Value: string);
begin
  Changed(False);
end;

procedure TCollectionItem.SetIndex(Value: Integer);
var
  CurIndex: Integer;
begin
  CurIndex := GetIndex;
  if (CurIndex >= 0) and (CurIndex <> Value) then
  begin
    FCollection.FItems.Move(CurIndex, Value);
    Changed(True);
  end;
end;

{ TCollection }

constructor TCollection.Create(ItemClass: TCollectionItemClass);
begin
  FItemClass := ItemClass;
  FItems := TList.Create;
end;

destructor TCollection.Destroy;
begin
  FUpdateCount := 1;
  if FItems <> nil then Clear;
  FItems.Free;
  inherited Destroy;
end;

function TCollection.Add: TCollectionItem;
begin
  Result := FItemClass.Create(Self);
end;

procedure TCollection.Assign(Source: TPersistent);
var
  I: Integer;
begin
  if Source is TCollection then
  begin
    BeginUpdate;
    try
      Clear;
      for I := 0 to TCollection(Source).Count - 1 do
        Add.Assign(TCollection(Source).Items[I]);
    finally
      EndUpdate;
    end;
    Exit;
  end;
  inherited Assign(Source);
end;

procedure TCollection.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TCollection.Changed;
begin
  if FUpdateCount = 0 then Update(nil);
end;

procedure TCollection.Clear;
begin
  if FItems.Count > 0 then
  begin
    BeginUpdate;
    try
      while FItems.Count > 0 do TCollectionItem(FItems.Last).Free;
    finally
      EndUpdate;
    end;
  end;
end;

procedure TCollection.EndUpdate;
begin
  Dec(FUpdateCount);
  Changed;
end;

function TCollection.FindItemID(ID: Integer): TCollectionItem;
var
  I: Integer;
begin
  for I := 0 to FItems.Count-1 do
  begin
    Result := TCollectionItem(FItems[I]);
    if Result.ID = ID then Exit;
  end;
  Result := nil;
end;

function TCollection.GetAttrCount: Integer;
begin
  Result := 0;
end;

function TCollection.GetAttr(Index: Integer): string;
begin
  Result := '';
end;

function TCollection.GetItemAttr(Index, ItemIndex: Integer): string;
begin
  Result := Items[ItemIndex].DisplayName;
end;

function TCollection.GetCount: Integer;
begin
  Result := FItems.Count;
end;

function TCollection.GetItem(Index: Integer): TCollectionItem;
begin
  Result := FItems[Index];
end;

function TCollection.GetNamePath: string;
var
  S, P: string;
begin
  Result := ClassName;
  if GetOwner = nil then Exit;
  S := GetOwner.GetNamePath;
  if S = '' then Exit;
  P := PropName;
  if P = '' then Exit;
  Result := S + '.' + P;
end;

function TCollection.GetPropName: string;
var
  I: Integer;
  Props: PPropList;
  TypeData: PTypeData;
  Owner: TPersistent;
begin
  Result := FPropName;
  Owner := GetOwner;
  if (Result <> '') or (Owner = nil) or (Owner.ClassInfo = nil) then Exit;
  TypeData := GetTypeData(Owner.ClassInfo);
  if (TypeData = nil) or (TypeData^.PropCount = 0) then Exit;
  GetMem(Props, TypeData^.PropCount * sizeof(Pointer));
  try
    GetPropInfos(Owner.ClassInfo, Props);
    for I := 0 to TypeData^.PropCount-1 do
    begin
      with Props^[I]^ do
        if (PropType^^.Kind = tkClass) and
          (GetOrdProp(Owner, Props^[I]) = Integer(Self)) then
          FPropName := Name;
    end;
  finally
    Freemem(Props);
  end;
  Result := FPropName;
end;

function TCollection.Insert(Index: Integer): TCollectionItem;
begin
  Result := Add;
  Result.Index := Index;
end;

// Out param is more code efficient for interfaces than function result
procedure GetDesigner(Obj: TPersistent; out Result: IDesignerNotify);
var
  Temp: TPersistent;
begin
  Result := nil;
  if Obj = nil then Exit;
  Temp := Obj.GetOwner;
  if Temp = nil then
  begin
    if (Obj is TComponent) and (csDesigning in TComponent(Obj).ComponentState) then
      TComponent(Obj).QueryInterface(IDesignerNotify, Result);
  end
  else
  begin
    if (Obj is TComponent) and
      not (csDesigning in TComponent(Obj).ComponentState) then Exit;
    GetDesigner(Temp, Result);
  end;
end;

function FindRootDesigner(Obj: TPersistent): IDesignerNotify;
begin
  GetDesigner(Obj, Result);
end;

procedure NotifyDesigner(Self, Item: TPersistent; Operation: TOperation);
var
  Designer: IDesignerNotify;
begin
  GetDesigner(Self, Designer);
  if Designer <> nil then
    Designer.Notification(Item, Operation);
end;

procedure TCollection.InsertItem(Item: TCollectionItem);
begin
  if not (Item is FItemClass) then TList.Error(@SInvalidProperty, 0);
  FItems.Add(Item);
  Item.FCollection := Self;
  Item.FID := FNextID;
  Inc(FNextID);
  SetItemName(Item);
  Changed;
  NotifyDesigner(Self, Item, opInsert);
end;

procedure TCollection.RemoveItem(Item: TCollectionItem);
begin
  NotifyDesigner(Self, Item, opRemove);
  FItems.Remove(Item);
  Item.FCollection := nil;
  Changed;
end;

procedure TCollection.SetItem(Index: Integer; Value: TCollectionItem);
begin
  TCollectionItem(FItems[Index]).Assign(Value);
end;

procedure TCollection.SetItemName(Item: TCollectionItem);
begin
end;

procedure TCollection.Update(Item: TCollectionItem);
begin
end;

procedure TCollection.Delete(Index: Integer);
begin
  TCollectionItem(FItems[Index]).Free;
end;

{ TOwnedCollection }

constructor TOwnedCollection.Create(AOwner: TPersistent;
  ItemClass: TCollectionItemClass);
begin
  FOwner := AOwner;
  inherited Create(ItemClass);
end;

function TOwnedCollection.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

{ TStrings }

destructor TStrings.Destroy;
begin
  StringsAdapter := nil;
  inherited Destroy;
end;

function TStrings.Add(const S: string): Integer;
begin
  Result := GetCount;
  Insert(Result, S);
end;

function TStrings.AddObject(const S: string; AObject: TObject): Integer;
begin
  Result := Add(S);
  PutObject(Result, AObject);
end;

procedure TStrings.Append(const S: string);
begin
  Add(S);
end;

procedure TStrings.AddStrings(Strings: TStrings);
var
  I: Integer;
begin
  BeginUpdate;
  try
    for I := 0 to Strings.Count - 1 do
      AddObject(Strings[I], Strings.Objects[I]);
  finally
    EndUpdate;
  end;
end;

procedure TStrings.Assign(Source: TPersistent);
begin
  if Source is TStrings then
  begin
    BeginUpdate;
    try
      Clear;
      AddStrings(TStrings(Source));
    finally
      EndUpdate;
    end;
    Exit;
  end;
  inherited Assign(Source);
end;

procedure TStrings.BeginUpdate;
begin
  if FUpdateCount = 0 then SetUpdateState(True);
  Inc(FUpdateCount);
end;

procedure TStrings.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
    begin
      Result := True;
      if Filer.Ancestor is TStrings then
        Result := not Equals(TStrings(Filer.Ancestor))
    end
    else Result := Count > 0;
  end;

begin
  Filer.DefineProperty('Strings', ReadData, WriteData, DoWrite);
end;

procedure TStrings.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then SetUpdateState(False);
end;

function TStrings.Equals(Strings: TStrings): Boolean;
var
  I, Count: Integer;
begin
  Result := False;
  Count := GetCount;
  if Count <> Strings.GetCount then Exit;
  for I := 0 to Count - 1 do if Get(I) <> Strings.Get(I) then Exit;
  Result := True;
end;

procedure TStrings.Error(const Msg: string; Data: Integer);

  function ReturnAddr: Pointer;
  asm
          MOV     EAX,[EBP+4]
  end;

begin
  raise EStringListError.CreateFmt(Msg, [Data]) at ReturnAddr;
end;

procedure TStrings.Error(Msg: PResStringRec; Data: Integer);
begin
  Error(LoadResString(Msg), Data);
end;

procedure TStrings.Exchange(Index1, Index2: Integer);
var
  TempObject: TObject;
  TempString: string;
begin
  BeginUpdate;
  try
    TempString := Strings[Index1];
    TempObject := Objects[Index1];
    Strings[Index1] := Strings[Index2];
    Objects[Index1] := Objects[Index2];
    Strings[Index2] := TempString;
    Objects[Index2] := TempObject;
  finally
    EndUpdate;
  end;
end;

function TStrings.GetCapacity: Integer;
begin  // descendants may optionally override/replace this default implementation
  Result := Count;
end;

function TStrings.GetCommaText: string;
var
  S: string;
  P: PChar;
  I, Count: Integer;
begin
  Count := GetCount;
  if (Count = 1) and (Get(0) = '') then
    Result := '""'
  else
  begin
    Result := '';
    for I := 0 to Count - 1 do
    begin
      S := Get(I);
      P := PChar(S);
      while not (P^ in [#0..' ','"',',']) do P := CharNext(P);
      if (P^ <> #0) then S := AnsiQuotedStr(S, '"');
      Result := Result + S + ',';
    end;
    System.Delete(Result, Length(Result), 1);
  end;
end;

function TStrings.GetName(Index: Integer): string;
var
  P: Integer;
begin
  Result := Get(Index);
  P := AnsiPos('=', Result);
  if P <> 0 then
    SetLength(Result, P-1) else
    SetLength(Result, 0);
end;

function TStrings.GetObject(Index: Integer): TObject;
begin
  Result := nil;
end;

function TStrings.GetText: PChar;
begin
  Result := StrNew(PChar(GetTextStr));
end;

function TStrings.GetTextStr: string;
var
  I, L, Size, Count: Integer;
  P: PChar;
  S: string;
begin
  Count := GetCount;
  Size := 0;
  for I := 0 to Count - 1 do Inc(Size, Length(Get(I)) + 2);
  SetString(Result, nil, Size);
  P := Pointer(Result);
  for I := 0 to Count - 1 do
  begin
    S := Get(I);
    L := Length(S);
    if L <> 0 then
    begin
      System.Move(Pointer(S)^, P^, L);
      Inc(P, L);
    end;
    P^ := #13;
    Inc(P);
    P^ := #10;
    Inc(P);
  end;
end;

function TStrings.GetValue(const Name: string): string;
var
  I: Integer;
begin
  I := IndexOfName(Name);
  if I >= 0 then
    Result := Copy(Get(I), Length(Name) + 2, MaxInt) else
    Result := '';
end;

function TStrings.IndexOf(const S: string): Integer;
begin
  for Result := 0 to GetCount - 1 do
    if AnsiCompareText(Get(Result), S) = 0 then Exit;
  Result := -1;
end;

function TStrings.IndexOfName(const Name: string): Integer;
var
  P: Integer;
  S: string;
begin
  for Result := 0 to GetCount - 1 do
  begin
    S := Get(Result);
    P := AnsiPos('=', S);
    if (P <> 0) and (AnsiCompareText(Copy(S, 1, P - 1), Name) = 0) then Exit;
  end;
  Result := -1;
end;

function TStrings.IndexOfObject(AObject: TObject): Integer;
begin
  for Result := 0 to GetCount - 1 do
    if GetObject(Result) = AObject then Exit;
  Result := -1;
end;

procedure TStrings.InsertObject(Index: Integer; const S: string;
  AObject: TObject);
begin
  Insert(Index, S);
  PutObject(Index, AObject);
end;

procedure TStrings.LoadFromFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TStrings.LoadFromStream(Stream: TStream);
var
  Size: Integer;
  S: string;
begin
  BeginUpdate;
  try
    Size := Stream.Size - Stream.Position;
    SetString(S, nil, Size);
    Stream.Read(Pointer(S)^, Size);
    SetTextStr(S);
  finally
    EndUpdate;
  end;
end;

procedure TStrings.Move(CurIndex, NewIndex: Integer);
var
  TempObject: TObject;
  TempString: string;
begin
  if CurIndex <> NewIndex then
  begin
    BeginUpdate;
    try
      TempString := Get(CurIndex);
      TempObject := GetObject(CurIndex);
      Delete(CurIndex);
      InsertObject(NewIndex, TempString, TempObject);
    finally
      EndUpdate;
    end;
  end;
end;

procedure TStrings.Put(Index: Integer; const S: string);
var
  TempObject: TObject;
begin
  TempObject := GetObject(Index);
  Delete(Index);
  InsertObject(Index, S, TempObject);
end;

procedure TStrings.PutObject(Index: Integer; AObject: TObject);
begin
end;

procedure TStrings.ReadData(Reader: TReader);
begin
  Reader.ReadListBegin;
  BeginUpdate;
  try
    Clear;
    while not Reader.EndOfList do Add(Reader.ReadString);
  finally
    EndUpdate;
  end;
  Reader.ReadListEnd;
end;

procedure TStrings.SaveToFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TStrings.SaveToStream(Stream: TStream);
var
  S: string;
begin
  S := GetTextStr;
  Stream.WriteBuffer(Pointer(S)^, Length(S));
end;

procedure TStrings.SetCapacity(NewCapacity: Integer);
begin
  // do nothing - descendants may optionally implement this method
end;

procedure TStrings.SetCommaText(const Value: string);
var
  P, P1: PChar;
  S: string;
begin
  BeginUpdate;
  try
    Clear;
    P := PChar(Value);
    while P^ in [#1..' '] do P := CharNext(P);
    while P^ <> #0 do
    begin
      if P^ = '"' then
        S := AnsiExtractQuotedStr(P, '"')
      else
      begin
        P1 := P;
        while (P^ > ' ') and (P^ <> ',') do P := CharNext(P);
        SetString(S, P1, P - P1);
      end;
      Add(S);
      while P^ in [#1..' '] do P := CharNext(P);
      if P^ = ',' then
        repeat
          P := CharNext(P);
        until not (P^ in [#1..' ']);
    end;
  finally
    EndUpdate;
  end;
end;

procedure TStrings.SetStringsAdapter(const Value: IStringsAdapter);
begin
  if FAdapter <> nil then FAdapter.ReleaseStrings;
  FAdapter := Value;
  if FAdapter <> nil then FAdapter.ReferenceStrings(Self);
end;

procedure TStrings.SetText(Text: PChar);
begin
  SetTextStr(Text);
end;

procedure TStrings.SetTextStr(const Value: string);
var
  P, Start: PChar;
  S: string;
begin
  BeginUpdate;
  try
    Clear;
    P := Pointer(Value);
    if P <> nil then
      while P^ <> #0 do
      begin
        Start := P;
        while not (P^ in [#0, #10, #13]) do Inc(P);
        SetString(S, Start, P - Start);
        Add(S);
        if P^ = #13 then Inc(P);
        if P^ = #10 then Inc(P);
      end;
  finally
    EndUpdate;
  end;
end;

procedure TStrings.SetUpdateState(Updating: Boolean);
begin
end;

procedure TStrings.SetValue(const Name, Value: string);
var
  I: Integer;
begin
  I := IndexOfName(Name);
  if Value <> '' then
  begin
    if I < 0 then I := Add('');
    Put(I, Name + '=' + Value);
  end else
  begin
    if I >= 0 then Delete(I);
  end;
end;

procedure TStrings.WriteData(Writer: TWriter);
var
  I: Integer;
begin
  Writer.WriteListBegin;
  for I := 0 to Count - 1 do Writer.WriteString(Get(I));
  Writer.WriteListEnd;
end;

{ TStringList }

destructor TStringList.Destroy;
begin
  FOnChange := nil;
  FOnChanging := nil;
  inherited Destroy;
  if FCount <> 0 then Finalize(FList^[0], FCount);
  FCount := 0;
  SetCapacity(0);
end;

function TStringList.Add(const S: string): Integer;
begin
  if not Sorted then
    Result := FCount
  else
    if Find(S, Result) then
      case Duplicates of
        dupIgnore: Exit;
        dupError: Error(@SDuplicateString, 0);
      end;
  InsertItem(Result, S);
end;

procedure TStringList.Changed;
begin
  if (FUpdateCount = 0) and Assigned(FOnChange) then FOnChange(Self);
end;

procedure TStringList.Changing;
begin
  if (FUpdateCount = 0) and Assigned(FOnChanging) then FOnChanging(Self);
end;

procedure TStringList.Clear;
begin
  if FCount <> 0 then
  begin
    Changing;
    Finalize(FList^[0], FCount);
    FCount := 0;
    SetCapacity(0);
    Changed;
  end;
end;

procedure TStringList.Delete(Index: Integer);
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  Finalize(FList^[Index]);
  Dec(FCount);
  if Index < FCount then
    System.Move(FList^[Index + 1], FList^[Index],
      (FCount - Index) * SizeOf(TStringItem));
  Changed;
end;

procedure TStringList.Exchange(Index1, Index2: Integer);
begin
  if (Index1 < 0) or (Index1 >= FCount) then Error(@SListIndexError, Index1);
  if (Index2 < 0) or (Index2 >= FCount) then Error(@SListIndexError, Index2);
  Changing;
  ExchangeItems(Index1, Index2);
  Changed;
end;

procedure TStringList.ExchangeItems(Index1, Index2: Integer);
var
  Temp: Integer;
  Item1, Item2: PStringItem;
begin
  Item1 := @FList^[Index1];
  Item2 := @FList^[Index2];
  Temp := Integer(Item1^.FString);
  Integer(Item1^.FString) := Integer(Item2^.FString);
  Integer(Item2^.FString) := Temp;
  Temp := Integer(Item1^.FObject);
  Integer(Item1^.FObject) := Integer(Item2^.FObject);
  Integer(Item2^.FObject) := Temp;
end;

function TStringList.Find(const S: string; var Index: Integer): Boolean;
var
  L, H, I, C: Integer;
begin
  Result := False;
  L := 0;
  H := FCount - 1;
  while L <= H do
  begin
    I := (L + H) shr 1;
    C := AnsiCompareText(FList^[I].FString, S);
    if C < 0 then L := I + 1 else
    begin
      H := I - 1;
      if C = 0 then
      begin
        Result := True;
        if Duplicates <> dupAccept then L := I;
      end;
    end;
  end;
  Index := L;
end;

function TStringList.Get(Index: Integer): string;
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Result := FList^[Index].FString;
end;

function TStringList.GetCapacity: Integer;
begin
  Result := FCapacity;
end;

function TStringList.GetCount: Integer;
begin
  Result := FCount;
end;

function TStringList.GetObject(Index: Integer): TObject;
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Result := FList^[Index].FObject;
end;

procedure TStringList.Grow;
var
  Delta: Integer;
begin
  if FCapacity > 64 then Delta := FCapacity div 4 else
    if FCapacity > 8 then Delta := 16 else
      Delta := 4;
  SetCapacity(FCapacity + Delta);
end;

function TStringList.IndexOf(const S: string): Integer;
begin
  if not Sorted then Result := inherited IndexOf(S) else
    if not Find(S, Result) then Result := -1;
end;

procedure TStringList.Insert(Index: Integer; const S: string);
begin
  if Sorted then Error(@SSortedListError, 0);
  if (Index < 0) or (Index > FCount) then Error(@SListIndexError, Index);
  InsertItem(Index, S);
end;

procedure TStringList.InsertItem(Index: Integer; const S: string);
begin
  Changing;
  if FCount = FCapacity then Grow;
  if Index < FCount then
    System.Move(FList^[Index], FList^[Index + 1],
      (FCount - Index) * SizeOf(TStringItem));
  with FList^[Index] do
  begin
    Pointer(FString) := nil;
    FObject := nil;
    FString := S;
  end;
  Inc(FCount);
  Changed;
end;

procedure TStringList.Put(Index: Integer; const S: string);
begin
  if Sorted then Error(@SSortedListError, 0);
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  FList^[Index].FString := S;
  Changed;
end;

procedure TStringList.PutObject(Index: Integer; AObject: TObject);
begin
  if (Index < 0) or (Index >= FCount) then Error(@SListIndexError, Index);
  Changing;
  FList^[Index].FObject := AObject;
  Changed;
end;

procedure TStringList.QuickSort(L, R: Integer; SCompare: TStringListSortCompare);
var
  I, J, P: Integer;
begin
  repeat
    I := L;
    J := R;
    P := (L + R) shr 1;
    repeat
      while SCompare(Self, I, P) < 0 do Inc(I);
      while SCompare(Self, J, P) > 0 do Dec(J);
      if I <= J then
      begin
        ExchangeItems(I, J);
        if P = I then
          P := J
        else if P = J then
          P := I;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then QuickSort(L, J, SCompare);
    L := I;
  until I >= R;
end;

procedure TStringList.SetCapacity(NewCapacity: Integer);
begin
  ReallocMem(FList, NewCapacity * SizeOf(TStringItem));
  FCapacity := NewCapacity;
end;

procedure TStringList.SetSorted(Value: Boolean);
begin
  if FSorted <> Value then
  begin
    if Value then Sort;
    FSorted := Value;
  end;
end;

procedure TStringList.SetUpdateState(Updating: Boolean);
begin
  if Updating then Changing else Changed;
end;

function StringListAnsiCompare(List: TStringList; Index1, Index2: Integer): Integer;
begin
  Result := AnsiCompareText(List.FList^[Index1].FString,
                            List.FList^[Index2].FString);
end;

procedure TStringList.Sort;
begin
  CustomSort(StringListAnsiCompare);
end;

procedure TStringList.CustomSort(Compare: TStringListSortCompare);
begin
  if not Sorted and (FCount > 1) then
  begin
    Changing;
    QuickSort(0, FCount - 1, Compare);
    Changed;
  end;
end;

{ TStream }

function TStream.GetPosition: Longint;
begin
  Result := Seek(0, 1);
end;

procedure TStream.SetPosition(Pos: Longint);
begin
  Seek(Pos, 0);
end;

function TStream.GetSize: Longint;
var
  Pos: Longint;
begin
  Pos := Seek(0, 1);
  Result := Seek(0, 2);
  Seek(Pos, 0);
end;

procedure TStream.SetSize(NewSize: Longint);
begin
  // default = do nothing  (read-only streams, etc)
end;

procedure TStream.ReadBuffer(var Buffer; Count: Longint);
begin
  if (Count <> 0) and (Read(Buffer, Count) <> Count) then
    raise EReadError.CreateRes(@SReadError);
end;

procedure TStream.WriteBuffer(const Buffer; Count: Longint);
begin
  if (Count <> 0) and (Write(Buffer, Count) <> Count) then
    raise EWriteError.CreateRes(@SWriteError);
end;

function TStream.CopyFrom(Source: TStream; Count: Longint): Longint;
const
  MaxBufSize = $F000;
var
  BufSize, N: Integer;
  Buffer: PChar;
begin
  if Count = 0 then
  begin
    Source.Position := 0;
    Count := Source.Size;
  end;
  Result := Count;
  if Count > MaxBufSize then BufSize := MaxBufSize else BufSize := Count;
  GetMem(Buffer, BufSize);
  try
    while Count <> 0 do
    begin
      if Count > BufSize then N := BufSize else N := Count;
      Source.ReadBuffer(Buffer^, N);
      WriteBuffer(Buffer^, N);
      Dec(Count, N);
    end;
  finally
    FreeMem(Buffer, BufSize);
  end;
end;

function TStream.ReadComponent(Instance: TComponent): TComponent;
var
  Reader: TReader;
begin
  Reader := TReader.Create(Self, 4096);
  try
    Result := Reader.ReadRootComponent(Instance);
  finally
    Reader.Free;
  end;
end;

procedure TStream.WriteComponent(Instance: TComponent);
begin
  WriteDescendent(Instance, nil);
end;

procedure TStream.WriteDescendent(Instance, Ancestor: TComponent);
var
  Writer: TWriter;
begin
  Writer := TWriter.Create(Self, 4096);
  try
    Writer.WriteDescendent(Instance, Ancestor);
  finally
    Writer.Free;
  end;
end;

function TStream.ReadComponentRes(Instance: TComponent): TComponent;
begin
  ReadResHeader;
  Result := ReadComponent(Instance);
end;

procedure TStream.WriteComponentRes(const ResName: string; Instance: TComponent);
begin
  WriteDescendentRes(ResName, Instance, nil);
end;

procedure TStream.WriteResourceHeader(const ResName: string; out FixupInfo: Integer);
var
  HeaderSize: Integer;
  Header: array[0..79] of Char;
begin
  Byte((@Header[0])^) := $FF;
  Word((@Header[1])^) := 10;
  HeaderSize := StrLen(StrUpper(StrPLCopy(@Header[3], ResName, 63))) + 10;
  Word((@Header[HeaderSize - 6])^) := $1030;
  Longint((@Header[HeaderSize - 4])^) := 0;
  WriteBuffer(Header, HeaderSize);
  FixupInfo := Position;
end;

procedure TStream.FixupResourceHeader(FixupInfo: Integer);
var
  ImageSize: Integer;
begin
  ImageSize := Position - FixupInfo;
  Position := FixupInfo - 4;
  WriteBuffer(ImageSize, SizeOf(Longint));
  Position := FixupInfo + ImageSize;
end;

procedure TStream.WriteDescendentRes(const ResName: string; Instance,
  Ancestor: TComponent);
var
  FixupInfo: Integer;
begin
  WriteResourceHeader(ResName, FixupInfo);
  WriteDescendent(Instance, Ancestor);
  FixupResourceHeader(FixupInfo);
end;

procedure TStream.ReadResHeader;
var
  ReadCount: Cardinal;
  Header: array[0..79] of Char;
begin
  FillChar(Header, SizeOf(Header), 0);
  ReadCount := Read(Header, SizeOf(Header) - 1);
  if (Byte((@Header[0])^) = $FF) and (Word((@Header[1])^) = 10) then
    Seek(StrLen(Header + 3) + 10 - ReadCount, 1)
  else
    raise EInvalidImage.CreateRes(@SInvalidImage);
end;

{ THandleStream }

constructor THandleStream.Create(AHandle: Integer);
begin
  FHandle := AHandle;
end;

function THandleStream.Read(var Buffer; Count: Longint): Longint;
begin
  Result := FileRead(FHandle, Buffer, Count);
  if Result = -1 then Result := 0;
end;

function THandleStream.Write(const Buffer; Count: Longint): Longint;
begin
  Result := FileWrite(FHandle, Buffer, Count);
  if Result = -1 then Result := 0;
end;

function THandleStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  Result := FileSeek(FHandle, Offset, Origin);
end;

procedure THandleStream.SetSize(NewSize: Longint);
begin
  Seek(NewSize, soFromBeginning);
  Win32Check(SetEndOfFile(FHandle));
end;

{ TFileStream }

constructor TFileStream.Create(const FileName: string; Mode: Word);
begin
  if Mode = fmCreate then
  begin
    FHandle := FileCreate(FileName);
    if FHandle < 0 then
      raise EFCreateError.CreateResFmt(@SFCreateError, [FileName]);
  end else
  begin
    FHandle := FileOpen(FileName, Mode);
    if FHandle < 0 then
      raise EFOpenError.CreateResFmt(@SFOpenError, [FileName]);
  end;
end;

destructor TFileStream.Destroy;
begin
  if FHandle >= 0 then FileClose(FHandle);
end;


{ TCustomMemoryStream }

procedure TCustomMemoryStream.SetPointer(Ptr: Pointer; Size: Longint);
begin
  FMemory := Ptr;
  FSize := Size;
end;

function TCustomMemoryStream.Read(var Buffer; Count: Longint): Longint;
begin
  if (FPosition >= 0) and (Count >= 0) then
  begin
    Result := FSize - FPosition;
    if Result > 0 then
    begin
      if Result > Count then Result := Count;
      Move(Pointer(Longint(FMemory) + FPosition)^, Buffer, Result);
      Inc(FPosition, Result);
      Exit;
    end;
  end;
  Result := 0;
end;

function TCustomMemoryStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  case Origin of
    soFromBeginning: FPosition := Offset;
    soFromCurrent: Inc(FPosition, Offset);
    soFromEnd: FPosition := FSize + Offset;
  end;
  Result := FPosition;
end;

procedure TCustomMemoryStream.SaveToStream(Stream: TStream);
begin
  if FSize <> 0 then Stream.WriteBuffer(FMemory^, FSize);
end;

procedure TCustomMemoryStream.SaveToFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

{ TMemoryStream }

const
  MemoryDelta = $2000; { Must be a power of 2 }

destructor TMemoryStream.Destroy;
begin
  Clear;
  inherited Destroy;
end;

procedure TMemoryStream.Clear;
begin
  SetCapacity(0);
  FSize := 0;
  FPosition := 0;
end;

procedure TMemoryStream.LoadFromStream(Stream: TStream);
var
  Count: Longint;
begin
  Stream.Position := 0;
  Count := Stream.Size;
  SetSize(Count);
  if Count <> 0 then Stream.ReadBuffer(FMemory^, Count);
end;

procedure TMemoryStream.LoadFromFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TMemoryStream.SetCapacity(NewCapacity: Longint);
begin
  SetPointer(Realloc(NewCapacity), FSize);
  FCapacity := NewCapacity;
end;

procedure TMemoryStream.SetSize(NewSize: Longint);
var
  OldPosition: Longint;
begin
  OldPosition := FPosition;
  SetCapacity(NewSize);
  FSize := NewSize;
  if OldPosition > NewSize then Seek(0, soFromEnd);
end;

function TMemoryStream.Realloc(var NewCapacity: Longint): Pointer;
begin
  if NewCapacity > 0 then
    NewCapacity := (NewCapacity + (MemoryDelta - 1)) and not (MemoryDelta - 1);
  Result := Memory;
  if NewCapacity <> FCapacity then
  begin
    if NewCapacity = 0 then
    begin
      GlobalFreePtr(Memory);
      Result := nil;
    end else
    begin
      if Capacity = 0 then
        Result := GlobalAllocPtr(HeapAllocFlags, NewCapacity)
      else
        Result := GlobalReallocPtr(Memory, NewCapacity, HeapAllocFlags);
      if Result = nil then raise EStreamError.CreateRes(@SMemoryStreamError);
    end;
  end;
end;

function TMemoryStream.Write(const Buffer; Count: Longint): Longint;
var
  Pos: Longint;
begin
  if (FPosition >= 0) and (Count >= 0) then
  begin
    Pos := FPosition + Count;
    if Pos > 0 then
    begin
      if Pos > FSize then
      begin
        if Pos > FCapacity then
          SetCapacity(Pos);
        FSize := Pos;
      end;
      System.Move(Buffer, Pointer(Longint(FMemory) + FPosition)^, Count);
      FPosition := Pos;
      Result := Count;
      Exit;
    end;
  end;
  Result := 0;
end;

{ TStringStream }

constructor TStringStream.Create(const AString: string);
begin
  inherited Create;
  FDataString := AString;
end;

function TStringStream.Read(var Buffer; Count: Longint): Longint;
begin
  Result := Length(FDataString) - FPosition;
  if Result > Count then Result := Count;
  Move(PChar(@FDataString[FPosition + 1])^, Buffer, Result);
  Inc(FPosition, Result);
end;

function TStringStream.Write(const Buffer; Count: Longint): Longint;
begin
  Result := Count;
  SetLength(FDataString, (FPosition + Result));
  Move(Buffer, PChar(@FDataString[FPosition + 1])^, Result);
  Inc(FPosition, Result);
end;

function TStringStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  case Origin of
    soFromBeginning: FPosition := Offset;
    soFromCurrent: FPosition := FPosition + Offset;
    soFromEnd: FPosition := Length(FDataString) - Offset;
  end;
  if FPosition > Length(FDataString) then
    FPosition := Length(FDataString)
  else if FPosition < 0 then FPosition := 0;
  Result := FPosition;
end;

function TStringStream.ReadString(Count: Longint): string;
var
  Len: Integer;
begin
  Len := Length(FDataString) - FPosition;
  if Len > Count then Len := Count;
  SetString(Result, PChar(@FDataString[FPosition + 1]), Len);
  Inc(FPosition, Len);
end;

procedure TStringStream.WriteString(const AString: string);
begin
  Write(PChar(AString)^, Length(AString));
end;

procedure TStringStream.SetSize(NewSize: Longint);
begin
  SetLength(FDataString, NewSize);
  if FPosition > NewSize then FPosition := NewSize;
end;

{ TResourceStream }

constructor TResourceStream.Create(Instance: THandle; const ResName: string;
  ResType: PChar);
begin
  inherited Create;
  Initialize(Instance, PChar(ResName), ResType);
end;

constructor TResourceStream.CreateFromID(Instance: THandle; ResID: Integer;
  ResType: PChar);
begin
  inherited Create;
  Initialize(Instance, PChar(ResID), ResType);
end;

procedure TResourceStream.Initialize(Instance: THandle; Name, ResType: PChar);

  procedure Error;
  begin
    raise EResNotFound.CreateFmt(SResNotFound, [Name]);
  end;

begin
  HResInfo := FindResource(Instance, Name, ResType);
  if HResInfo = 0 then Error;
  HGlobal := LoadResource(Instance, HResInfo);
  if HGlobal = 0 then Error;
  SetPointer(LockResource(HGlobal), SizeOfResource(Instance, HResInfo));
end;

destructor TResourceStream.Destroy;
begin
  UnlockResource(HGlobal);
  FreeResource(HGlobal);
  inherited Destroy;
end;

function TResourceStream.Write(const Buffer; Count: Longint): Longint;
begin
  raise EStreamError.CreateRes(@SCantWriteResourceStreamError);
end;

{ TFiler }

constructor TFiler.Create(Stream: TStream; BufSize: Integer);
begin
  FStream := Stream;
  GetMem(FBuffer, BufSize);
  FBufSize := BufSize;
end;

destructor TFiler.Destroy;
begin
  if FBuffer <> nil then FreeMem(FBuffer, FBufSize);
end;

procedure TFiler.SetRoot(Value: TComponent);
begin
  FRoot := Value;
end;

{ TPropFixup }

type
  TPropFixup = class
    FInstance: TPersistent;
    FInstanceRoot: TComponent;
    FPropInfo: PPropInfo;
    FRootName: string;
    FName: string;
    constructor Create(Instance: TPersistent; InstanceRoot: TComponent;
      PropInfo: PPropInfo; const RootName, Name: string);
    function MakeGlobalReference: Boolean;
  end;

var
  GlobalFixupList: TThreadList;

constructor TPropFixup.Create(Instance: TPersistent; InstanceRoot: TComponent;
  PropInfo: PPropInfo; const RootName, Name: string);
begin
  FInstance := Instance;
  FInstanceRoot := InstanceRoot;
  FPropInfo := PropInfo;
  FRootName := RootName;
  FName := Name;
end;

function TPropFixup.MakeGlobalReference: Boolean;
var
  S: PChar;
  P: PChar;
begin
  Result := False;
  S := PChar(Pointer(FName));
  P := S;
  while not (P^ in ['.', #0]) do Inc(P);
  if P^ = #0 then Exit;
  SetString(FRootName, S, P - S);
  Delete(FName, 1, P - S + 1);
  Result := True;
end;

function FindNestedComponent(Root: TComponent; const NamePath: string): TComponent;
var
  Current, Found: TComponent;
  S, P: PChar;
  Name: string;
begin
  Result := nil;
  if NamePath = '' then Exit;
  Current := Root;
  P := PChar(Pointer(NamePath));
  while P^ <> #0 do
  begin
    S := P;
    while not (P^ in ['.', '-', #0]) do Inc(P);
    SetString(Name, S, P - S);
    Found := Current.FindComponent(Name);
    if (Found = nil) and SameText(Name, 'Owner') then                           { Do not translate }
      Found := Current;
    if Found = nil then Exit;
    if P^ = '.' then Inc(P);
    if P^ = '-' then Inc(P);
    if P^ = '>' then Inc(P);
    Current := Found;
  end;
  Result := Current;
end;

procedure GlobalFixupReferences;
var
  FinishedList: TList;
  NotFinishedList: TList;
  GlobalList: TList;
  I: Integer;
  Root: TComponent;
  Instance: TPersistent;
  Reference: Pointer;

  procedure AddFinished(Instance: TPersistent);
  begin
    if (FinishedList.IndexOf(Instance) < 0) and
      (NotFinishedList.IndexOf(Instance) >= 0) then
      FinishedList.Add(Instance);
  end;

  procedure AddNotFinished(Instance: TPersistent);
  var
    Index: Integer;
  begin
    Index := FinishedList.IndexOf(Instance);
    if Index <> -1 then FinishedList.Delete(Index);
    if NotFinishedList.IndexOf(Instance) < 0 then
      NotFinishedList.Add(Instance);
  end;

begin
  if Assigned(FindGlobalComponent) then
  begin
    // Fixup resolution requires a stable component / name space
    // Block construction and destruction of forms / datamodules during fixups
    GlobalNameSpace.BeginWrite;
    try
      GlobalList := GlobalFixupList.LockList;
      try
        if GlobalList.Count > 0 then
        begin
          FinishedList := TList.Create;
          try
            NotFinishedList := TList.Create;
            try
              I := 0;
              while I < GlobalList.Count do
                with TPropFixup(GlobalList[I]) do
                begin
                  Root := FindGlobalComponent(FRootName);
                  if (Root <> nil) or (GetOrdProp(FInstance, FPropInfo) <> 0) then
                  begin
                    if Root <> nil then
                    begin
                      Reference := FindNestedComponent(Root, FName);
                      SetOrdProp(FInstance, FPropInfo, Longint(Reference));
                    end;
                    AddFinished(FInstance);
                    GlobalList.Delete(I);
                    Free;
                  end else
                  begin
                    AddNotFinished(FInstance);
                    Inc(I);
                  end;
                end;
            finally
              NotFinishedList.Free;
            end;
            for I := 0 to FinishedList.Count - 1 do
            begin
              Instance := FinishedList[I];
              if Instance is TComponent then
                Exclude(TComponent(Instance).FComponentState, csFixups);
            end;
          finally
            FinishedList.Free;
          end;
        end;
      finally
        GlobalFixupList.UnlockList;
      end;
    finally
      GlobalNameSpace.EndWrite;
    end;
  end;
end;

function NameInStrings(Strings: TStrings; const Name: string): Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 0 to Strings.Count - 1 do
    if SameText(Name, Strings[I]) then Exit;
  Result := False;
end;

procedure GetFixupReferenceNames(Root: TComponent; Names: TStrings);
var
  I: Integer;
  Fixup: TPropFixup;
begin
  with GlobalFixupList.LockList do
  try
    for I := 0 to Count - 1 do
    begin
      Fixup := Items[I];
      if ((Root = nil) or (Fixup.FInstanceRoot = Root)) and
        not NameInStrings(Names, Fixup.FRootName) then
        Names.Add(Fixup.FRootName);
    end;
  finally
    GlobalFixupList.UnlockList;
  end;
end;

procedure RedirectFixupReferences(Root: TComponent; const OldRootName,
  NewRootName: string);
var
  I: Integer;
  Fixup: TPropFixup;
begin
  with GlobalFixupList.LockList do
  try
    for I := 0 to Count - 1 do
    begin
      Fixup := Items[I];
      if ((Root = nil) or (Fixup.FInstanceRoot = Root)) and
        SameText(OldRootName, Fixup.FRootName) then
        Fixup.FRootName := NewRootName;
    end;
    GlobalFixupReferences;
  finally
    GlobalFixupList.Unlocklist;
  end;
end;

procedure RemoveFixupReferences(Root: TComponent; const RootName: string);
var
  I: Integer;
  Fixup: TPropFixup;
begin
  if GlobalFixupList = nil then Exit;
  with GlobalFixupList.LockList do
  try
    for I := Count - 1 downto 0 do
    begin
      Fixup := Items[I];
      if ((Root = nil) or (Fixup.FInstanceRoot = Root)) and
        ((RootName = '') or SameText(RootName, Fixup.FRootName)) then
      begin
        Delete(I);
        Fixup.Free;
      end;
    end;
  finally
    GlobalFixupList.UnlockList;
  end;
end;

procedure RemoveFixups(Instance: TPersistent);
var
  I: Integer;
  Fixup: TPropFixup;
begin
  if GlobalFixupList = nil then Exit;
  with GlobalFixupList.LockList do
  try
    for I := Count - 1 downto 0 do
    begin
      Fixup := Items[I];
      if (Fixup.FInstance = Instance) then
      begin
        Delete(I);
        Fixup.Free;
      end;
    end;
  finally
    GlobalFixupList.UnlockList;
  end;
end;

procedure GetFixupInstanceNames(Root: TComponent;
  const ReferenceRootName: string; Names: TStrings);
var
  I: Integer;
  Fixup: TPropFixup;
begin
  with GlobalFixupList.LockList do
  try
    for I := 0 to Count - 1 do
    begin
      Fixup := Items[I];
      if (Fixup.FInstanceRoot = Root) and
        SameText(ReferenceRootName, Fixup.FRootName) and
        not NameInStrings(Names, Fixup.FName) then
        Names.Add(Fixup.FName);
    end;
  finally
    GlobalFixupList.UnlockList;
  end;
end;

{ TReader }

procedure ReadError(Ident: PResStringRec);
begin
  raise EReadError.CreateRes(Ident);
end;

procedure PropValueError;
begin
  ReadError(@SInvalidPropertyValue);
end;

procedure PropertyNotFound;
begin
  ReadError(@SUnknownProperty);
end;

function EnumValue(EnumType: PTypeInfo; const EnumName: string): Integer;
begin
  Result := GetEnumValue(EnumType, EnumName);
  if Result = -1 then PropValueError;
end;

destructor TReader.Destroy;
begin
  FStream.Seek(Integer(FBufPos) - Integer(FBufEnd), 1);
  inherited Destroy;
end;

procedure TReader.BeginReferences;
begin
  FLoaded := TList.Create;
  try
    FFixups := TList.Create;
  except
    FLoaded.Free;
    raise;
  end;
end;

procedure TReader.CheckValue(Value: TValueType);
begin
  if ReadValue <> Value then
  begin
    Dec(FBufPos);
    SkipValue;
    PropValueError;
  end;
end;

procedure TReader.DefineProperty(const Name: string;
  ReadData: TReaderProc; WriteData: TWriterProc; HasData: Boolean);
begin
  if SameText(Name, FPropName) and Assigned(ReadData) then
  begin
    ReadData(Self);
    FPropName := '';
  end;
end;

procedure TReader.DefineBinaryProperty(const Name: string;
  ReadData, WriteData: TStreamProc; HasData: Boolean);
var
  Stream: TMemoryStream;
  Count: Longint;
begin
  if SameText(Name, FPropName) and Assigned(ReadData) then
  begin
    if ReadValue <> vaBinary then
    begin
      Dec(FBufPos);
      SkipValue;
      FCanHandleExcepts := True;
      PropValueError;
    end;
    Stream := TMemoryStream.Create;
    try
      Read(Count, SizeOf(Count));
      Stream.SetSize(Count);
      Read(Stream.Memory^, Count);
      FCanHandleExcepts := True;
      ReadData(Stream);
    finally
      Stream.Free;
    end;
    FPropName := '';
  end;
end;

function TReader.EndOfList: Boolean;
begin
  Result := ReadValue = vaNull;
  Dec(FBufPos);
end;

procedure TReader.EndReferences;
begin
  FreeFixups;
  FLoaded.Free;
  FLoaded := nil;
end;

function TReader.Error(const Message: string): Boolean;
begin
  Result := False;
  if Assigned(FOnError) then FOnError(Self, Message, Result);
end;

function TReader.FindMethod(Root: TComponent;
  const MethodName: string): Pointer;
var
  Error: Boolean;
begin
  Result := Root.MethodAddress(MethodName);
  Error := Result = nil;
  if Assigned(FOnFindMethod) then FOnFindMethod(Self, MethodName, Result, Error);
  if Error then PropValueError;
end;

procedure RemoveGlobalFixup(Fixup: TPropFixup);
var
  I: Integer;
begin
  with GlobalFixupList.LockList do
  try
    for I := Count-1 downto 0 do
      with TPropFixup(Items[I]) do
        if (FInstance = Fixup.FInstance) and (FPropInfo = Fixup.FPropInfo) then
        begin
          Free;
          Delete(I);
        end;
  finally
    GlobalFixupList.UnlockList;
  end;
end;

procedure TReader.DoFixupReferences;
var
  I: Integer;
  CompName: string;
  Reference: Pointer;
begin
  if FFixups <> nil then
    try
      for I := 0 to FFixups.Count - 1 do
        with TPropFixup(FFixups[I]) do
        begin
          CompName := FName;
          ReferenceName(CompName);
          Reference := FindNestedComponent(FInstanceRoot, CompName);
          { Free any preexisting global fixups for this instance/property.
            Last fixup added is the only one that counts.
            In particular, fixups created when streaming inherited forms/frames
            must be destroyed when overriding references are found later
            in the stream.  }
          RemoveGlobalFixup(FFixups[I]);
          if (Reference = nil) and MakeGlobalReference then
          begin
            GlobalFixupList.Add(FFixups[I]);
            FFixups[I] := nil;
          end
          else
            SetOrdProp(FInstance, FPropInfo, Longint(Reference));
        end;
    finally
      FreeFixups;
    end;
end;

procedure TReader.FixupReferences;
var
  I: Integer;
begin
  DoFixupReferences;
  GlobalFixupReferences;
  for I := 0 to FLoaded.Count - 1 do TComponent(FLoaded[I]).Loaded;
end;

procedure TReader.FlushBuffer;
begin
  FStream.Position := Position;
  FBufPos := 0;
  FBufEnd := 0;
end;

procedure TReader.FreeFixups;
var
  I: Integer;
begin
  if FFixups <> nil then
  begin
    for I := 0 to FFixups.Count - 1 do TPropFixup(FFixups[I]).Free;
    FFixups.Free;
    FFixups := nil;
  end;
end;

function TReader.GetPosition: Longint;
begin
  Result := FStream.Position - (FBufEnd - FBufPos);
end;

function TReader.NextValue: TValueType;
begin
  Result := ReadValue;
  Dec(FBufPos);
end;

procedure TReader.PropertyError;
begin
  SkipValue;
  PropertyNotFound;
end;

procedure TReader.Read(var Buf; Count: Longint); assembler;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     EDI,EDX
        MOV     EBX,ECX
        MOV     ESI,EAX
        JMP     @@6
@@1:    MOV     ECX,[ESI].TReader.FBufEnd
        SUB     ECX,[ESI].TReader.FBufPos
        JA      @@2
        MOV     EAX,ESI
        CALL    TReader.ReadBuffer
        MOV     ECX,[ESI].TReader.FBufEnd
@@2:    CMP     ECX,EBX
        JB      @@3
        MOV     ECX,EBX
@@3:    PUSH    ESI
        SUB     EBX,ECX
        MOV     EAX,[ESI].TReader.FBuffer
        ADD     EAX,[ESI].TReader.FBufPos
        ADD     [ESI].TReader.FBufPos,ECX
        MOV     ESI,EAX
        MOV     EDX,ECX
        SHR     ECX,2
        CLD
        REP     MOVSD
        MOV     ECX,EDX
        AND     ECX,3
        REP     MOVSB
        POP     ESI
@@6:    OR      EBX,EBX
        JNE     @@1
        POP     EBX
        POP     EDI
        POP     ESI
end;

procedure TReader.ReadBuffer;
begin
  FBufEnd := FStream.Read(FBuffer^, FBufSize);
  if FBufEnd = 0 then raise EReadError.CreateRes(@SReadError);
  FBufPos := 0;
end;

function TReader.ReadBoolean: Boolean;
begin
  Result := ReadValue = vaTrue;
end;

function TReader.ReadChar: Char;
begin
  CheckValue(vaString);
  Read(Result, 1);
  if Ord(Result) <> 1 then
  begin
    Dec(FBufPos);
    ReadStr;
    PropValueError;
  end;
  Read(Result, 1);
end;

procedure TReader.ReadCollection(Collection: TCollection);
var
  Item: TPersistent;
begin
  Collection.BeginUpdate;
  try
    if not EndOfList then Collection.Clear;
    while not EndOfList do
    begin
      if NextValue in [vaInt8, vaInt16, vaInt32] then ReadInteger;
      Item := Collection.Add;
      ReadListBegin;
      while not EndOfList do ReadProperty(Item);
      ReadListEnd;
    end;
    ReadListEnd;
  finally
    Collection.EndUpdate;
  end;
end;

function TReader.ReadComponent(Component: TComponent): TComponent;
var
  CompClass, CompName: string;
  Flags: TFilerFlags;
  Position: Integer;
  OldParent, OldLookupRoot: TComponent;

  function ComponentCreated: Boolean;
  begin
    Result := not (ffInherited in Flags) and (Component = nil);
  end;

  function Recover(var Component: TComponent): Boolean;
  begin
    Result := False;
    if not (ExceptObject is Exception) then Exit;
    if ComponentCreated then Component.Free;
    Component := nil;
    SkipComponent(False);
    Result := Error(Exception(ExceptObject).Message);
  end;

  procedure CreateComponent;
  var
    ComponentClass: TComponentClass;
  begin
    try
      ComponentClass := FindComponentClass(CompClass);
      Result := nil;
      if Assigned(FOnCreateComponent) then
        FOnCreateComponent(Self, ComponentClass, Result);
      if Result = nil then
      begin
        Result := TComponent(ComponentClass.NewInstance);
        if ffInline in Flags then
        begin
          Include(Result.FComponentState, csLoading);
          Include(Result.FComponentState, csInline);
        end;
        try
          Result.Create(Owner);
        except
          Result := nil;
          raise;
        end;
      end;
      Include(Result.FComponentState, csLoading);
    except
      if not Recover(Result) then raise;
    end;
  end;

  procedure SetCompName;
  begin
    try
      Result.SetParentComponent(Parent);
      SetName(Result, CompName);
      if Assigned(FindGlobalComponent) and
        (FindGlobalComponent(CompName) = Result) then
        Include(Result.FComponentState, csInline);
    except
      if not Recover(Result) then raise;
    end;
  end;

  procedure FindExistingComponent;
  begin
    try
      Result := FindAncestorComponent(CompName, FindComponentClass(CompClass));
      Parent := Result.GetParentComponent;
      if Parent = nil then Parent := Root;
    except
      if not Recover(Result) then raise;
    end;
  end;


begin
  ReadPrefix(Flags, Position);
  CompClass := ReadStr;
  CompName := ReadStr;
  OldParent := Parent;
  OldLookupRoot := FLookupRoot;
  try
    Result := Component;
    if Result = nil then
      if ffInherited in Flags then
        FindExistingComponent else
        CreateComponent;
    if Result <> nil then
      try
        Include(Result.FComponentState, csLoading);
        if not (ffInherited in Flags) then SetCompName;
        if Result = nil then Exit;
        if csInline in Result.ComponentState then
          FLookupRoot := Result;
        Include(Result.FComponentState, csReading);
        Result.ReadState(Self);
        Exclude(Result.FComponentState, csReading);
        if ffChildPos in Flags then Parent.SetChildOrder(Result, Position);
        if (ffInherited in Flags) or (csInline in Result.ComponentState) then
        begin
          if FLoaded.IndexOf(Result) < 0 then
            FLoaded.Add(Result)
        end
        else
          FLoaded.Add(Result);
      except
        if ComponentCreated then Result.Free;
        raise;
      end;
  finally
    Parent := OldParent;
    FLookupRoot := OldLookupRoot;
  end;
end;

procedure TReader.ReadData(Instance: TComponent);
begin
  if FFixups = nil then
  begin
    FFixups := TList.Create;
    try
      ReadDataInner(Instance);
      DoFixupReferences;
    finally
      FreeFixups;
    end;
  end else
    ReadDataInner(Instance);
end;

procedure TReader.ReadDataInner(Instance: TComponent);
var
  OldParent, OldOwner: TComponent;
begin
  while not EndOfList do ReadProperty(Instance);
  ReadListEnd;
  OldParent := Parent;
  OldOwner := Owner;
  Parent := Instance.GetChildParent;
  try
    Owner := Instance.GetChildOwner;
    if not Assigned(Owner) then Owner := Root;
    while not EndOfList do ReadComponent(nil);
    ReadListEnd;
  finally
    Parent := OldParent;
    Owner := OldOwner;
  end;
end;

function TReader.ReadFloat: Extended;
begin
  if ReadValue = vaExtended then Read(Result, SizeOf(Result)) else
  begin
    Dec(FBufPos);
    Result := ReadInteger;
  end;
end;

function TReader.ReadSingle: Single;
begin
  if ReadValue = vaSingle then Read(Result, SizeOf(Result)) else
  begin
    Dec(FBufPos);
    Result := ReadInteger;
  end;
end;

function TReader.ReadCurrency: Currency;
begin
  if ReadValue = vaCurrency then Read(Result, SizeOf(Result)) else
  begin
    Dec(FBufPos);
    Result := ReadInteger;
  end;
end;

function TReader.ReadDate: TDateTime;
begin
  if ReadValue = vaDate then Read(Result, SizeOf(Result)) else
  begin
    Dec(FBufPos);
    Result := ReadInteger;
  end;
end;

function TReader.ReadIdent: string;
var
  L: Byte;
begin
  case ReadValue of
    vaIdent:
      begin
        Read(L, SizeOf(Byte));
        SetString(Result, PChar(nil), L);
        Read(Result[1], L);
      end;
    vaFalse:
      Result := 'False';
    vaTrue:
      Result := 'True';
    vaNil:
      Result := 'nil';
    vaNull:
      Result := 'Null';
  else
    PropValueError;
  end;
end;

function TReader.ReadInteger: Longint;
var
  S: Shortint;
  I: Smallint;
begin
  case ReadValue of
    vaInt8:
      begin
        Read(S, SizeOf(Shortint));
        Result := S;
      end;
    vaInt16:
      begin
        Read(I, SizeOf(I));
        Result := I;
      end;
    vaInt32:
      Read(Result, SizeOf(Result));
  else
    PropValueError;
  end;
end;

function TReader.ReadInt64: Int64;
begin
  if NextValue = vaInt64 then
  begin
    ReadValue;
    Read(Result, Sizeof(Result));
  end
  else
    Result := ReadInteger;
end;

procedure TReader.ReadListBegin;
begin
  CheckValue(vaList);
end;

procedure TReader.ReadListEnd;
begin
  CheckValue(vaNull);
end;

procedure TReader.ReadPrefix(var Flags: TFilerFlags; var AChildPos: Integer);
var
  Prefix: Byte;
begin
  Flags := [];
  if Byte(NextValue) and $F0 = $F0 then
  begin
    Prefix := Byte(ReadValue);
    Byte(Flags) := Prefix and $0F;
    if ffChildPos in Flags then AChildPos := ReadInteger;
  end;
end;

procedure TReader.ReadProperty(AInstance: TPersistent);
var
  I, J, L: Integer;
  Instance: TPersistent;
  PropInfo: PPropInfo;
  PropValue: TObject;
  PropPath: string;

  procedure HandleException(E: Exception);
  var
    Name: string;
  begin
    Name := '';
    if AInstance is TComponent then
      Name := TComponent(AInstance).Name;
    if Name = '' then Name := AInstance.ClassName;
    raise EReadError.CreateResFmt(@SPropertyException, [Name, DotSep, PropPath, E.Message]);
  end;

  procedure PropPathError;
  begin
    SkipValue;
    ReadError(@SInvalidPropertyPath);
  end;

begin
  try
    PropPath := ReadStr;
    try
      I := 1;
      L := Length(PropPath);
      Instance := AInstance;
      FCanHandleExcepts := True;
      while True do
      begin
        J := I;
        while (I <= L) and (PropPath[I] <> '.') do Inc(I);
        FPropName := Copy(PropPath, J, I - J);
        if I > L then Break;
        PropInfo := GetPropInfo(Instance.ClassInfo, FPropName);
        if PropInfo = nil then PropertyError;
        PropValue := nil;
        if PropInfo^.PropType^.Kind = tkClass then
          PropValue := TObject(GetOrdProp(Instance, PropInfo));
        if not (PropValue is TPersistent) then PropPathError;
        Instance := TPersistent(PropValue);
        Inc(I);
      end;
      PropInfo := GetPropInfo(Instance.ClassInfo, FPropName);
      if PropInfo <> nil then ReadPropValue(Instance, PropInfo) else
      begin
        { Cannot reliably recover from an error in a defined property }
        FCanHandleExcepts := False;
        Instance.DefineProperties(Self);
        FCanHandleExcepts := True;
        if FPropName <> '' then PropertyError;
      end;
    except
      on E: Exception do HandleException(E);
    end;
  except
    on E: Exception do
      if not FCanHandleExcepts or not Error(E.Message) then raise;
  end;
end;

procedure TReader.ReadPropValue(Instance: TPersistent; PropInfo: Pointer);
const
  NilMethod: TMethod = (Code: nil; Data: nil);
var
  PropType: PTypeInfo;
  Method: TMethod;

  procedure SetIntIdent(Instance: TPersistent; PropInfo: Pointer;
    const Ident: string);
  var
    V: Longint;
    IdentToInt: TIdentToInt;
  begin
    IdentToInt := FindIdentToInt(PPropInfo(PropInfo)^.PropType^);
    if Assigned(IdentToInt) and IdentToInt(Ident, V) then
      SetOrdProp(Instance, PropInfo, V)
    else
      PropValueError;
  end;

  procedure SetObjectIdent(Instance: TPersistent; PropInfo: Pointer;
    const Ident: string);
  begin
    FFixups.Add(TPropFixup.Create(Instance, Root, PropInfo, '', Ident));
  end;

  procedure ReadVariantProp;
  const
    ValTtoVarT: array[TValueType] of Integer = (varNull, varError, varByte,
      varSmallInt, varInteger, varDouble, varString, varError, varBoolean,
      varBoolean, varError, varError, varString, varEmpty, varError, varSingle,
      varCurrency, varDate, varOleStr, varError);
  var
    Value: Variant;
    ValType: TValueType;
  begin
    ValType := NextValue;
    case ValType of
      vaNil, vaNull:
      begin
        if ReadValue = vaNil then
          VarClear(Value) else
          Value := NULL;
      end;
      vaInt8: TVarData(Value).VByte := Byte(ReadInteger);
      vaInt16: TVarData(Value).VSmallint := Smallint(ReadInteger);
      vaInt32: TVarData(Value).VInteger := ReadInteger;
      vaExtended: TVarData(Value).VDouble := ReadFloat;
      vaSingle: TVarData(Value).VSingle := ReadSingle;
      vaCurrency: TVarData(Value).VCurrency := ReadCurrency;
      vaDate: TVarData(Value).VDate := ReadDate;
      vaString, vaLString: Value := ReadString;
      vaWString: Value := ReadWideString;
      vaFalse, vaTrue: TVarData(Value).VBoolean := ReadValue = vaTrue;
    else
      raise EReadError.CreateRes(@SReadError);
    end;
    TVarData(Value).VType := ValTtoVarT[ValType];
    SetVariantProp(Instance, PropInfo, Value);
  end;

begin
  if PPropInfo(PropInfo)^.SetProc = nil then ReadError(@SReadOnlyProperty);
  PropType := PPropInfo(PropInfo)^.PropType^;
  case PropType^.Kind of
    tkInteger:
      if NextValue = vaIdent then
        SetIntIdent(Instance, PropInfo, ReadIdent) else
        SetOrdProp(Instance, PropInfo, ReadInteger);
    tkChar:
      SetOrdProp(Instance, PropInfo, Ord(ReadChar));
    tkEnumeration:
      SetOrdProp(Instance, PropInfo, EnumValue(PropType, ReadIdent));
    tkFloat:
      SetFloatProp(Instance, PropInfo, ReadFloat);
    tkString, tkLString, tkWString:
      SetStrProp(Instance, PropInfo, ReadString);
    tkSet:
      SetOrdProp(Instance, PropInfo, ReadSet(PropType));
    tkClass:
      case NextValue of
        vaNil:
          begin
            ReadValue;
            SetOrdProp(Instance, PropInfo, 0)
          end;
        vaCollection:
          begin
            ReadValue;
            ReadCollection(TCollection(GetOrdProp(Instance, PropInfo)));
          end
      else
        SetObjectIdent(Instance, PropInfo, ReadIdent);
      end;
    tkMethod:
      if NextValue = vaNil then
      begin
        ReadValue;
        SetMethodProp(Instance, PropInfo, NilMethod);
      end
      else
      begin
        Method.Code :=  FindMethod(Root, ReadIdent);
        Method.Data := Root;
        if Method.Code <> nil then SetMethodProp(Instance, PropInfo, Method);
      end;
    tkVariant:
      ReadVariantProp;
    tkInt64: SetInt64Prop(Instance, PropInfo, ReadInt64);
  end;
end;

function TReader.ReadRootComponent(Root: TComponent): TComponent;

  function FindUniqueName(const Name: string): string;
  var
    I: Integer;
  begin
    I := 0;
    Result := '';
    if Assigned(FindGlobalComponent) then
    begin
      Result := Name;
      while FindGlobalComponent(Result) <> nil do
      begin
        Inc(I);
        Result := Format('%s_%d', [Name, I]);
      end;
    end;
  end;

var
  I: Integer;
  Flags: TFilerFlags;
begin
  ReadSignature;
  Result := nil;
  GlobalNameSpace.BeginWrite;  // Loading from stream adds to name space
  try
    try
      ReadPrefix(Flags, I);
      if Root = nil then
      begin
        Result := TComponentClass(FindClass(ReadStr)).Create(nil);
        Result.Name := ReadStr;
      end else
      begin
        Result := Root;
        ReadStr; { Ignore class name }
        if csDesigning in Result.ComponentState then
          ReadStr else
        begin
          Include(Result.FComponentState, csLoading);
          Include(Result.FComponentState, csReading);
          Result.Name := FindUniqueName(ReadStr);
        end;
      end;
      FRoot := Result;
      FLookupRoot := Result;
      if GlobalLoaded <> nil then
        FLoaded := GlobalLoaded else
        FLoaded := TList.Create;
      try
        if FLoaded.IndexOf(FRoot) < 0 then
          FLoaded.Add(FRoot);
        FOwner := FRoot;
        Include(FRoot.FComponentState, csLoading);
        Include(FRoot.FComponentState, csReading);
        FRoot.ReadState(Self);
        Exclude(FRoot.FComponentState, csReading);
        if GlobalLoaded = nil then
          for I := 0 to FLoaded.Count - 1 do TComponent(FLoaded[I]).Loaded;
      finally
        if GlobalLoaded = nil then FLoaded.Free;
        FLoaded := nil;
      end;
      GlobalFixupReferences;
    except
      RemoveFixupReferences(Root, '');
      if Root = nil then Result.Free;
      raise;
    end;
  finally
    GlobalNameSpace.EndWrite;
  end;
end;

procedure TReader.ReadComponents(AOwner, AParent: TComponent;
  Proc: TReadComponentsProc);
var
  Component: TComponent;
begin
  Root := AOwner;
  Owner := AOwner;
  Parent := AParent;
  BeginReferences;
  try
    while not EndOfList do
    begin
      ReadSignature;
      Component := ReadComponent(nil);
      if Assigned(Proc) then Proc(Component);
    end;
    ReadListEnd;
    FixupReferences;
  finally
    EndReferences;
  end;
end;

function TReader.ReadSet(SetType: Pointer): Integer;
var
  EnumType: PTypeInfo;
  EnumName: string;
begin
  try
    if ReadValue <> vaSet then PropValueError;
    EnumType := GetTypeData(SetType)^.CompType^;
    Result := 0;
    while True do
    begin
      EnumName := ReadStr;
      if EnumName = '' then Break;
      Include(TIntegerSet(Result), EnumValue(EnumType, EnumName));
    end;
  except
    SkipSetBody;
    raise;
  end;
end;

procedure TReader.ReadSignature;
var
  Signature: Longint;
begin
  Read(Signature, SizeOf(Signature));
  if Signature <> Longint(FilerSignature) then ReadError(@SInvalidImage);
end;

function TReader.ReadStr: string;
var
  L: Byte;
begin
  Read(L, SizeOf(Byte));
  SetString(Result, PChar(nil), L);
  Read(Result[1], L);
end;

function TReader.ReadString: string;
var
  L: Integer;
begin
  L := 0;
  case ReadValue of
    vaString:
      Read(L, SizeOf(Byte));
    vaLString:
      Read(L, SizeOf(Integer));
  else
    PropValueError;
  end;
  SetString(Result, PChar(nil), L);
  Read(Pointer(Result)^, L);
end;

function TReader.ReadWideString: WideString;
var
  L: Integer;
begin
  L := 0;
  if ReadValue <> vaWString then
    PropValueError;
  Read(L, SizeOf(Integer));
  SetLength(Result, L);
  Read(Pointer(Result)^, L * 2);
end;

function TReader.ReadValue: TValueType;
begin
  Read(Result, SizeOf(Result));
end;

procedure TReader.SetPosition(Value: Longint);
begin
  FStream.Position := Value;
  FBufPos := 0;
  FBufEnd := 0;
end;

procedure TReader.SkipSetBody;
begin
  while ReadStr <> '' do begin end;
end;

procedure TReader.SkipValue;

  procedure SkipList;
  begin
    while not EndOfList do SkipValue;
    ReadListEnd;
  end;

  procedure SkipBytes(Count: Longint);
  var
    Bytes: array[0..255] of Char;
  begin
    while Count > 0 do
      if Count > SizeOf(Bytes) then
      begin
        Read(Bytes, SizeOf(Bytes));
        Dec(Count, SizeOf(Bytes));
      end
      else
      begin
        Read(Bytes, Count);
        Count := 0;
      end;
  end;

  procedure SkipBinary;
  var
    Count: Longint;
  begin
    Read(Count, SizeOf(Count));
    SkipBytes(Count);
  end;

  procedure SkipCollection;
  begin
    while not EndOfList do
    begin
      if NextValue in [vaInt8, vaInt16, vaInt32] then SkipValue;
      SkipBytes(1);
      while not EndOfList do SkipProperty;
      ReadListEnd;
    end;
    ReadListEnd;
  end;

begin
  case ReadValue of
    vaNull: begin end;
    vaList: SkipList;
    vaInt8: SkipBytes(1);
    vaInt16: SkipBytes(2);
    vaInt32: SkipBytes(4);
    vaExtended: SkipBytes(SizeOf(Extended));
    vaString, vaIdent: ReadStr;
    vaFalse, vaTrue: begin end;
    vaBinary: SkipBinary;
    vaSet: SkipSetBody;
    vaLString: SkipBinary;
    vaCollection: SkipCollection;
    vaSingle: SkipBytes(Sizeof(Single));
    vaCurrency: SkipBytes(SizeOf(Currency));
    vaDate: SkipBytes(Sizeof(TDateTime));
    vaWString: SkipBinary;
    vaInt64: SkipBytes(Sizeof(Int64));
  end;
end;

procedure TReader.CopyValue(Writer: TWriter);

  procedure CopySetBody;
  var
    s: string;
  begin
    Writer.WriteValue(ReadValue);
    repeat
      s := ReadStr;
      Writer.WriteStr(s);
    until s = '';
  end;

  procedure CopyList;
  begin
    Writer.WriteValue(ReadValue);
    while not EndOfList do
      CopyValue(Writer);
    ReadListEnd;
    Writer.WriteListEnd;
  end;

  procedure CopyBytes(Count: Longint);
  var
    Bytes: array[0..8191] of Char;
  begin
    while Count > SizeOf(Bytes) do
    begin
      Read(Bytes, SizeOf(Bytes));
      Writer.Write(Bytes, SizeOf(Bytes));
      Dec(Count, SizeOf(Bytes));
    end;
    if Count > 0 then
    begin
      Read(Bytes, Count);
      Writer.Write(Bytes, Count);
    end;
  end;

  procedure CopyBinary;
  var
    Count: Longint;
  begin
    Writer.WriteValue(ReadValue);
    Read(Count, SizeOf(Count));
    Writer.Write(Count, SizeOf(Count));
    CopyBytes(Count);
  end;

begin
  case NextValue of
    vaNull, vaFalse, vaTrue, vaNil: Writer.WriteValue(ReadValue);
    vaList, vaCollection: CopyList;
    vaInt8, vaInt16, vaInt32: Writer.WriteInteger(ReadInteger);
    vaExtended: Writer.WriteFloat(ReadFloat);
    vaString: Writer.WriteStr(ReadStr);
    vaIdent: Writer.WriteIdent(ReadIdent);
    vaBinary, vaLString, vaWString: CopyBinary;
    vaSet: CopySetBody;
    vaSingle: Writer.WriteSingle(ReadSingle);
    vaCurrency: Writer.WriteCurrency(ReadCurrency);
    vaDate: Writer.WriteDate(ReadDate);
    vaInt64: Writer.WriteInteger(ReadInt64);
  end;
end;

procedure TReader.SkipProperty;
begin
  ReadStr; { Skips property name }
  SkipValue;
end;

procedure TReader.SkipComponent(SkipHeader: Boolean);
var
  Flags: TFilerFlags;
  Position: Integer;
begin
  if SkipHeader then
  begin
    ReadPrefix(Flags, Position);
    ReadStr;
    ReadStr;
  end;
  while not EndOfList do SkipProperty;
  ReadListEnd;
  while not EndOfList do SkipComponent(True);
  ReadListEnd;
end;

function TReader.FindAncestorComponent(const Name: string;
  ComponentClass: TPersistentClass): TComponent;
var
  CompName: string;
begin
  CompName := Name;
  Result := nil;
  if FLookupRoot <> nil then
    Result := FLookupRoot.FindComponent(CompName);
  if Result = nil then
  begin
    if Assigned(FOnAncestorNotFound) then
      FOnAncestorNotFound(Self, CompName, ComponentClass, Result);
    if Result = nil then
      raise EReadError.CreateResFmt(@SAncestorNotFound, [CompName]);
  end;
end;

procedure TReader.ReferenceName(var Name: string);
begin
  if Assigned(FOnReferenceName) then FOnReferenceName(Self, Name);
end;

procedure TReader.SetName(Component: TComponent; var Name: string);
begin
  if Assigned(FOnSetName) then FOnSetName(Self, Component, Name);
  Component.Name := Name;
end;

function TReader.FindComponentClass(const ClassName: string): TComponentClass;
begin
  TPersistentClass(Result) := GetFieldClass(Root, ClassName);
  if not Assigned(Result) and Assigned(FLookupRoot) and (FLookupRoot <> Root) then
    TPersistentClass(Result) := GetFieldClass(FLookupRoot, ClassName);
  if Assigned(FOnFindComponentClass) then
    FOnFindComponentClass(Self, ClassName, Result);
  if (Result = nil) or not Result.InheritsFrom(TComponent) then
    ClassNotFound(ClassName);
end;

{ TWriter }

destructor TWriter.Destroy;
begin
  WriteBuffer;
  inherited Destroy;
end;

procedure TWriter.AddAncestor(Component: TComponent);
begin
  FAncestorList.Add(Component);
end;

procedure TWriter.DefineProperty(const Name: string;
  ReadData: TReaderProc; WriteData: TWriterProc; HasData: Boolean);
begin
  if HasData and Assigned(WriteData) then
  begin
    WritePropName(Name);
    WriteData(Self);
  end;
end;

procedure TWriter.DefineBinaryProperty(const Name: string;
  ReadData, WriteData: TStreamProc; HasData: Boolean);
begin
  if HasData and Assigned(WriteData) then
  begin
    WritePropName(Name);
    WriteBinary(WriteData);
  end;
end;

function TWriter.GetPosition: Longint;
begin
  Result := FStream.Position + FBufPos;
end;

procedure TWriter.FlushBuffer;
begin
  WriteBuffer;
end;

procedure TWriter.SetPosition(Value: Longint);
var
  StreamPosition: Longint;
begin
  StreamPosition := FStream.Position;
  { Only flush the buffer if the repostion is outside the buffer range }
  if (Value < StreamPosition) or (Value > StreamPosition + FBufPos) then
  begin
    WriteBuffer;
    FStream.Position := Value;
  end
  else FBufPos := Value - StreamPosition;
end;

procedure TWriter.SetRoot(Value: TComponent);
begin
  inherited SetRoot(Value);
  FLookupRoot := Value;
end;

procedure TWriter.Write(const Buf; Count: Longint); assembler;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     ESI,EDX
        MOV     EBX,ECX
        MOV     EDI,EAX
        JMP     @@6
@@1:    MOV     ECX,[EDI].TWriter.FBufSize
        SUB     ECX,[EDI].TWriter.FBufPos
        JA      @@2
        MOV     EAX,EDI
        CALL    TWriter.WriteBuffer
        MOV     ECX,[EDI].TWriter.FBufSize
@@2:    CMP     ECX,EBX
        JB      @@3
        MOV     ECX,EBX
@@3:    SUB     EBX,ECX
        PUSH    EDI
        MOV     EAX,[EDI].TWriter.FBuffer
        ADD     EAX,[EDI].TWriter.FBufPos
        ADD     [EDI].TWriter.FBufPos,ECX
@@5:    MOV     EDI,EAX
        MOV     EDX,ECX
        SHR     ECX,2
        CLD
        REP     MOVSD
        MOV     ECX,EDX
        AND     ECX,3
        REP     MOVSB
        POP     EDI
@@6:    OR      EBX,EBX
        JNE     @@1
        POP     EBX
        POP     EDI
        POP     ESI
end;

procedure TWriter.WriteBinary(WriteData: TStreamProc);
var
  Stream: TMemoryStream;
  Count: Longint;
begin
  Stream := TMemoryStream.Create;
  try
    WriteData(Stream);
    WriteValue(vaBinary);
    Count := Stream.Size;
    Write(Count, SizeOf(Count));
    Write(Stream.Memory^, Count);
  finally
    Stream.Free;
  end;
end;

procedure TWriter.WriteBuffer;
begin
  FStream.WriteBuffer(FBuffer^, FBufPos);
  FBufPos := 0;
end;

procedure TWriter.WriteBoolean(Value: Boolean);
begin
  if Value then
    WriteValue(vaTrue) else
    WriteValue(vaFalse);
end;

procedure TWriter.WriteChar(Value: Char);
begin
  WriteString(Value);
end;

procedure TWriter.WriteCollection(Value: TCollection);
var
  I: Integer;
begin
  WriteValue(vaCollection);
  if Value <> nil then
    for I := 0 to Value.Count - 1 do
    begin
      WriteListBegin;
      WriteProperties(Value.Items[I]);
      WriteListEnd;
    end;
  WriteListEnd;
end;

procedure TWriter.WriteComponent(Component: TComponent);

  function FindAncestor(const Name: string): TComponent;
  var
    I: Integer;
  begin
    for I := 0 to FAncestorList.Count - 1 do
    begin
      Result := FAncestorList[I];
      if SameText(Result.Name, Name) then Exit;
    end;
    Result := nil;
  end;

var
  OldAncestor: TPersistent;
  OldRootAncestor: TComponent;
  AncestorComponent: TComponent;
begin
  OldAncestor := Ancestor;
  OldRootAncestor := RootAncestor;
  try
    Include(Component.FComponentState, csWriting);
    if Assigned(FAncestorList) then
      Ancestor := FindAncestor(Component.Name);
    if Assigned(FOnFindAncestor) and ((Ancestor = nil) or (Ancestor is
      TComponent)) then
    begin
      AncestorComponent := TComponent(Ancestor);
      FOnFindAncestor(Self, Component, Component.Name, AncestorComponent,
        FRootAncestor);
      Ancestor := AncestorComponent;
    end;
    Component.WriteState(Self);
    Exclude(Component.FComponentState, csWriting);
  finally
    Ancestor := OldAncestor;
    FRootAncestor := OldRootAncestor;
  end;
end;

procedure TWriter.WriteData(Instance: TComponent);
var
  PreviousPosition, PropertiesPosition: Longint;
  OldAncestorList: TList;
  OldAncestorPos, OldChildPos: Integer;
  OldRoot, OldRootAncestor: TComponent;
  Flags: TFilerFlags;
begin
  if FBufSize - FBufPos < Length(Instance.ClassName) +
    Length(Instance.Name) + 1+5+3 then WriteBuffer;
     { Prefix + vaInt + integer + 2 end lists }
  PreviousPosition := Position;
  Flags := [];
  if csInline in Instance.ComponentState then
    if (Ancestor <> nil) and (csAncestor in Instance.ComponentState) and (FAncestorList <> nil) then
      // If the AncestorList is not nil, this really came from an ancestor form
      Include(Flags, ffInherited)
    else
      // otherwise the Ancestor is the original frame
      Include(Flags, ffInline)
  else if Ancestor <> nil then
    Include(Flags, ffInherited);
  if (FAncestorList <> nil) and (FAncestorPos < FAncestorList.Count) and
    ((Ancestor = nil) or (FAncestorList[FAncestorPos] <> Ancestor)) then
    Include(Flags, ffChildPos);
  WritePrefix(Flags, FChildPos);
  WriteStr(Instance.ClassName);
  WriteStr(Instance.Name);
  PropertiesPosition := Position;
  if (FAncestorList <> nil) and (FAncestorPos < FAncestorList.Count) then
  begin
    if Ancestor <> nil then Inc(FAncestorPos);
    Inc(FChildPos);
  end;
  WriteProperties(Instance);
  WriteListEnd;
  OldAncestorList := FAncestorList;
  OldAncestorPos := FAncestorPos;
  OldChildPos := FChildPos;
  OldRoot := FRoot;
  OldRootAncestor := FRootAncestor;
  try
    FAncestorList := nil;
    FAncestorPos := 0;
    FChildPos := 0;
    if not IgnoreChildren then
      try
        if (FAncestor <> nil) and (FAncestor is TComponent) then
        begin
          if (FAncestor is TComponent) and (csInline in TComponent(FAncestor).ComponentState) then
            FRootAncestor := TComponent(FAncestor);
          FAncestorList := TList.Create;
          TComponent(FAncestor).GetChildren(AddAncestor, FRootAncestor);
        end;
        if csInline in Instance.ComponentState then
          FRoot := Instance;
        Instance.GetChildren(WriteComponent, FRoot);
      finally
        FAncestorList.Free;
      end;
  finally
    FAncestorList := OldAncestorList;
    FAncestorPos := OldAncestorPos;
    FChildPos := OldChildPos;
    FRoot := OldRoot;
    FRootAncestor := OldRootAncestor;
  end;
  WriteListEnd;
  if (Instance <> Root) and (Flags = [ffInherited]) and
    (Position = PropertiesPosition + (1 + 1)) then { (1 + 1) is two end lists }
    Position := PreviousPosition;
end;

procedure TWriter.WriteDescendent(Root: TComponent; AAncestor: TComponent);
begin
  FRootAncestor := AAncestor;
  FAncestor := AAncestor;
  FRoot := Root;
  FLookupRoot := Root;
  WriteSignature;
  WriteComponent(Root);
end;

procedure TWriter.WriteFloat(const Value: Extended);
begin
  WriteValue(vaExtended);
  Write(Value, SizeOf(Extended));
end;

procedure TWriter.WriteSingle(const Value: Single);
begin
  WriteValue(vaSingle);
  Write(Value, SizeOf(Single));
end;

procedure TWriter.WriteCurrency(const Value: Currency);
begin
  WriteValue(vaCurrency);
  Write(Value, SizeOf(Currency));
end;

procedure TWriter.WriteDate(const Value: TDateTime);
begin
  WriteValue(vaDate);
  Write(Value, SizeOf(TDateTime));
end;

procedure TWriter.WriteIdent(const Ident: string);
begin
  if SameText(Ident, 'False') then WriteValue(vaFalse) else
  if SameText(Ident ,'True') then WriteValue(vaTrue) else
  if SameText(Ident ,'Null') then WriteValue(vaNull) else
  if SameText(Ident, 'nil') then WriteValue(vaNil) else
  begin
    WriteValue(vaIdent);
    WriteStr(Ident);
  end;
end;

procedure TWriter.WriteInteger(Value: Longint);
begin
  if (Value >= Low(ShortInt)) and (Value <= High(ShortInt)) then
  begin
    WriteValue(vaInt8);
    Write(Value, SizeOf(Shortint));
  end else
  if (Value >= Low(SmallInt)) and (Value <= High(SmallInt)) then
  begin
    WriteValue(vaInt16);
    Write(Value, SizeOf(Smallint));
  end
  else
  begin
    WriteValue(vaInt32);
    Write(Value, SizeOf(Integer));
  end;
end;

procedure TWriter.WriteInteger(Value: Int64);
begin
  if (Value >= Low(Integer)) and (Value <= High(Integer)) then
    WriteInteger(Longint(Value))
  else
  begin
    WriteValue(vaInt64);
    Write(Value, Sizeof(Int64));
  end;
end;

procedure TWriter.WriteListBegin;
begin
  WriteValue(vaList);
end;

procedure TWriter.WriteListEnd;
begin
  WriteValue(vaNull);
end;

procedure TWriter.WritePrefix(Flags: TFilerFlags; AChildPos: Integer);
var
  Prefix: Byte;
begin
  if Flags <> [] then
  begin
    Prefix := $F0 or Byte(Flags);
    Write(Prefix, SizeOf(Prefix));
    if ffChildPos in Flags then WriteInteger(AChildPos);
  end;
end;

procedure TWriter.WriteProperties(Instance: TPersistent);
var
  I, Count: Integer;
  PropInfo: PPropInfo;
  PropList: PPropList;
begin
  Count := GetTypeData(Instance.ClassInfo)^.PropCount;
  if Count > 0 then
  begin
    GetMem(PropList, Count * SizeOf(Pointer));
    try
      GetPropInfos(Instance.ClassInfo, PropList);
      for I := 0 to Count - 1 do
      begin
        PropInfo := PropList^[I];
        if PropInfo = nil then break;
        if IsStoredProp(Instance, PropInfo) then
          WriteProperty(Instance, PropInfo);
      end;
    finally
      FreeMem(PropList, Count * SizeOf(Pointer));
    end;
  end;
  Instance.DefineProperties(Self);
end;

procedure TWriter.WriteProperty(Instance: TPersistent; PropInfo: Pointer);
var
  PropType: PTypeInfo;

  function AncestorValid: Boolean;
  begin
    Result := (Ancestor <> nil) and ((Instance.ClassType = Ancestor.ClassType) or
      (Instance = Root));
  end;

  procedure WritePropPath;
  begin
    WritePropName(PPropInfo(PropInfo)^.Name);
  end;

  procedure WriteSet(Value: Longint);
  var
    I: Integer;
    BaseType: PTypeInfo;
  begin
    BaseType := GetTypeData(PropType)^.CompType^;
    WriteValue(vaSet);
    for I := 0 to SizeOf(TIntegerSet) * 8 - 1 do
      if I in TIntegerSet(Value) then WriteStr(GetEnumName(BaseType, I));
    WriteStr('');
  end;

  procedure WriteIntProp(IntType: PTypeInfo; Value: Longint);
  var
    Ident: string;
    IntToIdent: TIntToIdent;
  begin
    IntToIdent := FindIntToIdent(IntType);
    if Assigned(IntToIdent) and IntToIdent(Value, Ident) then
      WriteIdent(Ident)
    else
      WriteInteger(Value);
  end;

  procedure WriteCollectionProp(Collection: TCollection);
  var
    SavePropPath: string;
  begin
    WritePropPath;
    SavePropPath := FPropPath;
    try
      FPropPath := '';
      WriteCollection(Collection);
    finally
      FPropPath := SavePropPath;
    end;
  end;

  procedure WriteOrdProp;
  var
    Value: Longint;

    function IsDefaultValue: Boolean;
    begin
      if AncestorValid then
        Result := Value = GetOrdProp(Ancestor, PropInfo) else
        Result := Value = PPropInfo(PropInfo)^.Default;
    end;

  begin
    Value := GetOrdProp(Instance, PropInfo);
    if not IsDefaultValue then
    begin
      WritePropPath;
      case PropType^.Kind of
        tkInteger:
          WriteIntProp(PPropInfo(PropInfo)^.PropType^, Value);
        tkChar:
          WriteChar(Chr(Value));
        tkSet:
          WriteSet(Value);
        tkEnumeration:
          WriteIdent(GetEnumName(PropType, Value));
      end;
    end;
  end;

  procedure WriteFloatProp;
  var
    Value: Extended;

    function IsDefaultValue: Boolean;
    begin
      if AncestorValid then
        Result := Value = GetFloatProp(Ancestor, PropInfo) else
        Result := Value = 0;
    end;

  begin
    Value := GetFloatProp(Instance, PropInfo);
    if not IsDefaultValue then
    begin
      WritePropPath;
      WriteFloat(Value);
    end;
  end;

  procedure WriteInt64Prop;
  var
    Value: Int64;

    function IsDefaultValue: Boolean;
    begin
      if AncestorValid then
        Result := Value = GetInt64Prop(Ancestor, PropInfo) else
        Result := Value = 0;
    end;

  begin
    Value := GetInt64Prop(Instance, PropInfo);
    if not IsDefaultValue then
    begin
      WritePropPath;
      WriteInteger(Value);
    end;
  end;

  procedure WriteStrProp;
  var
    Value: string;

    function IsDefault: Boolean;
    begin
      if AncestorValid then
        Result := Value = GetStrProp(Ancestor, PropInfo) else
        Result := Value = '';
    end;

  begin
    Value := GetStrProp(Instance, PropInfo);
    if not IsDefault then
    begin
      WritePropPath;
      WriteString(Value);
    end;
  end;

  procedure WriteObjectProp;
  var
    Value: TObject;
    OldAncestor: TPersistent;
    SavePropPath, ComponentValue: string;

    function IsDefault: Boolean;
    var
      AncestorValue: TObject;
    begin
      AncestorValue := nil;
      if AncestorValid then
      begin
        AncestorValue := TObject(GetOrdProp(Ancestor, PropInfo));
        if (AncestorValue <> nil) and (TComponent(AncestorValue).Owner = FRootAncestor) and
          (Value <> nil) and (TComponent(Value).Owner = Root) and
          SameText(TComponent(AncestorValue).Name, TComponent(Value).Name) then
          AncestorValue := Value;
      end;
      Result := Value = AncestorValue;
    end;

    function GetComponentValue(Component: TComponent): string;
    begin
      if Component.Owner = LookupRoot then
        Result := Component.Name
      else if Component = LookupRoot then
        Result := 'Owner'                                                       { Do not translate }
      else if (Component.Owner <> nil) and (Component.Owner.Name <> '') and
        (Component.Name <> '') then
        Result := Component.Owner.Name + '.' + Component.Name
      else if Component.Name <> '' then
        Result := Component.Name + '.Owner'                                     { Do not translate }
      else Result := '';
    end;

  begin
    Value := TObject(GetOrdProp(Instance, PropInfo));
    if (Value = nil) and not IsDefault then
    begin
      WritePropPath;
      WriteValue(vaNil);
    end
    else if Value is TPersistent then
      if Value is TComponent then
      begin
        if not IsDefault then
        begin
          ComponentValue := GetComponentValue(TComponent(Value));
          if ComponentValue <> '' then
          begin
            WritePropPath;
            WriteIdent(ComponentValue);
          end
        end
      end else if Value is TCollection then
      begin
        if not AncestorValid or
          not CollectionsEqual(TCollection(Value),
            TCollection(GetOrdProp(Ancestor, PropInfo))) then
            WriteCollectionProp(TCollection(Value));
      end else
      begin
        OldAncestor := Ancestor;
        SavePropPath := FPropPath;
        try
          FPropPath := FPropPath + PPropInfo(PropInfo)^.Name + '.';
          if AncestorValid then
            Ancestor := TPersistent(GetOrdProp(Ancestor, PropInfo));
          WriteProperties(TPersistent(Value));
        finally
          Ancestor := OldAncestor;
          FPropPath := SavePropPath;
        end;
      end
  end;

  procedure WriteMethodProp;
  var
    Value: TMethod;

    function IsDefaultValue: Boolean;
    var
      DefaultCode: Pointer;
    begin
      DefaultCode := nil;
      if AncestorValid then DefaultCode := GetMethodProp(Ancestor, PropInfo).Code;
      Result := (Value.Code = DefaultCode) or
        ((Value.Code <> nil) and (FLookupRoot.MethodName(Value.Code) = ''));
    end;

  begin
    Value := GetMethodProp(Instance, PropInfo);
    if not IsDefaultValue then
    begin
      WritePropPath;
      if Value.Code = nil then
        WriteValue(vaNil) else
        WriteIdent(FLookupRoot.MethodName(Value.Code));
    end;
  end;

  procedure WriteVariantProp;
  var
    Value: Variant;

    function IsDefaultValue: Boolean;
    begin
      if AncestorValid then
        Result := Value = GetVariantProp(Ancestor, PropInfo) else
        Result := VarIsEmpty(Value);
    end;

  var
    VType: Integer;
  begin
    Value := GetVariantProp(Instance, PropInfo);
    if not IsDefaultValue then
    begin
      if VarIsArray(Value) then raise EWriteError.CreateRes(@SWriteError);
      WritePropPath;
      VType := VarType(Value);
      case VType and varTypeMask of
        varEmpty: WriteValue(vaNil);
        varNull: WriteValue(vaNull);
        varOleStr: WriteWideString(Value);
        varString: WriteString(Value);
        varByte, varSmallInt, varInteger: WriteInteger(Value);
        varSingle: WriteSingle(Value);
        varDouble: WriteFloat(Value);
        varCurrency: WriteCurrency(Value);
        varDate: WriteDate(Value);
        varBoolean:
          if Value then
            WriteValue(vaTrue) else
            WriteValue(vaFalse);
      else
        try
          WriteString(Value);
        except
          raise EWriteError.CreateRes(@SWriteError);
        end;
      end;
    end;
  end;

begin
  if (PPropInfo(PropInfo)^.SetProc <> nil) and
    (PPropInfo(PropInfo)^.GetProc <> nil) then
  begin
    PropType := PPropInfo(PropInfo)^.PropType^;
    case PropType^.Kind of
      tkInteger, tkChar, tkEnumeration, tkSet: WriteOrdProp;
      tkFloat: WriteFloatProp;
      tkString, tkLString, tkWString: WriteStrProp;
      tkClass: WriteObjectProp;
      tkMethod: WriteMethodProp;
      tkVariant: WriteVariantProp;
      tkInt64: WriteInt64Prop;
    end;
  end;
end;

procedure TWriter.WritePropName(const PropName: string);
begin
  WriteStr(FPropPath + PropName);
end;

procedure TWriter.WriteRootComponent(Root: TComponent);
begin
  WriteDescendent(Root, nil);
end;

procedure TWriter.WriteSignature;
begin
  Write(FilerSignature, SizeOf(FilerSignature));
end;

procedure TWriter.WriteStr(const Value: string);
var
  L: Integer;
begin
  L := Length(Value);
  if L > 255 then L := 255;
  Write(L, SizeOf(Byte));
  Write(Value[1], L);
end;

procedure TWriter.WriteString(const Value: string);
var
  L: Integer;
begin
  L := Length(Value);
  if L <= 255 then
  begin
    WriteValue(vaString);
    Write(L, SizeOf(Byte));
  end else
  begin
    WriteValue(vaLString);
    Write(L, SizeOf(Integer));
  end;
  Write(Pointer(Value)^, L);
end;

procedure TWriter.WriteWideString(const Value: WideString);
var
  L: Integer;
begin
  WriteValue(vaWString);
  L := Length(Value);
  Write(L, SizeOf(Integer));
  Write(Pointer(Value)^, L * 2);
end;

procedure TWriter.WriteValue(Value: TValueType);
begin
  Write(Value, SizeOf(Value));
end;

{ TParser }

const
  ParseBufSize = 4096;

procedure BinToHex(Buffer, Text: PChar; BufSize: Integer); assembler;
asm
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     EDX,0
        JMP     @@1
@@0:    DB      '0123456789ABCDEF'
@@1:    LODSB
        MOV     DL,AL
        AND     DL,0FH
        MOV     AH,@@0.Byte[EDX]
        MOV     DL,AL
        SHR     DL,4
        MOV     AL,@@0.Byte[EDX]
        STOSW
        DEC     ECX
        JNE     @@1
        POP     EDI
        POP     ESI
end;

function HexToBin(Text, Buffer: PChar; BufSize: Integer): Integer; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     EBX,EDX
        MOV     EDX,0
        JMP     @@1
@@0:    DB       0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
        DB      -1,10,11,12,13,14,15
@@1:    LODSW
        CMP     AL,'0'
        JB      @@2
        CMP     AL,'f'
        JA      @@2
        MOV     DL,AL
        MOV     AL,@@0.Byte[EDX-'0']
        CMP     AL,-1
        JE      @@2
        SHL     AL,4
        CMP     AH,'0'
        JB      @@2
        CMP     AH,'f'
        JA      @@2
        MOV     DL,AH
        MOV     AH,@@0.Byte[EDX-'0']
        CMP     AH,-1
        JE      @@2
        OR      AL,AH
        STOSB
        DEC     ECX
        JNE     @@1
@@2:    MOV     EAX,EDI
        SUB     EAX,EBX
        POP     EBX
        POP     EDI
        POP     ESI
end;

constructor TParser.Create(Stream: TStream);
begin
  FStream := Stream;
  GetMem(FBuffer, ParseBufSize);
  FBuffer[0] := #0;
  FBufPtr := FBuffer;
  FBufEnd := FBuffer + ParseBufSize;
  FSourcePtr := FBuffer;
  FSourceEnd := FBuffer;
  FTokenPtr := FBuffer;
  FSourceLine := 1;
  NextToken;
end;

destructor TParser.Destroy;
begin
  if FBuffer <> nil then
  begin
    FStream.Seek(Longint(FTokenPtr) - Longint(FBufPtr), 1);
    FreeMem(FBuffer, ParseBufSize);
  end;
end;

procedure TParser.CheckToken(T: Char);
begin
  if Token <> T then
    case T of
      toSymbol:
        Error(SIdentifierExpected);
      toString, toWString:
        Error(SStringExpected);
      toInteger, toFloat:
        Error(SNumberExpected);
    else
      ErrorFmt(SCharExpected, [T]);
    end;
end;

procedure TParser.CheckTokenSymbol(const S: string);
begin
  if not TokenSymbolIs(S) then ErrorFmt(SSymbolExpected, [S]);
end;

procedure TParser.Error(const Ident: string);
begin
  ErrorStr(Ident);
end;

procedure TParser.ErrorFmt(const Ident: string; const Args: array of const);
begin
  ErrorStr(Format(Ident, Args));
end;

procedure TParser.ErrorStr(const Message: string);
begin
  raise EParserError.CreateResFmt(@SParseError, [Message, FSourceLine]);
end;

procedure TParser.HexToBinary(Stream: TStream);
var
  Count: Integer;
  Buffer: array[0..255] of Char;
begin
  SkipBlanks;
  while FSourcePtr^ <> '}' do
  begin
    Count := HexToBin(FSourcePtr, Buffer, SizeOf(Buffer));
    if Count = 0 then Error(SInvalidBinary);
    Stream.Write(Buffer, Count);
    Inc(FSourcePtr, Count * 2);
    SkipBlanks;
  end;
  NextToken;
end;

function TParser.NextToken: Char;
var
  I, J: Integer;
  IsWideStr: Boolean;
  P, S: PChar;
begin
  SkipBlanks;
  P := FSourcePtr;
  FTokenPtr := P;
  case P^ of
    'A'..'Z', 'a'..'z', '_':
      begin
        Inc(P);
        while P^ in ['A'..'Z', 'a'..'z', '0'..'9', '_'] do Inc(P);
        Result := toSymbol;
      end;
    '#', '''':
      begin
        IsWideStr := False;
        J := 0;
        S := P;
        while True do
          case P^ of
            '#':
              begin
                Inc(P);
                I := 0;
                while P^ in ['0'..'9'] do
                begin
                  I := I * 10 + (Ord(P^) - Ord('0'));
                  Inc(P);
                end;
                if (i > 255) then IsWideStr := True;
                Inc(J);
              end;
            '''':
              begin
                Inc(P);
                while True do
                begin
                  case P^ of
                    #0, #10, #13:
                      Error(SInvalidString);
                    '''':
                      begin
                        Inc(P);
                        if P^ <> '''' then Break;
                      end;
                  end;
                  Inc(J);
                  Inc(P);
                end;
              end;
          else
            Break;
          end;
        P := S;
        if IsWideStr then SetLength(FWideStr, J);
        J := 1;
        while True do
          case P^ of
            '#':
              begin
                Inc(P);
                I := 0;
                while P^ in ['0'..'9'] do
                begin
                  I := I * 10 + (Ord(P^) - Ord('0'));
                  Inc(P);
                end;
                if IsWideStr then
                begin
                  FWideStr[J] := WideChar(SmallInt(I));
                  Inc(J);
                end else
                begin
                  S^ := Chr(I);
                  Inc(S);
                end;
              end;
            '''':
              begin
                Inc(P);
                while True do
                begin
                  case P^ of
                    #0, #10, #13:
                      Error(SInvalidString);
                    '''':
                      begin
                        Inc(P);
                        if P^ <> '''' then Break;
                      end;
                  end;
                  if IsWideStr then
                  begin
                    FWideStr[J] := WideChar(P^);
                    Inc(J);
                  end else
                  begin
                    S^ := P^;
                    Inc(S);
                  end;
                  Inc(P);
                end;
              end;
          else
            Break;
          end;
        FStringPtr := S;
        if IsWideStr then
          Result := toWString else
          Result := toString;
      end;
    '$':
      begin
        Inc(P);
        while P^ in ['0'..'9', 'A'..'F', 'a'..'f'] do Inc(P);
        Result := toInteger;
      end;
    '-', '0'..'9':
      begin
        Inc(P);
        while P^ in ['0'..'9'] do Inc(P);
        Result := toInteger;
        while P^ in ['0'..'9', '.', 'e', 'E', '+', '-'] do
        begin
          Inc(P);
          Result := toFloat;
        end;
        if (P^ in ['c', 'C', 'd', 'D', 's', 'S']) then
        begin
          Result := toFloat;
          FFloatType := P^;
          Inc(P);
        end else
          FFloatType := #0;
      end;
  else
    Result := P^;
    if Result <> toEOF then Inc(P);
  end;
  FSourcePtr := P;
  FToken := Result;
end;

procedure TParser.ReadBuffer;
var
  Count: Integer;
begin
  Inc(FOrigin, FSourcePtr - FBuffer);
  FSourceEnd[0] := FSaveChar;
  Count := FBufPtr - FSourcePtr;
  if Count <> 0 then Move(FSourcePtr[0], FBuffer[0], Count);
  FBufPtr := FBuffer + Count;
  Inc(FBufPtr, FStream.Read(FBufPtr[0], FBufEnd - FBufPtr));
  FSourcePtr := FBuffer;
  FSourceEnd := FBufPtr;
  if FSourceEnd = FBufEnd then
  begin
    FSourceEnd := LineStart(FBuffer, FSourceEnd - 1);
    if FSourceEnd = FBuffer then Error(SLineTooLong);
  end;
  FSaveChar := FSourceEnd[0];
  FSourceEnd[0] := #0;
end;

procedure TParser.SkipBlanks;
begin
  while True do
  begin
    case FSourcePtr^ of
      #0:
        begin
          ReadBuffer;
          if FSourcePtr^ = #0 then Exit;
          Continue;
        end;
      #10:
        Inc(FSourceLine);
      #33..#255:
        Exit;
    end;
    Inc(FSourcePtr);
  end;
end;

function TParser.SourcePos: Longint;
begin
  Result := FOrigin + (FTokenPtr - FBuffer);
end;

function TParser.TokenFloat: Extended;
begin
  if FFloatType <> #0 then Dec(FSourcePtr);
  Result := StrToFloat(TokenString);
  if FFloatType <> #0 then Inc(FSourcePtr);
end;

function TParser.TokenInt: Int64;
begin
  Result := StrToInt64(TokenString);
end;

function TParser.TokenString: string;
var
  L: Integer;
begin
  if FToken = toString then
    L := FStringPtr - FTokenPtr else
    L := FSourcePtr - FTokenPtr;
  SetString(Result, FTokenPtr, L);
end;

function TParser.TokenWideString: WideString;
begin
  Result := FWideStr;
end;

function TParser.TokenSymbolIs(const S: string): Boolean;
begin
  Result := (Token = toSymbol) and SameText(S, TokenString);
end;

function TParser.TokenComponentIdent: string;
var
  P: PChar;
begin
  CheckToken(toSymbol);
  P := FSourcePtr;
  while P^ = '.' do
  begin
    Inc(P);
    if not (P^ in ['A'..'Z', 'a'..'z', '_']) then
      Error(SIdentifierExpected);
    repeat
      Inc(P)
    until not (P^ in ['A'..'Z', 'a'..'z', '0'..'9', '_']);
  end;
  FSourcePtr := P;
  Result := TokenString;
end;

{ Binary to text conversion }

procedure ObjectBinaryToText(Input, Output: TStream);
var
  NestingLevel: Integer;
  SaveSeparator: Char;
  Reader: TReader;
  Writer: TWriter;

  procedure WriteIndent;
  const
    Blanks: array[0..1] of Char = '  ';
  var
    I: Integer;
  begin
    for I := 1 to NestingLevel do Writer.Write(Blanks, SizeOf(Blanks));
  end;

  procedure WriteStr(const S: string);
  begin
    Writer.Write(S[1], Length(S));
  end;

  procedure NewLine;
  begin
    WriteStr(#13#10);
    WriteIndent;
  end;

  procedure ConvertValue; forward;

  procedure ConvertHeader;
  var
    ClassName, ObjectName: string;
    Flags: TFilerFlags;
    Position: Integer;
  begin
    Reader.ReadPrefix(Flags, Position);
    ClassName := Reader.ReadStr;
    ObjectName := Reader.ReadStr;
    WriteIndent;
    if ffInherited in Flags then
      WriteStr('inherited ')
    else if ffInline in Flags then
      WriteStr('inline ')
    else
      WriteStr('object ');
    if ObjectName <> '' then
    begin
      WriteStr(ObjectName);
      WriteStr(': ');
    end;
    WriteStr(ClassName);
    if ffChildPos in Flags then
    begin
      WriteStr(' [');
      WriteStr(IntToStr(Position));
      WriteStr(']');
    end;
    WriteStr(#13#10);
  end;

  procedure ConvertBinary;
  const
    BytesPerLine = 32;
  var
    MultiLine: Boolean;
    I: Integer;
    Count: Longint;
    Buffer: array[0..BytesPerLine - 1] of Char;
    Text: array[0..BytesPerLine * 2 - 1] of Char;
  begin
    Reader.ReadValue;
    WriteStr('{');
    Inc(NestingLevel);
    Reader.Read(Count, SizeOf(Count));
    MultiLine := Count >= BytesPerLine;
    while Count > 0 do
    begin
      if MultiLine then NewLine;
      if Count >= 32 then I := 32 else I := Count;
      Reader.Read(Buffer, I);
      BinToHex(Buffer, Text, I);
      Writer.Write(Text, I * 2);
      Dec(Count, I);
    end;
    Dec(NestingLevel);
    WriteStr('}');
  end;

  procedure ConvertProperty; forward;

  procedure ConvertValue;
  const
    LineLength = 64;
  var
    I, J, K, L: Integer;
    S: string;
    W: WideString;
    LineBreak: Boolean;
  begin
    case Reader.NextValue of
      vaList:
        begin
          Reader.ReadValue;
          WriteStr('(');
          Inc(NestingLevel);
          while not Reader.EndOfList do
          begin
            NewLine;
            ConvertValue;
          end;
          Reader.ReadListEnd;
          Dec(NestingLevel);
          WriteStr(')');
        end;
      vaInt8, vaInt16, vaInt32:
        WriteStr(IntToStr(Reader.ReadInteger));
      vaExtended:
        WriteStr(FloatToStr(Reader.ReadFloat));
      vaSingle:
        WriteStr(FloatToStr(Reader.ReadSingle) + 's');
      vaCurrency:
        WriteStr(FloatToStr(Reader.ReadCurrency * 10000) + 'c');
      vaDate:
        WriteStr(FloatToStr(Reader.ReadDate) + 'd');
      vaWString:
        begin
          W := Reader.ReadWideString;
          L := Length(W);
          if L = 0 then WriteStr('''''') else
          begin
            I := 1;
            Inc(NestingLevel);
            try
              if L > LineLength then NewLine;
              K := I;
              repeat
                LineBreak := False;
                if (W[I] >= ' ') and (W[I] <> '''') and (Ord(W[i]) <= 255) then
                begin
                  J := I;
                  repeat
                    Inc(I)
                  until (I > L) or (W[I] < ' ') or (W[I] = '''') or
                    ((I - K) >= LineLength) or (Ord(W[i]) > 255);
                  if ((I - K) >= LineLength) then
                  begin
                    LineBreak := True;
                    if ByteType(W, I) = mbTrailByte then Dec(I);
                  end;
                  WriteStr('''');
                  while J < I do
                  begin
                    WriteStr(Char(W[J]));
                    Inc(J);
                  end;
                  WriteStr('''');
                end else
                begin
                  WriteStr('#');
                  WriteStr(IntToStr(Ord(W[I])));
                  Inc(I);
                  if ((I - K) >= LineLength) then LineBreak := True;
                end;
                if LineBreak and (I <= L) then
                begin
                  WriteStr(' +');
                  NewLine;
                  K := I;
                end;
              until I > L;
            finally
              Dec(NestingLevel);
            end;
          end;
        end;
      vaString, vaLString:
        begin
          S := Reader.ReadString;
          L := Length(S);
          if L = 0 then WriteStr('''''') else
          begin
            I := 1;
            Inc(NestingLevel);
            try
              if L > LineLength then NewLine;
              K := I;
              repeat
                LineBreak := False;
                if (S[I] >= ' ') and (S[I] <> '''') then
                begin
                  J := I;
                  repeat
                    Inc(I)
                  until (I > L) or (S[I] < ' ') or (S[I] = '''') or
                    ((I - K) >= LineLength);
                  if ((I - K) >= LineLength) then
                  begin
                    LIneBreak := True;
                    if ByteType(S, I) = mbTrailByte then Dec(I);
                  end;
                  WriteStr('''');
                  Writer.Write(S[J], I - J);
                  WriteStr('''');
                end else
                begin
                  WriteStr('#');
                  WriteStr(IntToStr(Ord(S[I])));
                  Inc(I);
                  if ((I - K) >= LineLength) then LineBreak := True;
                end;
                if LineBreak and (I <= L) then
                begin
                  WriteStr(' +');
                  NewLine;
                  K := I;
                end;
              until I > L;
            finally
              Dec(NestingLevel);
            end;
          end;
        end;
      vaIdent, vaFalse, vaTrue, vaNil, vaNull:
        WriteStr(Reader.ReadIdent);
      vaBinary:
        ConvertBinary;
      vaSet:
        begin
          Reader.ReadValue;
          WriteStr('[');
          I := 0;
          while True do
          begin
            S := Reader.ReadStr;
            if S = '' then Break;
            if I > 0 then WriteStr(', ');
            WriteStr(S);
            Inc(I);
          end;
          WriteStr(']');
        end;
      vaCollection:
        begin
          Reader.ReadValue;
          WriteStr('<');
          Inc(NestingLevel);
          while not Reader.EndOfList do
          begin
            NewLine;
            WriteStr('item');
            if Reader.NextValue in [vaInt8, vaInt16, vaInt32] then
            begin
              WriteStr(' [');
              ConvertValue;
              WriteStr(']');
            end;
            WriteStr(#13#10);
            Reader.CheckValue(vaList);
            Inc(NestingLevel);
            while not Reader.EndOfList do ConvertProperty;
            Reader.ReadListEnd;
            Dec(NestingLevel);
            WriteIndent;
            WriteStr('end');
          end;
          Reader.ReadListEnd;
          Dec(NestingLevel);
          WriteStr('>');
        end;
      vaInt64:
        WriteStr(IntToStr(Reader.ReadInt64));
    end;
  end;

  procedure ConvertProperty;
  begin
    WriteIndent;
    WriteStr(Reader.ReadStr);
    WriteStr(' = ');
    ConvertValue;
    WriteStr(#13#10);
  end;

  procedure ConvertObject;
  begin
    ConvertHeader;
    Inc(NestingLevel);
    while not Reader.EndOfList do ConvertProperty;
    Reader.ReadListEnd;
    while not Reader.EndOfList do ConvertObject;
    Reader.ReadListEnd;
    Dec(NestingLevel);
    WriteIndent;
    WriteStr('end'#13#10);
  end;

begin
  NestingLevel := 0;
  Reader := TReader.Create(Input, 4096);
  SaveSeparator := DecimalSeparator;
  DecimalSeparator := '.';
  try
    Writer := TWriter.Create(Output, 4096);
    try
      Reader.ReadSignature;
      ConvertObject;
    finally
      Writer.Free;
    end;
  finally
    DecimalSeparator := SaveSeparator;
    Reader.Free;
  end;
end;

type
  TObjectTextConvertProc = procedure (Input, Output: TStream);

procedure InternalBinaryToText(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat;
  ConvertProc: TObjectTextConvertProc;
  BinarySignature: Integer; SignatureLength: Byte);
var
  Pos: Integer;
  Signature: Integer;
begin
  Pos := Input.Position;
  Signature := 0;
  if SignatureLength > sizeof(Signature) then SignatureLength := sizeof(Signature);
  Input.Read(Signature, SignatureLength);
  Input.Position := Pos;
  if Signature = BinarySignature then
  begin     // definitely binary format
    if OriginalFormat = sofBinary then
      Output.CopyFrom(Input, Input.Size - Input.Position)
    else
    begin
      if OriginalFormat = sofUnknown then
        Originalformat := sofBinary;
      ConvertProc(Input, Output);
    end;
  end
  else  // might be text format
  begin
    if OriginalFormat = sofBinary then
      ConvertProc(Input, Output)
    else
    begin
      if OriginalFormat = sofUnknown then
      begin   // text format may begin with "object", "inherited", or whitespace
        if Char(Signature) in ['o','O','i','I',' ',#13,#11,#9] then
          OriginalFormat := sofText
        else    // not binary, not text... let it raise the exception
        begin
          ConvertProc(Input, Output);
          Exit;
        end;
      end;
      if OriginalFormat = sofText then
        Output.CopyFrom(Input, Input.Size - Input.Position);
    end;
  end;
end;

procedure InternalTextToBinary(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat;
  ConvertProc: TObjectTextConvertProc;
  BinarySignature: Integer; SignatureLength: Byte);
var
  Pos: Integer;
  Signature: Integer;
begin
  Pos := Input.Position;
  Signature := 0;
  if SignatureLength > sizeof(Signature) then SignatureLength := sizeof(Signature);
  Input.Read(Signature, SignatureLength);
  Input.Position := Pos;
  if Signature = BinarySignature then
  begin     // definitely binary format
    if OriginalFormat = sofUnknown then
      Originalformat := sofBinary;
    if OriginalFormat = sofBinary then
      Output.CopyFrom(Input, Input.Size - Input.Position)
    else    // let it raise the exception
      ConvertProc(Input, Output);
  end
  else  // might be text format
  begin
    case OriginalFormat of
      sofUnknown:
        begin  // text format may begin with "object", "inherited", or whitespace
          if Char(Signature) in ['o','O','i','I',' ',#13,#11,#9] then
            OriginalFormat := sofText;
          // if its not binary, not text... let it raise the exception
          ConvertProc(Input, Output);
        end;
      sofBinary:  ConvertProc(Input, Output);
      sofText:    Output.CopyFrom(Input, Input.Size - Input.Position);
    end;
  end;
end;

procedure ObjectBinaryToText(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat);
begin
  InternalBinaryToText(Input, Output, OriginalFormat, ObjectBinaryToText,
    Integer(FilerSignature), sizeof(Integer));
end;

{ Text to binary conversion }

procedure ObjectTextToBinary(Input, Output: TStream);
var
  SaveSeparator: Char;
  Parser: TParser;
  Writer: TWriter;

  function ConvertOrderModifier: Integer;
  begin
    Result := -1;
    if Parser.Token = '[' then
    begin
      Parser.NextToken;
      Parser.CheckToken(toInteger);
      Result := Parser.TokenInt;
      Parser.NextToken;
      Parser.CheckToken(']');
      Parser.NextToken;
    end;
  end;

  procedure ConvertHeader(IsInherited, IsInline: Boolean);
  var
    ClassName, ObjectName: string;
    Flags: TFilerFlags;
    Position: Integer;
  begin
    Parser.CheckToken(toSymbol);
    ClassName := Parser.TokenString;
    ObjectName := '';
    if Parser.NextToken = ':' then
    begin
      Parser.NextToken;
      Parser.CheckToken(toSymbol);
      ObjectName := ClassName;
      ClassName := Parser.TokenString;
      Parser.NextToken;
    end;
    Flags := [];
    Position := ConvertOrderModifier;
    if IsInherited then
      Include(Flags, ffInherited);
    if IsInline then
      Include(Flags, ffInline);
    if Position >= 0 then
      Include(Flags, ffChildPos);
    Writer.WritePrefix(Flags, Position);
    Writer.WriteStr(ClassName);
    Writer.WriteStr(ObjectName);
  end;

  procedure ConvertProperty; forward;

  procedure ConvertValue;
  var
    Order: Integer;

    function CombineString: string;
    begin
      Result := Parser.TokenString;
      while Parser.NextToken = '+' do
      begin
        Parser.NextToken;
        Parser.CheckToken(toString);
        Result := Result + Parser.TokenString;
      end;
    end;

    function CombineWideString: WideString;
    begin
      Result := Parser.TokenWideString;
      while Parser.NextToken = '+' do
      begin
        Parser.NextToken;
        Parser.CheckToken(toWString);
        Result := Result + Parser.TokenWideString;
      end;
    end;

  begin
    if Parser.Token = toString then
      Writer.WriteString(CombineString)
    else if Parser.Token = toWString then
      Writer.WriteWideString(CombineWideString)
    else
    begin
      case Parser.Token of
        toSymbol:
          Writer.WriteIdent(Parser.TokenComponentIdent);
        toInteger:
          Writer.WriteInteger(Parser.TokenInt);
        toFloat:
          begin
            case Parser.FloatType of
              's', 'S': Writer.WriteSingle(Parser.TokenFloat);
              'c', 'C': Writer.WriteCurrency(Parser.TokenFloat / 10000);
              'd', 'D': Writer.WriteDate(Parser.TokenFloat);
            else
              Writer.WriteFloat(Parser.TokenFloat);
            end;
          end;
        '[':
          begin
            Parser.NextToken;
            Writer.WriteValue(vaSet);
            if Parser.Token <> ']' then
              while True do
              begin
                if Parser.Token <> toInteger then
                  Parser.CheckToken(toSymbol);
                Writer.WriteStr(Parser.TokenString);
                if Parser.NextToken = ']' then Break;
                Parser.CheckToken(',');
                Parser.NextToken;
              end;
            Writer.WriteStr('');
          end;
        '(':
          begin
            Parser.NextToken;
            Writer.WriteListBegin;
            while Parser.Token <> ')' do ConvertValue;
            Writer.WriteListEnd;
          end;
        '{':
          Writer.WriteBinary(Parser.HexToBinary);
        '<':
          begin
            Parser.NextToken;
            Writer.WriteValue(vaCollection);
            while Parser.Token <> '>' do
            begin
              Parser.CheckTokenSymbol('item');
              Parser.NextToken;
              Order := ConvertOrderModifier;
              if Order <> -1 then Writer.WriteInteger(Order);
              Writer.WriteListBegin;
              while not Parser.TokenSymbolIs('end') do ConvertProperty;
              Writer.WriteListEnd;
              Parser.NextToken;
            end;
            Writer.WriteListEnd;
          end;
      else
        Parser.Error(SInvalidProperty);
      end;
      Parser.NextToken;
    end;
  end;

  procedure ConvertProperty;
  var
    PropName: string;
  begin
    Parser.CheckToken(toSymbol);
    PropName := Parser.TokenString;
    Parser.NextToken;
    while Parser.Token = '.' do
    begin
      Parser.NextToken;
      Parser.CheckToken(toSymbol);
      PropName := PropName + '.' + Parser.TokenString;
      Parser.NextToken;
    end;
    Writer.WriteStr(PropName);
    Parser.CheckToken('=');
    Parser.NextToken;
    ConvertValue;
  end;

  procedure ConvertObject;
  var
    InheritedObject: Boolean;
    InlineObject: Boolean;
  begin
    InheritedObject := False;
    InlineObject := False;
    if Parser.TokenSymbolIs('INHERITED') then
      InheritedObject := True
    else if Parser.TokenSymbolIs('INLINE') then
      InlineObject := True
    else
      Parser.CheckTokenSymbol('OBJECT');
    Parser.NextToken;
    ConvertHeader(InheritedObject, InlineObject);
    while not Parser.TokenSymbolIs('END') and
      not Parser.TokenSymbolIs('OBJECT') and
      not Parser.TokenSymbolIs('INHERITED') and
      not Parser.TokenSymbolIs('INLINE') do
      ConvertProperty;
    Writer.WriteListEnd;
    while not Parser.TokenSymbolIs('END') do ConvertObject;
    Writer.WriteListEnd;
    Parser.NextToken;
  end;

begin
  Parser := TParser.Create(Input);
  SaveSeparator := DecimalSeparator;
  DecimalSeparator := '.';
  try
    Writer := TWriter.Create(Output, 4096);
    try
      Writer.WriteSignature;
      ConvertObject;
    finally
      Writer.Free;
    end;
  finally
    DecimalSeparator := SaveSeparator;
    Parser.Free;
  end;
end;

procedure ObjectTextToBinary(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat);
begin
  InternalTextToBinary(Input, Output, OriginalFormat, ObjectTextToBinary,
    Integer(FilerSignature), sizeof(Integer));
end;

{ Resource to text conversion }

procedure ObjectResourceToText(Input, Output: TStream);
begin
  Input.ReadResHeader;
  ObjectBinaryToText(Input, Output);
end;

procedure ObjectResourceToText(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat);
begin
  InternalBinaryToText(Input, Output, OriginalFormat, ObjectResourceToText, $FF, 1);
end;

{ Text to resource conversion }

procedure ObjectTextToResource(Input, Output: TStream);
var
  Len: Byte;
  Tmp: Longint;
  MemoryStream: TMemoryStream;
  MemorySize: Longint;
  Header: array[0..79] of Char;
begin
  MemoryStream := TMemoryStream.Create;
  try
    ObjectTextToBinary(Input, MemoryStream);
    MemorySize := MemoryStream.Size;
    FillChar(Header, SizeOf(Header), 0);
    MemoryStream.Position := SizeOf(Longint); { Skip header }
    MemoryStream.Read(Len, 1);

    { Skip over object prefix if it is present }
    if Len and $F0 = $F0 then
    begin
      if ffChildPos in TFilerFlags((Len and $F0)) then
      begin
        MemoryStream.Read(Len, 1);
        case TValueType(Len) of
          vaInt8: Len := 1;
          vaInt16: Len := 2;
          vaInt32: Len := 4;
        end;
        MemoryStream.Read(Tmp, Len);
      end;
      MemoryStream.Read(Len, 1);
    end;

    MemoryStream.Read(Header[3], Len);
    StrUpper(@Header[3]);
    Byte((@Header[0])^) := $FF;
    Word((@Header[1])^) := 10;
    Word((@Header[Len + 4])^) := $1030;
    Longint((@Header[Len + 6])^) := MemorySize;
    Output.Write(Header, Len + 10);
    Output.Write(MemoryStream.Memory^, MemorySize);
  finally
    MemoryStream.Free;
  end;
end;

procedure ObjectTextToResource(Input, Output: TStream;
  var OriginalFormat: TStreamOriginalFormat);
begin
  InternalTextToBinary(Input, Output, OriginalFormat, ObjectTextToResource, $FF, 1);
end;

function TestStreamFormat(Stream: TStream): TStreamOriginalFormat;
var
  Pos: Integer;
  Signature: Integer;
begin
  Pos := Stream.Position;
  Signature := 0;
  Stream.Read(Signature, sizeof(Signature));
  Stream.Position := Pos;
  if (Byte(Signature) = $FF) or (Signature = Integer(FilerSignature)) then
    Result := sofBinary
    // text format may begin with "object", "inherited", or whitespace
  else if Char(Signature) in ['o','O','i','I',' ',#13,#11,#9] then
    Result := sofText
  else
    Result := sofUnknown;
end;

{ Thread management routines }

const
  CM_EXECPROC = $8FFF;
  CM_DESTROYWINDOW = $8FFE;

type
  PRaiseFrame = ^TRaiseFrame;
  TRaiseFrame = record
    NextRaise: PRaiseFrame;
    ExceptAddr: Pointer;
    ExceptObject: TObject;
    ExceptionRecord: PExceptionRecord;
  end;

var
  ThreadLock: TRTLCriticalSection;
  ThreadWindow: HWND;
  ThreadCount: Integer;

procedure FreeThreadWindow;
begin
  if ThreadWindow <> 0 then
  begin
    DestroyWindow(ThreadWindow);
    ThreadWindow := 0;
  end;
end;

function ThreadWndProc(Window: HWND; Message, wParam, lParam: Longint): Longint; stdcall;
begin
  case Message of
    CM_EXECPROC:
      with TThread(lParam) do
      begin
        Result := 0;
        try
          FSynchronizeException := nil;
          FMethod;
        except
          if RaiseList <> nil then
          begin
            FSynchronizeException := PRaiseFrame(RaiseList)^.ExceptObject;
            PRaiseFrame(RaiseList)^.ExceptObject := nil;
          end;
        end;
      end;
    CM_DESTROYWINDOW:
      begin
        EnterCriticalSection(ThreadLock);
        try
          Dec(ThreadCount);
          if ThreadCount = 0 then
            FreeThreadWindow;
        finally
          LeaveCriticalSection(ThreadLock);
        end;
        Result := 0;
      end;
  else
    Result := DefWindowProc(Window, Message, wParam, lParam);
  end;
end;

var
  ThreadWindowClass: TWndClass = (
    style: 0;
    lpfnWndProc: @ThreadWndProc;
    cbClsExtra: 0;
    cbWndExtra: 0;
    hInstance: 0;
    hIcon: 0;
    hCursor: 0;
    hbrBackground: 0;
    lpszMenuName: nil;
    lpszClassName: 'TThreadWindow');

procedure AddThread;

  function AllocateWindow: HWND;
  var
    TempClass: TWndClass;
    ClassRegistered: Boolean;
  begin
    ThreadWindowClass.hInstance := HInstance;
    ClassRegistered := GetClassInfo(HInstance, ThreadWindowClass.lpszClassName,
      TempClass);
    if not ClassRegistered or (TempClass.lpfnWndProc <> @ThreadWndProc) then
    begin
      if ClassRegistered then
        Windows.UnregisterClass(ThreadWindowClass.lpszClassName, HInstance);
      Windows.RegisterClass(ThreadWindowClass);
    end;
    Result := CreateWindow(ThreadWindowClass.lpszClassName, '', 0,
      0, 0, 0, 0, 0, 0, HInstance, nil);
  end;

begin
  EnterCriticalSection(ThreadLock);
  try
    if ThreadCount = 0 then
      ThreadWindow := AllocateWindow;
    Inc(ThreadCount);
  finally
    LeaveCriticalSection(ThreadLock);
  end;
end;

procedure RemoveThread;
begin
  EnterCriticalSection(ThreadLock);
  try
    if ThreadCount = 1 then
      PostMessage(ThreadWindow, CM_DESTROYWINDOW, 0, 0);
  finally
    LeaveCriticalSection(ThreadLock);
  end;
end;

{ TThread }

function ThreadProc(Thread: TThread): Integer;
var
  FreeThread: Boolean;
begin
  try
    Thread.Execute;
  finally
    FreeThread := Thread.FFreeOnTerminate;
    Result := Thread.FReturnValue;
    Thread.FFinished := True;
    Thread.DoTerminate;
    if FreeThread then Thread.Free;
    EndThread(Result);
  end;
end;

constructor TThread.Create(CreateSuspended: Boolean);
var
  Flags: DWORD;
begin
  inherited Create;
  AddThread;
  FSuspended := CreateSuspended;
  Flags := 0;
  if CreateSuspended then Flags := CREATE_SUSPENDED;
  FHandle := BeginThread(nil, 0, @ThreadProc, Pointer(Self), Flags, FThreadID);
end;

destructor TThread.Destroy;
begin
  if not FFinished and not Suspended then
  begin
    Terminate;
    WaitFor;
  end;
  if FHandle <> 0 then CloseHandle(FHandle);
  inherited Destroy;
  RemoveThread;
end;

procedure TThread.CallOnTerminate;
begin
  if Assigned(FOnTerminate) then FOnTerminate(Self);
end;

procedure TThread.DoTerminate;
begin
  if Assigned(FOnTerminate) then Synchronize(CallOnTerminate);
end;

const
  Priorities: array [TThreadPriority] of Integer =
   (THREAD_PRIORITY_IDLE, THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_BELOW_NORMAL,
    THREAD_PRIORITY_NORMAL, THREAD_PRIORITY_ABOVE_NORMAL,
    THREAD_PRIORITY_HIGHEST, THREAD_PRIORITY_TIME_CRITICAL);

function TThread.GetPriority: TThreadPriority;
var
  P: Integer;
  I: TThreadPriority;
begin
  P := GetThreadPriority(FHandle);
  Result := tpNormal;
  for I := Low(TThreadPriority) to High(TThreadPriority) do
    if Priorities[I] = P then Result := I;
end;

procedure TThread.SetPriority(Value: TThreadPriority);
begin
  SetThreadPriority(FHandle, Priorities[Value]);
end;

procedure TThread.Synchronize(Method: TThreadMethod);
begin
  FSynchronizeException := nil;
  FMethod := Method;
  SendMessage(ThreadWindow, CM_EXECPROC, 0, Longint(Self));
  if Assigned(FSynchronizeException) then raise FSynchronizeException;
end;

procedure TThread.SetSuspended(Value: Boolean);
begin
  if Value <> FSuspended then
    if Value then
      Suspend else
      Resume;
end;

procedure TThread.Suspend;
begin
  FSuspended := True;
  SuspendThread(FHandle);
end;

procedure TThread.Resume;
begin
  if ResumeThread(FHandle) = 1 then FSuspended := False;
end;

procedure TThread.Terminate;
begin
  FTerminated := True;
end;

function TThread.WaitFor: LongWord;
var
  Msg: TMsg;
  H: THandle;
begin
  H := FHandle;
  if GetCurrentThreadID = MainThreadID then
    while MsgWaitForMultipleObjects(1, H, False, INFINITE,
      QS_SENDMESSAGE) = WAIT_OBJECT_0 + 1 do PeekMessage(Msg, 0, 0, 0, PM_NOREMOVE)
  else WaitForSingleObject(H, INFINITE);
  GetExitCodeThread(H, Result);
end;

{ TComponent }

constructor TComponent.Create(AOwner: TComponent);
begin
  FComponentStyle := [csInheritable];
  if AOwner <> nil then AOwner.InsertComponent(Self);
end;

destructor TComponent.Destroy;
var
  I: Integer;
begin
  Destroying;
  if FFreeNotifies <> nil then
  begin
    for I := FFreeNotifies.Count - 1 downto 0 do
    begin
      TComponent(FFreeNotifies[I]).Notification(Self, opRemove);
      if FFreeNotifies = nil then Break;
    end;
    FFreeNotifies.Free;
    FFreeNotifies := nil;
  end;
  DestroyComponents;
  if FOwner <> nil then FOwner.RemoveComponent(Self);
  inherited Destroy;
end;

procedure TComponent.BeforeDestruction;
begin
  if not (csDestroying in ComponentState) then
    Destroying;
end;

procedure TComponent.FreeNotification(AComponent: TComponent);
begin
  if (Owner = nil) or (AComponent.Owner <> Owner) then
  begin
    if not Assigned(FFreeNotifies) then FFreeNotifies := TList.Create;
    if FFreeNotifies.IndexOf(AComponent) < 0 then
    begin
      FFreeNotifies.Add(AComponent);
      AComponent.FreeNotification(Self);
    end;
  end;
  Include(FComponentState, csFreeNotification);
end;

procedure TComponent.ReadLeft(Reader: TReader);
begin
  LongRec(FDesignInfo).Lo := Reader.ReadInteger;
end;

procedure TComponent.ReadTop(Reader: TReader);
begin
  LongRec(FDesignInfo).Hi := Reader.ReadInteger;
end;

procedure TComponent.WriteLeft(Writer: TWriter);
begin
  Writer.WriteInteger(LongRec(FDesignInfo).Lo);
end;

procedure TComponent.WriteTop(Writer: TWriter);
begin
  Writer.WriteInteger(LongRec(FDesignInfo).Hi);
end;

procedure TComponent.Insert(AComponent: TComponent);
begin
  if FComponents = nil then FComponents := TList.Create;
  FComponents.Add(AComponent);
  AComponent.FOwner := Self;
end;

procedure TComponent.Remove(AComponent: TComponent);
begin
  AComponent.FOwner := nil;
  FComponents.Remove(AComponent);
  if FComponents.Count = 0 then
  begin
    FComponents.Free;
    FComponents := nil;
  end;
end;

procedure TComponent.InsertComponent(AComponent: TComponent);
begin
  AComponent.ValidateContainer(Self);
  ValidateRename(AComponent, '', AComponent.FName);
  Insert(AComponent);
  AComponent.SetReference(True);
  if csDesigning in ComponentState then
    AComponent.SetDesigning(True);
  Notification(AComponent, opInsert);
end;

procedure TComponent.RemoveComponent(AComponent: TComponent);
begin
  ValidateRename(AComponent, AComponent.FName, '');
  Notification(AComponent, opRemove);
  AComponent.SetReference(False);
  Remove(AComponent);
end;

procedure TComponent.DestroyComponents;
var
  Instance: TComponent;
begin
  while FComponents <> nil do
  begin
    Instance := FComponents.Last;
    if (csFreeNotification in Instance.FComponentState)
      or (FComponentState * [csDesigning, csInline] = [csDesigning, csInline]) then
      RemoveComponent(Instance)
    else
      Remove(Instance);
    Instance.Destroy;
  end;
end;

procedure TComponent.Destroying;
var
  I: Integer;
begin
  if not (csDestroying in FComponentState) then
  begin
    Include(FComponentState, csDestroying);
    if FComponents <> nil then
      for I := 0 to FComponents.Count - 1 do
        TComponent(FComponents[I]).Destroying;
  end;
end;

procedure TComponent.RemoveNotification(AComponent: TComponent);
begin
  if FFreeNotifies <> nil then
  begin
    FFreeNotifies.Remove(AComponent);
    if FFreeNotifies.Count = 0 then
    begin
      FFreeNotifies.Free;
      FFreeNotifies := nil;
    end;
  end;
end;

procedure TComponent.RemoveFreeNotification(AComponent: TComponent);
begin
  RemoveNotification(AComponent);
  AComponent.RemoveNotification(Self);
end;

procedure TComponent.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  I: Integer;
begin
  if (Operation = opRemove) and (AComponent <> nil) then
    RemoveFreeNotification(AComponent);
  if FComponents <> nil then
    for I := 0 to FComponents.Count - 1 do
      TComponent(FComponents[I]).Notification(AComponent, Operation);
end;

procedure TComponent.DefineProperties(Filer: TFiler);
var
  Ancestor: TComponent;
  Info: Longint;
begin
  Info := 0;
  Ancestor := TComponent(Filer.Ancestor);
  if Ancestor <> nil then Info := Ancestor.FDesignInfo;
  Filer.DefineProperty('Left', ReadLeft, WriteLeft,
    LongRec(FDesignInfo).Lo <> LongRec(Info).Lo);
  Filer.DefineProperty('Top', ReadTop, WriteTop,
    LongRec(FDesignInfo).Hi <> LongRec(Info).Hi);
end;

function TComponent.HasParent: Boolean;
begin
  Result := False;
end;

procedure TComponent.GetChildren(Proc: TGetChildProc; Root: TComponent);
begin
end;

function TComponent.GetChildOwner: TComponent;
begin
  Result := nil;
end;

function TComponent.GetChildParent: TComponent;
begin
  Result := Self;
end;

function TComponent.GetNamePath: string;
begin
  Result := FName;
end;

function TComponent.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

procedure TComponent.SetChildOrder(Child: TComponent; Order: Integer);
begin
end;

function TComponent.GetParentComponent: TComponent;
begin
  Result := nil;
end;

procedure TComponent.SetParentComponent(Value: TComponent);
begin
end;

procedure TComponent.Updating;
begin
  Include(FComponentState, csUpdating);
end;

procedure TComponent.Updated;
begin
  Exclude(FComponentState, csUpdating);
end;

procedure TComponent.Loaded;
begin
  Exclude(FComponentState, csLoading);
end;

procedure TComponent.ReadState(Reader: TReader);
begin
  Reader.ReadData(Self);
end;

procedure TComponent.WriteState(Writer: TWriter);
begin
  Writer.WriteData(Self);
end;

procedure TComponent.ValidateRename(AComponent: TComponent;
  const CurName, NewName: string);
begin
  if (AComponent <> nil) and not SameText(CurName, NewName) and
    (AComponent.Owner = Self) and (FindComponent(NewName) <> nil) then
    raise EComponentError.CreateResFmt(@SDuplicateName, [NewName]);
  if (csDesigning in ComponentState) and (Owner <> nil) then
    Owner.ValidateRename(AComponent, CurName, NewName);
end;

procedure TComponent.ValidateContainer(AComponent: TComponent);
begin
  AComponent.ValidateInsert(Self);
end;

procedure TComponent.ValidateInsert(AComponent: TComponent);
begin
end;

function TComponent.FindComponent(const AName: string): TComponent;
var
  I: Integer;
begin
  if (AName <> '') and (FComponents <> nil) then
    for I := 0 to FComponents.Count - 1 do
    begin
      Result := FComponents[I];
      if SameText(Result.FName, AName) then Exit;
    end;
  Result := nil;
end;

procedure TComponent.SetName(const NewName: TComponentName);
begin
  if FName <> NewName then
  begin
    if (NewName <> '') and not IsValidIdent(NewName) then
      raise EComponentError.CreateResFmt(@SInvalidName, [NewName]);
    if FOwner <> nil then
      FOwner.ValidateRename(Self, FName, NewName) else
      ValidateRename(nil, FName, NewName);
    SetReference(False);
    ChangeName(NewName);
    SetReference(True);
  end;
end;

procedure TComponent.ChangeName(const NewName: TComponentName);
begin
  FName := NewName;
end;

function TComponent.GetComponentIndex: Integer;
begin
  if (FOwner <> nil) and (FOwner.FComponents <> nil) then
    Result := FOwner.FComponents.IndexOf(Self) else
    Result := -1;
end;

function TComponent.GetComponent(AIndex: Integer): TComponent;
begin
  if FComponents = nil then TList.Error(@SListIndexError, AIndex);
  Result := FComponents[AIndex];
end;

function TComponent.GetComponentCount: Integer;
begin
  if FComponents <> nil then
    Result := FComponents.Count else
    Result := 0;
end;

procedure TComponent.SetComponentIndex(Value: Integer);
var
  I, Count: Integer;
begin
  if FOwner <> nil then
  begin
    I := FOwner.FComponents.IndexOf(Self);
    if I >= 0 then
    begin
      Count := FOwner.FComponents.Count;
      if Value < 0 then Value := 0;
      if Value >= Count then Value := Count - 1;
      if Value <> I then
      begin
        FOwner.FComponents.Delete(I);
        FOwner.FComponents.Insert(Value, Self);
      end;
    end;
  end;
end;

procedure TComponent.SetAncestor(Value: Boolean);
var
  I: Integer;
begin
  if Value then
    Include(FComponentState, csAncestor) else
    Exclude(FComponentState, csAncestor);
  for I := 0 to ComponentCount - 1 do
    Components[I].SetAncestor(Value);
end;

procedure TComponent.SetDesigning(Value, SetChildren: Boolean);
var
  I: Integer;
begin
  if Value then
    Include(FComponentState, csDesigning) else
    Exclude(FComponentState, csDesigning);
  if SetChildren then
    for I := 0 to ComponentCount - 1 do Components[I].SetDesigning(Value);
end;

procedure TComponent.SetInline(Value: Boolean);
begin
  if Value then
    Include(FComponentState, csInline) else
    Exclude(FComponentState, csInline);
end;

procedure TComponent.SetDesignInstance(Value: Boolean);
begin
  if Value then
    Include(FComponentState, csDesignInstance) else
    Exclude(FComponentState, csDesignInstance);
end;

procedure TComponent.SetReference(Enable: Boolean);
var
  Field: ^TComponent;
begin
  if FOwner <> nil then
  begin
    Field := FOwner.FieldAddress(FName);
    if Field <> nil then
      if Enable then Field^ := Self else Field^ := nil;
  end;
end;

function TComponent.ExecuteAction(Action: TBasicAction): Boolean;//!
begin
  if Action.HandlesTarget(Self) then
  begin
    Action.ExecuteTarget(Self);
    Result := True;
  end
  else Result := False;
end;

function TComponent.UpdateAction(Action: TBasicAction): Boolean;//!
begin
  if Action.HandlesTarget(Self) then
  begin
    Action.UpdateTarget(Self);
    Result := True;
  end
  else Result := False;
end;

function TComponent.GetComObject: IUnknown;
begin
  if FVCLComObject = nil then
  begin
    if Assigned(CreateVCLComObjectProc) then CreateVCLComObjectProc(Self);
    if FVCLComObject = nil then
      raise EComponentError.CreateResFmt(@SNoComSupport, [ClassName]);
  end;
  IVCLComObject(FVCLComObject).QueryInterface(IUnknown, Result);
end;

function TComponent.SafeCallException(ExceptObject: TObject;
  ExceptAddr: Pointer): HResult;
begin
  if FVCLComObject <> nil then
    Result := IVCLComObject(FVCLComObject).SafeCallException(
      ExceptObject, ExceptAddr)
  else
    Result := inherited SafeCallException(ExceptObject, ExceptAddr);
end;

procedure TComponent.FreeOnRelease;
begin
  if FVCLComObject <> nil then IVCLComObject(FVCLComObject).FreeOnRelease;
end;

class procedure TComponent.UpdateRegistry(Register: Boolean; const ClassID, ProgID: string);
begin
end;

{ TComponent.IUnknown }

function TComponent.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if FVCLComObject = nil then
  begin
    if GetInterface(IID, Obj) then Result := S_OK
    else Result := E_NOINTERFACE
  end
  else
    Result := IVCLComObject(FVCLComObject).QueryInterface(IID, Obj);
end;

function TComponent._AddRef: Integer;
begin
  if FVCLComObject = nil then
    Result := -1   // -1 indicates no reference counting is taking place
  else
    Result := IVCLComObject(FVCLComObject)._AddRef;
end;

function TComponent._Release: Integer;
begin
  if FVCLComObject = nil then
    Result := -1   // -1 indicates no reference counting is taking place
  else
    Result := IVCLComObject(FVCLComObject)._Release;
end;

{ TComponent.IDispatch }

function TComponent.GetTypeInfoCount(out Count: Integer): HResult;
begin
  if FVCLComObject = nil then
    Result := E_NOTIMPL
  else
    Result := IVCLComObject(FVCLComObject).GetTypeInfoCount(Count);
end;

function TComponent.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult;
begin
  if FVCLComObject = nil then
    Result := E_NOTIMPL
  else
    Result := IVCLComObject(FVCLComObject).GetTypeInfo(
      Index, LocaleID, TypeInfo);
end;

function TComponent.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  if FVCLComObject = nil then
    Result := E_NOTIMPL
  else
    Result := IVCLComObject(FVCLComObject).GetIDsOfNames(IID, Names,
      NameCount, LocaleID, DispIDs);
end;

function TComponent.Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;
begin
  if FVCLComObject = nil then
    Result := E_NOTIMPL
  else
    Result := IVCLComObject(FVCLComObject).Invoke(DispID, IID, LocaleID,
      Flags, Params, VarResult, ExcepInfo, ArgErr);
end;

{ TBasicActionLink }

constructor TBasicActionLink.Create(AClient: TObject);
begin
  inherited Create;
  AssignClient(AClient);
end;

procedure TBasicActionLink.AssignClient(AClient: TObject);
begin
end;

destructor TBasicActionLink.Destroy;
begin
  if FAction <> nil then FAction.UnRegisterChanges(Self);
  inherited Destroy;
end;

procedure TBasicActionLink.Change;
begin
  if Assigned(OnChange) then OnChange(FAction);
end;

function TBasicActionLink.Execute: Boolean;
begin
  Result := FAction.Execute;
end;

procedure TBasicActionLink.SetAction(Value: TBasicAction);
begin
  if Value <> FAction then
  begin
    if FAction <> nil then FAction.UnRegisterChanges(Self);
    FAction := Value;
    if Value <> nil then Value.RegisterChanges(Self);
  end;
end;

function TBasicActionLink.IsOnExecuteLinked: Boolean;
begin
  Result := True;
end;

procedure TBasicActionLink.SetOnExecute(Value: TNotifyEvent);
begin
end;

function TBasicActionLink.Update: Boolean;
begin
  Result := FAction.Update;
end;

{ TBasicAction }

constructor TBasicAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FClients := TList.Create;
end;

destructor TBasicAction.Destroy;
begin
  inherited Destroy;
  while FClients.Count > 0 do
    UnRegisterChanges(TBasicActionLink(FClients.Last));
  FClients.Free;
end;

{!function TBasicAction.GetActionLinkClass: TBasicActionLinkClass;
begin
  Result := TBasicActionLink;
end;!}

function TBasicAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := False;
end;

procedure TBasicAction.ExecuteTarget(Target: TObject);
begin
end;

procedure TBasicAction.UpdateTarget(Target: TObject);
begin
end;

function TBasicAction.Execute: Boolean;
begin
  if Assigned(FOnExecute) then
  begin
    FOnExecute(Self);
    Result := True;
  end
  else Result := False;
end;

function TBasicAction.Update: Boolean;
begin
  if Assigned(FOnUpdate) then
  begin
    FOnUpdate(Self);
    Result := True;
  end
  else Result := False;
end;

procedure TBasicAction.SetOnExecute(Value: TNotifyEvent);
var
  I: Integer;
begin
  if @Value <> @OnExecute then
  begin
    for I := 0 to FClients.Count - 1 do
      TBasicActionLink(FClients[I]).SetOnExecute(Value);
    FOnExecute := Value;
    Change;
  end;
end;

procedure TBasicAction.Change;
{var
  I: Integer;}
begin
  if Assigned(FOnChange) then FOnChange(Self);
{!  for I := 0 to FClients.Count - 1 do
    TBasicActionLink(FClients[I]).Change;!}
end;

procedure TBasicAction.RegisterChanges(Value: TBasicActionLink);
begin
  Value.FAction := Self;
  FClients.Add(Value);
end;

procedure TBasicAction.UnRegisterChanges(Value: TBasicActionLink);
var
  I: Integer;
begin
  for I := 0 to FClients.Count - 1 do
    if FClients[I] = Value then
    begin
      Value.{!}FAction := nil;
      FClients.Delete(I);
      Break;
    end;
end;

{ TStreamAdapter }

constructor TStreamAdapter.Create(Stream: TStream;
  Ownership: TStreamOwnership);
begin
  inherited Create;
  FStream := Stream;
  FOwnership := Ownership;
end;

destructor TStreamAdapter.Destroy;
begin
  if FOwnership = soOwned then
  begin
    FStream.Free;
    FStream := nil;
  end;
  inherited Destroy;
end;

function TStreamAdapter.Read(pv: Pointer; cb: Longint; pcbRead: PLongint): HResult;
var
  NumRead: Longint;
begin
  try
    if pv = Nil then
    begin
      Result := STG_E_INVALIDPOINTER;
      Exit;
    end;
    NumRead := FStream.Read(pv^, cb);
    if pcbRead <> Nil then pcbRead^ := NumRead;
    Result := S_OK;
  except
    Result := S_FALSE;
  end;
end;

function TStreamAdapter.Write(pv: Pointer; cb: Longint; pcbWritten: PLongint): HResult;
var
  NumWritten: Longint;
begin
  try
    if pv = Nil then
    begin
      Result := STG_E_INVALIDPOINTER;
      Exit;
    end;
    NumWritten := FStream.Write(pv^, cb);
    if pcbWritten <> Nil then pcbWritten^ := NumWritten;
    Result := S_OK;
  except
    Result := STG_E_CANTSAVE;
  end;
end;

function TStreamAdapter.Seek(dlibMove: Largeint; dwOrigin: Longint;
  out libNewPosition: Largeint): HResult;
var
  NewPos: Integer;
begin
  try
    if (dwOrigin < STREAM_SEEK_SET) or (dwOrigin > STREAM_SEEK_END) then
    begin
      Result := STG_E_INVALIDFUNCTION;
      Exit;
    end;
    NewPos := FStream.Seek(LongInt(dlibMove), dwOrigin);
    if @libNewPosition <> nil then libNewPosition := NewPos;
    Result := S_OK;
  except
    Result := STG_E_INVALIDPOINTER;
  end;
end;

function TStreamAdapter.SetSize(libNewSize: Largeint): HResult;
begin
  try
    FStream.Size := LongInt(libNewSize);
    if libNewSize <> FStream.Size then
      Result := E_FAIL
    else
      Result := S_OK;
  except
    Result := E_UNEXPECTED;
  end;
end;

function TStreamAdapter.CopyTo(stm: IStream; cb: Largeint; out cbRead: Largeint;
  out cbWritten: Largeint): HResult;
const
  MaxBufSize = 1024 * 1024;  // 1mb
var
  Buffer: Pointer;
  BufSize, N, I: Integer;
  BytesRead, BytesWritten, W: LargeInt;
begin
  Result := S_OK;
  BytesRead := 0;
  BytesWritten := 0;
  try
    if cb > MaxBufSize then
      BufSize := MaxBufSize
    else
      BufSize := Integer(cb);
    GetMem(Buffer, BufSize);
    try
      while cb > 0 do
      begin
        if cb > MaxInt then
          I := MaxInt
        else
          I := cb;
        while I > 0 do
        begin
          if I > BufSize then N := BufSize else N := I;
          Inc(BytesRead, FStream.Read(Buffer^, N));
          W := 0;
          Result := stm.Write(Buffer, N, @W);
          Inc(BytesWritten, W);
          if (Result = S_OK) and (Integer(W) <> N) then Result := E_FAIL;
          if Result <> S_OK then Exit;
          Dec(I, N);
        end;
        Dec(cb, I);
      end;
    finally
      FreeMem(Buffer);
      if (@cbWritten <> nil) then cbWritten := BytesWritten;
      if (@cbRead <> nil) then cbRead := BytesRead;
    end;
  except
    Result := E_UNEXPECTED;
  end;
end;

function TStreamAdapter.Commit(grfCommitFlags: Longint): HResult;
begin
  Result := S_OK;
end;

function TStreamAdapter.Revert: HResult;
begin
  Result := STG_E_REVERTED;
end;

function TStreamAdapter.LockRegion(libOffset: Largeint; cb: Largeint;
  dwLockType: Longint): HResult;
begin
  Result := STG_E_INVALIDFUNCTION;
end;

function TStreamAdapter.UnlockRegion(libOffset: Largeint; cb: Largeint;
  dwLockType: Longint): HResult;
begin
  Result := STG_E_INVALIDFUNCTION;
end;

function TStreamAdapter.Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult;
begin
  Result := S_OK;
  try
    if (@statstg <> nil) then
      with statstg do
      begin
        dwType := STGTY_STREAM;
        cbSize := FStream.Size;
        mTime.dwLowDateTime := 0;
        mTime.dwHighDateTime := 0;
        cTime.dwLowDateTime := 0;
        cTime.dwHighDateTime := 0;
        aTime.dwLowDateTime := 0;
        aTime.dwHighDateTime := 0;
        grfLocksSupported := LOCK_WRITE;
      end;
  except
    Result := E_UNEXPECTED;
  end;
end;

function TStreamAdapter.Clone(out stm: IStream): HResult;
begin
  Result := E_NOTIMPL;
end;


procedure FreeIntConstList;
var
  I: Integer;
begin
  with IntConstList.LockList do
  try
    for I := 0 to Count - 1 do
      TIntConst(Items[I]).Free;
  finally
    IntConstList.UnlockList;
  end;
  IntConstList.Free;
end;

procedure ModuleUnload(Instance: Longint);
begin
  UnregisterModuleClasses(HMODULE(Instance));
end;

initialization
  InitializeCriticalSection(ThreadLock);
  AddModuleUnloadProc(ModuleUnload);
  GlobalNameSpace := TMultiReadExclusiveWriteSynchronizer.Create;
  ClassList := TThreadList.Create;
  ClassAliasList := TStringList.Create;
  IntConstList := TThreadList.Create;
  GlobalFixupList := TThreadList.Create;

finalization
  UnRegisterModuleClasses(HInstance);
  GlobalNameSpace.BeginWrite;
  FreeIntConstList;
  ClassList.Free;
  ClassAliasList.Free;
  RemoveFixupReferences(nil, '');
  GlobalFixupList.Free;
  GlobalFixupList := nil;
  GlobalLists.Free;
  FreeThreadWindow;
  GlobalNameSpace.Free;
  GlobalNameSpace := nil;
  RemoveModuleUnloadProc(ModuleUnload);
  DeleteCriticalSection(ThreadLock);
end.
