//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// table.cpp
// TTable wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TTable::SetTTable( PIUnknown p )
{
	table = 0;
	if (p)
		p->QueryInterface( IID_ITTable, (void**) &table );
}

void TTable::ClearTTable( void )
{
	if (table)
	{
		table->Release();
		table = 0;
	}
}

TTable::TTable( void ) : TDBDataSet()
{
	table = CreateITTable();
	TDBDataSet::SetPIT( table );
}

TTable::TTable( PITTable p ) : TDBDataSet( p )
{
	SetTTable( p );
}

TTable::TTable( const TTable& p ) : TDBDataSet( p )
{
	SetTTable( p.table );
}

TTable::TTable( PTTable p ) : TDBDataSet( p )
{
	SetTTable( p ? p->table : 0 );
}

TTable::TTable( HWND hdlg, int idc ) : TDBDataSet()
{
	SetTTable( GetVBXPIUnknown( hdlg, idc ) );
	TDBDataSet::SetPIT( table );
}

void TTable::AttachToControl( HWND hdlg, int idc )
{
	SetPIT( GetVBXPIUnknown( hdlg, idc ) );
}

void TTable::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, table );
}

TTable& TTable::operator=( PITTable p )
{
	TDBDataSet::operator=(p);
	ClearTTable();
	SetTTable( p );
	return *this;
}

TTable& TTable::operator=( const TTable& p )
{
	if (this != &p)
	{
		TDBDataSet::operator=(p);
		ClearTTable();
		SetTTable( p.table );
	}
	return *this;
}

int TTable::operator==( const TTable& p ) const
{
	if (this == &p)
		return true;
	if (table == p.table)
		return true;
	return false;
}

int TTable::operator!=( const TTable& p ) const
{
	return ! operator==(p);
}

TTable::~TTable()
{
	ClearTTable();
}

void TTable::SetPIT( PIUnknown p )
{
	ClearTTable();
	SetTTable( p );
	TDBDataSet::SetPIT( p );
}

int32 TTable::BatchMove( TDataSet& pt, TBatchMode m )
{
	if (table)
		return table->BatchMove( pt.GetPITDataSet(), m );
	return 0;
}

void TTable::AddIndex( const string& name, const string& fields, TIndexOptions options )
{
	if (table)
		table->AddIndex( AnyString(name).GetPITAnyString(), AnyString(fields).GetPITAnyString(), options );
}

void TTable::ApplyRange( void )
{
	if (table)
		table->ApplyRange();
}

void TTable::CancelRange( void )
{
	if (table)
		table->CancelRange();
}

void TTable::CreateTable( void )
{
	if (table)
		table->CreateTable();
}

void TTable::DeleteIndex( const string& n )
{
	if (table)
		table->DeleteIndex( AnyString(n).GetPITAnyString() );
}

void TTable::DeleteTable( void )
{
	if (table)
		table->DeleteTable();
}

void TTable::EditKey( void )
{
	if (table)
		table->EditKey();
}

void TTable::EditRangeEnd( void )
{
	if (table)
		table->EditRangeEnd();
}

void TTable::EditRangeStart( void )
{
	if (table)
		table->EditRangeStart();
}

void TTable::EmptyTable( void )
{
	if (table)
		table->EmptyTable();
}

bool TTable::FindKey( TVarRecs& values )
{
	if (table)
		return MakeBool( table->FindKey( values.Count, values.Variants ) );
	return false;
}

void TTable::FindNearest( TVarRecs& values )
{
	if (table)
		table->FindNearest( values.Count, values.Variants );
}

void TTable::GetIndexNames( TStrings& list )
{
	if (table)
		table->GetIndexNames( list.GetPITStrings() );
}

void TTable::GotoCurrent( TTable& pt )
{
	if (table)
		table->GotoCurrent( pt.table );
}

bool TTable::GotoKey( void )
{
	if (table)
		return MakeBool( table->GotoKey() );
	return false;
}

void TTable::GotoNearest( void )
{
	if (table)
		table->GotoNearest();
}

void TTable::LockTable( TLockType t )
{
	if (table)
		table->LockTable( t );
}

void TTable::RenameTable( const string& newname )
{
	if (table)
		table->RenameTable( AnyString(newname).GetPITAnyString() );
}

void TTable::SetKey( void )
{
	if (table)
		table->SetKey();
}

void TTable::SetRange( TVarRecs& startValues, TVarRecs& endValues )
{
	if (table)
		table->SetRange( startValues.Count, startValues.Variants, endValues.Count, endValues.Variants );
}

void TTable::SetRangeEnd( void )
{
	if (table)
		table->SetRangeEnd();
}

void TTable::SetRangeStart( void )
{
	if (table)
		table->SetRangeStart();
}

void TTable::UnlockTable( TLockType t )
{
	if (table)
		table->UnlockTable( t );
}

DEFINE_BDTO_OBJECTPROP_RO_FAST( TTable, TIndexDefs, PITIndexDefs, IndexDefs );
DEFINE_BDTO_PROP_RO( TTable, int, IndexFieldCount );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TTable, TField, PITField, IndexFields, int );
DEFINE_BDTO_PROP_RW( TTable, bool, KeyExclusive );
DEFINE_BDTO_PROP_RW( TTable, int, KeyFieldCount );

void TTable::GetIndexDefs( TIndexDefs& i )
{
	if (table)
	{
		PITIndexDefs pit = table->get_IndexDefs();
		if (pit)
		{
			i.SetPIT( pit );
			pit->Release();
		}
	}
}

void TTable::GetIndexFieldCount( int& c )
{
	if (table)
		c = table->get_IndexFieldCount();
}

void TTable::GetIndexFields( int i, TField& f )
{
	if (table)
	{
		PITField pit = table->get_IndexFields( i );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

void TTable::GetKeyExclusive( bool& k )
{
	if (table)
		k = MakeBool( table->get_KeyExclusive() );
}

void TTable::SetKeyExclusive( bool k )
{
	if (table)
		table->put_KeyExclusive( MakeVariantBool( k ) );
}

void TTable::GetKeyFieldCount( int& c )
{
	if (table)
		c = table->get_KeyFieldCount();
}

void TTable::SetKeyFieldCount( int c )
{
	if (table)
		table->put_KeyFieldCount( c );
}

DEFINE_BDTO_PROP_RW( TTable, bool, Exclusive );
DEFINE_BDTO_OBJECTPROP_RW( TTable, string, IndexFieldNames );
DEFINE_BDTO_OBJECTPROP_RW( TTable, string, IndexName );
DEFINE_BDTO_OBJECTPROP_RW( TTable, string, MasterFields );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TTable, TDataSource, PITDataSource, MasterSource );
DEFINE_BDTO_PROP_RW( TTable, bool, ReadOnly );
DEFINE_BDTO_OBJECTPROP_RW( TTable, string, TableName );
DEFINE_BDTO_PROP_RW( TTable, TTableType, TableType );
DEFINE_BDTO_PROP_RW( TTable, TUpdateMode, UpdateMode );

void TTable::GetExclusive( bool& e )
{
	if (table)
		e = MakeBool( table->get_Exclusive() );
}

void TTable::SetExclusive( bool e )
{
	if (table)
		table->put_Exclusive( MakeVariantBool( e ) );
}

void TTable::GetIndexFieldNames( string& s )
{
	if (table)
		AnyString( table->get_IndexFieldNames() ).GetString( s );
}

void TTable::SetIndexFieldNames( const string& n )
{
	if (table)
		table->put_IndexFieldNames( AnyString(n).GetPITAnyString() );
}

void TTable::GetIndexName( string& s )
{
	if (table)
		AnyString( table->get_IndexName() ).GetString( s );
}

void TTable::SetIndexName( const string& n )
{
	if (table)
		table->put_IndexName( AnyString(n).GetPITAnyString() );
}

void TTable::GetMasterFields( string& s )
{
	if (table)
		AnyString( table->get_MasterFields() ).GetString( s );
}

void TTable::SetMasterFields( const string& m )
{
	if (table)
		table->put_MasterFields( AnyString(m).GetPITAnyString() );
}

void TTable::GetMasterSource( TDataSource& d )
{
	if (table)
	{
		PITDataSource pit = table->get_MasterSource();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TTable::SetMasterSource( const TDataSource& source )
{
	if (table)
		table->put_MasterSource( source.GetPITDataSource() );
}

void TTable::GetReadOnly( bool& r )
{
	if (table)
		r = MakeBool( table->get_ReadOnly() );
}

void TTable::SetReadOnly( bool r )
{
	if (table)
		table->put_ReadOnly( MakeVariantBool( r ) );
}

void TTable::GetTableName( string& s )
{
	if (table)
		AnyString( table->get_TableName() ).GetString( s );
}

void TTable::SetTableName( const string& n )
{
	if (table)
		table->put_TableName( AnyString(n).GetPITAnyString() );
}

void TTable::GetTableType( TTableType& t )
{
	if (table)
		t = table->get_TableType();
}

void TTable::SetTableType( TTableType t )
{
	if (table)
		table->put_TableType( t );
}

void TTable::GetUpdateMode( TUpdateMode& u )
{
	if (table)
		u = table->get_UpdateMode();
}

void TTable::SetUpdateMode( TUpdateMode u )
{
	if (table)
		table->put_UpdateMode( u );
}
