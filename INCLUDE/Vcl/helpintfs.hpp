// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HelpIntfs.pas' rev: 6.00

#ifndef HelpIntfsHPP
#define HelpIntfsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Helpintfs
{
//-- type declarations -------------------------------------------------------
__interface IHelpSelector;
typedef System::DelphiInterface<IHelpSelector> _di_IHelpSelector;
__interface INTERFACE_UUID("{B0FC9358-5F0E-11D3-A3B9-00C04F79AD3A}") IHelpSelector  : public IInterface 
{
	
public:
	virtual int __fastcall SelectKeyword(Classes::TStrings* Keywords) = 0 ;
	virtual int __fastcall TableOfContents(Classes::TStrings* Contents) = 0 ;
};

__interface IHelpSystem;
typedef System::DelphiInterface<IHelpSystem> _di_IHelpSystem;
__interface INTERFACE_UUID("{B0FC9353-5F0E-11D3-A3B9-00C04F79AD3A}") IHelpSystem  : public IInterface 
{
	
public:
	virtual void __fastcall ShowHelp(const AnsiString HelpKeyword, const AnsiString HelpFileName) = 0 ;
	virtual void __fastcall ShowContextHelp(const int ContextID, const AnsiString HelpFileName) = 0 ;
	virtual void __fastcall ShowTableOfContents(void) = 0 ;
	virtual void __fastcall ShowTopicHelp(const AnsiString Topic, const AnsiString HelpFileName) = 0 ;
	virtual void __fastcall AssignHelpSelector(_di_IHelpSelector Selector) = 0 ;
	virtual bool __fastcall Hook(int Handle, AnsiString HelpFile, Word Comand, int Data) = 0 ;
};

__interface ICustomHelpViewer;
typedef System::DelphiInterface<ICustomHelpViewer> _di_ICustomHelpViewer;
__interface INTERFACE_UUID("{B0FC9364-5F0E-11D3-A3B9-00C04F79AD3A}") ICustomHelpViewer  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetViewerName(void) = 0 ;
	virtual int __fastcall UnderstandsKeyword(const AnsiString HelpString) = 0 ;
	virtual Classes::TStringList* __fastcall GetHelpStrings(const AnsiString HelpString) = 0 ;
	virtual bool __fastcall CanShowTableOfContents(void) = 0 ;
	virtual void __fastcall ShowTableOfContents(void) = 0 ;
	virtual void __fastcall ShowHelp(const AnsiString HelpString) = 0 ;
	virtual void __fastcall NotifyID(const int ViewerID) = 0 ;
	virtual void __fastcall SoftShutDown(void) = 0 ;
	virtual void __fastcall ShutDown(void) = 0 ;
};

__interface IExtendedHelpViewer;
typedef System::DelphiInterface<IExtendedHelpViewer> _di_IExtendedHelpViewer;
__interface INTERFACE_UUID("{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}") IExtendedHelpViewer  : public ICustomHelpViewer 
{
	
public:
	virtual bool __fastcall UnderstandsTopic(const AnsiString Topic) = 0 ;
	virtual void __fastcall DisplayTopic(const AnsiString Topic) = 0 ;
	virtual bool __fastcall UnderstandsContext(const int ContextID, const AnsiString HelpFileName) = 0 ;
	virtual void __fastcall DisplayHelpByContext(const int ContextID, const AnsiString HelpFileName) = 0 ;
};

__interface ISpecialWinHelpViewer;
typedef System::DelphiInterface<ISpecialWinHelpViewer> _di_ISpecialWinHelpViewer;
__interface INTERFACE_UUID("{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}") ISpecialWinHelpViewer  : public IExtendedHelpViewer 
{
	
public:
	virtual bool __fastcall CallWinHelp(int Handle, const AnsiString HelpFile, Word Command, int Data) = 0 ;
};

__interface IHelpManager;
typedef System::DelphiInterface<IHelpManager> _di_IHelpManager;
__interface INTERFACE_UUID("{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}") IHelpManager  : public IInterface 
{
	
public:
	virtual int __fastcall GetHandle(void) = 0 ;
	virtual AnsiString __fastcall GetHelpFile(void) = 0 ;
	virtual void __fastcall Release(const int ViewerID) = 0 ;
};

class DELPHICLASS EHelpSystemException;
class PASCALIMPLEMENTATION EHelpSystemException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EHelpSystemException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EHelpSystemException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EHelpSystemException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EHelpSystemException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EHelpSystemException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EHelpSystemException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EHelpSystemException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EHelpSystemException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EHelpSystemException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall RegisterViewer(_di_ICustomHelpViewer newViewer, /* out */ _di_IHelpManager &Manager);
extern PACKAGE int __fastcall GetHelpSystem(/* out */ _di_IHelpSystem &System);

}	/* namespace Helpintfs */
using namespace Helpintfs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HelpIntfs
