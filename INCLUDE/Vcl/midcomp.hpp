// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidComp.pas' rev: 6.00

#ifndef MidCompHPP
#define MidCompHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebComp.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <msxml.h>

namespace Midcomp
{
//-- type declarations -------------------------------------------------------
__interface IScriptProducer;
typedef System::DelphiInterface<IScriptProducer> _di_IScriptProducer;
__interface IScriptManager;
typedef System::DelphiInterface<IScriptManager> _di_IScriptManager;
__interface INTERFACE_UUID("{555DA472-F254-11D2-AA55-00A024C11562}") IScriptProducer  : public IInterface 
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
__interface IAddScriptElements;
typedef System::DelphiInterface<IAddScriptElements> _di_IAddScriptElements;
__interface INTERFACE_UUID("{94B8B14E-E6D6-11D2-AFA6-00C04FB16EC3}") IScriptManager  : public IInterface 
{
	
public:
	virtual _di_IXMLDocuments __fastcall GetXMLDocuments(void) = 0 ;
	virtual _di_IIncludeFiles __fastcall GetIncludeFiles(void) = 0 ;
	virtual _di_IFunctions __fastcall GetFunctions(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetWarnings(void) = 0 ;
	virtual _di_IScriptBlocks __fastcall GetScriptBlocks(void) = 0 ;
	virtual _di_IVars __fastcall GetVars(void) = 0 ;
	virtual _di_IHTMLBlocks __fastcall GetHTMLBlocks(void) = 0 ;
	virtual Webcomp::TWebContentOptions* __fastcall GetOptions(void) = 0 ;
	virtual _di_IAddScriptElements __fastcall GetAddElementsIntf(void) = 0 ;
	virtual void __fastcall AddError(const AnsiString Error) = 0 ;
	__property _di_IXMLDocuments XMLDocuments = {read=GetXMLDocuments};
	__property _di_IIncludeFiles IncludeFiles = {read=GetIncludeFiles};
	__property Classes::TStrings* Warnings = {read=GetWarnings};
	__property _di_IFunctions Functions = {read=GetFunctions};
	__property _di_IVars Vars = {read=GetVars};
	__property _di_IScriptBlocks ScriptBlocks = {read=GetScriptBlocks};
	__property _di_IHTMLBlocks HTMLBlocks = {read=GetHTMLBlocks};
	__property Webcomp::TWebContentOptions* Options = {read=GetOptions};
	__property _di_IAddScriptElements AddElementsIntf = {read=GetAddElementsIntf};
};

__interface IIncludeFile;
typedef System::DelphiInterface<IIncludeFile> _di_IIncludeFile;
__interface INTERFACE_UUID("{F735BC77-E7A4-11D2-AFA7-00C04FB16EC3}") IIncludeFiles  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IIncludeFile __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IIncludeFile Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{F735BC78-E7A4-11D2-AFA7-00C04FB16EC3}") IIncludeFile  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
};

__interface IFunction;
typedef System::DelphiInterface<IFunction> _di_IFunction;
__interface INTERFACE_UUID("{3AA43171-EC43-11D2-AFAE-00C04FB16EC3}") IFunctions  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IFunction __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IFunction Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{3AA43172-EC43-11D2-AFAE-00C04FB16EC3}") IFunction  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetFunctionName(void) = 0 ;
	virtual AnsiString __fastcall GetBody(void) = 0 ;
	__property AnsiString FunctionName = {read=GetFunctionName};
	__property AnsiString Body = {read=GetBody};
};

__interface IVar;
typedef System::DelphiInterface<IVar> _di_IVar;
__interface INTERFACE_UUID("{8AFBBDE2-2A11-11D3-AAAB-00A024C11562}") IVars  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IVar __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IVar Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE3-2A11-11D3-AAAB-00A024C11562}") IVar  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetVarName(void) = 0 ;
	virtual AnsiString __fastcall GetScript(void) = 0 ;
	__property AnsiString VarName = {read=GetVarName};
	__property AnsiString Script = {read=GetScript};
};

__interface IHTMLBlock;
typedef System::DelphiInterface<IHTMLBlock> _di_IHTMLBlock;
__interface INTERFACE_UUID("{8AFBBDE4-2A11-11D3-AAAB-00A024C11562}") IHTMLBlocks  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IHTMLBlock __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IHTMLBlock Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE5-2A11-11D3-AAAB-00A024C11562}") IHTMLBlock  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetBlockName(void) = 0 ;
	virtual AnsiString __fastcall GetHTML(void) = 0 ;
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString HTML = {read=GetHTML};
};

__interface IScriptBlock;
typedef System::DelphiInterface<IScriptBlock> _di_IScriptBlock;
__interface INTERFACE_UUID("{8AFBBDE6-2A11-11D3-AAAB-00A024C11562}") IScriptBlocks  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IScriptBlock __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IScriptBlock Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{8AFBBDE7-2A11-11D3-AAAB-00A024C11562}") IScriptBlock  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetBlockName(void) = 0 ;
	virtual AnsiString __fastcall GetScript(void) = 0 ;
	__property AnsiString BlockName = {read=GetBlockName};
	__property AnsiString Script = {read=GetScript};
};

__interface IXMLDocument;
typedef System::DelphiInterface<IXMLDocument> _di_IXMLDocument;
__interface INTERFACE_UUID("{94B8B150-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLDocuments  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLDocument __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLDocument Items[int I] = {read=GetItem};
};

__interface IXMLRowSets;
typedef System::DelphiInterface<IXMLRowSets> _di_IXMLRowSets;
__interface INTERFACE_UUID("{94B8B151-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLDocument  : public IInterface 
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
__interface INTERFACE_UUID("{94B8B152-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLRowSets  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IXMLRowSet __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IXMLRowSet Items[int I] = {read=GetItem};
};

__interface INTERFACE_UUID("{94B8B14F-E6D6-11D2-AFA6-00C04FB16EC3}") IXMLRowSet  : public IInterface 
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

typedef void __fastcall (__closure *TAddScriptElementsEvent)(void * Data, _di_IAddScriptElements AddScriptElements);

__interface INTERFACE_UUID("{2FF3A331-E790-11D2-AFA7-00C04FB16EC3}") IAddScriptElements  : public IInterface 
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
__interface INTERFACE_UUID("{1B9B0962-D28E-11D2-AF8A-00C04FB16EC3}") IScriptComponent  : public IInterface 
{
	
public:
	virtual void __fastcall AddElements(_di_IAddScriptElements AddIntf) = 0 ;
	virtual System::TObject* __fastcall GetSubComponents(void) = 0 ;
	__property System::TObject* SubComponents = {read=GetSubComponents};
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Midcomp */
using namespace Midcomp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidComp
