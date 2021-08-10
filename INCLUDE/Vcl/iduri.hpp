// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdURI.pas' rev: 6.00

#ifndef IdURIHPP
#define IdURIHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iduri
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdURI;
class PASCALIMPLEMENTATION TIdURI : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	AnsiString FDocument;
	AnsiString FProtocol;
	AnsiString FURI;
	AnsiString FPort;
	AnsiString Fpath;
	AnsiString FHost;
	AnsiString FBookmark;
	void __fastcall SetHost(const AnsiString Value);
	void __fastcall SetDocument(const AnsiString Value);
	void __fastcall SetBookmark(const AnsiString Value);
	void __fastcall Setpath(const AnsiString Value);
	void __fastcall SetPort(const AnsiString Value);
	void __fastcall SetProtocol(const AnsiString Value);
	void __fastcall SetURI(const AnsiString Value);
	void __fastcall Refresh(void);
	
public:
	/*         class method */ static void __fastcall NormalizePath(TMetaClass* vmt, AnsiString &APath);
	/*         class method */ static void __fastcall ParseURI(TMetaClass* vmt, AnsiString URI, AnsiString &Protocol, AnsiString &Host, AnsiString &path, AnsiString &Document, AnsiString &Port, AnsiString &Bookmark);
	__fastcall virtual TIdURI(const AnsiString AURI);
	__property AnsiString Protocol = {read=FProtocol, write=SetProtocol};
	__property AnsiString Path = {read=Fpath, write=Setpath};
	__property AnsiString Host = {read=FHost, write=SetHost};
	__property AnsiString Document = {read=FDocument, write=SetDocument};
	__property AnsiString Port = {read=FPort, write=SetPort};
	__property AnsiString URI = {read=FURI, write=SetURI};
	__property AnsiString Bookmark = {read=FBookmark, write=SetBookmark};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIdURI(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iduri */
using namespace Iduri;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdURI
