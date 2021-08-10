//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// session.cpp
// TSession wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

TSession Session( true );		// global session variable

//-----------------------------------------------------------------------------

void _export STDAPICALLTYPE PasswordEventCallback( int32 data, PITSession session, VARIANT_BOOL FAR* Continue )
{
	if (data)
	{
		PTSession ezSession = WrapPITSession( session );
		bool ezContinue = MakeBool( *Continue );

		TPasswordSource* source = (TPasswordSource*) data;
		(*source)( *ezSession, ezContinue );

		*Continue = MakeVariantBool( ezContinue );

		if (ezSession)
			delete ezSession;
	}
}

void TSession::AttachOnPassword( const TBdtEventSourceBase&, bool attach )
{
	CheckGlobalSession();
	if (session)
	{
		AttachedOnPassword = attach;
		if (attach)
			session->AttachOnPassword( PasswordEventCallback, (int32) &OnPasswordSource );
		else
			session->DetachOnPassword( PasswordEventCallback, (int32) &OnPasswordSource );
	}
}

void TSession::DetachEvents( void )
{
	if (session)
	{
		if (AttachedOnPassword)
			session->DetachOnPassword( PasswordEventCallback, (int32) &OnPasswordSource );
	}
}

void TSession::ReattachEvents( void )
{
	if (session)
	{
		if (AttachedOnPassword)
			session->AttachOnPassword( PasswordEventCallback, (int32) &OnPasswordSource );
	}
}

//-----------------------------------------------------------------------------

void TSession::SetTSession( PIUnknown p )
{
	session = 0;
	if (p)
		p->QueryInterface( IID_ITSession, (void**) &session );
	ReattachEvents();
}

void TSession::ClearTSession( void )
{
	DetachEvents();
	if (session)
	{
		session->Release();
		session = 0;
	}
}

TSession::TSession( bool createGlobal ) :
	TBDTComponent(),
	OnPasswordSource( SrcAttach_MFUNCTOR( *this, &TSession::AttachOnPassword ) ),
	AttachedOnPassword( false )
{
	global = createGlobal;
	if (global)
		session = 0;
	else
	{
		session = CreateITSession();
		TBDTComponent::SetPIT( session );
	}
}

TSession::TSession( void ) :
	TBDTComponent(),
	OnPasswordSource( SrcAttach_MFUNCTOR( *this, &TSession::AttachOnPassword ) ),
	AttachedOnPassword( false )
{
	global = false;
	session = CreateITSession();
	TBDTComponent::SetPIT( session );
}

TSession::TSession( PITSession p ) :
	TBDTComponent( p ),
	OnPasswordSource( SrcAttach_MFUNCTOR( *this, &TSession::AttachOnPassword ) ),
	AttachedOnPassword( false )
{
	global = false;
	SetTSession( p );
}

TSession::TSession( const TSession& p ) :
	TBDTComponent( p ),
	OnPasswordSource( SrcAttach_MFUNCTOR( *this, &TSession::AttachOnPassword ) ),
	AttachedOnPassword( false )
{
	global = false;
	SetTSession( p.session );
}

TSession::TSession( PTSession p ) :
	TBDTComponent( p ),
	OnPasswordSource( SrcAttach_MFUNCTOR( *this, &TSession::AttachOnPassword ) ),
	AttachedOnPassword( false )
{
	global = false;
	SetTSession( p ? p->session : 0 );
}

TSession& TSession::operator=( PITSession p )
{
	TBDTComponent::operator=(p);
	ClearTSession();
	SetTSession( p );
	return *this;
}

TSession& TSession::operator=( const TSession& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTSession();
		SetTSession( p.session );
	}
	return *this;
}

int TSession::operator==( const TSession& p ) const
{
	if (this == &p)
		return true;
	if (session == p.session)
		return true;
	return false;
}

int TSession::operator!=( const TSession& p ) const
{
	return ! operator==(p);
}

TSession::~TSession()
{
	ClearTSession();
}

void TSession::SetPIT( PIUnknown p )
{
	ClearTSession();
	SetTSession( p );
	TBDTComponent::SetPIT( p );
}

void TSession::CheckGlobalSession( void )
{
	if (! session && global)
	{
		session = GetITSession();
		TBDTComponent::SetPIT( session );
	}
}

void TSession::AddPassword( const string& p )
{
	CheckGlobalSession();
	if (session)
		session->AddPassword( AnyString(p).GetPITAnyString() );
}

void TSession::CloseDatabase( TDatabase& d )
{
	CheckGlobalSession();
	if (session)
		session->CloseDatabase( d.GetPITDatabase() );
}

void TSession::DropConnections( void )
{
	CheckGlobalSession();
	if (session)
		session->DropConnections();
}

DEFINE_BDTO_OBJECTMETHOD1( TSession, TDatabase, PITDatabase, FindDatabase, string& );

void TSession::CallFindDatabase( string& n, TDatabase& d )
{
	CheckGlobalSession();
	if (session)
	{
		PITDatabase pit = session->FindDatabase( AnyString(n).GetPITAnyString() );
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TSession::GetAliasNames( TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetAliasNames( list.GetPITStrings() );
}

void TSession::GetAliasParams( const string& n, TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetAliasParams( AnyString(n).GetPITAnyString(), list.GetPITStrings() );
}

void TSession::GetDatabaseNames( TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetDatabaseNames( list.GetPITStrings() );
}

void TSession::GetDriverNames( TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetDriverNames( list.GetPITStrings() );
}

void TSession::GetDriverParams( const string& n, TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetDriverParams( AnyString(n).GetPITAnyString(), list.GetPITStrings() );
}

bool TSession::GetPassword( void )
{
	CheckGlobalSession();
	if (session)
		return MakeBool( session->GetPassword() );
	return false;
}

void TSession::GetTableNames( const string& DatabaseName, const string& Pattern, bool Extensions, bool SystemTables, TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetTableNames( AnyString(DatabaseName).GetPITAnyString(), AnyString(Pattern).GetPITAnyString(), MakeVariantBool( Extensions ), MakeVariantBool( SystemTables ), list.GetPITStrings() );
}

void TSession::GetStoredProcNames( const string& DatabaseName, TStrings& list )
{
	CheckGlobalSession();
	if (session)
		session->GetStoredProcNames( AnyString(DatabaseName).GetPITAnyString(), list.GetPITStrings() );
}

DEFINE_BDTO_OBJECTMETHOD1( TSession, TDatabase, PITDatabase, OpenDatabase, string& );

void TSession::CallOpenDatabase( string& n, TDatabase& d )
{
	CheckGlobalSession();
	if (session)
	{
		PITDatabase pit = session->OpenDatabase( AnyString(n).GetPITAnyString() );
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TSession::RemoveAllPasswords( void )
{
	CheckGlobalSession();
	if (session)
		session->RemoveAllPasswords();
}

void TSession::RemovePassword( const string& p )
{
	CheckGlobalSession();
	if (session)
		session->RemovePassword( AnyString(p).GetPITAnyString() );
}

DEFINE_BDTO_PROP_RO( TSession, int, DatabaseCount );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TSession, TDatabase, PITDatabase, Databases, int );
DEFINE_BDTO_PROP_RO( TSession, hDBISes, Handle );
DEFINE_BDTO_PROP_RW( TSession, bool, KeepConnections );
DEFINE_BDTO_PROP_RO( TSession, TLocale, Locale );
DEFINE_BDTO_OBJECTPROP_RW( TSession, string, NetFileDir );
DEFINE_BDTO_OBJECTPROP_RW( TSession, string, PrivateDir );

void TSession::GetDatabaseCount( int& c )
{
	CheckGlobalSession();
	if (session)
		c = session->get_DatabaseCount();
}

void TSession::GetDatabases( int i, TDatabase& d )
{
	CheckGlobalSession();
	if (session)
	{
		PITDatabase pit = session->get_Databases( i );
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TSession::GetHandle( hDBISes& h )
{
	CheckGlobalSession();
	if (session)
		h = session->get_Handle();
}

void TSession::GetKeepConnections( bool& k )
{
	CheckGlobalSession();
	if (session)
		k = MakeBool( session->get_KeepConnections() );
}

void TSession::SetKeepConnections( bool k )
{
	CheckGlobalSession();
	if (session)
		session->put_KeepConnections( MakeVariantBool( k ) );
}

void TSession::GetLocale( TLocale& l )
{
	CheckGlobalSession();
	if (session)
		l = session->get_Locale();
}

void TSession::GetNetFileDir( string& s )
{
	CheckGlobalSession();
	if (session)
		AnyString( session->get_NetFileDir() ).GetString( s );
}

void TSession::SetNetFileDir( string& d )
{
	CheckGlobalSession();
	if (session)
		session->put_NetFileDir( AnyString(d).GetPITAnyString() );
}

void TSession::GetPrivateDir( string& s )
{
	CheckGlobalSession();
	if (session)
		AnyString( session->get_PrivateDir() ).GetString( s );
}

void TSession::SetPrivateDir( string& d )
{
	CheckGlobalSession();
	if (session)
		session->put_PrivateDir( AnyString(d).GetPITAnyString() );
}

