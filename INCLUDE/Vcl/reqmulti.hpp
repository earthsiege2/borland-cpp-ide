// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ReqMulti.pas' rev: 6.00

#ifndef ReqMultiHPP
#define ReqMultiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPParse.hpp>	// Pascal unit
#include <ReqFiles.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Reqmulti
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMultipartContentParser;
class PASCALIMPLEMENTATION TMultipartContentParser : public Httpapp::TAbstractContentParser 
{
	typedef Httpapp::TAbstractContentParser inherited;
	
private:
	Classes::TStrings* FContentFields;
	Reqfiles::TWebRequestFiles* FFiles;
	AnsiString FContentBuffer;
	
protected:
	virtual Classes::TStrings* __fastcall GetContentFields(void);
	virtual Httpapp::TAbstractWebRequestFiles* __fastcall GetFiles(void);
	void __fastcall ExtractContentTypeFields(Classes::TStrings* Strings);
	void __fastcall ParseMultiPartContent(void);
	void __fastcall ParseMultiPart(void * Part, int Size);
	void __fastcall BufferContent(void);
	void __fastcall ParseMultipartHeaders(Httpparse::THTTPParser* Parser, void * AContent, int AContentLength);
	void __fastcall ExtractMultipartContentFields(void);
	
public:
	__fastcall virtual ~TMultipartContentParser(void);
	/* virtual class method */ virtual bool __fastcall CanParse(TMetaClass* vmt, Httpapp::TWebRequest* AWebRequest);
public:
	#pragma option push -w-inl
	/* TAbstractContentParser.Create */ inline __fastcall virtual TMultipartContentParser(Httpapp::TWebRequest* AWebRequest) : Httpapp::TAbstractContentParser(AWebRequest) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Reqmulti */
using namespace Reqmulti;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ReqMulti
