// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ExtActns.pas' rev: 6.00

#ifndef ExtActnsHPP
#define ExtActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <UrlMon.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <ExtDlgs.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ShellAPI.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <StdActns.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Extactns
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TShowCmd { scHide, scMaximize, scMinimize, scRestore, scShow, scShowDefault, scShowMaximized, scShowMinimized, scShowMinNoActive, scShowNA, scShowNoActivate, scShowNormal };
#pragma option pop

class DELPHICLASS TCustomFileRun;
class PASCALIMPLEMENTATION TCustomFileRun : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	bool FBrowse;
	AnsiString FDirectory;
	AnsiString FFile;
	unsigned FHInst;
	unsigned FParentHWnd;
	AnsiString FParameters;
	AnsiString FOperation;
	TShowCmd FShowCmd;
	Dialogs::TOpenDialog* FBrowseDlg;
	Controls::TWinControl* FParentControl;
	void __fastcall SetBrowseDlg(const Dialogs::TOpenDialog* Value);
	void __fastcall SetParentControl(const Controls::TWinControl* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TCustomFileRun(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	void __fastcall SetupBrowseDialog(void);
	__property unsigned HInst = {read=FHInst, nodefault};
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property bool Browse = {read=FBrowse, write=FBrowse, nodefault};
	__property Dialogs::TOpenDialog* BrowseDlg = {read=FBrowseDlg, write=SetBrowseDlg};
	__property AnsiString Directory = {read=FDirectory, write=FDirectory};
	__property AnsiString FileName = {read=FFile, write=FFile};
	__property AnsiString Operation = {read=FOperation, write=FOperation};
	__property Controls::TWinControl* ParentControl = {read=FParentControl, write=SetParentControl};
	__property AnsiString Parameters = {read=FParameters, write=FParameters};
	__property TShowCmd ShowCmd = {read=FShowCmd, write=FShowCmd, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomFileRun(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFileRun;
class PASCALIMPLEMENTATION TFileRun : public TCustomFileRun 
{
	typedef TCustomFileRun inherited;
	
__published:
	__property Browse ;
	__property BrowseDlg ;
	__property Caption ;
	__property Directory ;
	__property Enabled  = {default=1};
	__property FileName ;
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property Operation ;
	__property ParentControl ;
	__property Parameters ;
	__property ShowCmd ;
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomFileRun.Create */ inline __fastcall virtual TFileRun(Classes::TComponent* AOwner) : TCustomFileRun(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TFileRun(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditAction;
class PASCALIMPLEMENTATION TRichEditAction : public Stdactns::TEditAction 
{
	typedef Stdactns::TEditAction inherited;
	
protected:
	Comctrls::TTextAttributes* __fastcall CurrText(Comctrls::TCustomRichEdit* Edit);
	void __fastcall SetFontStyle(Comctrls::TCustomRichEdit* Edit, Graphics::TFontStyle Style);
	
public:
	__fastcall virtual TRichEditAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditBold;
class PASCALIMPLEMENTATION TRichEditBold : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditBold(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditBold(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditItalic;
class PASCALIMPLEMENTATION TRichEditItalic : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditItalic(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditItalic(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditUnderline;
class PASCALIMPLEMENTATION TRichEditUnderline : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditUnderline(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditUnderline(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditStrikeOut;
class PASCALIMPLEMENTATION TRichEditStrikeOut : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditStrikeOut(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditStrikeOut(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditBullets;
class PASCALIMPLEMENTATION TRichEditBullets : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditBullets(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditBullets(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditAlignLeft;
class PASCALIMPLEMENTATION TRichEditAlignLeft : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditAlignLeft(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditAlignLeft(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditAlignRight;
class PASCALIMPLEMENTATION TRichEditAlignRight : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditAlignRight(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditAlignRight(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRichEditAlignCenter;
class PASCALIMPLEMENTATION TRichEditAlignCenter : public TRichEditAction 
{
	typedef TRichEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TRichEditAction.Create */ inline __fastcall virtual TRichEditAlignCenter(Classes::TComponent* AOwner) : TRichEditAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TRichEditAlignCenter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTabAction;
typedef void __fastcall (__closure *TValidateTabEvent)(TTabAction* Sender, Comctrls::TCustomTabControl* TabControl, bool &Enabled);

class PASCALIMPLEMENTATION TTabAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	Classes::TNotifyEvent FAfterTabChange;
	Classes::TNotifyEvent FBeforeTabChange;
	bool FEnabled;
	TValidateTabEvent FOnValidateTab;
	bool FSkipHiddenTabs;
	Comctrls::TCustomTabControl* FTabControl;
	bool FWrap;
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SelectNextTab(bool GoForward = true);
	
public:
	__fastcall virtual TTabAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property bool SkipHiddenTabs = {read=FSkipHiddenTabs, write=FSkipHiddenTabs, default=1};
	__property Comctrls::TCustomTabControl* TabControl = {read=FTabControl, write=FTabControl};
	__property bool Wrap = {read=FWrap, write=FWrap, default=0};
	__property Classes::TNotifyEvent BeforeTabChange = {read=FBeforeTabChange, write=FBeforeTabChange};
	__property Classes::TNotifyEvent AfterTabChange = {read=FAfterTabChange, write=FAfterTabChange};
	__property TValidateTabEvent OnValidateTab = {read=FOnValidateTab, write=FOnValidateTab};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TTabAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPreviousTab;
class PASCALIMPLEMENTATION TPreviousTab : public TTabAction 
{
	typedef TTabAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property TabControl ;
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SkipHiddenTabs  = {default=1};
	__property Visible  = {default=1};
	__property Wrap  = {default=0};
	__property AfterTabChange ;
	__property BeforeTabChange ;
	__property OnHint ;
	__property OnValidateTab ;
public:
	#pragma option push -w-inl
	/* TTabAction.Create */ inline __fastcall virtual TPreviousTab(Classes::TComponent* AOwner) : TTabAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TPreviousTab(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNextTab;
class PASCALIMPLEMENTATION TNextTab : public TTabAction 
{
	typedef TTabAction inherited;
	
private:
	AnsiString FOldCaption;
	AnsiString FLastTabCaption;
	Classes::TNotifyEvent FOnFinish;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property AnsiString LastTabCaption = {read=FLastTabCaption, write=FLastTabCaption};
	__property TabControl ;
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SkipHiddenTabs  = {default=1};
	__property Visible  = {default=1};
	__property Wrap  = {default=0};
	__property AfterTabChange ;
	__property BeforeTabChange ;
	__property Classes::TNotifyEvent OnFinish = {read=FOnFinish, write=FOnFinish};
	__property OnHint ;
	__property OnValidateTab ;
public:
	#pragma option push -w-inl
	/* TTabAction.Create */ inline __fastcall virtual TNextTab(Classes::TComponent* AOwner) : TTabAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TNextTab(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOpenPicture;
class PASCALIMPLEMENTATION TOpenPicture : public Stdactns::TCommonDialogAction 
{
	typedef Stdactns::TCommonDialogAction inherited;
	
private:
	Extdlgs::TOpenPictureDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall Getdialogclass(void);
	
__published:
	__property Extdlgs::TOpenPictureDialog* Dialog = {read=GetDialog};
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
	__property OnUpdate ;
	__property OnAccept ;
	__property OnCancel ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TOpenPicture(Classes::TComponent* AOwner) : Stdactns::TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TOpenPicture(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSavePicture;
class PASCALIMPLEMENTATION TSavePicture : public Stdactns::TCommonDialogAction 
{
	typedef Stdactns::TCommonDialogAction inherited;
	
private:
	Extdlgs::TSavePictureDialog* __fastcall GetDialog(void);
	
protected:
	virtual TMetaClass* __fastcall Getdialogclass(void);
	
__published:
	__property Extdlgs::TSavePictureDialog* Dialog = {read=GetDialog};
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
	__property OnUpdate ;
	__property OnAccept ;
	__property OnCancel ;
public:
	#pragma option push -w-inl
	/* TCommonDialogAction.Create */ inline __fastcall virtual TSavePicture(Classes::TComponent* AOwner) : Stdactns::TCommonDialogAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSavePicture(void) { }
	#pragma option pop
	
};


class DELPHICLASS TURLAction;
class PASCALIMPLEMENTATION TURLAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	AnsiString FURL;
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property AnsiString URL = {read=FURL, write=FURL};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TURLAction(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TURLAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBrowseURL;
class PASCALIMPLEMENTATION TBrowseURL : public TURLAction 
{
	typedef TURLAction inherited;
	
public:
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
	__property URL ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TBrowseURL(Classes::TComponent* AOwner) : TURLAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TBrowseURL(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TURLDownloadStatus { dsFindingResource, dsConnecting, dsRedirecting, dsBeginDownloadData, dsDownloadingData, dsEndDownloadData, dsBeginDownloadComponents, dsInstallingComponents, dsEndDownloadComponents, dsUsingCachedCopy, dsSendingRequest, dsClassIDAvailable, dsMIMETypeAvailable, dsCacheFileNameAvailable, dsBeginSyncOperation, dsEndSyncOperation, dsBeginUploadData, dsUploadingData, dsEndUploadData, dsProtocolClassID, dsEncoding, dsVerifiedMIMETypeAvailable, dsClassInstallLocation, dsDecoding, dsLoadingMIMIHandler };
#pragma option pop

class DELPHICLASS TDownLoadURL;
typedef void __fastcall (__closure *TDownloadProgressEvent)(TDownLoadURL* Sender, unsigned Progress, unsigned ProgressMax, TURLDownloadStatus StatusCode, AnsiString StatusText, bool &Cancel);

class PASCALIMPLEMENTATION TDownLoadURL : public TURLAction 
{
	typedef TURLAction inherited;
	
private:
	TDownloadProgressEvent FOnDownloadProgress;
	AnsiString FFilename;
	
protected:
	HRESULT __stdcall GetBindInfo(/* out */ unsigned &grfBINDF, _tagBINDINFO &bindinfo);
	HRESULT __stdcall GetPriority(/* out */ void *nPriority);
	HRESULT __stdcall OnDataAvailable(unsigned grfBSCF, unsigned dwSize, Activex::PFormatEtc formatetc, Activex::PStgMedium stgmed);
	HRESULT __stdcall OnLowResource(unsigned reserved);
	HRESULT __stdcall OnObjectAvailable(const GUID &iid, System::_di_IInterface punk);
	HRESULT __stdcall OnProgress(unsigned ulProgress, unsigned ulProgressMax, unsigned ulStatusCode, wchar_t * szStatusText);
	HRESULT __stdcall OnStartBinding(unsigned dwReserved, _di_IBinding pib);
	HRESULT __stdcall OnStopBinding(HRESULT hresult, wchar_t * szError);
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property AnsiString Filename = {read=FFilename, write=FFilename};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property URL ;
	__property OnHint ;
	__property OnUpdate ;
	__property TDownloadProgressEvent OnDownloadProgress = {read=FOnDownloadProgress, write=FOnDownloadProgress};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TDownLoadURL(Classes::TComponent* AOwner) : TURLAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDownLoadURL(void) { }
	#pragma option pop
	
private:
	void *__IBindStatusCallback;	/* IBindStatusCallback */
	
public:
	operator IBindStatusCallback*(void) { return (IBindStatusCallback*)&__IBindStatusCallback; }
	
};


class DELPHICLASS TSendMail;
class PASCALIMPLEMENTATION TSendMail : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	Classes::TStrings* FText;
	void __fastcall SetText(const Classes::TStrings* Value);
	Classes::TStrings* __fastcall GetText(void);
	
public:
	__fastcall virtual ~TSendMail(void);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Classes::TStrings* Text = {read=GetText, write=SetText};
	__property Visible  = {default=1};
	__property OnHint ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TSendMail(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlAction;
class PASCALIMPLEMENTATION TListControlAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	Controls::TCustomListControl* FListControl;
	void __fastcall SetListControl(const Controls::TCustomListControl* Value);
	
protected:
	bool __fastcall IsEnabled(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TListControlAction(Classes::TComponent* AOwner);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	__property Controls::TCustomListControl* ListControl = {read=FListControl, write=SetListControl};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlSelectAll;
class PASCALIMPLEMENTATION TListControlSelectAll : public TListControlAction 
{
	typedef TListControlAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ListControl ;
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TListControlAction.Create */ inline __fastcall virtual TListControlSelectAll(Classes::TComponent* AOwner) : TListControlAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlSelectAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlClearSelection;
class PASCALIMPLEMENTATION TListControlClearSelection : public TListControlAction 
{
	typedef TListControlAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ListControl ;
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TListControlAction.Create */ inline __fastcall virtual TListControlClearSelection(Classes::TComponent* AOwner) : TListControlAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlClearSelection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlDeleteSelection;
class PASCALIMPLEMENTATION TListControlDeleteSelection : public TListControlAction 
{
	typedef TListControlAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ListControl ;
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TListControlAction.Create */ inline __fastcall virtual TListControlDeleteSelection(Classes::TComponent* AOwner) : TListControlAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlDeleteSelection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlCopySelection;
class PASCALIMPLEMENTATION TListControlCopySelection : public TListControlAction 
{
	typedef TListControlAction inherited;
	
private:
	Controls::TCustomListControl* FDestination;
	void __fastcall SetDestination(const Controls::TCustomListControl* Value);
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property Caption ;
	__property Controls::TCustomListControl* Destination = {read=FDestination, write=SetDestination};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ListControl ;
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TListControlAction.Create */ inline __fastcall virtual TListControlCopySelection(Classes::TComponent* AOwner) : TListControlAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlCopySelection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListControlMoveSelection;
class PASCALIMPLEMENTATION TListControlMoveSelection : public TListControlCopySelection 
{
	typedef TListControlCopySelection inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TListControlAction.Create */ inline __fastcall virtual TListControlMoveSelection(Classes::TComponent* AOwner) : TListControlCopySelection(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TListControlMoveSelection(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Extactns */
using namespace Extactns;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ExtActns
