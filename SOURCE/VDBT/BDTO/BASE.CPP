//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// base.cpp
// TBDTObject and TBDTComponent wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TBDTObject::SetTBDTObject( PIUnknown p )
{
	bdtobject = 0;
	if (p)
		p->QueryInterface( IID_ITBDTObject, (void**) &bdtobject );
}

void TBDTObject::ClearTBDTObject( void )
{
	if (bdtobject)
	{
		bdtobject->Release();
		bdtobject = 0;
	}
}

TBDTObject::TBDTObject( void )
{
	SetTBDTObject( 0 );
}

TBDTObject::TBDTObject( PITBDTObject p )
{
	SetTBDTObject( p );
}

TBDTObject::TBDTObject( const TBDTObject& p )
{
	SetTBDTObject( p.bdtobject );
}

TBDTObject::TBDTObject( PTBDTObject p )
{
	SetTBDTObject( p ? p->bdtobject : 0 );
}

TBDTObject& TBDTObject::operator=( PITBDTObject p )
{
	ClearTBDTObject();
	SetTBDTObject( p );
	return *this;
}

TBDTObject& TBDTObject::operator=( const TBDTObject& p )
{
	if (this != &p)
	{
		ClearTBDTObject();
		SetTBDTObject( p.bdtobject );
	}
	return *this;
}

int TBDTObject::operator==( const TBDTObject& p ) const
{
	if (this == &p)
		return true;
	if (bdtobject == p.bdtobject)
		return true;
	return false;
}

int TBDTObject::operator!=( const TBDTObject& p ) const
{
	return ! operator==(p);
}

TBDTObject::~TBDTObject()
{
	ClearTBDTObject();
}

void TBDTObject::SetPIT( PIUnknown p )
{
	ClearTBDTObject();
	SetTBDTObject( p );
}

void TBDTObject::Detach( void )
{
	if (bdtobject)
		bdtobject->Detach();
}

void TBDTObject::Assign( TBDTObject& source )
{
	if (bdtobject)
		bdtobject->Assign( source.bdtobject );
}

//-----------------------------------------------------------------------------

void TBDTComponent::SetTBDTComponent( PIUnknown p )
{
	bdtcomponent = 0;
	if (p)
		p->QueryInterface( IID_ITBDTComponent, (void**) &bdtcomponent );
}

void TBDTComponent::ClearTBDTComponent( void )
{
	if (bdtcomponent)
	{
		bdtcomponent->Release();
		bdtcomponent = 0;
	}
}

TBDTComponent::TBDTComponent( void ) : TBDTObject()
{
	SetTBDTComponent( 0 );
}

TBDTComponent::TBDTComponent( PITBDTComponent p ) : TBDTObject( p )
{
	SetTBDTComponent( p );
}

TBDTComponent::TBDTComponent( const TBDTComponent& p ) : TBDTObject( p )
{
	SetTBDTComponent( p.bdtcomponent );
}

TBDTComponent::TBDTComponent( PTBDTComponent p ) : TBDTObject( p )
{
	SetTBDTComponent( p ? p->bdtcomponent : 0 );
}

TBDTComponent& TBDTComponent::operator=( PITBDTComponent p )
{
	TBDTObject::operator=(p);
	ClearTBDTComponent();
	SetTBDTComponent( p );
	return *this;
}

TBDTComponent& TBDTComponent::operator=( const TBDTComponent& p )
{
	if (this != &p)
	{
		TBDTObject::operator=(p);
		ClearTBDTComponent();
		SetTBDTComponent( p.bdtcomponent );
	}
	return *this;
}

int TBDTComponent::operator==( const TBDTComponent& p ) const
{
	if (this == &p)
		return true;
	if (bdtcomponent == p.bdtcomponent)
		return true;
	return false;
}

int TBDTComponent::operator!=( const TBDTComponent& p ) const
{
	return ! operator==(p);
}

TBDTComponent::~TBDTComponent()
{
	ClearTBDTComponent();
}

void TBDTComponent::SetPIT( PIUnknown p )
{
	ClearTBDTComponent();
	SetTBDTComponent( p );
	TBDTObject::SetPIT( p );
}

DEFINE_BDTO_OBJECTPROP_RW( TBDTComponent, string, Name );

void TBDTComponent::GetName( string& s )
{
	if (bdtcomponent)
		AnyString( bdtcomponent->get_Name() ).GetString( s );
}

void TBDTComponent::SetName( string& n )
{
	if (bdtcomponent)
		bdtcomponent->put_Name( AnyString(n).GetPITAnyString() );
}

