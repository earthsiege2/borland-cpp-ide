// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ComponentDesigner.pas' rev: 6.00

#ifndef ComponentDesignerHPP
#define ComponentDesignerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <EditIntf.hpp>	// Pascal unit
#include <Events.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <ToolUtils.hpp>	// Pascal unit
#include <ToolsAPI.hpp>	// Pascal unit
#include <Update.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Designer.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Componentdesigner
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPaintItemStyles { piDown, piSelected, piFramed, piGhosted };
#pragma option pop

typedef Set<TPaintItemStyles, piDown, piGhosted>  TPaintItemStyle;

__interface IPalettePaint;
typedef System::DelphiInterface<IPalettePaint> _di_IPalettePaint;
__interface INTERFACE_UUID("{D9BAD01A-99D9-4661-A470-90C7BC743DC9}") IPalettePaint  : public IInterface 
{
	
public:
	virtual void __fastcall Paint(Graphics::TCanvas* Canvas, int X, int Y, TPaintItemStyle AStyle = System::Set<TPaintItemStyles, piDown, piGhosted> () ) = 0 ;
};

__interface IPaletteBits;
typedef System::DelphiInterface<IPaletteBits> _di_IPaletteBits;
__interface INTERFACE_UUID("{E99AAAD9-8686-49FE-9129-13606772BDD9}") IPaletteBits  : public IInterface 
{
	
public:
	virtual Classes::TStream* __fastcall GetBits(TPaintItemStyle AStyle = System::Set<TPaintItemStyles, piDown, piGhosted> () ) = 0 ;
	virtual int __fastcall GetID(void) = 0 ;
};

#pragma option push -b-
enum ComponentDesigner__1 { fsVisible, fsIconic, fsZoomed };
#pragma option pop

typedef Set<ComponentDesigner__1, fsVisible, fsZoomed>  TFormState;

__interface IDatedStream;
typedef System::DelphiInterface<IDatedStream> _di_IDatedStream;
__interface INTERFACE_UUID("{A8613563-3389-4BA7-9A8A-5A8FF324F317}") IDatedStream  : public IStream 
{
	
public:
	virtual int __fastcall GetModifyTime(void) = 0 ;
	virtual void __fastcall SetModifyTime(int Time) = 0 ;
};

__interface IFile;
typedef System::DelphiInterface<IFile> _di_IFile;
__interface INTERFACE_UUID("{346E7BA0-D47E-11D3-BA96-0080C78ADCDB}") IFile  : public IInterface 
{
	
public:
	virtual _di_IStream __fastcall FormFileOpen(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual int __fastcall GetTimeAtLoad(void) = 0 ;
	virtual int __fastcall GetModifyTime(void) = 0 ;
	virtual bool __fastcall CheckFileDate(void) = 0 ;
	virtual void __fastcall Rename(const AnsiString NewFileName) = 0 ;
	virtual void __fastcall Save(void) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
	__property int TimeAtLoad = {read=GetTimeAtLoad};
	__property int ModifyTime = {read=GetModifyTime};
};

#pragma option push -b-
enum TAffect { afTop, afLeft, afBottom, afRight, afHCenter, afVCenter, afHSpace, afVSpace, afHWinCenter, afVWinCenter, afNothing };
#pragma option pop

#pragma option push -b-
enum TSizeAffect { asHGrow, asHShrink, asHAbsolute, asVGrow, asVShrink, asVAbsolute, asNothing };
#pragma option pop

#pragma option push -b-
enum TShowState { ssNormal, ssMinimized, ssMaximized };
#pragma option pop

#pragma option push -b-
enum ComponentDesigner__2 { dsVisible, dsIconic, dsZoomed };
#pragma option pop

typedef Set<ComponentDesigner__2, dsVisible, dsZoomed>  TDesignerState;

__interface IRoot;
typedef System::DelphiInterface<IRoot> _di_IRoot;
typedef void __fastcall (__closure *TGetRootProc)(_di_IRoot AForm);

__interface IPaletteItem;
typedef System::DelphiInterface<IPaletteItem> _di_IPaletteItem;
__interface IDesignerModule;
typedef System::DelphiInterface<IDesignerModule> _di_IDesignerModule;
__interface INTERFACE_UUID("{F9D448F1-50BC-11D1-9FB5-0020AF3D82DA}") IPaletteItem  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall CreateComponent(const Classes::TComponent* Owner, const Classes::TComponent* Parent, const _di_IDesignerModule Module, const Types::TRect &Rect) = 0 ;
};

__interface ICompInfo;
typedef System::DelphiInterface<ICompInfo> _di_ICompInfo;
__interface INTERFACE_UUID("{AF859551-7401-11D1-9FBC-0020AF3D82DA}") ICompInfo  : public IInterface 
{
	
public:
	virtual void __fastcall ClearEvent(int Index) = 0 ;
	virtual AnsiString __fastcall GetClassName(void) = 0 ;
	virtual int __fastcall GetEventCount(void) = 0 ;
	virtual Typinfo::PPropInfo __fastcall GetEventInfo(int Index) = 0 ;
	virtual AnsiString __fastcall GetEventName(int Index) = 0 ;
	virtual AnsiString __fastcall GetEventValue(int Index) = 0 ;
	virtual void * __fastcall GetComponentHandle(void) = 0 ;
	virtual AnsiString __fastcall GetNamePath(void) = 0 ;
	virtual int __fastcall GetSubInfoCount(void) = 0 ;
	virtual _di_ICompInfo __fastcall GetSubInfo(int Index) = 0 ;
};

__interface IAlignable;
typedef System::DelphiInterface<IAlignable> _di_IAlignable;
__interface INTERFACE_UUID("{346E7BA3-D47E-11D3-BA96-0080C78ADCDB}") IAlignable  : public IInterface 
{
	
public:
	virtual void __fastcall Align(TAffect Affect) = 0 ;
	virtual void __fastcall Size(TSizeAffect Affect, int Value) = 0 ;
};

__interface IScaleable;
typedef System::DelphiInterface<IScaleable> _di_IScaleable;
__interface INTERFACE_UUID("{346E7BA6-D47E-11D3-BA96-0080C78ADCDB}") IScaleable  : public IInterface 
{
	
public:
	virtual void __fastcall Scale(int Factor) = 0 ;
};

__interface ITabOrderable;
typedef System::DelphiInterface<ITabOrderable> _di_ITabOrderable;
__interface INTERFACE_UUID("{346E7BA4-D47E-11D3-BA96-0080C78ADCDB}") ITabOrderable  : public IInterface 
{
	
public:
	virtual int __fastcall GetTabCompCount(void) = 0 ;
	virtual bool __fastcall GetTabCompInfo(int Order, AnsiString &Name, void * &Comp) = 0 ;
	virtual void __fastcall SetTabCompOrder(void * Comp, int Order) = 0 ;
};

__interface ICreateOrderable;
typedef System::DelphiInterface<ICreateOrderable> _di_ICreateOrderable;
__interface INTERFACE_UUID("{346E7BA5-D47E-11D3-BA96-0080C78ADCDB}") ICreateOrderable  : public IInterface 
{
	
public:
	virtual int __fastcall GetCompCount(void) = 0 ;
	virtual AnsiString __fastcall GetCompName(int Index) = 0 ;
	virtual void * __fastcall GetNVComp(int Index) = 0 ;
	virtual void __fastcall SetNVComp(void * Comp, int Order) = 0 ;
};

__interface INTERFACE_UUID("{346E7BA1-D47E-11D3-BA96-0080C78ADCDB}") IRoot  : public IFile 
{
	
public:
	virtual void __fastcall Close(void) = 0 ;
	virtual void __fastcall CreateComponent(_di_IPaletteItem Item) = 0 ;
	virtual AnsiString __fastcall FindCompClass(const AnsiString CompName) = 0 ;
	virtual AnsiString __fastcall GetAncestorName(void) = 0 ;
	virtual int __fastcall GetCompCount(void) = 0 ;
	virtual void __fastcall GetDependentRoots(TGetRootProc Proc) = 0 ;
	virtual AnsiString __fastcall GetDesignClassName(void) = 0 ;
	virtual void __fastcall GetDependencies(TGetRootProc Proc) = 0 ;
	virtual _di_ICompInfo __fastcall GetCompInfo(int Index) = 0 ;
	virtual _di_IDesignerModule __fastcall GetModule(void) = 0 ;
	virtual AnsiString __fastcall GetCompName(int Index) = 0 ;
	virtual AnsiString __fastcall GetFileSystem(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetRoot(void) = 0 ;
	virtual AnsiString __fastcall GetRootName(void) = 0 ;
	virtual void __fastcall GetUnits(Classes::TGetStrProc Proc) = 0 ;
	virtual TDesignerState __fastcall GetState(void) = 0 ;
	virtual void __fastcall Hide(void) = 0 ;
	virtual void __fastcall GoDormant(void) = 0 ;
	virtual void __fastcall RenameRootMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual bool __fastcall RenameComponent(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall RemoveDependentLinks(void) = 0 ;
	virtual void __fastcall SetFileSystem(const AnsiString FileSystem) = 0 ;
	virtual void __fastcall SetRootName(const AnsiString AName) = 0 ;
	virtual void __fastcall SetSelection(const AnsiString Name) = 0 ;
	virtual void __fastcall Show(void) = 0 ;
	virtual void __fastcall ShowAs(TShowState ShowState) = 0 ;
	virtual void __fastcall ShowComponentHelp(void) = 0 ;
	virtual bool __fastcall SpecialPropertyHelp(const AnsiString Member, /* out */ AnsiString &HelpFile, /* out */ AnsiString &Context, /* out */ Classes::THelpType &HelpType) = 0 ;
	virtual Designintf::_di_IDesigner __fastcall GetDesigner(void) = 0 ;
	virtual Toolsapi::_di_IOTAFormEditor __fastcall GetFormEditor(void) = 0 ;
	__property Classes::TComponent* Root = {read=GetRoot};
	__property _di_IDesignerModule Module = {read=GetModule};
};

typedef IDesignWindow IDesignWindowActions;
;

__interface IComponentDesigner;
typedef System::DelphiInterface<IComponentDesigner> _di_IComponentDesigner;
__interface IDesignEnvironment;
typedef System::DelphiInterface<IDesignEnvironment> _di_IDesignEnvironment;
__interface INTERFACE_UUID("{7ED7BF25-E349-11D3-AB4A-00C04FB17A72}") IComponentDesigner  : public IInterface 
{
	
public:
	virtual void __fastcall CopySelectionToStream(Classes::TMemoryStream* S, Classes::TStrings* UnitDependencies) = 0 ;
	virtual _di_IRoot __fastcall CreateRoot(const _di_IDesignerModule AModule, const AnsiString AFileName, bool Existing, const AnsiString ARootName, const AnsiString AAncestor, const AnsiString AFileSystem) = 0 ;
	virtual _di_IRoot __fastcall CreateFromStream(const _di_IDesignerModule AModule, const AnsiString AFileName, const AnsiString AFileSystem, const _di_IDatedStream Stream) = 0 ;
	virtual _di_IRoot __fastcall CreateNewRoot(const _di_IDesignerModule AModule, const AnsiString AFileName, const System::_di_IInterface Creator) = 0 ;
	virtual bool __fastcall Active(void) = 0 ;
	virtual void __fastcall DesignerOptionsChanged(void) = 0 ;
	virtual bool __fastcall EditAction(Designintf::TEditAction Action) = 0 ;
	virtual _di_IFile __fastcall FindFile(const AnsiString FileName) = 0 ;
	virtual _di_IRoot __fastcall FindRoot(Classes::TComponent* Component) = 0 /* overload */;
	virtual _di_IRoot __fastcall FindRoot(const AnsiString RootName) = 0 /* overload */;
	virtual _di_IRoot __fastcall GetActiveRoot(void) = 0 ;
	virtual void __fastcall GetClassUnits(const AnsiString ClassName, Classes::TGetStrProc Proc) = 0 ;
	virtual Designintf::TEditState __fastcall GetEditState(void) = 0 ;
	virtual AnsiString __fastcall GetFirstSelectionType(void) = 0 ;
	virtual void __fastcall GetRootNames(Classes::TGetStrProc Proc) = 0 ;
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc) = 0 ;
	virtual AnsiString __fastcall GetSelectionName(void) = 0 ;
	virtual AnsiString __fastcall GetSelectionType(void) = 0 ;
	virtual void __fastcall HideWindows(void) = 0 ;
	virtual void __fastcall ShowWindows(void) = 0 ;
	virtual void __fastcall ModalEditDone(const Designintf::_di_IActivatable ReturnWindow) = 0 ;
	virtual _di_IRoot __fastcall OpenRootClass(const AnsiString ClassName) = 0 ;
	virtual void __fastcall PasteSelectionFromStream(Classes::TMemoryStream* S, Classes::TComponent* Parent, const Types::TRect &Rect) = 0 ;
	virtual void __fastcall GetSelection(const Designintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall SetSelection(const Designintf::_di_IDesigner Designer, const Designintf::_di_IDesignWindow DesignWindow, const Designintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall CancelModes(void) = 0 ;
	virtual bool __fastcall GetControlsLocked(void) = 0 ;
	virtual void __fastcall SetControlsLocked(bool Value) = 0 ;
	virtual _di_IRoot __fastcall GetRoots(int Index) = 0 ;
	virtual int __fastcall GetRootsCount(void) = 0 ;
	virtual TMetaClass* __fastcall GetFirstSelectionClass(void) = 0 ;
	virtual bool __fastcall IsNestable(const AnsiString ClassName) = 0 ;
	virtual _di_IDesignEnvironment __fastcall GetEnvironment(void) = 0 ;
	virtual AnsiString __fastcall GetExtension(void) = 0 ;
	__property bool ControlsLocked = {read=GetControlsLocked, write=SetControlsLocked};
	__property _di_IRoot Roots[int Index] = {read=GetRoots};
	__property _di_IDesignEnvironment Environment = {read=GetEnvironment};
};

typedef DynamicArray<AnsiString >  TStringArray;

__interface IComponentDesigners;
typedef System::DelphiInterface<IComponentDesigners> _di_IComponentDesigners;
__interface INTERFACE_UUID("{82B1BC83-2E27-49D8-BF00-09E60D8BCC20}") IComponentDesigners  : public IInterface 
{
	
public:
	virtual bool __fastcall DesignerActive(void) = 0 ;
	virtual void __fastcall DesignerOptionsChanged(void) = 0 ;
	virtual _di_IFile __fastcall FindFile(const AnsiString Filename) = 0 ;
	virtual _di_IComponentDesigner __fastcall GetActiveDesigner(void) = 0 ;
	virtual void __fastcall HideWindows(void) = 0 ;
	virtual void __fastcall ShowWindows(void) = 0 ;
	virtual void __fastcall SetProjectName(const AnsiString Name) = 0 ;
	virtual void __fastcall SetControlsLocked(bool Value) = 0 ;
	virtual bool __fastcall GetControlsLocked(void) = 0 ;
	virtual _di_IAlignable __fastcall GetAlignable(void) = 0 ;
	virtual void __fastcall GetSelection(const Designintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall SetSelection(const Designintf::_di_IDesigner Designer, const Designintf::_di_IDesignWindow DesignWindow, const Designintf::_di_IDesignerSelections ASelection) = 0 ;
	virtual void __fastcall ShowComponentHelp(void) = 0 ;
	virtual bool __fastcall SpecialPropertyHelp(const AnsiString Member, /* out */ AnsiString &HelpFile, /* out */ AnsiString &Context, /* out */ Classes::THelpType &HelpType) = 0 ;
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc) = 0 ;
	virtual AnsiString __fastcall GetFirstSelectionType(void) = 0 ;
	virtual TStringArray __fastcall RegisteredExtensions(void) = 0 ;
	virtual _di_IComponentDesigner __fastcall DesignerFromExtension(const AnsiString Extension) = 0 ;
	virtual bool __fastcall RootComponentClass(TMetaClass* ClassRef) = 0 ;
};

__interface IComponentPaletteItem;
typedef System::DelphiInterface<IComponentPaletteItem> _di_IComponentPaletteItem;
__interface INTERFACE_UUID("{707992A9-F11A-11D2-AAD2-00C04FB16FBC}") IComponentPaletteItem  : public IPaletteItem 
{
	
public:
	virtual TMetaClass* __fastcall GetComponentClass(void) = 0 ;
};

__interface IInternalComponentDesigner;
typedef System::DelphiInterface<IInternalComponentDesigner> _di_IInternalComponentDesigner;
__interface INTERFACE_UUID("{7ED7BF31-E349-11D3-AB4A-00C04FB17A72}") IInternalComponentDesigner  : public IComponentDesigner 
{
	
public:
	virtual void __fastcall RemoveDependenciesOn(const Classes::TComponent* Component) = 0 ;
	virtual void __fastcall RootListAdd(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootListRemove(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootGoingDormant(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootActivated(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootModified(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall UpdateRootDependents(void) = 0 ;
	virtual void __fastcall UpdateSelections(void) = 0 ;
	virtual Classes::TStream* __fastcall FileSystemFileOpen(const AnsiString FileSystem, const AnsiString FileName, int Mode) = 0 ;
	virtual int __fastcall FileSystemFileAge(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual bool __fastcall FileSystemFileExists(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual bool __fastcall FileSystemRenameFile(const AnsiString FileSystem, const AnsiString OldFileName, const AnsiString NewFileName) = 0 ;
	virtual AnsiString __fastcall FileSystemGetTempFileName(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual AnsiString __fastcall FileSystemGetBackupName(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual bool __fastcall FileSystemIsReadOnly(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual void __fastcall FileSystemDeleteFile(const AnsiString FileSystem, const AnsiString FileName) = 0 ;
	virtual void __fastcall FileSystemSetDate(const AnsiString FileSystem, Classes::TStream* FileStream, int Age) = 0 ;
	virtual AnsiString __fastcall FindBaseClass(const AnsiString AClassName) = 0 ;
	virtual TMetaClass* __fastcall FindCustomModuleClass(const AnsiString AClassName) = 0 ;
	virtual bool __fastcall IsRootBaseClass(const AnsiString AClassName) = 0 ;
	virtual bool __fastcall ValidBaseClass(TMetaClass* ComponentClass) = 0 ;
};

__interface IInternalComponentDesigners;
typedef System::DelphiInterface<IInternalComponentDesigners> _di_IInternalComponentDesigners;
__interface INTERFACE_UUID("{FE5E8AD1-28D6-4D96-B5E7-455A2A8B9FC5}") IInternalComponentDesigners  : public IComponentDesigners 
{
	
public:
	virtual void __fastcall AddDesigner(const _di_IInternalComponentDesigner Designer) = 0 ;
	virtual void __fastcall RemoveDesigner(const _di_IInternalComponentDesigner Designer) = 0 ;
	virtual void __fastcall ActivateDesigner(const _di_IInternalComponentDesigner Designer) = 0 ;
	virtual void __fastcall RemoveRoot(const _di_IRoot ARoot) = 0 ;
};

#pragma option push -b-
enum TDesignDialog { ddAlign, ddSize, ddScale, ddTabOrder, ddCreationOrder, ddSaveTemplate };
#pragma option pop

#pragma option push -b-
enum TDesignCommand { dmAlignToGrid, dmFlipAllChildren, dmFlipSelectedChildren, dmTextDFM, dmViewAsText, dmRevert };
#pragma option pop

#pragma pack(push, 4)
struct TDesignerOptions
{
	bool DisplayGrid;
	bool SnapToGrid;
	int GridSizeX;
	int GridSizeY;
	bool ShowComponentCaptions;
	bool ShowDesignerHints;
	bool DFMFormat;
	bool ShowNonVisualComponents;
	bool ShowExtendedControlHints;
} ;
#pragma pack(pop)

__interface INTERFACE_UUID("{7ED7BF2B-E349-11D3-AB4A-00C04FB17A72}") IDesignEnvironment  : public IInterface 
{
	
public:
	virtual void __fastcall ActiveRootModified(void) = 0 ;
	virtual void __fastcall ComponentRenamed(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual Classes::TComponent* __fastcall FindComponent(const AnsiString Name) = 0 ;
	virtual void __fastcall ExecDesignDialog(TDesignDialog DesignDialog) = 0 ;
	virtual void __fastcall RootActivated(void) = 0 ;
	virtual AnsiString __fastcall GetPathAndBaseExeName(void) = 0 ;
	virtual AnsiString __fastcall GetPrivateDirectory(void) = 0 ;
	virtual AnsiString __fastcall GetBaseRegKey(void) = 0 ;
	virtual Inifiles::TCustomIniFile* __fastcall GetIDEOptions(void) = 0 ;
	virtual bool __fastcall GetToolSelected(void) = 0 ;
	virtual _di_IPaletteItem __fastcall GetCurCompClass(void) = 0 ;
	virtual _di_IPaletteItem __fastcall GetPaletteItem(TMetaClass* ComponentClass) = 0 ;
	virtual int __fastcall GetCurTime(void) = 0 ;
	virtual void __fastcall GetDesignerOptions(TDesignerOptions &Options) = 0 ;
	virtual Types::TRect __fastcall GetMainWindowSize(void) = 0 ;
	virtual Types::TPoint __fastcall GetWorkspaceOrigin(void) = 0 ;
	virtual Events::TEvent* __fastcall GetPackagesEvInstalled(void) = 0 ;
	virtual Events::TEvent* __fastcall GetPackagesEvUninstalling(void) = 0 ;
	virtual void __fastcall ModalEdit(char EditKey, const Designintf::_di_IActivatable ReturnWindow) = 0 ;
	virtual void __fastcall OpenRoot(const AnsiString RootName, bool Show) = 0 ;
	virtual void __fastcall ResetCompClass(void) = 0 ;
	virtual void __fastcall SelectionChanged(void) = 0 ;
	virtual void __fastcall ShowClassHelp(const AnsiString ClassName) = 0 ;
	virtual void __fastcall ShowContextHelp(const AnsiString HelpFile, int Command, int Data) = 0 ;
	virtual void __fastcall SelectItemName(const AnsiString PropertyName) = 0 ;
	virtual bool __fastcall CreateBackupFile(void) = 0 ;
	virtual void __fastcall RequestTemplate(const AnsiString CompName, Classes::TStream* Stream, Classes::TStrings* Dependencies) = 0 ;
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem) = 0 ;
	__property Events::TEvent* PackagesEvUninstalling = {read=GetPackagesEvUninstalling};
	__property Events::TEvent* PackagesEvInstalled = {read=GetPackagesEvInstalled};
};

__interface INTERFACE_UUID("{7ED7BF27-E349-11D3-AB4A-00C04FB17A72}") IDesignerModule  : public IInterface 
{
	
public:
	virtual void __fastcall Activate(bool IsVisual) = 0 ;
	virtual void __fastcall CreateMethod(const AnsiString Name, Typinfo::PTypeData TypeData) = 0 ;
	virtual void __fastcall RootModified(void) = 0 ;
	virtual AnsiString __fastcall GetAncestorClassName(const AnsiString ClassName) = 0 ;
	virtual void __fastcall GetMethods(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc) = 0 ;
	virtual bool __fastcall GetRootIsTopmost(void) = 0 ;
	virtual void __fastcall RootResurrected(void) = 0 ;
	virtual bool __fastcall MethodExists(const AnsiString Name) = 0 ;
	virtual void __fastcall RenameComponent(const _di_ICompInfo CompInfo, const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall RenameRoot(const _di_ICompInfo CompInfo, const AnsiString NewName) = 0 ;
	virtual void __fastcall RenameMethod(const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall ShowMethod(const AnsiString Name) = 0 ;
	virtual void __fastcall GetImportedRoots(Classes::TGetStrProc Proc) = 0 ;
	virtual void __fastcall ImportRoot(const AnsiString RootName) = 0 ;
	virtual void __fastcall RootSaving(void) = 0 ;
	virtual void __fastcall Notify(Editintf::TNotifyCode NotifyCode) = 0 ;
	virtual void __fastcall SwapSourceVisualView(void) = 0 ;
	virtual AnsiString __fastcall GetMethod(const AnsiString MethodName) = 0 ;
	virtual void __fastcall AddMethods(AnsiString Methods, Classes::TStrings* Replacements, Classes::TStrings* MethodNames) = 0 ;
	virtual void __fastcall GetProjectModules(Classes::TGetModuleProc Proc) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	virtual void __fastcall ChainCall(const AnsiString MethodName, const AnsiString InstanceName, const AnsiString InstanceMethod, Typinfo::PTypeData TypeData) = 0 ;
	virtual bool __fastcall GetUnnamed(void) = 0 ;
	virtual bool __fastcall SaveModule(void) = 0 ;
	virtual void __fastcall ValidateEdit(void) = 0 ;
	__property bool RootIsTopmost = {read=GetRootIsTopmost};
	__property bool ReadOnly = {read=GetReadOnly};
	__property bool Unnamed = {read=GetUnnamed};
};

__interface IInterfaceDesigner;
typedef System::DelphiInterface<IInterfaceDesigner> _di_IInterfaceDesigner;
__interface INTERFACE_UUID("{7ED7BF28-E349-11D3-AB4A-00C04FB17A72}") IInterfaceDesigner  : public IInterface 
{
	
public:
	virtual bool __fastcall HasInterface(void) = 0 ;
	virtual bool __fastcall InterfaceMemberExists(const AnsiString Name) = 0 ;
	virtual void __fastcall AddToInterface(int InvKind, const AnsiString Name, Word VT, const AnsiString TypeInfo) = 0 ;
};

__interface IInternalRoot;
typedef System::DelphiInterface<IInternalRoot> _di_IInternalRoot;
class DELPHICLASS TComponentRoot;
__interface INTERFACE_UUID("{7ED7BF2C-E349-11D3-AB4A-00C04FB17A72}") IInternalRoot  : public IRoot 
{
	
public:
	virtual bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual void __fastcall CancelModes(void) = 0 ;
	virtual void __fastcall CopySelectionToStream(Classes::TMemoryStream* S, Classes::TStrings* UnitDependencies) = 0 ;
	virtual void __fastcall DesignerHide(void) = 0 ;
	virtual void __fastcall DesignerShow(void) = 0 ;
	virtual void __fastcall Edit(const Classes::TComponent* Component) = 0 ;
	virtual TMetaClass* __fastcall GetCustomModuleClass(void) = 0 ;
	virtual AnsiString __fastcall GetRootBaseClass(void) = 0 ;
	virtual TMetaClass* __fastcall GetRootClass(void) = 0 ;
	virtual Designintf::_di_ICustomModule __fastcall GetCustomModule(void) = 0 ;
	virtual _di_IInternalComponentDesigner __fastcall GetComponentDesigner(void) = 0 ;
	virtual Update::_di_IUpdateManager __fastcall GetUpdateManager(void) = 0 ;
	virtual TComponentRoot* __fastcall Implementor(void) = 0 ;
	virtual bool __fastcall IsDormant(void) = 0 ;
	virtual bool __fastcall IsFrame(Classes::TPersistent* AInstance) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall PasteSelectionFromStream(Classes::TMemoryStream* S, Classes::TComponent* Parent, const Types::TRect &Rect) = 0 ;
	virtual void __fastcall RemoveDependenciesOn(const Classes::TComponent* Component) = 0 ;
	virtual void __fastcall Resurrect(void) = 0 ;
	virtual void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual void __fastcall Select(Classes::TPersistent* Component, bool Extend) = 0 ;
	virtual void __fastcall SetActive(bool Value) = 0 ;
	virtual void __fastcall SetControlsLocked(bool Value) = 0 ;
	virtual void __fastcall UpdateDependencies(void) = 0 ;
	virtual void __fastcall UpdateOptions(void) = 0 ;
	__property AnsiString RootBaseClass = {read=GetRootBaseClass};
	__property TMetaClass* RootClass = {read=GetRootClass};
	__property TMetaClass* CustomModuleClass = {read=GetCustomModuleClass};
	__property Designintf::_di_ICustomModule CustomModule = {read=GetCustomModule};
	__property Update::_di_IUpdateManager UpdateManager = {read=GetUpdateManager};
	__property _di_IInternalComponentDesigner Designer = {read=GetComponentDesigner};
};

#pragma pack(push, 1)
struct TDesignSurfaceOptions
{
	bool DisplayGrid;
	Types::TPoint GridSize;
	bool ShowComponentCaptions;
	bool ShowDesignerHints;
	bool ShowNonVisualComponents;
	bool ShowExtendedControlHints;
} ;
#pragma pack(pop)

__interface IComponentDesignSurface;
typedef System::DelphiInterface<IComponentDesignSurface> _di_IComponentDesignSurface;
__interface INTERFACE_UUID("{7ED7BF33-E349-11D3-AB4A-00C04FB17A72}") IComponentDesignSurface  : public IDesignSurface 
{
	
public:
	virtual Designer::_di_IItem __fastcall ItemFor(Classes::TPersistent* APersistent) = 0 ;
	virtual void __fastcall MoveContainersFront(void) = 0 ;
	virtual void __fastcall ResyncContainers(void) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
	virtual void __fastcall InstanceRemoved(Classes::TPersistent* AInstance) = 0 ;
	virtual Classes::TShiftState __fastcall GetShiftState(void) = 0 ;
	virtual void __fastcall FlipContainers(void) = 0 ;
	virtual void __fastcall SetOptions(const TDesignSurfaceOptions &Value) = 0 ;
	virtual void __fastcall SetInitializing(bool Value) = 0 ;
};

__interface ISurfaceHost;
typedef System::DelphiInterface<ISurfaceHost> _di_ISurfaceHost;
__interface INTERFACE_UUID("{5DAEC2D5-5746-4DAD-ABD0-61ED54BFFF25}") ISurfaceHost  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall FindGlobalComponent(const AnsiString Name) = 0 ;
	virtual Designintf::_di_ICustomModule __fastcall GetCustomModule(void) = 0 ;
	virtual Designintf::_di_ISelectionEditorList __fastcall GetSelectionEditors(void) = 0 ;
	virtual Designintf::_di_IComponentEditor __fastcall GetComponentEditor(void) = 0 ;
	virtual Designer::_di_IItem __fastcall FindSelection(Classes::TPersistent* Instance) = 0 ;
	virtual _di_IPaletteItem __fastcall GetPaletteItem(TMetaClass* ComponentClass) = 0 ;
	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual void __fastcall InstanceInserted(Classes::TPersistent* AInstance) = 0 ;
	virtual void __fastcall InstanceRemoved(Classes::TPersistent* AInstance) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual bool __fastcall ModifiableFrame(Classes::TComponent* AComponent) = 0 ;
	virtual void __fastcall ValidateModification(void) = 0 ;
	virtual bool __fastcall HasSelectableChildren(Classes::TComponent* AComponent) = 0 ;
	virtual AnsiString __fastcall UniqueName(const AnsiString ClassName) = 0 ;
	virtual void __fastcall EditComponent(const Classes::TComponent* Component) = 0 ;
	virtual void __fastcall Activate(bool Activating) = 0 ;
	virtual bool __fastcall GetTextDFM(void) = 0 ;
	virtual bool __fastcall CanRevert(void) = 0 ;
	virtual bool __fastcall CanModify(void) = 0 ;
	virtual Designintf::_di_IDesignerSelections __fastcall GetSelection(void) = 0 ;
	virtual bool __fastcall GetLocked(void) = 0 ;
	virtual bool __fastcall CanUndelete(void) = 0 ;
	virtual void __fastcall Dialog(TDesignDialog Dialog) = 0 ;
	virtual void __fastcall Command(TDesignCommand Command) = 0 ;
	virtual void __fastcall DoUndelete(void) = 0 ;
	virtual void __fastcall DeleteSelection(bool ADoAll = false) = 0 ;
	virtual void __fastcall ShowHelp(void) = 0 ;
	virtual void __fastcall ModalEdit(char EditKey, const Designintf::_di_IActivatable ReturnWindow) = 0 ;
	virtual void __fastcall SelectItemName(const AnsiString PropertyName) = 0 ;
	virtual int __fastcall GetSelectableComponentCount(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetSelectableComponents(int Index) = 0 ;
	__property int SelectableComponentCount = {read=GetSelectableComponentCount};
	__property Classes::TComponent* SelectableComponents[int Index] = {read=GetSelectableComponents};
};

class DELPHICLASS TOTAComponent;
class PASCALIMPLEMENTATION TOTAComponent : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TPersistent* FObject;
	TComponentRoot* FComponentRoot;
	Typinfo::PPropInfo *FPropList;
	Toolsapi::TOTAGetChildCallback FProc;
	void *FParam;
	Typinfo::PPropList __fastcall GetPropList(void);
	void __fastcall GetChildProc(Classes::TComponent* Child);
	
protected:
	AnsiString __fastcall GetComponentType();
	void * __fastcall GetComponentHandle(void);
	Toolsapi::_di_IOTAComponent __fastcall GetParent();
	bool __fastcall IsTControl(void);
	int __fastcall GetPropCount(void);
	AnsiString __fastcall GetPropName(int Index);
	Typinfo::TTypeKind __fastcall GetPropType(int Index);
	Typinfo::TTypeKind __fastcall GetPropTypeByName(const AnsiString Name);
	bool __fastcall GetPropValue(int Index, void *Value);
	bool __fastcall GetPropValueByName(const AnsiString Name, void *Value);
	bool __fastcall SetProp(int Index, const void *Value);
	bool __fastcall SetPropByName(const AnsiString Name, const void *Value);
	bool __fastcall GetChildren(void * Param, Toolsapi::TOTAGetChildCallback Proc);
	int __fastcall GetControlCount(void);
	Toolsapi::_di_IOTAComponent __fastcall GetControl(int Index);
	int __fastcall GetComponentCount(void);
	Toolsapi::_di_IOTAComponent __fastcall GetComponent(int Index);
	bool __fastcall Select(bool AddToSelection);
	bool __fastcall Focus(bool AddToSelection);
	bool __fastcall Delete(void);
	Classes::TPersistent* __fastcall INTAComponent_GetPersistent(void);
	Classes::TComponent* __fastcall INTAComponent_GetComponent(void);
	
public:
	__fastcall TOTAComponent(Classes::TPersistent* AObject, TComponentRoot* AComponentRoot);
	__fastcall virtual ~TOTAComponent(void);
private:
	void *__IOTAComponent;	/* Toolsapi::IOTAComponent */
	void *__INTAComponent;	/* Toolsapi::INTAComponent [GetComponent=INTAComponent_GetComponent, GetPersistent=INTAComponent_GetPersistent] */
	
public:
	operator INTAComponent*(void) { return (INTAComponent*)&__INTAComponent; }
	operator IOTAComponent*(void) { return (IOTAComponent*)&__IOTAComponent; }
	
};


class DELPHICLASS TOTAFormEditor;
class PASCALIMPLEMENTATION TOTAFormEditor : public Toolutils::TOTAClass 
{
	typedef Toolutils::TOTAClass inherited;
	
private:
	TComponentRoot* FComponentRoot;
	
protected:
	int __fastcall AddNotifier(const Toolsapi::_di_IOTANotifier ANotifier);
	AnsiString __fastcall GetFileName();
	bool __fastcall GetModified(void);
	Toolsapi::_di_IOTAModule __fastcall GetModule();
	bool __fastcall MarkModified(void);
	void __fastcall RemoveNotifier(int Index);
	void __fastcall Show(void);
	Toolsapi::_di_IOTAComponent __fastcall GetRootComponent();
	Toolsapi::_di_IOTAComponent __fastcall FindComponent(const AnsiString Name);
	Toolsapi::_di_IOTAComponent __fastcall GetComponentFromHandle(void * ComponentHandle);
	int __fastcall GetSelCount(void);
	Toolsapi::_di_IOTAComponent __fastcall GetSelComponent(int Index);
	Toolsapi::_di_IOTAComponent __fastcall GetCreateParent();
	Toolsapi::_di_IOTAComponent __fastcall CreateComponent(const Toolsapi::_di_IOTAComponent Container, const AnsiString TypeName, int X, int Y, int W, int H);
	void __fastcall GetFormResource(const _di_IStream Stream);
	Designintf::_di_IDesigner __fastcall GetFormDesigner();
	void __fastcall INTAFormEditor_GetFormResource(Classes::TStream* Stream);
	
public:
	__fastcall TOTAFormEditor(TComponentRoot* AComponentRoot);
	void __fastcall FormModified(void);
	void __fastcall NotifyFormModified(System::_di_IInterface Unk, System::_di_IInterface UnkParam);
	void __fastcall FormSaving(void);
	void __fastcall NotifyFormSaving(System::_di_IInterface Unk, System::_di_IInterface UnkParam);
	void __fastcall NotifyActivate(void);
	void __fastcall NotifyActivated(System::_di_IInterface Unk, System::_di_IInterface UnkParam);
	void __fastcall NotifyDestruct(void);
	void __fastcall NotifyRenamed(Classes::TComponent* Component, const AnsiString OldName, const AnsiString NewName);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOTAFormEditor(void) { }
	#pragma option pop
	
private:
	void *__IOTAFormEditor;	/* Toolsapi::IOTAFormEditor */
	void *__INTAFormEditor;	/* Toolsapi::INTAFormEditor [GetFormResource=INTAFormEditor_GetFormResource] */
	
public:
	operator INTAFormEditor*(void) { return (INTAFormEditor*)&__INTAFormEditor; }
	operator IOTAFormEditor*(void) { return (IOTAFormEditor*)&__IOTAFormEditor; }
	operator IOTAEditor*(void) { return (IOTAEditor*)&__IOTAFormEditor; }
	
};


class DELPHICLASS TSelections;
class PASCALIMPLEMENTATION TSelections : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	Classes::TPersistent* operator[](int Index) { return Persistents[Index]; }
	
private:
	Designer::_di_ISelections FSelections;
	Classes::TNotifyEvent FOnChanged;
	void __fastcall SelectionChanged(const Designer::_di_ISelections Selections);
	int __fastcall GetCount(void);
	Classes::TPersistent* __fastcall GetPersistents(int Index);
	
public:
	__fastcall TSelections(const Designer::_di_ISelections Selections);
	__fastcall virtual ~TSelections(void);
	Designer::_di_IItem __fastcall FindItemFor(const Classes::TPersistent* Obj);
	__property int Count = {read=GetCount, nodefault};
	__property Designer::_di_ISelections Items = {read=FSelections};
	__property Classes::TPersistent* Persistents[int Index] = {read=GetPersistents/*, default*/};
	__property Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
private:
	void *__ISelectionsListener;	/* Designer::ISelectionsListener */
	
public:
	operator ISelectionsListener*(void) { return (ISelectionsListener*)&__ISelectionsListener; }
	
};


class DELPHICLASS TRenameItem;
class PASCALIMPLEMENTATION TRenameItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Source;
	AnsiString Target;
	__fastcall TRenameItem(const AnsiString ASource, const AnsiString ATarget);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TRenameItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRenames;
class PASCALIMPLEMENTATION TRenames : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TRenameItem* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FList;
	int __fastcall GetCount(void);
	TRenameItem* __fastcall GetItems(int Index);
	
public:
	__fastcall TRenames(void);
	__fastcall virtual ~TRenames(void);
	void __fastcall Add(AnsiString Source, AnsiString Target);
	void __fastcall Rename(AnsiString &Name);
	__property int Count = {read=GetCount, nodefault};
	__property TRenameItem* Items[int Index] = {read=GetItems/*, default*/};
};


class DELPHICLASS TEventItem;
class PASCALIMPLEMENTATION TEventItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void *Value;
	AnsiString Name;
	AnsiString OriginalName;
	void *NewValue;
	__fastcall TEventItem(void * AValue, const AnsiString AName);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEventItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEvents;
class PASCALIMPLEMENTATION TEvents : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TEventItem* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FList;
	int __fastcall GetCount(void);
	TEventItem* __fastcall GetItems(int Index);
	
public:
	__fastcall TEvents(void);
	__fastcall virtual ~TEvents(void);
	void __fastcall Add(void * Value, AnsiString MethodName);
	__property int Count = {read=GetCount, nodefault};
	__property TEventItem* Items[int Index] = {read=GetItems/*, default*/};
};


#pragma option push -b-
enum TRootReadErrorResult { rerOK, rerCancel, rerIgnoreAll };
#pragma option pop

#pragma option push -b-
enum TRecoveryResult { rrDelete, rrRename, rrCreate, rrCancel };
#pragma option pop

#pragma option push -b-
enum TQueryRedirectLinksResult { qrYes, qrNo, qrCancel };
#pragma option pop

#pragma option push -b-
enum TDeleteWarnResult { dwYes, dwNo, dwCancel };
#pragma option pop

typedef DynamicArray<Classes::TComponent* >  TComponentArray;

class PASCALIMPLEMENTATION TComponentRoot : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IInternalComponentDesigner FDesigner;
	_di_IDesignerModule FModule;
	_di_IComponentDesignSurface FSurface;
	Designer::_di_ISurfaceDesigner FSurfaceDesigner;
	Update::_di_IUpdateManager FRootUpdateManager;
	Classes::_di_IInterfaceList FUpdateManagers;
	_di_IInternalRoot FAncestorRoot;
	Designintf::_di_IComponentEditor FRootEditor;
	Designintf::_di_ICustomModule FCustomModule;
	AnsiString FFileSystem;
	AnsiString FFileName;
	AnsiString FRootBaseClass;
	AnsiString FRootName;
	DynamicArray<Classes::TComponent* >  FSelectableComponents;
	#pragma pack(push, 1)
	Types::TRect FAdjustmentRect;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect FAdjustmentBounds;
	#pragma pack(pop)
	
	Classes::TComponent* FRoot;
	TMetaClass*FRootClass;
	TMetaClass*FCustomModuleClass;
	TSelections* FSelections;
	Classes::_di_IInterfaceList FMarkedItems;
	System::_di_IInterface FSelectionsRef;
	Classes::TStrings* FUnitDependencies;
	Classes::TStrings* FImportedRootList;
	Classes::TStream* FRootStream;
	Classes::TStream* FDormantStream;
	Classes::TStream* FUndoStream;
	Classes::TComponent* FUndoParent;
	Classes::TList* FDependencies;
	Classes::TList* FDependents;
	Classes::TList* FModifiableFrames;
	TRenames* FRenames;
	TEvents* FEvents;
	int FModifyTime;
	int FDiskAge;
	bool FInUndo;
	bool FCreateContainers;
	bool FRevertingComponent;
	bool FDependenciesUpToDate;
	bool FReadError;
	bool FDFMToText;
	Classes::TStreamOriginalFormat FOrigDFMFormat;
	bool FCreateFrameManagers;
	bool FIgnoringErrors;
	bool FIgnoreNext;
	bool FResurrecting;
	bool FAllowNoSelection;
	bool FIgnoreRename;
	TOTAFormEditor* FOTAFormEditor;
	System::_di_IInterface FOTAFormEditorRef;
	void __fastcall ClearDependents(void);
	void __fastcall ClearDependencies(void);
	Classes::TComponent* __fastcall DoCreateComponent(const _di_IPaletteItem Item, Designer::_di_IItem ParentItem, const Types::TRect &Rect);
	void __fastcall EnsureSelectableComponents(void);
	Designer::_di_IItem __fastcall FindItemParent(const Designer::_di_IItem Item);
	TComponentRoot* __fastcall GetComponentRootFor(const Classes::TComponent* Root)/* overload */;
	TComponentRoot* __fastcall GetComponentRootFor(const AnsiString RootName)/* overload */;
	_di_IDesignEnvironment __fastcall GetEnvironment();
	Classes::TStream* __fastcall GetRootStream(void);
	void __fastcall IterateMethods(void * Func);
	void __fastcall WriterFindAncestor(Classes::TWriter* Writer, Classes::TComponent* Component, const AnsiString Name, Classes::TComponent* &Ancestor, Classes::TComponent* &RootAncestor);
	void __fastcall CreateFromStream(const Classes::TStream* Stream);
	Classes::TStream* __fastcall PrepareInputStream(const Classes::TStream* Strm, bool MatchFormat);
	void __fastcall GetCreateInfoFrom(const Classes::TStream* Stream, AnsiString &ClassName, AnsiString &AncestorClassName);
	_di_IRoot __fastcall FindAncestorRoot(const AnsiString AncestorClassName);
	void __fastcall SetCreateInfo(const AnsiString AncestorClassName);
	Classes::TComponent* __fastcall CreateRootInstance(const AnsiString AClassName);
	void __fastcall ValidateInheritence(Classes::TComponent* Root);
	Classes::TComponent* __fastcall CreateRootAs(const AnsiString AClassName, const AnsiString AAncestorClassName);
	void __fastcall FindObjectMethod(Classes::TReader* Reader, const AnsiString MethodName, void * &Address, bool &Error);
	void __fastcall ReaderObjectError(Classes::TReader* Reader, const AnsiString Message, bool &Handled);
	void __fastcall ReaderAncestorNotFound(Classes::TReader* Reader, const AnsiString ComponentName, TMetaClass* ComponentClass, Classes::TComponent* &Component);
	void __fastcall ReaderFindComponentClass(Classes::TReader* Reader, const AnsiString ClassName, TMetaClass* &ComponentClass);
	void __fastcall ReaderCreateComponent(Classes::TReader* Reader, TMetaClass* ComponentClass, Classes::TComponent* &Component);
	Classes::TComponent* __fastcall FrameCreateComponent(TMetaClass* ComponentClass, Classes::TComponent* Owner);
	void __fastcall AddClassProps(Classes::TList* ClassList, System::TObject* Obj);
	void __fastcall WriteRootStream(Classes::TStream* S);
	void __fastcall LoadDependentModules(Classes::TComponent* Component);
	void __fastcall ResurrectDependentModules(Classes::TComponent* Component);
	void __fastcall ClearDependenciesOn(const Classes::TComponent* Dependent);
	void __fastcall RenameEvents(void);
	void __fastcall VerifyEvents(Classes::TStrings* NewEvents);
	void __fastcall UpdateEvents(void);
	void __fastcall ReaderSetName(Classes::TReader* Reader, Classes::TComponent* Component, AnsiString &Name);
	void __fastcall ReaderReferenceName(Classes::TReader* Reader, AnsiString &Name);
	void __fastcall ReaderFindMethod(Classes::TReader* Reader, const AnsiString MethodName, void * &Address, bool &Error);
	void __fastcall ComponentRead(Classes::TComponent* Component);
	void __fastcall ComponentReadAdjust(Classes::TComponent* Component);
	void __fastcall AddImportedRoot(const AnsiString RootName);
	void __fastcall InternalInitializeDesigner(bool AResurrecting = false);
	void __fastcall InternalDeinitializeDesigner(bool AGoingDormant = false);
	void __fastcall SelectionsChanged(System::TObject* Sender);
	void __fastcall ModifiedUpdateNotification(void);
	
protected:
	void __fastcall BringToFront(void);
	void __fastcall SendToBack(void);
	void __fastcall SelectAll(void);
	void __fastcall ZOrder(bool Front);
	void __fastcall AlignToGrid(void);
	Classes::TComponent* __fastcall CompIndexToComponent(int Index);
	Classes::TComponent* __fastcall FindCurrentParent(void);
	Designer::_di_IItem __fastcall FindCurrentParentItem();
	void __fastcall ForceCommonParent(void);
	bool __fastcall IsRootSelected(void);
	void __fastcall SelectReadStream(const Classes::TStream* S, const Classes::TComponent* Parent, bool AdjustPos, const Types::TRect &Rect);
	void __fastcall ReadStream(const Classes::TStream* S, const Classes::TComponent* Parent, bool AdjustPos, const Types::TRect &Rect);
	virtual void __fastcall ReadObjectFromStream(Classes::TComponent* Instance, const Classes::TStream* Stream);
	Classes::TPersistent* __fastcall SelectedPersistent(void);
	Classes::TComponent* __fastcall SelectedComponent(void);
	void __fastcall StreamSelection(const Classes::TStream* S, bool CopyMethods, bool CopyBounds, Classes::TStrings* UnitDependencies);
	void __fastcall ValidateComponent(Classes::TComponent* Component);
	__property _di_IDesignerModule Module = {read=FModule};
	__property Classes::TList* Dependencies = {read=FDependencies};
	__property Classes::TList* Dependents = {read=FDependents};
	__property _di_IDesignEnvironment Environment = {read=GetEnvironment};
	__property Classes::TComponent* Root = {read=FRoot};
	__property AnsiString RootBaseClass = {read=FRootBaseClass};
	__property _di_IComponentDesignSurface Surface = {read=FSurface, write=FSurface};
	__property Designer::_di_ISurfaceDesigner SurfaceDesigner = {read=FSurfaceDesigner, write=FSurfaceDesigner};
	__property TSelections* Selections = {read=FSelections};
	__property Update::_di_IUpdateManager RootUpdateManager = {read=FRootUpdateManager};
	__property Classes::_di_IInterfaceList UpdateManagers = {read=FUpdateManagers};
	__property _di_IInternalComponentDesigner Designer = {read=FDesigner};
	__property Classes::TStream* UndoStream = {read=FUndoStream};
	__property TOTAFormEditor* OTAFormEditor = {read=FOTAFormEditor};
	_di_IStream __fastcall FormFileOpen();
	AnsiString __fastcall GetFileName();
	int __fastcall GetTimeAtLoad(void);
	int __fastcall GetModifyTime(void);
	bool __fastcall CheckFileDate(void);
	void __fastcall Rename(const AnsiString NewFileName);
	void __fastcall Save(void);
	void __fastcall Close(void);
	void __fastcall CreateComponent(_di_IPaletteItem Item)/* overload */;
	AnsiString __fastcall FindCompClass(const AnsiString CompName);
	AnsiString __fastcall GetAncestorName();
	int __fastcall GetCompCount(void);
	_di_ICompInfo __fastcall GetCompInfo(int Index);
	AnsiString __fastcall GetCompName(int Index);
	void __fastcall GetDependencies(TGetRootProc Proc);
	void __fastcall GetDependentRoots(TGetRootProc Proc);
	AnsiString __fastcall GetDesignClassName();
	_di_IDesignerModule __fastcall GetModule();
	AnsiString __fastcall GetFileSystem();
	Classes::TComponent* __fastcall GetRoot(void);
	AnsiString __fastcall GetRootName();
	void __fastcall GetUnits(Classes::TGetStrProc Proc);
	void __fastcall GoDormant(void);
	bool __fastcall IsDormant(void);
	bool __fastcall RenameComponent(const AnsiString CurName, const AnsiString NewName);
	void __fastcall RenameRootMethod(const AnsiString CurName, const AnsiString NewName);
	void __fastcall RemoveDependentLinks(void);
	void __fastcall SetFileSystem(const AnsiString FileSystem);
	void __fastcall SetRootName(const AnsiString AName);
	void __fastcall SetSelection(const AnsiString Name);
	bool __fastcall SpecialPropertyHelp(const AnsiString Member, /* out */ AnsiString &HelpFile, /* out */ AnsiString &Context, /* out */ Classes::THelpType &HelpType);
	bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo)/* overload */;
	void __fastcall CopySelectionToStream(Classes::TMemoryStream* S, Classes::TStrings* UnitDependencies);
	AnsiString __fastcall GetRootBaseClass();
	TMetaClass* __fastcall GetRootClass(void);
	TMetaClass* __fastcall GetCustomModuleClass(void);
	_di_IInternalComponentDesigner __fastcall GetComponentDesigner();
	Update::_di_IUpdateManager __fastcall GetUpdateManager();
	TComponentRoot* __fastcall Implementor(void);
	bool __fastcall IsFrame(Classes::TPersistent* AInstance);
	void __fastcall Modified(void);
	void __fastcall PasteSelectionFromStream(Classes::TMemoryStream* S, Classes::TComponent* Parent, const Types::TRect &Rect);
	void __fastcall RemoveDependenciesOn(const Classes::TComponent* Component);
	void __fastcall Resurrect(void);
	void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo);
	void __fastcall SetActive(bool Value);
	void __fastcall SetControlsLocked(bool Value);
	void __fastcall UpdateDependencies(void);
	void __fastcall UpdateOptions(void);
	Toolsapi::_di_IOTAFormEditor __fastcall GetFormEditor();
	void __fastcall Edit(const Classes::TComponent* Component);
	void __fastcall Select(Classes::TPersistent* Component, bool Extend);
	Classes::TComponent* __fastcall CreateComponent(TMetaClass* ComponentClass, Classes::TComponent* Parent, int Left, int Top, int Width, int Height)/* overload */;
	Classes::TComponent* __fastcall CreateCurrentComponent(Classes::TComponent* Parent, const Types::TRect &Rect);
	System::TMethod __fastcall CreateMethod(const AnsiString Name, Typinfo::PTypeData TypeData);
	AnsiString __fastcall GetMethodName(const System::TMethod &Method);
	void __fastcall GetMethods(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc);
	AnsiString __fastcall GetPathAndBaseExeName();
	AnsiString __fastcall GetPrivateDirectory();
	AnsiString __fastcall GetBaseRegKey();
	Inifiles::TCustomIniFile* __fastcall GetIDEOptions(void);
	void __fastcall GetSelections(const Designintf::_di_IDesignerSelections List);
	bool __fastcall MethodExists(const AnsiString Name);
	void __fastcall SelectComponent(Classes::TPersistent* Instance)/* overload */;
	void __fastcall SetSelections(const Designintf::_di_IDesignerSelections List);
	void __fastcall ShowMethod(const AnsiString Name);
	void __fastcall GetComponentNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc);
	Classes::TComponent* __fastcall GetComponent(const AnsiString Name);
	AnsiString __fastcall GetComponentName(Classes::TComponent* Component);
	Classes::TPersistent* __fastcall GetObject(const AnsiString Name);
	AnsiString __fastcall GetObjectName(Classes::TPersistent* Instance);
	void __fastcall GetObjectNames(Typinfo::PTypeData TypeData, Classes::TGetStrProc Proc);
	bool __fastcall MethodFromAncestor(const System::TMethod &Method);
	bool __fastcall IsComponentLinkable(Classes::TComponent* Component);
	bool __fastcall IsComponentHidden(Classes::TComponent* Component);
	void __fastcall MakeComponentLinkable(Classes::TComponent* Component);
	bool __fastcall GetIsDormant(void);
	void __fastcall GetProjectModules(Classes::TGetModuleProc Proc);
	Designintf::_di_IDesigner __fastcall GetAncestorDesigner();
	bool __fastcall IsSourceReadOnly(void);
	Types::TPoint __fastcall GetScrollRanges(const Types::TPoint &ScrollPosition);
	void __fastcall ChainCall(const AnsiString MethodName, const AnsiString InstanceName, const AnsiString InstanceMethod, Typinfo::PTypeData TypeData);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteSelection(bool ADoAll = false);
	void __fastcall NoSelection(void);
	void __fastcall ModuleFileNames(AnsiString &ImplFileName, AnsiString &IntfFileName, AnsiString &FormFileName);
	AnsiString __fastcall GetRootClassName();
	AnsiString __fastcall UniqueName(const AnsiString ClassName);
	void __fastcall RenameMethod(const AnsiString CurName, const AnsiString NewName);
	void __fastcall EditComponent(const Classes::TComponent* Component);
	Classes::TComponent* __fastcall FindGlobalComponent(const AnsiString Name);
	Designintf::_di_ICustomModule __fastcall GetCustomModule();
	Designintf::_di_ISelectionEditorList __fastcall GetSelectionEditors();
	Designintf::_di_IComponentEditor __fastcall GetComponentEditor();
	Designer::_di_IItem __fastcall FindSelection(Classes::TPersistent* Instance);
	_di_IPaletteItem __fastcall GetPaletteItem(TMetaClass* ComponentClass);
	void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
	void __fastcall InstanceInserted(Classes::TPersistent* AInstance);
	void __fastcall InstanceRemoved(Classes::TPersistent* AInstance);
	bool __fastcall ModifiableFrame(Classes::TComponent* AComponent);
	void __fastcall ModalEdit(char EditKey, const Designintf::_di_IActivatable ReturnWindow);
	void __fastcall SelectItemName(const AnsiString PropertyName);
	void __fastcall ValidateModification(void);
	bool __fastcall CanUndelete(void);
	void __fastcall DoUndelete(void);
	void __fastcall ShowHelp(void);
	bool __fastcall HasSelectableChildren(Classes::TComponent* AComponent);
	int __fastcall GetSelectableComponentCount(void);
	Classes::TComponent* __fastcall GetSelectableComponents(int Index);
	void __fastcall Updating(const Update::_di_IUpdateManager Context);
	void __fastcall Updated(const Update::_di_IUpdateManager Context);
	void __fastcall Deleting(const Update::_di_IUpdateManager Context, Classes::TPersistent* Instance);
	Classes::TComponent* __fastcall UpdateManagerCreateComponent(TMetaClass* ComponentClass, const Classes::TComponent* Owner);
	void __fastcall WriteComponent(Classes::TWriter* Writer, Classes::TComponent* Component);
	virtual void __fastcall RefuseChildren(Classes::TComponent* Component) = 0 ;
	void __fastcall Align(TAffect Affect);
	void __fastcall Size(TSizeAffect Affect, int Value);
	bool __fastcall GetTextDFM(void);
	bool __fastcall CanRevert(void)/* overload */;
	bool __fastcall CanModify(void);
	Designintf::_di_IDesignerSelections __fastcall GetSelection();
	bool __fastcall GetLocked(void);
	void __fastcall Dialog(TDesignDialog Dialog);
	void __fastcall Command(TDesignCommand Command);
	void __fastcall DoViewAsText(void);
	virtual void __fastcall AddClassProp(Classes::TList* ClassList, System::TObject* Obj) = 0 ;
	virtual void __fastcall AdjustComponent(Classes::TComponent* Component, const Types::TRect &AdjustmentRect, const Types::TRect &AdjustmentBounds) = 0 ;
	virtual bool __fastcall CanClassBeFrame(TMetaClass* Cls) = 0 ;
	virtual void __fastcall DisableAlignments(void) = 0 ;
	virtual void __fastcall DeinitializeDesigner(void) = 0 ;
	virtual void __fastcall FreeRoot(Classes::TComponent* Root) = 0 ;
	virtual void __fastcall EnableAlignments(void) = 0 ;
	virtual void __fastcall FinalizeNewRoot(Classes::TComponent* Component, const AnsiString RootName) = 0 ;
	virtual TRecoveryResult __fastcall InheritenceRecovery(const AnsiString RootName, const AnsiString AncestorName, AnsiString &ComponentName, const AnsiString Names, bool RecoveringFrame) = 0 ;
	virtual void __fastcall InitializeDesigner(void) = 0 ;
	virtual bool __fastcall IsBlankNameInheritenceException(Classes::TComponent* Component) = 0 ;
	virtual TQueryRedirectLinksResult __fastcall QueryRedirectLinks(const AnsiString RootName, const AnsiString ComponentName) = 0 ;
	virtual void __fastcall RedirectLinks(Classes::TComponent* Root, const AnsiString LinkName) = 0 ;
	virtual TRootReadErrorResult __fastcall RootReadError(const AnsiString Message) = 0 ;
	virtual void __fastcall SetDesignerListenerFor(Classes::TComponent* Component) = 0 ;
	virtual void __fastcall SelectComponent(Classes::TPersistent* Component, bool Extend)/* overload */;
	virtual void __fastcall SetRootDefaults(Classes::TComponent* Component, const AnsiString RootName) = 0 ;
	virtual void __fastcall InitCustomModule(void) = 0 ;
	virtual Classes::TComponent* __fastcall FindRootOf(Classes::TPersistent* Instance) = 0 ;
	virtual TDeleteWarnResult __fastcall NonAncestorDeleteWarning(const AnsiString Name, const AnsiString NonAncestors) = 0 ;
	virtual int __fastcall GetControlCount(Classes::TPersistent* APersistent) = 0 ;
	virtual Classes::TComponent* __fastcall GetControl(Classes::TPersistent* APersistent, int Index) = 0 ;
	virtual bool __fastcall IsTControl(Classes::TPersistent* APersistent) = 0 ;
	virtual Classes::TComponent* __fastcall GetParent(Classes::TPersistent* APersistent) = 0 ;
	virtual void __fastcall ForceRefuseChildren(Classes::TComponent* Component) = 0 ;
	virtual TMetaClass* __fastcall GetActiveClassGroup(void) = 0 ;
	virtual bool __fastcall SendRootComponent(void) = 0 ;
	virtual void __fastcall ClearRootReferences(void) = 0 ;
	virtual void __fastcall SetInstanceParent(Classes::TComponent* Instance) = 0 ;
	__property Designintf::_di_ICustomModule CustomModule = {read=FCustomModule};
	__property TMetaClass* CustomModuleClass = {read=FCustomModuleClass};
	__property TMetaClass* RootClass = {read=GetRootClass};
	
public:
	__fastcall TComponentRoot(const _di_IComponentDesigner Designer, const _di_IDesignerModule AModule, const AnsiString AFileName, bool Existing, const _di_IDatedStream RootStream, const _di_IDatedStream DesignStream, const AnsiString ARootName, const AnsiString AAncestor, const AnsiString AFileSystem);
	__fastcall virtual ~TComponentRoot(void);
	virtual void __fastcall BeforeDestruction(void);
private:
	void *__IUpdateManagerCallback;	/* Update::IUpdateManagerCallback [CreateComponent=UpdateManagerCreateComponent] */
	void *__IAlignable;	/* Componentdesigner::IAlignable */
	
public:
	operator IAlignable*(void) { return (IAlignable*)&__IAlignable; }
	operator IUpdateManagerCallback*(void) { return (IUpdateManagerCallback*)&__IUpdateManagerCallback; }
	
};


__interface IRootListUpdate;
typedef System::DelphiInterface<IRootListUpdate> _di_IRootListUpdate;
__interface INTERFACE_UUID("{7ED7BF26-E349-11D3-AB4A-00C04FB17A72}") IRootListUpdate  : public IInterface 
{
	
public:
	virtual void __fastcall RootListAdd(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootListRemove(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootGoingDormant(const _di_IRoot ARoot) = 0 ;
	virtual void __fastcall RootModified(const _di_IRoot ARoot) = 0 ;
};

__interface IInternalItem;
typedef System::DelphiInterface<IInternalItem> _di_IInternalItem;
__interface INTERFACE_UUID("{7ED7BF32-E349-11D3-AB4A-00C04FB17A72}") IInternalItem  : public IItem 
{
	
public:
	virtual Designer::_di_IItem __fastcall GetChildren(int Index) = 0 ;
	virtual int __fastcall GetChildCount(void) = 0 ;
	virtual Designintf::_di_IComponentEditor __fastcall GetEditor(void) = 0 ;
	virtual bool __fastcall GetMarked(void) = 0 ;
	virtual void __fastcall SetMarked(bool Value) = 0 ;
	virtual void __fastcall SetParent(const Designer::_di_IItem Item) = 0 ;
	virtual void __fastcall Show(void) = 0 ;
	virtual void __fastcall ZOrder(bool Front) = 0 ;
	virtual void __fastcall FlipChildren(void) = 0 ;
	__property Designer::_di_IItem Children[int Index] = {read=GetChildren};
	__property int ChildCount = {read=GetChildCount};
	__property Designintf::_di_IComponentEditor Editor = {read=GetEditor};
	__property Designer::_di_IItem Parent = {read=GetParent, write=SetParent};
	__property bool Marked = {read=GetMarked, write=SetMarked};
};

class DELPHICLASS TInternalItem;
class PASCALIMPLEMENTATION TInternalItem : public Designer::TPersistentItem 
{
	typedef Designer::TPersistentItem inherited;
	
private:
	Designintf::_di_IComponentEditor FEditor;
	_di_IInternalRoot FInternalRoot;
	Designintf::_di_IDesigner FDesigner;
	
protected:
	void __fastcall Edit(void);
	Designer::_di_IItem __fastcall GetChildren(int Index);
	int __fastcall GetChildCount(void);
	Designintf::_di_IComponentEditor __fastcall GetEditor();
	bool __fastcall Selectable(void);
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
	__property _di_IInternalRoot InternalRoot = {read=FInternalRoot};
	
public:
	__fastcall TInternalItem(Classes::TPersistent* AInstance, const Designintf::_di_IDesigner ADesigner);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInternalItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentItem;
class PASCALIMPLEMENTATION TComponentItem : public TInternalItem 
{
	typedef TInternalItem inherited;
	
private:
	Classes::TComponent* __fastcall GetComponent(void);
	
protected:
	__property Classes::TComponent* Component = {read=GetComponent};
	HIDESBASE bool __fastcall Selectable(void);
	HIDESBASE void __fastcall ValidateDeletable(void);
	void __fastcall ZOrder(bool Front);
	void __fastcall FlipChildren(void);
	
public:
	__fastcall TComponentItem(Classes::TComponent* AComponent, const Designintf::_di_IDesigner ADesigner);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TComponentItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentDesigner;
class PASCALIMPLEMENTATION TComponentDesigner : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::_di_IInterfaceList FRootList;
	_di_IInternalRoot FActiveRoot;
	Designintf::_di_IEditHandler FActiveEditHandler;
	_di_IDesignEnvironment FEnvironment;
	Designintf::_di_IDesignerSelections FSelections;
	bool FControlsLocked;
	bool FInUpdateSelections;
	
protected:
	__property Designintf::_di_IEditHandler ActiveEditHandler = {read=FActiveEditHandler};
	__property _di_IInternalRoot ActiveRoot = {read=FActiveRoot};
	__property _di_IDesignEnvironment Environment = {read=FEnvironment, write=FEnvironment};
	__property Classes::_di_IInterfaceList RootList = {read=FRootList};
	__property Designintf::_di_IDesignerSelections Selections = {read=FSelections};
	void __fastcall RootListAdd(const _di_IRoot ARoot);
	void __fastcall RootListRemove(const _di_IRoot ARoot);
	void __fastcall RootGoingDormant(const _di_IRoot ARoot);
	void __fastcall RootModified(const _di_IRoot ARoot);
	void __fastcall CopySelectionToStream(Classes::TMemoryStream* S, Classes::TStrings* UnitDependencies);
	void __fastcall DesignerOptionsChanged(void);
	bool __fastcall EditAction(Designintf::TEditAction Action);
	_di_IFile __fastcall FindFile(const AnsiString FileName);
	_di_IRoot __fastcall FindRoot(const AnsiString RootName)/* overload */;
	_di_IRoot __fastcall FindRoot(Classes::TComponent* Component)/* overload */;
	_di_IRoot __fastcall GetActiveRoot();
	void __fastcall GetClassUnits(const AnsiString ClassName, Classes::TGetStrProc Proc);
	Designintf::TEditState __fastcall GetEditState(void);
	AnsiString __fastcall GetFirstSelectionType();
	void __fastcall GetRootNames(Classes::TGetStrProc Proc);
	void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	AnsiString __fastcall GetSelectionName();
	AnsiString __fastcall GetSelectionType();
	void __fastcall HideWindows(void);
	void __fastcall ShowWindows(void);
	void __fastcall ModalEditDone(const Designintf::_di_IActivatable ReturnWindow);
	_di_IRoot __fastcall OpenRootClass(const AnsiString ClassName);
	void __fastcall PasteSelectionFromStream(Classes::TMemoryStream* S, Classes::TComponent* Parent, const Types::TRect &Rect);
	void __fastcall GetSelection(const Designintf::_di_IDesignerSelections ASelection);
	void __fastcall SetSelection(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignWindow DesignWindow, const Designintf::_di_IDesignerSelections ASelection);
	void __fastcall CancelModes(void);
	bool __fastcall GetControlsLocked(void);
	void __fastcall SetControlsLocked(bool Value);
	_di_IRoot __fastcall GetRoots(int Index);
	int __fastcall GetRootsCount(void);
	TMetaClass* __fastcall GetFirstSelectionClass(void);
	bool __fastcall IsNestable(const AnsiString ClassName);
	void __fastcall RemoveDependenciesOn(const Classes::TComponent* Component);
	void __fastcall RootActivated(const _di_IRoot ARoot);
	void __fastcall UpdateRootDependents(void);
	void __fastcall UpdateSelections(void);
	AnsiString __fastcall FindBaseClass(const AnsiString AClassName);
	TMetaClass* __fastcall FindCustomModuleClass(const AnsiString AClassName);
	bool __fastcall IsRootBaseClass(const AnsiString AClassName);
	virtual bool __fastcall ValidBaseClass(TMetaClass* ComponentClass) = 0 ;
	
public:
	__fastcall TComponentDesigner(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TComponentDesigner(void) { }
	#pragma option pop
	
private:
	void *__IRootListUpdate;	/* Componentdesigner::IRootListUpdate */
	
public:
	operator IRootListUpdate*(void) { return (IRootListUpdate*)&__IRootListUpdate; }
	
};


class DELPHICLASS TIStreamAdapter;
class PASCALIMPLEMENTATION TIStreamAdapter : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	_di_IStream FStream;
	
public:
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
	__fastcall TIStreamAdapter(const _di_IStream Stream);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIStreamAdapter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TStreamAdapter;
class PASCALIMPLEMENTATION TStreamAdapter : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TStream* FStream;
	bool FOwned;
	
protected:
	__property bool Owned = {read=FOwned, nodefault};
	__property Classes::TStream* Stream = {read=FStream};
	__int64 __fastcall Read(void *Buffer, __int64 Length);
	__int64 __fastcall Write(void *Buffer, __int64 Length);
	__int64 __fastcall Seek(__int64 Offset, int Origin);
	void __fastcall SetSize(__int64 Size);
	
public:
	__fastcall TStreamAdapter(const Classes::TStream* Stream, bool Owned);
	__fastcall virtual ~TStreamAdapter(void);
private:
	void *__IStream;	/* IStream */
	
public:
	operator IStream*(void) { return (IStream*)&__IStream; }
	
};


class DELPHICLASS TDatedStreamAdapter;
class PASCALIMPLEMENTATION TDatedStreamAdapter : public TStreamAdapter 
{
	typedef TStreamAdapter inherited;
	
private:
	int FDate;
	
protected:
	int __fastcall GetModifyTime(void);
	void __fastcall SetModifyTime(int Time);
	
public:
	__fastcall TDatedStreamAdapter(const Classes::TStream* Stream, int Date, bool Owned);
public:
	#pragma option push -w-inl
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TDatedStreamAdapter(void) { }
	#pragma option pop
	
private:
	void *__IDatedStream;	/* Componentdesigner::IDatedStream */
	
public:
	operator IDatedStream*(void) { return (IDatedStream*)&__IDatedStream; }
	
};


class DELPHICLASS TCompInfo;
class PASCALIMPLEMENTATION TCompInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IInternalRoot FRoot;
	Classes::TPersistent* FInstance;
	Typinfo::PPropInfo *FList;
	int FCount;
	Typinfo::PPropInfo *FSubList;
	int FSubCount;
	void __fastcall InitSubList(void);
	
public:
	__fastcall TCompInfo(const _di_IInternalRoot Root, Classes::TPersistent* Instance);
	__fastcall virtual ~TCompInfo(void);
	void __fastcall ClearEvent(int Index);
	AnsiString __fastcall GetClassName();
	int __fastcall GetEventCount(void);
	Typinfo::PPropInfo __fastcall GetEventInfo(int Index);
	AnsiString __fastcall GetEventValue(int Index);
	AnsiString __fastcall GetEventName(int Index);
	void * __fastcall GetComponentHandle(void);
	AnsiString __fastcall GetNamePath();
	int __fastcall GetSubInfoCount(void);
	_di_ICompInfo __fastcall GetSubInfo(int Index);
private:
	void *__ICompInfo;	/* Componentdesigner::ICompInfo */
	
public:
	operator ICompInfo*(void) { return (ICompInfo*)&__ICompInfo; }
	
};


typedef void __fastcall (__closure *TRootActivatedEvent)(System::TObject* Sender, const Designintf::_di_ICustomModule CustomModule);

class DELPHICLASS TEvRootActivatedEvent;
class PASCALIMPLEMENTATION TEvRootActivatedEvent : public Events::TEvent 
{
	typedef Events::TEvent inherited;
	
public:
	HIDESBASE void __fastcall Add(TRootActivatedEvent AHandler);
	HIDESBASE int __fastcall IndexOf(TRootActivatedEvent AHandler);
	HIDESBASE void __fastcall Remove(TRootActivatedEvent AHandler);
	HIDESBASE void __fastcall Send(System::TObject* Sender, const Designintf::_di_ICustomModule CustomModule);
public:
	#pragma option push -w-inl
	/* TEvent.Create */ inline __fastcall TEvRootActivatedEvent(void) : Events::TEvent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEvent.Destroy */ inline __fastcall virtual ~TEvRootActivatedEvent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEnvironmentTools;
class PASCALIMPLEMENTATION TEnvironmentTools : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IDesignEnvironment FEnvironment;
	
protected:
	bool __fastcall ToolSelected(void);
	
public:
	__fastcall TEnvironmentTools(const _di_IDesignEnvironment Environment);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEnvironmentTools(void) { }
	#pragma option pop
	
private:
	void *__ITools;	/* Designer::ITools */
	
public:
	operator ITools*(void) { return (ITools*)&__ITools; }
	
};


typedef void __fastcall (*TInitializeDesigner)(const _di_IDesignEnvironment Environment);

class DELPHICLASS ECannotDeleteNonComponentException;
class PASCALIMPLEMENTATION ECannotDeleteNonComponentException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECannotDeleteNonComponentException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECannotDeleteNonComponentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECannotDeleteNonComponentException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECannotDeleteNonComponentException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECannotDeleteNonComponentException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECannotDeleteNonComponentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECannotDeleteNonComponentException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECannotDeleteNonComponentException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECannotDeleteNonComponentException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint CompIconSize = 0x1c;
extern PACKAGE System::ResourceString _sAncestorClassName;
#define Componentdesigner_sAncestorClassName System::LoadResourceString(&Componentdesigner::_sAncestorClassName)
extern PACKAGE System::ResourceString _sBlankName;
#define Componentdesigner_sBlankName System::LoadResourceString(&Componentdesigner::_sBlankName)
extern PACKAGE System::ResourceString _sCannotInherit;
#define Componentdesigner_sCannotInherit System::LoadResourceString(&Componentdesigner::_sCannotInherit)
extern PACKAGE System::ResourceString _sCannotInheritFrom;
#define Componentdesigner_sCannotInheritFrom System::LoadResourceString(&Componentdesigner::_sCannotInheritFrom)
extern PACKAGE System::ResourceString _sCannotInheritFroms;
#define Componentdesigner_sCannotInheritFroms System::LoadResourceString(&Componentdesigner::_sCannotInheritFroms)
extern PACKAGE System::ResourceString _sCantDeleteAncestor;
#define Componentdesigner_sCantDeleteAncestor System::LoadResourceString(&Componentdesigner::_sCantDeleteAncestor)
extern PACKAGE System::ResourceString _sCantDeleteComponent;
#define Componentdesigner_sCantDeleteComponent System::LoadResourceString(&Componentdesigner::_sCantDeleteComponent)
extern PACKAGE System::ResourceString _sCantRename;
#define Componentdesigner_sCantRename System::LoadResourceString(&Componentdesigner::_sCantRename)
extern PACKAGE System::ResourceString _sComponentAlreadyExists;
#define Componentdesigner_sComponentAlreadyExists System::LoadResourceString(&Componentdesigner::_sComponentAlreadyExists)
extern PACKAGE System::ResourceString _sReadOnlyError;
#define Componentdesigner_sReadOnlyError System::LoadResourceString(&Componentdesigner::_sReadOnlyError)
extern PACKAGE System::ResourceString _sReadOnlySource;
#define Componentdesigner_sReadOnlySource System::LoadResourceString(&Componentdesigner::_sReadOnlySource)
extern PACKAGE System::ResourceString _sRenamingAncestor;
#define Componentdesigner_sRenamingAncestor System::LoadResourceString(&Componentdesigner::_sRenamingAncestor)
extern PACKAGE System::ResourceString _sCannotPasteForm;
#define Componentdesigner_sCannotPasteForm System::LoadResourceString(&Componentdesigner::_sCannotPasteForm)
extern PACKAGE System::ResourceString _sRootClassNotFound;
#define Componentdesigner_sRootClassNotFound System::LoadResourceString(&Componentdesigner::_sRootClassNotFound)
extern PACKAGE System::ResourceString _sNestedInsertedInSelf;
#define Componentdesigner_sNestedInsertedInSelf System::LoadResourceString(&Componentdesigner::_sNestedInsertedInSelf)
extern PACKAGE System::ResourceString _sAncestorDeleteWarning;
#define Componentdesigner_sAncestorDeleteWarning System::LoadResourceString(&Componentdesigner::_sAncestorDeleteWarning)
extern PACKAGE System::ResourceString _sCannotInheritControl;
#define Componentdesigner_sCannotInheritControl System::LoadResourceString(&Componentdesigner::_sCannotInheritControl)
extern PACKAGE System::ResourceString _sCantSaveModuleWithAFixup;
#define Componentdesigner_sCantSaveModuleWithAFixup System::LoadResourceString(&Componentdesigner::_sCantSaveModuleWithAFixup)
extern PACKAGE System::ResourceString _sCantSaveModuleWithFixups;
#define Componentdesigner_sCantSaveModuleWithFixups System::LoadResourceString(&Componentdesigner::_sCantSaveModuleWithFixups)
extern PACKAGE System::ResourceString _sRedirectLinks;
#define Componentdesigner_sRedirectLinks System::LoadResourceString(&Componentdesigner::_sRedirectLinks)
extern PACKAGE System::ResourceString _sPasteError;
#define Componentdesigner_sPasteError System::LoadResourceString(&Componentdesigner::_sPasteError)
extern PACKAGE System::ResourceString _sMenuAlignToGrid;
#define Componentdesigner_sMenuAlignToGrid System::LoadResourceString(&Componentdesigner::_sMenuAlignToGrid)
extern PACKAGE System::ResourceString _sMenuBringToFront;
#define Componentdesigner_sMenuBringToFront System::LoadResourceString(&Componentdesigner::_sMenuBringToFront)
extern PACKAGE System::ResourceString _sMenuSendToBack;
#define Componentdesigner_sMenuSendToBack System::LoadResourceString(&Componentdesigner::_sMenuSendToBack)
extern PACKAGE System::ResourceString _sMenuRevert;
#define Componentdesigner_sMenuRevert System::LoadResourceString(&Componentdesigner::_sMenuRevert)
extern PACKAGE System::ResourceString _sMenuAlign;
#define Componentdesigner_sMenuAlign System::LoadResourceString(&Componentdesigner::_sMenuAlign)
extern PACKAGE System::ResourceString _sMenuSize;
#define Componentdesigner_sMenuSize System::LoadResourceString(&Componentdesigner::_sMenuSize)
extern PACKAGE System::ResourceString _sMenuScale;
#define Componentdesigner_sMenuScale System::LoadResourceString(&Componentdesigner::_sMenuScale)
extern PACKAGE System::ResourceString _sMenuTabOrder;
#define Componentdesigner_sMenuTabOrder System::LoadResourceString(&Componentdesigner::_sMenuTabOrder)
extern PACKAGE System::ResourceString _sMenuCreatOrder;
#define Componentdesigner_sMenuCreatOrder System::LoadResourceString(&Componentdesigner::_sMenuCreatOrder)
extern PACKAGE System::ResourceString _sMenuFlipChildren;
#define Componentdesigner_sMenuFlipChildren System::LoadResourceString(&Componentdesigner::_sMenuFlipChildren)
extern PACKAGE System::ResourceString _sSubMenuFlipChildrenAll;
#define Componentdesigner_sSubMenuFlipChildrenAll System::LoadResourceString(&Componentdesigner::_sSubMenuFlipChildrenAll)
extern PACKAGE System::ResourceString _sSubMenuFlipChidrenSelected;
#define Componentdesigner_sSubMenuFlipChidrenSelected System::LoadResourceString(&Componentdesigner::_sSubMenuFlipChidrenSelected)
extern PACKAGE System::ResourceString _sMenuSaveAsTemplate;
#define Componentdesigner_sMenuSaveAsTemplate System::LoadResourceString(&Componentdesigner::_sMenuSaveAsTemplate)
extern PACKAGE System::ResourceString _sMenuViewAsText;
#define Componentdesigner_sMenuViewAsText System::LoadResourceString(&Componentdesigner::_sMenuViewAsText)
extern PACKAGE System::ResourceString _sMenuTextDFM;
#define Componentdesigner_sMenuTextDFM System::LoadResourceString(&Componentdesigner::_sMenuTextDFM)
extern PACKAGE System::ResourceString _sMenuTextXFM;
#define Componentdesigner_sMenuTextXFM System::LoadResourceString(&Componentdesigner::_sMenuTextXFM)
extern PACKAGE System::ResourceString _sCannotDeleteNonComponent;
#define Componentdesigner_sCannotDeleteNonComponent System::LoadResourceString(&Componentdesigner::_sCannotDeleteNonComponent)
extern PACKAGE Types::TRect EmptyRect;
extern PACKAGE Types::TPoint EmptyPoint;
extern PACKAGE Types::TRect OffScreenRect;
extern PACKAGE Types::TPoint OffScreenPoint;
extern PACKAGE TEvRootActivatedEvent* EvRootActivatedEvent;
extern PACKAGE bool __fastcall IsNoIconComponent(Classes::TComponent* Component);
extern PACKAGE _di_IDesignEnvironment __fastcall ProtectEnvironment(const _di_IDesignEnvironment ADesignEnvironment);
extern PACKAGE _di_IComponentDesigners __fastcall Designers();
extern PACKAGE _di_IComponentDesigner __fastcall ActiveDesigner();
extern PACKAGE _di_IRoot __fastcall ActiveRoot();
extern PACKAGE void __fastcall RegisterInitializeDesigner(TInitializeDesigner InitFunc);
extern PACKAGE void __fastcall InitializeDesigners(const _di_IDesignEnvironment Environment);

}	/* namespace Componentdesigner */
using namespace Componentdesigner;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ComponentDesigner
