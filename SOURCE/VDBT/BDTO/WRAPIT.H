//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// wrapit.h
// Functions which create wrapper objects
//-----------------------------------------------------------------------------

#if !defined(WRAPIT_H)
#define WRAPIT_H

//
// Mangle the class and function names so we can have mulitpale versions of the
// same classes and functions in one .LIB file.
//
#if defined( __DLL__ ) && ! defined( __FLAT__ )
#  if defined( _RTLDLL )
#    define WrapPITField      dWrapPITField
#    define WrapPITDataSet    dWrapPITDataSet
#    define WrapPITSession    dWrapPITSession
#    define WrapPITDatabase   dWrapPITDatabase
#    define WrapPITDataSource dWrapPITDataSource
#    define WrapPITStrings    dWrapPITStrings
#    define GetVBXPIUnknown   dGetVBXPIUnknown
#    define SetVBXPIUnknown   dSetVBXPIUnknown
#    define AnyString         dAnyString
#  else _RTLDLL
#    define WrapPITField      uWrapPITField
#    define WrapPITDataSet    uWrapPITDataSet
#    define WrapPITSession    uWrapPITSession
#    define WrapPITDatabase   uWrapPITDatabase
#    define WrapPITDataSource uWrapPITDataSource
#    define WrapPITStrings    uWrapPITStrings
#    define GetVBXPIUnknown   uGetVBXPIUnknown
#    define SetVBXPIUnknown   uSetVBXPIUnknown
#    define AnyString         uAnyString
#  endif _RTLDLL
#elif defined( _RTLDLL )
#  define WrapPITField      iWrapPITField
#  define WrapPITDataSet    iWrapPITDataSet
#  define WrapPITSession    iWrapPITSession
#  define WrapPITDatabase   iWrapPITDatabase
#  define WrapPITDataSource iWrapPITDataSource
#  define WrapPITStrings    iWrapPITStrings
#  define GetVBXPIUnknown   iGetVBXPIUnknown
#  define SetVBXPIUnknown   iSetVBXPIUnknown
#  define AnyString         iAnyString
#endif

PTField WrapPITField( PITField pit );
PTDataSet WrapPITDataSet( PITDataSet pitDataSet );
PTSession WrapPITSession( PITSession pitSession );
PTDatabase WrapPITDatabase( PITDatabase pitDatabase );
PTDataSource WrapPITDataSource( PITDataSource pitDataSource );
PTStrings WrapPITStrings( PITStrings pitStrings );

class AnyString
{
protected:
	PITAnyString pit;
public:
	AnyString( const string& s );
	AnyString( PITAnyString p );
	AnyString( const AnyString& p );
	virtual AnyString& operator=( AnyString& p );
	~AnyString( void );
	PITAnyString GetPITAnyString( void );
	void GetString( string& s );
};

PIUnknown GetVBXPIUnknown( HWND hdlg, int idc );
void SetVBXPIUnknown( HWND hdlg, int idc, PIUnknown punk );

#endif // WRAPIT_H
