//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// wrapit.h
// Functions which create wrapper objects
//-----------------------------------------------------------------------------

#if !defined(WRAPIT_H)
#define WRAPIT_H

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
