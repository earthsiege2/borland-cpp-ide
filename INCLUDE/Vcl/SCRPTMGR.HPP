// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ScrptMgr.pas' rev: 5.00

#ifndef ScrptMgrHPP
#define ScrptMgrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <XMLBrokr.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <CompProd.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Scrptmgr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TScriptObject;
class PASCALIMPLEMENTATION TScriptObject : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::TObject* FParent;
	
public:
	__fastcall TScriptObject(System::TObject* AParent);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TScriptObject(void) { }
	#pragma option pop
	
};


__interface INameContent;
typedef System::DelphiInterface<INameContent> _di_INameContent;
__interface INTERFACE_UUID("{8AFBBDE8-2A11-11D3-AAAB-00A024C11562}") INameContent  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual AnsiString __fastcall GetContent(void) = 0 ;
	virtual bool __fastcall MatchName(const AnsiString Name) = 0 ;
	__property AnsiString Name = {read=GetName};
	__property AnsiString Content = {read=GetContent};
};

class DELPHICLASS TNameContentScriptObject;
class PASCALIMPLEMENTATION TNameContentScriptObject : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	AnsiString FName;
	AnsiString FContent;
	
protected:
	AnsiString __fastcall GetName();
	AnsiString __fastcall GetContent();
	bool __fastcall MatchName(const AnsiString AName);
	
public:
	__fastcall TNameContentScriptObject(System::TObject* AParent, const AnsiString AName, const AnsiString 
		AContent);
	__property AnsiString Name = {read=GetName};
	__property AnsiString Content = {read=GetContent};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TNameContentScriptObject(void) { }
	#pragma option pop
	
private:
	void *__INameContent;	/* Scrptmgr::INameContent */
	
public:
	operator INameContent*(void) { return (INameContent*)&__INameContent; }
	
};


struct TItemHolder
{
	_di_IUnknown FIntf;
	TScriptObject* FObject;
} ;

typedef DynamicArray<TItemHolder >  ScrptMgr__4;

class DELPHICLASS TScriptObjectContainer;
class PASCALIMPLEMENTATION TScriptObjectContainer : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	DynamicArray<TItemHolder >  FItems;
	
protected:
	int __fastcall Add(TScriptObject* AObject);
	int __fastcall GetCount(void);
	TScriptObject* __fastcall GetAsObject(int I);
	_di_IUnknown __fastcall GetAsIntf(int I);
	
public:
	__fastcall virtual ~TScriptObjectContainer(void);
	TScriptObject* __fastcall FindNameObject(const AnsiString AName);
	__property int Count = {read=GetCount, nodefault};
	__property TScriptObject* Objects[int I] = {read=GetAsObject};
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TScriptObjectContainer(System::TObject* AParent) : TScriptObject(
		AParent) { }
	#pragma option pop
	
};


class DELPHICLASS TScriptManager;
class DELPHICLASS TXMLDocuments;
class DELPHICLASS TXMLDocument;
class PASCALIMPLEMENTATION TXMLDocuments : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TXMLDocument* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IXMLDocument __fastcall GetItem(int I);
	
public:
	TXMLDocument* __fastcall AddXMLBroker(Xmlbrokr::TXMLBroker* XMLBroker);
	TXMLDocument* __fastcall FindXMLBroker(Xmlbrokr::TXMLBroker* XMLBroker);
	__property TXMLDocument* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IXMLDocument Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~TXMLDocuments(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TXMLDocuments(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IXMLDocuments;	/* Webcomp::IXMLDocuments */
	
public:
	operator IXMLDocuments*(void) { return (IXMLDocuments*)&__IXMLDocuments; }
	
};


class DELPHICLASS TIncludeFiles;
class DELPHICLASS TIncludeFile;
class PASCALIMPLEMENTATION TIncludeFiles : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TIncludeFile* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IIncludeFile __fastcall GetItem(int I);
	
public:
	TIncludeFile* __fastcall AddFileName(const AnsiString FileName);
	TIncludeFile* __fastcall FindFileName(const AnsiString FileName);
	__property TIncludeFile* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IIncludeFile Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~TIncludeFiles(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TIncludeFiles(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IIncludeFiles;	/* Webcomp::IIncludeFiles */
	
public:
	operator IIncludeFiles*(void) { return (IIncludeFiles*)&__IIncludeFiles; }
	
};


class DELPHICLASS TFunctions;
class DELPHICLASS TFunction;
class PASCALIMPLEMENTATION TFunctions : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TFunction* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IFunction __fastcall GetItem(int I);
	
public:
	TFunction* __fastcall AddFunction(const AnsiString Name, const AnsiString Body);
	TFunction* __fastcall FindFunctionName(const AnsiString Name);
	__property TFunction* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IFunction Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~TFunctions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TFunctions(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IFunctions;	/* Webcomp::IFunctions */
	
public:
	operator IFunctions*(void) { return (IFunctions*)&__IFunctions; }
	
};


class DELPHICLASS TScriptBlocks;
class DELPHICLASS TScriptBlock;
class PASCALIMPLEMENTATION TScriptBlocks : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TScriptBlock* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IScriptBlock __fastcall GetItem(int I);
	
public:
	TScriptBlock* __fastcall AddBlock(const AnsiString Name, const AnsiString Script);
	TScriptBlock* __fastcall FindBlockName(const AnsiString Name);
	__property TScriptBlock* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IScriptBlock Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~TScriptBlocks(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TScriptBlocks(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IScriptBlocks;	/* Webcomp::IScriptBlocks */
	
public:
	operator IScriptBlocks*(void) { return (IScriptBlocks*)&__IScriptBlocks; }
	
};


class DELPHICLASS TVars;
class DELPHICLASS TVar;
class PASCALIMPLEMENTATION TVars : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TVar* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IVar __fastcall GetItem(int I);
	
public:
	TVar* __fastcall AddVar(const AnsiString Name, const AnsiString Script);
	TVar* __fastcall FindVarName(const AnsiString Name);
	__property TVar* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IVar Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~TVars(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TVars(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IVars;	/* Webcomp::IVars */
	
public:
	operator IVars*(void) { return (IVars*)&__IVars; }
	
};


class DELPHICLASS THTMLBlocks;
class DELPHICLASS THTMLBlock;
class PASCALIMPLEMENTATION THTMLBlocks : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	THTMLBlock* __fastcall GetObject(int I);
	
protected:
	Webcomp::_di_IHTMLBlock __fastcall GetItem(int I);
	
public:
	THTMLBlock* __fastcall AddBlock(const AnsiString Name, const AnsiString HTML);
	THTMLBlock* __fastcall FindBlockName(const AnsiString Name);
	__property THTMLBlock* Objects[int I] = {read=GetObject};
	__property Webcomp::_di_IHTMLBlock Items[int I] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TScriptObjectContainer.Destroy */ inline __fastcall virtual ~THTMLBlocks(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall THTMLBlocks(System::TObject* AParent) : TScriptObjectContainer(
		AParent) { }
	#pragma option pop
	
private:
	void *__IHTMLBlocks;	/* Webcomp::IHTMLBlocks */
	
public:
	operator IHTMLBlocks*(void) { return (IHTMLBlocks*)&__IHTMLBlocks; }
	
};


class DELPHICLASS TPassList;
class DELPHICLASS TPass;
class PASCALIMPLEMENTATION TPassList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
protected:
	HIDESBASE TPass* __fastcall GetItem(int I);
	
public:
	HIDESBASE void __fastcall Add(Webcomp::TAddScriptElementsEvent Event, void * Data);
	__property TPass* Items[int Index] = {read=GetItem};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TPassList(void)/* overload */ : Contnrs::TObjectList() { }
		
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TPassList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAddScriptElements;
class PASCALIMPLEMENTATION TAddScriptElements : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TScriptManager* FScriptManager;
	Classes::TStrings* FEmptyPath;
	
protected:
	bool __fastcall AddIncludeFile(AnsiString FileName);
	bool __fastcall AddRowSet(Classes::TComponent* XMLBroker, Classes::TStrings* Path);
	bool __fastcall AddHTMLBlock(AnsiString Name, AnsiString HTML);
	bool __fastcall AddScriptBlock(AnsiString Name, AnsiString Script);
	bool __fastcall AddFunction(AnsiString Name, AnsiString Body);
	bool __fastcall AddVar(AnsiString Name, AnsiString Script);
	void __fastcall AddError(AnsiString Text);
	void __fastcall AddPass(Webcomp::TAddScriptElementsEvent Event, void * Data);
	void __fastcall AddScriptComponents(System::TObject* List);
	Webcomp::_di_IScriptManager __fastcall GetScriptManager();
	
public:
	__fastcall TAddScriptElements(TScriptManager* AScriptManager);
	__fastcall virtual ~TAddScriptElements(void);
private:
	void *__IAddScriptElements;	/* Webcomp::IAddScriptElements */
	
public:
	operator IAddScriptElements*(void) { return (IAddScriptElements*)&__IAddScriptElements; }
	
};


class PASCALIMPLEMENTATION TScriptManager : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Webcomp::TWebContentOptions* FOptions;
	Classes::TStrings* FWarnings;
	Webcomp::_di_IXMLDocuments FXMLDocumentsIntf;
	TXMLDocuments* FXMLDocuments;
	TIncludeFiles* FIncludeFiles;
	Webcomp::_di_IIncludeFiles FIncludeFilesIntf;
	TFunctions* FFunctions;
	Webcomp::_di_IFunctions FFunctionsIntf;
	TScriptBlocks* FScriptBlocks;
	Webcomp::_di_IScriptBlocks FScriptBlocksIntf;
	TVars* FVars;
	Webcomp::_di_IVars FVarsIntf;
	THTMLBlocks* FHTMLBlocks;
	Webcomp::_di_IHTMLBlocks FHTMLBlocksIntf;
	TPassList* FPassList;
	TAddScriptElements* FAddElements;
	Webcomp::_di_IAddScriptElements FAddElementsIntf;
	void __fastcall AddScriptComponentsInternal(System::TObject* List);
	
protected:
	Webcomp::_di_IXMLDocuments __fastcall GetXMLDocuments();
	Webcomp::_di_IIncludeFiles __fastcall GetIncludeFiles();
	Webcomp::_di_IHTMLBlocks __fastcall GetHTMLBlocks();
	Webcomp::_di_IVars __fastcall GetVars();
	Webcomp::_di_IScriptBlocks __fastcall GetScriptBlocks();
	void __fastcall AddError(const AnsiString S);
	Webcomp::_di_IFunctions __fastcall GetFunctions();
	Classes::TStrings* __fastcall GetWarnings(void);
	Webcomp::TWebContentOptions* __fastcall GetOptions(void);
	Webcomp::_di_IAddScriptElements __fastcall GetAddElementsIntf();
	
public:
	__fastcall TScriptManager(Webcomp::TWebContentOptions* Options);
	__fastcall virtual ~TScriptManager(void);
	void __fastcall AddScriptComponents(System::TObject* List);
	__property Webcomp::_di_IIncludeFiles IncludeFiles = {read=FIncludeFilesIntf};
	__property Webcomp::_di_IScriptBlocks ScriptBlocks = {read=FScriptBlocksIntf};
	__property Webcomp::_di_IVars Vars = {read=FVarsIntf};
	__property Webcomp::_di_IHTMLBlocks HTMLBlocks = {read=FHTMLBlocksIntf};
	__property TPassList* PassList = {read=FPassList};
	__property Webcomp::TWebContentOptions* Options = {read=GetOptions};
	__property Webcomp::_di_IAddScriptElements AddElementsIntf = {read=GetAddElementsIntf};
private:
	void *__IScriptManager;	/* Webcomp::IScriptManager */
	
public:
	operator IScriptManager*(void) { return (IScriptManager*)&__IScriptManager; }
	
};


class PASCALIMPLEMENTATION TIncludeFile : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	AnsiString FFileName;
	
protected:
	AnsiString __fastcall GetFileName();
	__property AnsiString FileName = {read=GetFileName};
public:
	#pragma option push -w-inl
	/* TScriptObject.Create */ inline __fastcall TIncludeFile(System::TObject* AParent) : TScriptObject(
		AParent) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIncludeFile(void) { }
	#pragma option pop
	
private:
	void *__IIncludeFile;	/* Webcomp::IIncludeFile */
	
public:
	operator IIncludeFile*(void) { return (IIncludeFile*)&__IIncludeFile; }
	
};


class PASCALIMPLEMENTATION TFunction : public TNameContentScriptObject 
{
	typedef TNameContentScriptObject inherited;
	
protected:
	AnsiString __fastcall GetFunctionName();
	AnsiString __fastcall GetBody();
	__property AnsiString FunctionName = {read=GetFunctionName};
	__property AnsiString Body = {read=GetBody};
public:
	#pragma option push -w-inl
	/* TNameContentScriptObject.Create */ inline __fastcall TFunction(System::TObject* AParent, const AnsiString 
		AName, const AnsiString AContent) : TNameContentScriptObject(AParent, AName, AContent) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TFunction(void) { }
	#pragma option pop
	
private:
	void *__IFunction;	/* Webcomp::IFunction */
	
public:
	operator IFunction*(void) { return (IFunction*)&__IFunction; }
	
};


class PASCALIMPLEMENTATION TVar : public TNameContentScriptObject 
{
	typedef TNameContentScriptObject inherited;
	
protected:
	AnsiString __fastcall GetVarName();
	AnsiString __fastcall GetScript();
	__property AnsiString VarName = {read=GetVarName};
	__property AnsiString Script = {read=GetScript};
public:
	#pragma option push -w-inl
	/* TNameContentScriptObject.Create */ inline __fastcall TVar(System::TObject* AParent, const AnsiString 
		AName, const AnsiString AContent) : TNameContentScriptObject(AParent, AName, AContent) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVar(void) { }
	#pragma option pop
	
private:
	void *__IVar;	/* Webcomp::IVar */
	
public:
	operator IVar*(void) { return (IVar*)&__IVar; }
	
};


class PASCALIMPLEMENTATION TScriptBlock : public TNameContentScriptObject 
{
	typedef TNameContentScriptObject inherited;
	
protected:
	AnsiString __fastcall GetBlockName();
	AnsiString __fastcall GetScript();
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString Script = {read=GetScript};
public:
	#pragma option push -w-inl
	/* TNameContentScriptObject.Create */ inline __fastcall TScriptBlock(System::TObject* AParent, const 
		AnsiString AName, const AnsiString AContent) : TNameContentScriptObject(AParent, AName, AContent) { }
		
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TScriptBlock(void) { }
	#pragma option pop
	
private:
	void *__IScriptBlock;	/* Webcomp::IScriptBlock */
	
public:
	operator IScriptBlock*(void) { return (IScriptBlock*)&__IScriptBlock; }
	
};


class PASCALIMPLEMENTATION THTMLBlock : public TNameContentScriptObject 
{
	typedef TNameContentScriptObject inherited;
	
protected:
	AnsiString __fastcall GetBlockName();
	AnsiString __fastcall GetHTML();
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString HTML = {read=GetHTML};
public:
	#pragma option push -w-inl
	/* TNameContentScriptObject.Create */ inline __fastcall THTMLBlock(System::TObject* AParent, const 
		AnsiString AName, const AnsiString AContent) : TNameContentScriptObject(AParent, AName, AContent) { }
		
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~THTMLBlock(void) { }
	#pragma option pop
	
private:
	void *__IHTMLBlock;	/* Webcomp::IHTMLBlock */
	
public:
	operator IHTMLBlock*(void) { return (IHTMLBlock*)&__IHTMLBlock; }
	
};


class DELPHICLASS TXMLRowSets;
class DELPHICLASS TXMLRowSet;
class PASCALIMPLEMENTATION TXMLRowSets : public TScriptObjectContainer 
{
	typedef TScriptObjectContainer inherited;
	
private:
	TXMLDocument* FXMLDocument;
	
protected:
	TXMLRowSet* __fastcall FindPath(Classes::TStrings* Path);
	TXMLRowSet* __fastcall AddPath(Classes::TStrings* Path);
	Webcomp::_di_IXMLRowSet __fastcall GetItem(int I);
	TXMLRowSet* __fastcall GetObject(int I);
	__property TXMLRowSet* Objects[int I] = {read=GetObject};
	
public:
	__fastcall TXMLRowSets(TXMLDocument* AXMLDocument);
	__fastcall virtual ~TXMLRowSets(void);
private:
	void *__IXMLRowSets;	/* Webcomp::IXMLRowSets */
	
public:
	operator IXMLRowSets*(void) { return (IXMLRowSets*)&__IXMLRowSets; }
	
};


class PASCALIMPLEMENTATION TXMLDocument : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	TXMLRowSets* FXMLRowSets;
	Webcomp::_di_IXMLRowSets FXMLRowSetsIntf;
	Xmlbrokr::TXMLBroker* FXMLBroker;
	
protected:
	Webcomp::_di_IXMLRowSets __fastcall GetRowSets();
	Classes::TComponent* __fastcall GetComponent(void);
	AnsiString __fastcall GetDocumentVarName();
	AnsiString __fastcall GetXMLVarName();
	Xmlbrokr::TXMLBroker* __fastcall GetXMLBroker(void);
	__property Xmlbrokr::TXMLBroker* XMLBroker = {read=GetXMLBroker};
	
public:
	__fastcall TXMLDocument(TXMLDocuments* AXMLDocuments);
	__fastcall virtual ~TXMLDocument(void);
private:
	void *__IXMLDocument;	/* Webcomp::IXMLDocument */
	
public:
	operator IXMLDocument*(void) { return (IXMLDocument*)&__IXMLDocument; }
	
};


class PASCALIMPLEMENTATION TXMLRowSet : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Classes::TStrings* FPath;
	TXMLRowSets* FXMLRowSets;
	
protected:
	Classes::TStrings* __fastcall GetPath(void);
	AnsiString __fastcall GetRowSetVarName();
	AnsiString __fastcall GetMasterRowSetVarName();
	AnsiString __fastcall GetMasterDataSetFieldName();
	
public:
	__fastcall TXMLRowSet(TXMLRowSets* AXMLRowSets);
	__fastcall virtual ~TXMLRowSet(void);
private:
	void *__IXMLRowSet;	/* Webcomp::IXMLRowSet */
	
public:
	operator IXMLRowSet*(void) { return (IXMLRowSet*)&__IXMLRowSet; }
	
};


class PASCALIMPLEMENTATION TPass : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Webcomp::TAddScriptElementsEvent Event;
	void *Data;
	
public:
	__fastcall TPass(Webcomp::TAddScriptElementsEvent AEvent, void * AData);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPass(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Scrptmgr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Scrptmgr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ScrptMgr
