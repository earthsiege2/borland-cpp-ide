//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// wrapit.cpp
// Functions which create wrapper objects
//-----------------------------------------------------------------------------

#define INITGUID
#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"

BDTC_ENABLE_EXCEPTIONS;

#define NOTUSED( x )		((void)(long) (x))

//-----------------------------------------------------------------------------

PTField WrapPITField( PITField pitField )
{
	PTField pt = 0;

	if (pitField)
	{
		switch (pitField->get_DataType())
		{
			case ftUnknown:
				pt = new TField( pitField );
				break;
			case ftString:
				pt = new TStringField( pitField );
				break;
			case ftSmallint:
				pt = new TSmallintField( pitField );
				break;
			case ftInteger:
				pt = new TIntegerField( pitField );
				break;
			case ftWord:
				pt = new TWordField( pitField );
				break;
			case ftBoolean:
				pt = new TBooleanField( pitField );
				break;
			case ftFloat:
				pt = new TFloatField( pitField );
				break;
			case ftCurrency:
				pt = new TCurrencyField( pitField );
				break;
			case ftBCD:
				pt = new TBCDField( pitField );
				break;
			case ftDate:
				pt = new TDateField( pitField );
				break;
			case ftTime:
				pt = new TTimeField( pitField );
				break;
			case ftDateTime:
				pt = new TDateTimeField( pitField );
				break;
			case ftBytes:
				pt = new TBytesField( pitField );
				break;
			case ftVarBytes:
				pt = new TVarBytesField( pitField );
				break;
#ifdef __FLAT__
			case ftAutoInc:
				pt = new TIntegerField( pitField );
				break;
#endif // __FLAT__
			case ftBlob:
				pt = new TBlobField( pitField );
				break;
			case ftMemo:
				pt = new TMemoField( pitField );
				break;
			case ftGraphic:
				pt = new TGraphicField( pitField );
				break;
#ifdef __FLAT__
			case ftFmtMemo:
			case ftParadoxOle:
			case ftDBaseOle:
			case ftTypedBinary:
				pt = new TBlobField( pitField );
				break;
#endif // __FLAT__
			default:
				pt = new TField( pitField );
				break;
		}
	}

	return pt;
}

//-----------------------------------------------------------------------------

PTDataSet WrapPITDataSet( PITDataSet pitDataSet )
{
	PTDataSet pt = 0;

	if (pitDataSet)
	{
		PITTable pitTable = 0;
		PITQuery pitQuery = 0;
		PITStoredProc pitStoredProc = 0;
		PITDBDataSet pitDBDataSet = 0;

		if (pitDataSet->QueryInterface( IID_ITTable, (void**) &pitTable ) == NOERROR)
		{
			pt = new TTable( pitTable );
			pitTable->Release();
		}
		else if (pitDataSet->QueryInterface( IID_ITQuery, (void**) &pitQuery ) == NOERROR)
		{
			pt = new TQuery( pitQuery );
			pitQuery->Release();
		}
		else if (pitDataSet->QueryInterface( IID_ITStoredProc, (void**) &pitStoredProc ) == NOERROR)
		{
			pt = new TStoredProc( pitStoredProc );
			pitStoredProc->Release();
		}
		else if (pitDataSet->QueryInterface( IID_ITDBDataSet, (void**) &pitDBDataSet ) == NOERROR)
		{
			pt = new TDBDataSet( pitDBDataSet );
			pitDBDataSet->Release();
		}
		else
			pt = new TDataSet( pitDataSet );
	}

	return pt;
}

//-----------------------------------------------------------------------------

PTSession WrapPITSession( PITSession pitSession )
{
	PTSession pt = 0;

	if (pitSession)
		pt = new TSession( pitSession );

	return pt;
}

//-----------------------------------------------------------------------------

PTDatabase WrapPITDatabase( PITDatabase pitDatabase )
{
	PTDatabase pt = 0;

	if (pitDatabase)
		pt = new TDatabase( pitDatabase );

	return pt;
}

//-----------------------------------------------------------------------------

PTDataSource WrapPITDataSource( PITDataSource pitDataSource )
{
	PTDataSource pt = 0;

	if (pitDataSource)
		pt = new TDataSource( pitDataSource );

	return pt;
}

//-----------------------------------------------------------------------------

PTStrings WrapPITStrings( PITStrings pitStrings )
{
	PTStrings pt = 0;

	if (pitStrings)
		pt = new TStrings( pitStrings );

	return pt;
}

//-----------------------------------------------------------------------------

AnyString::AnyString( const string& s )
{
	pit = CreateITAnyString();
	if (pit)
		pit->put_AsStringBuf( s.c_str() );
}

AnyString::AnyString( PITAnyString p )
{
	pit = p;
	// Don't call AddRef here because the caller isn't going to release.
}

AnyString::AnyString( const AnyString& p )
{
	pit = p.pit;
	if (pit)
		pit->AddRef();
}

AnyString& AnyString::operator=( AnyString& p )
{
	if (this != &p)
	{
		if (pit)
			pit->Release();
		pit = p.pit;
		if (pit)
			pit->AddRef();
	}
	return *this;
}

AnyString::~AnyString( void )
{
	if (pit)
		pit->Release();
}

PITAnyString AnyString::GetPITAnyString( void )
{
	return pit;
}

void AnyString::GetString( string& s )
{
	if (pit)
	{
		s = pit->get_Buffer();
	}
}

//-----------------------------------------------------------------------------

#ifdef __FLAT__

typedef enum
{
	ItsWindows95,
	ItsWindowsNT,
} SystemType;

SystemType WhatsTheSystem( void )
{
	DWORD version = GetVersion();

	if (LOBYTE(LOWORD(version)) >= 4)
	{
		if (version < 0x80000000)
			return ItsWindowsNT;				// NT 4
		else
			return ItsWindows95;
	}

	return ItsWindowsNT;				// NT 3.xx
}

#else // __FLAT__

# define VBXMSG_GETEMUHANDLE "VBXGETEMUHANDLE"

#endif // __FLAT__

HMODULE GetVBXEmulator( HWND hwnd )
{
	HMODULE hvbxdll;

#ifdef __FLAT__

	NOTUSED( hwnd );

	if (WhatsTheSystem() == ItsWindows95)
		hvbxdll = GetModuleHandle( "BIVBX30.32C" );	// Windows 95
	else
		hvbxdll = GetModuleHandle( "BIVBX30.32N" );	// Windows NT

#else // __FLAT__

	WORD wMsgGetEmuHandle = RegisterWindowMessage( VBXMSG_GETEMUHANDLE );
	hvbxdll = HMODULE( SendMessage( hwnd, wMsgGetEmuHandle, 0, 0L ) );

#endif // __FLAT__

	return hvbxdll;
}

typedef LPVOID HCTL;
#define GPA_VBXGETHCTL "VBXGetHctl"
typedef HCTL (FAR PASCAL* VBXGETHCTL)( HWND );

HCTL GetVBXCtl( HWND hdlg, int idc, HMODULE* phvbxdll )
{
	HCTL hctl = 0;

	HWND hwnd = GetDlgItem( hdlg, idc );
	if (hwnd)
	{
		HMODULE hvbxdll = GetVBXEmulator( hwnd );
		*phvbxdll = hvbxdll;
		if (hvbxdll)
		{
			VBXGETHCTL fpVBXGetHctl = (VBXGETHCTL) GetProcAddress( hvbxdll, GPA_VBXGETHCTL );
			if (fpVBXGetHctl)
			{
				hctl = (*fpVBXGetHctl)( hwnd );
			}
		}
	}

	return hctl;
}

#ifdef __FLAT__
# define GPA_VBXGETPROPBYNAME	((LPCSTR)(DWORD) 80)
#else // __FLAT__
# define GPA_VBXGETPROPBYNAME "VBXGetPropByName"
#endif // __FLAT__

typedef BOOL (FAR PASCAL* VBXGETPROPBYNAME)( HCTL, LPSTR, LPVOID );

PIUnknown GetVBXPIUnknown( HWND hdlg, int idc )
{
	HMODULE hvbxdll = 0;
	HCTL hctl = GetVBXCtl( hdlg, idc, &hvbxdll );
	if (hctl)
	{
		VBXGETPROPBYNAME fpVBXGetPropByName = (VBXGETPROPBYNAME) GetProcAddress( hvbxdll, GPA_VBXGETPROPBYNAME );
		if (fpVBXGetPropByName)
		{
			PIUnknown punk = 0;
			if ((*fpVBXGetPropByName)( hctl, "Object", &punk ))
			{
				return punk;
			}
		}
	}

	return 0;
}

#ifdef __FLAT__
# define GPA_VBXSETPROPBYNAME	((LPCSTR)(DWORD) 132)
#else // __FLAT__
# define GPA_VBXSETPROPBYNAME "VBXSetPropByName"
#endif // __FLAT__

typedef BOOL (FAR PASCAL* VBXSETPROPBYNAME)( HCTL, LPSTR, LPVOID );

void SetVBXPIUnknown( HWND hdlg, int idc, PIUnknown punk )
{
	HMODULE hvbxdll = 0;
	HCTL hctl = GetVBXCtl( hdlg, idc, &hvbxdll );
	if (hctl)
	{
		VBXSETPROPBYNAME fpVBXSetPropByName = (VBXSETPROPBYNAME) GetProcAddress( hvbxdll, GPA_VBXSETPROPBYNAME );
		if (fpVBXSetPropByName)
		{
			(*fpVBXSetPropByName)( hctl, "Object", punk );
		}
	}
}

//-----------------------------------------------------------------------------

void VDBTEasterEgg( void )
{
	PIBDT50 pBDT = GetIBDT50();
	if (pBDT)
	{
		pBDT->EasterEgg();
		pBDT->Release();
	}
}

//-----------------------------------------------------------------------------
