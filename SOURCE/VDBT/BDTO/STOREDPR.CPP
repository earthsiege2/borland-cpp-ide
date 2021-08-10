//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// storedpr.cpp
// TStoredProc wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TStoredProc::SetTStoredProc( PIUnknown p )
{
	storedproc = 0;
	if (p)
		p->QueryInterface( IID_ITStoredProc, (void**) &storedproc );
}

void TStoredProc::ClearTStoredProc( void )
{
	if (storedproc)
	{
		storedproc->Release();
		storedproc = 0;
	}
}

TStoredProc::TStoredProc( void ) : TDBDataSet()
{
	storedproc = CreateITStoredProc();
	TDBDataSet::SetPIT( storedproc );
}

TStoredProc::TStoredProc( PITStoredProc p ) : TDBDataSet( p )
{
	SetTStoredProc( p );
}

TStoredProc::TStoredProc( const TStoredProc& p ) : TDBDataSet( p )
{
	SetTStoredProc( p.storedproc );
}

TStoredProc::TStoredProc( PTStoredProc p ) : TDBDataSet( p )
{
	SetTStoredProc( p ? p->storedproc : 0 );
}

TStoredProc::TStoredProc( HWND hdlg, int idc ) : TDBDataSet()

{
	SetTStoredProc( GetVBXPIUnknown( hdlg, idc ) );
	TDBDataSet::SetPIT( storedproc );
}

void TStoredProc::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, storedproc );
}

TStoredProc& TStoredProc::operator=( PITStoredProc p )
{
	TDBDataSet::operator=(p);
	ClearTStoredProc();
	SetTStoredProc( p );
	return *this;
}

TStoredProc& TStoredProc::operator=( const TStoredProc& p )
{
	if (this != &p)
	{
		TDBDataSet::operator=(p);
		ClearTStoredProc();
		SetTStoredProc( p.storedproc );
	}
	return *this;
}

int TStoredProc::operator==( const TStoredProc& p ) const
{
	if (this == &p)
		return true;
	if (storedproc == p.storedproc)
		return true;
	return false;
}

int TStoredProc::operator!=( const TStoredProc& p ) const
{
	return ! operator==(p);
}

TStoredProc::~TStoredProc()
{
	ClearTStoredProc();
}

void TStoredProc::SetPIT( PIUnknown p )
{
	ClearTStoredProc();
	SetTStoredProc( p );
	TDBDataSet::SetPIT( p );
}

void TStoredProc::CopyParams( TParams& p )
{
	if (storedproc)
		storedproc->CopyParams( p.GetPITParams() );
}

DEFINE_BDTO_PROP_RO( TStoredProc, bool, DescriptionsAvailable );

void TStoredProc::GetDescriptionsAvailable( bool& d )
{
	if (storedproc)
		d = MakeBool( storedproc->get_DescriptionsAvailable() );
	else
		d = false;
}

void TStoredProc::ExecProc( void )
{
	if (storedproc)
		storedproc->ExecProc();
}

DEFINE_BDTO_OBJECTMETHOD1( TStoredProc, TParam, PITParam, ParamByName, string& );

void TStoredProc::CallParamByName( string& value, TParam& p )
{
	if (storedproc)
	{
		PITParam pit = storedproc->ParamByName( AnyString(value).GetPITAnyString() );
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

void TStoredProc::Prepare( void )
{
	if (storedproc)
		storedproc->Prepare();
}

void TStoredProc::GetResults( void )
{
	if (storedproc)
		storedproc->GetResults();
}

void TStoredProc::UnPrepare( void )
{
	if (storedproc)
		storedproc->UnPrepare();
}

DEFINE_BDTO_PROP_RO( TStoredProc, uint16, ParamCount );
DEFINE_BDTO_PROP_RO( TStoredProc, hDBIStmt, StmtHandle );
DEFINE_BDTO_PROP_RW( TStoredProc, bool, Prepared );

void TStoredProc::GetParamCount( uint16& c )
{
	if (storedproc)
		c = storedproc->get_ParamCount();
}

void TStoredProc::GetStmtHandle( hDBIStmt& h )
{
	if (storedproc)
		h = storedproc->get_StmtHandle();
}

void TStoredProc::GetPrepared( bool& p )
{
	if (storedproc)
		p = MakeBool( storedproc->get_Prepared() );
}

void TStoredProc::SetPrepared( bool p )
{
	if (storedproc)
		storedproc->put_Prepared( MakeVariantBool( p ) );
}

DEFINE_BDTO_OBJECTPROP_RW( TStoredProc, string, StoredProcName );
DEFINE_BDTO_PROP_RW( TStoredProc, uint16, Overload );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TStoredProc, TParams, PITParams, Params );
DEFINE_BDTO_PROP_RW( TStoredProc, TParamBindMode, ParamBindMode );

void TStoredProc::GetStoredProcName( string& s )
{
	if (storedproc)
		AnyString( storedproc->get_StoredProcName() ).GetString( s );
}

void TStoredProc::SetStoredProcName( string& n )
{
	if (storedproc)
		storedproc->put_StoredProcName( AnyString(n).GetPITAnyString() );
}

void TStoredProc::GetOverload( uint16& o )
{
	if (storedproc)
		o = storedproc->get_Overload();
}

void TStoredProc::SetOverload( uint16 o )
{
	if (storedproc)
		storedproc->put_Overload( o );
}

void TStoredProc::GetParams( TParams& p )
{
	if (storedproc)
	{
		PITParams pit = storedproc->get_Params();
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

void TStoredProc::SetParams( TParams& p )
{
	if (storedproc)
		storedproc->put_Params( p.GetPITParams() );
}

void TStoredProc::GetParamBindMode( TParamBindMode& m )
{
	if (storedproc)
		m = storedproc->get_ParamBindMode();
}

void TStoredProc::SetParamBindMode( TParamBindMode m )
{
	if (storedproc)
		storedproc->put_ParamBindMode( m );
}
