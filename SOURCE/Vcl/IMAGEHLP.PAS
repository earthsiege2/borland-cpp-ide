
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{							}
{	Prototypes and constants required for the       }
{       Win32 image help routines.                      }
{							}
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Borland Software Corporation        }
{                                                       }
{*******************************************************}

unit ImageHlp;

interface

{$HPPEMIT '#include <imagehlp.h>'}

uses Windows;

{$Z4}

{ Define checksum return codes. }
const
  {$EXTERNALSYM CHECKSUM_SUCCESS}
  CHECKSUM_SUCCESS                = 0;
  {$EXTERNALSYM CHECKSUM_OPEN_FAILURE}
  CHECKSUM_OPEN_FAILURE           = 1;
  {$EXTERNALSYM CHECKSUM_MAP_FAILURE}
  CHECKSUM_MAP_FAILURE            = 2;
  {$EXTERNALSYM CHECKSUM_MAPVIEW_FAILURE}
  CHECKSUM_MAPVIEW_FAILURE        = 3;
  {$EXTERNALSYM CHECKSUM_UNICODE_FAILURE}
  CHECKSUM_UNICODE_FAILURE        = 4;

{ Define Splitsym flags. }

  {$EXTERNALSYM SPLITSYM_REMOVE_PRIVATE}
  SPLITSYM_REMOVE_PRIVATE         = $00000001;      { Remove CV types/symbols and Fixup debug }
{  Used for creating .dbg files that ship }
{  as part of the product. }

  {$EXTERNALSYM SPLITSYM_EXTRACT_ALL}
  SPLITSYM_EXTRACT_ALL            = $00000002;      { Extract all debug info from image. }
{  Normally, FPO is left in the image }
{  to allow stack traces through the code. }
{  Using this switch is similar to linking }
{  with -debug:none except the .dbg file }
{  exists... }

{ Define checksum function prototypes. }
{$EXTERNALSYM CheckSumMappedFile}
function CheckSumMappedFile(BaseAddress: Pointer; FileLength: DWORD;
  HeaderSum: PDWORD; CheckSum: PDWORD): PImageNtHeaders; stdcall;

{$EXTERNALSYM MapFileAndCheckSum}
function MapFileAndCheckSum(Filename: PChar; var HeaderSum,
  CheckSum: DWORD): DWORD; stdcall;
{$EXTERNALSYM MapFileAndCheckSumA}
function MapFileAndCheckSumA(Filename: PAnsiChar; var HeaderSum,
  CheckSum: DWORD): DWORD; stdcall;
{$EXTERNALSYM MapFileAndCheckSumW}
function MapFileAndCheckSumW(Filename: PWideChar; var HeaderSum,
  CheckSum: DWORD): DWORD; stdcall;


{$EXTERNALSYM TouchFileTimes}
function TouchFileTimes(FileHandle: THandle; const lpSystemTime: TSystemTime):
  Bool; stdcall;

{$EXTERNALSYM SplitSymbols}
function SplitSymbols(ImageName, SymbolsPath, SymbolFilePath: LPSTR;
  Flags: DWORD): Bool; stdcall;

{$EXTERNALSYM FindDebugInfoFile}
function FindDebugInfoFile(FileName, SymbolPath, DebugFilePath: LPSTR): THandle; stdcall;

{$EXTERNALSYM FindExecutableImage}
function FindExecutableImage(FileName, SymbolPath, ImageFilePath: LPSTR): THandle; stdcall;

{$EXTERNALSYM UpdateDebugInfoFile}
function UpdateDebugInfoFile(ImageFileName, SymbolPath, DebugFilePath: LPSTR;
  NtHeaders: PImageNtHeaders): Bool; stdcall;

{$EXTERNALSYM UpdateDebugInfoFileEx}
function UpdateDebugInfoFileEx(ImageFileName, SymbolPath, DebugFilePath: LPSTR;
  NtHeaders: PImageNtHeaders; OldChecksum: DWORD): Bool; stdcall;

{$EXTERNALSYM BindImage}
function BindImage(ImageName, DllPath, SymbolPath: LPSTR): Bool; stdcall;

type
  {$EXTERNALSYM _IMAGEHLP_STATUS_REASON}
  _IMAGEHLP_STATUS_REASON = (
    BindOutOfMemory,
    BindRvaToVaFailed,
    BindNoRoomInImage,
    BindImportModuleFailed,
    BindImportProcedureFailed,
    BindImportModule,
    BindImportProcedure,
    BindForwarder,
    BindForwarderNOT,
    BindImageModified,
    BindExpandFileHeaders,
    BindImageComplete,
    BindMismatchedSymbols,
    BindSymbolsNotUpdated
  );
  {$EXTERNALSYM IMAGEHLP_STATUS_REASON}
  IMAGEHLP_STATUS_REASON = _IMAGEHLP_STATUS_REASON;
  TImagehlpStatusReason = _IMAGEHLP_STATUS_REASON;

type
  {$EXTERNALSYM PIMAGEHLP_STATUS_ROUTINE}
  PIMAGEHLP_STATUS_ROUTINE = function(Reason: TImagehlpStatusReason;
    ImageName, DllName: LPSTR; Va, Parameter: ULONG): Bool; stdcall;
  TImagehlpStatusRoutine = PIMAGEHLP_STATUS_ROUTINE;

{$EXTERNALSYM BindImageEx}
function BindImageEx(Flags: DWORD; ImageName, DllPath, SymbolPath: LPSTR;
  var StatusRoutine: TImagehlpStatusReason): Bool; stdcall;

const
  {$EXTERNALSYM BIND_NO_BOUND_IMPORTS}
  BIND_NO_BOUND_IMPORTS     = $00000001;
  {$EXTERNALSYM BIND_NO_UPDATE}
  BIND_NO_UPDATE            = $00000002;
  {$EXTERNALSYM BIND_ALL_IMAGES}
  BIND_ALL_IMAGES           = $00000004;

{$EXTERNALSYM ReBaseImage}
function ReBaseImage(CurrentImageName, SymbolPath: LPSTR; fReBase,
  fRebaseSysfileOk, fGoingDown: Bool; CheckImageSize: ULONG;
  var OldImageSize, OldImageBase, NewImageSize, NewImageBase: ULONG;
  TimeStamp: ULONG): Bool; stdcall;

const
  {$EXTERNALSYM IMAGE_SEPARATION}
  IMAGE_SEPARATION     = 64 * 1024;

type
  PloadedImage = ^TLoadedImage;
  {$EXTERNALSYM _LOADED_IMAGE}
  _LOADED_IMAGE = record
    ModuleName: LPSTR;
    hFile: THandle;
    MappedAddress: PChar;
    FileHeader: PImageNtHeaders;
    LastRvaSection: PImageSectionHeader;
    NumberOfSections: ULONG;
    Sections: PImageSectionHeader;
    Characteristics: ULONG;
    fSystemImage: ByteBool;
    fDOSImage: ByteBool;
    Links: TListEntry;
    SizeOfImage: ULONG;
  end;
  {$EXTERNALSYM LOADED_IMAGE}
  LOADED_IMAGE = _LOADED_IMAGE;
  LoadedImage = _LOADED_IMAGE;
  TLoadedImage = _Loaded_IMAGE;


{$EXTERNALSYM ImageLoad}
function ImageLoad(DllName, DllPath: LPSTR): PLoadedImage; stdcall;

{$EXTERNALSYM ImageUnload}
function ImageUnload(LoadedImage: PLoadedImage): Bool; stdcall;

{$EXTERNALSYM ImageNtHeader}
function ImageNtHeader(Base: Pointer): PImageNtHeaders; stdcall;

{$EXTERNALSYM ImageDirectoryEntryToData}
function ImageDirectoryEntryToData(Base: Pointer; MappedAsImage: ByteBool;
  DirectoryEntry: Word; var Size: ULONG): Pointer; stdcall;

{$EXTERNALSYM ImageRvaToSection}
function ImageRvaToSection(NtHeaders: PImageNtHeaders; Base: Pointer;
  Rva: ULONG): PImageSectionHeader; stdcall;

{$EXTERNALSYM ImageRvaToVa}
function ImageRvaToVa(NtHeaders: PImageNtHeaders; Base: Pointer;
  Rva: ULONG; var LastRvaSection: PImageSectionHeader): Pointer; stdcall;

{$EXTERNALSYM MapAndLoad}
function MapAndLoad(ImageName, DllPath: LPSTR; LoadedImage: PLoadedImage;
  DotDll, ReadOnly: Bool): Bool; stdcall;

{$EXTERNALSYM GetImageConfigInformation}
function GetImageConfigInformation(LoadedImage: PLoadedImage;
  var ImageConfigInformation: TImageLoadConfigDirectory): Bool; stdcall;

{$EXTERNALSYM GetImageUnusedHeaderBytes}
function GetImageUnusedHeaderBytes(LoadedImage: PLoadedImage;
  var SizeUnusedHeaderBytes: DWORD): DWORD; stdcall;

{$EXTERNALSYM SetImageConfigInformation}
function SetImageConfigInformation(LoadedImage: PLoadedImage;
  const ImageConfigInformation: TImageLoadConfigDirectory): Bool; stdcall;

{$EXTERNALSYM UnMapAndLoad}
function UnMapAndLoad(LoadedImage: PLoadedImage): Bool; stdcall;

type
  PimageDebugInformation = ^TImageDebugInformation;
  {$EXTERNALSYM _IMAGE_DEBUG_INFORMATION}
  _IMAGE_DEBUG_INFORMATION = packed record
    List: TListEntry;
    Size: DWORD;
    MappedBase: Pointer;
    Machine: Word;
    Characteristics: Word;
    CheckSum: DWORD;
    ImageBase: DWORD;
    SizeOfImage: DWORD;
    NumberOfSections: DWORD;
    Sections: PImageSectionHeader;
    ExportedNamesSize: DWORD;
    ExportedNames: LPSTR;
    NumberOfFunctionTableEntries: DWORD;
    FunctionTableEntries: PImageFunctionEntry;
    LowestFunctionStartingAddress: DWORD;
    HighestFunctionEndingAddress: DWORD;
    NumberOfFpoTableEntries: DWORD;
    FpoTableEntries: PFpoData;
    SizeOfCoffSymbols: DWORD;
    CoffSymbols: PImageCOFFSymbolsHeader;
    SizeOfCodeViewSymbols: DWORD;
    CodeViewSymbols: Pointer;
    ImageFilePath: LPSTR;
    ImageFileName: LPSTR;
    DebugFilePath: LPSTR;
    TimeDateStamp: DWORD;
    RomImage: Bool;
    DebugDirectory: PImageDebugDirectory;
    NumberOfDebugDirectories: DWORD;
    Reserved: packed array[0..2] of DWORD;
  end;
  {$EXTERNALSYM IMAGE_DEBUG_INFORMATION}
  IMAGE_DEBUG_INFORMATION = _IMAGE_DEBUG_INFORMATION;
  TImageDebugInformation = _IMAGE_DEBUG_INFORMATION;

{$EXTERNALSYM MapDebugInformation}
function MapDebugInformation(FileHandle: THandle; FileName, SymbolPath: LPSTR;
  ImageBase: DWORD): PImageDebugInformation; stdcall;

{$EXTERNALSYM UnmapDebugInformation}
function UnmapDebugInformation(DebugInfo: PImageDebugInformation): Bool; stdcall;

{$EXTERNALSYM SearchTreeForFile}
function SearchTreeForFile(RootPath, InputPathName, OutputPathBuffer: LPSTR):
  Bool; stdcall;

{$EXTERNALSYM MakeSureDirectoryPathExists}
function MakeSureDirectoryPathExists(DirPath: LPCSTR): Bool; stdcall;

{ UnDecorateSymbolName Flags }
const
  {$EXTERNALSYM UNDNAME_COMPLETE}
  UNDNAME_COMPLETE                     = $0000;    { Enable full undecoration }
  {$EXTERNALSYM UNDNAME_NO_LEADING_UNDERSCORES}
  UNDNAME_NO_LEADING_UNDERSCORES       = $0001;    { Remove leading underscores from MS extended keywords }
  {$EXTERNALSYM UNDNAME_NO_MS_KEYWORDS}
  UNDNAME_NO_MS_KEYWORDS               = $0002;    { Disable expansion of MS extended keywords }
  {$EXTERNALSYM UNDNAME_NO_FUNCTION_RETURNS}
  UNDNAME_NO_FUNCTION_RETURNS          = $0004;    { Disable expansion of return type for primary declaration }
  {$EXTERNALSYM UNDNAME_NO_ALLOCATION_MODEL}
  UNDNAME_NO_ALLOCATION_MODEL          = $0008;    { Disable expansion of the declaration model }
  {$EXTERNALSYM UNDNAME_NO_ALLOCATION_LANGUAGE}
  UNDNAME_NO_ALLOCATION_LANGUAGE       = $0010;    { Disable expansion of the declaration language specifier }
  {$EXTERNALSYM UNDNAME_NO_MS_THISTYPE}
  UNDNAME_NO_MS_THISTYPE               = $0020;    { NYI Disable expansion of MS keywords on the 'this' type for primary declaration }
  {$EXTERNALSYM UNDNAME_NO_CV_THISTYPE}
  UNDNAME_NO_CV_THISTYPE               = $0040;    { NYI Disable expansion of CV modifiers on the 'this' type for primary declaration }
  {$EXTERNALSYM UNDNAME_NO_THISTYPE}
  UNDNAME_NO_THISTYPE                  = $0060;    { Disable all modifiers on the 'this' type }
  {$EXTERNALSYM UNDNAME_NO_ACCESS_SPECIFIERS}
  UNDNAME_NO_ACCESS_SPECIFIERS         = $0080;    { Disable expansion of access specifiers for members }
  {$EXTERNALSYM UNDNAME_NO_THROW_SIGNATURES}
  UNDNAME_NO_THROW_SIGNATURES          = $0100;    { Disable expansion of 'throw-signatures' for functions and pointers to functions }
  {$EXTERNALSYM UNDNAME_NO_MEMBER_TYPE}
  UNDNAME_NO_MEMBER_TYPE               = $0200;    { Disable expansion of 'static' or 'virtual'ness of members }
  {$EXTERNALSYM UNDNAME_NO_RETURN_UDT_MODEL}
  UNDNAME_NO_RETURN_UDT_MODEL          = $0400;    { Disable expansion of MS model for UDT returns }
  {$EXTERNALSYM UNDNAME_32_BIT_DECODE}
  UNDNAME_32_BIT_DECODE                = $0800;    { Undecorate 32-bit decorated names }
  {$EXTERNALSYM UNDNAME_NAME_ONLY}
  UNDNAME_NAME_ONLY                    = $1000;    { Crack only the name for primary declaration; }
{  return just [scope::]name.  Does expand template params }
  {$EXTERNALSYM UNDNAME_NO_ARGUMENTS}
  UNDNAME_NO_ARGUMENTS                 = $2000;    { Don't undecorate arguments to function }
  {$EXTERNALSYM UNDNAME_NO_SPECIAL_SYMS}
  UNDNAME_NO_SPECIAL_SYMS              = $4000;    { Don't undecorate special names (v-table, vcall, vector xxx, metatype, etc) }

{$EXTERNALSYM UnDecorateSymbolName}
function UnDecorateSymbolName(DecoratedName, UnDecoratedName: LPSTR;
  UndecoratedLength, Flags: DWORD): DWORD; stdcall;


{ StackWalking API }
type
  {$EXTERNALSYM ADDRESS_MODE}
  ADDRESS_MODE = (
    AddrMode1616,
    AddrMode1632,
    AddrModeReal,
    AddrModeFlat
  );
  TAddressMode = ADDRESS_MODE;

  PAddress = ^TAddress;
  {$EXTERNALSYM _tagADDRESS}
  _tagADDRESS = record
    Offset: DWORD;
    Segment: Word;
    Mode: TAddressMode;
  end;
  {$EXTERNALSYM ADDRESS}
  ADDRESS = _tagADDRESS;
  TAddress = _tagADDRESS;

{ This structure is included in the STACKFRAME structure, }
{ and is used to trace through usermode callbacks in a thread's }
{ kernel stack.  The values must be copied by the kernel debugger }
{ from the DBGKD_GET_VERSION and WAIT_STATE_CHANGE packets. }

  PKdHelp = ^TKdHelp;
  {$EXTERNALSYM _KDHELP}
  _KDHELP = packed record { address of kernel thread object, as provided }
                          { in the WAIT_STATE_CHANGE packet. }
    Thread: DWORD;
    { offset in thread object to pointer to the current callback frame }
    { in kernel stack. }
    ThCallbackStack: DWORD;
    { offsets to values in frame: }
    { address of next callback frame }
    NextCallback: DWORD;
    { address of saved frame pointer (if applicable) }
    FramePointer: DWORD;
    { Address of the kernel function that calls out to user mode }
    KiCallUserMode: DWORD;
    { Address of the user mode dispatcher function }
    KeUserCallbackDispatcher: DWORD;
  end;
  {$EXTERNALSYM KDHELP}
  KDHELP = _KDHELP;
  TKdHelp = _KDHELP;

  PStackFrame = ^TStackFrame;
  {$EXTERNALSYM _tagSTACKFRAME}
  _tagSTACKFRAME = packed record
    AddrPC: TAddress;                  { program counter }
    AddrReturn: TAddress;              { return address }
    AddrFrame: TAddress;               { frame pointer }
    AddrStack: TAddress;               { stack pointer }
    FuncTableEntry: Pointer;          { pointer to pdata/fpo or NULL }
    Params: packed array[0..3] of DWORD;{ possible arguments to the function }
    _Far: Bool;                        { WOW far call }
    _Virtual: Bool;                    { is this a virtual frame? }
    Reserved: packed array[0..2] of DWORD;{ used internally by StackWalk api }
    KdHelp: TKdHelp;
  end;
  {$EXTERNALSYM STACKFRAME}
  STACKFRAME = _tagSTACKFRAME;
  TStackFrame = _tagSTACKFRAME;

type
  {$EXTERNALSYM PREAD_PROCESS_MEMORY_ROUTINE}
  PREAD_PROCESS_MEMORY_ROUTINE = function(hProcess: THandle;
    lpBaseAddress, lpBuffer: Pointer; nSize: DWORD;
    var lpNumberOfBytesRead: DWORD): Bool; stdcall;
  TReadProcessMemoryRoutine = PREAD_PROCESS_MEMORY_ROUTINE;

  {$EXTERNALSYM PFUNCTION_TABLE_ACCESS_ROUTINE}
  PFUNCTION_TABLE_ACCESS_ROUTINE = function(hProcess: THandle;
    AddrBase: DWORD): Pointer; stdcall;
  TFunctionTableAccessRoutine = PFUNCTION_TABLE_ACCESS_ROUTINE;

  {$EXTERNALSYM PGET_MODULE_BASE_ROUTINE}
  PGET_MODULE_BASE_ROUTINE = function(hProcess: THandle;
    ReturnAddress: DWORD): DWORD; stdcall;
  TGetModuleBaseRoutine = PGET_MODULE_BASE_ROUTINE;

  {$EXTERNALSYM PTRANSLATE_ADDRESS_ROUTINE}
  PTRANSLATE_ADDRESS_ROUTINE = function(hProcess, hThread: THandle;
    lpaddr: PAddress): DWORD; stdcall;
  TTranslateAddressRoutine = PTRANSLATE_ADDRESS_ROUTINE;

{$EXTERNALSYM StackWalk}
function StackWalk(MachineType: DWORD; hProcess, hThread: THandle;
  StackFrame: PStackFrame; ContextRecord: Pointer;
  ReadMemoryRoutine: TReadProcessMemoryRoutine;
  FunctionTableAccessRoutine: TFunctionTableAccessRoutine;
  GetModuleBaseRoutine: TGetModuleBaseRoutine;
  TranslateAddress: TTranslateAddressRoutine): Bool; stdcall;

const
  {$EXTERNALSYM API_VERSION_NUMBER}
  API_VERSION_NUMBER     = 5;

type
  PApiVersion = ^TApiVersion;
  {$EXTERNALSYM API_VERSION}
  API_VERSION = packed record
    MajorVersion: Word;
    MinorVersion: Word;
    Revision: Word;
    Reserved: Word;
  end;
  TApiVersion = API_VERSION;

{$EXTERNALSYM ImagehlpApiVersion}
function ImagehlpApiVersion: PApiVersion; stdcall;

{$EXTERNALSYM ImagehlpApiVersionEx}
function ImagehlpApiVersionEx(var AppVersion: TApiVersion): PApiVersion; stdcall;

{$EXTERNALSYM GetTimestampForLoadedLibrary}
function GetTimestampForLoadedLibrary(Module: HMODULE): DWORD; stdcall;

{$EXTERNALSYM RemovePrivateCvSymbolic}
function RemovePrivateCvSymbolic(DebugData: PChar; var NewDebugData: PChar;
  var NewDebugSize: ULONG): Bool; stdcall;

{$EXTERNALSYM RemoveRelocations}
procedure RemoveRelocations(ImageName: PChar); stdcall;


{ typedefs for function pointers }
type
  {$EXTERNALSYM PSYM_ENUMMODULES_CALLBACK}
  PSYM_ENUMMODULES_CALLBACK = function(ModuleName: LPSTR; BaseOfDll: ULONG;
    UserContext: Pointer): Bool; stdcall;
  TSymEnummodulesCallback = PSYM_ENUMMODULES_CALLBACK;

  {$EXTERNALSYM PSYM_ENUMSYMBOLS_CALLBACK}
  PSYM_ENUMSYMBOLS_CALLBACK = function(SymbolName: LPSTR; SymbolAddress,
    SymbolSize: ULONG; UserContext: Pointer): Bool; stdcall;
  TSymEnumsymbolsCallback = PSYM_ENUMSYMBOLS_CALLBACK;

  {$EXTERNALSYM PENUMLOADED_MODULES_CALLBACK}
  PENUMLOADED_MODULES_CALLBACK = function(ModuleName: LPSTR; ModuleBase,
    ModuleSize: ULONG; UserContext: Pointer): Bool; stdcall;
  TEnumloadedModulesCallback = PENUMLOADED_MODULES_CALLBACK;

  {$EXTERNALSYM PSYMBOL_REGISTERED_CALLBACK}
  PSYMBOL_REGISTERED_CALLBACK = function(hProcess: THandle; ActionCode: ULONG;
    CallbackData, UserContext: Pointer): Bool; stdcall;
  TSymbolRegisteredCallback = PSYMBOL_REGISTERED_CALLBACK;


{ symbol flags }
const
  {$EXTERNALSYM SYMF_OMAP_GENERATED}
  SYMF_OMAP_GENERATED       = $00000001;
  {$EXTERNALSYM SYMF_OMAP_MODIFIED}
  SYMF_OMAP_MODIFIED        = $00000002;


{ symbol type enumeration }
type
  {$EXTERNALSYM SYM_TYPE}
  SYM_TYPE = (
    SymNone,
    SymCoff,
    SymCv,
    SymPdb,
    SymExport,
    SymDeferred,
    SymSym                  { .sym file }
  );
  TSymType = SYM_TYPE;

{ symbol data structure }
  PImagehlpSymbol = ^TImagehlpSymbol;
  {$EXTERNALSYM _IMAGEHLP_SYMBOL}
  _IMAGEHLP_SYMBOL = packed record
    SizeOfStruct: DWORD;                                { set to sizeof(IMAGEHLP_SYMBOL) }
    Address: DWORD;                                     { virtual address including dll base address }
    Size: DWORD;                                        { estimated size of symbol, can be zero }
    Flags: DWORD;                                       { info about the symbols, see the SYMF defines }
    MaxNameLength: DWORD;                               { maximum size of symbol name in 'Name' }
    Name: packed array[0..0] of Char;                   { symbol name (null terminated string) }
  end;
  {$EXTERNALSYM IMAGEHLP_SYMBOL}
  IMAGEHLP_SYMBOL = _IMAGEHLP_SYMBOL;
  TImagehlpSymbol = _IMAGEHLP_SYMBOL;


{ module data structure }
  PImagehlpModule = ^TImagehlpModule;
  {$EXTERNALSYM _IMAGEHLP_MODULE}
  _IMAGEHLP_MODULE = record
    SizeOfStruct: DWORD;                                { set to sizeof(IMAGEHLP_MODULE) }
    BaseOfImage: DWORD;                                 { base load address of module }
    ImageSize: DWORD;                                   { virtual size of the loaded module }
    TimeDateStamp: DWORD;                               { date/time stamp from pe header }
    CheckSum: DWORD;                                    { checksum from the pe header }
    NumSyms: DWORD;                                     { number of symbols in the symbol table }
    SymType: TSymType;                                  { type of symbols loaded }
    ModuleName: packed array[0..31] of Char;            { module name }
    ImageName: packed array[0..255] of Char;            { image name }
    LoadedImageName: packed array[0..255] of Char;      { symbol file name }
  end;
  {$EXTERNALSYM IMAGEHLP_MODULE}
  IMAGEHLP_MODULE = _IMAGEHLP_MODULE;
  TImagehlpModule = _IMAGEHLP_MODULE;


{ data structures used for registered symbol callbacks }
const
  {$EXTERNALSYM CBA_DEFERRED_SYMBOL_LOAD_START}
  CBA_DEFERRED_SYMBOL_LOAD_START              = $00000001;
  {$EXTERNALSYM CBA_DEFERRED_SYMBOL_LOAD_COMPLETE}
  CBA_DEFERRED_SYMBOL_LOAD_COMPLETE           = $00000002;
  {$EXTERNALSYM CBA_DEFERRED_SYMBOL_LOAD_FAILURE}
  CBA_DEFERRED_SYMBOL_LOAD_FAILURE            = $00000003;
  {$EXTERNALSYM CBA_SYMBOLS_UNLOADED}
  CBA_SYMBOLS_UNLOADED                        = $00000004;
  {$EXTERNALSYM CBA_DUPLICATE_SYMBOL}
  CBA_DUPLICATE_SYMBOL                        = $00000005;

type
  PImagehlpDeferredSymbolLoad = ^TImagehlpDeferredSymbolLoad;
  {$EXTERNALSYM _IMAGEHLP_DEFERRED_SYMBOL_LOAD}
  _IMAGEHLP_DEFERRED_SYMBOL_LOAD = packed record
    SizeOfStruct: DWORD;                                { set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD) }
    BaseOfImage: DWORD;                                 { base load address of module }
    CheckSum: DWORD;                                    { checksum from the pe header }
    TimeDateStamp: DWORD;                               { date/time stamp from pe header }
    FileName: packed array[0..MAX_PATH-1] of Char;      { symbols file or image name }
  end;
  {$EXTERNALSYM IMAGEHLP_DEFERRED_SYMBOL_LOAD}
  IMAGEHLP_DEFERRED_SYMBOL_LOAD = _IMAGEHLP_DEFERRED_SYMBOL_LOAD;
  TImagehlpDeferredSymbolLoad = _IMAGEHLP_DEFERRED_SYMBOL_LOAD;

  PImagehlpDuplicateSymbol = ^TImagehlpDuplicateSymbol;
  {$EXTERNALSYM _IMAGEHLP_DUPLICATE_SYMBOL}
  _IMAGEHLP_DUPLICATE_SYMBOL = packed record
    SizeOfStruct: DWORD;                                { set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL) }
    NumberOfDups: DWORD;                                { number of duplicates in the Symbol array }
    Symbol: PImagehlpSymbol;                            { array of duplicate symbols }
    SelectedSymbol: ULONG;                           { symbol selected (-1 to start) }
  end;
  {$EXTERNALSYM IMAGEHLP_DUPLICATE_SYMBOL}
  IMAGEHLP_DUPLICATE_SYMBOL = _IMAGEHLP_DUPLICATE_SYMBOL;
  TImagehlpDuplicateSymbol = _IMAGEHLP_DUPLICATE_SYMBOL;



{ options that are set/returned by SymSetOptions() & SymGetOptions() }
{ these are used as a mask }

const
  {$EXTERNALSYM SYMOPT_CASE_INSENSITIVE}
  SYMOPT_CASE_INSENSITIVE      = $00000001;
  {$EXTERNALSYM SYMOPT_UNDNAME}
  SYMOPT_UNDNAME               = $00000002;
  {$EXTERNALSYM SYMOPT_DEFERRED_LOADS}
  SYMOPT_DEFERRED_LOADS        = $00000004;
  {$EXTERNALSYM SYMOPT_NO_CPP}
  SYMOPT_NO_CPP                = $00000008;


{$EXTERNALSYM SymSetOptions}
function SymSetOptions(SymOptions: DWORD): DWORD; stdcall;

{$EXTERNALSYM SymGetOptions}
function SymGetOptions: DWORD; stdcall;

{$EXTERNALSYM SymCleanup}
function SymCleanup(hProcess: THandle): Bool; stdcall;

{$EXTERNALSYM SymEnumerateModules}
function SymEnumerateModules(hProcess: THandle;
  EnumModulesCallback: TSymEnumModulesCallback; UserContext: Pointer): Bool; stdcall;

{$EXTERNALSYM SymEnumerateSymbols}
function SymEnumerateSymbols(hProcess: THandle; BaseOfDll: DWORD;
  EnumSymbolsCallback: TSymEnumSymbolsCallback; UserContext: Pointer): Bool; stdcall;

{$EXTERNALSYM EnumerateLoadedModules}
function EnumerateLoadedModules(hProcess: THandle;
  EnumLoadedModulesCallback: TEnumLoadedModulesCallback;
  UserContext: Pointer): Bool; stdcall;

{$EXTERNALSYM SymFunctionTableAccess}
function SymFunctionTableAccess(hProcess: THandle; AddrBase: DWORD): Pointer; stdcall;

{$EXTERNALSYM SymGetModuleInfo}
function SymGetModuleInfo(hProcess: THandle; dwAddr: DWORD;
  var ModuleInfo: TImagehlpModule): Bool; stdcall;

{$EXTERNALSYM SymGetModuleBase}
function SymGetModuleBase(hProcess: THandle; dwAddr: DWORD): DWORD; stdcall;

{$EXTERNALSYM SymGetSymFromAddr}
function SymGetSymFromAddr(hProcess: THandle; dwAddr: DWORD;
  pdwDisplacement: PDWORD; var Symbol: TImagehlpSymbol): Bool; stdcall;

{$EXTERNALSYM SymGetSymFromName}
function SymGetSymFromName(hProcess: THandle; Name: LPSTR;
  var Symbol: TImagehlpSymbol): Bool; stdcall;

{$EXTERNALSYM SymGetSymNext}
function SymGetSymNext(hProcess: THandle; var Symbol: TImagehlpSymbol): Bool; stdcall;

{$EXTERNALSYM SymGetSymPrev}
function SymGetSymPrev(hProcess: THandle; var Symbol: TImagehlpSymbol): Bool; stdcall;

{$EXTERNALSYM SymInitialize}
function SymInitialize(hProcess: THandle; UserSearchPath: LPSTR;
  fInvadeProcess: Bool): Bool; stdcall;

{$EXTERNALSYM SymGetSearchPath}
function SymGetSearchPath(hProcess: THandle; SearchPath: LPSTR;
  SearchPathLength: DWORD): Bool; stdcall;

{$EXTERNALSYM SymSetSearchPath}
function SymSetSearchPath(hProcess: THandle; SearchPath: LPSTR): Bool; stdcall;

{$EXTERNALSYM SymLoadModule}
function SymLoadModule(hProcess: THandle; hFile: THandle; ImageName,
  ModuleName: LPSTR; BaseOfDll, SizeOfDll: DWORD): Bool; stdcall;

{$EXTERNALSYM SymUnloadModule}
function SymUnloadModule(hProcess: THandle; BaseOfDll: DWORD): Bool; stdcall;

{$EXTERNALSYM SymUnDName}
function SymUnDName(sym: PImagehlpSymbol; UnDecName: LPSTR;
  UnDecNameLength: DWORD): Bool; stdcall;

{$EXTERNALSYM SymRegisterCallback}
function SymRegisterCallback(hProcess: THandle;
  CallbackFunction: TSymbolRegisteredCallback; UserContext: Pointer): Bool; stdcall;

{ Image Integrity API's }

const
  {$EXTERNALSYM CERT_PE_IMAGE_DIGEST_DEBUG_INFO}
  CERT_PE_IMAGE_DIGEST_DEBUG_INFO             = $01;
  {$EXTERNALSYM CERT_PE_IMAGE_DIGEST_RESOURCES}
  CERT_PE_IMAGE_DIGEST_RESOURCES              = $02;
  {$EXTERNALSYM CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO}
  CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO        = $04;

  {$EXTERNALSYM CERT_SECTION_TYPE_ANY}
  CERT_SECTION_TYPE_ANY                       = $FF;      { Any Certificate type }

type
  {$EXTERNALSYM DIGEST_HANDLE}
  DIGEST_HANDLE = Pointer;
  TDigestHandle = DIGEST_HANDLE;

type
  {$EXTERNALSYM DIGEST_FUNCTION}
  DIGEST_FUNCTION = function(refdata: TDigestHandle; pData: PByte;
    dwLength: DWORD): Bool; stdcall;
  TDigestFunction = DIGEST_FUNCTION;

{$EXTERNALSYM ImageGetDigestStream}
function ImageGetDigestStream(FileHandle: THandle; DigestLevel: DWORD;
  DigestFunction: TDigestFunction; DigestHandle: TDigestHandle): Bool; stdcall;

{$EXTERNALSYM ImageAddCertificate}
function ImageAddCertificate(FileHandle: THandle;
  var Certificate: PWinCertificate; var Index: DWORD): Bool; stdcall;

{$EXTERNALSYM ImageRemoveCertificate}
function ImageRemoveCertificate(FileHandle: THandle; Index: DWORD): Bool; stdcall;

{$EXTERNALSYM ImageEnumerateCertificates}
function ImageEnumerateCertificates(FileHandle: THandle; TypeFilter: Word;
  CertificateCount, Indices, IndexCount: PDWORD): Bool; stdcall;

{$EXTERNALSYM ImageGetCertificateData}
function ImageGetCertificateData(FileHandle: THandle; CertificateIndex: DWORD;
  Certificate: PWinCertificate; var RequiredLength: DWORD): Bool; stdcall;

{$EXTERNALSYM ImageGetCertificateHeader}
function ImageGetCertificateHeader(FileHandle: THandle; CertificateIndex: DWORD;
  var Certificateheader: PWinCertificate): Bool; stdcall;

implementation

const
  ImagehlpLib = 'IMAGEHLP.DLL';

function BindImage;                     external ImagehlpLib name 'BindImage';
function BindImageEx;                   external ImagehlpLib name 'BindImageEx';
function CheckSumMappedFile;            external ImagehlpLib name 'CheckSumMappedFile';
function EnumerateLoadedModules;        external ImagehlpLib name 'EnumerateLoadedModules';
function FindDebugInfoFile;             external ImagehlpLib name 'FindDebugInfoFile';
function FindExecutableImage;           external ImagehlpLib name 'FindExecutableImage';
function GetImageConfigInformation;     external ImagehlpLib name 'GetImageConfigInformation';
function GetImageUnusedHeaderBytes;     external ImagehlpLib name 'GetImageUnusedHeaderBytes';
function GetTimestampForLoadedLibrary;  external ImagehlpLib name 'GetTimestampForLoadedLibrary';
function ImageAddCertificate;           external ImagehlpLib name 'ImageAddCertificate';
function ImageDirectoryEntryToData;     external ImagehlpLib name 'ImageDirectoryEntryToData';
function ImageEnumerateCertificates;    external ImagehlpLib name 'ImageEnumerateCertificates';
function ImageGetCertificateData;       external ImagehlpLib name 'ImageGetCertificateData';
function ImageGetCertificateHeader;     external ImagehlpLib name 'ImageGetCertificateHeader';
function ImageGetDigestStream;          external ImagehlpLib name 'ImageGetDigestStream';
function ImagehlpApiVersion;            external ImagehlpLib name 'ImagehlpApiVersion';
function ImagehlpApiVersionEx;          external ImagehlpLib name 'ImagehlpApiVersionEx';
function ImageLoad;                     external ImagehlpLib name 'ImageLoad';
function ImageNtHeader;                 external ImagehlpLib name 'ImageNtHeader';
function ImageRemoveCertificate;        external ImagehlpLib name 'ImageRemoveCertificate';
function ImageRvaToSection;             external ImagehlpLib name 'ImageRvaToSection';
function ImageRvaToVa;                  external ImagehlpLib name 'ImageRvaToVa';
function ImageUnload;                   external ImagehlpLib name 'ImageUnload';
function MakeSureDirectoryPathExists;   external ImagehlpLib name 'MakeSureDirectoryPathExists';
function MapAndLoad;                    external ImagehlpLib name 'MapAndLoad';
function MapDebugInformation;           external ImagehlpLib name 'MapDebugInformation';
function MapFileAndCheckSum;           external ImagehlpLib name 'MapFileAndCheckSumA';
function MapFileAndCheckSumA;           external ImagehlpLib name 'MapFileAndCheckSumA';
function MapFileAndCheckSumW;           external ImagehlpLib name 'MapFileAndCheckSumW';
function ReBaseImage;                   external ImagehlpLib name 'ReBaseImage';
function RemovePrivateCvSymbolic;       external ImagehlpLib name 'RemovePrivateCvSymbolic';
procedure RemoveRelocations;            external ImagehlpLib name 'RemoveRelocations';
function SearchTreeForFile;             external ImagehlpLib name 'SearchTreeForFile';
function SetImageConfigInformation;     external ImagehlpLib name 'SetImageConfigInformation';
function SplitSymbols;                  external ImagehlpLib name 'SplitSymbols';
function StackWalk;                     external ImagehlpLib name 'StackWalk';
function SymCleanup;                    external ImagehlpLib name 'SymCleanup';
function SymEnumerateModules;           external ImagehlpLib name 'SymEnumerateModules';
function SymEnumerateSymbols;           external ImagehlpLib name 'SymEnumerateSymbols';
function SymFunctionTableAccess;        external ImagehlpLib name 'SymFunctionTableAccess';
function SymGetModuleBase;              external ImagehlpLib name 'SymGetModuleBase';
function SymGetModuleInfo;              external ImagehlpLib name 'SymGetModuleInfo';
function SymGetOptions;                 external ImagehlpLib name 'SymGetOptions';
function SymGetSearchPath;              external ImagehlpLib name 'SymGetSearchPath';
function SymGetSymFromAddr;             external ImagehlpLib name 'SymGetSymFromAddr';
function SymGetSymFromName;             external ImagehlpLib name 'SymGetSymFromName';
function SymGetSymNext;                 external ImagehlpLib name 'SymGetSymNext';
function SymGetSymPrev;                 external ImagehlpLib name 'SymGetSymPrev';
function SymInitialize;                 external ImagehlpLib name 'SymInitialize';
function SymLoadModule;                 external ImagehlpLib name 'SymLoadModule';
function SymRegisterCallback;           external ImagehlpLib name 'SymRegisterCallback';
function SymSetOptions;                 external ImagehlpLib name 'SymSetOptions';
function SymSetSearchPath;              external ImagehlpLib name 'SymSetSearchPath';
function SymUnDName;                    external ImagehlpLib name 'SymUnDName';
function SymUnloadModule;               external ImagehlpLib name 'SymUnloadModule';
function TouchFileTimes;                external ImagehlpLib name 'TouchFileTimes';
function UnDecorateSymbolName;          external ImagehlpLib name 'UnDecorateSymbolName';
function UnMapAndLoad;                  external ImagehlpLib name 'UnMapAndLoad';
function UnmapDebugInformation;         external ImagehlpLib name 'UnmapDebugInformation';
function UpdateDebugInfoFile;           external ImagehlpLib name 'UpdateDebugInfoFile';
function UpdateDebugInfoFileEx;         external ImagehlpLib name 'UpdateDebugInfoFileEx';

end.
