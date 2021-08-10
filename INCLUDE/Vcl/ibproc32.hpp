// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBProc32.pas' rev: 6.00

#ifndef IBProc32HPP
#define IBProc32HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibproc32
{
//-- type declarations -------------------------------------------------------
typedef void *isc_db_handle;

typedef void * *pisc_db_handle;

typedef int isc_long;

typedef int *pisc_long;

typedef int isc_status;

typedef int *pisc_status;

typedef void *isc_tr_handle;

typedef void * *pisc_tr_handle;

typedef int status_vector[20];

typedef int *pstatus_vector;

typedef pstatus_vector *ppstatus_vector;

typedef Word Short;

#pragma pack(push, 4)
struct isc_teb
{
	void * *db_ptr;
	int tpb_len;
	char *tpb_ptr;
} ;
#pragma pack(pop)

typedef isc_teb *pisc_teb;

#pragma pack(push, 1)
struct TXSQLVar
{
	
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TXSQLDA
{
	
} ;
#pragma pack(pop)

typedef TXSQLDA *PTXSQLDA;

typedef void __fastcall (*isc_callback)(void * ptr, Word length, char * updated);

typedef int __stdcall (*TIscAttachDatabase)(pstatus_vector status, Word db_name_length, char * db_name, pisc_db_handle db_handle, Word parm_buffer_length, char * parm_buffer);

typedef int __stdcall (*TIscCancelEvents)(pstatus_vector status, pisc_db_handle db_handle, pisc_long event_id);

typedef int __stdcall (*TIscCommitTransaction)(pstatus_vector status, pisc_tr_handle trans_handle);

typedef int __stdcall (*TIscDetachDatabase)(pstatus_vector status, pisc_db_handle db_handle);

typedef int __stdcall (*TIscDropDatabase)(pstatus_vector status, pisc_db_handle db_handle);

typedef int __stdcall (*TIscDsqlExecuteImmediate)(pstatus_vector status, pisc_db_handle db_handle, pisc_tr_handle trans_handle, Word length, char * statement, Word dialect, PTXSQLDA xslqda);

typedef int __cdecl (*TIscEventBlock)(void * event_buf, void * result_buf, Word count, char * name1);

typedef void __stdcall (*TIscEventCounts)(pstatus_vector status, Word buffer_length, char * event_buffer, char * result_buffer);

typedef int __stdcall (*TIscFree)(char * buffer);

typedef int __stdcall (*TIscInterprete)(char * buffer, ppstatus_vector status);

typedef int __stdcall (*TIscQueEvents)(pstatus_vector status, pisc_db_handle db_handle, pisc_long event_id, Word length, char * event_buffer, isc_callback event_function, void * event_function_arg);

typedef int __stdcall (*TIscRollbackTransaction)(pstatus_vector status, pisc_tr_handle trans_handle);

typedef int __stdcall (*TIscStartMultiple)(pstatus_vector status, pisc_tr_handle trans_handle, Word db_handle_count, pisc_teb teb_vector_address);

class DELPHICLASS EDLLLoadError;
class PASCALIMPLEMENTATION EDLLLoadError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDLLLoadError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDLLLoadError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDLLLoadError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDLLLoadError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDLLLoadError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDLLLoadError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDLLLoadError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDLLLoadError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDLLLoadError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint isc_dpb_version1 = 0x1;
static const Shortint isc_dpb_user_name = 0x1c;
static const Shortint isc_dpb_password = 0x1d;
static const Shortint isc_tpb_concurrency = 0x2;
static const Shortint isc_tpb_version3 = 0x3;
static const Shortint isc_tpb_wait = 0x6;
static const Shortint isc_tpb_write = 0x9;

}	/* namespace Ibproc32 */
using namespace Ibproc32;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBProc32
