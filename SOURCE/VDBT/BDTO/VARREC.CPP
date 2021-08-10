//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// varrec.cpp
// TVarRec and TVarRecs wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

TVarRec::TVarRec( void )
{
	Allocate();
}

TVarRec::TVarRec( LPVARIANT p )
{
	Allocate();
	if (lpvar && p)
		VariantCopy( lpvar, p );
}

TVarRec::TVarRec( const TVarRec& p )
{
	Allocate();
	if (lpvar && p.lpvar)
		VariantCopy( lpvar, p.lpvar );
}

TVarRec::TVarRec( PTVarRec p )
{
	Allocate();
	if (lpvar && p && p->lpvar)
		VariantCopy( lpvar, p->lpvar );
}

TVarRec::TVarRec( bool b )
{
	Allocate();
	SetAsBoolean( b );
}

#if 0
TVarRec::TVarRec( DATE d )
{
	Allocate();
	SetAsDateTime( d );
}
#endif

TVarRec::TVarRec( double d )
{
	Allocate();
	SetAsFloat( d );
}

TVarRec::TVarRec( float f )
{
	Allocate();
	double d = f;
	SetAsFloat( d );
}

TVarRec::TVarRec( int32 l )
{
	Allocate();
	SetAsInteger( l );
}

TVarRec::TVarRec( int i )
{
	Allocate();
	int32 l = i;
	SetAsInteger( l );
}

TVarRec::TVarRec( int16 s )
{
	Allocate();
	int32 l = s;
	SetAsInteger( l );
}

TVarRec::TVarRec( string& s )
{
	Allocate();
	SetAsString( s );
}

TVarRec::TVarRec( LPSTR s )
{
	Allocate();
	SetAsString( string( s ) );
}

TVarRec& TVarRec::operator=( const TVarRec& p )
{
	if (this != &p)
	{
		if (lpvar)
		{
			if (allocated)
			{
				VariantClear( lpvar );
				delete lpvar;
				allocated = false;
			}
			lpvar = 0;
		}

		Allocate();
		if (lpvar && p.lpvar)
			VariantCopy( lpvar, p.lpvar );
	}

	return *this;
}

TVarRec::~TVarRec()
{
	if (lpvar)
	{
		if (allocated)
		{
			VariantClear( lpvar );
			delete lpvar;
			allocated = false;
		}
		lpvar = 0;
	}
}

void TVarRec::SetVariant( LPVARIANT p )
{
	if (lpvar)
	{
		if (allocated)
		{
			VariantClear( lpvar );
			delete lpvar;
			allocated = false;
		}
		lpvar = 0;
	}

	allocated = false;
	if (p)
		lpvar = p;
	else
		Allocate();
}

void TVarRec::Allocate( void )
{
	allocated = true;
	lpvar = new VARIANT;
	if (lpvar)
		VariantInit( lpvar );
}

DEFINE_BDTO_PROP_RW( TVarRec, bool, AsBoolean );
DEFINE_BDTO_PROP_RW( TVarRec, DATE, AsDateTime );
DEFINE_BDTO_PROP_RW( TVarRec, double, AsFloat );
DEFINE_BDTO_PROP_RW( TVarRec, int32, AsInteger );
DEFINE_BDTO_OBJECTPROP_RW( TVarRec, string, AsString );

void TVarRec::GetAsBoolean( bool& b )
{
	if (lpvar)
	{
		if (V_VT(lpvar) == VT_BOOL ||
			 VariantChangeType( lpvar, lpvar, 0, VT_BOOL ) == NOERROR )
		{
			b = MakeBool( V_BOOL(lpvar) );
		}
	}
}

void TVarRec::SetAsBoolean( bool b )
{
	if (lpvar)
	{
		VariantClear( lpvar );
		V_VT(lpvar) = VT_BOOL;
		V_BOOL(lpvar) = MakeVariantBool( b );
	}
}

void TVarRec::GetAsDateTime( DATE& d )
{
	if (lpvar)
	{
		if (V_VT(lpvar) == VT_DATE ||
			 VariantChangeType( lpvar, lpvar, 0, VT_DATE ) == NOERROR )
		{
			d = V_DATE(lpvar);
		}
	}
}

void TVarRec::SetAsDateTime( DATE d )
{
	if (lpvar)
	{
		VariantClear( lpvar );
		V_VT(lpvar) = VT_DATE;
		V_DATE(lpvar) = d;
	}
}

void TVarRec::GetAsFloat( double& d )
{
	if (lpvar)
	{
		if (V_VT(lpvar) == VT_R8 ||
			 VariantChangeType( lpvar, lpvar, 0, VT_R8 ) == NOERROR )
		{
			d = V_R8(lpvar);
		}
	}
}

void TVarRec::SetAsFloat( double d )
{
	if (lpvar)
	{
		VariantClear( lpvar );
		V_VT(lpvar) = VT_R8;
		V_R8(lpvar) = d;
	}
}

void TVarRec::GetAsInteger( int32& i )
{
	if (lpvar)
	{
		if (V_VT(lpvar) == VT_I4 ||
			 VariantChangeType( lpvar, lpvar, 0, VT_I4 ) == NOERROR )
		{
			i = V_I4(lpvar);
		}
	}
}

void TVarRec::SetAsInteger( int32 i )
{
	if (lpvar)
	{
		VariantClear( lpvar );
		V_VT(lpvar) = VT_I4;
		V_I4(lpvar) = i;
	}
}

void TVarRec::GetAsString( string& s )
{
	if (lpvar)
	{
		if (V_VT(lpvar) == VT_BSTR ||
			 VariantChangeType( lpvar, lpvar, 0, VT_BSTR ) == NOERROR )
		{
#ifdef __FLAT__
			int max = SysStringLen( V_BSTR(lpvar) )+1;
			LPSTR buf = new char [max];
			WideCharToMultiByte( CP_ACP, 0, V_BSTR(lpvar), -1, buf, max, 0, 0 );
			s = buf;
			delete [] buf;
#else
			s = V_BSTR(lpvar);
#endif
		}
	}
}

void TVarRec::SetAsString( string& s )
{
	if (lpvar)
	{
		VariantClear( lpvar );
		V_VT(lpvar) = VT_BSTR;
#ifdef __FLAT__
		V_BSTR( lpvar ) = SysAllocStringLen( 0, s.length()+1 );
		MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, s.c_str(), -1, V_BSTR( lpvar ), s.length()+1 );
#else
		V_BSTR( lpvar ) = SysAllocString( s.c_str() );
#endif
	}
}

TVarRec::operator bool()
{
	bool v;
	GetAsBoolean( v );
	return v;
}

TVarRec& TVarRec::operator=( bool v )
{
	SetAsBoolean( v );
	return *this;
}

#if 0
TVarRec::operator DATE()
{
	DATE v;
	GetAsDateTime( v );
	return v;
}

TVarRec& TVarRec::operator=( DATE v )
{
	SetAsDateTime( v );
	return *this;
}
#endif

TVarRec::operator double()
{
	double v;
	GetAsFloat( v );
	return v;
}

TVarRec& TVarRec::operator=( double v )
{
	SetAsFloat( v );
	return *this;
}

TVarRec::operator int32()
{
	int32 v;
	GetAsInteger( v );
	return v;
}

TVarRec& TVarRec::operator=( int32 v )
{
	SetAsInteger( v );
	return *this;
}

TVarRec::operator string()
{
	string v;
	GetAsString( v );
	return v;
}

TVarRec& TVarRec::operator=( string& v )
{
	SetAsString( v );
	return *this;
}

//-----------------------------------------------------------------------------

TVarRecs::TVarRecs( int c, LPVARIANT p )
{
	if (p && c)
	{
		count = c;
		lpvar = new VARIANT [count];
		int i;
		for (i = 0; i < count; i++)
		{
			VariantInit( lpvar+i );
			VariantCopy( lpvar+i, p+i );
		}
	}
	else
	{
		lpvar = 0;
		count = 0;
	}
}

TVarRecs::TVarRecs( const TVarRecs& p )
{
	if (p.lpvar && p.count)
	{
		count = p.count;
		lpvar = new VARIANT [count];
		int i;
		for (i = 0; i < count; i++)
		{
			VariantInit( lpvar+i );
			VariantCopy( lpvar+i, p.lpvar+i );
		}
	}
	else
	{
		lpvar = 0;
		count = 0;
	}
}

TVarRecs::TVarRecs( PTVarRecs p )
{
	if (p && p->lpvar && p->count)
	{
		count = p->count;
		lpvar = new VARIANT [count];
		int i;
		for (i = 0; i < count; i++)
		{
			VariantInit( lpvar+i );
			VariantCopy( lpvar+i, p->lpvar+i );
		}
	}
	else
	{
		lpvar = 0;
		count = 0;
	}
}

TVarRecs& TVarRecs::operator=( TVarRecs& p )
{
	if (this != &p)
	{
		if (lpvar)
		{
			int i;
			for (i = 0; i < count; i++)
				VariantClear( lpvar+i );
			delete [] lpvar;
		}

		if (p.lpvar && p.count)
		{
			count = p.count;
			lpvar = new VARIANT [count];
			int i;
			for (i = 0; i < count; i++)
			{
				VariantInit( lpvar+i );
				VariantCopy( lpvar+i, p.lpvar+i );
			}
		}
		else
		{
			lpvar = 0;
			count = 0;
		}
	}

	return *this;
}

TVarRecs::~TVarRecs()
{
	if (lpvar)
	{
		int i;
		for (i = 0; i < count; i++)
			VariantClear( lpvar+i );
		delete [] lpvar;
	}
}

void TVarRecs::Add( void )
{
	int count2 = count+1;
	LPVARIANT lpvar2 = new VARIANT [count2];
	if (lpvar2)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			VariantInit( lpvar2+i );
			VariantCopy( lpvar2+i, lpvar+i );
		}

		VariantInit( lpvar2+count );

		if (lpvar)
			delete [] lpvar;
		lpvar = lpvar2;
		count = count2;
	}
}

void TVarRecs::Add( TVarRec& v )
{
	int count2 = count+1;
	LPVARIANT lpvar2 = new VARIANT [count2];
	if (lpvar2)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			VariantInit( lpvar2+i );
			VariantCopy( lpvar2+i, lpvar+i );
		}

		VariantInit( lpvar2+count );
		LPVARIANT var = v.GetVariant();
		if (var)
			VariantCopy( lpvar2+count, var );

		if (lpvar)
			delete [] lpvar;
		lpvar = lpvar2;
		count = count2;
	}
}

void TVarRecs::Clear( void )
{
	if (lpvar)
	{
		int i;
		for (i = 0; i < count; i++)
			VariantClear( lpvar+i );
		delete [] lpvar;
		lpvar = 0;
	}
	count = 0;
}

DEFINE_BDTO_PROP_RO( TVarRecs, int, Count );
DEFINE_BDTO_PROP_RO( TVarRecs, LPVARIANT, Variants );
DEFINE_BDTO_ARRAYOBJECTPROP_RO( TVarRecs, TVarRec, Items, int );

void TVarRecs::GetCount( int& c )
{
	c = count;
}

void TVarRecs::GetVariants( LPVARIANT& v )
{
	v = lpvar;
}

void TVarRecs::GetItems( int i, TVarRec& v )
{
	if (lpvar && i < count)
		v.SetVariant( lpvar+i );
}
