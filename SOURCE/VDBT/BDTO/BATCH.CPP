//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// batch.cpp
// TBatchMove wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TBatchMove::SetTBatchMove( PIUnknown p )
{
	batchmove = 0;
	if (p)
		p->QueryInterface( IID_ITBatchMove, (void**) &batchmove );
}

void TBatchMove::ClearTBatchMove( void )
{
	if (batchmove)
	{
		batchmove->Release();
		batchmove = 0;
	}
}

TBatchMove::TBatchMove( void ) : TBDTComponent()
{
	batchmove = CreateITBatchMove();
	TBDTComponent::SetPIT( batchmove );
}

TBatchMove::TBatchMove( PITBatchMove p ) : TBDTComponent( p )
{
	SetTBatchMove( p );
}

TBatchMove::TBatchMove( const TBatchMove& p ) : TBDTComponent( p )
{
	SetTBatchMove( p.batchmove );
}

TBatchMove::TBatchMove( PTBatchMove p ) : TBDTComponent( p )
{
	SetTBatchMove( p ? p->batchmove : 0 );
}

TBatchMove::TBatchMove( HWND hdlg, int idc ) : TBDTComponent()
{
	SetTBatchMove( GetVBXPIUnknown( hdlg, idc ) );
	TBDTComponent::SetPIT( batchmove );
}

void TBatchMove::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, batchmove );
}

TBatchMove& TBatchMove::operator=( PITBatchMove p )
{
	TBDTComponent::operator=(p);
	ClearTBatchMove();
	SetTBatchMove( p );
	return *this;
}

TBatchMove& TBatchMove::operator=( const TBatchMove& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTBatchMove();
		SetTBatchMove( p.batchmove );
	}
	return *this;
}

int TBatchMove::operator==( const TBatchMove& p ) const
{
	if (this == &p)
		return true;
	if (batchmove == p.batchmove)
		return true;
	return false;
}

int TBatchMove::operator!=( const TBatchMove& p ) const
{
	return ! operator==(p);
}

TBatchMove::~TBatchMove()
{
	ClearTBatchMove();
}

void TBatchMove::SetPIT( PIUnknown p )
{
	ClearTBatchMove();
	SetTBatchMove( p );
	TBDTComponent::SetPIT( p );
}

void TBatchMove::Execute( void )
{
	if (batchmove)
		batchmove->Execute();
}

DEFINE_BDTO_PROP_RO( TBatchMove, int32, ChangedCount );
DEFINE_BDTO_PROP_RO( TBatchMove, int32, KeyViolCount );
DEFINE_BDTO_PROP_RO( TBatchMove, int32, MovedCount );
DEFINE_BDTO_PROP_RO( TBatchMove, int32, ProblemCount );

void TBatchMove::GetChangedCount( int32& c )
{
	if (batchmove)
		c = batchmove->get_ChangedCount();
}

void TBatchMove::GetKeyViolCount( int32& c )
{
	if (batchmove)
		c = batchmove->get_KeyViolCount();
}

void TBatchMove::GetMovedCount( int32& c )
{
	if (batchmove)
		c = batchmove->get_MovedCount();
}

void TBatchMove::GetProblemCount( int32& c )
{
	if (batchmove)
		c = batchmove->get_ProblemCount();
}

DEFINE_BDTO_PROP_RW( TBatchMove, bool, AbortOnKeyViol );
DEFINE_BDTO_PROP_RW( TBatchMove, bool, AbortOnProblem );
DEFINE_BDTO_OBJECTPROP_RW( TBatchMove, string, ChangedTableName );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TBatchMove, TTable, PITTable, Destination );
DEFINE_BDTO_OBJECTPROP_RW( TBatchMove, string, KeyViolTableName );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TBatchMove, TStrings, PITStrings, Mappings );
DEFINE_BDTO_PROP_RW( TBatchMove, TBatchMode, Mode );
DEFINE_BDTO_OBJECTPROP_RW( TBatchMove, string, ProblemTableName );
DEFINE_BDTO_PROP_RW( TBatchMove, int32, RecordCount );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TBatchMove, TDataSet, PITDataSet, Source );
DEFINE_BDTO_PROP_RW( TBatchMove, bool, Transliterate );

void TBatchMove::GetAbortOnKeyViol( bool& a )
{
	if (batchmove)
		a = MakeBool( batchmove->get_AbortOnKeyViol() );
}

void TBatchMove::SetAbortOnKeyViol( bool a )
{
	if (batchmove)
		batchmove->put_AbortOnKeyViol( MakeVariantBool( a ) );
}

void TBatchMove::GetAbortOnProblem( bool& a )
{
	if (batchmove)
		a = MakeBool( batchmove->get_AbortOnProblem() );
}

void TBatchMove::SetAbortOnProblem( bool a )
{
	if (batchmove)
		batchmove->put_AbortOnProblem( MakeVariantBool( a ) );
}

void TBatchMove::GetChangedTableName( string& s )
{
	if (batchmove)
		AnyString( batchmove->get_ChangedTableName() ).GetString( s );
}

void TBatchMove::SetChangedTableName( string& n )
{
	if (batchmove)
		batchmove->put_ChangedTableName( AnyString(n).GetPITAnyString() );
}

void TBatchMove::GetDestination( TTable& t )
{
	if (batchmove)
	{
		PITTable pit = batchmove->get_Destination();
		if (pit)
		{
			t.SetPIT( pit );
			pit->Release();
		}
	}
}

void TBatchMove::SetDestination( TTable& t )
{
	if (batchmove)
		batchmove->put_Destination( t.GetPITTable() );
}

void TBatchMove::GetKeyViolTableName( string& s )
{
	if (batchmove)
		AnyString( batchmove->get_KeyViolTableName() ).GetString( s );
}

void TBatchMove::SetKeyViolTableName( string& n )
{
	if (batchmove)
		batchmove->put_KeyViolTableName( AnyString(n).GetPITAnyString() );
}

void TBatchMove::GetMappings( TStrings& s )
{
	if (batchmove)
	{
		PITStrings pit = batchmove->get_Mappings();
		if (pit)
		{
			s.SetPIT( pit );
			pit->Release();
		}
	}
}

void TBatchMove::SetMappings( TStrings& s )
{
	if (batchmove)
		batchmove->put_Mappings( s.GetPITStrings() );
}

void TBatchMove::GetMode( TBatchMode& m )
{
	if (batchmove)
		m = batchmove->get_Mode();
}

void TBatchMove::SetMode( TBatchMode m )
{
	if (batchmove)
		batchmove->put_Mode( m );
}

void TBatchMove::GetProblemTableName( string& s )
{
	if (batchmove)
		AnyString( batchmove->get_ProblemTableName() ).GetString( s );
}

void TBatchMove::SetProblemTableName( string& n )
{
	if (batchmove)
		batchmove->put_ProblemTableName( AnyString(n).GetPITAnyString() );
}

void TBatchMove::GetRecordCount( int32& c )
{
	if (batchmove)
		c = batchmove->get_RecordCount();
}

void TBatchMove::SetRecordCount( int32 c )
{
	if (batchmove)
		batchmove->put_RecordCount( c );
}

void TBatchMove::GetSource( TDataSet& d )
{
	if (batchmove)
	{
		PITDataSet pit = batchmove->get_Source();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TBatchMove::SetSource( TDataSet& d )
{
	if (batchmove)
		batchmove->put_Source( d.GetPITDataSet() );
}

void TBatchMove::GetTransliterate( bool& t )
{
	if (batchmove)
		t = MakeBool( batchmove->get_Transliterate() );
}

void TBatchMove::SetTransliterate( bool t )
{
	if (batchmove)
		batchmove->put_Transliterate( MakeVariantBool( t ) );
}

