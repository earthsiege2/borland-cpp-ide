// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdActns.pas' rev: 6.00

#ifndef StdActnsHPP
#define StdActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdactns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THintAction;
class PASCALIMPLEMENTATION THintAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
public:
	__fastcall virtual THintAction(Classes::TComponent* AOwner);
	
__published:
	__property Hint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THintAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditAction;
class PASCALIMPLEMENTATION TEditAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Stdctrls::TCustomEdit* FControl;
	void __fastcall SetControl(Stdctrls::TCustomEdit* Value);
	
protected:
	virtual Stdctrls::TCustomEdit* __fastcall GetControl(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Stdctrls::TCustomEdit* Control = {read=FControl, write=SetControl};
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditAction(Classes::TComponent* AOwner) : Actnlist::TAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditCut;
class PASCALIMPLEMENTATION TEditCut : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditCut(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditCut(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditCopy;
class PASCALIMPLEMENTATION TEditCopy : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditCopy(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditCopy(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditPaste;
class PASCALIMPLEMENTATION TEditPaste : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditPaste(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditPaste(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditSelectAll;
class PASCALIMPLEMENTATION TEditSelectAll : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditSelectAll(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditSelectAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditUndo;
class PASCALIMPLEMENTATION TEditUndo : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditUndo(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditUndo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditDelete;
class PASCALIMPLEMENTATION TEditDelete : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TEditDelete(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditDelete(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowAction;
class PASCALIMPLEMENTATION TWindowAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Forms::TForm* FForm;
	void __fastcall SetForm(Forms::TForm* Value);
	
protected:
	virtual Forms::TForm* __fastcall GetForm(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TWindowAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Forms::TForm* Form = {read=FForm, write=SetForm};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowClose;
class PASCALIMPLEMENTATION TWindowClose : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowClose(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowClose(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowCascade;
class PASCALIMPLEMENTATION TWindowCascade : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowCascade(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowCascade(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowTileHorizontal;
class PASCALIMPLEMENTATION TWindowTileHorizontal : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowTileHorizontal(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowTileHorizontal(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowTileVertical;
class PASCALIMPLEMENTATION TWindowTileVertical : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowTileVertical(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowTileVertical(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowMinimizeAll;
class PASCALIMPLEMENTATION TWindowMinimizeAll : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowMinimizeAll(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowMinimizeAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowArrange;
class PASCALIMPLEMENTATION TWindowArrange : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TWindowAction.Create */ inline __fastcall virtual TWindowArrange(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowArrange(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpAction;
class PASCALIMPLEMENTATION THelpAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
public:
	__fastcall virtual THelpAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpContents;
class PASCALIMPLEMENTATION THelpContents : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* THelpAction.Create */ inline __fastcall virtual THelpContents(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpContents(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpTopicSearch;
class PASCALIMPLEMENTATION THelpTopicSearch : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* THelpAction.Create */ inline __fastcall virtual THelpTopicSearch(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpTopicSearch(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpOnHelp;
class PASCALIMPLEMENTATION THelpOnHelp : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* THelpAction.Create */ inline __fastcall virtual THelpOnHelp(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpOnHelp(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpContextAction;
class PASCALIMPLEMENTATION THelpContextAction : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* THelpAction.Create */ inline __fastcall virtual THelpContextAction(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpContextAction(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TCommonDialogClass;

class DELPHICLASS TCommonDialogAction;
class PASCALIMPLEMENTATION TCommonDialogAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	bool FExecuteResult;
	Classes::TNotifyEvent FOnAccept;
	Classes::TNotifyEvent FOnCancel;
	Classes::TNotifyEvent FBeforeExecute;
	
protected:
	Dialogs::TCommonDialog* FDialog;
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
public:
	__fastcall virtual TCommonDialogAction(Classes::TComponent* AOwner);
	virtual bool __fastcall Handlestarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	__property bool ExecuteResult = {read=FExecuteResult, nodefault};
	__property Classes::TNotifyEvent BeforeExecute = {read=FBeforeExecute, write=FBeforeExecute};
	__property Classes::TNotifyEvent OnAccept = {read=FOnAccept, write=FOnAccept};
	__property Classes::TNotifyEvent OnCancel = {read=FOnCancel, write=FOnCancel};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCommonDialogAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileAction;
class PASCALIMPLEMENTATION TFileAction : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
private:
	AnsiString __fastcall GetFileName();
	void __fastcall SetFileName(const AnsiString Value);
	
protected:
	Dialogs::TOpenDialog* __fastcall GetDialog(void);
	__property AnsiString FileName = {read=GetFileName, write=SetFileName};
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TFileAction(Classes::TComponent* AOwner) : TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileOpen;
class PASCALIMPLEMENTATION TFileOpen : public TFileAction 
{
	typedef TFileAction inherited;
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
public:
	__fastcall virtual TFileOpen(Classes::TComponent* AOwner);
	
__published:
	__property Caption ;
	__property Dialogs::TOpenDialog* Dialog = {read=GetDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileOpen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileOpenWith;
class PASCALIMPLEMENTATION TFileOpenWith : public TFileOpen 
{
	typedef TFileOpen inherited;
	
private:
	AnsiString FFileName;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	
__published:
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property BeforeExecute ;
public:
	#pragma option push -w-inl
	/* TFileOpen.Create */ inline __fastcall virtual TFileOpenWith(Classes::TComponent* AOwner) : TFileOpen(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileOpenWith(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileSaveAs;
class PASCALIMPLEMENTATION TFileSaveAs : public TFileAction 
{
	typedef TFileAction inherited;
	
private:
	Dialogs::TSaveDialog* __fastcall GetSaveDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
public:
	__fastcall virtual TFileSaveAs(Classes::TComponent* AOwner);
	
__published:
	__property Caption ;
	__property Dialogs::TSaveDialog* Dialog = {read=GetSaveDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileSaveAs(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFilePrintSetup;
class PASCALIMPLEMENTATION TFilePrintSetup : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
private:
	Dialogs::TPrinterSetupDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
__published:
	__property Caption ;
	__property Dialogs::TPrinterSetupDialog* Dialog = {read=GetDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TFilePrintSetup(Classes::TComponent* AOwner) : TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFilePrintSetup(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileExit;
class PASCALIMPLEMENTATION TFileExit : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TFileExit(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileExit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSearchAction;
class PASCALIMPLEMENTATION TSearchAction : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
protected:
	Stdctrls::TCustomEdit* FControl;
	bool FFindFirst;
	
public:
	__fastcall virtual TSearchAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall Search(System::TObject* Sender);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSearchAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSearchFind;
class PASCALIMPLEMENTATION TSearchFind : public TSearchAction 
{
	typedef TSearchAction inherited;
	
private:
	Dialogs::TFindDialog* __fastcall GetFindDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
__published:
	__property Caption ;
	__property Dialogs::TFindDialog* Dialog = {read=GetFindDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TSearchAction.Create */ inline __fastcall virtual TSearchFind(Classes::TComponent* AOwner) : TSearchAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSearchFind(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSearchReplace;
class PASCALIMPLEMENTATION TSearchReplace : public TSearchAction 
{
	typedef TSearchAction inherited;
	
private:
	void __fastcall Replace(System::TObject* Sender);
	Dialogs::TReplaceDialog* __fastcall GetReplaceDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Dialogs::TReplaceDialog* Dialog = {read=GetReplaceDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TSearchAction.Create */ inline __fastcall virtual TSearchReplace(Classes::TComponent* AOwner) : TSearchAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSearchReplace(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSearchFindFirst;
class PASCALIMPLEMENTATION TSearchFindFirst : public TSearchFind 
{
	typedef TSearchFind inherited;
	
public:
	__fastcall virtual TSearchFindFirst(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSearchFindFirst(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSearchFindNext;
class PASCALIMPLEMENTATION TSearchFindNext : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	TSearchFind* FSearchFind;
	
public:
	__fastcall virtual TSearchFindNext(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property TSearchFind* SearchFind = {read=FSearchFind, write=FSearchFind};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSearchFindNext(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFontEdit;
class PASCALIMPLEMENTATION TFontEdit : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
private:
	Dialogs::TFontDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
__published:
	__property Caption ;
	__property Dialogs::TFontDialog* Dialog = {read=GetDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TFontEdit(Classes::TComponent* AOwner) : TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFontEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TColorSelect;
class PASCALIMPLEMENTATION TColorSelect : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
private:
	Dialogs::TColorDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall GetDialogClass(void);
	
__published:
	__property Caption ;
	__property Dialogs::TColorDialog* Dialog = {read=GetDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TColorSelect(Classes::TComponent* AOwner) : TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TColorSelect(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPrintDlg;
class PASCALIMPLEMENTATION TPrintDlg : public TCommonDialogAction 
{
	typedef TCommonDialogAction inherited;
	
private:
	Dialogs::TPrintDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall Getdialogclass(void);
	
__published:
	__property Caption ;
	__property Dialogs::TPrintDialog* Dialog = {read=GetDialog};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property BeforeExecute ;
	__property OnAccept ;
	__property OnCancel ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TPrintDlg(Classes::TComponent* AOwner) : TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TPrintDlg(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stdactns */
using namespace Stdactns;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdActns
