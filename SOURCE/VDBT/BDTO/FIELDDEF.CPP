//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// fielddef.cpp
// TFieldDef and TFieldDefs wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TFieldDef::SetTFieldDef( PIUnknown p )
{
	fielddef = 0;
	if (p)
		p->QueryInterface( IID_ITFieldDef, (void**) &fielddef );
}

void TFieldDef::ClearTFieldDef( void )
{
	if (fielddef)
	{
		fielddef->Release();
		fielddef = 0;
	}
}

TFieldDef::TFieldDef( PTFieldDefs Owner, const string& Name, TFieldType DataType, uint16 Size, bool Required, int FieldNo )
{
	fielddef = CreateITFieldDef( Owner ? Owner->GetPITFieldDefs() : 0, Name.c_str(), DataType, Size, MakeVariantBool( Required ), FieldNo );
}

TFieldDef::TFieldDef( void )
{
	fielddef = CreateITFieldDef( 0, "", ftUnknown, 0, false, 0 );
}

TFieldDef::TFieldDef( PITFieldDef p )
{
	SetTFieldDef( p );
}

TFieldDef::TFieldDef( const TFieldDef& p )
{
	SetTFieldDef( p.fielddef );
}

TFieldDef::TFieldDef( PTFieldDef p )
{
	SetTFieldDef( p ? p->fielddef : 0 );
}

TFieldDef& TFieldDef::operator=( PITFieldDef p )
{
	ClearTFieldDef();
	SetTFieldDef( p );
	return *this;
}

TFieldDef& TFieldDef::operator=( const TFieldDef& p )
{
	if (this != &p)
	{
		ClearTFieldDef();
		SetTFieldDef( p.fielddef );
	}
	return *this;
}

int TFieldDef::operator==( const TFieldDef& p ) const
{
	if (this == &p)
		return true;
	if (fielddef == p.fielddef)
		return true;
	return false;
}

int TFieldDef::operator!=( const TFieldDef& p ) const
{
	return ! operator==(p);
}

TFieldDef::~TFieldDef()
{
	ClearTFieldDef();
}

void TFieldDef::SetPIT( PIUnknown p )
{
	ClearTFieldDef();
	SetTFieldDef( p );
}

void TFieldDef::Detach( void )
{
	if (fielddef)
		fielddef->Detach();
}

DEFINE_BDTO_OBJECTMETHOD1( TFieldDef, TField, PITField, CreateField, TBDTComponent& );

void TFieldDef::CallCreateField( TBDTComponent& owner, TField& f )
{
	if (fielddef)
	{
		PITField pit = fielddef->CreateField( owner.GetPITBDTComponent() );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

DEFINE_BDTO_PROP_RO( TFieldDef, TFieldType, DataType );
DEFINE_BDTO_PROP_RO( TFieldDef, int, FieldNo );
DEFINE_BDTO_OBJECTPROP_RO( TFieldDef, string, Name );
DEFINE_BDTO_PROP_RO( TFieldDef, bool, Required );
DEFINE_BDTO_PROP_RO( TFieldDef, uint16, Size );

void TFieldDef::GetDataType( TFieldType& t )
{
	if (fielddef)
		t = fielddef->get_DataType();
	else
		t = ftUnknown;
}

void TFieldDef::GetFieldNo( int& n )
{
	if (fielddef)
		n = fielddef->get_FieldNo();
	else
		n = 0;
}

void TFieldDef::GetName( string& s )
{
	if (fielddef)
		AnyString( fielddef->get_Name() ).GetString( s );
}

void TFieldDef::GetRequired( bool& r )
{
	if (fielddef)
		r = MakeBool( fielddef->get_Required() );
	else
		r = false;
}

void TFieldDef::GetSize( uint16& s )
{
	if (fielddef)
		s = fielddef->get_Size();
	else
		s = 0;
}

//-----------------------------------------------------------------------------

void TFieldDefs::SetTFieldDefs( PIUnknown p )
{
	fielddefs = 0;
	if (p)
		p->QueryInterface( IID_ITFieldDefs, (void**) &fielddefs );
}

void TFieldDefs::ClearTFieldDefs( void )
{
	if (fielddefs)
	{
		fielddefs->Release();
		fielddefs = 0;
	}
}

TFieldDefs::TFieldDefs( TDataSet& DataSet )
{
	fielddefs = CreateITFieldDefs( DataSet.GetPITDataSet() );
}

TFieldDefs::TFieldDefs( void )
{
	fielddefs = CreateITFieldDefs( 0 );
}

TFieldDefs::TFieldDefs( PITFieldDefs p )
{
	SetTFieldDefs( p );
}

TFieldDefs::TFieldDefs( const TFieldDefs& p )
{
	SetTFieldDefs( p.fielddefs );
}

TFieldDefs::TFieldDefs( PTFieldDefs p )
{
	SetTFieldDefs( p ? p->fielddefs : 0 );
}

TFieldDefs& TFieldDefs::operator=( PITFieldDefs p )
{
	ClearTFieldDefs();
	SetTFieldDefs( p );
	return *this;
}

TFieldDefs& TFieldDefs::operator=( const TFieldDefs& p )
{
	if (this != &p)
	{
		ClearTFieldDefs();
		SetTFieldDefs( p.fielddefs );
	}
	return *this;
}

int TFieldDefs::operator==( const TFieldDefs& p ) const
{
	if (this == &p)
		return true;
	if (fielddefs == p.fielddefs)
		return true;
	return false;
}

int TFieldDefs::operator!=( const TFieldDefs& p ) const
{
	return ! operator==(p);
}

TFieldDefs::~TFieldDefs()
{
	ClearTFieldDefs();
}

void TFieldDefs::SetPIT( PIUnknown p )
{
	ClearTFieldDefs();
	SetTFieldDefs( p );
}

void TFieldDefs::Detach( void )
{
	if (fielddefs)
		fielddefs->Detach();
}

void TFieldDefs::Add( const string& Name, TFieldType Type, uint16 Size, bool Required )
{
	if (fielddefs)
		fielddefs->Add( AnyString(Name).GetPITAnyString(), Type, Size, MakeVariantBool( Required ) );
}

void TFieldDefs::AddFieldDesc( pFLDDesc FieldDesc, bool Required, uint16 FieldNo )
{
	if (fielddefs)
		fielddefs->AddFieldDesc( FieldDesc, MakeVariantBool( Required ), FieldNo );
}

void TFieldDefs::Assign( TFieldDefs& f )
{
	if (fielddefs)
		fielddefs->Assign( f.fielddefs );
}

void TFieldDefs::Clear( void )
{
	if (fielddefs)
		fielddefs->Clear();
}

DEFINE_BDTO_OBJECTMETHOD1( TFieldDefs, TFieldDef, PITFieldDef, Find, string& );

void TFieldDefs::CallFind( string& n, TFieldDef& f )
{
	if (fielddefs)
	{
		PITFieldDef pit = fielddefs->Find( AnyString(n).GetPITAnyString() );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

int TFieldDefs::IndexOf( const string& n )
{
	if (fielddefs)
		return fielddefs->IndexOf( AnyString(n).GetPITAnyString() );
	return 0;
}

void TFieldDefs::Update( void )
{
	if (fielddefs)
		fielddefs->Update();
}

DEFINE_BDTO_PROP_RO( TFieldDefs, int, Count );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TFieldDefs, TFieldDef, PITFieldDef, Items, int );

void TFieldDefs::GetCount( int& c )
{
	if (fielddefs)
		c = fielddefs->get_Count();
	else
		c = 0;
}

void TFieldDefs::GetItems( int i, TFieldDef& f )
{
	if (fielddefs)
	{
		PITFieldDef pit = fielddefs->get_Items( i );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}
