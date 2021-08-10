// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ReqFiles.pas' rev: 6.00

#ifndef ReqFilesHPP
#define ReqFilesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPApp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Reqfiles
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebRequestFile;
class PASCALIMPLEMENTATION TWebRequestFile : public Httpapp::TAbstractWebRequestFile 
{
	typedef Httpapp::TAbstractWebRequestFile inherited;
	
private:
	AnsiString FFieldName;
	AnsiString FFileName;
	Classes::TStream* FStream;
	AnsiString FContentType;
	
protected:
	virtual AnsiString __fastcall GetFieldName();
	virtual AnsiString __fastcall GetFileName();
	virtual Classes::TStream* __fastcall GetStream(void);
	virtual AnsiString __fastcall GetContentType();
	
public:
	__fastcall TWebRequestFile(const AnsiString AFieldName, const AnsiString AFileName, const AnsiString AContentType, void * AContent, int AContentLength);
	__fastcall virtual ~TWebRequestFile(void);
};


class DELPHICLASS TWebRequestFiles;
class PASCALIMPLEMENTATION TWebRequestFiles : public Httpapp::TAbstractWebRequestFiles 
{
	typedef Httpapp::TAbstractWebRequestFiles inherited;
	
private:
	Contnrs::TObjectList* FList;
	
protected:
	virtual int __fastcall GetCount(void);
	virtual Httpapp::TAbstractWebRequestFile* __fastcall GetItem(int I);
	
public:
	__fastcall TWebRequestFiles(void);
	__fastcall virtual ~TWebRequestFiles(void);
	void __fastcall Add(const AnsiString AName, const AnsiString AFileName, const AnsiString AContentType, void * AContent, int AContentLength)/* overload */;
	void __fastcall Add(TWebRequestFile* AFile)/* overload */;
};


class DELPHICLASS TWebRequestFileStream;
class PASCALIMPLEMENTATION TWebRequestFileStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
public:
	__fastcall TWebRequestFileStream(void * ABuffer, int Size);
	virtual int __fastcall Write(const void *Buffer, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebRequestFileStream(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Reqfiles */
using namespace Reqfiles;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ReqFiles
