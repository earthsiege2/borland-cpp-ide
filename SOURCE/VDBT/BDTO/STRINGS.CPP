//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// strings.cpp
// TStrings wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

static void _export STDAPICALLTYPE StringsNotifyEventCallback( int32 data, PITStrings strings )
{
	if (data)
	{
		PTStrings ezStrings = WrapPITStrings( strings );

		TStringsNotifySource* source = (TStringsNotifySource*) data;
		(*source)( *ezStrings );

		if (ezStrings)
			delete ezStrings;
	}
}

void TStrings::AttachOnChange( const TBdtEventSourceBase&, bool attach )
{
	if (strings)
	{
		AttachedOnChange = attach;
		if (attach)
			strings->AttachOnChange( StringsNotifyEventCallback, (int32) &OnChangeSource );
		else
			strings->DetachOnChange( StringsNotifyEventCallback, (int32) &OnChangeSource );
	}
}

void TStrings::AttachOnChanging( const TBdtEventSourceBase&, bool attach )
{
	if (strings)
	{
		AttachedOnChanging = attach;
		if (attach)
			strings->AttachOnChanging( StringsNotifyEventCallback, (int32) &OnChangingSource );
		else
			strings->DetachOnChanging( StringsNotifyEventCallback, (int32) &OnChangingSource );
	}
}

void TStrings::DetachEvents( void )
{
	if (strings)
	{
		if (AttachedOnChange)
			strings->DetachOnChange( StringsNotifyEventCallback, (int32) &OnChangeSource );
		if (AttachedOnChanging)
			strings->DetachOnChanging( StringsNotifyEventCallback, (int32) &OnChangingSource );
	}
}

void TStrings::ReattachEvents( void )
{
	if (strings)
	{
		if (AttachedOnChange)
			strings->AttachOnChange( StringsNotifyEventCallback, (int32) &OnChangeSource );
		if (AttachedOnChanging)
			strings->AttachOnChanging( StringsNotifyEventCallback, (int32) &OnChangingSource );
	}
}

//-----------------------------------------------------------------------------

void TStrings::SetTStrings( PIUnknown p )
{
	strings = 0;
	if (p)
		p->QueryInterface( IID_ITStrings, (void**) &strings );
	ReattachEvents();
}

void TStrings::ClearTStrings( void )
{
	DetachEvents();
	if (strings)
	{
		strings->Release();
		strings = 0;
	}
}

TStrings::TStrings( const string& p ) :
	TBDTObject(),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnChangingSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChanging ) ),
	AttachedOnChanging( false )
{
	strings = CreateITStrings();
	TBDTObject::SetPIT( strings );

	if (strings)
		strings->put_Text( AnyString(p).GetPITAnyString() );
}

TStrings::TStrings( void ) :
	TBDTObject(),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnChangingSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChanging ) ),
	AttachedOnChanging( false )
{
	strings = CreateITStrings();
	TBDTObject::SetPIT( strings );
}

TStrings::TStrings( PITStrings p ) :
	TBDTObject( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnChangingSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChanging ) ),
	AttachedOnChanging( false )
{
	SetTStrings( p );
}

TStrings::TStrings( const TStrings& p ) :
	TBDTObject( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnChangingSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChanging ) ),
	AttachedOnChanging( false )
{
	SetTStrings( p.strings );
}

TStrings::TStrings( PTStrings p ) :
	TBDTObject( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnChangingSource( SrcAttach_MFUNCTOR( *this, &TStrings::AttachOnChanging ) ),
	AttachedOnChanging( false )
{
	SetTStrings( p ? p->strings : 0 );
}

TStrings& TStrings::operator=( PITStrings p )
{
	TBDTObject::operator=(p);
	ClearTStrings();
	SetTStrings( p );
	return *this;
}

TStrings& TStrings::operator=( const TStrings& p )
{
	if (this != &p)
	{
		TBDTObject::operator=(p);
		ClearTStrings();
		SetTStrings( p.strings );
	}
	return *this;
}

int TStrings::operator==( const TStrings& p ) const
{
	if (this == &p)
		return true;
	if (strings == p.strings)
		return true;
	return false;
}

int TStrings::operator!=( const TStrings& p ) const
{
	return ! operator==(p);
}

TStrings::~TStrings()
{
	ClearTStrings();
}

void TStrings::SetPIT( PIUnknown p )
{
	ClearTStrings();
	SetTStrings( p );
	TBDTObject::SetPIT( p );
}

int TStrings::Add( const string& s )
{
	if (strings)
		return strings->Add( AnyString(s).GetPITAnyString() );
	return 0;
}

int TStrings::AddObject( const string& s, LPVOID object )
{
	if (strings)
		return strings->AddObject( AnyString(s).GetPITAnyString(), object );
	return 0;
}

void TStrings::AddStrings( TStrings& s )
{
	if (strings)
		strings->AddStrings( s.strings );
}

void TStrings::BeginUpdate( void )
{
	if (strings)
		strings->BeginUpdate();
}

void TStrings::Clear( void )
{
	if (strings)
		strings->Clear();
}

void TStrings::Delete( int index )
{
	if (strings)
		strings->Delete( index );
}

void TStrings::EndUpdate( void )
{
	if (strings)
		strings->EndUpdate();
}

bool TStrings::Equals( TStrings& s )
{
	if (strings)
		return MakeBool( strings->Equals( s.strings ) );
	return false;
}

void TStrings::Exchange( int index1, int index2 )
{
	if (strings)
		strings->Exchange( index1, index2 );
}

bool TStrings::Find( const string& s, int& index )
{
	if (strings)
		return MakeBool( strings->Find( AnyString(s).GetPITAnyString(), &index ) );
	return false;
}

int TStrings::IndexOf( const string& s )
{
	if (strings)
		return strings->IndexOf( AnyString(s).GetPITAnyString() );
	return 0;
}

int TStrings::IndexOfObject( LPVOID object )
{
	if (strings)
		return strings->IndexOfObject( object );
	return 0;
}

void TStrings::Insert( int index, const string& s )
{
	if (strings)
		strings->Insert( index, AnyString(s).GetPITAnyString() );
}

void TStrings::InsertObject( int index, const string& s, LPVOID object )
{
	if (strings)
		strings->InsertObject( index, AnyString(s).GetPITAnyString(), object );
}

void TStrings::LoadFromFile( const string& filename )
{
	if (strings)
		strings->LoadFromFile( AnyString(filename).GetPITAnyString() );
}

void TStrings::LoadFromStream( TMemoryStream& stream )
{
	if (strings)
		strings->LoadFromStream( stream.GetPITMemoryStream() );
}

void TStrings::Move( int curIndex, int newIndex )
{
	if (strings)
		strings->Move( curIndex, newIndex );
}

void TStrings::SaveToFile( const string& filename )
{
	if (strings)
		strings->SaveToFile( AnyString(filename).GetPITAnyString() );
}

void TStrings::SaveToStream( TMemoryStream& stream )
{
	if (strings)
		strings->SaveToStream( stream.GetPITMemoryStream() );
}

void TStrings::Sort( void )
{
	if (strings)
		strings->Sort();
}

DEFINE_BDTO_PROP_RO( TStrings, int, Count );
DEFINE_BDTO_ARRAYPROP_RW( TStrings, LPVOID, Objects, int );
DEFINE_BDTO_ARRAYOBJECTPROP_RW( TStrings, string, Values, string& );
DEFINE_BDTO_ARRAYOBJECTPROP_RW( TStrings, string, Strings, int );
DEFINE_BDTO_OBJECTPROP_RW( TStrings, string, Text );
DEFINE_BDTO_PROP_RW( TStrings, TDuplicates, Duplicates );
DEFINE_BDTO_PROP_RW( TStrings, bool, Sorted );

void TStrings::GetCount( int& c )
{
	if (strings)
		c = strings->get_Count();
}

void TStrings::GetObjects( int index, LPVOID& object )
{
	if (strings)
		object = strings->get_Objects( index );
}

void TStrings::SetObjects( int index, LPVOID object )
{
	if (strings)
		strings->put_Objects( index, object );
}

void TStrings::GetValues( string& name, string& s )
{
	if (strings)
		AnyString( strings->get_Values( AnyString(name).GetPITAnyString() ) ).GetString( s );
}

void TStrings::SetValues( string& name, const string& value )
{
	if (strings)
		strings->put_Values( AnyString(name).GetPITAnyString(), AnyString(value).GetPITAnyString() );
}

void TStrings::GetStrings( int index, string& s )
{
	if (strings)
		AnyString( strings->get_Strings( index ) ).GetString( s );
}

void TStrings::SetStrings( int index, const string& s )
{
	if (strings)
		strings->put_Strings( index, AnyString(s).GetPITAnyString() );
}


void TStrings::GetText( string& s )
{
	if (strings)
		AnyString( strings->get_Text() ).GetString( s );
}

void TStrings::SetText( const string& text )
{
	if (strings)
		strings->put_Text( AnyString(text).GetPITAnyString() );
}

void TStrings::GetDuplicates( TDuplicates& d )
{
	if (strings)
		d = strings->get_Duplicates();
}

void TStrings::SetDuplicates( TDuplicates d )
{
	if (strings)
		strings->put_Duplicates( d );
}

void TStrings::GetSorted( bool& s )
{
	if (strings)
		s = MakeBool( strings->get_Sorted() );
}

void TStrings::SetSorted( bool s )
{
	if (strings)
		strings->put_Sorted( MakeVariantBool( s ) );
}
