//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// database.cpp
// TDatabase wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void _export STDAPICALLTYPE LoginEventCallback( int32 data, PITDatabase database, PITStrings LoginParams )
{
	if (data)
	{
		PTDatabase ezDatabase = WrapPITDatabase( database );
		PTStrings ezLoginParams = WrapPITStrings( LoginParams );

		TLoginSource* source = (TLoginSource*) data;
		(*source)( *ezDatabase, *ezLoginParams );

		if (ezLoginParams)
			delete ezLoginParams;
		if (ezDatabase)
			delete ezDatabase;
	}
}

void TDatabase::AttachOnLogin( const TBdtEventSourceBase&, bool attach )
{
	if (database)
	{
		AttachedOnLogin = attach;
		if (attach)
			database->AttachOnLogin( LoginEventCallback, (int32) &OnLoginSource );
		else
			database->DetachOnLogin( LoginEventCallback, (int32) &OnLoginSource );
	}
}

void TDatabase::DetachEvents( void )
{
	if (database)
	{
		if (AttachedOnLogin)
			database->DetachOnLogin( LoginEventCallback, (int32) &OnLoginSource );
	}
}

void TDatabase::ReattachEvents( void )
{
	if (database)
	{
		if (AttachedOnLogin)
			database->AttachOnLogin( LoginEventCallback, (int32) &OnLoginSource );
	}
}

//-----------------------------------------------------------------------------

void TDatabase::SetTDatabase( PIUnknown p )
{
	database = 0;
	if (p)
		p->QueryInterface( IID_ITDatabase, (void**) &database );
	ReattachEvents();
}

void TDatabase::ClearTDatabase( void )
{
	DetachEvents();
	if (database)
	{
		database->Release();
		database = 0;
	}
}

TDatabase::TDatabase( void ) :
	TBDTComponent(),
	OnLoginSource( SrcAttach_MFUNCTOR( *this, &TDatabase::AttachOnLogin ) ),
	AttachedOnLogin( false )
{
	database = CreateITDatabase();
	TBDTComponent::SetPIT( database );
}

TDatabase::TDatabase( PITDatabase p ) :
	TBDTComponent( p ),
	OnLoginSource( SrcAttach_MFUNCTOR( *this, &TDatabase::AttachOnLogin ) ),
	AttachedOnLogin( false )
{
	SetTDatabase( p );
}

TDatabase::TDatabase( const TDatabase& p ) :
	TBDTComponent( p ),
	OnLoginSource( SrcAttach_MFUNCTOR( *this, &TDatabase::AttachOnLogin ) ),
	AttachedOnLogin( false )
{
	SetTDatabase( p.database );
}

TDatabase::TDatabase( PTDatabase p ) :
	TBDTComponent( p ),
	OnLoginSource( SrcAttach_MFUNCTOR( *this, &TDatabase::AttachOnLogin ) ),
	AttachedOnLogin( false )
{
	SetTDatabase( p ? p->database : 0 );
}

TDatabase::TDatabase( HWND hdlg, int idc ) :
	TBDTComponent(),
	OnLoginSource( SrcAttach_MFUNCTOR( *this, &TDatabase::AttachOnLogin ) ),
	AttachedOnLogin( false )
{
	SetTDatabase( GetVBXPIUnknown( hdlg, idc ) );
	TBDTComponent::SetPIT( database );
}

void TDatabase::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, database );
}

TDatabase& TDatabase::operator=( PITDatabase p )
{
	TBDTComponent::operator=(p);
	ClearTDatabase();
	SetTDatabase( p );
	return *this;
}

TDatabase& TDatabase::operator=( const TDatabase& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTDatabase();
		SetTDatabase( p.database );
	}
	return *this;
}

int TDatabase::operator==( const TDatabase& p ) const
{
	if (this == &p)
		return true;
	if (database == p.database)
		return true;
	return false;
}

int TDatabase::operator!=( const TDatabase& p ) const
{
	return ! operator==(p);
}

TDatabase::~TDatabase()
{
	ClearTDatabase();
}

void TDatabase::SetPIT( PIUnknown p )
{
	ClearTDatabase();
	SetTDatabase( p );
	TBDTComponent::SetPIT( p );
}

void TDatabase::Close( void )
{
	if (database)
		database->Close();
}

void TDatabase::CloseDatasets( void )
{
	if (database)
		database->CloseDatasets();
}

void TDatabase::Commit( void )
{
	if (database)
		database->Commit();
}

void TDatabase::Open( void )
{
	if (database)
		database->Open();
}

void TDatabase::Rollback( void )
{
	if (database)
		database->Rollback();
}

void TDatabase::StartTransaction( void )
{
	if (database)
		database->StartTransaction();
}

void TDatabase::ValidateName( const string& name )
{
	if (database)
		database->ValidateName( AnyString(name).GetPITAnyString() );
}

DEFINE_BDTO_PROP_RO( TDatabase, int, DatasetCount );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TDatabase, TDBDataSet, PITDBDataSet, Datasets, int );
DEFINE_BDTO_PROP_RO( TDatabase, hDBIDb, Handle );
DEFINE_BDTO_PROP_RO( TDatabase, bool, IsSQLBased );
DEFINE_BDTO_PROP_RO( TDatabase, TLocale, Locale );
DEFINE_BDTO_PROP_RW( TDatabase, bool, Temporary );

void TDatabase::GetDatasetCount( int& c )
{
	if (database)
		c = database->get_DatasetCount();
}

void TDatabase::GetDatasets( int i, TDBDataSet& d )
{
	if (database)
	{
		PITDBDataSet pit = database->get_Datasets( i );
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDatabase::GetHandle( hDBIDb& h )
{
	if (database)
		h = database->get_Handle();
}

void TDatabase::GetIsSQLBased( bool& b )
{
	if (database)
		b = MakeBool( database->get_IsSQLBased() );
}

void TDatabase::GetLocale( TLocale& l )
{
	if (database)
		l = database->get_Locale();
}

void TDatabase::GetTemporary( bool& t )
{
	if (database)
		t = MakeBool( database->get_Temporary() );
}

void TDatabase::SetTemporary( bool t )
{
	if (database)
		database->put_Temporary( MakeVariantBool( t ) );
}

DEFINE_BDTO_OBJECTPROP_RW( TDatabase, string, AliasName );
DEFINE_BDTO_PROP_RW( TDatabase, bool, Connected );
DEFINE_BDTO_OBJECTPROP_RW( TDatabase, string, DatabaseName );
DEFINE_BDTO_OBJECTPROP_RW( TDatabase, string, DriverName );
DEFINE_BDTO_PROP_RW( TDatabase, bool, KeepConnection );
DEFINE_BDTO_PROP_RW( TDatabase, bool, LoginPrompt );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TDatabase, TStrings, PITStrings, Params );
DEFINE_BDTO_PROP_RW( TDatabase, TTransIsolation, TransIsolation );

void TDatabase::GetAliasName( string& s )
{
	if (database)
		AnyString( database->get_AliasName() ).GetString( s );
}

void TDatabase::SetAliasName( string& n )
{
	if (database)
		database->put_AliasName( AnyString(n).GetPITAnyString() );
}

void TDatabase::GetConnected( bool& c )
{
	if (database)
		c = MakeBool( database->get_Connected() );
}

void TDatabase::SetConnected( bool c )
{
	if (database)
		database->put_Connected( MakeVariantBool( c ) );
}

void TDatabase::GetDatabaseName( string& s )
{
	if (database)
		AnyString( database->get_DatabaseName() ).GetString( s );
}

void TDatabase::SetDatabaseName( string& n )
{
	if (database)
		database->put_DatabaseName( AnyString(n).GetPITAnyString() );
}

void TDatabase::GetDriverName( string& s )
{
	if (database)
		AnyString( database->get_DriverName() ).GetString( s );
}

void TDatabase::SetDriverName( string& n )
{
	if (database)
		database->put_DriverName( AnyString(n).GetPITAnyString() );
}

void TDatabase::GetKeepConnection( bool& k )
{
	if (database)
		k = MakeBool( database->get_KeepConnection() );
}

void TDatabase::SetKeepConnection( bool k )
{
	if (database)
		database->put_KeepConnection( MakeVariantBool( k ) );
}

void TDatabase::GetLoginPrompt( bool& l )
{
	if (database)
		l = MakeBool( database->get_LoginPrompt() );
}

void TDatabase::SetLoginPrompt( bool l )
{
	if (database)
		database->put_LoginPrompt( MakeVariantBool( l ) );
}

void TDatabase::GetParams( TStrings& s )
{
	if (database)
	{
		PITStrings pit = database->get_Params();
		if (pit)
		{
			s.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDatabase::SetParams( TStrings& p )
{
	if (database)
		database->put_Params( p.GetPITStrings() );
}

void TDatabase::GetTransIsolation( TTransIsolation& t )
{
	if (database)
		t = database->get_TransIsolation();
}

void TDatabase::SetTransIsolation( TTransIsolation t )
{
	if (database)
		database->put_TransIsolation( t );
}

