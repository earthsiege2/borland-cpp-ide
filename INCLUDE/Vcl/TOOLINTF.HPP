// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ToolIntf.pas' rev: 6.00

#ifndef ToolIntfHPP
#define ToolIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <FileIntf.hpp>	// Pascal unit
#include <EditIntf.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Toolintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIMenuFlag { mfInvalid, mfEnabled, mfVisible, mfChecked, mfBreak, mfBarBreak, mfRadioItem };
#pragma option pop

typedef Set<TIMenuFlag, mfInvalid, mfRadioItem>  TIMenuFlags;

class DELPHICLASS TIMenuItemIntf;
typedef void __fastcall (__closure *TIMenuClickEvent)(TIMenuItemIntf* Sender);

class PASCALIMPLEMENTATION TIMenuItemIntf : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual bool __stdcall DestroyMenuItem(void) = 0 ;
	virtual int __stdcall GetIndex(void) = 0 ;
	virtual int __stdcall GetItemCount(void) = 0 ;
	virtual TIMenuItemIntf* __stdcall GetItem(int Index) = 0 ;
	virtual AnsiString __stdcall GetName(void) = 0 ;
	virtual TIMenuItemIntf* __stdcall GetParent(void) = 0 ;
	virtual AnsiString __stdcall GetCaption(void) = 0 ;
	virtual bool __stdcall SetCaption(const AnsiString Caption) = 0 ;
	virtual int __stdcall GetShortCut(void) = 0 ;
	virtual bool __stdcall SetShortCut(int ShortCut) = 0 ;
	virtual TIMenuFlags __stdcall GetFlags(void) = 0 ;
	virtual bool __stdcall SetFlags(TIMenuFlags Mask, TIMenuFlags Flags) = 0 ;
	virtual int __stdcall GetGroupIndex(void) = 0 ;
	virtual bool __stdcall SetGroupIndex(int GroupIndex) = 0 ;
	virtual AnsiString __stdcall GetHint(void) = 0 ;
	virtual bool __stdcall SetHint(AnsiString Hint) = 0 ;
	virtual int __stdcall getContext(void) = 0 ;
	virtual bool __stdcall setContext(int Context) = 0 ;
	virtual TIMenuClickEvent __stdcall GetOnClick(void) = 0 ;
	virtual bool __stdcall SetOnClick(TIMenuClickEvent Click) = 0 ;
	virtual TIMenuItemIntf* __stdcall InsertItem(int Index, AnsiString Caption, AnsiString Name, AnsiString Hint, int ShortCut, int Context, int GroupIndex, TIMenuFlags Flags, TIMenuClickEvent EventHandler) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIMenuItemIntf(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIMenuItemIntf(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIMainMenuIntf;
class PASCALIMPLEMENTATION TIMainMenuIntf : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual TIMenuItemIntf* __stdcall GetMenuItems(void) = 0 ;
	virtual TIMenuItemIntf* __stdcall FindMenuItem(const AnsiString Name) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIMainMenuIntf(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIMainMenuIntf(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFileNotification { fnFileOpening, fnFileOpened, fnFileClosing, fnProjectOpening, fnProjectOpened, fnProjectClosing, fnAddedToProject, fnRemovedFromProject, fnDefaultDesktopLoad, fnDefaultDesktopSave, fnProjectDesktopLoad, fnprojectDesktopSave, fnPackageInstalled, fnPackageUninstalled };
#pragma option pop

#pragma option push -b-
enum TEventNotification { enBeforeCompile, enAfterCompile };
#pragma option pop

class DELPHICLASS TIAddInNotifier;
class PASCALIMPLEMENTATION TIAddInNotifier : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual void __stdcall FileNotification(TFileNotification NotifyCode, const AnsiString FileName, bool &Cancel) = 0 ;
	virtual void __stdcall EventNotification(TEventNotification NotifyCode, bool &Cancel) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIAddInNotifier(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIAddInNotifier(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCreateModuleFlag { cmAddToProject, cmShowSource, cmShowForm, cmUnNamed, cmNewUnit, cmNewForm, cmMainForm, cmMarkModified, cmNewFile, cmExisting };
#pragma option pop

typedef Set<TCreateModuleFlag, cmAddToProject, cmExisting>  TCreateModuleFlags;

#pragma option push -b-
enum TCreateProjectFlag { cpCustom, cpApplication, cpLibrary, cpCanShowSource, cpExisting, cpConsole };
#pragma option pop

typedef Set<TCreateProjectFlag, cpCustom, cpConsole>  TCreateProjectFlags;

#pragma option push -b-
enum TBoundsType { btForm, btCustomModule };
#pragma option pop

typedef bool __stdcall (*TProjectEnumProc)(void * Param, const AnsiString FileName, const AnsiString UnitName, const AnsiString FormName);

typedef bool __stdcall (*TProjectEnumModuleProc)(void * Param, const AnsiString FileName, const AnsiString UnitName, const AnsiString FormName, const AnsiString DesignClass);

class DELPHICLASS TIToolServices;
class PASCALIMPLEMENTATION TIToolServices : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual bool __stdcall CloseProject(void) = 0 ;
	virtual bool __stdcall OpenProject(const AnsiString ProjName) = 0 ;
	virtual bool __stdcall OpenProjectInfo(const AnsiString ProjName) = 0 ;
	virtual bool __stdcall SaveProject(void) = 0 ;
	virtual bool __stdcall CloseFile(const AnsiString FileName) = 0 ;
	virtual bool __stdcall SaveFile(const AnsiString FileName) = 0 ;
	virtual bool __stdcall OpenFile(const AnsiString FileName) = 0 ;
	virtual bool __stdcall ReloadFile(const AnsiString FileName) = 0 ;
	virtual int __stdcall ModalDialogBox(unsigned Instance, char * TemplateName, HWND WndParent, void * DialogFunc, int InitParam) = 0 ;
	virtual bool __stdcall CreateModule(const AnsiString ModuleName, _di_IStream Source, _di_IStream Form, TCreateModuleFlags CreateFlags) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall CreateModuleEx(const AnsiString ModuleName, const AnsiString FormName, const AnsiString AncestorClass, const AnsiString FileSystem, _di_IStream Source, _di_IStream Form, TCreateModuleFlags CreateFlags) = 0 ;
	virtual HWND __stdcall GetParentHandle(void) = 0 ;
	virtual AnsiString __stdcall GetProjectName(void) = 0 ;
	virtual int __stdcall GetUnitCount(void) = 0 ;
	virtual AnsiString __stdcall GetUnitName(int Index) = 0 ;
	virtual bool __stdcall EnumProjectUnits(TProjectEnumProc EnumProc, void * Param) = 0 ;
	virtual int __stdcall GetFormCount(void) = 0 ;
	virtual AnsiString __stdcall GetFormName(int Index) = 0 ;
	virtual AnsiString __stdcall GetCurrentFile(void) = 0 ;
	virtual bool __stdcall IsFileOpen(const AnsiString FileName) = 0 ;
	virtual bool __stdcall GetNewModuleName(AnsiString &UnitIdent, AnsiString &FileName) = 0 ;
	virtual int __stdcall GetModuleCount(void) = 0 ;
	virtual AnsiString __stdcall GetModuleName(int Index) = 0 ;
	virtual int __stdcall GetComponentCount(int ModIndex) = 0 ;
	virtual AnsiString __stdcall GetComponentName(int ModIndex, int CompIndex) = 0 ;
	virtual bool __stdcall RegisterFileSystem(Fileintf::TIVirtualFileSystem* AVirtualFileSystem) = 0 ;
	virtual bool __stdcall UnRegisterFileSystem(const AnsiString Ident) = 0 ;
	virtual Fileintf::TIVirtualFileSystem* __stdcall GetFileSystem(const AnsiString Ident) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall GetModuleInterface(const AnsiString FileName) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall GetFormModuleInterface(const AnsiString FormName) = 0 ;
	virtual TIMainMenuIntf* __stdcall GetMainMenu(void) = 0 ;
	virtual bool __stdcall AddNotifier(TIAddInNotifier* AddInNotifier) = 0 ;
	virtual bool __stdcall RemoveNotifier(TIAddInNotifier* AddInNotifier) = 0 ;
	virtual void * __stdcall NewPascalString(char * Str) = 0 ;
	virtual void __stdcall FreePascalString(void * &Str) = 0 ;
	virtual void __stdcall ReferencePascalString(void * &Str) = 0 ;
	virtual void __stdcall AssignPascalString(void * &Dest, void * &Src) = 0 ;
	virtual void __stdcall RaiseException(const AnsiString Message) = 0 ;
	virtual AnsiString __stdcall GetBaseRegistryKey(void) = 0 ;
	virtual Types::TRect __stdcall GetFormBounds(TBoundsType BoundsType) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall ProjectCreate(Editintf::TIProjectCreator* ProjectCreator, TCreateProjectFlags CreateFlags) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall ModuleCreate(Editintf::TIModuleCreator* ModuleCreator, TCreateModuleFlags CreateFlags) = 0 ;
	virtual bool __stdcall AddNotifierEx(TIAddInNotifier* AddInNotifier) = 0 ;
	virtual bool __stdcall GetNewModuleAndClassName(const AnsiString Prefix, AnsiString &UnitIdent, AnsiString &ClassName, AnsiString &FileName) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall CreateCppModule(const AnsiString ModuleName, const AnsiString FormName, const AnsiString AncestorClass, const AnsiString FileSystem, _di_IStream HdrSource, _di_IStream Source, _di_IStream Form, TCreateModuleFlags CreateFlags) = 0 ;
	virtual int __stdcall GetVcsCount(void) = 0 ;
	virtual void __stdcall GetVcsList(Classes::TStringList* List) = 0 ;
	virtual AnsiString __stdcall GetVcsName(int Index) = 0 ;
	virtual bool __stdcall EnumProjectModules(TProjectEnumModuleProc EnumProc, void * Param) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall ProjectCreateEx(Editintf::TIProjectCreatorEx* ProjectCreator, TCreateProjectFlags CreateFlags) = 0 ;
	virtual Editintf::TIModuleInterface* __stdcall ModuleCreateEx(Editintf::TIModuleCreatorEx* ModuleCreator, TCreateModuleFlags CreateFlags) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIToolServices(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIToolServices(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Toolintf */
using namespace Toolintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ToolIntf
