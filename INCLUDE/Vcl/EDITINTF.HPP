// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'EditIntf.pas' rev: 5.00

#ifndef EditIntfHPP
#define EditIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <VirtIntf.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Editintf
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TEditPos
{
	short Col;
	int Line;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCharPos
{
	short CharIndex;
	int Line;
} ;
#pragma pack(pop)

class DELPHICLASS TIEditReader;
class PASCALIMPLEMENTATION TIEditReader : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual int __stdcall GetText(int Position, char * Buffer, int Count) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIEditReader(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEditReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEditWriter;
class PASCALIMPLEMENTATION TIEditWriter : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual bool __stdcall CopyTo(int Pos) = 0 ;
	virtual bool __stdcall DeleteTo(int Pos) = 0 ;
	virtual bool __stdcall Insert(char * Text) = 0 ;
	virtual int __stdcall Position(void) = 0 ;
	virtual TCharPos __stdcall GetCurrentPos(void) = 0 ;
	__property TCharPos CurrentPos = {read=GetCurrentPos};
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIEditWriter(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEditWriter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEditView;
class PASCALIMPLEMENTATION TIEditView : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual TEditPos __stdcall GetPos(int Index) = 0 ;
	virtual void __stdcall SetPos(int Index, const TEditPos Value) = 0 ;
	virtual tagSIZE __stdcall GetViewSize(void) = 0 ;
	virtual TCharPos __stdcall PosToCharPos(int Pos) = 0 ;
	virtual int __stdcall CharPosToPos(const TCharPos CharPos) = 0 ;
	virtual void __stdcall ConvertPos(bool EdPosToCharPos, TEditPos &EditPos, TCharPos &CharPos) = 0 ;
	virtual void __stdcall GetAttributeAtPos(const TEditPos &EdPos, int &Element, int &LineFlag) = 0 ;
	__property TEditPos CursorPos = {read=GetPos, write=SetPos, index=0};
	__property TEditPos TopPos = {read=GetPos, write=SetPos, index=1};
	__property tagSIZE ViewSize = {read=GetViewSize};
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIEditView(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEditView(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSyntaxHighlighter { shNone, shPascal, shC, shSQL, shQuery };
#pragma option pop

#pragma option push -b-
enum TBlockType { btInclusive, btLine, btColumn, btNonInclusive, btUnknown };
#pragma option pop

class DELPHICLASS TIEditorInterface;
class PASCALIMPLEMENTATION TIEditorInterface : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual TIEditReader* __stdcall CreateReader(void) = 0 ;
	virtual TIEditWriter* __stdcall CreateWriter(void) = 0 ;
	virtual AnsiString __stdcall FileName(void) = 0 ;
	virtual int __stdcall LinesInBuffer(void) = 0 ;
	virtual bool __stdcall BufferModified(void) = 0 ;
	virtual bool __stdcall MarkModified(void) = 0 ;
	virtual TSyntaxHighlighter __stdcall SetSyntaxHighlighter(TSyntaxHighlighter SyntaxHighlighter) = 0 
		;
	virtual int __stdcall GetViewCount(void) = 0 ;
	virtual TIEditView* __stdcall GetView(int Index) = 0 ;
	virtual TIEditWriter* __stdcall CreateUndoableWriter(void) = 0 ;
	virtual TCharPos __stdcall GetBlockAfter(void) = 0 ;
	virtual TCharPos __stdcall GetBlockStart(void) = 0 ;
	virtual TBlockType __stdcall GetBlockType(void) = 0 ;
	virtual bool __stdcall GetBlockVisible(void) = 0 ;
	virtual void __stdcall SetBlockAfter(const TCharPos Value) = 0 ;
	virtual void __stdcall SetBlockStart(const TCharPos Value) = 0 ;
	virtual void __stdcall SetBlockType(TBlockType Value) = 0 ;
	virtual void __stdcall SetBlockVisible(bool Value) = 0 ;
	__property TCharPos BlockStart = {read=GetBlockStart, write=SetBlockStart};
	__property TCharPos BlockAfter = {read=GetBlockAfter, write=SetBlockAfter};
	__property TBlockType BlockType = {read=GetBlockType, write=SetBlockType, nodefault};
	__property bool BlockVisible = {read=GetBlockVisible, write=SetBlockVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIEditorInterface(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEditorInterface(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPropertyType { ptUnknown, ptInteger, ptChar, ptEnumeration, ptFloat, ptString, ptSet, ptClass, 
	ptMethod, ptWChar, ptLString, ptLWString, ptVariant };
#pragma option pop

class DELPHICLASS TIComponentInterface;
typedef bool __stdcall (*TGetChildCallback)(void * Param, TIComponentInterface* ComponentInterface);
	

class PASCALIMPLEMENTATION TIComponentInterface : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual AnsiString __stdcall GetComponentType(void) = 0 ;
	virtual void * __stdcall GetComponentHandle(void) = 0 ;
	virtual TIComponentInterface* __stdcall GetParent(void) = 0 ;
	virtual bool __stdcall IsTControl(void) = 0 ;
	virtual int __stdcall GetPropCount(void) = 0 ;
	virtual AnsiString __stdcall GetPropName(int Index) = 0 ;
	virtual TPropertyType __stdcall GetPropType(int Index) = 0 ;
	virtual TPropertyType __stdcall GetPropTypeByName(const AnsiString Name) = 0 ;
	virtual bool __stdcall GetPropValue(int Index, void *Value) = 0 ;
	virtual bool __stdcall GetPropValueByName(const AnsiString Name, void *Value) = 0 ;
	virtual bool __stdcall SetProp(int Index, const void *Value) = 0 ;
	virtual bool __stdcall SetPropByName(const AnsiString Name, const void *Value) = 0 ;
	virtual bool __stdcall GetChildren(void * Param, TGetChildCallback Proc) = 0 ;
	virtual int __stdcall GetControlCount(void) = 0 ;
	virtual TIComponentInterface* __stdcall GetControl(int Index) = 0 ;
	virtual int __stdcall GetComponentCount(void) = 0 ;
	virtual TIComponentInterface* __stdcall GetComponent(int Index) = 0 ;
	virtual bool __stdcall Select(void) = 0 ;
	virtual bool __stdcall Focus(void) = 0 ;
	virtual bool __stdcall Delete(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIComponentInterface(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIComponentInterface(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIFormInterface;
class PASCALIMPLEMENTATION TIFormInterface : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual AnsiString __stdcall FileName(void) = 0 ;
	virtual bool __stdcall FormModified(void) = 0 ;
	virtual bool __stdcall MarkModified(void) = 0 ;
	virtual TIComponentInterface* __stdcall GetFormComponent(void) = 0 ;
	virtual TIComponentInterface* __stdcall FindComponent(const AnsiString Name) = 0 ;
	virtual TIComponentInterface* __stdcall GetComponentFromHandle(void * ComponentHandle) = 0 ;
	virtual int __stdcall GetSelCount(void) = 0 ;
	virtual TIComponentInterface* __stdcall GetSelComponent(int Index) = 0 ;
	virtual TIComponentInterface* __stdcall GetCreateParent(void) = 0 ;
	virtual TIComponentInterface* __stdcall CreateComponent(TIComponentInterface* Container, const AnsiString 
		TypeName, int X, int Y, int W, int H) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIFormInterface(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIFormInterface(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TResHeaderValue { hvFlags, hvLanguage, hvDataVersion, hvVersion, hvCharacteristics };
#pragma option pop

class DELPHICLASS TIResourceEntry;
class PASCALIMPLEMENTATION TIResourceEntry : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual char * __stdcall GetResourceType(void) = 0 ;
	virtual char * __stdcall GetResourceName(void) = 0 ;
	virtual bool __stdcall Change(char * NewType, char * NewName) = 0 ;
	virtual bool __stdcall GetHeaderValue(TResHeaderValue HeaderValue, int &Value) = 0 ;
	virtual bool __stdcall SetHeaderValue(TResHeaderValue HeaderValue, int Value) = 0 ;
	virtual void * __stdcall GetData(void) = 0 ;
	virtual int __stdcall GetDataSize(void) = 0 ;
	virtual bool __stdcall SetDataSize(int NewSize) = 0 ;
	virtual void * __stdcall GetEntryHandle(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIResourceEntry(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIResourceEntry(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIResourceFile;
class PASCALIMPLEMENTATION TIResourceFile : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual AnsiString __stdcall FileName(void) = 0 ;
	virtual int __stdcall GetEntryCount(void) = 0 ;
	virtual TIResourceEntry* __stdcall GetEntry(int Index) = 0 ;
	virtual TIResourceEntry* __stdcall GetEntryFromHandle(void * EntryHandle) = 0 ;
	virtual TIResourceEntry* __stdcall FindEntry(char * ResType, char * Name) = 0 ;
	virtual bool __stdcall DeleteEntry(void * EntryHandle) = 0 ;
	virtual TIResourceEntry* __stdcall CreateEntry(char * ResType, char * Name, Word Flags, Word LanguageId
		, int DataVersion, int Version, int Characteristics) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIResourceFile(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIResourceFile(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TNotifyCode { ncModuleDeleted, ncModuleRenamed, ncEditorModified, ncFormModified, ncEditorSelected, 
	ncFormSelected, ncBeforeSave, ncAfterSave, ncFormSaving, ncProjResModified };
#pragma option pop

class DELPHICLASS TIModuleNotifier;
class PASCALIMPLEMENTATION TIModuleNotifier : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual void __stdcall Notify(TNotifyCode NotifyCode) = 0 ;
	virtual void __stdcall ComponentRenamed(void * ComponentHandle, const AnsiString OldName, const AnsiString 
		NewName) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIModuleNotifier(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIModuleNotifier(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIModuleInterface;
class PASCALIMPLEMENTATION TIModuleInterface : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual TIEditorInterface* __stdcall GetEditorInterface(void) = 0 ;
	virtual TIFormInterface* __stdcall GetFormInterface(void) = 0 ;
	virtual TIModuleInterface* __stdcall GetAncestorModule(void) = 0 ;
	virtual TIResourceFile* __stdcall GetProjectResource(void) = 0 ;
	virtual bool __stdcall IsProjectModule(void) = 0 ;
	virtual bool __stdcall Close(void) = 0 ;
	virtual bool __stdcall Save(bool ForceSave) = 0 ;
	virtual bool __stdcall Rename(const AnsiString NewName) = 0 ;
	virtual bool __stdcall GetFileSystem(AnsiString &FileSystem) = 0 ;
	virtual bool __stdcall SetFileSystem(const AnsiString FileSystem) = 0 ;
	virtual bool __stdcall ShowSource(void) = 0 ;
	virtual bool __stdcall ShowForm(void) = 0 ;
	virtual bool __stdcall AddNotifier(TIModuleNotifier* AModuleNotifier) = 0 ;
	virtual bool __stdcall RemoveNotifier(TIModuleNotifier* AModuleNotifier) = 0 ;
	virtual TIEditorInterface* __stdcall GetAuxEditorInterface(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIModuleInterface(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIModuleInterface(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIProjectCreator;
class PASCALIMPLEMENTATION TIProjectCreator : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual bool __stdcall Existing(void) = 0 ;
	virtual AnsiString __stdcall GetFileName(void) = 0 ;
	virtual AnsiString __stdcall GetFileSystem(void) = 0 ;
	virtual AnsiString __stdcall NewProjectSource(const AnsiString ProjectName) = 0 ;
	virtual void __stdcall NewDefaultModule(void) = 0 ;
	virtual void __stdcall NewProjectResource(TIModuleInterface* Module) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIProjectCreator(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIProjectCreator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIProjectCreatorEx;
class PASCALIMPLEMENTATION TIProjectCreatorEx : public TIProjectCreator 
{
	typedef TIProjectCreator inherited;
	
public:
	virtual AnsiString __stdcall GetOptionName(void) = 0 ;
	virtual AnsiString __stdcall NewOptionSource(const AnsiString ProjectName) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIProjectCreatorEx(void) : TIProjectCreator() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIProjectCreatorEx(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIModuleCreator;
class PASCALIMPLEMENTATION TIModuleCreator : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual bool __stdcall Existing(void) = 0 ;
	virtual AnsiString __stdcall GetAncestorName(void) = 0 ;
	virtual AnsiString __stdcall GetFileName(void) = 0 ;
	virtual AnsiString __stdcall GetFileSystem(void) = 0 ;
	virtual AnsiString __stdcall GetFormName(void) = 0 ;
	virtual AnsiString __stdcall NewModuleSource(const AnsiString UnitIdent, const AnsiString FormIdent
		, const AnsiString AncestorIdent) = 0 ;
	virtual void __stdcall FormCreated(TIFormInterface* Form) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIModuleCreator(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIModuleCreator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIModuleCreatorEx;
class PASCALIMPLEMENTATION TIModuleCreatorEx : public TIModuleCreator 
{
	typedef TIModuleCreator inherited;
	
public:
	virtual AnsiString __stdcall GetIntfName(void) = 0 ;
	virtual AnsiString __stdcall NewIntfSource(const AnsiString UnitIdent, const AnsiString FormIdent, 
		const AnsiString AncestorIdent) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIModuleCreatorEx(void) : TIModuleCreator() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIModuleCreatorEx(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const int cursorPos = 0x0;
static const int ViewTopPos = 0x1;
static const Shortint atWhiteSpace = 0x0;
static const Shortint atComment = 0x1;
static const Shortint atReservedWord = 0x2;
static const Shortint atIdentifier = 0x3;
static const Shortint atSymbol = 0x4;
static const Shortint atString = 0x5;
static const Shortint atNumber = 0x6;
static const Shortint atFloat = 0x7;
static const Shortint atOctal = 0x8;
static const Shortint atHex = 0x9;
static const Shortint atCharacter = 0xa;
static const Shortint atPreproc = 0xb;
static const Shortint atIllegal = 0xc;
static const Shortint atAssembler = 0xd;
static const Shortint SyntaxOff = 0xe;
static const Shortint MarkedBlock = 0xf;
static const Shortint SearchMatch = 0x10;
static const Shortint lfCurrentCSIP = 0x1;
static const Shortint lfBreakpointEnabled = 0x2;
static const Shortint lfBreakpointDisabled = 0x4;
static const Shortint lfBreakpointInvalid = 0x8;
static const Shortint lfErrorLine = 0x10;
static const Shortint lfBreakpointVerified = 0x20;

}	/* namespace Editintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Editintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// EditIntf
