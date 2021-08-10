//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// query.cpp
// TQuery wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TQuery::SetTQuery( PIUnknown p )
{
	query = 0;
	if (p)
		p->QueryInterface( IID_ITQuery, (void**) &query );
}

void TQuery::ClearTQuery( void )
{
	if (query)
	{
		query->Release();
		query = 0;
	}
}

TQuery::TQuery( void ) : TDBDataSet()
{
	query = CreateITQuery();
	TDBDataSet::SetPIT( query );
}

TQuery::TQuery( PITQuery p ) : TDBDataSet( p )
{
	SetTQuery( p );
}

TQuery::TQuery( const TQuery& p ) : TDBDataSet( p )
{
	SetTQuery( p.query );
}

TQuery::TQuery( PTQuery p ) : TDBDataSet( p )
{
	SetTQuery( p ? p->query : 0 );
}

TQuery::TQuery( HWND hdlg, int idc ) : TDBDataSet()
{
	SetTQuery( GetVBXPIUnknown( hdlg, idc ) );
	TDBDataSet::SetPIT( query );
}

void TQuery::AttachToControl( HWND hdlg, int idc )
{
	SetPIT( GetVBXPIUnknown( hdlg, idc ) );
}

void TQuery::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, query );
}

TQuery& TQuery::operator=( PITQuery p )
{
	TDBDataSet::operator=(p);
	ClearTQuery();
	SetTQuery( p );
	return *this;
}

TQuery& TQuery::operator=( const TQuery& p )
{
	if (this != &p)
	{
		TDBDataSet::operator=(p);
		ClearTQuery();
		SetTQuery( p.query );
	}
	return *this;
}

int TQuery::operator==( const TQuery& p ) const
{
	if (this == &p)
		return true;
	if (query == p.query)
		return true;
	return false;
}

int TQuery::operator!=( const TQuery& p ) const
{
	return ! operator==(p);
}

TQuery::~TQuery()
{
	ClearTQuery();
}

void TQuery::SetPIT( PIUnknown p )
{
	ClearTQuery();
	SetTQuery( p );
	TDBDataSet::SetPIT( p );
}

void TQuery::ExecSQL( void )
{
	if (query)
		query->ExecSQL();
}

DEFINE_BDTO_OBJECTMETHOD1( TQuery, TParam, PITParam, ParamByName, string& );

void TQuery::CallParamByName( string& value, TParam& p )
{
	if (query)
	{
		PITParam pit = query->ParamByName( AnyString(value).GetPITAnyString() );
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

void TQuery::Prepare( void )
{
	if (query)
		query->Prepare();
}

void TQuery::UnPrepare( void )
{
	if (query)
		query->UnPrepare();
}

DEFINE_BDTO_PROP_RW( TQuery, bool, Prepared );
DEFINE_BDTO_PROP_RO( TQuery, uint16, ParamCount );
DEFINE_BDTO_PROP_RO( TQuery, bool, Local );
DEFINE_BDTO_PROP_RO( TQuery, hDBIStmt, StmtHandle );
DEFINE_BDTO_OBJECTPROP_RO( TQuery, string, Text );

void TQuery::GetPrepared( bool& p )
{
	if (query)
		p = MakeBool( query->get_Prepared() );
}

void TQuery::SetPrepared( bool p )
{
	if (query)
		query->put_Prepared( MakeVariantBool( p ) );
}

void TQuery::GetParamCount( uint16& c )
{
	if (query)
		c = query->get_ParamCount();
}

void TQuery::GetLocal( bool& l )
{
	if (query)
		l = MakeBool( query->get_Local() );
}

void TQuery::GetStmtHandle( hDBIStmt& h )
{
	if (query)
		h = query->get_StmtHandle();
}

void TQuery::GetText( string& s )
{
	if (query)
		AnyString( query->get_Text() ).GetString( s );
}

DEFINE_BDTO_OBJECTPROP_RW_FAST( TQuery, TStrings, PITStrings, SQL );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TQuery, TDataSource, PITDataSource, DataSource );
DEFINE_BDTO_PROP_RW( TQuery, bool, UniDirectional );
DEFINE_BDTO_PROP_RW( TQuery, bool, RequestLive );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TQuery, TParams, PITParams, Params );
DEFINE_BDTO_PROP_RW( TQuery, TUpdateMode, UpdateMode );

void TQuery::GetSQL( TStrings& s )
{
	if (query)
	{
		PITStrings pit = query->get_SQL();
		if (pit)
		{
			s.SetPIT( pit );
			pit->Release();
		}
	}
}

void TQuery::SetSQL( const TStrings& s )
{
	if (query)
		query->put_SQL( s.GetPITStrings() );
}

void TQuery::GetDataSource( TDataSource& d )
{
	if (query)
	{
		PITDataSource pit = query->get_DataSource();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TQuery::SetDataSource( const TDataSource& d )
{
	if (query)
		query->put_DataSource( d.GetPITDataSource() );
}

void TQuery::GetUniDirectional( bool& u )
{
	if (query)
		u = MakeBool( query->get_UniDirectional() );
}

void TQuery::SetUniDirectional( bool u )
{
	if (query)
		query->put_UniDirectional( MakeVariantBool( u ) );
}

void TQuery::GetRequestLive( bool& r )
{
	if (query)
		r = MakeBool( query->get_RequestLive() );
}

void TQuery::SetRequestLive( bool r )
{
	if (query)
		query->put_RequestLive( MakeVariantBool( r ) );
}

void TQuery::GetParams( TParams& p )
{
	if (query)
	{
		PITParams pit = query->get_Params();
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

void TQuery::SetParams( const TParams& p )
{
	if (query)
		query->put_Params( p.GetPITParams() );
}

void TQuery::GetUpdateMode( TUpdateMode& m )
{
	if (query)
		m = query->get_UpdateMode();
}

void TQuery::SetUpdateMode( TUpdateMode m )
{
	if (query)
		query->put_UpdateMode( m );
}
