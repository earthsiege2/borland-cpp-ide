//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// param.cpp
// TParam and TParams wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

void TParam::SetTParam( PIUnknown p )
{
	param = 0;
	if (p)
		p->QueryInterface( IID_ITParam, (void**) &param );
}

void TParam::ClearTParam( void )
{
	if (param)
	{
		param->Release();
		param = 0;
	}
}

TParam::TParam( PTParams AParamList, TParamType AParamType )
{
	param = CreateITParam( AParamList ? AParamList->GetPITParams() : 0, AParamType );
}

TParam::TParam( void )
{
	param = CreateITParam( 0, ptUnknown );
}

TParam::TParam( PITParam p )
{
	SetTParam( p );
}

TParam::TParam( const TParam& p )
{
	SetTParam( p.param );
}

TParam::TParam( PTParam p )
{
	SetTParam( p ? p->param : 0 );
}

TParam& TParam::operator=( PITParam p )
{
	ClearTParam();
	SetTParam( p );
	return *this;
}

TParam& TParam::operator=( const TParam& p )
{
	if (this != &p)
	{
		ClearTParam();
		SetTParam( p.param );
	}
	return *this;
}

int TParam::operator==( const TParam& p ) const
{
	if (this == &p)
		return true;
	if (param == p.param)
		return true;
	return false;
}

int TParam::operator!=( const TParam& p ) const
{
	return ! operator==(p);
}

TParam::~TParam()
{
	ClearTParam();
}

void TParam::SetPIT( PIUnknown p )
{
	ClearTParam();
	SetTParam( p );
}

void TParam::Detach( void )
{
	if (param)
		param->Detach();
}

void TParam::Assign( TParam& p )
{
	if (param)
		param->Assign( p.GetPITParam() );
}

void TParam::AssignField( TField& f )
{
	if (param)
		param->AssignField( f.GetPITField() );
}

void TParam::GetData( LPVOID buffer )
{
	if (param)
		param->GetData( buffer );
}

uint16 TParam::GetDataSize( void )
{
	if (param)
		return param->GetDataSize();
	return 0;
}

void TParam::SetData( LPVOID buffer )
{
	if (param)
		param->SetData( buffer );
}

void TParam::Clear( void )
{
	if (param)
		param->Clear();
}

DEFINE_BDTO_OBJECTPROP_RW( TParam, string, Name );
DEFINE_BDTO_PROP_RW( TParam, TFieldType, DataType );
DEFINE_BDTO_PROP_RW( TParam, bool, AsBoolean );
DEFINE_BDTO_PROP_RW( TParam, double, AsFloat );
DEFINE_BDTO_PROP_RW( TParam, int32, AsInteger );
DEFINE_BDTO_OBJECTPROP_RW( TParam, string, AsString );
DEFINE_BDTO_PROP_RW( TParam, DATE, AsDate );
DEFINE_BDTO_PROP_RW( TParam, DATE, AsTime );
DEFINE_BDTO_PROP_RW( TParam, DATE, AsDateTime );
DEFINE_BDTO_PROP_RW( TParam, int32, AsSmallInt );
DEFINE_BDTO_PROP_RW( TParam, int32, AsWord );
DEFINE_BDTO_PROP_RW( TParam, double, AsCurrency );
DEFINE_BDTO_PROP_RW( TParam, double, AsBCD );
DEFINE_BDTO_PROP_RO( TParam, bool, IsNull );
DEFINE_BDTO_PROP_RW( TParam, TParamType, ParamType );
DEFINE_BDTO_PROP_RW( TParam, bool, Bound );
DEFINE_BDTO_OBJECTPROP_RW( TParam, string, Text );

void TParam::GetName( string& s )
{
	if (param)
		AnyString( param->get_Name() ).GetString( s );
}

void TParam::SetName( string& n )
{
	if (param)
		param->put_Name( AnyString(n).GetPITAnyString() );
}

void TParam::GetDataType( TFieldType& t )
{
	if (param)
		t = param->get_DataType();
}

void TParam::SetDataType( TFieldType t )
{
	if (param)
		param->put_DataType( t );
}

void TParam::GetAsBoolean( bool& b )
{
	if (param)
		b = MakeBool( param->get_AsBoolean() );
}

void TParam::SetAsBoolean( bool b )
{
	if (param)
		param->put_AsBoolean( MakeVariantBool( b ) );
}

void TParam::GetAsFloat( double& f )
{
	if (param)
		f = param->get_AsFloat();
}

void TParam::SetAsFloat( double f )
{
	if (param)
		param->put_AsFloat( f );
}

void TParam::GetAsInteger( int32& i )
{
	if (param)
		i = param->get_AsInteger();
}

void TParam::SetAsInteger( int32 i )
{
	if (param)
		param->put_AsInteger( i );
}

void TParam::GetAsString( string& s )
{
	if (param)
		AnyString( param->get_AsString() ).GetString( s );
}

void TParam::SetAsString( string& s )
{
	if (param)
		param->put_AsString( AnyString(s).GetPITAnyString() );
}

void TParam::GetAsDate( DATE& d )
{
	if (param)
		d = param->get_AsDate();
}

void TParam::SetAsDate( DATE d )
{
	if (param)
		param->put_AsDate( d );
}

void TParam::GetAsTime( DATE& t )
{
	if (param)
		t = param->get_AsTime();
}

void TParam::SetAsTime( DATE t )
{
	if (param)
		param->put_AsTime( t );
}

void TParam::GetAsDateTime( DATE& dt )
{
	if (param)
		dt = param->get_AsDateTime();
}

void TParam::SetAsDateTime( DATE dt )
{
	if (param)
		param->put_AsDateTime( dt );
}

void TParam::GetAsSmallInt( int32& si )
{
	if (param)
		si = param->get_AsSmallInt();
}

void TParam::SetAsSmallInt( int32 si )
{
	if (param)
		param->put_AsSmallInt( si );
}

void TParam::GetAsWord( int32& w )
{
	if (param)
		w = param->get_AsWord();
}

void TParam::SetAsWord( int32 w )
{
	if (param)
		param->put_AsWord( w );
}

void TParam::GetAsCurrency( double& c )
{
	if (param)
		c = param->get_AsCurrency();
}

void TParam::SetAsCurrency( double c )
{
	if (param)
		param->put_AsCurrency( c );
}

void TParam::GetAsBCD( double& b )
{
	if (param)
		b = param->get_AsBCD();
}

void TParam::SetAsBCD( double b )
{
	if (param)
		param->put_AsBCD( b );
}

void TParam::GetIsNull( bool& i )
{
	if (param)
		i = MakeBool( param->get_IsNull() );
}

void TParam::GetParamType( TParamType& t )
{
	if (param)
		t = param->get_ParamType();
}

void TParam::SetParamType( TParamType t )
{
	if (param)
		param->put_ParamType( t );
}

void TParam::GetBound( bool& b )
{
	if (param)
		b = MakeBool( param->get_Bound() );
}

void TParam::SetBound( bool b )
{
	if (param)
		param->put_Bound( MakeVariantBool( b ) );
}

void TParam::GetText( string& t )
{
	if (param)
		AnyString( param->get_Text() ).GetString( t );
}

void TParam::SetText( string& t )
{
	if (param)
		param->put_Text( AnyString(t).GetPITAnyString() );
}

//-----------------------------------------------------------------------------

void TParams::SetTParams( PIUnknown p )
{
	params = 0;
	if (p)
		p->QueryInterface( IID_ITParams, (void**) &params );
}

void TParams::ClearTParams( void )
{
	if (params)
	{
		params->Release();
		params = 0;
	}
}

TParams::TParams( void ) : TBDTObject()
{
	params = CreateITParams();
	TBDTObject::SetPIT( params );
}

TParams::TParams( PITParams p ) : TBDTObject( p )
{
	SetTParams( p );
}

TParams::TParams( const TParams& p ) : TBDTObject( p )
{
	SetTParams( p.params );
}

TParams::TParams( PTParams p ) : TBDTObject( p )
{
	SetTParams( p ? p->params : 0 );
}

TParams& TParams::operator=( PITParams p )
{
	TBDTObject::operator=(p);
	ClearTParams();
	SetTParams( p );
	return *this;
}

TParams& TParams::operator=( const TParams& p )
{
	if (this != &p)
	{
		TBDTObject::operator=(p);
		ClearTParams();
		SetTParams( p.params );
	}
	return *this;
}

int TParams::operator==( const TParams& p ) const
{
	if (this == &p)
		return true;
	if (params == p.params)
		return true;
	return false;
}

int TParams::operator!=( const TParams& p ) const
{
	return ! operator==(p);
}

TParams::~TParams()
{
	ClearTParams();
}

void TParams::SetPIT( PIUnknown p )
{
	ClearTParams();
	SetTParams( p );
	TBDTObject::SetPIT( p );
}

void TParams::AssignValues( TParams& p )
{
	if (params)
		params->AssignValues( p.GetPITParams() );
}

void TParams::AddParam( TParam& p )
{
	if (params)
		params->AddParam( p.GetPITParam() );
}

void TParams::RemoveParam( TParam& p )
{
	if (params)
		params->RemoveParam( p.GetPITParam() );
}

DEFINE_BDTO_OBJECTMETHOD3( TParams, TParam, PITParam, CreateParam, TFieldType, string&, TParamType );

void TParams::CallCreateParam( TFieldType fldType, string& name, TParamType paramType, TParam& p )
{
	if (params)
	{
		PITParam pit = params->CreateParam( fldType, AnyString(name).GetPITAnyString(), paramType );
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

DEFINE_BDTO_PROP_RO( TParams, int, Count );

void TParams::GetCount( int& c )
{
	if (params)
		c = params->get_Count();
	else
		c = 0;
}

void TParams::Clear( void )
{
	if (params)
		params->Clear();
}

DEFINE_BDTO_OBJECTMETHOD1( TParams, TParam, PITParam, ParamByName, string& );

void TParams::CallParamByName( string& value, TParam& p )
{
	if (params)
	{
		PITParam pit = params->ParamByName( AnyString(value).GetPITAnyString() );
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}

DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TParams, TParam, PITParam, Items, uint16 );

void TParams::GetItems( uint16 i, TParam& p )
{
	if (params)
	{
		PITParam pit = params->get_Items( i );
		if (pit)
		{
			p.SetPIT( pit );
			pit->Release();
		}
	}
}
