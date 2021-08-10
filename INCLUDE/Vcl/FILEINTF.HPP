// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FileIntf.pas' rev: 6.00

#ifndef FileIntfHPP
#define FileIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <VirtIntf.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Fileintf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIVirtualFileSystem;
class PASCALIMPLEMENTATION TIVirtualFileSystem : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual _di_IStream __stdcall GetFileStream(const AnsiString FileName, int Mode) = 0 ;
	virtual int __stdcall FileAge(const AnsiString FileName) = 0 ;
	virtual bool __stdcall RenameFile(const AnsiString OldName, const AnsiString NewName) = 0 ;
	virtual bool __stdcall IsReadonly(const AnsiString FileName) = 0 ;
	virtual bool __stdcall IsFileBased(void) = 0 ;
	virtual bool __stdcall DeleteFile(const AnsiString FileName) = 0 ;
	virtual bool __stdcall FileExists(const AnsiString FileName) = 0 ;
	virtual AnsiString __stdcall GetTempFileName(const AnsiString FileName) = 0 ;
	virtual AnsiString __stdcall GetBackupFileName(const AnsiString FileName) = 0 ;
	virtual AnsiString __stdcall GetIDString(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIVirtualFileSystem(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIVirtualFileSystem(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Fileintf */
using namespace Fileintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FileIntf
