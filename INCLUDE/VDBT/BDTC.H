//--------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
//   Additional definitions for database access COM interfaces.
//--------------------------------------------------------------------------
#ifndef BDTC_H
#define BDTC_H

#include <vdbt/bdtm.h>

#ifdef __FLAT__

# define INC_OLE2
# include <windows.h>

# ifdef INC_IDAPI
#  include <idapi.h>
# endif

#else

# include <windows.h>
# include <ole2.h>
# include <dispatch.h>

# ifdef INC_IDAPI
#  include <idapi.h>
# endif

#endif

#pragma warn -cln
#include <vdbt/bdti.h>
#pragma warn .cln

#include <cstring.h>
#include <winsys/exbase.h>

//............................................................................

typedef IUnknown far * PIUnknown;
typedef PIUnknown far * PPIUnknown;

typedef IBDT50 far * PIBDT50;
typedef PIBDT50 far * PPIBDT50;

typedef ITBDTObject far * PITBDTObject;
typedef PITBDTObject far * PPITBDTObject;
typedef ITBDTComponent far * PITBDTComponent;
typedef PITBDTComponent far * PPITBDTComponent;
typedef ITStrings far * PITStrings;
typedef PITStrings far * PPITStrings;
typedef ITSession far * PITSession;
typedef PITSession far * PPITSession;
typedef ITDatabase far * PITDatabase;
typedef PITDatabase far * PPITDatabase;
typedef ITFieldDef far * PITFieldDef;
typedef PITFieldDef far * PPITFieldDef;
typedef ITFieldDefs far * PITFieldDefs;
typedef PITFieldDefs far * PPITFieldDefs;
typedef ITDataSet far * PITDataSet;
typedef PITDataSet far * PPITDataSet;
typedef ITDBDataSet far * PITDBDataSet;
typedef PITDBDataSet far * PPITDBDataSet;
typedef ITDataSource far * PITDataSource;
typedef PITDataSource far * PPITDataSource;
typedef ITField far * PITField;
typedef PITField far * PPITField;
typedef ITIndexDef far * PITIndexDef;
typedef PITIndexDef far * PPITIndexDef;
typedef ITIndexDefs far * PITIndexDefs;
typedef PITIndexDefs far * PPITIndexDefs;
typedef ITTable far * PITTable;
typedef PITTable far * PPITTable;
typedef ITBatchMove far * PITBatchMove;
typedef PITBatchMove far * PPITBatchMove;
typedef ITParam far * PITParam;
typedef PITParam far * PPITParam;
typedef ITParams far * PITParams;
typedef PITParams far * PPITParams;
typedef ITStoredProc far * PITStoredProc;
typedef PITStoredProc far * PPITStoredProc;
typedef ITQuery far * PITQuery;
typedef PITQuery far * PPITQuery;
typedef ITMemoryStream far * PITMemoryStream;
typedef PITMemoryStream far * PPITMemoryStream;
typedef ITAnyString far * PITAnyString;
typedef PITAnyString far * PPITAnyString;

//............................................................................

// Size of the text buffer passed to the NFieldGetTextEvent callback.
#define MAXFIELDGETTEXT 256

//............................................................................

#ifndef NOBDTCFUNCTIONS

STDAPI_(PIBDT50) GetIBDT50( void );

STDAPI_(PITSession) GetITSession( void );

STDAPI_(PITSession) CreateITSession( void );
STDAPI_(PITDatabase) CreateITDatabase( void );
STDAPI_(PITFieldDef) CreateITFieldDef( PITFieldDefs Owner, LPCSTR Name, TFieldType DataType, WORD Size, VARIANT_BOOL Required, int FieldNo );
STDAPI_(PITFieldDefs) CreateITFieldDefs( PITDataSet dataset );
// can not create TDataSet
// can not create TDBDataSet
STDAPI_(PITDataSource) CreateITDataSource( void );
STDAPI_(PITField) CreateITField( PITBDTComponent Owner, TFieldType DataType );
STDAPI_(PITIndexDef) CreateITIndexDef( PITIndexDefs Owner, LPCSTR Name, LPCSTR Fields, TIndexOptions Options );
STDAPI_(PITIndexDefs) CreateITIndexDefs( PITTable table );
STDAPI_(PITTable) CreateITTable( void );
STDAPI_(PITBatchMove) CreateITBatchMove( void );
STDAPI_(PITParam) CreateITParam( PITParams AParamList, TParamType AParamType );
STDAPI_(PITParams) CreateITParams( void );
STDAPI_(PITStoredProc) CreateITStoredProc( void );
STDAPI_(PITQuery) CreateITQuery( void );
STDAPI_(PITMemoryStream) CreateITMemoryStream( void );
STDAPI_(PITStrings) CreateITStrings( void );

STDAPI_(PITAnyString) CreateITAnyString( void );

//
// Mangle the function and variable names so we can have mulitpale versions of
// the same functions and variables in one .LIB file.
//
#if defined( __DLL__ ) && ! defined( __FLAT__ )
#  if defined( _RTLDLL ) // user DLL linked with RTL.DLL
#    define InitBDTExceptions    dInitBDTExceptions
#    define TermBDTExceptions    dTermBDTExceptions
#    define __ForceBDTExceptions d_ForceBDTExceptions
#  else _RTLDLL  // user DLL linked with static libraries
#    define InitBDTExceptions    uInitBDTExceptions
#    define TermBDTExceptions    uTermBDTExceptions
#    define __ForceBDTExceptions u_ForceBDTExceptions
#  endif _RTLDLL
#elif defined( _RTLDLL ) // user EXE linked with RTL.DLL
#  define InitBDTExceptions    iInitBDTExceptions
#  define TermBDTExceptions    iTermBDTExceptions
#  define __ForceBDTExceptions i_ForceBDTExceptions
#endif __DLL__

STDAPI_(bool) _export InitBDTExceptions( void );
STDAPI_(bool) TermBDTExceptions( void );

#ifndef NOBDTCFORCEEXCEPTIONS
#pragma warn -use
static bool __ForceBDTExceptions = InitBDTExceptions();
#pragma warn .use
#endif // NOBDTCFORCEEXCEPTIONS

#define BDTC_ENABLE_EXCEPTIONS \
        static bool __ForceBDTExceptions = InitBDTExceptions()

#endif // NOBDTCFUNCTIONS

//............................................................................

#define _BDTCCLASS_RTL _EXPCLASS

class _BDTCCLASS_RTL BDTException : public TXBase
{
public:
	PIUnknown Sender;
	string Message;

	BDTException( PIUnknown s, LPCSTR m ) : TXBase( m )
	{
		Sender = s;
		Message = m;
	}

	BDTException( PIUnknown s, const string& m ) : TXBase( m )
	{
		Sender = s;
		Message = m;
	}

	void Show( LPCSTR s = NULL )
	{
		MessageBox( HWND_DESKTOP, Message.c_str(), s, MB_OK | MB_ICONSTOP | MB_TASKMODAL );
	}
};

class _BDTCCLASS_RTL EListError : public BDTException
{
public:
	EListError( PIUnknown s, LPCSTR m ) : BDTException( s, m )
	{
	}

	EListError( PIUnknown s, const string& m ) : BDTException( s, m )
	{
	}
};

class _BDTCCLASS_RTL EDatabaseError : public BDTException
{
public:
	WORD BDEErrorCode;
	ULONG NativeErrorCode;

	EDatabaseError( PIUnknown s, LPCSTR m, WORD b, ULONG n ) : BDTException( s, m )
	{
		BDEErrorCode = b;
		NativeErrorCode = n;
	}

	EDatabaseError( PIUnknown s, const string& m, WORD b, ULONG n ) : BDTException( s, m )
	{
		BDEErrorCode = b;
		NativeErrorCode = n;
	}
};

//............................................................................
#endif // BDTC_H
