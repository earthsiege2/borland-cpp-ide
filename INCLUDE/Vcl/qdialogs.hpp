// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QDialogs.pas' rev: 6.00

#ifndef QDialogsHPP
#define QDialogsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QExtCtrls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <CommDlg.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <ShlObj.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qdialogs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EQtDialogException;
class PASCALIMPLEMENTATION EQtDialogException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EQtDialogException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EQtDialogException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EQtDialogException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EQtDialogException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EQtDialogException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EQtDialogException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EQtDialogException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EQtDialogException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EQtDialogException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDialog;
class PASCALIMPLEMENTATION TDialog : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::THelpType FHelpType;
	Classes::THelpContext FHelpContext;
	AnsiString FHelpKeyword;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	bool FModal;
	#pragma pack(push, 1)
	Types::TPoint FPosition;
	#pragma pack(pop)
	
	int FWidth;
	int FHeight;
	WideString FTitle;
	bool FShowing;
	Qcontrols::TScalingFlags FScaleFlags;
	void __fastcall SetPosition(const Types::TPoint &Value);
	Types::TPoint __fastcall GetPosition();
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	DYNAMIC void __fastcall DoClose(void);
	virtual bool __fastcall DoExecute(void) = 0 ;
	DYNAMIC void __fastcall DoShow(void);
	virtual Types::TRect __fastcall GetBounds(void) = 0 ;
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight) = 0 ;
	virtual void __fastcall SetTitle(const WideString Value);
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property bool Modal = {read=FModal, write=FModal, nodefault};
	__property Types::TPoint Position = {read=GetPosition, write=SetPosition};
	__property WideString Title = {read=FTitle, write=SetTitle};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	
public:
	virtual bool __fastcall Execute(void);
	
__published:
	__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, default=0};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=FHelpKeyword};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TDialog(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TDialog(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQtDialog;
class PASCALIMPLEMENTATION TQtDialog : public TDialog 
{
	typedef TDialog inherited;
	
private:
	Qt::QObject_hookH* FHooks;
	Qt::QDialogH* FHandle;
	bool FUseNative;
	int FNativeFlags;
	Qt::QDialogH* __fastcall GetHandle(void);
	void __fastcall CreateHandle(void);
	void __cdecl DestroyedHook(void);
	void __fastcall HandleNeeded(void);
	void __fastcall InvokeHelp(void);
	Qt::QObject_hookH* __fastcall GetHooks(void);
	
protected:
	virtual bool __cdecl AppEventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall CreateWidget(void);
	void __fastcall DestroyWidget(void);
	virtual void __fastcall InitWidget(void);
	virtual Types::TRect __fastcall GetBounds();
	virtual void __fastcall HookEvents(void);
	virtual bool __fastcall DoExecute(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual bool __fastcall NativeExecute(int Flags);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetTitle(const WideString Value);
	virtual bool __cdecl EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual int __fastcall WidgetFlags(void);
	__property Qt::QObject_hookH* Hooks = {read=GetHooks, write=FHooks};
	
public:
	__fastcall virtual TQtDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TQtDialog(void);
	virtual bool __fastcall Execute(void);
	bool __fastcall HandleAllocated(void);
	__property Qt::QDialogH* Handle = {read=GetHandle};
	__property Position ;
	
__published:
	__property Height  = {default=0};
	__property int NativeFlags = {read=FNativeFlags, write=FNativeFlags, default=0};
	__property bool UseNativeDialog = {read=FUseNative, write=FUseNative, default=1};
	__property Width  = {default=0};
};


#pragma option push -b-
enum TOpenOption { ofShowHidden, ofOverwritePrompt, ofNoChangeDir, ofAllowMultiSelect, ofExtensionDifferent, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofViewDetail };
#pragma option pop

typedef Set<TOpenOption, ofShowHidden, ofViewDetail>  TOpenOptions;

typedef void __fastcall (__closure *TFileAddEvent)(System::TObject* Sender, const AnsiString Filename, const bool Readable, const bool Writeable, const bool Executable, bool &CanAdd);

typedef void __fastcall (__closure *TFileSelectEvent)(System::TObject* Sender, const AnsiString Filename);

typedef void __fastcall (__closure *TDirChangeEvent)(System::TObject* Sender, const AnsiString Dir);

class DELPHICLASS TOpenDialog;
class PASCALIMPLEMENTATION TOpenDialog : public TQtDialog 
{
	typedef TQtDialog inherited;
	
private:
	Classes::TStrings* FHistoryList;
	AnsiString FFilter;
	AnsiString FInitialDir;
	AnsiString FSaveDir;
	AnsiString FDefaultExt;
	AnsiString FFileName;
	Classes::TStrings* FFiles;
	int FFilterIndex;
	TOpenOptions FOptions;
	Classes::TStringList* FTempFiles;
	AnsiString FTempFilename;
	TFileAddEvent FOnFileAdd;
	TDirChangeEvent FOnFolderChange;
	TFileSelectEvent FOnSelected;
	Qforms::TCloseQueryEvent FOnCanClose;
	void __cdecl CanCloseHook(System::PBoolean canClose);
	void __cdecl DirEnteredHook(System::PWideString P1);
	void __cdecl FileAddHook(System::PAnsiString Filename, const bool Readable, const bool Writeable, const bool Executable, bool &CanAdd);
	void __cdecl FilterChangedHook(int Index);
	HIDESBASE Qt::QClxFileDialogH* __fastcall GetHandle(void);
	void __cdecl FileHighlightedHook(System::PWideString P1);
	void __fastcall SetHistoryList(Classes::TStrings* Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoCanClose(bool &CanClose);
	virtual bool __fastcall DoExecute(void);
	virtual bool __fastcall DoFileAdd(const AnsiString Filename, const bool Readable, const bool Writeable, const bool Executable);
	DYNAMIC void __fastcall DoFolderChange(const AnsiString Dir);
	DYNAMIC void __fastcall DoSelected(const AnsiString Filename);
	virtual void __fastcall HookEvents(void);
	virtual bool __fastcall NativeExecute(int Flags);
	virtual void __fastcall SetOptions(void);
	virtual void __fastcall RetrieveOptions(void);
	virtual int __fastcall WidgetFlags(void);
	
public:
	__fastcall virtual TOpenDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TOpenDialog(void);
	void __fastcall Refresh(void);
	__property Classes::TStrings* Files = {read=FFiles};
	__property Qt::QClxFileDialogH* Handle = {read=GetHandle};
	__property Classes::TStrings* HistoryList = {read=FHistoryList, write=SetHistoryList};
	
__published:
	__property AnsiString DefaultExt = {read=FDefaultExt, write=FDefaultExt};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property AnsiString Filter = {read=FFilter, write=FFilter};
	__property int FilterIndex = {read=FFilterIndex, write=FFilterIndex, default=1};
	__property AnsiString InitialDir = {read=FInitialDir, write=FInitialDir};
	__property TOpenOptions Options = {read=FOptions, write=FOptions, default=128};
	__property Height  = {default=350};
	__property Title ;
	__property Width  = {default=550};
	__property OnClose ;
	__property Qforms::TCloseQueryEvent OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property TFileAddEvent OnFileAdd = {read=FOnFileAdd, write=FOnFileAdd};
	__property TDirChangeEvent OnFolderChange = {read=FOnFolderChange, write=FOnFolderChange};
	__property TFileSelectEvent OnSelected = {read=FOnSelected, write=FOnSelected};
	__property OnShow ;
};


class DELPHICLASS TSaveDialog;
class PASCALIMPLEMENTATION TSaveDialog : public TOpenDialog 
{
	typedef TOpenDialog inherited;
	
protected:
	virtual bool __fastcall NativeExecute(int Flags);
	virtual void __fastcall SetOptions(void);
	
public:
	__fastcall virtual TSaveDialog(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TOpenDialog.Destroy */ inline __fastcall virtual ~TSaveDialog(void) { }
	#pragma option pop
	
};


typedef int TCustomColors[16];

class DELPHICLASS TColorDialog;
class PASCALIMPLEMENTATION TColorDialog : public TQtDialog 
{
	typedef TQtDialog inherited;
	
private:
	Qgraphics::TColor FColor;
	Classes::TStrings* FCustomColors;
	void __fastcall SetCustomColors(Classes::TStrings* Value);
	
protected:
	virtual bool __fastcall DoExecute(void);
	virtual bool __fastcall NativeExecute(int Flags);
	
public:
	__fastcall virtual TColorDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TColorDialog(void);
	
__published:
	__property Qgraphics::TColor Color = {read=FColor, write=FColor, default=0};
	__property Classes::TStrings* CustomColors = {read=FCustomColors, write=SetCustomColors};
};


class DELPHICLASS TFontDialog;
class PASCALIMPLEMENTATION TFontDialog : public TQtDialog 
{
	typedef TQtDialog inherited;
	
private:
	Qgraphics::TFont* FFont;
	void __fastcall SetFont(Qgraphics::TFont* Value);
	
protected:
	virtual bool __fastcall DoExecute(void);
	virtual bool __fastcall NativeExecute(int Flags);
	
public:
	__fastcall virtual TFontDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TFontDialog(void);
	
__published:
	__property Qgraphics::TFont* Font = {read=FFont, write=SetFont};
};


class DELPHICLASS TDialogForm;
class DELPHICLASS TCustomDialog;
class PASCALIMPLEMENTATION TCustomDialog : public TDialog 
{
	typedef TDialog inherited;
	
private:
	TDialogForm* FForm;
	void __fastcall Close(System::TObject* Sender, Qforms::TCloseAction &Action);
	
protected:
	virtual TDialogForm* __fastcall CreateForm(void) = 0 ;
	virtual bool __fastcall DoExecute(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall DoClose(void);
	virtual Types::TRect __fastcall GetBounds();
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetTitle(const WideString Value);
	
public:
	virtual bool __fastcall Execute(void);
	void __fastcall InvokeHelp(void);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomDialog(Classes::TComponent* AOwner) : TDialog(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomDialog(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDialogForm : public Qforms::TCustomForm 
{
	typedef Qforms::TCustomForm inherited;
	
private:
	TCustomDialog* FDialog;
	
public:
	virtual void __fastcall InvokeHelp(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDialogForm(Classes::TComponent* AOwner) : Qforms::TCustomForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDialogForm(Classes::TComponent* AOwner, int Dummy) : Qforms::TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDialogForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDialogForm(Qt::QWidgetH* ParentWidget) : Qforms::TCustomForm(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFindOption { frDown, frFindNext, frHideMatchCase, frHideWholeWord, frHideUpDown, frMatchCase, frDisableMatchCase, frDisableUpDown, frDisableWholeWord, frReplace, frReplaceAll, frWholeWord, frShowHelp };
#pragma option pop

typedef Set<TFindOption, frDown, frShowHelp>  TFindOptions;

class DELPHICLASS TFindDialogForm;
class PASCALIMPLEMENTATION TFindDialogForm : public TDialogForm 
{
	typedef TDialogForm inherited;
	
private:
	Qstdctrls::TEdit* FindEdit;
	Qstdctrls::TLabel* FindLabel;
	Qstdctrls::TCheckBox* WholeWord;
	Qstdctrls::TCheckBox* MatchCase;
	Qextctrls::TRadioGroup* Direction;
	Qstdctrls::TButton* FindNext;
	Qstdctrls::TButton* Cancel;
	Qstdctrls::TButton* Help;
	#pragma pack(push, 1)
	Types::TPoint DialogUnits;
	#pragma pack(pop)
	
	
protected:
	virtual void __fastcall ButtonPress(System::TObject* Sender);
	void __fastcall CheckboxCheck(System::TObject* Sender);
	void __fastcall DirectionClick(System::TObject* Sender);
	virtual void __fastcall EditChanged(System::TObject* Sender);
	void __fastcall SetDialogOption(TFindOption Option, bool Value);
	
public:
	__fastcall virtual TFindDialogForm(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFindDialogForm(Classes::TComponent* AOwner, int Dummy) : TDialogForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFindDialogForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TFindDialogForm(Qt::QWidgetH* ParentWidget) : TDialogForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TFindDialog;
class PASCALIMPLEMENTATION TFindDialog : public TCustomDialog 
{
	typedef TCustomDialog inherited;
	
private:
	TFindOptions FOptions;
	Classes::TNotifyEvent FOnFind;
	WideString FFindText;
	void __fastcall SetFindText(const WideString Value);
	
protected:
	virtual TDialogForm* __fastcall CreateForm(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall Find(void);
	
public:
	__fastcall virtual TFindDialog(Classes::TComponent* AOwner);
	__property Position ;
	
__published:
	__property WideString FindText = {read=FFindText, write=SetFindText};
	__property TFindOptions Options = {read=FOptions, write=FOptions, default=1};
	__property Title ;
	__property OnClose ;
	__property Classes::TNotifyEvent OnFind = {read=FOnFind, write=FOnFind};
	__property OnShow ;
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TFindDialog(void) { }
	#pragma option pop
	
};


class DELPHICLASS TReplaceDialogForm;
class PASCALIMPLEMENTATION TReplaceDialogForm : public TFindDialogForm 
{
	typedef TFindDialogForm inherited;
	
private:
	Qstdctrls::TButton* ReplaceBtn;
	Qstdctrls::TButton* ReplaceAll;
	Qstdctrls::TEdit* ReplaceEdit;
	Qstdctrls::TLabel* ReplaceLabel;
	
protected:
	virtual void __fastcall EditChanged(System::TObject* Sender);
	virtual void __fastcall ButtonPress(System::TObject* Sender);
	
public:
	__fastcall virtual TReplaceDialogForm(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TReplaceDialogForm(Classes::TComponent* AOwner, int Dummy) : TFindDialogForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TReplaceDialogForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TReplaceDialogForm(Qt::QWidgetH* ParentWidget) : TFindDialogForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TReplaceDialog;
class PASCALIMPLEMENTATION TReplaceDialog : public TFindDialog 
{
	typedef TFindDialog inherited;
	
private:
	WideString FReplaceText;
	Classes::TNotifyEvent FOnReplace;
	void __fastcall SetReplaceText(const WideString Value);
	
protected:
	virtual TDialogForm* __fastcall CreateForm(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall Replace(void);
	
public:
	__fastcall virtual TReplaceDialog(Classes::TComponent* AOwner);
	
__published:
	__property WideString ReplaceText = {read=FReplaceText, write=SetReplaceText};
	__property Classes::TNotifyEvent OnReplace = {read=FOnReplace, write=FOnReplace};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TReplaceDialog(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMsgDlgType { mtCustom, mtInformation, mtWarning, mtError, mtConfirmation };
#pragma option pop

#pragma option push -b-
enum TMsgDlgBtn { mbNone, mbOk, mbCancel, mbYes, mbNo, mbAbort, mbRetry, mbIgnore };
#pragma option pop

typedef Set<TMsgDlgBtn, mbNone, mbIgnore>  TMsgDlgButtons;

//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxCustomColors = 0x10;
#define mbYesNoCancel (System::Set<TMsgDlgBtn, mbNone, mbIgnore> () << TMsgDlgBtn(2) << TMsgDlgBtn(3) << TMsgDlgBtn(4) )
#define mbYesNo (System::Set<TMsgDlgBtn, mbNone, mbIgnore> () << TMsgDlgBtn(3) << TMsgDlgBtn(4) )
#define mbOKCancel (System::Set<TMsgDlgBtn, mbNone, mbIgnore> () << TMsgDlgBtn(1) << TMsgDlgBtn(2) )
#define mbAbortRetryIgnore (System::Set<TMsgDlgBtn, mbNone, mbIgnore> () << TMsgDlgBtn(5) << TMsgDlgBtn(6) << TMsgDlgBtn(7) )
extern PACKAGE bool __fastcall SelectDirectory(const AnsiString Caption, const WideString Root, /* out */ AnsiString &Directory);
extern PACKAGE int __fastcall MessageDlg(const WideString Caption, const WideString Msg, TMsgDlgType DlgType, TMsgDlgBtn Button1, TMsgDlgBtn Button2, TMsgDlgBtn Button3, int HelpCtx, int X, int Y, TMsgDlgBtn DefaultBtn = (TMsgDlgBtn)(0x0), Qgraphics::TBitmap* Bitmap = (Qgraphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE int __fastcall MessageDlg(const WideString Caption, const WideString Msg, TMsgDlgType DlgType, TMsgDlgButtons Buttons, int HelpCtx, int X, int Y, TMsgDlgBtn DefaultBtn = (TMsgDlgBtn)(0x0), Qgraphics::TBitmap* Bitmap = (Qgraphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE int __fastcall MessageDlg(const WideString Msg, TMsgDlgType DlgType, TMsgDlgButtons Buttons, int HelpCtx, TMsgDlgBtn DefaultBtn = (TMsgDlgBtn)(0x0), Qgraphics::TBitmap* Bitmap = (Qgraphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE int __fastcall MessageDlg(const WideString Caption, const WideString Msg, TMsgDlgType DlgType, TMsgDlgButtons Buttons, int HelpCtx, TMsgDlgBtn DefaultBtn = (TMsgDlgBtn)(0x0), Qgraphics::TBitmap* Bitmap = (Qgraphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE int __fastcall MessageDlgPos(const WideString Msg, TMsgDlgType DlgType, TMsgDlgButtons Buttons, int HelpCtx, int X, int Y, TMsgDlgBtn DefaultBtn = (TMsgDlgBtn)(0x0), Qgraphics::TBitmap* Bitmap = (Qgraphics::TBitmap*)(0x0));
extern PACKAGE void __fastcall ShowMessage(const WideString Msg)/* overload */;
extern PACKAGE void __fastcall ShowMessage(const WideString Msg, const System::TVarRec * Params, const int Params_Size)/* overload */;
extern PACKAGE void __fastcall ShowMessageFmt(const WideString Msg, const System::TVarRec * Params, const int Params_Size);
extern PACKAGE void __fastcall ShowMessagePos(const WideString Msg, int X, int Y);
extern PACKAGE bool __fastcall InputQuery(const WideString ACaption, const WideString APrompt, WideString &Value)/* overload */;
extern PACKAGE bool __fastcall InputQuery(const WideString ACaption, const WideString APrompt, AnsiString &Value)/* overload */;
extern PACKAGE bool __fastcall InputQuery(const WideString ACaption, const WideString APrompt, int &Value, int Min = 0x80000000, int Max = 0x7fffffff, int Increment = 0x1)/* overload */;
extern PACKAGE bool __fastcall InputQuery(const WideString ACaption, const WideString APrompt, double &Value, double Min = -2.147484E+09, double Max = 2.147484E+09, int Decimals = 0x1)/* overload */;
extern PACKAGE WideString __fastcall InputBox(const WideString ACaption, const WideString APrompt, const WideString ADefault)/* overload */;
extern PACKAGE int __fastcall InputBox(const WideString ACaption, const WideString APrompt, int ADefault, int Min = 0x80000000, int Max = 0x7fffffff, int Increment = 0x1)/* overload */;
extern PACKAGE double __fastcall InputBox(const WideString ACaption, const WideString APrompt, double ADefault, double Min = -2.147484E+09, double Max = 2.147484E+09, int Decimals = 0x1)/* overload */;

}	/* namespace Qdialogs */
using namespace Qdialogs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QDialogs
