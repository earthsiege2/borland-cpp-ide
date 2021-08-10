//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// indexdef.cpp
// TIndexDef and TIndexDefs wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TIndexDef::SetTIndexDef( PIUnknown p )
{
	indexdef = 0;
	if (p)
		p->QueryInterface( IID_ITIndexDef, (void**) &indexdef );
}

void TIndexDef::ClearTIndexDef( void )
{
	if (indexdef)
	{
		indexdef->Release();
		indexdef = 0;
	}
}

TIndexDef::TIndexDef( PTIndexDefs Owner, const string& Name, const string& Fields, TIndexOptions Options )
{
	indexdef = CreateITIndexDef( Owner ? Owner->GetPITIndexDefs() : 0, Name.c_str(), Fields.c_str(), Options );
}

TIndexDef::TIndexDef( void )
{
	indexdef = CreateITIndexDef( 0, "", "", (TIndexOptions) 0 );
}

TIndexDef::TIndexDef( PITIndexDef p )
{
	SetTIndexDef( p );
}

TIndexDef::TIndexDef( const TIndexDef& p )
{
	SetTIndexDef( p.indexdef );
}

TIndexDef::TIndexDef( PTIndexDef p )
{
	SetTIndexDef( p ? p->indexdef : 0 );
}

TIndexDef& TIndexDef::operator=( PITIndexDef p )
{
	ClearTIndexDef();
	SetTIndexDef( p );
	return *this;
}

TIndexDef& TIndexDef::operator=( const TIndexDef& p )
{
	if (this != &p)
	{
		ClearTIndexDef();
		SetTIndexDef( p.indexdef );
	}
	return *this;
}

int TIndexDef::operator==( const TIndexDef& p ) const
{
	if (this == &p)
		return true;
	if (indexdef == p.indexdef)
		return true;
	return false;
}

int TIndexDef::operator!=( const TIndexDef& p ) const
{
	return ! operator==(p);
}

TIndexDef::~TIndexDef()
{
	ClearTIndexDef();
}

void TIndexDef::SetPIT( PIUnknown p )
{
	ClearTIndexDef();
	SetTIndexDef( p );
}

void TIndexDef::Detach( void )
{
	if (indexdef)
		indexdef->Detach();
}

DEFINE_BDTO_OBJECTPROP_RO( TIndexDef, string, Expression );
DEFINE_BDTO_OBJECTPROP_RO( TIndexDef, string, Fields );
DEFINE_BDTO_OBJECTPROP_RO( TIndexDef, string, Name );
DEFINE_BDTO_PROP_RO( TIndexDef, TIndexOptions, Options );

void TIndexDef::GetExpression( string& s )
{
	if (indexdef)
		AnyString( indexdef->get_Expression() ).GetString( s );
}

void TIndexDef::GetFields( string& s )
{
	if (indexdef)
		AnyString( indexdef->get_Fields() ).GetString( s );
}

void TIndexDef::GetName( string& s )
{
	if (indexdef)
		AnyString( indexdef->get_Name() ).GetString( s );
}

void TIndexDef::GetOptions( TIndexOptions& o )
{
	if (indexdef)
		o = indexdef->get_Options();
}

//-----------------------------------------------------------------------------

void TIndexDefs::SetTIndexDefs( PIUnknown p )
{
	indexdefs = 0;
	if (p)
		p->QueryInterface( IID_ITIndexDefs, (void**) &indexdefs );
}

void TIndexDefs::ClearTIndexDefs( void )
{
	if (indexdefs)
	{
		indexdefs->Release();
		indexdefs = 0;
	}
}

TIndexDefs::TIndexDefs( TTable& Table )
{
	indexdefs = CreateITIndexDefs( Table.GetPITTable() );
}

TIndexDefs::TIndexDefs( void )
{
	indexdefs = CreateITIndexDefs( 0 );
}

TIndexDefs::TIndexDefs( PITIndexDefs p )
{
	SetTIndexDefs( p );
}

TIndexDefs::TIndexDefs( const TIndexDefs& p )
{
	SetTIndexDefs( p.indexdefs );
}

TIndexDefs::TIndexDefs( PTIndexDefs p )
{
	SetTIndexDefs( p ? p->indexdefs : 0 );
}

TIndexDefs& TIndexDefs::operator=( PITIndexDefs p )
{
	ClearTIndexDefs();
	SetTIndexDefs( p );
	return *this;
}

TIndexDefs& TIndexDefs::operator=( const TIndexDefs& p )
{
	if (this != &p)
	{
		ClearTIndexDefs();
		SetTIndexDefs( p.indexdefs );
	}
	return *this;
}

int TIndexDefs::operator==( const TIndexDefs& p ) const
{
	if (this == &p)
		return true;
	if (indexdefs == p.indexdefs)
		return true;
	return false;
}

int TIndexDefs::operator!=( const TIndexDefs& p ) const
{
	return ! operator==(p);
}

TIndexDefs::~TIndexDefs()
{
	ClearTIndexDefs();
}

void TIndexDefs::SetPIT( PIUnknown p )
{
	ClearTIndexDefs();
	SetTIndexDefs( p );
}

void TIndexDefs::Detach( void )
{
	if (indexdefs)
		indexdefs->Detach();
}

void TIndexDefs::Add( const string& name, const string& fields, TIndexOptions options )
{
	if (indexdefs)
		indexdefs->Add( AnyString(name).GetPITAnyString(), AnyString(fields).GetPITAnyString(), options );
}

void TIndexDefs::Assign( TIndexDefs& i )
{
	if (indexdefs)
		indexdefs->Assign( i.indexdefs );
}

void TIndexDefs::Clear( void )
{
	if (indexdefs)
		indexdefs->Clear();
}

DEFINE_BDTO_OBJECTMETHOD1( TIndexDefs, TIndexDef, PITIndexDef, FindIndexForFields, string& );

void TIndexDefs::CallFindIndexForFields( string& fields, TIndexDef& i )
{
	if (indexdefs)
	{
		PITIndexDef pit = indexdefs->FindIndexForFields( AnyString(fields).GetPITAnyString() );
		if (pit)
		{
			i.SetPIT( pit );
			pit->Release();
		}
	}
}

int TIndexDefs::IndexOf( const string& n )
{
	if (indexdefs)
		return indexdefs->IndexOf( AnyString(n).GetPITAnyString() );
	return 0;
}

void TIndexDefs::Update( void )
{
	if (indexdefs)
		indexdefs->Update();
}

DEFINE_BDTO_PROP_RO( TIndexDefs, int, Count );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TIndexDefs, TIndexDef, PITIndexDef, Items, int );

void TIndexDefs::GetCount( int& c )
{
	if (indexdefs)
		c = indexdefs->get_Count();
}

void TIndexDefs::GetItems( int index, TIndexDef& i )
{
	if (indexdefs)
	{
		PITIndexDef pit = indexdefs->get_Items( index );
		if (pit)
		{
			i.SetPIT( pit );
			pit->Release();
		}
	}
}
