// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCSpell3.pas' rev: 6.00

#ifndef VCSpell3HPP
#define VCSpell3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcspell3
{
//-- type declarations -------------------------------------------------------
__dispinterface _DVSpell;
typedef System::DelphiInterface<_DVSpell> _di__DVSpell;
typedef _DVSpell VSSpell;
;

typedef Activex::TOleEnum DictionaryCategories;

typedef Activex::TOleEnum DictionaryStatusBits;

typedef Activex::TOleEnum DictionaryLanguageCodes;

typedef Activex::TOleEnum EventOptionBits;

typedef Activex::TOleEnum SearchOrderCodes;

typedef Activex::TOleEnum SpellOptionBits;

typedef Activex::TOleEnum SuggestOptionBits;

typedef Activex::TOleEnum IgnoreReplaceCodes;

typedef Activex::TOleEnum EventActionCodes;

typedef Activex::TOleEnum ButtonClickBits;

typedef Activex::TOleEnum DialogElementBits;

typedef Activex::TOleEnum ResultStatusCodes;

typedef Activex::TOleEnum ResultErrorCodes;

typedef Activex::TOleEnum RuntimeErrorCodes;

typedef Activex::TOleEnum MiscellaneousCodes;

__dispinterface INTERFACE_UUID("{97F4CED1-9103-11CE-8385-524153480001}") _DVSpell  : public IDispatch 
{
	
};

__dispinterface _DVSpellEvents;
typedef System::DelphiInterface<_DVSpellEvents> _di__DVSpellEvents;
__dispinterface INTERFACE_UUID("{97F4CED2-9103-11CE-8385-524153480001}") _DVSpellEvents  : public IDispatch 
{
	
};

typedef void __fastcall (__closure *TVSSpellMisspelled)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellComplete)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellFound)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellBeforeReplace)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellAfterReplace)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellAfterPopup)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellCheckStatus)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellCheckError)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellClickIn)(System::TObject* Sender, short &EventAction);

typedef void __fastcall (__closure *TVSSpellClickOut)(System::TObject* Sender, short &EventAction);

class DELPHICLASS TVSSpell;
class PASCALIMPLEMENTATION TVSSpell : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TVSSpellMisspelled FOnMisspelled;
	TVSSpellComplete FOnComplete;
	TVSSpellFound FOnFound;
	TVSSpellBeforeReplace FOnBeforeReplace;
	TVSSpellAfterReplace FOnAfterReplace;
	TVSSpellAfterPopup FOnAfterPopup;
	TVSSpellCheckStatus FOnCheckStatus;
	TVSSpellCheckError FOnCheckError;
	TVSSpellClickIn FOnClickIn;
	TVSSpellClickOut FOnClickOut;
	_di__DVSpell FIntf;
	void __fastcall Set_OpenStandard(Word loadit, const WideString Value);
	short __fastcall Get_DictionaryLanguage(short index);
	WideString __fastcall Get_DictionaryName(short index);
	short __fastcall Get_DictionaryStatus(short index);
	Word __fastcall Get_DictionaryIsEnabled(short index);
	WideString __fastcall Get_DictionaryNameFull(short index);
	Word __fastcall Get_StandardIRListIsEnabled(short index);
	Word __fastcall Get_DictionaryIsLoaded(short index);
	short __fastcall Get_DictionaryPerformance(short index);
	void __fastcall Set_DictionaryPerformance(short index, short Value);
	WideString __fastcall Get_Suggestion(short index);
	Word __fastcall Get_CustomIsUpdateable(short index);
	void __fastcall Set_AddToStandardIRList(short index, short Value);
	void __fastcall Set_AddSuggestion(short matchcode, const WideString Value);
	void __fastcall Set_AddToCustom(short index, short Value);
	void __fastcall Set_ClearStandardIRList(short index, short Value);
	void __fastcall Set_CloseDictionary(short index, short Value);
	void __fastcall Set_GetEntry(short index, int Value);
	void __fastcall Set_RemoveFromStandardIRList(short index, const WideString Value);
	short __fastcall Get_DictionaryPerformanceActual(short index);
	short __fastcall Get_DictionaryBlockCount(short index);
	short __fastcall Get_DictionaryBlockSize(short index);
	short __fastcall Get_DictionaryCommonCount(short index);
	short __fastcall Get_DictionaryCompatibilityBits(short index);
	WideString __fastcall Get_DictionaryCopyright(short index);
	WideString __fastcall Get_DictionaryCopyrightDerived(short index);
	short __fastcall Get_DictionaryFlags(short index);
	short __fastcall Get_DictionaryLoadCount(short index);
	short __fastcall Get_DictionaryMakerVersion(short index);
	short __fastcall Get_DictionaryOpenCount(short index);
	short __fastcall Get_DictionarySymbolSetSize(short index);
	int __fastcall Get_DictionaryWordCount(short index);
	void __fastcall Set_CreateCustomExtended(short index, const WideString Value);
	void __fastcall Set_EnableDictionary(short index, Word Value);
	void __fastcall Set_EnableCustomUpdate(short index, Word Value);
	void __fastcall Set_LoadDictionary(short index, short Value);
	void __fastcall Set_UnloadDictionary(short index, short Value);
	Word __fastcall Get_CustomIsReadOnly(short index);
	Word __fastcall Get_CustomIsExtended(short index);
	void __fastcall Set_EnableStandardIRList(short index, Word Value);
	void __fastcall Set_OpenCustom(Word loadit, const WideString Value);
	
protected:
	virtual void __fastcall InitControlData(void);
	virtual void __fastcall InitControlInterface(const System::_di_IInterface Obj);
	
public:
	void __fastcall AboutBox(void);
	__property _di__DVSpell ControlInterface = {read=FIntf};
	__property WideString OpenStandard[Word loadit] = {write=Set_OpenStandard};
	__property short DictionaryLanguage[short index] = {read=Get_DictionaryLanguage};
	__property WideString DictionaryName[short index] = {read=Get_DictionaryName};
	__property short DictionaryStatus[short index] = {read=Get_DictionaryStatus};
	__property Word DictionaryIsEnabled[short index] = {read=Get_DictionaryIsEnabled};
	__property WideString DictionaryNameFull[short index] = {read=Get_DictionaryNameFull};
	__property Word StandardIRListIsEnabled[short index] = {read=Get_StandardIRListIsEnabled};
	__property Word DictionaryIsLoaded[short index] = {read=Get_DictionaryIsLoaded};
	__property short DictionaryPerformance[short index] = {read=Get_DictionaryPerformance, write=Set_DictionaryPerformance};
	__property WideString Suggestion[short index] = {read=Get_Suggestion};
	__property Word CustomIsUpdateable[short index] = {read=Get_CustomIsUpdateable};
	__property short AddToStandardIRList[short index] = {write=Set_AddToStandardIRList};
	__property WideString AddSuggestion[short matchcode] = {write=Set_AddSuggestion};
	__property short AddToCustom[short index] = {write=Set_AddToCustom};
	__property short ClearStandardIRList[short index] = {write=Set_ClearStandardIRList};
	__property short CloseDictionary[short index] = {write=Set_CloseDictionary};
	__property int GetEntry[short index] = {write=Set_GetEntry};
	__property WideString RemoveFromStandardIRList[short index] = {write=Set_RemoveFromStandardIRList};
	__property short DictionaryPerformanceActual[short index] = {read=Get_DictionaryPerformanceActual};
	__property short DictionaryBlockCount[short index] = {read=Get_DictionaryBlockCount};
	__property short DictionaryBlockSize[short index] = {read=Get_DictionaryBlockSize};
	__property short DictionaryCommonCount[short index] = {read=Get_DictionaryCommonCount};
	__property short DictionaryCompatibilityBits[short index] = {read=Get_DictionaryCompatibilityBits};
	__property WideString DictionaryCopyright[short index] = {read=Get_DictionaryCopyright};
	__property WideString DictionaryCopyrightDerived[short index] = {read=Get_DictionaryCopyrightDerived};
	__property short DictionaryFlags[short index] = {read=Get_DictionaryFlags};
	__property short DictionaryLoadCount[short index] = {read=Get_DictionaryLoadCount};
	__property short DictionaryMakerVersion[short index] = {read=Get_DictionaryMakerVersion};
	__property short DictionaryOpenCount[short index] = {read=Get_DictionaryOpenCount};
	__property short DictionarySymbolSetSize[short index] = {read=Get_DictionarySymbolSetSize};
	__property int DictionaryWordCount[short index] = {read=Get_DictionaryWordCount};
	__property WideString CreateCustomExtended[short index] = {write=Set_CreateCustomExtended};
	__property Word EnableDictionary[short index] = {write=Set_EnableDictionary};
	__property Word EnableCustomUpdate[short index] = {write=Set_EnableCustomUpdate};
	__property short LoadDictionary[short index] = {write=Set_LoadDictionary};
	__property short UnloadDictionary[short index] = {write=Set_UnloadDictionary};
	__property Word CustomIsReadOnly[short index] = {read=Get_CustomIsReadOnly};
	__property Word CustomIsExtended[short index] = {read=Get_CustomIsExtended};
	__property Word EnableStandardIRList[short index] = {write=Set_EnableStandardIRList};
	__property WideString OpenCustom[Word loadit] = {write=Set_OpenCustom};
	
__published:
	__property Word AutoPopup = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=4, nodefault};
	__property Word AutoReplace = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=5, nodefault};
	__property Word AutoSuggest = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=6, nodefault};
	__property short BreakWordCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=7, nodefault};
	__property short CacheSize = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=8, nodefault};
	__property short ErrorOffset = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=1, nodefault};
	__property Word IgnoreFullCaps = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=9, nodefault};
	__property Word IgnorePartialNumbers = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=10, nodefault};
	__property short MaxSuggestions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=11, nodefault};
	__property Word MultiLine = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=12, nodefault};
	__property short SuggestionsLimit = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=13, nodefault};
	__property WideString Version = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=14};
	__property int CurrentLine = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=15, nodefault};
	__property short CustomCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16, nodefault};
	__property int DLLHandle = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=17, nodefault};
	__property short EventOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=18, nodefault};
	__property WideString Hyphenation = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=19};
	__property short IRAction = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=20, nodefault};
	__property short IRWhereFound = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=21, nodefault};
	__property WideString LineBreak = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=22};
	__property short LineOffset = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=23, nodefault};
	__property WideString MisspelledWord = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=24};
	__property int ReplaceCount = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=25, nodefault};
	__property WideString ReplacementWord = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=26};
	__property short ResultCode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=27, nodefault};
	__property int ResumeOffset = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=28, nodefault};
	__property short SearchOrder = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=29, nodefault};
	__property short SpellOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property short StandardCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=31, nodefault};
	__property short SuggestOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=32, nodefault};
	__property short SuggestionCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=33, nodefault};
	__property WideString Text = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=34};
	__property short WhereFound = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=35, nodefault};
	__property int WordCount = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=36, nodefault};
	__property int WordOffset = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=37, nodefault};
	__property Word AllowJoinedWords = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=38, nodefault};
	__property int DialogLeft = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=39, nodefault};
	__property int DialogTop = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=40, nodefault};
	__property Word ReplaceRecheck = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=41, nodefault};
	__property Graphics::TColor DialogBgColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=42, nodefault};
	__property int DialogLeftActual = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=43, nodefault};
	__property int DialogTopActual = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=44, nodefault};
	__property Word ReplaceOccurred = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=45, nodefault};
	__property Word SuggestionsMade = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=46, nodefault};
	__property short WordLength = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=47, nodefault};
	__property int CacheHits = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=48, nodefault};
	__property int CacheMisses = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=49, nodefault};
	__property int TimerTicks = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=50, nodefault};
	__property int UserData = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=51, nodefault};
	__property WideString CheckedWord = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=52};
	__property Word CommonIRListIsEnabled = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=53, nodefault};
	__property WideString WordMisspelledTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=54};
	__property WideString OptionsTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=55};
	__property WideString ErrorTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=56};
	__property WideString WordMisspelledHelpFile = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=57};
	__property WideString OptionsHelpFile = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=58};
	__property int DialogElements = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=59, nodefault};
	__property int DialogWidth = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=60, nodefault};
	__property int DialogHeight = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=61, nodefault};
	__property WideString ErrorText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=62};
	__property int ClickedButton = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=63, nodefault};
	__property int ClickInfo = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=64, nodefault};
	__property WideString ClickInfoText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=65};
	__property short AddToCommonIRList = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=66, nodefault};
	__property short BeginCheck = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=67, nodefault};
	__property WideString CheckText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=68};
	__property WideString CheckWord = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=69};
	__property short ClearCounts = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=70, nodefault};
	__property short ClearOffsets = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=71, nodefault};
	__property WideString FindSuggestions = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=72};
	__property short ReplaceLastWord = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=73, nodefault};
	__property short ResumeCheck = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=74, nodefault};
	__property short ClearSuggestions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=75, nodefault};
	__property short PopupError = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=76, nodefault};
	__property short PopupOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=77, nodefault};
	__property short PopupWordMisspelled = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=78, nodefault};
	__property WideString CreateCustom = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=79};
	__property short ResumeWithRecheck = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=80, nodefault};
	__property Word EnableCommonIRList = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=81, nodefault};
	__property short ClearCommonIRList = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=82, nodefault};
	__property WideString RemoveFromCommonIRList = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=83};
	__property short EnableEventOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=84, nodefault};
	__property short DisableEventOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=85, nodefault};
	__property short EnableSpellOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=86, nodefault};
	__property short DisableSpellOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=87, nodefault};
	__property short EnableSuggestOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=88, nodefault};
	__property short DisableSuggestOptions = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=89, nodefault};
	__property int EnableDialogElements = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=90, nodefault};
	__property int DisableDialogElements = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=91, nodefault};
	__property WideString _Text = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=0};
	__property WideString StandardDictionary = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=2};
	__property WideString CustomDictionary = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=3};
	__property TVSSpellMisspelled OnMisspelled = {read=FOnMisspelled, write=FOnMisspelled};
	__property TVSSpellComplete OnComplete = {read=FOnComplete, write=FOnComplete};
	__property TVSSpellFound OnFound = {read=FOnFound, write=FOnFound};
	__property TVSSpellBeforeReplace OnBeforeReplace = {read=FOnBeforeReplace, write=FOnBeforeReplace};
	__property TVSSpellAfterReplace OnAfterReplace = {read=FOnAfterReplace, write=FOnAfterReplace};
	__property TVSSpellAfterPopup OnAfterPopup = {read=FOnAfterPopup, write=FOnAfterPopup};
	__property TVSSpellCheckStatus OnCheckStatus = {read=FOnCheckStatus, write=FOnCheckStatus};
	__property TVSSpellCheckError OnCheckError = {read=FOnCheckError, write=FOnCheckError};
	__property TVSSpellClickIn OnClickIn = {read=FOnClickIn, write=FOnClickIn};
	__property TVSSpellClickOut OnClickOut = {read=FOnClickOut, write=FOnClickOut};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TVSSpell(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TVSSpell(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVSSpell(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID LIBID_VspelocxLib;
static const Word VSCAT_STANDARD = 0x100;
static const Word VSCAT_IRLIST = 0x100;
static const Word VSCAT_CUSTOM = 0x200;
static const Word VSCAT_ENABLED = 0x400;
static const Word VSCAT_DISABLED = 0x800;
static const Shortint VSDSTAT_ENABLED = 0x1;
static const Shortint VSDSTAT_LOADED = 0x2;
static const Shortint VSDSTAT_IRLIST_ENABLED = 0x4;
static const Shortint VSDSTAT_UPDATEABLE = 0x8;
static const Shortint VSDSTAT_READONLY = 0x10;
static const Shortint VSDSTAT_EXTENDED = 0x20;
static const Shortint VSDSTAT_HYPHENATION = 0x40;
static const Byte VSDSTAT_PHONETICS = 0x80;
static const Word VSDSTAT_COMMONLIST = 0x100;
static const Shortint VSLANG_AMERICAN = 0x0;
static const Shortint VSLANG_ENGLISH = 0x1;
static const Shortint VSLANG_FRENCH = 0x2;
static const Shortint VSLANG_GERMAN = 0x3;
static const Shortint VSLANG_SPANISH = 0x4;
static const Shortint VSLANG_PORTUGUESE = 0x5;
static const Shortint VSLANG_ITALIAN = 0x6;
static const Shortint VSLANG_DUTCH = 0x7;
static const Shortint VSLANG_SWEDISH = 0x8;
static const Shortint VSLANG_FINNISH = 0x9;
static const Shortint VSLANG_NORWEGIAN = 0xa;
static const Shortint VSLANG_LATIN = 0xb;
static const Shortint VSLANG_WELSH = 0xc;
static const Shortint VSLANG_POLISH = 0xd;
static const Shortint VSLANG_HUNGARIAN = 0xe;
static const Shortint VSLANG_FLEMISH = 0xf;
static const Shortint VSLANG_CZECH = 0x10;
static const Shortint VSLANG_ICELANDIC = 0x11;
static const Shortint VSLANG_ESPERANTO = 0x12;
static const Shortint VSLANG_CATALAN = 0x13;
static const Shortint VSLANG_ROMANIAN = 0x14;
static const Shortint VSLANG_BULGARIAN = 0x15;
static const Shortint VSLANG_RUSSIAN = 0x16;
static const Shortint VSLANG_QUECHUA = 0x17;
static const Shortint VSLANG_TURKISH = 0x18;
static const Shortint VSLANG_INDONESIAN = 0x19;
static const Shortint VSLANG_HEBREW = 0x1a;
static const Shortint VSLANG_DANISH = 0x1b;
static const Shortint VSLANG_CANADIAN = 0x1c;
static const Shortint VSEVOPT_COMPLETE = 0x1;
static const Shortint VSEVOPT_FOUND = 0x2;
static const Shortint VSEVOPT_MISSPELLED = 0x4;
static const Shortint VSEVOPT_BEFORE_REPLACE = 0x8;
static const Shortint VSEVOPT_AFTER_POPUP = 0x10;
static const Shortint VSEVOPT_CHECK_STATUS = 0x20;
static const Shortint VSEVOPT_CHECK_ERROR = 0x40;
static const Byte VSEVOPT_AFTER_REPLACE = 0x80;
static const Word VSEVOPT_CLICK_IN = 0x100;
static const Word VSEVOPT_CLICK_OUT = 0x200;
static const Word VSEVOPT_DEFAULTS = 0xfffd;
static const Shortint VSORDER_SCIR = 0x0;
static const Shortint VSORDER_CIRS = 0x2;
static const Shortint VSORDER_IRSC = 0x3;
static const Shortint VSORDER_SIRC = 0x4;
static const Shortint VSORDER_CSIR = 0x6;
static const Shortint VSORDER_IRCS = 0x7;
static const Shortint VSORDER_NO_LOOKAHEAD = 0x8;
static const Shortint VSOPT_AUTO_REPLACE = 0x1;
static const Shortint VSOPT_AUTO_SUGGEST = 0x2;
static const Shortint VSOPT_AUTO_POPUP = 0x4;
static const Shortint VSOPT_IGNORE_FULL_CAPS = 0x8;
static const Shortint VSOPT_IGNORE_PARTIAL_NUMBERS = 0x10;
static const Shortint VSOPT_MULTILINE = 0x20;
static const Shortint VSOPT_IGNORE_PURE_NUMBERS = 0x40;
static const Byte VSOPT_ALLOW_JOINED_WORDS = 0x80;
static const Word VSOPT_EXACT_MATCH = 0x100;
static const Word VSOPT_RETURN_EACH_WORD = 0x200;
static const Word VSOPT_REPLACE_RECHECK = 0x400;
static const Word VSOPT_DEFAULTS = 0x467;
static const Shortint VSSUGOPT_CAPITALIZATION = 0x1;
static const Shortint VSSUGOPT_CHARSWAP = 0x2;
static const Shortint VSSUGOPT_DELETES = 0x4;
static const Shortint VSSUGOPT_DOUBLES = 0x8;
static const Shortint VSSUGOPT_HYPHENS = 0x10;
static const Shortint VSSUGOPT_SPLITS = 0x20;
static const Shortint VSSUGOPT_EXCHANGES = 0x40;
static const Word VSSUGOPT_INSERTIONS = 0x200;
static const Word VSSUGOPT_DEFAULTS = 0x27f;
static const Shortint VSIR_GLOBAL = 0x1;
static const Shortint VSIR_PROMPT = 0x2;
static const Shortint VSIR_IGNORE = 0x4;
static const Shortint VSIR_REPLACE = 0x8;
static const Shortint VSIR_HYPHENATION = 0x10;
static const Shortint VSIR_SPELLED_OK = 0x5;
static const Shortint VSIR_REPLACE_ALL = 0x9;
static const Shortint VSIR_MISSPELLED = 0x6;
static const Shortint VSIR_PROMPT_REPLACE = 0xa;
static const Shortint VS_DEFAULT_HANDLING = 0x0;
static const Shortint VS_EVENT_HANDLED = 0x1;
static const Shortint VS_CANCEL_SPELLCHECK = 0x2;
static const Shortint VSCLICK_WORD_MISSPELLED_HELP = 0x1;
static const Shortint VSCLICK_OPTIONS = 0x2;
static const Shortint VSCLICK_PROMPT_REPLACE = 0x4;
static const Shortint VSCLICK_ADD_TO_CUSTOM = 0x8;
static const Shortint VSCLICK_REPLACE_ALL = 0x10;
static const Shortint VSCLICK_REPLACE = 0x20;
static const Shortint VSCLICK_IGNORE_ALL = 0x40;
static const Byte VSCLICK_IGNORE = 0x80;
static const Word VSCLICK_SUGGEST_NOT_FOUND = 0x100;
static const Word VSCLICK_SUGGEST_REPLACE_WITH = 0x200;
static const Word VSCLICK_CANCEL_SPELLCHECK = 0x400;
static const Word VSCLICK_THESAURUS = 0x800;
static const int VSCLICK_OPTIONS_HELP = 0x10000;
static const int VSCLICK_OPTIONS_OK = 0x20000;
static const int VSCLICK_OPTIONS_CANCEL = 0x40000;
static const int VSCLICK_OPEN_CUSTOM = 0x80000;
static const int VSCLICK_CLOSE_CUSTOM = 0x100000;
static const int VSCLICK_OPEN_STANDARD = 0x200000;
static const int VSCLICK_CLOSE_STANDARD = 0x400000;
static const int VSCLICK_THESAURUS_OK = 0x1000000;
static const int VSCLICK_THESAURUS_SEARCH = 0x2000000;
static const int VSCLICK_THESAURUS_CANCEL = 0x4000000;
static const int VSCLICK_THESAURUS_HELP = 0x8000000;
static const Shortint VSD_WORD_MISSPELLED_HELP = 0x1;
static const Shortint VSD_OPTIONS = 0x2;
static const Shortint VSD_PROMPT_REPLACE = 0x4;
static const Shortint VSD_ADD_TO_CUSTOM = 0x8;
static const Shortint VSD_REPLACE_ALL = 0x10;
static const Shortint VSD_REPLACE = 0x20;
static const Shortint VSD_IGNORE_ALL = 0x40;
static const Byte VSD_IGNORE = 0x80;
static const Word VSD_SUGGEST_NOT_FOUND = 0x100;
static const Word VSD_SUGGEST_REPLACE_WITH = 0x200;
static const Word VSD_CANCEL_SPELLCHECK = 0x400;
static const Word VSD_SUGGESTIONS_LIST = 0x800;
static const Word VSD_REPLACE_BOX = 0x1000;
static const Word VSD_CUSTOM_LIST = 0x2000;
static const Word VSD_THESAURUS = 0x4000;
static const int VSD_OPTIONS_HELP = 0x10000;
static const int VSD_CUSTOMS = 0x20000;
static const int VSD_STANDARDS = 0x40000;
static const int VSD_PERFORMANCE = 0x80000;
static const int VSD_SUGGESTION_LIMIT = 0x100000;
static const int VSD_AUTO_SUGGESTIONS = 0x200000;
static const int VSD_EXACT_MATCH = 0x400000;
static const int VSD_IGNORE_FULL_CAPS = 0x800000;
static const int VSD_IGNORE_PARTIAL = 0x1000000;
static const int VSD_IGNORE_PURE = 0x2000000;
static const int VSD_ALLOW_JOINED = 0x4000000;
static const int VSD_RECHECK = 0x8000000;
static const int VSD_THESAURUS_HELP = 0x10000000;
static const int VSD_THESAURUS_SEARCH = 0x20000000;
static const Shortint VSR_WORD_MISSPELLED = 0xffffffff;
static const Shortint VSR_IGNORE_REPLACE = 0xfffffffe;
static const Shortint VSR_CHECK_CANCELED = 0xfffffffd;
static const Shortint VSR_BREAK = 0xfffffffc;
static const Shortint VSR_FOUND = 0xfffffffb;
static const Shortint VSR_REPLACED = 0xfffffffa;
static const Shortint VSR_CHANGED = 0xfffffff9;
static const Shortint VSR_END_LIST = 0xfffffff8;
static const Shortint VSR_ENTRY_NOT_FOUND = 0xfffffff7;
static const Shortint VSR_OPENED_READONLY = 0xfffffff5;
static const Shortint VSR_REPLACE_OVERFLOW = 0xfffffff4;
static const Shortint VSR_NOT_ADDED = 0xfffffff3;
static const Shortint VSR_POPPED = 0xfffffff2;
static const Shortint VSR_CLICK_IN = 0xfffffff1;
static const Shortint VSR_CLICK_OUT = 0xfffffff0;
static const Shortint VSR_NO_ERROR = 0x0;
static const Shortint VSR_WORD_TOO_LONG = 0x1;
static const Shortint VSR_NO_MISSPELL = 0x2;
static const Shortint VSR_ALREADY_OPEN = 0x4;
static const Shortint VSR_OPEN_FAILED = 0x5;
static const Shortint VSR_CREATE_FAILED = 0x6;
static const Shortint VSR_INVALID_DICTIONARY = 0x7;
static const Shortint VSR_WRITE_FAILURE = 0x9;
static const Shortint VSR_READ_FAILURE = 0xa;
static const Shortint VSR_BAD_FILE_NAME = 0xb;
static const Shortint VSR_NOT_UPDATEABLE = 0xc;
static const Shortint VSR_DUPLICATE_WORD = 0xd;
static const Shortint VSR_BAD_CUSTOM = 0xe;
static const Shortint VSR_IN_EVENT = 0xf;
static const Shortint VSR_NOT_LOADED = 0x10;
static const Shortint VSR_REPLACE_ERROR = 0x11;
static const Shortint VSR_CACHE_ERROR = 0x12;
static const Shortint VSR_INVALID_CONTEXT = 0x13;
static const Shortint VSR_NOTHING_TO_CHECK = 0x14;
static const Shortint VSR_DIALOG_ERROR = 0x15;
static const Shortint VSR_OUT_OF_MEMORY = 0x16;
static const Shortint VSR_BAD_INDEX = 0x17;
static const Shortint VSR_OUT_OF_STRING_SPACE = 0x18;
static const Shortint VSR_IN_DIALOG = 0x19;
static const Shortint VSR_FILE_EXISTS = 0x1a;
static const Word VB_OFFSET = 0x7e5e;
static const Word VBR_WORD_TOO_LONG = 0x7e5f;
static const Word VBR_NO_MISSPELL = 0x7e60;
static const Word VBR_ALREADY_OPEN = 0x7e62;
static const Word VBR_OPEN_FAILED = 0x7e63;
static const Word VBR_CREATE_FAILED = 0x7e64;
static const Word VBR_INVALID_DICTIONARY = 0x7e65;
static const Word VBR_WRITE_FAILURE = 0x7e67;
static const Word VBR_READ_FAILURE = 0x7e68;
static const Word VBR_BAD_FILE_NAME = 0x7e69;
static const Word VBR_NOT_UPDATEABLE = 0x7e6a;
static const Word VBR_DUPLICATE_WORD = 0x7e6b;
static const Word VBR_BAD_CUSTOM = 0x7e6c;
static const Word VBR_IN_EVENT = 0x7e6d;
static const Word VBR_NOT_LOADED = 0x7e6e;
static const Word VBR_REPLACE_ERROR = 0x7e6f;
static const Word VBR_CACHE_ERROR = 0x7e70;
static const Word VBR_INVALID_CONTEXT = 0x7e71;
static const Word VBR_NOTHING_TO_CHECK = 0x7e72;
static const Word VBR_DIALOG_ERROR = 0x7e73;
static const Word VBR_OUT_OF_MEMORY = 0x7e74;
static const Word VBR_BAD_INDEX = 0x7e75;
static const Word VBR_OUT_OF_STRING_SPACE = 0x7e76;
static const Word VBR_IN_DIALOG = 0x7e77;
static const Word VBR_FILE_EXISTS = 0x7e78;
static const Shortint VS_ALL = 0x0;
static const Shortint VS_MAXWORDSIZE = 0x4b;
extern PACKAGE GUID Class_VSSpell;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Vcspell3 */
using namespace Vcspell3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCSpell3
