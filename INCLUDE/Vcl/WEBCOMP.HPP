// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebComp.pas' rev: 5.00

#ifndef WebCompHPP
#define WebCompHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Masks.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webcomp
{
//-- type declarations -------------------------------------------------------
__interface IScriptProducer;
typedef System::DelphiInterface<IScriptProducer> _di_IScriptProducer;
__interface IScriptManager;
typedef System::DelphiInterface<IScriptManager> _di_IScriptManager;
__interface INTERFACE_UUID("{555DA472-F254-11D2-AA55-00A024C11562}") IScriptProducer  : public IUnknown 
	
{
	
public:
	virtual _di_IScriptManager __fastcall GetScriptManager(void) = 0 ;
	__property _di_IScriptManager ScriptManager = {read=GetScriptManager};
};

__interface IXMLDocuments;
typedef System::DelphiInterface<IXMLDocuments> _di_IXMLDocuments;
__interface IIncludeFiles;
typedef System::DelphiInterface<IIncludeFiles> _di_IIncludeFiles;
__interface IFunctions;
typedef System::DelphiInterface<IFunctions> _di_IFunctions;
__interface IScriptBlocks;
typedef System::DelphiInterface<IScriptBlocks> _di_IScriptBlocks;
__interface IVars;
typedef System::DelphiInterface<IVars> _di_IVars;
__interface IHTMLBlocks;
typedef System::DelphiInterface<IHTMLBlocks> _di_IHTMLBlocks;
class DELPHICLASS TWebContentOptions;
__interface IAddScriptElements;
typedef System::DelphiInterface<IAddScriptElements> _di_IAddScriptElements;
__interface INTERFACE_UUID("{94B8B14E-E6D6-11D2-AFA6-00C04FB16EC3}") IScriptManager  : public IUnknown 
	
{
	
public:
	virtual _di_IXMLDocuments __fastcall GetXMLDocuments(void) = 0 ;
	virtual _di_IIncludeFiles __fastcall GetIncludeFiles(void) = 0 ;
	virtual _di_IFunctions __fastcall GetFunctions(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetWarnings(void) = 0 ;
	virtual _di_IScriptBlocks __fastcall GetScriptBlocks(void) = 0 ;
	virtual _di_IVars __fastcall GetVars(void) = 0 ;
	virtual _di_IHTMLBlocks __fastcall GetHTMLBlocks(void) = 0 ;
	virtual TWebContentOptions* __fastcall GetOptions(void) = 0 ;
	virtual _di_IAddScriptElements __fastcall GetAddElementsIntf(void) = 0 ;
	virtual void __fastcall AddError(const AnsiString Error) = 0 ;
	__property _di_IXMLDocuments XMLDocuments = {read=GetXMLDocuments};
	__property _di_IIncludeFiles IncludeFiles = {read=GetIncludeFiles};
	__property Classes::TStrings* Warnings = {read=GetWarnings};
	__property _di_IFunctions Functions = {read=GetFunctions};
	__property _di_IVars Vars = {read=GetVars};
	__property _di_IScriptBlocks ScriptBlocks = {read=GetScriptBlocks};
	__property _di_IHTMLBlocks HTMLBlocks = {read=GetHTMLBlocks};
	__property TWebContentOptions* Options = {read=GetOptions};
	__property _di_IAddScriptElements AddElementsIntf = {read=GetAddElementsIntf};
};

__interface IIncludeFile;
typedef System::DelphiInterface<IIncludeFile> _di_IIncludeFile;
__interface INTERFACE_UUID("{F735BC77-E7A4-11D2-AFA7-00C04FB16EC3}") IIncludeFiles  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IIncludeFile __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IIncludeFile Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{F735BC78-E7A4-11D2-AFA7-00C04FB16EC3}") IIncludeFile  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
};

__interface IFunction;
typedef System::DelphiInterface<IFunction> _di_IFunction;
__interface INTERFACE_UUID("{3AA43171-EC43-11D2-AFAE-00C04FB16EC3}") IFunctions  : public IUnknown 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IFunction __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IFunction Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{3AA43172-EC43-11D2-AFAE-00C04FB16EC3}") IFunction  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall GetFunctionName(void) = 0 ;
	virtual AnsiString __fastcall GetBody(void) = 0 ;
	__property AnsiString FunctionName = {read=GetFunctionName};
	__property AnsiString Body = {read=GetBody};
};

__interface IVar;
typedef System::DelphiInterface<IVar> _di_IVar;
__interface INTERFACE_UUID("{8AFBBDE2-2A11-11D3-AAAB-00A024C11562}") IVars  : public IUnknown 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IVar __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IVar Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE3-2A11-11D3-AAAB-00A024C11562}") IVar  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall GetVarName(void) = 0 ;
	virtual AnsiString __fastcall GetScript(void) = 0 ;
	__property AnsiString VarName = {read=GetVarName};
	__property AnsiString Script = {read=GetScript};
};

__interface IHTMLBlock;
typedef System::DelphiInterface<IHTMLBlock> _di_IHTMLBlock;
__interface INTERFACE_UUID("{8AFBBDE4-2A11-11D3-AAAB-00A024C11562}") IHTMLBlocks  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IHTMLBlock __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IHTMLBlock Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE5-2A11-11D3-AAAB-00A024C11562}") IHTMLBlock  : public IUnknown 
{
	
public:
	virtual AnsiString __fastcall GetBlockName(void) = 0 ;
	virtual AnsiString __fastcall GetHTML(void) = 0 ;
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString HTML = {read=GetHTML};
};

__interface IScriptBlock;
typedef System::DelphiInterface<IScriptBlock> _di_IScriptBlock;
__interface INTERFACE_UUID("{8AFBBDE6-2A11-11D3-AAAB-00A024C11562}") IScriptBlocks  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IScriptBlock __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IScriptBlock Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE7-2A11-11D3-AAAB-00A024C11562}") IScriptBlock  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall GetBlockName(void) = 0 ;
	virtual AnsiString __fastcall GetScript(void) = 0 ;
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString Script = {read=GetScript};
};

__interface IXMLDocument;
typedef System::DelphiInterface<IXMLDocument> _di_IXMLDocument;
__interface INTERFACE_UUID("{94B8B150-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLDocuments  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLDocument __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLDocument Items[int I] = {read=GetItem};
};

__interface IXMLRowSets;
typedef System::DelphiInterface<IXMLRowSets> _di_IXMLRowSets;
__interface INTERFACE_UUID("{94B8B151-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLDocument  : public IUnknown 
	
{
	
public:
	virtual _di_IXMLRowSets __fastcall GetRowSets(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(void) = 0 ;
	virtual AnsiString __fastcall GetDocumentVarName(void) = 0 ;
	virtual AnsiString __fastcall GetXMLVarName(void) = 0 ;
	__property _di_IXMLRowSets RowSets = {read=GetRowSets};
	__property Classes::TComponent* Component = {read=GetComponent};
	__property AnsiString DocumentVarName = {read=GetDocumentVarName};
	__property AnsiString XMLVarName = {read=GetXMLVarName};
};

__interface IXMLRowSet;
typedef System::DelphiInterface<IXMLRowSet> _di_IXMLRowSet;
__interface INTERFACE_UUID("{94B8B152-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLRowSets  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLRowSet __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLRowSet Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{94B8B14F-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLRowSet  : public IUnknown 
{
	
public:
	virtual Classes::TStrings* __fastcall GetPath(void) = 0 ;
	virtual AnsiString __fastcall GetRowSetVarName(void) = 0 ;
	virtual AnsiString __fastcall GetMasterRowSetVarName(void) = 0 ;
	virtual AnsiString __fastcall GetMasterDataSetFieldName(void) = 0 ;
	__property AnsiString MasterRowSetVarName = {read=GetMasterRowSetVarName};
	__property AnsiString MasterDataSetFieldName = {read=GetMasterDataSetFieldName};
	__property AnsiString RowSetVarName = {read=GetRowSetVarName};
};

typedef void __fastcall (__closure *TAddScriptElementsEvent)(void * Data, _di_IAddScriptElements AddScriptElements
	);

__interface INTERFACE_UUID("{2FF3A331-E790-11D2-AFA7-00C04FB16EC3}") IAddScriptElements  : public IUnknown 
	
{
	
public:
	virtual _di_IScriptManager __fastcall GetScriptManager(void) = 0 ;
	virtual bool __fastcall AddIncludeFile(AnsiString FileName) = 0 ;
	virtual bool __fastcall AddRowSet(Classes::TComponent* XMLProducer, Classes::TStrings* Path) = 0 ;
	virtual bool __fastcall AddScriptBlock(AnsiString Name, AnsiString Script) = 0 ;
	virtual bool __fastcall AddHTMLBlock(AnsiString Name, AnsiString HTML) = 0 ;
	virtual bool __fastcall AddVar(AnsiString Name, AnsiString Script) = 0 ;
	virtual bool __fastcall AddFunction(AnsiString Name, AnsiString Body) = 0 ;
	virtual void __fastcall AddError(AnsiString Text) = 0 ;
	virtual void __fastcall AddPass(TAddScriptElementsEvent Event, void * Data) = 0 ;
	virtual void __fastcall AddScriptComponents(System::TObject* List) = 0 ;
	__property _di_IScriptManager ScriptManager = {read=GetScriptManager};
};

__interface IScriptComponent;
typedef System::DelphiInterface<IScriptComponent> _di_IScriptComponent;
__interface INTERFACE_UUID("{1B9B0962-D28E-11D2-AF8A-00C04FB16EC3}") IScriptComponent  : public IUnknown 
	
{
	
public:
	virtual void __fastcall AddElements(_di_IAddScriptElements AddIntf) = 0 ;
	virtual System::TObject* __fastcall GetSubComponents(void) = 0 ;
	__property System::TObject* SubComponents = {read=GetSubComponents};
};

typedef TObject TWebComponentContainer;
;

__interface IWebComponentContainer;
typedef System::DelphiInterface<IWebComponentContainer> _di_IWebComponentContainer;
__interface INTERFACE_UUID("{44957E12-E039-11D2-AA46-00A024C11562}") IWebComponentContainer  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetComponentCount(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(int I) = 0 ;
	__property int ComponentCount = {read=GetComponentCount};
	__property Classes::TComponent* Components[int I] = {read=GetComponent};
};

__interface IWebComponentEditor;
typedef System::DelphiInterface<IWebComponentEditor> _di_IWebComponentEditor;
__interface INTERFACE_UUID("{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}") IWebComponentEditor  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass) = 0 ;
};

__interface IWebComponentEditorHelper;
typedef System::DelphiInterface<IWebComponentEditorHelper> _di_IWebComponentEditorHelper;
__interface INTERFACE_UUID("{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}") IWebComponentEditorHelper  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall CanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent
		, TMetaClass* AClass) = 0 ;
};

__interface IWebComponentCommands;
typedef System::DelphiInterface<IWebComponentCommands> _di_IWebComponentCommands;
__interface INTERFACE_UUID("{FCB67B0D-F357-11D2-AFB6-00C04FB16EC3}") IWebComponentCommands  : public IUnknown 
	
{
	
public:
	virtual void __fastcall ExecuteVerb(Classes::TComponent* AComponent, int Index) = 0 ;
	virtual AnsiString __fastcall GetVerb(Classes::TComponent* AComponent, int Index) = 0 ;
	virtual int __fastcall GetVerbCount(Classes::TComponent* AComponent) = 0 ;
};

__interface IWebComponent;
typedef System::DelphiInterface<IWebComponent> _di_IWebComponent;
__interface INTERFACE_UUID("{EB813782-EEAE-11D2-AFB0-00C04FB16EC3}") IWebComponent  : public IUnknown 
	
{
	
public:
	virtual int __fastcall GetIndex(void) = 0 ;
	virtual void __fastcall SetIndex(int Value) = 0 ;
	virtual void __fastcall SetContainer(System::TObject* Container) = 0 ;
	virtual System::TObject* __fastcall GetContainer(void) = 0 ;
	virtual void __fastcall SetComponentList(System::TObject* List) = 0 ;
	__property int Index = {read=GetIndex, write=SetIndex};
	__property System::TObject* Container = {read=GetContainer, write=SetContainer};
	__property System::TObject* ComponentList = {write=SetComponentList};
};

__interface IGetWebComponentList;
typedef System::DelphiInterface<IGetWebComponentList> _di_IGetWebComponentList;
__interface INTERFACE_UUID("{5CDEB0F2-EEF9-11D2-AFB1-00C04FB16EC3}") IGetWebComponentList  : public IUnknown 
	
{
	
public:
	virtual System::TObject* __fastcall GetComponentList(void) = 0 ;
	virtual System::TObject* __fastcall GetDefaultComponentList(void) = 0 ;
};

#pragma option push -b-
enum TWebContentFlag { coNoScript, coLocalPaths };
#pragma option pop

typedef Set<TWebContentFlag, coNoScript, coLocalPaths>  TWebContentFlags;

class PASCALIMPLEMENTATION TWebContentOptions : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TWebContentFlags FFlags;
	
public:
	__fastcall TWebContentOptions(TWebContentFlags AFlags);
	__property TWebContentFlags Flags = {read=FFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebContentOptions(void) { }
	#pragma option pop
	
};


typedef TObject TLayout;
;

__interface IWebContent;
typedef System::DelphiInterface<IWebContent> _di_IWebContent;
__interface INTERFACE_UUID("{1B3E1CD1-DF59-11D2-AA45-00A024C11562}") IWebContent  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall Content(TWebContentOptions* Options, System::TObject* ParentLayout) = 0 
		;
};

#pragma option push -b-
enum TLabelPosition { lposLeft, lposRight, lposAbove, lposBelow };
#pragma option pop

class DELPHICLASS TLayoutAttributes;
class PASCALIMPLEMENTATION TLayoutAttributes : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString LabelAttributes;
	AnsiString ControlAttributes;
	TLabelPosition LabelPosition;
	__fastcall TLayoutAttributes(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLayoutAttributes(void) { }
	#pragma option pop
	
};


__interface ILayoutWebContent;
typedef System::DelphiInterface<ILayoutWebContent> _di_ILayoutWebContent;
__interface INTERFACE_UUID("{4E810ED1-F09B-11D2-AA53-00A024C11562}") ILayoutWebContent  : public IUnknown 
	
{
	
public:
	virtual AnsiString __fastcall LayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes
		) = 0 ;
	virtual AnsiString __fastcall LayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes
		) = 0 ;
	virtual AnsiString __fastcall LayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField
		, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall LayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes
		) = 0 ;
};

class DELPHICLASS TLayoutWebContent;
class PASCALIMPLEMENTATION TLayoutWebContent : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	System::TObject* FParentLayout;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	AnsiString __fastcall LayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes);
	AnsiString __fastcall LayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes);
	AnsiString __fastcall LayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString HTMLField, TLayoutAttributes* 
		Attributes);
	AnsiString __fastcall LayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes);
	virtual AnsiString __fastcall ImplLayoutButton(const AnsiString HTMLButton, TLayoutAttributes* Attributes
		) = 0 ;
	virtual AnsiString __fastcall ImplLayoutField(const AnsiString HTMLField, TLayoutAttributes* Attributes
		) = 0 ;
	virtual AnsiString __fastcall ImplLayoutLabelAndField(const AnsiString HTMLLabel, const AnsiString 
		HTMLField, TLayoutAttributes* Attributes) = 0 ;
	virtual AnsiString __fastcall ImplLayoutTable(const AnsiString HTMLTable, TLayoutAttributes* Attributes
		) = 0 ;
	
public:
	__fastcall TLayoutWebContent(System::TObject* AParentLayout);
	__property System::TObject* ParentLayout = {read=FParentLayout};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLayoutWebContent(void) { }
	#pragma option pop
	
private:
	void *__ILayoutWebContent;	/* Webcomp::ILayoutWebContent */
	
public:
	operator ILayoutWebContent*(void) { return (ILayoutWebContent*)&__ILayoutWebContent; }
	
};


class DELPHICLASS TWebComponentList;
class PASCALIMPLEMENTATION TWebComponentList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* FParentComponent;
	Classes::TList* FList;
	
protected:
	int __fastcall GetCount(void);
	Classes::TComponent* __fastcall GetComponent(int Index);
	virtual Classes::TComponent* __fastcall NewComponent(Classes::TComponent* AOwner);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	int __fastcall WebComponentContainer_GetComponentCount(void);
	Classes::TComponent* __fastcall WebComponentContainer_GetComponent(int I);
	
public:
	__fastcall TWebComponentList(Classes::TComponent* AParentComponent);
	__fastcall virtual ~TWebComponentList(void);
	void __fastcall Add(Classes::TComponent* Component);
	void __fastcall SetComponentIndex(Classes::TComponent* Component, int Value);
	void __fastcall Clear(void);
	int __fastcall IndexOf(Classes::TComponent* Component);
	void __fastcall Remove(Classes::TComponent* Component);
	__property int Count = {read=GetCount, nodefault};
	__property Classes::TComponent* WebComponents[int Index] = {read=GetComponent/*, default*/};
	__property Classes::TComponent* ParentComponent = {read=FParentComponent};
private:
	void *__IWebComponentContainer;	/* Webcomp::IWebComponentContainer [GetComponent=WebComponentContainer_GetComponent, 
		GetComponentCount=WebComponentContainer_GetComponentCount] */
	
public:
	operator IWebComponentContainer*(void) { return (IWebComponentContainer*)&__IWebComponentContainer; }
		
	
};


typedef void __fastcall (__closure *TEnumWebComponentsProc)(TMetaClass* WebComponentClass, System::TObject* 
	Editor, void * Info);

class DELPHICLASS TWebComponentsEditorHelper;
class PASCALIMPLEMENTATION TWebComponentsEditorHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	bool __fastcall CanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* 
		AClass);
	virtual bool __fastcall ImplCanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent
		, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TWebComponentsEditorHelper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebComponentsEditorHelper(void) { }
	#pragma option pop
	
private:
	void *__IWebComponentEditorHelper;	/* Webcomp::IWebComponentEditorHelper */
	
public:
	operator IWebComponentEditorHelper*(void) { return (IWebComponentEditorHelper*)&__IWebComponentEditorHelper; }
		
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall (*RegisterWebComponentsProc)(TMetaClass* const * AClasses, const int 
	AClasses_Size, System::TObject* Editor);
extern PACKAGE void __fastcall (*UnRegisterWebComponentsProc)(TMetaClass* const * AClasses, const int 
	AClasses_Size);
extern PACKAGE void __fastcall (*EnumRegisteredWebComponentsProc)(TEnumWebComponentsProc Proc, void * 
	Info);
extern PACKAGE System::TObject* __fastcall (*FindWebComponentEditorHelperProc)(TMetaClass* AClass);
extern PACKAGE void __fastcall RegisterWebComponents(TMetaClass** AClasses, const int AClasses_Size
	, System::TObject* Editor);
extern PACKAGE void __fastcall UnRegisterWebComponents(TMetaClass** AClasses, const int AClasses_Size
	);
extern PACKAGE void __fastcall EnumRegisteredWebComponents(TEnumWebComponentsProc Proc, void * Info)
	;
extern PACKAGE System::TObject* __fastcall FindWebComponentEditorHelper(TMetaClass* AClass);

}	/* namespace Webcomp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Webcomp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebComp
