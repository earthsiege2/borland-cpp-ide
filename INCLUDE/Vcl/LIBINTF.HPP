// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'LibIntf.pas' rev: 5.00

#ifndef LibIntfHPP
#define LibIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolsAPI.hpp>	// Pascal unit
#include <FileIntf.hpp>	// Pascal unit
#include <EditIntf.hpp>	// Pascal unit
#include <Exptintf.hpp>	// Pascal unit
#include <ToolIntf.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Libintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDesignDialog { ddAlign, ddSize, ddScale, ddTabOrder, ddCreationOrder, ddSaveTemplate };
#pragma option pop

struct TDesignerOptions
{
	bool DisplayGrid;
	bool SnapToGrid;
	int GridSizeX;
	int GridSizeY;
	bool ShowComponentCaptions;
	bool ShowDesignerHints;
	bool DFMFormat;
} ;

__interface IUpdateManager;
typedef System::DelphiInterface<IUpdateManager> _di_IUpdateManager;
__interface INTERFACE_UUID("{ABBE7253-5495-11D1-9FB5-0020AF3D82DA}") IUpdateManager  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 
		;
	virtual Dsgnintf::_di_IComponent __fastcall GetComponent(void) = 0 ;
	virtual Dsgnintf::_di_IComponent __fastcall GetAncestor(void) = 0 ;
	virtual bool __fastcall GetHasDescendents(void) = 0 ;
	virtual bool __fastcall GetIsDescendent(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual bool __fastcall NameExists(const AnsiString Name) = 0 ;
	virtual void __fastcall Notification(Dsgnintf::_di_IPersistent Component, Classes::TOperation Operation
		) = 0 ;
	virtual void __fastcall RenameComponent(const AnsiString CurrentName, const AnsiString NewName) = 0 
		;
	virtual void __fastcall RenameDescendents(const AnsiString CurrentName, const AnsiString NewName) = 0 
		;
	virtual void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
	__property Dsgnintf::_di_IComponent Component = {read=GetComponent};
	__property Dsgnintf::_di_IComponent Ancestor = {read=GetAncestor};
	__property bool HasDescendents = {read=GetHasDescendents};
	__property bool IsDescendent = {read=GetIsDescendent};
};

__interface IUpdateManagerCallback;
typedef System::DelphiInterface<IUpdateManagerCallback> _di_IUpdateManagerCallback;
__interface INTERFACE_UUID("{ABBE7254-5495-11D1-9FB5-0020AF3D82DA}") IUpdateManagerCallback  : public IUnknown 
	
{
	
public:
	virtual void __fastcall Updating(const _di_IUnknown Context) = 0 ;
	virtual void __fastcall Updated(const _di_IUnknown Context) = 0 ;
	virtual Dsgnintf::_di_IComponent __fastcall CreateComponent(void * ComponentClass, const Dsgnintf::_di_IComponent 
		Owner) = 0 ;
	virtual void __fastcall WriteComponent(Classes::TWriter* Writer, Classes::TComponent* Component) = 0 
		;
};

__interface IRootManager;
typedef System::DelphiInterface<IRootManager> _di_IRootManager;
__interface INTERFACE_UUID("{146303AB-097F-11D3-AB41-00C04FB17A72}") IRootManager  : public IUnknown 
	
{
	
public:
	virtual Dsgnintf::_di_IComponent __fastcall CreateRootAs(const AnsiString AClassname, const AnsiString 
		AAncestorClassName) = 0 ;
	virtual Dsgnintf::_di_IComponent __fastcall CreateRootInstance(const AnsiString AClassname) = 0 ;
	virtual Dsgnintf::_di_IComponent __fastcall CreateRootFrom(const _di_IStream Stream) = 0 ;
	virtual _di_IUpdateManager __fastcall CreateUpdateManager(const Dsgnintf::_di_IComponent Root, const 
		Dsgnintf::_di_IComponent AncestorRoot, const _di_IUpdateManager AncestorUpdateMgr, const _di_IUpdateManagerCallback 
		CallbackIntf) = 0 ;
	virtual void __fastcall FindDependencies(const Classes::_di_IInterfaceList Dependencies) = 0 ;
	virtual void __fastcall ClearDependenciesOn(const Dsgnintf::_di_IComponent Dependent) = 0 ;
	virtual AnsiString __fastcall GetAncestorName(void) = 0 ;
	virtual Dsgnintf::_di_IComponentEditor __fastcall GetComponentEditor(const Dsgnintf::_di_IComponent 
		Component, const _di_IUnknown Designer) = 0 ;
	virtual Classes::TStreamOriginalFormat __fastcall GetOrigDFMFormat(void) = 0 ;
	virtual AnsiString __fastcall GetNonAncestorNames(const Dsgnintf::_di_IComponent Component) = 0 ;
	virtual bool __fastcall GetReadError(void) = 0 ;
	virtual AnsiString __fastcall GetRootClassName(void) = 0 ;
	virtual AnsiString __fastcall GetUnitsList(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall ModuleRenamed(void) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
	virtual void __fastcall ReadStream(const _di_IStream S, const Dsgnintf::_di_IComponent Parent, bool 
		AdjustPos, const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall RenameFormMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual bool __fastcall RenameFormComponent(const AnsiString CurName, const AnsiString NewName) = 0 
		;
	virtual void __fastcall RenameRoot(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall ResetReadError(void) = 0 ;
	virtual bool __fastcall RootClassIsTWinControl(void) = 0 ;
	virtual bool __fastcall RootClassIsTCustomForm(void) = 0 ;
	virtual bool __fastcall RootClassIsTForm(void) = 0 ;
	virtual void __fastcall SetOrigDFMFormat(Classes::TStreamOriginalFormat Value) = 0 ;
	virtual void __fastcall SetRootClassName(const AnsiString Value) = 0 ;
	virtual void __fastcall StreamSelection(const _di_IStream S, bool CopyMethods, bool CopyBounds, Classes::TStrings* 
		UnitDependencies) = 0 ;
	virtual void __fastcall WriteFormStream(const _di_IStream S) = 0 ;
	virtual void __fastcall ComponentRemoved(const Dsgnintf::_di_IPersistent Component) = 0 ;
	virtual Dsgnintf::_di_IComponent __fastcall CreateComponent(void * ComponentClass, const Dsgnintf::_di_IComponent 
		Owner) = 0 ;
	virtual void __fastcall WriteComponent(Classes::TWriter* Writer, Classes::TComponent* Component) = 0 
		;
	virtual bool __fastcall GetTextDFM(void) = 0 ;
	virtual void __fastcall SetTextDFM(bool Value) = 0 ;
	__property AnsiString RootClassName = {read=GetRootClassName, write=SetRootClassName};
	__property bool ReadError = {read=GetReadError};
	__property bool TextDFM = {read=GetTextDFM, write=SetTextDFM};
	__property Classes::TStreamOriginalFormat OrigDFMFormat = {read=GetOrigDFMFormat, write=SetOrigDFMFormat
		};
};

#pragma option push -b-
enum TFIResult { fiDelete, fiRename, fiCreate, fiViewAsText, fiCancel };
#pragma option pop

__interface IDesignerStreamReadErrorResolution;
typedef System::DelphiInterface<IDesignerStreamReadErrorResolution> _di_IDesignerStreamReadErrorResolution;
	
__interface INTERFACE_UUID("{4169AB51-59F3-11D1-9FB6-0020AF3D82DA}") IDesignerStreamReadErrorResolution 
	 : public IUnknown 
{
	
public:
	virtual int __fastcall FormReadError(const AnsiString Msg) = 0 ;
	virtual TFIResult __fastcall FormInheritenceRecovery(const AnsiString FormName, const AnsiString AncestorFormName
		, AnsiString &ComponentName, const AnsiString Names, bool RecoveringFrame) = 0 ;
	virtual int __fastcall QueryRedirectLinks(const AnsiString RootName, const AnsiString ComponentName
		) = 0 ;
};

__interface IPaletteItem;
typedef System::DelphiInterface<IPaletteItem> _di_IPaletteItem;
__interface IDesignerModule;
typedef System::DelphiInterface<IDesignerModule> _di_IDesignerModule;
__interface INTERFACE_UUID("{F9D448F1-50BC-11D1-9FB5-0020AF3D82DA}") IPaletteItem  : public IUnknown 
	
{
	
public:
	virtual Dsgnintf::_di_IComponent __fastcall CreateComponent(const Dsgnintf::_di_IComponent Owner, const 
		Dsgnintf::_di_IComponent Parent, const _di_IDesignerModule Module, const Windows::TRect &Rect) = 0 
		;
	virtual void __fastcall Paint(Graphics::TCanvas* Canvas, int X, int Y) = 0 ;
};

__interface IComponentPaletteItem;
typedef System::DelphiInterface<IComponentPaletteItem> _di_IComponentPaletteItem;
__interface INTERFACE_UUID("{707992A9-F11A-11D2-AAD2-00C04FB16FBC}") IComponentPaletteItem  : public IPaletteItem 
	
{
	
public:
	virtual TMetaClass* __fastcall GetComponentClass(void) = 0 ;
};

__interface IDelphiIDE;
typedef System::DelphiInterface<IDelphiIDE> _di_IDelphiIDE;
__interface INTERFACE_UUID("{C8B1C803-AFFF-11D2-AACE-00C04FB16FBC}") IDelphiIDE  : public IUnknown 
{
	
public:
	virtual void __fastcall ActiveFormModified(void) = 0 ;
	virtual void __fastcall ComponentRenamed(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall ExecDesignDialog(TDesignDialog DesignDialog) = 0 ;
	virtual void __fastcall FormActivated(void) = 0 ;
	virtual HWND __fastcall GetAppHandle(void) = 0 ;
	virtual AnsiString __fastcall GetPathAndBaseExeName(void) = 0 ;
	virtual AnsiString __fastcall GetBaseRegKey(void) = 0 ;
	virtual bool __fastcall GetToolSelected(void) = 0 ;
	virtual _di_IPaletteItem __fastcall GetCurCompClass(void) = 0 ;
	virtual _di_IPaletteItem __fastcall GetPaletteItem(TMetaClass* ComponentClass) = 0 ;
	virtual int __fastcall GetCurTime(void) = 0 ;
	virtual void __fastcall GetDesignerOptions(TDesignerOptions &Options) = 0 ;
	virtual Windows::TRect __fastcall GetMainWindowSize(void) = 0 ;
	virtual Windows::TPoint __fastcall GetWorkspaceOrigin(void) = 0 ;
	virtual bool __fastcall LockState(void) = 0 ;
	virtual void __fastcall ModalEdit(char EditKey, void * ReturnWindow) = 0 ;
	virtual void __fastcall OpenForm(const AnsiString FormName, bool Show) = 0 ;
	virtual void __fastcall RaiseException(const AnsiString Message) = 0 ;
	virtual void __fastcall ResetCompClass(void) = 0 ;
	virtual void __fastcall SelectionChanged(void) = 0 ;
	virtual void __fastcall ShowClassHelp(const AnsiString ClassName) = 0 ;
	virtual void __fastcall SelectItemName(const AnsiString PropertyName) = 0 ;
	virtual void __fastcall ValidateActiveModule(void) = 0 ;
	virtual void __fastcall AddExpert(const Exptintf::TIExpert* Expert) = 0 ;
	virtual void __fastcall RemoveExpert(const Exptintf::TIExpert* Expert) = 0 ;
	virtual int __fastcall AddWizard(const Toolsapi::_di_IOTAWizard Wizard) = 0 ;
	virtual void __fastcall RemoveWizard(int Index) = 0 ;
	virtual Toolintf::TIToolServices* __fastcall GetToolServices(void) = 0 ;
	virtual void __fastcall ExpertsLoaded(void) = 0 ;
	virtual Toolsapi::_di_IOTAFileSystem __fastcall GetFileSystem(const AnsiString Ident) = 0 ;
	virtual AnsiString __fastcall MakeBackupFileName(const AnsiString FileName) = 0 ;
	virtual bool __fastcall CreateBackupFile(void) = 0 ;
	virtual bool __fastcall WinHelp(const AnsiString HelpFile, int Command, int Data) = 0 ;
	virtual void __fastcall ValidateFormEdit(void) = 0 ;
	virtual _di_IPaletteItem __fastcall GetPaletteItemByName(const AnsiString Classname) = 0 ;
	virtual void __fastcall RequestTemplate(const AnsiString CompName, Classes::TStream* Stream, Classes::TStrings* 
		Dependencies) = 0 ;
};

class DELPHICLASS TICompClass;
class PASCALIMPLEMENTATION TICompClass : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual Windows::TPoint __fastcall GetBitmapPos(bool Selected) = 0 ;
	virtual AnsiString __fastcall GetClassName(void) = 0 ;
	virtual AnsiString __fastcall GetDefaultPage(void) = 0 ;
	virtual int __fastcall GetModuleIndex(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TICompClass(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TICompClass(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPropKind { pkProperties, pkEvents };
#pragma option pop

class DELPHICLASS TIProperty;
typedef void __fastcall (__closure *TGetPropProc)(TIProperty* Prop);

#pragma option push -b-
enum LibIntf__2 { fsVisible, fsIconic, fsZoomed };
#pragma option pop

typedef Set<LibIntf__2, fsVisible, fsZoomed>  TFormState;

#pragma option push -b-
enum TShowState { ssNormal, ssMinimized, ssMaximized };
#pragma option pop

#pragma option push -b-
enum TAffect { afTop, afLeft, afBottom, afRight, afHCenter, afVCenter, afHSpace, afVSpace, afHWinCenter, 
	afVWinCenter, afNothing };
#pragma option pop

#pragma option push -b-
enum TSizeAffect { asHGrow, asHShrink, asHAbsolute, asVGrow, asVShrink, asVAbsolute, asNothing };
#pragma option pop

class DELPHICLASS TIFile;
class PASCALIMPLEMENTATION TIFile : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual _di_IStream __fastcall FormFileOpen(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual int __fastcall GetTimeAtLoad(void) = 0 ;
	virtual int __fastcall GetModifyTime(void) = 0 ;
	virtual bool __fastcall CheckFileDate(void) = 0 ;
	virtual void __fastcall Rename(const AnsiString NewFileName) = 0 ;
	virtual void __fastcall Save(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIFile(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIFile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIForm;
typedef void __fastcall (__closure *TGetFormProc)(TIForm* AForm);

class DELPHICLASS TICompInfo;
class PASCALIMPLEMENTATION TIForm : public TIFile 
{
	typedef TIFile inherited;
	
protected:
	virtual Dsgnintf::_di_IFormDesigner __fastcall GetDesigner(void) = 0 ;
	
public:
	virtual void __fastcall Align(TAffect Affect) = 0 ;
	virtual void __fastcall CreateComponent(_di_IPaletteItem Item) = 0 ;
	virtual AnsiString __fastcall FindCompClass(const AnsiString CompName) = 0 ;
	virtual AnsiString __fastcall GetAncestorName(void) = 0 ;
	virtual int __fastcall GetCompCount(void) = 0 ;
	virtual void __fastcall GetDependentForms(TGetFormProc Proc) = 0 ;
	virtual AnsiString __fastcall GetDesignClassName(void) = 0 ;
	virtual void __fastcall GetFormDependencies(TGetFormProc Proc) = 0 ;
	virtual void * __fastcall GetNVComp(int Index) = 0 ;
	virtual TICompInfo* __fastcall GetCompInfo(int Index) = 0 ;
	virtual _di_IDesignerModule __fastcall GetModule(void) = 0 ;
	virtual AnsiString __fastcall GetCompName(int Index) = 0 ;
	virtual AnsiString __fastcall GetFileSystem(void) = 0 ;
	virtual Editintf::TIFormInterface* __fastcall GetFormInterface(void) = 0 ;
	virtual Toolsapi::_di_IOTAFormEditor __fastcall GetFormEditor(void) = 0 ;
	virtual AnsiString __fastcall GetFormName(void) = 0 ;
	virtual HBITMAP __fastcall GetFormImage(void) = 0 ;
	virtual void __fastcall GetFormUnits(Classes::TGetStrProc Proc) = 0 ;
	virtual TFormState __fastcall GetState(void) = 0 ;
	virtual int __fastcall GetTabCompCount(void) = 0 ;
	virtual bool __fastcall GetTabCompInfo(int Order, AnsiString &Name, void * &Comp) = 0 ;
	virtual int __fastcall GetObjectMenuItemCount(void) = 0 ;
	virtual AnsiString __fastcall GetObjectMenuItem(int Index) = 0 ;
	virtual void __fastcall ObjectMenuAction(int Index) = 0 ;
	virtual void __fastcall Hide(void) = 0 ;
	virtual void __fastcall GoDormant(void) = 0 ;
	virtual void __fastcall RenameFormMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual bool __fastcall RenameFormComponent(const AnsiString CurName, const AnsiString NewName) = 0 
		;
	virtual void __fastcall RemoveDependentLinks(void) = 0 ;
	virtual void __fastcall Scale(int Factor) = 0 ;
	virtual void __fastcall SetFileSystem(const AnsiString FileSystem) = 0 ;
	virtual void __fastcall SetFormName(const AnsiString AName) = 0 ;
	virtual void __fastcall SetSelection(const AnsiString Name) = 0 ;
	virtual void __fastcall SetNVComp(void * Comp, int Order) = 0 ;
	virtual void __fastcall SetTabCompOrder(void * Comp, int Order) = 0 ;
	virtual void __fastcall Show(void) = 0 ;
	virtual void __fastcall ShowAs(TShowState ShowState) = 0 ;
	virtual void __fastcall Size(TSizeAffect Affect, int Value) = 0 ;
	virtual _di_IStream __fastcall GetDesignerData(void) = 0 ;
	__property Dsgnintf::_di_IFormDesigner Designer = {read=GetDesigner};
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIForm(void) : TIFile() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIForm(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragTarget;
class PASCALIMPLEMENTATION TDragTarget : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Dsgnintf::_di_IFormDesigner FDesigner;
	
public:
	__fastcall virtual TDragTarget(Dsgnintf::_di_IFormDesigner ADesigner);
	virtual bool __fastcall DragOver(System::TObject* Target, System::TObject* Source, int X, int Y, Controls::TDragState 
		State) = 0 ;
	virtual void __fastcall DragDrop(System::TObject* Target, System::TObject* Source, int X, int Y) = 0 
		;
	__property Dsgnintf::_di_IFormDesigner Designer = {read=FDesigner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragTarget(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDragTargetClass;

__interface IDesignerActions;
typedef System::DelphiInterface<IDesignerActions> _di_IDesignerActions;
__interface INTERFACE_UUID("{825D4B2D-1D20-11D3-B744-00C04FA35D12}") IDesignerActions  : public IUnknown 
	
{
	
public:
	virtual void __fastcall KeyDown(Word Key) = 0 ;
	virtual void __fastcall KeyPress(char Ch) = 0 ;
};

__interface ILibrary;
typedef System::DelphiInterface<ILibrary> _di_ILibrary;
__interface INTERFACE_UUID("{A2BABE07-ED17-11D2-AB41-00C04FB17A72}") ILibrary  : public IUnknown 
{
	
public:
	virtual void __fastcall CopySelectionToStream(Classes::TMemoryStream* S, Classes::TStrings* UnitDependencies
		) = 0 ;
	virtual TIForm* __fastcall CreateForm(const _di_IDesignerModule AModule, const AnsiString AFileName
		, bool Existing, const AnsiString AFormName, const AnsiString AAncestor, const AnsiString AFileSystem
		) = 0 ;
	virtual TIForm* __fastcall CreateFromStream(const _di_IDesignerModule AModule, const AnsiString AFileName
		, const AnsiString AFileSystem, const _di_IStream IStream) = 0 ;
	virtual TIForm* __fastcall CreateNewForm(const _di_IDesignerModule AModule, const AnsiString AFileName
		, const _di_IUnknown Creator) = 0 ;
	virtual void __fastcall DesignerOptionsChanged(void) = 0 ;
	virtual bool __fastcall EditAction(Dsgnintf::TEditAction Action) = 0 ;
	virtual TIFile* __fastcall FindFile(const AnsiString FileName) = 0 ;
	virtual TIForm* __fastcall FindForm(const AnsiString FormName) = 0 ;
	virtual TIForm* __fastcall GetActiveForm(void) = 0 ;
	virtual void __fastcall GetClassUnits(const AnsiString ClassName, Classes::TGetStrProc Proc) = 0 ;
	virtual TICompClass* __fastcall GetCompClass(int Index) = 0 ;
	virtual int __fastcall GetCompClassCount(void) = 0 ;
	virtual void __fastcall GetCompHierarchy(Classes::TGetStrProc Proc) = 0 ;
	virtual HBITMAP __fastcall GetComponentBitmap(void) = 0 ;
	virtual Dsgnintf::TEditState __fastcall GetEditState(void) = 0 ;
	virtual AnsiString __fastcall GetFirstSelectionType(void) = 0 ;
	virtual void __fastcall GetFormNames(Classes::TGetStrProc Proc) = 0 ;
	virtual int __fastcall GetModuleCount(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(int Index) = 0 ;
	virtual bool __fastcall GetOleCtrlHelp(const AnsiString Member, int &HelpCtx, AnsiString &HelpFile)
		 = 0 ;
	virtual void __fastcall GetProperties(TPropKind PropKind, TGetPropProc Proc) = 0 ;
	virtual AnsiString __fastcall GetSelectionName(void) = 0 ;
	virtual AnsiString __fastcall GetSelectionType(void) = 0 ;
	virtual void __fastcall HideWindows(void) = 0 ;
	virtual void __fastcall IsDesignMsg(tagMSG &Msg, bool &Handled) = 0 ;
	virtual bool __fastcall IsTopmostForm(HWND Wnd) = 0 ;
	virtual bool __fastcall IsValidTemplateSelection(void) = 0 ;
	virtual void __fastcall ModalEditDone(void * ReturnWindow) = 0 ;
	virtual void __fastcall PasteSelectionFromStream(Classes::TMemoryStream* S, Classes::TComponent* Parent
		, const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall RaiseException(const AnsiString Message) = 0 ;
	virtual void __fastcall RegisterDesignWindow(Forms::TForm* Window) = 0 ;
	virtual void __fastcall RegisterDragTarget(const AnsiString SourceName, TMetaClass* TargetClass) = 0 
		;
	virtual void __fastcall ShowWindows(void) = 0 ;
	virtual void __fastcall SetLockState(bool State) = 0 ;
	virtual void __fastcall SetProjectName(const AnsiString Name) = 0 ;
	virtual void __fastcall GetSelection(const Dsgnintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall SetSelection(const Forms::_di_IDesigner Designer, Forms::TCustomForm* DesignWindow
		, Dsgnintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall UnregisterDesignWindow(Forms::TForm* Window) = 0 ;
	virtual void __fastcall UnregisterExpertGroup(int Group) = 0 ;
	virtual void __fastcall CancelModes(void) = 0 ;
	virtual bool __fastcall GetControlsLocked(void) = 0 ;
	virtual void __fastcall FormActivated(const TIForm* AForm) = 0 ;
	virtual void __fastcall UpdateFormDependents(void) = 0 ;
	virtual void __fastcall UpdateSelections(bool AllowNoSelection) = 0 ;
	virtual void __fastcall RemoveDependenciesOn(const Dsgnintf::_di_IComponent Component) = 0 ;
	virtual void __fastcall FormListAdd(const TIForm* AForm) = 0 ;
	virtual void __fastcall FormListRemove(const TIForm* AForm) = 0 ;
	virtual void __fastcall FormGoDormant(const TIForm* AForm) = 0 ;
	virtual void __fastcall FormModified(const TIForm* AForm) = 0 ;
	virtual void __fastcall EditorGetProperties(TGetPropProc Proc, Dsgnintf::TPropertyEditor* Editor) = 0 
		;
	virtual TIForm* __fastcall GetForms(int Index) = 0 ;
	virtual int __fastcall GetFormsCount(void) = 0 ;
	virtual TMetaClass* __fastcall GetFirstSelectionClass(void) = 0 ;
	virtual bool __fastcall IsNestable(const AnsiString ClassName) = 0 ;
	__property bool ControlsLocked = {read=GetControlsLocked};
	__property TIForm* Forms[int Index] = {read=GetForms};
};

#pragma option push -b-
enum TVCLPlatform { vpWin32, vpJava };
#pragma option pop

__interface INTERFACE_UUID("{551B2B01-56DC-11D1-9FB6-0020AF3D82DA}") IDesignerModule  : public IUnknown 
	
{
	
public:
	virtual void __fastcall Activate(bool IsForm) = 0 ;
	virtual void __fastcall CreateMethod(const AnsiString Name, Typinfo::PTypeData TypeData) = 0 ;
	virtual void __fastcall FormModified(void) = 0 ;
	virtual AnsiString __fastcall GetAncestorClassName(const AnsiString ClassName) = 0 ;
	virtual void __fastcall GetMethods(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual bool __fastcall GetFormIsTopmost(void) = 0 ;
	virtual void __fastcall FormResurrected(void) = 0 ;
	virtual bool __fastcall MethodExists(const AnsiString Name) = 0 ;
	virtual void __fastcall RenameComponent(const Dsgnintf::_di_IComponent Component, const AnsiString 
		CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall RenameForm(const Dsgnintf::_di_IComponent Component, const AnsiString NewName
		) = 0 ;
	virtual void __fastcall RenameMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall ShowMethod(const AnsiString Name) = 0 ;
	virtual void __fastcall GetImportedForms(Classes::TGetStrProc Proc) = 0 ;
	virtual void __fastcall ImportForm(const AnsiString FormName) = 0 ;
	virtual void __fastcall FormSaving(void) = 0 ;
	virtual void __fastcall Notify(Editintf::TNotifyCode NotifyCode) = 0 ;
	virtual void __fastcall SwapSourceFormView(void) = 0 ;
	virtual AnsiString __fastcall GetMethod(const AnsiString MethodName) = 0 ;
	virtual void __fastcall AddMethods(AnsiString Methods, Classes::TStrings* Replacements, Classes::TStrings* 
		MethodNames) = 0 ;
	virtual bool __fastcall HasInterface(void) = 0 ;
	virtual bool __fastcall InterfaceMemberExists(const AnsiString Name) = 0 ;
	virtual void __fastcall AddToInterface(int InvKind, const AnsiString Name, Word VT, const AnsiString 
		TypeInfo) = 0 ;
	virtual void __fastcall GetProjectModules(Classes::TGetModuleProc Proc) = 0 ;
	virtual TVCLPlatform __fastcall GetPlatformID(void) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	virtual void __fastcall ChainCall(const AnsiString MethodName, const AnsiString InstanceName, const 
		AnsiString InstanceMethod, Typinfo::PTypeData TypeData) = 0 ;
	virtual bool __fastcall GetUnnamed(void) = 0 ;
	virtual bool __fastcall SaveModule(void) = 0 ;
	__property bool FormIsTopmost = {read=GetFormIsTopmost};
	__property bool ReadOnly = {read=GetReadOnly};
	__property bool Unnamed = {read=GetUnnamed};
};

__interface IClassInfo;
typedef System::DelphiInterface<IClassInfo> _di_IClassInfo;
__interface INTERFACE_UUID("{1D614790-77CA-11D1-AA6F-00C04FB17A72}") IClassInfo  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall ClassName(void) = 0 ;
	virtual _di_IClassInfo __fastcall ClassParent(void) = 0 ;
};

__interface IPropTypeInfo;
typedef System::DelphiInterface<IPropTypeInfo> _di_IPropTypeInfo;
__interface INTERFACE_UUID("{1D614792-77CA-11D1-AA6F-00C04FB17A72}") IPropTypeInfo  : public IUnknown 
	
{
	
public:
	virtual _di_IClassInfo __fastcall GetClassInfo(void) = 0 ;
	virtual Typinfo::TTypeKind __fastcall GetKind(void) = 0 ;
	__property _di_IClassInfo ClassInfo = {read=GetClassInfo};
	__property Typinfo::TTypeKind Kind = {read=GetKind};
};

__interface IReceivesProperties;
typedef System::DelphiInterface<IReceivesProperties> _di_IReceivesProperties;
__interface IProperty;
typedef System::DelphiInterface<IProperty> _di_IProperty;
__interface INTERFACE_UUID("{1D614791-77CA-11D1-AA6F-00C04FB17A72}") IReceivesProperties  : public IUnknown 
	
{
	
public:
	virtual void __fastcall NewProperty(_di_IProperty Prop) = 0 ;
};

__interface IReceivesStrings;
typedef System::DelphiInterface<IReceivesStrings> _di_IReceivesStrings;
__interface INTERFACE_UUID("{E3AA892A-77E1-11D1-AA6F-00C04FB17A72}") IReceivesStrings  : public IUnknown 
	
{
	
public:
	virtual void __fastcall NewString(const AnsiString Value) = 0 ;
};

__interface INTERFACE_UUID("{1D61478E-77CA-11D1-AA6F-00C04FB17A72}") IProperty  : public IUnknown 
{
	
public:
	virtual void __fastcall Activate(void) = 0 ;
	virtual bool __fastcall AllEqual(void) = 0 ;
	virtual bool __fastcall AutoFill(void) = 0 ;
	virtual void __fastcall Edit(void) = 0 ;
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void) = 0 ;
	virtual _di_IClassInfo __fastcall GetCompClassInfo(void) = 0 ;
	virtual int __fastcall GetEditLimit(void) = 0 ;
	virtual bool __fastcall GetEditValue(AnsiString &Value) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall GetProperties(_di_IReceivesProperties Container) = 0 ;
	virtual _di_IPropTypeInfo __fastcall GetPropTypeInfo(void) = 0 ;
	virtual AnsiString __fastcall GetValue(void) = 0 ;
	virtual void __fastcall GetValues(_di_IReceivesStrings Container) = 0 ;
	virtual void __fastcall Revert(void) = 0 ;
	virtual void __fastcall SetValue(const AnsiString Value) = 0 ;
	__property Dsgnintf::TPropertyAttributes Attributes = {read=GetAttributes};
	__property _di_IClassInfo CompClassInfo = {read=GetCompClassInfo};
	__property int EditLimit = {read=GetEditLimit};
	__property AnsiString Name = {read=GetName};
	__property _di_IPropTypeInfo ProptypeInfo = {read=GetPropTypeInfo};
	__property AnsiString Value = {read=GetValue, write=SetValue};
};

class PASCALIMPLEMENTATION TIProperty : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual void __fastcall Activate(void) = 0 ;
	virtual bool __fastcall AllEqual(void) = 0 ;
	virtual bool __fastcall AutoFill(void) = 0 ;
	virtual void __fastcall Edit(void) = 0 ;
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void) = 0 ;
	virtual AnsiString __fastcall GetCompClassName(void) = 0 ;
	virtual int __fastcall GetEditLimit(void) = 0 ;
	virtual bool __fastcall GetEditValue(AnsiString &Value) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall GetProperties(TGetPropProc Proc) = 0 ;
	virtual Typinfo::PTypeInfo __fastcall GetPropType(void) = 0 ;
	virtual AnsiString __fastcall GetValue(void) = 0 ;
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc) = 0 ;
	virtual void __fastcall Revert(void) = 0 ;
	virtual void __fastcall SetValue(const AnsiString Value) = 0 ;
	virtual TMetaClass* __fastcall GetCompClass(void) = 0 ;
	virtual void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		) = 0 ;
	virtual void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &
		AHeight) = 0 ;
	virtual void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected) = 0 ;
	virtual void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected) = 0 ;
	virtual void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool 
		ASelected) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIProperty(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIProperty(void) { }
	#pragma option pop
	
};


__interface ICompInfo;
typedef System::DelphiInterface<ICompInfo> _di_ICompInfo;
__interface INTERFACE_UUID("{AF859551-7401-11D1-9FBC-0020AF3D82DA}") ICompInfo  : public IUnknown 
{
	
public:
	virtual void __fastcall ClearEvent(int Index) = 0 ;
	virtual int __fastcall GetEventCount(void) = 0 ;
	virtual Typinfo::PPropInfo __fastcall GetEventInfo(int Index) = 0 ;
	virtual AnsiString __fastcall GetEventValue(int Index) = 0 ;
	virtual void * __fastcall GetComponentHandle(void) = 0 ;
	virtual int __fastcall GetSubInfoCount(void) = 0 ;
	virtual _di_ICompInfo __fastcall GetSubInfo(int Index) = 0 ;
};

class PASCALIMPLEMENTATION TICompInfo : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual void __fastcall ClearEvent(int Index) = 0 ;
	virtual AnsiString __fastcall GetClassName(void) = 0 ;
	virtual int __fastcall GetEventCount(void) = 0 ;
	virtual Typinfo::PPropInfo __fastcall GetEventInfo(int Index) = 0 ;
	virtual AnsiString __fastcall GetEventValue(int Index) = 0 ;
	virtual void * __fastcall GetComponentHandle(void) = 0 ;
	virtual AnsiString __fastcall GetNamePath(void) = 0 ;
	virtual int __fastcall GetSubInfoCount(void) = 0 ;
	virtual TICompInfo* __fastcall GetSubInfo(int Index) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TICompInfo(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TICompInfo(void) { }
	#pragma option pop
	
};


typedef _di_ILibrary __fastcall (*TInitLibraryFunc)(const _di_IDelphiIDE App);

class DELPHICLASS TGetStrProcToIReceivesStringsAdapter;
class PASCALIMPLEMENTATION TGetStrProcToIReceivesStringsAdapter : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TGetStrProc FGetStrProc;
	
public:
	__fastcall TGetStrProcToIReceivesStringsAdapter(Classes::TGetStrProc GetStrProc);
	void __fastcall NewString(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TGetStrProcToIReceivesStringsAdapter(void) { }
	#pragma option pop
	
private:
	void *__IReceivesStrings;	/* Libintf::IReceivesStrings */
	
public:
	operator IReceivesStrings*(void) { return (IReceivesStrings*)&__IReceivesStrings; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define LibrarySignature "COMPLIB0057"
extern PACKAGE _di_IDelphiIDE DelphiIDE;
extern PACKAGE _di_ILibrary CompLib;
extern PACKAGE Word CF_COMPONENTS;
extern PACKAGE bool __fastcall PossibleStream(const AnsiString S);
extern PACKAGE void __fastcall CopyStreamToClipboard(Classes::TMemoryStream* S);
extern PACKAGE Classes::TMemoryStream* __fastcall GetClipboardStream(void);
extern PACKAGE TIForm* __fastcall ActiveForm(void);

}	/* namespace Libintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Libintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// LibIntf
