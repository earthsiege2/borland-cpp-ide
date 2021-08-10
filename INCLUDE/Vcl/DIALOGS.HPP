// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dialogs.pas' rev: 5.00

#ifndef DialogsHPP
#define DialogsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ShlObj.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <CommDlg.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dialogs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCommonDialog;
class PASCALIMPLEMENTATION TCommonDialog : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FCtl3D;
	void *FDefWndProc;
	Classes::THelpContext FHelpContext;
	HWND FHandle;
	void *FObjectInstance;
	char *FTemplate;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMInitDialog(Messages::TWMInitDialog &Message);
	MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual bool __fastcall MessageHook(Messages::TMessage &Msg);
	virtual BOOL __fastcall TaskModalDialog(void * DialogFunc, void *DialogData);
	virtual bool __fastcall Execute(void) = 0 ;
	__property char * Template = {read=FTemplate, write=FTemplate};
	
public:
	__fastcall virtual TCommonDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TCommonDialog(void);
	virtual void __fastcall DefaultHandler(void *Message);
	__property HWND Handle = {read=FHandle, nodefault};
	
__published:
	__property bool Ctl3D = {read=FCtl3D, write=FCtl3D, default=1};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
};


#pragma option push -b-
enum TOpenOption { ofReadOnly, ofOverwritePrompt, ofHideReadOnly, ofNoChangeDir, ofShowHelp, ofNoValidate, 
	ofAllowMultiSelect, ofExtensionDifferent, ofPathMustExist, ofFileMustExist, ofCreatePrompt, ofShareAware, 
	ofNoReadOnlyReturn, ofNoTestFileCreate, ofNoNetworkButton, ofNoLongNames, ofOldStyleDialog, ofNoDereferenceLinks, 
	ofEnableIncludeNotify, ofEnableSizing };
#pragma option pop

typedef Set<TOpenOption, ofReadOnly, ofEnableSizing>  TOpenOptions;

#pragma option push -b-
enum TFileEditStyle { fsEdit, fsComboBox };
#pragma option pop

typedef void __fastcall (__closure *TIncludeItemEvent)(const Commdlg::TOFNotifyEx &OFN, bool &Include
	);

class DELPHICLASS TOpenDialog;
class PASCALIMPLEMENTATION TOpenDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
private:
	Classes::TStrings* FHistoryList;
	TOpenOptions FOptions;
	AnsiString FFilter;
	int FFilterIndex;
	int FCurrentFilterIndex;
	AnsiString FInitialDir;
	AnsiString FTitle;
	AnsiString FDefaultExt;
	AnsiString FFileName;
	Classes::TStrings* FFiles;
	TFileEditStyle FFileEditStyle;
	Classes::TNotifyEvent FOnSelectionChange;
	Classes::TNotifyEvent FOnFolderChange;
	Classes::TNotifyEvent FOnTypeChange;
	Forms::TCloseQueryEvent FOnCanClose;
	TIncludeItemEvent FOnIncludeItem;
	AnsiString __fastcall GetFileName();
	int __fastcall GetFilterIndex(void);
	void __fastcall ReadFileEditStyle(Classes::TReader* Reader);
	void __fastcall SetHistoryList(Classes::TStrings* Value);
	void __fastcall SetInitialDir(const AnsiString Value);
	
protected:
	bool __fastcall CanClose(tagOFNA &OpenFileName);
	DYNAMIC bool __fastcall DoCanClose(void);
	BOOL __fastcall DoExecute(void * Func);
	DYNAMIC void __fastcall DoSelectionChange(void);
	DYNAMIC void __fastcall DoFolderChange(void);
	DYNAMIC void __fastcall DoTypeChange(void);
	DYNAMIC void __fastcall DoIncludeItem(const Commdlg::TOFNotifyEx &OFN, bool &Include);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall GetFileNames(tagOFNA &OpenFileName);
	virtual Windows::TRect __fastcall GetStaticRect();
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TOpenDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TOpenDialog(void);
	virtual bool __fastcall Execute(void);
	__property TFileEditStyle FileEditStyle = {read=FFileEditStyle, write=FFileEditStyle, nodefault};
	__property Classes::TStrings* Files = {read=FFiles};
	__property Classes::TStrings* HistoryList = {read=FHistoryList, write=SetHistoryList};
	
__published:
	__property AnsiString DefaultExt = {read=FDefaultExt, write=FDefaultExt};
	__property AnsiString FileName = {read=GetFileName, write=FFileName};
	__property AnsiString Filter = {read=FFilter, write=FFilter};
	__property int FilterIndex = {read=GetFilterIndex, write=FFilterIndex, default=1};
	__property AnsiString InitialDir = {read=FInitialDir, write=SetInitialDir};
	__property TOpenOptions Options = {read=FOptions, write=FOptions, default=524292};
	__property AnsiString Title = {read=FTitle, write=FTitle};
	__property Forms::TCloseQueryEvent OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property Classes::TNotifyEvent OnFolderChange = {read=FOnFolderChange, write=FOnFolderChange};
	__property Classes::TNotifyEvent OnSelectionChange = {read=FOnSelectionChange, write=FOnSelectionChange
		};
	__property Classes::TNotifyEvent OnTypeChange = {read=FOnTypeChange, write=FOnTypeChange};
	__property TIncludeItemEvent OnIncludeItem = {read=FOnIncludeItem, write=FOnIncludeItem};
};


class DELPHICLASS TSaveDialog;
class PASCALIMPLEMENTATION TSaveDialog : public TOpenDialog 
{
	typedef TOpenDialog inherited;
	
__published:
	virtual bool __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TOpenDialog.Create */ inline __fastcall virtual TSaveDialog(Classes::TComponent* AOwner) : TOpenDialog(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOpenDialog.Destroy */ inline __fastcall virtual ~TSaveDialog(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TColorDialogOption { cdFullOpen, cdPreventFullOpen, cdShowHelp, cdSolidColor, cdAnyColor };
#pragma option pop

typedef Set<TColorDialogOption, cdFullOpen, cdAnyColor>  TColorDialogOptions;

typedef int TCustomColors[16];

class DELPHICLASS TColorDialog;
class PASCALIMPLEMENTATION TColorDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
private:
	Graphics::TColor FColor;
	TColorDialogOptions FOptions;
	Classes::TStrings* FCustomColors;
	void __fastcall SetCustomColors(Classes::TStrings* Value);
	
public:
	__fastcall virtual TColorDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TColorDialog(void);
	virtual bool __fastcall Execute(void);
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=FColor, default=0};
	__property Ctl3D ;
	__property Classes::TStrings* CustomColors = {read=FCustomColors, write=SetCustomColors};
	__property TColorDialogOptions Options = {read=FOptions, write=FOptions, default=0};
};


#pragma option push -b-
enum TFontDialogOption { fdAnsiOnly, fdTrueTypeOnly, fdEffects, fdFixedPitchOnly, fdForceFontExist, 
	fdNoFaceSel, fdNoOEMFonts, fdNoSimulations, fdNoSizeSel, fdNoStyleSel, fdNoVectorFonts, fdShowHelp, 
	fdWysiwyg, fdLimitSize, fdScalableOnly, fdApplyButton };
#pragma option pop

typedef Set<TFontDialogOption, fdAnsiOnly, fdApplyButton>  TFontDialogOptions;

#pragma option push -b-
enum TFontDialogDevice { fdScreen, fdPrinter, fdBoth };
#pragma option pop

typedef void __fastcall (__closure *TFDApplyEvent)(System::TObject* Sender, HWND Wnd);

class DELPHICLASS TFontDialog;
class PASCALIMPLEMENTATION TFontDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
private:
	Graphics::TFont* FFont;
	TFontDialogDevice FDevice;
	TFontDialogOptions FOptions;
	TFDApplyEvent FOnApply;
	int FMinFontSize;
	int FMaxFontSize;
	bool FFontCharsetModified;
	bool FFontColorModified;
	void __fastcall DoApply(HWND Wnd);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall UpdateFromLogFont(const tagLOGFONTA &LogFont);
	
protected:
	DYNAMIC void __fastcall Apply(HWND Wnd);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TFontDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TFontDialog(void);
	virtual bool __fastcall Execute(void);
	
__published:
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property TFontDialogDevice Device = {read=FDevice, write=FDevice, default=0};
	__property int MinFontSize = {read=FMinFontSize, write=FMinFontSize, nodefault};
	__property int MaxFontSize = {read=FMaxFontSize, write=FMaxFontSize, nodefault};
	__property TFontDialogOptions Options = {read=FOptions, write=FOptions, default=4};
	__property TFDApplyEvent OnApply = {read=FOnApply, write=FOnApply};
};


class DELPHICLASS TPrinterSetupDialog;
class PASCALIMPLEMENTATION TPrinterSetupDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
public:
	virtual bool __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TCommonDialog.Create */ inline __fastcall virtual TPrinterSetupDialog(Classes::TComponent* AOwner
		) : TCommonDialog(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCommonDialog.Destroy */ inline __fastcall virtual ~TPrinterSetupDialog(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPrintRange { prAllPages, prSelection, prPageNums };
#pragma option pop

#pragma option push -b-
enum TPrintDialogOption { poPrintToFile, poPageNums, poSelection, poWarning, poHelp, poDisablePrintToFile 
	};
#pragma option pop

typedef Set<TPrintDialogOption, poPrintToFile, poDisablePrintToFile>  TPrintDialogOptions;

class DELPHICLASS TPrintDialog;
class PASCALIMPLEMENTATION TPrintDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
private:
	int FFromPage;
	int FToPage;
	bool FCollate;
	TPrintDialogOptions FOptions;
	bool FPrintToFile;
	TPrintRange FPrintRange;
	int FMinPage;
	int FMaxPage;
	int FCopies;
	void __fastcall SetNumCopies(int Value);
	
public:
	virtual bool __fastcall Execute(void);
	
__published:
	__property bool Collate = {read=FCollate, write=FCollate, default=0};
	__property int Copies = {read=FCopies, write=SetNumCopies, default=0};
	__property int FromPage = {read=FFromPage, write=FFromPage, default=0};
	__property int MinPage = {read=FMinPage, write=FMinPage, default=0};
	__property int MaxPage = {read=FMaxPage, write=FMaxPage, default=0};
	__property TPrintDialogOptions Options = {read=FOptions, write=FOptions, default=0};
	__property bool PrintToFile = {read=FPrintToFile, write=FPrintToFile, default=0};
	__property TPrintRange PrintRange = {read=FPrintRange, write=FPrintRange, default=0};
	__property int ToPage = {read=FToPage, write=FToPage, default=0};
public:
	#pragma option push -w-inl
	/* TCommonDialog.Create */ inline __fastcall virtual TPrintDialog(Classes::TComponent* AOwner) : TCommonDialog(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCommonDialog.Destroy */ inline __fastcall virtual ~TPrintDialog(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFindOption { frDown, frFindNext, frHideMatchCase, frHideWholeWord, frHideUpDown, frMatchCase, 
	frDisableMatchCase, frDisableUpDown, frDisableWholeWord, frReplace, frReplaceAll, frWholeWord, frShowHelp 
	};
#pragma option pop

typedef Set<TFindOption, frDown, frShowHelp>  TFindOptions;

typedef HWND __stdcall (*TFindReplaceFunc)(tagFINDREPLACEA &FindReplace);

class DELPHICLASS TFindDialog;
class PASCALIMPLEMENTATION TFindDialog : public TCommonDialog 
{
	typedef TCommonDialog inherited;
	
private:
	TFindOptions FOptions;
	Windows::TPoint FPosition;
	TFindReplaceFunc FFindReplaceFunc;
	Controls::TWinControl* FRedirector;
	Classes::TNotifyEvent FOnFind;
	Classes::TNotifyEvent FOnReplace;
	HWND FFindHandle;
	#pragma pack(push, 1)
	tagFINDREPLACEA FFindReplace;
	#pragma pack(pop)
	
	char FFindText[256];
	char FReplaceText[256];
	AnsiString __fastcall GetFindText();
	int __fastcall GetLeft(void);
	Windows::TPoint __fastcall GetPosition();
	AnsiString __fastcall GetReplaceText();
	int __fastcall GetTop(void);
	void __fastcall SetFindText(const AnsiString Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetPosition(const Windows::TPoint &Value);
	void __fastcall SetReplaceText(const AnsiString Value);
	void __fastcall SetTop(int Value);
	__property AnsiString ReplaceText = {read=GetReplaceText, write=SetReplaceText};
	__property Classes::TNotifyEvent OnReplace = {read=FOnReplace, write=FOnReplace};
	
protected:
	virtual bool __fastcall MessageHook(Messages::TMessage &Msg);
	DYNAMIC void __fastcall Find(void);
	DYNAMIC void __fastcall Replace(void);
	
public:
	__fastcall virtual TFindDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TFindDialog(void);
	void __fastcall CloseDialog(void);
	virtual bool __fastcall Execute(void);
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property Windows::TPoint Position = {read=GetPosition, write=SetPosition};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	
__published:
	__property AnsiString FindText = {read=GetFindText, write=SetFindText};
	__property TFindOptions Options = {read=FOptions, write=FOptions, default=1};
	__property Classes::TNotifyEvent OnFind = {read=FOnFind, write=FOnFind};
};


class DELPHICLASS TReplaceDialog;
class PASCALIMPLEMENTATION TReplaceDialog : public TFindDialog 
{
	typedef TFindDialog inherited;
	
public:
	__fastcall virtual TReplaceDialog(Classes::TComponent* AOwner);
	
__published:
	__property ReplaceText ;
	__property OnReplace ;
public:
	#pragma option push -w-inl
	/* TFindDialog.Destroy */ inline __fastcall virtual ~TReplaceDialog(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMsgDlgType { mtWarning, mtError, mtInformation, mtConfirmation, mtCustom };
#pragma option pop

#pragma option push -b-
enum TMsgDlgBtn { mbYes, mbNo, mbOK, mbCancel, mbAbort, mbRetry, mbIgnore, mbAll, mbNoToAll, mbYesToAll, 
	mbHelp };
#pragma option pop

typedef Set<TMsgDlgBtn, mbYes, mbHelp>  TMsgDlgButtons;

//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxCustomColors = 0x10;
#define mbYesNoCancel (System::Set<TMsgDlgBtn, mbYes, mbHelp> () )
#define mbOKCancel (System::Set<TMsgDlgBtn, mbYes, mbHelp> () )
#define mbAbortRetryIgnore (System::Set<TMsgDlgBtn, mbYes, mbHelp> () )
extern PACKAGE bool ForceCurrentDirectory;
extern PACKAGE Forms::TForm* __fastcall CreateMessageDialog(const AnsiString Msg, TMsgDlgType DlgType
	, TMsgDlgButtons Buttons);
extern PACKAGE int __fastcall MessageDlg(const AnsiString Msg, TMsgDlgType DlgType, TMsgDlgButtons Buttons
	, int HelpCtx);
extern PACKAGE int __fastcall MessageDlgPos(const AnsiString Msg, TMsgDlgType DlgType, TMsgDlgButtons 
	Buttons, int HelpCtx, int X, int Y);
extern PACKAGE int __fastcall MessageDlgPosHelp(const AnsiString Msg, TMsgDlgType DlgType, TMsgDlgButtons 
	Buttons, int HelpCtx, int X, int Y, const AnsiString HelpFileName);
extern PACKAGE void __fastcall ShowMessage(const AnsiString Msg);
extern PACKAGE void __fastcall ShowMessageFmt(const AnsiString Msg, const System::TVarRec * Params, 
	const int Params_Size);
extern PACKAGE void __fastcall ShowMessagePos(const AnsiString Msg, int X, int Y);
extern PACKAGE bool __fastcall InputQuery(const AnsiString ACaption, const AnsiString APrompt, AnsiString 
	&Value);
extern PACKAGE AnsiString __fastcall InputBox(const AnsiString ACaption, const AnsiString APrompt, const 
	AnsiString ADefault);

}	/* namespace Dialogs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dialogs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dialogs
