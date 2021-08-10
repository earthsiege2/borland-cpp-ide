unit vcspell3;

{ This file contains pascal declarations imported from a type library.
  This file will be written during each import or refresh of the type
  library editor.  Changes to this file will be discarded during the
  refresh process. }

{ VCI VisualSpeller Library }
{ Version 2.0 }

interface

uses Windows, ActiveX, Classes, Graphics, OleCtrls, StdVCL;

const
  LIBID_VspelocxLib: TGUID = '{97F4CED3-9103-11CE-8385-524153480001}';

const

{ Dictionary category constants }

{ DictionaryCategories }

  VSCAT_STANDARD = 256;
  VSCAT_IRLIST = 256;
  VSCAT_CUSTOM = 512;
  VSCAT_ENABLED = 1024;
  VSCAT_DISABLED = 2048;

{ Dictionary status constants }

{ DictionaryStatusBits }

  VSDSTAT_ENABLED = 1;
  VSDSTAT_LOADED = 2;
  VSDSTAT_IRLIST_ENABLED = 4;
  VSDSTAT_UPDATEABLE = 8;
  VSDSTAT_READONLY = 16;
  VSDSTAT_EXTENDED = 32;
  VSDSTAT_HYPHENATION = 64;
  VSDSTAT_PHONETICS = 128;
  VSDSTAT_COMMONLIST = 256;

{ Dictionary language code constants }

{ DictionaryLanguageCodes }

  VSLANG_AMERICAN = 0;
  VSLANG_ENGLISH = 1;
  VSLANG_FRENCH = 2;
  VSLANG_GERMAN = 3;
  VSLANG_SPANISH = 4;
  VSLANG_PORTUGUESE = 5;
  VSLANG_ITALIAN = 6;
  VSLANG_DUTCH = 7;
  VSLANG_SWEDISH = 8;
  VSLANG_FINNISH = 9;
  VSLANG_NORWEGIAN = 10;
  VSLANG_LATIN = 11;
  VSLANG_WELSH = 12;
  VSLANG_POLISH = 13;
  VSLANG_HUNGARIAN = 14;
  VSLANG_FLEMISH = 15;
  VSLANG_CZECH = 16;
  VSLANG_ICELANDIC = 17;
  VSLANG_ESPERANTO = 18;
  VSLANG_CATALAN = 19;
  VSLANG_ROMANIAN = 20;
  VSLANG_BULGARIAN = 21;
  VSLANG_RUSSIAN = 22;
  VSLANG_QUECHUA = 23;
  VSLANG_TURKISH = 24;
  VSLANG_INDONESIAN = 25;
  VSLANG_HEBREW = 26;
  VSLANG_DANISH = 27;
  VSLANG_CANADIAN = 28;

{ Event option constants }

{ EventOptionBits }

  VSEVOPT_COMPLETE = 1;
  VSEVOPT_FOUND = 2;
  VSEVOPT_MISSPELLED = 4;
  VSEVOPT_BEFORE_REPLACE = 8;
  VSEVOPT_AFTER_POPUP = 16;
  VSEVOPT_CHECK_STATUS = 32;
  VSEVOPT_CHECK_ERROR = 64;
  VSEVOPT_AFTER_REPLACE = 128;
  VSEVOPT_CLICK_IN = 256;
  VSEVOPT_CLICK_OUT = 512;
  VSEVOPT_DEFAULTS = 65533;

{ Search order constants }

{ SearchOrderCodes }

  VSORDER_SCIR = 0;
  VSORDER_CIRS = 2;
  VSORDER_IRSC = 3;
  VSORDER_SIRC = 4;
  VSORDER_CSIR = 6;
  VSORDER_IRCS = 7;
  VSORDER_NO_LOOKAHEAD = 8;

{ Spell option constants }

{ SpellOptionBits }

  VSOPT_AUTO_REPLACE = 1;
  VSOPT_AUTO_SUGGEST = 2;
  VSOPT_AUTO_POPUP = 4;
  VSOPT_IGNORE_FULL_CAPS = 8;
  VSOPT_IGNORE_PARTIAL_NUMBERS = 16;
  VSOPT_MULTILINE = 32;
  VSOPT_IGNORE_PURE_NUMBERS = 64;
  VSOPT_ALLOW_JOINED_WORDS = 128;
  VSOPT_EXACT_MATCH = 256;
  VSOPT_RETURN_EACH_WORD = 512;
  VSOPT_REPLACE_RECHECK = 1024;
  VSOPT_DEFAULTS = 1127;

{ Suggestion option constants }

{ SuggestOptionBits }

  VSSUGOPT_CAPITALIZATION = 1;
  VSSUGOPT_CHARSWAP = 2;
  VSSUGOPT_DELETES = 4;
  VSSUGOPT_DOUBLES = 8;
  VSSUGOPT_HYPHENS = 16;
  VSSUGOPT_SPLITS = 32;
  VSSUGOPT_EXCHANGES = 64;
  VSSUGOPT_INSERTIONS = 512;
  VSSUGOPT_DEFAULTS = 639;

{ Ignore/replace constants }

{ IgnoreReplaceCodes }

  VSIR_GLOBAL = 1;
  VSIR_PROMPT = 2;
  VSIR_IGNORE = 4;
  VSIR_REPLACE = 8;
  VSIR_HYPHENATION = 16;
  VSIR_SPELLED_OK = 5;
  VSIR_REPLACE_ALL = 9;
  VSIR_MISSPELLED = 6;
  VSIR_PROMPT_REPLACE = 10;

{ Event action constants }

{ EventActionCodes }

  VS_DEFAULT_HANDLING = 0;
  VS_EVENT_HANDLED = 1;
  VS_CANCEL_SPELLCHECK = 2;

{ Button click constants }

{ ButtonClickBits }

  VSCLICK_WORD_MISSPELLED_HELP = 1;
  VSCLICK_OPTIONS = 2;
  VSCLICK_PROMPT_REPLACE = 4;
  VSCLICK_ADD_TO_CUSTOM = 8;
  VSCLICK_REPLACE_ALL = 16;
  VSCLICK_REPLACE = 32;
  VSCLICK_IGNORE_ALL = 64;
  VSCLICK_IGNORE = 128;
  VSCLICK_SUGGEST_NOT_FOUND = 256;
  VSCLICK_SUGGEST_REPLACE_WITH = 512;
  VSCLICK_CANCEL_SPELLCHECK = 1024;
  VSCLICK_THESAURUS = 2048;
  VSCLICK_OPTIONS_HELP = 65536;
  VSCLICK_OPTIONS_OK = 131072;
  VSCLICK_OPTIONS_CANCEL = 262144;
  VSCLICK_OPEN_CUSTOM = 524288;
  VSCLICK_CLOSE_CUSTOM = 1048576;
  VSCLICK_OPEN_STANDARD = 2097152;
  VSCLICK_CLOSE_STANDARD = 4194304;
  VSCLICK_THESAURUS_OK = 16777216;
  VSCLICK_THESAURUS_SEARCH = 33554432;
  VSCLICK_THESAURUS_CANCEL = 67108864;
  VSCLICK_THESAURUS_HELP = 134217728;

{ Dialog element constants }

{ DialogElementBits }

  VSD_WORD_MISSPELLED_HELP = 1;
  VSD_OPTIONS = 2;
  VSD_PROMPT_REPLACE = 4;
  VSD_ADD_TO_CUSTOM = 8;
  VSD_REPLACE_ALL = 16;
  VSD_REPLACE = 32;
  VSD_IGNORE_ALL = 64;
  VSD_IGNORE = 128;
  VSD_SUGGEST_NOT_FOUND = 256;
  VSD_SUGGEST_REPLACE_WITH = 512;
  VSD_CANCEL_SPELLCHECK = 1024;
  VSD_SUGGESTIONS_LIST = 2048;
  VSD_REPLACE_BOX = 4096;
  VSD_CUSTOM_LIST = 8192;
  VSD_THESAURUS = 16384;
  VSD_OPTIONS_HELP = 65536;
  VSD_CUSTOMS = 131072;
  VSD_STANDARDS = 262144;
  VSD_PERFORMANCE = 524288;
  VSD_SUGGESTION_LIMIT = 1048576;
  VSD_AUTO_SUGGESTIONS = 2097152;
  VSD_EXACT_MATCH = 4194304;
  VSD_IGNORE_FULL_CAPS = 8388608;
  VSD_IGNORE_PARTIAL = 16777216;
  VSD_IGNORE_PURE = 33554432;
  VSD_ALLOW_JOINED = 67108864;
  VSD_RECHECK = 134217728;
  VSD_THESAURUS_HELP = 268435456;
  VSD_THESAURUS_SEARCH = 536870912;

{ ResultCode status constants }

{ ResultStatusCodes }

  VSR_WORD_MISSPELLED = -1;
  VSR_IGNORE_REPLACE = -2;
  VSR_CHECK_CANCELED = -3;
  VSR_BREAK = -4;
  VSR_FOUND = -5;
  VSR_REPLACED = -6;
  VSR_CHANGED = -7;
  VSR_END_LIST = -8;
  VSR_ENTRY_NOT_FOUND = -9;
  VSR_OPENED_READONLY = -11;
  VSR_REPLACE_OVERFLOW = -12;
  VSR_NOT_ADDED = -13;
  VSR_POPPED = -14;
  VSR_CLICK_IN = -15;
  VSR_CLICK_OUT = -16;

{ ResultCode error constants }

{ ResultErrorCodes }

  VSR_NO_ERROR = 0;
  VSR_WORD_TOO_LONG = 1;
  VSR_NO_MISSPELL = 2;
  VSR_ALREADY_OPEN = 4;
  VSR_OPEN_FAILED = 5;
  VSR_CREATE_FAILED = 6;
  VSR_INVALID_DICTIONARY = 7;
  VSR_WRITE_FAILURE = 9;
  VSR_READ_FAILURE = 10;
  VSR_BAD_FILE_NAME = 11;
  VSR_NOT_UPDATEABLE = 12;
  VSR_DUPLICATE_WORD = 13;
  VSR_BAD_CUSTOM = 14;
  VSR_IN_EVENT = 15;
  VSR_NOT_LOADED = 16;
  VSR_REPLACE_ERROR = 17;
  VSR_CACHE_ERROR = 18;
  VSR_INVALID_CONTEXT = 19;
  VSR_NOTHING_TO_CHECK = 20;
  VSR_DIALOG_ERROR = 21;
  VSR_OUT_OF_MEMORY = 22;
  VSR_BAD_INDEX = 23;
  VSR_OUT_OF_STRING_SPACE = 24;
  VSR_IN_DIALOG = 25;
  VSR_FILE_EXISTS = 26;

{ Runtime error constants }

{ RuntimeErrorCodes }

  VB_OFFSET = 32350;
  VBR_WORD_TOO_LONG = 32351;
  VBR_NO_MISSPELL = 32352;
  VBR_ALREADY_OPEN = 32354;
  VBR_OPEN_FAILED = 32355;
  VBR_CREATE_FAILED = 32356;
  VBR_INVALID_DICTIONARY = 32357;
  VBR_WRITE_FAILURE = 32359;
  VBR_READ_FAILURE = 32360;
  VBR_BAD_FILE_NAME = 32361;
  VBR_NOT_UPDATEABLE = 32362;
  VBR_DUPLICATE_WORD = 32363;
  VBR_BAD_CUSTOM = 32364;
  VBR_IN_EVENT = 32365;
  VBR_NOT_LOADED = 32366;
  VBR_REPLACE_ERROR = 32367;
  VBR_CACHE_ERROR = 32368;
  VBR_INVALID_CONTEXT = 32369;
  VBR_NOTHING_TO_CHECK = 32370;
  VBR_DIALOG_ERROR = 32371;
  VBR_OUT_OF_MEMORY = 32372;
  VBR_BAD_INDEX = 32373;
  VBR_OUT_OF_STRING_SPACE = 32374;
  VBR_IN_DIALOG = 32375;
  VBR_FILE_EXISTS = 32376;

{ Miscellaneous constants }

{ MiscellaneousCodes }

  VS_ALL = 0;
  VS_MAXWORDSIZE = 75;

const

{ Component class GUIDs }
  Class_VSSpell: TGUID = '{97F4CED0-9103-11CE-8385-524153480001}';

type

{ Forward declarations }
{ Forward declarations: Interfaces }
  _DVSpell = dispinterface;
  _DVSpellEvents = dispinterface;

{ Forward declarations: CoClasses }
  VSSpell = _DVSpell;

{ Forward declarations: Enums }
  DictionaryCategories = TOleEnum;
  DictionaryStatusBits = TOleEnum;
  DictionaryLanguageCodes = TOleEnum;
  EventOptionBits = TOleEnum;
  SearchOrderCodes = TOleEnum;
  SpellOptionBits = TOleEnum;
  SuggestOptionBits = TOleEnum;
  IgnoreReplaceCodes = TOleEnum;
  EventActionCodes = TOleEnum;
  ButtonClickBits = TOleEnum;
  DialogElementBits = TOleEnum;
  ResultStatusCodes = TOleEnum;
  ResultErrorCodes = TOleEnum;
  RuntimeErrorCodes = TOleEnum;
  MiscellaneousCodes = TOleEnum;

{ Dispatch interface for VisualSpeller Control }

  _DVSpell = dispinterface
    ['{97F4CED1-9103-11CE-8385-524153480001}']
    property AutoPopup: WordBool dispid 4;
    property AutoReplace: WordBool dispid 5;
    property AutoSuggest: WordBool dispid 6;
    property BreakWordCount: Smallint dispid 7;
    property CacheSize: Smallint dispid 8;
    property ErrorOffset: Smallint dispid 1;
    property IgnoreFullCaps: WordBool dispid 9;
    property IgnorePartialNumbers: WordBool dispid 10;
    property MaxSuggestions: Smallint dispid 11;
    property MultiLine: WordBool dispid 12;
    property SuggestionsLimit: Smallint dispid 13;
    property Version: WideString dispid 14;
    property CurrentLine: Integer dispid 15;
    property CustomCount: Smallint dispid 16;
    property DLLHandle: Integer dispid 17;
    property EventOptions: Smallint dispid 18;
    property Hyphenation: WideString dispid 19;
    property IRAction: Smallint dispid 20;
    property IRWhereFound: Smallint dispid 21;
    property LineBreak: WideString dispid 22;
    property LineOffset: Smallint dispid 23;
    property MisspelledWord: WideString dispid 24;
    property ReplaceCount: Integer dispid 25;
    property ReplacementWord: WideString dispid 26;
    property ResultCode: Smallint dispid 27;
    property ResumeOffset: Integer dispid 28;
    property SearchOrder: Smallint dispid 29;
    property SpellOptions: Smallint dispid 30;
    property StandardCount: Smallint dispid 31;
    property SuggestOptions: Smallint dispid 32;
    property SuggestionCount: Smallint dispid 33;
    property Text: WideString dispid 34;
    property WhereFound: Smallint dispid 35;
    property WordCount: Integer dispid 36;
    property WordOffset: Integer dispid 37;
    property AllowJoinedWords: WordBool dispid 38;
    property DialogLeft: Integer dispid 39;
    property DialogTop: Integer dispid 40;
    property ReplaceRecheck: WordBool dispid 41;
    property DialogBgColor: TColor dispid 42;
    property DialogLeftActual: Integer dispid 43;
    property DialogTopActual: Integer dispid 44;
    property ReplaceOccurred: WordBool dispid 45;
    property SuggestionsMade: WordBool dispid 46;
    property WordLength: Smallint dispid 47;
    property CacheHits: Integer dispid 48;
    property CacheMisses: Integer dispid 49;
    property TimerTicks: Integer dispid 50;
    property UserData: Integer dispid 51;
    property CheckedWord: WideString dispid 52;
    property CommonIRListIsEnabled: WordBool dispid 53;
    property WordMisspelledTitle: WideString dispid 54;
    property OptionsTitle: WideString dispid 55;
    property ErrorTitle: WideString dispid 56;
    property WordMisspelledHelpFile: WideString dispid 57;
    property OptionsHelpFile: WideString dispid 58;
    property DialogElements: Integer dispid 59;
    property DialogWidth: Integer dispid 60;
    property DialogHeight: Integer dispid 61;
    property ErrorText: WideString dispid 62;
    property ClickedButton: Integer dispid 63;
    property ClickInfo: Integer dispid 64;
    property ClickInfoText: WideString dispid 65;
    property AddToCommonIRList: Smallint dispid 66;
    property BeginCheck: Smallint dispid 67;
    property CheckText: WideString dispid 68;
    property CheckWord: WideString dispid 69;
    property ClearCounts: Smallint dispid 70;
    property ClearOffsets: Smallint dispid 71;
    property FindSuggestions: WideString dispid 72;
    property ReplaceLastWord: Smallint dispid 73;
    property ResumeCheck: Smallint dispid 74;
    property ClearSuggestions: Smallint dispid 75;
    property PopupError: Smallint dispid 76;
    property PopupOptions: Smallint dispid 77;
    property PopupWordMisspelled: Smallint dispid 78;
    property CreateCustom: WideString dispid 79;
    property ResumeWithRecheck: Smallint dispid 80;
    property EnableCommonIRList: WordBool dispid 81;
    property ClearCommonIRList: Smallint dispid 82;
    property RemoveFromCommonIRList: WideString dispid 83;
    property EnableEventOptions: Smallint dispid 84;
    property DisableEventOptions: Smallint dispid 85;
    property EnableSpellOptions: Smallint dispid 86;
    property DisableSpellOptions: Smallint dispid 87;
    property EnableSuggestOptions: Smallint dispid 88;
    property DisableSuggestOptions: Smallint dispid 89;
    property EnableDialogElements: Integer dispid 90;
    property DisableDialogElements: Integer dispid 91;
    property _Text: WideString dispid 0;
    property StandardDictionary: WideString dispid 2;
    property CustomDictionary: WideString dispid 3;
    property OpenStandard[loadit: WordBool]: WideString writeonly dispid 92;
    property DictionaryLanguage[index: Smallint]: Smallint readonly dispid 107;
    property DictionaryName[index: Smallint]: WideString readonly dispid 108;
    property DictionaryStatus[index: Smallint]: Smallint readonly dispid 109;
    property DictionaryIsEnabled[index: Smallint]: WordBool readonly dispid 110;
    property DictionaryNameFull[index: Smallint]: WideString readonly dispid 111;
    property StandardIRListIsEnabled[index: Smallint]: WordBool readonly dispid 112;
    property DictionaryIsLoaded[index: Smallint]: WordBool readonly dispid 113;
    property DictionaryPerformance[index: Smallint]: Smallint dispid 114;
    property Suggestion[index: Smallint]: WideString readonly dispid 115;
    property CustomIsUpdateable[index: Smallint]: WordBool readonly dispid 116;
    property AddToStandardIRList[index: Smallint]: Smallint writeonly dispid 93;
    property AddSuggestion[matchcode: Smallint]: WideString writeonly dispid 94;
    property AddToCustom[index: Smallint]: Smallint writeonly dispid 95;
    property ClearStandardIRList[index: Smallint]: Smallint writeonly dispid 96;
    property CloseDictionary[index: Smallint]: Smallint writeonly dispid 97;
    property GetEntry[index: Smallint]: Integer writeonly dispid 98;
    property RemoveFromStandardIRList[index: Smallint]: WideString writeonly dispid 99;
    property DictionaryPerformanceActual[index: Smallint]: Smallint readonly dispid 117;
    property DictionaryBlockCount[index: Smallint]: Smallint readonly dispid 118;
    property DictionaryBlockSize[index: Smallint]: Smallint readonly dispid 119;
    property DictionaryCommonCount[index: Smallint]: Smallint readonly dispid 120;
    property DictionaryCompatibilityBits[index: Smallint]: Smallint readonly dispid 121;
    property DictionaryCopyright[index: Smallint]: WideString readonly dispid 122;
    property DictionaryCopyrightDerived[index: Smallint]: WideString readonly dispid 123;
    property DictionaryFlags[index: Smallint]: Smallint readonly dispid 124;
    property DictionaryLoadCount[index: Smallint]: Smallint readonly dispid 125;
    property DictionaryMakerVersion[index: Smallint]: Smallint readonly dispid 126;
    property DictionaryOpenCount[index: Smallint]: Smallint readonly dispid 127;
    property DictionarySymbolSetSize[index: Smallint]: Smallint readonly dispid 128;
    property DictionaryWordCount[index: Smallint]: Integer readonly dispid 129;
    property CreateCustomExtended[index: Smallint]: WideString writeonly dispid 100;
    property EnableDictionary[index: Smallint]: WordBool writeonly dispid 101;
    property EnableCustomUpdate[index: Smallint]: WordBool writeonly dispid 102;
    property LoadDictionary[index: Smallint]: Smallint writeonly dispid 103;
    property UnloadDictionary[index: Smallint]: Smallint writeonly dispid 104;
    property CustomIsReadOnly[index: Smallint]: WordBool readonly dispid 130;
    property CustomIsExtended[index: Smallint]: WordBool readonly dispid 131;
    property EnableStandardIRList[index: Smallint]: WordBool writeonly dispid 105;
    property OpenCustom[loadit: WordBool]: WideString writeonly dispid 106;
    procedure AboutBox; dispid -552;
  end;

{ Event interface for VisualSpeller Control }

  _DVSpellEvents = dispinterface
    ['{97F4CED2-9103-11CE-8385-524153480001}']
    procedure Misspelled(var EventAction: Smallint); dispid 1;
    procedure Complete(var EventAction: Smallint); dispid 2;
    procedure Found(var EventAction: Smallint); dispid 3;
    procedure BeforeReplace(var EventAction: Smallint); dispid 4;
    procedure AfterReplace(var EventAction: Smallint); dispid 5;
    procedure AfterPopup(var EventAction: Smallint); dispid 6;
    procedure CheckStatus(var EventAction: Smallint); dispid 7;
    procedure CheckError(var EventAction: Smallint); dispid 8;
    procedure ClickIn(var EventAction: Smallint); dispid 9;
    procedure ClickOut(var EventAction: Smallint); dispid 10;
  end;

{ VCI VisualSpeller Spellchecker }

  TVSSpellMisspelled = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellComplete = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellFound = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellBeforeReplace = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellAfterReplace = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellAfterPopup = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellCheckStatus = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellCheckError = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellClickIn = procedure(Sender: TObject; var EventAction: Smallint) of object;
  TVSSpellClickOut = procedure(Sender: TObject; var EventAction: Smallint) of object;

  TVSSpell = class(TOleControl)
  private
    FOnMisspelled: TVSSpellMisspelled;
    FOnComplete: TVSSpellComplete;
    FOnFound: TVSSpellFound;
    FOnBeforeReplace: TVSSpellBeforeReplace;
    FOnAfterReplace: TVSSpellAfterReplace;
    FOnAfterPopup: TVSSpellAfterPopup;
    FOnCheckStatus: TVSSpellCheckStatus;
    FOnCheckError: TVSSpellCheckError;
    FOnClickIn: TVSSpellClickIn;
    FOnClickOut: TVSSpellClickOut;
    FIntf: _DVSpell;
    procedure Set_OpenStandard(loadit: WordBool; const Value: WideString);
    function Get_DictionaryLanguage(index: Smallint): Smallint;
    function Get_DictionaryName(index: Smallint): WideString;
    function Get_DictionaryStatus(index: Smallint): Smallint;
    function Get_DictionaryIsEnabled(index: Smallint): WordBool;
    function Get_DictionaryNameFull(index: Smallint): WideString;
    function Get_StandardIRListIsEnabled(index: Smallint): WordBool;
    function Get_DictionaryIsLoaded(index: Smallint): WordBool;
    function Get_DictionaryPerformance(index: Smallint): Smallint;
    procedure Set_DictionaryPerformance(index: Smallint; Value: Smallint);
    function Get_Suggestion(index: Smallint): WideString;
    function Get_CustomIsUpdateable(index: Smallint): WordBool;
    procedure Set_AddToStandardIRList(index: Smallint; Value: Smallint);
    procedure Set_AddSuggestion(matchcode: Smallint; const Value: WideString);
    procedure Set_AddToCustom(index: Smallint; Value: Smallint);
    procedure Set_ClearStandardIRList(index: Smallint; Value: Smallint);
    procedure Set_CloseDictionary(index: Smallint; Value: Smallint);
    procedure Set_GetEntry(index: Smallint; Value: Integer);
    procedure Set_RemoveFromStandardIRList(index: Smallint; const Value: WideString);
    function Get_DictionaryPerformanceActual(index: Smallint): Smallint;
    function Get_DictionaryBlockCount(index: Smallint): Smallint;
    function Get_DictionaryBlockSize(index: Smallint): Smallint;
    function Get_DictionaryCommonCount(index: Smallint): Smallint;
    function Get_DictionaryCompatibilityBits(index: Smallint): Smallint;
    function Get_DictionaryCopyright(index: Smallint): WideString;
    function Get_DictionaryCopyrightDerived(index: Smallint): WideString;
    function Get_DictionaryFlags(index: Smallint): Smallint;
    function Get_DictionaryLoadCount(index: Smallint): Smallint;
    function Get_DictionaryMakerVersion(index: Smallint): Smallint;
    function Get_DictionaryOpenCount(index: Smallint): Smallint;
    function Get_DictionarySymbolSetSize(index: Smallint): Smallint;
    function Get_DictionaryWordCount(index: Smallint): Integer;
    procedure Set_CreateCustomExtended(index: Smallint; const Value: WideString);
    procedure Set_EnableDictionary(index: Smallint; Value: WordBool);
    procedure Set_EnableCustomUpdate(index: Smallint; Value: WordBool);
    procedure Set_LoadDictionary(index: Smallint; Value: Smallint);
    procedure Set_UnloadDictionary(index: Smallint; Value: Smallint);
    function Get_CustomIsReadOnly(index: Smallint): WordBool;
    function Get_CustomIsExtended(index: Smallint): WordBool;
    procedure Set_EnableStandardIRList(index: Smallint; Value: WordBool);
    procedure Set_OpenCustom(loadit: WordBool; const Value: WideString);
  protected
    procedure InitControlData; override;
    procedure InitControlInterface(const Obj: IUnknown); override;
  public
    procedure AboutBox;
    property ControlInterface: _DVSpell read FIntf;
    property OpenStandard[loadit: WordBool]: WideString write Set_OpenStandard;
    property DictionaryLanguage[index: Smallint]: Smallint read Get_DictionaryLanguage;
    property DictionaryName[index: Smallint]: WideString read Get_DictionaryName;
    property DictionaryStatus[index: Smallint]: Smallint read Get_DictionaryStatus;
    property DictionaryIsEnabled[index: Smallint]: WordBool read Get_DictionaryIsEnabled;
    property DictionaryNameFull[index: Smallint]: WideString read Get_DictionaryNameFull;
    property StandardIRListIsEnabled[index: Smallint]: WordBool read Get_StandardIRListIsEnabled;
    property DictionaryIsLoaded[index: Smallint]: WordBool read Get_DictionaryIsLoaded;
    property DictionaryPerformance[index: Smallint]: Smallint read Get_DictionaryPerformance write Set_DictionaryPerformance;
    property Suggestion[index: Smallint]: WideString read Get_Suggestion;
    property CustomIsUpdateable[index: Smallint]: WordBool read Get_CustomIsUpdateable;
    property AddToStandardIRList[index: Smallint]: Smallint write Set_AddToStandardIRList;
    property AddSuggestion[matchcode: Smallint]: WideString write Set_AddSuggestion;
    property AddToCustom[index: Smallint]: Smallint write Set_AddToCustom;
    property ClearStandardIRList[index: Smallint]: Smallint write Set_ClearStandardIRList;
    property CloseDictionary[index: Smallint]: Smallint write Set_CloseDictionary;
    property GetEntry[index: Smallint]: Integer write Set_GetEntry;
    property RemoveFromStandardIRList[index: Smallint]: WideString write Set_RemoveFromStandardIRList;
    property DictionaryPerformanceActual[index: Smallint]: Smallint read Get_DictionaryPerformanceActual;
    property DictionaryBlockCount[index: Smallint]: Smallint read Get_DictionaryBlockCount;
    property DictionaryBlockSize[index: Smallint]: Smallint read Get_DictionaryBlockSize;
    property DictionaryCommonCount[index: Smallint]: Smallint read Get_DictionaryCommonCount;
    property DictionaryCompatibilityBits[index: Smallint]: Smallint read Get_DictionaryCompatibilityBits;
    property DictionaryCopyright[index: Smallint]: WideString read Get_DictionaryCopyright;
    property DictionaryCopyrightDerived[index: Smallint]: WideString read Get_DictionaryCopyrightDerived;
    property DictionaryFlags[index: Smallint]: Smallint read Get_DictionaryFlags;
    property DictionaryLoadCount[index: Smallint]: Smallint read Get_DictionaryLoadCount;
    property DictionaryMakerVersion[index: Smallint]: Smallint read Get_DictionaryMakerVersion;
    property DictionaryOpenCount[index: Smallint]: Smallint read Get_DictionaryOpenCount;
    property DictionarySymbolSetSize[index: Smallint]: Smallint read Get_DictionarySymbolSetSize;
    property DictionaryWordCount[index: Smallint]: Integer read Get_DictionaryWordCount;
    property CreateCustomExtended[index: Smallint]: WideString write Set_CreateCustomExtended;
    property EnableDictionary[index: Smallint]: WordBool write Set_EnableDictionary;
    property EnableCustomUpdate[index: Smallint]: WordBool write Set_EnableCustomUpdate;
    property LoadDictionary[index: Smallint]: Smallint write Set_LoadDictionary;
    property UnloadDictionary[index: Smallint]: Smallint write Set_UnloadDictionary;
    property CustomIsReadOnly[index: Smallint]: WordBool read Get_CustomIsReadOnly;
    property CustomIsExtended[index: Smallint]: WordBool read Get_CustomIsExtended;
    property EnableStandardIRList[index: Smallint]: WordBool write Set_EnableStandardIRList;
    property OpenCustom[loadit: WordBool]: WideString write Set_OpenCustom;
  published
    property AutoPopup: WordBool index 4 read GetWordBoolProp write SetWordBoolProp stored False;
    property AutoReplace: WordBool index 5 read GetWordBoolProp write SetWordBoolProp stored False;
    property AutoSuggest: WordBool index 6 read GetWordBoolProp write SetWordBoolProp stored False;
    property BreakWordCount: Smallint index 7 read GetSmallintProp write SetSmallintProp stored False;
    property CacheSize: Smallint index 8 read GetSmallintProp write SetSmallintProp stored False;
    property ErrorOffset: Smallint index 1 read GetSmallintProp write SetSmallintProp stored False;
    property IgnoreFullCaps: WordBool index 9 read GetWordBoolProp write SetWordBoolProp stored False;
    property IgnorePartialNumbers: WordBool index 10 read GetWordBoolProp write SetWordBoolProp stored False;
    property MaxSuggestions: Smallint index 11 read GetSmallintProp write SetSmallintProp stored False;
    property MultiLine: WordBool index 12 read GetWordBoolProp write SetWordBoolProp stored False;
    property SuggestionsLimit: Smallint index 13 read GetSmallintProp write SetSmallintProp stored False;
    property Version: WideString index 14 read GetWideStringProp write SetWideStringProp stored False;
    property CurrentLine: Integer index 15 read GetIntegerProp write SetIntegerProp stored False;
    property CustomCount: Smallint index 16 read GetSmallintProp write SetSmallintProp stored False;
    property DLLHandle: Integer index 17 read GetIntegerProp write SetIntegerProp stored False;
    property EventOptions: Smallint index 18 read GetSmallintProp write SetSmallintProp stored False;
    property Hyphenation: WideString index 19 read GetWideStringProp write SetWideStringProp stored False;
    property IRAction: Smallint index 20 read GetSmallintProp write SetSmallintProp stored False;
    property IRWhereFound: Smallint index 21 read GetSmallintProp write SetSmallintProp stored False;
    property LineBreak: WideString index 22 read GetWideStringProp write SetWideStringProp stored False;
    property LineOffset: Smallint index 23 read GetSmallintProp write SetSmallintProp stored False;
    property MisspelledWord: WideString index 24 read GetWideStringProp write SetWideStringProp stored False;
    property ReplaceCount: Integer index 25 read GetIntegerProp write SetIntegerProp stored False;
    property ReplacementWord: WideString index 26 read GetWideStringProp write SetWideStringProp stored False;
    property ResultCode: Smallint index 27 read GetSmallintProp write SetSmallintProp stored False;
    property ResumeOffset: Integer index 28 read GetIntegerProp write SetIntegerProp stored False;
    property SearchOrder: Smallint index 29 read GetSmallintProp write SetSmallintProp stored False;
    property SpellOptions: Smallint index 30 read GetSmallintProp write SetSmallintProp stored False;
    property StandardCount: Smallint index 31 read GetSmallintProp write SetSmallintProp stored False;
    property SuggestOptions: Smallint index 32 read GetSmallintProp write SetSmallintProp stored False;
    property SuggestionCount: Smallint index 33 read GetSmallintProp write SetSmallintProp stored False;
    property Text: WideString index 34 read GetWideStringProp write SetWideStringProp stored False;
    property WhereFound: Smallint index 35 read GetSmallintProp write SetSmallintProp stored False;
    property WordCount: Integer index 36 read GetIntegerProp write SetIntegerProp stored False;
    property WordOffset: Integer index 37 read GetIntegerProp write SetIntegerProp stored False;
    property AllowJoinedWords: WordBool index 38 read GetWordBoolProp write SetWordBoolProp stored False;
    property DialogLeft: Integer index 39 read GetIntegerProp write SetIntegerProp stored False;
    property DialogTop: Integer index 40 read GetIntegerProp write SetIntegerProp stored False;
    property ReplaceRecheck: WordBool index 41 read GetWordBoolProp write SetWordBoolProp stored False;
    property DialogBgColor: TColor index 42 read GetTColorProp write SetTColorProp stored False;
    property DialogLeftActual: Integer index 43 read GetIntegerProp write SetIntegerProp stored False;
    property DialogTopActual: Integer index 44 read GetIntegerProp write SetIntegerProp stored False;
    property ReplaceOccurred: WordBool index 45 read GetWordBoolProp write SetWordBoolProp stored False;
    property SuggestionsMade: WordBool index 46 read GetWordBoolProp write SetWordBoolProp stored False;
    property WordLength: Smallint index 47 read GetSmallintProp write SetSmallintProp stored False;
    property CacheHits: Integer index 48 read GetIntegerProp write SetIntegerProp stored False;
    property CacheMisses: Integer index 49 read GetIntegerProp write SetIntegerProp stored False;
    property TimerTicks: Integer index 50 read GetIntegerProp write SetIntegerProp stored False;
    property UserData: Integer index 51 read GetIntegerProp write SetIntegerProp stored False;
    property CheckedWord: WideString index 52 read GetWideStringProp write SetWideStringProp stored False;
    property CommonIRListIsEnabled: WordBool index 53 read GetWordBoolProp write SetWordBoolProp stored False;
    property WordMisspelledTitle: WideString index 54 read GetWideStringProp write SetWideStringProp stored False;
    property OptionsTitle: WideString index 55 read GetWideStringProp write SetWideStringProp stored False;
    property ErrorTitle: WideString index 56 read GetWideStringProp write SetWideStringProp stored False;
    property WordMisspelledHelpFile: WideString index 57 read GetWideStringProp write SetWideStringProp stored False;
    property OptionsHelpFile: WideString index 58 read GetWideStringProp write SetWideStringProp stored False;
    property DialogElements: Integer index 59 read GetIntegerProp write SetIntegerProp stored False;
    property DialogWidth: Integer index 60 read GetIntegerProp write SetIntegerProp stored False;
    property DialogHeight: Integer index 61 read GetIntegerProp write SetIntegerProp stored False;
    property ErrorText: WideString index 62 read GetWideStringProp write SetWideStringProp stored False;
    property ClickedButton: Integer index 63 read GetIntegerProp write SetIntegerProp stored False;
    property ClickInfo: Integer index 64 read GetIntegerProp write SetIntegerProp stored False;
    property ClickInfoText: WideString index 65 read GetWideStringProp write SetWideStringProp stored False;
    property AddToCommonIRList: Smallint index 66 read GetSmallintProp write SetSmallintProp stored False;
    property BeginCheck: Smallint index 67 read GetSmallintProp write SetSmallintProp stored False;
    property CheckText: WideString index 68 read GetWideStringProp write SetWideStringProp stored False;
    property CheckWord: WideString index 69 read GetWideStringProp write SetWideStringProp stored False;
    property ClearCounts: Smallint index 70 read GetSmallintProp write SetSmallintProp stored False;
    property ClearOffsets: Smallint index 71 read GetSmallintProp write SetSmallintProp stored False;
    property FindSuggestions: WideString index 72 read GetWideStringProp write SetWideStringProp stored False;
    property ReplaceLastWord: Smallint index 73 read GetSmallintProp write SetSmallintProp stored False;
    property ResumeCheck: Smallint index 74 read GetSmallintProp write SetSmallintProp stored False;
    property ClearSuggestions: Smallint index 75 read GetSmallintProp write SetSmallintProp stored False;
    property PopupError: Smallint index 76 read GetSmallintProp write SetSmallintProp stored False;
    property PopupOptions: Smallint index 77 read GetSmallintProp write SetSmallintProp stored False;
    property PopupWordMisspelled: Smallint index 78 read GetSmallintProp write SetSmallintProp stored False;
    property CreateCustom: WideString index 79 read GetWideStringProp write SetWideStringProp stored False;
    property ResumeWithRecheck: Smallint index 80 read GetSmallintProp write SetSmallintProp stored False;
    property EnableCommonIRList: WordBool index 81 read GetWordBoolProp write SetWordBoolProp stored False;
    property ClearCommonIRList: Smallint index 82 read GetSmallintProp write SetSmallintProp stored False;
    property RemoveFromCommonIRList: WideString index 83 read GetWideStringProp write SetWideStringProp stored False;
    property EnableEventOptions: Smallint index 84 read GetSmallintProp write SetSmallintProp stored False;
    property DisableEventOptions: Smallint index 85 read GetSmallintProp write SetSmallintProp stored False;
    property EnableSpellOptions: Smallint index 86 read GetSmallintProp write SetSmallintProp stored False;
    property DisableSpellOptions: Smallint index 87 read GetSmallintProp write SetSmallintProp stored False;
    property EnableSuggestOptions: Smallint index 88 read GetSmallintProp write SetSmallintProp stored False;
    property DisableSuggestOptions: Smallint index 89 read GetSmallintProp write SetSmallintProp stored False;
    property EnableDialogElements: Integer index 90 read GetIntegerProp write SetIntegerProp stored False;
    property DisableDialogElements: Integer index 91 read GetIntegerProp write SetIntegerProp stored False;
    property _Text: WideString index 0 read GetWideStringProp write SetWideStringProp stored False;
    property StandardDictionary: WideString index 2 read GetWideStringProp write SetWideStringProp stored False;
    property CustomDictionary: WideString index 3 read GetWideStringProp write SetWideStringProp stored False;
    property OnMisspelled: TVSSpellMisspelled read FOnMisspelled write FOnMisspelled;
    property OnComplete: TVSSpellComplete read FOnComplete write FOnComplete;
    property OnFound: TVSSpellFound read FOnFound write FOnFound;
    property OnBeforeReplace: TVSSpellBeforeReplace read FOnBeforeReplace write FOnBeforeReplace;
    property OnAfterReplace: TVSSpellAfterReplace read FOnAfterReplace write FOnAfterReplace;
    property OnAfterPopup: TVSSpellAfterPopup read FOnAfterPopup write FOnAfterPopup;
    property OnCheckStatus: TVSSpellCheckStatus read FOnCheckStatus write FOnCheckStatus;
    property OnCheckError: TVSSpellCheckError read FOnCheckError write FOnCheckError;
    property OnClickIn: TVSSpellClickIn read FOnClickIn write FOnClickIn;
    property OnClickOut: TVSSpellClickOut read FOnClickOut write FOnClickOut;
  end;

procedure Register;

implementation

uses ComObj;

procedure TVSSpell.InitControlData;
const
  CEventDispIDs: array[0..9] of Integer = (
    $00000001, $00000002, $00000003, $00000004, $00000005, $00000006,
    $00000007, $00000008, $00000009, $0000000A);
  CLicenseKey: array[0..19] of Word = (
    $0043, $006F, $0070, $0079, $0072, $0069, $0067, $0068, $0074, $0020,
    $0028, $0063, $0029, $0020, $0031, $0039, $0039, $0035, $0020, $0000);
  CControlData: TControlData = (
    ClassID: '{97F4CED0-9103-11CE-8385-524153480001}';
    EventIID: '{97F4CED2-9103-11CE-8385-524153480001}';
    EventCount: 10;
    EventDispIDs: @CEventDispIDs;
    LicenseKey: @CLicenseKey;
    Flags: $00000000;
    Version: 300);
begin
  ControlData := @CControlData;
end;

procedure TVSSpell.InitControlInterface(const Obj: IUnknown);
begin
  FIntf := Obj as _DVSpell;
end;

procedure TVSSpell.AboutBox;
begin
  ControlInterface.AboutBox;
end;

procedure TVSSpell.Set_OpenStandard(loadit: WordBool; const Value: WideString);
begin
  ControlInterface.OpenStandard[loadit] := Value;
end;

function TVSSpell.Get_DictionaryLanguage(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryLanguage[index];
end;

function TVSSpell.Get_DictionaryName(index: Smallint): WideString;
begin
  Result := ControlInterface.DictionaryName[index];
end;

function TVSSpell.Get_DictionaryStatus(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryStatus[index];
end;

function TVSSpell.Get_DictionaryIsEnabled(index: Smallint): WordBool;
begin
  Result := ControlInterface.DictionaryIsEnabled[index];
end;

function TVSSpell.Get_DictionaryNameFull(index: Smallint): WideString;
begin
  Result := ControlInterface.DictionaryNameFull[index];
end;

function TVSSpell.Get_StandardIRListIsEnabled(index: Smallint): WordBool;
begin
  Result := ControlInterface.StandardIRListIsEnabled[index];
end;

function TVSSpell.Get_DictionaryIsLoaded(index: Smallint): WordBool;
begin
  Result := ControlInterface.DictionaryIsLoaded[index];
end;

function TVSSpell.Get_DictionaryPerformance(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryPerformance[index];
end;

procedure TVSSpell.Set_DictionaryPerformance(index: Smallint; Value: Smallint);
begin
  ControlInterface.DictionaryPerformance[index] := Value;
end;

function TVSSpell.Get_Suggestion(index: Smallint): WideString;
begin
  Result := ControlInterface.Suggestion[index];
end;

function TVSSpell.Get_CustomIsUpdateable(index: Smallint): WordBool;
begin
  Result := ControlInterface.CustomIsUpdateable[index];
end;

procedure TVSSpell.Set_AddToStandardIRList(index: Smallint; Value: Smallint);
begin
  ControlInterface.AddToStandardIRList[index] := Value;
end;

procedure TVSSpell.Set_AddSuggestion(matchcode: Smallint; const Value: WideString);
begin
  ControlInterface.AddSuggestion[matchcode] := Value;
end;

procedure TVSSpell.Set_AddToCustom(index: Smallint; Value: Smallint);
begin
  ControlInterface.AddToCustom[index] := Value;
end;

procedure TVSSpell.Set_ClearStandardIRList(index: Smallint; Value: Smallint);
begin
  ControlInterface.ClearStandardIRList[index] := Value;
end;

procedure TVSSpell.Set_CloseDictionary(index: Smallint; Value: Smallint);
begin
  ControlInterface.CloseDictionary[index] := Value;
end;

procedure TVSSpell.Set_GetEntry(index: Smallint; Value: Integer);
begin
  ControlInterface.GetEntry[index] := Value;
end;

procedure TVSSpell.Set_RemoveFromStandardIRList(index: Smallint; const Value: WideString);
begin
  ControlInterface.RemoveFromStandardIRList[index] := Value;
end;

function TVSSpell.Get_DictionaryPerformanceActual(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryPerformanceActual[index];
end;

function TVSSpell.Get_DictionaryBlockCount(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryBlockCount[index];
end;

function TVSSpell.Get_DictionaryBlockSize(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryBlockSize[index];
end;

function TVSSpell.Get_DictionaryCommonCount(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryCommonCount[index];
end;

function TVSSpell.Get_DictionaryCompatibilityBits(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryCompatibilityBits[index];
end;

function TVSSpell.Get_DictionaryCopyright(index: Smallint): WideString;
begin
  Result := ControlInterface.DictionaryCopyright[index];
end;

function TVSSpell.Get_DictionaryCopyrightDerived(index: Smallint): WideString;
begin
  Result := ControlInterface.DictionaryCopyrightDerived[index];
end;

function TVSSpell.Get_DictionaryFlags(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryFlags[index];
end;

function TVSSpell.Get_DictionaryLoadCount(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryLoadCount[index];
end;

function TVSSpell.Get_DictionaryMakerVersion(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryMakerVersion[index];
end;

function TVSSpell.Get_DictionaryOpenCount(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionaryOpenCount[index];
end;

function TVSSpell.Get_DictionarySymbolSetSize(index: Smallint): Smallint;
begin
  Result := ControlInterface.DictionarySymbolSetSize[index];
end;

function TVSSpell.Get_DictionaryWordCount(index: Smallint): Integer;
begin
  Result := ControlInterface.DictionaryWordCount[index];
end;

procedure TVSSpell.Set_CreateCustomExtended(index: Smallint; const Value: WideString);
begin
  ControlInterface.CreateCustomExtended[index] := Value;
end;

procedure TVSSpell.Set_EnableDictionary(index: Smallint; Value: WordBool);
begin
  ControlInterface.EnableDictionary[index] := Value;
end;

procedure TVSSpell.Set_EnableCustomUpdate(index: Smallint; Value: WordBool);
begin
  ControlInterface.EnableCustomUpdate[index] := Value;
end;

procedure TVSSpell.Set_LoadDictionary(index: Smallint; Value: Smallint);
begin
  ControlInterface.LoadDictionary[index] := Value;
end;

procedure TVSSpell.Set_UnloadDictionary(index: Smallint; Value: Smallint);
begin
  ControlInterface.UnloadDictionary[index] := Value;
end;

function TVSSpell.Get_CustomIsReadOnly(index: Smallint): WordBool;
begin
  Result := ControlInterface.CustomIsReadOnly[index];
end;

function TVSSpell.Get_CustomIsExtended(index: Smallint): WordBool;
begin
  Result := ControlInterface.CustomIsExtended[index];
end;

procedure TVSSpell.Set_EnableStandardIRList(index: Smallint; Value: WordBool);
begin
  ControlInterface.EnableStandardIRList[index] := Value;
end;

procedure TVSSpell.Set_OpenCustom(loadit: WordBool; const Value: WideString);
begin
  ControlInterface.OpenCustom[loadit] := Value;
end;


procedure Register;
begin
  RegisterComponents('ActiveX', [TVSSpell]);  { do not localize }   
end;

end.
