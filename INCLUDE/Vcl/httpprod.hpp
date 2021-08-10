// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPProd.pas' rev: 6.00

#ifndef HTTPProdHPP
#define HTTPProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpprod
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum THTMLAlign { haDefault, haLeft, haRight, haCenter };
#pragma option pop

#pragma option push -b-
enum THTMLVAlign { haVDefault, haTop, haMiddle, haBottom, haBaseline };
#pragma option pop

typedef AnsiString THTMLBgColor;

__interface ILocateFileService;
typedef System::DelphiInterface<ILocateFileService> _di_ILocateFileService;
__interface INTERFACE_UUID("{BD2B640D-8D7F-11D4-A4E2-00C04F6BB853}") ILocateFileService  : public IInterface 
{
	
public:
	virtual Classes::TStream* __fastcall GetTemplateStream(Classes::TComponent* AComponent, AnsiString AFileName, /* out */ bool &AOwned) = 0 ;
};

__interface IWebVariableName;
typedef System::DelphiInterface<IWebVariableName> _di_IWebVariableName;
__interface INTERFACE_UUID("{EDB15B48-F396-11D3-A42A-00C04F6BB853}") IWebVariableName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetVariableName(void) = 0 ;
	__property AnsiString VariableName = {read=GetVariableName};
};

__interface IWebVariablesContainer;
typedef System::DelphiInterface<IWebVariablesContainer> _di_IWebVariablesContainer;
__interface INTERFACE_UUID("{132142B1-0320-11D4-ABE8-E035EEC2EA5A}") IWebVariablesContainer  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall FindVariable(const AnsiString AName) = 0 ;
	virtual Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AName) = 0 ;
	virtual int __fastcall GetVariableCount(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetVariable(int I) = 0 ;
	__property int VariableCount = {read=GetVariableCount};
	__property Classes::TComponent* Variables[int I] = {read=GetVariable};
};

__interface IGetLocateFileService;
typedef System::DelphiInterface<IGetLocateFileService> _di_IGetLocateFileService;
__interface INTERFACE_UUID("{C9FD165B-8F1C-11D4-A4E4-00C04F6BB853}") IGetLocateFileService  : public IInterface 
{
	
public:
	virtual _di_ILocateFileService __fastcall GetLocateFileService(void) = 0 ;
};

__interface IDesignerFileManager;
typedef System::DelphiInterface<IDesignerFileManager> _di_IDesignerFileManager;
__interface INTERFACE_UUID("{1DF271BF-F2EC-11D4-A559-00C04F6BB853}") IDesignerFileManager  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall QualifyFileName(const AnsiString AFileName) = 0 ;
	virtual Classes::TStream* __fastcall GetStream(const AnsiString AFileName, bool &AOwned) = 0 ;
};

class DELPHICLASS THTMLTagAttributes;
class PASCALIMPLEMENTATION THTMLTagAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Httpapp::TCustomContentProducer* FProducer;
	AnsiString FCustom;
	Classes::TNotifyEvent FOnChange;
	void __fastcall SetCustom(const AnsiString Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall THTMLTagAttributes(Httpapp::TCustomContentProducer* Producer);
	virtual void __fastcall RestoreDefaults(void);
	__property Httpapp::TCustomContentProducer* Producer = {read=FProducer};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property AnsiString Custom = {read=FCustom, write=SetCustom};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTagAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableAttributes;
class PASCALIMPLEMENTATION THTMLTableAttributes : public THTMLTagAttributes 
{
	typedef THTMLTagAttributes inherited;
	
private:
	THTMLAlign FAlign;
	int FBorder;
	AnsiString FBgColor;
	int FCellSpacing;
	int FCellPadding;
	int FWidth;
	void __fastcall SetAlign(THTMLAlign Value);
	void __fastcall SetBorder(int Value);
	void __fastcall SetBGColor(AnsiString Value);
	void __fastcall SetCellSpacing(int Value);
	void __fastcall SetCellPadding(int Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall THTMLTableAttributes(Httpapp::TCustomContentProducer* Producer);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property THTMLAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=SetBGColor};
	__property int Border = {read=FBorder, write=SetBorder, default=-1};
	__property int CellSpacing = {read=FCellSpacing, write=SetCellSpacing, default=-1};
	__property int CellPadding = {read=FCellPadding, write=SetCellPadding, default=-1};
	__property int Width = {read=FWidth, write=SetWidth, default=100};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableElementAttributes;
class PASCALIMPLEMENTATION THTMLTableElementAttributes : public THTMLTagAttributes 
{
	typedef THTMLTagAttributes inherited;
	
private:
	THTMLAlign FAlign;
	AnsiString FBgColor;
	THTMLVAlign FVAlign;
	void __fastcall SetAlign(THTMLAlign Value);
	void __fastcall SetBGColor(AnsiString Value);
	void __fastcall SetVAlign(THTMLVAlign Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property THTMLAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=SetBGColor};
	__property THTMLVAlign VAlign = {read=FVAlign, write=SetVAlign, default=0};
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableElementAttributes(Httpapp::TCustomContentProducer* Producer) : THTMLTagAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableElementAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableHeaderAttributes;
class PASCALIMPLEMENTATION THTMLTableHeaderAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
private:
	AnsiString FCaption;
	void __fastcall SetCaption(AnsiString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableHeaderAttributes(Httpapp::TCustomContentProducer* Producer) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableHeaderAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableRowAttributes;
class PASCALIMPLEMENTATION THTMLTableRowAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableRowAttributes(Httpapp::TCustomContentProducer* Producer) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableRowAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableCellAttributes;
class PASCALIMPLEMENTATION THTMLTableCellAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableCellAttributes(Httpapp::TCustomContentProducer* Producer) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableCellAttributes(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTag { tgCustom, tgLink, tgImage, tgTable, tgImageMap, tgObject, tgEmbed };
#pragma option pop

typedef void __fastcall (__closure *THTMLTagEvent)(System::TObject* Sender, TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);

__interface IGetProducerTemplate;
typedef System::DelphiInterface<IGetProducerTemplate> _di_IGetProducerTemplate;
__interface INTERFACE_UUID("{44AA3FC1-FEB9-11D4-A566-00C04F6BB853}") IGetProducerTemplate  : public IInterface 
{
	
public:
	virtual Classes::TStream* __fastcall GetProducerTemplateStream(/* out */ bool &AOwned) = 0 ;
	virtual AnsiString __fastcall GetProducerTemplateFileName(void) = 0 ;
};

class DELPHICLASS TBasePageProducer;
class PASCALIMPLEMENTATION TBasePageProducer : public Httpapp::TCustomContentProducer 
{
	typedef Httpapp::TCustomContentProducer inherited;
	
private:
	THTMLTagEvent FOnHTMLTag;
	bool FStripParamQuotes;
	System::TObject* FWebModuleContext;
	System::TObject* FLocalWebModuleContext;
	AnsiString FScriptEngine;
	System::TObject* __fastcall GetWebModuleContext(void);
	_di_ILocateFileService __fastcall GetLocateFileService();
	
protected:
	virtual AnsiString __fastcall GetScriptEngine();
	virtual bool __fastcall UseScriptEngine(void);
	TTag __fastcall GetTagID(const AnsiString TagString);
	virtual AnsiString __fastcall HandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	AnsiString __fastcall ImplHandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	DYNAMIC void __fastcall DoTagEvent(TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	virtual bool __fastcall HandleScriptTag(const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceString);
	AnsiString __fastcall ServerScriptFromStream(Classes::TStream* Stream);
	Classes::TStream* __fastcall GetProducerTemplateStream(/* out */ bool &AOwned);
	AnsiString __fastcall GetProducerTemplateFileName();
	virtual AnsiString __fastcall GetTemplateFileName();
	virtual Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	__property THTMLTagEvent OnHTMLTag = {read=FOnHTMLTag, write=FOnHTMLTag};
	
public:
	__fastcall virtual TBasePageProducer(Classes::TComponent* AOwner);
	virtual AnsiString __fastcall Content();
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* Stream);
	virtual AnsiString __fastcall ContentFromString(const AnsiString S);
	__property System::TObject* WebModuleContext = {read=GetWebModuleContext};
	__property bool StripParamQuotes = {read=FStripParamQuotes, write=FStripParamQuotes, default=1};
	__property AnsiString ScriptEngine = {read=GetScriptEngine, write=FScriptEngine};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TBasePageProducer(void) { }
	#pragma option pop
	
private:
	void *__IGetProducerTemplate;	/* Httpprod::IGetProducerTemplate */
	
public:
	operator IGetProducerTemplate*(void) { return (IGetProducerTemplate*)&__IGetProducerTemplate; }
	
};


class DELPHICLASS TCustomPageProducer;
class PASCALIMPLEMENTATION TCustomPageProducer : public TBasePageProducer 
{
	typedef TBasePageProducer inherited;
	
private:
	AnsiString FHTMLFile;
	Classes::TStrings* FHTMLDoc;
	void __fastcall SetHTMLFile(const AnsiString Value);
	void __fastcall SetHTMLDoc(Classes::TStrings* Value);
	
protected:
	virtual Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	virtual AnsiString __fastcall HandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	virtual AnsiString __fastcall GetTemplateFileName();
	
public:
	__fastcall virtual TCustomPageProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomPageProducer(void);
	__property Classes::TStrings* HTMLDoc = {read=FHTMLDoc, write=SetHTMLDoc};
	__property AnsiString HTMLFile = {read=FHTMLFile, write=SetHTMLFile};
};


class DELPHICLASS TPageProducer;
class PASCALIMPLEMENTATION TPageProducer : public TCustomPageProducer 
{
	typedef TCustomPageProducer inherited;
	
__published:
	__property HTMLDoc ;
	__property HTMLFile ;
	__property StripParamQuotes  = {default=1};
	__property OnHTMLTag ;
	__property ScriptEngine ;
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TPageProducer(Classes::TComponent* AOwner) : TCustomPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TPageProducer(void) { }
	#pragma option pop
	
};


typedef AnsiString __fastcall (__closure *THandleTagProc)(const AnsiString TagString, Classes::TStrings* TagParams);

typedef bool __fastcall (__closure *THandledTagProc)(const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceString);

typedef TMetaClass*TScriptProducerClass;

class DELPHICLASS EScriptError;
class DELPHICLASS TAbstractScriptErrors;
class DELPHICLASS TAbstractScriptError;
class PASCALIMPLEMENTATION TAbstractScriptErrors : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TAbstractScriptError* operator[](int I) { return Errors[I]; }
	
protected:
	virtual TAbstractScriptError* __fastcall GetError(int I) = 0 ;
	virtual int __fastcall GetErrorCount(void) = 0 ;
	
public:
	virtual void __fastcall Add(const TAbstractScriptError* AError) = 0 ;
	__property TAbstractScriptError* Errors[int I] = {read=GetError/*, default*/};
	__property int Count = {read=GetErrorCount, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractScriptErrors(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractScriptErrors(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION EScriptError : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
private:
	TAbstractScriptErrors* FErrors;
	AnsiString FContent;
	
public:
	__fastcall EScriptError(const TAbstractScriptErrors* AErrors, const AnsiString AContent);
	__fastcall virtual ~EScriptError(void);
	__property TAbstractScriptErrors* Errors = {read=FErrors};
	__property AnsiString Content = {read=FContent};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EScriptError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EScriptError(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EScriptError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EScriptError(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EScriptError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EScriptError(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EScriptError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TAbstractScriptError : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual AnsiString __fastcall GetSourceLine(void) = 0 ;
	virtual int __fastcall GetCharPos(void) = 0 ;
	virtual int __fastcall GetLine(void) = 0 ;
	virtual AnsiString __fastcall GetDescription(void) = 0 ;
	virtual void __fastcall SetDescription(const AnsiString AValue) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	
public:
	__property int Line = {read=GetLine, nodefault};
	__property int CharPos = {read=GetCharPos, nodefault};
	__property AnsiString Description = {read=GetDescription, write=SetDescription};
	__property AnsiString SourceLine = {read=GetSourceLine};
	__property AnsiString FileName = {read=GetFileName};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractScriptError(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractScriptError(void) { }
	#pragma option pop
	
};


__interface IScriptContext;
typedef System::DelphiInterface<IScriptContext> _di_IScriptContext;
__interface INTERFACE_UUID("{5ECF283F-1C83-47FF-8914-33AB0EFD94FB}") IScriptContext  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetWebModuleContext(void) = 0 ;
	__property System::TObject* WebModuleContext = {read=GetWebModuleContext};
};

__interface IScriptProducer;
typedef System::DelphiInterface<IScriptProducer> _di_IScriptProducer;
__interface INTERFACE_UUID("{53324483-A14A-497B-81DF-CA51668F36B9}") IScriptProducer  : public IScriptContext 
{
	
public:
	virtual TAbstractScriptErrors* __fastcall GetErrors(void) = 0 ;
	virtual WideString __fastcall GetHTMLBlock(int I) = 0 ;
	virtual int __fastcall GetHTMLBlockCount(void) = 0 ;
	virtual void __fastcall ParseStream(Classes::TStream* Stream, bool Owned = false) = 0 ;
	virtual void __fastcall ParseString(const AnsiString S) = 0 ;
	virtual AnsiString __fastcall ReplaceTags(const AnsiString S) = 0 ;
	virtual AnsiString __fastcall Evaluate(void) = 0 ;
	virtual HRESULT __fastcall HandleScriptError(const System::_di_IInterface ScriptError) = 0 ;
	virtual void __fastcall Write(const wchar_t * Value, int ALength) = 0 /* overload */;
	virtual void __fastcall Write(const AnsiString Value) = 0 /* overload */;
	virtual void __fastcall WriteItem(int Index) = 0 ;
	virtual AnsiString __fastcall GetContent(void) = 0 ;
	virtual void __fastcall SetContent(const AnsiString Value) = 0 ;
	__property WideString HTMLBlocks[int I] = {read=GetHTMLBlock};
	__property int HTMLBlockCount = {read=GetHTMLBlockCount};
	__property AnsiString Content = {read=GetContent, write=SetContent};
	__property TAbstractScriptErrors* Errors = {read=GetErrors};
};

class DELPHICLASS TAbstractScriptProducer;
class PASCALIMPLEMENTATION TAbstractScriptProducer : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall virtual TAbstractScriptProducer(System::TObject* AWebModuleContext, bool AStripParamQuotes, THandleTagProc AHandleTag, const AnsiString AScriptEngine, _di_ILocateFileService ALocateFileService);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractScriptProducer(void) { }
	#pragma option pop
	
};


typedef AnsiString HTTPProd__41[4];

typedef AnsiString HTTPProd__51[5];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString HTMLAlign[4];
extern PACKAGE AnsiString HTMLVAlign[5];
extern PACKAGE TMetaClass*ScriptProducerClass;
extern PACKAGE _di_IDesignerFileManager DesignerFileManager;
extern PACKAGE TTag __fastcall GetTagID(const AnsiString TagString);
extern PACKAGE AnsiString __fastcall ContentFromStream(Classes::TStream* AStream, bool AStripParamQuotes, THandleTagProc AHandleTag, THandledTagProc AHandledTag);
extern PACKAGE AnsiString __fastcall ContentFromString(const AnsiString AValue, bool AStripParamQuotes, THandleTagProc AHandleTag, THandledTagProc AHandledTag);
extern PACKAGE AnsiString __fastcall ContentFromScriptStream(Classes::TStream* AStream, System::TObject* AWebModuleContext, bool AStripParamQuotes, THandleTagProc AHandleTag, THandledTagProc AHandleScriptTag, const AnsiString AScriptEngine, _di_ILocateFileService ALocateFileService);
extern PACKAGE AnsiString __fastcall ContentFromScriptFile(const AnsiString AFileName, System::TObject* AWebModuleContext, bool AStripParamQuotes, THandleTagProc AHandleTag, THandledTagProc AHandleScriptTag, const AnsiString AScriptEngine, _di_ILocateFileService ALocateFileService);
extern PACKAGE System::TObject* __fastcall FindComponentWebModuleContext(Classes::TComponent* AComponent);

}	/* namespace Httpprod */
using namespace Httpprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPProd
