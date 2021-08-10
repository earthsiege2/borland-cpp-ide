// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IStreams.pas' rev: 6.00

#ifndef IStreamsHPP
#define IStreamsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <AxCtrls.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Istreams
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIStreamAdapter;
class PASCALIMPLEMENTATION TIStreamAdapter : public Classes::TStreamAdapter 
{
	typedef Classes::TStreamAdapter inherited;
	
protected:
	int FModifyTime;
	
public:
	__fastcall TIStreamAdapter(Classes::TStream* Stream, Classes::TStreamOwnership Ownership);
	virtual HRESULT __stdcall Write(void * pv, int cb, PLongint pcbWritten);
	virtual HRESULT __stdcall Stat(/* out */ tagSTATSTG &statstg, int grfStatFlag);
	virtual int __stdcall GetModifyTime(void);
	virtual void __stdcall SetModifyTime(int Value);
public:
	#pragma option push -w-inl
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TIStreamAdapter(void) { }
	#pragma option pop
	
private:
	void *__IStreamModifyTime;	/* Virtintf::IStreamModifyTime */
	
public:
	operator IStreamModifyTime*(void) { return (IStreamModifyTime*)&__IStreamModifyTime; }
	
};


class DELPHICLASS TIMemoryStream;
class PASCALIMPLEMENTATION TIMemoryStream : public TIStreamAdapter 
{
	typedef TIStreamAdapter inherited;
	
private:
	Classes::TMemoryStream* __fastcall GetMemoryStream(void);
	
public:
	__fastcall TIMemoryStream(Classes::TMemoryStream* Stream, Classes::TStreamOwnership Ownership);
	__property Classes::TMemoryStream* MemoryStream = {read=GetMemoryStream};
public:
	#pragma option push -w-inl
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TIMemoryStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIFileStream;
class PASCALIMPLEMENTATION TIFileStream : public Classes::TStreamAdapter 
{
	typedef Classes::TStreamAdapter inherited;
	
private:
	Classes::TFileStream* __fastcall GetFileStream(void);
	
public:
	__fastcall TIFileStream(const AnsiString FileName, Word Mode);
	virtual HRESULT __stdcall Commit(int grfCommitFlags);
	virtual HRESULT __stdcall Stat(/* out */ tagSTATSTG &statstg, int grfStatFlag);
	int __stdcall GetModifyTime(void);
	void __stdcall SetModifyTime(int Time);
	__property Classes::TFileStream* FileStream = {read=GetFileStream};
public:
	#pragma option push -w-inl
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TIFileStream(void) { }
	#pragma option pop
	
private:
	void *__IStreamModifyTime;	/* Virtintf::IStreamModifyTime */
	
public:
	operator IStreamModifyTime*(void) { return (IStreamModifyTime*)&__IStreamModifyTime; }
	
};


class DELPHICLASS TVirtualStream;
class PASCALIMPLEMENTATION TVirtualStream : public Axctrls::TOleStream 
{
	typedef Axctrls::TOleStream inherited;
	
private:
	Virtintf::_di_IStreamModifyTime FStreamModifyTime;
	
public:
	__fastcall TVirtualStream(_di_IStream AStream);
	int __fastcall GetModifyTime(void);
	void __fastcall SetModifyTime(int Time);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVirtualStream(void) { }
	#pragma option pop
	
};


typedef void __fastcall (*TExceptionHandler)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TExceptionHandler ExceptionHandler;

}	/* namespace Istreams */
using namespace Istreams;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IStreams
