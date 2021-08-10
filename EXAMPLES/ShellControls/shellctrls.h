// Borland C++ Builder
// Copyright (c) 1995-2002 by Borland International
// All rights reserved

#ifndef ShellCtrlsH
#define ShellCtrlsH

#include <Menus.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit

#include <ShlObj.hpp>	// Pascal unit

#include <CommCtrl.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Shellctrls
{
//-- type declarations -------------------------------------------------------
typedef AnsiString TRoot;

enum TRootFolder { rfDesktop, rfMyComputer, rfNetwork, rfRecycleBin, rfAppData, rfCommonDesktopDirectory, rfCommonPrograms, rfCommonStartMenu, rfCommonStartup, rfControlPanel, rfDesktopDirectory, rfFavorites, rfFonts, rfInternet, rfPersonal, rfPrinters, rfPrintHood, rfPrograms, rfRecent, rfSendTo, rfStartMenu, rfStartup, rfTemplates };

enum TShellFolderCapability { fcCanCopy, fcCanDelete, fcCanLink, fcCanMove, fcCanRename, fcDropTarget, fcHasPropSheet };
enum TShellFolderProperty { fpCut, fpIsLink, fpReadOnly, fpShared, fpFileSystem, fpFileSystemAncestor, fpRemovable, fpValidate };
enum TShellObjectType { otFolders, otNonFolders, otHidden };
enum TNotifyFilter { nfFileNameChange, nfDirNameChange, nfAttributeChange, nfSizeChange, nfWriteChange, nfSecurityChange };

typedef Set<TNotifyFilter, nfFileNameChange, nfSecurityChange>  TNotifyFilters;
typedef Set<TShellFolderProperty, fpCut, fpValidate>  TShellFolderProperties;
typedef Set<TShellFolderCapability, fcCanCopy, fcHasPropSheet>  TShellFolderCapabilities;
typedef Set<TShellObjectType, otFolders, otHidden>  TShellObjectTypes;

class PACKAGE EInvalidPath : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;

public:
	__fastcall EInvalidPath(const AnsiString Msg);
	__fastcall EInvalidPath(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size);
	__fastcall EInvalidPath(int Ident);
	__fastcall EInvalidPath(int Ident, const System::TVarRec * Args, const int Args_Size);
	__fastcall EInvalidPath(const AnsiString Msg, int AHelpContext);
	__fastcall EInvalidPath(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext);
	__fastcall EInvalidPath(int Ident, int AHelpContext);
	__fastcall EInvalidPath(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext);
	__fastcall virtual ~EInvalidPath(void);
};


class PACKAGE TShellFolder : public System::TObject
{
	typedef System::TObject inherited;

private:
	TItemIDList *FPIDL;
	TItemIDList *FFullPIDL;
	TShellFolder* FParent;
	_di_IShellFolder FIShellFolder;
	_di_IShellFolder2 FIShellFolder2;
	Shlobj::_di_IShellDetails FIShellDetails;
	System::_di_IInterface FDetailInterface;
	int FLevel;
	HWND FViewHandle;
	Classes::TStrings* FDetails;
	System::_di_IInterface __fastcall GetDetailInterface();
	Shlobj::_di_IShellDetails __fastcall GetShellDetails();
	_di_IShellFolder2 __fastcall GetShellFolder2();
	AnsiString __fastcall GetDetails(int Index);
	void __fastcall SetDetails(int Index, const AnsiString Value);

public:
	__fastcall TShellFolder(TShellFolder* AParent, Shlobj::PItemIDList ID, _di_IShellFolder SF);
	__fastcall virtual ~TShellFolder(void);
	TShellFolderCapabilities __fastcall Capabilities(void);
	AnsiString __fastcall DisplayName();
	int __fastcall ExecuteDefault(void);
	int __fastcall ImageIndex(bool LargeIcon);
	bool __fastcall IsFolder(void);
	_di_IShellFolder __fastcall ParentShellFolder();
	AnsiString __fastcall PathName();
	TShellFolderProperties __fastcall Properties(void);
	bool __fastcall Rename(const WideString NewName);
	bool __fastcall SubFolders(void);
	__property Shlobj::PItemIDList AbsoluteID = {read=FFullPIDL};
	__property AnsiString Details[int Index] = {read=GetDetails, write=SetDetails};
	__property int Level = {read=FLevel, nodefault};
	__property TShellFolder* Parent = {read=FParent};
	__property Shlobj::PItemIDList RelativeID = {read=FPIDL};
	__property _di_IShellFolder ShellFolder = {read=FIShellFolder};
	__property _di_IShellFolder2 ShellFolder2 = {read=GetShellFolder2};
	__property Shlobj::_di_IShellDetails ShellDetails = {read=GetShellDetails};
	__property HWND ViewHandle = {read=FViewHandle, write=FViewHandle, nodefault};
	void __fastcall LoadColumnDetails(TShellFolder* RootFolder, HWND Handle, int ColumnCount);
};

class PACKAGE TShellChangeThread : public Classes::TThread
{
	typedef Classes::TThread inherited;
    friend class TCustomShellChangeNotifier;
private:
	HANDLE FMutex;
	HANDLE FWaitHandle;
	Classes::TThreadMethod FChangeEvent;
	AnsiString FDirectory;
	bool FWatchSubTree;
	bool FWaitChanged;
	unsigned FNotifyOptionFlags;

protected:
	virtual void __fastcall Execute(void);

public:
	__fastcall virtual TShellChangeThread(Classes::TThreadMethod ChangeEvent);
	__fastcall virtual ~TShellChangeThread(void);
	void __fastcall SetDirectoryOptions(AnsiString Directory, bool WatchSubTree, unsigned NotifyOptionFlags);
	__property Classes::TThreadMethod ChangeEvent = {read=FChangeEvent, write=FChangeEvent};
};

class PACKAGE TCustomShellChangeNotifier : public Classes::TComponent
{
	typedef Classes::TComponent inherited;

private:
	TNotifyFilters FFilters;
	bool FWatchSubTree;
	AnsiString FRoot;
	TShellChangeThread* FThread;
	Classes::TThreadMethod FOnChange;
	void __fastcall SetWatchSubTree(const bool Value);
	void __fastcall SetFilters(const TNotifyFilters Value);
	void __fastcall SetOnChange(const Classes::TThreadMethod Value);

protected:
	void __fastcall Change(void);
	void __fastcall Start(void);

public:
	__fastcall virtual TCustomShellChangeNotifier(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomShellChangeNotifier(void);
	__property TNotifyFilters NotifyFilters = {read=FFilters, write=SetFilters, nodefault};
	__property AnsiString Root = {read=FRoot, write=SetRoot};
	__property bool WatchSubTree = {read=FWatchSubTree, write=SetWatchSubTree, nodefault};
	__property Classes::TThreadMethod OnChange = {read=FOnChange, write=SetOnChange};
	void __fastcall SetRoot(const AnsiString Value);
};

class PACKAGE TShellChangeNotifier : public TCustomShellChangeNotifier
{
	typedef TCustomShellChangeNotifier inherited;

__published:
	__property NotifyFilters ;
	__property Root ;
	__property WatchSubTree ;
	__property OnChange ;
public:
	__fastcall virtual TShellChangeNotifier(Classes::TComponent* AOwner);
	__fastcall virtual ~TShellChangeNotifier(void);
};

typedef void __fastcall (__closure *TAddFolderEvent)(System::TObject* Sender, TShellFolder* AFolder, bool &CanAdd);
typedef void __fastcall (__closure *TGetImageIndexEvent)(System::TObject* Sender, int Index, int &ImageIndex);

class PACKAGE TCustomShellTreeView;
class PACKAGE TCustomShellComboBox;

class PACKAGE TCustomShellListView : public Comctrls::TCustomListView
{
	friend class TCustomShellTreeView;
	friend class TCustomShellComboBox;
	typedef Comctrls::TCustomListView inherited;

private:
	AnsiString FOldRoot;
	AnsiString FRoot;
	TShellFolder* FRootFolder;
	bool FAutoContext;
	bool FAutoRefresh;
	bool FAutoNavigate;
	bool FSorted;
	bool FUpdating;
	TShellObjectTypes FObjectTypes;
	int FLargeImages;
	int FSmallImages;
	TAddFolderEvent FOnAddFolder;
	Classes::TList* FFolders;
	TCustomShellTreeView* FTreeView;
	TCustomShellComboBox* FComboBox;
	TShellChangeNotifier* FNotifier;
	Comctrls::TLVEditingEvent FOnEditing;
	bool FSettingRoot;
	AnsiString FSavePath;
	bool __fastcall AddColumn(TStringList *ColNames, TShellDetails *SD);
	void __fastcall AddDefaultColumn(String ACaption, TAlignment AAlignment, int AWidth);
	void __fastcall AddDefaultColumns(int ColCount);
	void __fastcall EnumColumns(void);
	TShellFolder* __fastcall GetFolder(int Index);
	void __fastcall SetAutoRefresh(bool Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetTreeView(TCustomShellTreeView* Value);
	void __fastcall SetComboBox(TCustomShellComboBox* Value);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
	void __fastcall SynchPaths(void);

protected:
	void __fastcall ClearItems(void);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	void __fastcall EditText(void);
	DYNAMIC void __fastcall Edit(const tagLVITEMA &Item);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual bool __fastcall OwnerDataFetch(Comctrls::TListItem* Item, Comctrls::TItemRequest Request);
	virtual int __fastcall OwnerDataFind(Comctrls::TItemFind Find, const AnsiString FindString, const Types::TPoint &FindPosition, void * FindData, int StartIndex, Comctrls::TSearchDirection Direction, bool Wrap);
	virtual void __fastcall Populate(void);
	void __fastcall RootChanged(void);
	void __fastcall SetObjectTypes(TShellObjectTypes Value);
	virtual void __fastcall SetViewStyle(Comctrls::TViewStyle Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
public:                                 
	__fastcall virtual TCustomShellListView(Classes::TComponent* AOwner);
	__fastcall TCustomShellListView(HWND ParentWindow);
	__fastcall virtual ~TCustomShellListView(void);
	void __fastcall Back(void);
	/*HIDESBASE */void __fastcall Refresh(void);
	TShellFolder* __fastcall SelectedFolder(void);
	__property TShellFolder* Folders[int Index] = {read=GetFolder};
	__property TShellFolder* RootFolder = {read=FRootFolder};
	__property Items ;
	__property Columns ;
	__property bool AutoContextMenus = {read=FAutoContext, write=FAutoContext, default=1};
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, default=0};
	__property bool AutoNavigate = {read=FAutoNavigate, write=FAutoNavigate, default=1};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property AnsiString Root = {read=FRoot, write=SetRoot};
	__property TCustomShellTreeView* ShellTreeView = {read=FTreeView, write=SetTreeView};
	__property TCustomShellComboBox* ShellComboBox = {read=FComboBox, write=SetComboBox};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property TAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property Comctrls::TLVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	void __fastcall SetRoot(const AnsiString Value);
	void __fastcall TreeUpdate(Shlobj::PItemIDList NewRoot);
};

class PACKAGE TCustomShellComboBox : public Comctrls::TCustomComboBoxEx
{
	friend class TCustomShellTreeView;
	friend class TCustomShellListView;

	typedef Comctrls::TCustomComboBoxEx inherited;

private:
	int FImages;
	int FImageHeight;
	int FImageWidth;
	Imglist::TCustomImageList* FImageList;
	AnsiString FOldRoot;
	AnsiString FRoot;
	TShellFolder* FRootFolder;
	TCustomShellTreeView* FTreeView;
	TCustomShellListView* FListView;
	TShellObjectTypes FObjectTypes;
	bool FUseShellImages;
	bool FUpdating;
	TGetImageIndexEvent FOnGetImageIndex;
	void __fastcall ClearItems(void);
	TShellFolder* __fastcall GetFolder(int Index);
	AnsiString __fastcall GetPath();
	void __fastcall SetPath(const AnsiString Value);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
	void __fastcall SetTreeView(TCustomShellTreeView* Value);
	void __fastcall SetListView(TCustomShellListView* Value);
	void __fastcall SetUseShellImages(bool Value);
	int __fastcall GetShellImageIndex(TShellFolder* AFolder);
	void __fastcall InsertItemObject(int Position, String Text, TShellFolder *AFolder);

protected:
	void __fastcall AddItems(int Index, TShellFolder* ParentFolder);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	int __fastcall IndexFromID(Shlobj::PItemIDList AbsoluteID);
	virtual void __fastcall Init(void);
	TShellFolder* __fastcall InitItem(TShellFolder* ParentFolder, Shlobj::PItemIDList ID);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall RootChanged(void);
	virtual void __fastcall SetObjectTypes(TShellObjectTypes Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
public:
	__fastcall virtual TCustomShellComboBox(Classes::TComponent* AOwner);
	__fastcall TCustomShellComboBox(HWND ParentWindow);
	__fastcall virtual ~TCustomShellComboBox(void);
	__property Items ;
	__property AnsiString Path = {read=GetPath, write=SetPath};
	__property TShellFolder* Folders[int Index] = {read=GetFolder};
	__property AnsiString Root = {read=FRoot, write=SetRoot};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property TCustomShellTreeView* ShellTreeView = {read=FTreeView, write=SetTreeView};
	__property TCustomShellListView* ShellListView = {read=FListView, write=SetListView};
	__property bool UseShellImages = {read=FUseShellImages, write=SetUseShellImages, nodefault};
	__property TGetImageIndexEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	void __fastcall SetRoot(const AnsiString Value);
	void __fastcall TreeUpdate(Shlobj::PItemIDList NewPath);
};

class PACKAGE TCustomShellTreeView : public Comctrls::TCustomTreeView
{
	friend class TCustomShellComboBox;
	friend class TCustomShellListView;

	typedef Comctrls::TCustomTreeView inherited;

private:
	AnsiString FRoot;
	AnsiString FOldRoot;
	TShellFolder* FRootFolder;
	TShellObjectTypes FObjectTypes;
	int FImages;
	bool FLoadingRoot;
	bool FAutoContext;
	bool FUpdating;
	TCustomShellComboBox* FComboBox;
	TCustomShellListView* FListView;
	bool FAutoRefresh;
	bool FImageListChanging;
	bool FUseShellImages;
	TShellChangeNotifier* FNotifier;
	TAddFolderEvent FOnAddFolder;
	AnsiString FSavePath;
	Comctrls::TTreeNode* FNodeToMonitor;
	Comctrls::TTreeNode* __fastcall FolderExists(Shlobj::PItemIDList FindID, Comctrls::TTreeNode* InNode);
	TShellFolder* __fastcall GetFolder(int Index);
	AnsiString __fastcall GetPath();
	void __fastcall SetComboBox(TCustomShellComboBox* Value);
	void __fastcall SetListView(TCustomShellListView* Value);
	void __fastcall SetPath(const AnsiString Value);
	void __fastcall SetUseShellImages(const bool Value);
	void __fastcall SetAutoRefresh(const bool Value);

protected:
	DYNAMIC bool __fastcall CanChange(Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(Comctrls::TTreeNode* Node);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	DYNAMIC void __fastcall Edit(const tagTVITEMA &Item);
	virtual void __fastcall GetImageIndex(Comctrls::TTreeNode* Node);
	virtual void __fastcall GetSelectedIndex(Comctrls::TTreeNode* Node);
	void __fastcall InitNode(Comctrls::TTreeNode* NewNode, Shlobj::PItemIDList ID, Comctrls::TTreeNode* ParentNode);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall Delete(Comctrls::TTreeNode* Node);
	Comctrls::TTreeNode* __fastcall NodeFromAbsoluteID(Comctrls::TTreeNode* StartNode, Shlobj::PItemIDList ID);
	Comctrls::TTreeNode* __fastcall NodeFromRelativeID(Comctrls::TTreeNode* ParentNode, Shlobj::PItemIDList ID);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall PopulateNode(Comctrls::TTreeNode* Node);
	void __fastcall NodeDeleted(TObject *Sender, TTreeNode *Node);
	void __fastcall RootChanged(void);
	virtual void __fastcall SetObjectTypes(TShellObjectTypes Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall ClearItems(void);
	void __fastcall RefreshEvent(void);

public:
	__fastcall virtual TCustomShellTreeView(Classes::TComponent* AOwner);
	__fastcall TCustomShellTreeView(HWND ParentWindow);
	__fastcall virtual ~TCustomShellTreeView(void);
	/*HIDESBASE */void __fastcall Refresh(Comctrls::TTreeNode* Node);
	TShellFolder* __fastcall SelectedFolder(void);
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, nodefault};
	__property TShellFolder* Folders[int Index] = {read=GetFolder/*, default*/};
	__property Items ;
	__property AnsiString Path = {read=GetPath, write=SetPath};
	__property bool AutoContextMenus = {read=FAutoContext, write=FAutoContext, default=1};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property AnsiString Root = {read=FRoot, write=SetRoot};
	__property TCustomShellComboBox* ShellComboBox = {read=FComboBox, write=SetComboBox};
	__property TCustomShellListView* ShellListView = {read=FListView, write=SetListView};
	__property bool UseShellImages = {read=FUseShellImages, write=SetUseShellImages, nodefault};
	__property TAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	void __fastcall SetRoot(AnsiString Value);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
};

class PACKAGE TShellTreeView : public TCustomShellTreeView
{
	typedef TCustomShellTreeView inherited;

__published:
	__property AutoContextMenus ;
	__property ObjectTypes ;
	__property Root ;
	__property ShellComboBox ;
	__property ShellListView ;
	__property UseShellImages ;
	__property OnAddFolder ;
	__property Align ;
	__property Anchors ;
	__property AutoRefresh ;
	__property BorderStyle ;
	__property ChangeDelay ;
	__property Color ;
	__property Ctl3D ;
	__property Cursor ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HideSelection ;
	__property Images ;
	__property Indent ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property RightClickSelect ;
	__property ShowButtons ;
	__property ShowHint ;
	__property ShowLines ;
	__property ShowRoot ;
	__property StateImages ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnEnter ;
	__property OnExit ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnStartDrag ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnDblClick ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnChanging ;
	__property OnChange ;
	__property OnExpanding ;
	__property OnCollapsing ;
	__property OnCollapsed ;
	__property OnExpanded ;
	__property OnEditing ;
	__property OnEdited ;
	__property OnGetImageIndex ;
	__property OnGetSelectedIndex ;
public:
	__fastcall virtual TShellTreeView(Classes::TComponent* AOwner);
	__fastcall TShellTreeView(HWND ParentWindow);
	__fastcall virtual ~TShellTreeView(void);
};

class PACKAGE TShellComboBox : public TCustomShellComboBox
{
	typedef TCustomShellComboBox inherited;

__published:
	__property Images ;
	__property Root ;
	__property ShellTreeView ;
	__property ShellListView ;
	__property UseShellImages ;
	__property OnGetImageIndex ;
	__property Anchors ;
	__property BiDiMode ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property DropDownCount ;
	__property Enabled ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property MaxLength ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnChange ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDropDown ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	__fastcall virtual TShellComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TShellComboBox(void);
	__fastcall TShellComboBox(HWND ParentWindow);
};

class PACKAGE TShellListView : public TCustomShellListView
{
	typedef TCustomShellListView inherited;

__published:
	__property AutoContextMenus ;
	__property AutoRefresh ;
	__property AutoNavigate ;
	__property ObjectTypes ;
	__property Root ;
	__property ShellTreeView ;
	__property ShellComboBox ;
	__property Sorted ;
	__property OnAddFolder ;
	__property Align ;
	__property Anchors ;
	__property BorderStyle ;
	__property Color ;
	__property ColumnClick ;
	__property OnClick ;
	__property OnDblClick ;
	__property Ctl3D ;
	__property DragMode ;
	__property ReadOnly ;
	__property Enabled ;
	__property Font ;
	__property GridLines ;
	__property HideSelection ;
	__property HotTrack ;
	__property IconOptions ;
	__property AllocBy ;
	__property MultiSelect ;
	__property RowSelect ;
	__property OnChange ;
	__property OnChanging ;
	__property OnColumnClick ;
	__property OnContextPopup ;
	__property OnEnter ;
	__property OnExit ;
	__property OnInsert ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property DragCursor ;
	__property OnStartDrag ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property ShowHint ;
	__property PopupMenu ;
	__property ShowColumnHeaders ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property ViewStyle ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnEditing ;
public:
	__fastcall virtual TShellListView(Classes::TComponent* AOwner);
	__fastcall TShellListView(HWND ParentWindow);
	__fastcall virtual ~TShellListView(void);
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall InvokeContextMenu(Controls::TWinControl* Owner, TShellFolder* AFolder, int X, int Y);
extern PACKAGE TRootFolder GetEnumValue(String Value);
extern PACKAGE String GetEnumName(TRootFolder Value);

}	/* namespace Shellctrls */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Shellctrls;
#endif

//-- end unit ----------------------------------------------------------------
#endif	// ShellCtrls
